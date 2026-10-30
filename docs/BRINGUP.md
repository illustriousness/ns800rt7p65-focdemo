# NS800RT7P65D 电机控制 Bring Up 记录

整理日期：2026-10-09。最近一次实板验证：2026-10-09。日期和时间按 Asia/Shanghai 解释。

NSSinePad NS800RT7P65D 已打通双核 RT-Thread SMP、双 Bank 下载、UART1 终端，以及 SguanFOC 库接管的 ADC/PWM、IF→SMO 无感闭环。24 V、ATK-BL57H95D20E 电机条件下，Sguan 库在实板完成 500 rpm 启动、接管和确认停机；转速结果来自观测器，尚未用独立测速仪或编码器核验。

本文合并了指定会话 `01a04299-ab93-77f2-887f-f56484199cfc` 的 2026-08-27 至 2026-10-08 调试过程，以及 2026-10-09 的 eMATH 固件重编译、烧录和实板闭环验证。

## 工程和硬件基线

| 项目 | 当前基线 |
| --- | --- |
| 工作目录 | `/home/ari/code/ns800rt7p65-focdemo` |
| 芯片 | NS800RT7P65D-DHQFOY2，双 Cortex-M7 |
| 板卡 | NSSinePad，实板丝印 V1.3 |
| 功率板和电机 | ATK-PD6010B、ATK-BL57H95D20E |
| 母线 | 用户确认 24 V，日志读数约 24 V |
| RT-Thread | 当前配置和启动日志为 5.3.1 |
| SDK | `vendor/NS800_SDK_v0.4.0.zip` |
| 当前实验探头 | J-Link V9.20，工具报告 SN=-1，命令行使用 `4294967295` |
| 控制台 | J-Link CDC/VCOM 桥接 UART1，115200、8N1、无流控 |
| 电机控制频率 | PWM/ADC 20 kHz；电流环和 SMO 同步执行 |
| 有效控制实现 | `applications/sguan/` 的 SguanFOC 库和 `ns800_foc_port.c` 适配层 |
| 旧自写控制 | `motor_openloop.c`、`motor_sensorless.c` 保留为历史对照，当前构建不编译 |
| 控制入口 | `motor/foc start|closed <rpm> <A>`、`motor/foc status`、`motor/foc stop` |

文档采集时 HEAD 为 `28c62820dac0`，工作树包含本轮尚未提交的修改。因此下面的源码和镜像结果属于“该 HEAD 加工作树修改”，不能只凭 HEAD 重建。镜像大小、SHA-256、证据文件校验值见 [manifest.json](bringup_evidence/manifest.json)。

### 板卡版本识别

历史会话最初参考 V3.1 文件推断板载外设，随后根据用户提供的 STM32F103RCT6、CAN 芯片丝印、JP3/JP4/JP5、没有 J11/J12/J14、按键 GP41 等实物特征，修正为“布局更接近 V1.2”。V3.1 文件标题栏还写有 V3.0，不能用文件名直接证明与 V1.3 实板对应。厂商版本对应关系仍未确认。

因此接线以实际芯片复用定义、已验证的引脚和实物连线为准；板载调试 MCU、CAN 收发器和跳线编号不照搬 V3.1。历史识别记录的原会话摘录只保存在本地归档，不随公开仓库分发；相关原记录行 116、135。

### 核心编号和存储布局

| 硬件资源 | 软件含义 |
| --- | --- |
| 物理 CPU1 | RT-Thread 逻辑 CPU0；UART1、ADCA、EPWM8/9/10 的所属核 |
| 物理 CPU2 | RT-Thread 逻辑 CPU1 |
| Bank1 `0x08000000` | 主镜像 `rtthread.bin`，共享 RT-Thread 内核和应用 |
| Bank2 `0x08080000` | `rtthread_cpu2.bin`，最小启动跳板 |
| 邮箱 `0x2013FF00` | CPU2 启动入口和握手信息 |
| J-Link AHB AP0 | 当前 CPU1 设备脚本所选 AP |
| J-Link AHB AP2 | 当前 CPU2 设备脚本所选 AP |

```text
物理 CPU1 / 逻辑 CPU0               物理 CPU2 / 逻辑 CPU1
Bank1 主镜像                       Bank2 最小跳板
  初始化共享内核                     读取启动邮箱
  配置外设归属                       跳入 Bank1 的 SMP 入口
  启动调度器                         进入同一调度器
             共享 SRAM、线程、调度状态
             SEMA：原子操作和自旋锁
             MU：跨核调度中断
```

CPU2 没有独立的电机裸机业务。`DUAL_CORE_ENABLE=0` 在本 BSP 中用于将外设配置到物理 CPU1，不能据此判断 SMP 或 CPU2 未启用。当前 SMP 关闭 D-Cache；CPU2 idle 使用忙等，低功耗尚未验收。

## 当前电机接线

下表中的 CN3 分配来自历史接线记录和 ATK-PD6010B V1.0 原理图；GPIO/ADC 复用与当前厂商头文件和直接驱动对应。NS800 与功率板必须共地，A3 接功率板的分压输出，不能接 24 V 母线原电压。

| 功能 | ATK CN3 | NS800 引脚 | 当前复用 |
| --- | ---: | --- | --- |
| PWM_UH | 17 | GPIO14 | EPWM8_A，ALT1 |
| PWM_UL | 18 | GPIO15 | EPWM8_B，ALT1 |
| PWM_VH | 19 | GPIO16 | EPWM9_A，ALT5 |
| PWM_VL | 20 | GPIO17 | EPWM9_B，ALT5 |
| PWM_WH | 21 | GPIO18 | EPWM10_A，ALT5 |
| PWM_WL | 22 | GPIO19 | EPWM10_B，ALT5 |
| AMP_IU | 10 | A0 / AIO227 / GPIOH pin 3 | ADCA channel 0，SOC0 |
| AMP_IV | 12 | A1 / AIO228 / GPIOH pin 4 | ADCA channel 1，SOC1 |
| AMP_IW | 14 | A2 / AIO229 / GPIOH pin 5 | ADCA channel 2，SOC2 |
| VBUS 分压 | 8 | A3 / AIO230 / GPIOH pin 6 | ADCA channel 3，SOC3 |
| CTRL_SD | 24 | GPIO23 | 普通输出，高电平使能 |
| UART1_TX | J-Link VCOM_RX | GPIO12 | ALT6 |
| UART1_RX | J-Link VCOM_TX | GPIO13 | ALT6 |
| GND | 7、16 和控制信号参考地 | NS800 GND、J-Link GND | 共地 |

