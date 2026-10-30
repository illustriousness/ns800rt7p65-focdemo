/**
  * @file       qspi.h
  * @author     Alex-J
  * \brief      Header file for NS800RT7xxx QSPI module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __QSPI_H__
#define __QSPI_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup QSPI_EXPORTED_TYPES QSPI Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'QSPI' module.
  */

/** @defgroup QSPI_READMODE QSPI Module's Read Mode
  * @{
  * @brief  Values are used to control the read mode of the QSPI.
  */
typedef enum {
    STANDARD_READ = 0U,       /*!< Standard Read */
    FAST_READ,                /*!< Fast Read */
    FAST_READ_DUAL_OUT,       /*!< Fast Read Dual Output */
    FAST_READ_DUAL_IN_OUT,    /*!< Fast Read Dual I/O */
    FAST_READ_QUAD_OUT,       /*!< Fast Read Quad Output  */
    FAST_READ_QUAD_IN_OUT     /*!< Fast Read Quad I/O */
} QSPI_ReadMode;

/**
  * @}
  */

/** @defgroup QSPI_ADDRWIDTH QSPI Module's Number of Address Bytes
  * @{
  * @brief  Values are used to control the width of the QSPI address.
  */
typedef enum {
    ADDRESS_1_BYTE = 0U,    /*!< 1 Byte */
    ADDRESS_2_BYTES,        /*!< 2 Bytes */
    ADDRESS_3_BYTES,        /*!< 3 Bytes */
    ADDRESS_4_BYTES         /*!< 4 Bytes */
} QSPI_AddrWidth;

/**
  * @}
  */

/** @defgroup QSPI_CLKDIV QSPI Module's Clock Division
  * @{
  * @brief  Values are used to control the clock division of the QSPI.
  */
typedef enum {
    HLCK_DIV_2 = 0U,    /*!< 2 HCLK */
    HLCK_DIV_3,         /*!< 3 HCLK */
    HLCK_DIV_4,         /*!< 4 HCLK */
    HLCK_DIV_5,         /*!< 5 HCLK */
    HLCK_DIV_6,         /*!< 6 HCLK */
    HLCK_DIV_7,         /*!< 7 HCLK */
    HLCK_DIV_8,         /*!< 8 HCLK */
    HLCK_DIV_9,         /*!< 9 HCLK */
    HLCK_DIV_10,        /*!< 10 HCLK */
    HLCK_DIV_11,        /*!< 11 HCLK */
    HLCK_DIV_12,        /*!< 12 HCLK */
    HLCK_DIV_13,        /*!< 13 HCLK */
    HLCK_DIV_14,        /*!< 14 HCLK */
    HLCK_DIV_15,        /*!< 15 HCLK */
    HLCK_DIV_16,        /*!< 16 HCLK */
    HLCK_DIV_17,        /*!< 17 HCLK */
    HLCK_DIV_18,        /*!< 18 HCLK */
    HLCK_DIV_20,        /*!< 20 HCLK */
    HLCK_DIV_22,        /*!< 22 HCLK */
    HLCK_DIV_24,        /*!< 24 HCLK */
    HLCK_DIV_26,        /*!< 26 HCLK */
    HLCK_DIV_28,        /*!< 28 HCLK */
    HLCK_DIV_30,        /*!< 30 HCLK */
    HLCK_DIV_32,        /*!< 32 HCLK */
    HLCK_DIV_34,        /*!< 34 HCLK */
    HLCK_DIV_36,        /*!< 36 HCLK */
    HLCK_DIV_38,        /*!< 38 HCLK */
    HLCK_DIV_40,        /*!< 40 HCLK */
    HLCK_DIV_42,        /*!< 42 HCLK */
    HLCK_DIV_44,        /*!< 44 HCLK */
    HLCK_DIV_46,        /*!< 46 HCLK */
    HLCK_DIV_48         /*!< 48 HCLK */
} QSPI_ClkDiv;

/**
  * @}
  */

/** @defgroup QSPI_QSCKHIGHWIDTH QSPI Module's QSCK Minimum High-level Width
  * @{
  * @brief  Values are used to control the QSCK minimum high-level width of the QSPI.
  */
