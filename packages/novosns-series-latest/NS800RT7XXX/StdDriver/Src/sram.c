/**
  * @file       sram.c
  * @author     bilang.xiong
  * @brief      Function file for NS800RT7xxx sram module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "sram.h"

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
 * @brief  Configure the SRAM Ecc check enable
 * @param  sram         SRAM pointer to a SRAM_TypeDef structure
 *                       - SRAM: SRAM base address index
 * @param  chk          SRAM CHKT Typedef
 *                       This parameter can be any value of @ref SRAM_CHK
 * @param  operation    SRAM ERROROPERATION Typedef
 *                       This parameter can be any value of @ref SRAM_ERROP
 */
void SRAM_configChkCr (SRAM_TypeDef *sram, SRAM_Chk chk, SRAM_ErrOp operation)
{
    WRITE_REG(sram->UNLOCK.WORDVAL, SRAM_UNLOCK_KEY);
    CLEAR_BIT(sram->CHKCR.WORDVAL, (operation << chk));
    SET_BIT(sram->CHKCR.WORDVAL, (operation << chk));
    WRITE_REG(sram->UNLOCK.WORDVAL, SRAM_LOCK_KEY);
}

/**
 * @brief  Enable SRAM Registon Ecc ctrl.
 * @param  sram      SRAM pointer to a SRAM_TypeDef structure
 *                    - SRAM: SRAM base address index
 * @param  memSel    memroy select 
 *                    This parameter can be any value of @ref ECC_MEMNUM
 */
void SRAM_enableRegionEccCtrl (SRAM_TypeDef *sram, ECC_MemNum memSel)
{
    WRITE_REG(sram->UNLOCK.WORDVAL, SRAM_UNLOCK_KEY);
    switch(memSel)
    {
        case ECC_SRAM1_MEM:
            SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<16));
            break;
        case ECC_SRAM2_MEM:
            SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<17));
            break;
        case ECC_CORE1_ITCM_MEM:
            SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<18));
            break;
        case ECC_CORE1_DTCM_MEM:
            SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<19));
            break;
        case ECC_CORE2_ITCM_MEM:
            SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<20));
            break;
        case ECC_CORE2_DTCM_MEM:
            SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<21));
            break;
        default: break;
    }
    WRITE_REG(sram->UNLOCK.WORDVAL, SRAM_LOCK_KEY);
}

/**
 * @brief  Disable SRAM Registon Ecc ctrl.
 * @param  sram      SRAM pointer to a SRAM_TypeDef structure
 *                    - SRAM: SRAM base address index
 * @param  memSel    memroy select 
 *                    This parameter can be any value of @ref ECC_MEMNUM
 */
void SRAM_disableRegionEccCtrl (SRAM_TypeDef *sram, ECC_MemNum memSel)
{
    WRITE_REG(sram->UNLOCK.WORDVAL, SRAM_UNLOCK_KEY);
    switch(memSel)
    {
        case ECC_SRAM1_MEM:
            CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<16));
            break;
        case ECC_SRAM2_MEM:
            CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<17));
            break;
        case ECC_CORE1_ITCM_MEM:
            CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<18));
            break;
        case ECC_CORE1_DTCM_MEM:
            CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<19));
            break;
        case ECC_CORE2_ITCM_MEM:
            CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<20));
            break;
        case ECC_CORE2_DTCM_MEM:
            CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<21));
            break;
        default: break;
    }
    WRITE_REG(sram->UNLOCK.WORDVAL, SRAM_LOCK_KEY);
}

/**
 * @brief  Enable SRAM Registon Pipe ctrl.
 * @param  sram      SRAM pointer to a SRAM_TypeDef structure
 *                    - SRAM: SRAM base address index
 * @param  memSel    memroy select 
 *                    This parameter can be any value of @ref PIPE_MEMNUM
 */
void SRAM_enableRegionPipeCtrl (SRAM_TypeDef *sram, PIPE_MemNum memSel)
{
    WRITE_REG(sram->UNLOCK.WORDVAL, SRAM_UNLOCK_KEY);
    switch(memSel)
    {
        case PIPE_CORE1_ITCM_MEM:
            SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<1));
            break;
        case PIPE_CORE1_DTCM_MEM:
            SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<3));
            break;
        case PIPE_CORE2_ITCM_MEM:
            SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<5));
            break;
        case PIPE_CORE2_DTCM_MEM:
            SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<7));
            break;
        case PIPE_SRAM1_MEM:
            SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<8));
            break;
        case PIPE_SRAM2_MEM:
            SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<9));
            break;
        default: break;
    }
    WRITE_REG(sram->UNLOCK.WORDVAL, SRAM_LOCK_KEY);
}