GPIO14～19 的方案避开 UART1 GPIO12/13，以及历史 BSP 的 CANFD1 GPIO4/10 分配。VTEMP 曾规划到 A4/SOC4，但当前直接驱动仅配置 SOC0～3，温度保护没有据此接入。Hall、编码器和直接 BEMF 采样不是当前闭环反馈来源。

CTRL_SD 接线确认是带起过程的关键步骤。GPIO23 低时关断功率级，GPIO23 高且六路 PWM 有效时才允许输出。ATK 原理图包含过流电路；当前代码没有将 R_BREAK 配置为自动硬件 Trip 输入，不能把软件保护视为完整硬件故障链验收。

## 指定会话的历史调试过程

原始会话位于本机 Codex sessions；筛选后的用户/助手记录和工具输出保存在本地归档 `docs/bringup_evidence/history_*.jsonl`，**不随公开仓库分发**。每条包含原 JSONL 行号和时间，保留失败尝试及后续修正；本文只引用其行号。

### 单核工程和串口带起

8 月 28 日曾评估 `dual_servo_foc` 和 GD 功率板接管方案，属于方案讨论；当前实板路径后来采用 ATK 功率板，不能把 GD 的信号表当作当前接线。9 月 21 日按 ATK 原理图重新分配 EPWM8/9/10、ADCA 和 CTRL_SD，再进入 Sguan 移植。

2026-08-31 从 RT-Thread 基础工程启动 CPU1、SysTick、UART1 和 LED。初期通用 OpenOCD 连接失败，曾错误地怀疑供电或板上 S2；用户确认主控有电、BOOT=11 后，改用 pyOCD 0.45.1 和厂商 CMSIS-Pack，发现 AP 拓扑并成功读写 Flash、命中 `main()` 硬件断点。

该阶段写入约 19 KiB 镜像，`ping → pong` 双向串口测试连续三次通过。串口线程每 1 ms 轮询，而 `ping\r` 在约 0.43 ms 内到达，单字节接收缓冲 overrun；启用 RX FIFO 后恢复。该经验后来在完整 BSP 的串口设备层再次遇到，不能只在最小板级程序修正一次。

证据：历史消息原行 1098；这里的 pyOCD/OpenOCD 结果描述当时环境，不代表今天所有版本的支持状态。

### SMP 原子操作和 UART ISP 恢复

用户要求“RT-Thread 线程可以绑核”，明确排除了 CPU2 单独跑裸机业务的方案。初期跨核 `LDREX/STREX` 方案未可靠运行，改为硬件 SEMA 保护原子操作和自旋锁，MU 用于 IPI，CPU2 Bank2 仅作启动跳板。

旧 SMP 镜像锁死后，曾出现 AP1 共享内存还能读、CPU 调试 ROM 无效、pyOCD 报 `No cores were discovered`。能够发出 reset 与能够恢复核心发现、执行 Flash 算法是不同环节。保持 RESET 又遇到 SWD `WAIT ACK`，而 UART ISP 模式下 SWD 不可用，最终改为 ROM UART 协议直接下载。

历史恢复成功记录：

```text
芯片型号：NS800RT7P65DDHQFOY2
读保护：Level 0
MainFlash：全擦成功
CPU1 Bank1：24,164 字节，写入并全量读回一致
CPU2 Bank2：6,140 字节，写入并全量读回一致
```

ROM 写入末块按 8 字节粒度补齐。恢复 BOOT=11 后，绑核线程两秒分别增长 201 次，`mask0=1`、`mask1=2`，共享计数 `26846 = 13421 + 13425`，MU IPI 继续增长。这是 SMP 运行证据，不只是构建成功。相关历史记录为原行 1899、1993、2043、2072、2178、2283。

### J-Link 双 Bank 下载和完整 BSP

2026-09-01 先遇到主机设备库不识别 NS800、复位线接管不可靠、连接 DAP 后无法读取有效 CPUID。接入复位线并调整连接方式后，CPU1 读到 `CPUID=0x411FC272`、`MCM Core ID=1`，寄存器和 Flash 向量恢复可读。

早期认为官方 CMSIS FLM 不能直接复用，这个判断随后被修正：设备 XML 以 `FLASH_ALGO_TYPE_OPEN` 注册 Bank1/Bank2 官方 FLM，配合 AP 选择脚本完成 J-Link 双 Bank 写入和 `verifybin`。历史工具输出中保留了下载、验证和 GDB 结果。

冷上电后，两核 tick 一秒分别增长约 1005/1006，绑核线程各增长约 100，mask 固定为 1/2，共享计数一致，MU IPI 增长。FinSH、UART1、pin、线程表和堆检查通过。9 月 14 日会话记录曾归档到私有仓库 `illustriousness/ns800rt-rt-thread`，提交 `971f61604df80bc6558c8dbb50240a487a3fae98`；这是当时归档信息，不是当前工作树的提交。

9 月 21 日核对主线时也修正了一个表述：RT-Thread 主线具有通用 SMP 框架，但 NS800 的 CPU2 启动、MU、SEMA、双核上下文切换和链接布局属于本地平台适配，不能说“主线已经原生支持 NS800 SMP”。见历史原行 5269、7529、7712。

