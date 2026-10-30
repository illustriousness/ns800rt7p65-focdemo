/**
  * @file       dmamux.c
  * @author     yangjun
  * @brief      Function file for NS800RT7xxx dmamux module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "dmamux.h"


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
  * @brief  Initializes the DMAMUX peripheral.
  * @param  dmamux    The base address of the DMAMUX module.
  *                    - DMAMUX1: DMAMUX1 base address index
  *                    - DMAMUX2: DMAMUX2 base address index
  */
void DMAMUX_configModule (DMAMUX_TypeDef *dmamux)
{
    /* Initialize the value to 0 first. */
    DMAMUX_resetAllChannel(dmamux);
}
