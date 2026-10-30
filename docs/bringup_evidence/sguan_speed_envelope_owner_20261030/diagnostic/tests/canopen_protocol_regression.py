#!/usr/bin/env python3
from pathlib import Path
import subprocess
import tempfile

root = Path(__file__).resolve().parents[1]
app = root / 'applications/canopen'
stack = root / 'libraries/CANopenNode'
subprocess.run(['python3', str(app / 'generate_od.py'), '--check'], check=True)
sources = [app / name for name in ('OD.c', 'CO_driver.c', 'cia402.c', 'protocol.c')]
sources += [stack / '301' / name for name in ('CO_ODinterface.c', 'CO_Emergency.c',
            'CO_NMT_Heartbeat.c', 'CO_SDOserver.c', 'CO_PDO.c')]
with tempfile.TemporaryDirectory(prefix='ns800-canopen-', dir='/tmp/opencode') as folder:
    binary = Path(folder) / 'canopen_test'
    subprocess.run(['cc', '-std=gnu11', '-O2', '-g', '-Wall', '-Wextra', '-Werror',
                    '-fsanitize=address,undefined', '-I' + str(app), '-I' + str(stack),
                    '-I' + str(root / 'applications/sguan'),
                    str(root / 'tests/canopen_protocol_regression.c'), *map(str, sources),
                    '-lm', '-o', str(binary)], check=True)
    subprocess.run([str(binary)], check=True, timeout=30)
