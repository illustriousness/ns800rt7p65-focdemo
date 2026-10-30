/**
  * @file       debug.c
  * @author     bilang.xiong
  * @brief      Function file for NS800RT7xxx debug module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "debug.h"


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
  * @brief  Enbale the core1 ip to stop when the chip enters debug mode
  * @param  debug        DEBUG pointer to a DEBUG_TypeDef structure
  *                       - DEBUG_D: DEBUG base address index
  * @param  debugType    the ip number
  *                       This parameter can be any value of @ref DEBUG_CORE1_APBFZ
  */
void DEBUG_core1SetApbStop (DBG_TypeDef *debug, DEBUG_Core1_ApbFz debugType)
{
    SET_BIT(TYPE32(&(debug->APBFZ1_1) + (debugType >> 5UL)),0x1UL << (debugType - (debugType >> 5UL) * 32UL));
}

/**
  * @brief  Enbale the core1 ip to run when the chip enters debug mode
  * @param  debug        DEBUG pointer to a DEBUG_TypeDef structure
  *                       - DEBUG_D: DEBUG base address index
  * @param  debugType    the ip number
  *                       This parameter can be any value of @ref DEBUG_CORE1_APBFZ
  */
void DEBUG_core1SetApbRun (DBG_TypeDef *debug, DEBUG_Core1_ApbFz debugType)
{
    CLEAR_BIT(TYPE32(&(debug->APBFZ1_1) + (debugType >> 5UL)),0x1UL << (debugType - (debugType >> 5UL) * 32UL));
}

/**
  * @brief  Enbale the core2 ip to stop when the chip enters debug mode
  * @param  debug        DEBUG pointer to a DEBUG_TypeDef structure
  *                       - DEBUG_D: DEBUG base address index
  * @param  debugType    the ip number
  *                       This parameter can be any value of @ref DEBUG_CORE2_APBFZ
  */
void DEBUG_core2SetApbStop (DBG_TypeDef *debug, DEBUG_Core2_ApbFz debugType)
{
    SET_BIT(TYPE32(&(debug->APBFZ2_1) + (debugType >> 5UL)),0x1UL << (debugType - (debugType >> 5UL) * 32UL));
}

/**
  * @brief  Enbale the core2 ip to run when the chip enters debug mode
  * @param  debug        DEBUG pointer to a DEBUG_TypeDef structure
  *                       - DEBUG_D: DEBUG base address index
  * @param  debugType    the ip number
  *                       This parameter can be any value of @ref DEBUG_CORE2_APBFZ
  */
void DEBUG_core2SetApbRun (DBG_TypeDef *debug, DEBUG_Core2_ApbFz debugType)
{
    CLEAR_BIT(TYPE32(&(debug->APBFZ2_1) + (debugType >> 5UL)),0x1UL << (debugType - (debugType >> 5UL) * 32UL));
}