typedef enum {
    HIGH_LVL_1_QSCK = 0U,    /*!< 1 QSCK */
    HIGH_LVL_2_QSCK,         /*!< 2 QSCK */
    HIGH_LVL_3_QSCK,         /*!< 3 QSCK */
    HIGH_LVL_4_QSCK,         /*!< 4 QSCK */
    HIGH_LVL_5_QSCK,         /*!< 5 QSCK */
    HIGH_LVL_6_QSCK,         /*!< 6 QSCK */
    HIGH_LVL_7_QSCK,         /*!< 7 QSCK */
    HIGH_LVL_8_QSCK,         /*!< 8 QSCK */
    HIGH_LVL_9_QSCK,         /*!< 9 QSCK */
    HIGH_LVL_10_QSCK,        /*!< 10 QSCK */
    HIGH_LVL_11_QSCK,        /*!< 11 QSCK */
    HIGH_LVL_12_QSCK,        /*!< 12 QSCK */
    HIGH_LVL_13_QSCK,        /*!< 13 QSCK */
    HIGH_LVL_14_QSCK,        /*!< 14 QSCK */
    HIGH_LVL_15_QSCK,        /*!< 15 QSCK */
    HIGH_LVL_16_QSCK         /*!< 16 QSCK */
} QSPI_QsckHighWidth;

/**
  * @}
  */

/** @defgroup QSPI_DUMMYCYCLE QSPI Module's Number of Dummy Cycle
  * @{
  * @brief  Values are used to control the dummy cycle of the QSPI fast read instruction.
  */
typedef enum {
    DEFAULT_DUMMY_CYCLE = 0U,    /*!< Default dummy cycles for each instruction */
    DUMMY_CYCLE_3_QSCK,          /*!< 3 QSCK */
    DUMMY_CYCLE_4_QSCK,          /*!< 4 QSCK */
    DUMMY_CYCLE_5_QSCK,          /*!< 5 QSCK */
    DUMMY_CYCLE_6_QSCK,          /*!< 6 QSCK */
    DUMMY_CYCLE_7_QSCK,          /*!< 7 QSCK */
    DUMMY_CYCLE_8_QSCK,          /*!< 8 QSCK */
    DUMMY_CYCLE_9_QSCK,          /*!< 9 QSCK */
    DUMMY_CYCLE_10_QSCK,         /*!< 10 QSCK */
    DUMMY_CYCLE_11_QSCK,         /*!< 11 QSCK */
    DUMMY_CYCLE_12_QSCK,         /*!< 12 QSCK */
    DUMMY_CYCLE_13_QSCK,         /*!< 13 QSCK */
    DUMMY_CYCLE_14_QSCK,         /*!< 14 QSCK */
    DUMMY_CYCLE_15_QSCK,         /*!< 15 QSCK */
    DUMMY_CYCLE_16_QSCK,         /*!< 16 QSCK */
    DUMMY_CYCLE_17_QSCK          /*!< 17 QSCK */
} QSPI_DummyCycle;

/**
  * @}
  */

/** @defgroup QSPI_PROTOCOL QSPI Module's Protocol
  * @{
  * @brief  Values are used to control the protocol of the QSPI.
  */
typedef enum {
    EXTENDED_SPI_PROTOCOL = 0U,    /*!< Extended SPI protocol */
    DUAL_SPI_PROTOCOL,             /*!< Dual SPI protocol */
    QUAD_SPI_PROTOCOL,             /*!< Quad SPI protocol */
    SETTING_PROHIBITED             /*!< Setting prohibited */
} QSPI_Protocol;

/**
  * @}
  */

/** @defgroup QSPI_PINLEVEL QSPI Module's WP Pin Level
  * @{
  * @brief  Values are used to control the pin level of the QSPI WP pin.
  */
typedef enum {
    PIN_LOW_LEVEL = 0U,    /*!< Pin low level */
    PIN_HIGH_LEVEL         /*!< Pin high level */
} QSPI_PinLevel;

/**
  * @}
  */

/** @defgroup QSPI_DEVICE_START_ADDR QSPI Device Start Address
  * @{
  * @brief  Macro definitions about QSPI device start address definition.
  */
