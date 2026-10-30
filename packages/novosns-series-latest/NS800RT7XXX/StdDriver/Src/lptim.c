/**
  * @file       lptim.c
  * @author     Haven-X
  * @brief      Function file for NS800RT7xxx lptim module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "lptim.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Functions
 ******************************************************************************/

/**
  * @brief  Configure the LPTIM time base unit.
  * @param  lptim          LPTIM pointer to a LPTIM_TypeDef structure
  *                         - LPTIM: LPTIM base address index
  * @param  clockSource    The clock source acts as the input clock for the prescaler
  *                         This parameter can be any value of @ref LPTIM_CLOCKSOURCE
  *                         This feature can be modified afterwards using unitary function @ref LPTIM_setClockSource()
  * @param  prescaler      The prescaler value used to divide the LPTIM clock
  *                         This parameter can be any value of @ref LPTIM_PRESCALER
  *                         This feature can be modified afterwards using function @ref LPTIM_setPrescaler()
  * @param  counterMode    The counter mode is used to set whether free run or reset the counter when comparing matches
  *                         This parameter can be any value of @ref LPTIM_COUNTERMODE
  *                         This feature can be modified afterwards using function @ref LPTIM_setCounterMode()
  * @note   In the end you need to call the LPTIM_enableCounter() function to start the LPTIM.
  */
void LPTIM_configTimeBase (LPTIM_TypeDef *lptim, LPTIM_ClockSource clockSource, LPTIM_Prescaler prescaler,
                           LPTIM_CounterMode counterMode)
{
    /* Config LPTIM_CR Reg */
    MODIFY_REG(lptim->CR.WORDVAL, LPTIM_CR_TEN_M | LPTIM_CR_TMS_M | LPTIM_CR_TFC_M, (uint32_t)counterMode);

    /* Config LPTIM_PSR Reg */
    WRITE_REG(lptim->PSR.WORDVAL, (uint32_t)clockSource | (uint32_t)prescaler);
}

/**
  * @brief  Configure the LPTIM as the pulse counter.
  * @note   When used as a pulse counter, there is no need to call the LPTIM_configTimeBase() beforehand.
  * @note   After the function is called, if you need to configure filtering, please call the LPTIM_configPcntFilter().
  * @note   After the function is called, if you need to configure compare value, please call the LPTIM_setCompareValue().
  * @param  lptim          LPTIM pointer to a LPTIM_TypeDef structure
  *                         - LPTIM: LPTIM base address index
  * @param  pulseSource    Specifies the pulse input source in pulse counter mode
  *                         This parameter can be any value of @ref LPTIM_PULSESOURCE
  *                         This feature can be modified afterwards using unitary function @ref LPTIM_setPulseSource()
  * @param  pulsePol       Specifies the polarity of the pulse count input source
  *                         This parameter can be any value of @ref LPTIM_PULSEPOLARITY
  *                         This feature can be modified afterwards using function @ref LPTIM_setPulsePolarity()
  * @param  counterMode    The counter mode is used to set whether free run or reset the counter when comparing matches
  *                         This parameter can be any value of @ref LPTIM_COUNTERMODE
  *                         This feature can be modified afterwards using function @ref LPTIM_setCounterMode()
  * @note   In the end you need to call the LPTIM_enableCounter() function to start the LPTIM.
  */
void LPTIM_configPcntBase (LPTIM_TypeDef *lptim, LPTIM_PulseSource pulseSource, LPTIM_PulsePolarity pulsePol,
                           LPTIM_CounterMode counterMode)
{
    /* Config LPTIM_CR Reg */
    MODIFY_REG(lptim->CR.WORDVAL,
               LPTIM_CR_TEN_M | LPTIM_CR_TFC_M | LPTIM_CR_TPP_M | LPTIM_CR_TPS_M,
               LPTIM_CR_TMS_M | (uint32_t)counterMode | (uint32_t)pulsePol | (uint32_t)pulseSource);

    /* Disable Filter */
    SET_BIT(lptim->PSR.WORDVAL, LPTIM_PSR_PBYP_M);
}

/**
  * @brief  Configure filtering in pulse counter mode.
  * @param  lptim           LPTIM pointer to a LPTIM_TypeDef structure
  *                          - LPTIM: LPTIM base address index
  * @param  filterClkSrc    Specifies the filter clock source
  *                          This parameter can be any value of @ref LPTIM_CLOCKSOURCE
  *                          This feature can be modified afterwards using unitary function @ref LPTIM_setClockSource()
  * @param  pcntFilter      Specifies the filter width
  *                          This parameter can be any value of @ref LPTIM_PCNTFILTER
  *                          This feature can be modified afterwards using function @ref LPTIM_setPcntFilter()
  */
void LPTIM_configPcntFilter (LPTIM_TypeDef *lptim, LPTIM_ClockSource filterClkSrc, LPTIM_PcntFilter pcntFilter)
{
    WRITE_REG(lptim->PSR.WORDVAL, (uint32_t)filterClkSrc | (uint32_t)pcntFilter);
}
