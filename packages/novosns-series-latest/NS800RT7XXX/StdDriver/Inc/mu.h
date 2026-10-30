/**
  * @file       mu.h
  * @author     Alex-J
  * @brief      Header file for NS800RT7xxx MU module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __MU_H__
#define __MU_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/** @defgroup MU_EXPORTED_TYPES MU Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'MU' module.
  */

/** @defgroup MU_TR0_REGBIT MU TR0 register bits
  * @{
  * @brief  Macro definitions about MU_TR0 register bits definition.
  */
#define MU_TR0_DATA_S    (0UL)             /*!< DATA Bit Position (Bit 0) */
#define MU_TR0_DATA_M    (0xffffffffUL)    /*!< DATA (Bitfield-Mask: 0xffffffff) */

/**
  * @}
  */

/** @defgroup MU_TR1_REGBIT MU TR1 register bits
  * @{
  * @brief  Macro definitions about MU_TR1 register bits definition.
  */
#define MU_TR1_DATA_S    (0UL)             /*!< DATA Bit Position (Bit 0) */
#define MU_TR1_DATA_M    (0xffffffffUL)    /*!< DATA (Bitfield-Mask: 0xffffffff) */

/**
  * @}
  */

/** @defgroup MU_TR2_REGBIT MU TR2 register bits
  * @{
  * @brief  Macro definitions about MU_TR2 register bits definition.
  */
#define MU_TR2_DATA_S    (0UL)             /*!< DATA Bit Position (Bit 0) */
#define MU_TR2_DATA_M    (0xffffffffUL)    /*!< DATA (Bitfield-Mask: 0xffffffff) */

/**
  * @}
  */

/** @defgroup MU_TR3_REGBIT MU TR3 register bits
  * @{
  * @brief  Macro definitions about MU_TR3 register bits definition.
  */
#define MU_TR3_DATA_S    (0UL)             /*!< DATA Bit Position (Bit 0) */
#define MU_TR3_DATA_M    (0xffffffffUL)    /*!< DATA (Bitfield-Mask: 0xffffffff) */

/**
  * @}
  */

/** @defgroup MU_RR0_REGBIT MU RR0 register bits
  * @{
  * @brief  Macro definitions about MU_RR0 register bits definition.
  */
#define MU_RR0_DATA_S    (0UL)             /*!< DATA Bit Position (Bit 0) */
#define MU_RR0_DATA_M    (0xffffffffUL)    /*!< DATA (Bitfield-Mask: 0xffffffff) */

/**
  * @}
  */

/** @defgroup MU_RR1_REGBIT MU RR1 register bits
  * @{
  * @brief  Macro definitions about MU_RR1 register bits definition.
  */
#define MU_RR1_DATA_S    (0UL)             /*!< DATA Bit Position (Bit 0) */
#define MU_RR1_DATA_M    (0xffffffffUL)    /*!< DATA (Bitfield-Mask: 0xffffffff) */

/**
  * @}
  */

/** @defgroup MU_RR2_REGBIT MU RR2 register bits
  * @{
  * @brief  Macro definitions about MU_RR2 register bits definition.
  */
#define MU_RR2_DATA_S    (0UL)             /*!< DATA Bit Position (Bit 0) */
#define MU_RR2_DATA_M    (0xffffffffUL)    /*!< DATA (Bitfield-Mask: 0xffffffff) */

/**
  * @}
  */

/** @defgroup MU_RR3_REGBIT MU RR3 register bits
  * @{
  * @brief  Macro definitions about MU_RR3 register bits definition.
  */
#define MU_RR3_DATA_S    (0UL)             /*!< DATA Bit Position (Bit 0) */
#define MU_RR3_DATA_M    (0xffffffffUL)    /*!< DATA (Bitfield-Mask: 0xffffffff) */

/**
  * @}
  */

/** @defgroup MU_SR_REGBIT MU SR register bits
  * @{
  * @brief  Macro definitions about MU_SR register bits definition.
  */
