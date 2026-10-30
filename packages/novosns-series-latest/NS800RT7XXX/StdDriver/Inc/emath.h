/**
  * @file       emath.h
  * @author     yangjun
  * @brief      Header file for NS800RT7xxx emath module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __EMATH_H__
#define __EMATH_H__


#ifdef __cplusplus
extern "C" {
#endif


typedef float float32_t;


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup EMATH_EXPORTED_TYPES EMATH Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'EMATH' module.
  */

/** @defgroup EMATH_CTRL2_BIT EMATH CTRL2 group
  * @{
  * @brief  Macro definitions are used for CTRL2 bit set.
  */
#define EMATH_INV           (0UL << 2UL)              /*!< reciprocal */
#define EMATH_LN            (1UL << 2UL)              /*!< natural log */
#define EMATH_SQRT          (2UL << 2UL)              /*!< square-root */
#define EMATH_INVSQRT       (3UL << 2UL)              /*!< inverse square-root */
#define EMATH_ETOX          (4UL << 2UL)              /*!< natural exponent */
#define EMATH_ETONX         (5UL << 2UL)              /*!< natural exponent with negative parameter */
#define EMATH_DIV           (6UL << 2UL)              /*!< division */
#define EMATH_SIN           (0UL << 2UL)              /*!< trigonometric sine */
#define EMATH_COS           (1UL << 2UL)              /*!< trigonometric cosine */

#define CTRL2_START         (1UL << 6UL)              /*!< CTRL2 start operation */
#define CTRL2_LOAD          (1UL << 14UL)             /*!< CTRL2 load operation */

#define EMATH_TRANS         (0UL)                     /*!< transform */
#define EMATH_TRIG          (1UL)                     /*!< trigonometric calc */
#define EMATH_BIQUAD        (2UL)                     /*!< biquad */

#define MRC_DATAFP_CMP0     (0UL << 28UL)             /*!< LOAD_SEL float32 COMP0 */
#define MRC_DATAFIX_CMP0    (1UL << 28UL)             /*!< LOAD_SEL fixed point COMP0 */
#define MRC_DATAFP_CMP1     (2UL << 28UL)             /*!< LOAD_SEL float32 COMP1 */
#define MRC_DATAFIX_CMP1    (3UL << 28UL)             /*!< LOAD_SEL fixed point COMP1 */

#define MCR_DATAFP_CMP0     (0UL << 20UL)             /*!< COMP_SEL float32 COMP0 */
#define MCR_DATAFIX_CMP0    (1UL << 20UL)             /*!< COMP_SEL fixed point COMP0 */
#define MCR_DATAFP_CMP1     (2UL << 20UL)             /*!< COMP_SEL float32 COMP1 */
#define MCR_DATAFIX_CMP1    (3UL << 20UL)             /*!< COMP_SEL fixed point COMP1 */

#define READMULTI           (0UL << 10UL)             /*!< RSV_SEL code : readmulti */
#define READADD             (1UL << 10UL)             /*!< RSV_SEL code : readadd */

#define CORDIC              (5UL << 4UL)              /*!< Decode machine: cordic */

#define CORDIC_ITER(x)      ((uint32_t)(x) << 2UL)    /*!< Decode opcode: cordic iter */
#define CORDIC_MIU(x)       ((uint32_t)(x) << 1UL)    /*!< Decode opcode: cordic MIU */
#define CORDIC_T(x)         ((uint32_t)(x) << 0UL)    /*!< Decode opcode: cordic T */

/**
  * @}
  */

/** @defgroup EMATH_CALC factor group
  * @{
  * @brief  Macro definitions are used for conversion.
  */
#define ATAN_FACTOR      (0.00000002340668927f)    /* atan function factor : PI/0x8000000*/
#define CORDIC_FACTOR    (134217728.0f)            /* atanh function factor : 0x8000000 */

/**
  * @}
  */

/** @defgroup EMATH_CTRL1_MASK EMATH CTRL1 register mask group
  * @{
  * @brief  Macro definitions are used for CTRL1 register set.
  */
#define EMATH_CTRL1_OPCODE_MASK       (0x0000000FUL)    /*!< CTRL1 opcode MASK */
#define EMATH_CTRL1_MACHINE_MASK      (0x000000F0UL)    /*!< CTRL1 machine MASK */
#define EMATH_CTRL1_INST_BUSY_MASK    (0x80000000UL)    /*!< CTRL1 inst_busy MASK */

/**
  * @}
  */

 /** @defgroup EMATH_CP_STAT_REGBIT EMATH CP_STAT register bit group
  * @{
  * @brief  Macro definitions are used for CP_STAT register set.
  */
#define EMATH_CP_STAT_INTR    (0x2UL)    /*!< INTR_FLAG */

/**
  * @}
  */

 /** @defgroup EMATH_CURSORY_REGBIT EMATH CURSORY register bit group
  * @{
  * @brief  Macro definitions are used for CURSORY register set.
  */
#define EMATH_CURSORY_ENABLE    (0x1UL)    /*!< EMATH CURSORY register cursory enable bit */

/**
  * @}
  */

/** @defgroup EMATH_MATRIX_LENGTH EMATH Matrix length group
  * @{
  * @brief  Make the length used for matrix functions.
  */
#define EMATH_MAKE_MATRIX_LEN(mat1Row, mat1Col, mat2Col) \
    (((uint32_t)(mat1Row) << 0UL) | ((uint32_t)(mat1Col) << 8UL) | ((uint32_t)(mat2Col) << 16UL))

/**
  * @}
  */

/** @defgroup EMATH_FIR_DECODE_OPCODE EMATH FIR Decode opcode type group
  * @{
  * @brief  Macro definitions are used with 'EMATH filter' module.
  */
#define EMATH_FIR_FIR            (0UL)    /*!< FIR Decode opcode: fir */
#define EMATH_FIR_CONVOLUTION    (1UL)    /*!< FIR Decode opcode: convolution */
#define EMATH_FIR_CORRELATION    (2UL)    /*!< FIR Decode opcode: correlation */
#define EMATH_FIR_INCREMENTAL    (4UL)    /*!< FIR Decode opcode: incremental */

/**
  * @}
  */

/** @defgroup EMATH_FORMAT_BUILD EMATH config format build group
  * @{
  * @brief  make the format for EMATH config
  */
#define EMATH_MAKE_FORMAT(prescale, aFormat, mFormat) \
    (((uint32_t)(prescale) << 8UL) | ((uint32_t)(aFormat) << 4UL) | ((uint32_t)(mFormat)))

/**
 * @}
 */

/** @defgroup EMATH_INTREN_BIT EMATH interrupt enable bit group
  * @{
  * @brief  the bit mask for INTEN register.
  */
typedef enum {
    EMATH_INTR_OFLOW = 0,    /*!< Overflow error enable bit */
    EMATH_INTR_NAN,          /*!< Nan error enable bit */
    EMATH_INTR_FIXED,        /*!< Fixed overflow error enable bit */
    EMATH_INTR_UFLOW,        /*!< Underflow error enable bit */
    EMATH_INTR_BERR,         /*!< AHBM Bus error enable bit */
    EMATH_INTR_COMP = 7,     /*!< EMATH calculate complete enable bit */
} EMATH_IntrType;

/**
  * @}
  */

/** @defgroup EMATH_DMAEN_BIT EMATH DMA enable bit group
  * @{
  * @brief  the bit mask for DMAEN register.
  */
typedef enum {
    EMATH_DMA_OFLOW = 0,    /*!< Overflow error DMA request bit */
    EMATH_DMA_NAN,          /*!< Nan error DMA request bit */
    EMATH_DMA_FIXED,        /*!< Fixed overflow error DMA request bit */
    EMATH_DMA_UFLOW,        /*!< Underflow error DMA request bit */
    EMATH_DMA_BERR,         /*!< AHBM Bus error DMA request bit */
    EMATH_DMA_COMP = 7,     /*!< EMATH calculate complete DMA request bit */
} EMATH_DmaType;

