#!/usr/bin/env python3
"""Check core wiring and cross-compile CAN paths without changing BSP config."""
import json
from pathlib import Path
import shlex
import subprocess
import tempfile

root = Path(__file__).resolve().parents[1]
smp = (root / "board/smp/smp_port.c").read_text()
secondary = smp.split("void ns800_smp_secondary_start(void)", 1)[1].split(
    "void ns800_smp_context_switch_complete", 1)[0]
assert secondary.index("Interrupt_initVectorTable();") < secondary.index("ns800_smp_ipi_init();")
assert "if (rt_hw_cpu_id() == 0)" not in smp.split("static void ns800_smp_ipi_init(void)", 1)[1].split(
    "static void ns800_smp_irq_priority_init", 1)[0]
assert "(void *)(rt_ubase_t)NS800_COMM_CPU" in smp.split("static int ns800_console_smp_init", 1)[0]
port = (root / "applications/sguan/ns800_foc_port.c").read_text()
shell = port.split("static void foc_status(void)", 1)[1].split("static int foc_app_init", 1)[0]
assert "Sguan." not in shell, "communications code must use published state, not live controller fields"
assert "(void *)(rt_ubase_t)NS800_CONTROL_CPU" in port

subprocess.run(["scons", "--cdb", "build/compile_commands.json"], cwd=root, check=True)
entries = json.loads((root / "build/compile_commands.json").read_text())
base = shlex.split(next(e["command"] for e in entries if e["file"].endswith("/can/dev_can.c")))
driver = root / "libraries/HAL_Drivers/drivers/drv_can.c"
with tempfile.TemporaryDirectory(prefix="ns800-core-role-", dir="/tmp/opencode") as folder:
    for mode, defines in (
        ("can1", ["BSP_USING_CAN1"]),
        ("canfd1", ["BSP_USING_CANFD1"]),
        ("all", ["BSP_USING_CAN1", "BSP_USING_CANFD1", "BSP_USING_CANFD2"]),
    ):
        args = base.copy()
        args[args.index("-o") + 1] = str(Path(folder) / (mode + ".o"))
        args[-1] = str(driver)
        args.extend(["-DBSP_USING_CAN", *["-D" + define for define in defines]])
        subprocess.run(args, cwd=root, check=True)
        print(f"CAN driver ARM cross-compile passed: {mode}")
print("Per-core writable vectors, communication affinity and control-state separation passed")
