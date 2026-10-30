#!/usr/bin/env python3
"""Build the protocol-only host test against the user's installed ZLG SDK."""
import argparse
from pathlib import Path
import subprocess
import tempfile

parser = argparse.ArgumentParser()
parser.add_argument('output', type=Path, help='new CSV capture path')
parser.add_argument('--zlg-root', type=Path,
                    default=Path('/home/ari/code/quectel/exoskeleton/hip_motor/tools/zlg_can'))
args = parser.parse_args()
source = Path(__file__).with_suffix('.c')
with tempfile.TemporaryDirectory(prefix='ns800-zlg-', dir='/tmp/opencode') as folder:
    binary = Path(folder) / 'zlg_canopen_test'
    subprocess.run(['cc', '-std=c11', '-O2', '-Wall', '-Wextra', '-Werror',
                    '-I' + str(args.zlg_root / 'include'), str(source), '-o', str(binary),
                    '-L' + str(args.zlg_root / 'lib'), '-Wl,-rpath,' + str(args.zlg_root / 'lib'),
                    '-lusbcanfd', '-lm', '-pthread'], check=True)
    subprocess.run([str(binary), str(args.output)], check=True)
