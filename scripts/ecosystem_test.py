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
PROMPT = b"msh >"


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
    termios.tcflush(fd, termios.TCIOFLUSH)


def write_slow(fd: int, data: bytes) -> None:
    for byte in data:
        os.write(fd, bytes((byte,)))
        time.sleep(0.005)


def command(fd: int, text: str, timeout: float = 5.0) -> bytes:
    termios.tcflush(fd, termios.TCIFLUSH)
    encoded = text.encode()
    write_slow(fd, encoded + b"\r\n")
    deadline = time.monotonic() + timeout
    output = bytearray()

    while time.monotonic() < deadline:
        readable, _, _ = select.select([fd], [], [], 0.2)
        if readable:
            output.extend(os.read(fd, 4096))
            command_position = output.find(encoded)
            if command_position >= 0:
                prompt_position = output.find(
                    PROMPT, command_position + len(encoded)
                )
                if prompt_position >= 0:
                    return bytes(output)

    raise RuntimeError(f"shell command timed out: {text!r}; output={output!r}")


def require(output: bytes, token: bytes, command_name: str) -> None:
    if token not in output:
        raise RuntimeError(
            f"{command_name!r} output does not contain {token!r}: {output!r}"
        )


def main() -> int:
    fd = os.open(DEVICE, os.O_RDWR | os.O_NOCTTY | os.O_NONBLOCK)
    try:
        configure(fd)
        outputs = {
            "version": command(fd, "version"),
            "device": command(fd, "list device"),
            "threads": command(fd, "ps"),
            "heap": command(fd, "free"),
            "smp": command(fd, "smp"),
        }
    finally:
        os.close(fd)

    require(outputs["version"], b"RT-Thread", "version")
    require(outputs["device"], b"uart1", "list device")
    require(outputs["threads"], b"cpu0w", "ps")
    require(outputs["threads"], b"cpu1w", "ps")
    require(outputs["heap"], b"available:", "free")

    match = re.search(
        rb"smp ready=([0-9a-fA-F]+).*mask0=([0-9a-fA-F]+).*"
        rb"mask1=([0-9a-fA-F]+)",
        outputs["smp"],
    )
    if match is None:
        raise RuntimeError(f"invalid SMP shell output: {outputs['smp']!r}")
    ready, mask0, mask1 = (int(value, 16) for value in match.groups())
    if (ready, mask0, mask1) != (0xC020C020, 0x1, 0x2):
        raise RuntimeError(
            f"invalid SMP state: ready=0x{ready:08x}, "
            f"mask0=0x{mask0:x}, mask1=0x{mask1:x}"
        )

    for name, output in outputs.items():
        print(f"[{name}]")
        sys.stdout.buffer.write(output)
        if not output.endswith(b"\n"):
            print()

    print(f"RT-Thread ecosystem test passed on {DEVICE} at 115200 8N1")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
