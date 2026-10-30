/**
  * @file       adc.h
  * @author     wangyi,bilang.xiong
  * @brief      Header file for NS800RT7xxx adc module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __ADC_H__
#define __ADC_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_adc.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup ADC_EXPORTED_TYPES ADC Exported Types.
  * @{
  * @brief  Macro definitions are used with all files publicly about 'ADC' module.
  */

/** @defgroup ADC_CLKPRESCALE is ADC Clock Prescaler with one group(ADCA/B/C)
  * @{
  * @brief  Macro definitions about ADC Clock Prescaler.
  */
typedef enum {
    ADC_CLK_DIV_1 = 0U,    /*!< ADCCLK = (input clock) / 1 */
    ADC_CLK_DIV_2,         /*!< ADCCLK = (input clock) / 2 */
    ADC_CLK_DIV_3,         /*!< ADCCLK = (input clock) / 3 */
    ADC_CLK_DIV_4,         /*!< ADCCLK = (input clock) / 4 */
    ADC_CLK_DIV_5,         /*!< ADCCLK = (input clock) / 5 */
    ADC_CLK_DIV_6,         /*!< ADCCLK = (input clock) / 6 */
    ADC_CLK_DIV_7,         /*!< ADCCLK = (input clock) / 7 */
    ADC_CLK_DIV_8,         /*!< ADCCLK = (input clock) / 8 */
    ADC_CLK_DIV_9,         /*!< ADCCLK = (input clock) / 9 */
    ADC_CLK_DIV_10,        /*!< ADCCLK = (input clock) / 10 */
    ADC_CLK_DIV_11,        /*!< ADCCLK = (input clock) / 11 */
    ADC_CLK_DIV_12,        /*!< ADCCLK = (input clock) / 12 */
    ADC_CLK_DIV_13,        /*!< ADCCLK = (input clock) / 13 */
    ADC_CLK_DIV_14,        /*!< ADCCLK = (input clock) / 14 */
    ADC_CLK_DIV_15,        /*!< ADCCLK = (input clock) / 15 */
    ADC_CLK_DIV_16,        /*!< ADCCLK = (input clock) / 16 */
    ADC_CLK_DIV_17,        /*!< ADCCLK = (input clock) / 17 */
    ADC_CLK_DIV_18,        /*!< ADCCLK = (input clock) / 18 */
    ADC_CLK_DIV_19,        /*!< ADCCLK = (input clock) / 19 */
    ADC_CLK_DIV_20,        /*!< ADCCLK = (input clock) / 20 */
    ADC_CLK_DIV_21,        /*!< ADCCLK = (input clock) / 21 */
    ADC_CLK_DIV_22,        /*!< ADCCLK = (input clock) / 22 */
    ADC_CLK_DIV_23,        /*!< ADCCLK = (input clock) / 23 */
    ADC_CLK_DIV_24,        /*!< ADCCLK = (input clock) / 24 */
    ADC_CLK_DIV_25,        /*!< ADCCLK = (input clock) / 25 */
    ADC_CLK_DIV_26,        /*!< ADCCLK = (input clock) / 26 */
    ADC_CLK_DIV_27,        /*!< ADCCLK = (input clock) / 27 */
    ADC_CLK_DIV_28,        /*!< ADCCLK = (input clock) / 28 */
    ADC_CLK_DIV_29,        /*!< ADCCLK = (input clock) / 29 */
    ADC_CLK_DIV_30,        /*!< ADCCLK = (input clock) / 30 */
    ADC_CLK_DIV_31,        /*!< ADCCLK = (input clock) / 31 */
    ADC_CLK_DIV_32,        /*!< ADCCLK = (input clock) / 32 */
    ADC_CLK_DIV_33,        /*!< ADCCLK = (input clock) / 33 */
    ADC_CLK_DIV_34,        /*!< ADCCLK = (input clock) / 34 */
    ADC_CLK_DIV_35,        /*!< ADCCLK = (input clock) / 35 */
    ADC_CLK_DIV_36,        /*!< ADCCLK = (input clock) / 36 */
    ADC_CLK_DIV_37,        /*!< ADCCLK = (input clock) / 37 */
    ADC_CLK_DIV_38,        /*!< ADCCLK = (input clock) / 38 */
    ADC_CLK_DIV_39,        /*!< ADCCLK = (input clock) / 39 */
    ADC_CLK_DIV_40,        /*!< ADCCLK = (input clock) / 40 */
    ADC_CLK_DIV_41,        /*!< ADCCLK = (input clock) / 41 */
    ADC_CLK_DIV_42,        /*!< ADCCLK = (input clock) / 42 */
    ADC_CLK_DIV_43,        /*!< ADCCLK = (input clock) / 43 */
    ADC_CLK_DIV_44,        /*!< ADCCLK = (input clock) / 44 */
    ADC_CLK_DIV_45,        /*!< ADCCLK = (input clock) / 45 */
    ADC_CLK_DIV_46,        /*!< ADCCLK = (input clock) / 46 */
    ADC_CLK_DIV_47,        /*!< ADCCLK = (input clock) / 47 */
    ADC_CLK_DIV_48,        /*!< ADCCLK = (input clock) / 48 */
    ADC_CLK_DIV_49,        /*!< ADCCLK = (input clock) / 49 */
    ADC_CLK_DIV_50,        /*!< ADCCLK = (input clock) / 50 */
    ADC_CLK_DIV_51,        /*!< ADCCLK = (input clock) / 51 */
    ADC_CLK_DIV_52,        /*!< ADCCLK = (input clock) / 52 */
    ADC_CLK_DIV_53,        /*!< ADCCLK = (input clock) / 53 */
    ADC_CLK_DIV_54,        /*!< ADCCLK = (input clock) / 54 */
    ADC_CLK_DIV_55,        /*!< ADCCLK = (input clock) / 55 */
    ADC_CLK_DIV_56,        /*!< ADCCLK = (input clock) / 56 */
    ADC_CLK_DIV_57,        /*!< ADCCLK = (input clock) / 57 */
    ADC_CLK_DIV_58,        /*!< ADCCLK = (input clock) / 58 */
    ADC_CLK_DIV_59,        /*!< ADCCLK = (input clock) / 59 */
    ADC_CLK_DIV_60,        /*!< ADCCLK = (input clock) / 60 */
    ADC_CLK_DIV_61,        /*!< ADCCLK = (input clock) / 61 */
    ADC_CLK_DIV_62,        /*!< ADCCLK = (input clock) / 62 */
    ADC_CLK_DIV_63,        /*!< ADCCLK = (input clock) / 63 */
    ADC_CLK_DIV_64         /*!< ADCCLK = (input clock) / 64 */
} ADC_ClkPrescale;

/**
  * @}
  */

/** @defgroup ADC_TRIGGER ADC Interrupt Trigger Source with one group(ADCA/B/C)
  * @{
  * @brief  Macro definitions about ADC interrupt trigger source.
  */
typedef enum {
    ADC_TRIGGER_SW_ONLY = 0U,    /*!< Software only */
    ADC_TRIGGER_CPU1_TINT0,      /*!< CPU1 Timer 0, TINT0 */
    ADC_TRIGGER_CPU1_TINT1,      /*!< CPU1 Timer 1, TINT1 */
    ADC_TRIGGER_CPU1_TINT2,      /*!< CPU1 Timer 2, TINT2 */
    ADC_TRIGGER_INPUT_XBAR5,     /*!< INPUT_XBAR5 */
    ADC_TRIGGER_EPWM1_SOCA,      /*!< ePWM1, ADCSOCA */
    ADC_TRIGGER_EPWM1_SOCB,      /*!< ePWM1, ADCSOCB */
    ADC_TRIGGER_EPWM2_SOCA,      /*!< ePWM2, ADCSOCA */
    ADC_TRIGGER_EPWM2_SOCB,      /*!< ePWM2, ADCSOCB */
    ADC_TRIGGER_EPWM3_SOCA,      /*!< ePWM3, ADCSOCA */
    ADC_TRIGGER_EPWM3_SOCB,      /*!< ePWM3, ADCSOCB */
    ADC_TRIGGER_EPWM4_SOCA,      /*!< ePWM4, ADCSOCA */
    ADC_TRIGGER_EPWM4_SOCB,      /*!< ePWM4, ADCSOCB */
    ADC_TRIGGER_EPWM5_SOCA,      /*!< ePWM5, ADCSOCA */
    ADC_TRIGGER_EPWM5_SOCB,      /*!< ePWM5, ADCSOCB */
    ADC_TRIGGER_EPWM6_SOCA,      /*!< ePWM6, ADCSOCA */
    ADC_TRIGGER_EPWM6_SOCB,      /*!< ePWM6, ADCSOCB */
    ADC_TRIGGER_EPWM7_SOCA,      /*!< ePWM7, ADCSOCA */
    ADC_TRIGGER_EPWM7_SOCB,      /*!< ePWM7, ADCSOCB */
    ADC_TRIGGER_EPWM8_SOCA,      /*!< ePWM8, ADCSOCA */
    ADC_TRIGGER_EPWM8_SOCB,      /*!< ePWM8, ADCSOCB */
    ADC_TRIGGER_EPWM9_SOCA,      /*!< ePWM9, ADCSOCA */
    ADC_TRIGGER_EPWM9_SOCB,      /*!< ePWM9, ADCSOCB */
    ADC_TRIGGER_EPWM10_SOCA,     /*!< ePWM10, ADCSOCA */
    ADC_TRIGGER_EPWM10_SOCB,     /*!< ePWM10, ADCSOCB */
    ADC_TRIGGER_EPWM11_SOCA,     /*!< ePWM11, ADCSOCA */
    ADC_TRIGGER_EPWM11_SOCB,     /*!< ePWM11, ADCSOCB */
    ADC_TRIGGER_EPWM12_SOCA,     /*!< ePWM12, ADCSOCA */
    ADC_TRIGGER_EPWM12_SOCB,     /*!< ePWM12, ADCSOCB */
    ADC_TRIGGER_CPU2_TINT0,      /*!< CPU2 Timer 0, TINT0 */
    ADC_TRIGGER_CPU2_TINT1,      /*!< CPU2 Timer 1, TINT1 */
    ADC_TRIGGER_CPU2_TINT2,      /*!< CPU2 Timer 2, TINT2 */
    ADC_TRIGGER_TIMER1_TRIGO,    /*!< TIM1 TRIGO */
    ADC_TRIGGER_TIMER2_TRIGO,    /*!< TIM2 TRIGO */
    ADC_TRIGGER_REP1_TRIG = 40U,  /*!< REP1 TRIG */
    ADC_TRIGGER_REP2_TRIG,        /*!< REP2 TRIG */
    ADC_TRIGGER_ECAP1 = 80U,     /*!< eCAP1 */
    ADC_TRIGGER_ECAP2,           /*!< eCAP2 */
    ADC_TRIGGER_ECAP3,           /*!< eCAP3 */
    ADC_TRIGGER_ECAP4,           /*!< eCAP4 */
    ADC_TRIGGER_ECAP5,           /*!< eCAP5 */
    ADC_TRIGGER_ECAP6,           /*!< eCAP6 */
    ADC_TRIGGER_ECAP7,           /*!< eCAP7 */
    ADC_TRIGGER_EPWM13_SOCA = 88U,/*!< ePWM13, ADCSOCA */
    ADC_TRIGGER_EPWM13_SOCB,     /*!< ePWM13, ADCSOCB */
    ADC_TRIGGER_EPWM14_SOCA,     /*!< ePWM14, ADCSOCA */
    ADC_TRIGGER_EPWM14_SOCB,     /*!< ePWM14, ADCSOCB */
    ADC_TRIGGER_EPWM15_SOCA,     /*!< ePWM15, ADCSOCA */
    ADC_TRIGGER_EPWM15_SOCB,     /*!< ePWM15, ADCSOCB */
    ADC_TRIGGER_EPWM16_SOCA,     /*!< ePWM16, ADCSOCA */
    ADC_TRIGGER_EPWM16_SOCB,     /*!< ePWM16, ADCSOCB */
    ADC_TRIGGER_EPWM17_SOCA,     /*!< ePWM17, ADCSOCA */
    ADC_TRIGGER_EPWM17_SOCB,     /*!< ePWM17, ADCSOCB */
    ADC_TRIGGER_EPWM18_SOCA,     /*!< ePWM18, ADCSOCA */
    ADC_TRIGGER_EPWM18_SOCB      /*!< ePWM18, ADCSOCB */
} ADC_Trigger;

/**
  * @}
  */

/** @defgroup ADC_BURSTTRIGGER ADC Interrupt Burst Trigger Source with one group(ADCA/B/C)
  * @{
  * @brief  Macro definitions about ADC interrupt Burst trigger source.
  */
typedef enum {
    ADC_BURSTTRIG0_SW_ONLY = 0U,    /*!< Software only */
    ADC_BURSTTRIG1_CPU1_TINT0,      /*!< CPU1 Timer 0, TINT0 */
    ADC_BURSTTRIG2_CPU1_TINT1,      /*!< CPU1 Timer 1, TINT1 */
    ADC_BURSTTRIG3_CPU1_TINT2,      /*!< CPU1 Timer 2, TINT2 */
    ADC_BURSTTRIG4_GPIO_INPUT5,     /*!< GPIO, Input X-Bar INPUT5 */
    ADC_BURSTTRIG5_EPWM1_SOCA,      /*!< ePWM1, ADCSOCA */
    ADC_BURSTTRIG6_EPWM1_SOCB,      /*!< ePWM1, ADCSOCB */
    ADC_BURSTTRIG7_EPWM2_SOCA,      /*!< ePWM2, ADCSOCA */
    ADC_BURSTTRIG8_EPWM2_SOCB,      /*!< ePWM2, ADCSOCB */
    ADC_BURSTTRIG9_EPWM3_SOCA,      /*!< ePWM3, ADCSOCA */
    ADC_BURSTTRIG10_EPWM3_SOCB,     /*!< ePWM3, ADCSOCB */
    ADC_BURSTTRIG11_EPWM4_SOCA,     /*!< ePWM4, ADCSOCA */
    ADC_BURSTTRIG12_EPWM4_SOCB,     /*!< ePWM4, ADCSOCB */
    ADC_BURSTTRIG13_EPWM5_SOCA,     /*!< ePWM5, ADCSOCA */
    ADC_BURSTTRIG14_EPWM5_SOCB,     /*!< ePWM5, ADCSOCB */
    ADC_BURSTTRIG15_EPWM6_SOCA,     /*!< ePWM6, ADCSOCA */
    ADC_BURSTTRIG16_EPWM6_SOCB,     /*!< ePWM6, ADCSOCB */
    ADC_BURSTTRIG17_EPWM7_SOCA,     /*!< ePWM7, ADCSOCA */
    ADC_BURSTTRIG18_EPWM7_SOCB,     /*!< ePWM7, ADCSOCB */
    ADC_BURSTTRIG19_EPWM8_SOCA,     /*!< ePWM8, ADCSOCA */
    ADC_BURSTTRIG20_EPWM8_SOCB,      /*!< ePWM8, ADCSOCB */
    ADC_BURSTTRIG21_EPWM9_SOCA,     /*!< ePWM9, ADCSOCA */
    ADC_BURSTTRIG22_EPWM9_SOCB,     /*!< ePWM9, ADCSOCB */
    ADC_BURSTTRIG23_EPWM10_SOCA,    /*!< ePWM10, ADCSOCA */
    ADC_BURSTTRIG24_EPWM10_SOCB,    /*!< ePWM10, ADCSOCB */
    ADC_BURSTTRIG25_EPWM11_SOCA,    /*!< ePWM11, ADCSOCA */
    ADC_BURSTTRIG26_EPWM11_SOCB,    /*!< ePWM11, ADCSOCB */
    ADC_BURSTTRIG27_EPWM12_SOCA,    /*!< ePWM12, ADCSOCA */
    ADC_BURSTTRIG28_EPWM12_SOCB,    /*!< ePWM12, ADCSOCB */
    ADC_BURSTTRIG29_CPU2_TINT0,     /*!< CPU2 Timer 0, TINT0 */
    ADC_BURSTTRIG30_CPU2_TINT1,     /*!< CPU2 Timer 1, TINT1 */
    ADC_BURSTTRIG31_CPU2_TINT2,     /*!< CPU2 Timer 2, TINT2 */
    ADC_BURSTTRIG32_TIMER1_TRIGO,   /*!< TIM1 TRIGO */
    ADC_BURSTTRIG33_TIMER2_TRIGO,   /*!< TIM2 TRIGO */
    ADC_BURSTTRIG40_REP1_TRIG = 40U,  /*!< REP1 TRIG */
    ADC_BURSTTRIG41_REP2_TRIG,        /*!< REP2 TRIG */
    ADC_BURSTTRIG80_ECAP1 = 80U,    /*!< eCAP1 */
    ADC_BURSTTRIG81_ECAP2,          /*!< eCAP2 */
    ADC_BURSTTRIG82_ECAP3,          /*!< eCAP3 */
    ADC_BURSTTRIG83_ECAP4,          /*!< eCAP4 */
    ADC_BURSTTRIG84_ECAP5,          /*!< eCAP5 */
    ADC_BURSTTRIG85_ECAP6,          /*!< eCAP6 */
    ADC_BURSTTRIG86_ECAP7,          /*!< eCAP7 */
    ADC_BURSTTRIG88_EPWM13_SOCA = 88U,/*!< ePWM13, ADCSOCA */
    ADC_BURSTTRIG89_EPWM13_SOCB,    /*!< ePWM13, ADCSOCB */
    ADC_BURSTTRIG90_EPWM14_SOCA,    /*!< ePWM14, ADCSOCA */
    ADC_BURSTTRIG91_EPWM14_SOCB,    /*!< ePWM14, ADCSOCB */
    ADC_BURSTTRIG92_EPWM15_SOCA,    /*!< ePWM15, ADCSOCA */
    ADC_BURSTTRIG93_EPWM15_SOCB,    /*!< ePWM15, ADCSOCB */
    ADC_BURSTTRIG94_EPWM16_SOCA,    /*!< ePWM16, ADCSOCA */
    ADC_BURSTTRIG95_EPWM16_SOCB,    /*!< ePWM16, ADCSOCB */
    ADC_BURSTTRIG96_EPWM17_SOCA,    /*!< ePWM17, ADCSOCA */
    ADC_BURSTTRIG97_EPWM17_SOCB,    /*!< ePWM17, ADCSOCB */
    ADC_BURSTTRIG98_EPWM18_SOCA,    /*!< ePWM18, ADCSOCA */
    ADC_BURSTTRIG99_EPWM18_SOCB     /*!< ePWM18, ADCSOCB */
} ADC_BurstTrigger;

