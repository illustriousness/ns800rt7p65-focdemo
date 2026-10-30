/**
  * @file       smpu.h
  * @author     Alex-J
  * @brief      Header file for NS800RT7xxx SMPU module
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __SMPU_H__
#define __SMPU_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/** @defgroup SMPU_EXPORTED_TYPES SMPU Exported Types
 * @{
 * @brief  Macro definitions are used with all files publicly about 'SMPU' module.
 */

/** @defgroup SMPU_CONTRL_REGBIT SMPU CONTRL register bits
 * @{
 * @brief  Macro definitions about SMPU_CONTRL register bits definition.
 */
#define SMPU_CONTRL_KEY_VAL       (0x5a690000UL)    /*!< KEY Code Value */

/**
 * @}
 */

/** @defgroup SMPU_VIOLATIONACTION SMPU Module's Violation Action
 * @{
 * @brief  Values are used to control the violation action of the SMPU.
 */
typedef enum {
    DISABLE_WRITE_READ_0 = 0U,    /*!< Write ignorance, read to 0x00 */
    TRIGGER_NMI_INTERRUPT,        /*!< Non-Maskable Interrupt */
    SYSTEM_RESET,                 /*!< System Reset */
    RES_SET_DISABLE               /*!< Reserved(Set Disable) */
} SMPU_ViolationAction;

/**
 * @}
 */

 /** @defgroup SMPU_PROTECTMODE SMPU Module's Protection Mode
 * @{
 * @brief  Values are used to control the protection mode of the SMPU.
 */
typedef enum {
    SMPU_PROTECT_NONE = 0U,             /*!< No Protection */
    SMPU_PROTECT_READ = 2U,             /*!< Read Protection */
    SMPU_PROTECT_WRITE = 4U,            /*!< Write Protection */
    SMPU_PROTECT_READ_AND_WRITE = 6U    /*!< Read and Write Protection */
} SMPU_ProtectMode;

/**
 * @}
 */

/** @defgroup SMPU_EDMAREGION SMPU EDMA Memory Protection Region
 * @{
 * @brief  Macro definitions about EDMA memory protection region
 */
typedef enum {
    SMPU_EDMA_REGION_0 = 0U,    /*!< The protection region 0 of EDMA */
    SMPU_EDMA_REGION_1,         /*!< The protection region 1 of EDMA */
    SMPU_EDMA_REGION_2,         /*!< The protection region 2 of EDMA */
    SMPU_EDMA_REGION_3,         /*!< The protection region 3 of EDMA */
    SMPU_EDMA_REGION_4,         /*!< The protection region 4 of EDMA */
    SMPU_EDMA_REGION_5,         /*!< The protection region 5 of EDMA */
    SMPU_EDMA_REGION_6,         /*!< The protection region 6 of EDMA */
    SMPU_EDMA_REGION_7          /*!< The protection region 7 of EDMA */
} SMPU_EdmaRegion;

/**
 * @}
 */

/** @defgroup SMPU_AESREGION SMPU AES-HASH Memory Protection Region
 * @{
 * @brief  Macro definitions about AES-HASH memory protection region
 */
typedef enum {
    SMPU_AES_REGION_0 = 0U,    /*!< The protection region 0 of AES-HASH */
    SMPU_AES_REGION_1,         /*!< The protection region 1 of AES-HASH */
    SMPU_AES_REGION_2,         /*!< The protection region 2 of AES-HASH */
    SMPU_AES_REGION_3          /*!< The protection region 3 of AES-HASH */
} SMPU_AesRegion;

/**
 * @}
 */

/** @defgroup SMPU_EMATHREGION SMPU EMATH Memory Protection Region
 * @{
 * @brief  Macro definitions about EMATH memory protection region
 */