### 探头 VCOM 故障与目标 UART 故障的区分

2026-09-01，SN `941000024` 的 J-Link WiFi V12、当时探头固件 `2026-08-04`，出现第一次打开 `tio` 可收发、退出后第二次打开无数据的问题。

当时的证据包括：目标双核计数在串口沉默期间仍增长；端口释放、DTR/RTS、`SetHWFC Disable` 和 USB reset 未恢复；V9.10、V9.70 主机工具均复现；主机 GDB 看到 `JLINKARM_OpenEx → USBDEVFS_BULK` 对探头 bulk 端点反复超时。USB 枚举仍存在，换另一只探头后同环境不复现。结论限定为该探头的 USB/VCOM 数据路径异常，具体固件缺陷与硬件异常没有最终分离。

V9.72 独立工具及 V9.64 回退、再升回固件均有尝试，过程中多次更新后未自动重枚举，需要物理拔插。不能据此写成“回退或升级已永久修复”。这些历史问题也不能代替 10 月 8 日目标 UART 的断言诊断：后者有目标 MCU 的明确调用栈，且发生在另一只探头上。

当前实验探头报告 SN=-1，CLI 用无符号形式 `4294967295`，CDC 标识为 `004294967295`。不要用 `/dev/ttyACM` 编号猜设备。历史会话曾误把 CherryUSB ACM 当作控制台，用户随后纠正；它是另一块设备，本板控制台是 J-Link VCOM 到 UART1 的连线。

### Sguan 端口和初始化问题

当前构建已经切换到 SguanFOC 库：Sguan 的 `SguanFOC_High_Loop()`、`SguanFOC_Low_Loop()`、PID、SMO、PLL 和 SVPWM 运行在库内；`ns800_foc_port.c` 只负责 GPIO、EPWM、ADCA、保护、命令和 DWT 计时。旧自写控制文件不再加入 SCons。

2026-09-21 尝试 Sguan 无感算法，主要修复过程如下。

| 现象或检查结果 | 当时修复和结论 |
| --- | --- |
| 启动停在 `thread != RT_NULL` 断言 | `rt_hw_secondary_cpu_up()` 在创建线程前调用了 `rt_thread_mdelay(250)`；改为启动忙等待，不承诺该循环精确等于 250 ms |
| `.config` 与 `rtconfig.h` 不一致 | 恢复一次错误的配置生成，再核对宏和编译对象；用户随后要求绕过 RT-Thread ADC/PWM 设备层 |
| 直接厂商初始化后 `TBCTR/ETSEL/ETPS` 为 0 | 补 TBCLKSYNC；进一步确认初始化线程落到了错误核心，固定到逻辑 CPU0 |
| ADCA 中断进入 default handler/BKPT | 仅启用 NVIC 不会注册处理函数，补 `Interrupt_register()` |
| PWM 与算法周期不一致 | 当时 200 MHz EPWM 时钟、分频 2、上下计数，TBPRD=5000 得到 10 kHz；按 50 μs 控制周期改为 2500 |
| 在 PWM 零点中断读取 ADC | 同一时刻只刚开始转换，改在 SOC3 转换完成中断运行高环 |
| 对齐没有延时 | `User_Delay()` 是空实现，补线程毫秒延时 |
| 初始状态无法由 START 信号进入启动 | 状态机在低状态直接返回，改用 `Sguan.Func_Start/Stop()` |
| 高环运行但速度接近 0、只有几 mA 电流 | CTRL_SD 尚未接入和使能；确认 CN3-24 到 GPIO23 后继续试验 |

该阶段实测 A0/A1/A2 偏置约 1553/1545/1561 counts，VBUS 约 23.6 V，证明 ADC/PWM/中断计算链已运行，但这些结果本身不证明电机转动。当前直接驱动按实际 EPWM 时钟计算 TBPRD，不能继续复制旧固定周期值。

### HFI 和 NLFO 的失败过程

9 月 21 日接上 CTRL_SD 后，记录曾报告 500 rpm 目标下 HFI 估计约 494 rpm、Sguan `Real_Speed` 约 533 rpm。该阶段没有独立测速证据，速度 PI 目标电流还曾达到 −10.5 A 限幅，反馈却很小。10 月 8 日最后一条进展明确撤回了“实测成功”的表述：未能稳定重复，不能作为通过验收的基线。

1500 rpm 首次尝试记录为：目标 157.08 rad/s；`Real_Speed≈−74 rad/s`，HFI `Low_Wm≈−208 rad/s`，NLFO `High_Wm≈769.7 rad/s`，`Sensorless_Flag=0`。估计方向和幅值矛盾，未完成可信切换，随后停 PWM。

10 月 8 日继续尝试时，增加板内自主分段测试，减少克隆探头频繁 halt/continue。关键轮次如下，数字均为算法内部估算。

| 尝试 | 观察和后续调整 |
| --- | --- |
| 无编码器启动检查 | 恒为 0 的编码器回调参与了方向判定；限制速度 PI 电流，去除错误的启动判断 |
| 正向 500 rpm 分段 | 估计反向，出现约 −216/−299 rpm；未继续升速 |
| 负向 500→1000 rpm | 500 段融合约 −421 rpm；1000 段 HFI≈−1225、NLFO≈+1047 rpm，融合约 −36 rpm，停止 |
| 固定翻转 NLFO 符号 | 仍不稳定，改查高速 PLL 初值；不能只靠符号翻转 |
| 修正量纲和 PLL 初始化 | `OutWe` 是电角速度，机械速度需除极对数；初始化和输出方向约定仍多次不一致 |
| 继续融合试验 | 曾得到 371/677/860 rpm 的阶段估计，但 `Sensorless_Flag=0`，没有可信的 1500 rpm 接管 |
| 电流及 NLFO 增益调整 | 从 1 A 调到 2 A，把增益从 38,000,000 降到 3,800,000，重复性仍不足 |
| 改为模式 9 的 IF→NLFO | −52.36 rad/s 指令下，高速估计约 +503.95 rad/s、融合约 +330.35 rad/s；出现假锁相，最终报告失败并关闭 PWM |

