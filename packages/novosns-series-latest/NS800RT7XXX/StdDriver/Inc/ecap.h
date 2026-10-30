/**
  * @file       ecap.h
  * @author     Alex-J
  * @brief      Header file for NS800RT7xxx ecap module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __ECAP_H__
#define __ECAP_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup ECAP_EXPORTED_TYPES ECAP Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'ECAP' module.
  */

/** @defgroup ECAP_MUNITXCTL_REGBIT ECAP MUNITXCTL register bits
  * @{
  * @brief  Macro definitions about ECAP_MUNITXCTL register bits definition.
  */
#define ECAP_MUNITXCTL_EN_S                    (0UL)        /*!< EN Bit Position (Bit 0) */
#define ECAP_MUNITXCTL_EN_M                    (0x1UL)      /*!< Enable bit (Bitfield-Mask: 0x01) */
#define ECAP_MUNITXCTL_DEBUGRANGEEN_S          (1UL)        /*!< DEBUGRANGEEN Bit Position (Bit 1) */
#define ECAP_MUNITXCTL_DEBUGRANGEEN_M          (0x2UL)      /*!< Debug enable to aquire the range of  check being done (Bitfield-Mask: 0x01) */
#define ECAP_MUNITXCTL_DISABLEEARLYMAXERR_S    (2UL)        /*!< DISABLEEARLYMAXERR Bit Position (Bit 2) */
#define ECAP_MUNITXCTL_DISABLEEARLYMAXERR_M    (0x4UL)      /*!< Disable early max error check (Bitfield-Mask: 0x01) */
#define ECAP_MUNITXCTL_MONSEL_S                (8UL)        /*!< MONSEL Bit Position (Bit 8) */
#define ECAP_MUNITXCTL_MONSEL_M                (0xf00UL)    /*!< Selects type of monitoring (Bitfield-Mask: 0x0f) */

/**
  * @}
  */

/** @defgroup ECAP_MUNITXSHADOWCTL_REGBIT ECAP MUNITXSHADOWCTL register bits
  * @{
  * @brief  Macro definitions about ECAP_MUNITXSHADOWCTL register bits definition.
  */
#define ECAP_MUNITXSHADOWCTL_SYNCIEN_S     (0UL)      /*!< SYNCIEN Bit Position (Bit 0) */
#define ECAP_MUNITXSHADOWCTL_SYNCIEN_M     (0x1UL)    /*!< Enable for shadowing on Min and Max Registers (Bitfield-Mask: 0x01) */
#define ECAP_MUNITXSHADOWCTL_SWSYNC_S      (1UL)      /*!< SWSYNC Bit Position (Bit 1) */
#define ECAP_MUNITXSHADOWCTL_SWSYNC_M      (0x2UL)    /*!< SW sync to copy shadow to active Min and Max registers (Bitfield-Mask: 0x01) */
#define ECAP_MUNITXSHADOWCTL_LOADMODE_S    (2UL)      /*!< LOADMODE Bit Position (Bit 2) */
#define ECAP_MUNITXSHADOWCTL_LOADMODE_M    (0x4UL)    /*!< Load mode (Bitfield-Mask: 0x01) */

/**
  * @}
  */

/** @defgroup ECAP_EMULATIONMODE Number with one group(ECAP1/2/3/4/5/6/7)
  * @{
  * @brief Macro definitions about ECAP emulation mode.
  */
typedef enum {
    ECAP_EMULATION_STOP = 0U,      /*!< TSCTR is stopped on emulation suspension */
    ECAP_EMULATION_RUN_TO_ZERO,    /*!< TSCTR runs until 0 before stopping on emulation suspension */
    ECAP_EMULATION_FREE_RUN        /*!< TSCTR is not affected by emulation suspension */
} ECAP_EmulationMode;

/**
  * @}
  */

/** @defgroup ECAP_CAPTUREMODE Number with one group(ECAP1/2/3/4/5/6/7)
  * @{
  * @brief Macro definitions about ECAP capture mode.
  */
typedef enum {
    ECAP_CONTINUOUS_CAPTURE_MODE = 0U,    /*!< eCAP operates in continuous capture mode */
    ECAP_ONE_SHOT_CAPTURE_MODE            /*!< eCAP operates in one shot capture mode */
} ECAP_CaptureMode;

/**
  * @}
  */

/** @defgroup ECAP_EVENT Number with one group(ECAP1/2/3/4/5/6/7)
  * @{
  * @brief Macro definitions about ECAP event.
  */
typedef enum {
    ECAP_EVENT_1 = 0U,    /*!< eCAP event 1 */
    ECAP_EVENT_2,         /*!< eCAP event 2 */
    ECAP_EVENT_3,         /*!< eCAP event 3 */
    ECAP_EVENT_4          /*!< eCAP event 4 */
} ECAP_Events;

/**
  * @}
  */

/** @defgroup ECAP_SYNC_OUTMODE Number with one group(ECAP1/2/3/4/5/6/7)
  * @{
  * @brief Macro definitions about ECAP sync out mode.
  */
typedef enum {
    ECAP_SYNC_OUT_SYNCI       = 0x00U,    /*!< sync out on the sync in signal and software force */
    ECAP_SYNC_OUT_COUNTER_PRD = 0x40U,    /*!< sync out on counter equals period */
    ECAP_SYNC_OUT_DISABLED    = 0x80U     /*!< Disable sync out signal */
} ECAP_SyncOutMode;

/**
  * @}
  */

/** @defgroup ECAP_APWMPOLARITY Number with one group(ECAP1/2/3/4/5/6/7)
  * @{
  * @brief Macro definitions about ECAP APWM polarity.
  */
typedef enum {
    ECAP_APWM_ACTIVE_HIGH = 0x000U,    /*!< APWM is active high */
    ECAP_APWM_ACTIVE_LOW  = 0x400U     /*!< APWM is active low  */
} ECAP_APWMPolarity;

/**
  * @}
  */

/** @defgroup ECAP_EVENTPOLARITY Number with one group(ECAP1/2/3/4/5/6/7)
  * @{
  * @brief Macro definitions about ECAP event polarity.
  */
typedef enum {
    ECAP_EVNT_RISING_EDGE = 0U,    /*!< Rising edge polarity */
    ECAP_EVNT_FALLING_EDGE         /*!< Falling edge polarity */
} ECAP_EventPolarity;

/**
  * @}
  */

/** @defgroup ECAP_INPUTCAPTURESIGNALS Number with one group(ECAP1/2/3/4/5/6/7)
  * @{
  * @brief Values are used to select the ECAP input capture signals.
  */
