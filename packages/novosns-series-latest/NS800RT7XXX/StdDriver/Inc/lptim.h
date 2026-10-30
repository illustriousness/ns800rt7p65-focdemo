/**
  * @file       lptim.h
  * @author     Haven-X
  * @brief      Header file for NS800RT7xxx lptim module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __LPTIM_H__
#define __LPTIM_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_lptim.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup LPTIM_EXPORTED_TYPES LPTIM Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'LPTIM' module.
  */

/** @defgroup LPTIM_PULSESOURCE LPTIM Pulse Input Source
  * @{
  * @brief  Macro definitions about LPTIM pulse input source.
  */
typedef enum {
    LPTIM_PULSESOURCE_CMPSS1OUT = 0U,                          /*!< CMPSS1_OUT as input source for the pulse counter mode */
    LPTIM_PULSESOURCE_CMPSS2OUT = (0x1U << LPTIM_CR_TPS_S),    /*!< CMPSS2_OUT as input source for the pulse counter mode */
    LPTIM_PULSESOURCE_CMPSS3OUT = (0x2U << LPTIM_CR_TPS_S),    /*!< CMPSS3_OUT as input source for the pulse counter mode */
    LPTIM_PULSESOURCE_GPIOALT   = (0x3U << LPTIM_CR_TPS_S)     /*!< GPIO(LPTIM_IN) as input source for the pulse counter mode */
} LPTIM_PulseSource;

/**
  * @}
  */

/** @defgroup LPTIM_PULSEPOL LPTIM Pulse Polarity
  * @{
  * @brief  Macro definitions about LPTIM pulse polarity.
  */
typedef enum {
    LPTIM_PULSEPOLARITY_HIGH = 0U,               /*!< Pulse input is active high */
    LPTIM_PULSEPOLARITY_LOW  = LPTIM_CR_TPP_M    /*!< Pulse input is active low */
} LPTIM_PulsePolarity;

/**
  * @}
  */

/** @defgroup LPTIM_COUNTERMODE LPTIM Counter Mode
  * @{
  * @brief  Macro definitions about LPTIM counter mode.
  */
typedef enum {
    LPTIM_COUNTERMODE_CMPRESET = 0U,               /*!< Timer periodicity counts from 0 to CMR, Reset the count
                                                        value when counting to CMR */
    LPTIM_COUNTERMODE_FREE     = LPTIM_CR_TFC_M    /*!< Timer periodicity counts from 0 to 0xFFFF, Resets the count
                                                        value when the count reaches 0xFFFF */

} LPTIM_CounterMode;

/**
  * @}
  */

/** @defgroup LPTIM_WORKMODE LPTIM Work Mode
  * @{
  * @brief  Macro definitions about LPTIM work mode.
  */
typedef enum {
    LPTIM_WORKMODE_TIMER = 0U,               /*!< Works in timer mode */
    LPTIM_WORKMODE_PCNT  = LPTIM_CR_TMS_M    /*!< Works in pulse count mode */
} LPTIM_WorkMode;

/**
  * @}
  */

/** @defgroup LPTIM_PRESCALER LPTIM Prescaler
  * @{
  * @brief  Macro definitions about LPTIM timer mode perscaler.
  */