早期自主测试部分阶段只检查速度绝对值下限，异常偏大的估计也可能被记为阶段“通过”。文档不据该标志认定目标转速达标。此会话最终未打通 1500 rpm；恢复模式 11、速度上限 60 rad/s、默认关断，属于退回实验配置，不代表该 HFI 配置已完成稳定性验收。

上述过程见历史原行 10642、10740、11165、11228、11273、11388、11426、11536、11560、11575，以及工具记录中的 `fail_stage` 报告。

## 本轮直接驱动和闭环带起

### 最小电压开环

2026-10-08 的独立驱动版本已经作为历史对照保留。当前版本把硬件所有权移回 Sguan 适配层，Sguan 库执行 IF 强拖、SMO/PLL 接管、电流 PI、速度 PI 和 SVPWM；目标端 `fast_sin_cos`、sqrt、atan2 通过 eMATH，移除了 Sguan 原有正弦查表。

短时测试达到 5 Hz、电流采样峰值约 1.66 A、无运行故障，随后停机。用户确认 `motor start` 能持续转动，但不太平顺。这是物理转动确认；5 Hz 是施加的电频率，不是测得的轴速，也不证明转子始终同步。

停机同时拉低 GPIO23，并对三路 EPWM 强制 One-Shot Trip，令死区模块之后的 A/B 输出都为低。只在 Action Qualifier 之前强制低电平，经过死区极性变换后不能保证两路最终都低。读回 GPIO23=0、三路 `TZFLG=0x4` 是当时的关断证据。

证据：[开环试跑](bringup_evidence/openloop_spin.log)、[关断寄存器](bringup_evidence/openloop_gates.log)。

### 电流方向和中断耗时修正

首轮电流环在对齐阶段触发 3 A 保护，峰值记录 3012 mA；`Id≈−2.898 A`，目标却为正，说明反馈方向不一致。ATK 低侧分流放大器为非反相输入，而定义为“从驱动板流向电机”的正相电流在低管导通时使分流电压下降，ADC 差值为负。因此当前转换使用负增益。

```text
                    −(raw − offset) · 3.3
I_phase [A] = ---------------------------------
                      4096 · 6 · 0.020

VBUS [V] = raw_vbus · 3.3 · 25 / 4096
```

零点在桥臂关闭时取 256 组样本。3.3 V、20 mΩ、6 倍增益和 25 倍母线分压是本驱动使用的比例；偏置不固定写死为 2048，实际约 1550 counts。

同轮测到中断函数体最坏约 58.117 μs，超过 50 μs 周期。将驱动和算法按 `-O2` 构建、将 PLL/速度 PI 分别降到 2 kHz/1 kHz 后，查表版本的后续测试函数体最大约 35～39 μs。该指标由 DWT 计数，不包含完整异常入口、退出和全部响应延迟。

证据：[首轮电流方向失败](bringup_evidence/current_direction_failure.log)。

### 当前控制时序

```text
同步 EPWM8/9/10 上下计数，20 kHz，1 μs 死区
  EPWM8 到 PERIOD，处于低侧导通采样窗口
    SOCA → ADCA SOC0/1/2/3，32-cycle 采样窗口
      SOC3 转换完成 → ADCA_CONV_IRQHandler
        读取三相电流和 VBUS，检查保护
        U/V 电流 → Clarke/Park → d/q 电流 PI
        上一周期估算施加电压和电流 → SMO → PLL
        速度 PI / 角度切换 → PWM 影子比较寄存器
```

W 相 ADC 用于监测、过流和死区补偿；当前 Clarke 由 U/V 重建。施加电压从占空比量化和死区模型折算，并非直接 BEMF ADC 实测。ADCA 高优先级 ISR 不调用 RT-Thread 服务或 SMP 原子锁；命令由绑定 CPU0 的电机线程消费，状态输出先复制一致快照，再开中断打印。

### eMATH 替换查表和 DWT 测量

当前电机控制路径已去掉角度查表：开环调制和 sensorless FOC 的 Park、逆 Park、启动角差统一调用厂商 `EMATH_sincosF32()`。PLL 的 `atan2`、相位补偿 `atan` 和幅值计算的 `sqrt` 分别调用厂商 `EMATH_atan2F32()`、`EMATH_atanF32()` 和 `EMATH_sqrtF32()`。目标固件不保留查表和软件数学回退；主机仿真才使用 libm。

eMATH 是共享硬件块，当前人为约定只有物理 CPU1，也就是 RT-Thread 逻辑 CPU0 的 ADCA 控制 ISR 可以访问。CPU2/逻辑 CPU1 不调用 eMATH；代码在进入 sensorless ISR 前检查逻辑 CPU 编号，所有权标志在电机启动重置状态时保留。这样避免 CPU2 线程和 20 kHz 控制中断同时写 eMATH 控制寄存器。

每次 `motor status` 会报告原始 DWT 周期：

```text
isr_cycles=last/max
control_cycles=last/max
emath_sincos=last/max/calls
emath_trig=last/max/calls
emath_sqrt=last/max/calls
```

旧自写控制版本的纯 eMATH 数据如下，保留作历史性能对照。当前 Sguan 版本仍由逻辑 CPU0 的 ADC ISR 独占 eMATH；2026-10-10 实板 Sguan 轮次测得最大 ISR 16,325 cycles / 40.812 μs，控制主体 13,061 cycles，overflow=0。目标固件不保留正弦查表；主机仿真才使用 libm：

