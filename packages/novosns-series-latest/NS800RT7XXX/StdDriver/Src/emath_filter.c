/**
  * @file       emath_filter.c
  * @author     yangjun
  * @brief      Function file for NS800RT7xxx emath-filter module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "emath.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup EMATH_TRANSFORM INTERNAL_USED_TYPES EMATH Internal Used Types
  * @{
  * @brief  Macro definitions are used with only this file private about 'EMATH transform' module.
  */

/** @defgroup EMATH_TRANSFORM_DECODE_MACHINE EMATH transform Internal Used Types
  * @{
  * @brief  Macro definitions are used in EMATH transform module.
  */
#define CP_FIR    (3UL << 4UL)    /*!< Decode machine: fir */

/**
  * @}
  */

/** @defgroup EMATH_MCR_OPC EMATH mcr opc for biquad
  * @{
  * @brief  Macro definitions are used 'EMATH' CP_CTRL register opc1 config for biquad.
  */
#define BIQUAD_OPCODE    (1UL << 2UL)    /* opc1 for biquad */

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
 * @brief  FIR filter
 * @param  pAData    points to the coefficient buffer of A
 * @param  ALength   coefficient buffer size of A
 *                    This param's range is [1, 65535]
 * @param  pBData    points to the coefficient buffer of B
 * @param  BLength   coefficient buffer size of B
 *                    This param's range is [1, 65535]
 * @param  pResult   points to the result data buffer
 * @param  opType    fir decode machine type
 *                    This parameter can be any value of @ref EMATH_FIR_DECODE_OPCODE
 */
void EMATH_configFir (const void *pAData, uint32_t ALength,    \
                      const void *pBData, uint32_t BLength,    \
                      void *pResult, uint32_t opType)
{
    WRITE_REG(EMATH->INABASE.WORDVAL, (uint32_t)(const uint32_t *)pAData);
    WRITE_REG(EMATH->INBBASE.WORDVAL, (uint32_t)(const uint32_t *)pBData);
    WRITE_REG(EMATH->LENGTH.WORDVAL, ((uint32_t)BLength << 16U) + (uint32_t)ALength);
    WRITE_REG(EMATH->OUTBASE.WORDVAL, (uint32_t)(uint32_t *)pResult);

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL1.WORDVAL, (CP_FIR | opType));
}

/**
 * @brief  increase FIR filter
 * @param  pSrc      points to the coefficient buffer of Src
 * @param  srcLen    coefficient buffer size of Src
 *                    This param's range is [1, 65535]
 * @param  pTap      points to the coefficient buffer of Tap
 * @param  tapLen    coefficient buffer size of Tap
 *                    This param's range is [1, 65535]
 * @param  pDst      points to the result data buffer
 * @param  offset    points to the input data buffer
 * @param  elemSize  points to the input data buffer
 */
void EMATH_incrementFir (const void *pSrc, uint32_t srcLen,    \
                         const void *pTap, uint16_t tapLen,    \
                         void *pDst, uint32_t offset, uint32_t elemSize)
{
    WRITE_REG(EMATH->INABASE.WORDVAL, ((uint32_t)(const uint32_t *)pSrc) - (offset * elemSize));
    WRITE_REG(EMATH->INBBASE.WORDVAL, (uint32_t)(const uint32_t *)pTap);
    WRITE_REG(EMATH->LENGTH.WORDVAL, (((uint32_t)tapLen & 0xFFFFUL) << 16U) + (srcLen & 0xFFFFUL));
    WRITE_REG(EMATH->OUTBASE.WORDVAL, ((uint32_t)(uint32_t *)pDst) - (offset * elemSize));
    WRITE_REG(EMATH->MISC.WORDVAL, offset);

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL1.WORDVAL, (CP_FIR | EMATH_FIR_INCREMENTAL));
}

/**
 * @brief   init EMATH fir q15
 * @param   s        pointer of EMATH_fir_instance_q15
 * @param   numTaps  the length of FIR filter coefficient
 *                    This param's range is [1, 65535]
 * @param   pCoeffs  buffer of pcoeffs pointer(taps)
 * @param   pState   pState buffer, the temp buffer for fir calc
 *                    This param's length is numTaps + blockSize -1
 */
