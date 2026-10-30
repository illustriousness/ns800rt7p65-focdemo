# CAN / CANopen / CiA 402 真实 FOC 桥接

## 当前范围

当前代码把 CANopen 控制字接到 **CPU0 的真实异步 FOC 请求接口**，不再仅改变协议模型。
新桥接已烧录，完成 CAN 常驻时的 UART owner 运行与安全交接实测；**尚未完成经 CAN 命令启停电机的实板验收**。

- 上电先保持 GPIO23 低、三相 PWM Trip 关断，FOC 初始化/校准不等于使能输出。
- 只有 Operational 中的合法周期 RPDO 建立控制授权，且经过显式 shutdown/switch-on/enable 才提交 START。
- 收到控制字不直接报告 Operation enabled。桥接等待确切 `command_seq` 成功，
  并等待 FOC 从 `arming` 进入 `starting/closed`，确认原有三拍输出释放已完成。
- `0x606C` 使用控制核发布的估算速度换算为机械 rpm，绝不把目标速度复制为反馈。
  停机后保留最后估计，不将关输出冒充轴已静止。
- `0x2000=1` 表示软件电机后端已连接，**不表示已经接好电机/已检测到物理电压**；
  `0x2003=0` 表示不是旧协议台架。
- 启动目标限 ±350～800 rpm；进入闭环后同向改速可到 ±2500 rpm。2500 rpm 新范围只做过
  正向空载实板测试（通过 UART owner），不代表反转/带载/CAN 命令验收。0、HALT 或运行中反向请求先关输出，并回到 Disabled，
  不自动反向重启。无 Hall/编码器时，重新反向使能前需人工确认机械已停稳。
- `0x605A=0` 的 Quick stop 使用立即失能，不是受控减速。没有零速保持、位置模式或
  加减速轨迹；删除此前“只存数值不执行”的 `0x6083/6084`，访问会明确 abort。
  因此这是受限速度控制桥接，不宣称完整 Profile Velocity 或 CiA 402 一致性认证。

## 硬件与核分工

| 项目 | 当前设置 |
| --- | --- |
| 控制器 | CANFD1，**经典 CAN**，11 位标准帧，0～8 字节 |
| 引脚 | GPIO4/TX、GPIO10/RX，板上开关选择收发器 |
| 位速率 | 1 Mbit/s |
| CANopen Node-ID | 1，首版固定 |
| ZLG | USBCANFD-100U，设备类型 33、索引 0、通道 0，终端开启 |
| IRQ / CANopen / FinSH | RT-Thread 逻辑 CPU1，即物理 CPU2 |
| CPU0 | ADC EOC 跑 FOC，慢线程处理异步请求并发布六字段状态 |

协议栈采用 CANopenNode v4.1，子模块固定到
`ac2140717c3c498d9b0351bce052bab630a74764`，不改上游源码。只编译所需 301 模块，
由单一 CPU1 线程执行协议与 OD；硬件 ISR 只处理 RT-Thread CAN 队列。
没有新增逐次核检查。CAN 的全局时钟源由主核配置，运行期由通信核启用本核时钟、
经 SYSCON 复位 CAN；UART 向量表也使用第二核本地 DTCM 的可写副本。

## 已接入协议

- NMT 从节点：Pre-operational、Operational、Stopped、Reset node、Reset communication。
- Boot-up 和 500 ms Heartbeat producer。
- SDO Server：加速/分段传输，标准 abort 响应。
- 固定 RPDO1：`0x6040:00` 控制字 16 bit + `0x60FF:00` 目标速度 32 bit，6 字节。
- 固定 TPDO1：`0x6041:00` 状态字 16 bit + `0x606C:00` 速度反馈 32 bit，6 字节，10 ms。
- 402 FSA：shutdown、switch on、enable operation、disable、quick stop、fault reaction、fault reset 边沿，
  以控制核命令确认和实际输出状态推进，不再靠收包直接完成使能/停止。
- 模式 3；其他模式通过 SDO abort 拒绝。没有位置/回零/CSP/CSV/CST。
- EMCY producer：映射真实 FOC 故障及桥接错误，原来的协议故障注入对象已删除。
- `0x1018` 使用开发身份，vendor-ID=0，未冒用注册厂商号。
  真实桥接的 revision 为 `0x00020000`，区别于旧台架的 `0x00010000`。

| 报文 | CAN-ID |
| --- | --- |
| NMT | `0x000`，数据为命令 + Node-ID |
| EMCY | `0x081` |
| TPDO1 | `0x181` |
| RPDO1 | `0x201` |
| SDO 请求 / 响应 | `0x601` / `0x581` |
| Boot-up / Heartbeat | `0x701` |
| 原始链路验证 | `0x123` 原样回传到 `0x321` |
| 板端独立测试发送 | FinSH `co tx`，`0x456`，数据 `80 81 82 83 84 85 86 87` |