/**
  * @}
  */

/** @defgroup ADC_CHANNEL ADC Channel Number Selection in group(ADCA/B/C)
  * @{
  * @brief  Macro definitions about ADC channel.
  */
typedef enum {
    ADC_CH_ADCIN0 = 0U,    /*!< ADCIN0 is converted */
    ADC_CH_ADCIN1,         /*!< ADCIN1 is converted */
    ADC_CH_ADCIN2,         /*!< ADCIN2 is converted */
    ADC_CH_ADCIN3,         /*!< ADCIN3 is converted */
    ADC_CH_ADCIN4,         /*!< ADCIN4 is converted */
    ADC_CH_ADCIN5,         /*!< ADCIN5 is converted */
    ADC_CH_ADCIN6,         /*!< ADCIN6 is converted */
    ADC_CH_ADCIN7,         /*!< ADCIN7 is converted */
    ADC_CH_ADCIN8,         /*!< ADCIN8 is converted */
    ADC_CH_ADCIN9,         /*!< ADCIN9 is converted */
    ADC_CH_ADCIN10,        /*!< ADCIN10 is converted */
    ADC_CH_ADCIN11,        /*!< ADCIN11 is converted */
    ADC_CH_ADCIN12,        /*!< ADCIN12 is converted */
    ADC_CH_ADCIN13,        /*!< ADCIN13 is converted */
    ADC_CH_ADCIN14,        /*!< ADCIN14 is converted */
    ADC_CH_ADCIN15,        /*!< ADCIN15 is converted */
    ADC_CH_ADCIN16,        /*!< ADCIN16 is converted */
    ADC_CH_ADCIN17,        /*!< ADCIN17 is converted */
    ADC_CH_ADCIN18,        /*!< ADCIN18 is converted */
    ADC_CH_ADCIN19,        /*!< ADCIN19 is converted */
    ADC_CH_ADCIN20,        /*!< ADCIN20 is converted */
    ADC_CH_ADCIN21,        /*!< ADCIN21 is converted */
    ADC_CH_ADCIN22,        /*!< ADCIN22 is converted */
    ADC_CH_ADCIN23,        /*!< ADCIN23 is converted */
    ADC_CH_ADCIN24,        /*!< ADCIN24 is converted */
    ADC_CH_ADCIN25,        /*!< ADCIN25 is converted */
    ADC_CH_ADCIN26,        /*!< ADCIN26 is converted */
    ADC_CH_ADCIN27,        /*!< ADCIN27 is converted */
    ADC_CH_ADCIN28,        /*!< ADCIN28 is converted */
    ADC_CH_ADCIN29,        /*!< ADCIN29 is converted */
    ADC_CH_ADCIN30,        /*!< ADCIN30 is converted */
    ADC_CH_ADCIN31         /*!< ADCIN31 is converted */
} ADC_Channel;

/**
  * @}
  */

/** @defgroup ADC_INTNUMBER ADC Interrupt Number Selection
  * @{
  * @brief  Macro definitions about ADC Interrupt Number
  */
typedef enum {
    ADC_INT_NUMBER1 = 0U,    /*!< ADCINT1 Interrupt */
    ADC_INT_NUMBER2,         /*!< ADCINT2 Interrupt */
    ADC_INT_NUMBER3,         /*!< ADCINT3 Interrupt */
    ADC_INT_NUMBER4          /*!< ADCINT4 Interrupt */
} ADC_IntNumber;

/**
  * @}
  */

/** @defgroup ADC_PPBNUMBER ADC Post-processing Block
  * @{
  * @brief  Macro definitions about ADC Post-processing Block Number
  */
typedef enum {
    ADC_PPB_NUMBER1 = 0U,    /*!< Post-processing block 1 */
    ADC_PPB_NUMBER2,         /*!< Post-processing block 2 */
    ADC_PPB_NUMBER3,         /*!< Post-processing block 3 */
    ADC_PPB_NUMBER4          /*!< Post-processing block 4 */
} ADC_PPBNumber;

/**
  * @}
  */

/** @defgroup ADC_SOCNUMBER ADC SOC Number Selection
  * @{
  * @brief  Macro definitions about ADC SOC Number
  */
typedef enum {
    ADC_SOC_NUMBER0 = 0U,    /*!< SOC number 0 */
    ADC_SOC_NUMBER1,         /*!< SOC number 1 */
    ADC_SOC_NUMBER2,         /*!< SOC number 2 */
    ADC_SOC_NUMBER3,         /*!< SOC number 3 */
    ADC_SOC_NUMBER4,         /*!< SOC number 4 */
    ADC_SOC_NUMBER5,         /*!< SOC number 5 */
    ADC_SOC_NUMBER6,         /*!< SOC number 6 */
    ADC_SOC_NUMBER7,         /*!< SOC number 7 */
    ADC_SOC_NUMBER8,         /*!< SOC number 8 */
    ADC_SOC_NUMBER9,         /*!< SOC number 9 */
    ADC_SOC_NUMBER10,        /*!< SOC number 10 */
    ADC_SOC_NUMBER11,        /*!< SOC number 11 */
    ADC_SOC_NUMBER12,        /*!< SOC number 12 */
    ADC_SOC_NUMBER13,        /*!< SOC number 13 */
    ADC_SOC_NUMBER14,        /*!< SOC number 14 */
    ADC_SOC_NUMBER15,        /*!< SOC number 15 */
    ADC_SOC_NUMBER16,        /*!< SOC number 16 */
    ADC_SOC_NUMBER17,        /*!< SOC number 17 */
    ADC_SOC_NUMBER18,        /*!< SOC number 18 */
    ADC_SOC_NUMBER19,        /*!< SOC number 19 */
    ADC_SOC_NUMBER20,        /*!< SOC number 20 */
    ADC_SOC_NUMBER21,        /*!< SOC number 21 */
    ADC_SOC_NUMBER22,        /*!< SOC number 22 */
    ADC_SOC_NUMBER23,        /*!< SOC number 23 */
    ADC_SOC_NUMBER24,        /*!< SOC number 24 */
    ADC_SOC_NUMBER25,        /*!< SOC number 25 */
    ADC_SOC_NUMBER26,        /*!< SOC number 26 */
    ADC_SOC_NUMBER27,        /*!< SOC number 27 */
    ADC_SOC_NUMBER28,        /*!< SOC number 28 */
    ADC_SOC_NUMBER29,        /*!< SOC number 29 */
    ADC_SOC_NUMBER30,        /*!< SOC number 30 */
    ADC_SOC_NUMBER31         /*!< SOC number 31 */
} ADC_SOCNumber;

/**
  * @}
  */

/** @defgroup ADC_INTSOCTRIGGER ADC Interupt Source Selection
  * @{
  * @brief  Macro definitions about ADC Interupt source.
  */
typedef enum {
    ADC_INT_SOC_TRIGGER_NONE = 0U,    /*!< No ADCINT will trigger the SOC */
    ADC_INT_SOC_TRIGGER_ADCINT1,      /*!< ADCINT1 will trigger the SOC */
    ADC_INT_SOC_TRIGGER_ADCINT2       /*!< ADCINT2 will trigger the SOC */
} ADC_IntSOCTrigger;

/**
  * @}
  */

/** @defgroup ADC_PRIORITYMODE ADC Priority Selection
  * @{
  * @brief  Macro definitions about ADC Priority.
  */
typedef enum {
    ADC_PRI_ALL_ROUND_ROBIN = 0U,    /*!< Round robin mode is used for all */
    ADC_PRI_SOC0_HIPRI,              /*!< SOC 0 hi pri, others in round robin */
    ADC_PRI_THRU_SOC1_HIPRI,         /*!< SOC 0-1 hi pri, others in round robin */
    ADC_PRI_THRU_SOC2_HIPRI,         /*!< SOC 0-2 hi pri, others in round robin */
    ADC_PRI_THRU_SOC3_HIPRI,         /*!< SOC 0-3 hi pri, others in round robin */
    ADC_PRI_THRU_SOC4_HIPRI,         /*!< SOC 0-4 hi pri, others in round robin */
    ADC_PRI_THRU_SOC5_HIPRI,         /*!< SOC 0-5 hi pri, others in round robin */
    ADC_PRI_THRU_SOC6_HIPRI,         /*!< SOC 0-6 hi pri, others in round robin */
    ADC_PRI_THRU_SOC7_HIPRI,         /*!< SOC 0-7 hi pri, others in round robin */
    ADC_PRI_THRU_SOC8_HIPRI,         /*!< SOC 0-8 hi pri, others in round robin */
    ADC_PRI_THRU_SOC9_HIPRI,         /*!< SOC 0-9 hi pri, others in round robin */
    ADC_PRI_THRU_SOC10_HIPRI,        /*!< SOC 0-10 hi pri, others in round robin */
    ADC_PRI_THRU_SOC11_HIPRI,        /*!< SOC 0-11 hi pri, others in round robin */
    ADC_PRI_THRU_SOC12_HIPRI,        /*!< SOC 0-12 hi pri, others in round robin */
    ADC_PRI_THRU_SOC13_HIPRI,        /*!< SOC 0-13 hi pri, others in round robin */
    ADC_PRI_THRU_SOC14_HIPRI,        /*!< SOC 0-14 hi pri, SOC15 in round robin */
    ADC_PRI_THRU_SOC15_HIPRI,        /*!< SOC 0-15 hi pri, others in round robin */
    ADC_PRI_THRU_SOC16_HIPRI,        /*!< SOC 0-16 hi pri, others in round robin */
    ADC_PRI_THRU_SOC17_HIPRI,        /*!< SOC 0-17 hi pri, others in round robin */
    ADC_PRI_THRU_SOC18_HIPRI,        /*!< SOC 0-18 hi pri, others in round robin */
    ADC_PRI_THRU_SOC19_HIPRI,        /*!< SOC 0-19 hi pri, others in round robin */
    ADC_PRI_THRU_SOC20_HIPRI,        /*!< SOC 0-20 hi pri, others in round robin */
    ADC_PRI_THRU_SOC21_HIPRI,        /*!< SOC 0-21 hi pri, others in round robin */
    ADC_PRI_THRU_SOC22_HIPRI,        /*!< SOC 0-22 hi pri, others in round robin */
    ADC_PRI_THRU_SOC23_HIPRI,        /*!< SOC 0-23 hi pri, others in round robin */
    ADC_PRI_THRU_SOC24_HIPRI,        /*!< SOC 0-24 hi pri, others in round robin */
    ADC_PRI_THRU_SOC25_HIPRI,        /*!< SOC 0-25 hi pri, others in round robin */
    ADC_PRI_THRU_SOC26_HIPRI,        /*!< SOC 0-26 hi pri, others in round robin */
    ADC_PRI_THRU_SOC27_HIPRI,        /*!< SOC 0-27 hi pri, others in round robin */
    ADC_PRI_THRU_SOC28_HIPRI,        /*!< SOC 0-28 hi pri, others in round robin */
    ADC_PRI_THRU_SOC29_HIPRI,        /*!< SOC 0-29 hi pri, others in round robin */
    ADC_PRI_THRU_SOC30_HIPRI,        /*!< SOC 0-30 hi pri, others in round robin */
    ADC_PRI_ALL_HIPRI                /*!< All priorities based on SOC number */
} ADC_PriorityMode;

/**
  * @}
  */

/** @defgroup ADC_REFERENCEMODE ADC Reference Voltage Source Selection
  * @{
  * @brief  Macro definitions about ADC reference voltage source.
  */
typedef enum {
    ADC_REFERENCE_INTERNAL = 0U,    /*!< Internal reference voltage is used */
    ADC_REFERENCE_EXTERNAL          /*!< External reference voltage is used */
} ADC_ReferenceMode;

/**
  * @}
  */

/** @defgroup ADC_REFERENCEVOLTAGE ADC Reference Voltage Value Selection
  * @{
  * @brief  Macro definitions about ADC reference voltage value.
  */
typedef enum {
    ADC_REFERENCE_3_3V = 0U,    /*!< 3.3V is valid when ADC reference */
    ADC_REFERENCE_2_5V,         /*!< 2.5V is valid when ADC reference */
    ADC_REFERENCE_1_65V,        /*!< 1.65V is valid when ADC reference */
    ADC_REFERENCE_VREFHI        /*!< VREFHI is valid when ADC reference */
} ADC_ReferenceVoltage;

/**
  * @}
  */

/** @defgroup ADC_PPBSYMBOL ADC Post-processing Block Symbol Selection
  * @{
  * @brief  Macro definitions about ADC Post-processing Block Symbol
  */
typedef enum {
    ADC_PPB_PosSyb = 0U,    /*Positive numbers */
    ADC_PPB_NegSyb          /*Negative numbers */
} ADC_PPBSymbol;

/**
  * @}
  */

/** @defgroup ADC_PULSEPOSMODE ADC pulseMode parameter Selection
  * @{
  * @brief  Macro definitions about ADC pulseMode parameter
  */
