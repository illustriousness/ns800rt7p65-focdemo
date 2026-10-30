# SguanFOC 本板适配补丁

本目录保存 `libraries/SguanFOC_Library` 相对上游基点的本地适配，公开仓库不依赖私有 fork。

## 基点

```text
SguanFOC_Library commit: 5680b9ebce89203df0790c5e2313e7fd812513e9
source directory: SguanFOC库v3.1.0(无感foc，浮点运算，进阶)
```

## 应用

在仓库根目录执行：

```bash
git submodule update --init --recursive
git -C libraries/SguanFOC_Library apply ../../patches/sguan-ns800.patch
```

先检查能否干净应用：

```bash
git -C libraries/SguanFOC_Library apply --check ../../patches/sguan-ns800.patch
```

## 内容

补丁只修改 v3.1.0 浮点库的以下文件：

- `SguanFOC.c`：本板 SMO 模式适配、电压量纲/限幅、GCC/ITCM 入口等；
- `Sguan_SMO.c`：直接开关注入反馈修正；
- `UserData_Config.h`：本板运行模式；
- `UserData_Function.h`：ADC/PWM/延时等硬件回调；
- `UserData_Motor.h`、`UserData_Parameter.h`、`UserData_Status.h`：ATK 电机、保护和控制参数。

补丁不修改 `Sguan_math.c/.h`、`Sguan_SMO.h`、`SguanFOC.h` 的上游内容，也不包含其他版本目录或 Q31 定点库。

## 重新生成

在确认子模块工作区就是最终版本后：

```bash
git -C libraries/SguanFOC_Library diff > patches/sguan-ns800.patch
```

补丁只包含已跟踪文件的修改。若子模块新增了文件，需要把新增文件一并提交到仓库，不能只依赖该 diff。
