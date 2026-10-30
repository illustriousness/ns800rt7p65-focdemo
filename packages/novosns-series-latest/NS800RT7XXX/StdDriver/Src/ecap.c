/**
  * @file       ecap.c
  * @author     Alex-J
  * @brief      Function file for NS800RT7xxx ecap module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "ecap.h"


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
  * @brief  Configure the Emulation mode of the ECAP
  * @param  ecap    ecap pointer to a ECAP_TypeDef structure
  *                  - ECAP1: ECAP1 base address index
  *                  - ECAP2: ECAP2 base address index
  *                  - ECAP3: ECAP3 base address index
  *                  - ECAP4: ECAP4 base address index
  *                  - ECAP5: ECAP5 base address index
  *                  - ECAP6: ECAP6 base address index
  *                  - ECAP7: ECAP7 base address index
  * @param  mode    ECAP Emulation Mode
  *                 This parameter can be one of the following @ref ECAP_EmulationMode.
  */
void ECAP_setEmulationMode (ECAP_TypeDef *ecap, ECAP_EmulationMode mode)
{
    /* Write to FREE/SOFT bit */
    MODIFY_REG(ecap->ECCTL1.WORDVAL, ECAP_ECCTL1_FREESOFT_M, ((uint32_t)mode << ECAP_ECCTL1_FREESOFT_S));
}
