/**
  * @file       aeshash.h
  * @author     yangjun
  * @brief      Header file for NS800RT7xxx aeshash module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __AESHASH_H__
#define __AESHASH_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup AESHASH_EXPORTED_TYPES AESHASH Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'AESHASH' module.
  */

/** @defgroup AESHASH_DMAI AESHASH DMA_I On/Off
  * @{
  * @brief  Macro definitions about AESHASH DMA_I On/Off.
  */
typedef enum {
    AESHASH_DMAI_DISABLE = 0U,    /*!< AESHASH DMA_I Disable */
    AESHASH_DMAI_ENABLE           /*!< AESHASH DMA_I Enable  */
} AESHASH_Dmai;

/**
  * @}
  */

/** @defgroup AESHASH_DMAO AESHASH DMA_O On/Off
  * @{
  * @brief  Macro definitions about AESHASH DMA_O On/Off.
  */
typedef enum {
    AESHASH_DMAO_DISABLE = 0U,    /*!< AESHASH DMA_O Disable */
    AESHASH_DMAO_ENABLE           /*!< AESHASH DMA_O Enable  */
} AESHASH_Dmao;

/**
  * @}
  */

/** @defgroup AESHASH_OPERATIONMODE AESHASH Operation Mode
  * @{
  * @brief  Macro definitions about AESHASH operation mode.
  */
typedef enum {
    AESHASH_OPERATIONMODE_SHA1   = 1U,    /*!< AESHASH Operation mode SHA1   */
    AESHASH_OPERATIONMODE_SHA256 = 2U,    /*!< AESHASH Operation mode SHA256 */
    AESHASH_OPERATIONMODE_AES    = 4U     /*!< AESHASH Operation mode AES    */
} AESHASH_OperationMode;

/**
  * @}
  */

/** @defgroup AES_KEYSIZE AES Key Size
  * @{
  * @brief  Macro definitions about AES key size.
  */
typedef enum {
    AES_KEYSIZE_128 = 0U,    /*!< AES Key Size 128 */
    AES_KEYSIZE_192,         /*!< AES Key Size 192 */
    AES_KEYSIZE_256          /*!< AES Key Size 256 */
} AES_KeySize;

/**
  * @}
  */

/** @defgroup AES_BLOCKMODE AES Block Mode
  * @{
  * @brief  Macro definitions about AES block mode.
  */
typedef enum {
    AES_BLOCKMODE_ECB = 0U,    /*!< AES Block Mode ECB */
    AES_BLOCKMODE_CBC,         /*!< AES Block Mode CBC */
    AES_BLOCKMODE_CTR          /*!< AES Block Mode CTR */
} AES_BlockMode;

/**
  * @}
  */

/** @defgroup AES_CRYPTMODE AES Crypt Mode
  * @{
  * @brief  Macro definitions about AES crypt mode.
  */
typedef enum {
    AES_CRYPTMODE_ENC = 0U,    /*!< AES Crypt Mode Encrypt */
    AES_CRYPTMODE_DEC          /*!< AES Crypt Mode Decrypt */
} AES_CyptMode;

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
  * \brief  Config AESHASH operation mode.
  * \param  opmd   Operation Mode
  *                 This parameter can be any value of @ref AESHASH_OPERATIONMODE
  */
static inline void AESHASH_configOperationMode (AESHASH_OperationMode opmd)
{
    SET_BIT(AESHASH->CTRL.WORDVAL, AESHASH_CTRL_INI_M);
    __DSB();
    MODIFY_REG(AESHASH->CTRL.WORDVAL, AESHASH_CTRL_MODE_M, ((uint32_t)opmd << AESHASH_CTRL_MODE_S));
    __DSB();
}

/**
  * \brief  Initialize AES/HASH operation.
  */
static inline void AESHASH_initialize (void)
{
    SET_BIT(AESHASH->CTRL.WORDVAL, AESHASH_CTRL_INI_M);
    __DSB();
}

/**
  * \brief  Enable DMA write data to AES-HASH.
  */
static inline void AESHASH_enableDmaInput (void)
{
    SET_BIT(AESHASH->CTRL.WORDVAL, AESHASH_CTRL_DMAI_M);
    __DSB();
}

/**
  * \brief  Disable DMA write data to AES-HASH.
  */
static inline void AESHASH_disableDmaInput (void)
{
    CLEAR_BIT(AESHASH->CTRL.WORDVAL, AESHASH_CTRL_DMAI_M);
    __DSB();
}

