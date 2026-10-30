/**
  * @file       debug.h
  * @author     bilang.xiong
  * @brief      Header file for NS800RT7xxx debug module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __DEBUG_H__
#define __DEBUG_H__


#ifdef __cplusplus
extern "C"
{
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_debug.h"


/*******************************************************************************
 * Definitions 
 ******************************************************************************/
/** @defgroup DEBUG_EXPORTED_TYPES DEBUG Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'DEBUG' module.
  */

/** @defgroup DEBUG_CORE1_APBFZ DEBUG IP Number with DEBUG
  * @{
  * @brief  Macro definitions about DEBUG IPs.
  */
typedef enum {
    DEBUG_CORE1_SLEEP = 0UL,          /*!< DBG_SLEEP Enable/Disable when Debug */
    DEBUG_CORE1_STOP,                 /*!< DBG_STOP Enable/Disable when Debug */
    DEBUG_CORE1_STANDBY,              /*!< DBG_STANDBY Enable/Disable when Debug */
    DEBUG_CORE1_IWDG1CPU2 = 3UL,      /*!< IWDG1CPU2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_IWDG1CPU1,            /*!< IWDG1CPU1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_IWDG2,                /*!< IWDG2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_WWDGCPU1,             /*!< WWDGCPU1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_WWDGCPU2,             /*!< WWDGCPU2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_BTIM1,                /*!< BTIM1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_BTIM2,                /*!< BTIM2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_LPTIM,                /*!< LPTIM_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_STIM1 = 12UL,         /*!< STIM1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_STIM2,                /*!< STIM2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_STIM3,                /*!< STIM3_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_STIM4,                /*!< STIM4_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_STIM5,                /*!< STIM5_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_STIM6,                /*!< STIM6_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_I2C1 = 20UL,          /*!< I2C1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_I2C2,                 /*!< I2C2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_FCANFD1 = 24UL,       /*!< FCANFD1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_FCANFD2,              /*!< FCANFD2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_FCAN1,                /*!< FCAN1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CMPSS1 = 64UL,        /*!< CMPSS1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CMPSS2,               /*!< CMPSS2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CMPSS3,               /*!< CMPSS3_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CMPSS4,               /*!< CMPSS4_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CMPSS5,               /*!< CMPSS5_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CMPSS6,               /*!< CMPSS6_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CMPSS7,               /*!< CMPSS7_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CMPSS8,               /*!< CMPSS8_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CMPSS9,               /*!< CMPSS9_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CMPSS10,              /*!< CMPSS10_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CMPSS11,              /*!< CMPSS11_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_BGCRC1 = 80UL,        /*!< BGCRC1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_BGCRC2,               /*!< BGCRC2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_NMIWD1,               /*!< NMIWD1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_NMIWDG2,              /*!< NMIWDG2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EDMA1,                /*!< EDMA1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EDMA2,                /*!< EDMA2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_TIM1,                 /*!< TIM1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_TIM2,                 /*!< TIM2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CLB1,                 /*!< CLB1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CLB2,                 /*!< CLB2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CLB3,                 /*!< CLB3_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CLB4,                 /*!< CLB4_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CLB5,                 /*!< CLB5_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_CLB6,                 /*!< CLB6_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_UPP = 95UL,           /*!< UPP_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM1 = 128UL,        /*!< EPWM1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM2,                /*!< EPWM2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM3,                /*!< EPWM3_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM4,                /*!< EPWM4_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM5,                /*!< EPWM5_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM6,                /*!< EPWM6_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM7,                /*!< EPWM7_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM8,                /*!< EPWM8_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM9,                /*!< EPWM9_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM10,               /*!< EPWM10_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM11,               /*!< EPWM11_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM12,               /*!< EPWM12_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM13,               /*!< EPWM13_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM14,               /*!< EPWM14_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM15,               /*!< EPWM15_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM16,               /*!< EPWM16_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM17,               /*!< EPWM17_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EPWM18,               /*!< EPWM18_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_ECAP1 = 192UL,        /*!< ECAP1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_ECAP2,                /*!< ECAP2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_ECAP3,                /*!< ECAP3_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_ECAP4,                /*!< ECAP4_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_ECAP5,                /*!< ECAP5_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_ECAP6,                /*!< ECAP6_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_ECAP7,                /*!< ECAP7_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EQEP1 = 208UL,        /*!< EQEP1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EQEP2,                /*!< EQEP2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EQEP3,                /*!< EQEP3_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EQEP4,                /*!< EQEP4_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EQEP5,                /*!< EQEP5_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE1_EQEP6                 /*!< EQEP6_DBGSTOP Enable/Disable when Debug */
} DEBUG_Core1_ApbFz;

/**
  * @}
  */

/** @defgroup DEBUG_CORE2_APBFZ DEBUG IP Number with DEBUG
  * @{
  * @brief  Macro definitions about DEBUG IPs.
  */