#define QSPI_DEVICE_START_ADDR    (0x80000000UL)    /*!< QSPI device start address */

/**
  * @}
  */

/** @defgroup QSPI_END_UP_ON_D0 QSPI End Up on D0
  * @{
  * @brief  Macro definitions about QSPI end up on d0 definition.
  */
#define QSPI_DUAL_EVEN_BITS_CLEARED     (0xAAAAUL)        /*!< QSPI dual mode byte even bit clear */
#define QSPI_QUAD_LSB_NIBBLE_CLEARED    (0xEEEEEEEEUL)    /*!< QSPI quad mode double word lsb nibble clear */

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
 * \brief  Sets the Transfer Mode Control Register
 * \note   This function sets the transfer mode control register
 *         of the QSPI.
 *
 * \param  qspi    qspi pointer to a QSPI_TypeDef structure
 *                  - QSPI: QSPI base address index
 * \param  config  a value of the transfer mode configuration.
 */
static inline void QSPI_setTransModeCtrl (QSPI_TypeDef *qspi, uint16_t config)
{
    SET_BIT(qspi->SFMSMD.WORDVAL, (uint32_t)config);
}

/**
 * \brief  Clears the Transfer Mode Control Register
 * \note   This function clears the transfer mode control register
 *         of the QSPI.
 *
 * \param  qspi    qspi pointer to a QSPI_TypeDef structure
 *                  - QSPI: QSPI base address index
 * \param  config  a value of the transfer mode configuration.
 */
static inline void QSPI_clearTransModeCtrl (QSPI_TypeDef *qspi, uint16_t config)
{
    CLEAR_BIT(qspi->SFMSMD.WORDVAL, (uint32_t)config);
}

/**
 * \brief  Gets the Transfer Mode Control Register
 * \note   This function gets the transfer mode control register value
 *         of the QSPI.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 * \return Returns the configuration value of the transfer mode.
 */
static inline uint16_t QSPI_getTransModeCtrl (QSPI_TypeDef *qspi)
{
    return (uint16_t)(qspi->SFMSMD.WORDVAL);
}

/**
 * \brief  Sets the Read Mode
 * \note   This function sets the read mode of the QSPI.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 * \param  mode  a value of the read mode.
 */
static inline void QSPI_setReadMode (QSPI_TypeDef *qspi, QSPI_ReadMode mode)
{
    if (mode <= FAST_READ_QUAD_IN_OUT)
    {
        MODIFY_REG(qspi->SFMSMD.WORDVAL, QSPI_SFMSMD_SFMRM_M, (uint32_t)mode);
    }
}

/**
 * \brief  Sets the Chip Selection Control Register
 * \note   This function sets the chip selection control register
 *         of the QSPI.
 *
 * \param  qspi    qspi pointer to a QSPI_TypeDef structure
 *                  - QSPI: QSPI base address index
 * \param  config  a value of the chip selection configuration.
 */
static inline void QSPI_setChipSelectCtrl (QSPI_TypeDef *qspi, uint8_t config)
{
    MODIFY_REG(qspi->SFMSSC.WORDVAL, QSPI_SFMSSC_SFMSW_M, (uint32_t)(config & 0x3F));
}

/**
 * \brief  Clears the Chip Selection Control Register
 * \note   This function clears the chip selection control register
 *         of the QSPI.
 *
 * \param  qspi    qspi pointer to a QSPI_TypeDef structure
 *                  - QSPI: QSPI base address index
 * \param  config  a value of the chip selection configuration.
 */
static inline void QSPI_clearChipSelectCtrl (QSPI_TypeDef *qspi, uint8_t config)
{
    CLEAR_BIT(qspi->SFMSSC.WORDVAL, (uint32_t)(config & 0x3F));
}

/**
 * \brief  Gets the Chip Selection Control Register
 * \note   This function gets the chip selection control register value
 *         of the QSPI.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 * \return Returns the configuration value of the chip selection.
 */
static inline uint8_t QSPI_getChipSelectCtrl (QSPI_TypeDef *qspi)
{
    return (uint8_t)(qspi->SFMSSC.WORDVAL);
}