void EMATH_initFirQ15 (EMATH_FirInstanceQ15 *s, uint16_t numTaps,    \
                       const int16_t *pCoeffs, int16_t *pState)
{
    /**
     * CMSIS DSP API filter coefficients stored in time reversed order, but EMATH
     * uses the positive order. EMATH does not use pState, so pState pState[1:numTaps]
     * is used here to save the coefficients in positive order. At the same time,
     * pState[0] is used to save the offset used for incremetal calculation.
     * Because the length of pState is (numTaps + blockSize -1), to ensure enough space,
     * the blockSize should be larger than 1.
     */

    s->numTaps = numTaps;
    s->pCoeffs = pCoeffs;
    s->pState  = pState;

    for (uint32_t i = 0U; i < numTaps; i++)
    {
        pState[numTaps + 1U - i] = pCoeffs[i];
    }

    pState[0] = 0;

    EMATH_setFormat(EMATH_CP_FIR, EMATH_16Bit, 0, -15);
}

/**
 * @brief   EMATH fir q15
 * @param   s          pointer of arm_fir_instance_q15
 * @param   pSrc       pointer of source data
 * @param   pDst       pointer of result data
 * @param   blockSize  source data length
 *                      This param's range is [1, 65535]
 */
void EMATH_firQ15 (const EMATH_FirInstanceQ15 *s, const int16_t *pSrc,    \
                   int16_t *pDst, uint32_t blockSize)
{
    uint32_t curOffset = *(uint32_t *)(void *)(s->pState);

    if (curOffset == 0U)
    {
        EMATH_configFir((void *)EDMA_getAbsAddrForMultiCore((uint32_t)pSrc), blockSize,
                        (void *)EDMA_getAbsAddrForMultiCore((uint32_t)&(s->pState[2])), s->numTaps,
                        (void *)EDMA_getAbsAddrForMultiCore((uint32_t)pDst), EMATH_FIR_FIR);
    }
    else
    {
        EMATH_incrementFir((void *)EDMA_getAbsAddrForMultiCore((uint32_t)pSrc), blockSize,
                           (void *)EDMA_getAbsAddrForMultiCore((uint32_t)&(s->pState[2])), s->numTaps,
                           (void *)EDMA_getAbsAddrForMultiCore((uint32_t)pDst), curOffset, sizeof(*pSrc));
    }

    *(uint32_t *)(void *)(s->pState) = curOffset + blockSize;

    EMATH_waitDone();
}

/**
 * @brief   init EMATH fir q31
 * @param   s        pointer of EMATH_fir_instance_q31
 * @param   numTaps  the length of FIR filter coefficient
 *                    This param's range is [1, 65535]
 * @param   pCoeffs  buffer of pcoeffs pointer(taps)
 * @param   pState   pState buffer, the temp buffer for fir calc
 *                    This param's length is numTaps + blockSize -1
 */
void EMATH_initFirQ27 (EMATH_FirInstanceQ27 *s, uint16_t numTaps,    \
                       const int32_t *pCoeffs, int32_t *pState)
{
    /**
     * CMSIS DSP API filter coefficients stored in time reversed order, but EMATH
     * uses the positive order. EMATH does not use pState, so pState pState[1:numTaps]
     * is used here to save the coefficients in positive order. At the same time,
     * pState[0] is used to save the offset used for incremetal calculation.
     * Because the length of pState is (numTaps + blockSize -1), to ensure enough space,
     * the blockSize should be larger than 1.
     */

    s->numTaps = numTaps;
    s->pCoeffs = pCoeffs;
    s->pState  = pState;

    for (uint32_t i = 0U; i < numTaps; i++)
    {
        pState[numTaps - i] = pCoeffs[i];
    }

    pState[0] = 0;

    EMATH_setFormat(EMATH_CP_FIR, EMATH_32Bit, 0, -31);
}

/**
 * @brief   EMATH fir q31
 * @param   s          pointer of arm_fir_instance_q31
 * @param   pSrc       pointer of source data
 * @param   pDst       pointer of result data
 * @param   blockSize  source data length
 *                      This param's range is [1, 65535]
 */
