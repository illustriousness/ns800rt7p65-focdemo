#!/usr/bin/env bash
set -euo pipefail

project_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)
elf=${1:-"$project_dir/rtthread.elf"}
jlink_gdb_server=${JLINK_GDB_SERVER:-JLinkGDBServer}
jlink_sn=${JLINK_SN:-941000024}
jlink_speed=${JLINK_SPEED:-500}
jlink_device=${JLINK_DEVICE:-NS800RT7P65D-DHQFOY2}
gdb_port=${JLINK_GDB_PORT:-2331}
swo_port=${JLINK_SWO_PORT:-2332}
telnet_port=${JLINK_TELNET_PORT:-2333}

if [[ ! -f "$elf" ]]; then
    echo "ELF not found: $elf" >&2
    exit 1
fi

"$project_dir/scripts/jlink_install_device.sh"

"$jlink_gdb_server" \
    -select "USB=$jlink_sn" \
    -device "$jlink_device" \
    -if SWD \
    -speed "$jlink_speed" \
    -endian little \
    -noir \
    -singlerun \
    -port "$gdb_port" \
    -swoport "$swo_port" \
    -telnetport "$telnet_port" &
server_pid=$!
trap 'kill "$server_pid" 2>/dev/null || true' EXIT

for _ in $(seq 1 80); do
    if bash -c "</dev/tcp/127.0.0.1/$gdb_port" 2>/dev/null; then
        break
    fi
    if ! kill -0 "$server_pid" 2>/dev/null; then
        wait "$server_pid"
    fi
    sleep 0.1
done

arm-none-eabi-gdb "$elf" \
    -ex "target extended-remote :$gdb_port" \
    -ex "monitor reset" \
    -ex "monitor halt"
