#!/usr/bin/env python3
"""Compile the actual edited submodule and exercise the Sguan PMSM simulation."""
import json
import os
from pathlib import Path
import subprocess
import tempfile
from sguan_smo_feedback_regression import assert_smo_delta


root = Path(__file__).resolve().parents[1]
port = root / 'applications/sguan'
upstream = root / 'libraries/SguanFOC_Library'
config = port / 'upstream.json'
settings = json.loads(config.read_text())
library = upstream / settings['source_directory']


def git(*args):
    return subprocess.check_output(['git', '-C', str(upstream), *args], text=True).strip()


subprocess.run(['git', '-C', str(upstream), 'merge-base', '--is-ancestor',
                settings['base_revision'], 'HEAD'], check=True)
state_before = (git('status', '--porcelain'), git('diff', '--binary', 'HEAD'))
assert not list(port.glob('Sguan*.c')) and not list(port.glob('Sguan*.h')), 'Duplicated library sources'
assert not list(port.glob('UserData_*.h')), 'Duplicated board settings'
assert len(list(library.glob('UserData_*.h'))) == 6, 'Library settings missing'
for name in ('Sguan_math.c', 'Sguan_math.h', 'Sguan_SMO.h', 'SguanFOC.h'):
    original = subprocess.check_output(['git', '-C', str(upstream), 'show',
        settings['base_revision'] + ':' + settings['source_directory'] + '/' + name])
    assert (library / name).read_bytes() == original, name + ' differs from upstream'
assert_smo_delta(library, upstream, settings)
assert not list((root / 'build/sguan').glob('*.c'))
assert not list((root / 'build/sguan').glob('*.h')), 'Obsolete generated headers can shadow the submodule'

with tempfile.TemporaryDirectory(prefix='ns800-sguan-') as folder:
    scale_test = Path(folder) / 'svpwm_scale.c'
    scale_test.write_text(r'''
#include "Sguan_SVPWM.h"
#include <assert.h>
#include <math.h>
int main(void) {
    for (int n=0; n<360; ++n) {
        float angle=n*Value_2PI/360.0f;
        float alpha=.1f*cosf(angle), beta=.1f*sinf(angle), u,v,w;
        SVPWM(Value_SQRT3*alpha, Value_SQRT3*beta, &u,&v,&w);
        assert(fabsf((2*u-v-w)/3.0f-alpha)<1e-6f);
        assert(fabsf((v-w)*Value_INV_SQRT3-beta)<1e-6f);
    }
    return 0;
}
''')
    scale_executable = Path(folder) / 'svpwm_scale'
    subprocess.run([os.environ.get('CC', 'cc'), '-O2', '-I' + str(library),
                    str(scale_test), str(library / 'Sguan_SVPWM.c'),
                    '-lm', '-o', str(scale_executable)], check=True)
    subprocess.run([str(scale_executable)], check=True)
    print('SVPWM physical-voltage normalization passed in all sectors')
    executable = Path(folder) / 'sguan_foc_sim'
    sources = sorted(str(path) for path in library.glob('*.c'))
    subprocess.run([os.environ.get('CC', 'cc'), '-O2', '-fno-strict-aliasing',
                    '-I' + str(library), '-I' + str(port),
                    str(root / 'tests/sguan_foc_sim.c'), *sources,
                    '-lm', '-o', str(executable)], check=True)
    for rpm in (500, 800, -500, -800):
        for angle in (0, 1.5707963, 3.1415926, 4.712389):
            result = subprocess.run([str(executable), str(rpm), '0', str(angle)], capture_output=True, text=True, timeout=30)
            assert result.returncode == 0, result.stdout + result.stderr
            assert 'independent plant closed-loop pass' in result.stdout
        print(f'{rpm} rpm: independent PMSM plant passed at four initial angles')
    for rpm in (500, -500):
        result = subprocess.run([str(executable), str(rpm), 'blocked'], capture_output=True, text=True, timeout=30)
        assert result.returncode == 0, result.stdout + result.stderr
        assert 'blocked rotor rejected within startup deadline' in result.stdout
        print(f'{rpm} rpm: blocked rotor rejected within startup deadline')

assert state_before == (git('status', '--porcelain'), git('diff', '--binary', 'HEAD')), 'Test modified library sources'
print('Direct submodule compilation and single-source board settings passed')
