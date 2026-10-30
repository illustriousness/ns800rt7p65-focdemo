# FOC 最小状态与保留变量

## 发布快照：只保留 6 个字段

定义在 `applications/sguan/ns800_foc_port.h`，总计 **24 字节**，不再沿用旧的
220 字节诊断结构。共享通道只分配 6 个数据字和一个一致性序号，总计 **28 字节**，
不再保留原先 96 个数据字的 388 字节缓冲。

| 字段 | 类型 | 必须保留的理由 |
| --- | --- | --- |
| `state` | `uint32_t` | 判断控制是否已初始化、仍在校准、停机、启动、已确认闭环或故障；替代分别发布 ready/cal/running/closed/库状态的做法 |
| `error` | `uint32_t` | 区分 ADC、库、无感监控故障，并保存库的具体错误，不必为错误来源和库错误各放一个字段 |
| `command_seq` | `uint32_t` | 表示普通异步命令已由控制核执行；不能以通信核收到了命令作为执行完成证据 |
| `stop_seq` | `uint32_t` | STOP 使用独立通道，必须能独立确认控制核已经执行关断，不能拿普通命令序号代替 |
| `command_result` | `int32_t` | 对应 command_seq 的执行结果，区分成功、状态不允许、参数错误、被停止请求取消 |
| `speed` | `float` | 当前速度反馈，单位为机械 rad/s；当前来源是估算器，不是编码器或独立轴速测量 |

`speed` 仅在运行状态有意义。停机后可能保留最后一次估计，不能据此判断自由滑行
转子是否停止。这个结构不是直接发送的 CAN 帧，也不是 CiA 402 状态字；CANopen
桥接根据状态与确切命令序号显式转换，速度由机械 rad/s 换算为 rpm。

### state 编码

| 值 | 常量 | 含义 |
| --- | --- | --- |
| 0 | `FOC_STATE_NOT_READY` | 初始全零快照，控制初始化尚未发布状态 |
| 1 | `FOC_STATE_CALIBRATING` | 初始化返回，但尚未收齐 256 组零点样本 |
| 2 | `FOC_STATE_IDLE` | 已完成校准、未运行、无故障 |
| 3 | `FOC_STATE_STARTING` | 控制已运行，尚未确认无感闭环 |
| 4 | `FOC_STATE_CLOSED` | 无感监控已确认闭环 |
| 5 | `FOC_STATE_FAULT` | 已记录故障，优先于其他状态 |
| 6 | `FOC_STATE_ARMING` | 启动命令已接受，但原有三拍输出释放尚未完成；不能仅凭 command_seq 就报告输出已使能 |

### error 编码

高 16 位为 `enum ns800_foc_error_source`：0 正常、1 ADC、2 库、3 无感监控、
4 相电流、5 估算超速、6 母线窗口。只有库错误时，低 16 位保存 `Sguan.status`，
其他来源低 16 位为 0。例如 `0x00020012` 表示库错误，原始库状态为 `0x0012`。
错误在关断时锁存，STOP 和库状态重置不会抹掉详情；只有独立 `FOC_RESET_FAULT`
成功后清除。这不是 CANopen EMCY 编码。

## 控制核内还保留哪些状态，为什么

下表列的是适配层的持久状态，不是额外的发布字段。没有为了日志保留备用计数。

