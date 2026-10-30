#!/usr/bin/env python3
"""Constrain the SMO delta and verify direct-feedback discrete sample timing."""
import json
import os
from pathlib import Path
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
SETTINGS = json.loads((ROOT / 'applications/sguan/upstream.json').read_text())
REPO = ROOT / 'libraries/SguanFOC_Library'
LIBRARY = REPO / SETTINGS['source_directory']


def assert_smo_delta(library=LIBRARY, repo=REPO, settings=SETTINGS):
    original = subprocess.check_output(['git', '-C', str(repo), 'show',
        settings['base_revision'] + ':' + settings['source_directory'] + '/Sguan_SMO.c']).decode()
    insertion = ('    /* Feed switching correction directly into the current predictor.\n'
                 '     * The low-pass estimate is an output for the PLL, not this feedback. */\n'
                 '    float error = run->Output_Ix - run->Input_Ix;\n'
                 '    float Ex = Value_Sign(error)*smo->h;\n')
    expected = original.replace('    float I_input,part0,part1,part2,part3;',
                                insertion + '    float I_input,part0,part1,part2,part3;', 1)
    expected = expected.replace('    part3 = run->Output_Ex*smo->data.Gain0;',
                                '    part3 = Ex*smo->data.Gain0;', 1)
    old = ('    // 输出x轴的预测反电动势，并滤波\n'
           '    float error = run->Output_Ix - run->Input_Ix;\n'
           '\terror = Value_Sign(error);\t\n'
           '    float Ex = error*smo->h;')
    assert old in expected, 'Upstream SMO layout changed; review rather than silently accepting it'
    expected = expected.replace(old,
        '    // 输出x轴的预测反电动势，并滤波（与预测器共用同一个开关注入）', 1)
    assert (library / 'Sguan_SMO.c').read_bytes() == expected.encode(), 'Unexpected SMO delta'


TEST = r'''
#include "Sguan_SMO.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

static SMO_STRUCT observer(void) {
    SMO_STRUCT s={0};
    s.T=.00005f; s.Rs=.2f; s.Ld=.0004f; s.Lq=.0003f;
    s.Wc=800; s.h=6; s.IntMax=10; s.IntMin=-10;
    SMO_Init(&s); return s;
}
static void check_step(const SMO_STRUCT *before, const SMO_GO_STRUCT *old,
                       const SMO_GO_STRUCT *now) {
    float injection=old->Output_Ix>old->Input_Ix ? before->h : -before->h;
    float derivative=old->Input_Ux*before->data.Gain0
        -old->Output_Ix*before->data.Gain1
        -before->data.Input_We*before->data.Gain2*old->Input_Iy
        -injection*before->data.Gain0;
    float predicted=old->Output_Ix+before->data.I_num*(derivative+old->I_i);
    float emf=before->data.F_num*(injection+old->F_i)-before->data.F_den*old->F_o;
    assert(!old->IntegralFrozen_flag && fabsf(predicted)<before->IntMax);
    assert(fabsf(predicted-now->Output_Ix)<2e-6f);
    assert(fabsf(derivative-now->I_i)<.01f);
    assert(now->F_i==injection && fabsf(emf-now->Output_Ex)<2e-6f);
}
int main(void) {
    SMO_STRUCT s=observer(), other=s;
    /* Changing only filtered EMF must not change predicted current. */
    other.alpha.Output_Ex=other.alpha.F_o=3;
    other.beta.Output_Ex=other.beta.F_o=-2;
    SMO_Loop(&s); SMO_Loop(&other);
    assert(s.alpha.Output_Ix==other.alpha.Output_Ix);
    assert(s.beta.Output_Ix==other.beta.Output_Ix);
    /* sign(0)=-1: use the pre-integration error, not its new positive sign. */
    assert(s.alpha.Output_Ix>0 && s.alpha.F_i==-6);
    assert(s.alpha.Output_Ex!=other.alpha.Output_Ex);
    s=observer();
    for(unsigned n=0;n<4096;n++) {
        s.alpha.Input_Ix=.3f*sinf(n*.013f); s.beta.Input_Ix=.2f*cosf(n*.017f);
        s.alpha.Input_Ux=.4f*cosf(n*.011f); s.beta.Input_Ux=.3f*sinf(n*.019f);
        s.data.Input_We=10;
        SMO_STRUCT before=s;
        SMO_Loop(&s);
        check_step(&before,&before.alpha,&s.alpha);
        check_step(&before,&before.beta,&s.beta);
    }
    s=observer(); s.Lq=s.Ld; SMO_Init(&s);
    float peak=0;
    for(unsigned n=0;n<40000;n++) {
        SMO_Loop(&s);
        if(n>=20000 && fabsf(s.alpha.Output_Ex)>peak) peak=fabsf(s.alpha.Output_Ex);
    }
    /* Hard switching remains: reject the old ±1.32 V cycle, not all ripple. */
    assert(peak>.1f && peak<.13f);
    printf("SMO direct feedback: discrete timing, both axes, filtered-output isolation; zero-input peak %.6f V\n",peak);
    return 0;
}
'''


def main():
    assert_smo_delta()
    with tempfile.TemporaryDirectory(prefix='ns800-smo-feedback-') as name:
        folder = Path(name)
        source = folder / 'feedback.c'
        source.write_text(TEST)
        executable = folder / 'feedback'
        subprocess.run([os.environ.get('CC', 'cc'), '-O2', '-I'+str(LIBRARY),
            str(source), str(LIBRARY/'Sguan_SMO.c'), str(LIBRARY/'Sguan_math.c'),
            '-lm', '-o', str(executable)], check=True)
        subprocess.run([str(executable)], check=True)


if __name__ == '__main__':
    main()
