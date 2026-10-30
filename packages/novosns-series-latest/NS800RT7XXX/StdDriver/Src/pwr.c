/**
  * @file       pwr.c
  * @author     Alex-J
  * @brief      Function file for NS800RTxxx PWR module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "pwr.h"


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
 * @brief  Sets the PWR module Sleep Mode
 * @note   This function sets the sleep mode for the PWR module.
 *
 * @param  mode  the value is used to select the mode of WFI or WFE
 */
void PWR_setSleepMode (PWR_WaitMode mode)
{
    if (mode == PWR_WAIT_MODE_WFI)
    {
        SCB->SCR &= ~SCB_SCR_SEVONPEND_Msk;
        __ISB();
        __WFI();
    }
    else
    {
        SCB->SCR |= SCB_SCR_SEVONPEND_Msk;
        __ISB();
        __SEV();
        __WFE();
        __WFE();
    }
}

/**
 * @brief  Enters the PWR module Sleep Mode
 * @note   This function operates the PWR module to enter sleep mode.
 *
 * @param  mode  the value is used to select the mode of WFI or WFE
 */
void PWR_enterSleepMode (PWR_WaitMode mode)
{
    SCB->SCR = 0;

    PWR_setSleepMode(mode);
}

/**
 * @brief  Enters the PWR module Sleep On Exit Mode
 * @note   This function operates the PWR module to enter sleep 
 *         on exit mode.
 *
 * @param  mode  the value is used to select the mode of WFI or WFE
 */
void PWR_enterSleepOnExitMode (PWR_WaitMode mode)
{
    SCB->SCR  = 0;

    SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;

    PWR_setSleepMode(mode);
}

/**
 * @brief  Enters the PWR module Stop Mode
 * @note   This function operates the PWR module to enter stop mode.
 *
 * @param  mode  the value is used to select the mode of WFI or WFE
 */
void PWR_enterStopMode (PWR_WaitMode mode)
{
    SCB->SCR  = 0;

    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    if ((MCM->CPUID.WORDVAL & 0x01) == 0x01)
    {
        PWR_setCPU1DeepSleepMode(PWR, PWR_CPUn_DSLP_KEEP_STOP_MODE);
    }
    else if ((MCM->CPUID.WORDVAL & 0x02) == 0x02)
    {
        PWR_setCPU2DeepSleepMode(PWR, PWR_CPUn_DSLP_KEEP_STOP_MODE);
    }

    PWR_enableSystemLowPower(PWR);

    PWR_setSleepMode(mode);
}

/**
 * @brief  Enters the PWR module Stop On Exit Mode
 * @note   This function operates the PWR module to enter stop 
 *         on exit mode.
 *
 * @param  mode  the value is used to select the mode of WFI or WFE
 */
void PWR_enterStopOnExitMode (PWR_WaitMode mode)
{
    SCB->SCR  = 0;

    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;

    if ((MCM->CPUID.WORDVAL & 0x01) == 0x01)
    {
        PWR_setCPU1DeepSleepMode(PWR, PWR_CPUn_DSLP_KEEP_STOP_MODE);
    }
    else if ((MCM->CPUID.WORDVAL & 0x02) == 0x02)
    {
        PWR_setCPU2DeepSleepMode(PWR, PWR_CPUn_DSLP_KEEP_STOP_MODE);
    }

    PWR_enableSystemLowPower(PWR);

    PWR_setSleepMode(mode);
}

/**
 * @brief  Enters the PWR module Standby Mode
 * @note   This function operates the PWR module to enter standby mode.
 *
 * @param  mode  the value is used to select the mode of WFI or WFE
 */
void PWR_enterStandbyMode (PWR_WaitMode mode)
{
    SCB->SCR  = 0;

    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    if ((MCM->CPUID.WORDVAL & 0x01) == 0x01)
    {
        PWR_setCPU1DeepSleepMode(PWR, PWR_CPUn_DSLP_INTO_STANDBY_MODE);
    }
    else if ((MCM->CPUID.WORDVAL & 0x02) == 0x02)
    {
        PWR_setCPU2DeepSleepMode(PWR, PWR_CPUn_DSLP_INTO_STANDBY_MODE);
    }

    PWR_enableSystemLowPower(PWR);

    PWR_setSleepMode(mode);
}

/**
 * @brief  Enters the PWR module Standby On Exit Mode
 * @note   This function operates the PWR module to enter standby 
 *         on exit mode.
 *
 * @param  mode  the value is used to select the mode of WFI or WFE
 */
void PWR_enterStandbyOnExitMode (PWR_WaitMode mode)
{
    SCB->SCR  = 0;

    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;

    if ((MCM->CPUID.WORDVAL & 0x01) == 0x01)
    {
        PWR_setCPU1DeepSleepMode(PWR, PWR_CPUn_DSLP_INTO_STANDBY_MODE);
    }
    else if ((MCM->CPUID.WORDVAL & 0x02) == 0x02)
    {
        PWR_setCPU2DeepSleepMode(PWR, PWR_CPUn_DSLP_INTO_STANDBY_MODE);
    }

    PWR_enableSystemLowPower(PWR);

    PWR_setSleepMode(mode);
}