void EMATH_firQ27 (const EMATH_FirInstanceQ27 *s, const int32_t *pSrc,    \
                   int32_t *pDst, uint32_t blockSize)
{
    uint32_t curOffset = *(uint32_t *)(void *)(s->pState);

    if (curOffset == 0U)
    {
        EMATH_configFir((void *)EDMA_getAbsAddrForMultiCore((uint32_t)pSrc), blockSize,
                        (void *)EDMA_getAbsAddrForMultiCore((uint32_t)&(s->pState[1])), s->numTaps,
                        (void *)EDMA_getAbsAddrForMultiCore((uint32_t)pDst), EMATH_FIR_FIR);
    }
    else
    {
        EMATH_incrementFir((void *)EDMA_getAbsAddrForMultiCore((uint32_t)pSrc), blockSize,
                           (void *)EDMA_getAbsAddrForMultiCore((uint32_t)&(s->pState[1])), s->numTaps,
                           (void *)EDMA_getAbsAddrForMultiCore((uint32_t)pDst), curOffset, sizeof(*pSrc));
    }

    *(uint32_t *)(void *)(s->pState) = curOffset + blockSize;

    EMATH_waitDone();
}

/**
 * @brief            init EMATH fir f32
 * @param   s        pointer of EMATH_fir_instance_f32
 * @param   numTaps  the length of FIR filter coefficient
 *                    This param's range is [1, 65535]
 * @param   pCoeffs  buffer of pcoeffs pointer(taps)
 * @param   pState   pState buffer, the temp buffer for fir calc
 *                    This param's length is numTaps + blockSize -1
 */
void EMATH_initFirF32 (EMATH_FirInstanceF32 *s, uint16_t numTaps,    \
                       const float32_t *pCoeffs, float32_t *pState)
{
    /**
     * CMSIS DSP API filter coefficients stored in time reversed order, but EMATH
     * uses the positive order. EMATH does not use pState, so pState pState[1:numTaps]
     * is used here to save the coefficients in positive order. At the same time,
     * pState[0] is used to save the offset used for incremetal calculation.
     * Because the length of pState is (numTaps + blockSize -1), to ensure enough space,
     * the blockSize should be larger than 1.
     */

    s->numTaps = numTaps;
    s->pCoeffs = pCoeffs;
    s->pState  = pState;

    for (uint32_t i = 0U; i < numTaps; i++)
    {
        pState[numTaps - i] = pCoeffs[i];
    }

    pState[0] = 0;

    EMATH_setFormat(EMATH_CP_FIR, EMATH_Float, 0, 0);
}

/**
 * @brief   EMATH fir f32
 * @param   s          pointer of arm_fir_instance_f32
 * @param   pSrc       pointer of source data
 * @param   pDst       pointer of result data
 * @param   blockSize  source data length
 *                      This param's range is [1, 65535]
 */
void EMATH_firF32 (const EMATH_FirInstanceF32 *s, const float32_t *pSrc,    \
                   float32_t *pDst, uint32_t blockSize)
{
    uint32_t curOffset = *(uint32_t *)(void *)(s->pState);

    if (curOffset == 0U)
    {
        EMATH_configFir((void *)EDMA_getAbsAddrForMultiCore((uint32_t)pSrc), blockSize,
                        (void *)EDMA_getAbsAddrForMultiCore((uint32_t)&(s->pState[1])), s->numTaps,
                        (void *)EDMA_getAbsAddrForMultiCore((uint32_t)pDst), EMATH_FIR_FIR);
    }
    else
    {
        EMATH_incrementFir((void *)EDMA_getAbsAddrForMultiCore((uint32_t)pSrc), blockSize,
                           (void *)EDMA_getAbsAddrForMultiCore((uint32_t)&(s->pState[1])), s->numTaps,
                           (void *)EDMA_getAbsAddrForMultiCore((uint32_t)pDst), curOffset, sizeof(*pSrc));
    }

    *(uint32_t *)(void *)(s->pState) = curOffset + blockSize;

    EMATH_waitDone();
}

/**
 * @brief   EMATH direct II Biquad IIR f32
 * @param   biquadNum  biquad num
 *                      - 0: biquad0
 *                      - 1: biquad1
 * @param   pSrc       pointer of source data
 * @param   pDst       pointer of result data
 * @param   length     source data length
 *                      This param's range is [1, 2^32]
 */
