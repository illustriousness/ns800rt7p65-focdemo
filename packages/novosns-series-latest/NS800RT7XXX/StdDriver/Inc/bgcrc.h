/**
  * @file       bgcrc.h
  * @author     bilang.xiong
  * \brief      Header file for NS800RT7xxx bgcrc module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __BGCRC_H__
#define __BGCRC_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_bgcrc.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup BGCRC_EXPORTED_TYPES BGCRC Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'BGCRC' module.
  */



/** @defgroup BGCRC_REVERSEENABLE BGCRC Reverse Enablement
  * @{
  * @brief  Whether to reverse the input and output data.
  */
typedef enum {
    BGCRC_REVERSE_DISABLE = 0x1UL << BGCRC_CR_REVERSE_S,    /*!< Disable Reverse */
    BGCRC_REVERSE_ENABLE  = 0x0UL                           /*!< Enable Reverse */
} BGCRC_ReverseEnable;

/**
  * @}
  */

/** @defgroup BGCRC_MONITORENABLE BGCRC Monitor Enablement
  * @{
  * @brief  Definitions about whether to enable monitor function.
  */
typedef enum {
    BGCRC_MONITOR_DISABLE = 0x0UL,                      /*!< Disable monitor */
    BGCRC_MONITOR_ENABLE = 0x1UL << BGCRC_CR_MONEN_S    /*!< Enable monitor */
} BGCRC_MonitorEnable;

/**
  * @}
  */

/** @defgroup BGCRC_MONITORMODE BGCRC Monitor Mode
  * @{
  * @brief  Definitions about the working mode (reading mode/writing mode) of the monitor.
  */
typedef enum {
    BGCRC_MONITOR_MODE_READ = 0x0UL,                         /*!< Reading mode */
    BGCRC_MONITOR_MODE_WRITE = 0x1UL << BGCRC_CR_MONSRC_S    /*!< Writing mode */
} BGCRC_MonitorMode;

/**
  * @}
  */

/** @defgroup BGCRC_POLYTYPE BGCRC Polynomial Type
  * @{
  * @brief  Definitions about types of polynomial.
  */
typedef enum {
    BGCRC_POLY_CRC8 = 0x1UL << BGCRC_CR_POLY_S,                 /*!< 8-bit polynomial 0x07 */
    BGCRC_POLY_CRC8_ITU = 0x1UL << BGCRC_CR_POLY_S,             /*!< 8-bit polynomial 0x07 */
    BGCRC_POLY_CRC8_ROHC = 0x1UL << BGCRC_CR_POLY_S,            /*!< 8-bit polynomial 0x07 */
    BGCRC_POLY_CRC16_IBM = 0x2UL << BGCRC_CR_POLY_S,            /*!< 16-bit polynomial 0x8005 */
    BGCRC_POLY_CRC16_MAXIM = 0x2UL << BGCRC_CR_POLY_S,          /*!< 16-bit polynomial 0x8005 */
    BGCRC_POLY_CRC16_USB = 0x2UL << BGCRC_CR_POLY_S,            /*!< 16-bit polynomial 0x8005 */
    BGCRC_POLY_CRC16_MODBUS = 0x2UL << BGCRC_CR_POLY_S,         /*!< 16-bit polynomial 0x8005 */
    BGCRC_POLY_CRC16_CCITT = 0x3UL << BGCRC_CR_POLY_S,          /*!< 16-bit polynomial 0x1021 */
    BGCRC_POLY_CRC16_CCITT_FALSE = 0x3UL << BGCRC_CR_POLY_S,    /*!< 16-bit polynomial 0x1021 */
    BGCRC_POLY_CRC16_X25 = 0x3UL << BGCRC_CR_POLY_S,            /*!< 16-bit polynomial 0x1021 */
    BGCRC_POLY_CRC16_XMODEM = 0x3UL << BGCRC_CR_POLY_S,         /*!< 16-bit polynomial 0x1021 */
    BGCRC_POLY_CRC32 = 0x4UL << BGCRC_CR_POLY_S,                /*!< 32-bit polynomial 0x04C11DB7 */
    BGCRC_POLY_CRC32_MPEG2 = 0x4UL << BGCRC_CR_POLY_S,          /*!< 32-bit polynomial 0x04C11DB7 */
    BGCRC_POLY_CRC32_C = 0x5UL << BGCRC_CR_POLY_S               /*!< 32-bit polynomial 0x1EDC6F41 */
} BGCRC_PolyType;

