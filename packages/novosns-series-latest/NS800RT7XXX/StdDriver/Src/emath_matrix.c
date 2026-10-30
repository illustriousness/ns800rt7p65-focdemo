/**
  * @file       emath_matrix.c
  * @author     yangjun
  * @brief      Function file for NS800RT7xxx emath-matrix module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "emath.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup EMATH_MATRIX EMATH matrix Internal Used Types
  * @{
  * @brief  Macro definitions are used with only EMATH matrix module.
  */

/** @defgroup EMATH_MATRIX_DECODE_MACHINE EMATH Matrix Decode machine
  * @{
  * @brief  Macro definitions are used with decode machine.
  */

#define CP_MTX    (1UL << 4UL)    /*!< Decode machine: matrix */

/**
  * @}
  */

/** @defgroup EMATH_MATRIX_DECODE_OPCODE EMATH Matrix Decode opcode Types
  * @{
  * @brief  Macro definitions are used with EMATH Matrix module.
  */

#define EMATH_MTX_SCALE    (1UL)     /*!< matrix scale */
#define EMATH_MTX_MULT     (2UL)     /*!< matrix multiplication */
#define EMATH_MTX_ADD      (3UL)     /*!< matrix addition */
#define EMATH_MTX_INV      (4UL)     /*!< matrix inverition */
#define EMATH_MTX_PROD     (5UL)     /*!< matrix production */
#define EMATH_MTX_SUB      (7UL)     /*!< matrix subtraction */
#define EMATH_VEC_DOTP     (9UL)     /*!< vector production */
#define EMATH_MTX_TRAN     (10UL)    /*!< matrix transpose */

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
 * @brief  Calculate the matrix addition of two matrices
 * @param  pAData    points to the input matrix A
 * @param  pBData    points to the input matrix B
 * @param  length    length rows and cols for matrix
 *                   length[23:16] - B rows
 *                   length[15:8]  - A cols
 *                   length[7:0]   - A rows
 * @param  pResult   points to the output matrix
 */
void EMATH_matrixAddition (void *pAData, void *pBData, uint32_t length, void *pResult)
{
    WRITE_REG(EMATH->OUTBASE.WORDVAL, (uint32_t)pResult);
    WRITE_REG(EMATH->INABASE.WORDVAL, (uint32_t)pAData);
    WRITE_REG(EMATH->INBBASE.WORDVAL, (uint32_t)pBData);
    WRITE_REG(EMATH->LENGTH.WORDVAL, length);

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL1.WORDVAL, (CP_MTX | EMATH_MTX_ADD));
}

/**
 * @brief  Calculate the matrix subtration of two matrices
 * @param  pAData    points to the input matrix A
 * @param  pBData    points to the input matrix B
 * @param  length    length rows and cols for matrix
 *                   length[23:16] - B rows
 *                   length[15:8]  - A cols
 *                   length[7:0]   - A rows
 * @param  pResult   points to the output matrix
 */
void EMATH_matrixSubtraction (void *pAData, void *pBData, uint32_t length, void *pResult)
{
    WRITE_REG(EMATH->OUTBASE.WORDVAL, (uint32_t)pResult);
    WRITE_REG(EMATH->INABASE.WORDVAL, (uint32_t)pAData);
    WRITE_REG(EMATH->INBBASE.WORDVAL, (uint32_t)pBData);
    WRITE_REG(EMATH->LENGTH.WORDVAL, length);

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL1.WORDVAL, (CP_MTX | EMATH_MTX_SUB));
}

/**
 * @brief  Calculate the matrix multiplication of two matrices
 * @param  pAData    points to the input matrix A
 * @param  pBData    points to the input matrix B
 * @param  length    length rows and cols for matrix
 *                   length[23:16] - B rows
 *                   length[15:8]  - A cols
 *                   length[7:0]   - A rows
 * @param  pResult   points to the output matrix
 */
void EMATH_matrixMultiplication (void *pAData, void *pBData, uint32_t length, void *pResult)
{
    WRITE_REG(EMATH->OUTBASE.WORDVAL, (uint32_t)pResult);
    WRITE_REG(EMATH->INABASE.WORDVAL, (uint32_t)pAData);
    WRITE_REG(EMATH->INBBASE.WORDVAL, (uint32_t)pBData);
    WRITE_REG(EMATH->LENGTH.WORDVAL, length);

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL1.WORDVAL, (CP_MTX | EMATH_MTX_MULT));
}