/**
  * @}
  */

/** @defgroup EMATH_ENGINE EMATH engine type group
  * @{
  * @brief  Macro definitions about EMATH engine type definition.
  */
typedef enum {
    EMATH_CP_EMATH  = 0,     /*!< Math engine */
    EMATH_CP_MTX,            /*!< Matrix engine */
    EMATH_CP_FFT,            /*!< FFT engine */
    EMATH_CP_FIR,            /*!< FIR engine */
    EMATH_CP_CORDIC = 5      /*!< CORDIC engine */
} EMATH_EngineType;

/**
  * @}
  */

/** @defgroup EMATH_FORMAT EMATH format type group
  * @{
  * @brief  EMATH calc format type
  */
typedef enum {
    EMATH_16Bit = 0,    /*!< Int16 Fixed point */
    EMATH_32Bit,        /*!< Int32 Fixed point */
    EMATH_Float         /*!< Float point */
} EMATH_FormatType;

/**
  * @}
  */

/** @defgroup EMATH_DECODEMACHINE EMATH Decode machine type group
  * @{
  * @brief  EMATH Decode machine type
  */
typedef enum {
    EMATH_DECODEMACHINE_MATRIX = 1,    /*!< Matrix decode engine */
    EMATH_DECODEMACHINE_FFT,           /*!< FFT decode engine */
    EMATH_DECODEMACHINE_FIR,           /*!< FIR decode engine */
    EMATH_DECODEMACHINE_CORDIC = 5,    /*!< Cordic decode engine */
} EMATH_DecodeMachineType;

/**
  * @}
  */

/** @defgroup EMATH_CONFIG_STRUCTURE EMATH config structure group
  * @{
  * @brief  EMATH config structure
  */
typedef struct {
    EMATH_FormatType inAFormat;        /*!< Input A format */
    int8_t inAPrescale;                /*!< Input A prescale, for example 1.5 can be 1.5*2^n
                                            if you scale by 'shifting'('scaling' by a factor of n) */
    EMATH_FormatType inBFormat;        /*!< Input B format */
    int8_t inBPrescale;                /*!< Input B prescale */
    EMATH_FormatType outFormat;        /*!< Output format */
    int8_t outPrescale;                /*!< Out prescale */
    EMATH_FormatType tmpFormat;        /*!< Tmp format */
    int8_t tmpPrescale;                /*!< Tmp prescale */
    EMATH_FormatType machineFormat;    /*!< Machine format */
    uint32_t  tmpBaseAddr;             /*!< Tmp base address */
} EMATH_ConfigType;

/**
 * @}
 */

/** @defgroup EMATH_FILTER_INSTANCE_Q15 EMATH filter instance q15 group
  * @{
  * @brief Instance structure for the Q15 FIR filter.
  */
typedef struct {
        uint16_t numTaps;     /*!< number of filter coefficients in the filter. */
        int16_t  *pState;     /*!< points to the state variable array. The array is of length numTaps+blockSize-1. */
  const int16_t  *pCoeffs;    /*!< points to the coefficient array. The array is of length numTaps.*/
} EMATH_FirInstanceQ15;

/**
 * @}
 */

/** @defgroup EMATH_FILTER_INSTANCE_Q27 EMATH filter instance q27 group
  * @{
  * @brief Instance structure for the Q27 FIR filter.
  */
typedef struct {
        uint16_t numTaps;     /*!< number of filter coefficients in the filter. */
        int32_t  *pState;     /*!< points to the state variable array. The array is of length numTaps+blockSize-1. */
  const int32_t  *pCoeffs;    /*!< points to the coefficient array. The array is of length numTaps. */
} EMATH_FirInstanceQ27;

/**
 * @}
 */

/** @defgroup EMATH_FILTER_INSTANCE_F32 EMATH filter instance f32 group
  * @{
  * @brief Instance structure for the floating-point FIR filter.
  */
typedef struct {
        uint16_t  numTaps;     /*!< number of filter coefficients in the filter. */
        float32_t *pState;     /*!< points to the state variable array. The array is of length numTaps+blockSize-1. */
  const float32_t *pCoeffs;    /*!< points to the coefficient array. The array is of length numTaps. */
} EMATH_FirInstanceF32;

/**
 * @}
 */

/** @defgroup EMATH_BIQUAD_PARAM EMATH biquad param group
  * @{
  * @brief structure for the biquad parameters.
  */
typedef struct {
    float32_t vn1;    /*!< v[n-1], set to 0 when initialization. */
    float32_t vn;     /*!< v[n], set to 0 when initialization.  */
    float32_t a1;     /*!< a[1] */
    float32_t a2;     /*!< a[2] */
    float32_t b0;     /*!< b[0] */
    float32_t b1;     /*!< b[1] */
    float32_t b2;     /*!< b[2] */
} EMATH_BiquadParam;

/**
 * @}
 */

/** @defgroup EMATH_BIQUAD_STATE EMATH biquad state group
  * @{
  * @brief structure for the biquad state.
  */
typedef struct {
    EMATH_BiquadParam param;    /*!< Filter parameter. */
    uint32_t compreg;           /*!< Internal register, set to 0 when initialization. */
} EMATH_BiquadState;

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

/************************************ Math ************************************/
/**
 * \brief  Calc the trigonometric sine function for floating-point input.
 * \param  x       input value in radians
 *                  The parameter's range is (-INF, INF)
 * \return Returns the sine value: sin(x)
 *                  The return value's range is [-1, 1]
 */
static inline __attribute__((always_inline)) float32_t EMATH_sinF32 (float32_t x)
{
    uint32_t ctrl = (MRC_DATAFP_CMP0 | MCR_DATAFP_CMP0 | READADD | CTRL2_START | EMATH_SIN | EMATH_TRIG);

    WRITE_REG(EMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL2.WORDVAL, ctrl);

    __NOP();

    __asm volatile("" ::: "memory");

    SET_BIT(EMATH->CTRL2.WORDVAL, CTRL2_LOAD);

    __asm volatile("" ::: "memory");

    return *((float32_t *)&(EMATH->RDATA0.WORDVAL));
}

/**
 * \brief  Calc the trigonometric cosine function for floating-point input.
 * \param  x       input value in radians
 *                  The parameter's range is (-INF, INF)
 * \return Returns the cosine value: cos(x)
 *                  The return value's range is [-1, 1]
 */
static inline __attribute__((always_inline)) float32_t EMATH_cosF32 (float32_t x)
{
    uint32_t ctrl = (MRC_DATAFP_CMP0 | MCR_DATAFP_CMP0 | READADD | CTRL2_START | EMATH_COS | EMATH_TRIG);

    WRITE_REG(EMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL2.WORDVAL, ctrl);

    __NOP();

    __asm volatile("" ::: "memory");

    SET_BIT(EMATH->CTRL2.WORDVAL, CTRL2_LOAD);

    __asm volatile("" ::: "memory");

    return *((float32_t *)&(EMATH->RDATA0.WORDVAL));
}

/**
 * \brief  Calc the trigonometric sine & cosine value at the same time for floating-point input.
 * \param  x       input value in radians
 *                  The parameter's range is (-INF, INF)
 * \param  pSinVal point to sine value
 *                  The parameter's range is [-1, 1]
 * \param  pCosVal point to cosine value
 *                  The parameter's range is [-1, 1]
 */
