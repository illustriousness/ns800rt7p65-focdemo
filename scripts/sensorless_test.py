#!/usr/bin/env python3
"""Bounded real-board test; measured speed below is the independent SMO/PLL estimate.

This does not certify shaft RPM with a tachometer or encoder. It checks the
observer-branch indication, confirmed estimator tracking and speed response,
current/deadline bounds and a confirmed stop through the board's UART console.
It requires the legacy diagnostic status; compact status_schema=2 is rejected
before any start request because it cannot support those acceptance checks.
"""
import argparse
import fcntl
import json
import os
from pathlib import Path
import re
import termios
import time

from ecosystem_test import configure, command


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("device", nargs="?", default=
                        "/dev/serial/by-id/usb-SEGGER_J-Link_004294967295-if00")
    parser.add_argument("--start-rpm", type=int, default=500)
    parser.add_argument("--next-rpm", type=int, default=600)
    parser.add_argument("--current", type=float, default=0.8)
    parser.add_argument("--hold-seconds", type=float, default=8.0)
    parser.add_argument("--log", default="/tmp/ns800-sensorless-test.jsonl")
    args = parser.parse_args()
    if (not 350 <= abs(args.start_rpm) <= 800 or not 350 <= abs(args.next_rpm) <= 800
            or args.start_rpm * args.next_rpm <= 0 or not 0.5 <= args.current <= 1.2
            or not 4.0 <= args.hold_seconds <= 20.0):
        parser.error("use same-direction 350..800 rpm, 0.5..1.2 A, and a 4..20 s hold")

    log_path = Path(args.log)
    log_path.parent.mkdir(parents=True, exist_ok=True)
    fd = os.open(args.device, os.O_RDWR | os.O_NOCTTY | os.O_NONBLOCK)
    log = None
    begun = time.monotonic()
    compact_status = False

    def send(text):
        output = command(fd, text).decode(errors="replace")
        if "command not found" in output:
            raise RuntimeError(f"command rejected: {text}: {output}")
        return output

    def snapshot():
        nonlocal compact_status
        output = send("motor status")
        if re.search(r"\bstatus_schema=2\b", output):
            compact_status = True
            raise RuntimeError("Compact FOC status has no current/timing/angle diagnostics; "
                               "this legacy acceptance test cannot run and will not start the motor")
        if "Thread Operating System" in output:
            raise RuntimeError(f"board reset during status query: {output}")
        state = re.search(r"motor (idle|align|ramp|run|fault) fault=(\w+)", output)
        if not state:
            raise RuntimeError(f"invalid motor status: {output}")
        values = {k: v for k, v in re.findall(r"\b(\w+)=([^\s]+)", output)}
        numeric = {"adc", "overflow", "peak_mA", "ISR_ns", "cpu_hz", "est_rpm", "pll_rpm",
                   "target_rpm", "forced_rpm", "forced_mrad", "angle_mrad", "transitions"}
        record = {k: int(v) if k in numeric else v for k, v in values.items()}
        record.update(raw_output=output, seconds=round(time.monotonic() - begun, 3), state=state[1], fault=state[2])
        log.write(json.dumps(record) + "\n")
        log.flush()
        print(f"t={record['seconds']:6.2f} state={record['state']} loop={record.get('loop', '-')} "
              f"target={record.get('target_rpm', '-')} est={record.get('est_rpm', '-')} "
              f"pll={record.get('pll_rpm', '-')} peak_mA={record.get('peak_mA','MISSING')} "
              f"fault={record['fault']}", flush=True)
        return record

    def healthy(record, baseline):
        required = {"cpu_hz", "isr_cycles", "ISR_ns", "control_cycles",
                    "emath_sincos", "emath_trig", "emath_sqrt", "forced_mrad",
                    "angle_mrad", "current_error_mA"}
        if record["state"] == "idle":
            raise RuntimeError("motor unexpectedly stopped/reset during the run")
        if required - record.keys():
            raise RuntimeError(f"truncated timing/status output: {required - record.keys()}")
        for key in ("emath_sincos", "emath_trig", "emath_sqrt"):
            if not re.fullmatch(r"[0-9]+/[0-9]+/[0-9]+", record[key]):
                raise RuntimeError(f"invalid eMATH timing: {key}={record[key]}")
            if record.get("math") == "upstream":
                if record[key] != "0/0/0":
                    raise RuntimeError(f"unexpected eMATH activity with upstream math: {key}")
                continue
            if key == "emath_sincos" and any(value == 0 for value in map(int, record[key].split("/"))):
                raise RuntimeError(f"eMATH path did not execute: {key}={record[key]}")
            if key != "emath_sincos" and record.get("loop") == "closed" and any(value == 0 for value in map(int, record[key].split("/"))):
                raise RuntimeError(f"eMATH path did not execute: {key}={record[key]}")
        isr_last, isr_max = map(int, record["isr_cycles"].split("/"))
        control_last, control_max = map(int, record["control_cycles"].split("/"))
        if min(isr_last, isr_max, control_last, control_max) <= 0:
            raise RuntimeError("DWT timing inactive; reset before measuring the control loop")
        if record["cpu_hz"] <= 0 or record["ISR_ns"] != isr_max * 1000000000 // record["cpu_hz"]:
            raise RuntimeError("DWT cycle-to-time conversion mismatch")
        if record["fault"] != "none":
            raise RuntimeError(f"motor fault: {record}")
        if record["overflow"] != baseline:
            raise RuntimeError("ADC overflow count increased during the run")
        if record["peak_mA"] >= 3000 or record.get("ISR_ns", 0) >= 50000:
            raise RuntimeError("current or 50 us control-period bound exceeded")

    try:
        fcntl.ioctl(fd, termios.TIOCEXCL)
        configure(fd)
        log = log_path.open("w")
        send("motor stop")
        idle = snapshot()
        if idle["state"] != "idle" or idle["cal"] != "1":
            raise RuntimeError("motor not idle/calibrated before start")
        baseline = idle["overflow"]
        send(f"motor closed {args.start_rpm} {args.current}")
        deadline = time.monotonic() + 12.0
        while True:
            time.sleep(0.4)
            sample = snapshot()
            healthy(sample, baseline)
            if sample["state"] == "run" and sample.get("loop") == "closed":
                break
            if time.monotonic() > deadline:
                raise RuntimeError("sensorless handover did not complete in 12 s")

        forced_angle = sample["forced_mrad"]
        for index, target in enumerate((args.start_rpm, args.next_rpm, args.start_rpm)):
            if index:
                send(f"motor speed {target}")
            started = time.monotonic()
            settled = []
            while time.monotonic() - started < args.hold_seconds:
                time.sleep(0.4)
                sample = snapshot()
                healthy(sample, baseline)
                if (sample["state"] != "run" or sample.get("loop") != "closed"
                        or sample.get("transitions") != 1 or sample.get("if_stage") != "3"):
                    raise RuntimeError("closed loop lost or restarted")
                if sample["forced_mrad"] != forced_angle:
                    raise RuntimeError("last IF diagnostic angle changed after observer handover")
                if time.monotonic() - started > args.hold_seconds - 3.0:
                    settled.append(sample)
            errors = [abs(s["est_rpm"] - target) for s in settled]
            if not errors or max(errors) > 50 or sum(errors) / len(errors) > 25:
                raise RuntimeError(f"estimated speed failed hold at {target} rpm: {errors}")
            if len({s["angle_mrad"] for s in settled}) < 2:
                raise RuntimeError("estimated rotor angle did not change during the hold")
            print(f"hold {target} rpm: estimated error max={max(errors)}, "
                  f"mean={sum(errors)/len(errors):.1f} rpm", flush=True)
    finally:
        try:
            send("motor stop")
            time.sleep(0.1)
            if log and not compact_status:
                stopped = snapshot()
                if stopped["state"] != "idle" or stopped["electrical_mHz"] != "0":
                    raise RuntimeError("stop was not confirmed")
        finally:
            if log:
                log.close()
            fcntl.ioctl(fd, termios.TIOCNXCL)
            os.close(fd)
    print(f"UART sensorless test and confirmed stop passed; trace: {log_path}", flush=True)


if __name__ == "__main__":
    main()