/**
  * @}
  */

/** @defgroup BGCRC_MONITORBUSTYPE BGCRC Monitor Bus Type
  * @{
  * @brief  Definitions about the type of bus on which the monitored register resides.
  */
typedef enum {
    BGCRC_MONITOR_BUS_NONE = 0x0UL,                              /*!< Do not monitor any addresses */
    BGCRC_MONITOR_BUS_QSPI = 0x1UL << BGCRC_MONADDR2_ADDR2_S,    /*!< QSPI (Register Address Value: 0x84000000UL ~ 0x87FFFFFFUL) */
    BGCRC_MONITOR_BUS_APB6 = 0x2UL << BGCRC_MONADDR2_ADDR2_S,    /*!< APB6 (Register Address Value: 0x40070000UL ~ 0x4007FFFFUL) */
    BGCRC_MONITOR_BUS_APB2 = 0x3UL << BGCRC_MONADDR2_ADDR2_S,    /*!< APB2 (Register Address Value: 0x40040000UL ~ 0x4005FFFFUL) */
    BGCRC_MONITOR_BUS_APB4 = 0x4UL << BGCRC_MONADDR2_ADDR2_S,    /*!< APB4 (Register Address Value: 0x40060000UL ~ 0x4006FFFFUL) */
} BGCRC_MonitorBusType;

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
  * \brief  Enables the function of moniter.
  * \param  bgcrc    Pointer to a BGCRC_TypeDef structure
  *                   - BGCRC1: BGCRC1 base address index
  *                   - BGCRC2: BGCRC2 base address index
  */
static inline void BGCRC_enableMonitor (BGCRC_TypeDef *bgcrc)
{
    SET_BIT(bgcrc->CR.WORDVAL, BGCRC_CR_MONEN_M);
}

/**
  * \brief  Disables the function of monitor.
  * \param  bgcrc    Pointer to a BGCRC_TypeDef structure
  *                   - BGCRC1: BGCRC1 base address index
  *                   - BGCRC2: BGCRC2 base address index
  */
static inline void BGCRC_disableMonitor (BGCRC_TypeDef *bgcrc)
{
    CLEAR_BIT(bgcrc->CR.WORDVAL, BGCRC_CR_MONEN_M);
}

/**
  * \brief  Sets the working mode of the monitor.
  * \param  bgcrc    Pointer to a BGCRC_TypeDef structure
  *                   - BGCRC1: BGCRC1 base address index
  *                   - BGCRC2: BGCRC2 base address index
  * \param  mode     The working mode of the monitor
  *                   This parameter can be any value of @ref BGCRC_MONITORMODE
  */
static inline void BGCRC_setMonitorMode (BGCRC_TypeDef *bgcrc, BGCRC_MonitorMode mode)
{
    if (mode == BGCRC_MONITOR_MODE_READ)
    {
        CLEAR_BIT(bgcrc->CR.WORDVAL, BGCRC_CR_MONSRC_M);
    }
    else
    {
        SET_BIT(bgcrc->CR.WORDVAL, BGCRC_CR_MONSRC_M);
    }
}

/**
  * \brief  Enables reversing function.
  * \param  bgcrc    Pointer to a BGCRC_TypeDef structure
  *                   - BGCRC1: BGCRC1 base address index
  *                   - BGCRC2: BGCRC2 base address index
  */
static inline void BGCRC_enableReverse (BGCRC_TypeDef *bgcrc)
{
    MODIFY_REG(bgcrc->CR.WORDVAL, BGCRC_CR_REVERSE_M, BGCRC_REVERSE_ENABLE);
}

/**
  * \brief  Disables reversing function.
  * \param  bgcrc    Pointer to a BGCRC_TypeDef structure
  *                   - BGCRC1: BGCRC1 base address index
  *                   - BGCRC2: BGCRC2 base address index
  */
