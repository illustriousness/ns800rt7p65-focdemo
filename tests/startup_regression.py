#!/usr/bin/env python3
"""Check both built images use the BSP startup and keep the ITCM copy layout."""
from pathlib import Path
import re
import subprocess


root = Path(__file__).resolve().parents[1]
startup = root / "board/startup/startup_NS800RT7xxx.S"
source = startup.read_text()
vectors = source.split("g_pfnVectors:\n", 1)[1].split("__Vectors_End:", 1)[0]
entries = re.findall(r"^\s*\.word\s+(\w+)\s*$", vectors, re.MULTILINE)
for irq, handler in ((81, "ADCA_CONV_IRQHandler"),
                     (197, "UART1_TX_IRQHandler"), (198, "UART1_RX_IRQHandler")):
    assert entries[16 + irq] == handler, (irq, entries[16 + irq])


def tool(name, *args):
    return subprocess.check_output(["arm-none-eabi-" + name, *map(str, args)],
                                   cwd=root, text=True)


def symbols(image):
    return {name: int(address, 16) for address, name in
            re.findall(r"^([0-9a-fA-F]+)\s+\S\s+(\S+)$", tool("nm", image), re.MULTILINE)}


for name, base, expected in (
        ("rtthread", 0x08000000, "build/board/startup/startup_NS800RT7xxx.o"),
        ("rtthread_cpu2", 0x08080000, "build/cpu2/startup_NS800RT7xxx.o")):
    image = root / (name + ".elf")
    map_text = (root / (name + ".map")).read_text()
    loads = re.findall(r"^LOAD\s+(\S*startup_NS800RT7xxx\.o)\s*$", map_text, re.MULTILINE)
    assert loads == [expected], (name, loads)
    syms = symbols(image)
    assert base <= syms["Reset_Handler"] < base + 512 * 1024
    assert syms["__Vectors"] == base
    assert syms["__Vectors_Size"] == len(entries) * 4
    if name == "rtthread_cpu2":
        assert all(syms[key] == 0 for key in
                   ("__fast_start__", "__fast_end__", "__fast_load_addr__"))
        continue

    if "SguanFOC_High_Loop" not in syms:
        assert "ns800_foc_pwm_set" not in syms, "Motor port partially linked into protocol bench"
        assert syms["__fast_start__"] == syms["__fast_end__"]
        assert "canopen_init" in syms and "Board_disablePowerStage" in syms
        continue

    match = re.search(r"^\s*\d+\s+\.fast\s+(\w+)\s+(\w+)\s+(\w+)",
                      tool("objdump", "-h", image), re.MULTILINE)
    assert match, ".fast missing from CPU1 image"
    size, vma, lma = (int(value, 16) for value in match.groups())
    assert 0 < size <= 64 * 1024 and vma == 0
    assert base <= lma < lma + size <= base + 512 * 1024
    assert (syms["__fast_start__"], syms["__fast_end__"], syms["__fast_load_addr__"]) == (vma, vma + size, lma)
    for function in ("ADCA_CONV_IRQHandler", "SguanFOC_High_Loop", "SguanFOC_Low_Loop",
                     "ns800_foc_pwm_set"):
        assert vma <= syms[function] < vma + size, function
    for function in ("fast_sin_cos", "Value_sqrtf"):
        assert base <= syms[function] < base + 512 * 1024, function
    assert 'sin_tab' in syms, 'Original upstream sine table is missing'

print("BSP startup selection, IRQ vector order and CPU1/CPU2 ITCM copy layouts passed")