| 测试 | eMath sincos 最大 | eMath atan/atan2 最大 | eMath sqrt 最大 | 控制主体最大 | 完整 ISR 最大 | 结果 |
| --- | ---: | ---: | ---: | ---: | ---: | --- |
| 历史自写版本 500→600→500 rpm | 250 cycles | 451 cycles | 269 cycles | 8712 cycles | 13424 cycles / 33.560 μs | 历史对照 |
| 历史自写版本 800→700→800 rpm | 270 cycles | 391 cycles | 269 cycles | 8834 cycles | 13380 cycles / 33.560 μs | 历史对照 |

控制主体统计包含 Sguan 算法和 PWM 比较值更新；完整 ISR 还包含 ADC 读取、保护、状态更新和中断路径。Sguan 实板轮次低于 20 kHz 的 50 μs 周期；最终镜像在电源域掉线后尚未再次实板复测。此前曾把 13,467 cycles 误换算成约 67 μs，正确值是 33.667 μs；该旧表述已撤回。

### 启动和接管条件

```text
idle
  → align：Id=0.5 A，对齐 0.5 s
  → current-ramp：旋转 d 轴电流矢量，按 150 rpm/s 升速
  → 独立 SMO/PLL 满足锁定条件并连续保持 0.4 s
  → blend：1 s 渐变到观测角度和速度 PI
  → closed：强拖角度停止推进，使用观测角度控制

任一保护触发 → fault → GPIO23=0 + EPWM One-Shot Trip
```

接管检查包括强拖已接近目标、至少 8 Hz 电频率、估算反电势大于 0.35 V、估算速度与强拖速度误差小于 25%、角差小于约 1.05 rad、PLL 相位误差小于 0.35 rad。强拖阶段 10 s 内锁定失败则关断；渐变和闭环分别检查失锁。

SMO/PLL 的观测计算没有输入强拖角度或强拖速度。强拖信号只用于启动、锁定比较和接管过程。验证还检查进入 closed 后 `forced_mrad` 固定、`angle_mrad` 继续变化，避免把继续强拖误称为闭环。

### 算法和保护参数

| 参数 | 当前值及含义 |
| --- | --- |
| 极对数 | 2 |
| Rs、Ls | 0.2 Ω、0.4 mH，电机初值，未在本板完成参数辨识 |
| 电流 PI Kp、Ki | 0.5 V/A、250 V/(A·s) |
| SMO gain、boundary | 6.0 V、0.8 A |
| 反电势滤波极点 | 800 rad/s |
| PLL Kp、Ki | 200 s⁻¹、10000 s⁻² |
| 速度反馈低通极点 | 30 rad/s；保留原始 PLL 速度用于诊断 |
| 速度 PI Kp、Ki | 0.0015 A/rpm、0.004 A/(rpm·s) |
| q 轴目标电流限幅 | ±1.2 A |
| 相电流软件关断门限 | 3 A；同时检查 ADC 近满量程饱和 |
| 允许母线范围 | 12～30 V |
| 闭环指令范围 | 350～800 rpm 的正反向指令，禁止 `speed` 直接跨零换向 |
| 启动电流参数 | 0.5～1.2 A，指强拖 d 轴目标，不是母线电流或全程峰值上限 |

默认 `motor closed` 使用 500 rpm、0.8 A。`motor start` 保持独立电压开环。两种模式没有用独立机械基准标定统一正方向，不能仅由指令符号比较物理方向。

电角速度和机械速度分别为 `ω_e`、`ω_m`，`ω_e = 极对数 · ω_m`。当前 2 极对电机的估算轴速换算为 `rpm_est = f_e · 30`；这里的 `f_e` 是观测器电频率，而开环命令 Hz 是施加频率。

## 终端断言和丢字符修复

### FinSH 在错误核心打开 UART

第一轮恢复终端时，CPU0 的 UART1 RX IRQ 未启用、向量仍为默认 handler，CPU1 的 RX IRQ 却已启用。FinSH 线程在第二核打开设备，将中断装到了错误 NVIC。

使用 FinSH thread-entry hook，在打开串口设备前把 `tshell` 绑定逻辑 CPU0。电机线程同样固定在 CPU0。修复后 `smp` 报 `shell_cpu=0`，CPU0 IRQ198 使能、向量指向 `UART1_IRQHandler`，`version/motor status/smp/ps` 均收到回复。

### RX 中断误走 TX 完成分支

用户人工输入后出现：

```text
(completion != RT_NULL) assertion failed
function: rt_completion_wakeup_by_errno
line: 309
```

先 attach、保存寄存器/栈/内存，没有先复位或烧录。Flash 与当时 BIN 一致；`IPSR=214`，减去异常偏移 16 后为 UART1_RX IRQ198。现场调用链：

```text
UART1_IRQHandler
  → uart_isr
  → rt_hw_serial_isr(event=2 / TX_DONE)
  → rt_completion_done(completion=NULL)
  → rt_completion_wakeup_by_errno
  → rt_assert_handler
```

现场 `TC=1、TCIE=0、serial_tx=NULL`。终端轮询发送，没有 TX completion FIFO；空闲 TC 状态本来就会置位，旧驱动却只看 TC，不看发送中断使能，因而误报 TX_DONE。

修复为分别检查 RX/TX 的中断使能和对应状态，并独立处理两类事件。另修复 `CLR_INT(TX)` 时无条件关闭 RX NVIC 的错误。没有删除内核 completion 断言来掩盖错误事件。

证据：[原始调用栈](bringup_evidence/uart_assert_stack.log)。其中 PC/代码地址属于断言时旧镜像，不能直接拿当前 ELF 对这些地址做 addr2line；现场文本已包含当时解析出的函数和源码行号。

### RX overrun 和 FIFO 接收

首次只修中断分类后，原生 `tio` 突发输入再次丢字并无回复。现场 `OR=1、RDRF=0`，硬件 RX FIFO 关闭。之前自动测试每个字符延迟 5 ms，未覆盖这一条件。