/**
 * \brief  Sets the Clock Control Register
 * \note   This function sets the clock control register of the QSPI.
 *
 * \param  qspi    qspi pointer to a QSPI_TypeDef structure
 *                  - QSPI: QSPI base address index
 * \param  config  a value of the Clock configuration.
 */
static inline void QSPI_setClockCtrl (QSPI_TypeDef *qspi, uint8_t config)
{
    SET_BIT(qspi->SFMSKC.WORDVAL, (uint32_t)(config & 0x1F));
}

/**
 * \brief  Clears the Clock Control Register
 * \note   This function clears the clock control register of the QSPI.
 *
 * \param  qspi    qspi pointer to a QSPI_TypeDef structure
 *                  - QSPI: QSPI base address index
 * \param  config  a value of the Clock configuration.
 */
static inline void QSPI_clearClockCtrl (QSPI_TypeDef *qspi, uint8_t config)
{
    CLEAR_BIT(qspi->SFMSKC.WORDVAL, (uint32_t)(config & 0x1F));
}

/**
 * \brief  Gets the Clock Control Register
 * \note   This function gets the clock control register value of the QSPI.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 * \return Returns the configuration value of the clock.
 */
static inline uint8_t QSPI_getClockCtrl (QSPI_TypeDef *qspi)
{
    return (uint8_t)(qspi->SFMSKC.WORDVAL);
}

/**
 * \brief  Sets the Clock Division
 * \note   This function sets the clock division of the QSPI.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 * \param  div   a value of the Clock division.
 */
static inline void QSPI_setClockDivision (QSPI_TypeDef *qspi, QSPI_ClkDiv div)
{
    MODIFY_REG(qspi->SFMSKC.WORDVAL, QSPI_SFMSKC_SFMDV_M, (uint32_t)div);
}

/**
 * \brief  Enables the Duty ratio correction function
 * \note   This function sets the duty ratio correction of the QSPI.
 *
 * \param  qspi    qspi pointer to a QSPI_TypeDef structure
 *                  - QSPI: QSPI base address index
 * \param  enable  the value is uesed to control the duty ratio correction.
 *                  0: disaale 
 *                  1: enable
 */
static inline void QSPI_enableDutyCorrection (QSPI_TypeDef *qspi, uint8_t enable)
{
    MODIFY_REG(qspi->SFMSKC.WORDVAL, QSPI_SFMSKC_SFMDTY_M, (((uint32_t)enable & 0x1) << QSPI_SFMSKC_SFMDTY_S));
}


/**
 * \brief  Gets the Status Register
 * \note   This function gets the status register value of the QSPI.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 * \return Returns the status value of the qspi.
 */
static inline uint8_t QSPI_getStatus (QSPI_TypeDef *qspi)
{
    return (uint8_t)(qspi->SFMSST.WORDVAL);
}

/**
 * \brief  Sets the Communication Port Register
 * \note   This function sets the communication port register of the QSPI.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 * \param  sfmd  a value of the communication port.
 */
static inline void QSPI_setCommPort (QSPI_TypeDef *qspi, uint8_t sfmd)
{
    WRITE_REG(qspi->SFMCOM.WORDVAL, (uint32_t)sfmd);
}

/**
 * \brief  Gets the Communication Port Register
 * \note   This function gets the communication port register value of the QSPI.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 * \return Returns the value of the communication port.
 */
static inline uint8_t QSPI_getCommPort (QSPI_TypeDef *qspi)
{
    return (uint8_t)(qspi->SFMCOM.WORDVAL);
}

/**
 * \brief  Sets the Direct Communication Mode of the QSPI
 * \note   This function sets the direct communication mode of the QSPI.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 */
static inline void QSPI_setDirectCommMode (QSPI_TypeDef *qspi)
{
    WRITE_REG(qspi->SFMCMD.WORDVAL, QSPI_SFMCMD_DCOM_M);
}

/**
 * \brief  Sets the ROM Access Mode of the QSPI
 * \note   This function sets the rom access mode of the QSPI.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 */
static inline void QSPI_setRomAccessMode (QSPI_TypeDef *qspi)
{
    WRITE_REG(qspi->SFMCMD.WORDVAL, QSPI_SFMCMD_DCOM_S);
}