typedef enum {
    ECAP_INPUT_XBAR_INPUT1 = 0U,                   /*!< GPIO Input Crossbar output signal-1 */
    ECAP_INPUT_XBAR_INPUT2,                        /*!< GPIO Input Crossbar output signal-2 */
    ECAP_INPUT_XBAR_INPUT3,                        /*!< GPIO Input Crossbar output signal-3 */
    ECAP_INPUT_XBAR_INPUT4,                        /*!< GPIO Input Crossbar output signal-4 */
    ECAP_INPUT_XBAR_INPUT5,                        /*!< GPIO Input Crossbar output signal-5 */
    ECAP_INPUT_XBAR_INPUT6,                        /*!< GPIO Input Crossbar output signal-6 */
    ECAP_INPUT_XBAR_INPUT7,                        /*!< GPIO Input Crossbar output signal-7 */
    ECAP_INPUT_XBAR_INPUT8,                        /*!< GPIO Input Crossbar output signal-8 */
    ECAP_INPUT_XBAR_INPUT9,                        /*!< GPIO Input Crossbar output signal-9 */
    ECAP_INPUT_XBAR_INPUT10,                       /*!< GPIO Input Crossbar output signal-10 */
    ECAP_INPUT_XBAR_INPUT11,                       /*!< GPIO Input Crossbar output signal-11 */
    ECAP_INPUT_XBAR_INPUT12,                       /*!< GPIO Input Crossbar output signal-12 */
    ECAP_INPUT_XBAR_INPUT13,                       /*!< GPIO Input Crossbar output signal-13 */
    ECAP_INPUT_XBAR_INPUT14,                       /*!< GPIO Input Crossbar output signal-14 */
    ECAP_INPUT_XBAR_INPUT15,                       /*!< GPIO Input Crossbar output signal-15 */
    ECAP_INPUT_XBAR_INPUT16,                       /*!< GPIO Input Crossbar output signal-16 */
    ECAP_INPUT_ECAP1_CLB1_CLBOUT14 = 16U,          /*!< CLB1 CLBOUT14 input for ECAP1 instance */
    ECAP_INPUT_ECAP2_CLB1_CLBOUT14 = 16U,          /*!< CLB1 CLBOUT14 input for ECAP2 instance */
    ECAP_INPUT_ECAP3_CLB2_CLBOUT14 = 16U,          /*!< CLB1 CLBOUT14 input for ECAP3 instance */
    ECAP_INPUT_ECAP4_CLB2_CLBOUT14 = 16U,          /*!< CLB1 CLBOUT14 input for ECAP4 instance */
    ECAP_INPUT_ECAP5_CLB2_CLBOUT14 = 16U,          /*!< CLB1 CLBOUT14 input for ECAP5 instance */
    ECAP_INPUT_ECAP6_CLB3_CLBOUT14 = 16U,          /*!< CLB1 CLBOUT14 input for ECAP6 instance */
    ECAP_INPUT_ECAP7_CLB3_CLBOUT14 = 16U,          /*!< CLB1 CLBOUT14 input for ECAP7 instance */
    ECAP_INPUT_ECAP1_CLB1_CLBOUT15 = 17U,          /*!< CLB1 CLBOUT15 input for ECAP1 instance */
    ECAP_INPUT_ECAP2_CLB1_CLBOUT15 = 17U,          /*!< CLB1 CLBOUT15 input for ECAP2 instance */
    ECAP_INPUT_ECAP3_CLB2_CLBOUT15 = 17U,          /*!< CLB1 CLBOUT15 input for ECAP3 instance */
    ECAP_INPUT_ECAP4_CLB2_CLBOUT15 = 17U,          /*!< CLB1 CLBOUT15 input for ECAP4 instance */
    ECAP_INPUT_ECAP5_CLB2_CLBOUT15 = 17U,          /*!< CLB1 CLBOUT15 input for ECAP5 instance */
    ECAP_INPUT_ECAP6_CLB3_CLBOUT15 = 17U,          /*!< CLB1 CLBOUT15 input for ECAP6 instance */
    ECAP_INPUT_ECAP7_CLB3_CLBOUT15 = 17U,          /*!< CLB1 CLBOUT15 input for ECAP7 instance */
    ECAP_INPUT_ECAP1_CLB5_CLBOUT14 = 18U,          /*!< CLB5 CLBOUT14 input for ECAP1 instance */
    ECAP_INPUT_ECAP2_CLB5_CLBOUT14 = 18U,          /*!< CLB5 CLBOUT14 input for ECAP2 instance */
    ECAP_INPUT_ECAP3_CLB6_CLBOUT14 = 18U,          /*!< CLB5 CLBOUT14 input for ECAP3 instance */
    ECAP_INPUT_ECAP4_CLB6_CLBOUT14 = 18U,          /*!< CLB5 CLBOUT14 input for ECAP4 instance */
    ECAP_INPUT_ECAP5_CLB6_CLBOUT14 = 18U,          /*!< CLB5 CLBOUT14 input for ECAP5 instance */
    ECAP_INPUT_ECAP6_CLB4_CLBOUT14 = 18U,          /*!< CLB5 CLBOUT14 input for ECAP6 instance */
    ECAP_INPUT_ECAP7_CLB4_CLBOUT14 = 18U,          /*!< CLB5 CLBOUT14 input for ECAP7 instance */
    ECAP_INPUT_ECAP1_CLB5_CLBOUT15 = 19U,          /*!< CLB4 CLBOUT15 input for ECAP1 instance */
    ECAP_INPUT_ECAP2_CLB5_CLBOUT15 = 19U,          /*!< CLB4 CLBOUT15 input for ECAP2 instance */
    ECAP_INPUT_ECAP3_CLB6_CLBOUT15 = 19U,          /*!< CLB4 CLBOUT15 input for ECAP3 instance */
    ECAP_INPUT_ECAP4_CLB6_CLBOUT15 = 19U,          /*!< CLB4 CLBOUT15 input for ECAP4 instance */
    ECAP_INPUT_ECAP5_CLB6_CLBOUT15 = 19U,          /*!< CLB4 CLBOUT15 input for ECAP5 instance */
    ECAP_INPUT_ECAP6_CLB4_CLBOUT15 = 19U,          /*!< CLB4 CLBOUT15 input for ECAP6 instance */
    ECAP_INPUT_ECAP7_CLB4_CLBOUT15 = 19U,          /*!< CLB4 CLBOUT15 input for ECAP7 instance */
    ECAP_INPUT_CANFD1_INT          = 20U,         /*!< CANFD1 INT Input */
    ECAP_INPUT_CAN1_INT,                          /*!< CAN1 INT Input */
    ECAP_INPUT_CANFD2_INT,                        /*!< CANFD2 INT Input */
    ECAP_INPUT_ECAP6_DELAY_CLOCK = 23U,           /*!< Delay clock for measurement */
    ECAP_INPUT_ECAP7_DELAY_CLOCK = 23U,           /*!< Delay clock for measurement */
    ECAP_INPUT_XBAR_OUTPUT1      = 24U,           /*!< PWM Xbar Output-1 */
    ECAP_INPUT_XBAR_OUTPUT2,                      /*!< PWM Xbar Output-2 */
    ECAP_INPUT_XBAR_OUTPUT3,                      /*!< PWM Xbar Output-3 */
    ECAP_INPUT_XBAR_OUTPUT4,                      /*!< PWM Xbar Output-4 */
    ECAP_INPUT_XBAR_OUTPUT5,                      /*!< PWM Xbar Output-5 */
    ECAP_INPUT_XBAR_OUTPUT6,                      /*!< PWM Xbar Output-6 */
    ECAP_INPUT_XBAR_OUTPUT7,                      /*!< PWM Xbar Output-7 */
    ECAP_INPUT_XBAR_OUTPUT8,                      /*!< PWM Xbar Output-8 */
    ECAP_INPUT_ADCC_EVENT1 = 36U,                 /*!< ADCC Event1 */
    ECAP_INPUT_ADCC_EVENT2,                       /*!< ADCC Event2 */
    ECAP_INPUT_ADCC_EVENT3,                       /*!< ADCC Event3 */
    ECAP_INPUT_ADCC_EVENT4,                       /*!< ADCC Event4 */
    ECAP_INPUT_ADCB_EVENT1,                       /*!< ADCB Event1 */
    ECAP_INPUT_ADCB_EVENT2,                       /*!< ADCB Event2 */
    ECAP_INPUT_ADCB_EVENT3,                       /*!< ADCB Event3 */
    ECAP_INPUT_ADCB_EVENT4,                       /*!< ADCB Event4 */
    ECAP_INPUT_ADCA_EVENT1,                       /*!< ADCA Event1 */
    ECAP_INPUT_ADCA_EVENT2,                       /*!< ADCA Event2 */
    ECAP_INPUT_ADCA_EVENT3,                       /*!< ADCA Event3 */
    ECAP_INPUT_ADCA_EVENT4,                       /*!< ADCA Event4 */
    ECAP_INPUT_SDFM2_FLT1_COMPARE_LOW = 60U,      /*!< SDFM-2 Filter-1 Compare Low Trip */
    ECAP_INPUT_SDFM2_FLT2_COMPARE_LOW,            /*!< SDFM-2 Filter-2 Compare Low Trip */
    ECAP_INPUT_SDFM2_FLT3_COMPARE_LOW,            /*!< SDFM-2 Filter-3 Compare Low Trip */
    ECAP_INPUT_SDFM2_FLT4_COMPARE_LOW,            /*!< SDFM-2 Filter-4 Compare Low Trip */
    ECAP_INPUT_SDFM1_FLT1_COMPARE_LOW,            /*!< SDFM-1 Filter-1 Compare Low Trip */
    ECAP_INPUT_SDFM1_FLT2_COMPARE_LOW,            /*!< SDFM-1 Filter-2 Compare Low Trip */
    ECAP_INPUT_SDFM1_FLT3_COMPARE_LOW,            /*!< SDFM-1 Filter-3 Compare Low Trip */
    ECAP_INPUT_SDFM1_FLT4_COMPARE_LOW,            /*!< SDFM-1 Filter-4 Compare Low Trip */
    ECAP_INPUT_SDFM2_FLT1_COMPARE_ZERO,           /*!< SDFM-2 Filter-1 Compare ZERO Trip */
    ECAP_INPUT_SDFM2_FLT2_COMPARE_ZERO,           /*!< SDFM-2 Filter-2 Compare ZERO Trip */
    ECAP_INPUT_SDFM2_FLT3_COMPARE_ZERO,           /*!< SDFM-2 Filter-3 Compare ZERO Trip */
    ECAP_INPUT_SDFM2_FLT4_COMPARE_ZERO,           /*!< SDFM-2 Filter-4 Compare ZERO Trip */
    ECAP_INPUT_SDFM1_FLT1_COMPARE_ZERO,           /*!< SDFM-1 Filter-1 Compare ZERO Trip */
    ECAP_INPUT_SDFM1_FLT2_COMPARE_ZERO,           /*!< SDFM-1 Filter-2 Compare ZERO Trip */
    ECAP_INPUT_SDFM1_FLT3_COMPARE_ZERO,           /*!< SDFM-1 Filter-3 Compare ZERO Trip */
    ECAP_INPUT_SDFM1_FLT4_COMPARE_ZERO,           /*!< SDFM-1 Filter-4 Compare ZERO Trip */
    ECAP_INPUT_SDFM2_FLT1_COMPARE_HIGH,           /*!< SDFM-2 Filter-1 Compare High Trip */
    ECAP_INPUT_SDFM2_FLT2_COMPARE_HIGH,           /*!< SDFM-2 Filter-2 Compare High Trip */
    ECAP_INPUT_SDFM2_FLT3_COMPARE_HIGH,           /*!< SDFM-2 Filter-3 Compare High Trip */
    ECAP_INPUT_SDFM2_FLT4_COMPARE_HIGH,           /*!< SDFM-2 Filter-4 Compare High Trip */
    ECAP_INPUT_SDFM1_FLT1_COMPARE_HIGH,           /*!< SDFM-1 Filter-1 Compare High Trip */
    ECAP_INPUT_SDFM1_FLT2_COMPARE_HIGH,           /*!< SDFM-1 Filter-2 Compare High Trip */
    ECAP_INPUT_SDFM1_FLT3_COMPARE_HIGH,           /*!< SDFM-1 Filter-3 Compare High Trip */
    ECAP_INPUT_SDFM1_FLT4_COMPARE_HIGH,           /*!< SDFM-1 Filter-4 Compare High Trip */
    ECAP_INPUT_SDFM2_FLT1_COMPARE_HIGH_OR_LOW,    /*!< SDFM-2 Filter-1 Compare High Trip or Low Trip */
    ECAP_INPUT_SDFM2_FLT2_COMPARE_HIGH_OR_LOW,    /*!< SDFM-2 Filter-2 Compare High Trip or Low Trip */
    ECAP_INPUT_SDFM2_FLT3_COMPARE_HIGH_OR_LOW,    /*!< SDFM-2 Filter-3 Compare High Trip or Low Trip */
    ECAP_INPUT_SDFM2_FLT4_COMPARE_HIGH_OR_LOW,    /*!< SDFM-2 Filter-4 Compare High Trip or Low Trip */
    ECAP_INPUT_SDFM1_FLT1_COMPARE_HIGH_OR_LOW,    /*!< SDFM-1 Filter-1 Compare High Trip or Low Trip */
    ECAP_INPUT_SDFM1_FLT2_COMPARE_HIGH_OR_LOW,    /*!< SDFM-1 Filter-2 Compare High Trip or Low Trip */
    ECAP_INPUT_SDFM1_FLT3_COMPARE_HIGH_OR_LOW,    /*!< SDFM-1 Filter-3 Compare High Trip or Low Trip */
    ECAP_INPUT_SDFM1_FLT4_COMPARE_HIGH_OR_LOW,    /*!< SDFM-1 Filter-4 Compare High Trip or Low Trip */
    ECAP_INPUT_CMPSS1_CTRIP_LOW = 96U,            /*!< Compare Subsystem-1 Low Trip */
    ECAP_INPUT_CMPSS2_CTRIP_LOW,                  /*!< Compare Subsystem-2 Low Trip */
    ECAP_INPUT_CMPSS3_CTRIP_LOW,                  /*!< Compare Subsystem-3 Low Trip */
    ECAP_INPUT_CMPSS4_CTRIP_LOW,                  /*!< Compare Subsystem-4 Low Trip */
    ECAP_INPUT_CMPSS5_CTRIP_LOW,                  /*!< Compare Subsystem-5 Low Trip */
    ECAP_INPUT_CMPSS6_CTRIP_LOW,                  /*!< Compare Subsystem-6 Low Trip */
    ECAP_INPUT_CMPSS7_CTRIP_LOW,                  /*!< Compare Subsystem-7 Low Trip */
    ECAP_INPUT_CMPSS8_CTRIP_LOW,                  /*!< Compare Subsystem-8 Low Trip */
    ECAP_INPUT_CMPSS1_CTRIP_HIGH = 107U,          /*!< Compare Subsystem-1 High Trip */
    ECAP_INPUT_CMPSS2_CTRIP_HIGH,                 /*!< Compare Subsystem-2 High Trip */
    ECAP_INPUT_CMPSS3_CTRIP_HIGH,                 /*!< Compare Subsystem-3 High Trip */
    ECAP_INPUT_CMPSS4_CTRIP_HIGH,                 /*!< Compare Subsystem-4 High Trip */
    ECAP_INPUT_CMPSS5_CTRIP_HIGH,                 /*!< Compare Subsystem-5 High Trip */
    ECAP_INPUT_CMPSS6_CTRIP_HIGH,                 /*!< Compare Subsystem-6 High Trip */
    ECAP_INPUT_CMPSS7_CTRIP_HIGH,                 /*!< Compare Subsystem-7 High Trip */
    ECAP_INPUT_CMPSS8_CTRIP_HIGH,                 /*!< Compare Subsystem-8 High Trip */
    ECAP_INPUT_GPIO8,                             /*!< Compare GPIO8 */
    ECAP_INPUT_GPIO9,                             /*!< Compare GPIO9 */
    ECAP_INPUT_GPIO22,                            /*!< Compare GPIO22 */
    ECAP_INPUT_GPIO23,                            /*!< Compare GPIO23 */
    ECAP_INPUT_CMPSS1_CTRIP_HIGH_OR_LOW,          /*!< Compare Subsystem-1 High Trip or Low Trip */
    ECAP_INPUT_CMPSS2_CTRIP_HIGH_OR_LOW,          /*!< Compare Subsystem-2 High Trip or Low Trip */
    ECAP_INPUT_CMPSS3_CTRIP_HIGH_OR_LOW,          /*!< Compare Subsystem-3 High Trip or Low Trip */
    ECAP_INPUT_CMPSS4_CTRIP_HIGH_OR_LOW,          /*!< Compare Subsystem-4 High Trip or Low Trip */
    ECAP_INPUT_CMPSS5_CTRIP_HIGH_OR_LOW,          /*!< Compare Subsystem-5 High Trip or Low Trip */
    ECAP_INPUT_CMPSS6_CTRIP_HIGH_OR_LOW,          /*!< Compare Subsystem-6 High Trip or Low Trip */
    ECAP_INPUT_CMPSS7_CTRIP_HIGH_OR_LOW,          /*!< Compare Subsystem-7 High Trip or Low Trip */
    ECAP_INPUT_CMPSS8_CTRIP_HIGH_OR_LOW,          /*!< Compare Subsystem-8 High Trip or Low Trip */
    ECAP_INPUT_ECAP1_EPWM_TRIPIN3 = 127U,         /*!< EPWM Trip IN for ECAP1 instance */
    ECAP_INPUT_ECAP2_EPWM_TRIPIN4 = 127U,         /*!< EPWM Trip IN for ECAP2 instance */
    ECAP_INPUT_ECAP3_EPWM_TRIPIN5 = 127U,         /*!< EPWM Trip IN for ECAP3  instance */
    ECAP_INPUT_ECAP4_EPWM_TRIPIN6 = 127U,         /*!< EPWM Trip IN for ECAP4 instance */
    ECAP_INPUT_ECAP5_EPWM_TRIPIN7 = 127U,         /*!< EPWM Trip IN for ECAP5 instance */
    ECAP_INPUT_ECAP6_EPWM_TRIPIN8 = 127U,         /*!< EPWM Trip IN for ECAP6 instance */
    ECAP_INPUT_ECAP7_EPWM_TRIPIN1 = 127U,         /*!< EPWM Trip IN for ECAP7 instance */
    ECAP_INPUT_SDFM4_FLT1_COMPARE_LOW,            /*!< SDFM-4 Filter-1 Compare Low Trip */
    ECAP_INPUT_SDFM4_FLT2_COMPARE_LOW,            /*!< SDFM-4 Filter-2 Compare Low Trip */
    ECAP_INPUT_SDFM4_FLT3_COMPARE_LOW,            /*!< SDFM-4 Filter-3 Compare Low Trip */
    ECAP_INPUT_SDFM4_FLT4_COMPARE_LOW,            /*!< SDFM-4 Filter-4 Compare Low Trip */
    ECAP_INPUT_SDFM3_FLT1_COMPARE_LOW,            /*!< SDFM-3 Filter-1 Compare Low Trip */
    ECAP_INPUT_SDFM3_FLT2_COMPARE_LOW,            /*!< SDFM-3 Filter-2 Compare Low Trip */
    ECAP_INPUT_SDFM3_FLT3_COMPARE_LOW,            /*!< SDFM-3 Filter-3 Compare Low Trip */
    ECAP_INPUT_SDFM3_FLT4_COMPARE_LOW,            /*!< SDFM-3 Filter-4 Compare Low Trip */
    ECAP_INPUT_SDFM4_FLT1_COMPARE_ZERO,           /*!< SDFM-4 Filter-1 Compare ZERO Trip */
    ECAP_INPUT_SDFM4_FLT2_COMPARE_ZERO,           /*!< SDFM-4 Filter-2 Compare ZERO Trip */
    ECAP_INPUT_SDFM4_FLT3_COMPARE_ZERO,           /*!< SDFM-4 Filter-3 Compare ZERO Trip */
    ECAP_INPUT_SDFM4_FLT4_COMPARE_ZERO,           /*!< SDFM-4 Filter-4 Compare ZERO Trip */
    ECAP_INPUT_SDFM3_FLT1_COMPARE_ZERO,           /*!< SDFM-3 Filter-1 Compare ZERO Trip */
    ECAP_INPUT_SDFM3_FLT2_COMPARE_ZERO,           /*!< SDFM-3 Filter-2 Compare ZERO Trip */
    ECAP_INPUT_SDFM3_FLT3_COMPARE_ZERO,           /*!< SDFM-3 Filter-3 Compare ZERO Trip */
    ECAP_INPUT_SDFM3_FLT4_COMPARE_ZERO,           /*!< SDFM-3 Filter-4 Compare ZERO Trip */
    ECAP_INPUT_SDFM4_FLT1_COMPARE_HIGH,           /*!< SDFM-4 Filter-1 Compare High Trip */
    ECAP_INPUT_SDFM4_FLT2_COMPARE_HIGH,           /*!< SDFM-4 Filter-2 Compare High Trip */
    ECAP_INPUT_SDFM4_FLT3_COMPARE_HIGH,           /*!< SDFM-4 Filter-3 Compare High Trip */
    ECAP_INPUT_SDFM4_FLT4_COMPARE_HIGH,           /*!< SDFM-4 Filter-4 Compare High Trip */
    ECAP_INPUT_SDFM3_FLT1_COMPARE_HIGH,           /*!< SDFM-3 Filter-1 Compare High Trip */
    ECAP_INPUT_SDFM3_FLT2_COMPARE_HIGH,           /*!< SDFM-3 Filter-2 Compare High Trip */
    ECAP_INPUT_SDFM3_FLT3_COMPARE_HIGH,           /*!< SDFM-3 Filter-3 Compare High Trip */
    ECAP_INPUT_SDFM3_FLT4_COMPARE_HIGH,           /*!< SDFM-3 Filter-4 Compare High Trip */
    ECAP_INPUT_SDFM4_FLT1_COMPARE_HIGH_OR_LOW,    /*!< SDFM-4 Filter-1 Compare High Trip or Low Trip */
    ECAP_INPUT_SDFM4_FLT2_COMPARE_HIGH_OR_LOW,    /*!< SDFM-4 Filter-2 Compare High Trip or Low Trip */
    ECAP_INPUT_SDFM4_FLT3_COMPARE_HIGH_OR_LOW,    /*!< SDFM-4 Filter-3 Compare High Trip or Low Trip */
    ECAP_INPUT_SDFM4_FLT4_COMPARE_HIGH_OR_LOW,    /*!< SDFM-4 Filter-4 Compare High Trip or Low Trip */
    ECAP_INPUT_SDFM3_FLT1_COMPARE_HIGH_OR_LOW,    /*!< SDFM-3 Filter-1 Compare High Trip or Low Trip */
    ECAP_INPUT_SDFM3_FLT2_COMPARE_HIGH_OR_LOW,    /*!< SDFM-3 Filter-2 Compare High Trip or Low Trip */
    ECAP_INPUT_SDFM3_FLT3_COMPARE_HIGH_OR_LOW,    /*!< SDFM-3 Filter-3 Compare High Trip or Low Trip */
    ECAP_INPUT_SDFM3_FLT4_COMPARE_HIGH_OR_LOW,    /*!< SDFM-3 Filter-4 Compare High Trip or Low Trip */
    ECAP_INPUT_EPWM18_DEL_ACTIVE,                 /*!< EPWM-18 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM17_DEL_ACTIVE,                 /*!< EPWM-17 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM16_DEL_ACTIVE,                 /*!< EPWM-16 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM15_DEL_ACTIVE,                 /*!< EPWM-15 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM14_DEL_ACTIVE,                 /*!< EPWM-14 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM13_DEL_ACTIVE,                 /*!< EPWM-13 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM12_DEL_ACTIVE,                 /*!< EPWM-12 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM11_DEL_ACTIVE,                 /*!< EPWM-11 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM10_DEL_ACTIVE,                 /*!< EPWM-10 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM9_DEL_ACTIVE,                  /*!< EPWM-9 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM8_DEL_ACTIVE,                  /*!< EPWM-8 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM7_DEL_ACTIVE,                  /*!< EPWM-7 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM6_DEL_ACTIVE,                  /*!< EPWM-6 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM5_DEL_ACTIVE,                  /*!< EPWM-5 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM4_DEL_ACTIVE,                  /*!< EPWM-4 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM3_DEL_ACTIVE,                  /*!< EPWM-3 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM2_DEL_ACTIVE,                  /*!< EPWM-2 Diode Emulation Logic Active */
    ECAP_INPUT_EPWM1_DEL_ACTIVE,                  /*!< EPWM-1 Diode Emulation Logic Active */
    ECAP_INPUT_GPIO11 = 251,                      /*!< GPIO11 */
    ECAP_INPUT_GPIO12,                            /*!< GPIO12 */
    ECAP_INPUT_GPIO13,                            /*!< GPIO13 */
    ECAP_INPUT_GPIO14,                            /*!< GPIO14 */
    ECAP_INPUT_ECAP1_EPG1_DATAOUT53 = 255,        /*!< EPG-1 Data Output-53 Connection */
    ECAP_INPUT_ECAP2_EPG1_DATAOUT54 = 255,        /*!< EPG-1 Data Output-54 Connection */
    ECAP_INPUT_ECAP3_EPG1_DATAOUT55 = 255,        /*!< EPG-1 Data Output-55 Connection */
    ECAP_INPUT_ECAP4_EPG1_DATAOUT56 = 255,        /*!< EPG-1 Data Output-56 Connection */
    ECAP_INPUT_ECAP5_EPG1_DATAOUT57 = 255,        /*!< EPG-1 Data Output-57 Connection */
    ECAP_INPUT_ECAP6_EPG1_DATAOUT58 = 255,        /*!< EPG-1 Data Output-58 Connection */
    ECAP_INPUT_ECAP7_EPG1_DATAOUT59 = 255         /*!< EPG-1 Data Output-59 Connection */

} ECAP_InputCaptureSignals;