typedef enum {
    SMPU_EMATH_REGION_0 = 0U,    /*!< The protection region 0 of EMATH */
    SMPU_EMATH_REGION_1,         /*!< The protection region 1 of EMATH */
    SMPU_EMATH_REGION_2,         /*!< The protection region 2 of EMATH */
    SMPU_EMATH_REGION_3          /*!< The protection region 3 of EMATH */
} SMPU_EmathRegion;

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
 * \brief  Sets the EDMA1 Memory Protection Region n Start Address in the SMPU
 * \note   This function sets the EDMA1 memory protection region n start address 
 *         of the SMPU.
 *
 * \param  smpu         smpu pointer to a SMPU_TypeDef structure
 *                       - SMPU: SMPU base address index
 * \param  region       The region n of EDMA1 memory protection
 *                       This parameter can be any value of @ref SMPU_EdmaRegion
 * \param  startAddr    a value of EDMA1 protection region n start address.
 */
static inline void SMPU_setEdma1RegionStartAddr (SMPU_TypeDef *smpu, SMPU_EdmaRegion region, uint32_t startAddr)
{
    WRITE_REG (smpu->SEDMA1[region].WORDVAL, (startAddr & SMPU_SEDMA1_SEDMA1_M));
}

/**
 * \brief  Sets the EDMA1 Memory Protection Region n End Address in the SMPU
 * \note   This function sets the EDMA1 memory protection region n end address 
 *         of the SMPU.
 *
 * \param  smpu       smpu pointer to a SMPU_TypeDef structure
 *                     - SMPU: SMPU base address index
 * \param  region     The region n of EDMA1 memory protection
 *                     This parameter can be any value of @ref SMPU_EdmaRegion
 * \param  endAddr    a value of EDMA1 protection region n end address.
 */
static inline void SMPU_setEdma1RegionEndAddr (SMPU_TypeDef *smpu, SMPU_EdmaRegion region, uint32_t endAddr)
{
    WRITE_REG (smpu->SEDMA1[region].WORDVAL, (endAddr & SMPU_EEDMA1_EEDMA1_M));
}

/**
 * \brief  Sets the EDMA2 Memory Protection Region n Start Address in the SMPU
 * \note   This function sets the EDMA2 memory protection region n start address 
 *         of the SMPU.
 *
 * \param  smpu         smpu pointer to a SMPU_TypeDef structure
 *                       - SMPU: SMPU base address index
 * \param  region       The region n of EDMA2 memory protection
 *                       This parameter can be any value of @ref SMPU_EdmaRegion
 * \param  startAddr    a value of EDMA2 protection region n start address.
 */
static inline void SMPU_setEdma2RegionStartAddr (SMPU_TypeDef *smpu, SMPU_EdmaRegion region, uint32_t startAddr)
{
    WRITE_REG (smpu->SEDMA2[region].WORDVAL, (startAddr & SMPU_SEDMA2_SEDMA2_M));
}

/**
 * \brief  Sets the EDMA2 Memory Protection Region n End Address in the SMPU
 * \note   This function sets the EDMA2 memory protection region n end address 
 *         of the SMPU.
 *
 * \param  smpu       smpu pointer to a SMPU_TypeDef structure
 *                     - SMPU: SMPU base address index
 * \param  region     The region n of EDMA2 memory protection
 *                     This parameter can be any value of @ref SMPU_EdmaRegion
 * \param  endAddr    a value of EDMA2 protection region n end address.
 */
static inline void SMPU_setEdma2RegionEndAddr (SMPU_TypeDef *smpu, SMPU_EdmaRegion region, uint32_t endAddr)
{
    WRITE_REG (smpu->SEDMA2[region].WORDVAL, (endAddr & SMPU_EEDMA2_EEDMA2_M));
}

/**
 * \brief  Sets the AES Memory Protection Region n Start Address in the SMPU
 * \note   This function sets the AES memory protection region n start address 
 *         of the SMPU.
 *
 * \param  smpu         smpu pointer to a SMPU_TypeDef structure
 *                       - SMPU: SMPU base address index
 * \param  region       The region n of AES-HASH memory protection
 *                       This parameter can be any value of @ref SMPU_AesRegion
 * \param  startAddr    a value of AES protection region n start address.
 */