static inline __attribute__((always_inline)) void EMATH_sincosF32 (float32_t x, float32_t *pSinVal, float32_t *pCosVal)
{
    uint32_t ctrl = (MRC_DATAFP_CMP0 | MCR_DATAFP_CMP0 | READADD | CTRL2_START | EMATH_SIN | EMATH_TRIG);

    WRITE_REG(EMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL2.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    ctrl = (MRC_DATAFP_CMP1 | MCR_DATAFP_CMP1 | READADD | CTRL2_START | EMATH_COS | EMATH_TRIG);
    WRITE_REG(EMATH->CTRL2.WORDVAL, ctrl);

    __NOP();

    __asm volatile("" ::: "memory");

    SET_BIT(EMATH->CTRL2.WORDVAL, CTRL2_LOAD);

    __asm volatile("" ::: "memory");

    *pSinVal = *((float32_t *)&(EMATH->RDATA1.WORDVAL));
    *pCosVal = *((float32_t *)&(EMATH->RDATA0.WORDVAL));
}

/**
 * \brief  Calc the trigonometric sine function for Fix-point input.
 * \param  x       input value in radians
 *                  The parameter's range is [-32768, 32767] stand for [-pi, pi]
 * \return Returns the sine value: sin(x)
 *                  The return value's range is [-32768, 32767]
 */
static inline __attribute__((always_inline)) int16_t EMATH_sinQ15 (int16_t degree)
{
    int32_t real;
    int16_t res;

    if(degree >= 16384)
    {
        real = 32767 - degree;
    }
    else if(degree < -16384)
    {
        real = -32768 - degree;
    }
    else
    {
        real = degree;
    }

    real = real << 12;

    WRITE_REG(EMATH->CORDICX.WORDVAL, (uint32_t)19896U);
    WRITE_REG(EMATH->CORDICY.WORDVAL, (uint32_t)0u);
    WRITE_REG(EMATH->CORDICZ.WORDVAL, (uint32_t)real);

    __asm volatile("" ::: "memory");

    /* default iterate 24 times, user can change iterate times to 1,0(stand for 16 times, 8 times) */
    WRITE_REG(EMATH->CTRL1.WORDVAL, (CORDIC | CORDIC_ITER(2) | CORDIC_MIU(0) | CORDIC_T(0)));

    __NOP();

    __asm volatile("" ::: "memory");

    res = (int16_t)READ_REG(EMATH->CORDICY.WORDVAL);

    return res;
}

/**
 * \brief  Calc the trigonometric cosine function for Fix-point input.
 * \param  x       input value in radians
 *                  The parameter's range is [-32768, 32767] stand for [-pi, pi]
 * \return Returns the sine value: cos(x)
 *                  The return value's range is [-32768, 32767]
 */
static inline __attribute__((always_inline)) int16_t EMATH_cosQ15 (int16_t degree)
{
    int32_t real;
    int16_t res;

    if(degree < 0)
    {
        real = degree + 16384;
    }
    else
    {
        real = 16384 - degree;
    }

    real = real << 12;

    WRITE_REG(EMATH->CORDICX.WORDVAL, (uint32_t)19896U);
    WRITE_REG(EMATH->CORDICY.WORDVAL, (uint32_t)0u);
    WRITE_REG(EMATH->CORDICZ.WORDVAL, (uint32_t)real);

    __asm volatile("" ::: "memory");

    /* default iterate 24 times, user can change iterate times to 1,0(stand for 16 times, 8 times) */
    WRITE_REG(EMATH->CTRL1.WORDVAL, (CORDIC | CORDIC_ITER(2) | CORDIC_MIU(0) | CORDIC_T(0)));

    __NOP();

    __asm volatile("" ::: "memory");

    res = (int16_t)READ_REG(EMATH->CORDICY.WORDVAL);

    return res;
}

/**
 * \brief  Calc the trigonometric arc tangent value for floating-point input.
 * \note   The sum of CORDICX and CORDICY should not exceed the range of int32_t.
 * \note   Larger input number gets higher output accuracy, this func enlarge
 * \note   the input data by 0x10000 times for output accuracy.
 * \param  y       floating point Y-axis input,
 *                  The parameter's range is [-16384.0, 16384.0]
 * \param  x       floating point X-axis input
 *                  The parameter's range is [-16384.0, 16384.0]
 * \return Returns the arc tangent value: atanf(y, x)
 *                  The return value's range is [-PI/2, PI/2]
 */
static inline __attribute__((always_inline)) float32_t EMATH_atanF32 (float32_t y, float32_t x)
{
    int32_t arctan_result;
    int32_t intY = (int32_t)(y * 0x10000);
    int32_t intX = (int32_t)(x * 0x10000);

    WRITE_REG(EMATH->CORDICX.WORDVAL, (uint32_t)intX);
    WRITE_REG(EMATH->CORDICY.WORDVAL, (uint32_t)intY);
    WRITE_REG(EMATH->CORDICZ.WORDVAL, (uint32_t)0);

    __asm volatile("" ::: "memory");

    /* default iterate 24 times, user can change iterate times to 1,0(stand for 16 times, 8 times) */
    WRITE_REG(EMATH->CTRL1.WORDVAL, (CORDIC | CORDIC_ITER(2) | CORDIC_MIU(0) | CORDIC_T(1)));

    __NOP();

    __asm volatile("" ::: "memory");

    arctan_result = READ_REG(EMATH->CORDICZ.WORDVAL);

    return (float32_t)(arctan_result * ATAN_FACTOR);
}

/**
 * \brief  Calc the trigonometric arc tangent function for floating-point input.
 * \note   The sum of CORDICX and CORDICY should not exceed the range of int32_t.
 * \note   Larger input number gets higher output accuracy, this func enlarge
 * \note   the input data by 0x10000 times for output accuracy.
 * \param  y       floating point Y-axis input
 *                  The parameter's range is [-16384.0, 16384.0]
 * \param  x       floating point X-axis input
 *                  The parameter's range is [-16384.0, 16384.0]
 * \return Returns the arc tangent value: atan2f(y, x)
 *                  The return value's range is [-PI, PI]
 */
static inline __attribute__((always_inline)) float32_t EMATH_atan2F32 (float32_t y, float32_t x)
{
    int32_t result;
    int32_t intY = (int32_t)(y * 0x10000);
    int32_t intX = (int32_t)(x * 0x10000);

    WRITE_REG(EMATH->CORDICX.WORDVAL, (uint32_t)intX);
    WRITE_REG(EMATH->CORDICY.WORDVAL, (uint32_t)intY);
    WRITE_REG(EMATH->CORDICZ.WORDVAL, (uint32_t)0);

    __asm volatile("" ::: "memory");

    /* default iterate 24 times, user can change iterate times to 1,0(stand for 16 times, 8 times) */
    WRITE_REG(EMATH->CTRL1.WORDVAL, (CORDIC | CORDIC_ITER(2) | CORDIC_MIU(0) | CORDIC_T(1)));

    __NOP();

    __asm volatile("" ::: "memory");

    result = READ_REG(EMATH->CORDICZ.WORDVAL);

    if (intX < 0)
    {
        if (intY < 0)
        {
            result -= 0x08000000;
        }
        else
        {
            result += 0x08000000;
        }
    }

    return (float32_t)(result * ATAN_FACTOR);
}

/**
 * \brief  Calc the trigonometric arc tangent value for fix-point input.
 * \param  y       fix point Y-axis input
 *                  The parameter's range is [-0x7FFFFFF, 0x7FFFFFF]
 * \param  x       fix point X-axis input
 *                  The parameter's range is [-0x7FFFFFF, 0x7FFFFFF]
 * \return Returns arc tangent value: atan(y, x)
 *                  The return value's range is [-0x4000000, 0x3FFFFFF] stand for [-PI/2, PI/2]
 */
static inline __attribute__((always_inline)) int32_t EMATH_atanQ27 (int32_t y, int32_t x)
{
    int32_t result;

    WRITE_REG(EMATH->CORDICX.WORDVAL, (uint32_t)x);
    WRITE_REG(EMATH->CORDICY.WORDVAL, (uint32_t)y);
    WRITE_REG(EMATH->CORDICZ.WORDVAL, (uint32_t)0);

    __asm volatile("" ::: "memory");

    /* default iterate 24 times, user can change iterate times to 1,0(stand for 16 times, 8 times) */
    WRITE_REG(EMATH->CTRL1.WORDVAL, (CORDIC | CORDIC_ITER(2) | CORDIC_MIU(0) | CORDIC_T(1)));

    __NOP();

    __asm volatile("" ::: "memory");

    result = READ_REG(EMATH->CORDICZ.WORDVAL);

    return result;
}

/**
 * \brief  Calc the trigonometric arc tangent value for fix-point input.
 * \param  y       fix point Y-axis input
 *                  The parameter's range is [-0x7FFFFFF, 0x7FFFFFF]
 * \param  x       fix point X-axis input
 *                  The parameter's range is [-0x7FFFFFF, 0x7FFFFFF]
 * \return Returns arc tangent value: atan2(y, x)
 *                  The return value's range is [-0x8000000, 0x7FFFFFF] stand for [-PI, PI]
 */
static inline __attribute__((always_inline)) int32_t EMATH_atan2Q27 (int32_t y, int32_t x)
{
    int32_t result;

    WRITE_REG(EMATH->CORDICX.WORDVAL, (uint32_t)x);
    WRITE_REG(EMATH->CORDICY.WORDVAL, (uint32_t)y);
    WRITE_REG(EMATH->CORDICZ.WORDVAL, (uint32_t)0);

    __asm volatile("" ::: "memory");

    /* default iterate 24 times, user can change iterate times to 1,0(stand for 16 times, 8 times) */
    WRITE_REG(EMATH->CTRL1.WORDVAL, (CORDIC | CORDIC_ITER(2) | CORDIC_MIU(0) | CORDIC_T(1)));

    __NOP();

    __asm volatile("" ::: "memory");

    result = READ_REG(EMATH->CORDICZ.WORDVAL);

    if (x < 0)
    {
        if (y < 0)
        {
            result -= 0x08000000;
        }
        else
        {
            result += 0x08000000;
        }
    }

    return result;
}

/**
 * \brief  Calc the trigonometric arc tangent value for fix-point input.
 * \param  y       fix point Y-axis input
 *                  The parameter's range is [-0x7FFF, 0x7FFF]
 * \param  x       fix point X-axis input
 *                  The parameter's range is [-0x7FFF, 0x7FFF]
 * \return Returns arc tangent value: atan(y, x)
 *                  The return value's range is[-0x4000, 0x3FFF] stand for [-PI/2, PI/2]
 */
static inline __attribute__((always_inline)) int16_t EMATH_atanQ15 (int16_t y, int16_t x)
{
    int32_t result;

    WRITE_REG(EMATH->CORDICX.WORDVAL, (uint32_t)x);
    WRITE_REG(EMATH->CORDICY.WORDVAL, (uint32_t)y);
    WRITE_REG(EMATH->CORDICZ.WORDVAL, (uint32_t)0);

    __asm volatile("" ::: "memory");

    /* default iterate 24 times, user can change iterate times to 1,0(stand for 16 times, 8 times) */
    WRITE_REG(EMATH->CTRL1.WORDVAL, (CORDIC | CORDIC_ITER(2) | CORDIC_MIU(0) | CORDIC_T(1)));

    __NOP();

    __asm volatile("" ::: "memory");

    result = READ_REG(EMATH->CORDICZ.WORDVAL) >> 12;

    return result;
}

/**
 * \brief  Calc the trigonometric arc tangent value for fix-point input.
 * \param  y       fix point Y-axis input
 *                  The parameter's range is [-0x7FFF, 0x7FFF]
 * \param  x       fix point X-axis input
 *                  The parameter's range is [-0x7FFF, 0x7FFF]
 * \return Returns arc tangent value: atan2(y, x)
 *                  The return value's range is[-0x8000, 0x7FFF] stand for [-PI, PI]
 */
static inline __attribute__((always_inline)) int16_t EMATH_atan2Q15 (int16_t y, int16_t x)
{
    int32_t result;

    WRITE_REG(EMATH->CORDICX.WORDVAL, (uint32_t)x);
    WRITE_REG(EMATH->CORDICY.WORDVAL, (uint32_t)y);
    WRITE_REG(EMATH->CORDICZ.WORDVAL, (uint32_t)0);

    __asm volatile("" ::: "memory");

    /* default iterate 24 times, user can change iterate times to 1,0(stand for 16 times, 8 times) */
    WRITE_REG(EMATH->CTRL1.WORDVAL, (CORDIC | CORDIC_ITER(2) | CORDIC_MIU(0) | CORDIC_T(1)));

    __NOP();

    __asm volatile("" ::: "memory");

    result = READ_REG(EMATH->CORDICZ.WORDVAL) >> 12;

    if (x < 0)
    {
        if (y > 0)
        {
            result += 0x7FFF;
        }
        else
        {
            result -= 0x7FFF;
        }
    }

    return (int16_t)result;
}

/**
 * \brief  Calc the squre root value for floating-point input.
 * \param  x       floating-point data
 *                  The parameter's range is [0, INF)
 * \return Returns squre root value: sqrt(x)
 *                  The return value's range is [0, INF)
 */
static inline __attribute__((always_inline)) float32_t EMATH_sqrtF32 (float32_t x)
{
    uint32_t ctrl = (MRC_DATAFP_CMP0 | MCR_DATAFP_CMP0 | READMULTI | CTRL2_START | EMATH_SQRT | EMATH_TRANS);

    WRITE_REG(EMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL2.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    __NOP();

    SET_BIT(EMATH->CTRL2.WORDVAL, CTRL2_LOAD);

    __asm volatile("" ::: "memory");

    return *((float32_t *)&(EMATH->RDATA0.WORDVAL));
}

/**
 * \brief  Calc the square root for fix-point input.
 * \param  x       fix-point data
 *                  The parameter's range is [0, 0x7FFFFFFF]
 * \return Returns square root value: sqrt(x), fix-point data
 *                  The return value's range is [0, 185364)
 */
static inline __attribute__((always_inline)) uint32_t EMATH_sqrtFixed (uint32_t x)
{
    uint32_t ctrl = (MRC_DATAFIX_CMP0 | MCR_DATAFIX_CMP0 | READMULTI | CTRL2_START | EMATH_SQRT | EMATH_TRANS);

    WRITE_REG(EMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL2.WORDVAL, ctrl);

    __NOP();

    __asm volatile("" ::: "memory");

    SET_BIT(EMATH->CTRL2.WORDVAL, CTRL2_LOAD);

    __asm volatile("" ::: "memory");

    return *((uint32_t *)&(EMATH->RDATA0.WORDVAL));
}

/**
 * \brief  Calc the reciprocal square root for floating-point input.
 * \param  x       floating-point data
 *                  The parameter's range is [0, INF)
 * \return Returns reciprocal square root value: 1/sqrt(x)
 *                  The return value's range is [0, INF)
 */
static inline __attribute__((always_inline)) float32_t EMATH_invSqrtF32 (float32_t x)
{
    uint32_t ctrl = (MRC_DATAFP_CMP0 | MCR_DATAFP_CMP0 | READMULTI | CTRL2_START | EMATH_INVSQRT | EMATH_TRANS);

    WRITE_REG(EMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL2.WORDVAL, ctrl);

    __NOP();

    __asm volatile("" ::: "memory");

    SET_BIT(EMATH->CTRL2.WORDVAL, CTRL2_LOAD);

    __asm volatile("" ::: "memory");

    return *((float32_t *)&(EMATH->RDATA0.WORDVAL));
}

/**
 * \brief  Calc the div value for floating-point input.
 * \param  x1      floating-point data
 *                  The parameter's range is (-INF, INF)
 * \param  x2      floating-point data
 *                  The parameter is not equal to zero
 * \return Returns div value: x1/x2
 *                  The return value's range is (-INF, INF)
 */
static inline __attribute__((always_inline)) float32_t EMATH_divF32 (float32_t x1, float32_t x2)
{
    uint32_t ctrl = (MRC_DATAFP_CMP0 | MCR_DATAFP_CMP0 | READMULTI | CTRL2_START | EMATH_DIV | EMATH_TRANS);

    WRITE_REG(EMATH->WDATA0.WORDVAL, *((uint32_t *)&(x2)));
    WRITE_REG(EMATH->WDATA1.WORDVAL, *((uint32_t *)&(x1)));

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL2.WORDVAL, ctrl);

    __NOP();

    __asm volatile("" ::: "memory");

    SET_BIT(EMATH->CTRL2.WORDVAL, CTRL2_LOAD);

    __asm volatile("" ::: "memory");

    return *((float32_t *) &(EMATH->RDATA0.WORDVAL));
}

/**
 * \brief  Calc reciprocal for floating-point input.
 * \param  x       floating-point data
 *                  The parameter is not equal to zero
 * \return Returns reciprocal value: 1/x
 *                  The return value's range is (-INF, INF)
 */
static inline __attribute__((always_inline)) float32_t EMATH_invF32 (float32_t x)
{
    uint32_t ctrl = (MRC_DATAFP_CMP0 | MCR_DATAFP_CMP0 | READMULTI | CTRL2_START | EMATH_INV | EMATH_TRANS);

    WRITE_REG(EMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL2.WORDVAL, ctrl);

    __NOP();

    __asm volatile("" ::: "memory");

    SET_BIT(EMATH->CTRL2.WORDVAL, CTRL2_LOAD);

    __asm volatile("" ::: "memory");

    return *((float32_t *)&(EMATH->RDATA0.WORDVAL));
}

/**
 * \brief  Calc natural log for floating-point input.
 * \param  x       floating-point data
 *                  The parameter's range is (0, INF)
 * \return Returns natural log value: ln(x)
 *                  The return value's range is (-INF, INF)
 */
static inline __attribute__((always_inline)) float32_t EMATH_lnF32 (float32_t x)
{
    uint32_t ctrl = (MRC_DATAFP_CMP0 | MCR_DATAFP_CMP0 | READADD | CTRL2_START | EMATH_LN | EMATH_TRANS);

    WRITE_REG(EMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL2.WORDVAL, ctrl);

    __NOP();

    __asm volatile("" ::: "memory");

    SET_BIT(EMATH->CTRL2.WORDVAL, CTRL2_LOAD);

    __asm volatile("" ::: "memory");

    return *((float32_t *)&(EMATH->RDATA0.WORDVAL));
}

/**
 * \brief  Calc the nature exponential for floating-point input.
 * \param  x       floating-point data
 *                  The parameter's range is (-INF, INF)
 * \return Returns nature exponential value: e^x
 *                  The return value's range is (0, INF)
 */
static inline __attribute__((always_inline)) float32_t EMATH_etoxF32 (float32_t x)
{
    uint32_t ctrl = (MRC_DATAFP_CMP0 | MCR_DATAFP_CMP0 | READMULTI | CTRL2_START | EMATH_ETOX | EMATH_TRANS);

    WRITE_REG(EMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL2.WORDVAL, ctrl);

    __NOP();

    __asm volatile("" ::: "memory");

    SET_BIT(EMATH->CTRL2.WORDVAL, CTRL2_LOAD);

    __asm volatile("" ::: "memory");

    return *((float32_t *)&(EMATH->RDATA0.WORDVAL));
}

/**
 * \brief  Calc the nature exponential for floating-point input.
 * \param  x       floating-point data
 *                  The parameter's range is (-INF, INF)
 * \return Returns nature exponential value: e^(-x)
 *                  The return value's range is (0, INF)
 */
static inline __attribute__((always_inline)) float32_t EMATH_etonxF32 (float32_t x)
{
    uint32_t ctrl = (MRC_DATAFP_CMP0 | MCR_DATAFP_CMP0 | READMULTI | CTRL2_START | EMATH_ETONX | EMATH_TRANS);

    WRITE_REG(EMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL2.WORDVAL, ctrl);

    __NOP();

    __asm volatile("" ::: "memory");

    SET_BIT(EMATH->CTRL2.WORDVAL, CTRL2_LOAD);

    __asm volatile("" ::: "memory");

    return *((float32_t *)&(EMATH->RDATA0.WORDVAL));
}

/*!
 * \brief Calc the inverse tanh transformation value.
 * \param x        floating-point data
 *                  The parameter's range is (-0.806, 0.806).
 * \return Returns inverse tanh transformation: atanh(x)
 *                  The return value's range is [-1.118, 1.118] radians, this function
 *                  is not accurate out of range [-1.118, 1.118]
 */
static inline __attribute__((always_inline)) float32_t EMATH_atanhF32 (float32_t x)
{
    int32_t result;

    WRITE_REG(EMATH->CORDICX.WORDVAL, (int32_t)(x*CORDIC_FACTOR));
    WRITE_REG(EMATH->CORDICY.WORDVAL, (int32_t)CORDIC_FACTOR);
    WRITE_REG(EMATH->CORDICZ.WORDVAL, 0);

    __asm volatile("" ::: "memory");

    /* default iterate 24 times, user can change iterate times to 1,0(stand for 16 times, 8 times) */
    WRITE_REG(EMATH->CTRL1.WORDVAL, (CORDIC | CORDIC_ITER(2) | CORDIC_MIU(1) | CORDIC_T(1)));
    __NOP();

    __asm volatile("" ::: "memory");

    result = READ_REG(EMATH->CORDICZ.WORDVAL);

    return (float32_t)(result / CORDIC_FACTOR);
}


/*********************************** Transform ***********************************/
/**
 * \brief  complex FFT transform
 * \param  pData     points to the complex data buffer{x0_real, x0_imaginary, x1_real, x1_imaginary...}
 * \param  length    pData buffer size
 *                    this param can only be set 16, 32, 64, 128, 256, 512, max is 512
 * \param  pResult   points to complex FFT transform result
 *                    the result buffer length should be more than length
 */
extern void EMATH_transformCFFT (void *pData, uint32_t length, void *pResult);

/**
 * \brief  real FFT transform
 * \param  pData     points to the real data buffer{x0, x1...}
 * \param  length    pData buffer size
 *                    this param can only be set 16, 32, 64, 128, 256, 512, max is 512
 * \param  pResult   points to real FFT transform result
 *                    the result buffer length should be more than 2*length
 */
extern void EMATH_transformRFFT (void *pData, uint32_t length, void *pResult);

/**
 * \brief  inverse  FFT transform
 * \param  pData     points to the real data buffer{x0, x1...}
 * \param  length    pData buffer size
 *                    this param can only be set 16, 32, 64, 128, 256, 512, max is 512
 * \param  pResult   points to inverse FFT transform result
 *                    the result buffer length should be more than length
 */
extern void EMATH_transformIFFT (void *pData, uint32_t length, void *pResult);

/**
 * \brief  complex discrete cosine transform(DCT)
 * \param  pData     points to the complex data buffer{x0, x1...}
 * \param  length    pData buffer size
 *                    this param can only be set 16, 32, 64, 128, 256, 512, max is 512
 * \param  pResult   points to discrete cosine transform result
 *                    the result buffer length should be more than length
 */
extern void EMATH_transformCDCT (void *pData, uint32_t length, void *pResult);

/**
 * \brief  real discrete cosine transform(DCT)
 * \param  pData     points to the real data buffer{x0, x1...}
 * \param  length    pData buffer size
 *                    this param can only be set 16, 32, 64, 128, 256, 512, max is 512
 * \param  pResult   points to discrete cosine transform result
 *                    the result buffer length should be more than length
 */
extern void EMATH_transformRDCT (void *pData, uint32_t length, void *pResult);

/**
 * \brief  inverse discrete cosine transform(IDCT)
 * \param  pData     points to the data buffer{x0, x1...}
 * \param  length    pData buffer size
 *                    this param can only be set 16, 32, 64, 128, 256, 512, max is 512
 * \param  pResult   inverse discrete cosine transform result
 *                    the result buffer length should be more than length
 */
extern void EMATH_transformIDCT (void *pData, uint32_t length, void *pResult);


/************************************ Filter ************************************/
/**
 * \brief  FIR filter
 * \param  pAData    points to the coefficient buffer of A
 * \param  ALength   coefficient buffer size of A
 *                    This param's range is [1, 65535]
 * \param  pBData    points to the coefficient buffer of B
 * \param  BLength   coefficient buffer size of B
 *                    This param's range is [1, 65535]
 * \param  pResult   points to the result data buffer
 * \param  opType    fir decode machine type
 *                    This parameter can be any value of @ref EMATH_FIR_DECODE_OPCODE
 */
extern void EMATH_configFir (const void *pAData, uint32_t ALength,    \
                             const void *pBData, uint32_t BLength,    \
                             void *pResult, uint32_t opType);

/**
 * \brief  increase FIR filter
 * \param  pSrc      points to the coefficient buffer of Src
 * \param  srcLen    coefficient buffer size of Src
 *                    This param's range is [1, 65535]
 * \param  pTap      points to the coefficient buffer of Tap
 * \param  tapLen    coefficient buffer size of Tap
 *                    This param's range is [1, 65535]
 * \param  pDst      points to the result data buffer
 * \param  offset    points to the input data buffer
 * \param  elemSize  points to the input data buffer
 */
extern void EMATH_incrementFir (const void *pSrc, uint32_t srcLen,    \
                                const void *pTap, uint16_t tapLen,    \
                                void *pDst, uint32_t offset, uint32_t elemSize);

/**
 * \brief            init EMATH fir q15
 * \param   s        pointer of EMATH_fir_instance_q15
 * \param   numTaps  the length of FIR filter coefficient
 *                    This param's range is [1, 65535]
 * \param   pCoeffs  buffer of pcoeffs pointer(taps)
 * \param   pState   pState buffer, the temp buffer for fir calc
 *                    This param's length is numTaps + blockSize -1
 */
extern void EMATH_initFirQ15 (EMATH_FirInstanceQ15 *s, uint16_t numTaps,    \
                      const int16_t *pCoeffs, int16_t *pState);

/**
 * \brief   EMATH fir q15
 * \param   S          pointer of arm_fir_instance_q15
 * \param   pSrc       pointer of source data
 * \param   pDst       pointer of result data
 * \param   blockSize  source data length
 *                      This param's range is [1, 65535]
 */
extern void EMATH_firQ15 (const EMATH_FirInstanceQ15 *s, const int16_t *pSrc,    \
                  int16_t *pDst, uint32_t blockSize);

/**
 * \brief            init EMATH fir q27
 * \param   s        pointer of EMATH_fir_instance_q27
 * \param   numTaps  the length of FIR filter coefficient
 *                    This param's range is [1, 65535]
 * \param   pCoeffs  buffer of pcoeffs pointer(taps)
 * \param   pState   pState buffer, the temp buffer for fir calc
 *                    This param's length is numTaps + blockSize -1
 */
extern void EMATH_initFirQ27 (EMATH_FirInstanceQ27 *s, uint16_t numTaps,    \
                   const int32_t *pCoeffs, int32_t *pState);

/**
 * \brief   EMATH fir q27
 * \param   S          pointer of arm_fir_instance_q27
 * \param   pSrc       pointer of source data
 * \param   pDst       pointer of result data
 * \param   blockSize  source data length
 *                      This param's range is [1, 65535]
 */
extern void EMATH_firQ27(const EMATH_FirInstanceQ27 *s, const int32_t *pSrc,    \
                  int32_t *pDst, uint32_t blockSize);

/**
 * \brief            init EMATH fir f32
 * \param   s        pointer of EMATH_fir_instance_f32
 * \param   numTaps  the length of FIR filter coefficient
 *                    This param's range is [1, 65535]
 * \param   pCoeffs  buffer of pcoeffs pointer(taps)
 * \param   pState   pState buffer, the temp buffer for fir calc
 *                    This param's length is numTaps + blockSize -1
 */
extern void EMATH_initFirF32 (EMATH_FirInstanceF32 *s, uint16_t numTaps,    \
                   const float32_t *pCoeffs, float32_t *pState);

/**
 * \brief   EMATH fir f32
 * \param   S          pointer of arm_fir_instance_f32
 * \param   pSrc       pointer of source data
 * \param   pDst       pointer of result data
 * \param   blockSize  source data length
 *                      This param's range is [1, 65535]
 */
extern void EMATH_firF32 (const EMATH_FirInstanceF32 *S, const float32_t *pSrc,    \
                  float32_t *pDst, uint32_t blockSize);

/**
 * \brief   EMATH direct II Biquad IIR f32
 * \param   biquadNum  biquad num
 *                     - 0: biquad0
 *                     - 1: biquad1
 * \param   pSrc       pointer of source data
 * \param   pDst       pointer of result data
 * \param   length     source data length
 *                      This param's range is [1, 2^32]
 */
extern void EMATH_df2BiquadIirF32 (uint8_t biquadNum, float32_t *pSrc,    \
                                   float32_t *pDst, uint32_t length);

/**
 * \brief   Restore biquad state
 * \param   biquadNum  biquad num
 *                     - 0: biquad0
 *                     - 1: biquad1
 * \param   state      pointer of state
 */
extern void EMATH_restoreBiquadState (uint8_t biquadNum, EMATH_BiquadState *state);

/**
 * \brief   Backup biquad state
 * \param   biquadNum  biquad num
 *                     - 0: biquad0
 *                     - 1: biquad1
 * \param   state      pointer of state
 */
extern void EMATH_backUpBiquadState (uint8_t biquadNum, EMATH_BiquadState *state);


/************************************ Matrix ************************************/
/**
 * \brief  Calculate the matrix addition of two matrices
 * \param  pAData    points to the input matrix A
 * \param  pBData    points to the input matrix B
 * \param  length    length rows and cols for matrix
 *                   length[23:16] - B rows
 *                   length[15:8]  - A cols
 *                   length[7:0]   - A rows
 * \param  pResult   points to the output matrix
 */
extern void EMATH_matrixAddition (void *pAData, void *pBData, uint32_t length, void *pResult);

/**
 * \brief  Calculate the matrix subtration of two matrices
 * \param  pAData    points to the input matrix A
 * \param  pBData    points to the input matrix B
 * \param  length    length rows and cols for matrix
 *                   length[23:16] - B rows
 *                   length[15:8]  - A cols
 *                   length[7:0]   - A rows
 * \param  pResult   points to the output matrix
 */
extern void EMATH_matrixSubtraction (void *pAData, void* pBData, uint32_t length, void *pResult);

/**
 * \brief  Calculate the matrix multiplication of two matrices
 * \param  pAData    points to the input matrix A
 * \param  pBData    points to the input matrix B
 * \param  length    length rows and cols for matrix
 *                   length[23:16] - B rows
 *                   length[15:8]  - A cols
 *                   length[7:0]   - A rows
 * \param  pResult   points to the output matrix
 */
extern void EMATH_matrixMultiplication (void *pAData, void *pBData, uint32_t length, void *pResult);

/**
 * \brief  Calculate the matrix production of two matrices
 * \param  pAData    points to the input matrix A
 * \param  pBData    points to the input matrix B
 * \param  length    length rows and cols for matrix
 *                   length[23:16] - B rows
 *                   length[15:8]  - A cols
 *                   length[7:0]   - A rows
 * \param  pResult   points to the output matrix
 */
extern void EMATH_matrixProduct (void *pAData, void *pBData, uint32_t length, void *pResult);

/**
 * \brief  Calculate the dot production of two vectors
 * \param  pAData    points to the input vector A
 * \param  pBData    points to the input vector B
 * \param  length    length rows and cols for matrix
 *                   length[23:16] - B rows
 *                   length[15:8]  - A cols
 *                   length[7:0]   - A rows
 * \param  pResult   points to the output vector
 */
extern void EMATH_vectorDotProduct (void *pAData, void *pBData, uint32_t length, void *pResult);

/**
 * \brief  Calculate matrix inversion
 * \param  pData     points to the input matrix
 * \param  pTmpData  points to the temp buffer
 * \param  length    length for matrix
 * \param  pResult   points to the output matrix
 */
extern void EMATH_matrixInversion (void *pData, void *pTmp, uint32_t length, void *pResult);

/**
 * \brief  Calculate matrix transpose
 * \param  pData     points to the input matrix
 * \param  length    length for matrix
 * \param  pResult   points to the output matrix
 */
extern void EMATH_matrixTranspose (void *pData, uint32_t length, void *pResult);

/**
 * \brief  Calculate matrix scale
 * \param  pData     points to the input matrix
 * \param  length    length for matrix
 * \param  misc      scale cofficient
 * \param  pResult   points to the output matrix
 */
extern void EMATH_matrixScale (const void *pData, uint32_t length, float misc, void *pResult);


/************************************ Basic ************************************/
/**
 * \brief  enable or disable EMATH corresponding interrupt
 * \param  intrType  the interrupt corresponding type
 *                    This parameter can be any value of @ref EMATH_INTREN_BIT
 * \param  state     the value of enable or disable
 *                    0 - disable
 *                    1 - enable
 */
extern void EMATH_setIntCmd (EMATH_IntrType intrType, uint8_t state);

/**
 * \brief  enable or disable EMATH corresponding dma event
 * \param  intrType  the dma even corresponding type
 *                    This parameter can be any value of @ref EMATH_DMAEN_BIT
 * \param  state     the value of enable or disable
 *                    0 - disable
 *                    1 - enable
 */
extern void EMATH_setDmaCmd (EMATH_DmaType dmaType, uint8_t state);

/**
 * \brief  set format of EMATH calculation
 * \param  engine   EMATH calc engine type
 *                  This parameter can be any value of @ref EMATH_ENGINE
 * \param  format   EMATH clac number type
 *                  This parameter can be any value of @ref EMATH_FORMAT
 * \param  aScale   input A prescale value
 *                  When calc fft, input number buffer length is 512=2^9, aScale set 9
 * \param  outScale output prescale value
 *                  The parameter's range is [0, INF)
 */
extern void EMATH_setFormat (EMATH_EngineType engine, EMATH_FormatType format, int8_t aScale, int8_t outScale);

/**
 * \brief  wait the EMATH busy flag disappears.
 * \note   when use EMATH calc fft and matrix, should wait emath busy flag disappears
*/
static inline void EMATH_waitDone (void)
{
    /* wait for the completion */
    while (READ_BIT(EMATH->CTRL1.WORDVAL, EMATH_CTRL1_INST_BUSY_MASK) != 0U)
    {
        ;
    }
}

/**
 * \brief  Set EMATH outbase register
 * \note   assign EMATH output address.
 * \param  outBaseAddr   ram space address
 *                        This param's range is in the sram space(include DTCM)
 */
static inline void EMATH_setOutBase (uint32_t outBaseAddr)
{
    WRITE_REG(EMATH->OUTBASE.WORDVAL, outBaseAddr);
}

/**
 * \brief  Set EMATH outformat register
 * \param  scaler      output scale value
 *                      This parameter can be any value of int8_t
 * \param  formatext   output extern format
 *                      This parameter can be any value of @ref EMATH_FORMAT
 * \param  formatint   output internal value
 *                      This parameter can be any value of @ref EMATH_FORMAT
 */
static inline void EMATH_setOutFormat (int8_t scaler, EMATH_FormatType formatext, EMATH_FormatType formatint)
{
    WRITE_REG(EMATH->OUTFORMAT.WORDVAL, (uint32_t)((scaler<<8U) | (formatext<<4U) | (formatint)));
}

/**
 * \brief  Set EMATH tmpbase register
 * \note   assign EMATH tmp address.
 * \param  tmpBaseAddr   EMATH temp use ram space
 *                        This param can only be set 0xE0000000U
 */
static inline void EMATH_setTmpBase (uint32_t tmpBaseAddr)
{
    WRITE_REG(EMATH->TMPBASE.WORDVAL, tmpBaseAddr);
}

/**
 * \brief  Set EMATH tmpformat register
 * \param  scaler      temp scale value
*                       This parameter can be any value of int8_t
 * \param  formatext   temp extern format
 *                      This parameter can be any value of @ref EMATH_FORMAT
 * \param  formatint   temp internal format
 *                      This parameter can be any value of @ref EMATH_FORMAT
 */
static inline void EMATH_setTmpFormat (int8_t scaler, EMATH_FormatType formatext, EMATH_FormatType formatint)
{
    WRITE_REG(EMATH->TMPFORMAT.WORDVAL, (uint32_t)((scaler<<8U) | (formatext<<4U) | (formatint)));
}

/**
 * \brief  Set EMATH In A base register
 * \note   assign EMATH In A address.
 * \param  inaBaseAddr   ram space address
 *                        This param's range is in the sram space(include DTCM)
 */
static inline void EMATH_setInaBase (uint32_t inaBaseAddr)
{
    WRITE_REG(EMATH->INABASE.WORDVAL, inaBaseAddr);
}

/**
 * \brief  Set EMATH inaformat register
 * \param  scaler      in A scale value
 *                      This parameter can be any value of int8_t
 * \param  formatext   in A extern format
 *                      This parameter can be any value of @ref EMATH_FORMAT
 * \param  formatint   in A internal format
 *                      This parameter can be any value of @ref EMATH_FORMAT
 */
static inline void EMATH_setInaFormat (int8_t scaler, EMATH_FormatType formatext, EMATH_FormatType formatint)
{
    WRITE_REG(EMATH->INAFORMAT.WORDVAL, (uint32_t)((scaler<<8U) | (formatext<<4U) | (formatint)));
}

/**
 * \brief  Set EMATH In B base register
 * \note   assign EMATH In B address.
 * \param  inaBaseAddr   ram space address
 *                        This param's range is in the sram space(include DTCM)
 */
static inline void EMATH_setInbBase (uint32_t inbBaseAddr)
{
    WRITE_REG(EMATH->INBBASE.WORDVAL, inbBaseAddr);
}

/**
 * \brief  Set EMATH inbformat register
 * \param  scaler      in B scale value
 *                      This parameter can be any value of int8_t
 * \param  formatext   in B extern format
 *                      This parameter can be any value of @ref EMATH_FORMAT
 * \param  formatint   in B internal format
 *                      This parameter can be any value of @ref EMATH_FORMAT
 */
static inline void EMATH_setInbFormat (int8_t scaler, EMATH_FormatType formatext, EMATH_FormatType formatint)
{
    WRITE_REG(EMATH->INBFORMAT.WORDVAL, (uint32_t)((scaler<<8U) | (formatext<<4U) | (formatint)));
}

/**
 * \brief  Set EMATH CTRL1 register's Decode machine
 * \param  decodeMachine  EMATH Decode machine
 *                         This param's can be any value of @ref EMATH_DECODEMACHINE
 */
static inline void EMATH_setDecodeMachine (EMATH_DecodeMachineType decodeMachine)
{
    uint32_t machine = (decodeMachine << 4U);

    MODIFY_REG(EMATH->CTRL1.WORDVAL, EMATH_CTRL1_MACHINE_MASK, machine);
}

/**
 * \brief  Set EMATH CTRL1 register Decode opertion code
 * \param  opcode  operation code
 *                  -when Decode machine is Matrix:  @ref EMATH_MATRIX_DECODE_OPCODE
 *                  -when Decode machine is FFT:     @ref EMATH_TRANSFORM_DECODE_OPCODE
 *                  -when Decode machine is FIR:     @ref EMATH_FIR_DECODE_OPCODE
 *                  -when Decode machine is CORDIC:  bit combination with ITER, MIU, T
 */
static inline void EMATH_setDecodeOpcode (uint8_t opcode)
{
    MODIFY_REG(EMATH->CTRL1.WORDVAL, EMATH_CTRL1_OPCODE_MASK, opcode);
}

/**
 * \brief  Set EMATH LENGTH register
 * \param  length  calc data length infomation, different value with decode machine and opcode
 *                  -when calc fir:    length[31:16] is tap length,
 *                                     length[15:0] is input length
 *                  -when calc matrix: length[20:16] is Mat2 row,
 *                                     length[12:8] is Mat1 col,
 *                                     length[4:0] is Mat1 row
 */
static inline void EMATH_setLength (uint32_t length)
{
    WRITE_REG(EMATH->LENGTH.WORDVAL, length);
}

/**
 * \brief  Set EMATH CPPRE register
 * \param  value the value in the CPPRE register
 *                Bit17: cppre_sat8
 *                Bit16: cppre_sat
 *                Bit15-8: adjustment factor which is set when floating-point is converted to fixed-point
 *                Bit7-0: adjustment factor which is set when fixed-point is converted to floating-point
 */
static inline void EMATH_setCppre (uint32_t cppre)
{
    WRITE_REG(EMATH->CPPRE.WORDVAL, cppre);
}

/**
 * \brief  Set EMATH MISC register
 * \param  value the value in the MISC register, for matrix operations scale value
 *                This param's range is [0, 4294967296]
 * \note   Users need to be aware of arithmetic overflow
 */
static inline void EMATH_setMisc (uint32_t miscValue)
{
    WRITE_REG(EMATH->MISC.WORDVAL, miscValue);
}

/**
 * \brief  Enable EMATH CURSORY
 */
static inline void EMATH_enableCursory (void)
{
    SET_BIT(EMATH->CURSORY.WORDVAL, EMATH_CURSORY_ENABLE);
}

/**
 * \brief  Disable EMATH CURSORY
 */
static inline void EMATH_disableCursory (void)
{
    CLEAR_BIT(EMATH->CURSORY.WORDVAL, EMATH_CURSORY_ENABLE);
}

/**
 * \brief  Set EMATH CORDIC_X register
 * \param  value the value in the CORDIC_X register
 *                This param's range is [0, 4294967296]
 */
static inline void EMATH_setCordicX (uint32_t x)
{
    WRITE_REG(EMATH->CORDICX.WORDVAL, x);
}

/**
 * \brief  Set EMATH CORDIC_Y register
 * \param  value the value in the CORDIC_Y register
 *                This param's range is [0, 4294967296]
 */
static inline void EMATH_setCordicY (uint32_t y)
{
    WRITE_REG(EMATH->CORDICY.WORDVAL, y);
}

/**
 * \brief  Set EMATH CORDIC_Z register
 * \param  value the value in the CORDIC_Z register
 *                This param's range is [0, 4294967296]
 */
static inline void EMATH_setCordicZ (uint32_t z)
{
    WRITE_REG(EMATH->CORDICZ.WORDVAL, z);
}

/**
 * \brief  Get EMATH ERRSTAT register value
 * \return Returns  the value in the ERRSTAT register
 *                   This return value is bit combination value
 */
static inline uint32_t EMATH_getErrstat (void)
{
    return READ_REG(EMATH->ERRSTAT.WORDVAL);
}

/**
 * \brief  Get EMATH INTRSTAT register value
 * \return Returns  the value in the INTRSTAT register
 *                   This return value is bit combination value
 */
static inline uint32_t EMATH_getIntrstat (void)
{
    return READ_REG(EMATH->INTRSTAT.WORDVAL);
}

/**
 * \brief  Set EMATH GPREGS register
 * \param  num   GPREGS register index
 *                This param's range is [0, 15]
 * \param  value the value in the GPREGS register
 *                This param's range is [0, 4294967296]
 */
static inline void EMATH_setGrregs (uint8_t num, uint32_t value)
{
    WRITE_REG(EMATH->GPREGSX[num].WORDVAL, value);
}

/**
 * \brief  Get EMATH GPREGS register value
 * \param  num      GPREGS register index
 *                   This param's range is [0, 15]
 * \return Returns  the value in the GPREGS register
 *                  This return value's range is [0, 4294967296]
 */
static inline uint32_t EMATH_getGrregs (uint8_t num)
{
    return READ_REG(EMATH->GPREGSX[num].WORDVAL);
}

/**
 * \brief  Set EMATH COMPREGS register value
 * \param  num   COMPREGS register index
 *                This param's range is [0, 15]
 * \param  value the value in the COMPREGS register
 *                This param's range is [0, 4294967296]
 */
static inline void EMATH_setCompregs (uint8_t num, uint32_t vlaue)
{
    WRITE_REG(EMATH->COMPREGSX[num].WORDVAL, vlaue);
}

/**
 * \brief  Get EMATH COMPREGS register value
 * \param  num      COMPREGS register index
 *                   This param's range is [0, 15]
 * \return Returns  the value in the COMPREGS register
 *                   This return value's range is [0, 4294967296]
 */
static inline uint32_t EMATH_getCompregs (uint8_t num)
{
    return READ_REG(EMATH->COMPREGSX[num].WORDVAL);
}

/**
 * \brief  Set EMATH CTRL2 register value
 * \param  value the value in the CTRL2 register
 *                This parameter is bit combination value
 */
static inline void EMATH_setCpCtrl (uint32_t value)
{
    WRITE_REG(EMATH->CTRL2.WORDVAL, value);
}

/**
 * \brief  Set EMATH CTRL2 register's CTRL2_START bit
 * \note   Start mcr operation
 */
static inline void EMATH_setCpMcrCmd (void)
{
    SET_BIT(EMATH->CTRL2.WORDVAL, CTRL2_START);
    __NOP();
}

/**
 * \brief  Set EMATH CTRL2 register's CTRL2_LOAD bit
 * \note   Start mrc operation
 */
static inline void EMATH_setCpMrcCmd (void)
{
    SET_BIT(EMATH->CTRL2.WORDVAL, CTRL2_LOAD);
}

/**
 * \brief  Get EMATH CP_STAT register value
 * \return Returns  the value in the CP_STAT register
 *                   this return value is bit combination value
 */
static inline uint32_t EMATH_getCpStat (void)
{
    return READ_REG(EMATH->STAT.WORDVAL);
}

/**
 * \brief  Clear EMATH CP_STAT register's CP_INTR_FLAG Bit
 * \note   CP_INTR_FLAG is et when CP operate finish
 */
static inline void EMATH_clrCpIntrFlag (void)
{
    SET_BIT(EMATH->STAT.WORDVAL, EMATH_CP_STAT_INTR);
}

/**
 * \brief  Set EMATH CP_WR_DATA0 register
 * \param  value  the value in CP_WR_DATA0 register
 *                  This param's range is [0, 4294967296]
 */
static inline void EMATH_setCpWData0 (uint32_t value)
{
    WRITE_REG(EMATH->WDATA0.WORDVAL, value);
}

/**
 * \brief  Set EMATH CP_WR_DATA1 register
 * \param  value  the value in CP_WR_DATA1 register
 *                  This param's range is [0, 4294967296]
 */
static inline void EMATH_setCpWData1 (uint32_t value)
{
    WRITE_REG(EMATH->WDATA1.WORDVAL, value);
}

/**
 * \brief  Get EMATH CP_RD_DATA0 register value
 * \return Returns  the value in CP_WR_DATA0 register
 *                   This return value's range is [0, 4294967296]
 */
static inline uint32_t EMATH_getCpRData0 (void)
{
    return READ_REG(EMATH->RDATA0.WORDVAL);
}

/**
 * \brief  Get EMATH CP_RD_DATA1 register value
 * \return Returns  the value in CP_WR_DATA0 register
 *                   This param's range is [0, 4294967296]
 */
static inline uint32_t EMATH_getCpRData1 (void)
{
    return READ_REG(EMATH->RDATA1.WORDVAL);
}


#ifdef __cplusplus
}
#endif


#endif  /* __EMATH_H__ */