static inline void BGCRC_disableReverse (BGCRC_TypeDef *bgcrc)
{
    MODIFY_REG(bgcrc->CR.WORDVAL, BGCRC_CR_REVERSE_M, BGCRC_REVERSE_DISABLE);
}

/**
  * \brief  Gets CRC-8 result.
  * \param  bgcrc    Pointer to a BGCRC_TypeDef structure
  *                   - BGCRC1: BGCRC1 base address index
  *                   - BGCRC2: BGCRC2 base address index
  */
static inline uint8_t BGCRC_getCrc8Result (BGCRC_TypeDef *bgcrc)
{
    return READ_REG(bgcrc->DATAOUT.WORDVAL) >> 24U;
}

/**
  * \brief  Gets CRC-16 result.
  * \param  bgcrc    Pointer to a BGCRC_TypeDef structure
  *                   - BGCRC1: BGCRC1 base address index
  *                   - BGCRC2: BGCRC2 base address index
  */
static inline uint16_t BGCRC_getCrc16Result (BGCRC_TypeDef *bgcrc)
{
    return READ_REG(bgcrc->DATAOUT.WORDVAL) >> 16U;
}

/**
  * \brief  Gets CRC-32 result.
  * \param  bgcrc    Pointer to a BGCRC_TypeDef structure
  *                   - BGCRC1: BGCRC1 base address index
  *                   - BGCRC2: BGCRC2 base address index
  */
static inline uint32_t BGCRC_getCrc32Result (BGCRC_TypeDef *bgcrc)
{
    return READ_REG(bgcrc->DATAOUT.WORDVAL);
}

/**
  * \brief  Initializes the BGCRC peripheral for CRC-8.
  * \param  bgcrc            Pointer to a BGCRC_TypeDef structure
  *                           - BGCRC1: BGCRC1 base address index
  *                           - BGCRC2: BGCRC2 base address index
  * \param  initValue        8-bit initial value
  *                           This parameter can be any value of uint8_t
  * \param  polyType         The type of polynomial
  *                           - BGCRC_POLY_CRC8:      8-bit polynomial 0x07
  *                           - BGCRC_POLY_CRC8_ITU:  8-bit polynomial 0x07
  *                           - BGCRC_POLY_CRC8_ROHC: 8-bit polynomial 0x07
  * \param  enableReverse    Select whether to reverse the input and output data
                              This parameter can be any value of @ref BGCRC_REVERSEENABLE
  */
extern void BGCRC_initCrc8 (BGCRC_TypeDef *bgcrc, uint8_t initValue,
                            BGCRC_PolyType polyType, BGCRC_ReverseEnable enableReverse);

/**
  * \brief  Initializes the BGCRC peripheral for CRC-16.
  * \param  bgcrc            Pointer to a BGCRC_TypeDef structure
  *                           - BGCRC1: BGCRC1 base address index
  *                           - BGCRC2: BGCRC2 base address index
  * \param  initValue        16-bit initial value
  *                           This parameter can be any value of uint16_t
  * \param  polyType         The type of polynomial
  *                           - BGCRC_POLY_CRC16_IBM:         16-bit polynomial 0x8005
  *                           - BGCRC_POLY_CRC16_MAXIM:       16-bit polynomial 0x8005
  *                           - BGCRC_POLY_CRC16_USB:         16-bit polynomial 0x8005
  *                           - BGCRC_POLY_CRC16_MODBUS:      16-bit polynomial 0x8005
  *                           - BGCRC_POLY_CRC16_CCITT:       16-bit polynomial 0x1021
  *                           - BGCRC_POLY_CRC16_CCITT_FALSE: 16-bit polynomial 0x1021
  *                           - BGCRC_POLY_CRC16_X25:         16-bit polynomial 0x1021
  *                           - BGCRC_POLY_CRC16_XMODEM:      16-bit polynomial 0x1021
  * \param  enableReverse    Select whether to reverse the input and output data
                              This parameter can be any value of @ref BGCRC_REVERSEENABLE
  */
extern void BGCRC_initCrc16 (BGCRC_TypeDef *bgcrc, uint16_t initValue,
                             BGCRC_PolyType polyType, BGCRC_ReverseEnable enableReverse);