static inline void SMPU_setAesRegionStartAddr (SMPU_TypeDef *smpu, SMPU_AesRegion region, uint32_t startAddr)
{
    WRITE_REG (smpu->SAES[region].WORDVAL, (startAddr & SMPU_SAES_SAES_S));
}

/**
 * \brief  Sets the AES Memory Protection Region n End Address in the SMPU
 * \note   This function sets the AES memory protection region n end address 
 *         of the SMPU.
 *
 * \param  smpu       smpu pointer to a SMPU_TypeDef structure
 *                     - SMPU: SMPU base address index 
 * \param  region     The region n of AES-HASH memory protection
 *                     This parameter can be any value of @ref SMPU_AesRegion
 * \param  endAddr    a value of AES protection region n end address.
 */
static inline void SMPU_setAesRegionEndAddr (SMPU_TypeDef *smpu, SMPU_AesRegion region, uint32_t endAddr)
{
    WRITE_REG (smpu->EAES[region].WORDVAL, (endAddr & SMPU_EAES_EAES_M));
}

/**
 * \brief  Sets the EMATH Memory Protection Region n Start Address in the SMPU
 * \note   This function sets the EMATH memory protection region n start address 
 *         of the SMPU.
 *
 * \param  smpu         smpu pointer to a SMPU_TypeDef structure
 *                       - SMPU: SMPU base address index
 * \param  region       The region n of EMATH memory protection
 *                       This parameter can be any value of @ref SMPU_EmathRegion
 * \param  startAddr    a value of EMATH protection region n start address.
 */
static inline void SMPU_setEmathRegionStartAddr (SMPU_TypeDef *smpu, SMPU_EmathRegion region, uint32_t startAddr)
{
    WRITE_REG (smpu->SEMATH[region].WORDVAL, (startAddr & SMPU_SEMATH_SEMATH_M));
}

/**
 * \brief  Sets the EMATH Memory Protection Region n End Address in the SMPU
 * \note   This function sets the EMATH memory protection region n end address 
 *         of the SMPU.
 *
 * \param  smpu       smpu pointer to a SMPU_TypeDef structure
 *                     - SMPU: SMPU base address index
 * \param  region     The region n of EMATH memory protection
 *                     This parameter can be any value of @ref SMPU_EmathRegion
 * \param  endAddr    a value of EMATH protection region n end address.
 */
static inline void SMPU_setEmathRegionEndAddr (SMPU_TypeDef *smpu, SMPU_EmathRegion region, uint32_t endAddr)
{
    WRITE_REG (smpu->EEMATH[region].WORDVAL, (endAddr & SMPU_EEMATH_EEMATH_M));
}

/**
 * \brief  Sets the EDMA1 region n Access Control in the SMPU
 * \note   This function sets the EDMA1 region n access control of the SMPU.
 *
 * \param  smpu           smpu pointer to a SMPU_TypeDef structure
 *                         - SMPU: SMPU base address index
 * \param  region         The region n of EDMA1 memory protection
 *                         This parameter can be any value of @ref SMPU_EdmaRegion
 * \param  protectMode    The protection mode of the SMPU.
 *                         This parameter can be any value of @ref SMPU_ProtectMode
 * \param  protectEn      The protection enable of this region.
 *                         true: Region n MPU protection is effective.
 *                         false: Region n MPU protection is ineffective
 */
static inline void SMPU_setEdma1AccessCtrl (SMPU_TypeDef *smpu, SMPU_EdmaRegion region, 
                                            SMPU_ProtectMode protectMode, bool protectEn)
{
    volatile uint32_t regionShift = (region << 2U);
    MODIFY_REG (smpu->EDMA1AC.WORDVAL, (0x7UL << regionShift), 
                ((uint32_t)protectMode | (uint32_t)protectEn) << regionShift);
}

