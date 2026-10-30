/**
  * @file       crc.c
  * @author     yutai.meng
  * @brief      Function file for NS800RT7xxx crc module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "crc.h"


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
  * @brief  Initializes the CRC peripheral for 16-bit CRC computation.
  * @param  crc              Pointer to a CRC_TypeDef structure
  *                           - CRC1: CRC1 base address index
  *                           - CRC2: CRC2 base address index
  * @param  poly             16-bit polynomial
  *                           This parameter can be any value of uint16_t
  * @param  initValue        16-bit initial value
  *                           This parameter can be any value of uint16_t
  * @param  xorType          The binary sequence for XOR operation with output data
                              This parameter can be any value of @ref CRC_OUTPUTXORENABLE
  * @param  enableReverse    Select whether to reverse the input and output data
                              This parameter can be any value of @ref CRC_REVERSEENABLE
  */
extern void CRC_initCrc16(CRC_TypeDef *crc, uint16_t poly, uint16_t initValue,
                          CRC_OutputXorType xorType, CRC_ReverseEnable enableReverse)
{
    WRITE_REG(crc->CTRL.WORDVAL, (uint32_t)enableReverse | (uint32_t)xorType | CRC_CTRL_INI_M);
    WRITE_REG(crc->POLY.WORDVAL, poly);
    WRITE_REG(crc->DATA.WORDVAL, initValue);
    CLEAR_BIT(crc->CTRL.WORDVAL, CRC_CTRL_INI_M);
}

/**
  * @brief  Initializes the CRC peripheral for 32-bit CRC computation.
  * @param  crc              Pointer to a CRC_TypeDef structure
  *                           - CRC1: CRC1 base address index
  *                           - CRC2: CRC2 base address index
  * @param  poly             32-bit polynomial
  *                           This parameter can be any value of uint32_t
  * @param  initValue        32-bit initial value
  *                           This parameter can be any value of uint32_t
  * @param  xorType          The binary sequence for XOR operation with output data
                              This parameter can be any value of @ref CRC_OUTPUTXORENABLE
  * @param  enableReverse    Whether to reverse the input and output data
                              This parameter can be any value of @ref CRC_REVERSEENABLE
  */
extern void CRC_initCrc32(CRC_TypeDef *crc, uint32_t poly, uint32_t initValue,
                          CRC_OutputXorType xorType, CRC_ReverseEnable enableReverse)
{
    WRITE_REG(crc->CTRL.WORDVAL, (uint32_t)enableReverse | (uint32_t)xorType | CRC_CTRL_INI_M | CRC_CTRL_WIDTH_M);
    WRITE_REG(crc->POLY.WORDVAL, poly);
    WRITE_REG(crc->DATA.WORDVAL, initValue);
    CLEAR_BIT(crc->CTRL.WORDVAL, CRC_CTRL_INI_M);
}

/**
  * @brief  Writes data to data register.
  * @param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  */
void CRC_writeData(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt)
{
    while (byteCnt >= 4U)
    {
        crc->DATA.WORDVAL = TYPE32(pBuf);
        byteCnt -= 4U;
        pBuf += 4U;
    }

    while (byteCnt)
    {
        TYPE8(&crc->DATA.WORDVAL) = *pBuf;
        byteCnt--;
        pBuf++;
    }
}

/**
  * @brief  Calculates CRC16/IBM algorithm.
  * @param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     This value can be any value of uint16_t
  */
uint16_t CRC_calcCrc16Ibm(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt)
{
    CRC_initCrc16(crc, 0x8005U, 0x0000U, CRC_OUTPUT_XOR_ALL0, CRC_REVERSE_ENABLE);
    CRC_writeData(crc, pBuf, byteCnt);
    return CRC_getCrc16Result(crc, CRC_REVERSE_ENABLE);
}

/**
  * @brief  Calculates CRC16/MAXIM algorithm.
  * @param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     This value can be any value of uint16_t
  */
uint16_t CRC_calcCrc16Maxim(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt)
{
    CRC_initCrc16(crc, 0x8005U, 0x0000U, CRC_OUTPUT_XOR_ALL1, CRC_REVERSE_ENABLE);
    CRC_writeData(crc, pBuf, byteCnt);
    return CRC_getCrc16Result(crc, CRC_REVERSE_ENABLE);
}

/**
  * @brief  Calculates CRC16/USB algorithm.
  * @param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     This value can be any value of uint16_t
  */
uint16_t CRC_calcCrc16Usb(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt)
{
    CRC_initCrc16(crc, 0x8005U, 0xFFFFU, CRC_OUTPUT_XOR_ALL1, CRC_REVERSE_ENABLE);
    CRC_writeData(crc, pBuf, byteCnt);
    return CRC_getCrc16Result(crc, CRC_REVERSE_ENABLE);
}