typedef enum {
    ADC_PULSE_END_OF_ACQ_WIN = 0U,    /*!< Occurs at the end of the acquisition window */
    ADC_PULSE_END_OF_CONV             /*!< Occurs at the end of the conversion */
} ADC_PulsePosMode;

/**
  * @}
  */

/** @defgroup ADC_SGAINSEL ADC Source Gain Selection
  * @{
  * @brief  Macro definitions about ADC input source gain selection
  */
typedef enum {
    ADC_SGAIN_14DIV32 = 0U,    /*!< ADC SGAIN = 14/32 */
    ADC_SGAIN_1DIV2,           /*!< ADC SGAIN = 1/2 */
    ADC_SGAIN_1                /*!< ADC SGAIN = 1 */
} ADC_SgainSel;

/**
  * @}
  */

/** @defgroup ADC_EN ADC function enable or disable Selection
  * @{
  * @brief  Macro definitions about ADC function enable or disable
  */
typedef enum {
    ADC_DISABLE = 0U,    /*!< ADC Function disable */
    ADC_ENABLE           /*!< ADC Function enable */
} ADC_EN;

/**
  * @}
  */

/** @defgroup ADC_ChannelType ADC channel Selection
  * @{
  * @brief  Macro definitions about ADC channel Selection
  */
typedef enum
{
    ADC_CHANNEL_ODD     = 0U, /*!< ADC Odd Channel */
    ADC_CHANNEL_EVEN    = 1U  /*!< ADC Even Channel */
} ADC_ChannelType;

/**
  * @}
  */

/** @defgroup ADC_SyncInput ADC syncin channel Selection
  * @{
  * @brief  Macro definitions about ADC syncin channel Selection
  */
typedef enum
{
    ADC_SYNCIN_DISABLE          = 0x00U,  /*!< ADC Syncin is disabled  */
    ADC_SYNCIN_EPWM1SYNCOUT     = 0x01U,  /*!< ADC Syncin is EPWM1SYNCOUT */
    ADC_SYNCIN_EPWM2SYNCOUT     = 0x02U,  /*!< ADC Syncin is EPWM2SYNCOUT */
    ADC_SYNCIN_EPWM3SYNCOUT     = 0x03U,  /*!< ADC Syncin is EPWM3SYNCOUT */
    ADC_SYNCIN_EPWM4SYNCOUT     = 0x04U,  /*!< ADC Syncin is EPWM4SYNCOUT */
    ADC_SYNCIN_EPWM5SYNCOUT     = 0x05U,  /*!< ADC Syncin is EPWM5SYNCOUT */
    ADC_SYNCIN_EPWM6SYNCOUT     = 0x06U,  /*!< ADC Syncin is EPWM6SYNCOUT */
    ADC_SYNCIN_EPWM7SYNCOUT     = 0x07U,  /*!< ADC Syncin is EPWM7SYNCOUT */
    ADC_SYNCIN_EPWM8SYNCOUT     = 0x08U,  /*!< ADC Syncin is EPWM8SYNCOUT */
    ADC_SYNCIN_EPWM9SYNCOUT     = 0x09U,  /*!< ADC Syncin is EPWM9SYNCOUT */
    ADC_SYNCIN_EPWM10SYNCOUT    = 0x0AU,  /*!< ADC Syncin is EPWM10SYNCOUT */
    ADC_SYNCIN_EPWM11SYNCOUT    = 0x0BU,  /*!< ADC Syncin is EPWM11SYNCOUT */
    ADC_SYNCIN_EPWM12SYNCOUT    = 0x0CU,  /*!< ADC Syncin is EPWM12SYNCOUT */
    ADC_SYNCIN_EPWM13SYNCOUT    = 0x0DU,  /*!< ADC Syncin is EPWM13SYNCOUT */
    ADC_SYNCIN_EPWM14SYNCOUT    = 0x0EU,  /*!< ADC Syncin is EPWM14SYNCOUT */
    ADC_SYNCIN_EPWM15SYNCOUT    = 0x0FU,  /*!< ADC Syncin is EPWM15SYNCOUT */
    ADC_SYNCIN_EPWM16SYNCOUT    = 0x10U,  /*!< ADC Syncin is EPWM16SYNCOUT */
    ADC_SYNCIN_EPWM17SYNCOUT    = 0x11U,  /*!< ADC Syncin is EPWM17SYNCOUT */
    ADC_SYNCIN_EPWM18SYNCOUT    = 0x12U,  /*!< ADC Syncin is EPWM18SYNCOUT */
    ADC_SYNCIN_ECAP1SYNCOUT     = 0x13U,  /*!< ADC Syncin is ECAP1YNCOUT */
    ADC_SYNCIN_ECAP2SYNCOUT     = 0x14U,  /*!< ADC Syncin is ECAP2SYNCOUT */
    ADC_SYNCIN_ECAP3SYNCOUT     = 0x15U,  /*!< ADC Syncin is ECAP3SYNCOUT */
    ADC_SYNCIN_ECAP4SYNCOUT     = 0x16U,  /*!< ADC Syncin is ECAP4SYNCOUT */
    ADC_SYNCIN_ECAP5SYNCOUT     = 0x17U,  /*!< ADC Syncin is ECAP5SYNCOUT */
    ADC_SYNCIN_ECAP6SYNCOUT     = 0x18U,  /*!< ADC Syncin is ECAP6SYNCOUT */
    ADC_SYNCIN_ECAP7SYNCOUT     = 0x19U,  /*!< ADC Syncin is ECAP7SYNCOUT */
    ADC_SYNCIN_INPUTXBAROUTPUT5 = 0x1AU,  /*!< ADC Syncin is INPUTXBAROUTPUT5 */
    ADC_SYNCIN_INPUTXBAROUTPUT6 = 0x1BU  /*!< ADC Syncin is INPUTXBAROUTPUT6 */
} ADC_SyncInput;

/**
  * @}
  */

/** @defgroup ADC_PPBIntSrcSelect ADC PPB Interrupt Source Selection
  * @{
  * @brief  Macro definitions about ADC PPB Interrupt Source Selection
  */
typedef enum
{
    ADC_PPB_OS_INT_1 = 0x0U,          /*!< PCount generates PPB interrupt */
    ADC_PPB_OS_INT_2 = 0x1U,          /*!< PCount/Sync generates PPB interrupt */
} ADC_PPBIntSrcSelect;

/**
  * @}
  */

/** @defgroup ADC_Select ADC Interrupt Source Selection
  * @{
  * @brief  Macro definitions about ADC Interrupt Source Selection
  */
typedef enum
{
    ADC_INT_TRIGGER_EOC0   = 0U,        /*!< SOC/EOC0 */
    ADC_INT_TRIGGER_EOC1   = 1U,        /*!< SOC/EOC1 */
    ADC_INT_TRIGGER_EOC2   = 2U,        /*!< SOC/EOC2 */
    ADC_INT_TRIGGER_EOC3   = 3U,        /*!< SOC/EOC3 */
    ADC_INT_TRIGGER_EOC4   = 4U,        /*!< SOC/EOC4 */
    ADC_INT_TRIGGER_EOC5   = 5U,        /*!< SOC/EOC5 */
    ADC_INT_TRIGGER_EOC6   = 6U,        /*!< SOC/EOC6 */
    ADC_INT_TRIGGER_EOC7   = 7U,        /*!< SOC/EOC7 */
    ADC_INT_TRIGGER_EOC8   = 8U,        /*!< SOC/EOC8 */
    ADC_INT_TRIGGER_EOC9   = 9U,        /*!< SOC/EOC9 */
    ADC_INT_TRIGGER_EOC10  = 10U,       /*!< SOC/EOC10 */
    ADC_INT_TRIGGER_EOC11  = 11U,       /*!< SOC/EOC11 */
    ADC_INT_TRIGGER_EOC12  = 12U,       /*!< SOC/EOC12 */
    ADC_INT_TRIGGER_EOC13  = 13U,       /*!< SOC/EOC13 */
    ADC_INT_TRIGGER_EOC14  = 14U,       /*!< SOC/EOC14 */
    ADC_INT_TRIGGER_EOC15  = 15U,       /*!< SOC/EOC15 */
    ADC_INT_TRIGGER_EOC16  = 16U,       /*!< SOC/EOC16 */
    ADC_INT_TRIGGER_EOC17  = 17U,       /*!< SOC/EOC17 */
    ADC_INT_TRIGGER_EOC18  = 18U,       /*!< SOC/EOC18 */
    ADC_INT_TRIGGER_EOC19  = 19U,       /*!< SOC/EOC19 */
    ADC_INT_TRIGGER_EOC20  = 20U,       /*!< SOC/EOC20 */
    ADC_INT_TRIGGER_EOC21  = 21U,       /*!< SOC/EOC21 */
    ADC_INT_TRIGGER_EOC22  = 22U,       /*!< SOC/EOC22 */
    ADC_INT_TRIGGER_EOC23  = 23U,       /*!< SOC/EOC23 */
    ADC_INT_TRIGGER_EOC24  = 24U,       /*!< SOC/EOC24 */
    ADC_INT_TRIGGER_EOC25  = 25U,       /*!< SOC/EOC25 */
    ADC_INT_TRIGGER_EOC26  = 26U,       /*!< SOC/EOC26 */
    ADC_INT_TRIGGER_EOC27  = 27U,       /*!< SOC/EOC27 */
    ADC_INT_TRIGGER_EOC28  = 28U,       /*!< SOC/EOC28 */
    ADC_INT_TRIGGER_EOC29  = 29U,       /*!< SOC/EOC29 */
    ADC_INT_TRIGGER_EOC30  = 30U,       /*!< SOC/EOC30 */
    ADC_INT_TRIGGER_EOC31  = 31U,       /*!< SOC/EOC31 */
    ADC_INT_TRIGGER_OSINT1 = 32U,       /*!< OSINT1 */
    ADC_INT_TRIGGER_OSINT2 = 33U,       /*!< OSINT2 */
    ADC_INT_TRIGGER_OSINT3 = 34U,       /*!< OSINT3 */
    ADC_INT_TRIGGER_OSINT4 = 35U        /*!< OSINT4 */
} ADC_IntTrigger;

/**
  * @}
  */

/** @defgroup ADC_PPBCompSource ADC compare source Selection
  * @{
  * @brief  Macro definitions about ADC compare source Selection
  */
typedef enum
{
    ADC_PPB_COMPSOURCE_RESULT = 0x0U,   /*!< PPB compare source is ADCRESULT */
    ADC_PPB_COMPSOURCE_PSUM   = 0x1U,   /*!< PPB compare source is PSUM */
    ADC_PPB_COMPSOURCE_SUM    = 0x2U    /*!< PPB compare source is SUM */
} ADC_PPBCompSource;

/**
  * @}
  */

/** @defgroup ADC_Select ADC Selection
  * @{
  * @brief  Macro definitions about ADC Selection
   */
typedef enum
{
     ADC_A = 0U,                        /*!< Select ADCA instance */
     ADC_B = 1U,                        /*!< Select ADCB instance */
     ADC_C = 2U                         /*!< Select ADCC instance */
} ADC_Select;

/**
  * @}
  */

/** @defgroup ADC_ResultSelect ADC Safety Checker Result Selection
  * @{
  * @brief  Macro definitions about ADC Safety Checker Result Selection
   */
typedef enum
{
    ADC_RESULT0  = 0U,                  /*!< Select ADC Result 0 */
    ADC_RESULT1  = 1U,                  /*!< Select ADC Result 1 */
    ADC_RESULT2  = 2U,                  /*!< Select ADC Result 2 */
    ADC_RESULT3  = 3U,                  /*!< Select ADC Result 3 */
    ADC_RESULT4  = 4U,                  /*!< Select ADC Result 4 */
    ADC_RESULT5  = 5U,                  /*!< Select ADC Result 5 */
    ADC_RESULT6  = 6U,                  /*!< Select ADC Result 6 */
    ADC_RESULT7  = 7U,                  /*!< Select ADC Result 7 */
    ADC_RESULT8  = 8U,                  /*!< Select ADC Result 8 */
    ADC_RESULT9  = 9U,                  /*!< Select ADC Result 9 */
    ADC_RESULT10 = 10U,                 /*!< Select ADC Result 10 */
    ADC_RESULT11 = 11U,                 /*!< Select ADC Result 11 */
    ADC_RESULT12 = 12U,                 /*!< Select ADC Result 12 */
    ADC_RESULT13 = 13U,                 /*!< Select ADC Result 13 */
    ADC_RESULT14 = 14U,                 /*!< Select ADC Result 14 */
    ADC_RESULT15 = 15U,                  /*!< Select ADC Result 15 */
    ADC_RESULT16  = 16U,                /*!< Select ADC Result 16 */
    ADC_RESULT17  = 17U,                /*!< Select ADC Result 17 */
    ADC_RESULT18  = 18U,                /*!< Select ADC Result 18 */
    ADC_RESULT19  = 19U,                /*!< Select ADC Result 19 */
    ADC_RESULT20  = 20U,                /*!< Select ADC Result 20 */
    ADC_RESULT21  = 21U,                /*!< Select ADC Result 21 */
    ADC_RESULT22  = 22U,                /*!< Select ADC Result 22 */
    ADC_RESULT23  = 23U,                /*!< Select ADC Result 23 */
    ADC_RESULT24  = 24U,                /*!< Select ADC Result 24 */
    ADC_RESULT25  = 25U,                /*!< Select ADC Result 25 */
    ADC_RESULT26  = 26U,                /*!< Select ADC Result 26 */
    ADC_RESULT27  = 27U,                /*!< Select ADC Result 27 */
    ADC_RESULT28  = 28U,                /*!< Select ADC Result 28 */
    ADC_RESULT29  = 29U,                /*!< Select ADC Result 29 */
    ADC_RESULT30  = 30U,                /*!< Select ADC Result 30 */
    ADC_RESULT31  = 31U                /*!< Select ADC Result 31 */
} ADC_ResultSelect;

/**
  * @}
  */

/** @defgroup ADC_SafetyCheckInst ADC Safety Checker Input Selection
  * @{
  * @brief  Macro definitions about ADC Safety Checker Input Selection
   */
typedef enum
{
    ADC_SAFETY_CHECKER_INPUT_DISABLE  = 0x0U, /*!< Safety checker i/p disabled */
    ADC_SAFETY_CHECKER_INPUT_SOCx     = 0x1U, /*!< Safety checker i/p is SOCx */
    ADC_SAFETY_CHECKER_INPUT_PPBx     = 0x2U, /*!< Safety checker i/p is PPBx */
    ADC_SAFETY_CHECKER_INPUT_PPBSUMx  = 0x3U  /*!< Safety checker i/p is PPBSUMx */
} ADC_SafetyCheckerInput;

/**
  * @}
  */

/** @defgroup ADC_SafetyCheckInst ADC Safety Checker Result
  * @{
  * @brief  Macro definitions about ADC Safety Checker Result
   */
typedef enum
{
  ADC_SAFETY_CHECK1  = 0x0U,            /*!< Safety Check Result 1 */
  ADC_SAFETY_CHECK2  = 0x1U             /*!< Safety Check Result 2 */
} ADC_SafetyCheckInst;

/**
  * @}
  */

/** @defgroup ADC_SafetyCheckEvent ADC Safety Checker Event
  * @{
  * @brief  Macro definitions about ADC Safety Checker Event
   */
typedef enum
{
    ADC_SAFETY_CHECK_EVENT1 = 0U,    /*!< Safety Check Event 1 */
    ADC_SAFETY_CHECK_EVENT2 = 3U,    /*!< Safety Check Event 2 */
    ADC_SAFETY_CHECK_EVENT3 = 6U,    /*!< Safety Check Event 3 */
    ADC_SAFETY_CHECK_EVENT4 = 9U     /*!< Safety Check Event 4 */
} ADC_SafetyCheckEvent;

/**
  * @}
  */

