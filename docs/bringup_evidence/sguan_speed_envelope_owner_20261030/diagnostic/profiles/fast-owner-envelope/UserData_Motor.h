#ifndef __USERDATA_MOTOR_H
#define __USERDATA_MOTOR_H
#include "SguanFOC.h"
/* 电机控制User用户设置·电机参数(SguanFOC) */

/**
 * @description: 实体参数填写函数的初始化代码
 * @reminder: (此方函数->填写电机实际物理参数)
 * @param {SguanFOC_System_STRUCT} *user
 * @return {*}
 */
static inline void User_Motor_Init(SguanFOC_System_STRUCT *user){
    // +---------------------------------------------------------+
    // |                  电机实体参数Motor填写                   |
    // +---------------------------------------------------------+
    // 1.Sguan.foc参数设计(最初始的Target数值)
    user->foc.Target_Speed = 0.0f;                  // (float)期望的机械角速度
    user->foc.Target_Pos = 0.0f;                    // (float)期望的机械角度值
    user->foc.Target_Id = 0.0f;                     // (float)期望的D轴电流
    user->foc.Target_Iq = 0.0f;                     // (float)期望的Q轴电流

    user->foc.Target_VF_Uq = 0.0f;                  // (float)设置的Uq大小
    user->foc.Target_IF_Iq = 0.0f;

    user->foc.Ud_in = 0.0f;                         // (float)实际输入的D轴电压
    user->foc.Uq_in = 0.0f;                         // (float)实际输入的Q轴电压

    // 2.Sguan.motor参数设计(电机个性化配置)
    user->motor.identify.Rs = 0.200f;               // ATK-BL57H95D20E phase resistance (initial)
    user->motor.identify.Ld = 0.000400f;            // ATK-BL57H95D20E d-axis inductance (initial)
    user->motor.identify.Lq = 0.000400f;            // ATK-BL57H95D20E q-axis inductance (initial)
    
    user->motor.identify.Flux = 0.01520f;           // ATK-BL57H95D20E flux estimate
    user->motor.identify.B = 0.0001f;               // unknown; conservative initial value
    user->motor.identify.J = 0.0001f;               // unknown; conservative initial value
    /* ====================================== 分割线 =================================== */
    user->motor.Poles = 2;                          // ATK-BL57H95D20E pole pairs
    user->motor.VBUS = 24.0f;                       // (float)标定的母线电压
    
    user->motor.Motor_Dir = 1;                      // (int8_t)电机方向1->正向，负1->负向
    user->motor.Encoder_Dir = -1;                   // (int8_t)Q轴电感_默认参数
    user->motor.PWM_Dir = 1;                       // (int8_t)PWM占空比电平，1为正向,-1为负向
    user->motor.Duty = 1000;                        // normalized PWM scale used by adapter

    user->motor.Current_Dir0 = -1;                   // (int8_t)相线电流方向1->正向，负1->负向
    user->motor.Current_Dir1 = -1;                   // (int8_t)相线电流方向1->正向，负1->负向
    user->motor.Current_Num = 0;                    // AMP_IU/AMP_IV are used as AB currents
    user->motor.ADC_Precision = 4096;               // (uint32_t)ADC采样精度
    user->motor.Amplifier = 6.0f;                   // ATK board current amplifier gain
    user->motor.MCU_Voltage = 3.3f;                 // (float)DSP/单片机的ADC电压基准
    user->motor.Sampling_Rs = 0.020f;               // ATK board 20 mOhm shunts

    // 3.Sguan.safe参数设计(维护驱动器安全)
    user->safe.VBUS_MAX = 30.0f;                    // ATK board input range
    user->safe.VBUS_MIN = 12.0f;                    // ATK board minimum test bus voltage
    user->safe.VBUS_watchdog_limit = 1000;          // (uint32_t)看门狗

    user->safe.Temp_MAX = 60.0f;                    // (float)驱动器允许最大温度
    user->safe.Temp_MIN = -20.0f;                   // (float)驱动器允许最小温度
    user->safe.Temp_watchdog_limit = 1000;          // (uint32_t)看门狗

    user->safe.Dcur_MAX = 3.0f;                     // first bring-up current limit
    user->safe.Qcur_MAX = 3.0f;                     // first bring-up current limit
    user->safe.DQcur_watchdog_limit = 1000;         // (uint32_t)看门狗

    user->safe.Current_limit = 3.0f;                // first bring-up current limit
    user->safe.Speed_limit = 100.0f;                // about 955 rpm mechanical
    user->safe.Position_limit = 1.0f;               // (float)电机->位置状态机判断的位置范围

    user->safe.DISABLED_watchdog_limit = 1000;      // (uint32_t)看门狗

    // 4.Sguan.flag参数设计(非重要数据)
    user->flag.PWM_watchdog_limit = 10;             // (uint8_t)PWM错误次数限幅
}   


#endif // USERDATA_MOTOR_H
