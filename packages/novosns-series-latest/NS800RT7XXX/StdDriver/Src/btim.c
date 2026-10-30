/**
  * @file       btim.c
  * @author     Haven-X
  * @brief      Function file for NS800RT7xxx btim module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "btim.h"


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
  * @brief  Configure the BTIMx time base unit.
  * @param  btim          BTIMx pointer to a BTIM_TypeDef structure
  *                        - BTIM1: BTIM1 base address index
  *                        - BTIM2: BTIM2 base address index
  * @param  prescaler     The prescaler value used to divide the BTIMx clock
  *                        This parameter can be any value of @ref BTIM_PRESCALER
  *                        This feature can be modified afterwards using function @ref BTIM_setPrescaler().
  * @param  autoReload    The auto reload value to be loaded into the ARR and PARR Register
  *                        This parameter can be a number between Min_Data=0x0001 and Max_Data=0xFFFF/0xFFFFFFFF,
  *                        the Max_Data depends on the bit width setting. This feature can be modified afterwards 
  *                        using unitary function @ref BTIM_setAutoReload() or @ref BTIM_setAutoReloadPreload().
  * @param  configure     Configurable combination
  *                        All parameters can be or together, and the parameters include the following sections:
  *                        @ref BTIM_COUNTERMODE, Specifies the counter mode.
  *                        This feature can be modified afterwards using unitary function @ref BTIM_setCounterMode()
  *                        @ref BTIM_BITWIDTH, Specifies the bit width.
  *                        This feature can be modified afterwards using unitary function @ref BTIM_setBitWidth()
  *                        @ref BTIM_ONESHOTMODE, Specifies the one shot mode.
  *                        This feature can be modified afterwards using unitary function @ref BTIM_setOneShotMode()
  * @note   In the end you need to call the BTIM_enableCounter() function to start the BTIM.
  */
void BTIM_configTimeBase (BTIM_TypeDef *btim, BTIM_Prescaler prescaler, uint32_t autoReload, uint32_t configure)
{
    /* Read BTIMx_CR Reg */
    __IO uint32_t btimCr = btim->CR.WORDVAL;
    
    /* Config BTIMx_CR Reg */
    MODIFY_REG(btimCr,
               BTIM_CR_MODE_M | BTIM_CR_SIZE_M | BTIM_CR_ONESHOT_M | BTIM_CR_PSC_M, 
               (configure & (BTIM_CR_MODE_M | BTIM_CR_SIZE_M | BTIM_CR_ONESHOT_M)) | (uint32_t)prescaler);
    
    /* Clear BTIMx_CR Reg */
    WRITE_REG(btim->CR.WORDVAL, 0UL);

    /* Set the auto-reload(ARR) value */
    WRITE_REG(btim->ARR.WORDVAL, autoReload);

    /* Clear the interrupt flag */
    /* It should be noted that when writing 0 to the ARR register, it causes the interrupt flag to be set */
    WRITE_REG(btim->ICR.WORDVAL, 0UL);
    
    /* Write BTIMx_CR Reg */
    WRITE_REG(btim->CR.WORDVAL, btimCr);
}

/**
  * @brief  Restart the oneshot mode and use the new ARR value.
  * @note   In the oneshot mode, call the BTIM_enableCounter() function to make the timer run, 
  *         the timer will automatically stop after the count reaches 0. After that, you can use 
  *         @ref BTIM_enableCounter() or @ref BTIM_oneShotRestart() to restart the timer in OneShot mode again.
  * @param  btim          BTIMx pointer to a BTIM_TypeDef structure
  *                        - BTIM1: BTIM1 base address index
  *                        - BTIM2: BTIM2 base address index
  * @param  autoReload    The new auto reload value to be loaded into the ARR and PARR Register
  *                        This parameter can be a number between Min_Data=0x0001 and Max_Data=0xFFFF/0xFFFFFFFF,
  *                        the Max_Data depends on the bit width setting.
  */
void BTIM_oneShotRestart (BTIM_TypeDef *btim, uint32_t autoReload)
{
    /* Rewrite the load register in oneshot mode to restart the counter */
    WRITE_REG(btim->ARR.WORDVAL, autoReload);
}
