# 双核业务分工

以下编号为 RT-Thread 逻辑编号：CPU0 = 物理 CPU1，CPU1 = 物理 CPU2。
两个核心仍运行同一个 RT-Thread SMP 内核，不改成两个独立固件。

## 执行约定

| 资源/任务 | 执行核心 |
| --- | --- |
| ADC EOC、FOC 高低环、PWM/CTRL_SD | CPU0 |
| `sguan` 慢线程：初始化、处理启停/改速/故障复位请求、发布状态 | CPU0 |
| UART 收发中断、FinSH、命令解析与打印 | CPU1 |
| CAN 外设初始化、打开/关闭、收发及错误中断 | CPU1 |
| CANopen 协议、OD 和真实 FOC 控制桥接 | CPU1 的 `canopen` 线程 |
| CAN 周期状态读取及用户状态回调 | CPU1 的 `canpoll` 线程 |
| 主线程、LED、后续通信/分析业务 | CPU1 |
| SysTick、PendSV、MU 调度中断 | 每核保留 |

核归属靠以上约定，不在每次驱动调用中检查 CPU 编号，不增加通用防误用层。
后续 CAN 业务线程必须在启动前绑定 `NS800_COMM_CPU`，并在该线程中打开设备、
配置中断。ISR 不直接修改 Sguan 控制状态，控制请求交给 CPU0 慢线程处理。

当前启用 UART1 和 CANFD1（经典 CAN 1 Mbit/s、GPIO4/10）。CANopen 已连接真实
FOC 异步命令通道；基础总线曾通过实板验证，新电机桥接仍需单独验证。
CAN1 默认 GPIO18/19 与电机 PWM 冲突，不能直接启用。PinMux 在启动阶段完成，
不要在控制运行期间并行重配同一个 GPIO 端口的复用寄存器。

## 向量与外设归属

- 两个核心分别使用自己 DTCM 中的可写向量表。CPU1 在进入 SMP 调度器前，
  从共同主镜像复制系统异常向量，再安装本核 MU/UART/CAN 向量。
- NVIC、SysTick、SCB/PendSV 都是每核独立的，同一寄存器地址代表当前核心的实例。
- CAN1/CANFD1/CANFD2 的 CPUSEL 选择物理 CPU2；主核注册阶段配置全局 RCC
  时钟源，通信核打开设备时使能本核时钟门并通过 SYSCON 复位 CAN，再配置控制器。
  不从物理 CPU2 写只有物理 CPU1 可写的 RCC 外设复位寄存器。
- UART 的 CPUSELEN 保持共享，以保留 CPU0 早期启动日志和异常现场轮询输出。
  运行期收发中断只在 CPU1 的 NVIC 注册/使能，不是两核同时处理 UART。
- RT-Thread 的 CAN 硬定时器仍由系统 tick 检查，但其回调只发布一个计数值；
  真正读取 CAN 寄存器、调用状态/总线回调的操作转交 CPU1。没有新增 CPU0 外设 IRQ。

## 跨核命令和状态

`applications/sguan/ns800_foc_port.h` 提供通信线程接口：

```c
ns800_foc_request(FOC_START, 500.0f, 0.8f);
ns800_foc_request(FOC_SPEED, 600.0f, 0.8f);
ns800_foc_request(FOC_STOP, 0.0f, 0.0f);
ns800_foc_request(FOC_RESET_FAULT, 0.0f, 0.0f);
ns800_foc_status_read(&status);
ns800_foc_owner_set(FOC_OWNER_UART);   /* 先 STOP，确认后才授予 */
ns800_foc_owner_get();
```

- 请求异步执行，返回成功代表已发布，不代表已经启动/停止。
- 普通命令只有一个待处理槽位；未处理完时返回忙。CPU0 根据实际状态验证、执行，
  结果通过状态快照的 `command_seq/command_result` 发布。
- STOP 单独发布，不被改速覆盖；`stop_seq` 表示 CPU0 已完成关断请求。
  初始化过程中收到 STOP 不会在初始化结束后继续使能输出。
- CANopen 使用 `ns800_foc_submit(..., &sequence)` 取得实际发布序号，再等待快照确认。
  STOP 不清故障，Fault reset 是独立请求，成功后也不自动使能。
- 默认控制权是 CANopen；`motor owner uart` 可把 START/SPEED/RESET 交给 FinSH，
  `motor owner can` 再交回。切换先提交 STOP，等 CPU0 确认 `stop_seq` 后才授予；
  切换期间两个来源都被拒绝。UART 拥有时 CANopen 只读，不能抢回执行。
  `motor owner` 和 `co` 都会显示当前 owner。该约定不增加逐次核检查。
- 启动/改速/保护包络集中在 `applications/sguan/foc_limits.h`：启动 ±350～800 rpm，
  闭环同向改速到 ±2500 rpm，相电流 3.0 A、母线 22～27 V、估算超速 2750 rpm 关断。
  2500 rpm 新范围只做主机回归，未做全范围实板验收。
- CPU1 的多个命令来源在短本地临界区中串行发布；约定这些调用来自 CPU1 线程，
  不在 CAN ISR 中直接调用，不从 CPU0 反向发布。
- 只有 CPU0 读取实时 Sguan 状态，慢线程形成快照后发布；CPU1 只读快照。
  不再用 CPU1 的关中断假装保护 CPU0 正在更新的数据。
- 当前快照只有 `state/error/command_seq/stop_seq/command_result/speed` 六项、
  24 字节。保留理由、核内状态以及旧日志接口的退出方式见[最小状态清单](FOC_STATUS.md)。
- 通道采用对齐的 32 位发布和内存屏障，不调用 RT-Thread 的 SEMA 原子操作。
  状态读取最多尝试三次，冲突时返回忙。共享 SRAM 沿用当前关闭 D-Cache 的配置；
  以后启用 D-Cache 时必须先解决共享区一致性。

没有拆开 Sguan 高低环，也没有改动 PI/PLL/PWM/采样参数或放宽原有电机保护。
算法低环仍由 ADC ISR 每 20 个周期执行；线程慢环仅处理命令与状态。

## 诊断与验证

`main` 和 LED 移到 CPU1。`cpu0w/cpu1w` 仅在 `smp stress` 后运行约三秒，平时
阻塞；此压测约定只在电机停机时执行。`smp` 中 `shell_cpu` 应为 1。

```bash
./scripts/build.sh
python3 tests/foc_ipc_regression.py
python3 tests/core_role_regression.py
python3 tests/startup_regression.py
python3 tests/uart_irq_regression.py
python3 tests/sguan_integration_regression.py
```

新桥接只完成构建和主机测试，**未烧录、未启动电机**。基础 CAN 收发通过不等于
经 CAN 的电机启停已通过；后续应先停机检查两核 IRQ 归属，再分阶段验证真实
启动/改速/关断与通信断联。精简状态不再含电流峰值和时序诊断，实板周期裕量与
电流边界需要独立采集，不以缺少字段或构建通过代替这些验证。