/**
 * @brief  Disable SRAM Registon Pipe ctrl.
 * @param  sram      SRAM pointer to a SRAM_TypeDef structure
 *                    - SRAM: SRAM base address index
 * @param  memSel    memroy select 
 *                    This parameter can be any value of @ref PIPE_MEMNUM
 */
void SRAM_disableRegionPipeCtrl (SRAM_TypeDef *sram, PIPE_MemNum memSel)
{
    WRITE_REG(sram->UNLOCK.WORDVAL, SRAM_UNLOCK_KEY);
    switch(memSel)
    {
        case PIPE_CORE1_ITCM_MEM:
            CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<1));
            break;
        case PIPE_CORE1_DTCM_MEM:
            CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<3));
            break;
        case PIPE_CORE2_ITCM_MEM:
            CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<5));
            break;
        case PIPE_CORE2_DTCM_MEM:
            CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<7));
            break;
        case PIPE_SRAM1_MEM:
            CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<8));
            break;
        case PIPE_SRAM2_MEM:
            CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<9));
            break;
        default: break;
    }
    WRITE_REG(sram->UNLOCK.WORDVAL, SRAM_LOCK_KEY);
}

/**
 * @brief  Enable SRAM Registon Rwait ctrl.
 * @param  sram      SRAM pointer to a SRAM_TypeDef structure
 *                    - SRAM: SRAM base address index
 * @param  memSel    memroy select 
 *                    This parameter can be any value of @ref RWAIT_MEMNUM
 */
void SRAM_enableRegionRwaitCtrl (SRAM_TypeDef *sram, Rwait_MemNum memSel)
{
    WRITE_REG(sram->UNLOCK.WORDVAL, SRAM_UNLOCK_KEY);
    switch(memSel)
    {
        case RWAIT_CORE1_ITCM_MEM:
            SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<0));
            break;
        case RWAIT_CORE1_DTCM_MEM:
            SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<2));
            break;
        case RWAIT_CORE2_ITCM_MEM:
            SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<4));
            break;
        case RWAIT_CORE2_DTCM_MEM:
            SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<6));
            break;
        default: break;
    }
    WRITE_REG(sram->UNLOCK.WORDVAL, SRAM_LOCK_KEY);
}

/**
 * @brief  Disable SRAM Registon Rwait ctrl.
 * @param  sram      SRAM pointer to a SRAM_TypeDef structure
 *                    - SRAM: SRAM base address index
 * @param  memSel    memroy select 
 *                    This parameter can be any value of @ref RWAIT_MEMNUM
 */
void SRAM_disableRegionRwaitCtrl (SRAM_TypeDef *sram, Rwait_MemNum memSel)
{
    WRITE_REG(sram->UNLOCK.WORDVAL, SRAM_UNLOCK_KEY);
    switch(memSel)
    {
        case RWAIT_CORE1_ITCM_MEM:
            CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<0));
            break;
        case RWAIT_CORE1_DTCM_MEM:
            CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<2));
            break;
        case RWAIT_CORE2_ITCM_MEM:
            CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<4));
            break;
        case RWAIT_CORE2_DTCM_MEM:
            CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<6));
            break;
        default: break;
    }
    WRITE_REG(sram->UNLOCK.WORDVAL, SRAM_LOCK_KEY);
}

/**
 * @brief  Get SRAM Status from SRAM_CHKSR register
 * @param  sram         SRAM pointer to a AWK_TypeDef structure
 *                       - SRAM: SRAM base address index
 * @param  sramStNum    SRAM Reset Flag num of @ref SRAM_STNUM 
 * @return Returned the status of check registor
 *                       - 1: error 
 *                       - 0: no error
 */
uint32_t SRAM_getStatusFlag (SRAM_TypeDef *sram, SRAM_StNum sramStNum)
{
    uint32_t tmpreg = 0x0UL;
    tmpreg = sram->CHKSR.WORDVAL; 
    return ((tmpreg>>sramStNum) & 0x01UL);
}

/**
 * @brief  Clear Status Register
 * @param  sram         SRAM pointer to a AWK_TypeDef structure
 *                       - SRAM: SRAM base address index
 * @param  sramStNum    SRAM Reset Flag num of @ref SRAM_STNUM 
 */
void SRAM_clearStatusFlag (SRAM_TypeDef *sram, SRAM_StNum sramStNum)
{
    uint32_t tmpreg = 0x0UL;
    tmpreg = sram->CHKSR.WORDVAL; 
    tmpreg &= ~(0x01UL << sramStNum);
    WRITE_REG(sram->UNLOCK.WORDVAL, SRAM_UNLOCK_KEY);
    WRITE_REG(sram->CHKSR.WORDVAL, tmpreg);
    WRITE_REG(sram->UNLOCK.WORDVAL, SRAM_LOCK_KEY);
}
