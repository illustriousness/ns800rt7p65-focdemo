/**
  * @file       bgcrc.c
  * @author     bilang.xiong
  * @brief      Function file for NS800RT7xxx bgcrc module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "bgcrc.h"


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
  * @brief  Initializes the BGCRC peripheral for 8-bit CRC computation.
  * @param  bgcrc            Pointer to a BGCRC_TypeDef structure
  *                           - BGCRC1: BGCRC1 base address index
  *                           - BGCRC2: BGCRC2 base address index
  * @param  initValue        8-bit initial value
  *                           This parameter can be any value of uint8_t
  * @param  polyType         The type of polynomial
  *                           - BGCRC_POLY_CRC8:      8-bit polynomial 0x07
  *                           - BGCRC_POLY_CRC8_ITU:  8-bit polynomial 0x07
  *                           - BGCRC_POLY_CRC8_ROHC: 8-bit polynomial 0x07
  * @param  enableReverse    Select whether to reverse the input and output data
                              This parameter can be any value of @ref BGCRC_REVERSEENABLE
  */
void BGCRC_initCrc8 (BGCRC_TypeDef *bgcrc, uint8_t initValue,
                     BGCRC_PolyType polyType, BGCRC_ReverseEnable enableReverse)
{
    if (polyType != BGCRC_POLY_CRC8)
    {
        polyType = BGCRC_POLY_CRC8;
    }
    MODIFY_REG(bgcrc->CR.WORDVAL,
               BGCRC_CR_REVERSE_M | BGCRC_CR_POLY_M,
               (uint32_t)enableReverse | (uint32_t)polyType);
    SET_BIT(bgcrc->CR.WORDVAL, BGCRC_CR_CLR_M);
    WRITE_REG(bgcrc->DATAOUT.WORDVAL, (uint32_t)initValue << 24U);
}

/**
  * @brief  Initializes the BGCRC peripheral for 16-bit CRC computation.
  * @param  bgcrc            Pointer to a BGCRC_TypeDef structure
  *                           - BGCRC1: BGCRC1 base address index
  *                           - BGCRC2: BGCRC2 base address index
  * @param  initValue        16-bit initial value
  *                           This parameter can be any value of uint16_t
  * @param  polyType         The type of polynomial
  *                           - BGCRC_POLY_CRC16_IBM:         16-bit polynomial 0x8005
  *                           - BGCRC_POLY_CRC16_MAXIM:       16-bit polynomial 0x8005
  *                           - BGCRC_POLY_CRC16_USB:         16-bit polynomial 0x8005
  *                           - BGCRC_POLY_CRC16_MODBUS:      16-bit polynomial 0x8005
  *                           - BGCRC_POLY_CRC16_CCITT:       16-bit polynomial 0x1021
  *                           - BGCRC_POLY_CRC16_CCITT_FALSE: 16-bit polynomial 0x1021
  *                           - BGCRC_POLY_CRC16_X25:         16-bit polynomial 0x1021
  *                           - BGCRC_POLY_CRC16_XMODEM:      16-bit polynomial 0x1021
  * @param  enableReverse    Select whether to reverse the input and output data
                              This parameter can be any value of @ref BGCRC_REVERSEENABLE
  */
void BGCRC_initCrc16 (BGCRC_TypeDef *bgcrc, uint16_t initValue,
                      BGCRC_PolyType polyType, BGCRC_ReverseEnable enableReverse)
{
    if ((polyType != BGCRC_POLY_CRC16_IBM) && (polyType != BGCRC_POLY_CRC16_CCITT))
    {
        polyType = BGCRC_POLY_CRC16_IBM;
    }
    MODIFY_REG(bgcrc->CR.WORDVAL,
               BGCRC_CR_REVERSE_M | BGCRC_CR_POLY_M,
               (uint32_t)enableReverse | (uint32_t)polyType);
    SET_BIT(bgcrc->CR.WORDVAL, BGCRC_CR_CLR_M);
    WRITE_REG(bgcrc->DATAOUT.WORDVAL, (uint32_t)initValue << 16U);
}

