/**
  * @file       qspi.c
  * @author     Alex-J
  * @brief      Function file for NS800RTxxx QSPI module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "qspi.h"


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
 * @brief  Sets the MPU configuration for the QSPI
 * @note   This function sets the MPU configuration for the QSPI module.
 *
 * @param  mpu  mpu pointer to a MPU_Type structure
 *               - MPU: MPU base address index
 */
static void QSPI_setMPU (MPU_Type *mpu)
{
    mpu->RBAR = ((0x84000000 & MPU_RBAR_ADDR_Msk) | (0x01 << MPU_RBAR_REGION_Pos) | (0x01 << MPU_RBAR_VALID_Pos));

    mpu->RASR =
        ((0x03 << MPU_RASR_AP_Pos) | (0x0 << MPU_RASR_TEX_Pos) | (0x1 << MPU_RASR_S_Pos) | (0x0 << MPU_RASR_C_Pos) |
         (0x1 << MPU_RASR_B_Pos) | (0x19 << MPU_RASR_SIZE_Pos) | (0x1 << MPU_RASR_ENABLE_Pos));
    mpu->CTRL = 0x05;
    __DSB();
    __ISB();
}

/**
 * @brief  Open the QSPI module
 * @note   This function opens the QSPI module.
 *
 * @param  protocl    enum of QSPI protocols. Ref \b QSPI_Protocol
 * @param  div        enum of QSPI clock division. Ref \b QSPI_ClkDiv
 * @param  addrWidth  enum of QSPI address width. Ref \b QSPI_AddrWidth
 * @param  cycle      enum of QSPI dummy cycle. Ref \b QSPI_DummyCycle
 * @param  qsckWidth  enum of QSPI QSCK width. Ref \b QSPI_QsckHighWidth
 * @param  mode       enum of QSPI read mode. Ref \b QSPI_ReadMode
 */
void QSPI_open (QSPI_Protocol protocl, QSPI_ClkDiv div, QSPI_AddrWidth addrWidth, QSPI_DummyCycle cycle,
                QSPI_QsckHighWidth qsckWidth, QSPI_ReadMode mode)
{
    QSPI_setMPU(MPU);
    /* Initialized unused registers. */
    QSPI_clearRomAccessDetectStatus(QSPI);
    QSPI_clearInstructCode(QSPI, QSPI_SFMSIC_SFMCIC_M);
    QSPI_selectWpPinLevel(QSPI, PIN_LOW_LEVEL);
    QSPI_setBankSwitchAddress(QSPI, 0x00);
    /* Set the initial SPI protocol. */
    QSPI_selectSpiProtocol(QSPI, protocl);
    QSPI_enableSwitchIOQsckTime(QSPI, ENABLE);
    /* Set the SPI clock rate */
    QSPI_setClockDivision(QSPI, div);

    if ((div == HLCK_DIV_3) || (div == HLCK_DIV_5) || (div == HLCK_DIV_7) || (div == HLCK_DIV_9) ||
        (div == HLCK_DIV_11) || (div == HLCK_DIV_13) || (div == HLCK_DIV_15) || (div == HLCK_DIV_17))
    {
        QSPI_enableDutyCorrection(QSPI, ENABLE);
    }
    else
    {
        QSPI_enableDutyCorrection(QSPI, DISABLE);
    }
    /* Set the address mode. */
    QSPI_setAddressBytes(QSPI, addrWidth);
    /* Set the number of dummy cycles in QSPI peripheral */
    QSPI_selectFastReadDummyNumber(QSPI, cycle);

    QSPI_setXipModeData(QSPI, (QSPI_SFMSDC_SFMXD_M >> QSPI_SFMSDC_SFMXD_S));
    /* Set configured minimum high level width for QSSL signal. */
    QSPI_setChipSelectCtrl(QSPI, ((uint32_t)qsckWidth | QSPI_SFMSSC_SFMSHD_M | QSPI_SFMSSC_SFMSLD_M));
    /* Set the read mode based on user configuration. */
    QSPI_setReadMode(QSPI, mode);

    QSPI_setTransModeCtrl(QSPI, QSPI_SFMSMD_SFMPFE_M);
}

/**
 * @brief  Writes the D0 byte in QSPI Dual Mode
 * @note   This function writes a byte in extended SPI mode 
 *         when the QSPI peripheral is configured for dual mode.
 *
 * @param  byte  a value to be written
 */
