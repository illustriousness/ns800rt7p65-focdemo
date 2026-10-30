/**
  * @file       iwdg2.c
  * @author     bilang.xiong
  * @brief      Function file for NS800RT7xxx iwdg2 module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "iwdg2.h"


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
  * @brief  Initializes the IWDG2 peripheral according to the specified parameters
  * @param  iwdg         IWDG2 pointer to a IWDG2_TypeDef structure
  *                       - IWDG2: IWDG2 base address index
  * @param  resetsel     IWDG2 select reset or IRQ
  *                       - This parameter can be any value of @ref IWDG2_RESIRQSEL
  * @param  prescaler    IWDG2 clock division value
  *                       - This parameter can be any value of @ref IWDG2_PRESCALER
  * @param  loadvalue    Load value to IWDG2_RLR register
  *                       - This parameter is an unsigned integer that is less 
  *                         than 0xFFFUL
  * @return Returns a flag indicates whether the IWDG2 initialization operation 
  *                       has been successfully completed
  *                       - 0UL: the operation has failed
  *                       - 1UL: the operation has succeeded
  */
uint8_t IWDG2_configModule (IWDG2_TypeDef *iwdg, IWDG2_ResIrqSel mode,\
                            IWDG2_Prescaler prescaler, uint32_t loadvalue)
{
    uint32_t temp = 0x00;
    uint32_t timeout = 0x00;
    uint8_t  flag = 0xFF;

    if (mode == IRQ_SEL)
    {
        temp = IWDG2_CR_IRQ_EN_M | (mode << IWDG2_CR_RSTIRQS_S)\
                                 | (prescaler << IWDG2_CR_PR_S);
    }
    else
    {
        temp = (mode << IWDG2_CR_RSTIRQS_S) | (prescaler << IWDG2_CR_PR_S);
    }

    WRITE_REG(iwdg->KR.WORDVAL, 0x00005555);
    do
    {
        flag = READ_BIT(iwdg->VUSR.WORDVAL, IWDG2_VUSR_PVU_M);
        timeout++;
    }
    while ((timeout < 0x1FFFFFFF) && (flag != 0));
    
    if (flag == 0)
    {
        WRITE_REG(iwdg->CR.WORDVAL, temp);
    }
    else
    {
        return 0;
    }

    timeout = 0x00;
    flag = 0xFF;
    do
    {
        flag = READ_BIT(iwdg->VUSR.WORDVAL, IWDG2_VUSR_RVU_M);
        timeout++;
    }
    while ((timeout < 0x1FFFFFFF) && (flag != 0));

    if (flag == 0)
    {
        WRITE_REG(iwdg->RLR.WORDVAL, (loadvalue & 0x00000FFF));
        return 1;
    }
    else
    {
        return 0;
    }
}
