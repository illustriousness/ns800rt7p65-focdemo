# 2026 RT-Thread 嵌入式大赛提交清单

> 截止：**2026-11-01 24:00（北京时间）**
>
> 论坛标题格式：`〖2026嵌入式大赛〗+ 你的标题`
>
> 腾讯文档：<https://docs.qq.com/sheet/DTmdVWEFkZmxXaVpl?tab=000001>

---

## 0. 提交前必须先确认的 3 个事项

### 0.1 公开远程地址

先检查 `git remote -v`。如果为空，比赛要求提交的“开源软件代码”就没有可访问链接；必须先把代码推送到 GitHub/Gitee 等公开仓库，并在论坛帖和腾讯文档中给出链接。

```bash
git remote add origin git@github.com:illustriousness/ns800rt7p65-focdemo.git
git push -u origin main
```

推送后必须用**无痕窗口**打开链接，确认未登录也能查看。

### 0.2 SguanFOC 子模块还有未提交修改

先检查 `libraries/SguanFOC_Library` 是否有未提交修改。只要子模块工作区有修改，父仓库的 gitlink 就只指向子模块提交，**不会包含这些工作区修改**；如果只推父仓库，别人无法复现本项目的板级参数和 SMO 修正。

先确认哪些修改属于最终作品：

```bash
git -C libraries/SguanFOC_Library status --short
git -C libraries/SguanFOC_Library diff --stat
```

本项目采用**上游子模块 + 补丁**的方式，不依赖私有 fork。补丁放在仓库 `patches/`，README 和论坛帖给出应用命令。

生成补丁：

```bash
mkdir -p patches
git -C libraries/SguanFOC_Library diff > patches/sguan-ns800.patch
```

验证补丁能应用到干净的上游基点：

```bash
git -C libraries/SguanFOC_Library apply --check ../../patches/sguan-ns800.patch
```

克隆后应用：

```bash
git submodule update --init --recursive
git -C libraries/SguanFOC_Library apply ../../patches/sguan-ns800.patch
```

注意：补丁只包含已跟踪文件的修改；如果子模块有新增文件，必须另外加入补丁或仓库。不要把 `patches/` 写成只适用于当前工作区的绝对路径。

### 0.3 仓库根目录 LICENSE

检查根目录是否有 `LICENSE` 文件。若没有，建议在根目录添加许可证，并在 README 说明第三方组件许可证：

- RT-Thread：Apache-2.0；
- CANopenNode：Apache-2.0；
- SguanFOC：MIT（保留其 `LICENSE`）；
- 本项目根代码：Apache-2.0，与 RT-Thread 一致。

根目录放 Apache-2.0 标准文本，README 增加“Third-party licenses”小节。不要删除子模块中的原始许可证。

---

## 1. 材料对应表

| 比赛要求 | 本项目材料 | 当前状态 |
| --- | --- | --- |
| 项目概述 | `docs/competition/FORUM_POST.md` 第一节；本文件第 2.2 节短版 | 已整理 |
| 功能介绍 | 论坛帖第二节；本文件第 2.3 节短版 | 已整理 |
| 硬件框架说明 | 论坛帖第三节 + `hardware_topology.png` | 图已生成，待上传 |
| 软件框架说明 | 论坛帖第四节 + `software_flow.png` | 图已生成，待上传 |
| 开源软件代码 | https://github.com/illustriousness/ns800rt7p65-focdemo | **已发布公开仓库，tag `v1.0-competition`** |
| 演示视频 | B 站/腾讯视频公开链接 | **待录制/上传** |
| 论坛帖子 | `club.rt-thread.org` 帖子链接 | **待发布** |
| 腾讯文档 | 项目信息、链接、附件 | **待填写** |
| 其他附件 | EDS、实板证据、测试命令 | 已在仓库中 |

---

## 2. 腾讯文档填写内容（可直接复制）

> 腾讯文档的表格字段可能与本清单不完全一致，按实际字段拆分粘贴；原则是“短版进表格，长版放论坛链接”。

### 2.1 基本信息

| 字段 | 内容 |
| --- | --- |
| 项目名称 | 基于 NS800RT7P65D 双核 RT-Thread 的无感 FOC 与 CANopen 驱动平台 |
| 参赛者/团队 | {{姓名/团队名}} |
| 联系方式 | {{手机/邮箱/微信}} |
| 硬件平台 | NSSinePad NS800RT7P65D（双 Cortex-M7） |
| 软件平台 | RT-Thread 5.3.1 SMP、SguanFOC v3.1.0、CANopenNode v4.1 |
| 开源仓库 | https://github.com/illustriousness/ns800rt7p65-focdemo |
| 演示视频 | {{公开视频链接}} |
| 论坛帖子 | {{论坛帖子链接}} |
| 许可证 | Apache-2.0（第三方组件保留各自许可证） |

