#!/usr/bin/env bash
set -euo pipefail

project_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)
jobs=${JOBS:-$(nproc)}

exec scons -C "$project_dir" -j"$jobs"