/**
 * \brief  Gets the QSPI bus cycle completion state in direct communication
 * \note   This function gets the bus cycle completion state value of the QSPI.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 * \return Returns the value of the bus cycle completion state.
 */
static inline uint8_t QSPI_getCommBusyState (QSPI_TypeDef *qspi)
{
    return (uint8_t)(qspi->SFMCST.WORDVAL & QSPI_SFMCST_COMBSY_M);
}

/**
 * \brief  Gets the ROM access detection status in direct communication
 * \note   This function gets the rom access detection status value of the QSPI.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 * \return Returns the value of the rom access detection status.
 */
static inline uint8_t QSPI_getRomAccessDetectStatus (QSPI_TypeDef *qspi)
{
    return (uint8_t)(qspi->SFMCST.WORDVAL & QSPI_SFMCST_EROMR_M);
}

/**
 * \brief  Clears the ROM access detection status of the QSPI
 * \note   This function clears the rom access detection status of the QSPI.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 */
static inline void QSPI_clearRomAccessDetectStatus (QSPI_TypeDef *qspi)
{
    CLEAR_BIT(qspi->SFMCST.WORDVAL, QSPI_SFMCST_EROMR_M);
}

/**
 * \brief  Sets the Instruction Code Register
 * \note   This function sets the instruction code register of the QSPI.
 *
 * \param  qspi     qspi pointer to a QSPI_TypeDef structure
 *                   - QSPI: QSPI base address index
 * \param  insCode  a value of the instruction code.
 */
static inline void QSPI_setInstructCode (QSPI_TypeDef *qspi, uint8_t insCode)
{
    SET_BIT(qspi->SFMSIC.WORDVAL, (uint32_t)insCode);
}

/**
 * \brief  Clears the Instruction Code Register
 * \note   This function clears the instruction code register of the QSPI.
 *
 * \param  qspi     qspi pointer to a QSPI_TypeDef structure
 *                   - QSPI: QSPI base address index
 * \param  insCode  a value of the instruction code.
 */
static inline void QSPI_clearInstructCode (QSPI_TypeDef *qspi, uint8_t insCode)
{
    CLEAR_BIT(qspi->SFMSIC.WORDVAL, (uint32_t)insCode);
}

/**
 * \brief  Gets the Instruction Code Register
 * \note   This function gets the instruction code register value of the QSPI.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 * \return Returns the value of the instruction code.
 */
static inline uint8_t QSPI_getInstructCode (QSPI_TypeDef *qspi)
{
    return (uint8_t)(qspi->SFMSIC.WORDVAL);
}

/**
 * \brief  Sets the Number of Address Bytes
 * \note   This function sets the address bytes of the QSPI.
 *
 * \param  qspi   qspi pointer to a QSPI_TypeDef structure
 *                 - QSPI: QSPI base address index
 * \param  width  the bytes of the QSPI address.
 */
static inline void QSPI_setAddressBytes (QSPI_TypeDef *qspi, QSPI_AddrWidth width)
{
    MODIFY_REG(qspi->SFMSAC.WORDVAL, QSPI_SFMSAC_SFMAS_M, (uint32_t)width);
}

/**
 * \brief  Gets the Number of Address Bytes
 * \note   This function gets the address bytes of the QSPI.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 * \return Returns the value of the address bytes.
 */
static inline uint8_t QSPI_getAddressBytes (QSPI_TypeDef *qspi)
{
    return (uint8_t)(qspi->SFMSAC.WORDVAL & QSPI_SFMSAC_SFMAS_M);
}

/**
 * \brief  Sets the 4-byte address read instruction code
 * \note   This function sets the address bytes of the QSPI.
 *
 * \param  qspi    qspi pointer to a QSPI_TypeDef structure
 *                  - QSPI: QSPI base address index
 * \param  enable  the value is uesed to control 4-byte address read instruction code.
 *                  0: disaale 
 *                  1: enable
 */
