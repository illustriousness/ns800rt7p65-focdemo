#!/usr/bin/env bash
set -euo pipefail

project_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)
image=${1:-"$project_dir/rtthread.elf"}
cpu2_image=${2:-"$project_dir/rtthread_cpu2.elf"}
sdk_zip=${NS800_SDK_ZIP:-"$project_dir/vendor/NS800_SDK_v0.4.0.zip"}
pack_member=utilities/pack/MDK/NOVOSENSE.NS800RT7XXX.0.5.3.pack
target=${PYOCD_TARGET:-ns800rt7p65d_dhqfoy2}
frequency=${PYOCD_FREQUENCY:-1m}
probe=${PYOCD_PROBE:-$(udevadm info -q property -n /dev/ttyACM0 2>/dev/null | sed -n 's/^ID_SERIAL_SHORT=//p')}

if [[ ! -f "$image" || ! -f "$cpu2_image" ]]; then
    echo "CPU1 or CPU2 image is missing" >&2
    exit 1
fi

if [[ -z "$sdk_zip" || ! -f "$sdk_zip" ]]; then
    echo "Set NS800_SDK_ZIP to a valid NS800 SDK v0.4.0 archive." >&2
    exit 1
fi

pack_file=$(mktemp --suffix=.pack)
trap 'rm -f "$pack_file"' EXIT
unzip -p "$sdk_zip" "$pack_member" > "$pack_file"

echo "Warning: SWD download may fail after CPU2 is active; UART ISP is the recovery path." >&2

pyocd load \
    --pack "$pack_file" \
    --uid "$probe" \
    --target "$target" \
    --frequency "$frequency" \
    --connect under-reset \
    "$image" "$cpu2_image"