/**
  * @brief  Initializes the BGCRC peripheral for 32-bit CRC computation.
  * @param  bgcrc            Pointer to a BGCRC_TypeDef structure
  *                           - BGCRC1: BGCRC1 base address index
  *                           - BGCRC2: BGCRC2 base address index
  * @param  initValue        32-bit initial value
  *                           This parameter can be any value of uint32_t
  * @param  polyType         The type of polynomial
  *                           - BGCRC_POLY_CRC32:       32-bit polynomial 0x04C11DB7
  *                           - BGCRC_POLY_CRC32_MPEG2: 32-bit polynomial 0x04C11DB7
  *                           - BGCRC_POLY_CRC32_C:     32-bit polynomial 0x1EDC6F41
  * @param  enableReverse    Select whether to reverse the input and output data
                              This parameter can be any value of @ref BGCRC_REVERSEENABLE
  */
void BGCRC_initCrc32 (BGCRC_TypeDef *bgcrc, uint32_t initValue,
                      BGCRC_PolyType polyType, BGCRC_ReverseEnable enableReverse)
{
    if ((polyType != BGCRC_POLY_CRC32) && (polyType != BGCRC_POLY_CRC32_C))
    {
        polyType = BGCRC_POLY_CRC32;
    }
    MODIFY_REG(bgcrc->CR.WORDVAL,
               BGCRC_CR_REVERSE_M | BGCRC_CR_POLY_M,
               (uint32_t)enableReverse | (uint32_t)polyType);
    SET_BIT(bgcrc->CR.WORDVAL, BGCRC_CR_CLR_M);
    WRITE_REG(bgcrc->DATAOUT.WORDVAL, initValue);
}

/**
  * @brief  Writes 8-bit data to data register.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  */
void BGCRC_write8BitData (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    while (byteCnt)
    {
        WRITE_REG(bgcrc->DATAIN.WORDVAL, (uint32_t)(*pBuf) << 24U);
        byteCnt--;
        pBuf++;
    }
}

/**
  * @brief  Writes 32-bit data to data register.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 32-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @param  enableReverse    Select whether to reverse the input and output data
                              This parameter can be any value of @ref BGCRC_REVERSEENABLE
  */
void BGCRC_write32BitData (BGCRC_TypeDef *bgcrc, uint32_t *pBuf, uint32_t byteCnt,
                           BGCRC_ReverseEnable enableReverse)
{
    if (enableReverse == BGCRC_REVERSE_ENABLE)
    {
        while (byteCnt)
        {
            WRITE_REG(bgcrc->DATAIN.WORDVAL, *pBuf);
            byteCnt--;
            pBuf++;
        }
    }
    else
    {
        while (byteCnt)
        {
            uint32_t dataValue = *pBuf;
            dataValue = ((dataValue & 0xFFUL) << 24UL) |
                        ((dataValue & 0xFF00UL) << 8UL) |
                        ((dataValue & 0xFF0000UL) >> 8UL) |
                        ((dataValue & 0xFF000000UL) >> 24UL);
            WRITE_REG(bgcrc->DATAIN.WORDVAL, dataValue);
            byteCnt--;
            pBuf++;
        }
    }
}

/**
  * @brief  Calculates CRC8 algorithm
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint8_t
  */
uint8_t BGCRC_calcCrc8 (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc8(bgcrc, 0x00U, BGCRC_POLY_CRC8, BGCRC_REVERSE_DISABLE);
    BGCRC_write8BitData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc8Result(bgcrc);
}

/**
  * @brief  Calculates CRC8/ITU algorithm
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint8_t
  */
uint8_t BGCRC_calcCrc8Itu (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc8(bgcrc, 0x00U, BGCRC_POLY_CRC8_ITU, BGCRC_REVERSE_DISABLE);
    BGCRC_write8BitData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc8Result(bgcrc) ^ 0x55U;
}

/**
  * @brief  Calculates CRC8/ROHC algorithm
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint8_t
  */
uint8_t BGCRC_calcCrc8Rohc (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc8(bgcrc, 0xFFU, BGCRC_POLY_CRC8_ROHC, BGCRC_REVERSE_ENABLE);
    BGCRC_write8BitData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc8Result(bgcrc);
}

