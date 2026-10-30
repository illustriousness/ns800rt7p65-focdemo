"""Independent plant sweep, including explicit flux-mismatch voltage limits."""
import json
from pathlib import Path
import subprocess
import sys
BASE=Path(__file__).parent
ROOT=BASE/'isolated'
LIB=next((ROOT/'libraries/SguanFOC_Library').glob('SguanFOC库v3.1.0*'))
source=(ROOT/'tests/sguan_foc_sim.c').read_text()
results=[]
for flux in (.0152,.021):
    text=source.replace('flux=.021f',f'flux={flux}f')
    text=text.replace('Sguan.Func_Set_Velocity(target*Value_2PI/60);',
        'Sguan.Func_Set_Velocity((fabsf(target)>800 || fabsf(target)<350 ? copysignf(500,target) : target)*Value_2PI/60);')
    text=text.replace('        SguanFOC_High_Loop();',
        '        if(n==120000 && (fabsf(target)>800 || fabsf(target)<350)) Sguan.Func_Set_Velocity(target*Value_2PI/60);\n        SguanFOC_High_Loop();')
    text=text.replace('n<260000','n<320000').replace('n>=200000','n>=260000')
    test=BASE/f'plant-{flux}.c';test.write_text(text)
    exe=BASE/f'plant-{flux}'
    subprocess.run(['cc','-O2','-fno-strict-aliasing','-I'+str(LIB),'-I'+str(ROOT/'applications/sguan'),
        str(test),*[str(p) for p in sorted(LIB.glob('*.c'))],'-lm','-o',str(exe)],check=True)
    for rpm in (tuple(map(int,sys.argv[1:])) if len(sys.argv)>1 else (350,500,800,1000,1500,2000,2500,3000)):
        p=subprocess.run([str(exe),str(rpm),'0','0'],capture_output=True,text=True,timeout=30)
        r={'flux':flux,'rpm':rpm,'returncode':p.returncode,'stdout':p.stdout,'stderr':p.stderr};results.append(r)
        print(flux,rpm,p.returncode,p.stdout.splitlines()[-2:],p.stderr,flush=True)
(BASE/'model-results.json').write_text(json.dumps(results,indent=2))