/**
  * @}
  */

/** @defgroup ECAP_QUALPERIODSELECT Number with one group(ECAP1/2/3/4/5/6/7)
  * @{
  * @brief Values are used to select the ECAP qual period to filter out noise.
  */
typedef enum {

    ECAP_PULSE_WIDTH_FILTER_BYPASS = 0U,    /*!< Bypass */
    ECAP_PULSE_WIDTH_FILTER_CYCLE1,         /*!< Pulse width less than 1 cycle */
    ECAP_PULSE_WIDTH_FILTER_CYCLE2,         /*!< Pulse width less than 2 cycles */
    ECAP_PULSE_WIDTH_FILTER_CYCLE3,         /*!< Pulse width less than 3 cycles */
    ECAP_PULSE_WIDTH_FILTER_CYCLE4,         /*!< Pulse width less than 4 cycles */
    ECAP_PULSE_WIDTH_FILTER_CYCLE5,         /*!< Pulse width less than 5 cycles */
    ECAP_PULSE_WIDTH_FILTER_CYCLE6,         /*!< Pulse width less than 6 cycles */
    ECAP_PULSE_WIDTH_FILTER_CYCLE7,         /*!< Pulse width less than 7 cycles */
    ECAP_PULSE_WIDTH_FILTER_CYCLE8,         /*!< Pulse width less than 8 cycles */
    ECAP_PULSE_WIDTH_FILTER_CYCLE9,         /*!< Pulse width less than 9 cycles */
    ECAP_PULSE_WIDTH_FILTER_CYCLE10,        /*!< Pulse width less than 10 cycles */
    ECAP_PULSE_WIDTH_FILTER_CYCLE11,        /*!< Pulse width less than 11 cycles */
    ECAP_PULSE_WIDTH_FILTER_CYCLE12,        /*!< Pulse width less than 12 cycles */
    ECAP_PULSE_WIDTH_FILTER_CYCLE13,        /*!< Pulse width less than 13 cycles */
    ECAP_PULSE_WIDTH_FILTER_CYCLE14,        /*!< Pulse width less than 14 cycles */
    ECAP_PULSE_WIDTH_FILTER_CYCLE15,        /*!< Pulse width less than 15 cycles */
} ECAP_QualPeriodSelect;