/**
 * \brief  Sets the EDMA2 region n Access Control in the SMPU
 * \note   This function sets the EDMA2 region n access control of the SMPU.
 *
 * \param  smpu           smpu pointer to a SMPU_TypeDef structure
 *                         - SMPU: SMPU base address index
 * \param  region         The region n of EDMA2 memory protection
 *                         This parameter can be any value of @ref SMPU_EdmaRegion
 * \param  protectMode    The protection mode of the SMPU.
 *                         This parameter can be any value of @ref SMPU_ProtectMode
 * \param  protectEn      The protection enable of this region.
 *                         true: Region n MPU protection is effective.
 *                         false: Region n MPU protection is ineffective
 */
static inline void SMPU_setEdma2AccessCtrl (SMPU_TypeDef *smpu, SMPU_EdmaRegion region, 
                                            SMPU_ProtectMode protectMode, bool protectEn)
{
    volatile uint32_t regionShift = (region << 2U);
    MODIFY_REG (smpu->EDMA2AC.WORDVAL, (0x7UL << regionShift), 
                ((uint32_t)protectMode | (uint32_t)protectEn) << regionShift);
}

/**
 * \brief  Sets the AES region n Access Control in the SMPU
 * \note   This function sets the AES region n access control of the SMPU.
 *
 * \param  smpu           smpu pointer to a SMPU_TypeDef structure
 *                         - SMPU: SMPU base address index
 * \param  region         The region n of AES memory protection
 *                         This parameter can be any value of @ref SMPU_AesRegion
 * \param  protectMode    The protection mode of the SMPU.
 *                         This parameter can be any value of @ref SMPU_ProtectMode
 * \param  protectEn      The protection enable of this region.
 *                         true: Region n MPU protection is effective.
 *                         false: Region n MPU protection is ineffective
 */
static inline void SMPU_setAesAccessCtrl (SMPU_TypeDef *smpu, SMPU_AesRegion region, 
                                            SMPU_ProtectMode protectMode, bool protectEn)
{
    volatile uint32_t regionShift = (region << 2U);
    MODIFY_REG (smpu->AESAC.WORDVAL, (0x7UL << regionShift), 
                ((uint32_t)protectMode | (uint32_t)protectEn) << regionShift);
}

/**
 * \brief  Sets the EMATH region n Access Control in the SMPU
 * \note   This function sets the EMATH region n access control of the SMPU.
 *
 * \param  smpu           smpu pointer to a SMPU_TypeDef structure
 *                         - SMPU: SMPU base address index
 * \param  region         The region n of EMATH memory protection
 *                         This parameter can be any value of @ref SMPU_EmathRegion
 * \param  protectMode    The protection mode of the SMPU.
 *                         This parameter can be any value of @ref SMPU_ProtectMode
 * \param  protectEn      The protection enable of this region.
 *                         true: Region n MPU protection is effective.
 *                         false: Region n MPU protection is ineffective
 */
static inline void SMPU_setEmathAccessCtrl (SMPU_TypeDef *smpu, SMPU_EmathRegion region, 
                                            SMPU_ProtectMode protectMode, bool protectEn)
{
    volatile uint32_t regionShift = (region << 2U);
    MODIFY_REG (smpu->EMATHAC.WORDVAL, (0x7UL << regionShift), 
                ((uint32_t)protectMode | (uint32_t)protectEn) << regionShift);
}

/**
 * \brief  Gets the EDMA1 Error Status Register Value in the SMPU
 * \note   This function gets the EDMA1 error status register value
 *         of the SMPU.
 *
 * \param  smpu  smpu pointer to a SMPU_TypeDef structure
 *                 - SMPU: SMPU base address index
 * \return Returns the value of EDMA1 error status.
 */
static inline uint8_t SMPU_getEdma1ErrStatus (SMPU_TypeDef *smpu)
{
    return (uint8_t)(smpu->EDMA1ESR.WORDVAL);
}

