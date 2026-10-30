"""Decode synchronized MCU snapshots and reproduce the reported statistics.

No shaft encoder is present. Angles below are observer/control outputs, not
absolute rotor-angle errors. Windows are 1024 samples (51.2 ms).
"""
import csv
import hashlib
import json
from pathlib import Path
import struct
import sys
import re
import numpy as np

BASE=Path(sys.argv[1]) if len(sys.argv)>1 else Path(__file__).parent
HEAD=('magic','version','variant','kind','count','capacity','sample_bytes','cpu_hz',
      'fs','start_adc','end_adc','overflow_start','overflow_end','abort','max_isr','completed')
FLOATS=('ia','ib','ihat_a','ihat_b','za','zb','ea','eb','ua','ub','error','we','angle',
        'speed','control_angle','id','iq','iqref','phase_u','phase_v','phase_w','peak',
        'bus','previous_angle','previous_we')
DTYPE=np.dtype([('adc','<u4'),('dwt','<u4'),*[(k,'<f4') for k in FLOATS],('flags','<u4')])
assert DTYPE.itemsize==112
FACTOR=60/(4*np.pi)
math_source=BASE/'Sguan_math.c'
if not math_source.exists():
    math_source=next((BASE/'snapshot/libraries/SguanFOC_Library').glob('SguanFOC库v3.1.0*/Sguan_math.c'))
table_source=math_source.read_text().split('static const float sin_tab[512] = {')[1].split('};')[0]
TABLE=np.array([float(v) for v in re.findall(r'(-?\d+\.\d+)f',table_source)],dtype=np.float32)
assert len(TABLE)==512
def library_sine(theta):
    theta=np.array(theta,dtype=np.float32)
    for _ in range(4):
        theta=np.where(theta<0,theta+np.float32(2*np.pi),theta)
        theta=np.where(theta>np.float32(2*np.pi),theta-np.float32(2*np.pi),theta)
    index=(theta*np.float32(81.487330863050417)).astype(int)
    return TABLE[np.clip(index,0,511)]

def spectral(x,lo=200,hi=3000):
    n=len(x);t=np.arange(n)
    # Linear detrend, Hann-windowed one-sided periodogram; band RMS is the
    # integral of PSD, not just the height of one FFT bin.
    x=x-np.polyval(np.polyfit(t,x,1),t)
    window=np.hanning(n);z=np.fft.rfft(x*window)
    power=abs(z)**2/(n*np.sum(window**2));power[1:-1]*=2
    freq=np.fft.rfftfreq(n,1/20000);band=(freq>=lo)&(freq<=hi)
    peak=int(np.argmax(np.where(band,power,0)))
    return {'band_rms':float(np.sqrt(power[band].sum())),
            'peak_bin_Hz':float(freq[peak]) if power[peak]>0 else None}

def coherence(x,y):
    xx=[];yy=[]
    for i in range(0,len(x)-255,128):
        w=np.hanning(256);a=x[i:i+256];b=y[i:i+256]
        xx.append(np.fft.rfft((a-a.mean())*w));yy.append(np.fft.rfft((b-b.mean())*w))
    xx=np.array(xx);yy=np.array(yy)
    pxx=np.mean(abs(xx)**2,axis=0);pyy=np.mean(abs(yy)**2,axis=0)
    coh=abs(np.mean(xx*yy.conj(),axis=0))**2/np.maximum(pxx*pyy,1e-100)
    f=np.fft.rfftfreq(256,1/20000);band=(f>=600)&(f<=1200)
    return float(np.sum(coh[band]*pxx[band])/sum(pxx[band]))

