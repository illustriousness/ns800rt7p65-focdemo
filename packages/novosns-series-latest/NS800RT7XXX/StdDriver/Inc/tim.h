/**
  * @file       tim.h
  * @author     Haven-X
  * @brief      Header file for NS800RT7xxx tim module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __TIM_H__
#define __TIM_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_tim.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup TIM_EXPORTED_TYPES TIM Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'TIM' module.
  */

/** @defgroup TIM_IT TIM Interrupt Source
  * @{
  * @brief  Macro definitions about TIM interrupt source.
  */
#define TIM_IT_UPDATE     (TIM_DIER_UIE_M)      /*!< Update interrupt */
#define TIM_IT_CC1        (TIM_DIER_CC1IE_M)    /*!< Capture/Compare 1 interrupt */
#define TIM_IT_CC2        (TIM_DIER_CC2IE_M)    /*!< Capture/Compare 2 interrupt */
#define TIM_IT_CC3        (TIM_DIER_CC3IE_M)    /*!< Capture/Compare 3 interrupt */
#define TIM_IT_CC4        (TIM_DIER_CC4IE_M)    /*!< Capture/Compare 4 interrupt */
#define TIM_IT_COM        (TIM_DIER_COMIE_M)    /*!< COM event interrupt */
#define TIM_IT_TRIGGER    (TIM_DIER_TIE_M)      /*!< Trigger interrupt */
#define TIM_IT_BREAK      (TIM_DIER_BIE_M)      /*!< Break interrupt */
#define TIM_IT_ALL        (0x000000FFUL)        /*!< All interrupt */

/**
  * @}
  */

/** @defgroup TIM_DMA TIM DMA Request Source
  * @{
  * @brief  Macro definitions about TIM dma request source.
  */
#define TIM_DMA_UPDATE     (TIM_DIER_UDE_M)      /*!< Update DMA request */
#define TIM_DMA_CC1        (TIM_DIER_CC1DE_M)    /*!< Capture/Compare 1 DMA request */
#define TIM_DMA_CC2        (TIM_DIER_CC2DE_M)    /*!< Capture/Compare 1 DMA request */
#define TIM_DMA_CC3        (TIM_DIER_CC3DE_M)    /*!< Capture/Compare 1 DMA request */
#define TIM_DMA_CC4        (TIM_DIER_CC4DE_M)    /*!< Capture/Compare 1 DMA request */
#define TIM_DMA_COM        (TIM_DIER_COMDE_M)    /*!< COM DMA request */
#define TIM_DMA_TRIGGER    (TIM_DIER_TDE_M)      /*!< Trigger DMA request */
#define TIM_DMA_ALL        (0x00007F00UL)        /*!< All DMA request */

/**
  * @}
  */

/** @defgroup TIM_ADCTRIG TIM ADC Trigger Source
  * @{
  * @brief  Macro definitions about TIM trigger source.
  */
#define TIM_ADCTRIG_TRGO       (TIM_DIER_TOTAE_M)      /*!< Trgo(CR2.MMS) triger ADC */
#define TIM_ADCTRIG_CC1        (TIM_DIER_CC1TAE_M)     /*!< Capture/Compare 1 interrupt triger ADC */
#define TIM_ADCTRIG_CC2        (TIM_DIER_CC2ITAE_M)    /*!< Capture/Compare 2 interrupt triger ADC */
#define TIM_ADCTRIG_CC3        (TIM_DIER_CC3ITAE_M)    /*!< Capture/Compare 3 interrupt triger ADC */
#define TIM_ADCTRIG_CC4        (TIM_DIER_CC4ITAE_M)    /*!< Capture/Compare 4 interrupt triger ADC */
#define TIM_ADCTRIG_COM        (TIM_DIER_COMITAE_M)    /*!< COM interrupt triger ADC */
#define TIM_ADCTRIG_TRIGGER    (TIM_DIER_TITAE_M)      /*!< Trigger interrupt triger ADC */
#define TIM_ADCTRIG_BREAK      (TIM_DIER_BITAE_M)      /*!< Break interrupt triger ADC */
#define TIM_ADCTRIG_ALL        (0x00FF0000UL)          /*!< All interrupt triger adc */

/**
  * @}
  */

/** @defgroup TIM_FLAG TIM Interrupt Flag
  * @{
  * @brief  Macro definitions about TIM interrupt flag.
  */
#define TIM_FLAG_UPDATE     (TIM_SR_UIF_M)      /*!< Update interrupt flag */
#define TIM_FLAG_CC1        (TIM_SR_CC1IF_M)    /*!< Capture/Compare 1 interrupt flag */
#define TIM_FLAG_CC2        (TIM_SR_CC2IF_M)    /*!< Capture/Compare 2 interrupt flag */
#define TIM_FLAG_CC3        (TIM_SR_CC3IF_M)    /*!< Capture/Compare 3 interrupt flag */
#define TIM_FLAG_CC4        (TIM_SR_CC4IF_M)    /*!< Capture/Compare 4 interrupt flag */
#define TIM_FLAG_COM        (TIM_SR_COMIF_M)    /*!< COM interrupt flag */
#define TIM_FLAG_TRIGGER    (TIM_SR_TIF_M)      /*!< Trigger interrupt flag */
#define TIM_FLAG_BREAK      (TIM_SR_BIF_M)      /*!< Break interrupt flag */
#define TIM_FLAG_CC1OF      (TIM_SR_CC1OF_M)    /*!< Capture 1 over capture interrupt flag */
#define TIM_FLAG_CC2OF      (TIM_SR_CC2OF_M)    /*!< Capture 2 over capture interrupt flag */
#define TIM_FLAG_CC3OF      (TIM_SR_CC3OF_M)    /*!< Capture 3 over capture interrupt flag */
#define TIM_FLAG_CC4OF      (TIM_SR_CC4OF_M)    /*!< Capture 4 over capture interrupt flag */
#define TIM_FLAG_ALL        (0x00001EFFUL)      /*!< All interrupt flag */

/**
  * @}
  */

/** @defgroup TIM_EVENTSOURCE TIM Event Generate
  * @{
  * @brief  Macro definitions about TIM event generate.
  */
#define TIM_EVENTSOURCE_UPDATE     (TIM_EGR_UG_M)      /*!< Generate an update event */
#define TIM_EVENTSOURCE_CC1        (TIM_EGR_CC1G_M)    /*!< Generate an Capture/Compare 1 event */
#define TIM_EVENTSOURCE_CC2        (TIM_EGR_CC2G_M)    /*!< Generate an Capture/Compare 2 event */
#define TIM_EVENTSOURCE_CC3        (TIM_EGR_CC3G_M)    /*!< Generate an Capture/Compare 3 event */
#define TIM_EVENTSOURCE_CC4        (TIM_EGR_CC4G_M)    /*!< Generate an Capture/Compare 4 event */
#define TIM_EVENTSOURCE_COM        (TIM_EGR_COMG_M)    /*!< Generate an COM event */
#define TIM_EVENTSOURCE_TRIGGER    (TIM_EGR_TG_M)      /*!< Generate an Trigger event */
#define TIM_EVENTSOURCE_BREAK      (TIM_EGR_BG_M)      /*!< Generate an Break event */
#define TIM_EVENTSOURCE_ALL        (0x000000FFUL)      /*!< Generate all event */

/**
  * @}
  */

/** @defgroup TIM_PWMMODE TIM PWM Mode 2-Point Select
  * @{
  * @brief  Macro definitions about TIM pwm mode 2-point select.
  */
typedef enum {
    TIM_PWMMODE_ONEPOINT = 0U,               /*!< PWM Mode Select 1-Point */
    TIM_PWMMODE_TWOPOINT = TIM_CR1_PWMS_M    /*!< PWM Mode Select 2-Point */
} TIM_PwmMode;

/**
  * @}
  */

/** @defgroup TIM_CLOCKDIVISION TIM Clock Division
  * @{
  * @brief  Macro definitions about TIM clock division.
  */
typedef enum {
    TIM_CLOCKDIVISION_DIV1 = 0U,                         /*!< tDTS=tCK_INT */
    TIM_CLOCKDIVISION_DIV2 = (0x1U << TIM_CR1_CKD_S),    /*!< tDTS=2*tCK_INT */
    TIM_CLOCKDIVISION_DIV4 = (0x2U << TIM_CR1_CKD_S)     /*!< tDTS=4*tCK_INT */
} TIM_ClockDivision;
    
/**
  * @}
  */

/** @defgroup TIM_AUTORELOADPRELOAD TIM Auto-reload Preload
  * @{
  * @brief  Macro definitions about TIM Auto-reload preload.
  */
typedef enum {
    TIM_AUTORELOADPRELOAD_DISABLE = 0U,               /*!< Auto-reload preload disable */
    TIM_AUTORELOADPRELOAD_ENABLE  = TIM_CR1_ARPE_M    /*!< Auto-reload preload enable */
} TIM_AutoReloadPreload;

/**
  * @}
  */

/** @defgroup TIM_COUNTERMODE TIM Counter Mode
  * @{
  * @brief  Macro definitions about TIM counter mode.
  */
typedef enum {
    TIM_COUNTERMODE_UP             = 0U,                         /*!< Counter used as upcounter */
    TIM_COUNTERMODE_DOWN           = TIM_CR1_DIR_M,              /*!< Counter used as downcounter */
    TIM_COUNTERMODE_CENTER_UP      = (0x2U << TIM_CR1_CMS_S),    /*!< The counter counts up and down alternatively. 
                                                                      Output compare interrupt flags of output channels are set only when the counter is counting down. */
    TIM_COUNTERMODE_CENTER_DOWN    = (0x1U << TIM_CR1_CMS_S),    /*!< The counter counts up and down alternatively. 
                                                                      Output compare interrupt flags of output channels are set only when the counter is counting up */
    TIM_COUNTERMODE_CENTER_UP_DOWN = (0x3U << TIM_CR1_CMS_S)     /*!< The counter counts up and down alternatively. 
                                                                      Output compare interrupt flags of output channels are set only when the counter is counting up or down. */
} TIM_CounterMode;

/**
  * @}
  */

/** @defgroup TIM_COUNTERDIRECTION TIM Counter Direction
  * @{
  * @brief  Macro definitions about TIM Counter direction.
  */
typedef enum {
    TIM_COUNTERDIRECTION_UP   = 0U,              /*!< Timer counter counts up */
    TIM_COUNTERDIRECTION_DOWN = TIM_CR1_DIR_M    /*!< Timer counter counts down */
} TIM_CounterDirection;

/**
  * @}
  */

/** @defgroup TIM_ONEPULSEMODE TIM One Pulse Mode
  * @{
  * @brief  Macro definitions about TIM one pulse mode.
  */
typedef enum {
    TIM_ONEPULSEMODE_REPETITIVE = 0U,              /*!< Counter stops counting at the next update event */
    TIM_ONEPULSEMODE_SINGLE     = TIM_CR1_OPM_M    /*!< Counter is not stopped at update event */
} TIM_OnePulseMode;

/**
  * @}
  */

/** @defgroup TIM_UPDATEREQSRC TIM Update Request Source
  * @{
  * @brief  Macro definitions about TIM update request source.
  */
typedef enum {
    TIM_UPDATEREQSRC_REGULAR = 0U,              /*!< Counter overflow/underflow, Setting the UG bit or Update generation 
                                                   through the slave mode controller generates an update request */
    TIM_UPDATEREQSRC_COUNTER = TIM_CR1_URS_M    /*!< Only counter overflow/underflow generates an update request */
} TIM_UpdateReqSrc;

/**
  * @}
  */

/** @defgroup TIM_UPDATEEVENT TIM Update Event
  * @{
  * @brief  Macro definitions about TIM update event.
  */
typedef enum {
    TIM_UPDATEEVENT_ENABLE  = 0U,               /*!< Update event enable */
    TIM_UPDATEEVENT_DISABLE = TIM_CR1_UDIS_M    /*!< Update event disable */
} TIM_UpdateEvent;

/**
  * @}
  */

/** @defgroup TIM_TRGO TIM Trigger Output
  * @{
  * @brief  Macro definitions about TIM trigger output.
  */
typedef enum {
    TIM_TRGO_RESET  = 0U,                         /*!< UG bit from the TIMx_EGR register is used as trigger output */
    TIM_TRGO_ENABLE = (0x1U << TIM_CR2_MMS_S),    /*!< Counter Enable signal (CNT_EN) is used as trigger output */
    TIM_TRGO_UPDATE = (0x2U << TIM_CR2_MMS_S),    /*!< Update event is used as trigger output */
    TIM_TRGO_CC1IF  = (0x3U << TIM_CR2_MMS_S),    /*!< CC1 capture or a compare match is used as trigger output */
    TIM_TRGO_OC1REF = (0x4U << TIM_CR2_MMS_S),    /*!< OC1REF signal is used as trigger output */
    TIM_TRGO_OC2REF = (0x5U << TIM_CR2_MMS_S),    /*!< OC2REF signal is used as trigger output */
    TIM_TRGO_OC3REF = (0x6U << TIM_CR2_MMS_S),    /*!< OC3REF signal is used as trigger output */
    TIM_TRGO_OC4REF = (0x7U << TIM_CR2_MMS_S)     /*!< OC4REF signal is used as trigger output */
} TIM_TriggerOut;

/**
  * @}
  */

/** @defgroup TIM_CCUPDATESOURCE TIM Capture Compare Update Source
  * @{
  * @brief  Macro definitions about TIM capture compare update source.
  */
typedef enum {
    TIM_CCUPDATESOURCE_COMG_ONLY     = 0U,               /*!< Capture/compare control bits are updated by setting the COMG bit only */
    TIM_CCUPDATESOURCE_COMG_AND_TRGI = TIM_CR2_CCUS_M    /*!< Capture/compare control bits are updated by setting the COMG bit or 
                                                              when a rising edge occurs on trigger input (TRGI) */
} TIM_CcUpdateSource;

/**
  * @}
  */

/** @defgroup TIM_OCMODE TIM Output Configuration Mode
  * @{
  * @brief  Macro definitions about TIM output configuration mode.
  */
