/**
  * @file       flash.h
  * @author     xiacj
  * @brief      Header file for NS800RT7xxx flash module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __FLASH_H__
#define __FLASH_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_flash.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup FLASH_EXPORTED_TYPES FLASH Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'FLASH' module.
  */

/**
  * @}
  */

/** @defgroup FLASH_UNLOCK_KEYS FLASH registers / OptionBytes unlock keys
  * @{
  * @brief  Macro definitions about the unlock keys of the FLASH registers.
  */
#define FLASH_UNLOCKKEY1       (0x45670123UL)    /*!< FLASH regs/option unlock key1 */
#define FLASH_UNLOCKKEY2       (0xCDEF89ABUL)    /*!< FLASH regs/option unlock key2 */


/**
  * @}
  */

/** @defgroup FLASH_Operations FLASH Operations
  * @{
  * @brief  Macro definitions about the FLASH Operations.
  */
#define FLASH_OP_MASK      (0x37)    /*!< Mask of all operations */
#define FLASH_OP_PG        (0x01)    /*!< Mask of Prog */
#define FLASH_OP_PER       (0x02)    /*!< Mask of page erase */
#define FLASH_OP_MER       (0x04)    /*!< Mask of mass erase */
#define FLASH_OP_OPTPG     (0x10)    /*!< Mask of option prog */
#define FLASH_OP_OPTER     (0x20)    /*!< Mask of option erase */

/**
  * @}
  */

/** @defgroup FLASH_MEMORY_ADDRESS Flash memery addresses
  * @{
  * @brief  Macro definitions about the flash memory address.
  */
#define FLASH_BANK1_STARTADDR             (0x08000000UL)    /*!< Flash Bank1 Start Address */
#define FLASH_BANK1_ENDADDR               (0x0807FFFFUL)    /*!< Flash Bank1 End Address */
#define FLASH_BANK1_SIZE                  (0x00080000UL)    /*!< Flash Bank1 Size */
#define FLASH_BANK2_STARTADDR             (0x08080000UL)    /*!< Flash Bank2 Start Address */
#define FLASH_BANK2_ENDADDR               (0x080FFFFFUL)    /*!< Flash Bank2 End Address */
#define FLASH_BANK2_SIZE                  (0x00080000UL)    /*!< Flash Bank2 Size */
#define FLASH_OPTIONBYTES1_STARTADDR      (0x1FFFF800UL)    /*!< Option Bytes1 Start Address */
#define FLASH_OPTIONBYTES1_TAGADDR        (0x1FFFF803UL)    /*!< Option Bytes1 ValidTag Address */
#define FLASH_OPTIONBYTES1_ENDADDR        (0x1FFFFBFFUL)    /*!< Option Bytes1 End Address */
#define FLASH_OPTIONBYTES2_STARTADDR      (0x1FFFFC00UL)    /*!< Option Bytes2 Start Address */
#define FLASH_OPTIONBYTES2_TAGADDR        (0x1FFFFC03UL)    /*!< Option Bytes2 ValidTag Address */
#define FLASH_OPTIONBYTES2_ENDADDR        (0x1FFFFFFFUL)    /*!< Option Bytes2 End Address */
#define FLASH_OPTIONBYTES_SIZE            (1024UL)          /*!< Option Bytes Size */
#define FLASH_DATAFLASH_STARTADDR         (0x1FFF0000UL)    /*!< Data Flash Start Address */
#define FLASH_DATAFLASH_ENDADDR           (0x1FFF2FFFUL)    /*!< Data Flash End Address */
#define FLASH_DATAFLASH_SIZE              (12288UL)         /*!< Data Flash Size */
#define FLASH_SWAPTAG_ADDR                (0x1FFF33F0UL)    /*!< Swap Tag Address */
#define FLASH_SWAPCONFIGPAGE_STARTADDR    (0x1FFF3000UL)    /*!< Swap Config Page Start Address */
#define FLASH_SWAPCONFIGPAGE_ENDADDR      (0x1FFF33FFUL)    /*!< Swap Config Page End Address */
#define FLASH_SWAPCONFIGPAGE_SIZE         (1024UL)          /*!< Swap Config Page Size */

/**
  * @}
  */

/** @defgroup FLASH_LATENCY FLASH Latency 0-7
  * @{
  * @brief  Macro definitions about FLASH latency 0-7.
  */
