# 2026 RT-Thread 嵌入式大赛提交材料

| 文件 | 用途 |
| --- | --- |
| `FORUM_POST.md` | 可直接粘贴到 RT-Thread 官方论坛的帖子正文（含标题、项目概述、功能介绍、硬件/软件框架、验证结果、限制） |
| `SUBMISSION_CHECKLIST.md` | 腾讯文档填写短版、代码发布步骤、演示视频说明、最终检查清单 |
| `hardware_setup.jpg` | 论坛帖图 1：实板调试连接照片 |
| `hardware_topology.png` | 论坛帖图 2：硬件拓扑 |
| `software_flow.png` | 论坛帖图 3：软件数据流 |
| `hardware_topology.dot` / `software_flow.dot` | 图片源文件，修改后可用 Graphviz 重新生成 |
| 演示视频 | https://github.com/illustriousness/ns800rt7p65-focdemo/releases/tag/v1.0-competition |

## 仍需人工填写

公开仓库、tag、LICENSE 和演示视频链接已填。仍需：

- 参赛者/团队和联系方式（仅腾讯文档需要，论坛公开帖可不填）；
- 论坛帖子链接（发布后回填腾讯文档）。

## 提交前检查项

1. 是否已配置公开 remote，并确认无痕窗口可访问；
2. `libraries/SguanFOC_Library` 的最终修改是否已导出为 `patches/sguan-ns800.patch`，并验证可应用；
3. 根目录是否已添加 LICENSE，并保留第三方许可证；
4. 演示视频是否已上传且公开可访问（当前为 GitHub Release）；
5. 论坛帖和腾讯文档是否已发布/填写，链接是否互相回填。

详细处理步骤见 `SUBMISSION_CHECKLIST.md` 第 0 节。
