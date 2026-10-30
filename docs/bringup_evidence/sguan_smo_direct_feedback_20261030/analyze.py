"""Offline RAM-trace comparison; observer/control angles are not shaft errors."""
import csv
import hashlib
import json
from pathlib import Path
import re
import struct
import sys
import numpy as np

BASE=Path(sys.argv[1]) if len(sys.argv)>1 else Path(__file__).parent
HEAD=('magic','version','variant','kind','count','capacity','sample_bytes','cpu_hz',
      'fs','start_adc','end_adc','overflow_start','overflow_end','abort','max_isr','completed')
FLOATS=('ia','ib','ihat_a','ihat_b','za','zb','ea','eb','ua','ub','error','we','angle',
        'speed','control_angle','id','iq','iqref','phase_u','phase_v','phase_w','peak',
        'bus','previous_angle','previous_we')
DTYPE=np.dtype([('adc','<u4'),('dwt','<u4'),*[(k,'<f4') for k in FLOATS],('flags','<u4')])
FACTOR=60/(4*np.pi)

def spectrum(x,lo=200,hi=3000):
    n=len(x);t=np.arange(n)
    x=x-np.polyval(np.polyfit(t,x,1),t)
    window=np.hanning(n);z=np.fft.rfft(x*window)
    power=abs(z)**2/(n*np.sum(window**2));power[1:-1]*=2
    freq=np.fft.rfftfreq(n,1/20000);band=(freq>=lo)&(freq<=hi)
    peak=int(np.argmax(np.where(band,power,0)))
    return {'rms':float(np.sqrt(power[band].sum())),
            'peak_bin_Hz':float(freq[peak]) if power[peak]>0 else None}

results={}
labels=('A1-500','B1-500','A2-500','B2-500','B-800','A-800')
for label in labels:
    folder=BASE/label
    if not folder.exists(): continue
    data=(folder/'trace.bin').read_bytes();h=dict(zip(HEAD,struct.unpack('<16I',data[:64])))
    assert h['magic']==0x504C4C54 and h['sample_bytes']==112 and h['count']==1024
    assert h['completed']==1 and h['abort']==0 and h['overflow_start']==h['overflow_end']==0
    a=np.frombuffer(data[64:],dtype=DTYPE)
    assert len(a)==1024 and np.all(np.diff(a['adc'])==1) and np.all(a['flags']==3)
    x={k:a[k].astype(float) for k in FLOATS}
    assert all(np.isfinite(v).all() for v in x.values())
    rpm=x['we']*FACTOR;integral=rpm-200*FACTOR*x['error']
    angle=np.unwrap(x['control_angle'])*180/np.pi
    r={'header':h,'trace_sha256':hashlib.sha256(data).hexdigest(),
       'duration_ms':51.2,'fft_bin_Hz':19.53125,
       'isr_max_us':h['max_isr']/h['cpu_hz']*1e6,
       'dwt_interval_us_min_median_max':(np.percentile(np.diff(a['dwt']),[0,50,100])/400).tolist(),
       'raw_rpm_mean':float(rpm.mean()),'raw_rpm_std':float(rpm.std()),
       'raw_rpm_range':[float(rpm.min()),float(rpm.max())],
       'filtered_rpm_mean':float(np.mean(x['speed']*2*FACTOR)),
       'filtered_rpm_std':float(np.std(x['speed']*2*FACTOR)),
       'detector_error_std_V':float(x['error'].std()),
       'PI_integral_rpm_std':float(integral.std()),
       'raw_rpm_error_correlation':float(np.corrcoef(rpm,x['error'])[0,1]),
       'raw_rpm_200_3000':spectrum(rpm),'raw_rpm_200_9900':spectrum(rpm,200,9900),
       'control_angle_deg_200_3000':spectrum(angle),'control_angle_deg_200_9900':spectrum(angle,200,9900),
       'emf_alpha_200_3000':spectrum(x['ea']),'emf_alpha_200_9900':spectrum(x['ea'],200,9900),
       'id_200_3000':spectrum(x['id']),'iq_200_3000':spectrum(x['iq']),
       'phase_current_peak_A':float(x['peak'].max()),'bus_mean_V':float(x['bus'].mean()),
       'observer_current_error_rms_A':float(np.sqrt(np.mean((x['ihat_a']-x['ia'])**2)))}
    # Validate which correction actually fed the current predictor, not only
    # that the final output looks quieter. Gain2=0 for this equal-Ld/Lq motor.
    ih=x['ihat_a'];ea=x['ea'];ua=x['ua'];za=x['za']
    correction=ea[:-1] if h['variant']==0 else za[1:]
    derivative=2500*ua[1:]-500*ih[:-1]-2500*correction
    predicted=.000025*(derivative[1:]+derivative[:-1])
    r['observer_recurrence_max_error_A']=float(abs(ih[2:]-ih[1:-1]-predicted).max())
    assert r['observer_recurrence_max_error_A']<2e-6
    error=ih-x['ia'] if h['variant']==0 else ih[:-1]-x['ia'][1:]
    actual=za if h['variant']==0 else za[1:]
    assert np.array_equal(6*np.where(error>0,1.,-1.),actual)
    filtered=(.04/2.04)*(za[1:]+za[:-1])-(-1.96/2.04)*ea[:-1]
    r['emf_filter_recurrence_max_error_V']=float(abs(filtered-ea[1:]).max())
    assert r['emf_filter_recurrence_max_error_V']<1e-6
    expected_i=.25*FACTOR*(x['error'][1:]+x['error'][:-1])
    r['PI_recurrence_max_error_rpm']=float(abs(np.diff(integral)-expected_i).max())
    assert r['PI_recurrence_max_error_rpm']<.01
    # Include every running UART sample: do not infer settled-speed quality
    # from one high-frequency trace window alone.
    status=[]
    for row in map(json.loads,(folder/'uart.jsonl').read_text().splitlines()):
        if row['command']!='diag': continue
        v=dict(re.findall(r'\b(\w+)=([^\s]+)',row['output']))
        if v.get('state') in ('3','4'):
            assert v['error']=='00000000' and v['abort']=='0' and v['overflow']=='0'
            status.append(v)
    r['uart_run_peak_mA']=max(int(v['peak_mA']) for v in status)
    r['uart_run_max_isr_us']=max(int(v['isr'].split('/')[1])/400 for v in status)
    with (folder/'trace.csv').open('w') as stream:
        w=csv.writer(stream);w.writerow(a.dtype.names)
        w.writerows([[int(row[k]) if k in ('adc','dwt','flags') else float(row[k]) for k in a.dtype.names] for row in a])
    results[label]=r
    print(label,json.dumps(r))
if all(k in results for k in ('A1-500','A2-500','B1-500','B2-500')):
    results['comparison']={}
    for b in ('B1-500','B2-500'):
        results['comparison'][b]={}
        for a in ('A1-500','A2-500'):
            results['comparison'][b][a]={
                'raw_std_reduction_pct':100*(1-results[b]['raw_rpm_std']/results[a]['raw_rpm_std']),
                'control_angle_band_rms_reduction_pct':100*(1-results[b]['control_angle_deg_200_3000']['rms']/results[a]['control_angle_deg_200_3000']['rms'])}
(BASE/'results.json').write_text(json.dumps(results,ensure_ascii=False,indent=2)+'\n')