typedef enum {
    FLASH_LATENCY_0 = 0UL,    /*!< FLASH Latency = 0 */
    FLASH_LATENCY_1,          /*!< FLASH Latency = 1 */
    FLASH_LATENCY_2,          /*!< FLASH Latency = 2 */
    FLASH_LATENCY_3,          /*!< FLASH Latency = 3 */
    FLASH_LATENCY_4,          /*!< FLASH Latency = 4 */
    FLASH_LATENCY_5,          /*!< FLASH Latency = 5 */
    FLASH_LATENCY_6,          /*!< FLASH Latency = 6 */
    FLASH_LATENCY_7           /*!< FLASH Latency = 7 */
} FLASH_Latency;

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
  * \brief  Set FLASH latency.
  * \param  latency    Flash Latency
  *                       This parameter can be any value of @ref FLASH_LATENCY
  */
static inline void FLASH_setLatency (FLASH_Latency latency)
{
    WRITE_REG(FLASH->ACR.WORDVAL, latency);
    __DSB();
}

/**
  * \brief  Unlock FLASH Area1 registers.
  */
static inline void FLASH_unlockRegs1 (void)
{
    WRITE_REG(FLASH->KEYR1.WORDVAL, FLASH_UNLOCKKEY1);
    WRITE_REG(FLASH->KEYR1.WORDVAL, FLASH_UNLOCKKEY2);
    __DSB();
}

/**
  * \brief  Unlock FLASH Area2 registers.
  */
static inline void FLASH_unlockRegs2 (void)
{
    WRITE_REG(FLASH->KEYR2.WORDVAL, FLASH_UNLOCKKEY1);
    WRITE_REG(FLASH->KEYR2.WORDVAL, FLASH_UNLOCKKEY2);
    __DSB();
}

/**
  * \brief  Lock FLASH Area1 registers.
  */
static inline void FLASH_lockRegs1 (void)
{
    __DSB();
    SET_BIT(FLASH->CR1.WORDVAL, FLASH_CR1_LOCK_M);
    __DSB();
}

/**
  * \brief  Lock FLASH Area2 registers.
  */
static inline void FLASH_lockRegs2 (void)
{
    __DSB();
    SET_BIT(FLASH->CR2.WORDVAL, FLASH_CR2_LOCK_M);
    __DSB();
}

/**
  * \brief  Unlock FLASH optionBytes.
  */
static inline void FLASH_unlockOptionBytes (void)
{
    WRITE_REG(FLASH->OPTKEYR.WORDVAL, FLASH_UNLOCKKEY1);
    WRITE_REG(FLASH->OPTKEYR.WORDVAL, FLASH_UNLOCKKEY2);
    __DSB();
}

/**
  * \brief  Lock FLASH OptionBytes by CR1.
  */
static inline void FLASH_lockOptionBytes1 (void)
{
    __DSB();
    CLEAR_BIT(FLASH->CR1.WORDVAL, FLASH_CR1_OPTEWEN_M);
    __DSB();
}

/**
  * \brief  Lock FLASH OptionBytes by CR2.
  */
static inline void FLASH_lockOptionBytes2 (void)
{
    __DSB();
    CLEAR_BIT(FLASH->CR2.WORDVAL, FLASH_CR2_OPTEWEN_M);
    __DSB();
}

/**
  * \brief  Enable FLASH Area1 Error Interrupt.
  */
static inline void FLASH_enableErrorInterrupt1 (void)
{
    __DSB();
    SET_BIT(FLASH->CR1.WORDVAL, FLASH_CR1_ERRIE_M);
    __DSB();
}

/**
  * \brief  Enable FLASH Area2 Error Interrupt.
  */
static inline void FLASH_enableErrorInterrupt2 (void)
{
    __DSB();
    SET_BIT(FLASH->CR2.WORDVAL, FLASH_CR2_ERRIE_M);
    __DSB();
}

/**
  * \brief  Disable FLASH Area1 Error Interrupt.
  */
static inline void FLASH_disableErrorInterrupt1 (void)
{
    __DSB();
    CLEAR_BIT(FLASH->CR1.WORDVAL, FLASH_CR1_ERRIE_M);
    __DSB();
}

/**
  * \brief  Disable FLASH Area2 Error Interrupt.
  */