typedef enum {
    TIM_OCMODE_FROZEN          = 0U,                            /*!< The comparison between the output compare register TIMx_CCRy 
                                                                     and the counter TIMx_CNT has no effect on the output channel level */
    TIM_OCMODE_ACTIVE          = (0x1U << TIM_CCMR1_OC1M_S),    /*!< OCyREF is forced high on compare match */
    TIM_OCMODE_INACTIVE        = (0x2U << TIM_CCMR1_OC1M_S),    /*!< OCyREF is forced low on compare match */
    TIM_OCMODE_TOGGLE          = (0x3U << TIM_CCMR1_OC1M_S),    /*!< OCyREF toggles on compare match */
    TIM_OCMODE_FORCED_INACTIVE = (0x4U << TIM_CCMR1_OC1M_S),    /*!< OCyREF is forced low */
    TIM_OCMODE_FORCED_ACTIVE   = (0x5U << TIM_CCMR1_OC1M_S),    /*!< OCyREF is forced high */
    TIM_OCMODE_PWM1            = (0x6U << TIM_CCMR1_OC1M_S),    /*!< In upcounting, channel y is active as long as TIMx_CNT<TIMx_CCRy else inactive.  
                                                                     In downcounting, channel y is inactive as long as TIMx_CNT>TIMx_CCRy else active. */
    TIM_OCMODE_PWM2            = (0X7U << TIM_CCMR1_OC1M_S)     /*!< In upcounting, channel y is inactive as long as TIMx_CNT<TIMx_CCRy else active.  
                                                                     In downcounting, channel y is active as long as TIMx_CNT>TIMx_CCRy else inactive */
} TIM_OcMode;

/**
  * @}
  */

/** @defgroup TIM_OC_ACTIVE TIM Output Configuration State
  * @{
  * @brief  Macro definitions about TIM output configuration state.
  */
typedef enum {
    TIM_OC_ACTIVE_CHP_DISABLE_CHN_DISABLE = 0U,                                   /*!< OCx disable state, OCxN disable state */
    TIM_OC_ACTIVE_CHP_DISABLE_CHN_ENABLE  = TIM_CCER_CC1NE_M,                     /*!< OCx disable state, OCxN enable state */
    TIM_OC_ACTIVE_CHP_ENABLE_CHN_DISABLE  = TIM_CCER_CC1E_M,                      /*!< OCx enable state,  OCxN disable state */
    TIM_OC_ACTIVE_CHP_ENABLE_CHN_ENABLE   = TIM_CCER_CC1E_M | TIM_CCER_CC1NE_M    /*!< OCx enable state,  OCxN enable state */
} TIM_OcActive;

/**
  * @}
  */

/** @defgroup TIM_OC_POLARITY TIM Output Configuration Polarity
  * @{
  * @brief  Macro definitions about TIM output configuration polarity.
  */
typedef enum {
    TIM_OC_POLARITY_CHP_HIGH_CHN_HIGH = 0U,                                   /*!< OCx active high, OCxN active high */
    TIM_OC_POLARITY_CHP_HIGH_CHN_LOW  = TIM_CCER_CC1NP_M,                     /*!< OCx active high, OCxN active low */
    TIM_OC_POLARITY_CHP_LOW_CHN_HIGH  = TIM_CCER_CC1P_M,                      /*!< OCx active low, OCxN active high */
    TIM_OC_POLARITY_CHP_LOW_CHN_LOW   = TIM_CCER_CC1P_M | TIM_CCER_CC1NP_M    /*!< OCx active low, OCxN active low */
} TIM_OcPolarity;

/**
  * @}
  */

/** @defgroup TIM_OC_IDLESTATE TIM Output Configuration Idle State
  * @{
  * @brief  Macro definitions about TIM output configuration idle state.
  */
typedef enum {
    TIM_OC_IDLESTATE_CHP_LOW_CHN_LOW   = 0U,                                 /*!< OCx=0, OCxN=0 (after a dead-time if OC is implemented) when MOE=0 */
    TIM_OC_IDLESTATE_CHP_HIGH_CHN_LOW  = TIM_CR2_OIS1_M,                     /*!< OCx=1, OCxN=0 (after a dead-time if OC is implemented) when MOE=0 */
    TIM_OC_IDLESTATE_CHP_LOW_CHN_HIGH  = TIM_CR2_OIS1N_M,                    /*!< OCx=0, OCxN=1 (after a dead-time if OC is implemented) when MOE=0 */
    TIM_OC_IDLESTATE_CHP_HIGH_CHN_HIGH = TIM_CR2_OIS1_M | TIM_CR2_OIS1N_M    /*!< OCx=1, OCxN=1 (after a dead-time if OC is implemented) when MOE=0 */
} TIM_OcIdleState;

/**
  * @}
  */

/** @defgroup TIM_IC_ACTIVE TIM Input Channel Active Selection
  * @{
  * @brief  Macro definitions about TIM input channel active selection.
  */
typedef enum {
    TIM_IC_ACTIVE_DIRECTTI = 0x1U,    /*!< ICx is mapped on TIx */
    TIM_IC_ACTIVE_INDIRECTTI,         /*!< ICx is mapped on TIy */
    TIM_IC_ACTIVE_TRC                 /*!< ICx is mapped on TRC */
} TIM_IcActiveSel;

/**
  * @}
  */

/** @defgroup TIM_IC_POLARITY TIM Input Configuration Polarity
  * @{
  * @brief  Macro definitions about TIM input configuration polarity.
  */
typedef enum {
    TIM_IC_POLARITY_RISING  = 0U,                          /*!< The circuit is sensitive to TIxFP1 rising edge, TIxFP1 is not inverted */
    TIM_IC_POLARITY_FALLING = (TIM_CCER_CC1P_M << 16UL)    /*!< The circuit is sensitive to TIxFP1 falling edge, TIxFP1 is inverted */
} TIM_IcPolarity;

/**
  * @}
  */

/** @defgroup TIM_IC_PSC TIM Input Configuration Prescaler
  * @{
  * @brief  Macro definitions about TIM input configuration prescaler.
  */
typedef enum {
    TIM_IC_PSC_DIV1 = 0U,      /*!< No prescaler, capture is done each time an edge is detected on the capture input */
    TIM_IC_PSC_DIV2 = 0x4U,    /*!< Capture is done once every 2 events */
    TIM_IC_PSC_DIV4 = 0x8U,    /*!< Capture is done once every 4 events */
    TIM_IC_PSC_DIV8 = 0xCU     /*!< Capture is done once every 8 events */
} TIM_IcPrescaler;

/**
  * @}
  */

/** @defgroup TIM_IC_FILTER TIM Input Configuration Filter
  * @{
  * @brief  Macro definitions about TIM input configuration filter.
  */
typedef enum {
    TIM_IC_FILTER_FDIV1     = 0U,       /*!< No filter, sampling is done at fDTS */
    TIM_IC_FILTER_FDIV1_N2  = 0x10U,    /*!< fSAMPLING=fCK_INT, N=2 */
    TIM_IC_FILTER_FDIV1_N4  = 0x20U,    /*!< fSAMPLING=fCK_INT, N=4 */
    TIM_IC_FILTER_FDIV1_N8  = 0x30U,    /*!< fSAMPLING=fCK_INT, N=8 */
    TIM_IC_FILTER_FDIV2_N6  = 0x40U,    /*!< fSAMPLING=fDTS/2, N=6 */
    TIM_IC_FILTER_FDIV2_N8  = 0x50U,    /*!< fSAMPLING=fDTS/2, N=8 */
    TIM_IC_FILTER_FDIV4_N6  = 0x60U,    /*!< fSAMPLING=fDTS/4, N=6 */
    TIM_IC_FILTER_FDIV4_N8  = 0x70U,    /*!< fSAMPLING=fDTS/4, N=8 */
    TIM_IC_FILTER_FDIV8_N6  = 0x80U,    /*!< fSAMPLING=fDTS/8, N=6 */
    TIM_IC_FILTER_FDIV8_N8  = 0x90U,    /*!< fSAMPLING=fDTS/8, N=8 */
    TIM_IC_FILTER_FDIV16_N5 = 0xA0U,    /*!< fSAMPLING=fDTS/16, N=5 */
    TIM_IC_FILTER_FDIV16_N6 = 0xB0U,    /*!< fSAMPLING=fDTS/16, N=6 */
    TIM_IC_FILTER_FDIV16_N8 = 0xC0U,    /*!< fSAMPLING=fDTS/16, N=8 */
    TIM_IC_FILTER_FDIV32_N5 = 0xD0U,    /*!< fSAMPLING=fDTS/32, N=5 */
    TIM_IC_FILTER_FDIV32_N6 = 0xE0U,    /*!< fSAMPLING=fDTS/32, N=6 */
    TIM_IC_FILTER_FDIV32_N8 = 0xF0U     /*!< fSAMPLING=fDTS/32, N=8 */
} TIM_IcFilter;

/**
  * @}
  */

/** @defgroup TIM_CLOCKSOURCE TIM Clock Source
  * @{
  * @brief  Macro definitions about TIM clock source.
  */
typedef enum {
    TIM_CLOCKSOURCE_INTERNAL  = 0U,                /*!< The timer is clocked by the internal clock provided from the RCC */
    TIM_CLOCKSOURCE_EXT_MODE1 = TIM_SMCR_SMS_M,    /*!< Counter counts at each rising or falling edge on a selected input */
    TIM_CLOCKSOURCE_EXT_MODE2 = TIM_SMCR_ECE_M     /*!< Counter counts at each rising or falling edge on the external trigger input ETR */
} TIM_ClockSource;

/**
  * @}
  */

/** @defgroup TIM_TS TIM Trigger Selection
  * @{
  * @brief  Macro definitions about TIM trigger selection.
  */
typedef enum {
    TIM_TS_ITR0    = 0U,                         /*!< Internal Trigger 0 (ITR0) is used as trigger input */
    TIM_TS_ITR1    = (0x1U << TIM_SMCR_TS_S),    /*!< Internal Trigger 1 (ITR1) is used as trigger input */
    TIM_TS_ITR2    = (0x2U << TIM_SMCR_TS_S),    /*!< Internal Trigger 2 (ITR2) is used as trigger input */
    TIM_TS_ITR3    = (0x3U << TIM_SMCR_TS_S),    /*!< Internal Trigger 3 (ITR3) is used as trigger input */
    TIM_TS_TI1F_ED = (0x4U << TIM_SMCR_TS_S),    /*!< TI1 Edge Detector (TI1F_ED) is used as trigger input */
    TIM_TS_TI1FP1  = (0x5U << TIM_SMCR_TS_S),    /*!< Filtered Timer Input 1 (TI1FP1) is used as trigger input */
    TIM_TS_TI2FP2  = (0x6U << TIM_SMCR_TS_S),    /*!< Filtered Timer Input 2 (TI12P2) is used as trigger input */
    TIM_TS_ETRF    = (0x7U << TIM_SMCR_TS_S)     /*!< Filtered external Trigger (ETRF) is used as trigger input */
} TIM_TriggerSel;

/**
  * @}
  */

/** @defgroup TIM_ENCODERMODE TIM Encoder Mode
  * @{
  * @brief  Macro definitions about TIM encoder mode.
  */
typedef enum {
    TIM_ENCODERMODE_X2_TI1  = (0x1U << TIM_SMCR_SMS_S),    /*!< Quadrature encoder mode 1, x2 mode 
                                                               - Counter counts up/down on TI2FP2 edge depending on TI1FP1 level */
    TIM_ENCODERMODE_X2_TI2  = (0x2U << TIM_SMCR_SMS_S),    /*!< Quadrature encoder mode 2, x2 mode 
                                                               - Counter counts up/down on TI1FP1 edge depending on TI2FP2 level */
    TIM_ENCODERMODE_X4_TI12 = (0x3U << TIM_SMCR_SMS_S)     /*!< Quadrature encoder mode 3, x4 mode 
                                                               - Counter counts up/down on both TI1FP1 and TI2FP2 edges depending on the level of the other input */
} TIM_EncoderMode;

/**
  * @}
  */

/** @defgroup TIM_SLAVEMODE TIM Slave Mode
  * @{
  * @brief  Macro definitions about TIM slave mode.
  */
typedef enum {
    TIM_SLAVEMODE_DISABLED    = 0U,                          /*!< Slave mode disabled */
    TIM_SLAVEMODE_RESET       = (0x4U << TIM_SMCR_SMS_S),    /*!< Reset Mode - Rising edge of the selected trigger input (TRGI) reinitializes the counter */
    TIM_SLAVEMODE_GATED       = (0x5U << TIM_SMCR_SMS_S),    /*!< Gated Mode - The counter clock is enabled when the trigger input (TRGI) is high */
    TIM_SLAVEMODE_TRIGGER     = (0x6U << TIM_SMCR_SMS_S),    /*!< Trigger Mode - The counter starts at a rising edge of the trigger TRGI */
    TIM_SLAVEMODE_EXTCLKMODE1 = (0x7U << TIM_SMCR_SMS_S)     /*!< External Clock Mode 1 - Rising edges of the selected trigger (TRGI) clock the counter */
} TIM_SlaveMode;

/**
  * @}
  */

/** @defgroup TIM_ETR_POLARITY TIM External Trigger Polarity
  * @{
  * @brief  Macro definitions about TIM external trigger polarity.
  */
typedef enum {
    TIM_ETR_POLARITY_NONINVERTED = 0U,               /*!< ETR is non-inverted, active at high level or rising edge */
    TIM_ETR_POLARITY_INVERTED    = TIM_SMCR_ETP_M    /*!< ETR is inverted, active at low level or falling edge */
} TIM_EtrPolarity;

/**
  * @}
  */

/** @defgroup TIM_ETR_PRESCALER TIM External Trigger Prescaler
  * @{
  * @brief  Macro definitions about TIM external trigger perscaler.
  */
typedef enum {
    TIM_ETR_PRESCALER_DIV1 = 0U,                           /*!< ETR prescaler OFF */
    TIM_ETR_PRESCALER_DIV2 = (0x1U << TIM_SMCR_ETPS_S),    /*!< ETR frequency is divided by 2 */
    TIM_ETR_PRESCALER_DIV4 = (0x2U << TIM_SMCR_ETPS_S),    /*!< ETR frequency is divided by 4 */
    TIM_ETR_PRESCALER_DIV8 = (0x3U << TIM_SMCR_ETPS_S)     /*!< ETR frequency is divided by 8 */
} TIM_EtrPrescaler;