typedef enum {
    LPTIM_PRESCALER_DIV1     = LPTIM_PSR_PBYP_M,                  /*!< Timer mode frequency is divided by 1 */
    LPTIM_PRESCALER_DIV2     = (0x0U << LPTIM_PSR_PRESCALE_S),    /*!< Timer mode frequency is divided by 2 */
    LPTIM_PRESCALER_DIV4     = (0x1U << LPTIM_PSR_PRESCALE_S),    /*!< Timer mode frequency is divided by 4 */
    LPTIM_PRESCALER_DIV8     = (0x2U << LPTIM_PSR_PRESCALE_S),    /*!< Timer mode frequency is divided by 8 */
    LPTIM_PRESCALER_DIV16    = (0x3U << LPTIM_PSR_PRESCALE_S),    /*!< Timer mode frequency is divided by 16 */
    LPTIM_PRESCALER_DIV32    = (0x4U << LPTIM_PSR_PRESCALE_S),    /*!< Timer mode frequency is divided by 32 */
    LPTIM_PRESCALER_DIV64    = (0x5U << LPTIM_PSR_PRESCALE_S),    /*!< Timer mode frequency is divided by 64 */
    LPTIM_PRESCALER_DIV128   = (0x6U << LPTIM_PSR_PRESCALE_S),    /*!< Timer mode frequency is divided by 128 */
    LPTIM_PRESCALER_DIV256   = (0x7U << LPTIM_PSR_PRESCALE_S),    /*!< Timer mode frequency is divided by 256 */
    LPTIM_PRESCALER_DIV512   = (0x8U << LPTIM_PSR_PRESCALE_S),    /*!< Timer mode frequency is divided by 512 */
    LPTIM_PRESCALER_DIV1024  = (0x9U << LPTIM_PSR_PRESCALE_S),    /*!< Timer mode frequency is divided by 1024 */
    LPTIM_PRESCALER_DIV2048  = (0xAU << LPTIM_PSR_PRESCALE_S),    /*!< Timer mode frequency is divided by 2048 */
    LPTIM_PRESCALER_DIV4096  = (0xBU << LPTIM_PSR_PRESCALE_S),    /*!< Timer mode frequency is divided by 4096 */
    LPTIM_PRESCALER_DIV8192  = (0xCU << LPTIM_PSR_PRESCALE_S),    /*!< Timer mode frequency is divided by 8192 */
    LPTIM_PRESCALER_DIV16384 = (0xDU << LPTIM_PSR_PRESCALE_S),    /*!< Timer mode frequency is divided by 16384 */
    LPTIM_PRESCALER_DIV32768 = (0xEU << LPTIM_PSR_PRESCALE_S),    /*!< Timer mode frequency is divided by 32768 */
    LPTIM_PRESCALER_DIV65536 = (0xFU << LPTIM_PSR_PRESCALE_S)     /*!< Timer mode frequency is divided by 65536 */
} LPTIM_Prescaler;

/**
  * @}
  */

/** @defgroup LPTIM_PCNTFILTER LPTIM Pulse Counter Filter
  * @{
  * @brief  Macro definitions about LPTIM pulse counter mode filter.
  */
typedef enum {
    LPTIM_PCNTFILTER_OFF      = LPTIM_PSR_PBYP_M,                  /*!< Pulse counter mode filter close */
    LPTIM_PCNTFILTER_CLK2     = (0x1U << LPTIM_PSR_PRESCALE_S),    /*!< Pulse counter mode filter width is 2 clk */
    LPTIM_PCNTFILTER_CLK4     = (0x2U << LPTIM_PSR_PRESCALE_S),    /*!< Pulse counter mode filter width is 4 clk */
    LPTIM_PCNTFILTER_CLK8     = (0x3U << LPTIM_PSR_PRESCALE_S),    /*!< Pulse counter mode filter width is 8 clk */
    LPTIM_PCNTFILTER_CLK16    = (0x4U << LPTIM_PSR_PRESCALE_S),    /*!< Pulse counter mode filter width is 16 clk */
    LPTIM_PCNTFILTER_CLK32    = (0x5U << LPTIM_PSR_PRESCALE_S),    /*!< Pulse counter mode filter width is 32 clk */
    LPTIM_PCNTFILTER_CLK64    = (0x6U << LPTIM_PSR_PRESCALE_S),    /*!< Pulse counter mode filter width is 64 clk */
    LPTIM_PCNTFILTER_CLK128   = (0x7U << LPTIM_PSR_PRESCALE_S),    /*!< Pulse counter mode filter width is 128 clk */
    LPTIM_PCNTFILTER_CLK256   = (0x8U << LPTIM_PSR_PRESCALE_S),    /*!< Pulse counter mode filter width is 256 clk */
    LPTIM_PCNTFILTER_CLK512   = (0x9U << LPTIM_PSR_PRESCALE_S),    /*!< Pulse counter mode filter width is 512 clk */
    LPTIM_PCNTFILTER_CLK1024  = (0xAU << LPTIM_PSR_PRESCALE_S),    /*!< Pulse counter mode filter width is 1024 clk */
    LPTIM_PCNTFILTER_CLK2048  = (0xBU << LPTIM_PSR_PRESCALE_S),    /*!< Pulse counter mode filter width is 2048 clk */
    LPTIM_PCNTFILTER_CLK4096  = (0xCU << LPTIM_PSR_PRESCALE_S),    /*!< Pulse counter mode filter width is 4096 clk */
    LPTIM_PCNTFILTER_CLK8192  = (0xDU << LPTIM_PSR_PRESCALE_S),    /*!< Pulse counter mode filter width is 8192 clk */
    LPTIM_PCNTFILTER_CLK16384 = (0xEU << LPTIM_PSR_PRESCALE_S),    /*!< Pulse counter mode filter width is 16384 clk */
    LPTIM_PCNTFILTER_CLK32768 = (0xFU << LPTIM_PSR_PRESCALE_S)     /*!< Pulse counter mode filter width is 32768 clk */
} LPTIM_PcntFilter;