/** @defgroup ADC_SafetyCheckResult ADC Safety Checker Event Selection
  * @{
  * @brief  Macro definitions about ADC Safety Checker Event Selection
   */
typedef enum
{
    ADC_SAFETY_CHECK_RES1OVF = 0U,    /*!< Safety Check Result1 Overflow */
    ADC_SAFETY_CHECK_RES2OVF = 1U,    /*!< Safety Check Result2 Overflow */
    ADC_SAFETY_CHECK_OOT     = 2U     /*!< Safety Check OOT */
} ADC_SafetyCheckResult;

/**
  * @}
  */

/** @defgroup ADC_Checker ADC Safety Checker Selection
  * @{
  * @brief  Macro definitions about ADC Safety Checker Selection
   */
typedef enum
{
    ADC_SAFETY_CHECKER1 = 0U,    /*!< Safety Checker1 */
    ADC_SAFETY_CHECKER2 = 1U,    /*!< Safety Checker2 */
    ADC_SAFETY_CHECKER3 = 2U,    /*!< Safety Checker3 */
    ADC_SAFETY_CHECKER4 = 3U,    /*!< Safety Checker4 */
    ADC_SAFETY_CHECKER5 = 4U,    /*!< Safety Checker5 */
    ADC_SAFETY_CHECKER6 = 5U,    /*!< Safety Checker6 */
    ADC_SAFETY_CHECKER7 = 6U,    /*!< Safety Checker7 */
    ADC_SAFETY_CHECKER8 = 7U     /*!< Safety Checker8 */
}ADC_Checker;

/**
  * @}
  */

/** @defgroup ADC_SafetyCheckFlag ADC Safety Check Flag
  * @{
  * @brief  Macro definitions about ADC Safety Check Flag
  */
typedef enum
{
    ADC_SAFETY_CHECK_OOT_FLG     = 0U,    /*!< Safety Check Out-of-Tolerance Flag */
    ADC_SAFETY_CHECK_RES1OVF_FLG = 2U,    /*!< Safety Check Result1 Overflow Flag */
    ADC_SAFETY_CHECK_RES2OVF_FLG = 4U     /*!< Safety Check Result2 Overflow Flag */
}ADC_SafetyCheckFlag;

/**
  * @}
  */

/** @defgroup ADC_RepInstance ADC repeat instance parameter
  * @{
  * @brief  Macro definitions about ADC repeat instance parameter
  */
typedef enum
{
    ADC_REPINST1 = 0x0U,    /*!< Select ADC repeater instance 1 */
    ADC_REPINST2 = 0x1U     /*!< Select ADC repeater instance 2 */
} ADC_RepInstance;

/**
  * @}
  */

/** @defgroup ADC_RepMode ADC repeat mode configuration
  * @{
  * @brief  Macro definitions about ADC repeat mode
  */
typedef enum
{
    ADC_REPMODE_OVERSAMPLING  = 0x0U,    /*!< ADC repeater mode is oversampling */
    ADC_REPMODE_UNDERSAMPLING = 0x1U     /*!< ADC repeater mode is undersampling */
} ADC_RepMode;

/**
  * @}
  */

/** @defgroup ADC_RepeaterConfig ADC repeat configuration parameter
  * @{
  * @brief  Macro definitions about ADC repeat configuration parameter
  */
typedef struct
{
    ADC_RepMode repMode;        /*!< Repeater Mode */
    ADC_Trigger repTrigger;     /*!< Repeater Trigger */
    ADC_SyncInput repSyncin;    /*!< Repeater Syncin */
    uint16_t repCount;          /*!< Repeater trigger count */
    uint16_t repPhase;          /*!< Repeater trigger phase delay in sysclk cycles */
    uint16_t repSpread;         /*!< Repeater trigger spread in sysclk cycles */
} ADC_RepeaterConfig;

/**
  * @}
  */

/** @defgroup ADC_SOCMASK ADC ADCSOCFRC1 Register Definition
  * @{
  * @brief  Macro definitions about ADC_SOCMASK Register Definition
  * @note   The ADC_SOCMASK register is used to configure the ADC Software trigger SOCx.
  */
#define ADC_FORCE_SOC0     (0x00000001UL)    /*!< SW trigger ADC SOC 0 */
#define ADC_FORCE_SOC1     (0x00000002UL)    /*!< SW trigger ADC SOC 1 */
#define ADC_FORCE_SOC2     (0x00000004UL)    /*!< SW trigger ADC SOC 2 */
#define ADC_FORCE_SOC3     (0x00000008UL)    /*!< SW trigger ADC SOC 3 */
#define ADC_FORCE_SOC4     (0x00000010UL)    /*!< SW trigger ADC SOC 4 */
#define ADC_FORCE_SOC5     (0x00000020UL)    /*!< SW trigger ADC SOC 5 */
#define ADC_FORCE_SOC6     (0x00000040UL)    /*!< SW trigger ADC SOC 6 */
#define ADC_FORCE_SOC7     (0x00000080UL)    /*!< SW trigger ADC SOC 7 */
#define ADC_FORCE_SOC8     (0x00000100UL)    /*!< SW trigger ADC SOC 8 */
#define ADC_FORCE_SOC9     (0x00000200UL)    /*!< SW trigger ADC SOC 9 */
#define ADC_FORCE_SOC10    (0x00000400UL)    /*!< SW trigger ADC SOC 10 */
#define ADC_FORCE_SOC11    (0x00000800UL)    /*!< SW trigger ADC SOC 11 */
#define ADC_FORCE_SOC12    (0x00001000UL)    /*!< SW trigger ADC SOC 12 */
#define ADC_FORCE_SOC13    (0x00002000UL)    /*!< SW trigger ADC SOC 13 */
#define ADC_FORCE_SOC14    (0x00004000UL)    /*!< SW trigger ADC SOC 14 */
#define ADC_FORCE_SOC15    (0x00008000UL)    /*!< SW trigger ADC SOC 15 */
#define ADC_FORCE_SOC16    (0x00010000UL)    /*!< SW trigger ADC SOC 16 */
#define ADC_FORCE_SOC17    (0x00020000UL)    /*!< SW trigger ADC SOC 17 */
#define ADC_FORCE_SOC18    (0x00040000UL)    /*!< SW trigger ADC SOC 18 */
#define ADC_FORCE_SOC19    (0x00080000UL)    /*!< SW trigger ADC SOC 19 */
#define ADC_FORCE_SOC20    (0x00100000UL)    /*!< SW trigger ADC SOC 20 */
#define ADC_FORCE_SOC21    (0x00200000UL)    /*!< SW trigger ADC SOC 21 */
#define ADC_FORCE_SOC22    (0x00400000UL)    /*!< SW trigger ADC SOC 22 */
#define ADC_FORCE_SOC23    (0x00800000UL)    /*!< SW trigger ADC SOC 23 */
#define ADC_FORCE_SOC24    (0x01000000UL)    /*!< SW trigger ADC SOC 24 */
#define ADC_FORCE_SOC25    (0x02000000UL)    /*!< SW trigger ADC SOC 25 */
#define ADC_FORCE_SOC26    (0x04000000UL)    /*!< SW trigger ADC SOC 26 */
#define ADC_FORCE_SOC27    (0x08000000UL)    /*!< SW trigger ADC SOC 27 */
#define ADC_FORCE_SOC28    (0x10000000UL)    /*!< SW trigger ADC SOC 28 */
#define ADC_FORCE_SOC29    (0x20000000UL)    /*!< SW trigger ADC SOC 29 */
#define ADC_FORCE_SOC30    (0x40000000UL)    /*!< SW trigger ADC SOC 30 */
#define ADC_FORCE_SOC31    (0x80000000UL)    /*!< SW trigger ADC SOC 31 */

/**
  * @}
  */

/** @defgroup ADC_PPBN ADC PPB1CONFIG Register Definition
  * @{
  * @brief  Macro definitions about ADC PPBn CONFIG Register Definition
  * @note   The PPBnCONFIG register is used to configure the ADC post-processing block.
  */
#define ADC_PPBNCONFIG_TWOSCOMPEN     (0x00000020UL)     /*!< ADC Post Processing Block 1 Two's Complement Enable */
#define ADC_PPBNCONFIG_CBCEN          (0x00000040UL)    /*!< Cycle By Cycle Enable */
#define ADC_PPBNCONFIG_CONFIG_MASK    (0x0000001FUL)    /*!< ADC_PPBNCONFIG Config Mask Value */
#define ADC_PPBNOFFCAL_OFFCAL_MASK    (0x000003FFUL)    /*!< ADC_ADCPPBNOFFCAL Calibration Offset Mask Value */
#define ADC_PPBNOFFREF_OFFSET_MASK    (0x00000FFFUL)    /*!< ADC_ADCPPBNOFFREF ADC PPBN Offset Reference Register Mask Value */
#define ADC_PPBTRIP_MASK              (0x00000FFFUL)    /*!< ADC_PPBTRIP Mask Value */
#define ADC_PPBTRIP_SYBOL_MASK        (0x00001000UL)    /*!< ADC_PPBTRIP Sybol Mask Value */
#define ADC_PPBTRIPSIGN_OFFSET        (0x0000000CUL)    /*!< ADC_PPBTRIP Symbol Sign Offset Value */

/**
  * @}
  */

/** @defgroup ADC_CTL1 ADC CTL1 Register Definition
  * @{
  * @brief  Macro definitions about ADC CTL1 Register Definition
  * @note   The CTL1 register is used to configure the ADC interrupt trigger source, interrupt priority, and ADC power down.
  */
#define ADC_CTL1_INTPULSEPOS_MASK      (0x00000004UL)    /*!< ADC_CTL1 PulsePosMode Mask Value */
#define ADC_CTL1_INTPULSEPOS_OFFSET    (0x00000002UL)    /*!< ADC_CTL1 PulsePosMode Offset Value */
#define ADC_CTL1_ADCPWDNZ_MASK         (0x00000080UL)    /*!< ADC_CTL1 ADC Power Down Mask Value */
#define ADC_CTL1_ADCBSYFLAG_MASK       (0x00002000UL)    /*!< ADC_CTL1 ADC busy flag Mask Value */

/**
  * @}
  */

/** @defgroup ADC_CTL2 ADC CTL2 Register Definition
  * @{
  * @brief  Macro definitions about ADC CTL2 Register Definition
  * @note   The CTL2 register is used to configure the ADC clock prescaler.
  */
#define ADC_CTL2_PRESCALE_MASK    (0x0000003FUL)    /*!< ADC_CTL2 ClkPrescale Mask Value */

/**
  * @}
  */

/** @defgroup ADC_SOCNCTL ADC SOCnCTL Register Definition
  * @{
  * @brief  Macro definitions about ADC SOCnCTL Register Definition
  * @note   The SOCnCTL register is used to configure the channel selection, trigger selection, and trigger priority for each SOCn.
  */
#define ADC_SOCNCTL_MASK              (0xF7FF81FFUL)    /*!< ADCSOCnCTL Mask Value */
#define ADC_SOCNCTL_CHSEL_OFFSET      (0x0000000FUL)    /*!< ADCSOCnCTL Channel Sel Offset Value */
#define ADC_SOCNCTL_TRIGSEL_OFFSET    (0x00000014UL)    /*!< ADCSOCnCTL Trigger Sel Offset Value */

/**
  * @}
  */

/** @defgroup ADC_INTSOCSEL1 ADC INT SOCSEL1 Register Definition
  * @{
  * @brief  Macro definitions about ADC INT SOCSEL1 Register Definition
  * @note   The INT SOCSEL1 register is used to configure the interrupt trigger source for each SOCn.
  */
#define ADC_INTSOCSEL1_SOC0_MASK    (0x00000003UL)    /*!< ADC_INTSOCSEL1 Mask Value */

/**
  * @}
  */

/** @defgroup ADC_BURSTCTL ADC BURSTCTL Register Definition
  * @{
  * @brief  Macro definitions about ADC BURSTCTL Register Definition
  * @note   The BURSTCTL register is used to configure the burst trigger source and burst size for each SOCn.
  */
#define ADC_BURSTCTL_BURSTTRIGSEL_MASK    (0x0000003FUL)    /*!< ADC_BURSTCTL Bursttrigsel Mask Value */
#define ADC_BURSTCTL_BURSTSIZE_MASK       (0x00001F00UL)    /*!< ADC_BURSTCTL BURST_SIZE Mask Value */
#define ADC_BURSTCTL_BURSTSIZE_OFFSET     (0x00000008UL)    /*!< ADC_BURSTCTL BURST_SIZE Offset Value */
#define ADC_BURSTCTL_BURSTEN_MASK         (0x00008000UL)    /*!< ADC_BURSTCTL BURST_EN Mask Value */

/**
  * @}
  */

/** @defgroup ADC_SOCPRICTL ADC SOCPRICTL Register Definition
  * @{
  * @brief  Macro definitions about ADC SOCPRICTL Register Definition
  * @note   The SOCPRICTL register is used to configure the priority mode for each SOCn.
  */
#define ADC_SOCPRICTL_SOCPRIORITY_MASK      (0x0000003FUL)    /*!< ADC_SOCPRICTL priority mode Mask Value */
#define ADC_SOCPRICTL_SOCPRIORITY_OFFSET    (0x0UL)           /*!< ADC_SOCPRICTL priority mode Offset Value */
#define ADC_SOCPRICTL_RRPOINTER_MASK        (0x000007E0UL)    /*!< ADC_SOCPRICTL round robin pointer Mask Value */
#define ADC_SOCPRICTL_RRPOINTER_OFFSET      (0x5UL)           /*!< ADC_SOCPRICTL round robin pointer Offset Value */

/**
  * @}
  */

/** @defgroup ADC_ADCEVTSEL ADC ADCEVTSEL Register Definition
  * @{
  * @brief  Macro definitions about ADC ADCEVTSEL Register Definition
  * @note   The ADCEVTSEL register is used to configure the event selection, event interrupt selection, and event status for each SOCn.
  */
#define ADC_EVTSEL_MASK       (0x00000007UL)    /*!< ADC_ADCEVTSEL Mask Value */
#define ADC_EVTINTSEL_MASK    (0x00000007UL)    /*!< ADC_EVTINTSEL Mask Value */
#define ADC_EVTSTAT_MASK      (0x00000007UL)    /*!< ADC_EVTSTAT Mask Value */

/**
  * @}
  */

/** @defgroup ADC_ADCANACTL ADC ADCANACTL Register Definition
  * @{
  * @brief  Macro definitions about ADC ADCANACTL Register Definition
  * @note   The ADCANACTL register is used to configure the analog function selection.
  */
#define ADC_ADCANACTL_SGAINSEL_MASK      (0x00000300UL)    /*!< ADC_SGAINSEL Mask Value */
#define ADC_ADCANACTL_SGAINSEL_OFFSET    (8UL)             /*!< ADC_SGAINSEL Offset Value */
#define ADC_ADCANACTL_SDIF_MASK          (0x00002000UL)    /*!< ADC_SDIF Mask Value */
#define ADC_ADCANACTL_TSEN_MASK          (0x00200000UL)    /*!< ADC_TSEN Mask Value */

/**
  * @}
  */

/** @defgroup ADC_ADCANATRIM ADC ADCANATRIM Register Definition
  * @{
  * @brief  Macro definitions about ADC ADCANATRIM Register Definition
  * @note   The ADCANATRIM register is used to configure the analog trim function.
  */
#define ADC_ADCANATRIM_DISH_MASK    (0x00000001UL)    /*!< ADC_DISH Mask Value */

/**
  * @}
  */

/** @defgroup ADC_INTSEL1N2 ADC INT Register Definition
  * @{
  * @brief  Macro definitions about ADC INT Register Definition
  * @note   The INTSEL1N2 register is used to configure the interrupt selection for each SOCn.
  */
