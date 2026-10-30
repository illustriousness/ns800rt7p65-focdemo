# NS800RT7P65D NSSinePad RT-Thread SMP BSP

> **当前代码已接入 CANopen → CPU0 FOC 的真实异步控制桥接，不再是无输出协议模型。**
> CANFD1 使用经典 CAN 1 Mbit/s、Node-ID=1；上电不自动使能，需周期 RPDO 和显式控制字。
> 新桥接仅完成主机回归与构建，未烧录/运行电机验证。范围及旧 ZLG 工具限制见
> [CANopen 桥接说明](docs/CANOPEN.md)。下文归档结果不代表新桥接已通过实板验收。

当前 SguanFOC 库适配的 ADC/PWM、SMO/PLL 无感闭环、UART 修复，以及 SMP
探索过程见 [Bring Up 记录](docs/BRINGUP.md)。该记录合并了指定历史会话和
2026-10-08 实板验证；下文的“归档状态”描述 2026-09-14 BSP 快照。

## 归档状态

本目录是在 RT-Thread `54e5164064` 基础上完成的 NS800RT7P65D 双核 SMP
实板移植快照，目标芯片为 `NS800RT7P65D-DHQFOY2`。两个 Cortex-M7
运行同一个 RT-Thread 内核，线程可以通过 `RT_THREAD_CTRL_BIND_CPU` 分别绑定到
CPU0 和 CPU1；CPU1 不是独立运行裸机应用。

当前已在实板上验证 GCC 构建、双 Bank J-Link 下载与校验、冷上电启动、FinSH
交互、线程绑核、共享自旋锁计数和 MU 核间中断。板卡丝印为 v1.3，但现有资料中
原理图版本与该丝印的对应关系尚未得到厂商证实。

## 已确认硬件映射

| 功能 | 芯片引脚/资源 | 说明 |
| --- | --- | --- |
| 调试串口 TX | GP12 / UART1_TX | 115200 8N1 |
| 调试串口 RX | GP13 / UART1_RX | 115200 8N1 |
| LED1 | GPIO68 | 主线程每秒翻转状态 |
| 按键 | GPIO41 | 板级初始化已配置 |
| CPU1 镜像 | Flash Bank1 `0x08000000` | RT-Thread 内核和应用 |
| CPU2 引导镜像 | Flash Bank2 `0x08080000` | 跳入同一 SMP 内核 |
| CPU2 启动邮箱 | `0x2013FF00` | Bank2 引导与 CPU1 握手 |

## SMP 实现边界

- CPU1 初始化共享内存、MU 中断、硬件信号量和 CPU2 启动邮箱。
- CPU2 Bank2 镜像只负责最小启动，随后进入 CPU1 镜像中的 RT-Thread SMP 调度器。
- `.data`、`.bss`、线程栈和 RT-Thread heap 放在两核均可访问的 SRAM 区域。
- MU 用于核间调度中断；硬件 SEMA gate 保护软件自旋锁和原子操作。
- 当前按逻辑 CPU0 控制、CPU1 通信分工；UART IRQ/FinSH 迁到 CPU1，CAN
  分配给物理 CPU2。核归属靠约定，不增加逐次核检查。详见[核分工](docs/CORE_LAYOUT.md)。
- 当前 SMP 模式关闭 D-Cache；CPU2 idle 使用忙等，低功耗唤醒尚未完成。
- GDB 脚本调试 CPU1；尚未提供双核同步调试会话。

## 构建

在本 BSP 目录执行：

```bash
git submodule update --init --recursive
git -C libraries/SguanFOC_Library apply ../../patches/sguan-ns800.patch
scons --pyconfig-silent
./scripts/build.sh
```

SguanFOC 以 Git 子模块维护于 `libraries/SguanFOC_Library`，基于 v3.1.0 浮点库。
本板的算法修正与 `UserData_*` 配置以 `patches/sguan-ns800.patch` 发布，应用在
上游基点之上；`applications/sguan/` 仅保留硬件接口和构建集成。这样公开仓库
不依赖私有 fork，也能复现本项目的板级参数和 SMO 修正。
适配边界和升级方法见 [SguanFOC 适配说明](applications/sguan/README.md)。
当前上游基点为 `5680b9ebce89203df0790c5e2313e7fd812513e9`；本地修改的必要性、
保留/删除理由及隔离对照测试见 [改动审查](docs/SGUAN_CHANGE_REVIEW.md)。
当前已恢复 `Sguan_math.c/.h` 为该基点原样，使用原版查表和软件平方根，不依赖 eMATH。
原版 math 的短时实板启动、改速与停机测试结果见上述记录。
随后为最大复用又恢复了原版 SMO、IF/PLL 主体及 `SguanFOC.h`，仅保留小范围适配修正；
该收敛版本已重新纳入完整固件，另外完成两轮正转启动/改速/停机实板回归，
不沿用此前改写版的验收结果；记录见 [实板证据](docs/bringup_evidence/sguan_upstream_reuse_20261029/README.md)。
之后针对实测 PLL 高频抖动，仅修正 `Sguan_SMO.c` 的直接注入反馈路径，保留原版
硬 sign 和所有参数；500/800 rpm 对照及改速结果见
[SMO 修复实板证据](docs/bringup_evidence/sguan_smo_direct_feedback_20261030/README.md)。
这明显降低原始速度及控制角高频纹波，不代表低频速度波动、带载或可靠性均已解决。

构建会同时生成以下文件，但这些生成物不纳入 Git：

