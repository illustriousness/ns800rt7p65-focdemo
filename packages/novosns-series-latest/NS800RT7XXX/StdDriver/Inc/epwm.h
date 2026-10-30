/**
  * @file       epwm.h
  * @author     Pearce
  * @brief      Header file for NS800RT7xxx epwm module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __EPWM_H__
#define __EPWM_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_epwm.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup EPWM_EXPORTED_TYPES EPWM Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'EPWM' module.
  */

/** @defgroup EPWM_EMULATIONMODE EPWM EmulationMode Mode Selection
  * @{
  * @brief  Macro definitions about EPWM emulationMode mode selection.
  */
typedef enum {
    EPWM_EMULATION_STOP_AFTER_NEXT_TB = 0U,    /*! Stop after next Time Base counter increment or decrement */
    EPWM_EMULATION_STOP_AFTER_FULL_CYCLE,      /*! Stop when counter completes whole cycle */
    EPWM_EMULATION_FREE_RUN                    /*! Free run */
} EPWM_EmulationMode;

/**
  * @}
  */

/** @defgroup EPWM_SYNCCOUNTMODE EPWM Sync Count Mode Selection
  * @{
  * @brief  Macro definitions about EPWM sync count mode selection.
  */
typedef enum {
    EPWM_COUNT_MODE_DOWN_AFTER_SYNC = 0U,    /*!< Count down after sync event */
    EPWM_COUNT_MODE_UP_AFTER_SYNC            /*!< Count up after sync event */
} EPWM_SyncCountMode;

/**
  * @}
  */

/** @defgroup EPWM_CLOCKDIVIDER EPWM Clock Divide
  * @{
  * @brief  Macro definitions about EPWM clock divide.
  */
typedef enum {
    EPWM_CLOCK_DIVIDER_1 = 0U,    /*!< Divide clock by 1 */
    EPWM_CLOCK_DIVIDER_2,         /*!< Divide clock by 2 */
    EPWM_CLOCK_DIVIDER_4,         /*!< Divide clock by 4 */
    EPWM_CLOCK_DIVIDER_8,         /*!< Divide clock by 8 */
    EPWM_CLOCK_DIVIDER_16,        /*!< Divide clock by 16 */
    EPWM_CLOCK_DIVIDER_32,        /*!< Divide clock by 32 */
    EPWM_CLOCK_DIVIDER_64,        /*!< Divide clock by 64 */
    EPWM_CLOCK_DIVIDER_128        /*!< Divide clock by 128 */
} EPWM_ClockDivider;

/**
  * @}
  */

/** @defgroup EPWM_HSCLOCKDIVIDER EPWM High Speed Clock Divide
  * @{
  * @brief  Macro definitions about EPWM high speed clock divide.
  */
typedef enum {
    EPWM_HSCLOCK_DIVIDER_1 = 0U,    /*!< Divide clock by 1 */
    EPWM_HSCLOCK_DIVIDER_2,         /*!< Divide clock by 2 */
    EPWM_HSCLOCK_DIVIDER_4,         /*!< Divide clock by 4 */
    EPWM_HSCLOCK_DIVIDER_6,         /*!< Divide clock by 6 */
    EPWM_HSCLOCK_DIVIDER_8,         /*!< Divide clock by 8 */
    EPWM_HSCLOCK_DIVIDER_10,        /*!< Divide clock by 10 */
    EPWM_HSCLOCK_DIVIDER_12,        /*!< Divide clock by 12 */
    EPWM_HSCLOCK_DIVIDER_14         /*!< Divide clock by 14 */
} EPWM_HSClockDivider;

/**
  * @}
  */

/** @defgroup EPWM_SYNCINPULSESOURCE EPWM Synchronous Input Signal Source Selection
  * @{
  * @brief  Macro definitions about EPWM synchronous input signal source selection.
  */
typedef enum {
    EPWM_SYNC_IN_PULSE_SRC_DISABLE = 0x0U,    /*!< Disable Sync-in */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM1,     /*!< Sync-in source is EPWM1 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM2,     /*!< Sync-in source is EPWM2 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM3,     /*!< Sync-in source is EPWM3 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM4,     /*!< Sync-in source is EPWM4 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM5,     /*!< Sync-in source is EPWM5 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM6,     /*!< Sync-in source is EPWM6 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM7,     /*!< Sync-in source is EPWM7 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM8,     /*!< Sync-in source is EPWM8 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM9,     /*!< Sync-in source is EPWM8 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM10,    /*!< Sync-in source is EPWM8 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM11,    /*!< Sync-in source is EPWM8 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM12,    /*!< Sync-in source is EPWM8 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM13,    /*!< Sync-in source is EPWM8 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM14,    /*!< Sync-in source is EPWM8 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM15,    /*!< Sync-in source is EPWM8 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM16,    /*!< Sync-in source is EPWM8 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP1,     /*!< Sync-in source is ECAP1 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP2,     /*!< Sync-in source is ECAP2 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP3,     /*!< Sync-in source is ECAP3 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP4,     /*!< Sync-in source is ECAP4 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP5,     /*!< Sync-in source is ECAP5 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP6,     /*!< Sync-in source is ECAP6 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP7,     /*!< Sync-in source is ECAP7 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT5,    /*!< Sync-in source is Input XBAR out5 signal */
    EPWM_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT6,    /*!< Sync-in source is Input XBAR out6 signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM17,    /*!< Sync-in source is EPWM8 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM18,    /*!< Sync-in source is EPWM8 sync-out signal */

} EPWM_SyncInPulseSource;

/**
  * @}
  */

/** @defgroup EPWM_ONESHOTSYNCOUTTRIGGER EPWM Trigger Source Of Single Trigger Synchronous Output
  * @{
  * @brief  Macro definitions about EPWM configure the trigger source for one-shot synchronous output.
  */
typedef enum {
    EPWM_OSHT_SYNC_OUT_TRIG_SYNC = 0x0U,    /*!< Trigger is OSHT sync */
    EPWM_OSHT_SYNC_OUT_TRIG_RELOAD          /*!< Trigger is OSHT reload */
} EPWM_OneShotSyncOutTrigger;

/**
  * @}
  */

/** @defgroup EPWM_PERIODLOADMODE EPWM Loading Mode of Periodic Register
  * @{
  * @brief  Macro definitions about EPWM periodic loading mode selection.
  */
typedef enum {
    EPWM_PERIOD_SHADOW_LOAD = 0U,    /*!< PWM Period register access is through shadow register */
    EPWM_PERIOD_DIRECT_LOAD          /*!< PWM Period register access is directly */
} EPWM_PeriodLoadMode;

/**
  * @}
  */

/** @defgroup EPWM_TIMEBASECOUNTMODE EPWM Time Base Count Mode
  * @{
  * @brief  Macro definitions about EPWM time base counter mode selection.
  */
typedef enum {
    EPWM_COUNTER_MODE_UP = 0U,       /*!< Up - count mode */
    EPWM_COUNTER_MODE_DOWN,          /*!< Down - count mode */
    EPWM_COUNTER_MODE_UP_DOWN,       /*!< Up - down - count mode */
    EPWM_COUNTER_MODE_STOP_FREEZE    /*!< Stop - Freeze counter */
} EPWM_TimeBaseCountMode;

/**
  * @}
  */

/** @defgroup EPWM_PERIODSHADOWLOADMODE EPWM Periodic Shadow Loading Mode
  * @{
  * @brief  Macro definitions about EPWM periodic shadow loading mode selection.
  */
typedef enum {
    EPWM_SHADOW_LOAD_MODE_COUNTER_ZERO = 0U,    /*!< Shadow to active load occurs when time base counter reaches 0 */
    EPWM_SHADOW_LOAD_MODE_COUNTER_SYNC,         /*!< Shadow to active load occurs when time base counter reaches 0 and a SYNC occurs */
    EPWM_SHADOW_LOAD_MODE_SYNC                  /*!< Shadow to active load occurs only when a SYNC occurs */
} EPWM_PeriodShadowLoadMode;

/**
  * @}
  */

/** @defgroup EPWM_CURRENTLINK EPWM Link Mode Between Current EPWM and Other EPWM Modules
  * @{
  * @brief  Macro definitions about EPWM Configure the link mode between the current ePWM and other ePWM modules.
  */
typedef enum {
    EPWM_LINK_WITH_EPWM_1 = 0U,    /*!< link current ePWM with ePWM1 */
    EPWM_LINK_WITH_EPWM_2,         /*!< link current ePWM with ePWM2 */
    EPWM_LINK_WITH_EPWM_3,         /*!< link current ePWM with ePWM3 */
    EPWM_LINK_WITH_EPWM_4,         /*!< link current ePWM with ePWM4 */
    EPWM_LINK_WITH_EPWM_5,         /*!< link current ePWM with ePWM5 */
    EPWM_LINK_WITH_EPWM_6,         /*!< link current ePWM with ePWM6 */
    EPWM_LINK_WITH_EPWM_7,         /*!< link current ePWM with ePWM7 */
    EPWM_LINK_WITH_EPWM_8,         /*!< link current ePWM with ePWM8 */
    EPWM_LINK_WITH_EPWM_9,         /*!< link current ePWM with ePWM9 */
    EPWM_LINK_WITH_EPWM_10,        /*!< link current ePWM with ePWM10 */
    EPWM_LINK_WITH_EPWM_11,        /*!< link current ePWM with ePWM11 */
    EPWM_LINK_WITH_EPWM_12,        /*!< link current ePWM with ePWM12 */
    EPWM_LINK_WITH_EPWM_13,        /*!< link current ePWM with ePWM13 */
    EPWM_LINK_WITH_EPWM_14,        /*!< link current ePWM with ePWM14 */
    EPWM_LINK_WITH_EPWM_15,        /*!< link current ePWM with ePWM15 */
    EPWM_LINK_WITH_EPWM_16,        /*!< link current ePWM with ePWM16 */
    EPWM_LINK_WITH_EPWM_17,        /*!< link current ePWM with ePWM17 */
    EPWM_LINK_WITH_EPWM_18         /*!< link current ePWM with ePWM18 */
} EPWM_CurrentLink;

/**
  * @}
  */

/** @defgroup EPWM_LINKCOMPONENT EPWM Link Component
  * @{
  * @brief  Macro definitions about EPWM link component selection.
  */
typedef enum {
    EPWM_LINK_TBPRD   = 0U,            /*!< Link TBPRD:TBPRDHR registers */
    EPWM_LINK_COMP_A  = 5U,            /*!< Link COMPA registers */
    EPWM_LINK_COMP_B  = 10U,           /*!< Link COMPB registers */
    EPWM_LINK_COMP_C  = 16U,           /*!< Link COMPC registers */
    EPWM_LINK_COMP_D  = 21U,           /*!< Link COMPD registers */
    EPWM_LINK_GLDCTL2 = 26U,           /*!< Link GLDCTL2 registers */
    EPWM_LINK_DBRED = 0U + 0x0800U,    /*!< link DBRED registers */
    EPWM_LINK_DBFED = 5U + 0x0800U,    /*!< link DBFED registers */
    EPWM_LINK_TBPRDHR = 10U + 0x0800U, /*!< link DBFED registers */
    EPWM_LINK_XLOAD = 0U + 0x35800U    /*!< link XLOAD registers */
} EPWM_LinkComponent;

/**
  * @}
  */

/** @defgroup EPWM_COUNTERCOMPAREMODULE EPWM Counter Compare Module
  * @{
  * @brief  Macro definitions about EPWM counter compare module selection.
  */
typedef enum {
    EPWM_COUNTER_COMPARE_A = 0U,     /*!< Counter compare A */
    EPWM_COUNTER_COMPARE_B = 2U,     /*!< Counter compare B */
    EPWM_COUNTER_COMPARE_C = 5U,     /*!< Counter compare C */
    EPWM_COUNTER_COMPARE_D = 7U      /*!< Counter compare D */
} EPWM_CounterCompareModule;

/**
  * @}
  */

/** @defgroup EPWM_COUNTERCOMPARELOADMODE EPWM Counter Compare Load Mode
  * @{
  * @brief  Macro definitions about EPWM counter compare load mode selection.
  */
typedef enum {
    EPWM_COMP_LOAD_ON_CNTR_ZERO = 0U,           /*!< Load when counter equals zero */
    EPWM_COMP_LOAD_ON_CNTR_PERIOD,              /*!< Load when counter equals period */
    EPWM_COMP_LOAD_ON_CNTR_ZERO_PERIOD,         /*!< Load when counter equals zero or period */
    EPWM_COMP_LOAD_FREEZE,                      /*!< Freeze shadow to active load */
    EPWM_COMP_LOAD_ON_SYNC_CNTR_ZERO,           /*!< Load on sync or when counter equals zero */
    EPWM_COMP_LOAD_ON_SYNC_CNTR_PERIOD,         /*!< Load on sync or when counter equals period */
    EPWM_COMP_LOAD_ON_SYNC_CNTR_ZERO_PERIOD,    /*!< Load on sync or when counter equals zero or period */
    EPWM_COMP_LOAD_ON_SYNC_ONLY = 8U            /*!< Load on sync only */
} EPWM_CounterCompareLoadMode;

/**
  * @}
  */

/** @defgroup EPWM_ACTIONQUALIFIERMODULE EPWM Action Qualifier Module
  * @{
  * @brief  Macro definitions about EPWM action qualifier module selection.
  */
typedef enum {
    EPWM_ACTION_QUALIFIER_A = 0U,    /*!< Action Qualifier A */
    EPWM_ACTION_QUALIFIER_B,         /*!< Action Qualifier B */
} EPWM_ActionQualifierModule;

/**
  * @}
  */

/** @defgroup EPWM_SYNCOUTENABLEREGISTER EPWM Sync Out Enable Register
  * @{
  * @brief  Macro definitions about EPWM Sync Out Enable Register selection.
  */
typedef enum {
    EPWM_SYNC_OUT_ENABLE_REG = 0U,
    EPWM_SYNC_OUT_ENABLE_REG2,
} EPWM_SyncOutEnableRegister;

/**
  * @}
  */

/** @defgroup EPWM_ACTIONQUALIFIERLOADMODE EPWM Action Qualifier Load Mode
  * @{
  * @brief  Macro definitions about EPWM action qualifier load mode selection.
  */
typedef enum {
    EPWM_AQ_LOAD_ON_CNTR_ZERO = 0U,           /*!< Load when counter equals zero */
    EPWM_AQ_LOAD_ON_CNTR_PERIOD,              /*!< Load when counter equals period */
    EPWM_AQ_LOAD_ON_CNTR_ZERO_PERIOD,         /*!< Load when counter equals zero or period */
    EPWM_AQ_LOAD_FREEZE,                      /*!< Freeze shadow to active load */
    EPWM_AQ_LOAD_ON_SYNC_CNTR_ZERO,           /*!< Load on sync or when counter equals zero */
    EPWM_AQ_LOAD_ON_SYNC_CNTR_PERIOD,         /*!< Load on sync or when counter equals period */
    EPWM_AQ_LOAD_ON_SYNC_CNTR_ZERO_PERIOD,    /*!< Load on sync or when counter equals zero or period */
    EPWM_AQ_LOAD_ON_SYNC_ONLY = 8U            /*!< Load on sync only */
} EPWM_ActionQualifierLoadMode;

/**
  * @}
  */

/** @defgroup EPWM_ACTIONQUALIFIERTRIGGERSOURCE EPWM Action Qualifier Trigger Source
  * @{
  * @brief  Macro definitions about EPWM action qualifier trigger source selection.
  */
typedef enum {
    EPWM_AQ_TRIGGER_EVENT_TRIG_DCA_1 = 0U,     /*!< Digital compare event A 1 */
    EPWM_AQ_TRIGGER_EVENT_TRIG_DCA_2,          /*!< Digital compare event A 2 */
    EPWM_AQ_TRIGGER_EVENT_TRIG_DCB_1,          /*!< Digital compare event B 1 */
    EPWM_AQ_TRIGGER_EVENT_TRIG_DCB_2,          /*!< Digital compare event B 2 */
    EPWM_AQ_TRIGGER_EVENT_TRIG_TZ_1,           /*!< Trip zone 1 */
    EPWM_AQ_TRIGGER_EVENT_TRIG_TZ_2,           /*!< Trip zone 2 */
    EPWM_AQ_TRIGGER_EVENT_TRIG_TZ_3,           /*!< Trip zone 3 */
    EPWM_AQ_TRIGGER_EVENT_TRIG_EPWM_SYNCIN,    /*!< ePWM sync */
    EPWM_AQ_TRIGGER_EVENT_TRIG_DC_EVTFILT      /*!< Digital compare filter event */
} EPWM_ActionQualifierTriggerSource;

/**
  * @}
  */

/** @defgroup EPWM_ACTIONQUALIFIEROUTPUTMODULE EPWM Action Qualifier Output Module
  * @{
  * @brief  Macro definitions about EPWM action qualifier output module selection.
  */
typedef enum {
    EPWM_AQ_OUTPUT_A = 0U,    /*!< ePWMxA output */
    EPWM_AQ_OUTPUT_B = 2U,    /*!< ePWMxB output */
} EPWM_ActionQualifierOutputModule;

/**
  * @}
  */

/** @defgroup EPWM_ACTIONQUALIFIEROUTPUT EPWM Action Qualifier Output
  * @{
  * @brief  Macro definitions about EPWM action qualifier output selection.
  */
typedef enum {
    EPWM_AQ_OUTPUT_NO_CHANGE = 0U,    /*!< No change in the output pins */
    EPWM_AQ_OUTPUT_LOW,               /*!< Set output pins to low */
    EPWM_AQ_OUTPUT_HIGH,              /*!< Set output pins to High */
    EPWM_AQ_OUTPUT_TOGGLE             /*!< Toggle the output pins */
} EPWM_ActionQualifierOutput;

/**
  * @}
  */

/** @defgroup EPWM_ACTIONQUALIFIEROUTPUTEVENT EPWM Action Qualifier Output Event
  * @{
  * @brief  Macro definitions about EPWM action qualifier output event selection.
  */
typedef enum {
    EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO      = 0U,     /*!< Time base counter equals zero */
    EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD    = 2U,     /*!< Time base counter equals period */
    EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA   = 4U,     /*!< Time base counter up equals COMPA */
    EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA = 6U,     /*!< Time base counter down equals COMPA */
    EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB   = 8U,     /*!< Time base counter up equals COMPB */
    EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB = 10U,    /*!< Time base counter down equals COMPB */
    EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPC   = 12U,    /*!< Time base counter up equals COMPC */
    EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPC = 14U,    /*!< Time base counter down equals COMPC */
    EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPD   = 16U,    /*!< Time base counter up equals COMPD */
    EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPD = 18U,    /*!< Time base counter down equals COMPD */
    EPWM_AQ_OUTPUT_ON_T1_COUNT_UP        = 1U,     /*!< T1 event on count up */
    EPWM_AQ_OUTPUT_ON_T1_COUNT_DOWN      = 3U,     /*!< T1 event on count down */
    EPWM_AQ_OUTPUT_ON_T2_COUNT_UP        = 5U,     /*!< T2 event on count up */
    EPWM_AQ_OUTPUT_ON_T2_COUNT_DOWN      = 7U      /*!< T2 event on count down */
} EPWM_ActionQualifierOutputEvent;

/**
  * @}
  */

/** @defgroup EPWM_ACTIONQUALIFIERCONTFORCE EPWM Action Qualifier Continuous Forced Mode
  * @{
  * @brief  Macro definitions about EPWM action qualifier continuous forced mode selection.
  */
typedef enum {
    EPWM_AQ_SW_SH_LOAD_ON_CNTR_ZERO = 0U,      /*!< Shadow mode load when counter equals zero */
    EPWM_AQ_SW_SH_LOAD_ON_CNTR_PERIOD,         /*!< Shadow mode load when counter equals period */
    EPWM_AQ_SW_SH_LOAD_ON_CNTR_ZERO_PERIOD,    /*!< Shadow mode load when counter equals zero or period */
    EPWM_AQ_SW_IMMEDIATE_LOAD                  /*!< No shadow load mode. Immediate mode only. */
} EPWM_ActionQualifierContForce;

/**
  * @}
  */

/** @defgroup EPWM_ACTIONQUALIFIERSWOUTPUT EPWM Action Qualifier Software Forced Output Mode
  * @{
  * @brief  Macro definitions about EPWM action qualifier software forced output mode selection.
  */
typedef enum {
    EPWM_AQ_SW_DISABLED = 0U,    /*!< Software forcing disabled */
    EPWM_AQ_SW_OUTPUT_LOW,       /*!< Set output pins to low */
    EPWM_AQ_SW_OUTPUT_HIGH       /*!< Set output pins to High */
} EPWM_ActionQualifierSWOutput;

/**
  * @}
  */

/** @defgroup EPWM_DEADBANDOUTPUT EPWM Dead Band Output Source
  * @{
  * @brief  Macro definitions about EPWM dead band output source selection.
  */
typedef enum {
    EPWM_DB_OUTPUT_A = 1U,    /*!< DB output is ePWMA */
    EPWM_DB_OUTPUT_B = 0U     /*!< DB output is ePWMB */
} EPWM_DeadBandOutput;

/**
  * @}
  */

/** @defgroup EPWM_DEADBANDDELAYMODE EPWM Dead Band Delay Mode
  * @{
  * @brief  Macro definitions about EPWM dead band delay mode selection.
  */
typedef enum {
    EPWM_DB_RED = 1U,    /*!< DB RED (Rising Edge Delay) mode */
    EPWM_DB_FED = 0U     /*!< DB FED (Falling Edge Delay) mode */
} EPWM_DeadBandDelayMode;

/**
  * @}
  */

/** @defgroup EPWM_DEADBANDPOLARITY EPWM Dead Band Polarity
  * @{
  * @brief  Macro definitions about EPWM dead band polarity selection.
  */
typedef enum {
    EPWM_DB_POLARITY_ACTIVE_HIGH = 0U,    /*!< DB polarity is not inverted */
    EPWM_DB_POLARITY_ACTIVE_LOW  = 1U     /*!< DB polarity is inverted */
} EPWM_DeadBandPolarity;

/**
  * @}
  */

/** @defgroup EPWM_DEADBANDCONTROLLOADMODE EPWM Dead Band Control Load Mode
  * @{
  * @brief  Macro definitions about EPWM dead band control load mode selection.
  */
typedef enum {
    EPWM_DB_LOAD_ON_CNTR_ZERO = 0U,      /*!< Load when counter equals zero */
    EPWM_DB_LOAD_ON_CNTR_PERIOD,         /*!< Load when counter equals period */
    EPWM_DB_LOAD_ON_CNTR_ZERO_PERIOD,    /*!< Load when counter equals zero or period */
    EPWM_DB_LOAD_FREEZE                  /*!< Freeze shadow to active load */
} EPWM_DeadBandControlLoadMode;

/**
  * @}
  */

/** @defgroup EPWM_RISINGEDGEDELAYLOADMODE EPWM Rising Edge Delay Load Mode
  * @{
  * @brief  Macro definitions about EPWM rising edge delay load mode selection.
  */
typedef enum {
    EPWM_RED_LOAD_ON_CNTR_ZERO = 0U,      /*!< Load when counter equals zero */
    EPWM_RED_LOAD_ON_CNTR_PERIOD,         /*!< Load when counter equals period */
    EPWM_RED_LOAD_ON_CNTR_ZERO_PERIOD,    /*!< Load when counter equals zero or period */
    EPWM_RED_LOAD_FREEZE                  /*!< Freeze shadow to active load */
} EPWM_RisingEdgeDelayLoadMode;

/**
  * @}
  */

/** @defgroup EPWM_FALLINGEDGEDELAYLOADMODE EPWM Falling Edge Delay Load Mode
  * @{
  * @brief  Macro definitions about EPWM falling edge delay load mode selection.
  */
typedef enum {
    EPWM_FED_LOAD_ON_CNTR_ZERO = 0U,      /*!< Load when counter equals zero */
    EPWM_FED_LOAD_ON_CNTR_PERIOD,         /*!< Load when counter equals period */
    EPWM_FED_LOAD_ON_CNTR_ZERO_PERIOD,    /*!< Load when counter equals zero or period */
    EPWM_FED_LOAD_FREEZE                  /*!< Freeze shadow to active load */
} EPWM_FallingEdgeDelayLoadMode;

/**
  * @}
  */

/** @defgroup EPWM_DEADBANDCLOCKMODE EPWM Dead Band Counter Clock Mode
  * @{
  * @brief  Macro definitions about EPWM dead band counter clock mode selection.
  */
// typedef enum {
//     EPWM_DB_COUNTER_CLOCK_FULL_CYCLE = 0U,    /*!< Dead band counter runs at TBCLK rate */
//     EPWM_DB_COUNTER_CLOCK_HALF_CYCLE          /*!< Dead band counter runs at 2*TBCLK rate */
// } EPWM_DeadBandClockMode;

/**
  * @}
  */

/** @defgroup EPWM_TRIPZONEDIGITALCOMPAREOUTPUT EPWM Trip Zone Digital Compare Output
  * @{
  * @brief  Macro definitions about EPWM trip zone digital compare output selection.
  */
typedef enum {
    EPWM_TZ_DC_OUTPUT_A1 = 0U,    /*!< Digital Compare output 1 A */
    EPWM_TZ_DC_OUTPUT_A2 = 3U,    /*!< Digital Compare output 2 A */
    EPWM_TZ_DC_OUTPUT_B1 = 6U,    /*!< Digital Compare output 1 B */
    EPWM_TZ_DC_OUTPUT_B2 = 9U     /*!< Digital Compare output 2 B */
} EPWM_TripZoneDigitalCompareOutput;

/**
  * @}
  */

/** @defgroup EPWM_TRIPZONEDIGITALCOMPAREOUTPUTEVENT EPWM Trip Zone Digital Compare Output Event
  * @{
  * @brief  Macro definitions about EPWM trip zone digital compare output event selection.
  */
typedef enum {
    EPWM_TZ_EVENT_DC_DISABLED = 0U,     /*!< Event is disabled */
    EPWM_TZ_EVENT_DCXH_LOW,             /*!< Event when DCxH low */
    EPWM_TZ_EVENT_DCXH_HIGH,            /*!< Event when DCxH high */
    EPWM_TZ_EVENT_DCXL_LOW,             /*!< Event when DCxL low */
    EPWM_TZ_EVENT_DCXL_HIGH,            /*!< Event when DCxL high */
    EPWM_TZ_EVENT_DCXL_HIGH_DCXH_LOW    /*!< Event when DCxL high DCxH low */
} EPWM_TripZoneDigitalCompareOutputEvent;

/**
  * @}
  */

/** @defgroup EPWM_TRIPZONEEVENT EPWM Trip Zone Event
  * @{
  * @brief   Macro definitions about EPWM trip zone event selection.
  */
typedef enum {
    EPWM_TZ_ACTION_EVENT_TZA     = 0U,    /*!< TZ1 - TZ6, DCAEVT2, DCAEVT1 */
    EPWM_TZ_ACTION_EVENT_TZB     = 2U,    /*!< TZ1 - TZ6, DCBEVT2, DCBEVT1 */
    EPWM_TZ_ACTION_EVENT_DCAEVT1 = 4U,    /*!< DCAEVT1 (Digital Compare A event 1) */
    EPWM_TZ_ACTION_EVENT_DCAEVT2 = 6U,    /*!< DCAEVT2 (Digital Compare A event 2) */
    EPWM_TZ_ACTION_EVENT_DCBEVT1 = 8U,    /*!< DCBEVT1 (Digital Compare B event 1) */
    EPWM_TZ_ACTION_EVENT_DCBEVT2 = 10U    /*!< DCBEVT2 (Digital Compare B event 2) */
} EPWM_TripZoneEvent;

/**
  * @}
  */

/** @defgroup EPWM_TRIPZONEACTION EPWM Trip Zone Action
  * @{
  * @brief  Macro definitions about EPWM trip zone action selection.
  */
typedef enum {
    EPWM_TZ_ACTION_HIGH_Z = 0U,    /*!< High impedance output */
    EPWM_TZ_ACTION_HIGH,           /*!< High voltage state */
    EPWM_TZ_ACTION_LOW,            /*!< Low voltage state */
    EPWM_TZ_ACTION_DISABLE         /*!< Disable action */
} EPWM_TripZoneAction;

/**
  * @}
  */

/** @defgroup EPWM_TRIPZONEADVANCEDEVENT EPWM Trip Zone Advanced Event
  * @{
  * @brief  Macro definitions about EPWM trip zone advanced event selection.
  */
typedef enum {
    EPWM_TZ_ADV_ACTION_EVENT_TZB_D = 9U,    /*!< TZ1 - TZ6, DCBEVT2, DCBEVT1 while counting down */
    EPWM_TZ_ADV_ACTION_EVENT_TZB_U = 6U,    /*!< TZ1 - TZ6, DCBEVT2, DCBEVT1 while counting up */
    EPWM_TZ_ADV_ACTION_EVENT_TZA_D = 3U,    /*!< TZ1 - TZ6, DCAEVT2, DCAEVT1 while counting down */
    EPWM_TZ_ADV_ACTION_EVENT_TZA_U = 0U     /*!< TZ1 - TZ6, DCAEVT2, DCAEVT1 while counting up */
} EPWM_TripZoneAdvancedEvent;

/**
  * @}
  */

/** @defgroup EPWM_TRIPZONEADVANCEDACTION EPWM Trip Zone Advanced Action
  * @{
  * @brief  Macro definitions about EPWM trip zone advanced action selection.
  */
typedef enum {
    EPWM_TZ_ADV_ACTION_HIGH_Z = 0U,     /*!< High impedance output */
    EPWM_TZ_ADV_ACTION_HIGH,            /*!< High voltage state */
    EPWM_TZ_ADV_ACTION_LOW,             /*!< Low voltage state */
    EPWM_TZ_ADV_ACTION_TOGGLE,          /*!< Toggle the output */
    EPWM_TZ_ADV_ACTION_DISABLE = 7U     /*!< Disable action */
} EPWM_TripZoneAdvancedAction;

/**
  * @}
  */

/** @defgroup EPWM_TRIPZONEADVDIGITALCOMPAREEVENT EPWM Trip Zone Advanced Digital Compare Event
  * @{
  * @brief  Macro definitions about EPWM trip zone advanced digital compare event selection.
  */
typedef enum {
    EPWM_TZ_ADV_ACTION_EVENT_DCxEVT1_U = 0U,    /*!< Digital Compare event A/B 1 while counting up  */
    EPWM_TZ_ADV_ACTION_EVENT_DCxEVT1_D = 3U,    /*!< Digital Compare event A/B 1 while counting down */
    EPWM_TZ_ADV_ACTION_EVENT_DCxEVT2_U = 6U,    /*!< Digital Compare event A/B 2 while counting up */
    EPWM_TZ_ADV_ACTION_EVENT_DCxEVT2_D = 9U     /*!< Digital Compare event A/B 2 while counting down */
} EPWM_TripZoneAdvDigitalCompareEvent;

/**
  * @}
  */

/** @defgroup EPWM_CYCLEBYCYCLETRIPZONECLEARMODE EPWM Cycle By Cycle Trip Zone Clear Mode
  * @{
  * @brief  Macro definitions about EPWM cycle by cycle trip zone clear mode selection.
  */
typedef enum {
    EPWM_TZ_CBC_PULSE_CLR_CNTR_ZERO = 0U,     /*!< Clear CBC pulse when counter equals zero  */
    EPWM_TZ_CBC_PULSE_CLR_CNTR_PERIOD,        /*!< Clear CBC pulse when counter equals period */
    EPWM_TZ_CBC_PULSE_CLR_CNTR_ZERO_PERIOD    /*!< Clear CBC pulse when counter equals zero or period */
} EPWM_CycleByCycleTripZoneClearMode;

/**
  * @}
  */

/** @defgroup EPWM_ADCSTARTOFCONVERSIONTYPE EPWM ADC Start Of Conversion Type
  * @{
  * @brief  Macro definitions about EPWM ADC start of conversion type selection.
  */
typedef enum {
    EPWM_SOC_A = 0U,    /*!< SOC A */
    EPWM_SOC_B          /*!< SOC B */
} EPWM_ADCStartOfConversionType;

/**
  * @}
  */

/** @defgroup EPWM_ADCSTARTOFCONVERSIONSOURCE EPWM ADC Start of Conversion Trigger Source
  * @{
  * @brief  Macro definitions about EPWM ADC start of conversion trigger source.
  */
typedef enum {
    EPWM_SOC_DCxEVT1 = 0U,          /*!< Event is based on DCxEVT1 */
    EPWM_SOC_TBCTR_ZERO,            /*!< Time-base counter equal to zero */
    EPWM_SOC_TBCTR_PERIOD,          /*!< Time-base counter equal to period */
    EPWM_SOC_TBCTR_ETSOCMIX,        /*!< Time-base counter based on mixed events */
    EPWM_SOC_TBCTR_U_CMPA,          /*!< Time-base counter equal to CMPA when the timer is incrementing */
    EPWM_SOC_TBCTR_U_CMPC = 8U,     /*!< Time-base counter equal to CMPC when the timer is incrementing */
    EPWM_SOC_TBCTR_D_CMPA = 5U,     /*!< Time-base counter equal to CMPA when the timer is decrementing */
    EPWM_SOC_TBCTR_D_CMPC = 10U,    /*!< Time-base counter equal to CMPC when the timer is decrementing */
    EPWM_SOC_TBCTR_U_CMPB = 6U,     /*!< Time-base counter equal to CMPB when the timer is incrementing */
    EPWM_SOC_TBCTR_U_CMPD = 12U,    /*!< Time-base counter equal to CMPD when the timer is incrementing */
    EPWM_SOC_TBCTR_D_CMPB = 7U,     /*!< Time-base counter equal to CMPB when the timer is decrementing */
    EPWM_SOC_TBCTR_D_CMPD = 14U     /*!< Time-base counter equal to CMPD when the timer is decrementing */
} EPWM_ADCStartOfConversionSource;

/**
  * @}
  */

/** @defgroup EPWM_DIGITALCOMPARETRIPINPUT EPWM Digital Compare Trip Input
  * @{
  * @brief  Macro definitions about EPWM digital compare trip input.
  */
typedef enum {
    EPWM_DC_TRIP_TRIPIN1 = 0U,        /*!< Trip 1 */
    EPWM_DC_TRIP_TRIPIN2,             /*!< Trip 2 */
    EPWM_DC_TRIP_TRIPIN3,             /*!< Trip 3 */
    EPWM_DC_TRIP_TRIPIN4,             /*!< Trip 4 */
    EPWM_DC_TRIP_TRIPIN5,             /*!< Trip 5 */
    EPWM_DC_TRIP_TRIPIN6,             /*!< Trip 6 */
    EPWM_DC_TRIP_TRIPIN7,             /*!< Trip 7 */
    EPWM_DC_TRIP_TRIPIN8,             /*!< Trip 8 */
    EPWM_DC_TRIP_TRIPIN9,             /*!< Trip 9 */
    EPWM_DC_TRIP_TRIPIN10,            /*!< Trip 10 */
    EPWM_DC_TRIP_TRIPIN11,            /*!< Trip 11 */
    EPWM_DC_TRIP_TRIPIN12,            /*!< Trip 12 */
    EPWM_DC_TRIP_TRIPIN14 = 13U,      /*!< Trip 14 */
    EPWM_DC_TRIP_TRIPIN15 = 14U,      /*!< Trip 15 */
    EPWM_DC_TRIP_COMBINATION = 15U    /*!< All Trips (Trip1 - Trip 15) are selected */
} EPWM_DigitalCompareTripInput;

/**
  * @}
  */

/** @defgroup EPWM_DIGITALCOMPARETYPE EPWM Digital Compare Type
  * @{
  * @brief  Macro definitions about EPWM Digital Compare Type.
  */
typedef enum {
    EPWM_DC_TYPE_DCAH = 0U,    /*!< Digital Compare A High */
    EPWM_DC_TYPE_DCAL,         /*!< Digital Compare A Low */
    EPWM_DC_TYPE_DCBH,         /*!< Digital Compare B High */
    EPWM_DC_TYPE_DCBL          /*!< Digital Compare B Low */
} EPWM_DigitalCompareType;

/**
  * @}
  */

/** @defgroup EPWM_DIGITALCOMPAREBLANKINGPULSE EPWM Digital Compare starting Conditions Of Blanking Pulse Window
  * @{
  * @brief  Macro definitions about EPWM digital compare configure the starting condition of blanking pulse window.
  */
typedef enum {
    EPWM_DC_WINDOW_START_TBCTR_PERIOD = 0U,    /*!< Time base counter equals period */
    EPWM_DC_WINDOW_START_TBCTR_ZERO,           /*!< Time base counter equals zero */
    EPWM_DC_WINDOW_START_TBCTR_ZERO_PERIOD     /*!< Time base counter equals zero or period */
} EPWM_DigitalCompareBlankingPulse;

/**
  * @}
  */

/** @defgroup EPWM_DIGITALCOMPAREFILTERINPUT EPWM Input Signal Source Of Digital Comparison Filter
  * @{
  * @brief  Macro definitions about EPWM input signal source of digital comparison filter selection.
  */
typedef enum {
    EPWM_DC_WINDOW_SOURCE_DCAEVT1 = 0U,    /*!< DC filter signal source is DCAEVT1 */
    EPWM_DC_WINDOW_SOURCE_DCAEVT2,         /*!< DC filter signal source is DCAEVT2 */
    EPWM_DC_WINDOW_SOURCE_DCBEVT1,         /*!< DC filter signal source is DCBEVT1 */
    EPWM_DC_WINDOW_SOURCE_DCBEVT2          /*!< DC filter signal source is DCBEVT2 */
} EPWM_DigitalCompareFilterInput;