当前 serial v1 配置启用 RX FIFO，水位为 0，从首字节触发；`getc()` 根据真实 RXCOUNT 排空，避免根据残留 RDRF 去读空 FIFO。RX overrun、帧错误、噪声、奇偶校验错误中断也随 RX 一起启停，错误可以清除并继续接收。TX 保持轮询方式。

证据：[overrun 现场](bringup_evidence/uart_rx_overrun.log)、[150 条原生 tio 回归](bringup_evidence/tio_150_commands.log)。

### 隐藏控制字符和键盘编辑

现场接收环里有 `0x17`，即 Ctrl-W；当时 `FINSH_USING_WORD_OPERATION` 关闭，控制字符可能进入命令内容，让屏幕看起来正常的命令返回 −22。启用删词及编辑扩展后，进一步修复 Ctrl+Arrow 的 `CSI 1` 前缀与 `Home CSI 1~` 冲突，并支持 `CSI H/F` 的 Home/End。

回归覆盖退格、Ctrl-W、Tab、历史键、两类 Home/End、Delete、Ctrl+左右、额外空格和连续粘贴，共 150 条原生 `tio` 命令。尾部空格由原有 `msh_split` 处理，没有增加兼容解析层。`motor sstatus` 仍是非法子命令。

### CPU2 启动超时误报和复位记录

旧代码在 `rt_hw_secondary_cpu_up()` 中等待 `READY=c020c020`，而 CPU0 正持有 `_cpus_lock`，CPU2 必须等 CPU0 启动调度器释放锁后才可能完成首次上下文切换，因此日志总会等到 timeout。

当前先等待 `STARTING=c0200002` 入口握手，打印 `CPU2 boot ready`；真正的 READY 标志仍由 CPU2 首次切换后设置，后续 SMP 测试验证两个核心的计数和 mask。

原先用户报告的两次复位，没有逐次清除的原因记录，`0x301f` 混有历史标志，不能把复位统一归因于 UART 断言、FOC 或供电。新增启动时保存 reset 状态、由主核清除其 sticky 标志，`resetinfo` 输出原始记录。CPU2 只读状态仍可能保留自身历史，不能把它当作每次启动都已清零的原因。

修复后在停机状态执行一次主动 `reboot`，捕获到 `CPU2 boot ready`、`sys=00002010`，重启后 `ready=c020c020`、`shell_cpu=0`。这是受控软件重启验证，不是复现先前未知原因的异常复位。见 [warm_reset.log](bringup_evidence/warm_reset.log)。

## 实板验证结果

以下峰值为 ADC 换算的相电流，转速误差为滤波估算值相对指令的稳态误差。累计 overflow 可包含停机或启动历史，验收检查的是驱动运行期间没有新增溢出。

| 测试 | 总测试时间 | 闭环采样数 | 相电流峰值 | ISR 函数体最大值 | 结果和证据 |
| --- | ---: | ---: | ---: | ---: | --- |
| 正向 500→600→500，启动 0.8 A | 30.701 s | 49 | 1.427 A | 35.240 μs | 稳态最大误差依次 10/6/7 rpm；结束 idle；[日志](bringup_evidence/sensorless_forward_500.log) |
| 反向 −500→−600→−500，启动 0.8 A | 18.667 s | 25 | 1.204 A | 39.057 μs | 三段最大误差 13/4/8 rpm；结束 idle；[日志](bringup_evidence/sensorless_reverse_500.log) |
| 最终固件 800→700→800，启动 1.2 A | 20.682 s | 25 | 1.578 A | 39.120 μs | 三段最大误差 2/3/3 rpm；累计 overflow=0；结束 idle；[日志](bringup_evidence/sensorless_final_800.log) |
| 纯 eMATH 500→600→500，启动 0.8 A | 19.17 s | 25 | 1.346 A | 33.560 μs | 目标端无查表且 eMATH 计数有效；累计 overflow=0；[最终日志](bringup_evidence/sensorless_emath_500_final.log) |
| 纯 eMATH 800→700→800，启动 1.2 A | 20.76 s | 25 | 1.593 A | 33.560 μs | 目标端无查表且 eMATH 计数有效；三段通过；累计 overflow=0；[最终日志](bringup_evidence/sensorless_emath_800_final.log) |
| 原生 tio 编辑及粘贴 | 150 条命令 | 不适用 | 不适用 | 不适用 | 全部返回预期 idle 状态和 prompt，无断言或卡死 |
| SMP 最终验证 | 两个采样窗口 | 不适用 | 不适用 | 不适用 | 两个计数各 +202、mask=1/2、shared=13408、shell_cpu=0；[日志](bringup_evidence/smp_final.log) |
| RT-Thread 生态 | version/device/ps/free/smp | 不适用 | 不适用 | 不适用 | [检查通过](bringup_evidence/ecosystem_final.log) |
| 双 Bank 下载 | 一次最终下载 | 不适用 | 不适用 | 不适用 | 两次 `Verify successful`；[下载日志](bringup_evidence/flash_final.log) |

更早一轮 800→700→800、每段保持 8 s 的约 33 s 测试也通过；最终镜像增加启动握手修复后又完成表中的约 21 s 复测。这里不将多轮测试拼接成一次连续长时间耐久验收。

JSONL 轨迹及自动汇总见 [validation_summary.json](bringup_evidence/validation_summary.json)。正向 500/600 记录中累计 overflow 保持为 141，它是历史值；最后 800 记录为 0。各轮 closed 后强拖角度分别保持 −1320、+1320、−340 mrad，观测角度持续变化，`transitions=1`。

主机独立 PMSM 电气/机械模型还验证了正反转、负载/速度变化、Rs/Ls 偏差、堵转拒绝接管、接管后堵转关断、重启状态清零和非法采样保护，并通过地址/未定义行为检查。仿真堵转测试不代替实板堵转或带载验证。

