/**
  * @file       epg.c
  * @author     Alex-J
  * @brief      Function file for NS800RTxxx EPG module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "epg.h"

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
 * @brief  Select EPG Data Output
 * @note   This function selects EPG Modules's Final Data Output which can be used to
 *         feed EPG outputs to inputs of certain IPs or bypass the IP's input as is.
 * 
 * @param  epg         epg pointer to a EPG_TypeDef structure
 *                        - EPG: EPG base address index
 * @param  dataIn      the bit of EPG Data Input to be configured.
 * @param  dataOutSel  the source of \e dataOutBit to configure.
 */
void EPG_selectEPGDataOut (EPG_TypeDef* epg, EPG_DataIn dataIn, EPG_DataOutSel dataOutSel)
{
    if ((uint16_t)dataIn <= 31U)
    {
        MODIFY_REG(epg->EPGMXSEL0.WORDVAL, (1UL << (uint32_t)dataIn), ((uint32_t)dataOutSel << (uint32_t)dataIn));
    }
}