/**
  * @}
  */

/** @defgroup EPWM_DIGITALCOMPAREMODULE EPWM Digital Compare Module
  * @{
  * @brief  Macro definitions about EPWM digital compare module selection.
  */
typedef enum {
    EPWM_DC_MODULE_A = 0U,    /*!< Digital Compare Module A */
    EPWM_DC_MODULE_B          /*!< Digital Compare Module B */
} EPWM_DigitalCompareModule;

/**
  * @}
  */

/** @defgroup EPWM_DIGITALCOMPAREEVENT EPWM Digital Compare Event
  * @{
  * @brief  Macro definitions about EPWM digital compare event selection.
  */
typedef enum {
    EPWM_DC_EVENT_1 = 0U,    /*!< Digital Compare Event number 1 */
    EPWM_DC_EVENT_2          /*!< Digital Compare Event number 2 */
} EPWM_DigitalCompareEvent;

/**
  * @}
  */

/** @defgroup EPWM_DIGITALCOMPAREEVENTSOURCE EPWM Digital Compare Event Source
  * @{
  * @brief  Macro definitions about EPWM digital compare event source selection.
  */
typedef enum {
    EPWM_DC_EVENT_SOURCE_ORIG_SIGNAL = 0U,    /*!< Signal source is unfiltered (DCAEVT1/2) */
    EPWM_DC_EVENT_SOURCE_FILT_SIGNAL          /*!< Signal source is filtered (DCEVTFILT) */
} EPWM_DigitalCompareEventSource;

/**
  * @}
  */

/** @defgroup EPWM_DIGITALCOMPARESYNCMODE EPWM Digital Compare Event Sync Mode
  * @{
  * @brief  Macro definitions about EPWM digital compare event sync mode selection.
  */
typedef enum {
    EPWM_DC_EVENT_INPUT_SYNCED = 0U,    /*!< DC input signal is synced with TBCLK */
    EPWM_DC_EVENT_INPUT_NOT_SYNCED      /*!< DC input signal is not synced with TBCLK */
} EPWM_DigitalCompareSyncMode;

/**
  * @}
  */

/** @defgroup EPWM_DIGITALCOMPARECBCLATCHMODE EPWM Digital Compare Cycle-by-Cycle Latch Mode
  * @{
  * @brief  Macro definitions about EPWM digital compare cycle-by-cycle latch mode selection.
  */
typedef enum {
    EPWM_DC_CBC_LATCH_DISABLED = 0x0U,    /*!< DC cycle-by-cycle(CBC) latch is disabled */
    EPWM_DC_CBC_LATCH_ENABLED             /*!< DC cycle-by-cycle(CBC) latch is enabled */
} EPWM_DigitalCompareCBCLatchMode;

/**
  * @}
  */

/** @defgroup EPWM_DIGITALCOMPARECBCLATCHCLEAREVENT EPWM Digital Compare Cycle-by-Cycle Latch Clear Event
  * @{
  * @brief  Macro definitions about EPWM digital compare cycle-by-cycle latch clear event selection.
  */
typedef enum {
    EPWM_DC_CBC_LATCH_CLR_CNTR_ZERO = 0x0U,      /*!< Clear CBC latch when counter equals zero */
    EPWM_DC_CBC_LATCH_CLR_ON_CNTR_PERIOD,        /*!< Clear CBC latch when counter equals period */
    EPWM_DC_CBC_LATCH_CLR_ON_CNTR_ZERO_PERIOD    /*!< Clear CBC latch when counter equals zero or period */
} EPWM_DigitalCompareCBCLatchClearEvent;

/**
  * @}
  */

/** @defgroup EPWM_VALLEYTRIGGERSOURCE EPWM Valley Capture Trigger Source
  * @{
  * @brief  Macro definitions about EPWM valley capture trigger source selection.
  */
typedef enum {
    EPWM_VALLEY_TRIGGER_EVENT_SOFTWARE = 0U,       /*!< Valley capture trigged by software */
    EPWM_VALLEY_TRIGGER_EVENT_CNTR_ZERO,           /*!< Valley capture trigged by when counter is equal to zero */
    EPWM_VALLEY_TRIGGER_EVENT_CNTR_PERIOD,         /*!< Valley capture trigged by when counter is equal period */
    EPWM_VALLEY_TRIGGER_EVENT_CNTR_ZERO_PERIOD,    /*!< Valley capture trigged when counter is equal to zero or period */
    EPWM_VALLEY_TRIGGER_EVENT_DCAEVT1,             /*!< Valley capture trigged by DCAEVT1 (Digital Compare A event 1) */
    EPWM_VALLEY_TRIGGER_EVENT_DCAEVT2,             /*!< Valley capture trigged by DCAEVT2 (Digital Compare A event 2) */
    EPWM_VALLEY_TRIGGER_EVENT_DCBEVT1,             /*!< Valley capture trigged by DCBEVT1 (Digital Compare B event 1) */
    EPWM_VALLEY_TRIGGER_EVENT_DCBEVT2              /*!< Valley capture trigged by DCBEVT2 (Digital Compare B event 2) */
} EPWM_ValleyTriggerSource;

/**
  * @}
  */

/** @defgroup EPWM_VALLEYDELAYMODE EPWM Valley Delay Mode
  * @{
  * @brief  Macro definitions about EPWM valley delay mode selection.
  */
typedef enum {
    EPWM_VALLEY_DELAY_MODE_SW_DELAY = 0U,                  /*!< Delay value equals the shift value defines by software */
    EPWM_VALLEY_DELAY_MODE_VCNT_DELAY_SW_DELAY,            /*!< Delay value equals the sum of the Hardware counter
                                                                      value and the shift value defines by software */
    EPWM_VALLEY_DELAY_MODE_VCNT_DELAY_SHIFT_1_SW_DELAY,    /*!< Delay value equals the the Hardware counter
                                                                      shifted by (1 + the shift value defines by software) */
    EPWM_VALLEY_DELAY_MODE_VCNT_DELAY_SHIFT_2_SW_DELAY,    /*!< Delay value equals the the Hardware counter shifted by
                                                                      (2 + the shift value defines by software) */
    EPWM_VALLEY_DELAY_MODE_VCNT_DELAY_SHIFT_4_SW_DELAY     /*!< Delay value equals the the Hardware counter shifted by
                                                                      (4 + the shift value defines by software) */
} EPWM_ValleyDelayMode;

/**
  * @}
  */

/** @defgroup EPWM_VALLEYCOUNTEREDGE EPWM Valley Counter Edge
  * @{
  * @brief  Macro definitions about EPWM valley counter edge selection.
  */
typedef enum {
    EPWM_VALLEY_COUNT_START_EDGE = 0U,    /*!< Valley count start edge */
    EPWM_VALLEY_COUNT_STOP_EDGE           /*!< Valley count stop edge */
} EPWM_ValleyCounterEdge;

/**
  * @}
  */

/** @defgroup EPWM_GLOBALLOADTRIGGER EPWM Global Load Trigger Source
  * @{
  * @brief  Macro definitions about EPWM global load trigger source selection.
  */
typedef enum {
    EPWM_GL_LOAD_PULSE_CNTR_ZERO = 0x0U,         /*!< Load when counter is equal to zero */
    EPWM_GL_LOAD_PULSE_CNTR_PERIOD,              /*!< Load when counter is equal to period */
    EPWM_GL_LOAD_PULSE_CNTR_ZERO_PERIOD,         /*!< Load when counter is equal to zero or period */
    EPWM_GL_LOAD_PULSE_SYNC,                     /*!< Load on sync event */
    EPWM_GL_LOAD_PULSE_SYNC_OR_CNTR_ZERO,        /*!< Load on sync event or when counter  is equal to zero */
    EPWM_GL_LOAD_PULSE_SYNC_OR_CNTR_PERIOD,      /*!< Load on sync event or when counter  is equal to period */
    EPWM_GL_LOAD_PULSE_SYNC_CNTR_ZERO_PERIOD,    /*!< Load on sync event or when counter is equal to period or zero */
    EPWM_GL_LOAD_PULSE_CNTR_U_CMPC = 0x8U,       /*!< Load on counter incrementing equal cmpc */
    EPWM_GL_LOAD_PULSE_CNTR_D_CMPC,              /*!< Load on counter decrementing equal cmpc */
    EPWM_GL_LOAD_PULSE_CNTR_U_CMPD,              /*!< Load on counter incrementing equal cmpd */
    EPWM_GL_LOAD_PULSE_CNTR_D_CMPD,              /*!< Load on counter decrementing equal cmpd */
    EPWM_GL_LOAD_PULSE_GLOBAL_FORCE = 0xFU       /*!< Load on global force */
} EPWM_GlobalLoadTrigger;

/**
  * @}
  */

/** @defgroup EPWM_DIGITALCOMPAREEDGEFILTERMODE EPWM Digital Compare Edge Filter Mode
  * @{
  * @brief  Macro definitions about EPWM digital compare edge filter mode selection.
  */
typedef enum {
    EPWM_DC_EDGEFILT_MODE_RISING = 0U,    /*!< Digital Compare Edge filter low to high edge mode */
    EPWM_DC_EDGEFILT_MODE_FALLING,        /*!< Digital Compare Edge filter high to low edge mode */
    EPWM_DC_EDGEFILT_MODE_BOTH            /*!< Digital Compare Edge filter both edges mode */
} EPWM_DigitalCompareEdgeFilterMode;

/**
  * @}
  */

/** @defgroup EPWM_LOCKREGISTERGROUP EPWM Lock Register Group
  * @{
  * @brief  Macro definitions about EPWM lock register group selection.
  */
typedef enum {
    EPWM_REGISTER_GROUP_GLOBAL_LOAD     = 0x2U,    /*!< Global load register group */
    EPWM_REGISTER_GROUP_TRIP_ZONE       = 0x4U,    /*!< Trip zone register group */
    EPWM_REGISTER_GROUP_TRIP_ZONE_CLEAR = 0x8U,    /*!< Trip zone clear group */
    EPWM_REGISTER_GROUP_DIGITAL_COMPARE = 0x10U    /*!< Digital compare group */
} EPWM_LockRegisterGroup;

/**
  * @}
  */

/** @defgroup EPWM_DIGITALCOMPAREEDGEFILTEREDGECOUNT EPWM Edge Count Of Digital Comparison Edge Filter
  * @{
  * @brief  Macro definitions about EPWM edge count of digital comparison edge filter selection.
  */
typedef enum {
    EPWM_DC_EDGEFILT_EDGECNT_0 = 0U,    /*!< Digital Compare Edge filter edge count = 0 */
    EPWM_DC_EDGEFILT_EDGECNT_1,        /*!< Digital Compare Edge filter edge count = 1 */
    EPWM_DC_EDGEFILT_EDGECNT_2,        /*!< Digital Compare Edge filter edge count = 2 */
    EPWM_DC_EDGEFILT_EDGECNT_3,        /*!< Digital Compare Edge filter edge count = 3 */
    EPWM_DC_EDGEFILT_EDGECNT_4,        /*!< Digital Compare Edge filter edge count = 4 */
    EPWM_DC_EDGEFILT_EDGECNT_5,        /*!< Digital Compare Edge filter edge count = 5 */
    EPWM_DC_EDGEFILT_EDGECNT_6,        /*!< Digital Compare Edge filter edge count = 6 */
    EPWM_DC_EDGEFILT_EDGECNT_7         /*!< Digital Compare Edge filter edge count = 7 */
} EPWM_DigitalCompareEdgeFilterEdgeCount;

/**
  * @}
  */

/** @defgroup EPWM_ACTIONQUALIFIEREVENTACTION EPWM Action Qualifier Event Action
  * @{
  * @brief  Macro definitions about EPWM action qualifier event action configuration.
  */
typedef enum {
    EPWM_AQ_OUTPUT_NO_CHANGE_ZERO      = 0x0U,        /*!< Counter=0: No change */
    EPWM_AQ_OUTPUT_LOW_ZERO            = 0x1U,        /*!< Counter=0: Set low */
    EPWM_AQ_OUTPUT_HIGH_ZERO           = 0x2U,        /*!< Counter=0: Set high */
    EPWM_AQ_OUTPUT_TOGGLE_ZERO         = 0x3U,        /*!< Counter=0: Toggle */
    EPWM_AQ_OUTPUT_NO_CHANGE_PERIOD    = 0x0U,        /*!< Counter=Period: No change */
    EPWM_AQ_OUTPUT_LOW_PERIOD          = 0x4U,        /*!< Counter=Period: Set low */
    EPWM_AQ_OUTPUT_HIGH_PERIOD         = 0x8U,        /*!< Counter=Period: Set high */
    EPWM_AQ_OUTPUT_TOGGLE_PERIOD       = 0xCU,        /*!< Counter=Period: Toggle */
    EPWM_AQ_OUTPUT_NO_CHANGE_UP_CMPA   = 0x0U,        /*!< Counter↑=CMPA: No change */
    EPWM_AQ_OUTPUT_LOW_UP_CMPA         = 0x10U,       /*!< Counter↑=CMPA: Set low */
    EPWM_AQ_OUTPUT_HIGH_UP_CMPA        = 0x20U,       /*!< Counter↑=CMPA: Set high */
    EPWM_AQ_OUTPUT_TOGGLE_UP_CMPA      = 0x30U,       /*!< Counter↑=CMPA: Toggle */
    EPWM_AQ_OUTPUT_NO_CHANGE_DOWN_CMPA = 0x0U,        /*!< Counter↓=CMPA: No change */
    EPWM_AQ_OUTPUT_LOW_DOWN_CMPA       = 0x40U,       /*!< Counter↓=CMPA: Set low */
    EPWM_AQ_OUTPUT_HIGH_DOWN_CMPA      = 0x80U,       /*!< Counter↓=CMPA: Set high */
    EPWM_AQ_OUTPUT_TOGGLE_DOWN_CMPA    = 0xC0U,       /*!< Counter↓=CMPA: Toggle */
    EPWM_AQ_OUTPUT_NO_CHANGE_UP_CMPB   = 0x0U,        /*!< Counter↑=CMPB: No change */
    EPWM_AQ_OUTPUT_LOW_UP_CMPB         = 0x100U,      /*!< Counter↑=CMPB: Set low */
    EPWM_AQ_OUTPUT_HIGH_UP_CMPB        = 0x200U,      /*!< Counter↑=CMPB: Set high */
    EPWM_AQ_OUTPUT_TOGGLE_UP_CMPB      = 0x300U,      /*!< Counter↑=CMPB: Toggle */
    EPWM_AQ_OUTPUT_NO_CHANGE_DOWN_CMPB = 0x0U,        /*!< Counter↓=CMPB: No change */
    EPWM_AQ_OUTPUT_LOW_DOWN_CMPB       = 0x400U,      /*!< Counter↓=CMPB: Set low */
    EPWM_AQ_OUTPUT_HIGH_DOWN_CMPB      = 0x800U,      /*!< Counter↓=CMPB: Set high */
    EPWM_AQ_OUTPUT_TOGGLE_DOWN_CMPB    = 0xC00U,      /*!< Counter↓=CMPB: Toggle */
    EPWM_AQ_OUTPUT_NO_CHANGE_UP_CMPC   = 0x0U,        /*!< Counter↑=CMPC: No change */
    EPWM_AQ_OUTPUT_LOW_UP_CMPC         = 0x100U,      /*!< Counter↑=CMPC: Set low */
    EPWM_AQ_OUTPUT_HIGH_UP_CMPC        = 0x200U,      /*!< Counter↑=CMPC: Set high */
    EPWM_AQ_OUTPUT_TOGGLE_UP_CMPC      = 0x300U,      /*!< Counter↑=CMPC: Toggle */
    EPWM_AQ_OUTPUT_NO_CHANGE_DOWN_CMPC = 0x0U,        /*!< Counter↓=CMPC: No change */
    EPWM_AQ_OUTPUT_LOW_DOWN_CMPC       = 0x1000U,     /*!< Counter↓=CMPC: Set low */
    EPWM_AQ_OUTPUT_HIGH_DOWN_CMPC      = 0x2000U,     /*!< Counter↓=CMPC: Set high */
    EPWM_AQ_OUTPUT_TOGGLE_DOWN_CMPC    = 0x3000U,     /*!< Counter↓=CMPC: Toggle */
    EPWM_AQ_OUTPUT_NO_CHANGE_UP_CMPD   = 0x0U,        /*!< Counter↑=CMPD: No change */
    EPWM_AQ_OUTPUT_LOW_UP_CMPD         = 0x4000U,     /*!< Counter↑=CMPD: Set low */
    EPWM_AQ_OUTPUT_HIGH_UP_CMPD        = 0x8000U,     /*!< Counter↑=CMPD: Set high */
    EPWM_AQ_OUTPUT_TOGGLE_UP_CMPD      = 0xC000U,     /*!< Counter↑=CMPD: Toggle */
    EPWM_AQ_OUTPUT_NO_CHANGE_DOWN_CMPD = 0x0U,        /*!< Counter↓=CMPD: No change */
    EPWM_AQ_OUTPUT_LOW_DOWN_CMPD       = 0x10000U,    /*!< Counter↓=CMPD: Set low */
    EPWM_AQ_OUTPUT_HIGH_DOWN_CMPD      = 0x20000U,    /*!< Counter↓=CMPD: Set high */
    EPWM_AQ_OUTPUT_TOGGLE_DOWN_CMPD    = 0x30000U     /*!< Counter↓=CMPD: Toggle */
} EPWM_ActionQualifierEventAction;

/**
  * @}
  */

/** @defgroup EPWM_ADDITIONALACTIONQUALIFIEREVENTACTION EPWM Enhanced Pulse Width Modulation Additional Action Qualifier Event Action
  * @{
  * @brief  Macro definitions about EPWM Enhanced pulse width modulation additional action qualifier wvent action.
  */
typedef enum {
    EPWM_AQ_OUTPUT_NO_CHANGE_UP_T1   = 0x0U,     /*!< T1 up, no change */
    EPWM_AQ_OUTPUT_LOW_UP_T1         = 0x1U,     /*!< T1 up, set low */
    EPWM_AQ_OUTPUT_HIGH_UP_T1        = 0x2U,     /*!< T1 up, set high */
    EPWM_AQ_OUTPUT_TOGGLE_UP_T1      = 0x3U,     /*!< T1 up, toggle */
    EPWM_AQ_OUTPUT_NO_CHANGE_DOWN_T1 = 0x0U,     /*!< T1 down, no change */
    EPWM_AQ_OUTPUT_LOW_DOWN_T1       = 0x4U,     /*!< T1 down, set low */
    EPWM_AQ_OUTPUT_HIGH_DOWN_T1      = 0x8U,     /*!< T1 down, set high */
    EPWM_AQ_OUTPUT_TOGGLE_DOWN_T1    = 0xCU,     /*!< T1 down, toggle */
    EPWM_AQ_OUTPUT_NO_CHANGE_UP_T2   = 0x00U,    /*!< T2 up, no change */
    EPWM_AQ_OUTPUT_LOW_UP_T2         = 0x10U,    /*!< T2 up, set low */
    EPWM_AQ_OUTPUT_HIGH_UP_T2        = 0x20U,    /*!< T2 up, set high */
    EPWM_AQ_OUTPUT_TOGGLE_UP_T2      = 0x30U,    /*!< T2 up, toggle */
    EPWM_AQ_OUTPUT_NO_CHANGE_DOWN_T2 = 0x0U,     /*!< T2 down, no change */
    EPWM_AQ_OUTPUT_LOW_DOWN_T2       = 0x40U,    /*!< T2 down, set low */
    EPWM_AQ_OUTPUT_HIGH_DOWN_T2      = 0x80U,    /*!< T2 down, set high */
    EPWM_AQ_OUTPUT_TOGGLE_DOWN_T2    = 0xC0U     /*!< T2 down, toggle */
} EPWM_AdditionalActionQualifierEventAction;

/**
  * @}
  */

/** @defgroup EPWM_SELECTTRIPOUTSOURCE EPWM Trip Out Source
  * @{
  * @brief  Macro definitions about EPWM trip out source parameter.
  */
typedef enum {
    EPWM_TZ_TRIPOUT_OST = 0U,    /*!< OST as TRIPOUT source */
    EPWM_TZ_TRIPOUT_CBC,        /*!< CBC as TRIPOUT source */
    EPWM_TZ_TRIPOUT_TZ1,        /*!< TZ1 as TRIPOUT source */
    EPWM_TZ_TRIPOUT_TZ2,        /*!< TZ2 as TRIPOUT source */
    EPWM_TZ_TRIPOUT_TZ3,        /*!< TZ3 as TRIPOUT source */
    EPWM_TZ_TRIPOUT_TZ4,        /*!< TZ4 as TRIPOUT source */
    EPWM_TZ_TRIPOUT_TZ5,        /*!< TZ5 as TRIPOUT source */
    EPWM_TZ_TRIPOUT_TZ6,        /*!< TZ6 as TRIPOUT source */
    EPWM_TZ_TRIPOUT_DCAEVT1,    /*!< DCAEVT1 as TRIPOUT source */
    EPWM_TZ_TRIPOUT_DCAEVT2,    /*!< DCAEVT2 as TRIPOUT source */
    EPWM_TZ_TRIPOUT_DCBEVT1,    /*!< DCBEVT1 as TRIPOUT source */
    EPWM_TZ_TRIPOUT_DCBEVT2,    /*!< DCBEVT2 as TRIPOUT source */
    EPWM_TZ_TRIPOUT_CAPEVT      /*!< Capture Event as TRIPOUT source */
} EPWM_selectTripOutSource;

/**
  * @}
  */

/** @defgroup EPWM_ETMIXSIGNALSELECT EPWM Event-Trigger Mixed Signal
  * @{
  * @brief  Macro definitions about EPWM event-trigger mixed signal parameter.
  */
typedef enum {
    EPWM_ETMIX_INTERRUPT = 0U,      /*!< Event-Trigger Mixed INT Selection */
    EPWM_ETMIX_SOCA      = 0x8U,    /*!< Event-Trigger Mixed SOCA Selection */
    EPWM_ETMIX_SOCB      = 0x10U    /*!< Event-Trigger Mixed SOCB Selection */
} EPWM_ETMixSignalSelect;

/**
  * @}
  */

/** @defgroup EPWM_ETMIXTRIGGERSOURCE EPWM Event-Trigger Mixed Source
  * @{
  * @brief  Macro definitions about EPWM event-trigger mixed source parameter.
  */
typedef enum {
    EPWM_ETMIX_TBCTR_ZERO = 0U,    /*!< Time-base counter equal to zero */
    EPWM_ETMIX_TBCTR_PERIOD,       /*!< Time-base counter equal to period */
    EPWM_ETMIX_TBCTR_U_CMPA,       /*!< Time-base counter equal to CMPA when the timer is incrementing */
    EPWM_ETMIX_TBCTR_D_CMPA,       /*!< Time-base counter equal to CMPA when the timer is decrementing */
    EPWM_ETMIX_TBCTR_U_CMPB,       /*!< Time-base counter equal to CMPB when the timer is incrementing */
    EPWM_ETMIX_TBCTR_D_CMPB,       /*!< Time-base counter equal to CMPB when the timer is decrementing */
    EPWM_ETMIX_TBCTR_U_CMPC,       /*!< Time-base counter equal to CMPC when the timer is incrementing */
    EPWM_ETMIX_TBCTR_D_CMPC,       /*!< Time-base counter equal to CMPC when the timer is decrementing */
    EPWM_ETMIX_TBCTR_U_CMPD,       /*!< Time-base counter equal to CMPD when the timer is incrementing */
    EPWM_ETMIX_TBCTR_D_CMPD,       /*!< Time-base counter equal to CMPD when the timer is decrementing */
    EPWM_ETMIX_DCAEVT1,            /*!< Event is based on DCAEVT1 or DCBEVT1 */
    EPWM_ETMIX_DCAEVT1SEL = 16U    /*!< Event source selection of DCAEVT1 or DCBEVT1 */
} EPWM_ETMixTriggerSource;

/**
  * @}
  */

/** @defgroup EPWM_SELECTCAPTUREGATEINPUTPOLARITY EPWM Select Gate Input Polarity
  * @{
  * @brief  Macro definitions about EPWM Select Gate Input Polarity parameter.
  */
typedef enum {
    EPWM_CAPGATE_INPUT_ALWAYS_ON  = 0U,    /*!< Capture gate is always on */
    EPWM_CAPGATE_INPUT_ALWAYS_OFF,        /*!< Capture gate is always off */
    EPWM_CAPGATE_INPUT_SYNC,              /*!< Capture gate input is CAPGATE.sync */
    EPWM_CAPGATE_INPUT_SYNC_INVERT        /*!< Capture gate input is CAPGATE.sync inverted */
} EPWM_selectCaptureGateInputPolarity;

/**
  * @}
  */

/** @defgroup EPWM_SELECTCAPTUREINPUTPOLARITY EPWM Select Capture Input Polarity
  * @{
  * @brief  Macro definitions about EPWM Select Capture Input Polarity parameter.
  */
typedef enum {
    EPWM_CAPTURE_INPUT_CAPIN_SYNC = 0U,      /*!< Capture input is not inverted */
    EPWM_CAPTURE_INPUT_CAPIN_SYNC_INVERT    /*!< Capture input is inverted */
} EPWM_selectCaptureInputPolarity;

/**
  * @}
  */

/** @defgroup EPWM_CAPTUREINPUTTYPE EPWM Capture Input Type
  * @{
  * @brief  Macro definitions about EPWM Capture Input Type parameter.
  */
typedef enum {
    EPWM_CAPTURE_INPUT = 0U,    /*!< Capture Input */
    EPWM_CAPTURE_GATE           /*!< Capture Gate */
} EPWM_CaptureInputType;

/**
  * @}
  */

/** @defgroup EPWM_SIGNALPARAMS EPWM Signal Parameters
  * @{
  * @brief  Macro definitions about PWM signal parameter configuration.
  */
typedef struct {
    float                     freqInHz;         /*!< Desired Signal Frequency(in Hz) */
    float                     dutyValA;         /*!< Desired ePWMxA Signal Duty */
    float                     dutyValB;         /*!< Desired ePWMxB Signal Duty */
    bool                      invertSignalB;    /*!< Invert ePWMxB Signal if true */
    float                     sysClkInHz;       /*!< SYSCLK Frequency(in Hz) */
    EPWM_TimeBaseCountMode    tbCtrMode;        /*!< Time Base Counter Mode */
    EPWM_ClockDivider         tbClkDiv;         /*!< Time Base Counter Clock Divider */
    EPWM_HSClockDivider       tbHSClkDiv;       /*!< Time Base Counter HS Clock Divider */
} EPWM_SignalParams;

/**
  * @}
  */


/** @defgroup EPWM_DIODEEMULATIONMODE load mode selection for Diode emulation mode
  * @{
  * @brief  Macro definitions about load mode selection for Diode emulation mode.
  */
 typedef enum {
  EPWM_DIODE_EMULATION_CBC = 0U,    /*!< Diode Emulation mode is Cycle by Cycle */
  EPWM_DIODE_EMULATION_OST          /*!< Diode Emulation mode is One Shot */
} EPWM_DiodeEmulationMode;

/**
  * @}
  */

/** @defgroup EPWM_DIODEEMULATIONTRIPLSOURCE the trip low source
  * @{
  * @brief  Macro definitions about the tripL source.
  */
typedef enum {
  EPWM_DE_TRIPL_SRC_CMPSSTRIPL1 = 0x00U,           /*!< Trip source is CMPSSTRIPL1 signal */
  EPWM_DE_TRIPL_SRC_CMPSSTRIPL2 = 0x01U,           /*!< Trip source is CMPSSTRIPL2 signal */
  EPWM_DE_TRIPL_SRC_CMPSSTRIPL3 = 0x02U,           /*!< Trip source is CMPSSTRIPL3 signal */
  EPWM_DE_TRIPL_SRC_CMPSSTRIPL4 = 0x03U,           /*!< Trip source is CMPSSTRIPL4 signal */
  EPWM_DE_TRIPL_SRC_CMPSSTRIPL5 = 0x04U,           /*!< Trip source is CMPSSTRIPL5 signal */
  EPWM_DE_TRIPL_SRC_CMPSSTRIPL6 = 0x05U,           /*!< Trip source is CMPSSTRIPL6 signal */
  EPWM_DE_TRIPL_SRC_CMPSSTRIPL7 = 0x06U,           /*!< Trip source is CMPSSTRIPL7 signal */
  EPWM_DE_TRIPL_SRC_CMPSSTRIPL8 = 0x07U,           /*!< Trip source is CMPSSTRIPL8 signal */
  EPWM_DE_TRIPL_SRC_CMPSSTRIPL9 = 0x08U,           /*!< Trip source is CMPSSTRIPL9 signal */
  EPWM_DE_TRIPL_SRC_CMPSSTRIPL10 = 0x09U,          /*!< Trip source is CMPSSTRIPL10 signal */
  EPWM_DE_TRIPL_SRC_CMPSSTRIPL11 = 0x0AU,          /*!< Trip source is CMPSSTRIPL11 signal */
  EPWM_DE_TRIPL_SRC_INPUTXBAR_OUT1 = 0x10U,        /*!< Trip source is INPUTXBAR out1 signal */
  EPWM_DE_TRIPL_SRC_INPUTXBAR_OUT2 = 0x11U,        /*!< Trip source is INPUTXBAR out2 signal */
  EPWM_DE_TRIPL_SRC_INPUTXBAR_OUT3 = 0x12U,        /*!< Trip source is INPUTXBAR out3 signal */
  EPWM_DE_TRIPL_SRC_INPUTXBAR_OUT4 = 0x13U,        /*!< Trip source is INPUTXBAR out4 signal */
  EPWM_DE_TRIPL_SRC_INPUTXBAR_OUT5 = 0x14U,        /*!< Trip source is INPUTXBAR out5 signal */
  EPWM_DE_TRIPL_SRC_INPUTXBAR_OUT6 = 0x15U,        /*!< Trip source is INPUTXBAR out6 signal */
  EPWM_DE_TRIPL_SRC_INPUTXBAR_OUT7 = 0x16U,        /*!< Trip source is INPUTXBAR out7 signal */
  EPWM_DE_TRIPL_SRC_INPUTXBAR_OUT8 = 0x17U,        /*!< Trip source is INPUTXBAR out8 signal */
  EPWM_DE_TRIPL_SRC_INPUTXBAR_OUT9 = 0x18U,        /*!< Trip source is INPUTXBAR out9 signal */
  EPWM_DE_TRIPL_SRC_INPUTXBAR_OUT10 = 0x19U,       /*!< Trip source is INPUTXBAR out10 signal */
  EPWM_DE_TRIPL_SRC_INPUTXBAR_OUT11 = 0x1AU,       /*!< Trip source is INPUTXBAR out11 signal */
  EPWM_DE_TRIPL_SRC_INPUTXBAR_OUT12 = 0x1BU,       /*!< Trip source is INPUTXBAR out12 signal */
  EPWM_DE_TRIPL_SRC_INPUTXBAR_OUT13 = 0x1CU,       /*!< Trip source is INPUTXBAR out13 signal */
  EPWM_DE_TRIPL_SRC_INPUTXBAR_OUT14 = 0x1DU,       /*!< Trip source is INPUTXBAR out14 signal */
  EPWM_DE_TRIPL_SRC_INPUTXBAR_OUT15 = 0x1EU,       /*!< Trip source is INPUTXBAR out15 signal */
  EPWM_DE_TRIPL_SRC_INPUTXBAR_OUT16 = 0x1FU,       /*!< Trip source is INPUTXBAR out16 signal */
  EPWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT1 = 0x20U,     /*!< Trip source is CLBINPUTXBAR out1 signal */
  EPWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT2 = 0x21U,     /*!< Trip source is CLBINPUTXBAR out2 signal */
  EPWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT3 = 0x22U,     /*!< Trip source is CLBINPUTXBAR out3 signal */
  EPWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT4 = 0x23U,     /*!< Trip source is CLBINPUTXBAR out4 signal */
  EPWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT5 = 0x24U,     /*!< Trip source is CLBINPUTXBAR out5 signal */
  EPWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT6 = 0x25U,     /*!< Trip source is CLBINPUTXBAR out6 signal */
  EPWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT7 = 0x26U,     /*!< Trip source is CLBINPUTXBAR out7 signal */
  EPWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT8 = 0x27U,     /*!< Trip source is CLBINPUTXBAR out8 signal */
  EPWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT9 = 0x28U,     /*!< Trip source is CLBINPUTXBAR out9 signal */
  EPWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT10 = 0x29U,    /*!< Trip source is CLBINPUTXBAR out10 signal */
  EPWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT11 = 0x2AU,    /*!< Trip source is CLBINPUTXBAR out11 signal */
  EPWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT12 = 0x2BU,    /*!< Trip source is CLBINPUTXBAR out12 signal */
  EPWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT13 = 0x2CU,    /*!< Trip source is CLBINPUTXBAR out13 signal */
  EPWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT14 = 0x2DU,    /*!< Trip source is CLBINPUTXBAR out14 signal */
  EPWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT15 = 0x2EU,    /*!< Trip source is CLBINPUTXBAR out15 signal */
  EPWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT16 = 0x2FU,    /*!< Trip source is CLBINPUTXBAR out16 signal */
} EPWM_DiodeEmulationTripLSource;

/**
  * @}
  */

/** @defgroup EPWM_DIODEEMULATIONTRIPHSOURCE the trip low source
  * @{
  * @brief  Macro definitions about the tripL source.
  */
typedef enum {
  EPWM_DE_TRIPH_SRC_CMPSSTRIPH1 = 0x00U,           /*!< Trip source is CMPSSTRIPH1 signal */
  EPWM_DE_TRIPH_SRC_CMPSSTRIPH2 = 0x01U,           /*!< Trip source is CMPSSTRIPH2 signal */
  EPWM_DE_TRIPH_SRC_CMPSSTRIPH3 = 0x02U,           /*!< Trip source is CMPSSTRIPH3 signal */
  EPWM_DE_TRIPH_SRC_CMPSSTRIPH4 = 0x03U,           /*!< Trip source is CMPSSTRIPH4 signal */
  EPWM_DE_TRIPH_SRC_CMPSSTRIPH5 = 0x04U,           /*!< Trip source is CMPSSTRIPH5 signal */
  EPWM_DE_TRIPH_SRC_CMPSSTRIPH6 = 0x05U,           /*!< Trip source is CMPSSTRIPH6 signal */
  EPWM_DE_TRIPH_SRC_CMPSSTRIPH7 = 0x06U,           /*!< Trip source is CMPSSTRIPH7 signal */
  EPWM_DE_TRIPH_SRC_CMPSSTRIPH8 = 0x07U,           /*!< Trip source is CMPSSTRIPH8 signal */
  EPWM_DE_TRIPH_SRC_CMPSSTRIPH9 = 0x08U,           /*!< Trip source is CMPSSTRIPH9 signal */
  EPWM_DE_TRIPH_SRC_CMPSSTRIPH10 = 0x09U,          /*!< Trip source is CMPSSTRIPH10 signal */
  EPWM_DE_TRIPH_SRC_CMPSSTRIPH11 = 0x0AU,          /*!< Trip source is CMPSSTRIPH11 signal */
  EPWM_DE_TRIPH_SRC_INPUTXBAR_OUT1 = 0x10U,        /*!< Trip source is INPUTXBAR out1 signal */
  EPWM_DE_TRIPH_SRC_INPUTXBAR_OUT2 = 0x11U,        /*!< Trip source is INPUTXBAR out2 signal */
  EPWM_DE_TRIPH_SRC_INPUTXBAR_OUT3 = 0x12U,        /*!< Trip source is INPUTXBAR out3 signal */
  EPWM_DE_TRIPH_SRC_INPUTXBAR_OUT4 = 0x13U,        /*!< Trip source is INPUTXBAR out4 signal */
  EPWM_DE_TRIPH_SRC_INPUTXBAR_OUT5 = 0x14U,        /*!< Trip source is INPUTXBAR out5 signal */
  EPWM_DE_TRIPH_SRC_INPUTXBAR_OUT6 = 0x15U,        /*!< Trip source is INPUTXBAR out6 signal */
  EPWM_DE_TRIPH_SRC_INPUTXBAR_OUT7 = 0x16U,        /*!< Trip source is INPUTXBAR out7 signal */
  EPWM_DE_TRIPH_SRC_INPUTXBAR_OUT8 = 0x17U,        /*!< Trip source is INPUTXBAR out8 signal */
  EPWM_DE_TRIPH_SRC_INPUTXBAR_OUT9 = 0x18U,        /*!< Trip source is INPUTXBAR out9 signal */
  EPWM_DE_TRIPH_SRC_INPUTXBAR_OUT10 = 0x19U,       /*!< Trip source is INPUTXBAR out10 signal */
  EPWM_DE_TRIPH_SRC_INPUTXBAR_OUT11 = 0x1AU,       /*!< Trip source is INPUTXBAR out11 signal */
  EPWM_DE_TRIPH_SRC_INPUTXBAR_OUT12 = 0x1BU,       /*!< Trip source is INPUTXBAR out12 signal */
  EPWM_DE_TRIPH_SRC_INPUTXBAR_OUT13 = 0x1CU,       /*!< Trip source is INPUTXBAR out13 signal */
  EPWM_DE_TRIPH_SRC_INPUTXBAR_OUT14 = 0x1DU,       /*!< Trip source is INPUTXBAR out14 signal */
  EPWM_DE_TRIPH_SRC_INPUTXBAR_OUT15 = 0x1EU,       /*!< Trip source is INPUTXBAR out15 signal */
  EPWM_DE_TRIPH_SRC_INPUTXBAR_OUT16 = 0x1FU,       /*!< Trip source is INPUTXBAR out16 signal */
  EPWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT1 = 0x20U,     /*!< Trip source is CLBINPUTXBAR out1 signal */
  EPWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT2 = 0x21U,     /*!< Trip source is CLBINPUTXBAR out2 signal */
  EPWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT3 = 0x22U,     /*!< Trip source is CLBINPUTXBAR out3 signal */
  EPWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT4 = 0x23U,     /*!< Trip source is CLBINPUTXBAR out4 signal */
  EPWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT5 = 0x24U,     /*!< Trip source is CLBINPUTXBAR out5 signal */
  EPWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT6 = 0x25U,     /*!< Trip source is CLBINPUTXBAR out6 signal */
  EPWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT7 = 0x26U,     /*!< Trip source is CLBINPUTXBAR out7 signal */
  EPWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT8 = 0x27U,     /*!< Trip source is CLBINPUTXBAR out8 signal */
  EPWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT9 = 0x28U,     /*!< Trip source is CLBINPUTXBAR out9 signal */
  EPWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT10 = 0x29U,    /*!< Trip source is CLBINPUTXBAR out10 signal */
  EPWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT11 = 0x2AU,    /*!< Trip source is CLBINPUTXBAR out11 signal */
  EPWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT12 = 0x2BU,    /*!< Trip source is CLBINPUTXBAR out12 signal */
  EPWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT13 = 0x2CU,    /*!< Trip source is CLBINPUTXBAR out13 signal */
  EPWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT14 = 0x2DU,    /*!< Trip source is CLBINPUTXBAR out14 signal */
  EPWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT15 = 0x2EU,    /*!< Trip source is CLBINPUTXBAR out15 signal */
  EPWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT16 = 0x2FU,    /*!< Trip source is CLBINPUTXBAR out16 signal */
} EPWM_DiodeEmulationTripHSource;