/**
  * @}
  */

/** @defgroup ECAP_SYNCINPULSESOURCE Number with one group(ECAP1/2/3/4/5/6/7)
  * @{
  * @brief Macro definitions about ECAP sync in pulse source.
  */
typedef enum {
    ECAP_SYNC_IN_PULSE_SRC_DISABLE = 0U,             /*!< Disable Sync-in */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM1,            /*!< Sync-in source is EPWM1 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM2,            /*!< Sync-in source is EPWM2 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM3,            /*!< Sync-in source is EPWM3 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM4,            /*!< Sync-in source is EPWM4 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM5,            /*!< Sync-in source is EPWM5 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM6,            /*!< Sync-in source is EPWM6 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM7,            /*!< Sync-in source is EPWM7 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM8,            /*!< Sync-in source is EPWM8 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM9,            /*!< Sync-in source is ECAP9 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM10,           /*!< Sync-in source is ECAP10 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM11,           /*!< Sync-in source is ECAP11 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM12,           /*!< Sync-in source is ECAP12 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM13,           /*!< Sync-in source is ECAP13 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM14,           /*!< Sync-in source is ECAP14 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM15,           /*!< Sync-in source is ECAP15 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM16,           /*!< Sync-in source is ECAP16 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP1,            /*!< Sync-in source is ECAP1 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP2,            /*!< Sync-in source is ECAP2 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP3,            /*!< Sync-in source is ECAP3 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP4,            /*!< Sync-in source is ECAP4 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP5,            /*!< Sync-in source is ECAP5 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP6,            /*!< Sync-in source is ECAP6 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP7,            /*!< Sync-in source is ECAP7 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT5,           /*!< Sync-in source is Input XBAR out5 signal */
    ECAP_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT6,           /*!< Sync-in source is Input XBAR out6 signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM17 = 0x1C,    /*!< Sync-in source is EPWM17 sync-out signal */
    ECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM18            /*!< Sync-in source is EPWM18 sync-out signal */
} ECAP_SyncInPulseSource;

/**
  * @}
  */

/** @defgroup ECAP_SYNCINPULSESO Number with one group(ECAP1/2/3/4/5/6/7)
  * @{
  * @brief Values that can be passed to ECAP Signal Monitoring APIs.
  */
typedef enum {
    ECAP_MONITORING_UNIT_1 = 0U,    /*!< ECAP Monitoring Unit 1 */
    ECAP_MONITORING_UNIT_2          /*!< ECAP Monitoring Unit 2 */
} ECAP_MonitorUnit;

/**
  * @}
  */

/** @defgroup ECAP_MAXERRORCHECK Number with one group(ECAP1/2/3/4/5/6/7)
  * @{
  * @brief Values that can be passed to ECAP_setupEarlyMaxErrorCheck() as the
  *        \e checkError parameter.
  */
typedef enum {
    ECAP_PULSE_WIDTH_CROSS_MAX_VALUE = 0U,    /*!< Max error generated as soon as pulse width crosses max value */
    ECAP_SECOND_EVENT_OCCURED                 /*!< Max error generated when second event has occured */
} ECAP_MaxErrorCheck;

/**
  * @}
  */

/** @defgroup ECAP_SHADOWLOADMODE Number with one group(ECAP1/2/3/4/5/6/7)
  * @{
  * @brief Values that can be passed to ECAP_selectShadowLoadMode() as the
  *        \e loadMode parameter.
  */
typedef enum {
    ECAP_ACTIVE_LOAD_SYNC_EVT = 0U,    /*!< Load on next sync event */
    ECAP_ACTIVE_LOAD_GLDLCSTRB_EVT     /*!< Load on EPWM GLDLCSTRB event */
} ECAP_ShadowLoadMode;

/**
  * @}
  */

/** @defgroup ECAP_MONITORINGTYPESELECT Number with one group(ECAP1/2/3/4/5/6/7)
  * @{
  * @brief Values that can be passed to ECAP_selectMonitoringType() as the
  *        \e monSel parameter.
  */
typedef enum
{
    ECAP_MUNIT_HIGH_PULSE_WIDTH = 0U,    /*!< High Pulse Width */
    ECAP_MUNIT_LOW_PULSE_WIDTH,          /*!< Low Pulse Width */
    ECAP_MUNIT_PERIOD_WIDTH_RISE_RISE,   /*!< Period width from rise to rise */
    ECAP_MUNIT_PERIOD_WIDTH_FALL_FALL,   /*!< Period width from fall to fall */
    ECAP_MUNIT_MONITOR_RISE_EDGE,        /*!< Monitor rise edge */
    ECAP_MUNIT_MONITOR_FALL_EDGE         /*!< Monitor fall edge */
}ECAP_MonitoringTypeSelect;

/**
  * @}
  */

/** @defgroup ECAP_MUNITTRIPINPUTSSELECT Number with one group(ECAP1/2/3/4/5/6/7)
  * @{
  * @brief Values that can be passed to ECAP_selectTripSignal() &
  *        ECAP_selectGlobalLoadStrobe() as the \e tripSel and \e strobe parameter.
  */
typedef enum {
    ECAP_MUNIT_TRIP_DISABLED = 0U,          /*!< Disabled */
    ECAP_MUNIT_TRIP_EPWM_XBARA_OUT1,        /*!< MUNIT trip source is PWMXBAR-A output 1 */
    ECAP_MUNIT_TRIP_EPWM_XBARA_OUT2,        /*!< MUNIT trip source is PWMXBAR-A output 2 */
    ECAP_MUNIT_TRIP_EPWM_XBARA_OUT3,        /*!< MUNIT trip source is PWMXBAR-A output 3 */
    ECAP_MUNIT_TRIP_EPWM_XBARA_OUT4,        /*!< MUNIT trip source is PWMXBAR-A output 4 */
    ECAP_MUNIT_TRIP_EPWM_XBARA_OUT5,        /*!< MUNIT trip source is PWMXBAR-A output 5 */
    ECAP_MUNIT_TRIP_EPWM_XBARA_OUT6,        /*!< MUNIT trip source is PWMXBAR-A output 6 */
    ECAP_MUNIT_TRIP_EPWM_XBARA_OUT7,        /*!< MUNIT trip source is PWMXBAR-A output 7 */
    ECAP_MUNIT_TRIP_EPWM_XBARA_OUT8,        /*!< MUNIT trip source is PWMXBAR-A output 8 */
    ECAP_MUNIT_TRIP_EPWM_XBARB_OUT1,        /*!< MUNIT trip source is PWMXBAR-B output 1 */
    ECAP_MUNIT_TRIP_EPWM_XBARB_OUT2,        /*!< MUNIT trip source is PWMXBAR-B output 2 */
    ECAP_MUNIT_TRIP_EPWM_XBARB_OUT3,        /*!< MUNIT trip source is PWMXBAR-B output 3 */
    ECAP_MUNIT_TRIP_EPWM_XBARB_OUT4,        /*!< MUNIT trip source is PWMXBAR-B output 4 */
    ECAP_MUNIT_TRIP_EPWM_XBARB_OUT5,        /*!< MUNIT trip source is PWMXBAR-B output 5 */
    ECAP_MUNIT_TRIP_EPWM_XBARB_OUT6,        /*!< MUNIT trip source is PWMXBAR-B output 6 */
    ECAP_MUNIT_TRIP_EPWM_XBARB_OUT7,        /*!< MUNIT trip source is PWMXBAR-B output 7 */
    ECAP_MUNIT_TRIP_EPWM_XBARB_OUT8,        /*!< MUNIT trip source is PWMXBAR-B output 8 */
    ECAP_MUNIT_TRIP_EPWM1_TRIPOUT = 32U,    /*!< MUNIT trip source is EPWM1 trip out signal */
    ECAP_MUNIT_TRIP_EPWM2_TRIPOUT,          /*!< MUNIT trip source is EPWM2 trip out signal */
    ECAP_MUNIT_TRIP_EPWM3_TRIPOUT,          /*!< MUNIT trip source is EPWM3 trip out signal */
    ECAP_MUNIT_TRIP_EPWM4_TRIPOUT,          /*!< MUNIT trip source is EPWM4 trip out signal */
    ECAP_MUNIT_TRIP_EPWM5_TRIPOUT,          /*!< MUNIT trip source is EPWM5 trip out signal */
    ECAP_MUNIT_TRIP_EPWM6_TRIPOUT,          /*!< MUNIT trip source is EPWM6 trip out signal */
    ECAP_MUNIT_TRIP_EPWM7_TRIPOUT,          /*!< MUNIT trip source is EPWM7 trip out signal */
    ECAP_MUNIT_TRIP_EPWM8_TRIPOUT,          /*!< MUNIT trip source is EPWM8 trip out signal */
    ECAP_MUNIT_TRIP_EPWM9_TRIPOUT,          /*!< MUNIT trip source is EPWM9 trip out signal */
    ECAP_MUNIT_TRIP_EPWM10_TRIPOUT,         /*!< MUNIT trip source is EPWM10 trip out signal */
    ECAP_MUNIT_TRIP_EPWM11_TRIPOUT,         /*!< MUNIT trip source is EPWM11 trip out signal */
    ECAP_MUNIT_TRIP_EPWM12_TRIPOUT,         /*!< MUNIT trip source is EPWM12 trip out signal */
    ECAP_MUNIT_TRIP_EPWM13_TRIPOUT,         /*!< MUNIT trip source is EPWM13 trip out signal */
    ECAP_MUNIT_TRIP_EPWM14_TRIPOUT,         /*!< MUNIT trip source is EPWM14 trip out signal */
    ECAP_MUNIT_TRIP_EPWM15_TRIPOUT,         /*!< MUNIT trip source is EPWM15 trip out signal */
    ECAP_MUNIT_TRIP_EPWM16_TRIPOUT,         /*!< MUNIT trip source is EPWM16 trip out signal */
    ECAP_MUNIT_TRIP_EPWM17_TRIPOUT,         /*!< MUNIT trip source is EPWM17 trip out signal */
    ECAP_MUNIT_TRIP_EPWM18_TRIPOUT          /*!< MUNIT trip source is EPWM18 trip out signal */
} ECAP_MunitTripInputSelect;

