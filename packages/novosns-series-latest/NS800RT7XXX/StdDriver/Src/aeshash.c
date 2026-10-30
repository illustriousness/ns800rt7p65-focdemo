/**
  * @file       aeshash.c
  * @author     yangjun
  * @brief      Function file for NS800RT7xxx aeshash module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "aeshash.h"


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
 * @brief  AES ini
 * @param  cyptMode  AES Cypt mode
 *                    This parameter can be any value of @ref AES_CRYPTMODE
 * @param  keySize   AES Key size
 *                    This parameter can be any value of @ref AES_KEYSIZE
 * @param  blkMode   Block chain mode
 *                    This parameter can be any value of @ref AES_BLOCKMODE
 * @param  pKeyBuf   Pointer to Key, 16byte / 24byte / 32byte
 * @param  pIvNonce  Pointer to IV buffer(16 byte) in CBC mode
 *                   Pointer to Nonce buffer(16 byte) in CTR mode
 */
void AES_ini (AES_CyptMode cyptMode, AES_KeySize keySize, AES_BlockMode blkMode, uint8_t *pKeyBuf, uint8_t *pIvNonce)
{
    AESHASH_configOperationMode(AESHASH_OPERATIONMODE_AES);
    AESHASH_configAesCryptMode(cyptMode);
    AESHASH_configAesKeySize(keySize);
    AESHASH_configAesBlockMode(blkMode);
    AESHASH_initialize();

    while (AESHASH->STATUS.WORDVAL & AESHASH_STATUS_NEEDKEY_M)
    {
        AESHASH->INDATA.WORDVAL = *(uint32_t *)pKeyBuf;
        pKeyBuf += 4;
    }

    while (AESHASH->STATUS.WORDVAL & AESHASH_STATUS_NEEDIV_M)
    {
        AESHASH->INDATA.WORDVAL = *(uint32_t *)pIvNonce;
        pIvNonce += 4;
    }
}

/**
 * @brief  AES process block by polling
 * @param  pInputBlock   Pointer to the input message
 * @param  pOutputBlock  Pointer to the output message
 * @param  byteCnt       The quantity of data to be process
 * @note   The value of byteCnt must be a multiple of 16.
 */
void AES_processBlockByPolling (uint8_t *pInputBlock, uint8_t *pOutputBlock, uint32_t byteCnt)
{
    while (byteCnt >= 16)
    {
        AES_writeDataBlock(pInputBlock);
        while ((AESHASH->STATUS.WORDVAL & AESHASH_STATUS_DIGEST_M) == 0) {;}
        AES_readResultBlock(pOutputBlock);
        pInputBlock  += 16;
        pOutputBlock += 16;
        byteCnt      -= 16;
    }
}

/**
 * @brief  HASH ini
 * @param  oPMode  HASH Operation mode
 *                  This parameter can be any value of @ref AESHASH_OPERATIONMODE
 */
void HASH_ini (AESHASH_OperationMode oPMode)
{
    AESHASH_configOperationMode(oPMode);
    AESHASH_initialize();
}

/**
 * @brief  HASH process message by polling
 * @param  pMsgBuf   Pointer to the input message
 * @param  pHashBuf  Pointer to the hash result buffer
 * @param  byteCnt   The quantity of data to be process
 */
void HASH_processMessageByPolling (uint8_t *pMsgBuf, uint8_t *pHashBuf, uint32_t byteCnt)
{
    uint32_t msgBitCnt;
    uint8_t blockBuf[64];

    msgBitCnt = byteCnt * 8;
    while (byteCnt >= 64)
    {
        HASH_writeDataBlock(pMsgBuf);
        byteCnt -= 64;
        pMsgBuf += 64;
        while (AESHASH->STATUS.BIT.WAITING == 0) {;}
    }

    /* need one 512bit block */
    if (byteCnt <= 55)
    {
        for (uint32_t i = 0; i < 64; i++)
        {
            blockBuf[i] = 0x00;
        }
        for (uint32_t i = 0; i < byteCnt; i++)
        {
            blockBuf[i] = pMsgBuf[i];
        }
        blockBuf[byteCnt] = 0x80;
        *((uint32_t *)(blockBuf+60)) = __REV(msgBitCnt);

        HASH_writeDataBlock(blockBuf);
        while (AESHASH->STATUS.BIT.WAITING == 0) {;}
    }
    /* need two 512bit block */
    else
    {
        for (uint32_t i = 0; i < 64; i++)
        {
            blockBuf[i] = 0x00;
        }
        for (uint32_t i = 0; i < byteCnt; i++)
        {
            blockBuf[i] = pMsgBuf[i];
        }
        blockBuf[byteCnt] = 0x80;
        HASH_writeDataBlock(blockBuf);
        while (AESHASH->STATUS.BIT.WAITING == 0) {;}

        for (uint32_t i = 0; i < 64; i++)
        {
            blockBuf[i] = 0x00;
        }
        *((uint32_t *)(blockBuf+60)) = __REV(msgBitCnt);
        HASH_writeDataBlock(blockBuf);
        while (AESHASH->STATUS.BIT.WAITING == 0) {;}
    }

    while (AESHASH->STATUS.BIT.DIGEST == 0) {;}
    uint32_t resultWordCnt = 5;
    if (AESHASH->CTRL.BIT.MODE == AESHASH_OPERATIONMODE_SHA256)
    {
        resultWordCnt = 8;
    }

    for(uint32_t i = 0; i < resultWordCnt; i++)
    {
         *((uint32_t *)(pHashBuf + i*4)) = __REV(*(&AESHASH->DIGEST00.WORDVAL + i));
    }
}
