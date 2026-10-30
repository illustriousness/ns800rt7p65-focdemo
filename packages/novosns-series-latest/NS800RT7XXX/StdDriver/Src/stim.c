/**
  * @file       stim.c
  * @author     yangjun
  * @brief      Function file for NS800RT7xxx stim module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "stim.h"


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
  * @brief  Configure the STIM time base unit.
  * @param  stim            STIM pointer to a STIM_TypeDef structure
  *                          - STIM: STIM base address index
  * @param  cntMode         the STIMx MODE.
  *                          This parameter can be any value of @ref STIM_MODE
  * @param  ch1LoadValue    STIM Channel1 Load Value.
  *                          This parameter can be a number between Min_Data=0x00000000 and Max_Data=0xFFFFFFFF.
  * @param  ch2LoadValue    STIM Channel2 Load Value.
  *                          This parameter can be a number between Min_Data=0x00000000 and Max_Data=0xFFFFFFFF.
  */
void STIM_configModule (STIM_TypeDef *stim, STIM_Mode cntMode, uint32_t ch1LoadValue, uint32_t ch2LoadValue)
{
    WRITE_REG(stim->ARR1.WORDVAL, ch1LoadValue);
    WRITE_REG(stim->ARR2.WORDVAL, ch2LoadValue);
    STIM_setMode(stim, cntMode);
}