void QSPI_writeDualModeD0Byte (uint8_t byte)
{
    /* Every other bit ends up on D0. Unused bits are set. */
    uint16_t value = QSPI_DUAL_EVEN_BITS_CLEARED;

    for (uint32_t i = 0U; i < 8U; i++)
    {
        uint16_t bit = ((uint16_t) (byte >> i) & 1U);

        /* Place bits in every other bit (bit 0, 2, 4 ... 14). */
        uint16_t bit_mask = (uint16_t) (bit << (i * 2U));

        value |= bit_mask;
    }

    QSPI_setCommPort(QSPI, (uint8_t)(value >> 8U));
    QSPI_setCommPort(QSPI, (uint8_t)value);
}

/**
 * @brief  Writes the D0 byte in QSPI Quad Mode
 * @note   This function writes a byte in extended SPI mode 
 *         when the QSPI peripheral is configured for quad mode.
 *
 * @param  byte  a value to be written
 */
void QSPI_writeQuadModeD0Byte (uint8_t byte)
{
    /* The LSB of each nibble ends up on D0. */
    uint32_t value = QSPI_QUAD_LSB_NIBBLE_CLEARED;

    for (uint32_t i = 0U; i < 8U; i++)
    {
        uint32_t bit = ((uint32_t) (byte >> i) & 1U);

        /* Place bits in every 4th bit (bit 0, 4, 8, ... 28). */
        uint32_t bit_mask = bit << (i * 4U);

        value |= bit_mask;
    }

    QSPI_setCommPort(QSPI, (uint8_t)(value >> 24U));
    QSPI_setCommPort(QSPI, (uint8_t)(value >> 16U));
    QSPI_setCommPort(QSPI, (uint8_t)(value >> 8U));
    QSPI_setCommPort(QSPI, (uint8_t)value);
}

/**
 * @brief  QSPI directly write data.
 * @note   This function writes data directly via QSPI.
 *
 * @param  wData      pointer index of the data to be written
 * @param  dataLen    the length of the data to be written
 * @param  rdAfterWr  after writing is completed, switch to reading
 */
void QSPI_writeDirect (uint8_t *wData, uint32_t dataLen, uint8_t rdAfterWr)
{
    /* Enter direct communication mode */
    QSPI_setDirectCommMode(QSPI);

    /* Write data to QSPI. */
    for(uint32_t i=0; i<dataLen; i++)
    {
        // QSPI_setCommPort(QSPI, wData[i]);
        QSPI->SFMCOM.WORDVAL = wData[i];
    }

    if (rdAfterWr == DISABLE)
    {
        QSPI_setDirectCommMode(QSPI);

        QSPI_setRomAccessMode(QSPI);
    }
}

/**
 * @brief  QSPI directly read data.
 * @note   This function reads data directly via QSPI.
 *
 * @param  rData    memory pointer index to read data
 * @param  dataLen  the length of the data to be read
 */
void QSPI_readDirect (uint8_t *rData, uint32_t dataLen)
{
    /* Read data from QSPI. */
    for (uint32_t i = 0; i < dataLen; i++)
    {
        rData[i] = QSPI_getCommPort(QSPI);
    }

    QSPI_setDirectCommMode(QSPI);

    QSPI_setRomAccessMode(QSPI);
}

/**
 * @brief  QSPI enter XIP mode
 * @note   This function puts QSPI into XIP mode.
 *
 * @param  code   mode data for serial flash
 * @param  cycle  number of dummy cycles
 */
void QSPI_enterXip (uint8_t code, QSPI_DummyCycle cycle)
{
    QSPI_setXipModeData(QSPI, code);
    QSPI_setXipModePermit(QSPI, ENABLE);
    QSPI_selectFastReadDummyNumber(QSPI, cycle);

    while (QSPI_getXipModeStatus(QSPI) == 0)
    {
        /* code */
    }
}

/**
 * @brief  QSPI exit XIP mode
 * @note   This function makes QSPI exit XIP mode.
 */
void QSPI_exitXip (void)
{
    QSPI_setXipModePermit(QSPI, DISABLE);

    while (QSPI_getXipModeStatus(QSPI) != 0)
    {
        /* code */
    }
}

/**
 * @brief  QSPI set bank 
 * @note   This function sets QSPI bank switching address.
 * 
 * @param  bank  bank switching address. Range[0~0x3E]
 */
void QSPI_setBank (uint8_t bank)
{
    QSPI_setBankSwitchAddress(QSPI, bank);
}

/**
 * @brief  Close the QSPI driver module.
 * @note   This function closes QSPI driver module.
 */
void QSPI_close (void)
{
    /* code */
}