| 变量 | 保留理由 |
| --- | --- |
| `pwm[3]`（常量指针表） | 定位三相 EPWM 实例，供占空比更新和关断使用 |
| `period` | PWM 计数周期，用于将归一化占空比换算为比较寄存器值 |
| `raw[3]` | 三相原始 ADC 结果，供库采样回调、零点校准和相电流换算使用；母线原始结果不再缓存，读取后直接换算 |
| `offset_sum[3]` | 256 组校准样本的整数累加值，不能拿尚未完成的偏置给控制使用 |
| `offset_count` | 同时表示收集了多少组校准样本及校准是否完成，达到 256 后不再累加；取代总 ADC 计数和单独 calibrated 标志 |
| `offsets[3]` | 校准后的三相偏置，用于相电流换算和库偏置初始化 |
| `current[3]` | 三相实际电流参与已有死区补偿和施加电压计算，不只是遥测数据 |
| `vbus` | 母线电压参与库输入、占空比/死区补偿和施加电压计算 |
| `running` | 控制输出开关，ADC ISR、PWM 回调和慢线程共同使用；不能直接用库的启动状态代替输出已允许 |
| `fault` | 以同一个 32 位字锁存来源和库错误，STOP 后库状态可能被重置，不能届时再反推错误 |
| `adc_overflow_streak` | 保留原先连续 3 个溢出周期才关断的判定；删除的是累计诊断计数，不是此控制计数 |
| `align_count` | 保留启动后原有的三拍输出释放顺序，前两拍仍不释放功率级 |
| `high_count` | 每 20 个 20 kHz ADC 控制周期运行一次低环和监控，不是性能统计 |
| `sensorless.elapsed_ms` | 原有 10 秒启动接管期限 |
| `sensorless.valid_ms` | 原有连续 50 ms 有效跟踪确认条件 |
| `sensorless.lost_ms` | 原有连续失锁 100 ms 的关断条件 |
| `sensorless.closed` | 记录已经确认闭环，控制允许改速与发布状态均需此信息 |
| `command_mailbox` | 跨核异步请求、普通命令槽位复用及独立停止请求的交接 |
| `command_result` | 保存最近普通命令的执行结果，直到后续状态发布/下一命令执行 |
| `status_channel` | 保存通信核可读取的一致快照，避免它直接读取被 ADC ISR 修改的数据 |

邮箱中的 `offered/completed` 用来发布请求并决定槽位能否复用，`stop/stopped` 用来
发布和确认独立停止请求，`request` 保存操作类型、目标速度和启动电流。
快照中的序号则将执行结果与同一份控制状态一起提供给上层，不能只读取邮箱的
completed 后就假定快照已经更新。共享通道的 `sequence` 用于检测复制期间是否发生
更新，`words[6]` 是必要的 24 字节数据存储。

`ns800_foc_submit(..., &sequence)` 在发布命令的同一短临界区回传实际序号，不能拿
可能滞后的快照序号加一猜测。旧 `ns800_foc_request()` 保留为不需要序号的调用包装。
桥接仍使用同样的六字段快照，没有增加时间、遥测或诊断字段。

原来的 `ready` 无需单独保存：命令消费循环是在同步初始化返回后才进入的；初始化
之前共享快照全零，对外自然是 NOT_READY。校准完成与否直接由 offset_count 判断。
`emf/observer` 仍参与原有监控判定，但改成每次调用的局部计算结果，不再跨周期缓存。
原有库内变量与参数没有删除或改写。

## 已删除的诊断工作

- eMATH 统计结构、零计数兼容字段和重置逻辑。
- ADC 累计次数/累计 overflow、相电流峰值和接管次数统计。
- ISR/控制主体/低环的 last/max 周期数、DWT 启用和计时调用。
- 快照中的相电流、母线、Id/Iq、目标量、PLL/强拖角度、反电势、相位误差、
  启动/接管/失锁计时、固定 blend=0 等诊断字段。
- 强拖诊断角度缓存，以及仅为显示而做的误差、角度归一化和单位换算。

`foc_status_publish()` 的关中断区只读取/归并状态、错误和速度；命令确认数据及六字
发布在恢复本地中断之后完成。打印换算仅在通信核执行，不再每毫秒计算诊断量。
本轮未测量新的实板延迟，不宣称获得严格 WCET 或完全消除内核关中断延迟。

## 输出与验证边界

FinSH 的 `motor status` 改为带 `status_schema=2` 的一行输出。打印的
`speed_mrad_s` 是 speed 乘 1000 的显示值，不新增一份状态变量。

旧 `scripts/sensorless_test.py` 依赖电流峰值、ISR 周期和角度等验收数据。它现在明确
拒绝 schema=2，在发出 START 前退出，仅尝试 STOP；不以缺少字段为由跳过电流或
时序判据再报告成功。历史证据中的旧日志和诊断源码保持原样，不进入本轮清理。

```bash
python3 tests/foc_ipc_regression.py
python3 tests/foc_adc_regression.py
python3 tests/sensorless_status_schema_regression.py
python3 tests/sguan_arm_compile.py
python3 tests/sguan_integration_regression.py
./scripts/build.sh
```

这些验证不访问实板、不发送电机命令。真实 CANopen 桥接已使用此接口，但本轮未烧录、
未启动电机；协议控制和故障复位语义见 [CANopen 桥接说明](CANOPEN.md)。