最终构建记录为 CPU1 `text=126360、data=1312、bss=31076` 字节，CPU2 `text=1780、data=0、bss=20912` 字节。见 [build_final.log](bringup_evidence/build_final.log)；这些值不能代替对当前工作树重新构建后的资源检查。

## 重现构建和终端操作

### 配置和下载

```bash
cd /home/ari/code/ns800rt7p65-focdemo
scons --pyconfig-silent
./scripts/build.sh

export JLINK_SN=4294967295
./scripts/jlink_flash.sh
```

下载脚本默认 SN 为 `941000024`，当前接线用 `4294967295`，必须显式选择。脚本同时写入并校验两个 Bank，最后 reset/run。当前脚本的实际下载速度参数硬编码为 `4000k`，不要以为修改 `JLINK_SPEED` 就会改变下载速度。

### 打开控制台

```bash
tio -b 115200 -f none --no-reconnect \
  /dev/serial/by-id/usb-SEGGER_J-Link_004294967295-if00
```

连接后回车应出现 `msh >`。用 Ctrl-T 后按 q 退出。CDC 是探头的 UART 桥，不是 NS800 目标 USB 控制台；使用 by-id 避免 ACM 编号变化。

### 开环和闭环命令

逐条执行并观察状态，不把所有启动、改速、停止命令整块粘贴。

| 命令 | 含义 |
| --- | --- |
| `motor status` 或 `motor` | 查看状态；闭环还有估算速度、锁相、接管次数和 ISR 耗时 |
| `motor start` | 默认 5 Hz 电频率、1.0 V 电压开环 |
| `motor start <Hz> <V>` | 有符号电频率绝对值 0.5～10 Hz；幅值 0.6～2 V |
| `motor closed` | 默认 500 rpm、0.8 A 的电流强拖和无感接管 |
| `motor closed 800 1.2` | 800 rpm 指令、1.2 A 强拖 d 轴电流目标 |
| `motor speed 700` | 已进入 closed 后，同方向 350～800 rpm 改速 |
| `motor stop` | 请求关断并清除软件故障；随后确认 idle |
| `smp`、`ps` | 检查两核运行和 tshell/motor 的 CPU0 绑定 |
| `resetinfo` | 查看启动时保存的复位状态 |

从开环切到闭环：先 `motor stop`，用 `motor status` 确认 idle，再执行 `motor closed`。默认 500 rpm 通常数秒后接管；800 rpm 升速时间更长。改速前确认 `motor run fault=none`、`loop=closed`、`err=0`、`transitions=1`。

`motor stop` 是由电机线程处理的请求，不能把命令返回当作关断完成的证据。应检查 `state=idle`、`electrical_mHz=0`；若采样异常持续，清除后还会再次 fault。停机后部分控制器字段保留最后一次值，`loop=stopped` 下的 `est_rpm` 不是持续测量的自由滑行轴速。

### 主机和实板回归

```bash
python3 tests/uart_irq_regression.py

cc -O2 -Wall -Wextra -Werror -Iapplications \
  tests/motor_sensorless_sim.c applications/motor_sensorless.c \
  -lm -o /tmp/motor_sensorless_sim
/tmp/motor_sensorless_sim

./scripts/ecosystem_test.py \
  /dev/serial/by-id/usb-SEGGER_J-Link_004294967295-if00
./scripts/smp_test.py \
  /dev/serial/by-id/usb-SEGGER_J-Link_004294967295-if00

tio -b 115200 -f none --no-reconnect \
  --script-file tests/console_edit.lua \
  /dev/serial/by-id/usb-SEGGER_J-Link_004294967295-if00

./scripts/sensorless_test.py --start-rpm 800 --next-rpm 700 \
  --current 1.2 --hold-seconds 4 --log /tmp/ns800-new-trial.jsonl
```

`console_edit.lua` 会先停机再测试，完成标志为 `CONSOLE_REGRESSION_PASS 150 native tio commands`。闭环脚本独占串口、检查接管/电流/50 μs 函数体界限/运行期间新增溢出/强拖角度冻结，并在 finally 中请求和确认停止。脚本的速度容差是单点最大 50 rpm、均值 25 rpm；表中的实测误差比门限更小。运行实板脚本前退出其他 `tio` 会话。

## SguanFOC 当前实板结果

最终可观察到的实板轮次：`motor closed 500 0.8` 在约 7 s 进入 `loop=closed`，`transitions=1`，估计速度约 486～504 rpm，峰值相电流约 1.14 A，随后 `motor stop` 确认 idle。后续复测出现一次 ADC overflow，控制器没有立即停机并继续进入闭环；当前适配层只在连续 3 个转换周期溢出时关断，单次事件仍会累计记录。该轮次 ISR 峰值约 52.86 μs，说明仍需继续优化周期裕量，不能把它写成严格 50 μs 通过。

独立 Sguan 库模型覆盖正向 500 rpm、反向 500 rpm、正向 800 rpm 和堵转拒绝，四项均通过；模型不是实板机械测速证明。

## J-Link 现场诊断

现有 `scripts/jlink_debug.sh` 会执行 `monitor reset`，适合重新启动调试，不适合保留断言现场。现场 attach 用独立端口，先检查已有 J-Link/GDB 进程和探头 SN，避免连到另一块 RISC-V 设备的残留服务；历史会话曾因此收到错误 target 描述。

PWM 硬件在 CPU halt 时仍可能持续输出固定占空比，ADC 软件保护也会暂停。先停机或独立确认 CTRL_SD 已低，再 halt。若 UART 已死，应先检查关断状态，不能仅依据断言文字假定功率级关闭。

```bash
JLinkGDBServer \
  -select USB=4294967295 \
  -device NS800RT7P65D-DHQFOY2 \
  -if SWD -speed 1000 \
  -noreset -nohalt -noir -localhostonly 1 -nogui \
  -port 23341 -swoport 23342 -telnetport 23343
```

在另一个终端使用与板上镜像匹配的 ELF：