/**
  * @brief  Calculates CRC16/IBM algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
uint16_t BGCRC_calcCrc16Ibm (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc16(bgcrc, 0x0000U, BGCRC_POLY_CRC16_IBM, BGCRC_REVERSE_ENABLE);
    BGCRC_write8BitData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc16Result(bgcrc);
}

/**
  * @brief  Calculates CRC16/MAXIM algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
uint16_t BGCRC_calcCrc16Maxim (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc16(bgcrc, 0x0000U, BGCRC_POLY_CRC16_MAXIM, BGCRC_REVERSE_ENABLE);
    BGCRC_write8BitData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc16Result(bgcrc) ^ 0xFFFFU;
}

/**
  * @brief  Calculates CRC16/USB algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
uint16_t BGCRC_calcCrc16Usb (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc16(bgcrc, 0xFFFFU, BGCRC_POLY_CRC16_USB, BGCRC_REVERSE_ENABLE);
    BGCRC_write8BitData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc16Result(bgcrc) ^ 0xFFFFU;
}

/**
  * @brief  Calculates CRC16/MODBUS algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
uint16_t BGCRC_calcCrc16Modbus (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc16(bgcrc, 0xFFFFU, BGCRC_POLY_CRC16_MODBUS, BGCRC_REVERSE_ENABLE);
    BGCRC_write8BitData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc16Result(bgcrc);
}

/**
  * @brief  Calculates CRC16/CCITT algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
uint16_t BGCRC_calcCrc16Ccitt (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc16(bgcrc, 0x0000U, BGCRC_POLY_CRC16_CCITT, BGCRC_REVERSE_ENABLE);
    BGCRC_write8BitData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc16Result(bgcrc);
}

/**
  * @brief  Calculates CRC16/CCITTFALSE algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
uint16_t BGCRC_calcCrc16CcittFalse (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc16(bgcrc, 0xFFFFU, BGCRC_POLY_CRC16_CCITT_FALSE, BGCRC_REVERSE_DISABLE);
    BGCRC_write8BitData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc16Result(bgcrc);
}

/**
  * @brief  Calculates CRC16/X25 algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
uint16_t BGCRC_calcCrc16X25 (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc16(bgcrc, 0xFFFFU, BGCRC_POLY_CRC16_X25, BGCRC_REVERSE_ENABLE);
    BGCRC_write8BitData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc16Result(bgcrc) ^ 0xFFFFU;
}

/**
  * @brief  Calculates CRC16/XMODEM algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
uint16_t BGCRC_calcCrc16Xmodem (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc16(bgcrc, 0x0000U, BGCRC_POLY_CRC16_XMODEM, BGCRC_REVERSE_DISABLE);
    BGCRC_write8BitData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc16Result(bgcrc);
}

/**
  * @brief  Calculates CRC32 algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 32-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint32_t
  */
uint32_t BGCRC_calcCrc32 (BGCRC_TypeDef *bgcrc, uint32_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc32(bgcrc, 0xFFFFFFFFU, BGCRC_POLY_CRC32, BGCRC_REVERSE_ENABLE);
    BGCRC_write32BitData(bgcrc, pBuf, byteCnt, BGCRC_REVERSE_ENABLE);
    return BGCRC_getCrc32Result(bgcrc) ^ 0xFFFFFFFFU;
}

/**
  * \brief  Calculates CRC32/MPEG2 algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 32-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint32_t
  */
uint32_t BGCRC_calcCrc32Mpeg2 (BGCRC_TypeDef *bgcrc, uint32_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc32(bgcrc, 0xFFFFFFFFU, BGCRC_POLY_CRC32_MPEG2, BGCRC_REVERSE_DISABLE);
    BGCRC_write32BitData(bgcrc, pBuf, byteCnt, BGCRC_REVERSE_DISABLE);
    return BGCRC_getCrc32Result(bgcrc);
}

/**
  * \brief  Calculates CRC32C algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 32-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint32_t
  */
extern uint32_t BGCRC_calcCrc32C (BGCRC_TypeDef *bgcrc, uint32_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc32(bgcrc, 0xFFFFFFFFU, BGCRC_POLY_CRC32_C, BGCRC_REVERSE_ENABLE);
    BGCRC_write32BitData(bgcrc, pBuf, byteCnt, BGCRC_REVERSE_ENABLE);
    return BGCRC_getCrc32Result(bgcrc) ^ 0xFFFFFFFFU;
}