/**
  * @}
  */

/** @defgroup LPTIM_CLOCKSOURCE LPTIM Perscaler/Filter Clock Source
  * @{
  * @brief  Macro definitions about LPTIM perscaler/filter clock source.
  */
typedef enum {
    LPTIM_CLOCKSOURCE_LIRC = 0U,    /*!< LIRC as a perscaler/filter clock source */
    LPTIM_CLOCKSOURCE_MIRC1,        /*!< MIRC1 as a perscaler/filter clock source */
    LPTIM_CLOCKSOURCE_MIRC2,        /*!< MIRC2 as a perscaler/filter clock source */
    LPTIM_CLOCKSOURCE_PCLK          /*!< PCLK as a perscaler/filter clock source */
} LPTIM_ClockSource;

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
  * \brief  Enable timer counter.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  */
static inline void LPTIM_enableCounter (LPTIM_TypeDef *lptim)
{
    SET_BIT(lptim->CR.WORDVAL, LPTIM_CR_TEN_M);
}

/**
  * \brief  Disable timer counter.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  */
static inline void LPTIM_disableCounter (LPTIM_TypeDef *lptim)
{
    CLEAR_BIT(lptim->CR.WORDVAL, LPTIM_CR_TEN_M);
}

/**
  * \brief  Get whether the timer counter is enabled.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  * \return Returned the status of whether the timer counter is enabled or not
  *                   - 0: The timer counter is not enable.
  *                   - 1: The timer counter is enable.
  */
