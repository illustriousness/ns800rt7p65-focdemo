#!/usr/bin/env python3
import fcntl
import os
import re
import select
import struct
import sys
import termios
import time


DEVICE = sys.argv[1] if len(sys.argv) > 1 else "/dev/ttyACM0"
SMP_RE = re.compile(
    rb"smp ready=([0-9a-fA-F]+) cpu0=(\d+) mask0=([0-9a-fA-F]+) "
    rb"cpu1=(\d+) mask1=([0-9a-fA-F]+) shared=(\d+) ipi0=(\d+) ipi1=(\d+) "
    rb"shell_cpu=(\d+)\r?\n"
)


def configure(fd: int) -> None:
    attrs = termios.tcgetattr(fd)
    attrs[0] = 0
    attrs[1] = 0
    attrs[2] = termios.CS8 | termios.CREAD | termios.CLOCAL
    attrs[3] = 0
    attrs[4] = termios.B115200
    attrs[5] = termios.B115200
    attrs[6][termios.VMIN] = 0
    attrs[6][termios.VTIME] = 1
    termios.tcsetattr(fd, termios.TCSANOW, attrs)
    try:
        bits = termios.TIOCM_DTR | termios.TIOCM_RTS
        fcntl.ioctl(fd, termios.TIOCMBIS, struct.pack("I", bits))
    except OSError:
        pass
    time.sleep(0.25)
    termios.tcflush(fd, termios.TCIFLUSH)


def write_slow(fd: int, data: bytes) -> None:
    for byte in data:
        os.write(fd, bytes((byte,)))
        time.sleep(0.003)


def sample(fd: int, timeout: float = 3.0) -> tuple[int, ...]:
    termios.tcflush(fd, termios.TCIFLUSH)
    write_slow(fd, b"\r\nsmp\r\n")
    deadline = time.monotonic() + timeout
    data = bytearray()
    while time.monotonic() < deadline:
        readable, _, _ = select.select([fd], [], [], 0.2)
        if readable:
            data.extend(os.read(fd, 4096))
            match = SMP_RE.search(data)
            if match:
                values = tuple(int(value, 16 if index in (0, 2, 4) else 10)
                               for index, value in enumerate(match.groups()))
                sys.stdout.buffer.write(data)
                sys.stdout.flush()
                return values
    sys.stdout.buffer.write(data)
    raise RuntimeError("did not receive an SMP status line")


def main() -> int:
    fd = os.open(DEVICE, os.O_RDWR | os.O_NOCTTY | os.O_NONBLOCK)
    try:
        configure(fd)
        write_slow(fd, b"\r\nsmp stress\r\n")
        time.sleep(0.1)
        first = sample(fd)
        time.sleep(2.0)
        second = sample(fd)
    finally:
        os.close(fd)

    ready, cpu0, mask0, cpu1, mask1, shared, ipi0, ipi1, shell_cpu = second
    if ready != 0xC020C020:
        raise RuntimeError(f"CPU2 ready marker is invalid: 0x{ready:08x}")
    if mask0 != 0x1 or mask1 != 0x2:
        raise RuntimeError(f"thread affinity failed: mask0=0x{mask0:x}, mask1=0x{mask1:x}")
    if shell_cpu != 1:
        raise RuntimeError(f"FinSH must execute on communications CPU1, got {shell_cpu}")
    if cpu0 <= first[1] or cpu1 <= first[3]:
        raise RuntimeError("one or both bound threads stopped advancing")
    if abs(shared - (cpu0 + cpu1)) > 2:
        raise RuntimeError("shared spinlock counter is inconsistent")
    if ipi0 + ipi1 <= first[6] + first[7]:
        raise RuntimeError("MU IPI counters stopped advancing")

    print(
        "SMP test passed: "
        f"cpu0 +{cpu0 - first[1]}, cpu1 +{cpu1 - first[3]}, "
        f"mask0=0x{mask0:x}, mask1=0x{mask1:x}, "
        f"shared={shared}, ipi0={ipi0}, ipi1={ipi1}, shell_cpu={shell_cpu}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