### 2.2 项目概述（短版，约 300 字）

本项目在 NSSinePad NS800RT7P65D 双核 Cortex-M7 平台上，基于 RT-Thread 5.3.1 SMP 构建无感 FOC 与 CANopen CiA 402 驱动平台。CPU0 运行 20 kHz ADC/PWM 控制与 SguanFOC 无感算法，CPU1 运行 UART、CANopenNode 协议栈和 CiA 402 桥接；通过异步邮箱和 24 字节一致性快照实现跨核命令与状态交接。项目完成 24 V 电机 500/600/800 rpm 实板闭环、CANopen 协议台架实板验证，并对新控制桥接完成 ASan/UBSan 主机回归。作品定位为可复现的教学/原型平台，不宣称完整 CiA 402 认证。

### 2.3 功能介绍（短版，约 350 字）

- 双核 RT-Thread SMP：控制核与通信核分离，线程绑核、MU 核间中断、硬件 SEMA。
- 20 kHz 无感 FOC：IF 强拖 → SMO/PLL → 闭环接管，三相电流/母线电压采样，GPIO23 + EPWM Trip 硬件关断。
- CANopen：NMT、Heartbeat、SDO、固定 RPDO1/TPDO1、EMCY；CiA 402 受限速度模式 3。
- 真实控制桥接：以实际 `command_seq`、arming 状态和 FOC 状态更新 402 反馈，不以收包代替执行。
- 安全语义：STOP 优先锁存、故障 packed 锁存、独立故障复位、500 ms 控制授权、断联停止、恢复通信不自动重启。
- 控制权交接：默认 CAN，`motor owner uart/can` 切换前先 STOP，确认 `stop_seq` 后才授予；切换期间两个来源都不能提交新命令。
- 调试与验证：FinSH 命令、ZLG 协议台架、ADC ISR/IPC/CANopen 主机回归、实板证据链。

### 2.4 硬件框架（短版，约 250 字）

主控为 NSSinePad NS800RT7P65D（双 Cortex-M7），功率板为 ATK-PD6010B，电机为 ATK-BL57H95D20E（24 V、2 极对、无编码器）。三相 PWM 使用 EPWM8/9/10，20 kHz、1 µs 死区；三相低侧电流和母线电压接 ADCA SOC0～3；GPIO23 作为 CTRL_SD 功率级使能，故障时拉低并强制 EPWM One-Shot Trip。调试使用 J-Link VCOM 接 UART1，CAN 使用 CANFD1 经典 CAN 1 Mbit/s，上位机为 ZLG USBCANFD-100U。

### 2.5 软件框架（短版，约 300 字）

软件基于 RT-Thread 5.3.1 SMP。逻辑 CPU0 负责 ADC EOC、20 kHz FOC 高低环、PWM/CTRL_SD 和 `sguan` 慢线程；逻辑 CPU1 负责 UART/FinSH、CAN 外设、CANopenNode 和 CiA 402 桥接。跨核接口只有异步命令邮箱和六字段、24 字节一致性快照：`state/error/command_seq/stop_seq/command_result/speed`。CANopen 侧使用固定 RPDO1（控制字 + 目标速度）和 TPDO1（状态字 + 估算速度），SDO 提供参数访问。应用层位于 `applications/sguan/` 和 `applications/canopen/`，算法库以子模块维护。

### 2.6 创新点（短版）

1. 真双核职责隔离：20 kHz 控制不被 CANopen/SDO/日志抢占。
2. 以实际命令确认驱动 CiA 402，而不是协议模型自嗨。
3. STOP 在 PDO 最新值缓冲前锁存，同批报文不能覆盖停止。
4. 故障原因 packed 锁存，STOP 不清故障，复位独立且成功后不自动启动。
5. SMO 直接反馈修正：实板 500/800 rpm 原始 PLL 速度标准差降低约 80%，控制角高频纹波明显降低。
6. 证据链完整：保留失败记录、参数边界、抓包和复现命令。

### 2.7 验证结果（短版）

- 实板无感 FOC：500→600→500 rpm、800→700→800 rpm 通过；ISR 峰值 27.185/27.470 µs，相电流峰值 1.272/1.189 A，ADC overflow 0。
- SMO A/B：500 rpm 原始 PLL 标准差 821.60→142.88、776.82→147.96 rpm；800 rpm 744.07→145.71 rpm。
- CANopen 台架：经典 CAN 1 Mbit/s 100/100 回传，SDO/PDO/NMT/EMCY/402 通过，RXE=TXE=0。
- 新桥接：主机 ASan/UBSan 回归通过；**尚未烧录、未做经 CAN 的电机实板运行**。

