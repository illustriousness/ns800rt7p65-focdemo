"""Bounded UART-only sweep. 2.5 A is the external DC-source limit, not phase current."""
import fcntl
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import termios
import time

BASE=Path(__file__).parent;ROOT=Path(os.environ.get('SPEED_DIAG_ROOT',str(BASE/'isolated')))
owner_test=os.environ.get('SPEED_OWNER_TEST')=='1'
sys.path.insert(0,str(ROOT/'scripts'))
from ecosystem_test import configure,command
label=sys.argv[1];targets=list(map(int,sys.argv[2:]));assert targets and len(targets)<=7
assert all(0<r<=3000 for r in targets)
folder=BASE/label;folder.mkdir(exist_ok=False)
for name in ('rtthread.elf','rtthread.bin','rtthread_cpu2.bin'):
    shutil.copyfile(ROOT/name,folder/name)
for rel in ('applications/sguan/ns800_foc_port.c','applications/sguan/speed_diag.h',
            'applications/sguan/foc_sensorless.h','applications/canopen/cia402.c'):
    shutil.copyfile(ROOT/rel,folder/Path(rel).name)
lib=next((ROOT/'libraries/SguanFOC_Library').glob('SguanFOC库v3.1.0*'))
for name in ('SguanFOC.c','UserData_Config.h','UserData_Parameter.h','UserData_Motor.h','Sguan_SMO.c'):
    shutil.copyfile(lib/name,folder/name)
with (folder/'flash.log').open('w') as stream:
    subprocess.run([str(ROOT/'scripts/jlink_flash.sh')],cwd=ROOT,
        env=dict(os.environ,JLINK_SN='4294967295'),stdout=stream,stderr=subprocess.STDOUT,check=True,timeout=90)
fd=os.open('/dev/serial/by-id/usb-SEGGER_J-Link_004294967295-if00',os.O_RDWR|os.O_NOCTTY|os.O_NONBLOCK)
begun=time.monotonic();log=(folder/'uart.jsonl').open('w');stopped=False;failure=None;summary=[]
def send(text):
    out=command(fd,text,timeout=3).decode(errors='replace')
    log.write(json.dumps({'seconds':time.monotonic()-begun,'command':text,'output':out})+'\n');log.flush()
    assert 'command not found' not in out and 'Thread Operating System' not in out,out
    return out
def snapshot():
    out=send('diag');v=dict(re.findall(r'\b(\w+)=([^\s]+)',out))
    assert set(('adc','overflow','isr','control','peak_mA','bus_mV','I_mA','state','error',
        'ticks','reason','target_rpm','est_rpm','cpu_hz','offsets','clips','saturated','Udq_mV','Idq_mA','emf_mV'))<=v.keys(),out
    print(f"{label} t={time.monotonic()-begun:.2f} state={v['state']} err={v['error']} reason={v['reason']} target={v['target_rpm']} est={v['est_rpm']} peak={v['peak_mA']} bus={v['bus_mV']} clip={v['clips']} sat={v['saturated']}",flush=True)
    return v
def healthy(s,baseline):
    assert s['state'] in ('3','4','6') and s['error']=='00000000' and s['reason']=='0',s
    assert int(s['overflow'])==baseline and int(s['peak_mA'])<3000,s
    assert 22000<=int(s['bus_mV'])<=27000,s
    assert min(int(v) for key in ('isr','control') for v in s[key].split('/'))>0,s
    assert int(s['isr'].split('/')[1])/int(s['cpu_hz'])<.00005,s
try:
    fcntl.ioctl(fd,termios.TIOCEXCL);configure(fd);send('motor stop');s=snapshot()
    assert s['state']=='2' and s['error']=='00000000' and s['offsets']=='256',s
    assert 22500<int(s['bus_mV'])<25500,s
    assert max(abs(int(v)) for v in s['I_mA'].split(','))<200,s
    old=int(s['adc']);time.sleep(1);s=snapshot();assert int(s['adc'])>old and s['state']=='2',s
    if owner_test:
        assert 'owner=can ' in send('motor owner')
        seq=s['command_seq'];send('motor closed 500 0.8');time.sleep(.1);s=snapshot()
        assert s['state']=='2' and s['command_seq']==seq,'UART started without ownership'
        send('motor owner uart')
        deadline=time.monotonic()+2
        while 'owner=uart ' not in send('motor owner'):
            assert time.monotonic()<deadline,'UART handover did not complete'
        assert snapshot()['state']=='2'
    baseline=int(s['overflow'])
    for index,target in enumerate(targets):
        send(f'motor speed {target}' if index else f'motor closed {target} 0.8')
        start=time.monotonic();settled=[];before=None
        while time.monotonic()-start<8:
            time.sleep(.25);s=snapshot();healthy(s,baseline)
            if before is None:before=s
            if index:assert s['state']=='4',s
            if time.monotonic()-start>5:
                assert s['state']=='4',s
                settled.append(s)
        errors=[abs(int(v['est_rpm'])-target) for v in settled]
        stage={'target_rpm':target,'max_error_rpm':max(errors),'mean_error_rpm':sum(errors)/len(errors),
          'peak_mA':int(s['peak_mA']),'max_isr_us':int(s['isr'].split('/')[1])/400,
          'bus_min_mV':int(s['bus_min_mV']),'bus_max_mV':int(s['bus_max_mV']),
          'steady_clips':int(settled[-1]['clips'])-int(settled[0]['clips']),
          'steady_saturated_ticks':int(settled[-1]['saturated'])-int(settled[0]['saturated']),
          'last':s}
        summary.append(stage);(folder/'stages.json').write_text(json.dumps(summary,indent=2))
        print('STAGE',json.dumps(stage),flush=True)
        assert max(errors)<=50 and sum(errors)/len(errors)<=25,stage
        assert stage['steady_clips']==0,'PWM clipping: stop escalation without shrinking sampling window'
except BaseException as e:
    failure=e
finally:
    try:
        if owner_test:
            send('motor owner can')
            deadline=time.monotonic()+2
            while 'owner=can ' not in send('motor owner'):
                assert time.monotonic()<deadline,'CAN handover did not complete'
            s=snapshot();assert s['state'] in ('2','5'),s
            seq=s['command_seq'];send('motor closed 500 0.8');time.sleep(.1);s=snapshot()
            assert s['state'] in ('2','5') and s['command_seq']==seq,'UART command accepted after CAN handover'
            send('co')
        send('motor stop');time.sleep(.15);s=snapshot();public=send('motor status')
        assert s['state'] in ('2','5') and ('state=idle' in public or 'state=fault' in public),s
        stopped=True
    finally:
        log.close();fcntl.ioctl(fd,termios.TIOCNXCL);os.close(fd)
assert stopped
# STOP is acknowledged before any debugger connection. Do not halt a live stage.
script=folder/'gates.jlink';script.write_text('mem32 0x400A004C 1\nexit\n')
with (folder/'gates.log').open('w') as stream:
    subprocess.run(['JLinkExe','-SelectEmuBySN','4294967295','-device','NS800RT7P65D-DHQFOY2',
        '-if','SWD','-speed','4000','-nogui','1','-autoconnect','1','-CommandFile',str(script)],
        stdout=stream,stderr=subprocess.STDOUT,check=True,timeout=30)
out=(folder/'gates.log').read_text();m=re.search(r'^400A004C\s*=\s*([0-9A-Fa-f]+)',out,re.M)
assert m and int(m[1],16)&(1<<23)==0,out
if failure:raise failure
print(label,'PASS: bounded sweep, all stages accepted, STOP and GPIO23 off verified',flush=True)