#define ADC_ADCINTSELXNY_INTXE_MASK       (0x00000040UL)    /*!< ADC_ADCINTSELXNY ADCINT Interrupt Enable Mask Value */
#define ADC_ADCINTSELXNY_INTXSEL_MASK     (0x0000003FUL)    /*!< ADC_ADCINTSELXNY EOC Source Select Mask Value */
#define ADC_ADCINTSELXNY_INTXCONT_MASK    (0x00000080UL)    /*!< ADC_ADCINTSELXNY ADCINTX Continue to Interrupt Mode Mask Value */

/**
  * @}
  */

/** @defgroup ADC_INTEN ADC INT Register Definition
  * @{
  * @brief  Macro definitions about ADC INT Register Definition
  * @note   The INTEN register is used to configure each interrupt enable output to NVIC.
  */
#define ADC_ADCINTEN_MASK    (0x00000001UL)    /*!< ADC_ADCINTEN ADCINT Interrupt Enable output to NVIC */

/**
  * @}
  */

/** @defgroup ADC_ADCTRIM ADC ADCTRIM Register Definition
  * @{
  * @brief  Macro definitions about ADC ADCTRIM Register Definition
  * @note   The ADCTRIM register is used to configure the offset value and direction of the ADC trim.
  */
#define ADC_ADCTRIM_TRIMOFFSET_MASK    (0x00003F00UL)    /*!< ADC_ADCTRIM OFFSET Value Mask Value */

/**
  * @}
  */

/** @defgroup ADC_ADCRESULT ADC ADCRESULT Register Definition
  * @{
  * @brief  Macro definitions about ADC ADCRESULT Register Definition
  * @note   The ADCRESULT register is used to store the conversion result of each SOCn.
  */
#define ADC_ADCRESULTN_MASK            (0x00000FFFUL)    /*!< ADC_RESULTn Mask Value */
#define ADC_ADCPPBRESULTN_MASK         (0x00000FFFUL)    /*!< ADC_PPBRESULTn Mask Value */
#define ADC_ADCPPBRESULTN_SIGN_MASK    (0x00001000UL)    /*!< ADC_PPBRESULTn Sign Mask Value */

/**
  * @}
  */

/** @defgroup ADC_TSENSORCFG Parameter Configuration of ADC Temperature Sensor
  * @{
  * @brief  Macro definitions about reference voltage and conversion coefficient of ADC
  */
#define ADC_TSENSOR_25C_TRIM                  (0.925F)    /*!< Reference voltage of temperature sensor*/
#define ADC_TSENSOR_CONVERSION_COEFFICIENT    (3.1F)      /*!< ADC_TSENSOR_CONVERSION_COEFFICIENT=(4096*0.031/ADC_TSENSOR_VREH_VOLT)*/

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
  * \brief  Enable the analog-to-digital converter module synchronous prescaler.
  * \note   This function is used to enable clock division for multiple ADC synchronization.
  * \param  base           ADC base address
  *                         - ADCA: ADC A base address
  *                         - ADCB: ADC B base address
  *                         - ADCC: ADC C base address
  */
static inline void ADC_enableSyncPrescaler (ADC_TypeDef *base)
{
    SET_BIT(base->CTL2.WORDVAL, ADC_CTL2_SYNCEN_M);
}

/**
  * \brief  Disable the analog-to-digital converter module synchronous prescaler.
  * \note   This function is used to disable clock division for multiple ADC synchronization.
  * \param  base           ADC base address
  *                         - ADCA: ADC A base address
  *                         - ADCB: ADC B base address
  *                         - ADCC: ADC C base address
  */
static inline void ADC_disableSyncPrescaler (ADC_TypeDef *base)
{
    CLEAR_BIT(base->CTL2.WORDVAL, ADC_CTL2_SYNCEN_M);
}

/**
  * \brief  Configures the analog-to-digital converter module prescaler.
  * \note   clkPrescale parameter specifies the value by which the input clock is divided to make the ADCCLK.
  * \param  base           ADC base address
  *                         - ADCA: ADC A base address
  *                         - ADCB: ADC B base address
  *                         - ADCC: ADC C base address
  * \param  clkPrescale    ADC clock prescaler
  *                         This parameter can be any value of @ref ADC_CLKPRESCALE.
  */
static inline void ADC_setPrescaler (ADC_TypeDef *base, ADC_ClkPrescale clkPrescale)
{
    MODIFY_REG(base->CTL2.WORDVAL, ADC_CTL2_PRESCALE_MASK, (clkPrescale & ADC_CTL2_PRESCALE_MASK));
}

/**
  * \brief  Configures a start-of-conversion (SOC) in the ADC.
  * \param  base            ADC base address
  *                          - ADCA: ADC A base address
  *                          - ADCB: ADC B base address
  *                          - ADCC: ADC C base address
  * \param  socNumber       ADC SOC number
  *                          This parameter can be any value of @ref ADC_SOCNUMBER.
  * \param  trigger         ADC trigger source
  *                          This parameter can be any value of @ref ADC_TRIGGER.
  * \param  channel         ADC channel number
  *                          This parameter can be any value of @ref ADC_CHANNEL.
  * \param  sampleWindow    ADC sample window
  *                          This parameter can be one value that range from 1 to 512.
  */
static inline void ADC_setupSOC (ADC_TypeDef *base, ADC_SOCNumber socNumber, ADC_Trigger trigger, ADC_Channel channel,
                                 uint32_t sampleWindow)
{
    uint32_t temp;

    __IO uint32_t *mSocReg = &(base->SOC0CTL.WORDVAL);
    temp                   = ((trigger << ADC_SOCNCTL_TRIGSEL_OFFSET) | (channel << ADC_SOCNCTL_CHSEL_OFFSET) |
                              ((sampleWindow - 1UL) & 0x1FFUL));
    mSocReg[socNumber]     = temp;
}

/**
  * \brief  Configures the analog-to-digital converter resolution and signal mode.
  * \param  base            ADC base address
  *                          - ADCA: ADC A base address
  *                          - ADCB: ADC B base address
  *                          - ADCC: ADC C base address
  * \param  socNumber       ADC SOC number
  *                          This parameter can be any value of @ref ADC_SOCNUMBER.
  * \param  trigger         ADC trigger source
  *                          This parameter can be any value of @ref ADC_TRIGGER.
  * \param  extChannel      ADC desired external channel
  *                          This parameter can be any value of @ref ADC_EXTCHANNEL.
  */
static inline void ADC_selectSOCExtChannel (ADC_TypeDef *base, ADC_SOCNumber socNumber, uint16_t extChannel)
{
    __IO uint32_t *addr;
    addr = (uint32_t *)(&(base->SOC0CTL.WORDVAL) + ((uint32_t)socNumber * 1UL));
    MODIFY_REG(*addr, (ADC_SOC0CTL_EXTCHSEL_M), (extChannel << ADC_SOC0CTL_EXTCHSEL_S));
}

/**
  * \brief  Forces software trigger to ADC trigger repeater block
  * \param  base            ADC base address
  *                          - ADCA: ADC A base address
  *                          - ADCB: ADC B base address
  *                          - ADCC: ADC C base address
  * \param  repInstance      ADC repeater instance to be triggered
  *                          This parameter can be any value of @ref ADC_RepInstance.
  */
static inline void ADC_forceRepeaterTrigger (ADC_TypeDef *base, uint16_t repInstance)
{
    SET_BIT(TYPE32(&(base->REP1FRC.WORDVAL) + (repInstance * (5UL))), ADC_REP1FRC_SWFRC_M);
}

/**
  * \brief  Gets the current status for repeater block.
  * \param  base            ADC base address
  *                          - ADCA: ADC A base address
  *                          - ADCB: ADC B base address
  *                          - ADCC: ADC C base address
  * \param  repInstance      ADC repeater instance to be triggered
  *                          This parameter can be any value of @ref ADC_RepInstance.
  */
static inline uint16_t ADC_getRepeaterStatus (ADC_TypeDef *base, uint16_t repInstance)
{
    return READ_BIT(TYPE32(&(base->REP1CTL.WORDVAL) + (repInstance * (5UL))),
                    (ADC_REP1CTL_TRIGGER_M | ADC_REP1CTL_PHASEOVF_M | ADC_REP1CTL_TRIGGEROVF_M));
}

/**
  * \brief  Configures ADC the interrupt SOC trigger of an SOC.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  socNumber    ADC SOC number
  *                       This parameter can be any value of @ref ADC_SOCNUMBER.
  * \param  trigger      ADC trigger source
  *                       This parameter can be any value of @ref ADC_TRIGGER.
  */
static inline void ADC_setInterruptSOCTrigger (ADC_TypeDef *base, ADC_SOCNumber socNumber, ADC_IntSOCTrigger trigger)
{
    uint32_t temp;
    __IO uint32_t *addr;

    temp = (socNumber > ADC_SOC_NUMBER15)? 1 : 0;
    addr = (uint32_t *)(&(base->INTSOCSEL1) + temp);
    temp = (socNumber - (temp * 0xFUL)) << 1UL;
    MODIFY_REG(*addr, (ADC_INTSOCSEL1_SOC0_MASK << temp), ((trigger & ADC_INTSOCSEL1_SOC0_MASK) << temp));
}

/**
  * \brief  Sets the timing of the end-of-conversion pulse
  * \param  base            ADC base address
  *                          - ADCA: ADC A base address
  *                          - ADCB: ADC B base address
  *                          - ADCC: ADC C base address
  * \param  pulsePosMode    ADC pulse position mode
  *                          This parameter can be any value of @ref ADC_PULSEPOSMODE.
  */
static inline void ADC_setInterruptPulsePosMode (ADC_TypeDef *base, ADC_PulsePosMode pulsePosMode)
{
    MODIFY_REG(base->CTL1.WORDVAL, ADC_CTL1_INTPULSEPOS_MASK,
               ((pulsePosMode << ADC_CTL1_INTPULSEPOS_OFFSET) & ADC_CTL1_INTPULSEPOS_MASK));
}

/**
  * \brief  Sets the timing of early interrupt generation.
  * \param  base           ADC base address
  *                         - ADCA: ADC A base address
  *                         - ADCB: ADC B base address
  *                         - ADCC: ADC C base address
  * \param  cycleOffset    ADC cycle offset
  *                         This parameter can be one value that range from 0 to 0xFFFF.
  */
static inline void ADC_setInterruptCycleOffset (ADC_TypeDef *base, uint32_t cycleOffset)
{
    WRITE_REG(base->INTCYCLE.WORDVAL, cycleOffset);
}

/**
  * \brief  Enables alternate timings for DMA trigger.
  * \param  base           ADC base address
  *                         - ADCA: ADC A base address
  *                         - ADCB: ADC B base address
  *                         - ADCC: ADC C base address
  */
static inline void ADC_enableAltDMATiming (ADC_TypeDef *base)
{
    SET_BIT(TYPE32(&(base->CTL1.WORDVAL)), ADC_CTL1_TDMAEN_M);
}

/**
  * \brief  Disables alternate timings for DMA trigger.
  * \param  base           ADC base address
  *                         - ADCA: ADC A base address
  *                         - ADCB: ADC B base address
  *                         - ADCC: ADC C base address
  */
static inline void ADC_disableAltDMATiming (ADC_TypeDef *base)
{
    CLEAR_BIT(TYPE32(&(base->CTL1.WORDVAL)), ADC_CTL1_TDMAEN_M);
}

/**
  * \brief  Gets the result ready status for ADC interrupt
  * \param  base           ADC base address
  *                         - ADCA: ADC A base address
  *                         - ADCB: ADC B base address
  *                         - ADCC: ADC C base address
  * \param  adcIntNum      ADC interrupt number within the ADC wrapper
  *                        This parameter can be any value of@ref ADC_IntNumber.
  */
static inline uint32_t ADC_getIntResultStatus (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    return (READ_BIT(base->INTFLG.WORDVAL, (1U << ((uint16_t)adcIntNum + 4U))) != 0U);
}

/**
  * \brief  Powers up the analog-to-digital converter core.
  * \param  base    ADC base address
  *                  - ADCA: ADC A base address
  *                  - ADCB: ADC B base address
  *                  - ADCC: ADC C base address
  */
static inline void ADC_enableConverter (ADC_TypeDef *base)
{
    SET_BIT(base->CTL1.WORDVAL, ADC_CTL1_ADCPWDNZ_MASK);
}

/**
  * \brief  Powers down the analog-to-digital converter module.
  * \note   Allow at least a 500us delay before sampling after calling this API.
  *         If you enable multiple ADCs, you can delay after they all have begun powering up.
  * \param  base    ADC base address
  *                  - ADCA: ADC A base address
  *                  - ADCB: ADC B base address
  *                  - ADCC: ADC C base address
  */
static inline void ADC_disableConverter (ADC_TypeDef *base)
{
    CLEAR_BIT(base->CTL1.WORDVAL, ADC_CTL1_ADCPWDNZ_MASK);
}

/**
  * \brief  Forces a SOC flag to a 1 in the analog-to-digital converter.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  socNumber    ADC SOC number
  *                       This parameter can be any value of @ref ADC_SOCNUMBER.
  */
static inline void ADC_forceSOC (ADC_TypeDef *base, ADC_SOCNumber socNumber)
{
    SET_BIT(base->SOCFRC1.WORDVAL, (0x1UL << socNumber));
}

/**
  * \brief  Forces multiple SOC flags to 1 in the analog-to-digital converter.
  * \param  base       ADC base address
  *                     - ADCA: ADC A base address
  *                     - ADCB: ADC B base address
  *                     - ADCC: ADC C base address
  * \param  socMask    ADC mask
  *                     This parameter can be any value of @ref ADC_SOCMASK.
  */
static inline void ADC_forceMultipleSOC (ADC_TypeDef *base, uint32_t socMask)
{
    WRITE_REG(base->SOCFRC1.WORDVAL, socMask);
}

/**
  * \brief  Gets the current ADC interrupt status.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  adcIntNum    ADC interrupt number
  *                       This parameter can be any value of @ref ADC_INTNUMBER.
  * \return Returns the value in the data register for the Interrupt Status.
  *                       - 0: false  the interrupt flag for the specified interrupt number is not set
  *                       - 1: true   the interrupt flag for the specified interrupt number is set
  */
static inline uint32_t ADC_getInterruptStatus (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    return READ_BIT(base->INTFLG.WORDVAL, (0x1UL << adcIntNum))? 1UL : 0UL;
}

/**
  * \brief  Clears the ADC interrupt status.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  adcIntNum    ADC interrupt number
  *                       This parameter can be any value of @ref ADC_INTNUMBER.
  */
static inline void ADC_clearInterruptStatus (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    SET_BIT(base->INTFLGCLR.WORDVAL, (0x1UL << adcIntNum));
}

/**
  * \brief  Gets the ADC interrupt overflow status.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  adcIntNum    ADC interrupt number
  *                       This parameter can be any value of @ref ADC_INTNUMBER.
  * \return Returns the interrupt overflow status for the given interrupt number
  *                     - 0: false is the interrupt overflow flag for the specified interrupt number is not set
  *                     - 1: true is the interrupt overflow flag for the specified interrupt number is set
  * \note   This function is only valid when the ADC is in burst mode.
  */
static inline uint32_t ADC_getInterruptOverflowStatus (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    return READ_BIT(base->INTOVF.WORDVAL, (0x1UL << adcIntNum))? 1UL : 0UL;
}

/**
  * \brief  Clears the ADC interrupt overflow status.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  adcIntNum    ADC interrupt number
  *                       This parameter can be any value of @ref ADC_INTNUMBER.
  */
static inline void ADC_clearInterruptOverflowStatus (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    SET_BIT(base->INTOVFCLR.WORDVAL, (0x1UL << adcIntNum));
}