/**
  * @}
  */

/** @defgroup EPWM_DIODEEMULATIONSIGNAL the signal selected by the TRIPSEL[A/B]
  * @{
  * @brief  Macro definitions about the signal selected by the TRIPSEL[A/B].
  */
typedef enum {
  EPWM_DE_SYNC_TRIPHorL = 0U,    /*!< Synchronized version of TRIPH or TRIPL signal */
  EPWM_DE_SYNC_INV_TRIPHorL,     /*!< Synchronized and inverted version of TRIPH or TRIPL signal */
  EPWM_DE_LOW,                   /*!< A constant low signal */
  EPWM_DE_HIGH                   /*!< A constant high signal */
} EPWM_DiodeEmulationSignal;

/**
  * @}
  */

/** @defgroup EPWM_XCMPALLOCTIONCMPA register allocation for CMPA
  * @{
  * @brief  Macro definitions about alloctype parameter configuration for CMPA.
  */
typedef enum {
  EPWM_XCMP_NONE_CMPA = 0U,    /*!< Allocate 0 XCMP registers to CMPA */
  EPWM_XCMP_1_CMPA,            /*!< Allocate XCMP1 register to CMPA */
  EPWM_XCMP_2_CMPA,            /*!< Allocate XCMP1 - XCMP2 registers to CMPA */
  EPWM_XCMP_3_CMPA,            /*!< Allocate XCMP1 - XCMP3 registers to CMPA */
  EPWM_XCMP_4_CMPA,            /*!< Allocate XCMP1 - XCMP4 registers to CMPA */
  EPWM_XCMP_5_CMPA,            /*!< Allocate XCMP1 - XCMP5 registers to CMPA */
  EPWM_XCMP_6_CMPA,            /*!< Allocate XCMP1 - XCMP6 registers to CMPA */
  EPWM_XCMP_7_CMPA,            /*!< Allocate XCMP1 - XCMP7 registers to CMPA */
  EPWM_XCMP_8_CMPA             /*!< Allocate XCMP1 - XCMP8 registers to CMPA */
} EPWM_XCMPAllocationCompareA;

/**
  * @}
  */

/** @defgroup EPWM_XCMPALLOCTIONCMPB register allocation for CMPB
  * @{
  * @brief  Macro definitions about alloctype parameter configuration for CMPB.
  */
typedef enum {
  EPWM_XCMP_5_CMPB = 5U,    /*!< Allocate XCMP5 register to CMPB */
  EPWM_XCMP_6_CMPB,         /*!< Allocate XCMP5 - XCMP6 registers to CMPB */ 
  EPWM_XCMP_7_CMPB,         /*!< Allocate XCMP5 - XCMP7 registers to CMPB */
  EPWM_XCMP_8_CMPB          /*!< Allocate XCMP5 - XCMP8 registers to CMPB */
} EPWM_XCMPAllocationCompareB;

/**
  * @}
  */

/** @defgroup EPWM_XCMPMODELOADCTLLOADMODE load mode.
  * @{
  * @brief  Macro definitions about XCMP load mode.
  */
typedef enum {
  EPWM_XCMP_XLOADCTL_LOADMODE_LOADONCE = 0U,    /*!< Load mode is LOADONCE */
  EPWM_XCMP_XLOADCTL_LOADMODE_LOADMULTIPLE      /*!< Load mode is LOADMULTIPLE */
} EPWM_XCMPModeLoadCtlLoadMode;

/**
  * @}
  */

/** @defgroup EPWM_XCMPXLOADCTLSHDWLEVEL shadow register level allocation.
  * @{
  * @brief  Macro definitions about XCMP shadow register level allocation.
  */
typedef enum {
  EPWM_XCMP_XLOADCTL_SHDWLEVEL_0 = 0U,    /*!< Only Active register is available */
  EPWM_XCMP_XLOADCTL_SHDWLEVEL_1,         /*!< SHDW1 and Active registers are available */
  EPWM_XCMP_XLOADCTL_SHDWLEVEL_2,         /*!< SHDW2, SHDW1 and Active registers are available */
  EPWM_XCMP_XLOADCTL_SHDWLEVEL_3          /*!< SHDW3, SHDW2, SHDW1 and Active registers are available */
} EPWM_XCMPModeLoadCtlShdwLevel;

/**
  * @}
  */

/** @defgroup EPWM_XCMPXLOADCTLSHDWBUFPTR shadow register set in use.
  * @{
  * @brief  Macro definitions about XCMP shadow register set in use.
  */
typedef enum {
  EPWM_XCMP_XLOADCTL_SHDWBUFPTR_NULL = 0U,    /*!< No Shadow buffer is in use */
  EPWM_XCMP_XLOADCTL_SHDWBUFPTR_ONE,          /*!< Shadow buffer 1 is in use */
  EPWM_XCMP_XLOADCTL_SHDWBUFPTR_TWO,          /*!< Shadow buffer 2 is in use */
  EPWM_XCMP_XLOADCTL_SHDWBUFPTR_THREE         /*!< Shadow buffer 3 is in use */
} EPWM_XCMPXloadCtlShdwBufPtr;

/**
  * @}
  */

/** @defgroup EPWM_XCMPREGISTEROFFSET the XCMP register offset.
  * @{
  * @brief  Macro definitions about the XCMP register offset.
  */
typedef enum {
  EPWM_XCMP1_ACTIVE  = 0x0U,     /*!< XCMP1_ACTIVE */
  EPWM_XCMP2_ACTIVE  = 0x8U,     /*!< XCMP2_ACTIVE */
  EPWM_XCMP3_ACTIVE  = 0x10U,    /*!< XCMP3_ACTIVE */
  EPWM_XCMP4_ACTIVE  = 0x18U,    /*!< XCMP4_ACTIVE */
  EPWM_XCMP5_ACTIVE  = 0x20U,    /*!< XCMP5_ACTIVE */
  EPWM_XCMP6_ACTIVE  = 0x28U,    /*!< XCMP6_ACTIVE */
  EPWM_XCMP7_ACTIVE  = 0x30U,    /*!< XCMP7_ACTIVE */
  EPWM_XCMP8_ACTIVE  = 0x38U,    /*!< XCMP8_ACTIVE */
  EPWM_XTBPRD_ACTIVE = 0x40U,    /*!< XTBPRD_ACTIVE */

  EPWM_XCMP1_SHADOW1  = 0x80U,    /*!< XCMP1_SHADOW1 */
  EPWM_XCMP2_SHADOW1  = 0x88U,    /*!< XCMP2_SHADOW1 */
  EPWM_XCMP3_SHADOW1  = 0x90U,    /*!< XCMP3_SHADOW1 */
  EPWM_XCMP4_SHADOW1  = 0x90U,    /*!< XCMP4_SHADOW1 */
  EPWM_XCMP5_SHADOW1  = 0xA0U,    /*!< XCMP5_SHADOW1 */
  EPWM_XCMP6_SHADOW1  = 0xA8U,    /*!< XCMP6_SHADOW1 */
  EPWM_XCMP7_SHADOW1  = 0xB0U,    /*!< XCMP7_SHADOW1 */
  EPWM_XCMP8_SHADOW1  = 0xB8U,    /*!< XCMP8_SHADOW1 */
  EPWM_XTBPRD_SHADOW1 = 0xC0U,    /*!< XTBPRD_SHADOW1 */

  EPWM_XCMP1_SHADOW2  = 0x100U,    /*!< XCMP1_SHADOW2 */
  EPWM_XCMP2_SHADOW2  = 0x108U,    /*!< XCMP2_SHADOW2 */
  EPWM_XCMP3_SHADOW2  = 0x110U,    /*!< XCMP3_SHADOW2 */
  EPWM_XCMP4_SHADOW2  = 0x118U,    /*!< XCMP4_SHADOW2 */
  EPWM_XCMP5_SHADOW2  = 0x120U,    /*!< XCMP5_SHADOW2 */
  EPWM_XCMP6_SHADOW2  = 0x128U,    /*!< XCMP6_SHADOW2 */
  EPWM_XCMP7_SHADOW2  = 0x130U,    /*!< XCMP7_SHADOW2 */
  EPWM_XCMP8_SHADOW2  = 0x138U,    /*!< XCMP8_SHADOW2 */
  EPWM_XTBPRD_SHADOW2 = 0x140U,    /*!< XTBPRD_SHADOW2 */

  EPWM_XCMP1_SHADOW3  = 0x180U,    /*!< XCMP1_SHADOW3 */
  EPWM_XCMP2_SHADOW3  = 0x188U,    /*!< XCMP2_SHADOW3 */
  EPWM_XCMP3_SHADOW3  = 0x190U,    /*!< XCMP3_SHADOW3 */
  EPWM_XCMP4_SHADOW3  = 0x198U,    /*!< XCMP4_SHADOW3 */
  EPWM_XCMP5_SHADOW3  = 0x1A0U,    /*!< XCMP5_SHADOW3 */
  EPWM_XCMP6_SHADOW3  = 0x1A8U,    /*!< XCMP6_SHADOW3 */
  EPWM_XCMP7_SHADOW3  = 0x1B0U,    /*!< XCMP7_SHADOW3 */
  EPWM_XCMP8_SHADOW3  = 0x1B8U,    /*!< XCMP8_SHADOW3 */
  EPWM_XTBPRD_SHADOW3 = 0x1C0U,    /*!< XTBPRD_SHADOW3 */
} EPWM_XCMPRegisterOffset;

/**
  * @}
  */

/** @defgroup EPWM_XCMPACTIONQUALIFIEROUTPUTEVENT the event that causes a change in output.
  * @{
  * @brief  Macro definitions about the event that causes a change in output.
  */
typedef enum {
  EPWM_AQ_OUTPUT_ON_TIMEBASE_XCMP1 = 0U,     /*!< Time base counter equals XCMP1 */
  EPWM_AQ_OUTPUT_ON_TIMEBASE_XCMP2 = 2U,     /*!< Time base counter equals XCMP2 */
  EPWM_AQ_OUTPUT_ON_TIMEBASE_XCMP3 = 4U,     /*!< Time base counter equals XCMP3 */
  EPWM_AQ_OUTPUT_ON_TIMEBASE_XCMP4 = 6U,     /*!< Time base counter equals XCMP4 */
  EPWM_AQ_OUTPUT_ON_TIMEBASE_XCMP5 = 8U,     /*!< Time base counter equals XCMP5 */
  EPWM_AQ_OUTPUT_ON_TIMEBASE_XCMP6 = 10U,    /*!< Time base counter equals XCMP6 */
  EPWM_AQ_OUTPUT_ON_TIMEBASE_XCMP7 = 12U,    /*!< Time base counter equals XCMP7 */
  EPWM_AQ_OUTPUT_ON_TIMEBASE_XCMP8 = 14U     /*!< Time base counter equals XCMP8 */
} EPWM_XCMPActionQualifierOutputEvent;

/**
  * @}
  */

/** @defgroup EPWM_XCOMPAREREG values to CMPx Shadow registers.
  * @{
  * @brief  Macro definitions about values to CMPx Shadow registers.
  */
typedef enum {
  EPWM_CMPC_SHADOW1 = 0x0U,      /*!< CMPC_SHADOW1 */
  EPWM_CMPD_SHADOW1 = 0x8U,      /*!< CMPD_SHADOW1 */
  EPWM_CMPC_SHADOW2 = 0x80U,     /*!< CMPC_SHADOW2 */
  EPWM_CMPD_SHADOW2 = 0x88U,     /*!< CMPD_SHADOW2 */
  EPWM_CMPC_SHADOW3 = 0x100U,    /*!< CMPC_SHADOW3 */
  EPWM_CMPD_SHADOW3 = 0x108U     /*!< CMPD_SHADOW3 */
} EPWM_XCompareReg;

/**
  * @}
  */

/** @defgroup EPWM_XMINMAXREG the XCMP XMINMAX register offset.
  * @{
  * @brief  Macro definitions about the XCMP XMINMAX register offset.
  */
typedef enum {
  EPWM_XMAX_ACTIVE  = 0x0U,       /*!< XMAX_ACTIVE */
  EPWM_XMIN_ACTIVE  = 0x1U,       /*!< XMIN_ACTIVE */
  EPWM_XMAX_SHADOW1 = 0x80U,     /*!< XMAX_SHADOW1 */
  EPWM_XMIN_SHADOW1 = 0x81U,     /*!< XMIN_SHADOW1 */
  EPWM_XMAX_SHADOW2 = 0x100U,    /*!< XMAX_SHADOW2 */
  EPWM_XMIN_SHADOW2 = 0x101U,    /*!< XMIN_SHADOW2 */
  EPWM_XMAX_SHADOW3 = 0x180U,    /*!< XMAX_SHADOW3 */
  EPWM_XMIN_SHADOW3 = 0x181U,    /*!< XMIN_SHADOW3 */
} EPWM_XMinMaxReg;

/**
  * @}
  */

/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
  * \brief  Set the time base count
  * \note   This function writes a new value to the time base counter (TBCTR) register of the EPWM module,
  *         allowing the counter value to be directly set for control purposes
  * \param  epwm     EPWMx pointer to a EPWM_TypeDef structure
  *                   - EPWM1:  EPWM1 module
  *                   - EPWM2:  EPWM2 module
  *                   - EPWM3:  EPWM3 module
  *                   - EPWM4:  EPWM4 module
  *                   - EPWM5:  EPWM5 module
  *                   - EPWM6:  EPWM6 module
  *                   - EPWM7:  EPWM7 module
  *                   - EPWM8:  EPWM8 module
  *                   - EPWM9:  EPWM9 module
  *                   - EPWM10: EPWM10 module
  *                   - EPWM11: EPWM11 module
  *                   - EPWM12: EPWM12 module
  *                   - EPWM13: EPWM13 module
  *                   - EPWM14: EPWM14 module
  *                   - EPWM15: EPWM15 module
  *                   - EPWM16: EPWM16 module
  *                   - EPWM17: EPWM17 module
  *                   - EPWM18: EPWM18 module
  * \param  count    New counter value to be set
  */
static inline void EPWM_setTimeBaseCounter (EPWM_TypeDef *epwm, uint16_t count)
{
    WRITE_REG(epwm->TBCTR.WORDVAL, count);
}

/**
  * \brief  Set count mode after phase shift sync
  * \note   This function configures the count mode of the EPWM omdule after a synchronization event
  *         by modifying the PHSDIR bit in the TBCTL register. The count mode can be set to count up,
  *         count down, or freeze the current count direction
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \param  mode    This value can be any value of @ref EPWM_SYNCCOUNTMODE
  */
static inline void EPWM_setCountModeAfterSync (EPWM_TypeDef *epwm, EPWM_SyncCountMode mode)
{
    if (mode == EPWM_COUNT_MODE_UP_AFTER_SYNC)
    {
        SET_BIT(epwm->TBCTL.WORDVAL, EPWM_TBCTL_PHSDIR_M);
    }
    else
    {
        CLEAR_BIT(epwm->TBCTL.WORDVAL, EPWM_TBCTL_PHSDIR_M);
    }
}

/**
  * \brief  Set the time base clock and the high speed time base clock count pre-scaler
  * \note   This function sets the clock prescaler and high-speed clock prescaler values
  *         in the TBCTL register of the EPWM module. These settings determine the division
  *         ratio of the input clock, affecting the frequency of the EPWM signals
  * \param  epwm                  EPWMx pointer to a EPWM_TypeDef structure
  *                                - EPWM1:  EPWM1 module
  *                                - EPWM2:  EPWM2 module
  *                                - EPWM3:  EPWM3 module
  *                                - EPWM4:  EPWM4 module
  *                                - EPWM5:  EPWM5 module
  *                                - EPWM6:  EPWM6 module
  *                                - EPWM7:  EPWM7 module
  *                                - EPWM8:  EPWM8 module
  *                                - EPWM9:  EPWM9 module
  *                                - EPWM10: EPWM10 module
  *                                - EPWM11: EPWM11 module
  *                                - EPWM12: EPWM12 module
  *                                - EPWM13: EPWM13 module
  *                                - EPWM14: EPWM14 module
  *                                - EPWM15: EPWM15 module
  *                                - EPWM16: EPWM16 module
  *                                - EPWM17: EPWM17 module
  *                                - EPWM18: EPWM18 module
  * \param  prescaler             The clock prescaler value that determines the division ratio of the input clock
  *                                This parameter can be any value of @ref EPWM_CLOCKDIVIDER
  * \param  highSpeedPrescaler    The high-speed clock prescaler value for further dividing the high-speed clock
  *                                This parameter can be any value of @ref EPWM_HSCLOCKDIVIDER
  */
static inline void EPWM_setClockPrescaler (EPWM_TypeDef *epwm, EPWM_ClockDivider prescaler, EPWM_HSClockDivider highSpeedPrescaler)
{
    MODIFY_REG(epwm->TBCTL.WORDVAL, EPWM_TBCTL_CLKDIV_M | EPWM_TBCTL_HSPCLKDIV_M,
               ((uint32_t)prescaler << EPWM_TBCTL_CLKDIV_S) | ((uint32_t)highSpeedPrescaler << EPWM_TBCTL_HSPCLKDIV_S));
}

/**
  * \brief  Force a software sync pulse
  * \note   This function manually triggers the EPWM module to generate a synchronization pulse via software control
  * \note   It is useful in scenarios such as system initialization or specific events where a manual trigger of the EPWM
  *         sync pulse is required
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_forceSyncPulse (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->TBCTL.WORDVAL, EPWM_TBCTL_SWFSYNC_M);
}

/**
  * \brief  Enable load compare repair
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableLoadCompareRepair (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->TBCTL.WORDVAL, EPWM_TBCTL_CMPREPAIR_M);
}

/**
  * \brief  Disable load compare repair
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableLoadCompareRepair (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->TBCTL.WORDVAL, EPWM_TBCTL_CMPREPAIR_M);
}

/**
  * \brief  Select EPWMSYNCOUT
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_SelecSyncOutRegisterEN (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->TBCTL.WORDVAL, EPWM_TBCTL_SYNCOSEL_M);
}

/**
  * \brief  Select EPWMSYNCOUT
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_SelecSyncOutRegisterEN2 (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->TBCTL.WORDVAL, EPWM_TBCTL_SYNCOSEL_M);
}

/**
  * \brief  This function enable sync out enable register
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableSyncOutRegister (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->TBCTL.WORDVAL, EPWM_TBCTL_SYNCENSEL_M);
}

/**
  * \brief  This function disable sync out enable register
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableSyncOutRegister (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->TBCTL.WORDVAL, EPWM_TBCTL_SYNCENSEL_M);
}

/**
  * \brief  Enable Period Compare Sync Load
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enablePeriodCompareSyncLoad (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->TBCTL.WORDVAL, EPWM_TBCTL_PCSYNCEN_M);
}

/**
  * \brief  Disable Period Compare Sync Load
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disablePeriodCompareSyncLoad (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->TBCTL.WORDVAL, EPWM_TBCTL_PCSYNCEN_M);
}

/**
  * \brief  Get Period Shadow Status
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline bool EPWM_getPeriodShadowStatus (EPWM_TypeDef *epwm)
{
    return ((READ_REG(epwm->TBCTL2.WORDVAL) & EPWM_TBCTL2_PRDSHDWFULL_M) >> 16);
}

/**
  * \brief  Enable CMPAHR/CMPBHR Register Linking
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableLinkDutyHR (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->CMPCTL.WORDVAL, EPWM_CMPCTL_LINKDUTYHR_M);
}

/**
  * \brief  Disable CMPAHR/CMPBHR Register Linking
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableLinkDutyHR (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->CMPCTL.WORDVAL, EPWM_CMPCTL_LINKDUTYHR_M);
}

/**
  * \brief  Enable Capture Input Event
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableCaptureInEvent (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->CAPCTL.WORDVAL, EPWM_CAPCTL_SRCSEL_M);
}

/**
  * \brief  Disable Capture Input Event
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableCaptureInEvent (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->CAPCTL.WORDVAL, EPWM_CAPCTL_SRCSEL_M);
}

/**
  * \brief  Config capture gate input polarity
  * \param  epwm      EPWMx pointer to a EPWM_TypeDef structure
  *                    - EPWM1:  EPWM1 module
  *                    - EPWM2:  EPWM2 module
  *                    - EPWM3:  EPWM3 module
  *                    - EPWM4:  EPWM4 module
  *                    - EPWM5:  EPWM5 module
  *                    - EPWM6:  EPWM6 module
  *                    - EPWM7:  EPWM7 module
  *                    - EPWM8:  EPWM8 module
  *                    - EPWM9:  EPWM9 module
  *                    - EPWM10: EPWM10 module
  *                    - EPWM11: EPWM11 module
  *                    - EPWM12: EPWM12 module
  *                    - EPWM13: EPWM13 module
  *                    - EPWM14: EPWM14 module
  *                    - EPWM15: EPWM15 module
  *                    - EPWM16: EPWM16 module
  *                    - EPWM17: EPWM17 module
  *                    - EPWM18: EPWM18 module
  * \param  polSel    This parameter can be any value of @ref EPWM_SELECTCAPTUREGATEINPUTPOLARITY
  */
static inline void EPWM_configCaptureGateInputPolarity (EPWM_TypeDef *epwm, EPWM_selectCaptureGateInputPolarity polSel)
{
    MODIFY_REG(epwm->CAPCTL.WORDVAL, EPWM_CAPCTL_CAPGATEPOL_M, (uint32_t)polSel << EPWM_CAPCTL_CAPGATEPOL_S);
}

/**
  * \brief  Config capture input polarity
  * \param  epwm      EPWMx pointer to a EPWM_TypeDef structure
  *                    - EPWM1:  EPWM1 module
  *                    - EPWM2:  EPWM2 module
  *                    - EPWM3:  EPWM3 module
  *                    - EPWM4:  EPWM4 module
  *                    - EPWM5:  EPWM5 module
  *                    - EPWM6:  EPWM6 module
  *                    - EPWM7:  EPWM7 module
  *                    - EPWM8:  EPWM8 module
  *                    - EPWM9:  EPWM9 module
  *                    - EPWM10: EPWM10 module
  *                    - EPWM11: EPWM11 module
  *                    - EPWM12: EPWM12 module
  *                    - EPWM13: EPWM13 module
  *                    - EPWM14: EPWM14 module
  *                    - EPWM15: EPWM15 module
  *                    - EPWM16: EPWM16 module
  *                    - EPWM17: EPWM17 module
  *                    - EPWM18: EPWM18 module
  * \param  polSel    This parameter can be any value of @ref EPWM_SELECTCAPTUREINPUTPOLARITY
  */
static inline void EPWM_invertCaptureInputPolarity (EPWM_TypeDef *epwm, EPWM_selectCaptureInputPolarity polSel)
{
    MODIFY_REG(epwm->CAPCTL.WORDVAL, EPWM_CAPCTL_CAPINPOL_M, (uint32_t)polSel << EPWM_CAPCTL_CAPINPOL_S);
}

/**
  * \brief  Enable Independent Pulse Logic
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableIndependentPulseLogic (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->CAPCTL.WORDVAL, EPWM_CAPCTL_PULSECTL_M);
}

/**
  * \brief  Disable Independent Pulse Logic
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableIndependentPulseLogic (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->CAPCTL.WORDVAL, EPWM_CAPCTL_PULSECTL_M);
}

/**
  * \brief  Force Capture Event Load
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_forceCaptureEventLoad (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->CAPCTL.WORDVAL, EPWM_CAPCTL_FRCLOAD_M);
}

/**
  * \brief  Enable capture trip combination input
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  tripInput    This parameter can be any value of @ref EPWM_DCAHTRIPSELCONF
  * \param  dcType       This parameter can be any value of @ref EPWM_CAPTUREINPUTTYPE
  */
static inline void EPWM_enableCaptureTripCombinationInput (EPWM_TypeDef *epwm,
                                                           uint16_t tripInput,
                                                           EPWM_CaptureInputType dcType)
{
    SET_BIT(TYPE32(&(epwm->CAPGATETRIPSEL.WORDVAL) + dcType), tripInput);
}

/**
  * \brief  Disable capture trip combination input
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  tripInput    This parameter can be any value of @ref EPWM_DCAHTRIPSELCONF
  * \param  dcType       This parameter can be any value of @ref EPWM_CAPTUREINPUTTYPE
  */
static inline void EPWM_disableCaptureTripCombinationInput (EPWM_TypeDef *epwm,
                                                            uint16_t tripInput,
                                                            EPWM_CaptureInputType dcType)
{
    CLEAR_BIT(TYPE32(&(epwm->CAPGATETRIPSEL.WORDVAL) + dcType), tripInput);
}

/**
  * \brief  This function select event capture signal.
  * \param  epwm             EPWMx pointer to a EPWM_TypeDef structure
  *                            - EPWM1:  EPWM1 module
  *                            - EPWM2:  EPWM2 module
  *                            - EPWM3:  EPWM3 module
  *                            - EPWM4:  EPWM4 module
  *                            - EPWM5:  EPWM5 module
  *                            - EPWM6:  EPWM6 module
  *                            - EPWM7:  EPWM7 module
  *                            - EPWM8:  EPWM8 module
  *                            - EPWM9:  EPWM9 module
  *                            - EPWM10: EPWM10 module
  *                            - EPWM11: EPWM11 module
  *                            - EPWM12: EPWM12 module
  *                            - EPWM13: EPWM13 module
  *                            - EPWM14: EPWM14 module
  *                            - EPWM15: EPWM15 module
  *                            - EPWM16: EPWM16 module
  *                            - EPWM17: EPWM17 module
  *                            - EPWM18: EPWM18 module
  * \param  captripsel       This parameter select CAPGATECOMPSEL or CAPINCOMPSEL
  *                            This parameter can be any value of @ref EPWM_CAPTRIPSEL
  * \param  tripselection    This parameter select trip input signal
  *                           The value is range from 0 to 15, except 12.
  */
 static inline void EPWM_selectEventCaptureSignal (EPWM_TypeDef *epwm,
                                                  uint32_t captripsel,
                                                  uint32_t tripselection)
{
    MODIFY_REG(epwm->CAPTRIPSEL.WORDVAL, captripsel, tripselection);
}

/**
  * \brief  This function sets the trip input to the Digital Compare (DC).
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  tripSource    This parameter is the tripSource
  *                        This parameter can be any value of @ref EPWM_DIGITALCOMPARETRIPINPUT
  * \param  dcType        This parameter is the Digital Compare type
  *                        This parameter can be any value of @ref EPWM_CAPTUREINPUTTYPE
  */
static inline void EPWM_selectCaptureTripInput (EPWM_TypeDef *epwm,
                                                EPWM_DigitalCompareTripInput tripSource,
                                                EPWM_CaptureInputType dcType)
{
    MODIFY_REG(epwm->CAPTRIPSEL.WORDVAL, (0xFU << (dcType << 2U)), (tripSource << (dcType << 2U)));
}

/**
  * \brief  This function enable EPWMxSYNOUT link to its own EPWMxSYNCIN.
  * \param  epwm      EPWMx pointer to a EPWM_TypeDef structure
  *                    - EPWM1:  EPWM1 module
  *                    - EPWM2:  EPWM2 module
  *                    - EPWM3:  EPWM3 module
  *                    - EPWM4:  EPWM4 module
  *                    - EPWM5:  EPWM5 module
  *                    - EPWM6:  EPWM6 module
  *                    - EPWM7:  EPWM7 module
  *                    - EPWM8:  EPWM8 module
  *                    - EPWM9:  EPWM9 module
  *                    - EPWM10: EPWM10 module
  *                    - EPWM11: EPWM11 module
  *                    - EPWM12: EPWM12 module
  *                    - EPWM13: EPWM13 module
  *                    - EPWM14: EPWM14 module
  *                    - EPWM15: EPWM15 module
  *                    - EPWM16: EPWM16 module
  *                    - EPWM17: EPWM17 module
  *                    - EPWM18: EPWM18 module
  */
static inline void EPWM_enableSyncOutPulseToSelf (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->EPWMSYNCINSEL.WORDVAL, EPWM_EPWMSYNCINSEL_SYNCSELF_M);
}

/**
  * \brief  This function disable EPWMxSYNOUT link to its own EPWMxSYNCIN.
  * \param  epwm      EPWMx pointer to a EPWM_TypeDef structure
  *                    - EPWM1:  EPWM1 module
  *                    - EPWM2:  EPWM2 module
  *                    - EPWM3:  EPWM3 module
  *                    - EPWM4:  EPWM4 module
  *                    - EPWM5:  EPWM5 module
  *                    - EPWM6:  EPWM6 module
  *                    - EPWM7:  EPWM7 module
  *                    - EPWM8:  EPWM8 module
  *                    - EPWM9:  EPWM9 module
  *                    - EPWM10: EPWM10 module
  *                    - EPWM11: EPWM11 module
  *                    - EPWM12: EPWM12 module
  *                    - EPWM13: EPWM13 module
  *                    - EPWM14: EPWM14 module
  *                    - EPWM15: EPWM15 module
  *                    - EPWM16: EPWM16 module
  *                    - EPWM17: EPWM17 module
  *                    - EPWM18: EPWM18 module
  */
static inline void EPWM_disableSyncOutPulseToSelf (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->EPWMSYNCINSEL.WORDVAL, EPWM_EPWMSYNCINSEL_SYNCSELF_M);
}

/**
  * \brief  Set up the source for sync-in pulse
  * \note   This function selects the synchronization input pulse source for the EPWM module
  *         by modifying the SEL bit in the EPWMSYNCINSEL register. The input pulse source can be set to
  *         software-generated pulse, sync-in signal from another module, or a combination of both
  * \param  epwm      EPWMx pointer to a EPWM_TypeDef structure
  *                    - EPWM1:  EPWM1 module
  *                    - EPWM2:  EPWM2 module
  *                    - EPWM3:  EPWM3 module
  *                    - EPWM4:  EPWM4 module
  *                    - EPWM5:  EPWM5 module
  *                    - EPWM6:  EPWM6 module
  *                    - EPWM7:  EPWM7 module
  *                    - EPWM8:  EPWM8 module
  *                    - EPWM9:  EPWM9 module
  *                    - EPWM10: EPWM10 module
  *                    - EPWM11: EPWM11 module
  *                    - EPWM12: EPWM12 module
  *                    - EPWM13: EPWM13 module
  *                    - EPWM14: EPWM14 module
  *                    - EPWM15: EPWM15 module
  *                    - EPWM16: EPWM16 module
  *                    - EPWM17: EPWM17 module
  *                    - EPWM18: EPWM18 module
  * \param  source    The synchronization input pulse source
  *                    This parameter can be any value of @ref EPWM_SYNCINPULSESOURCE
  */
static inline void EPWM_setSyncInPulseSource (EPWM_TypeDef *epwm, EPWM_SyncInPulseSource source)
{
    MODIFY_REG(epwm->EPWMSYNCINSEL.WORDVAL, EPWM_EPWMSYNCINSEL_SEL_M, (uint32_t)source & EPWM_EPWMSYNCINSEL_SEL_M);
}

/**
  * \brief  Enables sync-out pulse source
  * \param  epwm      EPWMx pointer to a EPWM_TypeDef structure
  *                    - EPWM1:  EPWM1 module
  *                    - EPWM2:  EPWM2 module
  *                    - EPWM3:  EPWM3 module
  *                    - EPWM4:  EPWM4 module
  *                    - EPWM5:  EPWM5 module
  *                    - EPWM6:  EPWM6 module
  *                    - EPWM7:  EPWM7 module
  *                    - EPWM8:  EPWM8 module
  *                    - EPWM9:  EPWM9 module
  *                    - EPWM10: EPWM10 module
  *                    - EPWM11: EPWM11 module
  *                    - EPWM12: EPWM12 module
  *                    - EPWM13: EPWM13 module
  *                    - EPWM14: EPWM14 module
  *                    - EPWM15: EPWM15 module
  *                    - EPWM16: EPWM16 module
  *                    - EPWM17: EPWM17 module
  *                    - EPWM18: EPWM18 module
  * \param  source    Is the sync-out pulse source
  *                    This parameter can be any value of @ref EPWM_EPWMSYNCOUTENCONF,
  *                    And all parameters can be OR‘d together.
  */
static inline void EPWM_enableSyncOutPulseSource (EPWM_TypeDef *epwm, uint32_t source)
{
    SET_BIT(epwm->EPWMSYNCOUTEN.WORDVAL, source);
}
static inline void EPWM_enableSyncOut2PulseSource (EPWM_TypeDef *epwm, uint32_t source)
{
    SET_BIT(epwm->EPWMSYNCOUTEN2.WORDVAL, source);
}
/**
  * \brief  Disables sync-out pulse source
  * \param  epwm     EPWMx pointer to a EPWM_TypeDef structure
  *                    - EPWM1:  EPWM1 module
  *                    - EPWM2:  EPWM2 module
  *                    - EPWM3:  EPWM3 module
  *                    - EPWM4:  EPWM4 module
  *                    - EPWM5:  EPWM5 module
  *                    - EPWM6:  EPWM6 module
  *                    - EPWM7:  EPWM7 module
  *                    - EPWM8:  EPWM8 module
  *                    - EPWM9:  EPWM9 module
  *                    - EPWM10: EPWM10 module
  *                    - EPWM11: EPWM11 module
  *                    - EPWM12: EPWM12 module
  *                    - EPWM13: EPWM13 module
  *                    - EPWM14: EPWM14 module
  *                    - EPWM15: EPWM15 module
  *                    - EPWM16: EPWM16 module
  *                    - EPWM17: EPWM17 module
  *                    - EPWM18: EPWM18 module
  * \param  source    Is the sync-out pulse source
  *                    This parameter can be any value of @ref EPWM_EPWMSYNCOUTENCONF,
  *                    And all parameters can be OR‘d together.
  */
static inline void EPWM_disableSyncOutPulseSource (EPWM_TypeDef *epwm, uint32_t source)
{
    CLEAR_BIT(epwm->EPWMSYNCOUTEN.WORDVAL, source);
}

/**
  * \brief  Set up the one-shot sync-out trigger source
  * \param  epwm       EPWMx pointer to a EPWM_TypeDef structure
  *                     - EPWM1:  EPWM1 module
  *                     - EPWM2:  EPWM2 module
  *                     - EPWM3:  EPWM3 module
  *                     - EPWM4:  EPWM4 module
  *                     - EPWM5:  EPWM5 module
  *                     - EPWM6:  EPWM6 module
  *                     - EPWM7:  EPWM7 module
  *                     - EPWM8:  EPWM8 module
  *                     - EPWM9:  EPWM9 module
  *                     - EPWM10: EPWM10 module
  *                     - EPWM11: EPWM11 module
  *                     - EPWM12: EPWM12 module
  *                     - EPWM13: EPWM13 module
  *                     - EPWM14: EPWM14 module
  *                     - EPWM15: EPWM15 module
  *                     - EPWM16: EPWM16 module
  *                     - EPWM17: EPWM17 module
  *                     - EPWM18: EPWM18 module
  * \param  trigger    Is the one-shot sync-out signal trigger source
  *                     This parameter can be any value of @ref EPWM_ONESHOTSYNCOUTTRIGGER
  */
static inline void EPWM_setOneShotSyncOutTrigger (EPWM_TypeDef *epwm, EPWM_OneShotSyncOutTrigger trigger)
{
    MODIFY_REG(epwm->TBCTL3.WORDVAL, EPWM_TBCTL3_OSSFRCEN, (uint32_t)trigger);
}

/**
  * \brief  Set the period load mode for the EPWM module
  * \note   This function configures when the EPWM period register (TBPRD) is updated by writing to the PRDLD bit in the TBCTL register
  * \note   It determines whether the period register updates immediately or after a specific event
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  loadMode    Enumerated value specifying the period load mode for the EPWM module
  *                      This parameter can be any value of @ref EPWM_PERIODLOADMODE
  */
