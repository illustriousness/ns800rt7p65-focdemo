/**
  * @file       epwm.c
  * @author     Pearce
  * @brief      Function file for NS800RT7xxx epwm module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "epwm.h"


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
  * @brief  Set the emulation mode.
  * @param  epwm             EPWMx pointer to a EPWM_TypeDef structure
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
  * @param  emulationMode    The emulation mode.
  *                           This parameter can be any value of @ref EPWM_EMULATIONMODE
  */
void EPWM_setEmulationMode (EPWM_TypeDef *epwm, EPWM_EmulationMode emulationMode)
{
    MODIFY_REG(epwm->TBCTL.WORDVAL, EPWM_TBCTL_FREE_SOFT_M, (uint32_t)emulationMode << EPWM_TBCTL_FREE_SOFT_S);
}

/**
  * @brief  Configures ePWM signal with desired frequency & duty
  * @param  epwm             EPWMx pointer to a EPWM_TypeDef structure
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
  * @param  signalParams    Pointer to the signal parameters structure.
  *                          This parameter can be any value of @ref EPWM_EMULATIONMODE
  * @note   This function configures the ePWM module to generate a signal with desired frequency & duty.
  */    
void EPWM_configureSignal (EPWM_TypeDef *epwm, const EPWM_SignalParams *signalParams)
{
    float tbClkInHz = 0.0F;
    uint16_t tbPrdVal = 0U, cmpAVal = 0U, cmpBVal = 0U;

    EPWM_setClockPrescaler(epwm, signalParams->tbClkDiv, signalParams->tbHSClkDiv);
    EPWM_setTimeBaseCounterMode(epwm, signalParams->tbCtrMode);
    tbClkInHz = ((float)signalParams->sysClkInHz / (float)(1U << (uint16_t)signalParams->tbClkDiv));
    if (signalParams->tbHSClkDiv <= EPWM_HSCLOCK_DIVIDER_4)
    {
        tbClkInHz /= (float)(1U << (uint16_t)signalParams->tbHSClkDiv);
    }
    else
    {
        tbClkInHz /= (float)(2U * (uint16_t)signalParams->tbHSClkDiv);
    }
    if (signalParams->tbCtrMode == EPWM_COUNTER_MODE_UP)
    {
        tbPrdVal = (uint16_t)((tbClkInHz / signalParams->freqInHz) - 1.0f);
        cmpAVal = (uint16_t)(signalParams->dutyValA * (float)(tbPrdVal + 1U));
        cmpBVal = (uint16_t)(signalParams->dutyValB * (float)(tbPrdVal + 1U));
    }
    else if (signalParams->tbCtrMode == EPWM_COUNTER_MODE_DOWN)
    {
        tbPrdVal = (uint16_t)((tbClkInHz / signalParams->freqInHz) - 1.0f);
        cmpAVal = (uint16_t)((float)(tbPrdVal + 1U) - (signalParams->dutyValA * (float)(tbPrdVal + 1U)));
        cmpBVal = (uint16_t)((float)(tbPrdVal + 1U) - (signalParams->dutyValB * (float)(tbPrdVal + 1U)));
    }
    else
    {
        tbPrdVal = (uint16_t)(tbClkInHz / (2.0f * signalParams->freqInHz));
        cmpAVal = (uint16_t)(((float)tbPrdVal - ((signalParams->dutyValA * (float)tbPrdVal))) + 0.5f);
        cmpBVal = (uint16_t)(((float)tbPrdVal - ((signalParams->dutyValB * (float)tbPrdVal))) + 0.5f);
    }
    EPWM_setTimeBasePeriod(epwm, tbPrdVal);
    EPWM_disablePhaseShiftLoad(epwm);
    EPWM_setPhaseShift(epwm, 0U);
    EPWM_setTimeBaseCounter(epwm, 0U);
    EPWM_setCounterCompareShadowLoadMode(epwm, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(epwm, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareValue(epwm, EPWM_COUNTER_COMPARE_A, cmpAVal);
    EPWM_setCounterCompareValue(epwm, EPWM_COUNTER_COMPARE_B, cmpBVal);
    if (signalParams->tbCtrMode == EPWM_COUNTER_MODE_UP)
    {
        EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
        EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
        if (signalParams->invertSignalB == true)
        {
            EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
            EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
        }
        else
        {
            EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
            EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
        }
    }
    else if ((signalParams->tbCtrMode == EPWM_COUNTER_MODE_DOWN))
    {
        EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
        EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
        if (signalParams->invertSignalB == true)
        {
            EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
            EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
        }
        else
        {
            EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
            EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
        }
    }
    else
    {
        EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
        EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
        EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
        if (signalParams->invertSignalB == true)
        {
            EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
            EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
            EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
        }
        else
        {
            EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
            EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
            EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
        }
    }
}