static inline void FLASH_disableErrorInterrupt2 (void)
{
    __DSB();
    CLEAR_BIT(FLASH->CR2.WORDVAL, FLASH_CR2_ERRIE_M);
    __DSB();
}

/**
  * \brief  Enable FLASH Area1 Option Complete Interrupt.
  */
static inline void FLASH_enableOperationCompleteInterrupt1 (void)
{
    __DSB();
    SET_BIT(FLASH->CR1.WORDVAL, FLASH_CR1_EOPIE_M);
    __DSB();
}

/**
  * \brief  Enable FLASH Area2 Option Complete Interrupt.
  */
static inline void FLASH_enableOperationCompleteInterrupt2 (void)
{
    __DSB();
    SET_BIT(FLASH->CR2.WORDVAL, FLASH_CR2_EOPIE_M);
    __DSB();
}

/**
  * \brief  Disable FLASH Area1 Option Complete Interrupt.
  */
static inline void FLASH_disableOperationCompleteInterrupt1 (void)
{
    __DSB();
    CLEAR_BIT(FLASH->CR1.WORDVAL, FLASH_CR1_EOPIE_M);
    __DSB();
}

/**
  * \brief  Disable FLASH Area2 Option Complete Interrupt.
  */
static inline void FLASH_disableOperationCompleteInterrupt2 (void)
{
    __DSB();
    CLEAR_BIT(FLASH->CR2.WORDVAL, FLASH_CR2_EOPIE_M);
    __DSB();
}

/**
  * \brief  Enable FLASH Area1 ECC 1 bit Error Interrupt.
  */
static inline void FLASH_enableEcc1BitErrorInterrupt1 (void)
{
    __DSB();
    SET_BIT(FLASH->ECCCR1.WORDVAL, FLASH_ECCCR1_SNIE_M);
    __DSB();
}

/**
  * \brief  Enable FLASH Area2 ECC 1 bit Error Interrupt.
  */
static inline void FLASH_enableEcc1BitErrorInterrupt2 (void)
{
    __DSB();
    SET_BIT(FLASH->ECCCR2.WORDVAL, FLASH_ECCCR2_SNIE_M);
    __DSB();
}

/**
  * \brief  Disable FLASH Area1 ECC 1 bit Error Interrupt.
  */
static inline void FLASH_disableEcc1BitErrorInterrupt1 (void)
{
    __DSB();
    CLEAR_BIT(FLASH->ECCCR1.WORDVAL, FLASH_ECCCR1_SNIE_M);
    __DSB();
}

/**
  * \brief  Disable FLASH Area2 ECC 1 bit Error Interrupt.
  */
static inline void FLASH_disableEcc1BitErrorInterrupt2 (void)
{
    __DSB();
    CLEAR_BIT(FLASH->ECCCR2.WORDVAL, FLASH_ECCCR2_SNIE_M);
    __DSB();
}

/**
  * \brief  Enable FLASH Area1 ECC 2 bit Error Interrupt.
  */
static inline void FLASH_enableEcc2BitErrorInterrupt1 (void)
{
    __DSB();
    SET_BIT(FLASH->ECCCR1.WORDVAL, FLASH_ECCCR1_DBIE_M);
    __DSB();
}

/**
  * \brief  Enable FLASH Area2 ECC 2 bit Error Interrupt.
  */
static inline void FLASH_enableEcc2BitErrorInterrupt2 (void)
{
    __DSB();
    SET_BIT(FLASH->ECCCR2.WORDVAL, FLASH_ECCCR2_DBIE_M);
    __DSB();
}

/**
  * \brief  Disable FLASH Area1 ECC 2 bit Error Interrupt.
  */
static inline void FLASH_disableEcc2BitErrorInterrupt1 (void)
{
    __DSB();
    CLEAR_BIT(FLASH->ECCCR1.WORDVAL, FLASH_ECCCR1_DBIE_M);
    __DSB();
}

/**
  * \brief  Disable FLASH Area2 ECC 2 bit Error Interrupt.
  */
static inline void FLASH_disableEcc2BitErrorInterrupt2 (void)
{
    __DSB();
    CLEAR_BIT(FLASH->ECCCR2.WORDVAL, FLASH_ECCCR2_DBIE_M);
    __DSB();
}

/**
  * \brief  Clear FLASH Area1 Option Complete Flag.
  */