/**
  * \brief  Reads the ADC result.
  * \param  resultBase    ADC result base address
  *                        - ADCA: ADC A result base address
  *                        - ADCB: ADC B result base address
  *                        - ADCC: ADC C result base address
  * \param  socNumber     ADC SOC number
  *                        This parameter can be any value of @ref ADC_SOCNUMBER.
  * \return Returns the conversion result.
  */
static inline uint32_t ADC_readResult (ADCRESULT_TypeDef *resultBase, ADC_SOCNumber socNumber)
{
    return READ_BIT(TYPE32(&(resultBase->RESULT0.WORDVAL) + socNumber), ADC_ADCRESULTN_MASK);
}

/**
  * \brief  Checks whether the ADC is busy.
  * \param  base    ADC base address
  *                  - ADCA: ADC A base address
  *                  - ADCB: ADC B base address
  *                  - ADCC: ADC C base address
  * \return Returns if the ADC is sampling or all samples are complete
  *                - 0: false all samples are complete
  *                - 1: true is sampling
  */
static inline uint32_t ADC_isBusy (ADC_TypeDef *base)
{
    return READ_BIT(base->CTL1.WORDVAL, ADC_CTL1_ADCBSYFLAG_MASK)? 1UL : 0UL;
}

/**
  * \brief  Sets the burst mode configuration.
  * \param  base            ADC base address
  *                          - ADCA: ADC A base address
  *                          - ADCB: ADC B base address
  *                          - ADCC: ADC C base address
  * \param  burstTrigger    ADC burst trigger
  *                          This parameter can be any value of @ref ADC_BURSTTRIGGER.
  * \param  burstSize       ADC burst size
  *                          This parameter can be one value that range from 1 to 20.
  */
static inline void ADC_setBurstModeConfig (ADC_TypeDef *base, ADC_BurstTrigger burstTrigger, uint32_t burstSize)
{
    MODIFY_REG(base->BURSTCTL.WORDVAL, ADC_BURSTCTL_BURSTTRIGSEL_MASK, (burstTrigger & ADC_BURSTCTL_BURSTTRIGSEL_MASK));
    MODIFY_REG(base->BURSTCTL.WORDVAL, ADC_BURSTCTL_BURSTSIZE_MASK,
               (((burstSize - 1) << ADC_BURSTCTL_BURSTSIZE_OFFSET) & ADC_BURSTCTL_BURSTSIZE_MASK));
}

/**
  * \brief  Enables the burst mode.
  * \param  base    ADC base address
  *                  - ADCA: ADC A base address
  *                  - ADCB: ADC B base address
  *                  - ADCC: ADC C base address
  */
static inline void ADC_enableBurstMode (ADC_TypeDef *base)
{
    SET_BIT(base->BURSTCTL.WORDVAL, ADC_BURSTCTL_BURSTEN_MASK);
}

/**
  * \brief  Disables the burst mode.
  * \param  base    ADC base address
  *                  - ADCA: ADC A base address
  *                  - ADCB: ADC B base address
  *                  - ADCC: ADC C base address
  */
static inline void ADC_disableBurstMode (ADC_TypeDef *base)
{
    CLEAR_BIT(base->BURSTCTL.WORDVAL, ADC_BURSTCTL_BURSTEN_MASK);
}

/**
  * \brief  Sets the ADC SOC priority mode.
  * \param  base       ADC base address
  *                     - ADCA: ADC A base address
  *                     - ADCB: ADC B base address
  *                     - ADCC: ADC C base address
  * \param  priMode    ADC SOC priority mode
  *                     This parameter can be any value of @ref ADC_PRIORITYMODE.
  */
static inline void ADC_setSOCPriority (ADC_TypeDef *base, ADC_PriorityMode priMode)
{
    MODIFY_REG(base->SOCPRICTL.WORDVAL, ADC_SOCPRICTL_SOCPRIORITY_MASK, priMode);
}

/**
  * \brief  Gets the ADC SOC priority mode.
  * \param  base       ADC base address
  *                     - ADCA: ADC A base address
  *                     - ADCB: ADC B base address
  *                     - ADCC: ADC C base address
  * \return ADC SOC priority mode
  *                     This parameter can be one value of @ref ADC_PRIORITYMODE.
  */
static inline ADC_PriorityMode ADC_getSOCPriority (ADC_TypeDef *base)
{
    return (ADC_PriorityMode)(READ_BIT(base->SOCPRICTL.WORDVAL, ADC_SOCPRICTL_SOCPRIORITY_MASK) >> ADC_SOCPRICTL_SOCPRIORITY_OFFSET);
}

/**
  * \brief  Gets the ADC SOC priority mode.
  * \param  base       ADC base address
  *                     - ADCA: ADC A base address
  *                     - ADCB: ADC B base address
  *                     - ADCC: ADC C base address
  * \return ADC SOC round robin pointer value
  *                     This parameter can be one value that range from 0 to 20.
  *                     - 0: SOC0 conversion completed and SOC1 round robin conversion is highest
  *                     - 1: SOC1 conversion completed and SOC2 round robin conversion is highest
  *                     - 2: SOC2 conversion completed and SOC3 round robin conversion is highest
  *                     ...
  *                     - 19: SOC19 conversion completed and SOC0 round robin conversion is highest
  *                     - 20: reset value
  */
static inline uint32_t ADC_getSOCPointer (ADC_TypeDef *base)
{
    return (READ_BIT(base->SOCPRICTL.WORDVAL, ADC_SOCPRICTL_RRPOINTER_MASK) >> ADC_SOCPRICTL_RRPOINTER_OFFSET);
}

/**
  * \brief  Configures a post-processing block (PPB) in the ADC.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER.
  * \param  socNumber    ADC SOC number
  *                       This parameter can be any value of @ref ADC_SOCNUMBER.
  */
static inline void ADC_setupPPB (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, ADC_SOCNumber socNumber)
{
    MODIFY_REG(TYPE32(&(base->PPB1CONFIG) + (ppbNumber * 6UL)), ADC_PPBNCONFIG_CONFIG_MASK, \
               (socNumber & ADC_PPBNCONFIG_CONFIG_MASK));
}

/**
  * \brief  Enables individual the ADC PPB event sources.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER.
  * \param  evtFlags     ADC PPB event flags
  *                       - bit0: the PPBn upper limit event flag.
  *                       - bit1: the PPBn lower limit event flag.
  *                       - bit2: the PPBn zero event flag.
  */
static inline void ADC_enablePPBEvent (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint32_t evtFlags)
{
    MODIFY_REG(base->EVTSEL.WORDVAL, (ADC_EVTSEL_MASK << (ppbNumber << 2UL)), ((evtFlags & ADC_EVTSEL_MASK) << (ppbNumber << 2UL)));
}

/**
  * \brief  Disables individual the ADC PPB event sources.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER.
  * \param  evtFlags     ADC PPB event flags
  *                       - bit0: the PPBn upper limit event flag.
  *                       - bit1: the PPBn lower limit event flag.
  *                       - bit2: the PPBn zero event flag.
  */
static inline void ADC_disablePPBEvent (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint32_t evtFlags)
{
    CLEAR_BIT(base->EVTSEL.WORDVAL, ((evtFlags & ADC_EVTSEL_MASK) << (ppbNumber << 2UL)));
}

/**
  * \brief  Enables individual the ADC PPB event interrupt sources.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER
  * \param  intFlags     ADC PPB interrupt flags
  *                       - bit0: the PPBn upper limit interrupt flag.
  *                       - bit1: the PPBn lower limit interrupt flag.
  *                       - bit2: the PPBn zero interrupt flag.
  */
static inline void ADC_enablePPBEventInterrupt (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint32_t intFlags)
{
    MODIFY_REG(base->EVTINTSEL.WORDVAL, (ADC_EVTINTSEL_MASK << (ppbNumber << 2UL)), ((intFlags & ADC_EVTINTSEL_MASK) << (ppbNumber << 2UL)));
}

/**
  * \brief  Disables individual the ADC PPB event interrupt sources.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER.
  * \param  intFlags     ADC PPB interrupt flags
  *                       - bit0: the PPBn upper limit interrupt flag.
  *                       - bit1: the PPBn lower limit interrupt flag.
  *                       - bit2: the PPBn zero interrupt flag..
  */
static inline void ADC_disablePPBEventInterrupt (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint32_t intFlags)
{
    CLEAR_BIT(base->EVTINTSEL.WORDVAL, ((intFlags & ADC_EVTINTSEL_MASK) << (ppbNumber << 2UL)));
}

/**
  * \brief  Gets the ADC PPB event status.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER.
  * \return Returns the current event status.
  *                       - ADC_EVT_TRIPHI
  *                       - ADC_EVT_TRIPLO
  *                       - ADC_EVT_ZERO
  */
static inline uint32_t ADC_getPPBEventStatus (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    return ((READ_REG(base->EVTSTAT.WORDVAL) >> (ppbNumber * 4UL)) & ADC_EVTSEL_MASK);
}

/**
  * \brief  Clears the ADC PPB event flags.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER.
  * \param  evtFlags     ADC PPB event flags
  *                       - bit0: the PPBn upper limit event flag.
  *                       - bit1: the PPBn lower limit event flag.
  *                       - bit2: the PPBn zero event flag.
  */
static inline void ADC_clearPPBEventStatus (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint32_t evtFlags)
{
    WRITE_REG(base->EVTCLR.WORDVAL, (evtFlags & ADC_EVTSTAT_MASK) << (ppbNumber << 2UL));
}

/**
  * \brief  Enables cycle-by-cycle clear of ADC PPB event flags.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER
  */
static inline void ADC_enablePPBEventCBCClear (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    SET_BIT(TYPE32(&(base->PPB1CONFIG.WORDVAL) + (ppbNumber * 6UL)), ADC_PPBNCONFIG_CBCEN);
}

/**
  * \brief  Disables cycle-by-cycle clear of ADC PPB event flags.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER
  */
static inline void ADC_disablePPBEventCBCClear (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    CLEAR_BIT(TYPE32(&(base->PPB1CONFIG.WORDVAL) + (ppbNumber * 6UL)), ADC_PPBNCONFIG_CBCEN);
}

/**
  * \brief  Disables cycle-by-cycle clear of ADC PPB event flags.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER
  * \param  limit        ADC desired PPB count limit
  */
static inline void ADC_setPPBCountLimit (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint16_t limit)
{
    MODIFY_REG(TYPE32(&(base->PPB1LIMIT) + (ppbNumber * 9UL)), ADC_PPB1LIMIT_LIMIT_M, (limit << ADC_PPB1LIMIT_LIMIT_S));
}

/**
  * \brief  Returns the PPB count limit.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER
  */
static inline uint16_t ADC_getPPBCountLimit (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(base->PPB1LIMIT.WORDVAL) + (ppbNumber * 9UL)));
    return (temp >> ADC_PPB1LIMIT_LIMIT_S);
}

/**
  * \brief  Reads the oversampled partial count from the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline uint16_t ADC_readPPBPCount (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(base->PPB1PCOUNT.WORDVAL) + ((uint32_t)ppbNumber * 9UL)));
    return (temp);
}

/**
  * \brief  Reads the oversampled partial sum from the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline int32_t ADC_readPPBPSum (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(base->PPB1PSUM.WORDVAL) + ((uint32_t)ppbNumber * 9UL)));
    return (temp);
}

/**
  * \brief  Reads the processed conversion result's partial maximum value from the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline int32_t ADC_readPPBPMax (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(base->PPB1PMAX.WORDVAL) + ((uint32_t)ppbNumber * 9UL)));
    return (temp);
}

/**
  * \brief  Reads the processed conversion result's partial minimum value from the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline int32_t ADC_readPPBPMin (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(base->PPB1PMIN.WORDVAL) + ((uint32_t)ppbNumber * 9UL)));
    return (temp);
}

/**
  * \brief  Reads the index of the result with partial maximum value from the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline uint16_t ADC_readPPBPMaxIndex (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(base->PPB1PMAXI.WORDVAL) + ((uint32_t)ppbNumber * 9UL)));
    return (temp);
}

/**
  * \brief  Reads the index of the result with partial minimum value from the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline uint16_t ADC_readPPBPMinIndex (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(base->PPB1PMINI.WORDVAL) + ((uint32_t)ppbNumber * 9UL)));
    return (temp);
}

/**
  * \brief  Enables absolute value capability in the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline void ADC_enablePPBAbsoluteValue (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    SET_BIT(TYPE32(&(base->PPB1CONFIG.WORDVAL) + (ppbNumber * 6UL)), ADC_PPB1CONFIG_PPBXABSEN_M);
}

/**
  * \brief  Disables absolute value capability in the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline void ADC_disablePPBAbsoluteValue (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    CLEAR_BIT(TYPE32(&(base->PPB1CONFIG.WORDVAL) + (ppbNumber * 6UL)), ADC_PPB1CONFIG_PPBXABSEN_M);
}

/**
  * \brief  Configures PPB shift value..
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  * \param  shiftVal     ADC ppbNumber is number of bits to right shift PSUM before
  *                       loading to final PPB SUM.
  */
static inline void ADC_setPPBShiftValue (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint16_t shiftVal)
{
    MODIFY_REG(TYPE32(&(base->PPB1CONFIG2.WORDVAL) + (ppbNumber * 9UL)), ADC_PPB1CONFIG2_SHIFT_M,
               (shiftVal << ADC_PPB1CONFIG2_SHIFT_S));
}

/**
  * \brief  Configures PPB shift value.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  * \param  syncInput     ADC desired sync event to transfer partial registers
  *                       to final registers and reset the partial registers.
  */
static inline void ADC_selectPPBSyncInput (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint16_t syncInput)
{
    MODIFY_REG(TYPE32(&(base->PPB1CONFIG2.WORDVAL) + (ppbNumber * 9UL)), ADC_PPB1CONFIG2_SYNCINSEL_M,
               (syncInput << ADC_PPB1CONFIG2_SYNCINSEL_S));
}

/**
  * \brief  Forces PPB software sync.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline void ADC_forcePPBSync (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    SET_BIT(TYPE32(&(base->PPB1CONFIG2.WORDVAL) + (ppbNumber * 9UL)), (ADC_PPB1CONFIG2_SWSYNC_M));
}

/**
  * \brief  Configures PPB interrupt source.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  * \param  syncInput     ADC selects PPB interrupt source.
  */
static inline void ADC_selectPPBOSINTSource (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint16_t osIntSrc)
{
    MODIFY_REG(TYPE32(&(base->PPB1CONFIG2.WORDVAL) + (ppbNumber * 9UL)), ADC_PPB1CONFIG2_OSINTSEL_M,
               (osIntSrc << ADC_PPB1CONFIG2_OSINTSEL_S));
}

/**
  * \brief  Configures PPB compare source.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  * \param  compSrc     ADC desired source to be used for zero crossing detect
  *                       logic and threshold compare.
  */
static inline void ADC_selectPPBCompareSource (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint16_t compSrc)
{
    MODIFY_REG(TYPE32(&(base->PPB1CONFIG2.WORDVAL) + (ppbNumber * 9UL)), ADC_PPB1CONFIG2_COMPSEL_M,
               (compSrc << ADC_PPB1CONFIG2_COMPSEL_S));
}

