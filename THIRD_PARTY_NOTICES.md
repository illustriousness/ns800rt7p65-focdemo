# 第三方组件与许可证

本项目根代码采用 Apache-2.0，见 [LICENSE](LICENSE)。以下第三方组件保留各自许可证；
发布或再分发时不得删除其原始版权和许可证文本。

| 组件 | 位置 | 许可证 | 说明 |
| --- | --- | --- | --- |
| RT-Thread | `rt-thread/`、`rt-thread/` 相关 BSP | Apache-2.0 | 上游 RT-Thread 5.3.1 及 NOVOSENSE BSP |
| CANopenNode | `libraries/CANopenNode/` | Apache-2.0 | 上游 v4.1，保留 `LICENSE` |
| SguanFOC | `libraries/SguanFOC_Library/` | MIT | 上游 v3.1.0 浮点库，保留 `LICENSE`；本板适配见 `patches/sguan-ns800.patch` |
| CMSIS / 芯片头文件 | `rt-thread/`、厂商 BSP 依赖 | 各自上游许可证 | 由 RT-Thread/NOVOSENSE BSP 提供 |
| NOVOSENSE NS800 SDK | 不随公开仓库分发 | 厂商授权 | 仅用于 J-Link 下载/调试；请从官方渠道获取并通过 `NS800_SDK_ZIP` 指定 |

## 本板修改

`patches/sguan-ns800.patch` 是对 SguanFOC 上游基点的本板适配，包含板级参数、SMO 直接反馈
修正和少量编译/量纲适配。它不是上游官方版本；上游作者不对这些修改负责。

## 硬件资料

ATK-PD6010B、ATK-BL57H95D20E 和 NSSinePad 的原理图、手册和商标归各自权利人所有。
本仓库只引用接线和测试所需信息，不重新分发厂商原理图或闭源工具。