typedef enum {
    DEBUG_CORE2_IWDG1CPU2 = 3UL,      /*!< IWDG1CPU2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_IWDG1CPU1,            /*!< IWDG1CPU1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_IWDG2,                /*!< IWDG2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_WWDGCPU1,             /*!< WWDGCPU1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_WWDGCPU2,             /*!< WWDGCPU2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_BTIM1,                /*!< BTIM1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_BTIM2,                /*!< BTIM2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_LPTIM,                /*!< LPTIM_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_STIM1 = 12UL,         /*!< STIM1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_STIM2,                /*!< STIM2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_STIM3,                /*!< STIM3_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_STIM4,                /*!< STIM4_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_STIM5,                /*!< STIM5_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_STIM6,                /*!< STIM6_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_I2C1 = 20UL,          /*!< I2C1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_I2C2,                 /*!< I2C2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_FCANFD1 = 24UL,       /*!< FCANFD1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_FCANFD2,              /*!< FCANFD2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_FCAN1,                /*!< FCAN1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CMPSS1 = 64UL,        /*!< CMPSS1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CMPSS2,               /*!< CMPSS2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CMPSS3,               /*!< CMPSS3_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CMPSS4,               /*!< CMPSS4_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CMPSS5,               /*!< CMPSS5_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CMPSS6,               /*!< CMPSS6_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CMPSS7,               /*!< CMPSS7_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CMPSS8,               /*!< CMPSS8_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CMPSS9,               /*!< CMPSS9_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CMPSS10,              /*!< CMPSS10_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CMPSS11,              /*!< CMPSS11_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_BGCRC1 = 112UL,       /*!< BGCRC1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_BGCRC2,               /*!< BGCRC2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_NMIWD1,               /*!< NMIWD1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_NMIWDG2,              /*!< NMIWDG2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EDMA1,                /*!< EDMA1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EDMA2,                /*!< EDMA2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_TIM1,                 /*!< TIM1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_TIM2,                 /*!< TIM2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CLB1,                 /*!< CLB1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CLB2,                 /*!< CLB2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CLB3,                 /*!< CLB3_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CLB4,                 /*!< CLB4_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CLB5,                 /*!< CLB5_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_CLB6,                 /*!< CLB6_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_UPP = 127UL,          /*!< UPP_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM1 = 128UL,        /*!< EPWM1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM2,                /*!< EPWM2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM3,                /*!< EPWM3_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM4,                /*!< EPWM4_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM5,                /*!< EPWM5_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM6,                /*!< EPWM6_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM7,                /*!< EPWM7_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM8,                /*!< EPWM8_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM9,                /*!< EPWM9_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM10,               /*!< EPWM10_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM11,               /*!< EPWM11_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM12,               /*!< EPWM12_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM13,               /*!< EPWM13_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM14,               /*!< EPWM14_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM15,               /*!< EPWM15_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM16,               /*!< EPWM16_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM17,               /*!< EPWM17_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EPWM18,               /*!< EPWM18_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_ECAP1 = 192UL,        /*!< ECAP1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_ECAP2,                /*!< ECAP2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_ECAP3,                /*!< ECAP3_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_ECAP4,                /*!< ECAP4_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_ECAP5,                /*!< ECAP5_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_ECAP6,                /*!< ECAP6_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_ECAP7,                /*!< ECAP7_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EQEP1 = 304UL,        /*!< EQEP1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EQEP2,                /*!< EQEP2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EQEP3,                /*!< EQEP3_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EQEP4,                /*!< EQEP4_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EQEP5,                /*!< EQEP5_DBGSTOP Enable/Disable when Debug */
    DEBUG_CORE2_EQEP6                 /*!< EQEP6_DBGSTOP Enable/Disable when Debug */
} DEBUG_Core2_ApbFz;

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
  * \brief  Enbale the core1 ip to stop when the chip enters debug mode
  * \param  debug        DEBUG pointer to a DEBUG_TypeDef structure
  *                       - DEBUG_D: DEBUG base address index
  * \param  debugType    the ip number
  *                       This parameter can be any value of @ref DEBUG_APBFZ
  */
extern void DEBUG_core1SetApbStop (DBG_TypeDef *debug, DEBUG_Core1_ApbFz debugType);

/**
  * \brief  Enbale the core1 ip to run when the chip enters debug mode
  * \param  debug        DEBUG pointer to a DEBUG_TypeDef structure
  *                       - DEBUG_D: DEBUG base address index
  * \param  debugType    the ip number
  *                       This parameter can be any value of @ref DEBUG_APBFZ
  */
extern void DEBUG_core1SetApbRun (DBG_TypeDef *debug, DEBUG_Core1_ApbFz debugType);

/**
  * \brief  Enbale the core2 ip to stop when the chip enters debug mode
  * \param  debug        DEBUG pointer to a DEBUG_TypeDef structure
  *                       - DEBUG_D: DEBUG base address index
  * \param  debugType    the ip number
  *                       This parameter can be any value of @ref DEBUG_APBFZ
  */
extern void DEBUG_core2SetApbStop (DBG_TypeDef *debug, DEBUG_Core2_ApbFz debugType);

/**
  * \brief  Enbale the core2 ip to run when the chip enters debug mode
  * \param  debug        DEBUG pointer to a DEBUG_TypeDef structure
  *                       - DEBUG_D: DEBUG base address index
  * \param  debugType    the ip number
  *                       This parameter can be any value of @ref DEBUG_APBFZ
  */
extern void DEBUG_core2SetApbRun (DBG_TypeDef *debug, DEBUG_Core2_ApbFz debugType);

#ifdef __cplusplus
}
#endif


#endif /*__DEBUG_H__ */
