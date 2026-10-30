/**
  * @file       emath_basic.c
  * @author     yangjun
  * @brief      Function file for NS800RT7xxx emath-basic module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "emath.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup EMATH_BASIC_PRIVATE_CONSTANTS EMATH Basic Private Constants
  * @{
  * @brief  Macro definitions are used with this file private about 'EMATH' module.
  */

/** @defgroup EMATH_ERRSTAT_REGBIT EMATH ERRSTAT register bits
 * @{
 * @brief  Macro definitions about EMATH ERRSTAT register bits definition.
 */
#define EMATH_ERRSTAT_OVERFLOW         (0x1UL)     /*!< ERRSTAT OVERFLOW bit */
#define EMATH_ERRSTAT_NAN              (0x2UL)     /*!< ERRSTAT NAN bit */
#define EMATH_ERRSTAT_FIXEDOVERFLOW    (0x4UL)     /*!< ERRSTAT FIXDOVERFLOW bit */
#define EMATH_ERRSTAT_UNDERFLOW        (0x8UL)     /*!< ERRSTAT UNDERFLOW bit */
#define EMATH_ERRSTAT_BUSERROR         (0x10UL)    /*!< ERRSTAT BUSERROR bit */

/**
 * @}
 */

/** @defgroup EMATH_INTRSTAT_REGBIT EMATH INTRSTAT register bits
 * @{
 * @brief  Macro definitions about EMATH INTRSTAT register bits definition.
 */
#define EMATH_INTRSTAT_STAT    (0x1UL)    /*!< INTRSTAT intr_stat bit */

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
 * @brief    set EMATH TMPBASE, INAFORMAT, INBFORMAT, TMPFORMAT, OUTFORMAT register
 * @param    config points to structure @ref EMATH_CONFIG_STRUCTURE
 */
static void EMATH_setConfig (const EMATH_ConfigType *config);

/**
 * @brief  enable or disable EMATH corresponding interrupt
 * @param  intrType  the interrupt corresponding type
 *                    This parameter can be any value of @ref EMATH_INTREN_BIT
 * @param  state     the value of enable or disable
 *                    0 - disable
 *                    1 - enable
 */
void EMATH_setIntCmd (EMATH_IntrType intrType, uint8_t state)
{
    uint32_t mask = (1UL << intrType);

    if (state != 0u)
    {
        SET_BIT(EMATH->INTREN.WORDVAL, mask);
    }
    else
    {
        CLEAR_BIT(EMATH->INTREN.WORDVAL, mask);
    }
}

/**
 * @brief  enable or disable EMATH corresponding dma event
 * @param  intrType  the dma even corresponding type
 *                    This parameter can be any value of @ref EMATH_DMAEN_BIT
 * @param  state     the value of enable or disable
 *                    0 - disable
 *                    1 - enable
 */
void EMATH_setDmaCmd (EMATH_DmaType dmaType, uint8_t state)
{
    uint32_t mask = (1UL << dmaType);

    if (state != 0u)
    {
        SET_BIT(EMATH->DMAEN.WORDVAL, mask);
    }
    else
    {
        CLEAR_BIT(EMATH->DMAEN.WORDVAL, mask);
    }
}

/**
 * @brief  set format of EMATH calculation
 * @param  engine   EMATH calc engine type
 *                  This parameter can be any value of @ref EMATH_ENGINE
 * @param  format   EMATH clac number type
 *                  This parameter can be any value of @ref EMATH_FORMAT
 * @param  aScale   input A prescale value
 *                  When calc fft, input number buffer length is 512=2^9, aScale set 9
 * @param  outScale output prescale value
 *                  The parameter's range is [0, INF)
 */
void EMATH_setFormat (EMATH_EngineType engine, EMATH_FormatType format, int8_t aScale, int8_t outScale)
{
    EMATH_ConfigType config;

    if (EMATH_32Bit == format)
    {
        config.inAFormat   = EMATH_32Bit;
        config.inBFormat   = EMATH_32Bit;
        config.outFormat   = EMATH_32Bit;
        config.tmpFormat   = EMATH_Float;
    }
    else if (EMATH_16Bit == format)
    {
        config.inAFormat   = EMATH_16Bit;
        config.inBFormat   = EMATH_16Bit;
        config.outFormat   = EMATH_16Bit;
        config.tmpFormat   = EMATH_Float;
    }
    else
    {
        config.inAFormat   = EMATH_Float;
        config.inBFormat   = EMATH_Float;
        config.outFormat   = EMATH_Float;
        config.tmpFormat   = EMATH_Float;
    }

    if (EMATH_CP_FFT == engine)
    {
        config.machineFormat = EMATH_32Bit;
    }
    else
    {
        config.machineFormat = EMATH_Float;
    }

    config.inAPrescale = aScale;
    config.inBPrescale = 0;
    config.outPrescale = outScale;
    config.tmpPrescale = 0;
    config.tmpBaseAddr = 0xE0000000U;

    EMATH_setConfig(&config);
}

/**
 * @brief    set EMATH TMPBASE, INAFORMAT, INBFORMAT, TMPFORMAT, OUTFORMAT register
 * @param    config points to structure @ref EMATH_CONFIG_STRUCTURE
 */
static void EMATH_setConfig (const EMATH_ConfigType *config)
{
    uint32_t format;

    WRITE_REG(EMATH->TMPBASE.WORDVAL, config->tmpBaseAddr);

    format = EMATH_MAKE_FORMAT(config->inAPrescale, config->inAFormat, config->machineFormat);
    WRITE_REG(EMATH->INAFORMAT.WORDVAL, format);

    format = EMATH_MAKE_FORMAT(config->inBPrescale, config->inBFormat, config->machineFormat);
    WRITE_REG(EMATH->INBFORMAT.WORDVAL, format);

    format = EMATH_MAKE_FORMAT(config->tmpPrescale, config->tmpFormat, config->machineFormat);
    WRITE_REG(EMATH->TMPFORMAT.WORDVAL, format);

    format = EMATH_MAKE_FORMAT(config->outPrescale, config->outFormat, config->machineFormat);
    WRITE_REG(EMATH->OUTFORMAT.WORDVAL, format);
}