/**
  * @}
  */

/** @defgroup TIM_ETR_FILTER TIM External Trigger Filter
  * @{
  * @brief  Macro definitions about TIM external trigger filter.
  */
typedef enum {
    TIM_ETR_FILTER_FDIV1     = 0U,                          /*!< No filter, sampling is done at fDTS */
    TIM_ETR_FILTER_FDIV1_N2  = (0x1U << TIM_SMCR_ETF_S),    /*!< fSAMPLING=fCK_INT, N=2 */
    TIM_ETR_FILTER_FDIV1_N4  = (0x2U << TIM_SMCR_ETF_S),    /*!< fSAMPLING=fCK_INT, N=4 */
    TIM_ETR_FILTER_FDIV1_N8  = (0x3U << TIM_SMCR_ETF_S),    /*!< fSAMPLING=fCK_INT, N=8 */
    TIM_ETR_FILTER_FDIV2_N6  = (0x4U << TIM_SMCR_ETF_S),    /*!< fSAMPLING=fDTS/2, N=6 */
    TIM_ETR_FILTER_FDIV2_N8  = (0x5U << TIM_SMCR_ETF_S),    /*!< fSAMPLING=fDTS/2, N=8 */
    TIM_ETR_FILTER_FDIV4_N6  = (0x6U << TIM_SMCR_ETF_S),    /*!< fSAMPLING=fDTS/4, N=6 */
    TIM_ETR_FILTER_FDIV4_N8  = (0x7U << TIM_SMCR_ETF_S),    /*!< fSAMPLING=fDTS/4, N=8 */
    TIM_ETR_FILTER_FDIV8_N6  = (0x8U << TIM_SMCR_ETF_S),    /*!< fSAMPLING=fDTS/8, N=8 */
    TIM_ETR_FILTER_FDIV8_N8  = (0x9U << TIM_SMCR_ETF_S),    /*!< fSAMPLING=fDTS/16, N=5 */
    TIM_ETR_FILTER_FDIV16_N5 = (0xAU << TIM_SMCR_ETF_S),    /*!< fSAMPLING=fDTS/16, N=6 */
    TIM_ETR_FILTER_FDIV16_N6 = (0xBU << TIM_SMCR_ETF_S),    /*!< fSAMPLING=fDTS/16, N=8 */
    TIM_ETR_FILTER_FDIV16_N8 = (0xCU << TIM_SMCR_ETF_S),    /*!< fSAMPLING=fDTS/16, N=5 */
    TIM_ETR_FILTER_FDIV32_N5 = (0xDU << TIM_SMCR_ETF_S),    /*!< fSAMPLING=fDTS/32, N=5 */
    TIM_ETR_FILTER_FDIV32_N6 = (0xEU << TIM_SMCR_ETF_S),    /*!< fSAMPLING=fDTS/32, N=6 */
    TIM_ETR_FILTER_FDIV32_N8 = (0xFU << TIM_SMCR_ETF_S)     /*!< fSAMPLING=fDTS/32, N=8 */
} TIM_EtrFilter;

/**
  * @}
  */

/** @defgroup TIM_AUTOMATICOUTPUT TIM Automatic Output Enable/Disable
  * @{
  * @brief  Macro definitions about TIM automatic output enable/disable.
  */
typedef enum {
    TIM_AUTOMATICOUTPUT_DISABLE = 0U,               /*!< MOE can be set only by software */
    TIM_AUTOMATICOUTPUT_ENABLE  = TIM_BDTR_AOE_M    /*!< MOE can be set by software or automatically at the next update event */
} TIM_AutomaticOutput;

/**
  * @}
  */

/** @defgroup TIM_BREAK_POLARITY TIM Break Polarity
  * @{
  * @brief  Macro definitions about TIM break polarity.
  */
typedef enum {
    TIM_BREAK_POLARITY_LOW  = 0U,               /*!< Break input BRK is active low */
    TIM_BREAK_POLARITY_HIGH = TIM_BDTR_BKP_M    /*!< Break input BRK is active high */
} TIM_BreakPolarity;

/**
  * @}
  */

/** @defgroup TIM_BREAK TIM Break Enable/Disable
  * @{
  * @brief  Macro definitions about TIM break enable/disable.
  */
typedef enum {
    TIM_BREAK_DISABLE = 0U,               /*!< Break function disabled */
    TIM_BREAK_ENABLE  = TIM_BDTR_BKE_M    /*!< Break function enabled */
} TIM_Break;

/**
  * @}
  */

/** @defgroup TIM_OSSR TIM Off-State Selection For Run Mode
  * @{
  * @brief  Macro definitions about TIM off-state selection for run mode.
  */
typedef enum {
    TIM_OSSR_DISABLE = 0U,                /*!< When inactive, OCx/OCxN outputs are disabled */
    TIM_OSSR_ENABLE  = TIM_BDTR_OSSR_M    /*!< When inactive, OC/OCN outputs are enabled with their inactive level as 
                                               soon as CCxE=1 or CCxNE=1 */
} TIM_Ossr;

/**
  * @}
  */

/** @defgroup TIM_OSSI TIM Off-State Selection For Idle Mode
  * @{
  * @brief  Macro definitions about TIM off-state selection for idle mode.
  */
typedef enum {
    TIM_OSSI_DISABLE = 0U,                /*!< When inactive, OCx/OCxN outputs are disabled */
    TIM_OSSI_ENABLE  = TIM_BDTR_OSSI_M    /*!< When inactive, OxC/OCxN outputs are first forced with their 
                                               inactive level then forced to their idle level after the deadtime */
} TIM_Ossi;

/**
  * @}
  */

/** @defgroup TIM_LOCKLEVEL TIM Lock Level
  * @{
  * @brief  Macro definitions about TIM lock level.
  */
typedef enum {
    TIM_LOCKLEVEL_OFF = 0U,                           /*!< LOCK OFF - No bit is write protected */
    TIM_LOCKLEVEL_1   = (0x1U << TIM_BDTR_LOCK_S),    /*!< LOCK Level 1 */
    TIM_LOCKLEVEL_2   = (0x2U << TIM_BDTR_LOCK_S),    /*!< LOCK Level 2 */
    TIM_LOCKLEVEL_3   = (0x3U << TIM_BDTR_LOCK_S)     /*!< LOCK Level 3 */
} TIM_LockLevel;

/**
  * @}
  */

/** @defgroup TIM_DMABURST_BASEADDR TIM DMA Burst Base Address
  * @{
  * @brief  Macro definitions about TIM DMA burst base address.
  */
typedef enum {
    TIM_DMABURST_BASEADDR_CR1 = 0U,    /*!< TIMx_CR1 register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_CR2,         /*!< TIMx_CR2 register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_SMCR,        /*!< TIMx_SMCR register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_DIER,        /*!< TIMx_DIER register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_SR,          /*!< TIMx_SR register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_EGR,         /*!< TIMx_EGR register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_CCMR1,       /*!< TIMx_CCMR1 register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_CCMR2,       /*!< TIMx_CCMR2 register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_CCER,        /*!< TIMx_CCER register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_CNT,         /*!< TIMx_CNT register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_PSC,         /*!< TIMx_PSC register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_ARR,         /*!< TIMx_ARR register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_RCR,         /*!< TIMx_RCR register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_CCR1,        /*!< TIMx_CCR1 register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_CCR2,        /*!< TIMx_CCR2 register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_CCR3,        /*!< TIMx_CCR3 register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_CCR4,        /*!< TIMx_CCR4 register is the DMA base address for DMA burst */
    TIM_DMABURST_BASEADDR_BDTR         /*!< TIMx_BDTR register is the DMA base address for DMA burst */
} TIM_DmaBurstAddr;

/**
  * @}
  */

/** @defgroup TIM_DMABURST_LENGTH TIM DMA Burst Length
  * @{
  * @brief  Macro definitions about TIM DMA burst length.
  */
typedef enum {
    TIM_DMABURST_LENGTH_1TRANSFER   = 0U,                          /*!< Transfer is done to 1 register starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_2TRANSFERS  = (0x1U << TIM_DCR_DBL_S),     /*!< Transfer is done to 2 registers starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_3TRANSFERS  = (0x2U << TIM_DCR_DBL_S),     /*!< Transfer is done to 3 registers starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_4TRANSFERS  = (0x3U << TIM_DCR_DBL_S),     /*!< Transfer is done to 4 registers starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_5TRANSFERS  = (0x4U << TIM_DCR_DBL_S),     /*!< Transfer is done to 5 registers starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_6TRANSFERS  = (0x5U << TIM_DCR_DBL_S),     /*!< Transfer is done to 6 registers starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_7TRANSFERS  = (0x6U << TIM_DCR_DBL_S),     /*!< Transfer is done to 7 registers starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_8TRANSFERS  = (0x7U << TIM_DCR_DBL_S),     /*!< Transfer is done to 1 registers starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_9TRANSFERS  = (0x8U << TIM_DCR_DBL_S),     /*!< Transfer is done to 9 registers starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_10TRANSFERS = (0x9U << TIM_DCR_DBL_S),     /*!< Transfer is done to 10 registers starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_11TRANSFERS = (0xAU << TIM_DCR_DBL_S),     /*!< Transfer is done to 11 registers starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_12TRANSFERS = (0xBU << TIM_DCR_DBL_S),     /*!< Transfer is done to 12 registers starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_13TRANSFERS = (0xCU << TIM_DCR_DBL_S),     /*!< Transfer is done to 13 registers starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_14TRANSFERS = (0xDU << TIM_DCR_DBL_S),     /*!< Transfer is done to 14 registers starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_15TRANSFERS = (0xEU << TIM_DCR_DBL_S),     /*!< Transfer is done to 15 registers starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_16TRANSFERS = (0xFU << TIM_DCR_DBL_S),     /*!< Transfer is done to 16 registers starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_17TRANSFERS = (0x10U << TIM_DCR_DBL_S),    /*!< Transfer is done to 17 registers starting from the DMA burst base address */
    TIM_DMABURST_LENGTH_18TRANSFERS = (0x11U << TIM_DCR_DBL_S)     /*!< Transfer is done to 18 registers starting from the DMA burst base address */
} TIM_DmaBurstLength;

/**
  * @}
  */

/** @defgroup TIM_CHANNEL TIM Channel
  * @{
  * @brief  Macro definitions about TIM channel.
  */
typedef enum {
    TIM_CHANNEL_CH1 = 0U,    /*!< Timer input/output channel 1 */
    TIM_CHANNEL_CH2,         /*!< Timer input/output channel 2 */
    TIM_CHANNEL_CH3,         /*!< Timer input/output channel 3 */
    TIM_CHANNEL_CH4          /*!< Timer input/output channel 4 */
} TIM_Channel;

/**
  * @}
  */

/**
  * @}
  */


/*******************************************************************************
 * Variables
 ******************************************************************************/
/** @defgroup TIM_PUBLIC_VARIABLES TIM Publicly Variables
  * @{
  * @brief  These public variables do not need to be configured by the user
  */

/** @defgroup TIM_SHIFT_TAB_CCMR The Shift Table For Capturing/Comparing Control Bits In The CCMR Registers
  * @{
  * @brief  This static constant is used to index the position of each channel in the CCMR registers
  */
static const uint8_t SHIFT_TAB_CCMR[] =
{
    0U,    /* 0: OC1M, OC1FE, OC1PE, CC1S, IC1PSC, IC1F */
    8U,    /* 1: OC2M, OC2FE, OC2PE, CC2S, IC2PSC, IC2F */
    0U,    /* 2: OC3M, OC3FE, OC3PE, CC3S, IC3PSC, IC3F */
    8U     /* 3: OC4M, OC4FE, OC4PE, CC4S, IC4PSC, IC4F */
};

/**
  * @}
  */

/** @defgroup TIM_SHIFT_TAB_CCER The Shift Table For Capturing/Comparing Enable Bits In The CCER Registers
  * @{
  * @brief  This static constant is used to index the position of each channel in the CCER registers
  */
static const uint8_t SHIFT_TAB_CCER[] =
{
    0U,    /* 0: CC1E, CC1P, CC1NE, CC1NP */
    4U,    /* 0: CC2E, CC2P, CC2NE, CC2NP */
    8U,    /* 0: CC3E, CC3P, CC3NE, CC3NP */
    12U    /* 0: CC4E, CC4P, CC4NE, CC4NP */
};

/**
  * @}
  */

/**
  * @}
  */


/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
  * \brief  Enable timer counter.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_enableCounter (TIM_TypeDef *tim)
{
    SET_BIT(tim->CR1.WORDVAL, TIM_CR1_CEN_M);
}

/**
  * \brief  Disable timer counter.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_disableCounter (TIM_TypeDef *tim)
{
    CLEAR_BIT(tim->CR1.WORDVAL, TIM_CR1_CEN_M);
}

/**
  * \brief  Get whether the timer counter is enabled.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the status of whether the timer counter is enabled or not
  *                 - 0: The timer counter is not enable.
  *                 - 1: The timer counter is enable.
  */