static inline void FLASH_clearOperationCompleteFlag1 (void)
{
    WRITE_REG(FLASH->SR1.WORDVAL, FLASH_SR1_EOP_M);
    __DSB();
}

/**
  * \brief  Clear FLASH Area2 Option Complete Flag.
  */
static inline void FLASH_clearOperationCompleteFlag2 (void)
{
    WRITE_REG(FLASH->SR2.WORDVAL, FLASH_SR2_EOP_M);
    __DSB();
}

/**
  * \brief  Clear FLASH Area1 Write Protect Error Flag.
  */
static inline void FLASH_clearProtectErrorFlag1 (void)
{
    WRITE_REG(FLASH->SR1.WORDVAL, FLASH_SR1_WRPRTERR_M);
    __DSB();
}

/**
  * \brief  Clear FLASH Area2 Write Protect Error Flag.
  */
static inline void FLASH_clearProtectErrorFlag2 (void)
{
    WRITE_REG(FLASH->SR2.WORDVAL, FLASH_SR2_WRPRTERR_M);
    __DSB();
}

/**
  * \brief  Clear FLASH Area1 Program Error Flag.
  */
static inline void FLASH_clearProgramErrorFlag1 (void)
{
    WRITE_REG(FLASH->SR1.WORDVAL, FLASH_SR1_PGERR_M);
    __DSB();
}

/**
  * \brief  Clear FLASH Area2 Program Error Flag.
  */
static inline void FLASH_clearProgramErrorFlag2 (void)
{
    WRITE_REG(FLASH->SR2.WORDVAL, FLASH_SR2_PGERR_M);
    __DSB();
}

/**
  * \brief  Clear FLASH Area1 ECC 1 bit Error Flag.
  */
static inline void FLASH_clearEcc1BitErrorFlag1 (void)
{
    __DSB();
    SET_BIT(FLASH->ECCCR1.WORDVAL, FLASH_ECCCR1_SNFLAG_M);
    __DSB();
}

/**
  * \brief  Clear FLASH Area2 ECC 1 bit Error Flag.
  */
static inline void FLASH_clearEcc1BitErrorFlag2 (void)
{
    __DSB();
    SET_BIT(FLASH->ECCCR2.WORDVAL, FLASH_ECCCR2_SNFLAG_M);
    __DSB();
}

/**
  * \brief  Clear FLASH Area1 ECC 2 bit Error Flag.
  */
static inline void FLASH_clearEcc2BitErrorFlag1 (void)
{
    __DSB();
    SET_BIT(FLASH->ECCCR1.WORDVAL, FLASH_ECCCR1_DBFLAG_M);
    __DSB();
}

/**
  * \brief  Clear FLASH Area2 ECC 2 bit Error Flag.
  */
static inline void FLASH_clearEcc2BitErrorFlag2 (void)
{
    __DSB();
    SET_BIT(FLASH->ECCCR2.WORDVAL, FLASH_ECCCR2_DBFLAG_M);
    __DSB();
}

/**
  * \brief  Get FLASH Area1 Option Complete Flag.
  * \return Returns bit value of FLASH_SR1.EOP bit
  *           - uint32_t: 0: FLASH_SR1.EOP = 0
  *                       x: FLASH_SR1.EOP = 1
  */
static inline uint32_t FLASH_getOperationCompleteFlag1 (void)
{
    return READ_BIT(FLASH->SR1.WORDVAL, FLASH_SR1_EOP_M);
}

/**
  * \brief  Get FLASH Area2 Option Complete Flag.
  * \return Returns bit value of FLASH_SR2.EOP bit
  *           - uint32_t: 0: FLASH_SR2.EOP = 0
  *                       x: FLASH_SR2.EOP = 1
  */
static inline uint32_t FLASH_getOperationCompleteFlag2 (void)
{
    return READ_BIT(FLASH->SR2.WORDVAL, FLASH_SR2_EOP_M);
}

/**
  * \brief  Get FLASH Area1 Write Protect Error Flag.
  * \return Returns bit value of FLASH_SR1.WRPRTERR bit
  *           - uint32_t: 0: FLASH_SR1.WRPRTERR = 0
  *                       x: FLASH_SR1.WRPRTERR = 1
  */
