/**
  * @file       version.h
  * @author     Haven-X
  * @brief      API to return the version number of the drivers in use.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __VERSION_H__
#define __VERSION_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup VERSION_EXPORTED_TYPES VERSION Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'VERSION' module.
  */

/** @defgroup VERSION_NUMBER
  * @{
  * @brief  Version number to be returned by Version_getLibVersion().
  *         Format x.xx.xx.xx
  */                                        
#define VERSION_NUMBER      0040000U   /*!< Version number: v0.4.0.0 */

/**
  * @}
  */

/**
 * @}
 */

/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
  * \brief  Version_getLibVersion
  * \return Returns the version of the drivers in use.
  * \note   This function can be used to check the version number of the drivers
  *         that is in use. The version number will take the format xx.xx.xx.xx, so for
  *         example, if the function returns 00010400, the driverlib version being used
  *         is 00.01.04.00.
  */
extern uint32_t Version_getLibVersion(void);


#ifdef __cplusplus
}
#endif


#endif /* __VERSION_H__ */