static inline uint32_t TIM_getCounterEnabledStatus (TIM_TypeDef *tim)
{
    return ((READ_BIT(tim->CR1.WORDVAL, TIM_CR1_CEN_M) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Enable update event generation.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_enableUpdateEvent (TIM_TypeDef *tim)
{
    CLEAR_BIT(tim->CR1.WORDVAL, TIM_CR1_UDIS_M);
}

/**
  * \brief  Disable update event generation.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_disableUpdateEvent (TIM_TypeDef *tim)
{
    SET_BIT(tim->CR1.WORDVAL, TIM_CR1_UDIS_M);
}

/**
  * \brief  Get whether update event generation is enabled.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the status of whether the timer update event generation is enabled or not
  *                 - 0: The timer update event generation is not enable.
  *                 - 1: The timer update event generation is enable.
  */
static inline uint32_t TIM_getUpdateEventEnabledStatus (TIM_TypeDef *tim)
{
    return ((READ_BIT(tim->CR1.WORDVAL, TIM_CR1_UDIS_M) == 0UL) ? 1UL : 0UL);
}

/**
  * \brief  Set update request source.
  * \note   Update event source set to TIM_UPDATESOURCE_REGULAR: any of the following events
  *         generate an update interrupt or DMA request if enabled:
  *          - Counter overflow/underflow
  *          - Setting the UG bit
  *          - Update generation through the slave mode controller
  * \note   Update event source set to TIM_UPDATESOURCE_COUNTER: only counter
  *         overflow/underflow generates an update interrupt or DMA request if enabled.
  * \param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * \param  updateReqSrc    Update request source
  *                          This parameter can be any value of @ref TIM_UPDATEREQSRC
  */
static inline void TIM_setUpdateRequestSource (TIM_TypeDef *tim, TIM_UpdateReqSrc updateReqSrc)
{
    MODIFY_REG(tim->CR1.WORDVAL, TIM_CR1_URS_M, updateReqSrc);
}

/**
  * \brief  Get actual request update source.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned actual update request source
  *                 This value can be any value of @ref TIM_UPDATEREQSRC
  */
static inline TIM_UpdateReqSrc TIM_getUpdateSource (TIM_TypeDef *tim)
{
    return (TIM_UpdateReqSrc)(READ_BIT(tim->CR1.WORDVAL, TIM_CR1_URS_M));
}

/**
  * \brief  Set one pulse mode (one shot v.s. repetitive).
  * \param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * \param  onePulseMode    One pulse Mode
  *                          This parameter can be any value of @ref TIM_ONEPULSEMODE
  */
static inline void TIM_setOnePulseMode (TIM_TypeDef *tim, TIM_OnePulseMode onePulseMode)
{
    MODIFY_REG(tim->CR1.WORDVAL, TIM_CR1_OPM_M, onePulseMode);
}

/**
  * \brief  Get actual one pulse mode.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned actual one pulse mode
  *                 This value can be any value of @ref TIM_ONEPULSEMODE
  */
static inline TIM_OnePulseMode TIM_getOnePulseMode (TIM_TypeDef *tim)
{
    return (TIM_OnePulseMode)(READ_BIT(tim->CR1.WORDVAL, TIM_CR1_OPM_M));
}

/**
  * \brief  Set the timer counter counting mode.
  * \note   Switching from Center Aligned counter mode to Edge counter mode (or reverse) requires 
  *         a timer reset to avoid unexpected direction due to DIR bit readonly in center aligned mode.
  * \param  tim            TIMx pointer to a TIM_TypeDef structure
  *                         - TIM1: TIM1 base address index
  *                         - TIM2: TIM2 base address index
  * \param  counterMode    Counter mode
  *                         This parameter can be any value of @ref TIM_COUNTERMODE
  */
static inline void TIM_setCounterMode (TIM_TypeDef *tim, TIM_CounterMode counterMode)
{
    MODIFY_REG(tim->CR1.WORDVAL, (TIM_CR1_DIR_M | TIM_CR1_CMS_M), counterMode);
}

/**
  * \brief  Get actual counter mode.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned actual counter mode
  *                 This value can be any value of @ref TIM_COUNTERMODE
  */
static inline TIM_CounterMode TIM_getCounterMode (TIM_TypeDef *tim)
{
    return (TIM_CounterMode)(READ_BIT(tim->CR1.WORDVAL, TIM_CR1_DIR_M | TIM_CR1_CMS_M));
}

/**
  * \brief  Enable auto-reload (ARR) preload.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_enableAutoReloadPreload (TIM_TypeDef *tim)
{
    SET_BIT(tim->CR1.WORDVAL, TIM_CR1_ARPE_M);
}

/**
  * \brief  Disable auto-reload (ARR) preload.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_disableAutoReloadPreload (TIM_TypeDef *tim)
{
    CLEAR_BIT(tim->CR1.WORDVAL, TIM_CR1_ARPE_M);
}

/**
  * \brief  Get whether auto-reload (ARR) preload is enabled.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the status of whether the auto-reload (ARR) preload is enabled or not
  *                 - 0: The timer auto-reload (ARR) preload is not enable.
  *                 - 1: The timer auto-reload (ARR) preload is enable.
  */
static inline uint32_t TIM_getAutoReloadPreloadEnabledStatus (TIM_TypeDef *tim)
{
    return ((READ_BIT(tim->CR1.WORDVAL, TIM_CR1_ARPE_M) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Set the division ratio between the timer clock and the sampling clock 
  *         used by the dead-time generators (when supported) and the digital filters.
  * \param  tim              TIMx pointer to a TIM_TypeDef structure
  *                           - TIM1: TIM1 base address index
  *                           - TIM2: TIM2 base address index
  * \param  clockDivision    Clock division
  *                           This parameter can be any value of @ref TIM_CLOCKDIVISION
  */
static inline void TIM_setClockDivision (TIM_TypeDef *tim, TIM_ClockDivision clockDivision)
{
    MODIFY_REG(tim->CR1.WORDVAL, TIM_CR1_CKD_M, clockDivision);
}

/**
  * \brief  Get the actual division ratio between the timer clock  and the sampling clock 
  *         used by the dead-time generators (when supported) and the digital filters.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned actual division
  *                 This value can be any value of @ref TIM_CLOCKDIVISION
  */
static inline TIM_ClockDivision TIM_getClockDivision (TIM_TypeDef *tim)
{
    return (TIM_ClockDivision)(READ_BIT(tim->CR1.WORDVAL, TIM_CR1_CKD_M));
}

/**
  * \brief  Enable PWM 2-point compare mode.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_enablePwm2PointMode (TIM_TypeDef *tim)
{
    SET_BIT(tim->CR1.WORDVAL, TIM_CR1_PWMS_M);
}

/**
  * \brief  Disable PWM 2-point compare mode.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_disablePwm2PointMode (TIM_TypeDef *tim)
{
    CLEAR_BIT(tim->CR1.WORDVAL, TIM_CR1_PWMS_M);
}

/**
  * \brief  Get whether PWM 2-point compare mode is enabled.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the status of whether the PWM 2-point compare mode is enabled or not
  *                 - 0: The timer PWM 2-point compare mode is not enable.
  *                 - 1: The timer PWM 2-point compare mode is enable.
  */
static inline uint32_t TIM_getPwm2PointModeEnabledStatus (TIM_TypeDef *tim)
{
    return ((READ_BIT(tim->CR1.WORDVAL, TIM_CR1_PWMS_M) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Set the counter value.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  counter    Counter value
  *                     This parameter between Min_Data=0 and Max_Data=65535
  */
static inline void TIM_setCounter (TIM_TypeDef *tim, uint32_t counter)
{
    WRITE_REG(tim->CNT.WORDVAL, counter);
}

/**
  * \brief  Get the counter value.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned counter value
  *                 This value between Min_Data=0 and Max_Data=65535
  */
static inline uint32_t TIM_getCounter (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->CNT.WORDVAL));
}

/**
  * \brief  Get the current direction of the counter
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the current direction
  *                 This value can be any value of @ref TIM_COUNTERDIRECTION
  */
static inline TIM_CounterDirection TIM_getCounterDirection (TIM_TypeDef *tim)
{
    return (TIM_CounterDirection)(READ_BIT(tim->CR1.WORDVAL, TIM_CR1_DIR_M));
}

/**
  * \brief  Set the prescaler value.
  * \note   The counter clock frequency CK_CNT is equal to fCK_PSC / (PSC[15:0] + 1).
  * \note   The prescaler can be changed on the fly as this control register is buffered. 
  *         The new prescaler ratio is taken into account at the next update event.
  * \param  tim          TIMx pointer to a TIM_TypeDef structure
  *                       - TIM1: TIM1 base address index
  *                       - TIM2: TIM2 base address index
  * \param  prescaler    Prescaler value
  *                       This parameter between Min_Data=0 and Max_Data=65535
  */
static inline void TIM_setPrescaler (TIM_TypeDef *tim, uint32_t prescaler)
{
    WRITE_REG(tim->PSC.WORDVAL, prescaler);
}

/**
  * \brief  Get the prescaler value.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the prescaler value
  *                 This value between Min_Data=0 and Max_Data=65535
  */
static inline uint32_t TIM_getPrescaler (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->PSC.WORDVAL));
}

/**
  * \brief  Set the auto-reload value.
  * \note   The counter is blocked while the auto-reload value is null.
  * \param  tim           TIMx pointer to a TIM_TypeDef structure
  *                        - TIM1: TIM1 base address index
  *                        - TIM2: TIM2 base address index
  * \param  autoReload    AutoReload value
  *                        This parameter between Min_Data=0 and Max_Data=65535
  */
static inline void TIM_setAutoReload (TIM_TypeDef *tim, uint32_t autoReload)
{
    WRITE_REG(tim->ARR.WORDVAL, autoReload);
}

/**
  * \brief  Get the auto-reload value.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the auto-reload value
  *                 This value between Min_Data=0 and Max_Data=65535
  */
static inline uint32_t TIM_getAutoReload (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->ARR.WORDVAL));
}

/**
  * \brief  Set the repetition counter value.
  * \param  tim                  TIMx pointer to a TIM_TypeDef structure
  *                               - TIM1: TIM1 base address index
  *                               - TIM2: TIM2 base address index
  * \param  repetitionCounter    Repetition Counter
  *                               This parameter between Min_Data=0 and Max_Data=255
  */
static inline void TIM_setRepetitionCounter (TIM_TypeDef *tim, uint32_t repetitionCounter)
{
    WRITE_REG(tim->RCR.WORDVAL, repetitionCounter);
}

/**
  * \brief  Get the repetition counter value.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the repetition counter value
  *                 This value between Min_Data=0 and Max_Data=255
  */
static inline uint32_t TIM_getRepetitionCounter (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->RCR.WORDVAL));
}

/**
  * \brief  Enable the capture/compare control bits (CCxE, CCxNE and OCxM) preload.
  * \note   CCxE, CCxNE and OCxM bits are preloaded, after having been written,
  *         they are updated only when a commutation event (COM) occurs.
  * \note   This function acts only on channels that have a complementary output.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_enableCcPreload (TIM_TypeDef *tim)
{
    SET_BIT(tim->CR2.WORDVAL, TIM_CR2_CCPC_M);
}

/**
  * \brief  Disable the capture/compare control bits (CCxE, CCxNE and OCxM) preload.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_disableCcPreload (TIM_TypeDef *tim)
{
    CLEAR_BIT(tim->CR2.WORDVAL, TIM_CR2_CCPC_M);
}

/**
  * \brief  Get whether capture/compare control bits (CCxE, CCxNE and OCxM) preload is enabled.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the status of whether the capture/compare control bits (CCxE, CCxNE, OCxM) preload is enabled or not
  *                 - 0: The timer capture/compare control bits (CCxE, CCxNE and OCxM) preload is not enable.
  *                 - 1: The timer capture/compare control bits (CCxE, CCxNE and OCxM) preload is enable.
  */
static inline uint32_t TIM_getCcPreloadEnabledStatus (TIM_TypeDef *tim)
{
    return ((READ_BIT(tim->CR2.WORDVAL, TIM_CR2_CCPC_M) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Set the updated source of the capture/compare control bits (CCxE, CCxNE and OCxM).
  * \note   This function acts only on channels that have a complementary output.
  * \param  tim               TIMx pointer to a TIM_TypeDef structure
  *                            - TIM1: TIM1 base address index
  *                            - TIM2: TIM2 base address index
  * \param  ccUpdateSource    Capture/Compare update source
  *                            This parameter can be any value of @ref TIM_CCUPDATESOURCE
  */
static inline void TIM_setCcUpdateSource (TIM_TypeDef *tim, TIM_CcUpdateSource ccUpdateSource)
{
    MODIFY_REG(tim->CR2.WORDVAL, TIM_CR2_CCUS_M, ccUpdateSource);
}

/**
  * \brief  Get the actual updated source of the capture/compare control bits (CCxE, CCxNE and OCxM).
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned actual updated source
  *                 This value can be any value of @ref TIM_CCUPDATESOURCE
  */
static inline TIM_CcUpdateSource TIM_getCcUpdateSource (TIM_TypeDef *tim)
{
    return (TIM_CcUpdateSource)(READ_BIT(tim->CR2.WORDVAL, TIM_CR2_CCUS_M));
}

/**
  * \brief  Set the lock level to freeze the configuration of several capture/compare parameters.
  * \note   The LOCK bits can be written only once after the reset. Once the TIMx_BDTR register
  *         has been written, their content is frozen until the next reset.
  * \param  tim          TIMx pointer to a TIM_TypeDef structure
  *                       - TIM1: TIM1 base address index
  *                       - TIM2: TIM2 base address index
  * \param  lockLevel    Lock level
  *                       This parameter can be any value of @ref TIM_LOCKLEVEL
  */
static inline void TIM_setLockLevel (TIM_TypeDef *tim, TIM_LockLevel lockLevel)
{
    MODIFY_REG(tim->BDTR.WORDVAL, TIM_BDTR_LOCK_M, lockLevel);
}

/**
  * \brief  Get the actual lock level.
  * \note   The LOCK bits can be written only once after the reset. Once the TIMx_BDTR register
  *         has been written, their content is frozen until the next reset.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned actual lock level
  *                 This value can be any value of @ref TIM_LOCKLEVEL
  */
static inline TIM_LockLevel TIM_getLockLevel (TIM_TypeDef *tim)
{
    return (TIM_LockLevel)(READ_BIT(tim->BDTR.WORDVAL, TIM_BDTR_LOCK_M));
}

/**
  * \brief  Enable capture/compare channels.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  */
static inline void TIM_enableChannel (TIM_TypeDef *tim, TIM_Channel channel)
{
    SET_BIT(tim->CCER.WORDVAL, 0x1UL << SHIFT_TAB_CCER[channel]);
}

/**
  * \brief  Disable capture/compare channels.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  */
static inline void TIM_disableChannel (TIM_TypeDef *tim, TIM_Channel channel)
{
    CLEAR_BIT(tim->CCER.WORDVAL, 0x1UL << SHIFT_TAB_CCER[channel]);
}

/**
  * \brief  Enable capture/compare complementary channels.
  * \note   Channel 4 does not have a complementary output channel
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameters can only be selected in the following sections:
  *                     - TIM_CHANNEL_CH1
  *                     - TIM_CHANNEL_CH2
  *                     - TIM_CHANNEL_CH3
  */
static inline void TIM_enableChannelN (TIM_TypeDef *tim, TIM_Channel channel)
{
    SET_BIT(tim->CCER.WORDVAL, TIM_CCER_CC1NE_M << SHIFT_TAB_CCER[channel]);
}

/**
  * \brief  Disable capture/compare complementary channels.
  * \note   Channel 4 does not have a complementary output channel
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameters can only be selected in the following sections:
  *                     - TIM_CHANNEL_CH1
  *                     - TIM_CHANNEL_CH2
  *                     - TIM_CHANNEL_CH3
  */
static inline void TIM_disableChannelN (TIM_TypeDef *tim, TIM_Channel channel)
{
    CLEAR_BIT(tim->CCER.WORDVAL, TIM_CCER_CC1NE_M << SHIFT_TAB_CCER[channel]);
}

/**
  * \brief  Get whether channel is enabled.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter only can be a any value of @ref TIM_CHANNEL
  * \return Returned the status of whether the channel is enabled or not
  *                     - 0: The timer channel is not enable.
  *                     - 1: The timer channel is enable.
  */
static inline uint32_t TIM_getChannelEnabledStatus (TIM_TypeDef *tim, TIM_Channel channel)
{
    return ((READ_BIT(tim->CCER.WORDVAL, 0x1UL << SHIFT_TAB_CCER[channel]) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Get whether complementary channel is enabled.
  * \note   Channel 4 does not have a complementary output channel
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameters can only be selected in the following sections:
  *                     - TIM_CHANNEL_CH1
  *                     - TIM_CHANNEL_CH2
  *                     - TIM_CHANNEL_CH3
  * \return Returned the status of whether the channel is enabled or not
  *                     - 0: The timer channel is not enable.
  *                     - 1: The timer channel is enable.
  */
static inline uint32_t TIM_getChannelNEnabledStatus (TIM_TypeDef *tim, TIM_Channel channel)
{
    return ((READ_BIT(tim->CCER.WORDVAL, TIM_CCER_CC1NE_M << SHIFT_TAB_CCER[channel]) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Define the behavior of the output reference signal OCxREF from which OCx and OCxN (when relevant) are derived.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  * \param  ocMode     Output compare mode
  *                     This parameter can be any value of @ref TIM_OCMODE
  */
static inline void TIM_setOcMode (TIM_TypeDef *tim, TIM_Channel channel, TIM_OcMode ocMode)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    MODIFY_REG(*pReg,
               ((TIM_CCMR1_OC1M_M | TIM_CCMR1_CC1S_M) << SHIFT_TAB_CCMR[channel]),
               (uint32_t)ocMode << SHIFT_TAB_CCMR[channel]);
}

/**
  * \brief  Get the output compare mode of an output channel.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  * \return Returned the output compare mode of an output channel
  *                     This value can be any value of @ref TIM_OCMODE
  */
static inline TIM_OcMode TIM_getOcMode (TIM_TypeDef *tim, TIM_Channel channel)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    return (TIM_OcMode)(READ_BIT(*pReg, (TIM_CCMR1_OC1M_M << SHIFT_TAB_CCMR[channel])) >> SHIFT_TAB_CCMR[channel]);
}

/**
  * \brief  Set the polarity of an output channel and complementary channel.
  * \param  tim           TIMx pointer to a TIM_TypeDef structure
  *                        - TIM1: TIM1 base address index
  *                        - TIM2: TIM2 base address index
  * \param  channel       TIMx Channel
  *                        This parameter can be any value of @ref TIM_CHANNEL
  * \param  ocPolarity    Polarity of an output channel and complementary channel
  *                        This parameter can be any value of @ref TIM_OC_POLARITY
  *                        It is important to note that the parameters @ref TIM_OC_POLARITY_CHP_HIGH_CHN_LOW and 
  *                        @ref TIM_OC_POLARITY_CHP_LOW_CHN_LOW are not available on channel 4.
  */
static inline void TIM_setOcPolarity (TIM_TypeDef *tim, TIM_Channel channel, TIM_OcPolarity ocPolarity)
{
    MODIFY_REG(tim->CCER.WORDVAL, 
               (TIM_CCER_CC1P_M | TIM_CCER_CC1NP_M) << SHIFT_TAB_CCER[channel], 
               (uint32_t)ocPolarity << SHIFT_TAB_CCER[channel]);
}

/**
  * \brief  Get the polarity of an output channel and complementary channel.
  * \note   Channel 4 does not have a complementary output channel
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  * \return Returned a combination polarity of an output channel and complementary channel
  *                     This value can be any value of @ref TIM_OC_POLARITY
  */
static inline TIM_OcPolarity TIM_getOcPolarity (TIM_TypeDef *tim, TIM_Channel channel)
{
    return (TIM_OcPolarity)(READ_BIT(tim->CCER.WORDVAL, (TIM_CCER_CC1P_M | TIM_CCER_CC1NP_M) << SHIFT_TAB_CCER[channel]) 
                            >> SHIFT_TAB_CCER[channel]);
}

/**
  * \brief  Set the IDLE state of an output channel and complementary channel.
  * \param  tim            TIMx pointer to a TIM_TypeDef structure
  *                         - TIM1: TIM1 base address index
  *                         - TIM2: TIM2 base address index
  * \param  channel        TIMx Channel
  *                         This parameter can be any value of @ref TIM_CHANNEL
  * \param  ocIdleState    Idle state of an output channel and complementary channel
  *                         This parameter can be any value of @ref TIM_OC_IDLESTATE
  *                         It is important to note that the parameters @ref TIM_OC_IDLESTATE_CHP_LOW_CHN_HIGH and 
  *                         @ref TIM_OC_IDLESTATE_CHP_HIGH_CHN_HIGH are not available on channel 4.
  */
static inline void TIM_setOcIdleState (TIM_TypeDef *tim, TIM_Channel channel, TIM_OcIdleState ocIdleState)
{
    __IO uint32_t shift = (uint32_t)channel << 1UL;
    MODIFY_REG(tim->CR2.WORDVAL, (TIM_CR2_OIS1_M | TIM_CR2_OIS1N_M) << shift, (uint32_t)ocIdleState << shift);
}

/**
  * \brief  Get the IDLE state of an output channel and complementary channel.
  * \note   Channel 4 does not have a complementary output channel
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  * \return Returned the IDLE state of output channel and complementary channel
  *                     This value can be any value of @ref TIM_OC_IDLESTATE
  */
static inline TIM_OcIdleState TIM_getOcIdleState (TIM_TypeDef *tim, TIM_Channel channel)
{
    __IO uint32_t shift = (uint32_t)channel << 1UL;
    return (TIM_OcIdleState)(READ_BIT(tim->CR2.WORDVAL, (TIM_CR2_OIS1_M | TIM_CR2_OIS1N_M) << shift) >> shift);
}

/**
  * \brief  Enable fast mode for the output channel.
  * \note   Acts only if the channel is configured in PWM1 or PWM2 mode.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  */
static inline void TIM_enableOcFastMode (TIM_TypeDef *tim, TIM_Channel channel)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    SET_BIT(*pReg, (TIM_CCMR1_OC1FE_M << SHIFT_TAB_CCMR[channel]));
}

/**
  * \brief  Disable fast mode for the output channel.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  */
static inline void TIM_disableOcFastMode (TIM_TypeDef *tim, TIM_Channel channel)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    CLEAR_BIT(*pReg, (TIM_CCMR1_OC1FE_M << SHIFT_TAB_CCMR[channel]));
}

/**
  * \brief  Get whether fast mode is enabled for the output channel.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  * \return Returned the status of whether fast mode is enabled or not
  *                     - 0: The fast mode is not enable.
  *                     - 1: The fast mode is enable.
  */
static inline uint32_t TIM_getOcFastModeEnabledStatus (TIM_TypeDef *tim, TIM_Channel channel)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    return ((READ_BIT(*pReg, TIM_CCMR1_OC1FE_M << SHIFT_TAB_CCMR[channel]) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Enable compare register (TIMx_CCRx) preload for the output channel.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  */
static inline void TIM_enableOcPreload (TIM_TypeDef *tim, TIM_Channel channel)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    SET_BIT(*pReg, (TIM_CCMR1_OC1PE_M << SHIFT_TAB_CCMR[channel]));
}

/**
  * \brief  Disable compare register (TIMx_CCRx) preload for the output channel.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  */
static inline void TIM_disableOcPreload (TIM_TypeDef *tim, TIM_Channel channel)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    CLEAR_BIT(*pReg, (TIM_CCMR1_OC1PE_M << SHIFT_TAB_CCMR[channel]));
}

/**
  * \brief  Get whether compare register (TIMx_CCRx) preload is enabled for the output channel.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  * \return Returned the status of whether compare register (TIMx_CCRx) preload is enabled or not
  *                     - 0: The compare register (TIMx_CCRx) preload is not enable.
  *                     - 1: The compare register (TIMx_CCRx) preload is enable.
  */
static inline uint32_t TIM_getOcPreloadEnabledStatus (TIM_TypeDef *tim, TIM_Channel channel)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    return ((READ_BIT(*pReg, TIM_CCMR1_OC1PE_M << SHIFT_TAB_CCMR[channel]) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Enable clearing the output channel on an external event.
  * \note   This function can only be used in Output compare and PWM modes. It does not work in Forced mode.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  */
static inline void TIM_enableOcClear (TIM_TypeDef *tim, TIM_Channel channel)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    SET_BIT(*pReg, (TIM_CCMR1_OC1CE_M << SHIFT_TAB_CCMR[channel]));
}

/**
  * \brief  Disable clearing the output channel on an external event.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  */
static inline void TIM_disableOcClear (TIM_TypeDef *tim, TIM_Channel channel)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    CLEAR_BIT(*pReg, (TIM_CCMR1_OC1CE_M << SHIFT_TAB_CCMR[channel]));
}

/**
  * \brief  Get clearing the output channel on an external event is enabled for the output channel.
  * \note   This function enables clearing the output channel on an external event.
  * \note   This function can only be used in Output compare and PWM modes. It does not work in Forced mode.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  * \return Returned the status of whether OCxCE is enabled or not
  *                     - 0: The OCxCE (TIMx_CCMR.OCxCE) is not enable.
  *                     - 1: The OCxCE (TIMx_CCMR.OCxCE) is enable.
  */
static inline uint32_t TIM_getOcClearEnabledStatus (TIM_TypeDef *tim, TIM_Channel channel)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    return ((READ_BIT(*pReg, TIM_CCMR1_OC1CE_M << SHIFT_TAB_CCMR[channel]) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Set the dead-time delay (delay inserted between the rising edge of the OCxREF signal and the 
  *         rising edge of the Ocx and OCxN signals).
  * \param  tim         TIMx pointer to a TIM_TypeDef structure
  *                      - TIM1: TIM1 base address index
  *                      - TIM2: TIM2 base address index
  * \param  deadTime    Dead time
  *                       This parameter between Min_Data=0 and Max_Data=255
  */
static inline void TIM_setOcDeadTime (TIM_TypeDef *tim, uint32_t deadTime)
{
    MODIFY_REG(tim->BDTR.WORDVAL, TIM_BDTR_DTG_M, deadTime);
}

/**
  * \brief  Get the dead-time value.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the dead-time value
  *                 This value between Min_Data=0 and Max_Data=255
  */
static inline uint32_t TIM_getOcDeadTime (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->BDTR.WORDVAL));
}

/**
  * \brief  Set compare value for output channel 1A (TIMx_CCR1A).
  * \param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * \param  compareValue    Compare value
  *                          This parameter between Min_Data=0 and Max_Data=65535
  */
static inline void TIM_setOutputCompareCh1A (TIM_TypeDef *tim, uint32_t compareValue)
{
    WRITE_REG(tim->CCR1A.WORDVAL, compareValue);
}

/**
  * \brief  Set compare value for output channel 1B (TIMx_CCR1B).
  * \param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * \param  compareValue    Compare value
  *                          This parameter between Min_Data=0 and Max_Data=65535
  */
static inline void TIM_setOutputCompareCh1B (TIM_TypeDef *tim, uint32_t compareValue)
{
    WRITE_REG(tim->CCR1B.WORDVAL, compareValue);
}

/**
  * \brief  Set compare value for output channel 2A (TIMx_CCR2A).
  * \param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * \param  compareValue    Compare value
  *                          This parameter between Min_Data=0 and Max_Data=65535
  */
static inline void TIM_setOutputCompareCh2A (TIM_TypeDef *tim, uint32_t compareValue)
{
    WRITE_REG(tim->CCR2A.WORDVAL, compareValue);
}

/**
  * \brief  Set compare value for output channel 2B (TIMx_CCR2B).
  * \param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * \param  compareValue    Compare value
  *                          This parameter between Min_Data=0 and Max_Data=65535
  */
static inline void TIM_setOutputCompareCh2B (TIM_TypeDef *tim, uint32_t compareValue)
{
    WRITE_REG(tim->CCR2B.WORDVAL, compareValue);
}

/**
  * \brief  Set compare value for output channel 3A (TIMx_CCR3A).
  * \param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * \param  compareValue    Compare value
  *                          This parameter between Min_Data=0 and Max_Data=65535
  */
static inline void TIM_setOutputCompareCh3A (TIM_TypeDef *tim, uint32_t compareValue)
{
    WRITE_REG(tim->CCR3A.WORDVAL, compareValue);
}

/**
  * \brief  Set compare value for output channel 3B (TIMx_CCR3B).
  * \param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * \param  compareValue    Compare value
  *                          This parameter between Min_Data=0 and Max_Data=65535
  */
static inline void TIM_setOutputCompareCh3B (TIM_TypeDef *tim, uint32_t compareValue)
{
    WRITE_REG(tim->CCR3B.WORDVAL, compareValue);
}

/**
  * \brief  Set compare value for output channel 4A (TIMx_CCR4A).
  * \param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * \param  compareValue    Compare value
  *                          This parameter between Min_Data=0 and Max_Data=65535
  */
static inline void TIM_setOutputCompareCh4A (TIM_TypeDef *tim, uint32_t compareValue)
{
    WRITE_REG(tim->CCR4A.WORDVAL, compareValue);
}

/**
  * \brief  Set compare value for output channel 4B (TIMx_CCR4B).
  * \param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * \param  compareValue    Compare value
  *                          This parameter between Min_Data=0 and Max_Data=65535
  */
static inline void TIM_setOutputCompareCh4B (TIM_TypeDef *tim, uint32_t compareValue)
{
    WRITE_REG(tim->CCR4B.WORDVAL, compareValue);
}

/**
  * \brief  Get compare value (TIMx_CCR1A) set for output channel 1.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the compare value
  *                 This value between Min_Data=0 and Max_Data=65535
  */
static inline uint32_t TIM_getOutputCompareCh1A (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->CCR1A.WORDVAL));
}

/**
  * \brief  Get compare value (TIMx_CCR1B) set for output channel 1.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the compare value
  *                 This value between Min_Data=0 and Max_Data=65535
  */
static inline uint32_t TIM_getOutputCompareCh1B (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->CCR1B.WORDVAL));
}

/**
  * \brief  Get compare value (TIMx_CCR2A) set for output channel 2.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the compare value
  *                 This value between Min_Data=0 and Max_Data=65535
  */
static inline uint32_t TIM_getOutputCompareCh2A (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->CCR2A.WORDVAL));
}

