#!/usr/bin/env bash
set -euo pipefail

project_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)
device=${1:-/dev/ttyACM0}

exec "$project_dir/scripts/uart_isp_flash.py" "$device"
