#!/usr/bin/env bash
set -euo pipefail

project_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)
cpu1_image=${1:-"$project_dir/rtthread.bin"}
cpu2_image=${2:-"$project_dir/rtthread_cpu2.bin"}
jlink_exe=${JLINK_EXE:-JLinkExe}
jlink_sn=${JLINK_SN:-941000024}
jlink_speed=${JLINK_SPEED:-4000k}
jlink_device=${JLINK_DEVICE:-NS800RT7P65D-DHQFOY2}
command_file=$(mktemp)
trap 'rm -f -- "$command_file"' EXIT

if [[ ! -f "$cpu1_image" || ! -f "$cpu2_image" ]]; then
    echo "CPU1 or CPU2 binary is missing" >&2
    exit 1
fi

"$project_dir/scripts/jlink_install_device.sh"

{
    echo "r"
    echo "h"
    if [[ ${JLINK_FORCE_PROGRAM:-0} == 1 ]]; then
        echo "exec SetCompareMode 0"
    fi
    echo "loadbin $cpu1_image, 0x08000000"
    echo "verifybin $cpu1_image, 0x08000000"
    echo "loadbin $cpu2_image, 0x08080000"
    echo "verifybin $cpu2_image, 0x08080000"
    echo "r"
    echo "g"
    echo "exit"
} > "$command_file"

exec "$jlink_exe" \
    -SelectEmuBySN "$jlink_sn" \
    -device "$jlink_device" \
    -if SWD \
    -nogui 1 \
    -speed 4000k \
    -autoconnect 1 \
    -CommandFile "$command_file"