/**
  * \brief  Get compare value (TIMx_CCR2B) set for output channel 2.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the compare value
  *                 This value between Min_Data=0 and Max_Data=65535
  */
static inline uint32_t TIM_getOutputCompareCh2B (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->CCR2B.WORDVAL));
}

/**
  * \brief  Get compare value (TIMx_CCR3A) set for output channel 3.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the compare value
  *                 This value between Min_Data=0 and Max_Data=65535
  */
static inline uint32_t TIM_getOutputCompareCh3A (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->CCR3A.WORDVAL));
}

/**
  * \brief  Get compare value (TIMx_CCR3B) set for output channel 3.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the compare value
  *                 This value between Min_Data=0 and Max_Data=65535
  */
static inline uint32_t TIM_getOutputCompareCh3B (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->CCR3B.WORDVAL));
}

/**
  * \brief  Get compare value (TIMx_CCR4A) set for  output channel 4.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the compare value
  *                 This value between Min_Data=0 and Max_Data=65535
  */
static inline uint32_t TIM_getOutputCompareCh4A (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->CCR4A.WORDVAL));
}

/**
  * \brief  Get compare value (TIMx_CCR4B) set for  output channel 4.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the compare value
  *                 This value between Min_Data=0 and Max_Data=65535
  */
static inline uint32_t TIM_getOutputCompareCh4B (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->CCR4B.WORDVAL));
}

