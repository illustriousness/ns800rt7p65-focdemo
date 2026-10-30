/**
  * @file       dcc.c
  * @author     bilang.xiong
  * @brief      Function file for NS800RT7xxx dcc module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include  "dcc.h"


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
 * @brief  Set the Clock DCC monitor function
 * @param  dcc       DCC pointer to DCC_TypeDef structure
 *                    - DCC: DCC base address index
 * @param  refclk    DCC CR register REFCLKSEL value
 *                    - This parameter can be any value of @ref DCC_CLKSOURCE
 * @param  calClk    DCC CR register CALCLKSEL value
 *                    - This parameter can be any value of @ref DCC_CLKSOURCE
 * @param  rstEn     DCC CR register RST_IE value
 *                    - This parameter can be any value of @ref DCC_MODE
 * @param  refCon    DCC DCC_REFCON register value
 *                    - This parameter can be any value from 1~0xFFFFFFFF
 * @param  htCr      DCC DCC_HTCR register value
 *                    - This parameter can be any value from 0~0xFFFFFFFF
 * @param  ltCr      DCC DCC_ register value
 *                    - This parameter can be any value from 0~0xFFFFFFFF
 * @return Returns the DCC monitor mode status set whether success
 *                    - true : set success
 *                    - false: set false
 */
bool DCC_setClockMonitor (DCC_TypeDef *dcc, DCC_ClkSource refClk, DCC_ClkSource calClk,
                          DCC_Mode rstEn, uint32_t refCon, uint32_t htCr, uint32_t ltCr)
{
    if (refClk != calClk)
    {
        /* Set Reference clock, set Calibration clock, set DCCEN  */ 
        MODIFY_REG(dcc->CR.WORDVAL, 
                   (DCC_CR_CALCLKSEL_M | DCC_CR_REFCLKSEL_M | DCC_CR_MONEN_M | DCC_CR_TRIMSTART_M),
                   ((refClk << DCC_CR_REFCLKSEL_S) | (calClk << DCC_CR_CALCLKSEL_S) | DCC_CR_CLKEN_M));

        WRITE_REG(dcc->REFCON.WORDVAL, refCon);
        WRITE_REG(dcc->HTCR.WORDVAL, htCr);
        WRITE_REG(dcc->LTCR.WORDVAL, ltCr);

        /* Set Monitor Mode */ 
        SET_BIT(dcc->CR.WORDVAL, DCC_CR_MONEN_M);
        
        if (rstEn == DCC_INTERRTUP_MODE)
        {
            /* disable reset-mode & enable interrupt-mode */
            MODIFY_REG(dcc->CR.WORDVAL, DCC_CR_RSTIE_M, DCC_CR_IRQEN_M);
        }
        else
        {
            /* enable reset-mode & disable interrupt-mode*/
            MODIFY_REG(dcc->CR.WORDVAL, DCC_CR_IRQEN_M, DCC_CR_RSTIE_M);
        }
        /* Start */
        SET_BIT(dcc->CR.WORDVAL, DCC_CR_TRIMSTART_M);
    }
    else
    {
        return false;
    }
    return true;
}

/**
 * @brief  Set the Clock DCC trim function
 * @param  dcc          DCC pointer to DCC_TypeDef structure
 *                       - DCC: DCC base address index
 * @param  refclk       DCC CR register REFCLKSEL value
 *                       - This parameter can be any value of @ref DCC_CLKSOURCE
 * @param  calClk       DCC CR register CALCLKSEL value
 *                       - This parameter can be any value of @ref DCC_CLKSOURCE
 * @param  refCon       DCC DCC_REFCON register value
 *                       - This parameter can be any value from 1~0xFFFFFFFF
 * @param  irqEnable    DCC CR register IRQ_EN value
 *                       - true : ENABLE IRQ
 *                       - false: DISABLE IRQ
 * @return Returns the DCC trim mode status set whether success
 *                       - true : set success
 *                       - false: set false
 */
bool DCC_setClockTrim (DCC_TypeDef *dcc, DCC_ClkSource refClk, DCC_ClkSource calClk,
                       uint32_t refCon, bool irqEnable)
{
    if (refClk != calClk)
    {
        MODIFY_REG(dcc->CR.WORDVAL, 
                   (DCC_CR_MONEN_M | DCC_CR_RSTIE_M | DCC_CR_CALCLKSEL_M |
                    DCC_CR_REFCLKSEL_M | DCC_CR_IRQEN_M | DCC_CR_TRIMSTART_M),
                   ((refClk << DCC_CR_REFCLKSEL_S) | (calClk << DCC_CR_CALCLKSEL_S) | DCC_CR_CLKEN_M));

        /* Set value to REFCON register the start data */
        WRITE_REG(dcc->REFCON.WORDVAL, refCon);

        /*Config interrupt and Start to trim mode */ 
        SET_BIT(dcc->CR.WORDVAL, (irqEnable ? DCC_CR_IRQEN_M : 0U) | DCC_CR_TRIMSTART_M);
    }
    else
    {
        return false;
    }
    return true;
}