static inline void EPWM_setPeriodLoadMode (EPWM_TypeDef *epwm, EPWM_PeriodLoadMode loadMode)
{
    if (loadMode == EPWM_PERIOD_SHADOW_LOAD)
    {
        CLEAR_BIT(epwm->TBCTL.WORDVAL, EPWM_TBCTL_PRDLD_M);
    }
    else
    {
        SET_BIT(epwm->TBCTL.WORDVAL, EPWM_TBCTL_PRDLD_M);
    }
}

/**
  * \brief  Enable phase shift load
  * \note   This function enables the phase shift load by setting the PHSEN bit in the TBCTL register
  * \note   This allows the phase value to be loaded at the start of the next period, which is useful
  *         for applications requiring precise phase control
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enablePhaseShiftLoad (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->TBCTL.WORDVAL, EPWM_TBCTL_PHSEN_M);
}

/**
  * \brief  Disable phase shift load
  * \note   This function disables the phase shift load by clearing the PHSEN bit in the TBCTL register
  * \note   This prevents the phase value from being loaded at the start of the next period, which may be
  *         useful for applications that do not require precise phase control
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disablePhaseShiftLoad (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->TBCTL.WORDVAL, EPWM_TBCTL_PHSEN_M);
}

/**
  * \brief  Set the time base counter mode
  * \param  epwm           EPWMx pointer to a EPWM_TypeDef structure
  *                         - EPWM1:  EPWM1 module
  *                         - EPWM2:  EPWM2 module
  *                         - EPWM3:  EPWM3 module
  *                         - EPWM4:  EPWM4 module
  *                         - EPWM5:  EPWM5 module
  *                         - EPWM6:  EPWM6 module
  *                         - EPWM7:  EPWM7 module
  *                         - EPWM8:  EPWM8 module
  *                         - EPWM9:  EPWM9 module
  *                         - EPWM10: EPWM10 module
  *                         - EPWM11: EPWM11 module
  *                         - EPWM12: EPWM12 module
  *                         - EPWM13: EPWM13 module
  *                         - EPWM14: EPWM14 module
  *                         - EPWM15: EPWM15 module
  *                         - EPWM16: EPWM16 module
  *                         - EPWM17: EPWM17 module
  *                         - EPWM18: EPWM18 module
  * \param  counterMode    Is the time base counter mode
  *                         This parameter can be any value of @ref EPWM_TIMEBASECOUNTMODE
  */
static inline void EPWM_setTimeBaseCounterMode (EPWM_TypeDef *epwm, EPWM_TimeBaseCountMode counterMode)
{
    MODIFY_REG(epwm->TBCTL.WORDVAL, EPWM_TBCTL_CTRMODE_M, (uint32_t)counterMode);
}

/**
  * \brief  Set shadow to active period load on sync mode
  * \param  epwm              EPWMx pointer to a EPWM_TypeDef structure
  *                            - EPWM1:  EPWM1 module
  *                            - EPWM2:  EPWM2 module
  *                            - EPWM3:  EPWM3 module
  *                            - EPWM4:  EPWM4 module
  *                            - EPWM5:  EPWM5 module
  *                            - EPWM6:  EPWM6 module
  *                            - EPWM7:  EPWM7 module
  *                            - EPWM8:  EPWM8 module
  *                            - EPWM9:  EPWM9 module
  *                            - EPWM10: EPWM10 module
  *                            - EPWM11: EPWM11 module
  *                            - EPWM12: EPWM12 module
  *                            - EPWM13: EPWM13 module
  *                            - EPWM14: EPWM14 module
  *                            - EPWM15: EPWM15 module
  *                            - EPWM16: EPWM16 module
  *                            - EPWM17: EPWM17 module
  *                            - EPWM18: EPWM18 module
  * \param  shadowLoadMode    Is the event that triggers the period shadow load
  *                            This parameter can be any value of @ref EPWM_PERIODSHADOWLOADMODE
  */
static inline void EPWM_selectPeriodLoadEvent (EPWM_TypeDef *epwm, EPWM_PeriodShadowLoadMode shadowLoadMode)
{
    MODIFY_REG(epwm->TBCTL2.WORDVAL, EPWM_TBCTL2_PRDLDSYNC_M, (uint32_t)shadowLoadMode << EPWM_TBCTL2_PRDLDSYNC_S);
}

/**
  * \brief  Enable one-shot sync mode
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableOneShotSync (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->TBCTL2.WORDVAL, EPWM_TBCTL2_OSHTSYNCMODE_M);
}

/**
  * \brief  Disable one-shot sync mode
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableOneShotSync (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->TBCTL2.WORDVAL, EPWM_TBCTL2_OSHTSYNCMODE_M);
}

/**
  * \brief  Start one-shot sync
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \note   This function starts one-shot sync
  */
static inline void EPWM_startOneShotSync (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->TBCTL2.WORDVAL, EPWM_TBCTL2_OSHTSYNC_M);
}

/**
  * \brief  Returns time base counter value
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the time base counter value
  */
static inline uint16_t EPWM_getTimeBaseCounterValue (EPWM_TypeDef *epwm)
{
    return (uint16_t)(READ_REG(epwm->TBCTR.WORDVAL));
}

/**
  * \brief  Return time base counter maximum status
  * \note   This function returns the EPWM time base counter overflow event status by reading the CTRMAX bit in the TBSTS register
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the EPWM time base counter overflow event status
  *                  - 0: No event occurred
  *                  - 1: Event occurred
  */
static inline bool EPWM_getTimeBaseCounterOverflowStatus (EPWM_TypeDef *epwm)
{
    return (READ_BIT(epwm->TBSTS.WORDVAL, EPWM_TBSTS_CTRMAX_M) == EPWM_TBSTS_CTRMAX_M) ? 1UL : 0UL;
}

/**
  * \brief  Clear the overflow event flag of EPWM module time reference counter
  * \note   This function clears the EPWM time base counter overflow event by writing a 1 to the CTRMAX bit in the TBSTS register
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_clearTimeBaseCounterOverflowEvent (EPWM_TypeDef *epwm)
{
    WRITE_REG(epwm->TBSTS.WORDVAL, EPWM_TBSTS_CTRMAX_M);
}

/**
  * \brief  Return external sync signal status
  * \note   This function returns the EPWM sync event status by reading the SYNCI bit in the TBSTS register
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the EPWM sync event status.
  *                  - 0: Counter is counting down
  *                  - 1: Counter is counting up
  */
static inline bool EPWM_getSyncStatus (EPWM_TypeDef *epwm)
{
    return (((epwm->TBSTS.WORDVAL & EPWM_TBSTS_SYNCI_M) == EPWM_TBSTS_SYNCI_M) ? 1UL : 0UL);
}

/**
  * \brief  Clear sync signal event
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_clearSyncEvent (EPWM_TypeDef *epwm)
{
    WRITE_REG(epwm->TBSTS.WORDVAL, EPWM_TBSTS_SYNCI_M);
}

/**
  * \brief  Return time base counter direction
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the EPWM time base counter direction
  *                  - 0: Counter is counting down
  *                  - 1: Counter is counting up
  */
static inline uint16_t EPWM_getTimeBaseCounterDirection (EPWM_TypeDef *epwm)
{
    return READ_BIT(epwm->TBSTS.WORDVAL, EPWM_TBSTS_CTRDIR_M);
}

/**
  * \brief  Sets the phase shift offset counter value
  * \note   This function sets the EPWM time base counter phase shift by writing to the TBPHS register
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  phaseCount    Is the EPWM time base counter phase shift
  */
static inline void EPWM_setPhaseShift (EPWM_TypeDef *epwm, uint16_t phaseCount)
{
    MODIFY_REG(epwm->TBPHS.WORDVAL, (uint32_t)EPWM_TBPHS_TBPHS_M, (uint32_t)phaseCount << EPWM_TBPHS_TBPHS_S);
}

/**
 * \brief  Sets the PWM period count
 * \note   This function sets the EPWM time base counter period by writing to the TBPRD register
 * \param  epwm           EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
 * \param  periodCount    Is the EPWM time base counter period.
 */
static inline void EPWM_setTimeBasePeriod (EPWM_TypeDef *epwm, uint16_t periodCount)
{
    WRITE_REG(epwm->TBPRD.WORDVAL, periodCount);
}

/**
  * \brief  Gets the PWM period count
  * \note   This function returns the EPWM time base counter period by reading the TBPRD register
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the EPWM time base counter period
  */
static inline uint16_t EPWM_getTimeBasePeriod (EPWM_TypeDef *epwm)
{
    return (READ_REG(epwm->TBPRD.WORDVAL));
}

/**
  * \brief  Sets the EPWM links
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  epwmLink    Is the ePWM instance to link with
  *                      This parameter can be any value of @ref EPWM_CURRENTLINK
  * \param  linkComp    Is the ePWM component to link
  *                      This parameter can be any value of @ref EPWM_LINKCOMPONENT
  */
static inline void EPWM_setupEPWMLinks (EPWM_TypeDef *epwm, EPWM_CurrentLink epwmLink, EPWM_LinkComponent linkComp)
{
    uint32_t regOffset = ((uint32_t)linkComp & 0xFFF00) >> 8;
    uint32_t link      = ((uint32_t)linkComp & 0xFF);

    MODIFY_REG(TYPE32(&(epwm->EPWMXLINK.WORDVAL) + regOffset), (uint32_t)EPWM_XLINK_TBPRDLINK_M << (uint32_t)link,
               (uint32_t)epwmLink << (uint32_t)link);
}

/**
  * \brief  Sets up the counter compare shadow load mode
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  compModule    Is the Counter Compare value module
  *                        This parameter can be any value of @ref EPWM_COUNTERCOMPAREMODULE
  * \param  loadMode      Is the EPWM time base counter phase shift load component
  *                        This parameter can be any value of @ref EPWM_COUNTERCOMPARELOADMODE
  */
static inline void EPWM_setCounterCompareShadowLoadMode (EPWM_TypeDef *epwm,
                                                         EPWM_CounterCompareModule compModule,
                                                         EPWM_CounterCompareLoadMode loadMode)
{
    uint32_t syncModeOffset;
    uint32_t loadModeOffset;
    uint32_t shadowModeOffset;
    uint32_t registerOffset;

    if((compModule == EPWM_COUNTER_COMPARE_A) || (compModule == EPWM_COUNTER_COMPARE_C))
    {
        syncModeOffset = 10U;
        loadModeOffset = 0U;
        shadowModeOffset = 4U;
    }
    else
    {
        syncModeOffset = 12U;
        loadModeOffset = 2U;
        shadowModeOffset = 6U;
    }

    registerOffset = ((uint32_t)&epwm->CMPCTL.WORDVAL + ((uint32_t)compModule & 0x4));

    MODIFY_REG(TYPE32(registerOffset),
               ((0x3U << syncModeOffset) | (0x3U << loadModeOffset) | (0x1U << shadowModeOffset)),
               ((((uint32_t)loadMode >> 0x2U) << syncModeOffset) | (((uint32_t)loadMode &  0x3U) << loadModeOffset)));
}

/**
  * \brief  Disable the shadow loading mode of the counter comparator
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  compModule    Is the Counter Compare value module
  *                        This parameter can be any value of @ref EPWM_COUNTERCOMPAREMODULE
  */
static inline void EPWM_disableCounterCompareShadowLoadMode (EPWM_TypeDef *epwm, EPWM_CounterCompareModule compModule)
{
    uint32_t shadowModeOffset;
    uint32_t registerOffset;

    if((compModule == EPWM_COUNTER_COMPARE_A) || (compModule == EPWM_COUNTER_COMPARE_C))
    {
        shadowModeOffset = 4U;
    }
    else
    {
        shadowModeOffset = 6U;
    }

    registerOffset = ((uint32_t)&epwm->CMPCTL.WORDVAL + ((uint32_t)compModule & 0x4));

    SET_BIT(TYPE32(registerOffset), (0x1U << shadowModeOffset));
}

/**
  * \brief  Set counter compare values
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  compModule    Is the Counter Compare value module
  *                        This parameter can be any value of @ref EPWM_COUNTERCOMPAREMODULE
  * \param  compCount     Is the counter compare count value
  */
static inline void EPWM_setCounterCompareValue (EPWM_TypeDef *epwm, EPWM_CounterCompareModule compModule, uint16_t compCount)
{
    uint32_t registerOffset = (uint32_t)&epwm->CMPA.WORDVAL + ((uint32_t)compModule << 2U);
    if((compModule == EPWM_COUNTER_COMPARE_A) || (compModule == EPWM_COUNTER_COMPARE_B))
    {
        MODIFY_REG(TYPE32(registerOffset), EPWM_CMPA_CMPA_M, (uint32_t)(compCount) << EPWM_CMPA_CMPA_S);
    }
    else
    {
        MODIFY_REG(TYPE32(registerOffset), EPWM_CMPC_CMPC_M, (uint32_t)compCount);
    }
}

/**
  * \brief  Get counter compare values
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  compModule    Is the Counter Compare value module
  *                        This parameter can be any value of @ref EPWM_COUNTERCOMPAREMODULE
  * \return Returns the counter compare count value
  */
static inline uint16_t EPWM_getCounterCompareValue (EPWM_TypeDef *epwm, EPWM_CounterCompareModule compModule)
{
    uint16_t compCount;
    uint32_t registerOffset = (uint32_t)&epwm->CMPA.WORDVAL + ((uint32_t)compModule << 2U);
    if((compModule == EPWM_COUNTER_COMPARE_A) || (compModule == EPWM_COUNTER_COMPARE_B))
    {
        compCount = (uint16_t)(READ_BIT(TYPE32(registerOffset), EPWM_CMPA_CMPA_M) >> EPWM_CMPA_CMPA_S);
    }
    else
    {
        compCount = (uint16_t)(READ_BIT(TYPE32(registerOffset), EPWM_CMPC_CMPC_M) >> EPWM_CMPC_CMPC_S);
    }
    return (compCount);
}

/**
  * \brief  Return the counter compare shadow register full status
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  compModule    The Counter Compare value module
  *                        This parameter can be any value of @ref EPWM_COUNTERCOMPAREMODULE
  * \return               Returns the counter compare shadow status
  *                        - 1 : the shadow register is full
  *                        - 0 : the shadow register is not full
  */
static inline uint32_t EPWM_getCounterCompareShadowStatus (EPWM_TypeDef *epwm, EPWM_CounterCompareModule compModule)
{
    uint32_t shadowFullOffset = ((((uint32_t)compModule >> 1U) & 0x1U) + 8U);
    uint32_t registerOffset = (uint32_t)&epwm->CMPCTL.WORDVAL + ((uint32_t)compModule & 0x4U);

    return (((READ_REG(TYPE32(registerOffset)) >> shadowFullOffset) & 0x1U) == 0x1U) ? 1U : 0U;
}

/**
  * \brief  Sets the action qualifier shadow load mode
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  aqModule    Is the Action Qualifier module value
  *                      This parameter can be any value of @ref EPWM_ACTIONQUALIFIERMODULE
  * \param  loadMode    Is the EPWM time base counter phase shift load mode
  *                      This parameter can be any value of @ref EPWM_ACTIONQUALIFIERLOADMODE
  */
static inline void EPWM_setActionQualifierShadowLoadMode (EPWM_TypeDef *epwm,
                                                          EPWM_ActionQualifierModule aqModule,
                                                          EPWM_ActionQualifierLoadMode loadMode)
{
    uint32_t aqModeOffset     = (uint32_t)aqModule << 1U;
    uint32_t shadowModeOffset = 8U + (uint32_t)aqModule;
    uint32_t syncModeOffset   = 12U + aqModeOffset;

    /* Set the appropriate sync and load mode bits and also enable shadow
       load mode. Shadow to active load can also be frozen. */
    MODIFY_REG(epwm->AQCTL.WORDVAL, (0x3U << aqModeOffset) | (0x3U << syncModeOffset),
               (0x1U << shadowModeOffset) |
               (((uint32_t)loadMode >> 0x2U) << syncModeOffset) |
               (((uint32_t)loadMode &  0x3U) << (uint32_t)aqModeOffset));
}

/**
  * \brief  Disable action qualifier shadow load mode
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  aqModule    EPWM time base counter phase shift load mode
  *                      This parameter can be any value of @ref EPWM_ACTIONQUALIFIERMODULE
  */
static inline void EPWM_disableActionQualifierShadowLoadMode (EPWM_TypeDef *epwm, EPWM_ActionQualifierModule aqModule)
{
    uint32_t shadowModeOffset = 8U + (uint32_t)aqModule;
    CLEAR_BIT(epwm->AQCTL.WORDVAL, (1U << shadowModeOffset));
}

/**
  * \brief  Set up action qualifier trigger source for event T1
  * \param  epwm       EPWMx pointer to a EPWM_TypeDef structure
  *                     - EPWM1:  EPWM1 module
  *                     - EPWM2:  EPWM2 module
  *                     - EPWM3:  EPWM3 module
  *                     - EPWM4:  EPWM4 module
  *                     - EPWM5:  EPWM5 module
  *                     - EPWM6:  EPWM6 module
  *                     - EPWM7:  EPWM7 module
  *                     - EPWM8:  EPWM8 module
  *                     - EPWM9:  EPWM9 module
  *                     - EPWM10: EPWM10 module
  *                     - EPWM11: EPWM11 module
  *                     - EPWM12: EPWM12 module
  *                     - EPWM13: EPWM13 module
  *                     - EPWM14: EPWM14 module
  *                     - EPWM15: EPWM15 module
  *                     - EPWM16: EPWM16 module
  *                     - EPWM17: EPWM17 module
  *                     - EPWM18: EPWM18 module
  * \param  trigger    Is sources for Action Qualifier triggers
  *                     This parameter can be any value of @ref EPWM_ACTIONQUALIFIERTRIGGERSOURCE
  */
static inline void EPWM_setActionQualifierT1TriggerSource (EPWM_TypeDef *epwm, EPWM_ActionQualifierTriggerSource trigger)
{
    MODIFY_REG(epwm->AQTSRCSEL.WORDVAL, EPWM_AQTSRCSEL_T1SEL_M, (uint32_t)trigger & EPWM_AQTSRCSEL_T1SEL_M);
}

/**
  * \brief  Set up action qualifier trigger source for event T2
  * \param  epwm       EPWMx pointer to a EPWM_TypeDef structure
  *                     - EPWM1:  EPWM1 module
  *                     - EPWM2:  EPWM2 module
  *                     - EPWM3:  EPWM3 module
  *                     - EPWM4:  EPWM4 module
  *                     - EPWM5:  EPWM5 module
  *                     - EPWM6:  EPWM6 module
  *                     - EPWM7:  EPWM7 module
  *                     - EPWM8:  EPWM8 module
  *                     - EPWM9:  EPWM9 module
  *                     - EPWM10: EPWM10 module
  *                     - EPWM11: EPWM11 module
  *                     - EPWM12: EPWM12 module
  *                     - EPWM13: EPWM13 module
  *                     - EPWM14: EPWM14 module
  *                     - EPWM15: EPWM15 module
  *                     - EPWM16: EPWM16 module
  *                     - EPWM17: EPWM17 module
  *                     - EPWM18: EPWM18 module
  * \param  trigger    Is sources for Action Qualifier triggers
  *                     This parameter can be any value of @ref EPWM_ACTIONQUALIFIERTRIGGERSOURCE
  */
static inline void EPWM_setActionQualifierT2TriggerSource (EPWM_TypeDef *epwm, EPWM_ActionQualifierTriggerSource trigger)
{
    MODIFY_REG(epwm->AQTSRCSEL.WORDVAL, EPWM_AQTSRCSEL_T2SEL_M, (uint32_t)trigger << EPWM_AQTSRCSEL_T2SEL_S);
}

/**
  * \brief  Set the output behavior of the action qualifier of the EPWM module
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  epwmOutput    Is output actions for Action Qualifier triggers
  *                        This parameter can be any value of @ref EPWM_ACTIONQUALIFIEROUTPUTMODULE
  * \param  output        Is output actions for Action Qualifier triggers
  *                        This parameter can be any value of @ref EPWM_ACTIONQUALIFIEROUTPUT
  * \param  event         Is output actions for Action Qualifier triggers
  *                        This parameter can be any value of @ref EPWM_ACTIONQUALIFIEROUTPUTEVENT
  */
static inline void EPWM_setActionQualifierAction (EPWM_TypeDef *epwm,
                                                  EPWM_ActionQualifierOutputModule epwmOutput,
                                                  EPWM_ActionQualifierOutput output,
                                                  EPWM_ActionQualifierOutputEvent event)
{
    if (((uint32_t)event & 0x1U) == 0x1U)
    {
        uint32_t shift_amount = ((uint32_t)event - 1U) % 32U;
        MODIFY_REG(TYPE32(&(epwm->AQCTLA2.WORDVAL) + epwmOutput),
                   3U << shift_amount,
                   (uint32_t)output << shift_amount);
    }
    else
    {
        MODIFY_REG(TYPE32(&(epwm->AQCTLA.WORDVAL) + epwmOutput),
                   3U << ((uint32_t)event),
                   (uint32_t)output << ((uint32_t)event));
    }
}

/**
  * \brief  Set up action qualifier event outputs
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  epwmOutput    Is output actions for Action Qualifier triggers.
  *                        This parameter can be any value of @ref EPWM_ACTIONQUALIFIEROUTPUTMODULE
  * \param  action        Is output actions for Action Qualifier triggers.
  *                        This parameter can be any value of @ref EPWM_ACTIONQUALIFIEREVENTACTION
  */
static inline void EPWM_setActionQualifierActionComplete (EPWM_TypeDef *epwm,
                                                          EPWM_ActionQualifierOutputModule epwmOutput,
                                                          uint32_t action)
{
    WRITE_REG(TYPE32(&(epwm->AQCTLA.WORDVAL) + epwmOutput), action);
}

/**
  *  \brief  Set the enhanced PWM additional action limiter to complete the action
  *  \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                         - EPWM1:  EPWM1 module
  *                         - EPWM2:  EPWM2 module
  *                         - EPWM3:  EPWM3 module
  *                         - EPWM4:  EPWM4 module
  *                         - EPWM5:  EPWM5 module
  *                         - EPWM6:  EPWM6 module
  *                         - EPWM7:  EPWM7 module
  *                         - EPWM8:  EPWM8 module
  *                         - EPWM9:  EPWM9 module
  *                         - EPWM10: EPWM10 module
  *                         - EPWM11: EPWM11 module
  *                         - EPWM12: EPWM12 module
  *                         - EPWM13: EPWM13 module
  *                         - EPWM14: EPWM14 module
  *                         - EPWM15: EPWM15 module
  *                         - EPWM16: EPWM16 module
  *                         - EPWM17: EPWM17 module
  *                         - EPWM18: EPWM18 module
  *  \param  epwmOutput    Is the output module for Action Qualifier trigger
  *                         This parameter can be any value of @ref EPWM_ACTIONQUALIFIEROUTPUTMODULE
  *  \param  action        Is the action to be taken on the output pin.
  *                         This parameter can be any value of @ref EPWM_ADDITIONALACTIONQUALIFIEREVENTACTION
  */
static inline void EPWM_setAdditionalActionQualifierActionComplete (EPWM_TypeDef *epwm,
                                                                    EPWM_ActionQualifierOutputModule epwmOutput,
                                                                    uint16_t action)
{
    WRITE_REG(TYPE32(&(epwm->AQCTLA2.WORDVAL) + epwmOutput), action);
}

/**
  *  \brief  Set Action Qualifier Continuous Software Force Shadow Mode
  *  \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                   - EPWM1:  EPWM1 module
  *                   - EPWM2:  EPWM2 module
  *                   - EPWM3:  EPWM3 module
  *                   - EPWM4:  EPWM4 module
  *                   - EPWM5:  EPWM5 module
  *                   - EPWM6:  EPWM6 module
  *                   - EPWM7:  EPWM7 module
  *                   - EPWM8:  EPWM8 module
  *                   - EPWM9:  EPWM9 module
  *                   - EPWM10: EPWM10 module
  *                   - EPWM11: EPWM11 module
  *                   - EPWM12: EPWM12 module
  *                   - EPWM13: EPWM13 module
  *                   - EPWM14: EPWM14 module
  *                   - EPWM15: EPWM15 module
  *                   - EPWM16: EPWM16 module
  *                   - EPWM17: EPWM17 module
  *                   - EPWM18: EPWM18 module
  *  \param  mode    Is the action qualifier shadow load mode
  *                   This parameter can be any value of @ref EPWM_ACTIONQUALIFIERCONTFORCE
  */
static inline void EPWM_setActionQualifierContSWForceShadowMode (EPWM_TypeDef *epwm, EPWM_ActionQualifierContForce mode)
{
    MODIFY_REG(epwm->AQSFRC.WORDVAL, EPWM_AQSFRC_RLDCSF_M, (uint32_t)mode << EPWM_AQSFRC_RLDCSF_S);
}

/**
  *  \brief  Triggers a continuous software forced event
  *  \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                         - EPWM1:  EPWM1 module
  *                         - EPWM2:  EPWM2 module
  *                         - EPWM3:  EPWM3 module
  *                         - EPWM4:  EPWM4 module
  *                         - EPWM5:  EPWM5 module
  *                         - EPWM6:  EPWM6 module
  *                         - EPWM7:  EPWM7 module
  *                         - EPWM8:  EPWM8 module
  *                         - EPWM9:  EPWM9 module
  *                         - EPWM10: EPWM10 module
  *                         - EPWM11: EPWM11 module
  *                         - EPWM12: EPWM12 module
  *                         - EPWM13: EPWM13 module
  *                         - EPWM14: EPWM14 module
  *                         - EPWM15: EPWM15 module
  *                         - EPWM16: EPWM16 module
  *                         - EPWM17: EPWM17 module
  *                         - EPWM18: EPWM18 module
  *  \param  epwmOutput    Is the action qualifier output module
  *                         This parameter can be any value of @ref EPWM_ActionQualifierOutputModule
  *  \param  output        Is the action qualifier output
  *                         This parameter can be any value of @ref EPWM_ACTIONQUALIFIERSWOUTPUT
  */
static inline void EPWM_setActionQualifierContSWForceAction (EPWM_TypeDef *epwm,
                                                             EPWM_ActionQualifierOutputModule epwmOutput,
                                                             EPWM_ActionQualifierSWOutput output)
{
    MODIFY_REG(epwm->AQCSFRC.WORDVAL,
               EPWM_AQCSFRC_CSFX << (uint32_t)epwmOutput,
               (uint32_t)output << (uint32_t)epwmOutput);
}

/**
  * \brief   Set Action Qualifier Software Action
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  epwmOutput    Is the action qualifier output module
  *                        This parameter can be any value of @ref EPWM_ActionQualifierOutputModule
  * \param  output        Is the action qualifier output
  *                        This parameter can be any value of @ref EPWM_ACTIONQUALIFIEROUTPUT
  */
static inline void EPWM_setActionQualifierSWAction (EPWM_TypeDef *epwm,
                                                    EPWM_ActionQualifierOutputModule epwmOutput,
                                                    EPWM_ActionQualifierOutput output)
{
    if(epwmOutput == EPWM_AQ_OUTPUT_A)
    {
        MODIFY_REG(epwm->AQSFRC.WORDVAL, EPWM_AQSFRC_ACTSFX, output);
    }
    else
    {
        MODIFY_REG(epwm->AQSFRC.WORDVAL, (EPWM_AQSFRC_ACTSFX << 3), (output << 3));
    }
}

/**
  * \brief  Force Action Qualifier Software Action
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  epwmOutput    Is the action qualifier output module.
  *                        This parameter can be any value of @ref EPWM_ActionQualifierOutputModule
  */
static inline void EPWM_forceActionQualifierSWAction (EPWM_TypeDef *epwm, EPWM_ActionQualifierOutputModule epwmOutput)
{
    SET_BIT(epwm->AQSFRC.WORDVAL, EPWM_AQSFRC_OTSFX << (((uint32_t)epwmOutput >> 1U) * 3U + 2U));
}

/**
  * \brief  Sets Dead Band signal output swap mode
  * \param  epwm              EPWMx pointer to a EPWM_TypeDef structure
  *                            - EPWM1:  EPWM1 module
  *                            - EPWM2:  EPWM2 module
  *                            - EPWM3:  EPWM3 module
  *                            - EPWM4:  EPWM4 module
  *                            - EPWM5:  EPWM5 module
  *                            - EPWM6:  EPWM6 module
  *                            - EPWM7:  EPWM7 module
  *                            - EPWM8:  EPWM8 module
  *                            - EPWM9:  EPWM9 module
  *                            - EPWM10: EPWM10 module
  *                            - EPWM11: EPWM11 module
  *                            - EPWM12: EPWM12 module
  *                            - EPWM13: EPWM13 module
  *                            - EPWM14: EPWM14 module
  *                            - EPWM15: EPWM15 module
  *                            - EPWM16: EPWM16 module
  *                            - EPWM17: EPWM17 module
  *                            - EPWM18: EPWM18 module
  * \param  output            Is the action qualifier output
  *                            This parameter can be any value of @ref EPWM_DEADBANDOUTPUT
  * \param  enableSwapMode    Is the action qualifier output
  *                            - true     - Enable output swap mode
  *                            - false    - Disable output swap mode
  */
static inline void EPWM_setDeadBandOutputSwapMode (EPWM_TypeDef *epwm, EPWM_DeadBandOutput output, bool enableSwapMode)
{
    uint16_t mask;
    mask = (uint16_t)1U << ((uint16_t)output + EPWM_DBCTL_OUTSWAP_S);
    if (enableSwapMode)
    {
        SET_BIT(epwm->DBCTL.WORDVAL, mask);
    }
    else
    {
        CLEAR_BIT(epwm->DBCTL.WORDVAL, mask);
    }
}

/**
  * \brief  Set Dead Band Delay Mode
  * \param  epwm               EPWMx pointer to a EPWM_TypeDef structure
  *                             - EPWM1:  EPWM1 module
  *                             - EPWM2:  EPWM2 module
  *                             - EPWM3:  EPWM3 module
  *                             - EPWM4:  EPWM4 module
  *                             - EPWM5:  EPWM5 module
  *                             - EPWM6:  EPWM6 module
  *                             - EPWM7:  EPWM7 module
  *                             - EPWM8:  EPWM8 module
  *                             - EPWM9:  EPWM9 module
  *                             - EPWM10: EPWM10 module
  *                             - EPWM11: EPWM11 module
  *                             - EPWM12: EPWM12 module
  *                             - EPWM13: EPWM13 module
  *                             - EPWM14: EPWM14 module
  *                             - EPWM15: EPWM15 module
  *                             - EPWM16: EPWM16 module
  *                             - EPWM17: EPWM17 module
  *                             - EPWM18: EPWM18 module
  * \param  delayMode          Is the action qualifier output delay mode
  *                             This parameter can be any value of @ref EPWM_DEADBANDDELAYMODE
  * \param  enableDelayMode    Is the action qualifier output delay mode
  *                             - true     - Enable delay mode
  *                             - false    - Disable delay mode
  */
static inline void EPWM_setDeadBandDelayMode (EPWM_TypeDef *epwm, EPWM_DeadBandDelayMode delayMode, bool enableDelayMode)
{
    uint16_t mask;
    mask = (uint16_t)1U << ((uint16_t)delayMode + EPWM_DBCTL_OUT_MODE_S);
    if (enableDelayMode)
    {
        SET_BIT(epwm->DBCTL.WORDVAL, mask);
    }
    else
    {
        CLEAR_BIT(epwm->DBCTL.WORDVAL, mask);
    }
}

/**
  * \brief  Sets Dead Band delay polarity
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                       - EPWM1:  EPWM1 module
  *                       - EPWM2:  EPWM2 module
  *                       - EPWM3:  EPWM3 module
  *                       - EPWM4:  EPWM4 module
  *                       - EPWM5:  EPWM5 module
  *                       - EPWM6:  EPWM6 module
  *                       - EPWM7:  EPWM7 module
  *                       - EPWM8:  EPWM8 module
  *                       - EPWM9:  EPWM9 module
  *                       - EPWM10: EPWM10 module
  *                       - EPWM11: EPWM11 module
  *                       - EPWM12: EPWM12 module
  *                       - EPWM13: EPWM13 module
  *                       - EPWM14: EPWM14 module
  *                       - EPWM15: EPWM15 module
  *                       - EPWM16: EPWM16 module
  *                       - EPWM17: EPWM17 module
  *                       - EPWM18: EPWM18 module
  * \param  delayMode    Is the action qualifier output delay mode
  *                       This parameter can be any value of @ref EPWM_DEADBANDDELAYMODE
  * \param  polarity     Is the action qualifier output delay mode
  *                       This parameter can be any value of @ref EPWM_DEADBANDPOLARITY
  */
static inline void EPWM_setDeadBandDelayPolarity (EPWM_TypeDef *epwm, EPWM_DeadBandDelayMode delayMode, EPWM_DeadBandPolarity polarity)
{
    uint8_t shift;
    shift = (uint16_t)((delayMode ^ 0x1U) + 2);
    MODIFY_REG(epwm->DBCTL.WORDVAL, 1U << shift, (uint32_t)polarity << shift);
}

/**
  * \brief  Sets rising edge Dead Band delay input
  * \param  epwm     EPWMx pointer to a EPWM_TypeDef structure
  *                   - EPWM1:  EPWM1 module
  *                   - EPWM2:  EPWM2 module
  *                   - EPWM3:  EPWM3 module
  *                   - EPWM4:  EPWM4 module
  *                   - EPWM5:  EPWM5 module
  *                   - EPWM6:  EPWM6 module
  *                   - EPWM7:  EPWM7 module
  *                   - EPWM8:  EPWM8 module
  *                   - EPWM9:  EPWM9 module
  *                   - EPWM10: EPWM10 module
  *                   - EPWM11: EPWM11 module
  *                   - EPWM12: EPWM12 module
  *                   - EPWM13: EPWM13 module
  *                   - EPWM14: EPWM14 module
  *                   - EPWM15: EPWM15 module
  *                   - EPWM16: EPWM16 module
  *                   - EPWM17: EPWM17 module
  *                   - EPWM18: EPWM18 module
  * \param  input    Is the action qualifier output delay mode
  *                   This parameter can be any value of @ref EPWM_DEADBANDINPUT
  */
static inline void EPWM_setRisingEdgeDeadBandDelayInput (EPWM_TypeDef *epwm, uint16_t input)
{
    MODIFY_REG(epwm->DBCTL.WORDVAL, 1U << EPWM_DBCTL_IN_MODE_S, input << EPWM_DBCTL_IN_MODE_S);
}

/**
  * \brief  Sets falling edge Dead Band delay input
  * \param  epwm     EPWMx pointer to a EPWM_TypeDef structure
  *                   - EPWM1:  EPWM1 module
  *                   - EPWM2:  EPWM2 module
  *                   - EPWM3:  EPWM3 module
  *                   - EPWM4:  EPWM4 module
  *                   - EPWM5:  EPWM5 module
  *                   - EPWM6:  EPWM6 module
  *                   - EPWM7:  EPWM7 module
  *                   - EPWM8:  EPWM8 module
  *                   - EPWM9:  EPWM9 module
  *                   - EPWM10: EPWM10 module
  *                   - EPWM11: EPWM11 module
  *                   - EPWM12: EPWM12 module
  *                   - EPWM13: EPWM13 module
  *                   - EPWM14: EPWM14 module
  *                   - EPWM15: EPWM15 module
  *                   - EPWM16: EPWM16 module
  *                   - EPWM17: EPWM17 module
  *                   - EPWM18: EPWM18 module
  * \param  input    Is the action qualifier output delay mode.
  *                   This parameter can be any value of @ref EPWM_DEADBANDINPUT
  */
static inline void EPWM_setFallingEdgeDeadBandDelayInput (EPWM_TypeDef *epwm, uint16_t input)
{
    if (input == EPWM_DB_INPUT_DB_RED)
    {
        SET_BIT(epwm->DBCTL.WORDVAL, EPWM_DBCTL_DEDB_MODE);
    }
    else
    {
        CLEAR_BIT(epwm->DBCTL.WORDVAL, EPWM_DBCTL_DEDB_MODE);
        MODIFY_REG(epwm->DBCTL.WORDVAL, 1U << (EPWM_DBCTL_IN_MODE_S + 1U), input << (EPWM_DBCTL_IN_MODE_S + 1U));
    }
}

/**
  * \brief  Set the Dead Band control shadow load mode
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  loadMode    Is the action qualifier output delay mode.
  *                      This parameter can be any value of @ref EPWM_DEADBANDCONTROLLOADMODE
  */
static inline void EPWM_setDeadBandControlShadowLoadMode (EPWM_TypeDef *epwm, EPWM_DeadBandControlLoadMode loadMode)
{
    MODIFY_REG(epwm->DBCTL2.WORDVAL, EPWM_DBCTL2_LOADDBCTLMODE_M, EPWM_DBCTL2_SHDWDBCTLMODE | (uint32_t)loadMode);
}

/**
  * \brief  Disable Dead Band control shadow load mode
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableDeadBandControlShadowLoadMode (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->DBCTL2.WORDVAL, EPWM_DBCTL2_SHDWDBCTLMODE);
}

/**
  * \brief  Set the RED (Rising Edge Delay) count shadow load mode
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  loadMode    Is the action qualifier output delay mode
  *                      This parameter can be any value of @ref EPWM_RISINGEDGEDELAYLOADMODE
  */
static inline void EPWM_setRisingEdgeDelayCountShadowLoadMode (EPWM_TypeDef *epwm, EPWM_RisingEdgeDelayLoadMode loadMode)
{
    MODIFY_REG(epwm->DBCTL.WORDVAL, EPWM_DBCTL_LOADREDMODE_M,
               (uint32_t)EPWM_DBCTL_SHDWDBREDMODE | (uint32_t)loadMode << EPWM_DBCTL_LOADREDMODE_S);
}