/**
  * @}
  */

/**
  * @}
  */


/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
 * \brief  Sets the input prescaler.
 *         This function divides the ECAP input scaler. The pre scale value is doubled inside the module.
 *         For example a preScalerValue of 5 will divide the input clock by 10.
 *         The pre scaler value is calculated as follows:preScalerValue = (ECAP input clock / (ECAP output clock * 2)) -
 * 1
 * \param  ecap              ecap pointer to a ECAP_TypeDef structure
 *                            - ECAP1: ECAP1 base address index
 *                            - ECAP2: ECAP2 base address index
 *                            - ECAP3: ECAP3 base address index
 *                            - ECAP4: ECAP4 base address index
 *                            - ECAP5: ECAP5 base address index
 *                            - ECAP6: ECAP6 base address index
 *                            - ECAP7: ECAP7 base address index
 * \param  preScalerValue    preScalerValue is the pre scaler value for ECAP input
 *                            This parameter can be less than 32U
 */
static inline void ECAP_setEventPrescaler (ECAP_TypeDef *ecap, uint16_t preScalerValue)
{
    MODIFY_REG(ecap->ECCTL1.WORDVAL, ECAP_ECCTL1_PRESCALE_M,
               (((uint32_t)preScalerValue << ECAP_ECCTL1_PRESCALE_S) & ECAP_ECCTL1_PRESCALE_M));
}

/**
 * \brief  Sets the Capture event polarity.
 * \note   This function sets the polarity of a given event.
 * \param  ecap        ecap pointer to a ECAP_TypeDef structure
 *                      - ECAP1: ECAP1 base address index
 *                      - ECAP2: ECAP2 base address index
 *                      - ECAP3: ECAP3 base address index
 *                      - ECAP4: ECAP4 base address index
 *                      - ECAP5: ECAP5 base address index
 *                      - ECAP6: ECAP6 base address index
 *                      - ECAP7: ECAP7 base address index
 * \param  event       event is the event number for ECAP input
 *                      This parameter can be one of the following @ref ECAP_Events:
 * \param  polarity    polarity is the polarity for ECAP input
 *                      This parameter can be one of the following @ref ECAP_EventPolarity:
 */
static inline void ECAP_setEventPolarity (ECAP_TypeDef *ecap, ECAP_Events event, ECAP_EventPolarity polarity)
{
    uint16_t shift;

    shift = ((uint16_t)event) << 1UL;
    MODIFY_REG(ecap->ECCTL1.WORDVAL, (1 << shift), ((uint32_t)polarity << shift));
}

/**
 * \brief  Sets the capture mode.
 * \note   This function sets the capture mode.
 *         The value of event determines the event number at which the counter stops
 *         (in one-shot mode) or the counter wraps (in continuous mode).
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  mode     mode is the input source
 *                   This parameter can be one of the following @ref ECAP_CaptureMode:
 * \param  event    event is the event number for ECAP input
 *                   This parameter can be one of the following @ref ECAP_Events:
 */
static inline void ECAP_setCaptureMode (ECAP_TypeDef *ecap, ECAP_CaptureMode mode, ECAP_Events event)
{
    MODIFY_REG(ecap->ECCTL2.WORDVAL, ECAP_ECCTL2_CONTONESHT_M, (uint32_t)mode);
    MODIFY_REG(ecap->ECCTL2.WORDVAL, ECAP_ECCTL2_STOPWRAP_M, ((uint32_t)event << ECAP_ECCTL2_STOPWRAP_S));
}

/**
 * \brief  Re-arms the eCAP module.
 * \note   This function re-arms the eCAP module.
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 */
static inline void ECAP_reArm (ECAP_TypeDef *ecap)
{
    SET_BIT(ecap->ECCTL2.WORDVAL, ECAP_ECCTL2_REARM_M);
}

/**
 * \brief  Enables interrupt source.
 * \note   This function sets and enables eCAP interrupt source.
 * \param  ecap        ecap pointer to a ECAP_TypeDef structure
 *                      - ECAP1: ECAP1 base address index
 *                      - ECAP2: ECAP2 base address index
 *                      - ECAP3: ECAP3 base address index
 *                      - ECAP4: ECAP4 base address index
 *                      - ECAP5: ECAP5 base address index
 *                      - ECAP6: ECAP6 base address index
 *                      - ECAP7: ECAP7 base address index
 * \param  intFlags    intFlags is the interrupt flags
 *                      This parameter can be one of the following \b @ref ECAP_ECEINT_REGBIT:
 *                        ECAP_ECEINT_CEVT1_M
 *                        ECAP_ECEINT_CEVT2_M
 *                        ECAP_ECEINT_CEVT3_M
 *                        ECAP_ECEINT_CEVT4_M
 *                        ECAP_ECEINT_CTROVF_M
 *                        ECAP_ECEINT_CTREQPRD_M
 *                        ECAP_ECEINT_CTREQCMP_M
 *                        ECAP_ECEINT_MUNIT1ERROREVT1EN_M
 *                        ECAP_ECEINT_MUNIT1ERROREVT2EN_M
 *                        ECAP_ECEINT_MUNIT2ERROREVT1EN_M
 *                        ECAP_ECEINT_MUNIT2ERROREVT2EN_M
 */
static inline void ECAP_enableInterrupt (ECAP_TypeDef *ecap, uint16_t intFlags)
{
    SET_BIT(ecap->ECEINT.WORDVAL, (uint32_t)intFlags);
}

/**
 * \brief  Disables interrupt source.
 * \param  ecap        ecap pointer to a ECAP_TypeDef structure
 *                      - ECAP1: ECAP1 base address index
 *                      - ECAP2: ECAP2 base address index
 *                      - ECAP3: ECAP3 base address index
 *                      - ECAP4: ECAP4 base address index
 *                      - ECAP5: ECAP5 base address index
 *                      - ECAP6: ECAP6 base address index
 *                      - ECAP7: ECAP7 base address index
 * \param  intFlags    intFlags is the interrupt flags
 *                      This parameter can be one of the following \b @ref ECAP_ECEINT_REGBIT:
 *                        ECAP_ECEINT_CEVT1_M
 *                        ECAP_ECEINT_CEVT2_M
 *                        ECAP_ECEINT_CEVT3_M
 *                        ECAP_ECEINT_CEVT4_M
 *                        ECAP_ECEINT_CTROVF_M
 *                        ECAP_ECEINT_CTREQPRD_M
 *                        ECAP_ECEINT_CTREQCMP_M
 *                        ECAP_ECEINT_MUNIT1ERROREVT1EN_M
 *                        ECAP_ECEINT_MUNIT1ERROREVT2EN_M
 *                        ECAP_ECEINT_MUNIT2ERROREVT1EN_M
 *                        ECAP_ECEINT_MUNIT2ERROREVT2EN_M
 */
static inline void ECAP_disableInterrupt (ECAP_TypeDef *ecap, uint16_t intFlags)
{
    CLEAR_BIT(ecap->ECEINT.WORDVAL, (uint32_t)intFlags);
}

/**
 * \brief  Returns the interrupt flag.
 * \note   This function returns the eCAP interrupt flag.
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 * \return  Returns the eCAP interrupt that has occurred.
 */
static inline uint16_t ECAP_getInterruptSource (ECAP_TypeDef *ecap)
{
    return (uint16_t)READ_BIT(ecap->ECFLAG.WORDVAL, 0x1EFEU);
}

/**
 * \brief  Returns the global interrupt status.
 * \note   This function returns the eCAP global interrupt status.
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 * \return  Returns true if there is a global eCAP interrupt, false otherwise.
 */
static inline uint8_t ECAP_getGlobalInterruptStatus (ECAP_TypeDef *ecap)
{
    return (uint8_t)(READ_BIT(ecap->ECFLAG.WORDVAL, 0x1U) == 0x1U);
}

/**
 * \brief  Clears the interrupt flag.
 * \note   This function clears the eCAP interrupt flag.
 * \param  ecap        ecap pointer to a ECAP_TypeDef structure
 *                      - ECAP1: ECAP1 base address index
 *                      - ECAP2: ECAP2 base address index
 *                      - ECAP3: ECAP3 base address index
 *                      - ECAP4: ECAP4 base address index
 *                      - ECAP5: ECAP5 base address index
 *                      - ECAP6: ECAP6 base address index
 *                      - ECAP7: ECAP7 base address index
 * \param  intFlags    intFlags is the interrupt flags
 *                      This parameter can be one of the following \b @ref ECAP_ECCLR_REGBIT:
 *                        ECAP_ECCLR_CEVT1_M
 *                        ECAP_ECCLR_CEVT2_M
 *                        ECAP_ECCLR_CEVT3_M
 *                        ECAP_ECCLR_CEVT4_M
 *                        ECAP_ECCLR_CTROVF_M
 *                        ECAP_ECCLR_CTRPRD_M
 *                        ECAP_ECCLR_CTRCMP_M
 *                        ECAP_ECCLR_MUNIT1ERROREVT1_M
 *                        ECAP_ECCLR_MUNIT1ERROREVT2_M
 *                        ECAP_ECCLR_MUNIT2ERROREVT1_M
 *                        ECAP_ECCLR_MUNIT2ERROREVT2_M
 */
static inline void ECAP_clearInterrupt (ECAP_TypeDef *ecap, uint16_t intFlags)
{
    WRITE_REG(ecap->ECCLR.WORDVAL, (uint32_t)intFlags);
}

/**
 * \brief  Clears the global interrupt flag.
 * \note   This function clears the eCAP global interrupt flag.
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 */
static inline void ECAP_clearGlobalInterrupt (ECAP_TypeDef *ecap)
{
    WRITE_REG(ecap->ECCLR.WORDVAL, ECAP_ECCLR_INT_M);
}

/**
 * \brief  Forces the interrupt flag.
 * \note   This function forces and enables eCAP interrupt source.
 * \param  ecap        ecap pointer to a ECAP_TypeDef structure
 *                      - ECAP1: ECAP1 base address index
 *                      - ECAP2: ECAP2 base address index
 *                      - ECAP3: ECAP3 base address index
 *                      - ECAP4: ECAP4 base address index
 *                      - ECAP5: ECAP5 base address index
 *                      - ECAP6: ECAP6 base address index
 *                      - ECAP7: ECAP7 base address index
 * \param  intFlags    intFlags is the interrupt flags
 *                      This parameter can be one of the following \b @ref ECAP_ECFRC_REGBIT:
 *                        ECAP_ECFRC_CEVT1_M
 *                        ECAP_ECFRC_CEVT2_M
 *                        ECAP_ECFRC_CEVT3_M
 *                        ECAP_ECFRC_CEVT4_M
 *                        ECAP_ECFRC_CTROVF_M
 *                        ECAP_ECFRC_CTRPRD_M
 *                        ECAP_ECFRC_CTRCMP_M
 *                        ECAP_ECFRC_MUNIT1ERROREVT1_M
 *                        ECAP_ECFRC_MUNIT1ERROREVT2_M
 *                        ECAP_ECFRC_MUNIT2ERROREVT1_M
 *                        ECAP_ECFRC_MUNIT2ERROREVT2_M
 */