/**
  * \brief  Enable DMA read data from AES-HASH.
  */
static inline void AESHASH_enableDmaOutput (void)
{
    SET_BIT(AESHASH->CTRL.WORDVAL, AESHASH_CTRL_DMAO_M);
    __DSB();
}

/**
  * \brief  Disable DMA read data from AES-HASH.
  */
static inline void AESHASH_disableDmaOutput (void)
{
    CLEAR_BIT(AESHASH->CTRL.WORDVAL, AESHASH_CTRL_DMAO_M);
    __DSB();
}

/**
  * \brief  Enable waiting interrupt.
  */
static inline void AESHASH_enableWaitingInterrupt (void)
{
    SET_BIT(AESHASH->INTENSET.WORDVAL, AESHASH_INTENSET_WAITING_M);
    __DSB();
}

/**
  * \brief  Disable waiting interrupt.
  */
static inline void AESHASH_disableWaitingInterrupt (void)
{
    SET_BIT(AESHASH->INTENCLR.WORDVAL, AESHASH_INTENCLR_WAITING_M);
    __DSB();
}

/**
  * \brief  Enable digest interrupt.
  */
static inline void AESHASH_enableDigestInterrupt (void)
{
    SET_BIT(AESHASH->INTENSET.WORDVAL, AESHASH_INTENSET_DIGEST_M);
    __DSB();
}

/**
  * \brief  Disable digest interrupt.
  */
static inline void AESHASH_disableDigestInterrupt (void)
{
    SET_BIT(AESHASH->INTENCLR.WORDVAL, AESHASH_INTENCLR_DIGEST_M);
    __DSB();
}

/**
  * \brief  Enable error interrupt.
  */
static inline void AESHASH_enableErrorInterrupt (void)
{
    SET_BIT(AESHASH->INTENSET.WORDVAL, AESHASH_INTENSET_ERROR_M);
    __DSB();
}

/**
  * \brief  Disable error interrupt.
  */
static inline void AESHASH_disableErrorInterrupt (void)
{
    SET_BIT(AESHASH->INTENCLR.WORDVAL, AESHASH_INTENSET_ERROR_M);
    __DSB();
}

/**
  * \brief  AES-HASH work as AHB master.
  */
static inline void AESHASH_enableAhbMaster (void)
{
    SET_BIT(AESHASH->MEMCTRL.WORDVAL, AESHASH_MEMCTRL_MASTER_M);
    __DSB();
}

/**
  * \brief  AES-HASH work as AHB slave.
  */
static inline void AESHASH_disableAhbMaster (void)
{
    CLEAR_BIT(AESHASH->MEMCTRL.WORDVAL, AESHASH_MEMCTRL_MASTER_M);
    __DSB();
}

/**
  * \brief  config block count AES-HASH AHB Master need to process.
  */
static inline void AESHASH_configAhbMasterBlockCnt (uint16_t blkcnt)
{
    MODIFY_REG(AESHASH->MEMCTRL.WORDVAL, AESHASH_MEMCTRL_COUNT_M, ((uint32_t)blkcnt << AESHASH_MEMCTRL_COUNT_S));
    __DSB();
}

/**
  * \brief  config memery addr AES-HASH AHB Master read from.
  */
static inline void AESHASH_configAhbMasterAccessAddr (uint32_t addr)
{
    AESHASH->MEMADDR.WORDVAL = addr;
}

/**
  * \brief  Config AES crypt mode.
  * \param  cymd   crypt Mode
  *                 This parameter can be any value of @ref AES_CRYPTMODE
  */
static inline void AESHASH_configAesCryptMode (AES_CyptMode cymd)
{
    MODIFY_REG(AESHASH->CRYPTCFG.WORDVAL, AESHASH_CRYPTCFG_AESDECRYPT_M, ((uint32_t)cymd << AESHASH_CRYPTCFG_AESDECRYPT_S));
    __DSB();
    SET_BIT(AESHASH->CRYPTCFG.WORDVAL, 0xF);
    __DSB();
}

/**
  * \brief  Config AES block mode.
  * \param  blkmd  Block Mode
  *                 This parameter can be any value of @ref AES_BLOCKMODE
  */
