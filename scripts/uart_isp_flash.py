#!/usr/bin/env python3
import fcntl
import os
import select
import struct
import sys
import termios
import time
from pathlib import Path


HEAD = 0x65
STATUS_TEXT = {
    0x80: "CRC error",
    0x83: "chip erase required",
    0x84: "external authentication failed",
    0x85: "debug authentication required",
    0x86: "ISP flash commands disabled",
    0x90: "unsupported command",
    0x91: "unsupported parameter",
    0x92: "read denied",
    0x93: "write denied",
    0x94: "alignment error",
    0x95: "erase denied",
    0x96: "verify denied",
    0x97: "jump denied",
    0x98: "write failed",
    0x99: "flash is not blank",
}


def crc16_x25(data: bytes) -> int:
    crc = 0xFFFF
    for byte in data:
        crc ^= byte
        for _ in range(8):
            crc = (crc >> 1) ^ 0x8408 if crc & 1 else crc >> 1
    return crc ^ 0xFFFF


class UartIsp:
    def __init__(self, device: str):
        self.device = device
        self.fd = os.open(device, os.O_RDWR | os.O_NOCTTY | os.O_NONBLOCK)
        attrs = termios.tcgetattr(self.fd)
        attrs[0] = 0
        attrs[1] = 0
        attrs[2] = termios.CS8 | termios.CREAD | termios.CLOCAL
        attrs[3] = 0
        attrs[4] = termios.B115200
        attrs[5] = termios.B115200
        attrs[6][termios.VMIN] = 0
        attrs[6][termios.VTIME] = 1
        termios.tcsetattr(self.fd, termios.TCSANOW, attrs)
        try:
            bits = termios.TIOCM_DTR | termios.TIOCM_RTS
            fcntl.ioctl(self.fd, termios.TIOCMBIS, struct.pack("I", bits))
        except OSError:
            pass
        time.sleep(0.2)
        termios.tcflush(self.fd, termios.TCIOFLUSH)

    def close(self):
        os.close(self.fd)

    def write_all(self, data: bytes):
        view = memoryview(data)
        while view:
            _, writable, _ = select.select([], [self.fd], [], 1.0)
            if not writable:
                raise TimeoutError("UART write timeout")
            count = os.write(self.fd, view)
            view = view[count:]
        termios.tcdrain(self.fd)

    def read_exact(self, count: int, timeout: float) -> bytes:
        deadline = time.monotonic() + timeout
        result = bytearray()
        while len(result) < count:
            remaining = deadline - time.monotonic()
            if remaining <= 0:
                raise TimeoutError(
                    f"UART read timeout: wanted {count}, received {len(result)}"
                )
            readable, _, _ = select.select([self.fd], [], [], remaining)
            if readable:
                result.extend(os.read(self.fd, count - len(result)))
        return bytes(result)

    def handshake(self):
        for _ in range(10):
            termios.tcflush(self.fd, termios.TCIFLUSH)
            self.write_all(b"\x51")
            try:
                if self.read_exact(1, 0.3) == b"\x51":
                    return
            except TimeoutError:
                pass
        raise RuntimeError("UART ISP handshake failed")

    def command(self, info: bytes, timeout: float = 2.0) -> bytes:
        if not 1 <= len(info) <= 255:
            raise ValueError("invalid ISP command length")
        frame = bytes((HEAD, len(info))) + info
        frame += struct.pack("<H", crc16_x25(frame))
        self.write_all(frame)

        header = self.read_exact(2, timeout)
        if header[0] != HEAD or header[1] == 0:
            raise RuntimeError(f"invalid ISP response header: {header.hex(' ')}")
        tail = self.read_exact(header[1] + 2, timeout)
        response = header + tail
        expected_crc = struct.unpack_from("<H", response, len(response) - 2)[0]
        actual_crc = crc16_x25(response[:-2])
        if expected_crc != actual_crc:
            raise RuntimeError(
                f"ISP response CRC mismatch: {expected_crc:04x} != {actual_crc:04x}"
            )

        status = response[2]
        if status != 0:
            detail = STATUS_TEXT.get(status, "unknown status")
            raise RuntimeError(f"ISP command 0x{info[0]:02x} failed: 0x{status:02x} {detail}")
        return response[3:-2]


def set_base(isp: UartIsp, address: int):
    isp.command(b"\x20\x00\x00" + struct.pack("<I", address))


def program_region(isp: UartIsp, address: int, data: bytes):
    position = 0
    current_base = None
    while position < len(data):
        absolute = address + position
        base = absolute & ~0xFFFF
        offset = absolute - base
        length = min(240, len(data) - position, 0x10000 - offset)
        if current_base != base:
            set_base(isp, base)
            current_base = base
        chunk = data[position:position + length]
        chunk += b"\xff" * (-len(chunk) % 8)
        payload = b"\x28" + struct.pack("<H", offset) + chunk
        isp.command(payload, timeout=3.0)
        position += length
        if position == len(data) or position % 4096 < 240:
            print(f"  wrote {position}/{len(data)} bytes", flush=True)


def verify_region(isp: UartIsp, address: int, data: bytes):
    position = 0
    current_base = None
    while position < len(data):
        absolute = address + position
        base = absolute & ~0xFFFF
        offset = absolute - base
        length = min(240, len(data) - position, 0x10000 - offset)
        if current_base != base:
            set_base(isp, base)
            current_base = base
        actual = isp.command(b"\x29" + struct.pack("<H", offset) + bytes((length,)))
        expected = data[position:position + length]
        if actual != expected:
            raise RuntimeError(f"verify mismatch at 0x{absolute:08x}")
        position += length
    print(f"  verified {len(data)} bytes", flush=True)


def main() -> int:
    project = Path(__file__).resolve().parent.parent
    device = sys.argv[1] if len(sys.argv) > 1 else "/dev/ttyACM0"
    regions = [
        (0x08000000, (project / "rtthread.bin").read_bytes()),
        (0x08080000, (project / "rtthread_cpu2.bin").read_bytes()),
    ]

    isp = UartIsp(device)
    try:
        isp.handshake()
        print(f"UART ISP handshake passed on {device}")
        query = isp.command(b"\x10")
        print(f"Query: {query.hex(' ')}")
        part = isp.command(b"\x15").rstrip(b"\x00\xff").decode("ascii", errors="replace")
        print(f"Part: {part}")
        level = isp.command(b"\x12")
        print(f"Read protection level: {level.hex(' ')}")

        print("Erasing MainFlash...", flush=True)
        isp.command(b"\x24", timeout=30.0)
        print("MainFlash erase passed")

        for address, data in regions:
            print(f"Programming 0x{address:08x}, {len(data)} bytes")
            program_region(isp, address, data)

        for address, data in regions:
            print(f"Verifying 0x{address:08x}")
            verify_region(isp, address, data)

        print("UART ISP programming and byte-for-byte verification passed")
        return 0
    finally:
        isp.close()


if __name__ == "__main__":
    raise SystemExit(main())
