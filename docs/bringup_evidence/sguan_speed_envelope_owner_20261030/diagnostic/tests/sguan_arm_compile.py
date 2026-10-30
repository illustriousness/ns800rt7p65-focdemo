#!/usr/bin/env python3
"""Cross-compile/link the motor component even when the CAN bench excludes it.

This builds a relocatable component, not a flashable motor firmware image.
It does not modify the active application configuration or access the board.
"""
import json
from pathlib import Path
import shlex
import subprocess
import tempfile

root = Path(__file__).resolve().parents[1]
config = json.loads((root / 'applications/sguan/upstream.json').read_text())
library = root / 'libraries/SguanFOC_Library' / config['source_directory']
port = root / 'applications/sguan'
subprocess.run(['scons', '--cdb', 'build/compile_commands.json'], cwd=root, check=True)
entries = json.loads((root / 'build/compile_commands.json').read_text())
entry = next(e for e in entries if e['file'].endswith('applications/main.c'))
base = shlex.split(entry['command'])
compiler = base[0]
with tempfile.TemporaryDirectory(prefix='ns800-sguan-arm-', dir='/tmp/opencode') as name:
    folder = Path(name)
    objects = []
    for source in [*sorted(library.glob('*.c')), port / 'ns800_foc_port.c']:
        output = folder / (source.stem + '.o')
        args = base.copy()
        args[args.index('-o') + 1] = str(output)
        args[-1] = str(source)
        args += ['-O3', '-fno-strict-aliasing', '-I'+str(library), '-I'+str(port)]
        subprocess.run(args, cwd=root, check=True)
        objects.append(str(output))
    linked = folder / 'sguan-component.o'
    subprocess.run([compiler, '-mcpu=cortex-m7', '-mfpu=fpv5-d16', '-mfloat-abi=hard',
                    '-nostdlib', '-r', *objects, '-o', str(linked)], check=True)
    undefined = subprocess.check_output(['arm-none-eabi-nm', '-u', str(linked)], text=True)
    for line in undefined.splitlines():
        symbol = line.split()[-1]
        assert not symbol.startswith(('Sguan', 'ns800_foc_')), symbol
    symbols = subprocess.check_output(['arm-none-eabi-nm', str(linked)], text=True)
    assert ' T ADCA_CONV_IRQHandler' in symbols
    assert ' T SguanFOC_High_Loop' in symbols
    sections = subprocess.check_output(['arm-none-eabi-objdump', '-h', str(linked)], text=True)
    assert '.fast' in sections
print('ARM motor component compile + relocatable link passed (not a flashable firmware image)')
