/**
  * @file       wwdg.c
  * @author     bilang.xiong
  * @brief      Function file for NS800RT7xxx wwdg module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "wwdg.h"


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
  * @brief  Initializes the WWDG peripheral according to the specified parameters
  * @param  iwdg           WWDG pointer to a WWDG_TypeDef structure
  *                         - WWDG: WWDG base address index
  * @param  model_sel      WWDG Select Reset or Wakeup int
  *                         - This parameter can be any value of @ref WWDG_INTSEL
  * @param  prescaler      WWDG clock division value
  *                         - This parameter can be any value of @ref WWDG_PRESCALER
  * @param  windowvalue    WWDG load windows value
  *                         - This parameter is an unsigned integer that is greater 
  *                           than or equal to 0x41 and less than or equal to 0x7F
  */
void WWDG_configModule (WWDG_TypeDef *wwdg, WWDG_IntSel model_sel, \
                        WWDG_Prescaler prescaler,  uint32_t windowvalue)
{
    if (model_sel == WWDG_EARLY_WAKEUP_INT)
    {
        WWDG_enableInterrupt(wwdg);
    }
    
    WWDG_setPrescaler(wwdg, prescaler);
    WWDG_setWindow(wwdg, windowvalue);
}