results={}
for label in ('zero-A','zero-B2','zero-A2','zero-C','motor-A1','motor-B1','motor-A2'):
    folder=BASE/label
    path=folder/'trace.bin'
    data=path.read_bytes();h=dict(zip(HEAD,struct.unpack('<16I',data[:64])))
    assert h['magic']==0x504C4C54 and h['sample_bytes']==112 and h['count']==1024
    assert h['completed']==1 and h['abort']==0 and h['overflow_start']==h['overflow_end']==0
    a=np.frombuffer(data[64:],dtype=DTYPE)
    assert len(a)==1024 and np.all(np.diff(a['adc'])==1)
    x={k:a[k].astype(float) for k in FLOATS}
    assert all(np.isfinite(v).all() for v in x.values())
    cycles=np.diff(a['dwt']).astype(float)
    assert abs(np.median(cycles)-20000)<2
    r={'header':h,'sha256':hashlib.sha256(data).hexdigest(),
       'duration_ms':51.2,'fft_bin_Hz':19.53125,
       'isr_max_us':h['max_isr']/h['cpu_hz']*1e6,
       'dwt_interval_us_min_median_max':(np.percentile(cycles,[0,50,100])/400).tolist(),
       'flags_unique':[int(v) for v in np.unique(a['flags'])],
       'emf_alpha_range_V':[float(x['ea'].min()),float(x['ea'].max())],
       'emf_alpha':spectral(x['ea']),
       'observer_current_error_rms_A':float(np.sqrt(np.mean((x['ihat_a']-x['ia'])**2))),
       'detector_error_std_V':float(x['error'].std()),
       'detector_error':spectral(x['error']),
       'input_current_alpha':spectral(x['ia']),
       'switching_alpha':spectral(x['za'])}
    if h['kind']==2:
        assert np.all(a['flags']==0)
        assert all(np.all(x[k]==0) for k in ('ia','ib','ua','ub'))
        r['emf_alpha_full_spectrum']=spectral(x['ea'],200,9999)
        rising=np.flatnonzero(np.diff((x['za']>0).astype(int))==1)
        if len(rising)>1:
            periods=np.diff(rising);r['switching_period_samples_median']=float(np.median(periods))
            r['switching_Hz_from_period']=float(20000/np.median(periods))
    else:
        assert np.all(a['flags']==3),'Must be running/closed with neither frozen flag nor fault'
        rpm=x['we']*FACTOR;integral=rpm-200*FACTOR*x['error']
        angle=np.unwrap(x['angle']);control=np.unwrap(x['control_angle'])
        r.update(raw_rpm_mean=float(rpm.mean()),raw_rpm_std=float(rpm.std()),
          raw_rpm_range=[float(rpm.min()),float(rpm.max())],
          filtered_rpm_mean=float(np.mean(x['speed']*2*FACTOR)),
          filtered_rpm_std=float(np.std(x['speed']*2*FACTOR)),
          PI_integral_rpm_std=float(integral.std()),
          raw_rpm_error_correlation=float(np.corrcoef(rpm,x['error'])[0,1]),
          raw_rpm_error_coherence_600_1200=coherence(rpm,x['error']),
          raw_rpm=spectral(rpm),
          pll_angle_deg=spectral(angle*180/np.pi),
          control_angle_deg=spectral(control*180/np.pi),
          id=spectral(x['id']),iq=spectral(x['iq']),
          phase_current_peak_A=float(x['peak'].max()),
          bus_mean_V=float(x['bus'].mean()),
          phase_current_in_window_max_A=float(max(abs(x[k]).max() for k in ('phase_u','phase_v','phase_w'))))
        # Verify discrete observer feedback recurrence against the exported
        # input voltage, prior predicted current and prior filtered EMF.
        ih=x['ihat_a'];ea=x['ea'];ua=x['ua']
        derivative=2500*ua[1:]-500*ih[:-1]-2500*ea[:-1]
        delta=ih[2:]-ih[1:-1]
        predicted=.000025*(derivative[1:]+derivative[:-1])
        r['observer_recurrence_max_error_A']=float(abs(delta-predicted).max())
        assert r['observer_recurrence_max_error_A']<2e-6
        error=ih-x['ia']
        expected=6*np.where(error>0,1.,-1.) if h['variant']==0 else 6*np.clip(error/.8,-1,1)
        r['switching_reconstruction_max_error_V']=float(abs(expected-x['za']).max())
        assert r['switching_reconstruction_max_error_V']<1e-6
        # Exact trig is only an approximate cross-check: the production table
        # uses truncating lookup, not interpolation. Also reproduce its lookup.
        detector=-(x['ea']*np.cos(x['previous_angle'])+x['eb']*np.sin(x['previous_angle']))
        r['detector_exact_trig_max_difference_V']=float(abs(detector-x['error']).max())
        sine=library_sine(x['previous_angle'])
        cosine=library_sine(np.float32(np.pi/2)-x['previous_angle'].astype(np.float32))
        detector=-(x['ea']*cosine+x['eb']*sine)
        r['detector_library_lookup_max_difference_V']=float(abs(detector-x['error']).max())
        assert r['detector_library_lookup_max_difference_V']<1e-6
        integral_delta=integral[1:]-integral[:-1]
        expected_i=.25*FACTOR*(x['error'][1:]+x['error'][:-1])
        r['PI_recurrence_max_error_rpm']=float(abs(integral_delta-expected_i).max())
        assert r['PI_recurrence_max_error_rpm']<.01
    # CSV is exported directly from raw RAM, not resampled or reconstructed.
    with (folder/'trace.csv').open('w') as stream:
        w=csv.writer(stream);w.writerow(a.dtype.names)
        w.writerows([[int(row[k]) if k in ('adc','dwt','flags') else float(row[k]) for k in a.dtype.names] for row in a])
    results[label]=r
    print(label,json.dumps(r,ensure_ascii=False))
results['comparison']={
  'B_raw_std_reduction_vs_A1_pct':100*(1-results['motor-B1']['raw_rpm_std']/results['motor-A1']['raw_rpm_std']),
  'B_raw_std_reduction_vs_A2_pct':100*(1-results['motor-B1']['raw_rpm_std']/results['motor-A2']['raw_rpm_std'])}
(BASE/'results.json').write_text(json.dumps(results,ensure_ascii=False,indent=2)+'\n')
