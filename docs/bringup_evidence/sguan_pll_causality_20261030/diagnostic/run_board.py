"""Bounded physical diagnostic run, then gate-off SWD trace export."""
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

ROOT=Path(os.environ.get('PLL_DIAG_ROOT','/tmp/opencode/pll-board-20261030/isolated'))
BASE=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
from ecosystem_test import configure, command
label,kind,variant=sys.argv[1],sys.argv[2],int(sys.argv[3])
folder=BASE/label; folder.mkdir(exist_ok=False)
for name in ('rtthread.elf','rtthread.bin','rtthread_cpu2.bin'):
    shutil.copyfile(ROOT/name,folder/name)
(folder/'diagnostic.patch').write_bytes(subprocess.check_output(['git','diff','--',
    'applications/sguan/ns800_foc_port.c','applications/sguan/SConscript'],cwd=ROOT))
shutil.copyfile(ROOT/'applications/sguan/foc_trace_diag.h',folder/'foc_trace_diag.h')
shutil.copyfile(ROOT/'applications/sguan/ns800_foc_port.c',folder/'instrumented-port.c')
(folder/'SMO.c').write_bytes(next((ROOT/'libraries/SguanFOC_Library').glob('SguanFOC库v3.1.0*/Sguan_SMO.c')).read_bytes())
env=dict(os.environ,JLINK_SN='4294967295')
with (folder/'flash.log').open('w') as stream:
    subprocess.run([str(ROOT/'scripts/jlink_flash.sh')],cwd=ROOT,env=env,stdout=stream,stderr=subprocess.STDOUT,check=True,timeout=90)
fd=os.open('/dev/serial/by-id/usb-SEGGER_J-Link_004294967295-if00',os.O_RDWR|os.O_NOCTTY|os.O_NONBLOCK)
begun=time.monotonic(); log=(folder/'uart.jsonl').open('w'); stopped=False
def send(text):
    out=command(fd,text,timeout=3).decode(errors='replace')
    log.write(json.dumps({'seconds':time.monotonic()-begun,'command':text,'output':out})+'\n');log.flush()
    assert 'command not found' not in out,out
    return out
def status():
    out=send('motor status')
    match=re.search(r'motor (idle|ramp|run|fault) fault=(\w+)',out);assert match,out
    v=dict(re.findall(r'\b(\w+)=([^\s]+)',out));v['state']=match[1];v['fault']=match[2]
    print(f"{label} t={time.monotonic()-begun:.2f} {v['state']} fault={v['fault']} est={v['est_rpm']} peak={v['peak_mA']} ISR={v['ISR_ns']}",flush=True)
    return v
try:
    fcntl.ioctl(fd,termios.TIOCEXCL);configure(fd);send('motor stop');s=status()
    assert s['state']=='idle' and s['fault']=='none' and s['cal']=='1' and s['ready']=='1',s
    assert 12000<int(s['vbus_mV'])<30000,s
    assert max(abs(int(v)) for v in s['I_mA'].split(','))<200,'Invalid idle current calibration'
    assert int(s['isr_cycles'].split('/')[0])>0,s
    old_adc=int(s['adc']);time.sleep(1);s=status()
    assert s['state']=='idle' and int(s['adc'])>old_adc and s['fault']=='none',s
    assert max(abs(int(v)) for v in s['I_mA'].split(','))<200,s
    baseline=int(s['overflow']);out=send('trace');assert f'variant={variant} ' in out,out
    if kind=='zero':
        send('trace zero');time.sleep(1.3);s=status();assert s['state']=='idle',s
    else:
        assert variant in (0,1),'Direct-feedback variant is zero-input only'
        send('motor closed 500 0.8');start=time.monotonic();settled=[]
        while time.monotonic()-start<10.5:
            time.sleep(.2);s=status()
            assert s['fault']=='none' and s['state'] in ('ramp','run'),s
            assert int(s['overflow'])==baseline and int(s['peak_mA'])<3000 and 0<int(s['ISR_ns'])<50000,s
            assert min(int(v) for key in ('isr_cycles','control_cycles') for v in s[key].split('/'))>0,s
            if time.monotonic()-start>8:
                assert s['state']=='run' and abs(int(s['est_rpm'])-500)<=50,s
                settled.append(int(s['est_rpm']))
        assert settled
    out=send('trace');assert 'count=1024 complete=1 abort=0' in out,out
finally:
    try:
        send('motor stop');time.sleep(.12);s=status()
        assert s['state']=='idle' and s['loop']=='stopped',s
        stopped=True
    finally:
        log.close();fcntl.ioctl(fd,termios.TIOCNXCL);os.close(fd)
assert stopped
# No debugger attach/halt is performed until the motor stop is acknowledged.
symbols=subprocess.check_output(['arm-none-eabi-nm','-S',str(folder/'rtthread.elf')],text=True)
m=re.search(r'^([0-9a-f]+)\s+([0-9a-f]+)\s+B foc_trace$',symbols,re.M);assert m
address,size=(int(s,16) for s in m.groups());assert size==114752 and address+size<0x2013ff00
script=folder/'export.jlink'
script.write_text(f'mem32 0x400A004C 1\nw4 0x400A0054 0x00800000\nh\nsavebin {folder}/trace.bin, 0x{address:x}, 0x{size:x}\ng\nexit\n')
with (folder/'export.log').open('w') as stream:
    subprocess.run(['JLinkExe','-SelectEmuBySN','4294967295','-device','NS800RT7P65D-DHQFOY2',
        '-if','SWD','-speed','4000','-nogui','1','-autoconnect','1','-CommandFile',str(script)],
        cwd=ROOT,stdout=stream,stderr=subprocess.STDOUT,check=True,timeout=30)
out=(folder/'export.log').read_text();m=re.search(r'^400A004C\s*=\s*([0-9A-Fa-f]+)',out,re.M);assert m,out
assert int(m[1],16)&(1<<23)==0,'GPIO23 was high before forced clear'
data=(folder/'trace.bin').read_bytes();assert len(data)==size
header=struct.unpack('<16I',data[:64]);assert header[0]==0x504C4C54 and header[2]==variant and header[4]==1024 and header[13]==0 and header[15]==1,header
(folder/'header.json').write_text(json.dumps(dict(zip(('magic','version','variant','kind','count','capacity','sample_bytes','cpu_hz','fs','start_adc','end_adc','overflow_start','overflow_end','abort','max_isr','completed'),header)),indent=2))
print(label,'PASS: bounded run, completed 20 kHz capture, acknowledged stop, GPIO23 low before SWD halt',flush=True)