static inline void QSPI_set4BytesAddrCode (QSPI_TypeDef *qspi, uint8_t enable)
{
    MODIFY_REG(qspi->SFMSAC.WORDVAL, QSPI_SFMSAC_SFM4BC_M, (((uint32_t)enable & 0x1) << QSPI_SFMSAC_SFM4BC_S));
}

/**
 * \brief  Sets the Number of dummy cycles select for Fast Read instructions
 * \note   This function sets the number of dummy cycles for the QSPI.
 *
 * \param  qspi   qspi pointer to a QSPI_TypeDef structure
 *                 - QSPI: QSPI base address index
 * \param  cycle  a value of the number of dummy cycles.
 */
static inline void QSPI_selectFastReadDummyNumber (QSPI_TypeDef *qspi, QSPI_DummyCycle cycle)
{
    MODIFY_REG(qspi->SFMSDC.WORDVAL, QSPI_SFMSDC_SFMDN_M, (uint32_t)cycle);
}

/**
 * \brief  Gets the XIP Mode Status
 * \note   This function gets the XIP mode status value of the QSPI.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 * \return Returns the value of the XIP mode status.
 */
static inline uint8_t QSPI_getXipModeStatus (QSPI_TypeDef *qspi)
{
    return (uint8_t)(qspi->SFMSDC.WORDVAL & QSPI_SFMSDC_SFMXST_M);
}

/**
 * \brief  Sets the XIP Mode Permission
 * \note   This function sets the XIP mode permission of the QSPI.
 *
 * \param  qspi    qspi pointer to a QSPI_TypeDef structure
 *                  - QSPI: QSPI base address index
 * \param  enable  the value is uesed to control 4-byte address read instruction code.
 *                  0: disaale
 *                  1: enable
 */
static inline void QSPI_setXipModePermit (QSPI_TypeDef *qspi, uint8_t enable)
{
    MODIFY_REG(qspi->SFMSDC.WORDVAL, QSPI_SFMSDC_SFMXEN_M, (((uint32_t)enable & 0x1) << QSPI_SFMSDC_SFMXEN_S));
}

/**
 * \brief  Sets the XIP Mode Data
 * \note   This function sets the XIP mode data for the QSPI serial flash.
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 * \param  data  the value of the mode data.
 */
static inline void QSPI_setXipModeData (QSPI_TypeDef *qspi, uint8_t data)
{
    MODIFY_REG(qspi->SFMSDC.WORDVAL, QSPI_SFMSDC_SFMXD_M, ((uint32_t)data << QSPI_SFMSDC_SFMXD_S));
}

/**
 * \brief  Selects the SPI Protocol
 * \note   This function selects the protocol for the QSPI.
 *
 * \param  qspi     qspi pointer to a QSPI_TypeDef structure
 *                   - QSPI: QSPI base address index
 * \param  protocl  a value of the SPI protocol.
 */
static inline void QSPI_selectSpiProtocol (QSPI_TypeDef *qspi, QSPI_Protocol protocl)
{
    if (protocl != SETTING_PROHIBITED)
    {
        MODIFY_REG(qspi->SFMSPC.WORDVAL, QSPI_SFMSPC_SFMSPI_M, (uint32_t)protocl);
    }
}

/**
 * \brief  Sets the Minimum Time Select for Input/output Switch
 * \note   This function sets the minimum time select for I/O switch of the QSPI.
 *
 * \param  qspi    qspi pointer to a QSPI_TypeDef structure
 *                  - QSPI: QSPI base address index
 * \param  enable  the value is uesed to control the minimum time select for I/O switch.
 *                  0: disaale
 *                  1: enable
 */
static inline void QSPI_enableSwitchIOQsckTime (QSPI_TypeDef *qspi, uint8_t enable)
{
    MODIFY_REG(qspi->SFMSPC.WORDVAL, QSPI_SFMSPC_SFMSDE_M, (((uint32_t)enable & 0x1) << QSPI_SFMSPC_SFMSDE_S));
}

/**
 * \brief  Selects the WP Pin Level
 * \note   This function selects the pin level for the QSPI WP Pin.
 *
 * \param  qspi   qspi pointer to a QSPI_TypeDef structure
 *                 - QSPI: QSPI base address index
 * \param  level  a value of the level of WP pin.
 */
