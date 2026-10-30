/**
  * @file       fmu.c
  * @author     yangjun
  * @brief      Function file for NS800RT7xxx fmu module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "fmu.h"


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
  * @brief  Selects the controller core of a FMU event
  * @param  fmu        FMU pointer to a FMU_TypeDef structure
 *                      - FMU: FMU base address index
  * @param  eventID    This is the Event that may cause FMU error
 *                      - This parameter can be any value of @ref FMU_EVENT
  * @param  core       FMU is the core controller of a FMU event
  *                     This parameter can be any value of @ref FMU_CORESELECT
  */
void FMU_setControllerCore (FMU_TypeDef *fmu, FMU_Event eventID, FMU_CoreSelect core)
{
    uint32_t index, offset;

    index  = (uint32_t)eventID >> 4UL;
    offset = (uint32_t)(eventID & 0xFUL) << 1UL;
    MODIFY_REG(fmu->EVTCTRL[index].WORDVAL, (0x3UL << offset), (uint32_t)core << offset);
}
