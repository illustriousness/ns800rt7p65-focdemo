/**
  * @file       mcm.h
  * @author     Alex-J, yangjun
  * @brief      Header file for NS800RT7xxx mcm module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __MCM_H__
#define __MCM_H__


#ifdef __cplusplus
extern "C"
{
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 *******************************************************************************/

/** @defgroup MCM_EXPORTED_TYPES MCM Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'MCM' module.
  */

/** @defgroup MCM_COREINDEX MCU Module's Core Index
  * @{
  * @brief  Values is used to represent the index of number of the MCU core.
  */
typedef enum {
    MCM_CORE_NONE = 0U,    /*!< Reset initial value */
    MCM_CORE_1,              /*!< MCU Core 1 */
    MCM_CORE_2               /*!< MCU Core 2 */
} MCM_CoreIndex;

/**
  * @}
  */

/** @defgroup MCM_CACHEERRINTSEL MCU MCM cache error interrupt selection
  * @{
  * @brief  Macro definitions about MCU MCM cache error interrupt selection.
  */
typedef enum {
    MCM_CACHE_TAG_RAM_CORRECT_INT = 0U,    /*!< Cache tag RAM correctable error interrupt */
    MCM_CACHE_TAG_RAM_UNCORRECT_INT,       /*!< Cache tag RAM uncorrectable error interrupt */
    MCM_CACHE_DATA_RAM_CORRECT_INT,        /*!< Cache data RAM correctable error interrupt */
    MCM_CACHE_DATA_RAM_UNCORRECT_INT       /*!< Cache data RAM uncorrectable error interrupt */
} MCM_CacheErrIntSel;

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup MCM_ITCM_VRTLADDR COREx ITCM Virtual Address
  * @{
  * @brief  Macro definitions about Corex itcm virtual address.
  */
#define MCM_ITCM_VRTLADDR_START        (0x00000000UL)    /*!< CORE1~2 ITCM Virtual Start Address */
#define MCM_ITCM_VRTLADDR_END          (0x0001FFFFUL)    /*!< CORE1~2 ITCM Virtual End Address */

/**
  * @}
  */

/** @defgroup MCM_DTCM_VRTLADDR COREx DTCM Virtual Address
  * @{
  * @brief  Macro definitions about Corex dtcm virtual address.
  */
#define MCM_DTCM_VRTLADDR_START        (0x20000000UL)    /*!< CORE1~2 DTCM Virtual Start Address */
#define MCM_DTCM_VRTLADDR_END          (0x2001FFFFUL)    /*!< CORE1~2 DTCM Virtual End Address */

/**
  * @}
  */

/** @defgroup MCM_COREx_TCM_ABSADDROFFSET MCU Core x ITCM or DTCM
  *            Absolute Address Offset Value (x = 1 or 2)
  * @{
  * @brief  Macro definitions about COREx itcm or dtcm absolute address offset.
  */
#define MCM_CORE1_TCM_ABSADDR_OFFSET    (0x01000000UL)    /*!< CORE1 ITCM or DTCM Absolute Address Offset */
#define MCM_CORE2_TCM_ABSADDR_OFFSET    (0x01020000UL)    /*!< CORE2 ITCM or DTCM Absolute Address Offset */

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
 * \brief  Gets the CORE ID.
 * \note   This function returns the CORE index num from the MCM_CPUID Register.
 *
 * \param  mcm  mcm pointer to a MCM_TypeDef structure
 *               - MCM: MCM base address index
 * \return Returns the value of MCU core index. Enum from \e MCM_CoreIndex
 */
static inline MCM_CoreIndex MCM_getCoreIndex (MCM_TypeDef *mcm)
{
    return (MCM_CoreIndex)READ_BIT((mcm->CPUID.WORDVAL >> MCM_CPUID_CPUID_S), MCM_CPUID_CPUID_M);
}

/**
 * \brief  Sets the MCU software higher priority in AHB bus.
 *
 * \param  mcm  mcm pointer to a MCM_TypeDef structure
 *               - MCM: MCM base address index
 */
static inline void MCM_setCoreAhbHighPrioIsSW (MCM_TypeDef *mcm)
{
    CLEAR_BIT(mcm->CPCR.WORDVAL, MCM_CPCR_AHBSPRI_M);
}

/**
 * \brief  Sets the MCU interface higher priority in AHB bus.
 *
 * \param  mcm  mcm pointer to a MCM_TypeDef structure
 *               - MCM: MCM base address index
 */
static inline void MCM_setCoreAhbHighPrioIsIF (MCM_TypeDef *mcm)
{
    SET_BIT(mcm->CPCR.WORDVAL, MCM_CPCR_AHBSPRI_M);
}

/**
 * \brief  Gets the MCU AHB bus priority.
 *
 * \param  mcm  mcm pointer to a MCM_TypeDef structure
 *               - MCM: MCM base address index
 * \return Returns the MCU AHB bus priority.
 *               - 0: software high priority
 *               - 1: interface high priority
 */
static inline uint32_t MCM_getCoreAhbPrioCfg (MCM_TypeDef *mcm)
{
    return READ_BIT(mcm->CPCR.WORDVAL, MCM_CPCR_AHBSPRI_M) >> MCM_CPCR_AHBSPRI_S;
}

/**
 * \brief  MCM get status.
 *
 * \param  mcm     mcm pointer to a MCM_TypeDef structure
 *                  - MCM: MCM base address index
 * \return Returns the MCM status.
 */
static inline uint16_t MCM_getStatus (MCM_TypeDef *mcm)
{
    uint16_t status_msk = (MCM_ISCR_ICDET_M | MCM_ISCR_DCDET_M | MCM_ISCR_WABS_M | MCM_ISCR_WABSO_M | 
                          MCM_ISCR_FIOC_M | MCM_ISCR_FDZC_M | MCM_ISCR_FOFC_M | MCM_ISCR_FUFC_M | 
                          MCM_ISCR_FIXC_M | MCM_ISCR_FIDC_M );

    return (uint16_t)(READ_BIT(mcm->ISCR.WORDVAL, status_msk));
}

/**
 * \brief  Clear the MCM error status.
 *
 * \param  mcm      mcm pointer to a MCM_TypeDef structure
 *                   - MCM: MCM base address index
 * \param  clear    the value is used to clear MCM error status
 *                   This parameter can be one of the following:
 *                   - MCM_ISCR_ICDET_M
 *                   - MCM_ISCR_DCDET_M
 *                   - MCM_ISCR_WABS_M
 */
static inline void MCM_clearErrorStatus (MCM_TypeDef *mcm, uint32_t clear)
{
    uint32_t status_msk = (MCM_ISCR_ICDET_M | MCM_ISCR_DCDET_M | MCM_ISCR_WABS_M);

    SET_BIT(mcm->ISCR.WORDVAL, (uint32_t)(clear & status_msk));
}

/**
 * \brief  Enable the MCM interrupt.
 *
 * \param  mcm       mcm pointer to a MCM_TypeDef structure
 *                    - MCM: MCM base address index
 * \param  enable    the value is used to enable MCM interrupt
 *                    This parameter can be one of the following:
 *                    - MCM_ISCR_WABE_M
 *                    - MCM_ISCR_FIOCE_M
 *                    - MCM_ISCR_FDZCE_M
 *                    - MCM_ISCR_FOFCE_M
 *                    - MCM_ISCR_FUFCE_M
 *                    - MCM_ISCR_FIXCE_M
 *                    - MCM_ISCR_FIDCE_M
 */
static inline void MCM_enableCoreMCMInterrupt (MCM_TypeDef *mcm, uint32_t enable)
{
    uint32_t en_msk = (MCM_ISCR_WABE_M | MCM_ISCR_FIOCE_M | MCM_ISCR_FDZCE_M | 
                       MCM_ISCR_FOFCE_M | MCM_ISCR_FUFCE_M | MCM_ISCR_FIXCE_M | MCM_ISCR_FIDCE_M);

    WRITE_REG(mcm->ISCR.WORDVAL, (enable & en_msk));
}

/**
 * \brief  Disable the MCM interrupt.
 *
 * \param  mcm        mcm pointer to a MCM_TypeDef structure
 *                     - MCM: MCM base address index
 * \param  disable    the value is used to disable MCM interrupt
 *                     This parameter can be one of the following:
 *                      - MCM_ISCR_WABE_M
 *                      - MCM_ISCR_FIOCE_M
 *                      - MCM_ISCR_FDZCE_M
 *                      - MCM_ISCR_FOFCE_M
 *                      - MCM_ISCR_FUFCE_M
 *                      - MCM_ISCR_FIXCE_M
 *                      - MCM_ISCR_FIDCE_M
 */
static inline void MCM_disableCoreMCMInterrupt (MCM_TypeDef *mcm, uint32_t disable)
{
    uint32_t dis_msk = (MCM_ISCR_WABE_M | MCM_ISCR_FIOCE_M | MCM_ISCR_FDZCE_M | 
                        MCM_ISCR_FOFCE_M | MCM_ISCR_FUFCE_M | MCM_ISCR_FIXCE_M | MCM_ISCR_FIDCE_M);

    CLEAR_BIT(mcm->ISCR.WORDVAL, (disable & dis_msk));
}

/**
 * \brief  Set MCM tick calibration
 *
 * \param  mcm      mcm pointer to a MCM_TypeDef structure
 *                   - MCM: MCM base address index
 * \param  calib    the value is used to set tick calibration.
 */
static inline void MCM_setTickCalibration (MCM_TypeDef *mcm, uint32_t calib)
{
    MODIFY_REG(mcm->CSTC.WORDVAL, MCM_CSTC_TENMS_M, (calib & MCM_CSTC_TENMS_M));
}

/**
 * \brief  Get MCM tick calibration
 *
 * \param  mcm    mcm pointer to a MCM_TypeDef structure
 *                 - MCM: MCM base address index
 * \return the value of the tick calibration.
 */
static inline uint32_t MCM_getTickCalibration (MCM_TypeDef *mcm)
{
    return READ_BIT(mcm->CSTC.WORDVAL, MCM_CSTC_TENMS_M);
}

/**
 * \brief  Set I-Cache error interrupt enable
 *
 * \param  mcm    mcm pointer to a MCM_TypeDef structure
 *                 - MCM: MCM base address index
 * \param  sel    the value is used to select cache error interrupt enable.
 */
static inline void MCM_setICacheErrorInterrupt (MCM_TypeDef *mcm, MCM_CacheErrIntSel sel)
{
    MODIFY_REG(mcm->CECR.WORDVAL, MCM_CECR_ICDETCE_M, (uint32_t)sel);
}

/**
 * \brief  Set D-Cache error interrupt enable
 *
 * \param  mcm    mcm pointer to a MCM_TypeDef structure
 *                 - MCM: MCM base address index
 * \param  sel    the value is used to select cache error interrupt enable.
 */
static inline void MCM_setDCacheErrorInterrupt (MCM_TypeDef *mcm, MCM_CacheErrIntSel sel)
{
    MODIFY_REG(mcm->CECR.WORDVAL, MCM_CECR_DCDETCE_M, (uint32_t)sel << MCM_CECR_DCDETCE_S);
}


#ifdef __cplusplus
}
#endif


#endif /* __MCM_H__ */
