/**
  * @file       iwdg1.c
  * @author     bilang.xiong
  * @brief      Function file for NS800RT7xxx iwdg1 module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "iwdg1.h"


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
  * @brief  Initializes the IWDG1 peripheral according to the specified parameters
  * @param  iwdg          IWDG1 pointer to a IWDG1_TypeDef structure
  *                        - IWDG1: IWDG1 base address index
  * @param  resetsel      IWDG1 select reset or IRQ
  *                        - This parameter can be any value of @ref IWDG1_RESIRQSEL
  * @param  lpmode        IWDG1 work mode in lowpower mode
  *                        - This parameter can be any value of @ref IWDG1_LOWPOWERMODE
  * @param  prescaler     IWDG1 clock division value
  *                        - This parameter can be any value of @ref IWDG1_PRESCALER
  * @param  windowhead    IWDG1 refresh windowshead value
  *                        - This parameter can be any value of @ref IWDG1_WINDOWHEAD
  * @param  windowend     IWDG1 refresh windowsend value
  *                        - This parameter can be any value of @ref IWDG1_WINDOWEND
  * @param  timeout       IWDG1 timeout periods
  *                        - This parameter can be any value of @ref IWDG1_TIMEOUT
  */
void IWDG1_configModule (IWDG1_TypeDef *iwdg, IWDG1_ResIrqSel resetsel, IWDG1_LowpowerMode lpmode,\
                         IWDG1_Prescaler preScale, IWDG1_WindowHead windowhead,\
                         IWDG1_WindowEnd windowend, IWDG1_Timeout timeout)
{
    uint32_t temp;

    temp = timeout | (resetsel << IWDG_CR_RSTIRQS_S) \
                   | (lpmode << IWDG_CR_SLCSTP_S) \
                   | (preScale << IWDG_CR_CKS_S) \
                   | (windowend << IWDG_CR_RPES_S) \
                   | (windowhead << IWDG_CR_RPSS_S);
    WRITE_REG(iwdg->CR.WORDVAL,temp);
}