### 2.8 已知限制（短版）

仅模式 3；启动 ±350～800 rpm，闭环同向改速到 ±2500 rpm；无零速保持、直接跨零换向、完整加减速轨迹或位置模式；速度是观测器估算，非独立测速；500 ms 超时为任务级处理，不替代硬件安全链；新桥接未做实板电机验证；实板 FOC 为短时空载，未覆盖反转、堵转、带载、温升、长期和热重启；2500 rpm 新范围仅主机回归。

### 2.9 附件建议

| 附件 | 说明 |
| --- | --- |
| `NS800_FOC_BRIDGE.eds` | CANopen 对象字典，主站可直接导入 |
| `hardware_topology.png` | 硬件框架图 |
| `software_flow.png` | 软件数据流图 |
| 实板 FOC 证据摘要 | 可把 `docs/bringup_evidence/.../README.md` 导出 PDF |
| CANopen 台架证据摘要 | 可把 `docs/canopen_evidence/manifest.json` 和抓包说明导出 PDF |
| 构建/测试说明 | `docs/CANOPEN.md`、`docs/FOC_STATUS.md`、`docs/CORE_LAYOUT.md` |

> 腾讯文档若限制附件大小，优先放“仓库链接 + 论坛帖子链接 + 两张图 + EDS”，证据放在仓库中。

---

## 3. 论坛发帖步骤

1. 登录 <https://club.rt-thread.org>。
2. 进入大赛/作品展示对应板块（以论坛实际版块为准）。
3. 标题粘贴：

   ```text
   〖2026嵌入式大赛〗基于 NS800RT7P65D 双核 RT-Thread 的无感 FOC 与 CANopen 驱动平台
   ```

4. 正文复制 `docs/competition/FORUM_POST.md` 的全部内容（从一级标题下一行开始）。
5. 在编辑器中上传：
   - `docs/competition/hardware_topology.png`
   - `docs/competition/software_flow.png`
6. 替换所有 `{{...}}` 占位符：
   - 开源仓库、分支/tag、LICENSE 已填；
   - 仍需填演示视频链接；
   - 论坛帖子链接（发布后回填腾讯文档）。
7. 建议标签：`RT-Thread`、`NS800RT7P65D`、`FOC`、`CANopen`、`CiA402`、`双核`。
8. 先点“预览”，检查表格、代码块、图片和中文标点；再发布。
9. 发布后用无痕窗口打开帖子，复制 URL 填入腾讯文档。

---

## 4. 演示视频脚本（3～5 分钟）

> 只录实际跑过的内容。新桥接尚未做实板电机运行，就不要在视频里剪成“CANopen 已控制电机”；可以展示主机回归或协议台架，并用字幕标注边界。

| 时间 | 画面 | 旁白/字幕 |
| --- | --- | --- |
| 0:00–0:20 | 主控板、功率板、电机、ZLG、J-Link | 作品名称、硬件平台、RT-Thread 5.3.1 |
| 0:20–0:50 | 两张架构图 | CPU0 控制、CPU1 通信、邮箱/快照 |
| 0:50–1:20 | 上电，串口 `motor status`、`ps`、`smp` | 默认停机、双核绑核、GPIO23 低 |
| 1:20–2:20 | `motor closed 500 0.8` → `motor speed 600` → `motor stop` | 实板无感 FOC 启动/改速/停机；速度是估算值 |
| 2:20–3:10 | CANopen 主站/协议台架或主机回归 | 若实板桥接未验证，字幕写“桥接仅主机回归” |
| 3:10–3:40 | STOP 优先、故障复位、断联停止 | 停止优先、故障不丢、复位不自动启动 |
| 3:40–4:00 | 仓库页面、构建命令、限制 | 开源地址、复现方式、已知限制 |

常用命令：

```text
motor status
motor closed 500 0.8
motor speed 600
motor stop
motor status
co
```

录制注意：

- 接线变更先断电；不要用手强行转动电机；
- 画面中保留串口原始输出，不要只剪“成功”片段；
- 字幕注明“估算速度，非独立测速”“短时空载，非长期/带载验收”；
- 视频上传 B 站或腾讯视频，设置为公开，复制链接。

---

## 5. 代码发布检查

### 5.1 公开仓库