```text
arm-none-eabi-gdb rtthread.elf
set pagination off
target extended-remote :23341
monitor halt
info registers
bt full
p uart_obj[0].serial.serial_tx
p *shell
p state
p fault
p adc_count
p adc_overflows
x/wx 0x40042014
x/wx 0x40042018
x/wx 0x400A004C
```

UART STAT/CTRL 地址分别为 `0x40042014/0x40042018`；GPIOA DATA 为 `0x400A004C`，GPIO23 对应 bit23。读取 UART DATA 会消耗接收字节，不用跨过 DATA 的整段寄存器读取来调查丢字。CPU2 使用设备名 `NS800RT7P65D-DHQFOY2_CPU2`；目前没有统一停住双核的 GDB 工作流，停一核时另一核仍会修改共享内核状态。

保存现场时一并保存 ELF、BIN、MAP、寄存器、回溯、状态和所需内存。不要重新构建后再用新 ELF 解释旧 PC。detach/关闭 GDB 会话可能恢复 CPU，应以实际功率级状态管理输出。

### UART ISP 恢复

只在调试接管确实失败、且已关闭功率级时进入恢复流程。历史启动选择记录为：

| GP72 | GP84 | 模式 |
| ---: | ---: | --- |
| 1 | 1 | Flash 用户程序 |
| 0 | 1 | UART ISP |
| 1 | 0 | CAN FD ISP |

UART ISP 下使用实际桥接到 UART1 的设备路径：

```bash
./scripts/flash.sh /dev/serial/by-id/usb-SEGGER_J-Link_004294967295-if00
```

该脚本执行 MainFlash 全擦、双 Bank 写入和读回比对，会替换两个镜像。完成后恢复 GP72/GP84=11 并复位。UART ISP 与 FinSH 是不同固件入口，不能在正常 msh 模式直接执行 ISP 下载。

## 故障判断和验收边界

| 输出或现象 | 判断和处理 |
| --- | --- |
| `command failed -16` | 忙、未 idle、未校准或尚未 closed；按命令前提确认状态，不直接重复启动 |
| `command failed -22` | 子命令、参数或隐藏控制字符不合法；修复后 Ctrl-W/编辑/尾空白均已验证 |
| `fault=current` | 软件相电流/ADC 饱和保护；检查方向、采样、接线和电流目标 |
| `fault=adc` | 驱动运行时转换溢出，或采样长时间不更新；先保持关断并检查周期/关中断时间 |
| `fault=observer`、`err=1/2/3` | 分别为没有锁定、失锁、数值非法；不能把估计值当作通过条件 |
| TC=1 但 TCIE=0 | 轮询/空闲发送状态，不能报告 TX_DONE |
| OR=1、RDRF=0、输入停滞 | 检查 RX FIFO、真实 RXCOUNT、错误 IRQ 和错误清除，不以延迟逐字脚本代替粘贴测试 |
| 部分通用寄存器为 DEADBEEF | 可为新线程未用寄存器的填充值；须结合 PC/SP/总线读取判断，不能据单个值判 AP 丢失 |
| 核心和双核计数正常，但 VCOM 与 bulk 均不响应 | 对照历史探头问题，定位探头数据面；不直接归因目标 MCU |
| 估计速度很好看，但无可信接管 | 参考历史 NLFO 假锁相；检查来源、目标容差、角度、估算和独立机械反馈 |

当前实板覆盖的是这套接线、24 V 和几次短时试验，尚不构成 350～800 rpm 全范围、带载、堵转、温升、长时间运行或可靠性验收。HFI 静止/极低速、1500 rpm、硬件故障 Trip 输入、独立轴速基准和电机参数辨识仍需单独推进。历史低速 HFI 报告不能填补这些边界。

## 源码和证据索引

| 文件 | 职责 |
| --- | --- |
| [sguan/ns800_foc_port.c](../applications/sguan/ns800_foc_port.c) | Sguan 库的 GPIO、EPWM、ADCA、保护、命令和 DWT 适配 |
| [sguan/SguanFOC.c](../applications/sguan/SguanFOC.c) | Sguan 的电流 PI、SMO、PLL、速度 PI 和 SVPWM 库主体 |
| [sguan/Sguan_math.c](../applications/sguan/Sguan_math.c) | eMATH 正弦、sqrt、atan2 适配；主机仿真使用 libm |
| [applications/SConscript](../applications/SConscript) | Sguan 单一控制所有者，排除旧自写控制文件 |
| [smp_port.c](../board/smp/smp_port.c) | CPU2 启动、SEMA、MU、上下文切换及 FinSH 绑核 hook |
| [drv_uart.c](../libraries/HAL_Drivers/drivers/drv_uart.c) | RX FIFO、IRQ 源判断、RX/TX 独立控制 |
| [shell.c](../rt-thread/components/finsh/shell.c) | 终端按键处理，Home 与 Ctrl+Arrow 前缀修复 |
| [board.c](../board/board.c)、[main.c](../applications/main.c) | 启动复位状态保存和 resetinfo |
| [J-Link XML](../scripts/NS800RT7P65D.Devices.xml) | 两个 AP 设备和官方 FLM 的注册 |
| [UART 回归](../tests/uart_irq_regression.py) | 对实际 ISR/control/getc 函数建立 IRQ/FIFO 模型验证 |
| [电机仿真](../tests/motor_sensorless_sim.c) | 独立电气和机械模型及异常测试 |
| [终端实板回归](../tests/console_edit.lua) | 原生 tio 的 150 条编辑和粘贴命令 |
| [闭环实板回归](../scripts/sensorless_test.py) | 有界运行、估算速度响应、冻结强拖角度和确认停止 |

证据目录的完整文件、来源会话、摘录行号、镜像指纹和校验值均见 [manifest.json](bringup_evidence/manifest.json)。原始完整会话没有复制到仓库；归档保留与本板调试直接相关的消息、工具结果和原始实验日志。
