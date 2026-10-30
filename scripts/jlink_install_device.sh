#!/usr/bin/env bash
set -euo pipefail

project_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)
sdk_zip=${NS800_SDK_ZIP:-"$project_dir/vendor/NS800_SDK_v0.4.0.zip"}
pack_member=utilities/pack/MDK/NOVOSENSE.NS800RT7XXX.0.5.3.pack
config_base=${XDG_CONFIG_HOME:-"${HOME}/.config"}
device_dir=${JLINK_DEVICE_DIR:-"$config_base/SEGGER/JLinkDevices/NOVOSENSE/NS800RT7P65D"}
temp_dir=$(mktemp -d)
trap 'rm -rf -- "$temp_dir"' EXIT

if [[ -z "$sdk_zip" || ! -f "$sdk_zip" ]]; then
    echo "Set NS800_SDK_ZIP to a valid NS800 SDK v0.4.0 archive." >&2
    exit 1
fi

unzip -p "$sdk_zip" "$pack_member" > "$temp_dir/ns800.pack"

for loader in NS800RT7xxx_FlashBank1.FLM NS800RT7xxx_FlashBank2.FLM; do
    unzip -p "$temp_dir/ns800.pack" "CMSIS/Flash/$loader" > "$temp_dir/$loader"
    if [[ ! -s "$temp_dir/$loader" ]]; then
        echo "Failed to extract $loader" >&2
        exit 1
    fi
done

mkdir -p "$device_dir"
install -m 0644 "$project_dir/scripts/NS800RT7P65D.Devices.xml" \
    "$device_dir/Devices.xml"
install -m 0644 "$project_dir/scripts/NS800RT7P65D_CPU1.JLinkScript" \
    "$device_dir/NS800RT7P65D_CPU1.JLinkScript"
install -m 0644 "$project_dir/scripts/NS800RT7P65D_CPU2.JLinkScript" \
    "$device_dir/NS800RT7P65D_CPU2.JLinkScript"
install -m 0644 "$temp_dir/NS800RT7xxx_FlashBank1.FLM" \
    "$device_dir/NS800RT7xxx_FlashBank1.FLM"
install -m 0644 "$temp_dir/NS800RT7xxx_FlashBank2.FLM" \
    "$device_dir/NS800RT7xxx_FlashBank2.FLM"

echo "Installed NS800RT7P65D J-Link device support in $device_dir"