static inline uint32_t FLASH_getProtectErrorFlag1 (void)
{
    return READ_BIT(FLASH->SR1.WORDVAL, FLASH_SR1_WRPRTERR_M);
}

/**
  * \brief  Get FLASH Area2 Write Protect Error Flag.
  * \return Returns bit value of FLASH_SR2.WRPRTERR bit
  *           - uint32_t: 0: FLASH_SR2.WRPRTERR = 0
  *                       x: FLASH_SR2.WRPRTERR = 1
  */
static inline uint32_t FLASH_getProtectErrorFlag2 (void)
{
    return READ_BIT(FLASH->SR2.WORDVAL, FLASH_SR2_WRPRTERR_M);
}

/**
  * \brief  Get FLASH Area1 Program Error Flag.
  * \return Returns bit value of FLASH_SR1.PGERR bit
  *           - uint32_t: 0: FLASH_SR1.PGERR = 0
  *                       x: FLASH_SR1.PGERR = 1
  */
static inline uint32_t FLASH_getProgramErrorFlag1 (void)
{
    return READ_BIT(FLASH->SR1.WORDVAL, FLASH_SR1_PGERR_M);
}

/**
  * \brief  Get FLASH Area2 Program Error Flag.
  * \return Returns bit value of FLASH_SR2.PGERR bit
  *           - uint32_t: 0: FLASH_SR2.PGERR = 0
  *                       x: FLASH_SR2.PGERR = 1
  */
static inline uint32_t FLASH_getProgramErrorFlag2 (void)
{
    return READ_BIT(FLASH->SR2.WORDVAL, FLASH_SR2_PGERR_M);
}

/**
  * \brief  Get FLASH Area1 ECC 1 bit Error Flag.
  * \return Returns bit value of FLASH_ECCCR1.SNECC bit
  *           - uint32_t: 0: FLASH_ECCCR1.SNECC = 0
  *                       x: FLASH_ECCCR1.SNECC = 1
  */
static inline uint32_t FLASH_getEcc1BitErrorFlag1 (void)
{
    return READ_BIT(FLASH->ECCCR1.WORDVAL, FLASH_ECCCR1_SNFLAG_M);
}

/**
  * \brief  Get FLASH Area2 ECC 1 bit Error Flag.
  * \return Returns bit value of FLASH_ECCCR2.SNECC bit
  *           - uint32_t: 0: FLASH_ECCCR2.SNECC = 0
  *                       x: FLASH_ECCCR2.SNECC = 1
  */
static inline uint32_t FLASH_getEcc1BitErrorFlag2 (void)
{
    return READ_BIT(FLASH->ECCCR2.WORDVAL, FLASH_ECCCR2_SNFLAG_M);
}

/**
  * \brief  Get FLASH Area1 ECC 2 bit Error Flag.
  * \return Returns bit value of FLASH_ECCCR1.DBECC bit
  *           - uint32_t: 0: FLASH_ECCCR1.DBECC = 0
  *                       x: FLASH_ECCCR1.DBECC = 1
  */
static inline uint32_t FLASH_getEcc2BitErrorFlag1 (void)
{
    return READ_BIT(FLASH->ECCCR1.WORDVAL, FLASH_ECCCR1_DBFLAG_M);
}

/**
  * \brief  Get FLASH Area2 ECC 2 bit Error Flag.
  * \return Returns bit value of FLASH_ECCCR2.DBECC bit
  *           - uint32_t: 0: FLASH_ECCCR2.DBECC = 0
  *                       x: FLASH_ECCCR2.DBECC = 1
  */
static inline uint32_t FLASH_getEcc2BitErrorFlag2 (void)
{
    return READ_BIT(FLASH->ECCCR2.WORDVAL, FLASH_ECCCR2_DBFLAG_M);
}

/**
  * \brief  Get FLASH ECC Error Address.
  * \return Returns ECC error address
  */
static inline uint32_t FLASH_getEccErrorAddr (void)
{
    return READ_REG(FLASH->ECCADDR.WORDVAL);
}

/**
  * \brief  Determine whether Flash Area1 is busy or not.
  * \return Returns bit value of FLASH_SR1.BSY bit
  *           - uint32_t: 0: FLASH_SR1.BSY=0
  *                       x: FLASH_SR1.BSY=1
  */
