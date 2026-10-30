#!/usr/bin/env python3
"""Nominal independent plant: safe starts followed by the extended speed range.

No board access. Existing current/speed error limits are not relaxed. The old
integration regression separately retains flux-mismatch and blocked-rotor tests.
"""
import json
import os
from pathlib import Path
import subprocess
import tempfile

root=Path(__file__).resolve().parents[1]
settings=json.loads((root/'applications/sguan/upstream.json').read_text())
library=root/'libraries/SguanFOC_Library'/settings['source_directory']
source=(root/'tests/sguan_foc_sim.c').read_text().replace('flux=.021f','flux=.0152f')
source=source.replace('Sguan.Func_Set_Velocity(target*Value_2PI/60);',
    'Sguan.Func_Set_Velocity((fabsf(target)>800 ? copysignf(500,target) : target)*Value_2PI/60);')
source=source.replace('        SguanFOC_High_Loop();',
    '        if(n==120000 && fabsf(target)>800) Sguan.Func_Set_Velocity(target*Value_2PI/60);\n        SguanFOC_High_Loop();')
source=source.replace('n<260000','n<320000').replace('n>=200000','n>=260000')
with tempfile.TemporaryDirectory(prefix='ns800-envelope-',dir='/tmp/opencode') as name:
    folder=Path(name);test=folder/'plant.c';exe=folder/'plant';test.write_text(source)
    subprocess.run([os.environ.get('CC','cc'),'-O2','-fno-strict-aliasing','-I'+str(library),
        '-I'+str(root/'applications/sguan'),str(test),*[str(p) for p in sorted(library.glob('*.c'))],
        '-lm','-o',str(exe)],check=True)
    for rpm in (350,500,800,1000,1500,2000,2500,-500,-800,-1500,-2500):
        for angle in (0,1.5707963,3.1415926,4.712389):
            p=subprocess.run([str(exe),str(rpm),'0',str(angle)],capture_output=True,text=True,timeout=30)
            assert p.returncode==0,(rpm,angle,p.stdout,p.stderr)
        print(f'{rpm} rpm: nominal independent plant, four initial angles passed')
print('Extended envelope: original current/error criteria retained; model only, no hardware')