#define MU_SR_FN_S      (0UL)             /*!< FN Bit Position Bit 0) */
#define MU_SR_FN_M      (0x7UL)           /*!< FN (Bitfield-Mask: 0x07) */
#define MU_SR_EP_S      (4UL)             /*!< EP Bit Position (Bit 4) */
#define MU_SR_EP_M      (0x10UL)          /*!< EP (Bitfield-Mask: 0x01) */
#define MU_SR_RS_S      (7UL)             /*!< RS Bit Position (Bit 7) */
#define MU_SR_RS_M      (0x80UL)          /*!< RS (Bitfield-Mask: 0x01) */
#define MU_SR_FUP_S     (8UL)             /*!< FUP Bit Position (Bit 8) */
#define MU_SR_FUP_M     (0x100UL)         /*!< FUP (Bitfield-Mask: 0x01) */
#define MU_SR_TEN_S     (20UL)            /*!< TEN Bit Position (Bit 20) */
#define MU_SR_TEN_M     (0xf00000UL)      /*!< TEN (Bitfield-Mask: 0x0f) */
#define MU_SR_RFN_S     (24UL)            /*!< RFN Bit Position (Bit 24) */
#define MU_SR_RFN_M     (0xf000000UL)     /*!< RFN (Bitfield-Mask: 0x0f) */
#define MU_SR_GIPN_S    (28UL)            /*!< GIPN Bit Position (Bit 28) */
#define MU_SR_GIPN_M    (0xf0000000UL)    /*!< GIPN (Bitfield-Mask: 0x0f) */

#define MU_SR_TE0_M     (0x800000UL)      /*!< TE0 (Bitfield-Mask: 0x01) */
#define MU_SR_TE1_M     (0x400000UL)      /*!< TE1 (Bitfield-Mask: 0x01) */
#define MU_SR_TE2_M     (0x200000UL)      /*!< TE2 (Bitfield-Mask: 0x01) */
#define MU_SR_TE3_M     (0x100000UL)      /*!< TE3 (Bitfield-Mask: 0x01) */

#define MU_SR_RF0_M     (0x8000000UL)     /*!< RF0 (Bitfield-Mask: 0x01) */
#define MU_SR_RF1_M     (0x4000000UL)     /*!< RF1 (Bitfield-Mask: 0x01) */
#define MU_SR_RF2_M     (0x2000000UL)     /*!< RF2 (Bitfield-Mask: 0x01) */
#define MU_SR_RF3_M     (0x1000000UL)     /*!< RF3 (Bitfield-Mask: 0x01) */

#define MU_SR_GIP0_M    (0x80000000UL)    /*!< GIP0 (Bitfield-Mask: 0x01) */
#define MU_SR_GIP1_M    (0x40000000UL)    /*!< GIP1 (Bitfield-Mask: 0x01) */
#define MU_SR_GIP2_M    (0x20000000UL)    /*!< GIP2 (Bitfield-Mask: 0x01) */
#define MU_SR_GIP3_M    (0x10000000UL)    /*!< GIP3 (Bitfield-Mask: 0x01) */

/**
  * @}
  */

/** @defgroup MU_CR_REGBIT MU CR register bits
  * @{
  * @brief  Macro definitions about MU_CR register bits definition.
  */
#define MU_CR_FN_S      (0UL)             /*!< FN (Bit 0) */
#define MU_CR_FN_M      (0x7UL)           /*!< FN (Bitfield-Mask: 0x07) */
#define MU_CR_MUR_S     (5UL)             /*!< MUR (Bit 5) */
#define MU_CR_MUR_M     (0x20UL)          /*!< MUR (Bitfield-Mask: 0x01) */
#define MU_CR_GIRN_S    (16UL)            /*!< GIRN (Bit 16) */
#define MU_CR_GIRN_M    (0xf0000UL)       /*!< GIRN (Bitfield-Mask: 0x0f) */
#define MU_CR_TIEN_S    (20UL)            /*!< TIEN (Bit 20) */
#define MU_CR_TIEN_M    (0xf00000UL)      /*!< TIEN (Bitfield-Mask: 0x0f) */
#define MU_CR_RIEN_S    (24UL)            /*!< RIEN (Bit 24) */
#define MU_CR_RIEN_M    (0xf000000UL)     /*!< RIEN (Bitfield-Mask: 0x0f) */
#define MU_CR_GIEN_S    (28UL)            /*!< GIEN (Bit 28) */
#define MU_CR_GIEN_M    (0xf0000000UL)    /*!< GIEN (Bitfield-Mask: 0x0f) */

