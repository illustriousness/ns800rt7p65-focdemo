#!/usr/bin/env bash
set -euo pipefail

project_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)
elf=${1:-"$project_dir/rtthread.elf"}
sdk_zip=${NS800_SDK_ZIP:-"$project_dir/vendor/NS800_SDK_v0.4.0.zip"}
pack_member=utilities/pack/MDK/NOVOSENSE.NS800RT7XXX.0.5.3.pack
target=${PYOCD_TARGET:-ns800rt7p65d_dhqfoy2}
frequency=${PYOCD_FREQUENCY:-1m}
probe=${PYOCD_PROBE:-$(udevadm info -q property -n /dev/ttyACM0 2>/dev/null | sed -n 's/^ID_SERIAL_SHORT=//p')}

if [[ ! -f "$elf" ]]; then
    echo "ELF not found: $elf" >&2
    exit 1
fi

if [[ -z "$sdk_zip" || ! -f "$sdk_zip" ]]; then
    echo "Set NS800_SDK_ZIP to a valid NS800 SDK v0.4.0 archive." >&2
    exit 1
fi

if ! command -v pyocd >/dev/null 2>&1; then
    echo "pyocd not found; install it with: pipx install pyocd" >&2
    exit 1
fi

pack_file=$(mktemp --suffix=.pack)
unzip -p "$sdk_zip" "$pack_member" > "$pack_file"

echo "Warning: this GDB session controls CPU1 only and may not attach after CPU2 is active." >&2

pyocd gdbserver \
    --pack "$pack_file" \
    --uid "$probe" \
    --target "$target" \
    --frequency "$frequency" \
    --connect under-reset \
    --persist \
    --port 3333 &
gdbserver_pid=$!
trap 'kill "$gdbserver_pid" 2>/dev/null || true; rm -f "$pack_file"' EXIT

for _ in $(seq 1 40); do
    if bash -c '</dev/tcp/127.0.0.1/3333' 2>/dev/null; then
        break
    fi
    sleep 0.1
done

arm-none-eabi-gdb "$elf" \
    -ex 'target extended-remote :3333' \
    -ex 'monitor reset halt'
