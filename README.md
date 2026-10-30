# NS800RT7P65D Dual-Core RT-Thread FOC + CANopen

[中文详细说明](README_zh.md) · [比赛提交材料](docs/competition/) · [演示视频](https://github.com/illustriousness/ns800rt7p65-focdemo/releases/tag/v1.0-competition) · [CANopen 说明](docs/CANOPEN.md) · [FOC 状态](docs/FOC_STATUS.md)

NSSinePad NS800RT7P65D（双 Cortex-M7）上的 RT-Thread 5.3.1 SMP 电机控制平台：

- **逻辑 CPU0（物理 CPU1）**：20 kHz ADC/PWM、SguanFOC 无感 FOC、SMO/PLL、硬件关断；
- **逻辑 CPU1（物理 CPU2）**：UART/FinSH、CANopenNode v4.1、CiA 402 桥接、CAN 收发；
- 跨核只用异步命令邮箱和六字段、24 字节一致性快照；
- 支持 CAN/UART 控制权交接，交接先 STOP，确认 `stop_seq` 后才授予。

## 验证状态

| 项目 | 状态 |
| --- | --- |
| 双核 RT-Thread SMP、绑核、MU/SEMA、双 Bank 下载 | **实板通过** |
| 20 kHz 无感 FOC 500/600/800 rpm 启动、改速、停机 | **实板通过**（短时空载） |
| CANopen NMT/SDO/PDO/EMCY/402 协议台架 | **实板通过** |
| CANopen → CPU0 真实异步 FOC 桥接 | 固件已烧录，owner 交接及 UART owner 运行已实测；**经 CAN 命令的电机启停尚未验收** |
| 闭环同向改速到 2500 rpm | 24 V / 2.5 A 直流限流、正向空载短测通过；非带载/反转/长期保证 |

速度反馈来自 SMO/PLL 估算，不是编码器或独立测速仪。项目不宣称完整 CiA 402
一致性、零速保持、直接跨零换向或硬件安全认证。

## 快速构建

```bash
git clone --recursive https://github.com/illustriousness/ns800rt7p65-focdemo.git
cd ns800rt7p65-focdemo
git -C libraries/SguanFOC_Library apply ../../patches/sguan-ns800.patch
scons --pyconfig-silent
./scripts/build.sh
```

仓库已包含 `packages/` 依赖快照（CMSIS-Core、novosns-series），正常构建不需要联网。
公开仓库**不包含** NOVOSENSE NS800 SDK 压缩包；J-Link 下载/调试时从官方渠道获取，
并设置 `NS800_SDK_ZIP=/path/to/NS800_SDK_v0.4.0.zip`。

主要回归：

```bash
python3 tests/foc_ipc_regression.py
python3 tests/foc_adc_regression.py
python3 tests/canopen_protocol_regression.py
python3 tests/startup_regression.py
python3 tests/sguan_integration_regression.py
```

## 目录

| 路径 | 内容 |
| --- | --- |
| `applications/sguan/` | FOC 硬件端口、ADC ISR、命令邮箱、六字段状态、保护、FinSH |
| `applications/canopen/` | CANopenNode 集成、OD/EDS、CiA 402 桥接 |
| `patches/sguan-ns800.patch` | SguanFOC v3.1.0 本板适配补丁 |
| `tests/` | 主机回归、ARM 编译、启动/UART/核分工/ADC/IPC/CANopen 检查 |
| `docs/` | 架构、核分工、FOC 状态、CANopen 说明和实板证据 |
| `docs/competition/` | 2026 RT-Thread 嵌入式大赛论坛帖、腾讯文档清单、架构图 |

## 许可证

本项目根代码采用 **Apache-2.0**，与 RT-Thread 一致。第三方组件保留各自许可证：
RT-Thread/CANopenNode 为 Apache-2.0，SguanFOC 为 MIT，novosns-series 为 BSD-3-Clause。
详见 [LICENSE](LICENSE) 和 [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md)。

## 硬件

NSSinePad NS800RT7P65D、ATK-PD6010B 24 V 三相功率板、ATK-BL57H95D20E 无刷电机
（无编码器）、J-Link VCOM、ZLG USBCANFD-100U。CANFD1 经典 CAN 1 Mbit/s，
20 kHz PWM、1 µs 死区，ADCA 三相电流 + 母线电压，GPIO23/CTRL_SD 功率级使能。