| 文件 | 用途 |
| --- | --- |
| `rtthread.elf` / `rtthread.bin` | CPU1 主镜像 |
| `rtthread_cpu2.elf` / `rtthread_cpu2.bin` | CPU2 最小引导镜像 |

GCC 启动文件由本仓库维护：`board/startup/startup_NS800RT7xxx.S`。
`SConstruct` 将依赖包默认的启动文件替换为此文件，CPU1 和 CPU2 均使用它，
无需修改或强行跟踪被忽略的 `packages/` 文件。CPU1 启动时复制 `.fast` 到
ITCM，CPU2 的链接脚本提供空复制区间。更新依赖包不会覆盖该启动逻辑。
构建后运行 `python3 tests/startup_regression.py`，检查两份镜像仅链接本仓库
启动对象、关键 IRQ 向量顺序以及 ITCM 代码/Flash 装载区间。

## SDK 归档

J-Link Flash loader 和 pyOCD pack 来自 NOVOSENSE NS800 SDK v0.4.0。
公开仓库**不包含**该 SDK 压缩包，请从 NOVOSENSE 官方渠道获取，并设置：

```bash
export NS800_SDK_ZIP=/path/to/NS800_SDK_v0.4.0.zip
```

相关脚本默认查找 `vendor/NS800_SDK_v0.4.0.zip`；构建本身不需要该 zip，
只有 J-Link 下载/调试脚本需要。使用和再分发应遵守 NOVOSENSE 的授权条件。

## 许可证

本项目根代码采用 **Apache-2.0**，与 RT-Thread 一致。第三方组件保留各自许可证：

| 组件 | 许可证 |
| --- | --- |
| RT-Thread | Apache-2.0 |
| CANopenNode | Apache-2.0 |
| SguanFOC | MIT |

详见 [LICENSE](LICENSE) 和 [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md)。

## J-Link 下载与调试

指定要使用的原装 J-Link 序列号，然后下载：

```bash
export JLINK_SN=941000024
./scripts/jlink_flash.sh
```

脚本会安装本目录的自定义 J-Link device XML，并从 SDK pack 中提取两个官方
FLM，随后分别下载和校验 Bank1、Bank2。CPU1 调试入口为：

```bash
export JLINK_SN=941000024
./scripts/jlink_debug.sh
```

`flash_swd.sh` 和 `debug.sh` 保留为 pyOCD/DAPLink 备用路径。CPU2 已运行后，
pyOCD 的 reset/attach 可能失败；UART ISP 是恢复路径，使用前必须让芯片进入
UART ISP 模式。

## 串口与验证

调试串口为 UART1、115200 8N1。推荐使用稳定的 by-id 设备路径：

```bash
python3 -m serial.tools.miniterm \
  /dev/serial/by-id/usb-SEGGER_J-Link_000941000024-if00 \
  115200 --rts 0 --dtr 0 --eol CR
```

当前串口使用 Serial V1：RX 为硬件 FIFO + 接收中断，控制台 TX 为轮询；
驱动没有实现 DMA 接收。运行期 UART RX IRQ 和 FinSH 在逻辑 CPU1，ADCA
IRQ 在逻辑 CPU0，通信中断不再占用控制核。SysTick/PendSV/MU 仍各核保留。
全局 `PRIMASK` 关中断临界区仍会延迟 ADC 进入；这不是 UART 抢占，且不包含
在 ISR 入口后开始计数的 `isr_cycles` 中。DMA 可减少接收中断次数，但并不能
消除内核或控制台的全局关中断临界区。

自动验证命令：

```bash
./scripts/smp_test.py /dev/ttyACM0
./scripts/ecosystem_test.py /dev/ttyACM0
```

`smp` 命令的关键判据为：

```text
ready=c020c020  mask0=1  mask1=2
shared ≈ cpu0 + cpu1
shell_cpu=1
```

`smp` 只读状态；停机后执行 `smp stress` 才运行约三秒的双核计数/自旋锁压测。
压测线程平时阻塞，不再每 10 ms 唤醒控制核。`scripts/smp_test.py` 会主动发起该压测，
不要在电机运行时执行。当前核分工修改仅完成构建和主机回归，尚未烧录实板验收。

归档前的实板结果包括：两核绑核线程在连续采样中同步增长、共享计数一致、MU
IPI 计数增长；冷上电后两核约 1 秒内各增长约 100 个 10 ms 工作周期；FinSH 的
`version`、`list device`、`ps`、`free` 和 `smp` 均通过。

## 已知调试器问题

在一只 `J-Link WiFi V12.00`（SN `941000024`，固件 2026-08-04）上观察到：
`tio 3.9` 退出后，探头的 VCOM 和调试 bulk 通道可能同时停止响应，物理拔插后
恢复。相同板卡换另一只 J-Link 后不复现，且 pyserial 连续开关串口也不复现。
因此该现象不属于 NS800RT SMP 停机；归档验证优先使用 pyserial、独立 USB-TTL
或已确认正常的 J-Link。

## 2026 RT-Thread 嵌入式大赛提交材料

论坛帖子草稿、腾讯文档填写清单、演示视频脚本和两张架构图见
[`docs/competition/`](docs/competition/)。提交前必须替换其中的仓库、视频、
许可证等占位符，并确认新 CANopen→FOC 桥接的实板验证边界没有被改写。

## 来源与维护

本移植基于 RT-Thread 主线已有的 NOVOSENSE NS800 BSP；原 BSP 维护人为
[tyustli](https://github.com/tyustli)。归档日期为 2026-09-14。