```bash
# 确认没有未提交的父仓库改动
git status --short

# 确认构建产物没有被跟踪
git ls-files | grep -E '(^|/)(build|rtthread\.(elf|bin)|rtthread_cpu2\.(elf|bin))' || true

# 创建 tag（可选但推荐）
git tag -a v1.0-competition -m "2026 RT-Thread embedded competition submission"
git push origin main
git push origin v1.0-competition
```

### 5.2 子模块补丁

- `.gitmodules` 保持上游 SguanFOC 地址；
- `patches/sguan-ns800.patch` 已提交，README 写清应用顺序；
- 克隆验证：

```bash
git clone --recursive https://github.com/illustriousness/ns800rt7p65-focdemo /tmp/opencode/ns800-submission-check
cd /tmp/opencode/ns800-submission-check
git submodule status
git -C libraries/SguanFOC_Library apply ../../patches/sguan-ns800.patch
./scripts/build.sh
```

> 不要在提交前把 `build/`、`rtthread.elf`、`rtthread.bin`、J-Link 临时文件、个人 token 或私钥推上公开仓库。

### 5.3 许可证与第三方

- 根目录 `LICENSE`；
- 保留 `libraries/SguanFOC_Library/LICENSE`（MIT）；
- 保留 `libraries/CANopenNode/LICENSE`（Apache-2.0）；
- README 增加“第三方组件与许可证”小节；
- 公开仓库不包含 NOVOSENSE SDK 压缩包；README 写清从官方渠道获取，并通过 `NS800_SDK_ZIP` 指定路径。构建本身不依赖该 zip，下载/调试脚本才需要。

### 5.4 个人信息

- 提交前检查提交作者邮箱是否愿意公开；
- 检查文档中是否包含本机绝对路径、内网 IP、Wi-Fi 密码、J-Link 序列号等；
- J-Link 序列号本身不是密钥，但可按需脱敏。

---

## 6. 最终提交前检查（逐项打勾）

- [ ] 公开仓库链接在无痕窗口可访问；
- [ ] `git clone --recursive` 后能构建；
- [ ] 子模块补丁已发布，克隆后能应用并构建；
- [ ] 根目录有 LICENSE，第三方许可证保留；
- [ ] 论坛帖子标题符合 `〖2026嵌入式大赛〗+ 标题`；
- [ ] 帖子中所有 `{{...}}` 已替换；
- [ ] 两张架构图已上传且显示正常；
- [ ] 演示视频公开可播放，链接无权限限制；
- [ ] 腾讯文档中项目概述、功能介绍、硬件/软件框架、代码、视频、论坛链接均已填写；
- [ ] 腾讯文档附件/链接权限为“任何人可查看”；
- [ ] 提交时间早于 **2026-11-01 24:00**；
- [ ] 本地保留一份 ZIP + SHA256 归档，防止仓库后续改动影响评审。

生成归档：

```bash
git archive --format=zip --output=/tmp/opencode/ns800-submission-$(date +%Y%m%d).zip HEAD
sha256sum /tmp/opencode/ns800-submission-$(date +%Y%m%d).zip
```

> `git archive` 不包含子模块内容；如果要交完整源码包，请额外打包已发布的 SguanFOC 子模块，或直接以 `git clone --recursive` 的公开仓库为准。

---

## 7. 建议时间安排

| 时间 | 任务 |
| --- | --- |
| 10 月 30 日晚 | 确认子模块发布方案；创建公开仓库；补 LICENSE；推送代码 |
| 10 月 31 日上午 | 录制视频、截图、导出证据摘要 |
| 10 月 31 日下午 | 发布论坛帖子；回填链接；填写腾讯文档 |
| 10 月 31 日晚 | 无痕窗口逐项检查链接、权限、构建复现 |
| 11 月 1 日 | 只做修正和复核，不再大改代码；提前提交，避免 24:00 前网络/审核问题 |

---

## 8. 口径提醒（避免评审争议）

**可以写“已完成”：**

- 双核 RT-Thread SMP 实板启动、绑核、MU/SEMA；
- 20 kHz 无感 FOC 实板 500/600/800 rpm 短时空载；
- CANopen 协议台架实板 NMT/SDO/PDO/EMCY/402；
- 新桥接主机 ASan/UBSan 回归和完整固件构建。

**不要写“已完成”：**

- “CANopen 已实板控制电机运行”——新桥接尚未烧录/实板电机验证；
- “完整 CiA 402 一致性”——只实现受限速度子集；
- “独立测速/编码器闭环”——速度来自 SMO/PLL 估算；
- “硬件安全认证/严格 WCET”——只有软件关断和短时观测；
- “SMO 修正解决所有速度波动”——只降低原始 PLL/控制角高频纹波。

把边界写清楚不会丢分，反而能让评审复现你的结果、理解你的工程判断。