static inline uint32_t FLASH_isBusy1 (void)
{
    return READ_BIT(FLASH->SR1.WORDVAL, FLASH_SR1_BUSY_M);
}

/**
  * \brief  Determine whether Flash Area2 is busy or not.
  * \return Returns bit value of FLASH_SR2.BSY bit
  *           - uint32_t: 0: FLASH_SR2.BSY=0
  *                       x: FLASH_SR2.BSY=1
  */
static inline uint32_t FLASH_isBusy2 (void)
{
    return READ_BIT(FLASH->SR2.WORDVAL, FLASH_SR2_BUSY_M);
}

/**
  * \brief  Determine whether Flash bank is swaped or not.
  * \return Returns bit value of FLASH_OBR1.BANKSWAP bit
  *           - uint32_t: 0: FLASH_OBR1.BANKSWAP=0
  *                       1: FLASH_OBR1.BANKSWAP=1
  */
static inline uint32_t FLASH_isSwaped (void)
{
    return !!READ_BIT(FLASH->OBR1.WORDVAL, FLASH_OBR1_BANKSWAP_M);
}

/**
  * \brief  Get swap tag.
  * \return Returns swap tag value in falash
  *           - uint32_t: 0x5A : Bank will swap after reset
  *                       other: Bank will not swap after reset
  */
static inline uint8_t FLASH_getSwapTag (void)
{
    return *((uint8_t*)FLASH_SWAPTAG_ADDR);
}

/**
  * \brief  Erase all Flash pages in Bank1
  * \return Returns current option status
  *           - bool: 0: Fail
  *                   1: Success
  * \note    User should disable icache and dcache.
  * \note    User should disable all flash Interrupt.
  */
extern uint8_t FLASH_eraseAllPageInBank1 (void);

/**
  * \brief  Erase all Flash pages in Bank2
  * \return Returns current option status
  *           - bool: 0: Fail
  *                   1: Success
  * \note    User should disable icache and dcache.
  * \note    User should disable all flash Interrupt.
  */
extern uint8_t FLASH_eraseAllPageInBank2 (void);

/**
  * \brief  Erase One Flash Page in Bank1
  * \param  addr    addr of flash page need to be erased
  * \return Returns current option status
  *           - bool: 0: Fail
  *                   1: Success
  * \note    User should disable icache and dcache.
  * \note    User should disable all flash Interrupt.
  */
extern uint8_t FLASH_eraseOnePageInBank1 (uint32_t addr);

/**
  * \brief  Erase One Flash Page in Bank2
  * \param  addr    addr of flash page need to be erased
  * \return Returns current option status
  *           - bool: 0: Fail
  *                   1: Success
  * \note    User should disable icache and dcache.
  * \note    User should disable all flash Interrupt.
  */
extern uint8_t FLASH_eraseOnePageInBank2 (uint32_t addr);

/**
  * \brief  Erase Data Flash Page
  * \param  addr    addr of flash page need to be erased
  * \return Returns current option status
  *           - bool: 0: Fail
  *                   1: Success
  * \note    User should disable icache and dcache.
  * \note    User should disable all flash Interrupt.
  */
extern uint8_t FLASH_eraseOneDataPage (uint32_t addr);

/**
  * \brief  Erase one Option Flash Page
  * \param  addr  addr of data flash page need to be erased
  * \return Returns current option status
  *          - bool: 0: Fail
  *                  1: Success
  * \note User should disable icache and dcache.
  * \note User should disable all flash Interrupt.
  */
extern uint8_t FLASH_eraseOneOptionPage (uint32_t addr);

/**
  * \brief  Check Flash or DataFlash is blank or not
  * \param  addr     Addr of memery need to be check
  * \param  byteCnt  The quantity of data to be checked
  * \return Returns blank status
  *          - bool: 0: not blank
  *                  1: blank
  */
extern uint8_t FLASH_isBlank (uint32_t addr, uint32_t byteCnt);

/**
  * \brief  Write data to Main Flash Bank1
  * \param  addr       Addr of memery need to be write into
  * \param  pBuf       Pointer to the data to be writed
  * \param  byteCnt    The quantity of data to be writed
  * \return Returns current option status
  *           - bool: 0: Fail
  *                   1: Success
  * \note User should disable icache and dcache.
  * \note User should disable all flash Interrupt.
  * \note The value of byteCnt must be a multiple of 8.
  * \note The value of addr must be a multiple of 8.
  */