/**
 * \brief  Gets the EDMA2 Error Status Register Value in the SMPU
 * \note   This function gets the EDMA2 error status register value
 *         of the SMPU.
 *
 * \param  smpu  smpu pointer to a SMPU_TypeDef structure
 *                 - SMPU: SMPU base address index
 * \return Returns the value of EDMA2 error status.
 */
static inline uint8_t SMPU_getEdma2ErrStatus (SMPU_TypeDef *smpu)
{
    return (uint8_t)(smpu->EDMA2ESR.WORDVAL);
}

/**
 * \brief  Gets the AES Error Status Register Value in the SMPU
 * \note   This function gets the AES error status register value
 *         of the SMPU.
 *
 * \param  smpu  smpu pointer to a SMPU_TypeDef structure
 *                 - SMPU: SMPU base address index
 * \return Returns the value of AES error status.
 */
static inline uint8_t SMPU_getAesErrStatus (SMPU_TypeDef *smpu)
{
    return (uint8_t)(smpu->AESESR.WORDVAL);
}

/**
 * \brief  Gets the EMATH Error Status Register Value in the SMPU
 * \note   This function gets the EMATH error status register value
 *         of the SMPU.
 *
 * \param  smpu  smpu pointer to a SMPU_TypeDef structure
 *                 - SMPU: SMPU base address index
 * \return Returns the value of EMATH error status.
 */
static inline uint8_t SMPU_getEmathErrStatus (SMPU_TypeDef *smpu)
{
    return (uint8_t)(smpu->EMATHESR.WORDVAL);
}

/**
 * \brief  Clears the EDMA1 Error Status Register in the SMPU
 * \note   This function clears the EDMA1 Error Status register 
 *         of the SMPU.
 *
 * \param  smpu   smpu pointer to a SMPU_TypeDef structure
 *                  - SMPU: SMPU base address index
 * \param  clear  A value used to clear the EDMA1 error status.
 */
static inline void SMPU_clearEdma1ErrStatus (SMPU_TypeDef *smpu, uint8_t clear)
{
    WRITE_REG (smpu->EDMA1ECLR.WORDVAL, clear & 0x000000FFU);
    __DSB();
}

/**
 * \brief  Clears the EDMA2 Error Status Register in the SMPU
 * \note   This function clears the EDMA2 Error Status register 
 *         of the SMPU.
 *
 * \param  smpu   smpu pointer to a SMPU_TypeDef structure
 *                  - SMPU: SMPU base address index
 * \param  clear  A value used to clear the EDMA2 error status.
 */
static inline void SMPU_clearEdma2ErrStatus (SMPU_TypeDef *smpu, uint8_t clear)
{
    WRITE_REG (smpu->EDMA2ECLR.WORDVAL, clear & 0x000000FFU);
    __DSB();
}

/**
 * \brief  Clears the AES Error Status Register in the SMPU
 * \note   This function clears the AES Error Status register 
 *         of the SMPU.
 *
 * \param  smpu   smpu pointer to a SMPU_TypeDef structure
 *                  - SMPU: SMPU base address index
 * \param  clear  A value used to clear the AES error status.
 */
static inline void SMPU_clearAesErrStatus (SMPU_TypeDef *smpu, uint8_t clear)
{
    WRITE_REG (smpu->AESECLR.WORDVAL, clear & 0x0000000FUL);
    __DSB();
}

/**
 * \brief  Clears the EMATH Error Status Register in the SMPU
 * \note   This function clears the EMATH Error Status register 
 *         of the SMPU.
 *
 * \param  smpu   smpu pointer to a SMPU_TypeDef structure
 *                  - SMPU: SMPU base address index
 * \param  clear  A value used to clear the EMATH error status.
 */
static inline void SMPU_clearEmathErrStatus (SMPU_TypeDef *smpu, uint8_t clear)
{
    WRITE_REG (smpu->EMATHECLR.WORDVAL, (clear & 0x0000000FUL));
    __DSB();
}