static inline void QSPI_selectWpPinLevel (QSPI_TypeDef *qspi, QSPI_PinLevel level)
{
    MODIFY_REG(qspi->SFMPMD.WORDVAL, QSPI_SFMPMD_SFMWPL_M, ((uint32_t)level << QSPI_SFMPMD_SFMWPL_S));
}

/**
 * \brief  Sets the Bank Switching Address
 * \note   This function sets the bank switching address for the QSPI .
 *
 * \param  qspi  qspi pointer to a QSPI_TypeDef structure
 *                - QSPI: QSPI base address index
 * \param  bank  the value of the bank switching address.
 */
static inline void QSPI_setBankSwitchAddress (QSPI_TypeDef *qspi, uint8_t bank)
{
    if (bank < 0x3F)
    {
        MODIFY_REG(qspi->SFMCNT1.WORDVAL, QSPI_SFMCNT1_QSPIEXIT_M, (((uint32_t)bank & 0x3F) << QSPI_SFMCNT1_QSPIEXIT_S));
    }
}

/**
 * \brief  Open the QSPI module
 * \note   This function opens the QSPI module.
 *
 * \param  protocl    enum of QSPI protocols. Ref \b QSPI_Protocol
 * \param  div        enum of QSPI clock division. Ref \b QSPI_ClkDiv
 * \param  addrWidth  enum of QSPI address width. Ref \b QSPI_AddrWidth
 * \param  cycle      enum of QSPI dummy cycle. Ref \b QSPI_DummyCycle
 * \param  qsckWidth  enum of QSPI QSCK width. Ref \b QSPI_QsckHighWidth
 * \param  mode       enum of QSPI read mode. Ref \b QSPI_ReadMode
 */
extern void QSPI_open (QSPI_Protocol protocl, QSPI_ClkDiv div, QSPI_AddrWidth addrWidth, QSPI_DummyCycle cycle,
                QSPI_QsckHighWidth qsckWidth, QSPI_ReadMode mode);

/**
 * \brief  Writes the D0 byte in QSPI Dual Mode
 * \note   This function writes a byte in extended SPI mode 
 *         when the QSPI peripheral is configured for dual mode.
 *
 * \param  byte  a value to be written
 */
extern void QSPI_writeDualModeD0Byte (uint8_t byte);

/**
 * \brief  Writes the D0 byte in QSPI Quad Mode
 * \note   This function writes a byte in extended SPI mode 
 *         when the QSPI peripheral is configured for quad mode.
 *
 * \param  byte  a value to be written
 */
extern void QSPI_writeQuadModeD0Byte (uint8_t byte);

/**
 * \brief  QSPI directly write data.
 * \note   This function writes data directly via QSPI.
 *
 * \param  wData      pointer index of the data to be written
 * \param  dataLen    the length of the data to be written
 * \param  rdAfterWr  after writing is completed, switch to reading
 */
extern void QSPI_writeDirect (uint8_t *wData, uint32_t dataLen, uint8_t rdAfterWr);

/**
 * \brief  QSPI directly read data.
 * \note   This function reads data directly via QSPI.
 *
 * \param  rData    memory pointer index to read data
 * \param  dataLen  the length of the data to be read
 */
extern void QSPI_readDirect (uint8_t *rData, uint32_t dataLen);

/**
 * \brief  QSPI enter XIP mode
 * \note   This function puts QSPI into XIP mode.
 *
 * \param  code   mode data for serial flash
 * \param  cycle  number of dummy cycles
 */
extern void QSPI_enterXip (uint8_t code, QSPI_DummyCycle cycle);

/**
 * \brief  QSPI exit XIP mode
 * \note   This function makes QSPI exit XIP mode.
 */
extern void QSPI_exitXip (void);

/**
 * \brief  QSPI set bank 
 * \note   This function sets QSPI bank switching address.
 * 
 * \param  bank  bank switching address. Range[0~0x3E]
 */
extern void QSPI_setBank (uint8_t bank);

/**
 * \brief  Close the QSPI driver module.
 * \note   This function closes QSPI driver module.
 */
extern void QSPI_close (void);


#ifdef __cplusplus
}
#endif


#endif /* __QSPI_H__ */
