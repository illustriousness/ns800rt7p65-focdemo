/**
  * @file       crc.h
  * @author     yutai.meng
  * @brief      Header file for NS800RT7xxx crc module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __CRC_H__
#define __CRC_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_crc.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup CRC_EXPORTED_TYPES CRC Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'CRC' module.
  */

/** @defgroup CRC_OUTPUTXORENABLE CRC Output Xor Calculation Enablement
  * @{
  * @brief  The binary sequence for XOR operation with output data.
  */
typedef enum {
    CRC_OUTPUT_XOR_ALL0 = 0x0UL,                     /*!< The output data is XORed with
                                                          all-zero binary sequence of equal bit length*/
    CRC_OUTPUT_XOR_ALL1 = 0x1UL << CRC_CTRL_XOR_S    /*!< The output data is XORed with
                                                          all-one binary sequence of equal bit length*/
} CRC_OutputXorType;

/**
  * @}
  */

/** @defgroup CRC_REVERSEENABLE CRC Reverse Enablement
  * @{
  * @brief  Whether to reverse the input and output data.
  */
typedef enum {
    CRC_REVERSE_DISABLE = 0xCUL << CRC_CTRL_REVERSE_S,    /*!< Disable Reverse */
    CRC_REVERSE_ENABLE = 0xAUL << CRC_CTRL_REVERSE_S      /*!< Enable Reverse */
} CRC_ReverseEnable;

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
  * \brief  ​​Selects the binary sequence for XOR operation with output data.
  * \param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * \param  xorType    The binary sequence for XOR operation with output data
  *                     This parameter can be any value of @ref CRC_OUTPUTXORENABLE
  */
static inline void CRC_selectOutputXorType (CRC_TypeDef *crc, CRC_OutputXorType xorType)
{
    if (xorType == CRC_OUTPUT_XOR_ALL1)
    {
        SET_BIT(crc->CTRL.WORDVAL, CRC_CTRL_XOR_M);
    }
    else
    {
        CLEAR_BIT(crc->CTRL.WORDVAL, CRC_CTRL_XOR_M);
    }
}

/**
  * \brief  Enables the function of reversing input and output data.
  * \param  crc    Pointer to a CRC_TypeDef structure
  *                 - CRC1: CRC1 base address index
  *                 - CRC2: CRC2 base address index
  */
static inline void CRC_enableReverse (CRC_TypeDef *crc)
{
    MODIFY_REG(crc->CTRL.WORDVAL, CRC_CTRL_REVERSE_M, CRC_REVERSE_ENABLE);
}

/**
  * \brief  Disables the function of of reversing input and output data.
  * \param  crc    Pointer to a CRC_TypeDef structure
  *                 - CRC1: CRC1 base address index
  *                 - CRC2: CRC2 base address index
  */
static inline void CRC_disableReverse (CRC_TypeDef *crc)
{
    MODIFY_REG(crc->CTRL.WORDVAL, CRC_CTRL_REVERSE_M, CRC_REVERSE_DISABLE);
}

/**
  * \brief  Gets CRC-16 calculation result.
  * \param  crc              Pointer to a CRC_TypeDef structure
  *                           - CRC1: CRC1 base address index
  *                           - CRC2: CRC2 base address index
  * \param  enableReverse    Whether to reverse the input and output data
  *                           - CRC_REVERSE_DISABLE: Disable reverse
  *                           - CRC_REVERSE_ENABLE: Enable reverse
  */
static inline uint16_t CRC_getCrc16Result (CRC_TypeDef *crc, CRC_ReverseEnable enableReverse)
{
    if (enableReverse == CRC_REVERSE_ENABLE)
    {
        return (uint16_t)(crc->DATA.WORDVAL >> 16U);
    }
    else
    {
        return (uint16_t)(crc->DATA.WORDVAL);
    }
}

/**
  * \brief  Gets CRC-32 calculation result.
  * \param  crc    Pointer to a CRC_TypeDef structure
  *                 - CRC1: CRC1 base address index
  *                 - CRC2: CRC2 base address index
  */
