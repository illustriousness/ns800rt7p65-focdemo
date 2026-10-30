/**
  * @file       version.c
  * @author     Haven-X
  * @brief      API to return the version number of the drivers in use.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "version.h"


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
  * @brief  Version_getLibVersion
  * @return Returns the version of the drivers in use.
  * @note   This function can be used to check the version number of the drivers
  *         that is in use. The version number will take the format xx.xx.xx.xx, so for
  *         example, if the function returns 1020300, the driverlib version being used
  *         is 1.02.03.00.
  */
uint32_t Version_getLibVersion(void)
{
    return(VERSION_NUMBER);
}