/**
  * \brief  Set the active input of input channel.
  * \note   This function can only be called if the channel is closed
  * \param  tim            TIMx pointer to a TIM_TypeDef structure
  *                         - TIM1: TIM1 base address index
  *                         - TIM2: TIM2 base address index
  * \param  channel        TIMx Channel
  *                         This parameter can be any value of @ref TIM_CHANNEL
  * \param  IcActiveSel    Input channel active selection
  *                         This parameter can be any value of @ref TIM_IC_ACTIVESEL
  */
static inline void TIM_setIcActiveInput (TIM_TypeDef *tim, TIM_Channel channel, TIM_IcActiveSel icActiveSel)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    MODIFY_REG(*pReg, (TIM_CCMR1_CC1S_M << SHIFT_TAB_CCMR[channel]), (uint32_t)icActiveSel << SHIFT_TAB_CCMR[channel]);
}

/**
  * \brief  Get the current active input of input channel.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  * \return Returned the current active input
  *                     This value can be any value of @ref TIM_IC_ACTIVESEL
  */
static inline TIM_IcActiveSel TIM_getIcActiveInput (TIM_TypeDef *tim, TIM_Channel channel)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    return (TIM_IcActiveSel)(READ_BIT(*pReg, (TIM_CCMR1_CC1S_M << SHIFT_TAB_CCMR[channel])) >> SHIFT_TAB_CCMR[channel]);
}

/**
  * \brief  Set the prescaler of input channel.
  * \param  tim            TIMx pointer to a TIM_TypeDef structure
  *                         - TIM1: TIM1 base address index
  *                         - TIM2: TIM2 base address index
  * \param  channel        TIMx Channel
  *                         This parameter can be any value of @ref TIM_CHANNEL
  * \param  icPrescaler    Input configuration prescaler
  *                         This parameter can be any value of @ref TIM_IC_PSC
  */
static inline void TIM_setIcPrescaler (TIM_TypeDef *tim, TIM_Channel channel, TIM_IcPrescaler icPrescaler)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    MODIFY_REG(*pReg, (TIM_CCMR1_CAP_IC1PSC_M << SHIFT_TAB_CCMR[channel]), (uint32_t)icPrescaler << SHIFT_TAB_CCMR[channel]);
}

/**
  * \brief  Get the current prescaler value acting on an input channel.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  * \return Returned the current prescaler value acting on an input channel
  *                     This value can be any value of @ref TIM_IC_PSC
  */
static inline TIM_IcPrescaler TIM_getIcPrescaler (TIM_TypeDef *tim, TIM_Channel channel)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    return (TIM_IcPrescaler)(READ_BIT(*pReg, (TIM_CCMR1_CAP_IC1PSC_M << SHIFT_TAB_CCMR[channel])) >> SHIFT_TAB_CCMR[channel]);
}

/**
  * \brief  Set the input filter duration.
  * \param  tim         TIMx pointer to a TIM_TypeDef structure
  *                      - TIM1: TIM1 base address index
  *                      - TIM2: TIM2 base address index
  * \param  channel     TIMx Channel
  *                      This parameter can be any value of @ref TIM_CHANNEL
  * \param  icFilter    Input configuration filter
  *                      This parameter can be any value of @ref TIM_IC_FILTER
  */
static inline void TIM_setIcFilter (TIM_TypeDef *tim, TIM_Channel channel, TIM_IcFilter icFilter)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    MODIFY_REG(*pReg, ((TIM_CCMR1_CAP_IC1F_M) << SHIFT_TAB_CCMR[channel]), (uint32_t)icFilter << SHIFT_TAB_CCMR[channel]);
}

/**
  * \brief  Get the input filter duration.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  * \return Returned the input filter duration on an input channel
  *                     This value can be any value of @ref TIM_IC_FILTER
  */
static inline TIM_IcFilter TIM_getIcFilter (TIM_TypeDef *tim, TIM_Channel channel)
{
    __IO uint32_t *pReg;
    
    pReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    return (TIM_IcFilter)(READ_BIT(*pReg, ((TIM_CCMR1_CAP_IC1F_M) << SHIFT_TAB_CCMR[channel])) >> SHIFT_TAB_CCMR[channel]);
}

/**
  * \brief  Set the input channel polarity.
  * \param  tim           TIMx pointer to a TIM_TypeDef structure
  *                        - TIM1: TIM1 base address index
  *                        - TIM2: TIM2 base address index
  * \param  channel       TIMx Channel
  *                        This parameter can be any value of @ref TIM_CHANNEL
  * \param  icPolarity    Input configuration polarity
  *                        This parameter can be any value of @ref TIM_IC_POLARITY
  */
static inline void TIM_setIcPolarity (TIM_TypeDef *tim, TIM_Channel channel, TIM_IcPolarity icPolarity)
{
    MODIFY_REG(tim->CCER.WORDVAL, 
               TIM_CCER_CC1P_M << SHIFT_TAB_CCER[channel], 
               (((uint32_t)icPolarity >> 16UL) & TIM_CCER_CC1P_M) << SHIFT_TAB_CCER[channel]);
}

/**
  * \brief  Get the current input channel polarity.
  * \param  tim        TIMx pointer to a TIM_TypeDef structure
  *                     - TIM1: TIM1 base address index
  *                     - TIM2: TIM2 base address index
  * \param  channel    TIMx Channel
  *                     This parameter can be any value of @ref TIM_CHANNEL
  * \return Returned the current input channel polarity
  *                     This value can be any value of @ref TIM_IC_POLARITY
  */
static inline TIM_IcPolarity TIM_getIcPolarity (TIM_TypeDef *tim, TIM_Channel channel)
{
    return (TIM_IcPolarity)((READ_BIT(tim->CCER.WORDVAL, TIM_CCER_CC1P_M << SHIFT_TAB_CCER[channel])
                            >> SHIFT_TAB_CCER[channel]) << 16UL);
}

/**
  * \brief  Connect the TIMx_CH1, CH2 and CH3 pins to the TI1 input (XOR combination).
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_enableIcXORCombination (TIM_TypeDef *tim)
{
    SET_BIT(tim->CR2.WORDVAL, TIM_CR2_TI1S_M);
}

/**
  * \brief  Disconnect the TIMx_CH1, CH2 and CH3 pins  from the TI1 input.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_disableIcXORCombination (TIM_TypeDef *tim)
{
    CLEAR_BIT(tim->CR2.WORDVAL, TIM_CR2_TI1S_M);
}

/**
  * \brief  Get whether the TIMx_CH1, CH2 and CH3 pins are connectected to the TI1 input.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the status of whether TI1S is enabled or not
  *                 - 0: The TI1S (TIMx_CR2.TI1S) is not enable.
  *                 - 1: The TI1S (TIMx_CR2.TI1S) is enable.
  */
static inline uint32_t TIM_getIcXORCombinationStatus (TIM_TypeDef *tim)
{
    return ((READ_BIT(tim->CR2.WORDVAL, TIM_CR2_TI1S_M) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Get captured value for input channel 1.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the captured value
  *                 This value between Min_Data=0 and Max_Data=65535
  */
static inline uint32_t TIM_getInputCaptureCh1 (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->CCR1A.WORDVAL));
}

/**
  * \brief  Get captured value for input channel 2.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the captured value
  *                 This value between Min_Data=0 and Max_Data=65535
  */
static inline uint32_t TIM_getInputCaptureCh2 (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->CCR2A.WORDVAL));
}

/**
  * \brief  Get captured value for input channel 3.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the captured value
  *                 This value between Min_Data=0 and Max_Data=65535
  */
static inline uint32_t TIM_getInputCaptureCh3 (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->CCR3A.WORDVAL));
}

/**
  * \brief  Get captured value for input channel 4.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the captured value
  *                 This value between Min_Data=0 and Max_Data=65535
  */
static inline uint32_t TIM_getInputCaptureCh4 (TIM_TypeDef *tim)
{
    return (uint32_t)(READ_REG(tim->CCR4A.WORDVAL));
}

/**
  * \brief  Enable external clock mode 2.
  * \note   When external clock mode 2 is enabled the counter is clocked by any active edge on the ETRF signal.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_enableExternalClock (TIM_TypeDef *tim)
{
    SET_BIT(tim->SMCR.WORDVAL, TIM_SMCR_ECE_M);
}

/**
  * \brief  Disable external clock mode 2.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  */
static inline void TIM_disableExternalClock (TIM_TypeDef *tim)
{
    CLEAR_BIT(tim->SMCR.WORDVAL, TIM_SMCR_ECE_M);
}

/**
  * \brief  Get whether external clock mode 2 is enabled.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the status of whether external clock mode 2 is enabled or not
  *                 - 0: The external clock mode 2 is not enable.
  *                 - 1: The external clock mode 2 is enable.
  */