extern uint8_t FLASH_writeBytesToBank1 (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Write data to Main Flash Bank2
  * \param  addr       Addr of memery need to be write into
  * \param  pBuf       Pointer to the data to be writed
  * \param  byteCnt    The quantity of data to be writed
  * \return Returns current option status
  *           - bool: 0: Fail
  *                   1: Success
  * \note User should disable icache and dcache.
  * \note User should disable all flash Interrupt.
  * \note The value of byteCnt must be a multiple of 8.
  * \note The value of addr must be a multiple of 8.
  */
extern uint8_t FLASH_writeBytesToBank2 (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Write data to DataFlash
  * \param  addr       Addr of memery need to be write into
  * \param  pBuf       Pointer to the data to be writed
  * \param  byteCnt    The quantity of data to be writed
  * \return Returns current option status
  *           - bool: 0: Fail
  *                   1: Success
  * \note User should disable icache and dcache.
  * \note User should disable all flash Interrupt.
  * \note The value of byteCnt must be a multiple of 8.
  * \note The value of addr must be a multiple of 8.
  */
extern uint8_t FLASH_writeBytesToDataPage (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Write data to OptionFlash
  * \param  addr       Addr of memery need to be write into
  * \param  pBuf       Pointer to the data to be writed
  * \param  byteCnt    The quantity of data to be writed
  * \return Returns current option status
  *          - bool: 0: Fail
  *                  1: Success
  * \note User should disable icache and dcache.
  * \note User should disable all flash Interrupt.
  * \note The value of byteCnt must be a multiple of 8.
  * \note The value of addr must be a multiple of 8.
  */
extern uint8_t FLASH_writeBytesToOptionPage (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt);


/**
  * \brief  Write SwapTag to Swap Config Page
  * \param  SwapEn    Enable or Disable Bank swap
  *                    - 0x00: do not swap bank1 and bank2
  *                    - 0x01: swap bank1 and bank2 after reset
  * \return Returns current option status
  *                    - bool: 0: Fail
  *                            1: Success
  * \note User should disable icache and dcache.
  * \note User should disable all flash Interrupt.
  */
extern uint8_t FLASH_writeSwapTag (uint8_t SwapEn);

/**
  * \brief  Get Write Protect Status 1.
  * \param  pBuf    Pointer to the write protect status buf
  * \note Returns protect status(16 bytes) at pBuf
  */
extern void FLASH_getWriteProtectStatus1 (uint8_t *pBuf);

/**
  * \brief  Get Write Protect Status 2.
  * \param  pBuf    Pointer to the write protect status buf
  * \note Returns protect status(16 bytes) at pBuf
 */
extern void FLASH_getWriteProtectStatus2 (uint8_t *pBuf);

/**
  * \brief  Modify Option Bytes.
  * \param  addr       Addr of option byte memery need to be modify
  * \param  pBuf       Pointer to the data to be writed
  * \param  byteCnt    The quantity of data to be writed
  * \return Returns current option status
  *           - bool: 0: Fail
  *                   1: Success
  * \note User should disable icache and dcache.
  * \note User should disable all flash Interrupt.
  */
extern uint8_t FLASH_modifyOptionBytes (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Maintain Option Bytes.
  * \return Returns current option status
  *           - bool: 0: Fail
  *                   1: Success
  * \note User should disable icache and dcache.
  * \note User should disable all flash Interrupt.
  */
extern uint8_t FLASH_maintainOptionBytes (void);

/**
  * \brief  Config readout protect.
  * \param  rdpLevel    readout protect level
  *                       - 0: No protect
  *                       - 1: readout protect level-1
  *                       - 2: readout protect level-2
  * \return Returns current option status
  *           - bool: 0: Fail
  *                   1: Success
  * \note User should disable icache and dcache.
  * \note User should disable all flash Interrupt.
  */
extern uint8_t FLASH_configReadoutProtectLevel (uint32_t rdpLevel);

/**
  * \brief  Get readout protect level.
  * \return Returns readout protect level
  *          - 0: No protect
  *          - 1: readout protect level-1
  *          - 2: readout protect level-2
  */
extern uint8_t FLASH_getReadoutProtectLevel (void);


#ifdef __cplusplus
}
#endif


#endif /* __FLASH_H__ */