/**
  * \brief  Reads the oversampled final sum from the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline int32_t ADC_readPPBSum (ADCRESULT_TypeDef *resultBase, ADC_PPBNumber ppbNumber)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(resultBase->PPB1SUM.WORDVAL) + ((uint32_t)ppbNumber * 4UL)));
    return (temp);
}

/**
  * \brief  Reads the oversampled final count from the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline uint32_t ADC_readPPBCount (ADCRESULT_TypeDef *resultBase, ADC_PPBNumber ppbNumber)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(resultBase->PPB1COUNT.WORDVAL) + ((uint32_t)ppbNumber * 4UL)));
    return (temp);
}

/**
  * \brief  Reads the processed conversion result's maximum value from the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline int32_t ADC_readPPBMax (ADCRESULT_TypeDef *resultBase, ADC_PPBNumber ppbNumber)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(resultBase->PPB1MAX.WORDVAL) + ((uint32_t)ppbNumber * 4UL)));
    return (temp);
}

/**
  * \brief  Reads the processed conversion result's minimum value from the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline int32_t ADC_readPPBMin (ADCRESULT_TypeDef *resultBase, ADC_PPBNumber ppbNumber)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(resultBase->PPB1MIN.WORDVAL) + ((uint32_t)ppbNumber * 4UL)));
    return (temp);
}

/**
  * \brief  Reads the index of the result with maximum value from the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline uint16_t ADC_readPPBMaxIndex (ADCRESULT_TypeDef *resultBase, ADC_PPBNumber ppbNumber)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(resultBase->PPB1MAXI.WORDVAL) + ((uint32_t)ppbNumber * 4UL)));
    return (temp);
}

/**
  * \brief  Reads the index of the result with minimum value from the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline uint16_t ADC_readPPBMinIndex (ADCRESULT_TypeDef *resultBase, ADC_PPBNumber ppbNumber)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(resultBase->PPB1MINI.WORDVAL) + ((uint32_t)ppbNumber * 4UL)));
    return (temp);
}

/**
  * \brief  Reads the processed conversion result from the PPB.
  * \param  resultBase    ADC result base address
  *                        - ADCA: ADC A result base address
  *                        - ADCB: ADC B result base address
  *                        - ADCC: ADC C result base address
  * \param  ppbNumber     ADC ppbNumber is the number of the post-processing block.
  *                        This parameter can be any value of @ref ADC_PPBNUMBER.
  * \return Returns the signed 32-bit conversion result.
  */
static inline int32_t ADC_readPPBResult (ADCRESULT_TypeDef *resultBase, ADC_PPBNumber ppbNumber)
{
    uint32_t result = READ_BIT(TYPE32(&(resultBase->PPB1RESULT.WORDVAL) + ppbNumber), 0x1FFFUL);

    return (int32_t)result;
}

/**
  * \brief  Reads the delay time stamp of the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER.
  * \return Returns the delay time stamp.
  */
static inline uint32_t ADC_getPPBDelayTimeStamp (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    return READ_REG(TYPE32(&(base->PPB1STAMP.WORDVAL) + (ppbNumber * 6UL)));
}

/**
  * \brief  Sets the post processing block offset correction.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER.
  * \param  offset       The offset of the PPB.
  *                       This parameter can be any value of @ref ADC_Result.
  */
static inline void ADC_setPPBCalibrationOffset (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint32_t offset)
{
    MODIFY_REG(TYPE32(&(base->PPB1OFFCAL.WORDVAL) + (ppbNumber * 6UL)), ADC_PPBNOFFCAL_OFFCAL_MASK, (offset & ADC_PPBNOFFCAL_OFFCAL_MASK));
}

/**
  * \brief  Sets the post processing block reference offset.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER.
  * \param  offset       The reference offset of the PPB
  *                       This parameter can be one value that range from 0x0 to 0xFFF.
  */
static inline void ADC_setPPBReferenceOffset (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint32_t offset)
{
    MODIFY_REG(TYPE32(&(base->PPB1OFFREF.WORDVAL) + (ppbNumber * 6UL)), ADC_PPBNOFFREF_OFFSET_MASK, (offset & ADC_PPBNOFFREF_OFFSET_MASK));
}

/**
  * \brief  Enables the two's complement capability of the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER.
  */
static inline void ADC_enablePPBTwosComplement (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    SET_BIT(TYPE32(&(base->PPB1CONFIG.WORDVAL) + (ppbNumber * 6UL)), ADC_PPBNCONFIG_TWOSCOMPEN);
}

/**
  * \brief  Disables the two's complement capability of the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER.
  */
static inline void ADC_disablePPBTwosComplement (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    CLEAR_BIT(TYPE32(&(base->PPB1CONFIG.WORDVAL) + (ppbNumber * 6UL)), ADC_PPBNCONFIG_TWOSCOMPEN);
}

/**
  * \brief  Enables the extended low limit in the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER.
  */
static inline void ADC_enablePPBExtendedLowLimit (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    SET_BIT(TYPE32(&(base->PPB1TRIPLO.WORDVAL) + (ppbNumber * 6UL)), 0x80000U);
}

/**
  * \brief  Disables extended low limit capability in the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNUMBER.
  */
static inline void ADC_disablePPBExtendedLowLimit (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    CLEAR_BIT(TYPE32(&(base->PPB1TRIPLO.WORDVAL) + (ppbNumber * 6UL)), 0x80000U);
}

/**
  * \brief  Enables the interrupt of the ADC.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  adcIntNum    ADC interrupt number
  *                       This parameter can be any value of @ref ADC_IntNumber.
  */
static inline void ADC_enableInterrupt (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    uint32_t temp;
    __IO uint32_t *addr;

    temp = (adcIntNum > ADC_INT_NUMBER2)? 1 : 0;
    addr = (uint32_t *)(&(base->INTSEL1N2) + temp);
    temp = (adcIntNum - (temp << 1UL)) << 3UL;
    SET_BIT(*addr, (ADC_ADCINTSELXNY_INTXE_MASK << temp));
    SET_BIT(base->INTEN.WORDVAL, (ADC_ADCINTEN_MASK << adcIntNum));
}

/**
  * \brief  Disables the interrupt of the ADC.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  adcIntNum    ADC interrupt number
  *                       This parameter can be any value of @ref ADC_IntNumber.
  */
static inline void ADC_disableInterrupt (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    uint32_t temp;
    __IO uint32_t *addr;

    temp = (adcIntNum > ADC_INT_NUMBER2)? 1 : 0;
    addr = (uint32_t *)(&(base->INTSEL1N2) + temp);
    temp = (adcIntNum - (temp << 1UL)) << 3UL;
    CLEAR_BIT(*addr, (ADC_ADCINTSELXNY_INTXE_MASK << temp));
    CLEAR_BIT(base->INTEN.WORDVAL, (ADC_ADCINTEN_MASK << adcIntNum));
}

/**
  * \brief  Sets the source EOC for an analog-to-digital converter interrupt.
  * \param  base          ADC base address
  *                        - ADCA: ADC A base address
  *                        - ADCB: ADC B base address
  *                        - ADCC: ADC C base address
  * \param  adcIntNum     ADC interrupt number
  *                        This parameter can be any value of @ref ADC_INTNUMBER.
  * \param  intTrigger    ADC interrupt trigger
  *                        This parameter can be any value of @ref ADC_SOCNUMBER.
  */
static inline void ADC_setInterruptSource (ADC_TypeDef *base, ADC_IntNumber adcIntNum, ADC_SOCNumber intTrigger)
{
    uint32_t temp;
    __IO uint32_t *addr;

    temp = (adcIntNum > ADC_INT_NUMBER2) ? 1 : 0;
    addr = (uint32_t *)(&(base->INTSEL1N2) + temp);
    temp = (adcIntNum - (temp << 1UL)) << 3UL;
    MODIFY_REG(*addr, (ADC_ADCINTSELXNY_INTXSEL_MASK << temp), ((intTrigger & ADC_ADCINTSELXNY_INTXSEL_MASK) << temp));
}

/**
  * \brief  Enables the continuous mode of the ADC.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  adcIntNum    ADC interrupt number
  *                       This parameter can be any value of @ref ADC_INTNUMBER.
  */
static inline void ADC_enableContinuousMode (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    uint32_t temp;
    __IO uint32_t *addr;

    temp = (adcIntNum > ADC_INT_NUMBER2)? 1 : 0;
    addr = (uint32_t *)(&(base->INTSEL1N2) + temp);
    temp = (adcIntNum - (temp << 1UL)) << 3UL;
    SET_BIT(*addr, (ADC_ADCINTSELXNY_INTXCONT_MASK << temp));
}

/**
  * \brief  Disables the continuous mode of the ADC interrupt.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  adcIntNum    ADC interrupt number
  *                       This parameter can be any value of @ref ADC_INTNUMBER.
  */
static inline void ADC_disableContinuousMode (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    uint32_t temp;
    __IO uint32_t *addr;

    temp = (adcIntNum > ADC_INT_NUMBER2)? 1 : 0;
    addr = (uint32_t *)(&(base->INTSEL1N2) + temp);
    temp = (adcIntNum - (temp << 1UL)) << 3UL;
    CLEAR_BIT(*addr, (ADC_ADCINTSELXNY_INTXCONT_MASK << temp));
}

/**
  * \brief  Select the ADC input source gain.
  * \param  base    ADC base address
  *                  - ADCA: ADC A base address
  *                  - ADCB: ADC B base address
  *                  - ADCC: ADC C base address
  * \param  gain    ADC input source gain
  *                  This parameter can be any value of @ref ADC_SGAINSEL.
  */
static inline void ADC_selectSgain (ADC_TypeDef *base, ADC_SgainSel gain)
{
    MODIFY_REG(base->ANACTL.WORDVAL, ADC_ADCANACTL_SGAINSEL_MASK, ((uint32_t)gain << ADC_ADCANACTL_SGAINSEL_OFFSET));
}

/**
  * \brief  Set the ADC analog input as single method.
  * \param  base    ADC base address
  *                  - ADCA: ADC A base address
  *                  - ADCB: ADC B base address
  *                  - ADCC: ADC C base address
  */
static inline void ADC_setSingleInput (ADC_TypeDef *base)
{
    CLEAR_BIT(base->ANACTL.WORDVAL, ADC_ADCANACTL_SDIF_MASK);
}

/**
  * \brief  Set the ADC analog work as normal method.
  * \param  base    ADC base address
  *                  - ADCA: ADC A base address
  *                  - ADCB: ADC B base address
  *                  - ADCC: ADC C base address
  */
static inline void ADC_setNormalMethod (ADC_TypeDef *base)
{
    CLEAR_BIT(base->ANATRIM.WORDVAL, ADC_ADCANATRIM_DISH_MASK);
}

/**
  * \brief  Set the ADC analog work as trim method.
  * \param  base    ADC base address
  *                  - ADCA: ADC A base address
  *                  - ADCB: ADC B base address
  *                  - ADCC: ADC C base address
  */
static inline void ADC_setTrimMethod (ADC_TypeDef *base)
{
    SET_BIT(base->ANATRIM.WORDVAL, ADC_ADCANATRIM_DISH_MASK);
}

/**
  * \brief  Converts temperature from sensor reading to degrees C
  * \param  tempResult   ADC temperature sensor reading result
  *                       This parameter can be set one value that ranges from 0 to 0xFFF.
  * \param  adcVrefVolt  ADC vref voltage
  *                       This parameter can be set one value that ranges from 0.0 to 3.3 .
  * \return Returns the temperature sensor reading converted to degrees C.
  *                       This parameter can be one value that ranges from -50 to 150.
  */
static inline float ADC_getTemperatureC (uint32_t tempResult, float adcVrefVolt)
{
    return (25.0 + (float)((tempResult / 4095.0 * adcVrefVolt - ADC_TSENSOR_25C_TRIM) * 1000 / ADC_TSENSOR_CONVERSION_COEFFICIENT));
}

/**
  * \brief  Converts temperature from sensor reading to degrees K
  * \param  tempResult     ADC temperature sensor reading result
  *                         This parameter can be set one value that ranges from 0 to 0xFFF.
  * \param  adcVrefVolt    ADC vref voltage
  *                         This parameter can be set one value that ranges from 0.0 to 3.3 .
  * \return Returns the temperature sensor reading converted to degrees k.
  *                        This parameter can be one value that ranges from 223 to 423.
  */
static inline float ADC_getTemperatureK (uint32_t tempResult, float adcVrefVolt)
{
    return (298.0 + (float)((tempResult / 4095.0 * adcVrefVolt - ADC_TSENSOR_25C_TRIM) * 1000 / ADC_TSENSOR_CONVERSION_COEFFICIENT));
}

/**
  * \brief  Configures the safety checker result for a selected SOC.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  socNumber    ADC number of the start-of-conversion
  *                       This parameter can be any value of @ref ADC_SOCNumber.
  * \param  scInput      ADC desired input configuration
  *                       This parameter can be any value of @ref ADC_SafetyCheckerInput.
  * \return None.
  */
static inline void ADC_configSOCSafetyCheckerInput (ADC_TypeDef *base, ADC_SOCNumber socNumber,
                                                    ADC_SafetyCheckerInput scInput)
{
    uint32_t temp;
    temp = ((uint32_t)socNumber * 2U);
    MODIFY_REG(TYPE32(&(base->SAFECHECKRESEN1)), ADC_SAFECHECKRESEN1_SOC0CHKEN_M << temp, ((uint32_t)scInput << temp));
}

/**
  * \brief  Enables the ADC result safety checker module.
  * \param  scBase         ADC base address of the ADC Safety Checker module
  *
  * \return None.
  */
static inline void ADC_enableSafetyChecker (ADCSAFETYCHKCHK_TypeDef *scBase)
{
    SET_BIT(TYPE32(&(scBase->CHECKCONFIG.WORDVAL)), ADCSAFETYCHKCHK_CHECKCONFIG_CHKEN_M);
}

/**
  * \brief  Disables the ADC result safety checker module.
  * \param  scBase         ADC base address of the ADC Safety Checker module
  *
  * \return None.
  */
static inline void ADC_disableSafetyChecker (ADCSAFETYCHKCHK_TypeDef *scBase)
{
    CLEAR_BIT(TYPE32(&(scBase->CHECKCONFIG.WORDVAL)), ADCSAFETYCHKCHK_CHECKCONFIG_CHKEN_M);
}

/**
  * \brief  Forces the software sync for the safety checker module
  * \param  scBase         ADC base address of the ADC Safety Checker module
  *
  * \return None.
  */
static inline void ADC_forceSafetyCheckerSync (ADCSAFETYCHKCHK_TypeDef *scBase)
{
    SET_BIT(TYPE32(&(scBase->CHECKCONFIG.WORDVAL)), ADCSAFETYCHKCHK_CHECKCONFIG_SWSYNC_M);
}

/**
  * \brief  Returns the status of the safey checker module.
  * \param  scBase         ADC base address of the ADC Safety Checker module
  *
  * \return None.
  */
static inline uint16_t ADC_getSafetyCheckerStatus (ADCSAFETYCHKCHK_TypeDef *scBase)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(scBase->TOLERANCE.WORDVAL)));
    return (temp & ADCSAFETYCHKCHK_TOLERANCE_TOLERANCE_M);
}

/**
  * \brief  Configures the safety checker module.
  * \param  scBase         ADC base address of the ADC Safety Checker module
  *
  * \param  checkInst      ADC safety checker instance to be configured.
  *                         This parameter can be any value of @ref ADC_SafetyCheckInst.
  * \param  adcInst        ADC desired ADC instance.
  *                         This parameter can be any value of @ref ADC_Select.
  * \param  adcResultInst  ADC desired ADC result instance
  *                         This parameter can be any value of @ref ADC_ResultSelect.
  * \return None.
  */
static inline void ADC_configureSafetyChecker (ADCSAFETYCHKCHK_TypeDef *scBase, ADC_SafetyCheckInst checkInst,
                                               ADC_Select adcInst, ADC_ResultSelect adcResultInst)
{
    MODIFY_REG(TYPE32(&(scBase->ADCRESSEL1.WORDVAL) + (uint16_t)checkInst),
               (ADCSAFETYCHKCHK_ADCRESSEL1_ADCSEL_M | ADCSAFETYCHKCHK_ADCRESSEL1_ADCRESULTSEL_M),
               (((uint16_t)adcInst << ADCSAFETYCHKCHK_ADCRESSEL1_ADCSEL_S) |
                ((uint16_t)adcResultInst << ADCSAFETYCHKCHK_ADCRESSEL1_ADCRESULTSEL_S)));
}