/**
 * \brief  Selects the EDMA1_OAD mode of the control register in the SMPU
 * \note   This function selects the EDMA1_OAD mode of the control register 
 *         in the SMPU.
 *
 * \param  smpu  smpu pointer to a SMPU_TypeDef structure
 *                 - SMPU: SMPU base address index
 * \param  mode  the value is used to select the mode to be executed 
 *               after the violation
 */
static inline void SMPU_selectEdma1ActionMode (SMPU_TypeDef *smpu, SMPU_ViolationAction mode)
{
    if (mode != RES_SET_DISABLE)
    {
        MODIFY_REG(smpu->CONTRL.WORDVAL, SMPU_CONTRL_EDMA1OAD_M,
                   (((uint32_t)mode << SMPU_CONTRL_EDMA1OAD_S) | SMPU_CONTRL_KEY_VAL));
    }
}

/**
 * \brief  Selects the EDMA2_OAD mode of the control register in the SMPU
 * \note   This function selects the EDMA2_OAD mode of the control register 
 *         in the SMPU.
 *
 * \param  smpu  smpu pointer to a SMPU_TypeDef structure
 *                 - SMPU: SMPU base address index
 * \param  mode  the value is used to select the mode to be executed 
 *               after the violation
 */
static inline void SMPU_selectEdma2ActionMode (SMPU_TypeDef *smpu, SMPU_ViolationAction mode)
{
    if (mode != RES_SET_DISABLE)
    {
        MODIFY_REG(smpu->CONTRL.WORDVAL, SMPU_CONTRL_EDMA2OAD_M,
                   (((uint32_t)mode << SMPU_CONTRL_EDMA2OAD_S) | SMPU_CONTRL_KEY_VAL));
    }
}

/**
 * \brief  Selects the AES_OAD mode of the control register in the SMPU
 * \note   This function selects the AES_OAD mode of the control register 
 *         in the SMPU.
 *
 * \param  smpu  smpu pointer to a SMPU_TypeDef structure
 *                 - SMPU: SMPU base address index
 * \param  mode  the value is used to select the mode to be executed 
 *               after the violation
 */
static inline void SMPU_selectAesActionMode (SMPU_TypeDef *smpu, SMPU_ViolationAction mode)
{
    if (mode != RES_SET_DISABLE)
    {
        MODIFY_REG(smpu->CONTRL.WORDVAL, SMPU_CONTRL_AESOAD_M, 
                   (((uint32_t)mode << SMPU_CONTRL_AESOAD_S) | SMPU_CONTRL_KEY_VAL));
    }
}

/**
 * \brief  Selects the EMATH_OAD mode of the control register in the SMPU
 * \note   This function selects the EMATH_OAD mode of the control register 
 *         in the SMPU.
 *
 * \param  smpu  smpu pointer to a SMPU_TypeDef structure
 *                 - SMPU: SMPU base address index
 * \param  mode  the value is used to select the mode to be executed 
 *               after the violation
 */
static inline void SMPU_selectEmathActionMode (SMPU_TypeDef *smpu, SMPU_ViolationAction mode)
{
    if (mode != RES_SET_DISABLE)
    {
        MODIFY_REG(smpu->CONTRL.WORDVAL, SMPU_CONTRL_EMATHOAD_M,
                   (((uint32_t)mode << SMPU_CONTRL_EMATHOAD_S) | SMPU_CONTRL_KEY_VAL));
    }
}

/**
 * \brief  Enable the MPU monitoring function of EDMA1 of SMPU
 * \note   This function enables the MPU monitoring function of EDMA1 of SMPU.
 *
 * \param  smpu  smpu pointer to a SMPU_TypeDef structure
 *                 - SMPU: SMPU base address index
 */
static inline void SMPU_enableEdma1MpuMonitor (SMPU_TypeDef *smpu)
{
    SET_BIT(smpu->CONTRL.WORDVAL, (SMPU_CONTRL_EDMA1EN_M | SMPU_CONTRL_KEY_VAL));
}

