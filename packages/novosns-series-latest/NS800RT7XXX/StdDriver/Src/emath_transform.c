/**
  * @file       emath_transform.c
  * @author     yangjun
  * @brief      Function file for NS800RT7xxx emath-transform module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "emath.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup EMATH_TRANSFORM EMATH transform Internal Used Types
  * @{
  * @brief  Macro definitions are used with only EMATH transform module.
  */

/** @defgroup FFT decode machine
  * @{
  * @brief  Macro definitions about Decode machine FFT.
  */
#define CP_FFT    (2UL << 4UL)    /*!< Decode machine: FFT */

/**
  * @}
  */

/** @defgroup EMATH_TRANSFORM_DECODE_OPCODE EMATH tannsform decode opcode
  * @{
  * @brief  Macro definitions are used with EMATH FFT decode opcode.
  */
#define EMATH_TRANS_CFFT    (0UL)    /*!< complex FFT transform */
#define EMATH_TRANS_IFFT    (1UL)    /*!< inverse FFT transform */
#define EMATH_TRANS_CDCT    (2UL)    /*!< complex discrete cosine transform */
#define EMATH_TRANS_IDCT    (3UL)    /*!< inverse discrete cosine transform */
#define EMATH_TRANS_RFFT    (4UL)    /*!< real FFT transform */
#define EMATH_TRANS_RDCT    (6UL)    /*!< real discrete cosine transform */

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
 * @brief  complex FFT transform
 * @param  pData     points to the complex data buffer{x0_real, x0_imaginary, x1_real, x1_imaginary...}
 * @param  length    pData buffer size(can only be set 16, 32, 64, 128, 256, 512, max is 512),
 * @param  pResult   points to complex FFT transform result
 */
void EMATH_transformCFFT (void *pData, uint32_t length, void *pResult)
{
    WRITE_REG(EMATH->OUTBASE.WORDVAL, (uint32_t)pResult);
    WRITE_REG(EMATH->INABASE.WORDVAL, (uint32_t)pData);
    WRITE_REG(EMATH->LENGTH.WORDVAL, length);

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL1.WORDVAL, (CP_FFT | EMATH_TRANS_CFFT));
}

/**
 * @brief  real FFT transform
 * @param  pData     points to the real data buffer{x0, x1...}
 * @param  length    pData buffer size(can only be set 16, 32, 64, 128, 256, 512, max is 512),
 * @param  pResult   points to real FFT transform result
 */
void EMATH_transformRFFT (void *pData, uint32_t length, void *pResult)
{
    /* Set 0's for imaginary inputs as not be reading them in by the machine */
    WRITE_REG(EMATH->GPREGSX[1].WORDVAL, 0U);
    WRITE_REG(EMATH->GPREGSX[3].WORDVAL, 0U);
    WRITE_REG(EMATH->GPREGSX[5].WORDVAL, 0U);
    WRITE_REG(EMATH->GPREGSX[7].WORDVAL, 0U);
    WRITE_REG(EMATH->GPREGSX[9].WORDVAL, 0U);
    WRITE_REG(EMATH->GPREGSX[11].WORDVAL, 0U);
    WRITE_REG(EMATH->GPREGSX[13].WORDVAL, 0U);
    WRITE_REG(EMATH->GPREGSX[15].WORDVAL, 0U);
    WRITE_REG(EMATH->OUTBASE.WORDVAL, (uint32_t)pResult);
    WRITE_REG(EMATH->INABASE.WORDVAL, (uint32_t)pData);
    WRITE_REG(EMATH->LENGTH.WORDVAL, length);

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL1.WORDVAL, (CP_FFT | EMATH_TRANS_RFFT));
}

/**
 * @brief  inverse FFT transform
 * @param  pData     points to the real data buffer{x0, x1...}
 * @param  length    pData buffer size(can only be set 16, 32, 64, 128, 256, 512, max is 512),
 * @param  pResult   points to inverse FFT transform result
 */
void EMATH_transformIFFT (void *pData, uint32_t length, void *pResult)
{
    WRITE_REG(EMATH->OUTBASE.WORDVAL, (uint32_t)pResult);
    WRITE_REG(EMATH->INABASE.WORDVAL, (uint32_t)pData);
    WRITE_REG(EMATH->LENGTH.WORDVAL, length);

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL1.WORDVAL, (CP_FFT | EMATH_TRANS_IFFT));
}

/**
 * @brief  complex discrete cosine transform(DCT)
 * @param  pData     points to the complex data buffer{x0, x1...}
 * @param  length    pData buffer size(can only be set 16, 32, 64, 128, 256, 512, max is 512),
 * @param  pResult   points to discrete cosine transform result
 */
void EMATH_transformCDCT (void *pData, uint32_t length, void *pResult)
{
    WRITE_REG(EMATH->OUTBASE.WORDVAL, (uint32_t)pResult);
    WRITE_REG(EMATH->INABASE.WORDVAL, (uint32_t)pData);
    WRITE_REG(EMATH->LENGTH.WORDVAL, length);

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL1.WORDVAL, (CP_FFT | EMATH_TRANS_CDCT));
}

/**
 * @brief  real discrete cosine transform(DCT)
 * @param  pData     points to the real data buffer{x0, x1...}
 * @param  length    pData buffer size(can only be set 16, 32, 64, 128, 256, 512, max is 512),
 * @param  pResult   points to discrete cosine transform result
 */
void EMATH_transformRDCT (void *pData, uint32_t length, void *pResult)
{
    WRITE_REG(EMATH->GPREGSX[1].WORDVAL, 0U);
    WRITE_REG(EMATH->GPREGSX[3].WORDVAL, 0U);
    WRITE_REG(EMATH->GPREGSX[5].WORDVAL, 0U);
    WRITE_REG(EMATH->GPREGSX[7].WORDVAL, 0U);
    WRITE_REG(EMATH->GPREGSX[9].WORDVAL, 0U);
    WRITE_REG(EMATH->GPREGSX[11].WORDVAL, 0U);
    WRITE_REG(EMATH->GPREGSX[13].WORDVAL, 0U);
    WRITE_REG(EMATH->GPREGSX[15].WORDVAL, 0U);
    WRITE_REG(EMATH->OUTBASE.WORDVAL, (uint32_t)pResult);
    WRITE_REG(EMATH->INABASE.WORDVAL, (uint32_t)pData);
    WRITE_REG(EMATH->LENGTH.WORDVAL, length);

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL1.WORDVAL, (CP_FFT | EMATH_TRANS_RDCT));
}

/**
 * @brief  inverse discrete cosine transform(IDCT)
 * @param  pData     points to the data buffer{x0, x1...}
 * @param  length    pData buffer size(can only be set 16, 32, 64, 128, 256, 512, max is 512),
 * @param  pResult   inverse discrete cosine transform result
 */
void EMATH_transformIDCT (void *pData, uint32_t length, void *pResult)
{
    WRITE_REG(EMATH->OUTBASE.WORDVAL, (uint32_t)pResult);
    WRITE_REG(EMATH->INABASE.WORDVAL, (uint32_t)pData);
    WRITE_REG(EMATH->LENGTH.WORDVAL, length);

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL1.WORDVAL, (CP_FFT | EMATH_TRANS_IDCT));
}
