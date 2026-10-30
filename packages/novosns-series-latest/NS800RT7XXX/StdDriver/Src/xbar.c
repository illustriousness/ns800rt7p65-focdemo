/**
  * @file       XBAR.c
  * @author     wuxiao
  * @brief      Function file for NS800RT7xxx xbar module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "xbar.h"


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
  * @brief Configures output mux settings in XBAR module
  * @note Uses optimized bit manipulation for minimum cycle count
  * @param xbar X-BAR pointer to a XBAR_TypeDef structure
  *         - XBAR: X-BAR base address index
  * @param output Output number selector
  *         - This parameter can be any value of @ref XBAR_OUTPUTNUM
  * @param muxConfig Configuration value with shift and mux data
  *         - This parameter can be any value of @ref XBAR_OUTPUTMUXCONFIG
  */
void XBAR_setOutputMuxConfig (XBAR_TypeDef *xbar, XBAR_OutputNum output, XBAR_OutputMuxConfig muxConfig)
{
    const uint32_t u32Config = (uint32_t)muxConfig;
    /* Bit position (0-31) */
    const uint32_t shift = (u32Config >> 8U) & 0x1FU;
    /* Aux output flag */
    const uint32_t isAuxOutput = output & 0x100U;
    volatile uint32_t *regAddr;
    /* Calculate register offset */ 
    uint32_t offset;
    if (!isAuxOutput) 
    {
        /* Standard outputs (0-255)*/ 
        const uint32_t muxFlags = u32Config & 0x6000U;
        /* Determine offset base using bit patterns (more efficient than multiple if-else) */ 
        offset = (uint32_t)(output << 2U) + ((muxFlags == 0x6000U) ? 12U :
                                             (muxFlags & 0x4000U)  ? 8U  :
                                             (muxFlags & 0x2000U)  ? 4U  : 0U );
        /* Get register address */ 
        regAddr = (volatile uint32_t *)((uint8_t *)xbar->OUTPUTXMUX + XBAR_O_OUTPUT1MUX0TO15CFG + offset);
    } 
    else 
    {
        /* Auxiliary outputs (output >= 256) */ 
        offset = (uint32_t)(output & 0xFFU) * 2U + ((u32Config & 0x2000U) ? 4U : 0U);
        regAddr = (volatile uint32_t *)((uint8_t *)xbar->CLBOUTPUTXMUX + CLBXBAR_O_OUTPUT1MUX0TO15CFG + offset);
    }
    MODIFY_REG(*regAddr, (0x3U << shift), ((muxConfig & 0x3U) << shift));
}

/**
  * @brief Configures EPWM mux settings in XBAR module
  * @note  Uses optimized single-pass calculation for real-time critical applications
  * @param xbar X-BAR pointer to a XBAR_TypeDef structure
  *         - XBAR: X-BAR base address index
  * @param trip Trip number selector
  *         - This parameter can be any value of @ref XBAR_TRIPNUM
  * @param muxConfig Configuration value with shift and mux data
  *         - This parameter can be any value of @ref XBAR_EPWMMUXCONFIG
  */
void XBAR_setEPWMMuxConfig (XBAR_TypeDef *xbar, XBAR_TripNum trip, XBAR_EPWMMuxConfig muxConfig)
{
    /* Determine base address and adjust trip number */
    const uint32_t tripSel = (uint32_t)trip;
    const uint32_t base = (tripSel <= (uint32_t)XBAR_TRIPA8) ? 
                           XBARA_EPWM_CFG_REG_BASE : XBARB_EPWM_CFG_REG_BASE;
    const uint32_t adjTripSel = (tripSel <= (uint32_t)XBAR_TRIPA8) ? 
                                 tripSel * 2 : (tripSel - 32U) * 2;
    /* Calculate offset in one expression */
    const uint32_t offset = ((muxConfig & 0x6000U) == 0x6000U) ? (adjTripSel << 1U) + 12U :
                            ((muxConfig & 0x4000U) != 0U)      ? (adjTripSel << 1U) + 8U  :
                            ((muxConfig & 0x2000U) != 0U)      ? (adjTripSel << 1U) + 4U  :
                            (adjTripSel << 1U);
    /* Bit manipulation */
    const uint32_t shift = (muxConfig >> 8U) & 0x1FU;
    /* Atomic register modification with protection */
    if (base == XBARA_EPWM_CFG_REG_BASE)
    {
        MODIFY_REG(TYPE32((uint8_t *)(&xbar->EPWMAOUTXMUX) + offset), (0x3U << shift), ((muxConfig & 0x3U) << shift));
    }
    else
    {
        MODIFY_REG(TYPE32((uint8_t *)(&xbar->EPWMBOUTXMUX) + offset), (0x3U << shift), ((muxConfig & 0x3U) << shift));
    }
}