/**
  * \brief  Disable the RED (Rising Edge Delay) count shadow load mode
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableRisingEdgeDelayCountShadowLoadMode (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->DBCTL.WORDVAL, EPWM_DBCTL_SHDWDBREDMODE);
}

/**
  * \brief  Set the FED (Falling Edge Delay) count shadow load mode
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  loadMode    Is the action qualifier output delay mode
  *                      This parameter can be any value of @ref EPWM_FALLINGEDGEDELAYLOADMODE
  */
static inline void EPWM_setFallingEdgeDelayCountShadowLoadMode (EPWM_TypeDef *epwm, EPWM_FallingEdgeDelayLoadMode loadMode)
{
    MODIFY_REG(epwm->DBCTL.WORDVAL, EPWM_DBCTL_LOADFEDMODE_M,
               (uint32_t)EPWM_DBCTL_SHDWDBFEDMODE | (uint32_t)loadMode << EPWM_DBCTL_LOADFEDMODE_S);
}

/**
  * \brief  Disables the FED (Falling Edge Delay) count shadow load mode
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableFallingEdgeDelayCountShadowLoadMode (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->DBCTL.WORDVAL, EPWM_DBCTL_SHDWDBFEDMODE);
}

/**
  * \brief Set Rising Edge Delay Count
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  redCount    Is the RED (Rising Edge Delay) count
  */
static inline void EPWM_setRisingEdgeDelayCount (EPWM_TypeDef *epwm, uint16_t redCount)
{
  WRITE_REG(epwm->DBRED.WORDVAL, redCount);
}

/**
  * \brief  Set Falling Edge Delay Count
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  fedCount    Is the FED (Falling Edge Delay) count
  */
static inline void EPWM_setFallingEdgeDelayCount (EPWM_TypeDef *epwm, uint16_t fedCount)
{
    WRITE_REG(epwm->DBFED.WORDVAL, fedCount);
}

/**
  * \brief  Enable chopper mode
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableChopper (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->PCCTL.WORDVAL, EPWM_PCCTL_CHPEN);
}

/**
  * \brief  Disable chopper mode
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableChopper (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->PCCTL.WORDVAL, EPWM_PCCTL_CHPEN);
}

/**
  * \brief  Set chopper duty cycle
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                       - EPWM1:  EPWM1 module
  *                       - EPWM2:  EPWM2 module
  *                       - EPWM3:  EPWM3 module
  *                       - EPWM4:  EPWM4 module
  *                       - EPWM5:  EPWM5 module
  *                       - EPWM6:  EPWM6 module
  *                       - EPWM7:  EPWM7 module
  *                       - EPWM8:  EPWM8 module
  *                       - EPWM9:  EPWM9 module
  *                       - EPWM10: EPWM10 module
  *                       - EPWM11: EPWM11 module
  *                       - EPWM12: EPWM12 module
  *                       - EPWM13: EPWM13 module
  *                       - EPWM14: EPWM14 module
  *                       - EPWM15: EPWM15 module
  *                       - EPWM16: EPWM16 module
  *                       - EPWM17: EPWM17 module
  *                       - EPWM18: EPWM18 module
  * \param  dutyCycle    Is the chopping clock duty cycle count
  */
static inline void EPWM_setChopperDutyCycle (EPWM_TypeDef *epwm, uint16_t dutyCycleCount)
{
    MODIFY_REG(epwm->PCCTL.WORDVAL, EPWM_PCCTL_CHPDUTY_M, dutyCycleCount << EPWM_PCCTL_CHPDUTY_S);
}

/**
  * \brief  Set chopper clock frequency scaler
  * \param  epwm       EPWMx pointer to a EPWM_TypeDef structure
  *                     - EPWM1:  EPWM1 module
  *                     - EPWM2:  EPWM2 module
  *                     - EPWM3:  EPWM3 module
  *                     - EPWM4:  EPWM4 module
  *                     - EPWM5:  EPWM5 module
  *                     - EPWM6:  EPWM6 module
  *                     - EPWM7:  EPWM7 module
  *                     - EPWM8:  EPWM8 module
  *                     - EPWM9:  EPWM9 module
  *                     - EPWM10: EPWM10 module
  *                     - EPWM11: EPWM11 module
  *                     - EPWM12: EPWM12 module
  *                     - EPWM13: EPWM13 module
  *                     - EPWM14: EPWM14 module
  *                     - EPWM15: EPWM15 module
  *                     - EPWM16: EPWM16 module
  *                     - EPWM17: EPWM17 module
  *                     - EPWM18: EPWM18 module
  * \param  freqDiv    Is the chopping clock frequency divider count
  */
static inline void EPWM_setChopperFreq (EPWM_TypeDef *epwm, uint16_t freqDiv)
{
    MODIFY_REG(epwm->PCCTL.WORDVAL, (uint16_t) EPWM_PCCTL_CHPFREQ_M, freqDiv << EPWM_PCCTL_CHPFREQ_S);
}

/**
  * \brief  Set Chopper First Pulse Width
  * \param  epwm               EPWMx pointer to a EPWM_TypeDef structure
  *                             - EPWM1:  EPWM1 module
  *                             - EPWM2:  EPWM2 module
  *                             - EPWM3:  EPWM3 module
  *                             - EPWM4:  EPWM4 module
  *                             - EPWM5:  EPWM5 module
  *                             - EPWM6:  EPWM6 module
  *                             - EPWM7:  EPWM7 module
  *                             - EPWM8:  EPWM8 module
  *                             - EPWM9:  EPWM9 module
  *                             - EPWM10: EPWM10 module
  *                             - EPWM11: EPWM11 module
  *                             - EPWM12: EPWM12 module
  *                             - EPWM13: EPWM13 module
  *                             - EPWM14: EPWM14 module
  *                             - EPWM15: EPWM15 module
  *                             - EPWM16: EPWM16 module
  *                             - EPWM17: EPWM17 module
  *                             - EPWM18: EPWM18 module
  * \param  firstPulseWidth    Is the width of the first pulse
  */
static inline void EPWM_setChopperFirstPulseWidth (EPWM_TypeDef *epwm, uint16_t firstPulseWidth)
{
    MODIFY_REG(epwm->PCCTL.WORDVAL, EPWM_PCCTL_OSHTWTH_M, firstPulseWidth << EPWM_PCCTL_OSHTWTH_S);
}

/**
  * \brief  Enable Trip Zone signal
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  tzSignal    Is the trip zone signal
  *                      This parameter can be any value of @ref EPWM_TZSELCONF
  */
static inline void EPWM_enableTripZoneSignals (EPWM_TypeDef *epwm, uint32_t tzSignal)
{
    SET_BIT(epwm->TZSEL.WORDVAL, tzSignal);
}

/**
  * \brief  Disable Trip Zone signal
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  tzSignal    Is the trip zone signal
  *                      This parameter can be any value of @ref EPWM_TZSELCONF
  */
static inline void EPWM_disableTripZoneSignals (EPWM_TypeDef *epwm, uint32_t tzSignal)
{
    CLEAR_BIT(epwm->TZSEL.WORDVAL, tzSignal);
}

/**
  * \brief  This function enables the Trip Zone signals specified by tzSignal as a
  *         source for the Trip Zone module.
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  tzSignal    Is the trip zone signal
  *                      This parameter can be any value of @ref EPWM_TZSEL2CONF
  */
static inline void EPWM_enableTripZone2Signals (EPWM_TypeDef *epwm, uint32_t tzSignal)
{
    SET_BIT(epwm->TZSEL2.WORDVAL, tzSignal);
}

/**
  * \brief  This function disables the Trip Zone signals specified by tzSignal as a
  *         source for the Trip Zone module.
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  tzSignal    Is the trip zone signal
  *                      This parameter can be any value of @ref EPWM_TZSEL2CONF
  */
static inline void EPWM_disableTripZone2Signals (EPWM_TypeDef *epwm, uint32_t tzSignal)
{
    CLEAR_BIT(epwm->TZSEL2.WORDVAL, tzSignal);
}

/**
  * \brief  Set Trip Zone Digital Compare Event Condition
  * \param  epwm       EPWMx pointer to a EPWM_TypeDef structure
  *                     - EPWM1:  EPWM1 module
  *                     - EPWM2:  EPWM2 module
  *                     - EPWM3:  EPWM3 module
  *                     - EPWM4:  EPWM4 module
  *                     - EPWM5:  EPWM5 module
  *                     - EPWM6:  EPWM6 module
  *                     - EPWM7:  EPWM7 module
  *                     - EPWM8:  EPWM8 module
  *                     - EPWM9:  EPWM9 module
  *                     - EPWM10: EPWM10 module
  *                     - EPWM11: EPWM11 module
  *                     - EPWM12: EPWM12 module
  *                     - EPWM13: EPWM13 module
  *                     - EPWM14: EPWM14 module
  *                     - EPWM15: EPWM15 module
  *                     - EPWM16: EPWM16 module
  *                     - EPWM17: EPWM17 module
  *                     - EPWM18: EPWM18 module
  * \param  dcType     Is the trip zone digital compare output type
  *                     This parameter can be any value of @ref EPWM_TRIPZONEDIGITALCOMPAREOUTPUT
  * \param  dcEvent    Is the trip zone digital compare output event
  *                     This parameter can be any value of @ref EPWM_TRIPZONEDIGITALCOMPAREOUTPUTEVENT
  */
static inline void EPWM_setTripZoneDigitalCompareEventCondition (EPWM_TypeDef *epwm,
                                                                 EPWM_TripZoneDigitalCompareOutput dcType,
                                                                 EPWM_TripZoneDigitalCompareOutputEvent dcEvent)
{
    MODIFY_REG(epwm->TZDCSEL.WORDVAL, EPWM_TZDCSEL_DCXEVTX << (uint32_t)dcType, (uint32_t)dcEvent << (uint32_t)dcType);
}

/**
  * \brief  Enable advanced Trip Zone event action
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableTripZoneAdvAction (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->TZCTL2.WORDVAL, EPWM_TZCTL2_ETZE);
}

/**
  * \brief  Disable advanced Trip Zone event action
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableTripZoneAdvAction (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->TZCTL2.WORDVAL, EPWM_TZCTL2_ETZE);
}

/**
  * \brief  Set Trip Zone action
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  tzEvent     Is the trip zone event
  *                      This parameter can be any value of @ref EPWM_TRIPZONEEVENT
  * \param  tzAction    Is the trip zone action
  *                      This parameter can be any value of @ref EPWM_TRIPZONEACTION
  */
static inline void EPWM_setTripZoneAction (EPWM_TypeDef *epwm, EPWM_TripZoneEvent tzEvent, EPWM_TripZoneAction tzAction)
{
    MODIFY_REG(epwm->TZCTL.WORDVAL, 0x3U << (uint32_t)tzEvent, (uint32_t)tzAction << (uint32_t)tzEvent);
}

/**
  * \brief  Set Trip Zone Advanced Action
  * \param  epwm           EPWMx pointer to a EPWM_TypeDef structure
  *                         - EPWM1:  EPWM1 module
  *                         - EPWM2:  EPWM2 module
  *                         - EPWM3:  EPWM3 module
  *                         - EPWM4:  EPWM4 module
  *                         - EPWM5:  EPWM5 module
  *                         - EPWM6:  EPWM6 module
  *                         - EPWM7:  EPWM7 module
  *                         - EPWM8:  EPWM8 module
  *                         - EPWM9:  EPWM9 module
  *                         - EPWM10: EPWM10 module
  *                         - EPWM11: EPWM11 module
  *                         - EPWM12: EPWM12 module
  *                         - EPWM13: EPWM13 module
  *                         - EPWM14: EPWM14 module
  *                         - EPWM15: EPWM15 module
  *                         - EPWM16: EPWM16 module
  *                         - EPWM17: EPWM17 module
  *                         - EPWM18: EPWM18 module
  * \param  tzAdvEvent     Is the trip zone advanced event
  *                         This parameter can be any value of @ref EPWM_TRIPZONEADVANCEDEVENT
  * \param  tzAdvAction    Is the trip zone advanced action
  *                         This parameter can be any value of @ref EPWM_TRIPZONEADVANCEDACTION
  */
static inline void EPWM_setTripZoneAdvAction (EPWM_TypeDef *epwm,
                                              EPWM_TripZoneAdvancedEvent tzAdvEvent,
                                              EPWM_TripZoneAdvancedAction tzAdvAction)
{
    MODIFY_REG(epwm->TZCTL2.WORDVAL, 0x7U << (uint32_t)tzAdvEvent, (uint32_t)tzAdvAction << (uint32_t)tzAdvEvent);
    SET_BIT(epwm->TZCTL2.WORDVAL, EPWM_TZCTL2_ETZE);
}

/**
  * \brief  Set Trip Zone Advanced Digital Compare Action A
  * \param  epwm             EPWMx pointer to a EPWM_TypeDef structure
  *                           - EPWM1:  EPWM1 module
  *                           - EPWM2:  EPWM2 module
  *                           - EPWM3:  EPWM3 module
  *                           - EPWM4:  EPWM4 module
  *                           - EPWM5:  EPWM5 module
  *                           - EPWM6:  EPWM6 module
  *                           - EPWM7:  EPWM7 module
  *                           - EPWM8:  EPWM8 module
  *                           - EPWM9:  EPWM9 module
  *                           - EPWM10: EPWM10 module
  *                           - EPWM11: EPWM11 module
  *                           - EPWM12: EPWM12 module
  *                           - EPWM13: EPWM13 module
  *                           - EPWM14: EPWM14 module
  *                           - EPWM15: EPWM15 module
  *                           - EPWM16: EPWM16 module
  *                           - EPWM17: EPWM17 module
  *                           - EPWM18: EPWM18 module
  * \param  tzAdvDCEvent     Is the trip zone advanced digital compare event
  *                           This parameter can be any value of @ref EPWM_TRIPZONEADVDIGITALCOMPAREEVENT
  * \param  tzAdvDCAction    Is the trip zone advanced digital compare action
  *                           This parameter can be any value of @ref EPWM_TRIPZONEADVANCEDACTION
  */
static inline void EPWM_setTripZoneAdvDigitalCompareActionA (EPWM_TypeDef *epwm,
                                                             EPWM_TripZoneAdvDigitalCompareEvent tzAdvDCEvent,
                                                             EPWM_TripZoneAdvancedAction tzAdvDCAction)
{
    MODIFY_REG(epwm->TZCTLDCA.WORDVAL, 0x7U << (uint32_t)tzAdvDCEvent, (uint32_t)tzAdvDCAction << (uint16_t)tzAdvDCEvent);
    SET_BIT(epwm->TZCTL2.WORDVAL, EPWM_TZCTL2_ETZE);
}

/**
  *  \brief  Set Trip Zone Advanced Digital Compare Action B
  *  \param  epwm             EPWMx pointer to a EPWM_TypeDef structure
  *                            - EPWM1:  EPWM1 module
  *                            - EPWM2:  EPWM2 module
  *                            - EPWM3:  EPWM3 module
  *                            - EPWM4:  EPWM4 module
  *                            - EPWM5:  EPWM5 module
  *                            - EPWM6:  EPWM6 module
  *                            - EPWM7:  EPWM7 module
  *                            - EPWM8:  EPWM8 module
  *                            - EPWM9:  EPWM9 module
  *                            - EPWM10: EPWM10 module
  *                            - EPWM11: EPWM11 module
  *                            - EPWM12: EPWM12 module
  *                            - EPWM13: EPWM13 module
  *                            - EPWM14: EPWM14 module
  *                            - EPWM15: EPWM15 module
  *                            - EPWM16: EPWM16 module
  *                            - EPWM17: EPWM17 module
  *                            - EPWM18: EPWM18 module
  *  \param  tzAdvDCEvent     Is the trip zone advanced digital compare event
  *                            This parameter can be any value of @ref EPWM_TRIPZONEADVDIGITALCOMPAREEVENT
  *  \param  tzAdvDCAction    Is the trip zone advanced digital compare action
  *                            This parameter can be any value of @ref EPWM_TRIPZONEADVANCEDACTION
  */
static inline void EPWM_setTripZoneAdvDigitalCompareActionB (EPWM_TypeDef *epwm,
                                                             EPWM_TripZoneAdvDigitalCompareEvent tzAdvDCEvent,
                                                             EPWM_TripZoneAdvancedAction tzAdvDCAction)
{
    MODIFY_REG(epwm->TZCTLDCB.WORDVAL, 0x7U << (uint32_t)tzAdvDCEvent, (uint32_t)tzAdvDCAction << (uint16_t)tzAdvDCEvent);
    SET_BIT(epwm->TZCTL2.WORDVAL, EPWM_TZCTL2_ETZE);
}

/**
  * \brief  Enable Trip Zone interrupts
  * \param  epwm           EPWMx pointer to a EPWM_TypeDef structure
  *                         - EPWM1:  EPWM1 module
  *                         - EPWM2:  EPWM2 module
  *                         - EPWM3:  EPWM3 module
  *                         - EPWM4:  EPWM4 module
  *                         - EPWM5:  EPWM5 module
  *                         - EPWM6:  EPWM6 module
  *                         - EPWM7:  EPWM7 module
  *                         - EPWM8:  EPWM8 module
  *                         - EPWM9:  EPWM9 module
  *                         - EPWM10: EPWM10 module
  *                         - EPWM11: EPWM11 module
  *                         - EPWM12: EPWM12 module
  *                         - EPWM13: EPWM13 module
  *                         - EPWM14: EPWM14 module
  *                         - EPWM15: EPWM15 module
  *                         - EPWM16: EPWM16 module
  *                         - EPWM17: EPWM17 module
  *                         - EPWM18: EPWM18 module
  * \param  tzInterrupt    Is the trip zone interrupt
  *                         This parameter can be any value of @ref EPWM_TZEINTCONF
  */
static inline void EPWM_enableTripZoneInterrupt (EPWM_TypeDef *epwm, uint16_t tzInterrupt)
{
    SET_BIT(epwm->TZEINT.WORDVAL, tzInterrupt);
}

/**
  * \brief  Disable Trip Zone interrupts
  * \param  epwm           EPWMx pointer to a EPWM_TypeDef structure
  *                         - EPWM1:  EPWM1 module
  *                         - EPWM2:  EPWM2 module
  *                         - EPWM3:  EPWM3 module
  *                         - EPWM4:  EPWM4 module
  *                         - EPWM5:  EPWM5 module
  *                         - EPWM6:  EPWM6 module
  *                         - EPWM7:  EPWM7 module
  *                         - EPWM8:  EPWM8 module
  *                         - EPWM9:  EPWM9 module
  *                         - EPWM10: EPWM10 module
  *                         - EPWM11: EPWM11 module
  *                         - EPWM12: EPWM12 module
  *                         - EPWM13: EPWM13 module
  *                         - EPWM14: EPWM14 module
  *                         - EPWM15: EPWM15 module
  *                         - EPWM16: EPWM16 module
  *                         - EPWM17: EPWM17 module
  *                         - EPWM18: EPWM18 module
  * \param  tzInterrupt    Is the trip zone interrupt
  *                         This parameter can be any value of @ref EPWM_TZEINTCONF
  */
static inline void EPWM_disableTripZoneInterrupt (EPWM_TypeDef *epwm, uint16_t tzInterrupt)
{
    CLEAR_BIT(epwm->TZEINT.WORDVAL, tzInterrupt);
}

/**
  * \brief  Gets the Trip Zone status flag
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the trip zone flag status
  *                  - 0: No trip zone flag is set
  *                  - 1: Trip zone flag is set
 */
static inline uint16_t EPWM_getTripZoneFlagStatus (EPWM_TypeDef *epwm)
{
    return (READ_BIT(epwm->TZFLG.WORDVAL, 0xFFU));
}

/**
  * \brief  Gets the Trip Zone cycle by cycle flag status
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the cycle by cycle trip zone flag status
  *                  - 0: No cycle by cycle trip zone flag is set
  *                  - 1: Cycle by cycle trip zone flag is set
  */
static inline uint16_t EPWM_getCycleByCycleTripZoneFlagStatus (EPWM_TypeDef *epwm)
{
    return (READ_BIT(epwm->TZCBCFLG.WORDVAL, 0x1FFU));
}

/**
  * \brief  Gets the Trip Zone one shot flag status
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns one shot trip zone flag status
  *                  - 0: No one shot trip zone flag is set
  *                  - 1: One shot trip zone flag is set
  */
static inline uint16_t EPWM_getOneShotTripZoneFlagStatus (EPWM_TypeDef *epwm)
{
    return (READ_BIT(epwm->TZOSTFLG.WORDVAL, 0x1FFU));
}

/**
  * \brief  Set the Trip Zone CBC pulse clear event
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  clearEvent    Is the cycle by cycle trip zone clear event
  *                        This parameter can be any value of @ref EPWM_CYCLEBYCYCLETRIPZONECLEARMODE
  */
static inline void EPWM_selectCycleByCycleTripZoneClearEvent (EPWM_TypeDef *epwm,
                                                              EPWM_CycleByCycleTripZoneClearMode clearEvent)
{
    MODIFY_REG(epwm->TZCLR.WORDVAL, EPWM_TZCLR_CBCPULSE_M, (uint32_t)clearEvent << EPWM_TZCLR_CBCPULSE_S);
}

/**
  * \brief  Clear Trip Zone flag
  * \param  epwm       EPWMx pointer to a EPWM_TypeDef structure
  *                     - EPWM1:  EPWM1 module
  *                     - EPWM2:  EPWM2 module
  *                     - EPWM3:  EPWM3 module
  *                     - EPWM4:  EPWM4 module
  *                     - EPWM5:  EPWM5 module
  *                     - EPWM6:  EPWM6 module
  *                     - EPWM7:  EPWM7 module
  *                     - EPWM8:  EPWM8 module
  *                     - EPWM9:  EPWM9 module
  *                     - EPWM10: EPWM10 module
  *                     - EPWM11: EPWM11 module
  *                     - EPWM12: EPWM12 module
  *                     - EPWM13: EPWM13 module
  *                     - EPWM14: EPWM14 module
  *                     - EPWM15: EPWM15 module
  *                     - EPWM16: EPWM16 module
  *                     - EPWM17: EPWM17 module
  *                     - EPWM18: EPWM18 module
  * \param  tzFlags    Is the trip zone flag
  *                     This parameter can be any value of @ref EPWM_TZFLGCONF
  */
static inline void EPWM_clearTripZoneFlag (EPWM_TypeDef *epwm, uint16_t tzFlags)
{
    SET_BIT(epwm->TZCLR.WORDVAL, tzFlags);
}

/**
  * \brief  Clear the Trip Zone cycle by cycle flag
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  clearEvent    Is the one shot trip zone clear event
  *                        This parameter can be any value of @ref EPWM_TZCBCFLGCONF
  */
static inline void EPWM_clearCycleByCycleTripZoneFlag (EPWM_TypeDef *epwm, uint16_t tzCBCFlags)
{
    SET_BIT(epwm->TZCBCCLR.WORDVAL, tzCBCFlags);
}

/**
  * \brief  Clear the Trip Zone one shot flag
  * \param  epwm       EPWMx pointer to a EPWM_TypeDef structure
  *                     - EPWM1:  EPWM1 module
  *                     - EPWM2:  EPWM2 module
  *                     - EPWM3:  EPWM3 module
  *                     - EPWM4:  EPWM4 module
  *                     - EPWM5:  EPWM5 module
  *                     - EPWM6:  EPWM6 module
  *                     - EPWM7:  EPWM7 module
  *                     - EPWM8:  EPWM8 module
  *                     - EPWM9:  EPWM9 module
  *                     - EPWM10: EPWM10 module
  *                     - EPWM11: EPWM11 module
  *                     - EPWM12: EPWM12 module
  *                     - EPWM13: EPWM13 module
  *                     - EPWM14: EPWM14 module
  *                     - EPWM15: EPWM15 module
  *                     - EPWM16: EPWM16 module
  *                     - EPWM17: EPWM17 module
  *                     - EPWM18: EPWM18 module
  * \param  tzFlags    Is the one shot trip zone flag
  *                     This parameter can be any value of @ref EPWM_TZOSTFLGCONF
  */
static inline void EPWM_clearOneShotTripZoneFlag (EPWM_TypeDef *epwm, uint16_t tzOSTFlags)
{
    SET_BIT(epwm->TZOSTCLR.WORDVAL, tzOSTFlags);
}

/**
  * \brief  Force Trip Zone events
  * \param  epwm            EPWMx pointer to a EPWM_TypeDef structure
  *                          - EPWM1:  EPWM1 module
  *                          - EPWM2:  EPWM2 module
  *                          - EPWM3:  EPWM3 module
  *                          - EPWM4:  EPWM4 module
  *                          - EPWM5:  EPWM5 module
  *                          - EPWM6:  EPWM6 module
  *                          - EPWM7:  EPWM7 module
  *                          - EPWM8:  EPWM8 module
  *                          - EPWM9:  EPWM9 module
  *                          - EPWM10: EPWM10 module
  *                          - EPWM11: EPWM11 module
  *                          - EPWM12: EPWM12 module
  *                          - EPWM13: EPWM13 module
  *                          - EPWM14: EPWM14 module
  *                          - EPWM15: EPWM15 module
  *                          - EPWM16: EPWM16 module
  *                          - EPWM17: EPWM17 module
  *                          - EPWM18: EPWM18 module
  * \param  tzForceEvent    Is the trip zone force event
  *                          This parameter can be any value of @ref EPWM_TZFRCCONF
  */
static inline void EPWM_forceTripZoneEvent (EPWM_TypeDef *epwm, uint16_t tzForceEvent)
{
    SET_BIT(epwm->TZFRC.WORDVAL, tzForceEvent);
}

/**
  * \brief  Enable trip out source
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                       - EPWM1:  EPWM1 module
  *                       - EPWM2:  EPWM2 module
  *                       - EPWM3:  EPWM3 module
  *                       - EPWM4:  EPWM4 module
  *                       - EPWM5:  EPWM5 module
  *                       - EPWM6:  EPWM6 module
  *                       - EPWM7:  EPWM7 module
  *                       - EPWM8:  EPWM8 module
  *                       - EPWM9:  EPWM9 module
  *                       - EPWM10: EPWM10 module
  *                       - EPWM11: EPWM11 module
  *                       - EPWM12: EPWM12 module
  *                       - EPWM13: EPWM13 module
  *                       - EPWM14: EPWM14 module
  *                       - EPWM15: EPWM15 module
  *                       - EPWM16: EPWM16 module
  *                       - EPWM17: EPWM17 module
  *                       - EPWM18: EPWM18 module
  * \param  tzTripOut    This parameter can be any value of @ref EPWM_SELECTTRIPOUTSOURCE
  */
static inline void EPWM_enableTripOutSource (EPWM_TypeDef *epwm, EPWM_selectTripOutSource tzTripOut)
{
    SET_BIT(epwm->TZTRIPOUTSEL.WORDVAL, 1UL << (uint32_t) tzTripOut);
}

/**
  * \brief  Disable trip out source
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                       - EPWM1:  EPWM1 module
  *                       - EPWM2:  EPWM2 module
  *                       - EPWM3:  EPWM3 module
  *                       - EPWM4:  EPWM4 module
  *                       - EPWM5:  EPWM5 module
  *                       - EPWM6:  EPWM6 module
  *                       - EPWM7:  EPWM7 module
  *                       - EPWM8:  EPWM8 module
  *                       - EPWM9:  EPWM9 module
  *                       - EPWM10: EPWM10 module
  *                       - EPWM11: EPWM11 module
  *                       - EPWM12: EPWM12 module
  *                       - EPWM13: EPWM13 module
  *                       - EPWM14: EPWM14 module
  *                       - EPWM15: EPWM15 module
  *                       - EPWM16: EPWM16 module
  *                       - EPWM17: EPWM17 module
  *                       - EPWM18: EPWM18 module
  * \param  tzTripOut    This parameter can be any value of @ref EPWM_SELECTTRIPOUTSOURCE
  */
static inline void EPWM_disableTripOutSource (EPWM_TypeDef *epwm, EPWM_selectTripOutSource tzTripOut)
{
    CLEAR_BIT(epwm->TZTRIPOUTSEL.WORDVAL, 1UL << (uint32_t) tzTripOut);
}

/**
  * \brief  Enable ePWM interrupt
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableInterrupt (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->ETSEL.WORDVAL, EPWM_ETSEL_INTEN);
}

/**
  * \brief  Disable ePWM interrupt
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableInterrupt (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->ETSEL.WORDVAL, EPWM_ETSEL_INTEN);
}

/**
  * \brief  Sets the ePWM interrupt source
  * \param  epwm               EPWMx pointer to a EPWM_TypeDef structure
  *                             - EPWM1:  EPWM1 module
  *                             - EPWM2:  EPWM2 module
  *                             - EPWM3:  EPWM3 module
  *                             - EPWM4:  EPWM4 module
  *                             - EPWM5:  EPWM5 module
  *                             - EPWM6:  EPWM6 module
  *                             - EPWM7:  EPWM7 module
  *                             - EPWM8:  EPWM8 module
  *                             - EPWM9:  EPWM9 module
  *                             - EPWM10: EPWM10 module
  *                             - EPWM11: EPWM11 module
  *                             - EPWM12: EPWM12 module
  *                             - EPWM13: EPWM13 module
  *                             - EPWM14: EPWM14 module
  *                             - EPWM15: EPWM15 module
  *                             - EPWM16: EPWM16 module
  *                             - EPWM17: EPWM17 module
  *                             - EPWM18: EPWM18 module
  * \param  interruptSource    Is the interrupt source
  *                             This parameter can be any value of @ref EPWM_INTSELCONF
  */
static inline void EPWM_setInterruptSource (EPWM_TypeDef *epwm, uint16_t interruptSource)
{
    uint16_t intSource;
    if ((interruptSource == EPWM_INT_TBCTR_U_CMPC) ||
        (interruptSource == EPWM_INT_TBCTR_U_CMPD) ||
        (interruptSource == EPWM_INT_TBCTR_D_CMPC) ||
        (interruptSource == EPWM_INT_TBCTR_D_CMPD))
    {
        intSource = interruptSource >> 1U;
        SET_BIT(epwm->ETSEL.WORDVAL, EPWM_ETSEL_INTSELCMP);
    }
    else if ((interruptSource == EPWM_INT_TBCTR_U_CMPA) ||
             (interruptSource == EPWM_INT_TBCTR_U_CMPB) ||
             (interruptSource == EPWM_INT_TBCTR_D_CMPA) ||
             (interruptSource == EPWM_INT_TBCTR_D_CMPB))
    {
        intSource = interruptSource;
        CLEAR_BIT(epwm->ETSEL.WORDVAL, EPWM_ETSEL_INTSELCMP);
    }
    else
    {
        intSource = interruptSource;
    }
    MODIFY_REG(epwm->ETSEL.WORDVAL, EPWM_ETSEL_INTSEL_M, intSource);
}

/**
  * \brief  Sets the ePWM interrupt event counts
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  eventCount    Is the event count for interrupt scale
  */
static inline void EPWM_setInterruptEventCount (EPWM_TypeDef *epwm, uint16_t eventCount)
{
    SET_BIT(epwm->ETPS.WORDVAL, EPWM_ETPS_INTPSSEL);
    MODIFY_REG(epwm->ETINTPS.WORDVAL, EPWM_ETINTPS_INTPRD2_M, eventCount);
}

/**
  * \brief  Return the event trigger interrupt status
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the interrupt status
  *                  - 1 : ePWM interrupt was generated
  *                  - 0 : no interrupt was generated
  */
static inline bool EPWM_getEventTriggerInterruptStatus (EPWM_TypeDef *epwm)
{
    return (((epwm->ETFLG.WORDVAL) & 0x1U) == 0x1U) ? 1UL : 0UL;
}

/**
  * \brief  Clear event trigger interrupt flag
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_clearEventTriggerInterruptFlag (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->ETCLR.WORDVAL, EPWM_ETCLR_INT);
}

/**
  * \brief  Enable interrupt event count initialization
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableInterruptEventCountInit (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->ETCNTINITCTL.WORDVAL, EPWM_ETCNTINITCTL_INTINITEN);
}

/**
  * \brief  Disable interrupt event count initialization
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableInterruptEventCountInit (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->ETCNTINITCTL.WORDVAL, EPWM_ETCNTINITCTL_INTINITEN);
}

/**
  * \brief  Force Interrupt Event Count Initialization
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_forceInterruptEventCountInit (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->ETCNTINITCTL.WORDVAL, EPWM_ETCNTINITCTL_INTINITFRC);
}

/**
  * \brief  Set Interrupt Event Count Initialization Value
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  eventCount    The event count value
  */
static inline void EPWM_setInterruptEventCountInitValue (EPWM_TypeDef *epwm, uint16_t eventCount)
{
    MODIFY_REG(epwm->ETCNTINIT.WORDVAL, EPWM_ETCNTINIT_INTINIT_M, (uint32_t)(eventCount & 0xFU));
}

/**
  * \brief  Enable Mix Event Trigger Source
  * \param  epwm                EPWMx pointer to a EPWM_TypeDef structure
  *                              - EPWM1:  EPWM1 module
  *                              - EPWM2:  EPWM2 module
  *                              - EPWM3:  EPWM3 module
  *                              - EPWM4:  EPWM4 module
  *                              - EPWM5:  EPWM5 module
  *                              - EPWM6:  EPWM6 module
  *                              - EPWM7:  EPWM7 module
  *                              - EPWM8:  EPWM8 module
  *                              - EPWM9:  EPWM9 module
  *                              - EPWM10: EPWM10 module
  *                              - EPWM11: EPWM11 module
  *                              - EPWM12: EPWM12 module
  *                              - EPWM13: EPWM13 module
  *                              - EPWM14: EPWM14 module
  *                              - EPWM15: EPWM15 module
  *                              - EPWM16: EPWM16 module
  *                              - EPWM17: EPWM17 module
  *                              - EPWM18: EPWM18 module
  * \param  etmixSignal        This parameter can be any value of @ref EPWM_ETMIXSIGNALSELECT
  * \param  interruptSource    This parameter can be any value of @ref EPWM_ETMIXTRIGGERSOURCE
  */
static inline void EPWM_enableMixEvtTriggerSource(EPWM_TypeDef *epwm,
                                                  EPWM_ETMixSignalSelect etmixSignal,
                                                  EPWM_ETMixTriggerSource interruptSource)
{
    SET_BIT(TYPE32(&(epwm->ETINTMIXEN.WORDVAL) + (etmixSignal >> 2)), (0x1U << (uint16_t)interruptSource));
}

/**
  * \brief  Disable Mix Event Trigger Source
  * \param  epwm                EPWMx pointer to a EPWM_TypeDef structure
  *                              - EPWM1:  EPWM1 module
  *                              - EPWM2:  EPWM2 module
  *                              - EPWM3:  EPWM3 module
  *                              - EPWM4:  EPWM4 module
  *                              - EPWM5:  EPWM5 module
  *                              - EPWM6:  EPWM6 module
  *                              - EPWM7:  EPWM7 module
  *                              - EPWM8:  EPWM8 module
  *                              - EPWM9:  EPWM9 module
  *                              - EPWM10: EPWM10 module
  *                              - EPWM11: EPWM11 module
  *                              - EPWM12: EPWM12 module
  *                              - EPWM13: EPWM13 module
  *                              - EPWM14: EPWM14 module
  *                              - EPWM15: EPWM15 module
  *                              - EPWM16: EPWM16 module
  *                              - EPWM17: EPWM17 module
  *                              - EPWM18: EPWM18 module
  * \param  etmixSignal        This parameter can be any value of @ref EPWM_ETMIXSIGNALSELECT
  * \param  interruptSource    This parameter can be any value of @ref EPWM_ETMIXTRIGGERSOURCE
  */
static inline void EPWM_disableMixEvtTriggerSource(EPWM_TypeDef *epwm,
                                                   EPWM_ETMixSignalSelect etmixSignal,
                                                   EPWM_ETMixTriggerSource interruptSource)
{
    CLEAR_BIT(TYPE32(&(epwm->ETINTMIXEN.WORDVAL) + (etmixSignal >> 2)), (0x1U << (uint16_t)interruptSource));
}

/**
  * \brief  Enable Mix Blank Trigger Pulse Source
  * \param  epwm      EPWMx pointer to a EPWM_TypeDef structure
  *                    - EPWM1:  EPWM1 module
  *                    - EPWM2:  EPWM2 module
  *                    - EPWM3:  EPWM3 module
  *                    - EPWM4:  EPWM4 module
  *                    - EPWM5:  EPWM5 module
  *                    - EPWM6:  EPWM6 module
  *                    - EPWM7:  EPWM7 module
  *                    - EPWM8:  EPWM8 module
  *                    - EPWM9:  EPWM9 module
  *                    - EPWM10: EPWM10 module
  *                    - EPWM11: EPWM11 module
  *                    - EPWM12: EPWM12 module
  *                    - EPWM13: EPWM13 module
  *                    - EPWM14: EPWM14 module
  *                    - EPWM15: EPWM15 module
  *                    - EPWM16: EPWM16 module
  *                    - EPWM17: EPWM17 module
  *                    - EPWM18: EPWM18 module
  * \param  source    This parameter can be any value of @ref EPWM_DCMIXSELCONF
  */
static inline void EPWM_enableMixBlankTriggerPulseSource (EPWM_TypeDef *epwm, uint32_t source)
{
    SET_BIT(epwm->BLANKPULSEMIXSEL.WORDVAL, source);
}