void EMATH_df2BiquadIirF32 (uint8_t biquadNum, float32_t *pSrc, float32_t *pDst, uint32_t length)
{
    uint32_t tmp;
    uint32_t ctrl = (MRC_DATAFP_CMP0 | MCR_DATAFP_CMP0 | READADD | CTRL2_START | BIQUAD_OPCODE | EMATH_BIQUAD);

    if (1U == biquadNum)
    {
        ctrl = (MRC_DATAFP_CMP1 | MCR_DATAFP_CMP1 | READADD | CTRL2_START | BIQUAD_OPCODE | EMATH_BIQUAD);
    }

    for (uint32_t i = 0u; i < length; i++)
    {
        tmp = *((uint32_t *)&(pSrc[i]));
        WRITE_REG(EMATH->WDATA0.WORDVAL, tmp);

        __asm volatile("" ::: "memory");

        WRITE_REG(EMATH->CTRL2.WORDVAL, ctrl);

        while ((EMATH->STAT.WORDVAL & 1u) == 0u);

        __asm volatile("" ::: "memory");

        SET_BIT(EMATH->CTRL2.WORDVAL, CTRL2_LOAD);

        __asm volatile("" ::: "memory");

        pDst[i] = *((float32_t *)&(EMATH->RDATA0.WORDVAL));
    }
}

/**
 * @brief   Restore biquad state
 * @param   biquadNum  biquad num
 *                      - 0: biquad0
 *                      - 1: biquad1
 * @param   state      pointer of state
 */
void EMATH_restoreBiquadState (uint8_t biquadNum, EMATH_BiquadState *state)
{
    if (0U == biquadNum)
    {
        EMATH->GPREGSX[0].WORDVAL   = *((uint32_t *)&(state->param.vn1));
        EMATH->GPREGSX[1].WORDVAL   = *((uint32_t *)&(state->param.vn));
        EMATH->GPREGSX[2].WORDVAL   = *((uint32_t *)&(state->param.a1));
        EMATH->GPREGSX[3].WORDVAL   = *((uint32_t *)&(state->param.a2));
        EMATH->GPREGSX[4].WORDVAL   = *((uint32_t *)&(state->param.b0));
        EMATH->GPREGSX[5].WORDVAL   = *((uint32_t *)&(state->param.b1));
        EMATH->GPREGSX[6].WORDVAL   = *((uint32_t *)&(state->param.b2));
        EMATH->COMPREGSX[1].WORDVAL = state->compreg;
    }
    else
    {
        EMATH->GPREGSX[8].WORDVAL   = *((uint32_t *)&(state->param.vn1));
        EMATH->GPREGSX[9].WORDVAL   = *((uint32_t *)&(state->param.vn));
        EMATH->GPREGSX[10].WORDVAL  = *((uint32_t *)&(state->param.a1));
        EMATH->GPREGSX[11].WORDVAL  = *((uint32_t *)&(state->param.a2));
        EMATH->GPREGSX[12].WORDVAL  = *((uint32_t *)&(state->param.b0));
        EMATH->GPREGSX[13].WORDVAL  = *((uint32_t *)&(state->param.b1));
        EMATH->GPREGSX[14].WORDVAL  = *((uint32_t *)&(state->param.b2));
        EMATH->COMPREGSX[3].WORDVAL = state->compreg;
    }
}

/**
 * @brief   Backup biquad state
 * @param   biquadNum  biquad num
 *                      - 0: biquad0
 *                      - 1: biquad1
 * @param   state      pointer of state
 */
void EMATH_backUpBiquadState (uint8_t biquadNum, EMATH_BiquadState *state)
{
    if (0U == biquadNum)
    {
        state->param.vn1 = *((float32_t *)&(EMATH->GPREGSX[0].WORDVAL));
        state->param.vn  = *((float32_t *)&(EMATH->GPREGSX[1].WORDVAL));
        state->compreg   = EMATH->COMPREGSX[1].WORDVAL;
    }
    else
    {
        state->param.vn1 = *((float32_t *)&(EMATH->GPREGSX[8].WORDVAL));
        state->param.vn  = *((float32_t *)&(EMATH->GPREGSX[9].WORDVAL));
        state->compreg   = EMATH->COMPREGSX[3].WORDVAL;
    }
}