static inline uint32_t TIM_getExternalClockEnabledStatus (TIM_TypeDef *tim)
{
    return ((READ_BIT(tim->SMCR.WORDVAL, TIM_SMCR_ECE_M) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Set the clock source of the counter clock.
  * \note   when selected clock source is external clock mode 1, the timer input the external 
  *         clock is applied is selected by calling the @ref TIM_setTriggerInput() function. 
  * \param  tim            TIMx pointer to a TIM_TypeDef structure
  *                         - TIM1: TIM1 base address index
  *                         - TIM2: TIM2 base address index
  * \param  clockSource    Clock source of the counter clock
  *                         This parameter can be any value of @ref TIM_CLOCKSOURCE
  */
static inline void TIM_setClockSource (TIM_TypeDef *tim, TIM_ClockSource clockSource)
{
    MODIFY_REG(tim->SMCR.WORDVAL, TIM_SMCR_SMS_M | TIM_SMCR_ECE_M, clockSource);
}

/**
  * \brief  Get the current clock source of the counter clock.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the current clock source of the counter clock
  *                 This value can be any value of @ref TIM_CLOCKSOURCE
  */
static inline TIM_ClockSource TIM_getClockSource (TIM_TypeDef *tim)
{
    return (TIM_ClockSource)READ_BIT(tim->SMCR.WORDVAL, TIM_SMCR_SMS_M | TIM_SMCR_ECE_M);
}

/**
  * \brief  Set the encoder interface mode.
  * \param  tim            TIMx pointer to a TIM_TypeDef structure
  *                         - TIM1: TIM1 base address index
  *                         - TIM2: TIM2 base address index
  * \param  encoderMode    Encoder interface mode
  *                         This parameter can be any value of @ref TIM_ENCODERMODE
  */
static inline void TIM_setEncoderMode (TIM_TypeDef *tim, TIM_EncoderMode encoderMode)
{
    MODIFY_REG(tim->SMCR.WORDVAL, TIM_SMCR_SMS_M, encoderMode);
}

/**
  * \brief  Get the current encoder interface mode.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the current encoder interface mode
  *                 This value can be any value of @ref TIM_ENCODERMODE
  */
static inline TIM_EncoderMode TIM_getEncoderMode (TIM_TypeDef *tim)
{
    return (TIM_EncoderMode)READ_BIT(tim->SMCR.WORDVAL, TIM_SMCR_SMS_M);
}

/**
  * \brief  Set the trigger output (TRGO) used for timer synchronization.
  * \param  tim           TIMx pointer to a TIM_TypeDef structure
  *                        - TIM1: TIM1 base address index
  *                        - TIM2: TIM2 base address index
  * \param  triggerOut    Trigger output source
  *                        This parameter can be any value of @ref TIM_TRGO
  */
static inline void TIM_setTriggerOutput (TIM_TypeDef *tim, TIM_TriggerOut triggerOut)
{
    MODIFY_REG(tim->CR2.WORDVAL, TIM_CR2_MMS_M, triggerOut);
}

/**
  * \brief  Get the current trigger output (TRGO) used for timer synchronization.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the current trigger output (TRGO) used for timer synchronization
  *                 This value can be any value of @ref TIM_TRGO
  */
static inline TIM_TriggerOut TIM_getTriggerOutput (TIM_TypeDef *tim)
{
    return (TIM_TriggerOut)READ_BIT(tim->CR2.WORDVAL, TIM_CR2_MMS_M);
}

/**
  * \brief  Set the synchronization mode of a slave timer.
  * \param  tim          TIMx pointer to a TIM_TypeDef structure
  *                       - TIM1: TIM1 base address index
  *                       - TIM2: TIM2 base address index
  * \param  slaveMode    TIMx Slave mode
  *                       This parameter can be any value of @ref TIM_SLAVEMODE
  */
static inline void TIM_setSlaveMode (TIM_TypeDef *tim, TIM_SlaveMode slaveMode)
{
    MODIFY_REG(tim->SMCR.WORDVAL, TIM_SMCR_SMS_M, slaveMode);
}

/**
  * \brief  Get the current synchronization mode of a slave timer.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the current synchronization mode of a slave timer
  *                 This value can be any value of @ref TIM_SLAVEMODE
  */
static inline TIM_SlaveMode TIM_getSlaveMode (TIM_TypeDef *tim)
{
    return (TIM_SlaveMode)READ_BIT(tim->SMCR.WORDVAL, TIM_SMCR_SMS_M);
}

/**
  * \brief  Set the selects the trigger input to be used to synchronize the counter.
  * \note   The trigger input can only be configured when the slave mode (SMS) is 0.
  * \param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * \param  triggerInput    TIMx trigger input source
  *                          This parameter can be any value of @ref TIM_TS
  */
static inline void TIM_setTriggerInput (TIM_TypeDef *tim, TIM_TriggerSel triggerInput)
{
    MODIFY_REG(tim->SMCR.WORDVAL, TIM_SMCR_TS_M, triggerInput);
}

/**
  * \brief  Get the current selects the trigger input to be used to synchronize the counter.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the current selects the trigger input to be used to synchronize the counter
  *                 This value can be any value of @ref TIM_TS
  */
static inline TIM_TriggerSel TIM_getTriggerInput (TIM_TypeDef *tim)
{
    return (TIM_TriggerSel)READ_BIT(tim->SMCR.WORDVAL, TIM_SMCR_TS_M);
}

/**
  * \brief  Enable the Master/Slave mode.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_enableMasterSlaveMode (TIM_TypeDef *tim)
{
    SET_BIT(tim->SMCR.WORDVAL, TIM_SMCR_MSM_M);
}

/**
  * \brief  Disable the Master/Slave mode.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_disableMasterSlaveMode (TIM_TypeDef *tim)
{
    CLEAR_BIT(tim->SMCR.WORDVAL, TIM_SMCR_MSM_M);
}

/**
  * \brief  Get whether the Master/Slave mode is enabled.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the status of whether the Master/Slave mode is enabled or not
  *                 - 0: The Master/Slave mode is not enable.
  *                 - 1: The Master/Slave mode is enable.
  */
static inline uint32_t TIM_getMasterSlaveModeEnabledStatus (TIM_TypeDef *tim)
{
    return ((READ_BIT(tim->SMCR.WORDVAL, TIM_SMCR_MSM_M) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Enable the break function.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_enableBreak (TIM_TypeDef *tim)
{
    __IO uint32_t tmpreg;

    SET_BIT(tim->BDTR.WORDVAL, TIM_BDTR_BKE_M);
    /* Note: Any write operation to this bit takes a delay of 1 APB clock cycle to become effective. */
    tmpreg = READ_REG(tim->BDTR.WORDVAL);
    (void)(tmpreg);
}

/**
  * \brief  Disable the break function.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_disableBreak (TIM_TypeDef *tim)
{
    __IO uint32_t tmpreg;

    CLEAR_BIT(tim->BDTR.WORDVAL, TIM_BDTR_BKE_M);
    /* Note: Any write operation to this bit takes a delay of 1 APB clock cycle to become effective. */
    tmpreg = READ_REG(tim->BDTR.WORDVAL);
    (void)(tmpreg);
}

/**
  * \brief  Get whether the the break is enabled.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the status of whether the break is enabled or not
  *                 - 0: The break is not enable.
  *                 - 1: The break is enable.
  */
static inline uint32_t TIM_getBreakEnabledStatus (TIM_TypeDef *tim)
{
    return ((READ_BIT(tim->BDTR.WORDVAL, TIM_BDTR_BKE_M) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Set the break input polarity.
  * \param  tim              TIMx pointer to a TIM_TypeDef structure
  *                           - TIM1: TIM1 base address index
  *                           - TIM2: TIM2 base address index
  * \param  breakPolarity    Break polarity
  *                           This parameter can be any value of @ref TIM_BREAK_POLARITY
  */
static inline void TIM_setBreakPolarity (TIM_TypeDef *tim, TIM_BreakPolarity breakPolarity)
{
    __IO uint32_t tmpreg;

    MODIFY_REG(tim->BDTR.WORDVAL, TIM_BDTR_BKP_M, breakPolarity);
    /* Note: Any write operation to BKP bit takes a delay of 1 APB clock cycle to become effective. */
    tmpreg = READ_REG(tim->BDTR.WORDVAL);
    (void)(tmpreg);
}

/**
  * \brief  Get the current break input polarity.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the current break input polarity
  *                 This value can be any value of @ref TIM_BREAK_POLARITY
  */
static inline TIM_BreakPolarity TIM_getBreakPolarity (TIM_TypeDef *tim)
{
    return (TIM_BreakPolarity)READ_BIT(tim->BDTR.WORDVAL, TIM_BDTR_BKP_M);
}

/**
  * \brief  Select the outputs off state (enabled v.s. disabled) in Idle and Run modes.
  * \param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * \param  offStateIdle    Off-state selection for idle mode.
  *                          This parameter can be any value of @ref TIM_OSSI
  * \param  offStateRun     Off-state selection for run mode.
  *                          This parameter can be any value of @ref TIM_OSSR
  */
static inline void TIM_setOffStates (TIM_TypeDef *tim, TIM_Ossi offStateIdle, TIM_Ossr offStateRun)
{
    MODIFY_REG(tim->BDTR.WORDVAL, TIM_BDTR_OSSI_M | TIM_BDTR_OSSR_M, (uint32_t)offStateIdle | (uint32_t)offStateRun);
}

/**
  * \brief  Enable automatic output
  * \note   MOE can be set by software or automatically when a break input is no active.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_enableAutomaticOutput (TIM_TypeDef *tim)
{
    SET_BIT(tim->BDTR.WORDVAL, TIM_BDTR_AOE_M);
}

/**
  * \brief  Disable automatic output (MOE can be set only by software).
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_disableAutomaticOutput (TIM_TypeDef *tim)
{
    CLEAR_BIT(tim->BDTR.WORDVAL, TIM_BDTR_AOE_M);
}

/**
  * \brief  Get whether automatic output is enabled.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the status of whether the Master/Slave mode is enabled or not
  *                 - 0: The automatic output is not enable.
  *                 - 1: The automatic output is enable.
  */
static inline uint32_t TIM_getAutomaticOutputEnabledStatus (TIM_TypeDef *tim)
{
    return ((READ_BIT(tim->BDTR.WORDVAL, TIM_BDTR_AOE_M) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Enable the main output (set the MOE bit in TIMx_BDTR register).
  * \note   The MOE bit in TIMx_BDTR register allows to enable /disable the outputs by
  *         software and is reset in case of break event
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_enableMainOutput (TIM_TypeDef *tim)
{
    SET_BIT(tim->BDTR.WORDVAL, TIM_BDTR_MOE_M);
}

/**
  * \brief  Disable the main output (reset the MOE bit in TIMx_BDTR register).
  * \note   The MOE bit in TIMx_BDTR register allows to enable /disable the outputs by
  *         software and is reset in case of break or break2 event.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  */
static inline void TIM_disableMainOutput (TIM_TypeDef *tim)
{
    CLEAR_BIT(tim->BDTR.WORDVAL, TIM_BDTR_MOE_M);
}

/**
  * \brief  Get whether main output are enabled.
  * \param  tim    TIMx pointer to a TIM_TypeDef structure
  *                 - TIM1: TIM1 base address index
  *                 - TIM2: TIM2 base address index
  * \return Returned the status of whether main output is enabled or not
  *                 - 0: The main output is not enable.
  *                 - 1: The main output is enable.
  */
static inline uint32_t TIM_getMainOutputEnabledStatus (TIM_TypeDef *tim)
{
    return ((READ_BIT(tim->BDTR.WORDVAL, TIM_BDTR_MOE_M) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Configures the timer DMA burst feature.
  * \param  tim                 TIMx pointer to a TIM_TypeDef structure
  *                              - TIM1: TIM1 base address index
  *                              - TIM2: TIM2 base address index
  * \param  dmaBurstBaseAddr    DMA burst base address
  *                              This parameter can be any value of @ref TIM_DMABURST_BASEADDR
  * \param  dmaBurstLength      DMA burst length
  *                              This parameter can be any value of @ref TIM_DMABURST_LENGTH
  */
static inline void TIM_configDmaBurst (TIM_TypeDef *tim, TIM_DmaBurstAddr dmaBurstBaseAddr, TIM_DmaBurstLength dmaBurstLength)
{
    MODIFY_REG(tim->DCR.WORDVAL, TIM_DCR_DBL_M | TIM_DCR_DBA_M, (uint32_t)dmaBurstBaseAddr | (uint32_t)dmaBurstLength);
}

/**
  * \brief  Clear the specified interrupt flags.
  * \param  tim      TIMx pointer to a TIM_TypeDef structure
  *                   - TIM1: TIM1 base address index
  *                   - TIM2: TIM2 base address index
  * \param  flags    Interrupt flags, the input parameters can be combined
  *                   This parameter can be any value of @ref TIM_FLAG
  */
static inline void TIM_clearFlags (TIM_TypeDef *tim, uint32_t flags)
{
    WRITE_REG(tim->SR.WORDVAL, ~(flags));
}

/**
  * \brief  Get whether the specified interrupt flags.
  * \param  tim      TIMx pointer to a TIM_TypeDef structure
  *                   - TIM1: TIM1 base address index
  *                   - TIM2: TIM2 base address index
  * \param  flags    Interrupt flags
  *                   This parameter can be any value of @ref TIM_FLAG or a combination of elements within it
  * \return Returned Interrupt flags
  *                   This value is any value in the @ref TIM_FLAG or a combination of elements within it
  */
static inline uint32_t TIM_getFlags (TIM_TypeDef *tim, uint32_t flags)
{
    return READ_BIT(tim->SR.WORDVAL, flags);
}

/**
  * \brief  Enable specified interrupts.
  * \param  tim           TIMx pointer to a TIM_TypeDef structure
  *                        - TIM1: TIM1 base address index
  *                        - TIM2: TIM2 base address index
  * \param  interrupts    Interrupt source
  *                        This parameter can be any value of @ref TIM_IT or a combination of elements within it
  */
static inline void TIM_enableInterruptSource (TIM_TypeDef *tim, uint32_t interrupts)
{
    SET_BIT(tim->DIER.WORDVAL, ((interrupts) & 0xFFUL));
}

/**
  * \brief  Disable specified interrupts.
  * \param  tim           TIMx pointer to a TIM_TypeDef structure
  *                        - TIM1: TIM1 base address index
  *                        - TIM2: TIM2 base address index
  * \param  interrupts    Interrupt source
  *                        This parameter can be any value of @ref TIM_IT or a combination of elements within it
  */
static inline void TIM_disableInterruptSource (TIM_TypeDef *tim, uint32_t interrupts)
{
    CLEAR_BIT(tim->DIER.WORDVAL, ((interrupts) & 0xFFUL));
}

/**
  * \brief  Get whether the specified interrupts is enabled.
  * \param  tim           TIMx pointer to a TIM_TypeDef structure
  *                        - TIM1: TIM1 base address index
  *                        - TIM2: TIM2 base address index
  * \param  interrupts    Interrupt source
  *                        This parameter can be any value of @ref TIM_IT or a combination of elements within it
  * \return Returned Interrupt source
  *                        This value is any value in the @ref TIM_IT or a combination of elements within it
  */
static inline uint32_t TIM_getInterruptSource (TIM_TypeDef *tim, uint32_t interrupts)
{
    return READ_BIT(tim->DIER.WORDVAL, ((interrupts) & 0xFFUL));
}

/**
  * \brief  Enable specified dma request source.
  * \param  tim          TIMx pointer to a TIM_TypeDef structure
  *                       - TIM1: TIM1 base address index
  *                       - TIM2: TIM2 base address index
  * \param  dmaReqSrc    DMA request source
  *                       This parameter can be any value of @ref TIM_DMA or a combination of elements within it
  */
static inline void TIM_enableDmaRequestSource (TIM_TypeDef *tim, uint32_t dmaReqSrc)
{
    SET_BIT(tim->DIER.WORDVAL, ((dmaReqSrc) & 0xFF00UL));
}

/**
  * \brief  Disable specified dma request source.
  * \param  tim          TIMx pointer to a TIM_TypeDef structure
  *                       - TIM1: TIM1 base address index
  *                       - TIM2: TIM2 base address index
  * \param  dmaReqSrc    DMA request source
  *                       This parameter can be any value of @ref TIM_DMA or a combination of elements within it
  */
static inline void TIM_disableDmaRequestSource (TIM_TypeDef *tim, uint32_t dmaReqSrc)
{
    CLEAR_BIT(tim->DIER.WORDVAL, ((dmaReqSrc) & 0xFF00UL));
}

/**
  * \brief  Get whether the specified dma request source is enabled.
  * \param  tim          TIMx pointer to a TIM_TypeDef structure
  *                       - TIM1: TIM1 base address index
  *                       - TIM2: TIM2 base address index
  * \param  dmaReqSrc    DMA request source
  *                       This parameter can be any value of @ref TIM_DMA or a combination of elements within it
  * \return Returned DMA request source
  *                       This value is any value in the @ref TIM_DMA or a combination of elements within it
  */
static inline uint32_t TIM_getDmaRequestSource (TIM_TypeDef *tim, uint32_t dmaReqSrc)
{
    return READ_BIT(tim->DIER.WORDVAL, ((dmaReqSrc) & 0xFF00UL));
}

/**
  * \brief  Enable specified adc trigger source.
  * \param  tim          TIMx pointer to a TIM_TypeDef structure
  *                       - TIM1: TIM1 base address index
  *                       - TIM2: TIM2 base address index
  * \param  adcTrigSrc   ADC trigger source
  *                       This parameter can be any value of @ref TIM_ADCTRIG or a combination of elements within it
  */
static inline void TIM_enableAdcTriggerSource (TIM_TypeDef *tim, uint32_t adcTrigSrc)
{
    SET_BIT(tim->DIER.WORDVAL, ((adcTrigSrc) & 0xFF0000UL));
}

/**
  * \brief  Disable specified adc trigger source.
  * \param  tim          TIMx pointer to a TIM_TypeDef structure
  *                       - TIM1: TIM1 base address index
  *                       - TIM2: TIM2 base address index
  * \param  adcTrigSrc   ADC trigger source
  *                       This parameter can be any value of @ref TIM_ADCTRIG or a combination of elements within it
  */
static inline void TIM_disableAdcTriggerSource (TIM_TypeDef *tim, uint32_t adcTrigSrc)
{
    CLEAR_BIT(tim->DIER.WORDVAL, ((adcTrigSrc) & 0xFF0000UL));
}

/**
  * \brief  Get whether the specified adc trigger source is enabled.
  * \param  tim           TIMx pointer to a TIM_TypeDef structure
  *                        - TIM1: TIM1 base address index
  *                        - TIM2: TIM2 base address index
  * \param  adcTrigSrc    ADC trigger source
  *                        This parameter can be any value of @ref TIM_ADCTRIG or a combination of elements within it
  * \return Returned ADC trigger source
  *                        This value is any value in the @ref TIM_ADCTRIG or a combination of elements within it
  */
static inline uint32_t TIM_getAdcTriggerSource (TIM_TypeDef *tim, uint32_t adcTrigSrc)
{
    return READ_BIT(tim->DIER.WORDVAL, ((adcTrigSrc) & 0xFF0000UL));
}

/**
  * \brief  Generate an specified event.
  * \param  tim       TIMx pointer to a TIM_TypeDef structure
  *                    - TIM1: TIM1 base address index
  *                    - TIM2: TIM2 base address index
  * \param  events    Event generate source
  *                    This parameter can be any value of @ref TIM_EVENTSOURCE or a combination of elements within it
  */
static inline void TIM_generateEvent (TIM_TypeDef *tim, uint32_t events)
{
    SET_BIT(tim->EGR.WORDVAL, events);
}

/**
  * \brief  Configure the TIMx time base unit.
  * \param  tim           TIMx pointer to a TIM_TypeDef structure
  *                        - TIM1: TIM1 base address index
  *                        - TIM2: TIM2 base address index
  * \param  prescaler     The prescaler value used to divide the TIMx clock
  *                        This parameter can be a number between Min_Data=0x0000 and Max_Data=0xFFFF.
  *                        This feature can be modified afterwards using function @ref TIM_setPrescaler().
  * \param  autoReload    The auto reload value to be loaded into the ARR Register at the next update event
  *                        This parameter can be a number between Min_Data=0x0000 and Max_Data=0xFFFF.
  *                        This feature can be modified afterwards using unitary function @ref TIM_setAutoReload().
  * \param  configure     Configurable combination
  *                        All parameters can be or together, and the parameters include the following sections:
  *                        @ref TIM_PWMMODE, Specifies the PWM comparison mode, choosing single-point comparison or 
  *                             double-point comparison. 
  *                             This feature can be modified afterwards using unitary function 
  *                             @ref TIM_enablePwm2PointMode() or @ref TIM_disablePwm2PointMode()
  *                        @ref TIM_CLOCKDIVISION, Specifies the clock division.
  *                             This feature can be modified afterwards using unitary function @ref TIM_setClockDivision()
  *                        @ref TIM_AUTORELOADPRELOAD, Specifies whether to enable Auto-reload preload function.
  *                             This feature can be modified afterwards using unitary function 
  *                             @ref TIM_enableAutoReloadPreload() or @ref disableAutoReloadPreload()
  *                        @ref TIM_COUNTERMODE, Specifies the counting mode, which includes the counting direction 
  *                             and alignment mode. 
  *                             This feature can be modified afterwards using unitary function @ref TIM_setCounterMode()
  *                        @ref TIM_ONEPULSEMODE, Specifies single mode or repetitive mode.
  *                             This feature can be modified afterwards using unitary function @ref TIM_setOnePulseMode()
  * \note   In the end you need to call the TIM_enableCounter() function to start the TIM.
  * \note   When the value of the auto-reload is empty, the TIM does not work.
  */
extern void TIM_configTimeBase (TIM_TypeDef *tim, uint16_t prescaler, uint16_t autoReload, uint32_t configure);

/**
  * \brief  Configure the TIMx output channel.
  * \param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * \param  channel         TIMx Channel
  *                          This parameter can be any value of @ref TIM_CHANNEL
  * \param  compareValue    Combination compare values
  *                          The compare value of the channel is placed in the lower 16 bits, 
  *                          and if a two-point compare is required, the value of CCRxB is placed in the upper 16 bits.
  *                          eg: if compareValue = 0x5555AAAAU, means CCRxA = 0xAAAAU and CCRxB = 0x5555U.
  * \param  configure       Output configuration combination
  *                          All parameters can be or together, and the parameters include the following sections:
  *                          @ref TIM_OCMODE, Specifies the output mode.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setOcMode()
  *                          @ref TIM_OC_ACTIVE, Specifies the TIM Output Compare state.
  *                               This feature can be modified afterwards using unitary functions 
  *                               @ref TIM_enableChannel() or @ref TIM_disableChannel()
  *                          @ref TIM_OC_POLARITY, Specifies the output polarity.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setOcPolarity()
  *                          @ref TIM_OC_IDLESTATE, Specifies the TIM Output Compare pin state during Idle state.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setOcIdleState()
  * \note   Before this function is called, you need to use the TIM_configTimeBase() function to configure the basic 
  *         parameters of TIM, in the end you need to call the TIM_enableCounter() function to start the TIM.
  * \note   If you need to output PWM to the pins, you also need to use TIM_enableMainOutput().
  */
extern void TIM_configOutputChannel (TIM_TypeDef *tim, TIM_Channel channel, uint32_t compareValue, uint32_t configure);

/**
  * \brief  Configure the TIMx input channel.
  * \param  tim          TIMx pointer to a TIM_TypeDef structure
  *                       - TIM1: TIM1 base address index
  *                       - TIM2: TIM2 base address index
  * \param  channel      TIMx Channel
  *                       This parameter can be any value of @ref TIM_CHANNEL
  * \param  configure    Input configuration combination
  *                       All parameters can be or together, and the parameters include the following sections:
  *                       @ref TIM_IC_ACTIVE, Specifies the input.
  *                            This feature can be modified afterwards using unitary function @ref TIM_setIcActiveInput()
  *                       @ref TIM_IC_PSC, Specifies the Input Capture Prescaler.
  *                            This feature can be modified afterwards using unitary function @ref TIM_setIcPrescaler()
  *                       @ref TIM_IC_FILTER, Specifies the input capture filter.
  *                            This feature can be modified afterwards using unitary function @ref TIM_setIcFilter()
  *                       @ref TIM_IC_POLARITY, Specifies the active edge of the input signal.
  *                            This feature can be modified afterwards using unitary function @ref TIM_setIcPolarity()
  * \note   Before this function is called, you need to use the TIM_configTimeBase() function to configure the basic 
  *         parameters of TIM, in the end you need to call the TIM_enableCounter() function to start the TIM.
  */
extern void TIM_configInputChannel (TIM_TypeDef *tim, TIM_Channel channel, uint32_t configure);

/**
  * \brief  Configure the encoder interface of the timer instance.
  * \param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * \param  encoderMode     Specifies the encoder resolution
  *                          This parameter can be any value of @ref TIM_ENCODERMODE
  *                          This feature can be modified afterwards using unitary function @ref TIM_setEncoderMode()
  * \param  ic1Configure    Encode input ch1 configuration combination
  *                          All parameters can be or together, and the parameters include the following sections:
  *                          @ref TIM_IC_ACTIVE, Specifies the input.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setIcActiveInput()
  *                          @ref TIM_IC_PSC, Specifies the Input Capture Prescaler.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setIcPrescaler()
  *                          @ref TIM_IC_FILTER, Specifies the input capture filter.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setIcFilter()
  *                          @ref TIM_IC_POLARITY, Specifies the active edge of the input signal.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setIcPolarity()
  * \param  ic2Configure    Encode input ch2 configuration combination
  *                          All parameters can be or together, and the parameters include the following sections:
  *                          @ref TIM_IC_ACTIVE, Specifies the input.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setIcActiveInput()
  *                          @ref TIM_IC_PSC, Specifies the Input Capture Prescaler.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setIcPrescaler()
  *                          @ref TIM_IC_FILTER, Specifies the input capture filter.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setIcFilter()
  *                          @ref TIM_IC_POLARITY, Specifies the active edge of the input signal.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setIcPolarity()
  * \note   Before this function is called, you need to use the TIM_configTimeBase() function to configure the basic 
  *         parameters of TIM, in the end you need to call the TIM_enableCounter() function to start the TIM.
  */
extern void TIM_configEncoder (TIM_TypeDef *tim, TIM_EncoderMode encoderMode, uint32_t ic1Configure, uint32_t ic2Configure);

/**
  * \brief  Configure the Hall sensor interface of the timer instance.
  * \note   TIMx CH1, CH2 and CH3 inputs connected through a XOR to the TI1 input channel.
  * \note   TIMx slave mode controller is configured in reset mode. Selected internal trigger is TI1F_ED.
  * \note   Channel 1 is configured as input, IC1 is mapped on TRC.
  * \note   Captured value stored in TIMx_CCR1A correspond to the time elapsed between 2 changes on the inputs. 
  *         It gives information about motor speed.
  * \note   Channel 4 is configured in output PWM 2 mode.
  * \note   Compare value stored in TIMx_CCR4A corresponds to the commutation delay.
  * \note   OC4REF is selected as trigger output on TRGO.
  * \param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * \param  ic1Prescaler    Specifies the TI1 input prescaler value
  *                          This parameter can be any value of @ref TIM_IC_PSC
  *                          This feature can be modified afterwards using unitary function @ref TIM_setIcPrescaler()
  * \param  ic1Filter       Specifies the TI1 input filter
  *                          This parameter can be any value of @ref TIM_IC_FILTER
  *                          This feature can be modified afterwards using unitary function @ref TIM_setIcFilter()
  * \param  comDelay        Specifies the compare value to be loaded into the CCR4A Register
  *                          This parameter can be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF.
  *                          This feature can be modified afterwards using unitary function @ref TIM_setOcCompareCh2A()
  * \note   Before this function is called, you need to use the TIM_configTimeBase() function to configure the basic 
  *         parameters of TIM, in the end you need to call the TIM_enableCounter() function to start the TIM.
  * \note   If you need to output PWM to the pins, you also need to use TIM_enableMainOutput().
  */
extern void TIM_configHallSensor (TIM_TypeDef *tim, TIM_IcPrescaler ic1Prescaler, TIM_IcFilter ic1Filter, uint32_t comDelay);

/**
  * \brief  Configure the Break and Dead Time feature of the timer instance.
  * \note   As the bits AOE, BKP, BKE, OSSR, OSSI and DTG[7:0] can be write-locked depending on the LOCK configuration, 
  *         it can be necessary to configure all of them during the first write access to the TIMx_BDTR register.
  * \param  tim          TIMx pointer to a TIM_TypeDef structure
  *                       - TIM1: TIM1 base address index
  *                       - TIM2: TIM2 base address index
  * \param  deadTime     Specifies the delay time between the switching-off and the switching-on of the outputs
  *                       This parameter can be a number between Min_Data = 0x00 and Max_Data = 0xFF.
  *                       This feature can be modified afterwards using unitary function @ref TIM_setOcDeadTime()
  * \param  configure    Break configuration combination
  *                       All parameters can be or together, and the parameters include the following sections:
  *                       @ref TIM_OSSR, Specifies the Off-State selection used in Run mode.
  *                            This feature can be modified afterwards using unitary function @ref TIM_setOffStates()
  *                       @ref TIM_OSSI, Specifies the Off-State used in Idle state.
  *                            This feature can be modified afterwards using unitary function @ref TIM_setOffStates()
  *                       @ref TIM_LOCKLEVEL, Specifies the LOCK level parameters.
  *                            The LOCK bits can be written only once after the reset. Once the TIMx_BDTR 
  *                            register has been written, their content is frozen until the next reset.
  *                       @ref TIM_BREAK_POLARITY, Specifies the TIM Break Input pin polarity.
  *                            This feature can be modified afterwards using unitary function @ref TIM_setBreakPolarity()
  *                       @ref TIM_BREAK, Specifies whether the TIM Break input is enabled or not.
  *                            This feature can be modified afterwards using unitary functions @ref TIM_enableBreak() 
  *                            or @ref TIM_disableBreak()
  *                       @ref TIM_AUTOMATICOUTPUT, Specifies whether the TIM Automatic Output feature is enabled or not.
  *                            This feature can be modified afterwards using unitary functions 
  *                            @ref TIM_enableAutomaticOutput() or @ref TIM_disableAutomaticOutput()
  */
extern void TIM_configBreakDeadTime (TIM_TypeDef *tim, uint8_t deadTime, uint32_t configure);

/**
  * \brief  Configure the external trigger (ETR) input.
  * \param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * \param  etrPolarity     External trigger polarity
  *                          This parameter can be any value of @ref TIM_ETR_POLARITY
  * \param  etrPrescaler    External trigger perscaler
  *                          This parameter can be any value of @ref TIM_ETR_PRESCALER
  * \param  etrFilter       External trigger filter
  *                          This parameter can be any value of @ref TIM_ETR_FILTER
  */
extern void TIM_configEtr (TIM_TypeDef *tim, TIM_EtrPolarity etrPolarity, 
                           TIM_EtrPrescaler etrPrescaler, TIM_EtrFilter etrFilter);


#ifdef __cplusplus
}
#endif


#endif /* __TIM_H__ */