static inline void AESHASH_configAesBlockMode (AES_BlockMode blkmd)
{
    MODIFY_REG(AESHASH->CRYPTCFG.WORDVAL, AESHASH_CRYPTCFG_AESMODE_M, ((uint32_t)blkmd << AESHASH_CRYPTCFG_AESMODE_S));
    __DSB();
}

/**
  * \brief  Config AES key size.
  * \param  keysize  Key Size
  *                   This parameter can be any value of @ref AES_KEYSIZE
  */
static inline void AESHASH_configAesKeySize (AES_KeySize ksize)
{
    MODIFY_REG(AESHASH->CRYPTCFG.WORDVAL, AESHASH_CRYPTCFG_AESKEYSZ_M, ((uint32_t)ksize << AESHASH_CRYPTCFG_AESKEYSZ_S));
    __DSB();
}

/**
  * \brief  Write 1 data block (64 bytes) to HASH.
  * \param  pbuf  Pointer to data to be process, 64byte
  */
static inline void HASH_writeDataBlock (uint8_t *pbuf)
{
    for (uint32_t i = 0; i < 16; i++)
    {
        WRITE_REG(AESHASH->INDATA.WORDVAL, *((uint32_t *)(pbuf + i * 4)));
    }
}

/**
  * \brief  Write 1 data block (16 bytes) to AES.
  * \param  pbuf  Pointer to data to be process, 16byte
  */
static inline void AES_writeDataBlock (uint8_t *pbuf)
{
    WRITE_REG(AESHASH->INDATA.WORDVAL, *((uint32_t *)(pbuf + 0)));
    WRITE_REG(AESHASH->INDATA.WORDVAL, *((uint32_t *)(pbuf + 4)));
    WRITE_REG(AESHASH->INDATA.WORDVAL, *((uint32_t *)(pbuf + 8)));
    WRITE_REG(AESHASH->INDATA.WORDVAL, *((uint32_t *)(pbuf + 12)));
}

/**
  * \brief  Read result block (16 bytes) from AES.
  * \param  pbuf  Pointer to result buffer, 16byte
  */
static inline void AES_readResultBlock (uint8_t *pbuf)
{
    *((uint32_t *)(pbuf + 0))  = __REV(AESHASH->DIGEST00.WORDVAL);
    *((uint32_t *)(pbuf + 4))  = __REV(AESHASH->DIGEST01.WORDVAL);
    *((uint32_t *)(pbuf + 8))  = __REV(AESHASH->DIGEST02.WORDVAL);
    *((uint32_t *)(pbuf + 12)) = __REV(AESHASH->DIGEST03.WORDVAL);
}

/**
  * \brief  AES ini
  * \param  cyptMode  AES Cypt mode
  *                    This parameter can be any value of @ref AES_CRYPTMODE
  * \param  keySize   AES Key size
  *                    This parameter can be any value of @ref AES_KEYSIZE
  * \param  blkMode   Block chain mode
  *                    This parameter can be any value of @ref AES_BLOCKMODE
  * \param  pKeyBuf   Pointer to Key, 16byte / 24byte / 32byte
  * \param  pIvNonce  Pointer to IV buffer(16 byte) in CBC mode
  *                   Pointer to Nonce buffer(16 byte) in CTR mode
  */
extern void AES_ini (AES_CyptMode cyptMode, AES_KeySize keySize, AES_BlockMode blkMode, uint8_t *pKeyBuf, uint8_t *pIvNonce);

/**
  * \brief  AES process block by polling
  * \param  pInputBlock   Pointer to the input message
  * \param  pOutputBlock  Pointer to the output message
  * \param  byteCnt       The quantity of data to be process
  * \note   The value of byteCnt must be a multiple of 16.
  */
extern void AES_processBlockByPolling (uint8_t *pInputBlock, uint8_t *pOutputBlock, uint32_t byteCnt);

/**
  * \brief  HASH ini
  * \param  oPMode    HASH Operation mode
  *                    This parameter can be any value of @ref AESHASH_OPERATIONMODE
  */
extern void HASH_ini (AESHASH_OperationMode oPMode);

/**
  * \brief  HASH process message by polling
  * \param  pMsgBuf   Pointer to the input message
  * \param  pHashBuf  Pointer to the hash result buffer
  * \param  byteCnt   The quantity of data to be process
  */
extern void HASH_processMessageByPolling (uint8_t *pMsgBuf, uint8_t *pHashBuf, uint32_t byteCnt);


#ifdef __cplusplus
}
#endif


#endif /* __AESHASH_H__ */