/**
  * @brief  Calculates CRC16/MODBUS algorithm.
  * @param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     This value can be any value of uint16_t
  */
uint16_t CRC_calcCrc16Modbus(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt)
{
    CRC_initCrc16(crc, 0x8005U, 0xFFFFU, CRC_OUTPUT_XOR_ALL0, CRC_REVERSE_ENABLE);
    CRC_writeData(crc, pBuf, byteCnt);
    return CRC_getCrc16Result(crc, CRC_REVERSE_ENABLE);
}

/**
  * @brief  Calculates CRC16/CCITT algorithm.
  * @param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     This value can be any value of uint16_t
  */
uint16_t CRC_calcCrc16Ccitt(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt)
{
    CRC_initCrc16(crc, 0x1021U, 0x0000U, CRC_OUTPUT_XOR_ALL0, CRC_REVERSE_ENABLE);
    CRC_writeData(crc, pBuf, byteCnt);
    return CRC_getCrc16Result(crc, CRC_REVERSE_ENABLE);
}

/**
  * @brief  Calculates CRC16/CCITTFALSE algorithm.
  * @param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     This value can be any value of uint16_t
  */
uint16_t CRC_calcCrc16CcittFalse(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt)
{
    CRC_initCrc16(crc, 0x1021U, 0xFFFFU, CRC_OUTPUT_XOR_ALL0, CRC_REVERSE_DISABLE);
    CRC_writeData(crc, pBuf, byteCnt);
    return CRC_getCrc16Result(crc, CRC_REVERSE_DISABLE);
}

/**
  * @brief  Calculates CRC16/X25 algorithm.
  * @param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     This value can be any value of uint16_t
  */
uint16_t CRC_calcCrc16X25(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt)
{
    CRC_initCrc16(crc, 0x1021U, 0xFFFFU, CRC_OUTPUT_XOR_ALL1, CRC_REVERSE_ENABLE);
    CRC_writeData(crc, pBuf, byteCnt);
    return CRC_getCrc16Result(crc, CRC_REVERSE_ENABLE);
}

/**
  * @brief  Calculates CRC16/XMODEM algorithm.
  * @param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     This value can be any value of uint16_t
  */
uint16_t CRC_calcCrc16Xmodem(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt)
{
    CRC_initCrc16(crc, 0x1021U, 0x0000U, CRC_OUTPUT_XOR_ALL0, CRC_REVERSE_DISABLE);
    CRC_writeData(crc, pBuf, byteCnt);
    return CRC_getCrc16Result(crc, CRC_REVERSE_DISABLE);
}

/**
  * @brief  Calculates CRC32 algorithm.
  * @param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     This value can be any value of uint32_t
  */
uint32_t CRC_calcCrc32(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt)
{
    CRC_initCrc32(crc, 0x04C11DB7U, 0xFFFFFFFFU, CRC_OUTPUT_XOR_ALL1, CRC_REVERSE_ENABLE);
    CRC_writeData(crc, pBuf, byteCnt);
    return CRC_getCrc32Result(crc);
}

/**
  * @brief  Calculates CRC32/MPEG2 algorithm.
  * @param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     This value can be any value of uint32_t
  */
uint32_t CRC_calcCrc32Mpeg2(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt)
{
    CRC_initCrc32(crc, 0x04C11DB7U, 0xFFFFFFFFU, CRC_OUTPUT_XOR_ALL0, CRC_REVERSE_DISABLE);
    CRC_writeData(crc, pBuf, byteCnt);
    return CRC_getCrc32Result(crc);
}

/**
  * @brief  Calculates CRC32/KOOPMAN algorithm.
  * @param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     This value can be any value of uint32_t
  */
uint32_t CRC_calcCrc32Koopman(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt)
{
    CRC_initCrc32(crc, 0x741B8CD7U, 0xFFFFFFFFU, CRC_OUTPUT_XOR_ALL1, CRC_REVERSE_ENABLE);
    CRC_writeData(crc, pBuf, byteCnt);
    return CRC_getCrc32Result(crc);
}

/**
  * @brief  Calculates CRC32C algorithm.
  * @param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * @param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     This value can be any value of uint32_t
  */
uint32_t CRC_calcCrc32C(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt)
{
    CRC_initCrc32(crc, 0x1EDC6F41U, 0xFFFFFFFFU, CRC_OUTPUT_XOR_ALL1, CRC_REVERSE_ENABLE);
    CRC_writeData(crc, pBuf, byteCnt);
    return CRC_getCrc32Result(crc);
}