/**
 * @brief  Calculate the matrix production of two matrices
 * @param  pAData    points to the input matrix A
 * @param  pBData    points to the input matrix B
 * @param  length    length rows and cols for matrix
 *                   length[23:16] - B rows
 *                   length[15:8]  - A cols
 *                   length[7:0]   - A rows
 * @param  pResult   points to the output matrix
 */
void EMATH_matrixProduct (void *pAData, void *pBData, uint32_t length, void *pResult)
{
    WRITE_REG(EMATH->OUTBASE.WORDVAL, (uint32_t)pResult);
    WRITE_REG(EMATH->INABASE.WORDVAL, (uint32_t)pAData);
    WRITE_REG(EMATH->INBBASE.WORDVAL, (uint32_t)pBData);
    WRITE_REG(EMATH->LENGTH.WORDVAL, length);

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL1.WORDVAL, (CP_MTX | EMATH_MTX_PROD));
}

/**
 * @brief  Calculate the dot production of two vectors
 * @param  pAData    points to the input vector A
 * @param  pBData    points to the input vector B
 * @param  length    length rows and cols for matrix
 *                   length[23:16] - B rows
 *                   length[15:8]  - A cols
 *                   length[7:0]   - A rows
 * @param  pResult   points to the output vector
 */
void EMATH_vectorDotProduct (void *pAData, void *pBData, uint32_t length, void *pResult)
{
    WRITE_REG(EMATH->OUTBASE.WORDVAL, (uint32_t)pResult);
    WRITE_REG(EMATH->INABASE.WORDVAL, (uint32_t)pAData);
    WRITE_REG(EMATH->INBBASE.WORDVAL, (uint32_t)pBData);
    WRITE_REG(EMATH->LENGTH.WORDVAL, length);

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL1.WORDVAL, (CP_MTX | EMATH_VEC_DOTP));
}

/**
 * @brief  Calculate matrix inversion
 * @param  pData     points to the input matrix
 * @param  pTmpData  points to the temp buffer
 * @param  length    length for matrix
 * @param  pResult   points to the output matrix
 */
void EMATH_matrixInversion (void *pData, void *pTmp, uint32_t length, void *pResult)
{
    WRITE_REG(EMATH->INABASE.WORDVAL, (uint32_t)pData);
    WRITE_REG(EMATH->TMPBASE.WORDVAL, (uint32_t)pTmp);
    WRITE_REG(EMATH->OUTBASE.WORDVAL, (uint32_t)pResult);
    WRITE_REG(EMATH->LENGTH.WORDVAL, length);

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL1.WORDVAL, (CP_MTX | EMATH_MTX_INV));
}

/**
 * @brief  Calculate matrix transpose
 * @param  pData     points to the input matrix
 * @param  length    length for matrix
 * @param  pResult   points to the output matrix
 */
void EMATH_matrixTranspose (void *pData, uint32_t length, void *pResult)
{
    WRITE_REG(EMATH->OUTBASE.WORDVAL, (uint32_t)pResult);
    WRITE_REG(EMATH->INABASE.WORDVAL, (uint32_t)pData);
    WRITE_REG(EMATH->LENGTH.WORDVAL, length);

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL1.WORDVAL, (CP_MTX | EMATH_MTX_TRAN));
}

/**
 * @brief  Calculate matrix scale
 * @param  pData     points to the input matrix
 * @param  length    length for matrix
 * @param  misc      scale cofficient
 * @param  pResult   points to the output matrix
 */
void EMATH_matrixScale (const void *pData, uint32_t length, float misc, void *pResult)
{
    WRITE_REG(EMATH->OUTBASE.WORDVAL, (uint32_t)(uint32_t *)pResult);
    WRITE_REG(EMATH->INABASE.WORDVAL, (uint32_t)(const uint32_t *)pData);
    WRITE_REG(EMATH->LENGTH.WORDVAL, length);
    WRITE_REG(EMATH->MISC.WORDVAL, *((uint32_t *)&(misc)));

    __asm volatile("" ::: "memory");

    WRITE_REG(EMATH->CTRL1.WORDVAL, (CP_MTX | EMATH_MTX_SCALE));
}
