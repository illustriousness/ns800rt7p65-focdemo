#!/usr/bin/env python3
"""Constrain the SMO repair; verify other upstream algorithms and supervision."""
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
from sguan_smo_feedback_regression import assert_smo_delta

root = Path(__file__).resolve().parents[1]
config = json.loads((root / 'applications/sguan/upstream.json').read_text())
repo = root / 'libraries/SguanFOC_Library'
library = repo / config['source_directory']
port = root / 'applications/sguan'


def upstream(name):
    return subprocess.check_output(['git', '-C', str(repo), 'show',
        config['base_revision'] + ':' + config['source_directory'] + '/' + name])


def function(text, name):
    match = re.search(r'^static void ' + name + r'\([^;]+?\)\s*\{', text, re.MULTILINE)
    assert match, name
    begin = match.start()
    end = text.index('{', begin) + 1
    depth = 1
    while depth:
        depth += (text[end] == '{') - (text[end] == '}')
        end += 1
    return text[begin:end]


for name in ('SguanFOC.h', 'Sguan_SMO.h', 'Sguan_math.c', 'Sguan_math.h'):
    assert (library / name).read_bytes() == upstream(name), name
assert_smo_delta(library, repo, config)
original = upstream('SguanFOC.c').decode().replace('VBUS_MIM', 'VBUS_MIN')
current = (library / 'SguanFOC.c').read_text()
for name in ('Encoder_Sensorless_Tall', 'Control_VelCur_DOUBLE', 'Control_PosVelCur_THREE',
             'Transfer_Init', 'Current_Tick', 'Status_Switch_Loop'):
    assert function(current, name) == function(original, name), name + ' differs from upstream'
reverse_fix = ('    if (CONFIG_MODE == MODE_Sensorless_SMO && sguan->foc.Target_Speed < 0.0f)\n'
               '        pll->go.Error = -pll->go.Error;\n')
assert reverse_fix in function(current, 'Transfer_SMO_Loop')
gain_schedule = ('    /* Board range: h=6 below 800 rpm, ramp to h=12 at 2000 rpm. */\n'
                 '    float injection = 6.0f + .0477464829f*(sguan->value.Speed_abs - 83.7758041f);\n'
                 '    Value_Limit(&injection, 12.0f, 6.0f);\n'
                 '    sguan->transfer.SMO.h = injection;\n')
assert gain_schedule in function(current, 'Transfer_SMO_Loop')
assert function(current, 'Transfer_SMO_Loop').replace(reverse_fix, '').replace(gain_schedule, '') == function(original, 'Transfer_SMO_Loop')
assert 'Transfer_NLFO_Loop' in function(current, 'Encoder_Sensorless_Tall')
scale_fix = ('    #if CONFIG_MODE == MODE_Sensorless_SMO\n'
             '    U_alpha *= Value_SQRT3;\n'
             '    U_beta *= Value_SQRT3;\n'
             '    #endif\n')
assert scale_fix in function(current, 'PWM_Tick')
normalize = lambda text: '\n'.join(line.rstrip() for line in text.splitlines())
assert normalize(function(current, 'PWM_Tick').replace(scale_fix, '')) == normalize(function(original, 'PWM_Tick'))
print('Original IF/current/position/PID, math and public state preserved; exact SMO feedback and gain schedule allowed')

supervisor_test = r'''
#include "foc_sensorless.h"
#include <assert.h>
#include <string.h>
int main(void) {
    SguanFOC_System_STRUCT motor={0}, before;
    struct foc_sensorless_monitor state;
    foc_sensorless_reset(&state);
    motor.motor.Poles=2;
    motor.value.Sensorless_AbsMin=35;
    motor.value.Low_angle=.5f;
    motor.foc.Speed_in=52;
    motor.encoder.Real_Speed=52;
    motor.transfer.SMO.alpha.Output_Ex=1;
    before=motor;
    assert(foc_sensorless_tick(&state,&motor) && !state.closed);
    assert(memcmp(&before,&motor,sizeof(motor))==0);
    motor.value.Speed_abs=52;
    motor.value.Low_angle=2;
    before=motor;
    for(unsigned n=0;n<49;n++) assert(foc_sensorless_tick(&state,&motor) && !state.closed);
    assert(foc_sensorless_tick(&state,&motor) && state.closed);
    assert(memcmp(&before,&motor,sizeof(motor))==0);
    assert(!motor.value.Sensorless_Flag); /* No fabricated library closed flag. */
    motor.transfer.SMO.alpha.Output_Ex=0;
    for(unsigned n=0;n<99;n++) assert(foc_sensorless_tick(&state,&motor));
    assert(!foc_sensorless_tick(&state,&motor));
    foc_sensorless_reset(&state);
    motor.encoder.Real_Speed=0;
    for(unsigned n=0;n<9999;n++) assert(foc_sensorless_tick(&state,&motor) && !state.closed);
    assert(!foc_sensorless_tick(&state,&motor));
    foc_sensorless_reset(&state);
    motor.encoder.Real_Speed=NAN;
    assert(!foc_sensorless_tick(&state,&motor));
    return 0;
}
'''

with tempfile.TemporaryDirectory(prefix='ns800-sguan-reuse-') as name:
    folder = Path(name)
    test = folder / 'supervisor.c'
    test.write_text(supervisor_test)
    executable = folder / 'supervisor'
    subprocess.run([os.environ.get('CC', 'cc'), '-O2', '-I'+str(library), '-I'+str(port),
                    str(test), '-lm', '-o', str(executable)], check=True)
    subprocess.run([str(executable)], check=True)
    print('Supervisor: read-only observation, bounded confirmation/loss/startup and invalid data passed')
    copied = folder / 'library'
    copied.mkdir()
    for path in library.iterdir():
        if path.suffix in ('.c', '.h'):
            shutil.copyfile(path, copied / path.name)
    settings = copied / 'UserData_Config.h'
    original_config = settings.read_text()
    for mode in (8, 9):
        settings.write_text(re.sub(r'(#define Define_Run_Mode)\s+\d+', r'\g<1> '+str(mode), original_config))
        subprocess.run([os.environ.get('CC', 'cc'), '-O2', '-fno-strict-aliasing',
                        '-I'+str(copied), '-c', str(copied / 'SguanFOC.c'),
                        '-o', str(folder / f'mode{mode}.o')], check=True)
    print('Library SMO and NLFO configurations both compile; no production sources changed')