static inline void ECAP_forceInterrupt (ECAP_TypeDef *ecap, uint16_t intFlags)
{
    WRITE_REG(ecap->ECFRC.WORDVAL, (uint32_t)intFlags);
}

/**
 * \brief  Sets eCAP in Capture mode.
 * \note   This function sets the eCAP module to operate in Capture mode.
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 */
static inline void ECAP_enableCaptureMode (ECAP_TypeDef *ecap)
{
    CLEAR_BIT(ecap->ECCTL2.WORDVAL, ECAP_ECCTL2_CAPAPWM_M);
}

/**
 * \brief  Sets eCAP in APWM mode.
 * \note   This function sets the eCAP module to operate in APWM mode.
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 */
static inline void ECAP_enableAPWMMode (ECAP_TypeDef *ecap)
{
    SET_BIT(ecap->ECCTL2.WORDVAL, ECAP_ECCTL2_CAPAPWM_M);
}

/**
 * \brief  Enables the counter reset on event.
 * \note   This function enables the base timer, TSCTR, to be reset on capture
 *         event provided by the variable event.
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  event    event is the event number for ECAP input
 *                   This parameter can be one of the following @ref ECAP_Events.
 */
static inline void ECAP_enableCounterResetOnEvent (ECAP_TypeDef *ecap, ECAP_Events event)
{
    SET_BIT(ecap->ECCTL1.WORDVAL, 1UL << (((uint16_t)event << 1) + 1U));
}

/**
 * \brief  Disables the counter reset on event.
 * \note   This function disables the base timer, TSCTR, to be reset on capture
 *         event provided by the variable event.
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  event    event is the event number for ECAP input
 *                   This parameter can be one of the following @ref ECAP_Events.
 */
static inline void ECAP_disableCounterResetOnEvent (ECAP_TypeDef *ecap, ECAP_Events event)
{
    CLEAR_BIT(ecap->ECCTL1.WORDVAL, 1UL << (((uint16_t)event << 1) + 1U));
}

/**
 * \brief  Enables time stamp capture.
 * \note   This function enables time stamp count to be captured
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 */
static inline void ECAP_enableTimeStampCapture (ECAP_TypeDef *ecap)
{
    SET_BIT(ecap->ECCTL1.WORDVAL, ECAP_ECCTL1_CAPLDEN_M);
}

/**
 * \brief  Disables time stamp capture.
 * \note   This function disables time stamp count to be captured
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 */
static inline void ECAP_disableTimeStampCapture (ECAP_TypeDef *ecap)
{
    CLEAR_BIT(ecap->ECCTL1.WORDVAL, ECAP_ECCTL1_CAPLDEN_M);
}

/**
 * \brief  Sets the time stamp counter.
 * \note   This function writes a phase shift value to be loaded into the main time stamp counter.
 * \param  ecap         ecap pointer to a ECAP_TypeDef structure
 *                       - ECAP1: ECAP1 base address index
 *                       - ECAP2: ECAP2 base address index
 *                       - ECAP3: ECAP3 base address index
 *                       - ECAP4: ECAP4 base address index
 *                       - ECAP5: ECAP5 base address index
 *                       - ECAP6: ECAP6 base address index
 *                       - ECAP7: ECAP7 base address index
 * \param  timeStamp    timeStamp is the time stamp counter value
 *                       This parameter can be shiftCount is the phase shift value.
 */
static inline void ECAP_setPhaseShiftCount (ECAP_TypeDef *ecap, uint32_t shiftCount)
{
    WRITE_REG(ecap->CTRPHS.WORDVAL, shiftCount);
}

/**
 * \brief  Set up the source for sync-in pulse.
 * \note   This function writes a phase shift value to be loaded into the main time stamp counter.
 * \param  ecap      ecap pointer to a ECAP_TypeDef structure
 *                    - ECAP1: ECAP1 base address index
 *                    - ECAP2: ECAP2 base address index
 *                    - ECAP3: ECAP3 base address index
 *                    - ECAP4: ECAP4 base address index
 *                    - ECAP5: ECAP5 base address index
 *                    - ECAP6: ECAP6 base address index
 *                    - ECAP7: ECAP7 base address index
 * \param  source    source is the sync-in pulse source.
 *                    This parameter can be one of the following @ref ECAP_SyncInPulseSource.
 */
static inline void ECAP_setSyncInPulseSource (ECAP_TypeDef *ecap, ECAP_SyncInPulseSource source)
{
    MODIFY_REG(ecap->ECAPSYNCINSEL.WORDVAL, ECAP_ECAPSYNCINSEL_SEL_M, ((uint32_t)source & ECAP_ECAPSYNCINSEL_SEL_M));
}

/**
 * \brief  Enable counter loading with phase shift value.
 * \note   This function enables loading of the counter with the value present in the
 *         phase shift counter as defined by the function.
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 */
static inline void ECAP_enableLoadCounter (ECAP_TypeDef *ecap)
{
    SET_BIT(ecap->ECCTL2.WORDVAL, ECAP_ECCTL2_SYNCIEN_M);
}

/**
 * \brief  Disable counter loading with phase shift value.
 * \note   This function disables loading of the counter with the value present in the
 *         phase shift counter as defined by the function.
 *         The counter is not loaded until the next sync-in pulse.
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 */
static inline void ECAP_disableLoadCounter (ECAP_TypeDef *ecap)
{
    CLEAR_BIT(ecap->ECCTL2.WORDVAL, ECAP_ECCTL2_SYNCIEN_M);
}

/**
 * \brief  Load time stamp counter
 * \note   This function forces the value in the phase shift counter register to be
 *         loaded into Time stamp counter register.
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 */
static inline void ECAP_loadCounter (ECAP_TypeDef *ecap)
{
    SET_BIT(ecap->ECCTL2.WORDVAL, ECAP_ECCTL2_SWSYNC_M);
}

/**
 * \brief  Configures Sync out signal mode.
 * \note   This function sets the sync out mode.
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 * \param  mode    mode is the sync-out mode.
 *                  This parameter can be one of the following @ref ECAP_SyncOutMode.
 */
static inline void ECAP_setSyncOutMode (ECAP_TypeDef *ecap, ECAP_SyncOutMode mode)
{
    MODIFY_REG(ecap->ECCTL2.WORDVAL, ECAP_ECCTL2_SYNCOSEL_M, (uint32_t)mode);
}

/**
 * \brief  Stops Time stamp counter.
 * \note   This function stops the time stamp counter.
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 */
static inline void ECAP_stopCounter (ECAP_TypeDef *ecap)
{
    CLEAR_BIT(ecap->ECCTL2.WORDVAL, ECAP_ECCTL2_TSCTRSTOP_M);
}

/**
 * \brief  Starts Time stamp counter.
 * \note   This function starts the time stamp counter.
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 */
static inline void ECAP_startCounter (ECAP_TypeDef *ecap)
{
    SET_BIT(ecap->ECCTL2.WORDVAL, ECAP_ECCTL2_TSCTRSTOP_M);
}

/**
 * \brief  Sets APWM polarity.
 * \note   This function sets the polarity of the eCAP in APWM mode.
 * \param  ecap        ecap pointer to a ECAP_TypeDef structure
 *                      - ECAP1: ECAP1 base address index
 *                      - ECAP2: ECAP2 base address index
 *                      - ECAP3: ECAP3 base address index
 *                      - ECAP4: ECAP4 base address index
 *                      - ECAP5: ECAP5 base address index
 *                      - ECAP6: ECAP6 base address index
 *                      - ECAP7: ECAP7 base address index
 * \param  polarity    polarity is the APWM polarity.
 *                      This parameter can be one of the following @ref ECAP_APWMPolarity.
 */
static inline void ECAP_setAPWMPolarity (ECAP_TypeDef *ecap, ECAP_APWMPolarity polarity)
{
    MODIFY_REG(ecap->ECCTL2.WORDVAL, ECAP_ECCTL2_APWMPOL_M, (uint32_t)polarity);
}

/**
 * \brief  Sets APWM period.
 * \note   This function sets the period count of the APWM waveform.
 * \param  ecap           ecap pointer to a ECAP_TypeDef structure
 *                         - ECAP1: ECAP1 base address index
 *                         - ECAP2: ECAP2 base address index
 *                         - ECAP3: ECAP3 base address index
 *                         - ECAP4: ECAP4 base address index
 *                         - ECAP5: ECAP5 base address index
 *                         - ECAP6: ECAP6 base address index
 *                         - ECAP7: ECAP7 base address index
 * \param  periodCount    periodCount is the period count for APWM.
 *                         This parameter can be a value between 0x0000 and 0xFFFF.
 */
static inline void ECAP_setAPWMPeriod (ECAP_TypeDef *ecap, uint32_t periodCount)
{
    WRITE_REG(ecap->CAP1.WORDVAL, periodCount);
}

/**
 * \brief  Set eCAP APWM on or off time count.
 * \note   This function sets the on or off time count of the APWM waveform depending
 *         on the polarity of the output.
 * \param  ecap            ecap pointer to a ECAP_TypeDef structure
 *                          - ECAP1: ECAP1 base address index
 *                          - ECAP2: ECAP2 base address index
 *                          - ECAP3: ECAP3 base address index
 *                          - ECAP4: ECAP4 base address index
 *                          - ECAP5: ECAP5 base address index
 *                          - ECAP6: ECAP6 base address index
 *                          - ECAP7: ECAP7 base address index
 * \param  compareCount    compareCount is the on or off count for APWM.
 *                          This parameter can be a value between 0x0000 and 0xFFFF.
 */
static inline void ECAP_setAPWMCompare (ECAP_TypeDef *ecap, uint32_t compareCount)
{
    WRITE_REG(ecap->CAP2.WORDVAL, compareCount);
}

/**
 * \brief  Load eCAP APWM shadow period.
 * \note   This function sets the shadow period count of the APWM waveform.
 * \param  ecap           ecap pointer to a ECAP_TypeDef structure
 *                         - ECAP1: ECAP1 base address index
 *                         - ECAP2: ECAP2 base address index
 *                         - ECAP3: ECAP3 base address index
 *                         - ECAP4: ECAP4 base address index
 *                         - ECAP5: ECAP5 base address index
 *                         - ECAP6: ECAP6 base address index
 *                         - ECAP7: ECAP7 base address index
 * \param  periodCount    periodCount is the shadow period count for APWM.
 */
static inline void ECAP_setAPWMShadowPeriod (ECAP_TypeDef *ecap, uint32_t periodCount)
{
    WRITE_REG(ecap->CAP3.WORDVAL, periodCount);
}