static inline uint32_t CRC_getCrc32Result (CRC_TypeDef *crc)
{
    return (crc->DATA.WORDVAL);
}

/**
  * \brief  Initializes the CRC peripheral for 16-bit CRC computation.
  * \param  crc              Pointer to a CRC_TypeDef structure
  *                           - CRC1: CRC1 base address index
  *                           - CRC2: CRC2 base address index
  * \param  poly             16-bit polynomial
  *                           This parameter can be any value of uint16_t
  * \param  initValue        16-bit initial value
  *                           This parameter can be any value of uint16_t
  * \param  xorType          The binary sequence for XOR operation with output data
                              This parameter can be any value of @ref CRC_OUTPUTXORENABLE
  * \param  enableReverse    Select whether to reverse the input and output data
                              This parameter can be any value of @ref CRC_REVERSEENABLE
  */
extern void CRC_initCrc16(CRC_TypeDef *crc, uint16_t poly, uint16_t initValue,
                          CRC_OutputXorType xorType, CRC_ReverseEnable enableReverse);

/**
  * \brief  Initializes the CRC peripheral for 32-bit CRC computation.
  * \param  crc              Pointer to a CRC_TypeDef structure
  *                           - CRC1: CRC1 base address index
  *                           - CRC2: CRC2 base address index
  * \param  poly             32-bit polynomial
  *                           This parameter can be any value of uint32_t
  * \param  initValue        32-bit initial value
  *                           This parameter can be any value of uint32_t
  * \param  xorType          The binary sequence for XOR operation with output data
                              This parameter can be any value of @ref CRC_OUTPUTXORENABLE
  * \param  enableReverse    Whether to reverse the input and output data
                              This parameter can be any value of @ref CRC_REVERSEENABLE
  */
extern void CRC_initCrc32(CRC_TypeDef *crc, uint32_t poly, uint32_t initValue,
                          CRC_OutputXorType xorType, CRC_ReverseEnable enableReverse);

/**
  * \brief  Writes data to data register.
  * \param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  */
extern void CRC_writeData(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/IBM algorithm.
  * \param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     This value can be any value of uint16_t
  */
extern uint16_t CRC_calcCrc16Ibm(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/MAXIM algorithm.
  * \param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     This value can be any value of uint16_t
  */
extern uint16_t CRC_calcCrc16Maxim(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/USB algorithm.
  * \param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     This value can be any value of uint16_t
  */
extern uint16_t CRC_calcCrc16Usb(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/MODBUS algorithm.
  * \param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     This value can be any value of uint16_t
  */
extern uint16_t CRC_calcCrc16Modbus(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/CCITT algorithm.
  * \param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     This value can be any value of uint16_t
  */
extern uint16_t CRC_calcCrc16Ccitt(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/CCITTFALSE algorithm.
  * \param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     This value can be any value of uint16_t
  */
extern uint16_t CRC_calcCrc16CcittFalse(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/X25 algorithm.
  * \param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     This value can be any value of uint16_t
  */
extern uint16_t CRC_calcCrc16X25(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/XMODEM algorithm.
  * \param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     This value can be any value of uint16_t
  */
extern uint16_t CRC_calcCrc16Xmodem(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC32 algorithm.
  * \param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     This value can be any value of uint32_t
  */
extern uint32_t CRC_calcCrc32(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC32/MPEG2 algorithm.
  * \param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     This value can be any value of uint32_t
  */
extern uint32_t CRC_calcCrc32Mpeg2(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * /brief  Calculates CRC32/KOOPMAN algorithm.
  * /param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * /param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * /param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * /return Returns the calculation result
  *                     This value can be any value of uint32_t
  */
uint32_t CRC_calcCrc32Koopman(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC32C algorithm.
  * \param  crc        Pointer to a CRC_TypeDef structure
  *                     - CRC1: CRC1 base address index
  *                     - CRC2: CRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     The pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     This value can be any value of uint32_t
  */
extern uint32_t CRC_calcCrc32C(CRC_TypeDef *crc, uint8_t *pBuf, uint32_t byteCnt);

#ifdef __cplusplus
}
#endif


#endif /* __CRC_H__ */