#define MU_CR_GIR0_M    (0x80000UL)       /*!< GIR0 (Bitfield-Mask: 0x01) */
#define MU_CR_GIR1_M    (0x40000UL)       /*!< GIR1 (Bitfield-Mask: 0x01) */
#define MU_CR_GIR2_M    (0x20000UL)       /*!< GIR2 (Bitfield-Mask: 0x01) */
#define MU_CR_GIR3_M    (0x10000UL)       /*!< GIR3 (Bitfield-Mask: 0x01) */

#define MU_CR_TIE0_M    (0x800000UL)      /*!< TIE0 (Bitfield-Mask: 0x01) */
#define MU_CR_TIE1_M    (0x400000UL)      /*!< TIE1 (Bitfield-Mask: 0x01) */
#define MU_CR_TIE2_M    (0x200000UL)      /*!< TIE2 (Bitfield-Mask: 0x01) */
#define MU_CR_TIE3_M    (0x100000UL)      /*!< TIE3 (Bitfield-Mask: 0x01) */

#define MU_CR_RIE0_M    (0x8000000UL)     /*!< RIE0 (Bitfield-Mask: 0x01) */
#define MU_CR_RIE1_M    (0x4000000UL)     /*!< RIE1 (Bitfield-Mask: 0x01) */
#define MU_CR_RIE2_M    (0x2000000UL)     /*!< RIE2 (Bitfield-Mask: 0x01) */
#define MU_CR_RIE3_M    (0x1000000UL)     /*!< RIE3 (Bitfield-Mask: 0x01) */

#define MU_CR_GIE0_M    (0x80000000UL)    /*!< GIE0 (Bitfield-Mask: 0x01) */
#define MU_CR_GIE1_M    (0x40000000UL)    /*!< GIE1 (Bitfield-Mask: 0x01) */
#define MU_CR_GIE2_M    (0x20000000UL)    /*!< GIE2 (Bitfield-Mask: 0x01) */
#define MU_CR_GIE3_M    (0x10000000UL)    /*!< GIE3 (Bitfield-Mask: 0x01) */

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
 * \brief  Sets the data to Tranfer Register 0 of CPU1(or CPU2).
 * \note   This function sets the data to transfer register 0 of CPU1(or CPU2)
 * \param  mu      mu pointer to a MU_TypeDef structure
 *                   - MU: MU base address index
 * \param  data    a value that cpu1(or cpu2) wants to send out 
 */
static inline void MU_setTransmitRegister0 (MU_TypeDef *mu, uint32_t data)
{
    WRITE_REG(mu->TR0.WORDVAL, data);
}

/**
 * \brief  Sets the data to Tranfer Register 1 of CPU1(or CPU2).
 * \note   This function sets the data to transfer register 1 of CPU1(or CPU2)
 * \param  mu      mu pointer to a MU_TypeDef structure
 *                   - MU: MU base address index
 * \param  data    a value that cpu1(or cpu2) wants to send out 
 */
static inline void MU_setTransmitRegister1 (MU_TypeDef *mu, uint32_t data)
{
    WRITE_REG(mu->TR1.WORDVAL, data);
}

/**
 * \brief  Sets the data to Tranfer Register 2 of CPU1(or CPU2).
 * \note   This function sets the data to transfer register 2 of CPU1(or CPU2)
 * \param  mu      mu pointer to a MU_TypeDef structure
 *                   - MU: MU base address index
 * \param  data    a value that cpu1(or cpu2) wants to send out 
 */
static inline void MU_setTransmitRegister2 (MU_TypeDef *mu, uint32_t data)
{
    WRITE_REG(mu->TR2.WORDVAL, data);
}

/**
 * \brief  Sets the data to Tranfer Register 3 of CPU1(or CPU2).
 * \note   This function sets the data to transfer register 3 of CPU1(or CPU2)
 * \param  mu      mu pointer to a MU_TypeDef structure
 *                   - MU: MU base address index
 * \param  data    a value that cpu1(or cpu2) wants to send out 
 */
static inline void MU_setTransmitRegister3 (MU_TypeDef *mu, uint32_t data)
{
    WRITE_REG(mu->TR3.WORDVAL, data);
}

/**
 * \brief  Gets the data from Receive Register 0 of CPU1(or CPU2).
 * \note   This function gets the data from receive register 0 of CPU1(or CPU2)
 * \param  mu     mu pointer to a MU_TypeDef structure
 *                  - MU: MU base address index
 * 
 * \return Returns the receive register 0 data.
 */