`generate_od.py` 是 OD 与 EDS 的唯一数据定义，生成 `OD.c`、`OD.h` 和
`NS800_FOC_BRIDGE.eds`。PDO 映射只读，不支持动态映射、SYNC、LSS、掉电保存或固件升级。
CAN owner 下 NMT reset 先发布 STOP，再重置协议/OD；UART owner 下只重置协议，不抢停本地运行。
不复位整片 MCU，也不清除驱动故障锁存。

## 控制流程与参数

| 对象 | 当前含义 |
| --- | --- |
| `0x6040/6041` | 控制字/经 CPU0 确认的状态字 |
| `0x60FF/606C` | 目标/估算机械速度，INTEGER32，单位 rpm |
| `0x2004` | 启动电流，500～1200 mA，默认 800 mA；仅停用且无待执行命令时允许修改 |
| `0x2005` | 固定控制超时 500 ms，只读 |
| `0x2006` | 原始 FOC 错误，高 16 位来源、低 16 位库状态 |
| `0x603F` | 桥接/CANopen 的 16 位错误码 |

当前控制包络集中定义在 `applications/sguan/foc_limits.h`：

| 项目 | 当前值 |
| --- | ---: |
| 启动转速 | ±350～800 rpm |
| 闭环同向改速 | ±350～2500 rpm |
| 估算超速关断 | 2750 rpm |
| 相电流软件门限 | 3.0 A |
| 运行母线窗口 | 22～27 V |

首轮联调建议先用已验证过的正向 500/600 rpm，默认 800 mA：

1. 等待控制核校准完成；上电和进入 NMT Operational 都不会自动启动。
2. SDO 选择模式 3，可在停用状态配置启动电流。
3. 主站以约 10 ms 周期发送 RPDO1：控制字 16 bit + 目标 rpm 32 bit，小端，共 6 字节。
4. 控制字 0x0006 等待 Ready，0x0007 等待 Switched on，0x000F 请求启动；也支持 Ready 后直接 0x000F。
5. 启动请求未确认/还在 arming 时不报告 Operation enabled。输出允许后可进入 Operation enabled；
   这不等于已经完成无感接管。接管期间的同方向目标更新先保存最新值，待 FOC closed 后提交改速。
6. 同方向改速等待上一命令完成，不反复发送相同 FOC 请求。连续目标更新合并为最新值。
   启动仍限 ±350～800 rpm；进入闭环后同向 `SPEED` 可到 ±2500 rpm。
7. 零目标、反向、HALT、Quick stop 或 Disable voltage 都先提交停止；Quick stop 0 最终进入 Disabled。
   常规 shutdown/disable-operation 分别在关断确认后回到 Ready/Switched on。

只读反馈速度，没有独立轴速来源。Statusword 的 bit4 在本适配中跟随控制核的输出释放状态，
不是对引脚或母线电压的独立测量。未实现 target-reached 判定，不伪造该标志。

### STOP、故障复位和断联

- STOP、disable、HALT 等意图在进入最新值 PDO 缓冲前锁存；同一批报文中后来的使能/改速
  不能抹掉已收到的停止。SDO 控制字的 disable/quick-stop/HALT 同样先锁存。
- NMT Stop、Pre-operational、Reset node、Reset communication 也在接收时锁存 STOP，
  清空旧控制字/目标及控制授权，即使同批报文又有 NMT Start 也不重放旧使能。
- 活动控制中 bus-off 或超过 500 ms 无合法 Operational RPDO，会请求 STOP 并锁存通信故障。
  SDO 查询、心跳、原始 echo、不合法/非 Operational RPDO 都不续期。初始无主站且已停机时不凭空报运行故障。
- 以上是 CPU1 任务级处理，不替代硬件急停/独立看门狗；不提供核心死锁下的独立关断保证。
- STOP 只关断，不清除 FOC 错误。Fault reset 上升沿单独提交 `FOC_RESET_FAULT`，等待 CPU0
  的实际结果；CPU0 在仍运行、连续 ADC 异常或现有电压/电流条件仍越界时拒绝清除。
  观察器类故障在停机时不能证明机械原因已解除，应排查后再显式使能。
- 复位不自动启动，恢复通信也不自动启动；需要新的 shutdown/enable 流程。Pre-operational 中
  可以通过 SDO 复位故障，但其他运行/使能位会被屏蔽。