/**
 * \brief  Set eCAP APWM shadow on or off time count.
 * \note   This function sets the shadow on or off time count of the APWM waveform
 *         depending on the polarity of the output.
 * \param  ecap            ecap pointer to a ECAP_TypeDef structure
 *                          - ECAP1: ECAP1 base address index
 *                          - ECAP2: ECAP2 base address index
 *                          - ECAP3: ECAP3 base address index
 *                          - ECAP4: ECAP4 base address index
 *                          - ECAP5: ECAP5 base address index
 *                          - ECAP6: ECAP6 base address index
 *                          - ECAP7: ECAP7 base address index
 * \param  compareCount    compareCount is the on or off count for APWM.
 *                          This parameter can be a value between 0x0000 and 0xFFFF.
 */
static inline void ECAP_setAPWMShadowCompare (ECAP_TypeDef *ecap, uint32_t compareCount)
{
    WRITE_REG(ecap->CAP4.WORDVAL, compareCount);
}

/**
 * \brief  Returns the time base counter.
 * \note   This function returns the time base counter value.
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 * \return  Returns the time base counter.
 */
static inline uint32_t ECAP_getTimeBaseCounter (ECAP_TypeDef *ecap)
{
    return READ_REG(ecap->TSCTR.WORDVAL);
}

/**
 * \brief  Returns the event time stamp.
 * \note   This function returns the current time stamp count of the given event.
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  event    event is the event number for ECAP input
 *                   This parameter can be one of the following @ref ECAP_Events:
 * \return  Returns the event time stamp.
 */
static inline uint32_t ECAP_getEventTimeStamp (ECAP_TypeDef *ecap, ECAP_Events event)
{
    return READ_REG(TYPE32(&(ecap->CAP1.WORDVAL) + event));
}

/**
 * \brief  Select eCAP input.
 * \note   This function selects the eCAP input signal.
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  input    input is the input capture signals for ECAP input
 *                   This parameter can be one of the following @ref ECAP_InputCaptureSignals.
 */
static inline void ECAP_selectECAPInput (ECAP_TypeDef *ecap, ECAP_InputCaptureSignals input)
{
    MODIFY_REG(ecap->ECCTL0.WORDVAL, ECAP_ECCTL0_INPUTSEL_M, (uint32_t)input);
}

/**
 * \brief  Select qualification period to filter out noise.
 * \note   This function selects the qualification period to filter out pulses with
 *         width less than the mentioned number of cycles.
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  width    width is the pulse width below which the pulse will be filtered out.
 *                   This parameter can be one of the following @ref ECAP_QualPeriodSelect.
 */
static inline void ECAP_selectQualPeriod (ECAP_TypeDef *ecap, ECAP_QualPeriodSelect width)
{
    MODIFY_REG(ecap->ECCTL0.WORDVAL, ECAP_ECCTL0_QUALORD_M, (uint32_t)width << ECAP_ECCTL0_QUALORD_S);
}

/**
 * \brief  Sets the eCAP SOC trigger source.
 * \note   This function sets the eCAP event source in capture mode and APWM mode
 *         for the SOC trigger trigger.
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  event    event is the event number for ECAP input
 *                   This parameter can be one of the following @ref ECAP_Events:
 *                    In capture mode of operation -
 *                    \b ECAP_EVENT_1 - SOC trigger interrupt source is CEVT1
 *                    \b ECAP_EVENT_2 - SOC trigger interrupt source is CEVT2
 *                    \b ECAP_EVENT_3 - SOC trigger interrupt source is CEVT3
 *                    \b ECAP_EVENT_4 - SOC trigger interrupt source is CEVT4
 * 
 *                    In APWM mode of operation -
 *                    \b ECAP_EVENT_1 - SOC trigger interrupt source is period match
 *                    \b ECAP_EVENT_2 - SOC trigger interrupt source is compare match
 *                    \b ECAP_EVENT_3 - SOC trigger interrupt source is period or compare match
 *                    \b ECAP_EVENT_4 - disabled
 */
static inline void ECAP_setSOCTriggerSource(ECAP_TypeDef *ecap, ECAP_Events event)
{
    MODIFY_REG(ecap->ECCTL0.WORDVAL, ECAP_ECCTL0_SOCEVTSEL_M, (uint32_t)event << ECAP_ECCTL0_SOCEVTSEL_S);
}

/**
 * \brief  Resets eCAP counters and flags.
 * \note   This function resets the main counter (TSCTR register), event filter,
 *         modulo counter, capture events and counter overflow flags
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 */
static inline void ECAP_resetCounters (ECAP_TypeDef *ecap)
{
    SET_BIT(ecap->ECCTL2.WORDVAL, ECAP_ECCTL2_CTRFILTRESET_M);
}

/**
 * \brief  Sets the eCAP DMA source.
 * \note   This function sets the eCAP event source for the DMA trigger.
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  event    event is the event number for ECAP input
 *                   This parameter can be one of the following @ref ECAP_Events:
 *                    In capture mode of operation -
 *                    \b ECAP_EVENT_1 - DMA interrupt source is CEVT1
 *                    \b ECAP_EVENT_2 - DMA interrupt source is CEVT2
 *                    \b ECAP_EVENT_3 - DMA interrupt source is CEVT3
 *                    \b ECAP_EVENT_4 - DMA interrupt source is CEVT4
 * 
 *                    In APWM mode of operation -
 *                    \b ECAP_EVENT_1 - DMA interrupt source is period match
 *                    \b ECAP_EVENT_2 - DMA interrupt source is compare match
 *                    \b ECAP_EVENT_3 - DMA interrupt source is period or compare match
 *                    \b ECAP_EVENT_4 - disabled
 */
static inline void ECAP_setDMASource (ECAP_TypeDef *ecap, ECAP_Events event)
{
    MODIFY_REG(ecap->ECCTL2.WORDVAL, ECAP_ECCTL2_DMAEVTSEL_M, (uint32_t)event << ECAP_ECCTL2_DMAEVTSEL_S);
}

/**
 * \brief  Returns the modulo counter status.
 * \note   This function returns the modulo counter status, indicating which register
 *         gets loaded on the next capture event.
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 * \return  Returns an \b ECAP_EVENT_n value indicating that CAPn is the 
 *          register to be loaded on the next event.
 */
static inline ECAP_Events ECAP_getModuloCounterStatus (ECAP_TypeDef *ecap)
{
    uint16_t counterStatusValue;

    counterStatusValue = (ecap->ECCTL2.WORDVAL & ECAP_ECCTL2_MODCNTRSTS_M) >> ECAP_ECCTL2_MODCNTRSTS_S;

    return ((ECAP_Events)(counterStatusValue));
}

/**
 * \brief  Enable eCAP monitoring unit.
 * \note   This function enables the eCAP signal monitoring unit.
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  munit    values that can be passed to ECAP Signal Monitoring
 */
static inline void ECAP_enableSignalMonitoringUnit (ECAP_TypeDef *ecap, ECAP_MonitorUnit munit)
{
    SET_BIT(ecap->MUNITXGRP[munit].MUNITXCTL.WORDVAL, ECAP_MUNITXCTL_EN_M);
}

/**
 * \brief  Disable eCAP monitoring unit.
 * \note   This function disables the eCAP signal monitoring unit.
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  munit    values that can be passed to ECAP Signal Monitoring
 */
static inline void ECAP_disableSignalMonitoringUnit (ECAP_TypeDef *ecap, ECAP_MonitorUnit munit)
{
    CLEAR_BIT(ecap->MUNITXGRP[munit].MUNITXCTL.WORDVAL, ECAP_MUNITXCTL_EN_M);
}

/**
 * \brief  Enables debug mode to capture range from min to max.
 * \note   This function enables the eCAP debug mode for signal monitoring.
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  munit    values that can be passed to ECAP Signal Monitoring
 */
static inline void ECAP_enableDebugRange (ECAP_TypeDef *ecap, ECAP_MonitorUnit munit)
{
    SET_BIT(ecap->MUNITXGRP[munit].MUNITXCTL.WORDVAL, ECAP_MUNITXCTL_DEBUGRANGEEN_M);
}

/**
 * \brief  Disables debug mode to capture range from min to max.
 * \note   This function disables the eCAP debug mode for signal monitoring.
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  munit    values that can be passed to ECAP Signal Monitoring
 */
static inline void ECAP_disableDebugRange (ECAP_TypeDef *ecap, ECAP_MonitorUnit munit)
{
    CLEAR_BIT(ecap->MUNITXGRP[munit].MUNITXCTL.WORDVAL, ECAP_MUNITXCTL_DEBUGRANGEEN_M);
}

/**
 * \brief  Setup the early max error check.
 * \note   This function sets the early max error check for signal monitoring.
 * \param  ecap          ecap pointer to a ECAP_TypeDef structure
 *                        - ECAP1: ECAP1 base address index
 *                        - ECAP2: ECAP2 base address index
 *                        - ECAP3: ECAP3 base address index
 *                        - ECAP4: ECAP4 base address index
 *                        - ECAP5: ECAP5 base address index
 *                        - ECAP6: ECAP6 base address index
 *                        - ECAP7: ECAP7 base address index
 * \param  munit         values that can be passed to ECAP Signal Monitoring
 * \param  errorCheck    the functionality for early max error check to be enabled.
 */
static inline void ECAP_setupEarlyMaxErrorCheck (ECAP_TypeDef *ecap, ECAP_MonitorUnit munit,
                                                 ECAP_MaxErrorCheck errorCheck)
{
    MODIFY_REG(ecap->MUNITXGRP[munit].MUNITXCTL.WORDVAL, ECAP_MUNITXCTL_DISABLEEARLYMAXERR_M,
               ((uint32_t)errorCheck << ECAP_MUNITXCTL_DISABLEEARLYMAXERR_S));
}

/**
 * \brief  Selects the type of monitoring.
 * \note   This function selects the type for signal monitoring.
 * \param  ecap      ecap pointer to a ECAP_TypeDef structure
 *                    - ECAP1: ECAP1 base address index
 *                    - ECAP2: ECAP2 base address index
 *                    - ECAP3: ECAP3 base address index
 *                    - ECAP4: ECAP4 base address index
 *                    - ECAP5: ECAP5 base address index
 *                    - ECAP6: ECAP6 base address index
 *                    - ECAP7: ECAP7 base address index
 * \param  munit     values that can be passed to ECAP Signal Monitoring
 * \param  monSel    the type of monitoring to be selected.
 */
static inline void ECAP_selectMonitoringType (ECAP_TypeDef *ecap, ECAP_MonitorUnit munit, ECAP_MonitoringTypeSelect monSel)
{
    MODIFY_REG(ecap->MUNITXGRP[munit].MUNITXCTL.WORDVAL, ECAP_MUNITXCTL_MONSEL_M,
               ((uint32_t)monSel << ECAP_MUNITXCTL_MONSEL_S));
}

