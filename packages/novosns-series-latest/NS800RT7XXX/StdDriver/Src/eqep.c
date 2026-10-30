/**
  * @file       eqep.c
  * @author     Alex-J
  * @brief      Function file for NS800RT7xxx gpio module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "eqep.h"


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
 * @brief  Configures eQEP module position-compare unit.
 * @note   This function configures the operation of the eQEP module position-compare
 *         unit.
 * @note   You can set the sync pulse width independently using the EQEP_setComparePulseWidth()
 *         function.
 *
 * @param  eqep          eqep pointer to a EQEP_TypeDef structure
 *                         - EQEP1: eQEP1 base address index
 *                         - EQEP2: eQEP2 base address index
 *                         - EQEP3: eQEP2 base address index
 *                         - EQEP4: eQEP2 base address index
 *                         - EQEP5: eQEP2 base address index
 *                         - EQEP6: eQEP2 base address index
 * @param  config        the configuration for the eQEP module position-compare unit.
 * @param  compareValue  the value to which the position count value is compared for
 *                       a position-compare event.
 * @param  cycles        the width of the pulse that can be generated on a position-compare event.
 *                       It is in units of 4 SYSCLKOUT cycles.
 */
void EQEP_setCompareConfig (EQEP_TypeDef *eqep, uint16_t config, uint32_t compareValue, uint16_t cycles)
{
    uint16_t regValue;

    /* Check the arguments. */
    if (cycles <= (EQEP_QPOSCTL_PCSPW_M + 1U))
    {
        return;
    }

    /* Set the compare match value */
    WRITE_REG(eqep->QPOSCMP.WORDVAL, compareValue);

    /* Set the shadow register settings and pulse width. */
    regValue = (config & (uint16_t)(EQEP_QPOSCTL_PCSHDW | EQEP_QPOSCTL_PCLOAD)) | (cycles - 1U);

    MODIFY_REG(eqep->QPOSCTL.WORDVAL, (EQEP_QPOSCTL_PCSPW_M | EQEP_QPOSCTL_PCLOAD | EQEP_QPOSCTL_PCSHDW), regValue);

    /* Set position compare sync-output mode. */
    regValue = config & (uint16_t)(EQEP_QDECCTL_SOEN | EQEP_QDECCTL_SPSEL);

    MODIFY_REG(eqep->QDECCTL.WORDVAL, (EQEP_QDECCTL_SOEN | EQEP_QDECCTL_SPSEL), regValue);
}

/**
 * @brief  Sets the polarity of the eQEP module's input signals.
 * @note   This function configures the polarity of the inputs to the eQEP module. To
 *         negate the polarity of any of the input signals, pass \b true into its
 *         corresponding parameter in this function. Pass \b false to leave it as-is.
 *
 * @param  eqep          eqep pointer to a EQEP_TypeDef structure
 *                         - EQEP1: eQEP1 base address index
 *                         - EQEP2: eQEP2 base address index
 *                         - EQEP3: eQEP2 base address index
 *                         - EQEP4: eQEP2 base address index
 *                         - EQEP5: eQEP2 base address index
 *                         - EQEP6: eQEP2 base address index
 * @param  invertQEPA    the flag to negate the QEPA input.
 * @param  invertQEPB    the flag to negate the QEPA input.
 * @param  invertIndex   the flag to negate the index input.
 * @param  invertStrobe  the flag to negate the strobe input.
 */
void EQEP_setInputPolarity (EQEP_TypeDef *eqep, bool invertQEPA, bool invertQEPB, bool invertIndex, bool invertStrobe)
{
    /* Configure QEPA signal */
    if (invertQEPA)
    {
        SET_BIT(eqep->QDECCTL.WORDVAL, EQEP_QDECCTL_QAP);
    }
    else
    {
        CLEAR_BIT(eqep->QDECCTL.WORDVAL, EQEP_QDECCTL_QAP);
    }

    /* Configure QEPB signal */
    if (invertQEPB)
    {
        SET_BIT(eqep->QDECCTL.WORDVAL, EQEP_QDECCTL_QBP);
    }
    else
    {
        CLEAR_BIT(eqep->QDECCTL.WORDVAL, EQEP_QDECCTL_QBP);
    }

    /* Configure index signal */
    if (invertIndex)
    {
        SET_BIT(eqep->QDECCTL.WORDVAL, EQEP_QDECCTL_QIP);
    }
    else
    {
        CLEAR_BIT(eqep->QDECCTL.WORDVAL, EQEP_QDECCTL_QIP);
    }

    /* Configure strobe signal */
    if (invertStrobe)
    {
        SET_BIT(eqep->QDECCTL.WORDVAL, EQEP_QDECCTL_QSP);
    }
    else
    {
        CLEAR_BIT(eqep->QDECCTL.WORDVAL, EQEP_QDECCTL_QSP);
    }
}