- 默认控制权是 `motor owner=can`。可用 `motor owner uart` 交给 FinSH，切换会先提交 STOP，
  等 CPU0 确认 `stop_seq` 后才授予；切换期间两个来源都不能提交新的 START/SPEED/RESET。
  UART 拥有时 CANopen 只读并报告 Disabled，不能抢回执行；`motor owner can` 同样先 STOP，
   不自动恢复旧使能；返回 CAN 后须重新走 shutdown/enable 流程。
- 同一时刻只有一个 START/SPEED/RESET 来源，不并行竞争。FinSH 的 `motor status` 和
  紧急 `motor stop` 始终可用；本地 STOP 后远程不会自动重新启动。CPU0 合并确认了更新的
  本地 STOP 时，桥接也会结束原 STOP 的等待并锁存本地停止故障，不会卡在旧序号，
  也不会沿原 Ready/Switched on 路径继续启动。

| 错误码 | 含义 |
| --- | --- |
| `0x8100` | 活动控制的 RPDO 超时或 bus-off |
| `0xFF01` | 无效 RPDO/速度给定 |
| `0xFF02` | 请求发布或控制核执行失败 |
| `0xFF03` | 非预期本地停止/控制状态不一致 |
| `0xFF04` | 非有限或越界的速度反馈 |
| `0xFF11/FF12/FF13` | ADC/库/无感监控故障，完整原因见 `0x2006` |
| `0xFF14/FF15/FF16` | 相电流/估算超速/母线窗口故障，完整原因见 `0x2006` |

## 构建与验证

```bash
git submodule update --init --recursive
./scripts/build.sh
python3 tests/canopen_protocol_regression.py
python3 tests/foc_ipc_regression.py
python3 tests/foc_adc_regression.py
python3 tests/startup_regression.py
python3 tests/uart_irq_regression.py
```

下载前先确认旧固件电机已停机，并选择实际连接 NS800 的探头：

```bash
JLINK_SN=4294967295 ./scripts/jlink_flash.sh
```

主机复用用户提供目录的 ZLG 头文件/动态库，不复制闭源 SDK，也不修改另一项目。
原始 echo 工具不发送电机控制字，可单独检验链路：

```bash
/home/ari/code/quectel/exoskeleton/hip_motor/tools/zlg_can/zlg_link_test \
  classic 100 /tmp/opencode/ns800-classic-new.csv
```

**旧 `scripts/zlg_canopen_test.py` 是无电机台架工具，不用于新固件运行验证。** 它在发送
NMT/reset/enable 前检查 `0x2000/2003`，遇到真实桥接标记会拒绝执行。不能直接把旧台架
“使能/故障注入”测试当作新固件的安全电机测试。主机回归使用假 CPU0；最新实板验证走 UART owner，
不能混写为 CAN 命令运行或总线压力验收。见[速度包络与 owner 实板记录](bringup_evidence/sguan_speed_envelope_owner_20261030/README.md)。

输出文件必须不存在。ZLG 设备不能被其他抓包/控制进程同时占用。FinSH 使用
UART1/115200，`co` 查看协议/总线状态，`co tx` 独立发一帧，`ps/smp` 核对绑核。
`smp stress` 仍为手动三秒测试，不自动运行。

## 2026-10-29 无电机协议台架的历史实板证据

见 `docs/canopen_evidence/`：

- `classic_100.csv`：用户工具经典 CAN 1 Mbit/s，**100/100** 正确回传，ZLG RXE=0、TXE=0。
- CANopen 测试：Boot-up、Pre-operational/Stopped 心跳、SDO 加速/分段传输及 abort、
  RPDO/TPDO、402 状态迁移、EMCY、fault-reset 边沿、NMT reset、0～8 字节原始回传。
- 独立抓包实收 `0x456 / 8081828384858687`，不是只依据 MCU 的提交计数。
- UART `ps` 中 canopen、canpoll、tshell、main 绑定 CPU1；无 sguan 线程。
- SWD 读回 GPIOA DATA=`0x00003010`（GPIO23=0），三路 TZFLG 均为 `0x4`，
  CPU0 NVIC ISER2=`0`，ADC EOC IRQ 未启用。ELF 中无 Sguan/电机端口实现。

主机未启动或关闭后，MCU 心跳发送没有对端 ACK，TXE 会累积，曾在 UART 中记录到
122/128；这与有效连接时测试结束的 ZLG 零错误计数不是同一采样窗口，不能混写为
“全程两端错误计数均为零”。本轮没有测试物理电机行为。

以上记录对应旧 `motor_connected=0` 台架，**不能作为新 FOC 桥接的实板运行证明**。