/**
  * \brief  Disable Mix Blank Trigger Pulse Source
  * \param  epwm      EPWMx pointer to a EPWM_TypeDef structure
  *                    - EPWM1:  EPWM1 module
  *                    - EPWM2:  EPWM2 module
  *                    - EPWM3:  EPWM3 module
  *                    - EPWM4:  EPWM4 module
  *                    - EPWM5:  EPWM5 module
  *                    - EPWM6:  EPWM6 module
  *                    - EPWM7:  EPWM7 module
  *                    - EPWM8:  EPWM8 module
  *                    - EPWM9:  EPWM9 module
  *                    - EPWM10: EPWM10 module
  *                    - EPWM11: EPWM11 module
  *                    - EPWM12: EPWM12 module
  *                    - EPWM13: EPWM13 module
  *                    - EPWM14: EPWM14 module
  *                    - EPWM15: EPWM15 module
  *                    - EPWM16: EPWM16 module
  *                    - EPWM17: EPWM17 module
  *                    - EPWM18: EPWM18 module
  * \param  source    This parameter can be any value of @ref EPWM_DCMIXSELCONF
  */
static inline void EPWM_disableMixBlankTriggerPulseSource (EPWM_TypeDef *epwm, uint32_t source)
{
    CLEAR_BIT(epwm->BLANKPULSEMIXSEL.WORDVAL, source);
}

/**
  * \brief  Enable Mix Capture Event Pulse source
  * \param  epwm      EPWMx pointer to a EPWM_TypeDef structure
  *                    - EPWM1:  EPWM1 module
  *                    - EPWM2:  EPWM2 module
  *                    - EPWM3:  EPWM3 module
  *                    - EPWM4:  EPWM4 module
  *                    - EPWM5:  EPWM5 module
  *                    - EPWM6:  EPWM6 module
  *                    - EPWM7:  EPWM7 module
  *                    - EPWM8:  EPWM8 module
  *                    - EPWM9:  EPWM9 module
  *                    - EPWM10: EPWM10 module
  *                    - EPWM11: EPWM11 module
  *                    - EPWM12: EPWM12 module
  *                    - EPWM13: EPWM13 module
  *                    - EPWM14: EPWM14 module
  *                    - EPWM15: EPWM15 module
  *                    - EPWM16: EPWM16 module
  *                    - EPWM17: EPWM17 module
  *                    - EPWM18: EPWM18 module
  * \param  source    This parameter can be any value of @ref EPWM_DCMIXSELCONF
  */
static inline void EPWM_enableMixCaptureEventPulseSource (EPWM_TypeDef *epwm, uint32_t source)
{
     SET_BIT(epwm->DCCAPMIXSEL.WORDVAL, source);
}

/**
  * \brief  Disable Mix Capture Event Pulse source
  * \param  epwm      EPWMx pointer to a EPWM_TypeDef structure
  *                    - EPWM1:  EPWM1 module
  *                    - EPWM2:  EPWM2 module
  *                    - EPWM3:  EPWM3 module
  *                    - EPWM4:  EPWM4 module
  *                    - EPWM5:  EPWM5 module
  *                    - EPWM6:  EPWM6 module
  *                    - EPWM7:  EPWM7 module
  *                    - EPWM8:  EPWM8 module
  *                    - EPWM9:  EPWM9 module
  *                    - EPWM10: EPWM10 module
  *                    - EPWM11: EPWM11 module
  *                    - EPWM12: EPWM12 module
  *                    - EPWM13: EPWM13 module
  *                    - EPWM14: EPWM14 module
  *                    - EPWM15: EPWM15 module
  *                    - EPWM16: EPWM16 module
  *                    - EPWM17: EPWM17 module
  *                    - EPWM18: EPWM18 module
  * \param  source    This parameter can be any value of @ref EPWM_DCMIXSELCONF
  */
static inline void EPWM_disableMixCaptureEventPulseSource (EPWM_TypeDef *epwm, uint32_t source)
{
     CLEAR_BIT(epwm->DCCAPMIXSEL.WORDVAL, source);
}

/**
  * \brief  Get Interrupt Event Count
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the interrupt event counts that have occurred
  */
static inline uint16_t EPWM_getInterruptEventCount (EPWM_TypeDef *epwm)
{
    return ((epwm->ETINTPS.WORDVAL & EPWM_ETINTPS_INTCNT2_M) >> EPWM_ETINTPS_INTCNT2_S);
}

/**
  * \brief  Force Event Trigger Interrupt
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_forceEventTriggerInterrupt (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->ETFRC.WORDVAL, EPWM_ETFRC_INT);
}

/**
  * \brief  Enable ADC SOC trigger
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  adcSOCType    ADC start of conversion type
  *                        This parameter can be any value of @ref EPWM_ADCSTARTOFCONVERSIONTYPE
  */
static inline void EPWM_enableADCTrigger (EPWM_TypeDef *epwm, EPWM_ADCStartOfConversionType adcSOCType)
{
    if (adcSOCType == EPWM_SOC_A)
    {
        SET_BIT(epwm->ETSEL.WORDVAL, EPWM_ETSEL_SOCAEN);
    }
    else
    {
        SET_BIT(epwm->ETSEL.WORDVAL, EPWM_ETSEL_SOCBEN);
    }
}

/**
  * \brief  Disable ADC SOC trigger
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  adcSOCType    ADC trigger type
  *                        This parameter can be any value of @ref EPWM_ADCSTARTOFCONVERSIONTYPE
  */
static inline void EPWM_disableADCTrigger (EPWM_TypeDef *epwm, EPWM_ADCStartOfConversionType adcSOCType)
{
    if (adcSOCType == EPWM_SOC_A)
    {
        CLEAR_BIT(epwm->ETSEL.WORDVAL, EPWM_ETSEL_SOCAEN);
    }
    else
    {
        CLEAR_BIT(epwm->ETSEL.WORDVAL, EPWM_ETSEL_SOCBEN);
    }
}

/**
  * \brief  Sets the ePWM SOC source
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  adcSOCType    The ADC SOC type
  *                        This parameter can be any value of @ref EPWM_ADCSTARTOFCONVERSIONTYPE
  * \param  socSource     The SOC source
  *                        This parameter can be any value of @ref EPWM_ADCSTARTOFCONVERSIONSOURCE
  */
static inline void EPWM_setADCTriggerSource (EPWM_TypeDef *epwm,
                                             EPWM_ADCStartOfConversionType adcSOCType,
                                             EPWM_ADCStartOfConversionSource socSource)
{
    uint32_t source;
    if ((socSource == EPWM_SOC_TBCTR_U_CMPC) ||
        (socSource == EPWM_SOC_TBCTR_U_CMPD) ||
        (socSource == EPWM_SOC_TBCTR_D_CMPC) ||
        (socSource == EPWM_SOC_TBCTR_D_CMPD))
    {
        source = (uint32_t)socSource >> 1U;
    }
    else
    {
        source = (uint32_t)socSource;
    }
    if (adcSOCType == EPWM_SOC_A)
    {
        MODIFY_REG(epwm->ETSEL.WORDVAL, EPWM_ETSEL_SOCASEL_M, source << EPWM_ETSEL_SOCASEL_S);
        if ((socSource == EPWM_SOC_TBCTR_U_CMPA) ||
            (socSource == EPWM_SOC_TBCTR_U_CMPB) ||
            (socSource == EPWM_SOC_TBCTR_D_CMPA) ||
            (socSource == EPWM_SOC_TBCTR_D_CMPB))
        {
            CLEAR_BIT(epwm->ETSEL.WORDVAL, EPWM_ETSEL_SOCASELCMP);
        }
        else if ((socSource == EPWM_SOC_TBCTR_U_CMPC) ||
                 (socSource == EPWM_SOC_TBCTR_U_CMPD) ||
                 (socSource == EPWM_SOC_TBCTR_D_CMPC) ||
                 (socSource == EPWM_SOC_TBCTR_D_CMPD))
        {
            SET_BIT(epwm->ETSEL.WORDVAL, EPWM_ETSEL_SOCASELCMP);
        }
    }
    else
    {
        MODIFY_REG(epwm->ETSEL.WORDVAL, EPWM_ETSEL_SOCBSEL_M, source << EPWM_ETSEL_SOCBSEL_S);
        if ((socSource == EPWM_SOC_TBCTR_U_CMPA) ||
            (socSource == EPWM_SOC_TBCTR_U_CMPB) ||
            (socSource == EPWM_SOC_TBCTR_D_CMPA) ||
            (socSource == EPWM_SOC_TBCTR_D_CMPB))
        {
            CLEAR_BIT(epwm->ETSEL.WORDVAL, EPWM_ETSEL_SOCBSELCMP);
        }
        else if ((socSource == EPWM_SOC_TBCTR_U_CMPC) ||
                 (socSource == EPWM_SOC_TBCTR_U_CMPD) ||
                 (socSource == EPWM_SOC_TBCTR_D_CMPC) ||
                 (socSource == EPWM_SOC_TBCTR_D_CMPD))
        {
            SET_BIT(epwm->ETSEL.WORDVAL, EPWM_ETSEL_SOCBSELCMP);
        }
    }
}

/**
  * \brief  Set ADC Trigger Event Prescale
  * \param  epwm             EPWMx pointer to a EPWM_TypeDef structure
  *                           - EPWM1:  EPWM1 module
  *                           - EPWM2:  EPWM2 module
  *                           - EPWM3:  EPWM3 module
  *                           - EPWM4:  EPWM4 module
  *                           - EPWM5:  EPWM5 module
  *                           - EPWM6:  EPWM6 module
  *                           - EPWM7:  EPWM7 module
  *                           - EPWM8:  EPWM8 module
  *                           - EPWM9:  EPWM9 module
  *                           - EPWM10: EPWM10 module
  *                           - EPWM11: EPWM11 module
  *                           - EPWM12: EPWM12 module
  *                           - EPWM13: EPWM13 module
  *                           - EPWM14: EPWM14 module
  *                           - EPWM15: EPWM15 module
  *                           - EPWM16: EPWM16 module
  *                           - EPWM17: EPWM17 module
  *                           - EPWM18: EPWM18 module
  * \param  adcSOCType       Is the ADC SOC type
  *                           This parameter can be any value of @ref EPWM_ADCSTARTOFCONVERSIONTYPE
  * \param  preScaleCount    Is the event count number
  */
static inline void EPWM_setADCTriggerEventPrescale (EPWM_TypeDef *epwm,
                                                    EPWM_ADCStartOfConversionType adcSOCType,
                                                    uint16_t preScaleCount)
{
    SET_BIT(epwm->ETPS.WORDVAL, EPWM_ETPS_SOCPSSEL);
    if (adcSOCType == EPWM_SOC_A)
    {
        MODIFY_REG(epwm->ETSOCPS.WORDVAL, EPWM_ETSOCPS_SOCAPRD2_M, preScaleCount);
    }
    else
    {
        MODIFY_REG(epwm->ETSOCPS.WORDVAL, EPWM_ETSOCPS_SOCBPRD2_M, preScaleCount << EPWM_ETSOCPS_SOCBPRD2_S);
    }
}

/**
  * \brief  Return the SOC trigger flag status
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  adcSOCType    ADC trigger type
  *                        This parameter can be any value of @ref EPWM_ADCSTARTOFCONVERSIONTYPE
  * \return Returns value is the flag status
  *                         - 1 : the flag is set
  *                         - 0 : the flag is not set
  */
static inline bool EPWM_getADCTriggerFlagStatus (EPWM_TypeDef *epwm,
                                                 EPWM_ADCStartOfConversionType adcSOCType)
{
    return ((((epwm->ETFLG.WORDVAL) >> ((uint32_t)adcSOCType + 2U)) & 0x1U) == 0x1U)? 1UL: 0UL;
}

/**
  * \brief  Clear the SOC trigger flag status
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  adcSOCType    ADC trigger type
  *                        This parameter can be any value of @ref EPWM_ADCSTARTOFCONVERSIONTYPE
  */
static inline void EPWM_clearADCTriggerFlag (EPWM_TypeDef *epwm,
                                             EPWM_ADCStartOfConversionType adcSOCType)
{
    SET_BIT(epwm->ETCLR.WORDVAL, 1U << ((uint32_t)adcSOCType + 2U));
}

/**
  * \brief  Enable ADC trigger event count initialization
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  adcSOCType    ADC trigger type
  *                        This parameter can be any value of @ref EPWM_ADCSTARTOFCONVERSIONTYPE
  */
static inline void EPWM_enableADCTriggerEventCountInit (EPWM_TypeDef *epwm, EPWM_ADCStartOfConversionType adcSOCType)
{
    SET_BIT(epwm->ETCNTINITCTL.WORDVAL, 1U << ((uint32_t)adcSOCType + 14U));
}

/**
  * \brief  Disable ADC trigger event count initialization
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  adcSOCType    ADC trigger type
  *                        This parameter can be any value of @ref EPWM_ADCSTARTOFCONVERSIONTYPE
  */
static inline void EPWM_disableADCTriggerEventCountInit (EPWM_TypeDef *epwm, EPWM_ADCStartOfConversionType adcSOCType)
{
    CLEAR_BIT(epwm->ETCNTINITCTL.WORDVAL, 1U << ((uint32_t)adcSOCType + 14U));
}

/**
  * \brief  Force ADC trigger event count initialization
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  adcSOCType    ADC trigger type
  *                        This parameter can be any value of @ref EPWM_ADCSTARTOFCONVERSIONTYPE
  */
static inline void EPWM_forceADCTriggerEventCountInit (EPWM_TypeDef *epwm, EPWM_ADCStartOfConversionType adcSOCType)
{
    SET_BIT(epwm->ETCNTINITCTL.WORDVAL, 1U << ((uint32_t)adcSOCType + 11U));
}

/**
  * \brief  Set ADC trigger event count initialization values
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  adcSOCType    ADC trigger type.
  *                        This parameter can be any value of @ref EPWM_ADCSTARTOFCONVERSIONTYPE
  * \param  eventCount    Event countvalue.
  */
static inline void EPWM_setADCTriggerEventCountInitValue (EPWM_TypeDef *epwm,
                                                          EPWM_ADCStartOfConversionType adcSOCType,
                                                          uint16_t eventCount)
{
    if (adcSOCType == EPWM_SOC_A)
    {
        MODIFY_REG(epwm->ETCNTINIT.WORDVAL, EPWM_ETCNTINIT_SOCAINIT_M, (uint32_t)(eventCount << EPWM_ETCNTINIT_SOCAINIT_S));
    }
    else
    {
        MODIFY_REG(epwm->ETCNTINIT.WORDVAL, EPWM_ETCNTINIT_SOCBINIT_M, (uint32_t)(eventCount << EPWM_ETCNTINIT_SOCBINIT_S));
    }
}

/**
  * \brief  Return ADC trigger event count
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  adcSOCType    ADC trigger type
  *                        This parameter can be any value of @ref EPWM_ADCSTARTOFCONVERSIONTYPE
  * \return Returns the event count value
  */
static inline uint16_t EPWM_getADCTriggerEventCount (EPWM_TypeDef *epwm, EPWM_ADCStartOfConversionType adcSOCType)
{
    uint16_t eventCount;
    if (adcSOCType == EPWM_SOC_A)
    {
        eventCount = (READ_REG(epwm->ETSOCPS.WORDVAL) >> EPWM_ETSOCPS_SOCACNT2_S) & 0xFU;
    }
    else
    {
        eventCount = (READ_REG(epwm->ETSOCPS.WORDVAL) >> EPWM_ETSOCPS_SOCBCNT2_S) & 0xFU;
    }
    return (eventCount);
}

/**
  * \brief  Force ADC trigger
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  adcSOCType    ADC trigger type
  *                        This parameter can be any value of @ref EPWM_ADCSTARTOFCONVERSIONTYPE
  */
static inline void EPWM_forceADCTrigger (EPWM_TypeDef *epwm, EPWM_ADCStartOfConversionType adcSOCType)
{
    SET_BIT(epwm->ETFRC.WORDVAL, 1U << ((uint32_t)adcSOCType + 2U));
}

/**
  * \brief  Select Digital Compare Trip Input
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  tripSource    Trip source
  *                        This parameter can be any value of @ref EPWM_DIGITALCOMPARETRIPINPUT
  * \param  dcType        Is the Digital Compare type
  *                        This parameter can be any value of @ref EPWM_DIGITALCOMPARETYPE
  */
static inline void EPWM_selectDigitalCompareTripInput (EPWM_TypeDef *epwm,
                                                       EPWM_DigitalCompareTripInput tripSource,
                                                       EPWM_DigitalCompareType dcType)
{
    MODIFY_REG(epwm->DCTRIPSEL.WORDVAL, 0xFU << ((uint32_t)dcType << 2U), (uint32_t)tripSource << ((uint32_t)dcType << 2U));
}

/**
  * \brief  Enable digital compare blanking window
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableDigitalCompareBlankingWindow (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->DCFCTL.WORDVAL, EPWM_DCFCTL_BLANKE);
}

/**
  * \brief  Disable digital compare blanking window
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableDigitalCompareBlankingWindow (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->DCFCTL.WORDVAL, EPWM_DCFCTL_BLANKE);
}

/**
  * \brief  Enable digital compare window inverse mode
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableDigitalCompareWindowInverseMode (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->DCFCTL.WORDVAL, EPWM_DCFCTL_BLANKINV);
}

/**
  * \brief  Disable digital compare window inverse mode
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableDigitalCompareWindowInverseMode (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->DCFCTL.WORDVAL, EPWM_DCFCTL_BLANKINV);
}

/**
  * \brief  Set digital compare blanking event
  * \param  epwm             EPWMx pointer to a EPWM_TypeDef structure
  *                           - EPWM1:  EPWM1 module
  *                           - EPWM2:  EPWM2 module
  *                           - EPWM3:  EPWM3 module
  *                           - EPWM4:  EPWM4 module
  *                           - EPWM5:  EPWM5 module
  *                           - EPWM6:  EPWM6 module
  *                           - EPWM7:  EPWM7 module
  *                           - EPWM8:  EPWM8 module
  *                           - EPWM9:  EPWM9 module
  *                           - EPWM10: EPWM10 module
  *                           - EPWM11: EPWM11 module
  *                           - EPWM12: EPWM12 module
  *                           - EPWM13: EPWM13 module
  *                           - EPWM14: EPWM14 module
  *                           - EPWM15: EPWM15 module
  *                           - EPWM16: EPWM16 module
  *                           - EPWM17: EPWM17 module
  *                           - EPWM18: EPWM18 module
  * \param  blankingPulse    Blanking pulse
  *                            This parameter can be any value of @ref EPWM_DIGITALCOMPAREBLANKINGPULSE
  */
static inline void EPWM_setDigitalCompareBlankingEvent (EPWM_TypeDef *epwm,
                                                        EPWM_DigitalCompareBlankingPulse blankingPulse)
{
    MODIFY_REG(epwm->DCFCTL.WORDVAL, EPWM_DCFCTL_PULSESEL_M, ((uint32_t)blankingPulse << EPWM_DCFCTL_PULSESEL_S));
}

/**
  * \brief  Set up the digital compare filter input
  * \param  epwm           EPWMx pointer to a EPWM_TypeDef structure
  *                         - EPWM1:  EPWM1 module
  *                         - EPWM2:  EPWM2 module
  *                         - EPWM3:  EPWM3 module
  *                         - EPWM4:  EPWM4 module
  *                         - EPWM5:  EPWM5 module
  *                         - EPWM6:  EPWM6 module
  *                         - EPWM7:  EPWM7 module
  *                         - EPWM8:  EPWM8 module
  *                         - EPWM9:  EPWM9 module
  *                         - EPWM10: EPWM10 module
  *                         - EPWM11: EPWM11 module
  *                         - EPWM12: EPWM12 module
  *                         - EPWM13: EPWM13 module
  *                         - EPWM14: EPWM14 module
  *                         - EPWM15: EPWM15 module
  *                         - EPWM16: EPWM16 module
  *                         - EPWM17: EPWM17 module
  *                         - EPWM18: EPWM18 module
  * \param  filterInput    Filter input
  *                          This parameter can be any value of @ref EPWM_DIGITALCOMPAREFILTERINPUT
  */
static inline void EPWM_setDigitalCompareFilterInput (EPWM_TypeDef *epwm,
                                                      EPWM_DigitalCompareFilterInput filterInput)
{
    MODIFY_REG(epwm->DCFCTL.WORDVAL, EPWM_DCFCTL_SRCSEL_M, (uint32_t)filterInput);
}

/**
  * \brief  Enable digital compare edge filter
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableDigitalCompareEdgeFilter (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->DCFCTL.WORDVAL, EPWM_DCFCTL_EDGEFILTSEL);
}

/**
  * \brief  Disable digital compare edge filter
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableDigitalCompareEdgeFilter (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->DCFCTL.WORDVAL, EPWM_DCFCTL_EDGEFILTSEL);
}

/**
  * \brief  Set the digital compare edge filter mode
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  edgeMode    Edge filter mode
  *                      This parameter can be any value of @ref EPWM_DIGITALCOMPAREEDGEFILTERMODE
  */
static inline void EPWM_setDigitalCompareEdgeFilterMode (EPWM_TypeDef *epwm,
                                                         EPWM_DigitalCompareEdgeFilterMode edgeMode)
{
    MODIFY_REG(epwm->DCFCTL.WORDVAL, EPWM_DCFCTL_EDGEMODE_M, (uint32_t)edgeMode << EPWM_DCFCTL_EDGEMODE_S);
}

/**
  * \brief  Set the digital compare edge filter edge count
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                       - EPWM1:  EPWM1 module
  *                       - EPWM2:  EPWM2 module
  *                       - EPWM3:  EPWM3 module
  *                       - EPWM4:  EPWM4 module
  *                       - EPWM5:  EPWM5 module
  *                       - EPWM6:  EPWM6 module
  *                       - EPWM7:  EPWM7 module
  *                       - EPWM8:  EPWM8 module
  *                       - EPWM9:  EPWM9 module
  *                       - EPWM10: EPWM10 module
  *                       - EPWM11: EPWM11 module
  *                       - EPWM12: EPWM12 module
  *                       - EPWM13: EPWM13 module
  *                       - EPWM14: EPWM14 module
  *                       - EPWM15: EPWM15 module
  *                       - EPWM16: EPWM16 module
  *                       - EPWM17: EPWM17 module
  *                       - EPWM18: EPWM18 module
  * \param  edgeCount    Edge filter edge count
  *                       This parameter can be any value of @ref EPWM_DIGITALCOMPAREEDGEFILTEREDGECOUNT
  */
static inline void EPWM_setDigitalCompareEdgeFilterEdgeCount (EPWM_TypeDef *epwm, uint16_t edgeCount)
{
    MODIFY_REG(epwm->DCFCTL.WORDVAL, EPWM_DCFCTL_EDGECOUNT_M, edgeCount << EPWM_DCFCTL_EDGECOUNT_S);
}

/**
  * \brief  Returns the digital compare edge filter edge count
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the count of captured edges
  */
static inline uint16_t EPWM_getDigitalCompareEdgeFilterEdgeCount (EPWM_TypeDef *epwm)
{
    return (((epwm->DCFCTL.WORDVAL) & EPWM_DCFCTL_EDGECOUNT_M) >> EPWM_DCFCTL_EDGECOUNT_S);
}

/**
  * \brief  Returns the digital compare edge filter captured edge count status
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the count of captured edges
  */
static inline uint16_t EPWM_getDigitalCompareEdgeFilterEdgeStatus (EPWM_TypeDef *epwm)
{
    return (((epwm->DCFCTL.WORDVAL) & EPWM_DCFCTL_EDGESTATUS_M) >> EPWM_DCFCTL_EDGESTATUS_S);
}

/**
  * \brief  Set the digital compare filter window offset
  * \param  epwm                 EPWMx pointer to a EPWM_TypeDef structure
  *                               - EPWM1:  EPWM1 module
  *                               - EPWM2:  EPWM2 module
  *                               - EPWM3:  EPWM3 module
  *                               - EPWM4:  EPWM4 module
  *                               - EPWM5:  EPWM5 module
  *                               - EPWM6:  EPWM6 module
  *                               - EPWM7:  EPWM7 module
  *                               - EPWM8:  EPWM8 module
  *                               - EPWM9:  EPWM9 module
  *                               - EPWM10: EPWM10 module
  *                               - EPWM11: EPWM11 module
  *                               - EPWM12: EPWM12 module
  *                               - EPWM13: EPWM13 module
  *                               - EPWM14: EPWM14 module
  *                               - EPWM15: EPWM15 module
  *                               - EPWM16: EPWM16 module
  *                               - EPWM17: EPWM17 module
  *                               - EPWM18: EPWM18 module
  * \param  windowOffsetCount    Window offset count
  */
static inline void EPWM_setDigitalCompareWindowOffset (EPWM_TypeDef *epwm, uint16_t windowOffsetCount)
{
    WRITE_REG(epwm->DCFOFFSET.WORDVAL, windowOffsetCount);
}

/**
  * \brief  Set up the digital compare filter window length
  * \param  epwm                 EPWMx pointer to a EPWM_TypeDef structure
  *                               - EPWM1:  EPWM1 module
  *                               - EPWM2:  EPWM2 module
  *                               - EPWM3:  EPWM3 module
  *                               - EPWM4:  EPWM4 module
  *                               - EPWM5:  EPWM5 module
  *                               - EPWM6:  EPWM6 module
  *                               - EPWM7:  EPWM7 module
  *                               - EPWM8:  EPWM8 module
  *                               - EPWM9:  EPWM9 module
  *                               - EPWM10: EPWM10 module
  *                               - EPWM11: EPWM11 module
  *                               - EPWM12: EPWM12 module
  *                               - EPWM13: EPWM13 module
  *                               - EPWM14: EPWM14 module
  *                               - EPWM15: EPWM15 module
  *                               - EPWM16: EPWM16 module
  *                               - EPWM17: EPWM17 module
  *                               - EPWM18: EPWM18 module
  * \param  windowLengthCount    Window length count
  */
static inline void EPWM_setDigitalCompareWindowLength (EPWM_TypeDef *epwm, uint16_t windowLengthCount)
{
    WRITE_REG(epwm->DCFWINDOW.WORDVAL, windowLengthCount);
}

/**
  * \brief  Return  digital compare filter blanking window offset count
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the digital compare filter blanking window offset count
  */
static inline uint16_t EPWM_getDigitalCompareBlankingWindowOffsetCount (EPWM_TypeDef *epwm)
{
    return (READ_REG(epwm->DCFOFFSETCNT.WORDVAL));
}

/**
  * \brief  Return  digital compare filter blanking window length count
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the digital compare filter blanking window length count
  */
static inline uint16_t EPWM_getDigitalCompareBlankingWindowLengthCount (EPWM_TypeDef *epwm)
{
    return (READ_REG(epwm->DCFWINDOWCNT.WORDVAL));
}

/**
  * \brief  Set the digital compare event source
  * \param  epwm             EPWMx pointer to a EPWM_TypeDef structure
  *                           - EPWM1:  EPWM1 module
  *                           - EPWM2:  EPWM2 module
  *                           - EPWM3:  EPWM3 module
  *                           - EPWM4:  EPWM4 module
  *                           - EPWM5:  EPWM5 module
  *                           - EPWM6:  EPWM6 module
  *                           - EPWM7:  EPWM7 module
  *                           - EPWM8:  EPWM8 module
  *                           - EPWM9:  EPWM9 module
  *                           - EPWM10: EPWM10 module
  *                           - EPWM11: EPWM11 module
  *                           - EPWM12: EPWM12 module
  *                           - EPWM13: EPWM13 module
  *                           - EPWM14: EPWM14 module
  *                           - EPWM15: EPWM15 module
  *                           - EPWM16: EPWM16 module
  *                           - EPWM17: EPWM17 module
  *                           - EPWM18: EPWM18 module
  * \param  dcModule         Digital compare module
  *                           This parameter can be any value of @ref EPWM_DIGITALCOMPAREMODULE
  * \param  dcEvent          Digital compare event
  *                           This parameter can be any value of @ref EPWM_DIGITALCOMPAREEVENT
  * \param  dcEventSource    Digital compare event source
  *                           This parameter can be any value of @ref EPWM_DIGITALCOMPAREEVENTSOURCE
  */
static inline void EPWM_setDigitalCompareEventSource (EPWM_TypeDef *epwm,
                                                      EPWM_DigitalCompareModule dcModule,
                                                      EPWM_DigitalCompareEvent dcEvent,
                                                      EPWM_DigitalCompareEventSource dcEventSource)
{
    if (dcEvent == EPWM_DC_EVENT_1)
    {
        MODIFY_REG(TYPE32(&(epwm->DCACTL.WORDVAL) + dcModule), EPWM_DCACTL_EVT1SRCSEL, (uint32_t)dcEventSource);
    }
    else
    {
        MODIFY_REG(TYPE32(&(epwm->DCACTL.WORDVAL) + dcModule), EPWM_DCACTL_EVT2SRCSEL, (uint32_t)dcEventSource << 8U);
    }
}

/**
  * \brief  Set the digital compare input sync mode
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  dcModule    Digital compare module
  *                      This parameter can be any value of @ref EPWM_DIGITALCOMPAREMODULE
  * \param  dcEvent     Digital compare event
  *                      This parameter can be any value of @ref EPWM_DIGITALCOMPAREEVENT
  * \param  syncMode    Digital compare event source
  *                      This parameter can be any value of @ref EPWM_DIGITALCOMPARESYNCMODE
  */
static inline void EPWM_setDigitalCompareEventSyncMode (EPWM_TypeDef *epwm,
                                                        EPWM_DigitalCompareModule dcModule,
                                                        EPWM_DigitalCompareEvent dcEvent,
                                                        EPWM_DigitalCompareSyncMode syncMode)
{
    if (dcEvent == EPWM_DC_EVENT_1)
    {
        MODIFY_REG(TYPE32(&(epwm->DCACTL.WORDVAL) + dcModule), EPWM_DCACTL_EVT1FRCSYNCSEL, (uint32_t)syncMode << 1U);
    }
    else
    {
        MODIFY_REG(TYPE32(&(epwm->DCACTL.WORDVAL) + dcModule), EPWM_DCACTL_EVT2FRCSYNCSEL, (uint32_t)syncMode << 9U);
    }
}

/**
  * \brief  Enable digital compare to ADC start of conversion
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  dcModule    Digital compare module
  *                      This parameter can be any value of @ref EPWM_DIGITALCOMPAREMODULE
  */
static inline void EPWM_enableDigitalCompareADCTrigger (EPWM_TypeDef *epwm, EPWM_DigitalCompareModule dcModule)
{
    SET_BIT(TYPE32(&(epwm->DCACTL.WORDVAL) + dcModule), EPWM_DCACTL_EVT1SOCE);
}

/**
  * \brief  Disable digital compare from ADC start of conversion
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  dcModule    Digital compare module
  *                      This parameter can be any value of @ref EPWM_DIGITALCOMPAREMODULE
  */
static inline void EPWM_disableDigitalCompareADCTrigger (EPWM_TypeDef *epwm, EPWM_DigitalCompareModule dcModule)
{
    CLEAR_BIT(TYPE32(&(epwm->DCACTL.WORDVAL) + dcModule), EPWM_DCACTL_EVT1SOCE);
}

/**
  * \brief  Enable digital compare to generate sync out event
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  dcModule    Digital compare module
  *                      This parameter can be any value of @ref EPWM_DIGITALCOMPAREMODULE
  */
static inline void EPWM_enableDigitalCompareSyncEvent (EPWM_TypeDef *epwm, EPWM_DigitalCompareModule dcModule)
{
    SET_BIT(TYPE32(&(epwm->DCACTL.WORDVAL) + dcModule), EPWM_DCACTL_EVT1SYNCE);
}

/**
  * \brief  Disable digital compare to generate sync out event
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  dcModule    Digital compare module
  *                      This parameter can be any value of @ref EPWM_DIGITALCOMPAREMODULE
  */
static inline void EPWM_disableDigitalCompareSyncEvent (EPWM_TypeDef *epwm, EPWM_DigitalCompareModule dcModule)
{
    CLEAR_BIT(TYPE32(&(epwm->DCACTL.WORDVAL) + dcModule), EPWM_DCACTL_EVT1SYNCE);
}

/**
  * \brief  Set the digital compare CBC latch mode
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                       - EPWM1:  EPWM1 module
  *                       - EPWM2:  EPWM2 module
  *                       - EPWM3:  EPWM3 module
  *                       - EPWM4:  EPWM4 module
  *                       - EPWM5:  EPWM5 module
  *                       - EPWM6:  EPWM6 module
  *                       - EPWM7:  EPWM7 module
  *                       - EPWM8:  EPWM8 module
  *                       - EPWM9:  EPWM9 module
  *                       - EPWM10: EPWM10 module
  *                       - EPWM11: EPWM11 module
  *                       - EPWM12: EPWM12 module
  *                       - EPWM13: EPWM13 module
  *                       - EPWM14: EPWM14 module
  *                       - EPWM15: EPWM15 module
  *                       - EPWM16: EPWM16 module
  *                       - EPWM17: EPWM17 module
  *                       - EPWM18: EPWM18 module
  * \param  dcModule     Digital compare module
  *                       This parameter can be any value of @ref EPWM_DIGITALCOMPAREMODULE
  * \param  dcEvent      Digital compare event
  *                       This parameter can be any value of @ref EPWM_DIGITALCOMPAREEVENT
  * \param  latchMode    Latch mode
  *                       This parameter can be any value of @ref EPWM_DIGITALCOMPARECBCLATCHMODE
  */
static inline void EPWM_setDigitalCompareCBCLatchMode (EPWM_TypeDef *epwm,
                                                       EPWM_DigitalCompareModule dcModule,
                                                       EPWM_DigitalCompareEvent dcEvent,
                                                       EPWM_DigitalCompareCBCLatchMode latchMode)
{
    if (dcEvent == EPWM_DC_EVENT_1)
    {
        MODIFY_REG(TYPE32(&(epwm->DCACTL.WORDVAL) + dcModule), EPWM_DCACTL_EVT1LATSEL, (uint32_t)latchMode << 4U);
    }
    else
    {
        MODIFY_REG(TYPE32(&(epwm->DCACTL.WORDVAL) + dcModule), EPWM_DCACTL_EVT2LATSEL, (uint32_t)latchMode << 12U);
    }
}

/**
  * \brief  Select digital compare CBC latch clear event
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  dcModule      Digital compare module
  *                        This parameter can be any value of @ref EPWM_DIGITALCOMPAREMODULE
  * \param  dcEvent       Digital compare event
  *                        This parameter can be any value of @ref EPWM_DIGITALCOMPAREEVENT
  * \param  clearEvent    Latch mode
  *                        This parameter can be any value of @ref EPWM_DIGITALCOMPARECBCLATCHCLEAREVENT
  */
static inline void EPWM_selectDigitalCompareCBCLatchClearEvent (EPWM_TypeDef *epwm,
                                                                EPWM_DigitalCompareModule dcModule,
                                                                EPWM_DigitalCompareEvent dcEvent,
                                                                EPWM_DigitalCompareCBCLatchClearEvent clearEvent)
{
    if (dcEvent == EPWM_DC_EVENT_1)
    {
        MODIFY_REG(TYPE32(&(epwm->DCACTL.WORDVAL) + dcModule),
                   EPWM_DCACTL_EVT1LATCLRSEL_M,
                   (uint32_t)clearEvent << EPWM_DCACTL_EVT1LATCLRSEL_S);
    }
    else
    {
        MODIFY_REG(TYPE32(&(epwm->DCACTL.WORDVAL) + dcModule),
                   EPWM_DCACTL_EVT2LATCLRSEL_M,
                   (uint32_t)clearEvent << EPWM_DCACTL_EVT2LATCLRSEL_S);
    }
}

/**
  * \brief  Gets the digital compare CBC latch status
  * \param  epwm        EPWMx pointer to a EPWM_TypeDef structure
  *                      - EPWM1:  EPWM1 module
  *                      - EPWM2:  EPWM2 module
  *                      - EPWM3:  EPWM3 module
  *                      - EPWM4:  EPWM4 module
  *                      - EPWM5:  EPWM5 module
  *                      - EPWM6:  EPWM6 module
  *                      - EPWM7:  EPWM7 module
  *                      - EPWM8:  EPWM8 module
  *                      - EPWM9:  EPWM9 module
  *                      - EPWM10: EPWM10 module
  *                      - EPWM11: EPWM11 module
  *                      - EPWM12: EPWM12 module
  *                      - EPWM13: EPWM13 module
  *                      - EPWM14: EPWM14 module
  *                      - EPWM15: EPWM15 module
  *                      - EPWM16: EPWM16 module
  *                      - EPWM17: EPWM17 module
  *                      - EPWM18: EPWM18 module
  * \param  dcModule    Digital compare module
  *                      This parameter can be any value of @ref EPWM_DIGITALCOMPAREMODULE
  * \param  dcEvent     Digital compare event
  *                      This parameter can be any value of @ref EPWM_DIGITALCOMPAREEVENT
  * \return Returns Digital Compare CBC latch status
  *                      - 1 : CBC latch is enabled
  *                      - 0 : CBC latch is disabled
  */
static inline bool EPWM_getDigitalCompareCBCLatchStatus (EPWM_TypeDef *epwm,
                                                         EPWM_DigitalCompareModule dcModule,
                                                         EPWM_DigitalCompareEvent dcEvent)
{
    uint16_t status;
    if (dcEvent == EPWM_DC_EVENT_1)
    {
        status = READ_REG(TYPE32(&(epwm->DCACTL.WORDVAL) + dcModule)) & EPWM_DCACTL_EVT1LAT;
    }
    else
    {
        status = READ_REG(TYPE32(&(epwm->DCACTL.WORDVAL) + dcModule)) & EPWM_DCACTL_EVT2LAT;
    }
    return (status != 0U);
}