/**
  * \brief  Configures the tolerance allowed between safety check results
  * \param  scBase         ADC base address of the ADC Safety Checker module
  *
  * \param  tolerance      ADC number of the start-of-conversion.
  *
  * \return None.
  */
static inline void ADC_setSafetyCheckerTolerance (ADCSAFETYCHKCHK_TypeDef *scBase, uint32_t tolerance)
{
    MODIFY_REG(TYPE32(&(scBase->TOLERANCE)), ADCSAFETYCHKCHK_TOLERANCE_TOLERANCE_M,
               (tolerance & ADCSAFETYCHKCHK_TOLERANCE_TOLERANCE_M));
}

/**
  * \brief  Returns the safety check result for the selected instance.
  * \param  scBase         ADC base address of the ADC Safety Checker module
  *
  * \param  checkInst      ADC number of the start-of-conversion.
  *                         This parameter can be any value of @ref ADC_SafetyCheckInst.
  * \return None.
  */
static inline uint32_t ADC_getSafetyCheckerResult (ADCSAFETYCHKCHK_TypeDef *scBase, ADC_SafetyCheckInst checkInst)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(scBase->CHECKRESULT1.WORDVAL)) + (uint16_t)checkInst);
    return (temp & ADCSAFETYCHKCHK_CHECKRESULT1_RESULT_M);
}

/**
  * \brief  Returns the safety check result for the selected instance.
  * \param  scBase         ADC base address of the ADC Safety Checker module
  *
  * \param  checkerNumber   ADC number of the start-of-conversion.
  *                         This parameter can be any value of @ref ADC_Checker.
  * \param  checkEvent      ADC desired event number.
  *                         This parameter can be any value of @ref ADC_SafetyCheckEvent.
  * \param  checkResult     ADC desired ADC Safety Checker result.
  *                         This parameter can be any value of @ref ADC_SafetyCheckResult.
  * \return None.
  */
static inline void ADC_enableSafetyCheckEvt (ADCSAFETYCHKAGG_TypeDef *scIntEvtBase, ADC_Checker checkerNumber,
                                             ADC_SafetyCheckEvent checkEvent, ADC_SafetyCheckResult checkResult)
{
    SET_BIT(TYPE32(&(scIntEvtBase->CHECKEVT1SEL1.WORDVAL) + (uint32_t)checkEvent + (uint32_t)checkResult),
            (1UL << (uint32_t)checkerNumber));
}

/**
  * \brief  Disables the safety check result for the selected instance.
  * \param  scBase         ADC base address of the ADC Safety Checker module
  *
  * \param  checkerNumber   ADC number of the start-of-conversion.
  *                         This parameter can be any value of @ref ADC_Checker.
  * \param  checkEvent      ADC desired event number.
  *                         This parameter can be any value of @ref ADC_SafetyCheckEvent.
  * \param  checkResult     ADC desired ADC Safety Checker result.
  *                         This parameter can be any value of @ref ADC_SafetyCheckResult.
  * \return None.
  */
static inline void ADC_disableSafetyCheckEvt (ADCSAFETYCHKAGG_TypeDef *scIntEvtBase, ADC_Checker checkerNumber,
                                              ADC_SafetyCheckEvent checkEvent, ADC_SafetyCheckResult checkResult)
{
    CLEAR_BIT(TYPE32(&(scIntEvtBase->CHECKEVT1SEL1.WORDVAL) + (uint32_t)checkEvent + (uint32_t)checkResult),
              (1UL << (uint32_t)checkerNumber));
}

/**
  * \brief  Enables the safety check result for the selected instance.
  * \param  scBase         ADC base address of the ADC Safety Checker module
  *
  * \param  checkerNumber   ADC number of the start-of-conversion.
  *                         This parameter can be any value of @ref ADC_Checker.
  * \param  checkResult     ADC desired ADC Safety Checker result.
  *                         This parameter can be any value of @ref ADC_SafetyCheckResult.
  * \return None.
  */
static inline void ADC_enableSafetyCheckInt (ADCSAFETYCHKAGG_TypeDef *scIntEvtBase, ADC_Checker checkerNumber,
                                             ADC_SafetyCheckResult checkResult)
{
    SET_BIT(TYPE32(&(scIntEvtBase->CHECKEVT1SEL1.WORDVAL) + checkResult), (1UL << (uint32_t)checkerNumber));
}

/**
  * \brief  Disables the safety check result for the selected instance.
  * \param  scBase         ADC base address of the ADC Safety Checker module
  *
  * \param  checkerNumber   ADC number of the start-of-conversion.
  *                         This parameter can be any value of @ref ADC_Checker.
  * \param  checkResult     ADC desired ADC Safety Checker result.
  *                         This parameter can be any value of @ref ADC_SafetyCheckResult.
  * \return None.
  */
static inline void ADC_disableSafetyCheckInt (ADCSAFETYCHKAGG_TypeDef *scIntEvtBase, ADC_Checker checkerNumber,
                                              ADC_SafetyCheckResult checkResult)
{
    CLEAR_BIT(TYPE32(&(scIntEvtBase->CHECKEVT1SEL1.WORDVAL) + checkResult), (1UL << (uint32_t)checkerNumber));
}

/**
  * \brief  Get the ADC safety checker OOT and OVF event status.
  * \param  scBase         ADC base address of the ADC Safety Checker module
  *
  * \param  checkerNumber   ADC number of the start-of-conversion.
  *                         This parameter can be any value of @ref ADC_Checker.
  * \param  checkerFlag     ADC desired ADC Safety Checker result.
  *                         This parameter can be any value of @ref ADC_SafetyCheckFlag.
  * \return Returns the status of the safety checker event module for
  *         the selected instance.
  */
static inline uint32_t ADC_getSafetyCheckStatus (ADCSAFETYCHKAGG_TypeDef *scIntEvtBase, ADC_Checker checkerNumber,
                                                 ADC_SafetyCheckFlag checkerFlag)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(scIntEvtBase->OOTFLG.WORDVAL) + (uint32_t)checkerFlag));
    return (temp & (1U << (uint32_t)checkerNumber));
}

/**
  * \brief  Clears the ADC safety checker OOT and OVF event status.
  * \param  scIntEvtBase    ADC base address of ADC Safe Check INTEVT module.
  *
  * \param  checkerNumber   ADC number of the start-of-conversion.
  *                         This parameter can be any value of @ref ADC_Checker.
  * \param  checkerFlag     ADC desired ADC Safety Checker result.
  *                         This parameter can be any value of @ref ADC_SafetyCheckFlag.
  * \return None.
  *
  */
static inline void ADC_clearSafetyCheckStatus (ADCSAFETYCHKAGG_TypeDef *scIntEvtBase, ADC_Checker checkerNumber,
                                               ADC_SafetyCheckFlag checkerFlag)
{
    CLEAR_BIT(TYPE32(&(scIntEvtBase->OOTFLGCLR.WORDVAL) + checkerFlag), (1UL << (uint32_t)checkerNumber));
}

/**
  * \brief  Get the ADC safety checker OOT and OVF event status.
  * \param  scIntEvtBase    ADC base address of ADC Safe Check INTEVT module.
  *
  * \return Returns the status of the safety checker interrupt for
  *  the selected instance.
  *
  */
static inline uint32_t ADC_getSafetyCheckIntStatus (ADCSAFETYCHKAGG_TypeDef *scIntEvtBase)
{
    uint32_t temp;
    temp = READ_REG(TYPE32(&(scIntEvtBase->CHECKINTFLG.WORDVAL)));
    return (temp);
}

/**
  * \brief  Clears the ADC safety checker interrupt status
  * \param  scIntEvtBase    ADC base address of ADC Safe Check INTEVT module.
  *
  * \return None
  *
  */
static inline void ADC_clearSafetyCheckIntStatus (ADCSAFETYCHKAGG_TypeDef *scIntEvtBase)
{
    CLEAR_BIT(TYPE32(&(scIntEvtBase->CHECKINTFLGCLR.WORDVAL)), (1UL));
}

/**
  * \brief  Configures the trigger repeater mode select.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  repInstance  ADC repeater instance
  *
  * \param  mode  ADC repeater mode
  *                         This parameter can be any value of @ref ADC_RepMode.
  * \return None
  */
static inline void ADC_triggerRepeaterMode (ADC_TypeDef *base, uint32_t repInstance, ADC_RepMode mode)
{
    MODIFY_REG(TYPE32(&(base->REP1CTL.WORDVAL) + (repInstance * (5UL))), (ADC_REP1CTL_MODE_M), (mode));
}

/**
  * \brief  Get the trigger repeater active mode status.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  repInstance  ADC repeater instance
  *
  * \return None
  */
static inline void ADC_triggerRepeaterActiveMode (ADC_TypeDef *base, uint32_t repInstance)
{
    SET_BIT(TYPE32(&(base->REP1CTL.WORDVAL) + (repInstance * (5UL))), (1UL << ADC_REP1CTL_ACTIVEMODE_S));
}

/**
  * \brief  Clears the ADC safety checker interrupt status
  * \param  scIntEvtBase    ADC base address of ADC Safe Check INTEVT module.
  *
  * \return None
  *
  */
static inline void ADC_triggerRepeaterModuleBusy (ADC_TypeDef *base, uint32_t repInstance)
{
    SET_BIT(TYPE32(&(base->REP1CTL.WORDVAL) + (repInstance * (5UL))), (1UL << ADC_REP1CTL_MODULEBUSY_S));
}

/**
  * \brief  Configures the trigger source of the trigger repeater.
  * \param  scIntEvtBase    ADC base address of ADC Safe Check INTEVT module.
  *
  * \param  repInstance     ADC repeater instance
  *
  * \param  trigger         ADC source to modify via oversampling or undersampling.
  *                          This parameter can be any value of @ref ADC_Trigger.
  * \return None
  *
  */
static inline void ADC_triggerRepeaterSelect (ADC_TypeDef *base, uint16_t repInstance, ADC_Trigger trigger)
{
    SET_BIT(TYPE32(&(base->REP1CTL.WORDVAL) + (repInstance * (5UL))), (trigger << ADC_REP1CTL_TRIGGER_S));
}

/**
  * \brief  Configures the trigger repeater syncin source.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  repInstance  ADC repeater instance
  *
  * \param  syncInput    ADC desired sync event to reset all counters.
  *                         This parameter can be any value of @ref ADC_SyncInput.
  * \return None
  *
  */
static inline void ADC_triggerRepeaterSyncIn (ADC_TypeDef *base, uint16_t repInstance, ADC_SyncInput syncInput)
{
    SET_BIT(TYPE32(&(base->REP1CTL.WORDVAL) + (repInstance * (5UL))), (syncInput << ADC_REP1CTL_SYNCINSEL_S));
}

/**
  * \brief  Forces software sync for the trigger repeater block.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  repInstance  ADC repeater instance
  *
  * \return None
  *
  */
static inline void ADC_forceRepeaterTriggerSync (ADC_TypeDef *base, uint16_t repInstance)
{
    SET_BIT(TYPE32(&(base->REP1CTL.WORDVAL) + (repInstance * (5UL))), (ADC_REP1CTL_SWSYNC_M));
}

/**
  * \brief  Configures the trigger repeater count.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  repInstance  ADC repeater instance
  *
  * \param  repCount     ADC desired trigger count to be selected
  *
  * \return None
  *
  */
static inline void ADC_triggerRepeaterCount (ADC_TypeDef *base, uint16_t repInstance, uint16_t repCount)
{
    MODIFY_REG(TYPE32(&(base->REP1N.WORDVAL) + (repInstance * (5UL))), ADC_REP1N_NSEL_M, (repCount & ADC_REP1N_NSEL_M));
}

/**
  * \brief  Configures the trigger repeater phase.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  repInstance  ADC repeater instance
  *
  * \param  repPhase     ADC repeater trigger phase delay
  *                      in sysclk cycles.
  * \return None
  *
  */
static inline void ADC_triggerRepeaterPhase (ADC_TypeDef *base, uint16_t repInstance, uint16_t repPhase)
{
    MODIFY_REG(TYPE32(&(base->REP1PHASE.WORDVAL) + (repInstance * (5UL))), ADC_REP1PHASE_PHASE_M,
               (repPhase & ADC_REP1PHASE_PHASE_M));
}

/**
  * \brief  Configures the trigger repeater spread.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  repInstance  ADC repeater instance
  *
  * \param  repSpread    ADC desired trigger spread in sysclk cycle
  *
  * \return None
  *
  */
static inline void ADC_triggerRepeaterSpread (ADC_TypeDef *base, uint16_t repInstance, uint16_t repSpread)
{
    MODIFY_REG(TYPE32(&(base->REP1SPREAD.WORDVAL) + (repInstance * (5UL))), ADC_REP1SPREAD_SPREAD_M,
               (repSpread & ADC_REP1SPREAD_SPREAD_M));
}

/**
  * \brief  Configures the trigger repeater.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  repInstance  ADC repeater instance
  *
  * \param  config    ADC desired repeater configuration
  *
  * \return None
  *
  */
extern void ADC_configureRepeater (ADC_TypeDef *base, uint16_t repInstance, ADC_RepeaterConfig *config);

/**
  * \brief  Configures the ADC module's reference mode and offset trim
  * \note   In this device, the bandgaps are common for all the ADC instances,
  *         hence common Vref configuration needs to be done for all the ADCs. This
  *         API configures same Vref configuration for all the supported ADCs in the device.
  * \param  base          ADC base address
  *                        - ADCA: ADC A base address
  *                        - ADCB: ADC B base address
  *                        - ADCC: ADC C base address
  * \param  refMode       ADC reference Mode
  *                        This parameter can be one of the following @ref ADC_ReferenceMode:
  * \param  refVoltage    ADC reference Voltage
  *                        This parameter can be one of the following @ref ADC_ReferenceVoltage:
  */
extern void ADC_setVREF (ADC_TypeDef *base, ADC_ReferenceMode refMode, ADC_ReferenceVoltage refVoltage);

/**
  * \brief  Configures the offset trim for the desired ADC instance
  * \note   This function loads the offset trims for the desired ADC instance.
  * \param  base       ADC base address
  *                     - ADCA: ADCA_BASE
  *                     - ADCB: ADCB_BASE
  *                     - ADCC: ADCC_BASE
  * \param  trimVal    ADC offset trim value
  *                     the value scope: 0~0x1f, but the mask is 0x3f, for example:
  *                       if trimVal=0x1F, the offset trim value is +0x1F;
  *                       if trimVal=0x3F, the offset trim value is -0x1F;
  * 
  * \note  The ADC offset trim value of the NS800RTxxx series chips is automatically
  *        loaded upon chip power-on! There is no need to call this function to 
  *        load it.
  */
extern void ADC_setOffsetTrim (ADC_TypeDef *base, uint8_t trimVal);

/**
  * \brief  Sets the windowed trip limits for a PPB.
  * \note   This function sets the windowed trip limits for a PPB. These values set
  *         the digital comparator trip high and low limits.
  *         The trip limits are used to determine when the PPB is tripped.
  * \param  base           ADC base address
  *                         - ADCA: ADC A base address
  *                         - ADCB: ADC B base address
  *                         - ADCC: ADC C base address
  * \param  ppbNumber      ADC PPB Number
  *                         This parameter can be one of the following @ref ADC_PPBNumbe:
  * \param  sybol          ADC PPB Symbol
  *                         This parameter can be one of the following @ref ADC_PPBSymbol:
  * \param  tripHiLimit    ADC PPB Trip Hi Limit
  * \param  tripLoLimit    ADC PPB Trip Lo Limit
  */
extern void ADC_setPPBTripLimits (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, ADC_PPBSymbol sybol, uint32_t tripHiLimit,
                                  uint32_t tripLoLimit);


#ifdef __cplusplus
}
#endif


#endif /*__ADC_H__ */