static inline uint32_t MU_getReceiveRegister0 (MU_TypeDef *mu)
{
    return (mu->RR0.WORDVAL);
}

/**
 * \brief  Gets the data from Receive Register 1 of CPU1(or CPU2).
 * \note   This function gets the data from receive register 1 of CPU1(or CPU2)
 * \param  mu    mu pointer to a MU_TypeDef structure
 *                 - MU: MU base address index
 * 
 * \return Returns the receive register 1 data.
 */
static inline uint32_t MU_getReceiveRegister1 (MU_TypeDef *mu)
{
    return (mu->RR1.WORDVAL);
}

/**
 * \brief  Gets the data from Receive Register 2 of CPU1(or CPU2).
 * \note   This function gets the data from receive register 2 of CPU1(or CPU2)
 * \param  mu    mu pointer to a MU_TypeDef structure
 *                 - MU: MU base address index
 * 
 * \return Returns the receive register 2 data.
 */
static inline uint32_t MU_getReceiveRegister2 (MU_TypeDef *mu)
{
    return (mu->RR2.WORDVAL);
}

/**
 * \brief  Gets the data from Receive Register 3 of CPU1(or CPU2).
 * \note   This function gets the data from receive register 3 of CPU1(or CPU2)
 * \param  mu    mu pointer to a MU_TypeDef structure
 *                 - MU: MU base address index
 * 
 * \return Returns the receive register 3 data.
 */
static inline uint32_t MU_getReceiveRegister3 (MU_TypeDef *mu)
{
    return (mu->RR3.WORDVAL);
}

/**
 * \brief  Gets the data from status Register of CPU1(or CPU2).
 * \note   This function gets the data from status register of CPU1(or CPU2)
 * \param  mu    mu pointer to a MU_TypeDef structure
 *                 - MU: MU base address index
 * 
 * \return Returns the status register data.
 */
static inline uint32_t MU_getStatusRegister (MU_TypeDef *mu)
{
    return (mu->SR.WORDVAL);
}

/**
 * \brief  Clears the status to status Register of CPU1(or CPU2).
 * \note   This function clears the status to status register of CPU1(or CPU2)
 * \param  mu       mu pointer to a MU_TypeDef structure
 *                    - MU: MU base address index
 * \param  clear    a value that you want to clear
 */
static inline void MU_clearStatusRegister (MU_TypeDef *mu, uint32_t clear)
{
    SET_BIT(mu->SR.WORDVAL, clear);
}

/**
 * \brief  Sets the parameters to Control Register of CPU1(or CPU2).
 * \note   This function sets the data to control register 3 of CPU1(or CPU2)
 * \param  mu        mu pointer to a MU_TypeDef structure
 *                     - MU: MU base address index
 * \param  config    a value that cpu1(or cpu2) wants to send out 
 */
static inline void MU_setControlRegister (MU_TypeDef *mu, uint32_t config)
{
    SET_BIT(mu->CR.WORDVAL, config);
}

/**
 * \brief  Sets the CPU Flag to Control Register of CPU1(or CPU2).
 * \note   This function sets the cpu flag to control register of CPU1(or CPU2).
 *         If you set the cpu2 flag, cpu1 will read this flag form the SR register.
 *         The same goes for the other way around.
 * 
 * \param  mu      mu pointer to a MU_TypeDef structure
 *                   - MU: MU base address index
 * \param  flag    a value that cpu1(or cpu2) flag wants to set.
 *                   Flag Scop: 0, 1, 2
 */
static inline void MU_setCpuFlag (MU_TypeDef *mu, uint8_t flag)
{
    MODIFY_REG(mu->CR.WORDVAL, MU_SR_FN_M, (uint32_t)flag);
}

/**
 * \brief  Gets the CPU Flag from Status Register of CPU1(or CPU2).
 * \note   This function gets the cpu flag from status register of CPU1(or CPU2)
 *         If you set the cpu2 flag, cpu1 will read this flag form the SR register.
 *         The same goes for the other way around.
 * 
 * \param  mu    mu pointer to a MU_TypeDef structure
 *                 - MU: MU base address index
 * 
 * \return Returns the CPU flag form the SR register.
 */
static inline uint8_t MU_getCpuFlag (MU_TypeDef *mu)
{
    return (uint8_t)(mu->SR.WORDVAL & MU_SR_FN_M);
}


#ifdef __cplusplus
}
#endif

#endif /* __MU_H__ */