/**
  * \brief   Enable digital compare counter capture
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableDigitalCompareCounterCapture (EPWM_TypeDef *epwm)
{
    SET_BIT((epwm->DCCAPCTL.WORDVAL), EPWM_DCCAPCTL_CAPE);
}

/**
  * \brief  Disables digital compare counter capture
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableDigitalCompareCounterCapture (EPWM_TypeDef *epwm)
{
    CLEAR_BIT((epwm->DCCAPCTL.WORDVAL), EPWM_DCCAPCTL_CAPE);
}

/**
  * \brief  Set digital compare counter shadow mode
  * \param  epwm                EPWMx pointer to a EPWM_TypeDef structure
  *                              - EPWM1:  EPWM1 module
  *                              - EPWM2:  EPWM2 module
  *                              - EPWM3:  EPWM3 module
  *                              - EPWM4:  EPWM4 module
  *                              - EPWM5:  EPWM5 module
  *                              - EPWM6:  EPWM6 module
  *                              - EPWM7:  EPWM7 module
  *                              - EPWM8:  EPWM8 module
  *                              - EPWM9:  EPWM9 module
  *                              - EPWM10: EPWM10 module
  *                              - EPWM11: EPWM11 module
  *                              - EPWM12: EPWM12 module
  *                              - EPWM13: EPWM13 module
  *                              - EPWM14: EPWM14 module
  *                              - EPWM15: EPWM15 module
  *                              - EPWM16: EPWM16 module
  *                              - EPWM17: EPWM17 module
  *                              - EPWM18: EPWM18 module
  * \param  enableShadowMode    Enable shadow mode
  */
static inline void EPWM_setDigitalCompareCounterShadowMode (EPWM_TypeDef *epwm, bool enableShadowMode)
{
    if (enableShadowMode)
    {
        CLEAR_BIT((epwm->DCCAPCTL.WORDVAL), EPWM_DCCAPCTL_SHDWMODE);
    }
    else
    {
        SET_BIT((epwm->DCCAPCTL.WORDVAL), EPWM_DCCAPCTL_SHDWMODE);
    }
}

/**
  * \brief  Return the digital compare capture status
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns true(false) if a(no) DC capture event has occurs
  *                   - 1 : a DC capture event has occurs
  *                   - 0 : no DC Capture event has occurred
  */
static inline bool EPWM_getDigitalCompareCaptureStatus (EPWM_TypeDef *epwm)
{
    return (((epwm->DCCAPCTL.WORDVAL & EPWM_DCCAPCTL_CAPSTS) == EPWM_DCCAPCTL_CAPSTS) ? 1U : 0U);
}

/**
  * \brief  Clears digital compare capture latched status flag
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_clearDigitalCompareCaptureStatusFlag (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->DCCAPCTL.WORDVAL, EPWM_DCCAPCTL_CAPCLR);
}

/**
  * \brief  Configure digital compare counter capture mode
  * \param  epwm                EPWMx pointer to a EPWM_TypeDef structure
  *                              - EPWM1: EPWM1 module
  *                              - EPWM2: EPWM2 module
  *                              - EPWM3: EPWM3 module
  *                              - EPWM4: EPWM4 module
  *                              - EPWM5: EPWM5 module
  *                              - EPWM6: EPWM6 module
  *                              - EPWM7: EPWM7 module
  *                              - EPWM8: EPWM8 module
  * \param  disableClearMode    Disable clear mode
  */
static inline void EPWM_configureDigitalCompareCounterCaptureMode (EPWM_TypeDef *epwm, bool disableClearMode)
{
    if (disableClearMode)
    {
        SET_BIT(epwm->DCCAPCTL.WORDVAL, EPWM_DCCAPCTL_CAPMODE);
    }
    else
    {
        CLEAR_BIT(epwm->DCCAPCTL.WORDVAL, EPWM_DCCAPCTL_CAPMODE);
    }
}

/**
  * \brief  Return the digital compare capture Count
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the digital compare capture count
  */
static inline uint16_t EPWM_getDigitalCompareCaptureCount (EPWM_TypeDef *epwm)
{
    return READ_REG(epwm->DCCAP.WORDVAL);
}

/**
  * \brief  Enables the digital stroke comparison combination input function
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \param  tripInput    Trip input
  *                       This parameter can be any value of @ref EPWM_DCAHTRIPSELCONF
  * \param  dcType       Digital compare type
  *                       This parameter can be any value of @ref EPWM_DIGITALCOMPARETYPE
  */
static inline void EPWM_enableDigitalCompareTripCombinationInput (EPWM_TypeDef *epwm,
                                                                  uint16_t tripInput,
                                                                  EPWM_DigitalCompareType dcType)
{
    SET_BIT(TYPE32(&(epwm->DCAHTRIPSEL.WORDVAL) + dcType), tripInput);
    SET_BIT(epwm->DCTRIPSEL.WORDVAL, (0xFU << ((uint32_t)dcType << 2U)));
}

/**
  * \brief  Disable the digital stroke comparison combination input function
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \param  tripInput    Trip input
  *                       This parameter can be any value of @ref EPWM_DCAHTRIPSELCONF
  * \param  dcType       Digital compare type
  *                       This parameter can be any value of @ref EPWM_DIGITALCOMPARETYPE
  */
static inline void EPWM_disableDigitalCompareTripCombinationInput (EPWM_TypeDef *epwm,
                                                                   uint16_t tripInput,
                                                                   EPWM_DigitalCompareType dcType)
{
    CLEAR_BIT(TYPE32(&(epwm->DCAHTRIPSEL.WORDVAL) + dcType), tripInput);
}

/**
  * \brief  Enable valley capture mode
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableValleyCapture (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->VCAPCTL.WORDVAL, EPWM_VCAPCTL_VCAPE);
}

/**
  * \brief  Disable valley capture mode
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableValleyCapture (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->VCAPCTL.WORDVAL, EPWM_VCAPCTL_VCAPE);
}

/**
  * \brief  Start valley capture mode
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_startValleyCapture (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->VCAPCTL.WORDVAL, EPWM_VCAPCTL_VCAPSTART);
}

/**
  * \brief  Set valley capture trigger source
  * \param  epwm       EPWMx pointer to a EPWM_TypeDef structure
  *                     - EPWM1:  EPWM1 module
  *                     - EPWM2:  EPWM2 module
  *                     - EPWM3:  EPWM3 module
  *                     - EPWM4:  EPWM4 module
  *                     - EPWM5:  EPWM5 module
  *                     - EPWM6:  EPWM6 module
  *                     - EPWM7:  EPWM7 module
  *                     - EPWM8:  EPWM8 module
  *                     - EPWM9:  EPWM9 module
  *                     - EPWM10: EPWM10 module
  *                     - EPWM11: EPWM11 module
  *                     - EPWM12: EPWM12 module
  *                     - EPWM13: EPWM13 module
  *                     - EPWM14: EPWM14 module
  *                     - EPWM15: EPWM15 module
  *                     - EPWM16: EPWM16 module
  *                     - EPWM17: EPWM17 module
  *                     - EPWM18: EPWM18 module
  * \param  trigger    Valley trigger source
  *                     This parameter can be any value of @ref EPWM_VALLEYTRIGGERSOURCE
  */
static inline void EPWM_setValleyTriggerSource (EPWM_TypeDef *epwm, EPWM_ValleyTriggerSource trigger)
{
    MODIFY_REG(epwm->VCAPCTL.WORDVAL, EPWM_VCAPCTL_TRIGSEL_M, (uint32_t)trigger << EPWM_VCAPCTL_TRIGSEL_S);
}

/**
  * \brief  Set valley capture trigger edge counts
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  startCount    Valley trigger start edge count
  */
static inline void EPWM_setValleyTriggerEdgeCounts (EPWM_TypeDef *epwm, uint16_t startCount,
                                                    uint16_t stopCount)
{
    MODIFY_REG(epwm->VCNTCFG.WORDVAL, EPWM_VCNTCFG_STARTEDGE_M | EPWM_VCNTCFG_STOPEDGE_M,
               (startCount << EPWM_VCNTCFG_STARTEDGE_S | (stopCount << EPWM_VCNTCFG_STOPEDGE_S)));
}

/**
  * \brief  Enable valley hardware delay
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableValleyHWDelay (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->VCAPCTL.WORDVAL, EPWM_VCAPCTL_EDGEFILTDLYSEL);
}

/**
  * \brief  Disable valley hardware delay
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableValleyHWDelay (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->VCAPCTL.WORDVAL, EPWM_VCAPCTL_EDGEFILTDLYSEL);
}

/**
  * \brief  Set valley software delay delay values
  * \param  epwm                EPWMx pointer to a EPWM_TypeDef structure
  *                              - EPWM1:  EPWM1 module
  *                              - EPWM2:  EPWM2 module
  *                              - EPWM3:  EPWM3 module
  *                              - EPWM4:  EPWM4 module
  *                              - EPWM5:  EPWM5 module
  *                              - EPWM6:  EPWM6 module
  *                              - EPWM7:  EPWM7 module
  *                              - EPWM8:  EPWM8 module
  *                              - EPWM9:  EPWM9 module
  *                              - EPWM10: EPWM10 module
  *                              - EPWM11: EPWM11 module
  *                              - EPWM12: EPWM12 module
  *                              - EPWM13: EPWM13 module
  *                              - EPWM14: EPWM14 module
  *                              - EPWM15: EPWM15 module
  *                              - EPWM16: EPWM16 module
  *                              - EPWM17: EPWM17 module
  *                              - EPWM18: EPWM18 module
  * \param  delayOffsetValue    Valley trigger software delay value
  */
static inline void EPWM_setValleySWDelayValue (EPWM_TypeDef *epwm, uint16_t delayOffsetValue)
{
    WRITE_REG(epwm->SWVDELVAL.WORDVAL, delayOffsetValue);
}

/**
  * \brief  Set valley valley delay frequency divider
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                       - EPWM1:  EPWM1 module
  *                       - EPWM2:  EPWM2 module
  *                       - EPWM3:  EPWM3 module
  *                       - EPWM4:  EPWM4 module
  *                       - EPWM5:  EPWM5 module
  *                       - EPWM6:  EPWM6 module
  *                       - EPWM7:  EPWM7 module
  *                       - EPWM8:  EPWM8 module
  *                       - EPWM9:  EPWM9 module
  *                       - EPWM10: EPWM10 module
  *                       - EPWM11: EPWM11 module
  *                       - EPWM12: EPWM12 module
  *                       - EPWM13: EPWM13 module
  *                       - EPWM14: EPWM14 module
  *                       - EPWM15: EPWM15 module
  *                       - EPWM16: EPWM16 module
  *                       - EPWM17: EPWM17 module
  *                       - EPWM18: EPWM18 module
  * \param  delayMode    Valley trigger software delay mode
  *                       This parameter can be any value of @ref EPWM_VALLEYDELAYMODE
  */
static inline void EPWM_setValleyDelayDivider (EPWM_TypeDef *epwm, EPWM_ValleyDelayMode delayMode)
{
    MODIFY_REG(epwm->VCAPCTL.WORDVAL, EPWM_VCAPCTL_VDELAYDIV_M, (uint16_t)delayMode << EPWM_VCAPCTL_VDELAYDIV_S);
}

/**
  * \brief  Get the valley edge status
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \param  edge    The start or stop edge
  *                  This parameter can be any value of @ref EPWM_VALLEYCOUNTEREDGE
  * \return Returns the status of the edge
  *                  - 1  : the specified edge has occurred
  *                  - 0  : the specified edge has not occurred
  */
static inline bool EPWM_getValleyEdgeStatus (EPWM_TypeDef *epwm, EPWM_ValleyCounterEdge edge)
{
    if (edge == EPWM_VALLEY_COUNT_START_EDGE)
    {
        return ((((epwm->VCNTCFG.WORDVAL) & EPWM_VCNTCFG_STARTEDGESTS) == EPWM_VCNTCFG_STARTEDGESTS) ? 1UL : 0UL);
    }
    else
    {
        return ((((epwm->VCNTCFG.WORDVAL) & EPWM_VCNTCFG_STOPEDGESTS) == EPWM_VCNTCFG_STOPEDGESTS) ? 1UL : 0UL);
    }
}

/**
  * \brief  Get the valley counter value
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the valley counter value
  */
static inline uint16_t EPWM_getValleyCount (EPWM_TypeDef *epwm)
{
    return (epwm->VCNTVAL.WORDVAL);
}

/**
  * \brief  Get the valley hardware delay value
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the valley delay count
  */
static inline uint16_t EPWM_getValleyHWDelay (EPWM_TypeDef *epwm)
{
    return (epwm->HWVDELVAL.WORDVAL);
}

/**
  * \brief  Enable global shadow load mode
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableGlobalLoad (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->GLDCTL.WORDVAL, EPWM_GLDCTL_GLD);
}

/**
  * \brief  Disable global shadow load mode
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableGlobalLoad (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->GLDCTL.WORDVAL, EPWM_GLDCTL_GLD);
}

/**
  * \brief  Set the global load trigger
  * \param  epwm           EPWMx pointer to a EPWM_TypeDef structure
  *                         - EPWM1:  EPWM1 module
  *                         - EPWM2:  EPWM2 module
  *                         - EPWM3:  EPWM3 module
  *                         - EPWM4:  EPWM4 module
  *                         - EPWM5:  EPWM5 module
  *                         - EPWM6:  EPWM6 module
  *                         - EPWM7:  EPWM7 module
  *                         - EPWM8:  EPWM8 module
  *                         - EPWM9:  EPWM9 module
  *                         - EPWM10: EPWM10 module
  *                         - EPWM11: EPWM11 module
  *                         - EPWM12: EPWM12 module
  *                         - EPWM13: EPWM13 module
  *                         - EPWM14: EPWM14 module
  *                         - EPWM15: EPWM15 module
  *                         - EPWM16: EPWM16 module
  *                         - EPWM17: EPWM17 module
  *                         - EPWM18: EPWM18 module
  * \param  loadTrigger    The global load trigger
  *                         This parameter can be any value of @ref EPWM_GLOBALLOADTRIGGER
  */
static inline void EPWM_setGlobalLoadTrigger (EPWM_TypeDef *epwm, EPWM_GlobalLoadTrigger loadTrigger)
{
    MODIFY_REG(epwm->GLDCTL.WORDVAL, EPWM_GLDCTL_GLDMODE_M, (uint32_t)loadTrigger << EPWM_GLDCTL_GLDMODE_S);
}

/**
  * \brief  Sets the global load event prescaler
  * \param  epwm                  EPWMx pointer to a EPWM_TypeDef structure
  *                                - EPWM1:  EPWM1 module
  *                                - EPWM2:  EPWM2 module
  *                                - EPWM3:  EPWM3 module
  *                                - EPWM4:  EPWM4 module
  *                                - EPWM5:  EPWM5 module
  *                                - EPWM6:  EPWM6 module
  *                                - EPWM7:  EPWM7 module
  *                                - EPWM8:  EPWM8 module
  *                                - EPWM9:  EPWM9 module
  *                                - EPWM10: EPWM10 module
  *                                - EPWM11: EPWM11 module
  *                                - EPWM12: EPWM12 module
  *                                - EPWM13: EPWM13 module
  *                                - EPWM14: EPWM14 module
  *                                - EPWM15: EPWM15 module
  *                                - EPWM16: EPWM16 module
  *                                - EPWM17: EPWM17 module
  *                                - EPWM18: EPWM18 module
  * \param  prescalePulseCount    The global load event prescale pulse count
  */
static inline void EPWM_setGlobalLoadEventPrescale (EPWM_TypeDef *epwm, uint16_t prescalePulseCount)
{
    MODIFY_REG(epwm->GLDCTL.WORDVAL, EPWM_GLDCTL_GLDPRD_M, prescalePulseCount << EPWM_GLDCTL_GLDPRD_S);
}

/**
  * \brief  Return the number of global load pulse event counts
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \return Returns the number of global load pulse events
  */
static inline uint16_t EPWM_getGlobalLoadEventCount (EPWM_TypeDef *epwm)
{
    return ((epwm->GLDCTL.WORDVAL >> EPWM_GLDCTL_GLDCNT_S) & 0x7U);
}

/**
  * \brief  Disable global load one-shot trigger mode
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableGlobalLoadOneShotMode (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->GLDCTL.WORDVAL, EPWM_GLDCTL_OSHTMODE);
}

/**
  * \brief  Enable global load one-shot trigger mode
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableGlobalLoadOneShotMode (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->GLDCTL.WORDVAL, EPWM_GLDCTL_OSHTMODE);
}

/**
  * \brief  Set Set one-shot trigger latch
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_setGlobalLoadOneShotLatch (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->GLDCTL2.WORDVAL, EPWM_GLDCTL2_OSHTLD);
}

/**
  * \brief  Force a software one shot global load event
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_forceGlobalLoadOneShotEvent (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->GLDCTL2.WORDVAL, EPWM_GLDCTL2_GFRCLD);
}

/**
  * \brief  Enables the global load register of the module
  * \param  epwm            EPWMx pointer to a EPWM_TypeDef structure
  *                          - EPWM1:  EPWM1 module
  *                          - EPWM2:  EPWM2 module
  *                          - EPWM3:  EPWM3 module
  *                          - EPWM4:  EPWM4 module
  *                          - EPWM5:  EPWM5 module
  *                          - EPWM6:  EPWM6 module
  *                          - EPWM7:  EPWM7 module
  *                          - EPWM8:  EPWM8 module
  *                          - EPWM9:  EPWM9 module
  *                          - EPWM10: EPWM10 module
  *                          - EPWM11: EPWM11 module
  *                          - EPWM12: EPWM12 module
  *                          - EPWM13: EPWM13 module
  *                          - EPWM14: EPWM14 module
  *                          - EPWM15: EPWM15 module
  *                          - EPWM16: EPWM16 module
  *                          - EPWM17: EPWM17 module
  *                          - EPWM18: EPWM18 module
  * \param  loadRegister    The global load register to be loaded
  *                          This parameter can be any value of @ref EPWM_GLDCFGCONF
  */
static inline void EPWM_enableGlobalLoadRegisters (EPWM_TypeDef *epwm, uint16_t loadRegister)
{
    SET_BIT(epwm->GLDCFG.WORDVAL, loadRegister);
}

/**
  * \brief  Disable the global load register of the module
  * \param  epwm            EPWMx pointer to a EPWM_TypeDef structure
  *                          - EPWM1:  EPWM1 module
  *                          - EPWM2:  EPWM2 module
  *                          - EPWM3:  EPWM3 module
  *                          - EPWM4:  EPWM4 module
  *                          - EPWM5:  EPWM5 module
  *                          - EPWM6:  EPWM6 module
  *                          - EPWM7:  EPWM7 module
  *                          - EPWM8:  EPWM8 module
  *                          - EPWM9:  EPWM9 module
  *                          - EPWM10: EPWM10 module
  *                          - EPWM11: EPWM11 module
  *                          - EPWM12: EPWM12 module
  *                          - EPWM13: EPWM13 module
  *                          - EPWM14: EPWM14 module
  *                          - EPWM15: EPWM15 module
  *                          - EPWM16: EPWM16 module
  *                          - EPWM17: EPWM17 module
  *                          - EPWM18: EPWM18 module
  * \param  loadRegister    The global load register to be loaded
  *                          This parameter can be any value of @ref EPWM_GLDCFGCONF
  */
static inline void EPWM_disableGlobalLoadRegisters (EPWM_TypeDef *epwm, uint16_t loadRegister)
{
    CLEAR_BIT(epwm->GLDCFG.WORDVAL, loadRegister);
}

/**
  * \brief  This function enables the ePWM XCMP mode.
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableXCMPMode (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->XCMPCTL1.WORDVAL, EPWM_XCMPCTL1_XCMPEN);
}

/**
  * \brief  This function disables the ePWM XCMP mode.
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableXCMPMode (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->XCMPCTL1.WORDVAL, EPWM_XCMPCTL1_XCMPEN);
}

/**
  * \brief  This function splits 8 XCMP registers between CMPA and CMPB equally.
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableSplitXCMP (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->XCMPCTL1.WORDVAL, EPWM_XCMPCTL1_XCMPSPLIT);
}

/**
  * \brief  This function allocates 8 XCMP registers to CMPA.
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableSplitXCMP (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->XCMPCTL1.WORDVAL, EPWM_XCMPCTL1_XCMPSPLIT);
}

/**
  * \brief  This function allocates XCMPA_ALLOC registers to CMPA.
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                       - EPWM1:  EPWM1 module
  *                       - EPWM2:  EPWM2 module
  *                       - EPWM3:  EPWM3 module
  *                       - EPWM4:  EPWM4 module
  *                       - EPWM5:  EPWM5 module
  *                       - EPWM6:  EPWM6 module
  *                       - EPWM7:  EPWM7 module
  *                       - EPWM8:  EPWM8 module
  *                       - EPWM9:  EPWM9 module
  *                       - EPWM10: EPWM10 module
  *                       - EPWM11: EPWM11 module
  *                       - EPWM12: EPWM12 module
  *                       - EPWM13: EPWM13 module
  *                       - EPWM14: EPWM14 module
  *                       - EPWM15: EPWM15 module
  *                       - EPWM16: EPWM16 module
  *                       - EPWM17: EPWM17 module
  *                       - EPWM18: EPWM18 module
  * \param  alloctype    Range of XCMPA_ALLOC registers to be allocated to CMPA
  *                       This parameter can be any value of @ref EPWM_XCMPALLOCTIONCMPA
  */
static inline void EPWM_allocAXCMP (EPWM_TypeDef *epwm, EPWM_XCMPAllocationCompareA alloctype)
{
    MODIFY_REG(epwm->XCMPCTL1.WORDVAL, EPWM_XCMPCTL1_XCMPA_ALLOC_M, (alloctype << EPWM_XCMPCTL1_XCMPA_ALLOC_S));
}

/**
  * \brief  This function allocates XCMPB_ALLOC registers to CMPB.
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                       - EPWM1:  EPWM1 module
  *                       - EPWM2:  EPWM2 module
  *                       - EPWM3:  EPWM3 module
  *                       - EPWM4:  EPWM4 module
  *                       - EPWM5:  EPWM5 module
  *                       - EPWM6:  EPWM6 module
  *                       - EPWM7:  EPWM7 module
  *                       - EPWM8:  EPWM8 module
  *                       - EPWM9:  EPWM9 module
  *                       - EPWM10: EPWM10 module
  *                       - EPWM11: EPWM11 module
  *                       - EPWM12: EPWM12 module
  *                       - EPWM13: EPWM13 module
  *                       - EPWM14: EPWM14 module
  *                       - EPWM15: EPWM15 module
  *                       - EPWM16: EPWM16 module
  *                       - EPWM17: EPWM17 module
  *                       - EPWM18: EPWM18 module
  * \param  alloctype    Range of XCMPB_ALLOC registers to be allocated to CMPB
  *                       This parameter can be any value of @ref EPWM_XCMPALLOCTIONCMPB 
  */
static inline void EPWM_allocBXCMP (EPWM_TypeDef *epwm, EPWM_XCMPAllocationCompareB alloctype)
{
    MODIFY_REG(epwm->XCMPCTL1.WORDVAL, EPWM_XCMPCTL1_XCMPB_ALLOC_M, (alloctype << EPWM_XCMPCTL1_XCMPB_ALLOC_S));
}

/**
  * \brief  This function select Load mode for Shadow registers.
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \param  mode    Load mode selection for Shadow registers
  *                  This parameter can be any value of @ref EPWM_XCMPMODELOADCTLLOADMODE 
  */
static inline void EPWM_setXCMPLoadMode (EPWM_TypeDef *epwm, EPWM_XCMPModeLoadCtlLoadMode mode)
{
    MODIFY_REG(epwm->XLOADCTL.WORDVAL, EPWM_XLOADCTL_LOADMODE_M, (mode << EPWM_XLOADCTL_LOADMODE_S));
}

/**
  * \brief  This function select Shadow Register Level Allocation.
  * \param  epwm     EPWMx pointer to a EPWM_TypeDef structure
  *                   - EPWM1:  EPWM1 module
  *                   - EPWM2:  EPWM2 module
  *                   - EPWM3:  EPWM3 module
  *                   - EPWM4:  EPWM4 module
  *                   - EPWM5:  EPWM5 module
  *                   - EPWM6:  EPWM6 module
  *                   - EPWM7:  EPWM7 module
  *                   - EPWM8:  EPWM8 module
  *                   - EPWM9:  EPWM9 module
  *                   - EPWM10: EPWM10 module
  *                   - EPWM11: EPWM11 module
  *                   - EPWM12: EPWM12 module
  *                   - EPWM13: EPWM13 module
  *                   - EPWM14: EPWM14 module
  *                   - EPWM15: EPWM15 module
  *                   - EPWM16: EPWM16 module
  *                   - EPWM17: EPWM17 module
  *                   - EPWM18: EPWM18 module
  * \param  level    Shadow register level allocation
  *                   This parameter can be any value of @ref EPWM_XCMPXLOADCTLSHDWLEVEL 
  */
static inline void EPWM_setXCMPShadowLevel (EPWM_TypeDef *epwm, EPWM_XCMPModeLoadCtlShdwLevel level)
{
    MODIFY_REG(epwm->XLOADCTL.WORDVAL, EPWM_XLOADCTL_SHDWLEVEL_M, (level << EPWM_XLOADCTL_SHDWLEVEL_S));
}

/**
  * \brief  This function select which shadow register set is in use.
  * \param  epwm   EPWMx pointer to a EPWM_TypeDef structure
  *                 - EPWM1:  EPWM1 module
  *                 - EPWM2:  EPWM2 module
  *                 - EPWM3:  EPWM3 module
  *                 - EPWM4:  EPWM4 module
  *                 - EPWM5:  EPWM5 module
  *                 - EPWM6:  EPWM6 module
  *                 - EPWM7:  EPWM7 module
  *                 - EPWM8:  EPWM8 module
  *                 - EPWM9:  EPWM9 module
  *                 - EPWM10: EPWM10 module
  *                 - EPWM11: EPWM11 module
  *                 - EPWM12: EPWM12 module
  *                 - EPWM13: EPWM13 module
  *                 - EPWM14: EPWM14 module
  *                 - EPWM15: EPWM15 module
  *                 - EPWM16: EPWM16 module
  *                 - EPWM17: EPWM17 module
  *                 - EPWM18: EPWM18 module
  * \param  ptr    This param indicates current shadow buffer in use
  *                 This parameter can be any value of @ref EPWM_XCMPXLOADCTLSHDWBUFPTR 
  */
static inline void EPWM_setXCMPShadowBufPtrLoadOnce (EPWM_TypeDef *epwm, EPWM_XCMPXloadCtlShdwBufPtr ptr)
{
    MODIFY_REG(epwm->XLOADCTL.WORDVAL, EPWM_XLOADCTL_SHDWBUFPTR_LOADONCE_M, (ptr << EPWM_XLOADCTL_SHDWBUFPTR_LOADONCE_S));
}

/**
  * \brief  This function gives us choice to select how many times shadow buffer 2 or 3 is applied. 
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                       - EPWM1:  EPWM1 module
  *                       - EPWM2:  EPWM2 module
  *                       - EPWM3:  EPWM3 module
  *                       - EPWM4:  EPWM4 module
  *                       - EPWM5:  EPWM5 module
  *                       - EPWM6:  EPWM6 module
  *                       - EPWM7:  EPWM7 module
  *                       - EPWM8:  EPWM8 module
  *                       - EPWM9:  EPWM9 module
  *                       - EPWM10: EPWM10 module
  *                       - EPWM11: EPWM11 module
  *                       - EPWM12: EPWM12 module
  *                       - EPWM13: EPWM13 module
  *                       - EPWM14: EPWM14 module
  *                       - EPWM15: EPWM15 module
  *                       - EPWM16: EPWM16 module
  *                       - EPWM17: EPWM17 module
  *                       - EPWM18: EPWM18 module
  * \param  bufferset    The shadow set number
  *                       - EPWM_XCMP_SHADOW2: set shadow buffer 2
  *                       - EPWM_XCMP_SHADOW3: set shadow buffer 3
  * \param  count        Number of times shadow buffer 2 or 3 is applied
  *                       - 0: Apply shadow buffer 1 time
  *                       - 1: Apply shadow buffer 2 times
  *                       - 2: Apply shadow buffer 3 times
  *                       - 3: Apply shadow buffer 4 times
  *                       - 4: Apply shadow buffer 5 times
  *                       - 5: Apply shadow buffer 6 times
  *                       - 6: Apply shadow buffer 7 times
  *                       - 7: Apply shadow buffer 8 times
  */
static inline void EPWM_setXCMPShadowRepeatBufxCount (EPWM_TypeDef *epwm, uint32_t bufferset, uint32_t count)
{
    MODIFY_REG(epwm->XLOADCTL.WORDVAL, (EPWM_XLOADCTL_RPTBUF2PRD_M << ((bufferset - 2) << 3)), (count << (EPWM_XLOADCTL_RPTBUF2PRD_S + ((bufferset - 2) << 3))));  
}

/**
  * \brief  This function returns how many times shadow buffer 2 or 3 has been be applied before moving to the next buffer. 
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                       - EPWM1:  EPWM1 module
  *                       - EPWM2:  EPWM2 module
  *                       - EPWM3:  EPWM3 module
  *                       - EPWM4:  EPWM4 module
  *                       - EPWM5:  EPWM5 module
  *                       - EPWM6:  EPWM6 module
  *                       - EPWM7:  EPWM7 module
  *                       - EPWM8:  EPWM8 module
  *                       - EPWM9:  EPWM9 module
  *                       - EPWM10: EPWM10 module
  *                       - EPWM11: EPWM11 module
  *                       - EPWM12: EPWM12 module
  *                       - EPWM13: EPWM13 module
  *                       - EPWM14: EPWM14 module
  *                       - EPWM15: EPWM15 module
  *                       - EPWM16: EPWM16 module
  *                       - EPWM17: EPWM17 module
  *                       - EPWM18: EPWM18 module
  * \param  bufferset    The shadow set number
  *                       - EPWM_XCMP_SHADOW2: set shadow buffer 2
  *                       - EPWM_XCMP_SHADOW3: set shadow buffer 3
  * \return Returns how many times shadow buffer 2 or 3 has been be applied
  *          This value is range from 0 to 7
  */
static inline uint32_t EPWM_readXCMPShadowRepeatBufxCount (EPWM_TypeDef *epwm, uint32_t bufferset)
{
    return (((READ_REG(epwm->XLOADCTL.WORDVAL)) >> (EPWM_XLOADCTL_RPTBUF2CNT_S + ((bufferset - 2) << 3))) & (EPWM_XLOADCTL_RPTBUF2CNT_M >> ((bufferset - 2) << 3)));
}

/**
  * \brief  This function enables the ePWM XCMP reload event. 
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableXLoad (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->XLOAD.WORDVAL, EPWM_XLOAD_STARTLD);
}

/**
  * \brief  This function is used for software force loading of the events in global load mode. 
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_forceXLoad (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->XLOAD.WORDVAL, EPWM_XLOAD_FRCLD);
}

/**
  * \brief  This function writes xcmpvalue to XCMP registers. 
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                       - EPWM1:  EPWM1 module
  *                       - EPWM2:  EPWM2 module
  *                       - EPWM3:  EPWM3 module
  *                       - EPWM4:  EPWM4 module
  *                       - EPWM5:  EPWM5 module
  *                       - EPWM6:  EPWM6 module
  *                       - EPWM7:  EPWM7 module
  *                       - EPWM8:  EPWM8 module
  *                       - EPWM9:  EPWM9 module
  *                       - EPWM10: EPWM10 module
  *                       - EPWM11: EPWM11 module
  *                       - EPWM12: EPWM12 module
  *                       - EPWM13: EPWM13 module
  *                       - EPWM14: EPWM14 module
  *                       - EPWM15: EPWM15 module
  *                       - EPWM16: EPWM16 module
  *                       - EPWM17: EPWM17 module
  *                       - EPWM18: EPWM18 module
  * \param  xcmpReg      The XCMP register offset
  *                       This parameter can be any value of @ref EPWM_XCMPREGISTEROFFSET
  * \param  xcmpvalue    The value to be written to XCMP registers
  *                       This value type is unsigned 16
  */
static inline void EPWM_setXCMPRegValue (EPWM_TypeDef *epwm, EPWM_XCMPRegisterOffset xcmpReg, uint32_t xcmpvalue)
{
    MODIFY_REG(TYPE32(&(epwm->XCMP1ACTIVE.WORDVAL) + (xcmpReg >> 2)), HIGH_16BIT_M, (uint32_t)(xcmpvalue << 16));
}

/**
  * \brief  This function writes cmpvalue to CMPC/D shadow registers. 
  * \param  epwm      EPWMx pointer to a EPWM_TypeDef structure
  *                    - EPWM1:  EPWM1 module
  *                    - EPWM2:  EPWM2 module
  *                    - EPWM3:  EPWM3 module
  *                    - EPWM4:  EPWM4 module
  *                    - EPWM5:  EPWM5 module
  *                    - EPWM6:  EPWM6 module
  *                    - EPWM7:  EPWM7 module
  *                    - EPWM8:  EPWM8 module
  *                    - EPWM9:  EPWM9 module
  *                    - EPWM10: EPWM10 module
  *                    - EPWM11: EPWM11 module
  *                    - EPWM12: EPWM12 module
  *                    - EPWM13: EPWM13 module
  *                    - EPWM14: EPWM14 module
  *                    - EPWM15: EPWM15 module
  *                    - EPWM16: EPWM16 module
  *                    - EPWM17: EPWM17 module
  *                    - EPWM18: EPWM18 module
  * \para cmpReg      This is the CMP register offset
  *                    This parameter can be any value of @ref EPWM_XCOMPAREREG
  * \para cmpvalue    This is the value to be written to CMPC/D shadow registers
  *                    This value type is unsigned 16
  * 
  */
static inline void EPWM_setCMPShadowRegValue (EPWM_TypeDef *epwm, EPWM_XCompareReg cmpReg, uint32_t cmpvalue)
{
    MODIFY_REG(TYPE32(&(epwm->CMPCSHDW1.WORDVAL) + (cmpReg >> 2)), LOW_16BIT_M, cmpvalue);
}

/**
  * \brief  This function writes MIN or MAX xcmpvalue to XCMP registers. 
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  xminmaxReg    The XCMP register offset
  *                        This parameter can be any value of @ref EPWM_XMINMAXREG
  * \param  xcmpvalue     The value to be written to XCMP registers
  *                        This value type is unsigned 16
  */
static inline void EPWM_setXMINMAXRegValue (EPWM_TypeDef *epwm, EPWM_XMinMaxReg xminmaxReg, uint32_t xcmpvalue)
{
    MODIFY_REG(TYPE32(&(epwm->XMINMAXACTIVE.WORDVAL) + ((xminmaxReg & 0xFFFE) >> 2)), (LOW_16BIT_M << ((xminmaxReg & 0x1) << 4)), (xcmpvalue << ((xminmaxReg & 0x1) << 4)));
}

/**
  * \brief  This function sets up the Action Qualifier output on ePWM A or ePWMB,
  *         depending on the value of epwmOutput, to a value specified by outPut based
  *         on the input events - specified by event.
  * \param  epwm          EPWMx pointer to a EPWM_TypeDef structure
  *                        - EPWM1:  EPWM1 module
  *                        - EPWM2:  EPWM2 module
  *                        - EPWM3:  EPWM3 module
  *                        - EPWM4:  EPWM4 module
  *                        - EPWM5:  EPWM5 module
  *                        - EPWM6:  EPWM6 module
  *                        - EPWM7:  EPWM7 module
  *                        - EPWM8:  EPWM8 module
  *                        - EPWM9:  EPWM9 module
  *                        - EPWM10: EPWM10 module
  *                        - EPWM11: EPWM11 module
  *                        - EPWM12: EPWM12 module
  *                        - EPWM13: EPWM13 module
  *                        - EPWM14: EPWM14 module
  *                        - EPWM15: EPWM15 module
  *                        - EPWM16: EPWM16 module
  *                        - EPWM17: EPWM17 module
  *                        - EPWM18: EPWM18 module
  * \param  shadowset     The ePWM pin type
  *                        - EPWM_XCMP_ACTIVE:  XCMP set is Active
  *                        - EPWM_XCMP_SHADOW1: XCMP set is Shadow 1
  *                        - EPWM_XCMP_SHADOW2: XCMP set is Shadow 2
  *                        - EPWM_XCMP_SHADOW3: XCMP set is Shadow 3
  * \param  epwmOutput    The XCMP register offset
  *                        - EPWM_AQ_OUTPUT_A: ePWMxA output
  *                        - EPWM_AQ_OUTPUT_B: ePWMxB output
  * \param  output        The value to be written to XCMP registers
  *                        This parameter can be any value of @ref EPWM_ACTIONQUALIFIEROUTPUT
  * \param  event         The value to be written to XCMP registers
  *                        This parameter can be any value of @ref EPWM_XCMPACTIONQUALIFIEROUTPUTEVENT
  */
static inline void EPWM_setXCMPActionQualifierAction (EPWM_TypeDef *epwm, uint32_t shadowset, 
                                                      EPWM_ActionQualifierOutputModule epwmOutput,
                                                      EPWM_ActionQualifierOutput output,
                                                      EPWM_XCMPActionQualifierOutputEvent event)
{
    MODIFY_REG(TYPE32(&(epwm->XAQCTLA.WORDVAL) + ADDRESS_OFFSET_BETWEEN_XAQCTLA * shadowset + (epwmOutput >> 1)), (3UL << (uint32_t)event), ((uint32_t)output << (uint32_t)event));
}