/**
 * \brief  Disable the MPU monitoring function of EDMA1 of SMPU
 * \note   This function disables the MPU monitoring function of EDMA1 of SMPU.
 *
 * \param  smpu  smpu pointer to a SMPU_TypeDef structure
 *                 - SMPU: SMPU base address index
 */
static inline void SMPU_disableEdma1MpuMonitor (SMPU_TypeDef *smpu)
{
    MODIFY_REG(smpu->CONTRL.WORDVAL, SMPU_CONTRL_EDMA1EN_M, SMPU_CONTRL_KEY_VAL);
}

/**
 * \brief  Enable the MPU monitoring function of EDMA2 of SMPU
 * \note   This function enables the MPU monitoring function of EDMA2 of SMPU.
 *
 * \param  smpu  smpu pointer to a SMPU_TypeDef structure
 *                 - SMPU: SMPU base address index
 */
static inline void SMPU_enableEdma2MpuMonitor (SMPU_TypeDef *smpu)
{
    SET_BIT(smpu->CONTRL.WORDVAL, (SMPU_CONTRL_EDMA2EN_M | SMPU_CONTRL_KEY_VAL));
}

/**
 * \brief  Disable the MPU monitoring function of EDMA2 of SMPU
 * \note   This function disables the MPU monitoring function of EDMA2 of SMPU.
 *
 * \param  smpu  smpu pointer to a SMPU_TypeDef structure
 *                 - SMPU: SMPU base address index
 */
static inline void SMPU_disableEdma2MpuMonitor (SMPU_TypeDef *smpu)
{
    MODIFY_REG(smpu->CONTRL.WORDVAL, SMPU_CONTRL_EDMA2EN_M, SMPU_CONTRL_KEY_VAL);
}

/**
 * \brief  Enable the MPU monitoring function of AES of SMPU
 * \note   This function enables the MPU monitoring function of AES of SMPU.
 *
 * \param  smpu  smpu pointer to a SMPU_TypeDef structure
 *                 - SMPU: SMPU base address index
 */
static inline void SMPU_enableAesMpuMonitor (SMPU_TypeDef *smpu)
{
    SET_BIT(smpu->CONTRL.WORDVAL, (SMPU_CONTRL_AESEN_M | SMPU_CONTRL_KEY_VAL));
}

/**
 * \brief  Disable the MPU monitoring function of AES of SMPU
 * \note   This function disables the MPU monitoring function of AES of SMPU.
 *
 * \param  smpu  smpu pointer to a SMPU_TypeDef structure
 *                 - SMPU: SMPU base address index
 */
static inline void SMPU_disableAesMpuMonitor (SMPU_TypeDef *smpu)
{
    MODIFY_REG(smpu->CONTRL.WORDVAL, SMPU_CONTRL_AESEN_M, SMPU_CONTRL_KEY_VAL);
}

/**
 * \brief  Enable the MPU monitoring function of EMATH of SMPU
 * \note   This function enables the MPU monitoring function of EMATH of SMPU.
 *
 * \param  smpu  smpu pointer to a SMPU_TypeDef structure
 *                 - SMPU: SMPU base address index
 */
static inline void SMPU_enableEmathMpuMonitor (SMPU_TypeDef *smpu)
{
    SET_BIT(smpu->CONTRL.WORDVAL, (SMPU_CONTRL_EMATHEN_M | SMPU_CONTRL_KEY_VAL));
}

/**
 * \brief  Disable the MPU monitoring function of EMATH of SMPU
 * \note   This function disables the MPU monitoring function of EMATH of SMPU.
 *
 * \param  smpu  smpu pointer to a SMPU_TypeDef structure
 *                 - SMPU: SMPU base address index
 */
static inline void SMPU_disableEmathMpuMonitor (SMPU_TypeDef *smpu)
{
    MODIFY_REG(smpu->CONTRL.WORDVAL, SMPU_CONTRL_EMATHEN_M, SMPU_CONTRL_KEY_VAL);
}


#ifdef __cplusplus
}
#endif


#endif /* __SMPU_H__ */