/**
  * \brief  Initializes the BGCRC peripheral for CRC-32.
  * \param  bgcrc            Pointer to a BGCRC_TypeDef structure
  *                           - BGCRC1: BGCRC1 base address index
  *                           - BGCRC2: BGCRC2 base address index
  * \param  initValue        32-bit initial value
  *                           This parameter can be any value of uint32_t
  * \param  polyType         The type of polynomial
  *                           - BGCRC_POLY_CRC32:       32-bit polynomial 0x04C11DB7
  *                           - BGCRC_POLY_CRC32_MPEG2: 32-bit polynomial 0x04C11DB7
  *                           - BGCRC_POLY_CRC32_C:     32-bit polynomial 0x1EDC6F41
  * \param  enableReverse    Select whether to reverse the input and output data
                              This parameter can be any value of @ref BGCRC_REVERSEENABLE
  */
extern void BGCRC_initCrc32 (BGCRC_TypeDef *bgcrc, uint32_t initValue,
                             BGCRC_PolyType polyType, BGCRC_ReverseEnable enableReverse);

/**
  * \brief  Writes 8-bit data to data register.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  */
extern void BGCRC_write8BitData (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Writes 32-bit data to data register.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 32-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \param  enableReverse    Select whether to reverse the input and output data
                              This parameter can be any value of @ref BGCRC_REVERSEENABLE
  */
void BGCRC_write32BitData (BGCRC_TypeDef *bgcrc, uint32_t *pBuf, uint32_t byteCnt,
                           BGCRC_ReverseEnable enableReverse);

/**
  * \brief  Calculates CRC8 algorithm
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint8_t
  */
extern uint8_t BGCRC_calcCrc8 (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC8/ITU algorithm
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint8_t
  */
extern uint8_t BGCRC_calcCrc8Itu (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC8/ROHC algorithm
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint8_t
  */
extern uint8_t BGCRC_calcCrc8Rohc (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/IBM algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
extern uint16_t BGCRC_calcCrc16Ibm (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/MAXIM algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
extern uint16_t BGCRC_calcCrc16Maxim (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/USB algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
extern uint16_t BGCRC_calcCrc16Usb (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/MODBUS algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
extern uint16_t BGCRC_calcCrc16Modbus (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/CCITT algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
extern uint16_t BGCRC_calcCrc16Ccitt (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/CCITTFALSE algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
extern uint16_t BGCRC_calcCrc16CcittFalse (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/X25 algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
extern uint16_t BGCRC_calcCrc16X25 (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/XMODEM algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  *                     - BGCRC2: BGCRC2 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
extern uint16_t BGCRC_calcCrc16Xmodem (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC32 algorithm.
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
extern uint32_t BGCRC_calcCrc32 (BGCRC_TypeDef *bgcrc, uint32_t *pBuf, uint32_t byteCnt);

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
extern uint32_t BGCRC_calcCrc32Mpeg2 (BGCRC_TypeDef *bgcrc, uint32_t *pBuf, uint32_t byteCnt);

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
extern uint32_t BGCRC_calcCrc32C (BGCRC_TypeDef *bgcrc, uint32_t *pBuf, uint32_t byteCnt);

/**
 * \brief Configures monitor.
 * \param bgcrc            Pointer to a BGCRC_TypeDef structure
 *                          - BGCRC1: BGCRC1 base address index
 *                          - BGCRC2: BGCRC2 base address index
 * \param enableMonitor    Whether to enable the monitor
 *                          This parameter can be any value of @ref BGCRC_MONITORENABLE
 * \param mode             The mode (reading mode/writing mode) of the monitor
 *                          This parameter can be any value of @ref BGCRC_MONITORMODE
 * \param addr             The address to be continuously monitored
 *                          This parameter can be any value of uint32_t
 * \return Returns the status of function execution
 *                          - True:  The monitor are successfully configured
 *                          - False: Monitor configuration failed
 */
extern bool BGCRC_configMonitor (BGCRC_TypeDef *bgcrc, BGCRC_MonitorEnable enableMonitor,
                                 BGCRC_MonitorMode mode, uint32_t addr);

#ifdef __cplusplus
}
#endif


#endif /* __BGCRC_H__ */