/**
  * \brief  This function enables the ePWM diode emulation mode. 
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableDiodeEmulationMode (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->DECTL.WORDVAL, EPWM_DECTL_ENABLE);
}

/**
  * \brief  This function disables the ePWM diode emulation mode. 
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableDiodeEmulationMode (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->DECTL.WORDVAL, EPWM_DECTL_ENABLE);
}

/**
  * \brief  This function gives us choice to select the mode for Diode emulation mode. 
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  * \param  mode    Load mode selection for Diode emulation mode
  *                  This parameter can be any value of @ref EPWM_DIODEEMULATIONMODE
  */
static inline void EPWM_setDiodeEmulationMode (EPWM_TypeDef *epwm, EPWM_DiodeEmulationMode mode)
{
    MODIFY_REG(epwm->DECTL.WORDVAL, EPWM_DECTL_MODE_M, (mode << EPWM_DECTL_MODE_S));
}

/**
  * \brief  This function determines the blocking window after DEACTIVE flag is cleared
  *         in which setting of DEACTIVE flag is prevented from being set.
  * \param  epwm     EPWMx pointer to a EPWM_TypeDef structure
  *                   - EPWM1:  EPWM1 module
  *                   - EPWM2:  EPWM2 module
  *                   - EPWM3:  EPWM3 module
  *                   - EPWM4:  EPWM4 module
  *                   - EPWM5:  EPWM5 module
  *                   - EPWM6:  EPWM6 module
  *                   - EPWM7:  EPWM7 module
  *                   - EPWM8:  EPWM8 module
  *                   - EPWM9:  EPWM9 module
  *                   - EPWM10: EPWM10 module
  *                   - EPWM11: EPWM11 module
  *                   - EPWM12: EPWM12 module
  *                   - EPWM13: EPWM13 module
  *                   - EPWM14: EPWM14 module
  *                   - EPWM15: EPWM15 module
  *                   - EPWM16: EPWM16 module
  *                   - EPWM17: EPWM17 module
  *                   - EPWM18: EPWM18 module
  * \param  delay    The re-entry delay in terms of number of PWMSYNCOUT events
  *                   This value is range from 0 to 255
  */
static inline void EPWM_setDiodeEmulationReentryDelay (EPWM_TypeDef *epwm, uint32_t delay)
{
    MODIFY_REG(epwm->DECTL.WORDVAL, EPWM_DECTL_REENTRYDLY_M, (delay << EPWM_DECTL_REENTRYDLY_S));
}

/**
  * \brief  This function is used to configure the comparator whose trip sources will be used.
  * \param  epwm      EPWMx pointer to a EPWM_TypeDef structure
  *                    - EPWM1:  EPWM1 module
  *                    - EPWM2:  EPWM2 module
  *                    - EPWM3:  EPWM3 module
  *                    - EPWM4:  EPWM4 module
  *                    - EPWM5:  EPWM5 module
  *                    - EPWM6:  EPWM6 module
  *                    - EPWM7:  EPWM7 module
  *                    - EPWM8:  EPWM8 module
  *                    - EPWM9:  EPWM9 module
  *                    - EPWM10: EPWM10 module
  *                    - EPWM11: EPWM11 module
  *                    - EPWM12: EPWM12 module
  *                    - EPWM13: EPWM13 module
  *                    - EPWM14: EPWM14 module
  *                    - EPWM15: EPWM15 module
  *                    - EPWM16: EPWM16 module
  *                    - EPWM17: EPWM17 module
  *                    - EPWM18: EPWM18 module
  * \param  source    The trip low source
  *                    This parameter can be any value of @ref EPWM_DIODEEMULATIONTRIPLSOURCE
  */
static inline void EPWM_configureDiodeEmulationTripLowSources (EPWM_TypeDef *epwm, 
                                                               EPWM_DiodeEmulationTripLSource source)
{
    MODIFY_REG(epwm->DECOMPSEL.WORDVAL, EPWM_DECOMPSEL_TRIPL_M, (source << EPWM_DECOMPSEL_TRIPL_S));
}

/**
  * \brief  This function is used to configure the comparator whose trip sources will be used.
  * \param  epwm      EPWMx pointer to a EPWM_TypeDef structure
  *                    - EPWM1:  EPWM1 module
  *                    - EPWM2:  EPWM2 module
  *                    - EPWM3:  EPWM3 module
  *                    - EPWM4:  EPWM4 module
  *                    - EPWM5:  EPWM5 module
  *                    - EPWM6:  EPWM6 module
  *                    - EPWM7:  EPWM7 module
  *                    - EPWM8:  EPWM8 module
  *                    - EPWM9:  EPWM9 module
  *                    - EPWM10: EPWM10 module
  *                    - EPWM11: EPWM11 module
  *                    - EPWM12: EPWM12 module
  *                    - EPWM13: EPWM13 module
  *                    - EPWM14: EPWM14 module
  *                    - EPWM15: EPWM15 module
  *                    - EPWM16: EPWM16 module
  *                    - EPWM17: EPWM17 module
  *                    - EPWM18: EPWM18 module
  * \param  source    The trip high source
  *                    This parameter can be any value of @ref EPWM_DIODEEMULATIONTRIPHSOURCE
  */
static inline void EPWM_configureDiodeEmulationTripHighSources (EPWM_TypeDef *epwm, 
                                                                EPWM_DiodeEmulationTripHSource source)
{
    MODIFY_REG(epwm->DECOMPSEL.WORDVAL, EPWM_DECOMPSEL_TRIPH_M, (source << EPWM_DECOMPSEL_TRIPH_S));
}

/**
  * \brief  This function is used to select the pwm signal in DE mode.
  * \param  epwm               EPWMx pointer to a EPWM_TypeDef structure
  *                             - EPWM1:  EPWM1 module
  *                             - EPWM2:  EPWM2 module
  *                             - EPWM3:  EPWM3 module
  *                             - EPWM4:  EPWM4 module
  *                             - EPWM5:  EPWM5 module
  *                             - EPWM6:  EPWM6 module
  *                             - EPWM7:  EPWM7 module
  *                             - EPWM8:  EPWM8 module
  *                             - EPWM9:  EPWM9 module
  *                             - EPWM10: EPWM10 module
  *                             - EPWM11: EPWM11 module
  *                             - EPWM12: EPWM12 module
  *                             - EPWM13: EPWM13 module
  *                             - EPWM14: EPWM14 module
  *                             - EPWM15: EPWM15 module
  *                             - EPWM16: EPWM16 module
  *                             - EPWM17: EPWM17 module
  *                             - EPWM18: EPWM18 module
  * \param  channel            The epwm output channel
  *                             - EPWM_DE_CHANNEL_A: Diode emulation channel A
  *                             - EPWM_DE_CHANNEL_B: Diode emulation channel B
  * \param  emulationSignal    The signal selected by the TRIPSEL[A/B]
  *                             This parameter can be any value of @ref EPWM_DIODEEMULATIONSIGNAL
  */
static inline void EPWM_selectDiodeEmulationPWMsignal (EPWM_TypeDef *epwm, uint32_t channel,
                                                       EPWM_DiodeEmulationSignal emulationSignal)
{
    uint32_t PWM_channel_choice;

    PWM_channel_choice = channel << 2;
    MODIFY_REG(epwm->DEACTCTL.WORDVAL, (EPWM_DEACTCTL_PWMA_M << PWM_channel_choice), (emulationSignal << (EPWM_DEACTCTL_PWMA_S + PWM_channel_choice)));
}

/**
  * \brief  This function is used to select between TRIPH and TRIPL for a channel in DE mode.
  * \param  epwm               EPWMx pointer to a EPWM_TypeDef structure
  *                             - EPWM1:  EPWM1 module
  *                             - EPWM2:  EPWM2 module
  *                             - EPWM3:  EPWM3 module
  *                             - EPWM4:  EPWM4 module
  *                             - EPWM5:  EPWM5 module
  *                             - EPWM6:  EPWM6 module
  *                             - EPWM7:  EPWM7 module
  *                             - EPWM8:  EPWM8 module
  *                             - EPWM9:  EPWM9 module
  *                             - EPWM10: EPWM10 module
  *                             - EPWM11: EPWM11 module
  *                             - EPWM12: EPWM12 module
  *                             - EPWM13: EPWM13 module
  *                             - EPWM14: EPWM14 module
  *                             - EPWM15: EPWM15 module
  *                             - EPWM16: EPWM16 module
  *                             - EPWM17: EPWM17 module
  *                             - EPWM18: EPWM18 module
  * \param  channel            The epwm output channel
  *                             - EPWM_DE_CHANNEL_A: Diode emulation channel A
  *                             - EPWM_DE_CHANNEL_B: Diode emulation channel B
  * \param  emulationSignal    The signal selected by the TRIPSEL[A/B]
  *                             - 0: RIPH
  *                             - 1: RIPL
  */
static inline void EPWM_selectDiodeEmulationTripSignal (EPWM_TypeDef *epwm, uint32_t channel,
                                                       uint32_t emulationSignal)
{
    uint32_t PWM_tripsel;
    
    PWM_tripsel = channel << 4;
    MODIFY_REG(epwm->DEACTCTL.WORDVAL, (EPWM_DEACTCTL_TRIPSELA << PWM_tripsel), (emulationSignal << (2 + PWM_tripsel)));
}

/**
  * \brief  This function is used to go through DE.
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_nobypassDiodeEmulationLogic (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->DEACTCTL.WORDVAL, EPWM_DEACTCTL_TRIPENABLE);
}

/**
  * \brief  This function is used to bypass DE.
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_bypassDiodeEmulationLogic (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->DEACTCTL.WORDVAL, EPWM_DEACTCTL_TRIPENABLE);
}

/**
  * \brief  This function is used to force DEACTIVE flag to 1.
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_forceDiodeEmulationActive (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->DEFRC.WORDVAL, EPWM_DEFRC_DEACTIVE);
}

/**
  * \brief  This function is used to clear the DE mode active flag.
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
 static inline void EPWM_clearDiodeEmulationActiveFlag (EPWM_TypeDef *epwm)
 {
     SET_BIT(epwm->DECLR.WORDVAL, EPWM_DECLR_DEACTIVE);
 }

/**
  * \brief  This function is used to enable the DE monitor counter function.
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_enableDiodeEmulationMonitorModeControl (EPWM_TypeDef *epwm)
{
    SET_BIT(epwm->DEMONCTL.WORDVAL, EPWM_DEMONCTL_ENABLE);
}

/**
  * \brief  This function is used to disable the DE monitor counter function.
  * \param  epwm    EPWMx pointer to a EPWM_TypeDef structure
  *                  - EPWM1:  EPWM1 module
  *                  - EPWM2:  EPWM2 module
  *                  - EPWM3:  EPWM3 module
  *                  - EPWM4:  EPWM4 module
  *                  - EPWM5:  EPWM5 module
  *                  - EPWM6:  EPWM6 module
  *                  - EPWM7:  EPWM7 module
  *                  - EPWM8:  EPWM8 module
  *                  - EPWM9:  EPWM9 module
  *                  - EPWM10: EPWM10 module
  *                  - EPWM11: EPWM11 module
  *                  - EPWM12: EPWM12 module
  *                  - EPWM13: EPWM13 module
  *                  - EPWM14: EPWM14 module
  *                  - EPWM15: EPWM15 module
  *                  - EPWM16: EPWM16 module
  *                  - EPWM17: EPWM17 module
  *                  - EPWM18: EPWM18 module
  */
static inline void EPWM_disableDiodeEmulationMonitorModeControl (EPWM_TypeDef *epwm)
{
    CLEAR_BIT(epwm->DEMONCTL.WORDVAL, EPWM_DEMONCTL_ENABLE);
}

/**
  * \brief  This function is used to set the DE monitor counter step size.
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                       - EPWM1:  EPWM1 module
  *                       - EPWM2:  EPWM2 module
  *                       - EPWM3:  EPWM3 module
  *                       - EPWM4:  EPWM4 module
  *                       - EPWM5:  EPWM5 module
  *                       - EPWM6:  EPWM6 module
  *                       - EPWM7:  EPWM7 module
  *                       - EPWM8:  EPWM8 module
  *                       - EPWM9:  EPWM9 module
  *                       - EPWM10: EPWM10 module
  *                       - EPWM11: EPWM11 module
  *                       - EPWM12: EPWM12 module
  *                       - EPWM13: EPWM13 module
  *                       - EPWM14: EPWM14 module
  *                       - EPWM15: EPWM15 module
  *                       - EPWM16: EPWM16 module
  *                       - EPWM17: EPWM17 module
  *                       - EPWM18: EPWM18 module
  * \param  direction    The direction of the monitor counter counting either UP or DOWN
  *                       - EPWM_DE_COUNT_UP: Diode emulation count up step size
  *                       - EPWM_DE_COUNT_DOWN: Diode emulation count down step size
  * \param  stepsize     The amount by which the counter increments or decrements at each step
  *                       This value is range from 0 to 255
  */
static inline void EPWM_setDiodeEmulationMonitorModeStep (EPWM_TypeDef *epwm, uint32_t direction, uint32_t stepsize)
{
    MODIFY_REG(epwm->DEMONSTEP.WORDVAL, (EPWM_DEMONSTEP_INCSTEP_M << (direction << 4)), (stepsize << (EPWM_DEMONSTEP_INCSTEP_S + (direction << 4))));
}

/**
  * \brief  This function is used to set the DE monitor counter threshold.
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                       - EPWM1:  EPWM1 module
  *                       - EPWM2:  EPWM2 module
  *                       - EPWM3:  EPWM3 module
  *                       - EPWM4:  EPWM4 module
  *                       - EPWM5:  EPWM5 module
  *                       - EPWM6:  EPWM6 module
  *                       - EPWM7:  EPWM7 module
  *                       - EPWM8:  EPWM8 module
  *                       - EPWM9:  EPWM9 module
  *                       - EPWM10: EPWM10 module
  *                       - EPWM11: EPWM11 module
  *                       - EPWM12: EPWM12 module
  *                       - EPWM13: EPWM13 module
  *                       - EPWM14: EPWM14 module
  *                       - EPWM15: EPWM15 module
  *                       - EPWM16: EPWM16 module
  *                       - EPWM17: EPWM17 module
  *                       - EPWM18: EPWM18 module
  * \param  threshold    The max value till which the monitor counter can count
  *                       The value is range from 0 to 65535
  */
static inline void EPWM_setDiodeEmulationMonitorCounterThreshold (EPWM_TypeDef *epwm, uint32_t threshold)
{
    MODIFY_REG(epwm->DEMONTHRES.WORDVAL, EPWM_DEMONTHRES_THRESHOLD_M, (threshold << EPWM_DEMONTHRES_THRESHOLD_S));
}

/**
  * \brief  This function enables the Minimum DeadBand module.
  * \param  epwm     EPWMx pointer to a EPWM_TypeDef structure
  *                   - EPWM1:  EPWM1 module
  *                   - EPWM2:  EPWM2 module
  *                   - EPWM3:  EPWM3 module
  *                   - EPWM4:  EPWM4 module
  *                   - EPWM5:  EPWM5 module
  *                   - EPWM6:  EPWM6 module
  *                   - EPWM7:  EPWM7 module
  *                   - EPWM8:  EPWM8 module
  *                   - EPWM9:  EPWM9 module
  *                   - EPWM10: EPWM10 module
  *                   - EPWM11: EPWM11 module
  *                   - EPWM12: EPWM12 module
  *                   - EPWM13: EPWM13 module
  *                   - EPWM14: EPWM14 module
  *                   - EPWM15: EPWM15 module
  *                   - EPWM16: EPWM16 module
  *                   - EPWM17: EPWM17 module
  *                   - EPWM18: EPWM18 module
  * \param  block    The Minimum DeadBand Block to be selected
  *                   - EPWM_MINDB_BLOCK_A: select minimum dead band block A
  *                   - EPWM_MINDB_BLOCK_B: select minimum dead band block B
  */
static inline void EPWM_enableMinimumDeadBand (EPWM_TypeDef *epwm, uint32_t block)
{
    SET_BIT(epwm->MINDBCFG.WORDVAL, (EPWM_MINDBCFG_ENABLEA << (block << 4)));
}

/**
  * \brief  This function disables the Minimum DeadBand module.
  * \param  epwm     EPWMx pointer to a EPWM_TypeDef structure
  *                   - EPWM1:  EPWM1 module
  *                   - EPWM2:  EPWM2 module
  *                   - EPWM3:  EPWM3 module
  *                   - EPWM4:  EPWM4 module
  *                   - EPWM5:  EPWM5 module
  *                   - EPWM6:  EPWM6 module
  *                   - EPWM7:  EPWM7 module
  *                   - EPWM8:  EPWM8 module
  *                   - EPWM9:  EPWM9 module
  *                   - EPWM10: EPWM10 module
  *                   - EPWM11: EPWM11 module
  *                   - EPWM12: EPWM12 module
  *                   - EPWM13: EPWM13 module
  *                   - EPWM14: EPWM14 module
  *                   - EPWM15: EPWM15 module
  *                   - EPWM16: EPWM16 module
  *                   - EPWM17: EPWM17 module
  *                   - EPWM18: EPWM18 module
  * \param  block    The Minimum DeadBand Block to be selected
  *                   - EPWM_MINDB_BLOCK_A: select minimum dead band block A
  *                   - EPWM_MINDB_BLOCK_B: select minimum dead band block B
  */
 static inline void EPWM_disableMinimumDeadBand (EPWM_TypeDef *epwm, uint32_t block)
 {
     CLEAR_BIT(epwm->MINDBCFG.WORDVAL, (EPWM_MINDBCFG_ENABLEA << (block << 4)));
 }

/**
  * \brief  This function configures the Minimum DeadBand module to invert reference.
  * \param  epwm     EPWMx pointer to a EPWM_TypeDef structure
  *                   - EPWM1:  EPWM1 module
  *                   - EPWM2:  EPWM2 module
  *                   - EPWM3:  EPWM3 module
  *                   - EPWM4:  EPWM4 module
  *                   - EPWM5:  EPWM5 module
  *                   - EPWM6:  EPWM6 module
  *                   - EPWM7:  EPWM7 module
  *                   - EPWM8:  EPWM8 module
  *                   - EPWM9:  EPWM9 module
  *                   - EPWM10: EPWM10 module
  *                   - EPWM11: EPWM11 module
  *                   - EPWM12: EPWM12 module
  *                   - EPWM13: EPWM13 module
  *                   - EPWM14: EPWM14 module
  *                   - EPWM15: EPWM15 module
  *                   - EPWM16: EPWM16 module
  *                   - EPWM17: EPWM17 module
  *                   - EPWM18: EPWM18 module
  * \param  block    The Minimum DeadBand Block to be selected
  *                   - EPWM_MINDB_BLOCK_A: select minimum dead band block A
  *                   - EPWM_MINDB_BLOCK_B: select minimum dead band block B
  * \param  invert    This para specifies whether reference signal is to be inverted or not
  *                   - EPWM_MINDB_REF_SIG: Minimum dead band don't invert reference signal
  *                   - EPWM_MINDB_REF_SIG_INVERT: Minimum dead band invert reference signal
  */
static inline void EPWM_invertMinimumDeadBandSignal (EPWM_TypeDef *epwm, uint32_t block, uint32_t invert)
{
    MODIFY_REG(epwm->MINDBCFG.WORDVAL, (EPWM_MINDBCFG_INVERTA_M << (block << 4)), (invert << (EPWM_MINDBCFG_INVERTA_S + (block << 4))));
}

/**
  * \brief  This function configures the blocking signal for Minimum DeadBand module.
  * \param  epwm              EPWMx pointer to a EPWM_TypeDef structure
  *                            - EPWM1:  EPWM1 module
  *                            - EPWM2:  EPWM2 module
  *                            - EPWM3:  EPWM3 module
  *                            - EPWM4:  EPWM4 module
  *                            - EPWM5:  EPWM5 module
  *                            - EPWM6:  EPWM6 module
  *                            - EPWM7:  EPWM7 module
  *                            - EPWM8:  EPWM8 module
  *                            - EPWM9:  EPWM9 module
  *                            - EPWM10: EPWM10 module
  *                            - EPWM11: EPWM11 module
  *                            - EPWM12: EPWM12 module
  *                            - EPWM13: EPWM13 module
  *                            - EPWM14: EPWM14 module
  *                            - EPWM15: EPWM15 module
  *                            - EPWM16: EPWM16 module
  *                            - EPWM17: EPWM17 module
  *                            - EPWM18: EPWM18 module
  * \param  block             The Minimum DeadBand Block to be selected
  *                            - EPWM_MINDB_BLOCK_A: Select minimum dead band block A
  *                            - EPWM_MINDB_BLOCK_B: Select minimum dead band block B
  * \param  blockingSignal    The blocking signal to be used for a block
  *                            - EPWM_MINDB_BLOCKING_SIGNAL_BLOCKA: Select BLOCKA as the blocking signal on PWMA
  *                            - EPWM_MINDB_BLOCKING_SIGNAL_BLOCKB: Select BLOCKB as the blocking signal on PWMB
  */
static inline void EPWM_selectMinimumDeadBandBlockingSignal (EPWM_TypeDef *epwm, uint32_t block, uint32_t blockingSignal)
{
    MODIFY_REG(epwm->MINDBCFG.WORDVAL, (EPWM_MINDBCFG_SELBLOCKA_M << (block << 4)), (blockingSignal << (EPWM_MINDBCFG_SELBLOCKA_S + (block << 4))));
}

/**
  * \brief  This function selects the reference signal for Minimum DeadBand module.
  * \param  epwm               EPWMx pointer to a EPWM_TypeDef structure
  *                             - EPWM1:  EPWM1 module
  *                             - EPWM2:  EPWM2 module
  *                             - EPWM3:  EPWM3 module
  *                             - EPWM4:  EPWM4 module
  *                             - EPWM5:  EPWM5 module
  *                             - EPWM6:  EPWM6 module
  *                             - EPWM7:  EPWM7 module
  *                             - EPWM8:  EPWM8 module
  *                             - EPWM9:  EPWM9 module
  *                             - EPWM10: EPWM10 module
  *                             - EPWM11: EPWM11 module
  *                             - EPWM12: EPWM12 module
  *                             - EPWM13: EPWM13 module
  *                             - EPWM14: EPWM14 module
  *                             - EPWM15: EPWM15 module
  *                             - EPWM16: EPWM16 module
  *                             - EPWM17: EPWM17 module
  *                             - EPWM18: EPWM18 module
  * \param  block              The Minimum DeadBand Block to be selected
  *                             - EPWM_MINDB_BLOCK_A: Select minimum dead band block A
  *                             - EPWM_MINDB_BLOCK_B: Select minimum dead band block B
  * \param  referenceSignal    The reference signal to be selected
  *                             This parameter can be any value of @ref EPWM_MINDBCFGSELA
  */
static inline void EPWM_selectMinimumDeadBandReferenceSignal (EPWM_TypeDef *epwm, uint32_t block, uint32_t referenceSignal)
{
    MODIFY_REG(epwm->MINDBCFG.WORDVAL, (EPWM_MINDBCFG_SELA_M << (block << 4)), (referenceSignal << (EPWM_MINDBCFG_SELA_S + (block << 4))));
}

/**
  * \brief  This function configures how the signal will be combined with the
  *         PWM output. The signal can be inverted and ANDed with PWM output or it can
  *         be ORed with the PWM output.
  * \param  epwm     EPWMx pointer to a EPWM_TypeDef structure
  *                   - EPWM1:  EPWM1 module
  *                   - EPWM2:  EPWM2 module
  *                   - EPWM3:  EPWM3 module
  *                   - EPWM4:  EPWM4 module
  *                   - EPWM5:  EPWM5 module
  *                   - EPWM6:  EPWM6 module
  *                   - EPWM7:  EPWM7 module
  *                   - EPWM8:  EPWM8 module
  *                   - EPWM9:  EPWM9 module
  *                   - EPWM10: EPWM10 module
  *                   - EPWM11: EPWM11 module
  *                   - EPWM12: EPWM12 module
  *                   - EPWM13: EPWM13 module
  *                   - EPWM14: EPWM14 module
  *                   - EPWM15: EPWM15 module
  *                   - EPWM16: EPWM16 module
  *                   - EPWM17: EPWM17 module
  *                   - EPWM18: EPWM18 module
  * \param  block    The Minimum DeadBand Block to be selected
  *                   - EPWM_MINDB_BLOCK_A: Select minimum dead band block A
  *                   - EPWM_MINDB_BLOCK_B: Select minimum dead band block B
  * \param  logic    The reference signal to be selected
  *                   - EPWM_MINDB_POLSEL_INVERT_LOGICAL_AND: Invert and Logical AND
  *                   - EPWM_MINDB_POLSEL_LOGICAL_OR: Logical OR
  */
static inline void EPWM_selectMinimumDeadBandAndOrLogic (EPWM_TypeDef *epwm, uint32_t block, uint32_t logic)
{
    MODIFY_REG(epwm->MINDBCFG.WORDVAL, (EPWM_MINDBCFG_POLSELA_M << (block << 4)), (logic << (EPWM_MINDBCFG_POLSELA_S + (block << 4))));
}

/**
  * \brief  This function returns the delay value for the Minimum DeadBand module.
  * \param  epwm     EPWMx pointer to a EPWM_TypeDef structure
  *                   - EPWM1:  EPWM1 module
  *                   - EPWM2:  EPWM2 module
  *                   - EPWM3:  EPWM3 module
  *                   - EPWM4:  EPWM4 module
  *                   - EPWM5:  EPWM5 module
  *                   - EPWM6:  EPWM6 module
  *                   - EPWM7:  EPWM7 module
  *                   - EPWM8:  EPWM8 module
  *                   - EPWM9:  EPWM9 module
  *                   - EPWM10: EPWM10 module
  *                   - EPWM11: EPWM11 module
  *                   - EPWM12: EPWM12 module
  *                   - EPWM13: EPWM13 module
  *                   - EPWM14: EPWM14 module
  *                   - EPWM15: EPWM15 module
  *                   - EPWM16: EPWM16 module
  *                   - EPWM17: EPWM17 module
  *                   - EPWM18: EPWM18 module
  * \param  block    The Minimum DeadBand Block to be selected
  *                   - EPWM_MINDB_BLOCK_A: Select minimum dead band block A
  *                   - EPWM_MINDB_BLOCK_B: Select minimum dead band block B
  * \return Delay value of the Minimum DeadBand module
  */
static inline uint32_t EPWM_getMinDeadBandDelay (EPWM_TypeDef *epwm, uint32_t block)
{
    return (READ_REG(epwm->MINDBDLY.WORDVAL) >> (block << 4)) & EPWM_MINDBDLY_DELAYA_M;
}

/**
  * \brief  This function returns the delay value for the Minimum DeadBand module.
  * \param  epwm     EPWMx pointer to a EPWM_TypeDef structure
  *                   - EPWM1:  EPWM1 module
  *                   - EPWM2:  EPWM2 module
  *                   - EPWM3:  EPWM3 module
  *                   - EPWM4:  EPWM4 module
  *                   - EPWM5:  EPWM5 module
  *                   - EPWM6:  EPWM6 module
  *                   - EPWM7:  EPWM7 module
  *                   - EPWM8:  EPWM8 module
  *                   - EPWM9:  EPWM9 module
  *                   - EPWM10: EPWM10 module
  *                   - EPWM11: EPWM11 module
  *                   - EPWM12: EPWM12 module
  *                   - EPWM13: EPWM13 module
  *                   - EPWM14: EPWM14 module
  *                   - EPWM15: EPWM15 module
  *                   - EPWM16: EPWM16 module
  *                   - EPWM17: EPWM17 module
  *                   - EPWM18: EPWM18 module
  * \param  block    The Minimum DeadBand Block to be selected
  *                   - EPWM_MINDB_BLOCK_A: Select minimum dead band block A
  *                   - EPWM_MINDB_BLOCK_B: Select minimum dead band block B
  * \param  delay    The delay value to be programmed for the Minimum DeadBand
  *                   The value is range from 0 to 65535
  */
static inline void EPWM_setMinDeadBandDelay (EPWM_TypeDef *epwm, uint32_t block, uint32_t delay)
{
    MODIFY_REG(epwm->MINDBDLY.WORDVAL, (EPWM_MINDBDLY_DELAYA_M << (block << 4)), (delay << (EPWM_MINDBDLY_DELAYA_S + (block << 4))));
}

/**
  * \brief  This function enables the Illegal Combo Logic block.
  * \param  epwm     EPWMx pointer to a EPWM_TypeDef structure
  *                   - EPWM1:  EPWM1 module
  *                   - EPWM2:  EPWM2 module
  *                   - EPWM3:  EPWM3 module
  *                   - EPWM4:  EPWM4 module
  *                   - EPWM5:  EPWM5 module
  *                   - EPWM6:  EPWM6 module
  *                   - EPWM7:  EPWM7 module
  *                   - EPWM8:  EPWM8 module
  *                   - EPWM9:  EPWM9 module
  *                   - EPWM10: EPWM10 module
  *                   - EPWM11: EPWM11 module
  *                   - EPWM12: EPWM12 module
  *                   - EPWM13: EPWM13 module
  *                   - EPWM14: EPWM14 module
  *                   - EPWM15: EPWM15 module
  *                   - EPWM16: EPWM16 module
  *                   - EPWM17: EPWM17 module
  *                   - EPWM18: EPWM18 module
  * \param  block    The Minimum DeadBand Block to be selected
  *                   - EPWM_MINDB_BLOCK_A: select minimum dead band block A
  *                   - EPWM_MINDB_BLOCK_B: select minimum dead band block B
  */
static inline void EPWM_enableIllegalComboLogic (EPWM_TypeDef *epwm, uint32_t block)
{
    CLEAR_BIT(TYPE32(&(epwm->LUTCTLA.WORDVAL) + (block << 1)), EPWM_LUTCTLA_BYPASS);
}
 
/**
  * \brief  This function disables the Illegal Combo Logic block.
  * \param  epwm     EPWMx pointer to a EPWM_TypeDef structure
  *                   - EPWM1:  EPWM1 module
  *                   - EPWM2:  EPWM2 module
  *                   - EPWM3:  EPWM3 module
  *                   - EPWM4:  EPWM4 module
  *                   - EPWM5:  EPWM5 module
  *                   - EPWM6:  EPWM6 module
  *                   - EPWM7:  EPWM7 module
  *                   - EPWM8:  EPWM8 module
  *                   - EPWM9:  EPWM9 module
  *                   - EPWM10: EPWM10 module
  *                   - EPWM11: EPWM11 module
  *                   - EPWM12: EPWM12 module
  *                   - EPWM13: EPWM13 module
  *                   - EPWM14: EPWM14 module
  *                   - EPWM15: EPWM15 module
  *                   - EPWM16: EPWM16 module
  *                   - EPWM17: EPWM17 module
  *                   - EPWM18: EPWM18 module
  * \param  block    The Minimum DeadBand Block to be selected
  *                   - EPWM_MINDB_BLOCK_A: select minimum dead band block A
  *                   - EPWM_MINDB_BLOCK_B: select minimum dead band block B
  */
static inline void EPWM_disableIllegalComboLogic (EPWM_TypeDef *epwm, uint32_t block)
{
    SET_BIT(TYPE32(&(epwm->LUTCTLA.WORDVAL) + (block << 1)), EPWM_LUTCTLA_BYPASS);
}

/**
  * \brief  This function selects which Xbar signal feeds into the Illegal Combo Logic.
  * \param  epwm         EPWMx pointer to a EPWM_TypeDef structure
  *                       - EPWM1:  EPWM1 module
  *                       - EPWM2:  EPWM2 module
  *                       - EPWM3:  EPWM3 module
  *                       - EPWM4:  EPWM4 module
  *                       - EPWM5:  EPWM5 module
  *                       - EPWM6:  EPWM6 module
  *                       - EPWM7:  EPWM7 module
  *                       - EPWM8:  EPWM8 module
  *                       - EPWM9:  EPWM9 module
  *                       - EPWM10: EPWM10 module
  *                       - EPWM11: EPWM11 module
  *                       - EPWM12: EPWM12 module
  *                       - EPWM13: EPWM13 module
  *                       - EPWM14: EPWM14 module
  *                       - EPWM15: EPWM15 module
  *                       - EPWM16: EPWM16 module
  *                       - EPWM17: EPWM17 module
  *                       - EPWM18: EPWM18 module
  * \param  block        The Minimum DeadBand Block to be selected
  *                       - EPWM_MINDB_BLOCK_A: select minimum dead band block A
  *                       - EPWM_MINDB_BLOCK_B: select minimum dead band block B
  * \param  xbarInput    The Xbar signal to feed into the Illegal Combo Logic
  *                       This parameter can be any value of @ref EPWM_MINDBICLXBAR
  */
static inline void EPWM_selectXbarInput (EPWM_TypeDef *epwm, uint32_t block, uint32_t xbarInput)
{
    MODIFY_REG(TYPE32(&(epwm->LUTCTLA.WORDVAL) + (block << 1)), EPWM_LUTCTLA_SELXBAR_M, (xbarInput << EPWM_LUTCTLA_SELXBAR_S));
}

/**
  * \brief  This function programs value in the Decx register fields of the Illegal.
  * \param  epwm     EPWMx pointer to a EPWM_TypeDef structure
  *                   - EPWM1:  EPWM1 module
  *                   - EPWM2:  EPWM2 module
  *                   - EPWM3:  EPWM3 module
  *                   - EPWM4:  EPWM4 module
  *                   - EPWM5:  EPWM5 module
  *                   - EPWM6:  EPWM6 module
  *                   - EPWM7:  EPWM7 module
  *                   - EPWM8:  EPWM8 module
  *                   - EPWM9:  EPWM9 module
  *                   - EPWM10: EPWM10 module
  *                   - EPWM11: EPWM11 module
  *                   - EPWM12: EPWM12 module
  *                   - EPWM13: EPWM13 module
  *                   - EPWM14: EPWM14 module
  *                   - EPWM15: EPWM15 module
  *                   - EPWM16: EPWM16 module
  *                   - EPWM17: EPWM17 module
  *                   - EPWM18: EPWM18 module
  * \param  block    The Minimum DeadBand Block to be selected
  *                   - EPWM_MINDB_BLOCK_A: select minimum dead band block A
  *                   - EPWM_MINDB_BLOCK_B: select minimum dead band block B
  * \param  decx     The register to be programmed
  *                   This parameter can be any value of @ref EPWM_MINDBICLLUTDEC
  * \param  force    The value to be programmed in the register
  *                   -0: force 0
  *                   -1: force 1
  */
static inline void EPWM_setLutDecX (EPWM_TypeDef *epwm, uint32_t block, uint32_t decx, uint32_t force)
{
    MODIFY_REG(TYPE32(&(epwm->LUTCTLA.WORDVAL) + (block << 1)), (1U << (decx + 16)), (force << (decx + 16)));
}

/**
  * \brief  Set the emulation mode.
  * \param  epwm             EPWMx pointer to a EPWM_TypeDef structure
  *                           - EPWM1:  EPWM1 module
  *                           - EPWM2:  EPWM2 module
  *                           - EPWM3:  EPWM3 module
  *                           - EPWM4:  EPWM4 module
  *                           - EPWM5:  EPWM5 module
  *                           - EPWM6:  EPWM6 module
  *                           - EPWM7:  EPWM7 module
  *                           - EPWM8:  EPWM8 module
  *                           - EPWM9:  EPWM9 module
  *                           - EPWM10: EPWM10 module
  *                           - EPWM11: EPWM11 module
  *                           - EPWM12: EPWM12 module
  *                           - EPWM13: EPWM13 module
  *                           - EPWM14: EPWM14 module
  *                           - EPWM15: EPWM15 module
  *                           - EPWM16: EPWM16 module
  *                           - EPWM17: EPWM17 module
  *                           - EPWM18: EPWM18 module
  * \param  emulationMode    The emulation mode.
  *                           This parameter can be any value of @ref EPWM_EMULATIONMODE
  */
extern void EPWM_setEmulationMode (EPWM_TypeDef *epwm, EPWM_EmulationMode emulationMode);

/**
  * \brief  Configures ePWM signal with desired frequency & duty
  * \param  epwm            EPWMx pointer to a EPWM_TypeDef structure
  *                          - EPWM1:  EPWM1 module
  *                          - EPWM2:  EPWM2 module
  *                          - EPWM3:  EPWM3 module
  *                          - EPWM4:  EPWM4 module
  *                          - EPWM5:  EPWM5 module
  *                          - EPWM6:  EPWM6 module
  *                          - EPWM7:  EPWM7 module
  *                          - EPWM8:  EPWM8 module
  *                          - EPWM9:  EPWM9 module
  *                          - EPWM10: EPWM10 module
  *                          - EPWM11: EPWM11 module
  *                          - EPWM12: EPWM12 module
  *                          - EPWM13: EPWM13 module
  *                          - EPWM14: EPWM14 module
  *                          - EPWM15: EPWM15 module
  *                          - EPWM16: EPWM16 module
  *                          - EPWM17: EPWM17 module
  *                          - EPWM18: EPWM18 module
  * \param  signalParams    Pointer to the signal parameters structure.
  *                          This parameter can be any value of @ref EPWM_SIGNALPARAMS
  * \note   This function configures the ePWM module to generate a signal with desired frequency & duty.
  */
extern void EPWM_configureSignal (EPWM_TypeDef *epwm, const EPWM_SignalParams *signalParams);


#ifdef __cplusplus
}
#endif


#endif /* __EPWM_H__ */
