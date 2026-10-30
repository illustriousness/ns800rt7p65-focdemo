#!/usr/bin/env python3
"""The old physical acceptance test must not start a motor using compact status."""
from pathlib import Path
import sys
import tempfile
from unittest.mock import patch

root = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(root / 'scripts'))
import sensorless_test

commands = []


def command(fd, text):
    commands.append(text)
    if text == 'motor status':
        return b'motor status_schema=2 state=idle error=00000000 speed_mrad_s=0 command_seq=0 result=0 stop_seq=1\n'
    assert text == 'motor stop', 'No start or speed command may be sent'
    return b'msh >'


with tempfile.TemporaryDirectory(prefix='ns800-schema-', dir='/tmp/opencode') as folder:
    with patch.object(sys, 'argv', ['sensorless_test.py', '/dev/mock', '--log', str(Path(folder) / 'test.jsonl')]), \
         patch.object(sensorless_test.os, 'open', return_value=12345), \
         patch.object(sensorless_test.os, 'close'), \
         patch.object(sensorless_test.fcntl, 'ioctl'), \
         patch.object(sensorless_test, 'configure'), \
         patch.object(sensorless_test, 'command', side_effect=command), \
         patch.object(sensorless_test.time, 'sleep'):
        try:
            sensorless_test.main()
        except RuntimeError as error:
            assert 'Compact FOC status' in str(error), error
        else:
            raise AssertionError('Missing diagnostics must not be reported as a successful acceptance test')
assert commands == ['motor stop', 'motor status', 'motor stop'], commands
print('Legacy real-board test rejects compact status before START; no hardware accessed')