static inline uint32_t LPTIM_getCounterEnabledStatus (LPTIM_TypeDef *lptim)
{
    return ((READ_BIT(lptim->CR.WORDVAL, LPTIM_CR_TEN_M) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Clear the compare/overflow interrupt flag.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  */
static inline void LPTIM_clearFlag (LPTIM_TypeDef *lptim)
{
    SET_BIT(lptim->CR.WORDVAL, LPTIM_CR_TCF_M);
}

/**
  * \brief  Get whether the compare/overflow interrupt flag.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  * \return Returned Interrupt flag
  *                   - true : The timer flag is set.
  *                   - false: The timer flag is not set.
  */
static inline bool LPTIM_getFlag (LPTIM_TypeDef *lptim)
{
    return (READ_BIT(lptim->CR.WORDVAL, LPTIM_CR_TCF_M) ? true : false);
}

/**
  * \brief  Enable the compare/overflow interrupt.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  */
static inline void LPTIM_enableInterrupt (LPTIM_TypeDef *lptim)
{
    SET_BIT(lptim->CR.WORDVAL, LPTIM_CR_TIE_M);
}

/**
  * \brief  Disable the compare/overflow interrupt.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  */
static inline void LPTIM_disableInterrupt (LPTIM_TypeDef *lptim)
{
    CLEAR_BIT(lptim->CR.WORDVAL, LPTIM_CR_TIE_M);
}

/**
  * \brief  Get whether the compare/overflow interrupt is enabled.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  * \return Returned the status of whether the timer interrupt is enabled or not
  *                   - true : The timer interrupt is enable.
  *                   - false: The timer interrupt is not enable.
  */
static inline bool LPTIM_getInterrupt (LPTIM_TypeDef *lptim)
{
    return (READ_BIT(lptim->CR.WORDVAL, LPTIM_CR_TIE_M) ? true : false);
}

/**
  * \brief  Set the lptim pulse count input source.
  * \note   The pulse count input source can only be modified if LPTIM is disabled.
  * \param  lptim          LPTIM pointer to a LPTIM_TypeDef structure
  *                         - LPTIM: LPTIM base address index
  * \param  pulseSource    Pulse count input source
  *                         This parameter can be any value of @ref LPTIM_PULSESOURCE
  */
static inline void LPTIM_setPulseSource (LPTIM_TypeDef *lptim, LPTIM_PulseSource pulseSource)
{
    MODIFY_REG(lptim->CR.WORDVAL, LPTIM_CR_TPS_M, pulseSource);
}

/**
  * \brief  Get actual lptim pulse count input source.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  * \return Returned actual pulse count input source
  *                   This value can be any value of @ref LPTIM_PULSESOURCE
  */
static inline LPTIM_PulseSource LPTIM_getPulseSource (LPTIM_TypeDef *lptim)
{
    return (LPTIM_PulseSource)(READ_BIT(lptim->CR.WORDVAL, LPTIM_CR_TPS_M));
}

/**
  * \brief  Set the lptim pulse count input polarity.
  * \note   The pulse count input polarity can only be modified if LPTIM is disabled.
  * \param  lptim            LPTIM pointer to a LPTIM_TypeDef structure
  *                           - LPTIM: LPTIM base address index
  * \param  pulsePolarity    Pulse count input polarity
  *                           This parameter can be any value of @ref LPTIM_PULSEPOLARITY
  */
static inline void LPTIM_setPulsePolarity (LPTIM_TypeDef *lptim, LPTIM_PulsePolarity pulsePolarity)
{
    MODIFY_REG(lptim->CR.WORDVAL, LPTIM_CR_TPP_M, pulsePolarity);
}

/**
  * \brief  Get actual lptim pulse count input polarity.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  * \return Returned actual pulse count input polarity
  *                   This value can be any value of @ref LPTIM_PULSEPOLARITY
  */
static inline LPTIM_PulsePolarity LPTIM_getPulsePolarity (LPTIM_TypeDef *lptim)
{
    return (LPTIM_PulsePolarity)(READ_BIT(lptim->CR.WORDVAL, LPTIM_CR_TPP_M));
}

/**
  * \brief  Set the lptim counter mode.
  * \note   The counter mode can only be modified if LPTIM is disabled.
  * \param  lptim          LPTIM pointer to a LPTIM_TypeDef structure
  *                         - LPTIM: LPTIM base address index
  * \param  counterMode    Counter mode
  *                         This parameter can be any value of @ref LPTIM_COUNTERMODE
  */
static inline void LPTIM_setCounterMode (LPTIM_TypeDef *lptim, LPTIM_CounterMode counterMode)
{
    MODIFY_REG(lptim->CR.WORDVAL, LPTIM_CR_TFC_M, (uint32_t)counterMode);
}

/**
  * \brief  Get actual lptim counter mode.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  * \return Returned actual counter mode
  *                   This value can be any value of @ref LPTIM_COUNTERMODE
  */
static inline LPTIM_CounterMode LPTIM_getCounterMode (LPTIM_TypeDef *lptim)
{
    return (LPTIM_CounterMode)(READ_BIT(lptim->CR.WORDVAL, LPTIM_CR_TFC_M));
}

/**
  * \brief  Set the lptim work mode.
  * \note   The work mode can only be modified if LPTIM is disabled.
  * \param  lptim       LPTIM pointer to a LPTIM_TypeDef structure
  *                      - LPTIM: LPTIM base address index
  * \param  workMode    Work mode
  *                      This parameter can be any value of @ref LPTIM_WORKMODE
  */
static inline void LPTIM_setWorkMode (LPTIM_TypeDef *lptim, LPTIM_WorkMode workMode)
{
    MODIFY_REG(lptim->CR.WORDVAL, LPTIM_CR_TMS_M, (uint32_t)workMode);
}

/**
  * \brief  Get actual lptim work mode.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  * \return Returned actual work mode
  *                   This value can be any value of @ref LPTIM_WORKMODE
  */
static inline LPTIM_WorkMode LPTIM_getWorkMode (LPTIM_TypeDef *lptim)
{
    return (LPTIM_WorkMode)(READ_BIT(lptim->CR.WORDVAL, LPTIM_CR_TMS_M));
}

/**
  * \brief  Set the lptim prescaler value.
  * \note   This function is used when lptim is working in timer mode.
  * \note   The prescaler value can only be modified if LPTIM is disabled.
  * \param  lptim        LPTIM pointer to a LPTIM_TypeDef structure
  *                       - LPTIM: LPTIM base address index
  * \param  prescaler    Prescaler value
  *                       This value can be any value of @ref LPTIM_PRESCALER
  */
static inline void LPTIM_setPrescaler (LPTIM_TypeDef *lptim, LPTIM_Prescaler prescaler)
{
    MODIFY_REG(lptim->PSR.WORDVAL, LPTIM_PSR_PRESCALE_M | LPTIM_PSR_PBYP_M, (uint32_t)prescaler);
}

/**
  * \brief  Get the lptim prescaler value.
  * \note   This function is used when lptim is working in timer mode.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  * \return Returned the prescaler value
  *                   This value can be any value of @ref LPTIM_PRESCALER
  */
static inline LPTIM_Prescaler LPTIM_getPrescaler (LPTIM_TypeDef *lptim)
{
    return (LPTIM_Prescaler)(READ_BIT(lptim->PSR.WORDVAL, LPTIM_PSR_PRESCALE_M | LPTIM_PSR_PBYP_M));
}

/**
  * \brief  Set the lptim pulse counter filter value.
  * \note   This function is used when lptim is working in pulse count mode.
  * \note   The filter value can only be modified if LPTIM is disabled.
  * \param  lptim         LPTIM pointer to a LPTIM_TypeDef structure
  *                        - LPTIM: LPTIM base address index
  * \param  pcntFilter    filter value
  *                        This value can be any value of @ref LPTIM_PCNTFILTER
  */
static inline void LPTIM_setPcntFilter (LPTIM_TypeDef *lptim, LPTIM_PcntFilter pcntFilter)
{
    MODIFY_REG(lptim->PSR.WORDVAL, LPTIM_PSR_PRESCALE_M | LPTIM_PSR_PBYP_M, (uint32_t)pcntFilter);
}

/**
  * \brief  Get the lptim pulse counter filter value.
  * \note   This function is used when lptim is working in pulse count mode.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  * \return Returned the filter value
  *                   This value can be any value of @ref LPTIM_PCNTFILTER
  */
static inline LPTIM_PcntFilter LPTIM_getPcntFilter (LPTIM_TypeDef *lptim)
{
    return (LPTIM_PcntFilter)(READ_BIT(lptim->PSR.WORDVAL, LPTIM_PSR_PRESCALE_M | LPTIM_PSR_PBYP_M));
}

/**
  * \brief  Set the lptim clock source.
  * \note   In timer mode, the clock source acts as the input clock for the prescaler.
  * \note   In pulse count mode, the clock source acts as the input clock for the filter.
  * \note   The clock source can only be modified if LPTIM is disabled.
  * \param  lptim          LPTIM pointer to a LPTIM_TypeDef structure
  *                         - LPTIM: LPTIM base address index
  * \param  clockSource    Clock source
  *                         This value can be any value of @ref LPTIM_CLOCKSOURCE
  */
static inline void LPTIM_setClockSource (LPTIM_TypeDef *lptim, LPTIM_ClockSource clockSource)
{
    MODIFY_REG(lptim->PSR.WORDVAL, LPTIM_PSR_PCS_M, (uint32_t)clockSource);
}

/**
  * \brief  Get the lptim clock source.
  * \note   In timer mode, the clock source acts as the input clock for the prescaler.
  * \note   In pulse count mode, the clock source acts as the input clock for the filter.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  * \return Returned the clock source
  *                   This value can be any value of @ref LPTIM_CLOCKSOURCE
  */
static inline LPTIM_ClockSource LPTIM_getClockSource (LPTIM_TypeDef *lptim)
{
    return (LPTIM_ClockSource)(READ_BIT(lptim->PSR.WORDVAL, LPTIM_PSR_PCS_M));
}

/**
  * \brief  Set the lptim compare value.
  * \param  lptim           LPTIM pointer to a LPTIM_TypeDef structure
  *                          - LPTIM: LPTIM base address index
  * \param  compareValue    Compare value
  *                          This parameter between Min_Data=0 and Max_Data=65535(0xFFFF).
  */
static inline void LPTIM_setCompareValue (LPTIM_TypeDef *lptim, uint32_t compareValue)
{
    WRITE_REG(lptim->CMR.WORDVAL, compareValue);
}

/**
  * \brief  Get the lptim compare value.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  * \return Returned the compare value
  *                   This value between Min_Data=0 and Max_Data=65535(0xFFFF).
  */
static inline uint32_t LPTIM_getCompareValue (LPTIM_TypeDef *lptim)
{
    return (uint32_t)READ_REG(lptim->CMR.WORDVAL);
}

/**
  * \brief  Get the lptim counter value.
  * \param  lptim    LPTIM pointer to a LPTIM_TypeDef structure
  *                   - LPTIM: LPTIM base address index
  * \return Returned counter value
  *                   This value between Min_Data=0 and Max_Data=0xFFFF.
  */
static inline uint32_t LPTIM_getCounter (LPTIM_TypeDef *lptim)
{
    WRITE_REG(lptim->CNT.WORDVAL, 0UL);
    __DSB();
    return (uint32_t)READ_REG(lptim->CNT.WORDVAL);
}

/**
  * \brief  Configure the LPTIM time base unit.
  * \param  lptim          LPTIM pointer to a LPTIM_TypeDef structure
  *                         - LPTIM: LPTIM base address index
  * \param  clockSource    The clock source acts as the input clock for the prescaler
  *                         This parameter can be any value of @ref LPTIM_CLOCKSOURCE
  *                         This feature can be modified afterwards using unitary function @ref LPTIM_setClockSource()
  * \param  prescaler      The prescaler value used to divide the LPTIM clock
  *                         This parameter can be any value of @ref LPTIM_PRESCALER
  *                         This feature can be modified afterwards using function @ref LPTIM_setPrescaler()
  * \param  counterMode    The counter mode is used to set whether free run or reset the counter when comparing matches
  *                         This parameter can be any value of @ref LPTIM_COUNTERMODE
  *                         This feature can be modified afterwards using function @ref LPTIM_setCounterMode()
  * \note   In the end you need to call the LPTIM_enableCounter() function to start the LPTIM.
  */
extern void LPTIM_configTimeBase (LPTIM_TypeDef *lptim, LPTIM_ClockSource clockSource, LPTIM_Prescaler prescaler,
                                  LPTIM_CounterMode counterMode);

/**
  * \brief  Configure the LPTIM as the pulse counter.
  * \note   When used as a pulse counter, there is no need to call the LPTIM_configTimeBase() beforehand.
  * \note   After the function is called, if you need to configure filtering, please call the LPTIM_configPcntFilter().
  * \note   After the function is called, if you need to configure compare value, please call the LPTIM_setCompareValue().
  * \param  lptim          LPTIM pointer to a LPTIM_TypeDef structure
  *                         - LPTIM: LPTIM base address index
  * \param  pulseSource    Specifies the pulse input source in pulse counter mode
  *                         This parameter can be any value of @ref LPTIM_PULSESOURCE
  *                         This feature can be modified afterwards using unitary function @ref LPTIM_setPulseSource()
  * \param  pulsePol       Specifies the polarity of the pulse count input source
  *                         This parameter can be any value of @ref LPTIM_PULSEPOLARITY
  *                         This feature can be modified afterwards using function @ref LPTIM_setPulsePolarity()
  * \param  counterMode    The counter mode is used to set whether free run or reset the counter when comparing matches
  *                         This parameter can be any value of @ref LPTIM_COUNTERMODE
  *                         This feature can be modified afterwards using function @ref LPTIM_setCounterMode()
  * \note   In the end you need to call the LPTIM_enableCounter() function to start the LPTIM.
  */
extern void LPTIM_configPcntBase (LPTIM_TypeDef *lptim, LPTIM_PulseSource pulseSource, LPTIM_PulsePolarity pulsePol,
                                  LPTIM_CounterMode counterMode);

/**
  * \brief  Configure filtering in pulse counter mode.
  * \param  lptim           LPTIM pointer to a LPTIM_TypeDef structure
  *                          - LPTIM: LPTIM base address index
  * \param  filterClkSrc    Specifies the filter clock source
  *                          This parameter can be any value of @ref LPTIM_CLOCKSOURCE
  *                          This feature can be modified afterwards using unitary function @ref LPTIM_setClockSource()
  * \param  pcntFilter      Specifies the pcnt filter width
  *                          This parameter can be any value of @ref LPTIM_PCNTFILTER
  *                          This feature can be modified afterwards using function @ref LPTIM_setPcntFilter()
  */
extern void LPTIM_configPcntFilter (LPTIM_TypeDef *lptim, LPTIM_ClockSource filterClkSrc, LPTIM_PcntFilter pcntFilter);


#ifdef __cplusplus
}
#endif


#endif /* __LPTIM_H__ */