/**
  * @brief Configures CLB mux settings in XBAR module
  * @note Uses direct register access for maximum efficiency
  * @param xbar X-BAR pointer to a XBAR_TypeDef structure
  *         - XBAR: X-BAR base address index
  * @param auxSignal Auxiliary signal number
  *         - This parameter can be any value of @ref XBAR_AUXSIGNUM
  * @param muxConfig Configuration value with shift and mux data
  *         - This parameter can be any value of @ref XBAR_CLBMUXCONFIG
  */
void XBAR_setCLBMuxConfig (XBAR_TypeDef *xbar, XBAR_AuxSigNum auxSignal, XBAR_CLBMuxConfig muxConfig)
{
    /* Calculate offset in single expression */
    const uint32_t offset = ((muxConfig & 0x2000U) != 0U) ? 
                            ((uint32_t)auxSignal << 2U) + 4U : 
                            ((uint32_t)auxSignal << 2U);
    /* Bit manipulation parameters */
    const uint32_t shift = (muxConfig >> 8U) & 0x1FU;
    /* Protected register access */
    MODIFY_REG(TYPE32((uint8_t *)(&xbar->AUXSIGXMUX) + offset), (0x3U << shift), ((muxConfig & 0x3U) << shift));
}

/**
  * @brief Gets the specified input flag in the XBAR module
  * @param inputFlag Combined field containing register index and bit position
  *         - This parameter can be any value of @ref XBAR_INPUTFLAG
  * @note Uses lookup table for maximum performance
  */
bool XBAR_getInputFlagStatus (XBAR_TypeDef *xbar, XBAR_InputFlag inputFlag)
{
    /* Predefined register offset table (compile-time constant) */
    static const uint32_t flagRegOffset[16] = {
        XBAR_O_FLG1,  XBAR_O_FLG2,  XBAR_O_FLG3,  XBAR_O_FLG4,
        XBAR_O_FLG5,  XBAR_O_FLG6,  XBAR_O_FLG7,  XBAR_O_FLG8,
        XBAR_O_FLG9,  XBAR_O_FLG10, XBAR_O_FLG11, XBAR_O_FLG12,
        XBAR_O_FLG13, XBAR_O_FLG14, XBAR_O_FLG15, XBAR_O_FLG16
    };
    /* Extract register index and bit position (completed in a single bit operation) */
    const uint32_t regIndex = ((uint32_t)inputFlag & XBAR_INPUT_FLG_REG_M) >> 8U;
    const uint32_t bitPos   = (uint32_t)inputFlag & XBAR_INPUT_FLG_INPUT_M;
    /* Get the status of the X-BAR input latch. */
    return (READ_BIT(TYPE32((uint8_t *)(&xbar->INPUTXSEL) + flagRegOffset[regIndex]), (uint32_t)1UL << bitPos) != 0UL);
}

/**
  * @brief Clears the specified input flag in the XBAR module
  * @param inputFlag Combined field containing register index and bit position
  *         - This parameter can be any value of @ref XBAR_INPUTFLAG
  * @note Uses lookup table for maximum performance
  */
void XBAR_clearInputFlag (XBAR_TypeDef *xbar, XBAR_InputFlag inputFlag)
{
    /* Register clear offsets lookup table */
    static const uint32_t flagClrOffsets[16] = {
        XBAR_O_CLR1,  XBAR_O_CLR2,  XBAR_O_CLR3,  XBAR_O_CLR4,
        XBAR_O_CLR5,  XBAR_O_CLR6,  XBAR_O_CLR7,  XBAR_O_CLR8,
        XBAR_O_CLR9,  XBAR_O_CLR10, XBAR_O_CLR11, XBAR_O_CLR12,
        XBAR_O_CLR13, XBAR_O_CLR14, XBAR_O_CLR15, XBAR_O_CLR16
    };
    /* Extract parameters in one operation */
    const uint32_t regIndex = ((uint32_t)inputFlag & XBAR_INPUT_FLG_REG_M) >> 8U;
    const uint32_t bitPos = (uint32_t)inputFlag & XBAR_INPUT_FLG_INPUT_M;
    /* Atomic register write */    
    WRITE_REG(TYPE32((uint8_t *)(&xbar->INPUTXSEL) + flagClrOffsets[regIndex]), (uint32_t)(1U << bitPos));
}