/**
 * \brief  Selects the trip signal to disable and enable monitoring automatically.
 * \note   This function selects the trip signal to disable and enable for signal monitoring.
 * \param  ecap       ecap pointer to a ECAP_TypeDef structure
 *                     - ECAP1: ECAP1 base address index
 *                     - ECAP2: ECAP2 base address index
 *                     - ECAP3: ECAP3 base address index
 *                     - ECAP4: ECAP4 base address index
 *                     - ECAP5: ECAP5 base address index
 *                     - ECAP6: ECAP6 base address index
 *                     - ECAP7: ECAP7 base address index
 * \param  tripSel    the trip signal.
 */
static inline void ECAP_selectTripSignal (ECAP_TypeDef *ecap, ECAP_MunitTripInputSelect tripSel)
{
    MODIFY_REG(ecap->MUNITCOMMONCTL.WORDVAL, ECAP_MUNITCOMMONCTL_TRIPSEL_M,
               (uint32_t)tripSel << ECAP_MUNITCOMMONCTL_TRIPSEL_S);
}

/**
 * \brief  Selects the global load strobe to enable shadow to active loading.
 * \note   This function selects tglobal load strobe to enable shadow to active loading
 *         for signal monitoring.
 * \param  ecap      ecap pointer to a ECAP_TypeDef structure
 *                    - ECAP1: ECAP1 base address index
 *                    - ECAP2: ECAP2 base address index
 *                    - ECAP3: ECAP3 base address index
 *                    - ECAP4: ECAP4 base address index
 *                    - ECAP5: ECAP5 base address index
 *                    - ECAP6: ECAP6 base address index
 *                    - ECAP7: ECAP7 base address index
 * \param  strobe    the type of monitoring to be selected.
 */
static inline void ECAP_selectGlobalLoadStrobe (ECAP_TypeDef *ecap, ECAP_MunitTripInputSelect strobe)
{
    MODIFY_REG(ecap->MUNITCOMMONCTL.WORDVAL, ECAP_MUNITCOMMONCTL_GLDSTRBSEL_M,
               (uint32_t)strobe << ECAP_MUNITCOMMONCTL_GLDSTRBSEL_S);
}

/**
 * \brief  Enables shadowing for min and max registers.
 * \note   This function enables the shadowing feature for min and max registers.
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  munit    values that can be passed to ECAP Signal Monitoring
 */
static inline void ECAP_enableShadowMinMaxRegisters (ECAP_TypeDef *ecap, ECAP_MonitorUnit munit)
{
    SET_BIT(ecap->MUNITXGRP[munit].MUNITXSHADOWCTL.WORDVAL, ECAP_MUNITXSHADOWCTL_SYNCIEN_M);
}

/**
 * \brief  Disables shadowing for min and max registers.
 * \note   This function disables the shadowing feature for min and max registers.
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  munit    values that can be passed to ECAP Signal Monitoring
 */
static inline void ECAP_disableShadowMinMaxRegisters (ECAP_TypeDef *ecap, ECAP_MonitorUnit munit)
{
    CLEAR_BIT(ecap->MUNITXGRP[munit].MUNITXSHADOWCTL.WORDVAL, ECAP_MUNITXSHADOWCTL_SYNCIEN_M);
}

/**
 * \brief  Enables software sync operation.
 * \note   This function enables the SW Sync to copy min and max values from
 *         shadow to active registers immediately is shadowing is enabled.
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  munit    values that can be passed to ECAP Signal Monitoring
 */
static inline void ECAP_enableSoftwareSync (ECAP_TypeDef *ecap, ECAP_MonitorUnit munit)
{
    SET_BIT(ecap->MUNITXGRP[munit].MUNITXSHADOWCTL.WORDVAL, ECAP_MUNITXSHADOWCTL_SWSYNC_M);
}

/**
 * \brief  Selects the shadow to active load mode.
 * \note   This function selects the shadow to active load mode for signal monitoring.
 * \param  ecap        ecap pointer to a ECAP_TypeDef structure
 *                      - ECAP1: ECAP1 base address index
 *                      - ECAP2: ECAP2 base address index
 *                      - ECAP3: ECAP3 base address index
 *                      - ECAP4: ECAP4 base address index
 *                      - ECAP5: ECAP5 base address index
 *                      - ECAP6: ECAP6 base address index
 *                      - ECAP7: ECAP7 base address index
 * \param  munit       values that can be passed to ECAP Signal Monitoring
 * \param  loadMode    the shadow to active mode to be selected
 */
static inline void ECAP_selectShadowLoadMode (ECAP_TypeDef *ecap, ECAP_MonitorUnit munit, ECAP_ShadowLoadMode loadMode)
{
    MODIFY_REG(ecap->MUNITXGRP[munit].MUNITXSHADOWCTL.WORDVAL, ECAP_MUNITXSHADOWCTL_LOADMODE_M,
               (uint32_t)loadMode << ECAP_MUNITXSHADOWCTL_LOADMODE_S);
}

/**
 * \brief  Configure minimum value for monitoring.
 * \note   This function configure minimum value for signal monitoring.
 * \param  ecap        ecap pointer to a ECAP_TypeDef structure
 *                      - ECAP1: ECAP1 base address index
 *                      - ECAP2: ECAP2 base address index
 *                      - ECAP3: ECAP3 base address index
 *                      - ECAP4: ECAP4 base address index
 *                      - ECAP5: ECAP5 base address index
 *                      - ECAP6: ECAP6 base address index
 *                      - ECAP7: ECAP7 base address index
 * \param  munit       values that can be passed to ECAP Signal Monitoring
 * \param  minValue    the minimum value for monitoring.
 *                       Range from 0x0 to 0xFFFFFFFF
 */
static inline void ECAP_configureMinValue (ECAP_TypeDef *ecap, ECAP_MonitorUnit munit, uint32_t minValue)
{
    WRITE_REG(ecap->MUNITXGRP[munit].MUNITXMIN.WORDVAL, minValue);
}

/**
 * \brief  Configure maximum value for monitoring.
 * \note   This function configure maximum value for signal monitoring.
 * \param  ecap        ecap pointer to a ECAP_TypeDef structure
 *                      - ECAP1: ECAP1 base address index
 *                      - ECAP2: ECAP2 base address index
 *                      - ECAP3: ECAP3 base address index
 *                      - ECAP4: ECAP4 base address index
 *                      - ECAP5: ECAP5 base address index
 *                      - ECAP6: ECAP6 base address index
 *                      - ECAP7: ECAP7 base address index
 * \param  munit       values that can be passed to ECAP Signal Monitoring
 * \param  maxValue    the maximum value for monitoring.
 *                       Range from 0x0 to 0xFFFFFFFF
 */
static inline void ECAP_configureMaxValue (ECAP_TypeDef *ecap, ECAP_MonitorUnit munit, uint32_t maxValue)
{
    WRITE_REG(ecap->MUNITXGRP[munit].MUNITXMAX.WORDVAL, maxValue);
}

/**
 * \brief  Configure minimum value for shadow register.
 * \note   This function configure minimum value for signal monitoring.
 * \param  ecap        ecap pointer to a ECAP_TypeDef structure
 *                      - ECAP1: ECAP1 base address index
 *                      - ECAP2: ECAP2 base address index
 *                      - ECAP3: ECAP3 base address index
 *                      - ECAP4: ECAP4 base address index
 *                      - ECAP5: ECAP5 base address index
 *                      - ECAP6: ECAP6 base address index
 *                      - ECAP7: ECAP7 base address index
 * \param  munit       values that can be passed to ECAP Signal Monitoring
 * \param  minValue    the minimum value for monitoring.
 *                       Range from 0x0 to 0xFFFFFFFF
 */
static inline void ECAP_configureShadowMinValue (ECAP_TypeDef *ecap, ECAP_MonitorUnit munit, uint32_t minValue)
{
    WRITE_REG(ecap->MUNITXGRP[munit].MUNITXMINSHADOW.WORDVAL, minValue);
}

/**
 * \brief  Configure maximum value for shadow register.
 * \note   This function configure maximum value for signal monitoring.
 * \param  ecap        ecap pointer to a ECAP_TypeDef structure
 *                      - ECAP1: ECAP1 base address index
 *                      - ECAP2: ECAP2 base address index
 *                      - ECAP3: ECAP3 base address index
 *                      - ECAP4: ECAP4 base address index
 *                      - ECAP5: ECAP5 base address index
 *                      - ECAP6: ECAP6 base address index
 *                      - ECAP7: ECAP7 base address index
 * \param  munit       values that can be passed to ECAP Signal Monitoring
 * \param  maxValue    the maximum value for monitoring.
 *                       Range from 0x0 to 0xFFFFFFFF
 */
static inline void ECAP_configureShadowMaxValue (ECAP_TypeDef *ecap, ECAP_MonitorUnit munit, uint32_t maxValue)
{
    WRITE_REG(ecap->MUNITXGRP[munit].MUNITXMAXSHADOW.WORDVAL, maxValue);
}

/**
 * \brief  Returns observed minimum value.
 * \note   This function returns the observed minimum value when the DEBUG_RANGE_EN
 *         bit is set to 1.
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  munit    values that can be passed to ECAP Signal Monitoring
 * 
 * \return  Returns the observed minimum value.
 */
static inline uint32_t ECAP_observedMinValue (ECAP_TypeDef *ecap, ECAP_MonitorUnit munit)
{
    return (ecap->MUNITXGRP[munit].MUNITXDEBUGRANGEMIN.WORDVAL);
}

/**
 * \brief  Returns observed maximum value.
 * \note   This function returns the observed maximum value when the DEBUG_RANGE_EN
 *         bit is set to 1.
 * \param  ecap     ecap pointer to a ECAP_TypeDef structure
 *                   - ECAP1: ECAP1 base address index
 *                   - ECAP2: ECAP2 base address index
 *                   - ECAP3: ECAP3 base address index
 *                   - ECAP4: ECAP4 base address index
 *                   - ECAP5: ECAP5 base address index
 *                   - ECAP6: ECAP6 base address index
 *                   - ECAP7: ECAP7 base address index
 * \param  munit    values that can be passed to ECAP Signal Monitoring
 * 
 * \return  Returns the observed maximum value.
 */
static inline uint32_t ECAP_observedMaxValue (ECAP_TypeDef *ecap, ECAP_MonitorUnit munit)
{
    return (ecap->MUNITXGRP[munit].MUNITXDEBUGRANGEMAX.WORDVAL);
}

/**
 * \brief  Configure the Emulation mode of the ECAP
 * \note   This function configures the eCAP counter, TSCTR,  to the desired emulation
 *         mode when emulation suspension occurs.
 * \param  ecap    ecap pointer to a ECAP_TypeDef structure
 *                  - ECAP1: ECAP1 base address index
 *                  - ECAP2: ECAP2 base address index
 *                  - ECAP3: ECAP3 base address index
 *                  - ECAP4: ECAP4 base address index
 *                  - ECAP5: ECAP5 base address index
 *                  - ECAP6: ECAP6 base address index
 *                  - ECAP7: ECAP7 base address index
 * \param  mode    ECAP Emulation Mode
 *                 This parameter can be one of the following @ref ECAP_EmulationMode.
 */
extern void ECAP_setEmulationMode (ECAP_TypeDef *ecap, ECAP_EmulationMode mode);


#ifdef __cplusplus
}
#endif

#endif /* __ECAP_H__ */
