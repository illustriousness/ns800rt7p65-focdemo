"""Bounded real-motor test. Uses isolated diagnostics, not the public status ABI."""
import fcntl
import json
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess
import sys
import termios
import time

BASE=Path(__file__).parent
ROOT=BASE/'isolated'
sys.path.insert(0,str(ROOT/'scripts'))
from ecosystem_test import configure,command
label,variant=sys.argv[1],int(sys.argv[2])
rpm=int(sys.argv[3]) if len(sys.argv)>3 else 500
sequence=len(sys.argv)>4 and sys.argv[4]=='sequence'
assert 350<=abs(rpm)<=800
folder=BASE/label;folder.mkdir(exist_ok=False)
for name in ('rtthread.elf','rtthread.bin','rtthread_cpu2.bin'):
    shutil.copyfile(ROOT/name,folder/name)
for name in ('ns800_foc_port.c','foc_trace_diag.h','SConscript'):
    shutil.copyfile(ROOT/'applications/sguan'/name,folder/name)
library=next((ROOT/'libraries/SguanFOC_Library').glob('SguanFOC库v3.1.0*'))
shutil.copyfile(library/'Sguan_SMO.c',folder/'SMO.c')
with (folder/'flash.log').open('w') as stream:
    subprocess.run([str(ROOT/'scripts/jlink_flash.sh')],cwd=ROOT,
        env=dict(os.environ,JLINK_SN='4294967295'),stdout=stream,stderr=subprocess.STDOUT,check=True,timeout=90)
fd=os.open('/dev/serial/by-id/usb-SEGGER_J-Link_004294967295-if00',os.O_RDWR|os.O_NOCTTY|os.O_NONBLOCK)
begun=time.monotonic();log=(folder/'uart.jsonl').open('w');stopped=False
def send(text):
    out=command(fd,text,timeout=3).decode(errors='replace')
    log.write(json.dumps({'seconds':time.monotonic()-begun,'command':text,'output':out})+'\n');log.flush()
    assert 'command not found' not in out and 'Thread Operating System' not in out,out
    return out
def snapshot():
    out=send('diag');v=dict(re.findall(r'\b(\w+)=([^\s]+)',out))
    assert set(('variant','adc','overflow','isr','control','peak_mA','bus_mV','I_mA',
                'state','error','ticks','count','complete','abort','target_rpm','est_rpm','cpu_hz','offsets'))<=v.keys(),out
    print(f"{label} t={time.monotonic()-begun:.2f} state={v['state']} err={v['error']} est={v['est_rpm']} peak={v['peak_mA']} isr={v['isr']} count={v['count']}",flush=True)
    return v
def check(s,baseline):
    assert s['state'] in ('3','4') and s['error']=='00000000' and s['abort']=='0',s
    assert int(s['overflow'])==baseline and int(s['peak_mA'])<3000,s
    assert min(int(v) for key in ('isr','control') for v in s[key].split('/'))>0,s
    assert int(s['isr'].split('/')[1])/int(s['cpu_hz'])<.00005,s
try:
    fcntl.ioctl(fd,termios.TIOCEXCL);configure(fd);send('motor stop');s=snapshot()
    assert s['variant']==str(variant) and s['state']=='2' and s['error']=='00000000',s
    assert s['offsets']=='256' and 12000<int(s['bus_mV'])<30000,s
    assert max(abs(int(v)) for v in s['I_mA'].split(','))<200,s
    assert int(s['isr'].split('/')[0])>0,s
    old=int(s['adc']);time.sleep(1);s=snapshot();assert int(s['adc'])>old and s['state']=='2',s
    baseline=int(s['overflow'])
    send(f'motor closed {rpm} 0.8')
    targets=(rpm,600,rpm) if sequence else (rpm,)
    for index,target in enumerate(targets):
        if index: send(f'motor speed {target}')
        start=time.monotonic();settled=[]
        hold=8.0 if sequence else 10.5
        while time.monotonic()-start<hold:
            time.sleep(.25);s=snapshot();check(s,baseline)
            if index: assert s['state']=='4',s
            if time.monotonic()-start>hold-(3 if sequence else 2.5):
                assert s['state']=='4' and abs(int(s['est_rpm'])-target)<=50,s
                settled.append(int(s['est_rpm']))
        errors=[abs(v-target) for v in settled]
        assert errors and sum(errors)/len(errors)<=25,errors
        print(f'hold {target}: max error={max(errors)} mean error={sum(errors)/len(errors):.3f}',flush=True)
    assert s['count']=='1024' and s['complete']=='1',s
finally:
    try:
        send('motor stop');time.sleep(.15);s=snapshot()
        public=send('motor status')
        assert s['state']=='2' and 'state=idle error=00000000' in public,s
        stopped=True
    finally:
        log.close();fcntl.ioctl(fd,termios.TIOCNXCL);os.close(fd)
assert stopped
symbols=subprocess.check_output(['arm-none-eabi-nm','-S',str(folder/'rtthread.elf')],text=True)
m=re.search(r'^([0-9a-f]+)\s+([0-9a-f]+)\s+B foc_trace$',symbols,re.M);assert m
address,size=(int(s,16) for s in m.groups());assert size==114752 and address+size<0x2013ff00
script=folder/'export.jlink'
script.write_text(f'mem32 0x400A004C 1\nw4 0x400A0054 0x00800000\nh\nsavebin {folder}/trace.bin, 0x{address:x}, 0x{size:x}\ng\nexit\n')
with (folder/'export.log').open('w') as stream:
    subprocess.run(['JLinkExe','-SelectEmuBySN','4294967295','-device','NS800RT7P65D-DHQFOY2',
        '-if','SWD','-speed','4000','-nogui','1','-autoconnect','1','-CommandFile',str(script)],
        cwd=ROOT,stdout=stream,stderr=subprocess.STDOUT,check=True,timeout=30)
out=(folder/'export.log').read_text();m=re.search(r'^400A004C\s*=\s*([0-9A-Fa-f]+)',out,re.M)
assert m and int(m[1],16)&(1<<23)==0,out
data=(folder/'trace.bin').read_bytes();assert len(data)==size
header=struct.unpack('<16I',data[:64]);assert header[0]==0x504C4C54 and header[2]==variant and header[4]==1024 and header[13]==0 and header[15]==1,header
(folder/'header.json').write_text(json.dumps(header))
print(label,'PASS: bounded test, current/timing/tracking checks, full capture, STOP and GPIO23 off verified',flush=True)
