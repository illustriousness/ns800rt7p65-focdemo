/**
  * @file       trng.h
  * @author     yangjun
  * @brief      Header file for NS800RT7xxx trng module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __TRNG_H__
#define __TRNG_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup TRNG_EXPORTED_TYPES TRNG Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'TRNG' module.
  */

/** @defgroup TRNG_STATUS TRNG status register
  * @{
  * @brief  The following are defines for the bit fields in the TRNG_STATUS register.
  */
#define TRNG_STATUS_TEST_RESULT_S    (0UL)
#define TRNG_STATUS_TEST_RESULT_M    (0x0000FFFFUL)    /*!< all test bits */

/**
  * @}
  */

/** @defgroup TRNG_PKRCNT TRNG statistical check poker count high and low register
  * @{
  * @brief  The following are defines for the bit fields in the TRNG_PKRCNT register.
  */
#define TRNG_PKRCNT_PKR_HI_CT_S     (16UL)
#define TRNG_PKRCNT_PKR_HI_CT_M     (0xFFFF0000UL)     /*!< Poker high Count */
#define TRNG_PKRCNT_PKR_LOW_CT_S    (0UL)
#define TRNG_PKRCNT_PKR_LOW_CT_M    (0x0000FFFFUL)    /*!< Poker low Count */

/**
  * @}
  */

/** @defgroup TRNG_INT_CTRL TRNG interrupt control register
  * @{
  * @brief  The following are defines for the bit fields in the TRNG_INT_CTRL register.
  */
#define TRNG_INT_CTRL_S    (0UL)
#define TRNG_INT_CTRL_M    (0x00000007UL)    /*!< control the status for the three important interrupts */

/**
  * @}
  */

/** @defgroup TRNG_INT_MASK TRNG interrupt mask register
  * @{
  * @brief  The following are defines for the bit fields in the TRNG_INT_MASK register.
  */
#define TRNG_INT_MASK_S    (0UL)
#define TRNG_INT_MASK_M    (0x00000007UL)    /*!< disable/mask the status for the three important interrupts */

/**
  * @}
  */

/** @defgroup TRNG_INT_STATUS TRNG interrupt status register
  * @{
  * @brief  The following are defines for the bit fields in the TRNG_INT_STATUS register.
  */
#define TRNG_INT_STATUS_S    (0UL)
#define TRNG_INT_STATUS_M    (0x00000007UL)    /*!< the status for the three important interrupts */

/**
  * @}
  */

/** @defgroup TRNG_TEST_RESULT TRNG test result
  * @{
  * @brief  Values that can be passed to TRNG_getTestResult() as the \e mode parameter.
  */
#define TRNG_TEST_RESULT_TFMB       (0x00008000UL)    /*!< Test Fail, Mono Bit */
#define TRNG_TEST_RESULT_TFP        (0x00004000UL)    /*!< Test Fail, Poker */
#define TRNG_TEST_RESULT_TFLR       (0x00002000UL)    /*!< Test Fail, Long Run */
#define TRNG_TEST_RESULT_TFSB       (0x00001000UL)    /*!< Test Fail, Sparse Bit */
#define TRNG_TEST_RESULT_TF6PBR1    (0x00000800UL)    /*!< Test Fail, 6 Plus Bit Run, Sampling 1s */
#define TRNG_TEST_RESULT_TF6PBR0    (0x00000400UL)    /*!< Test Fail, 6 Plus Bit Run, Sampling 0s */
#define TRNG_TEST_RESULT_TF5BR1     (0x00000200UL)    /*!< Test Fail, 5-Bit Run, Sampling 1s */
#define TRNG_TEST_RESULT_TF5BR0     (0x00000100UL)    /*!< Test Fail, 5-Bit Run, Sampling 0s */
#define TRNG_TEST_RESULT_TF4BR1     (0x00000080UL)    /*!< Test Fail, 4-Bit Run, Sampling 1s */
#define TRNG_TEST_RESULT_TF4BR0     (0x00000040UL)    /*!< Test Fail, 4-Bit Run, Sampling 0s */
#define TRNG_TEST_RESULT_TF3BR1     (0x00000020UL)    /*!< Test Fail, 3-Bit Run, Sampling 1s */
#define TRNG_TEST_RESULT_TF3BR0     (0x00000010UL)    /*!< Test Fail, 3-Bit Run, Sampling 0s */
#define TRNG_TEST_RESULT_TF2BR1     (0x00000008UL)    /*!< Test Fail, 2-Bit Run, Sampling 1s */
#define TRNG_TEST_RESULT_TF2BR0     (0x00000004UL)    /*!< Test Fail, 2-Bit Run, Sampling 0s */
#define TRNG_TEST_RESULT_TF1BR1     (0x00000002UL)    /*!< Test Fail, 1-Bit Run, Sampling 1s */
#define TRNG_TEST_RESULT_TF1BR0     (0x00000001UL)    /*!< Test Fail, 1-Bit Run, Sampling 0s */

/**
  * @}
  */

/** @defgroup TRNG_INT TRNG interrupt
  * @{
  * @brief  Values that can be passed to TRNG_clearInterruptSource(), TRNG_getInterruptStatus(),
  *          TRNG_enableInterruptSource() and TRNG_disableInterruptSource() as the \e mode parameter.
  */
#define TRNG_INT_FRQ_CT_FAIL    (0x4UL)    /*!< Frequency count fail interrupt */
#define TRNG_INT_ENT_VAL        (0x2UL)    /*!< Entropy valid interrupt */
#define TRNG_INT_HW_ERR         (0x1UL)    /*!< HW error interrupt */

/**
  * @}
  */

/** @defgroup TRNG_WORKMODE TRNG programming mode select
  * @{
  * @brief  Values that can be passed to TRNG_setWorkMode() as the \e mode parameter.
  */
typedef enum {
    TRNG_RUN_MODE = 0U,    /*!< run mode */
    TRNG_PROG_MODE         /*!< program mode */
} TRNG_WorkMode;

/**
  * @}
  */

/** @defgroup TRNG_CLOCKSOURCE TRNG clock source select
  * @{
  * @brief  Values that can be passed to TRNG_setClockSource() as the \e mode parameter.
  */
 typedef enum {
    TRNG_CLOCK_SOURCE_RING_OSC = 0U,    /*!< use ring oscillator */
    TRNG_CLOCK_SOURCE_FORCE_SYS         /*!< use system clock */
 } TRNG_ClockSource;

/**
  * @}
  */

/** @defgroup TRNG_RINGOSCDIV TRNG ring oscillator divide
  * @{
  * @brief  Values that can be passed to TRNG_setRingOscDivide() as the \e mode parameter.
  */
typedef enum {
    TRNG_RING_OSC_DIV1 = 0U,    /*!< use ring oscillator with no divide */
    TRNG_RING_OSC_DIV2,         /*!< use ring oscillator divided-by-2 */
    TRNG_RING_OSC_DIV4,         /*!< use ring oscillator divided-by-4 */
    TRNG_RING_OSC_DIV8          /*!< use ring oscillator divided-by-8 */
 } TRNG_RingOscDivide;

/**
  * @}
  */

/** @defgroup TRNG_SAMPLEMODE TRNG sample mode
  * @{
  * @brief  Values that can be passed to TRNG_setSampleMode() as the \e mode parameter.
  */
typedef enum {
    TRNG_SAMPLE_USE_VONNEUMANN = 0U,    /*!< use Von Neumann data into both Entropy shifter and Statistical Checker */
    TRNG_SAMPLE_USE_RAW,                /*!< use raw data into both Entropy shifter and Statistical Checker */
    TRNG_SAMPLE_USE_BOTH                /*!< use Von Neumann data into Entropy shifter. Use raw data into Statistical Checker */
} TRNG_SampleMode;

/**
  * @}
  */

/** @defgroup TRNG_ENTROPYINDEX TRNG entropy index
  * @{
  * @brief  Values that can be passed to TRNG_getEntropyValue() as the \e index parameter.
  */
typedef enum {
    TRNG_ENTROPY_0 = 0,    /*!< entropy value 0 */
    TRNG_ENTROPY_1,        /*!< entropy value 1 */
    TRNG_ENTROPY_2,        /*!< entropy value 2 */
    TRNG_ENTROPY_3,        /*!< entropy value 3 */
    TRNG_ENTROPY_4,        /*!< entropy value 4 */
    TRNG_ENTROPY_5,        /*!< entropy value 5 */
    TRNG_ENTROPY_6,        /*!< entropy value 6 */
    TRNG_ENTROPY_7,        /*!< entropy value 7 */
    TRNG_ENTROPY_8,        /*!< entropy value 8 */
    TRNG_ENTROPY_9,        /*!< entropy value 9 */
    TRNG_ENTROPY_10,       /*!< entropy value 10 */
    TRNG_ENTROPY_11,       /*!< entropy value 11 */
    TRNG_ENTROPY_12,       /*!< entropy value 12 */
    TRNG_ENTROPY_13,       /*!< entropy value 13 */
    TRNG_ENTROPY_14,       /*!< entropy value 14 */
    TRNG_ENTROPY_15        /*!< entropy value 15 */
} TRNG_EntropyIndex;

/**
  * @}
  */

/** @defgroup TRNG_POKERCOUNTTYPDE TRNG poker count type
  * @{
  * @brief  Values that can be passed to TRNG_getPokerCount() as the \e count parameter.
  */
typedef enum {
    TRNG_POKER_0_COUNT = 0,    /*!< Poker 0h Counter */
    TRNG_POKER_1_COUNT,        /*!< Poker 1h Counter */
    TRNG_POKER_2_COUNT,        /*!< Poker 2h Counter */
    TRNG_POKER_3_COUNT,        /*!< Poker 3h Counter */
    TRNG_POKER_4_COUNT,        /*!< Poker 4h Counter */
    TRNG_POKER_5_COUNT,        /*!< Poker 5h Counter */
    TRNG_POKER_6_COUNT,        /*!< Poker 6h Counter */
    TRNG_POKER_7_COUNT,        /*!< Poker 7h Counter */
    TRNG_POKER_8_COUNT,        /*!< Poker 8h Counter */
    TRNG_POKER_9_COUNT,        /*!< Poker 9h Counter */
    TRNG_POKER_A_COUNT,        /*!< Poker Ah Counter */
    TRNG_POKER_B_COUNT,        /*!< Poker Bh Counter */
    TRNG_POKER_C_COUNT,        /*!< Poker Ch Counter */
    TRNG_POKER_D_COUNT,        /*!< Poker Dh Counter */
    TRNG_POKER_E_COUNT,        /*!< Poker Eh Counter */
    TRNG_POKER_F_COUNT         /*!< Poker Fh Counter */
} TRNG_PokerCountType;

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
 * \brief  Set TRNG Programming Mode.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  mode  the TRNG Programming Mode Select.
 *                This parameter can be any value of @ref TRNG_WORKMODE
 */
static inline void TRNG_setWorkMode (TRNG_TypeDef *trng, TRNG_WorkMode mode)
{
    MODIFY_REG(trng->MCTL.WORDVAL, TRNG_MCTL_PRGM_M, (uint32_t)mode << TRNG_MCTL_PRGM_S);
}

/**
 * \brief  Check if ok to stop the TRNG clock.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG TRNG_OK_TO_STOP status.
 *                - 1: it is ok to stop the TRNG clock.
 *                - 0: it is not ok to stop the TRNG clock.
 */
static inline uint32_t TRNG_isOkToStop (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->MCTL.WORDVAL, TRNG_MCTL_TSTOPOK_M)? 1UL : 0UL;
}

/**
 * \brief  Get TRNG error status.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG error status.
 *                - 1: error detected.
 *                - 0: no error.
 */
static inline uint32_t TRNG_getErrorStatus (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->MCTL.WORDVAL, TRNG_MCTL_ERR_M)? 1UL : 0UL;
}

/**
 * \brief  Clear TRNG error.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 */
static inline void TRNG_clearErrorStatus (TRNG_TypeDef *trng)
{
    SET_BIT(trng->MCTL.WORDVAL, TRNG_MCTL_ERR_M);
}

/**
 * \brief  Check if TRNG entropy valid.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG error status.
 *                - 1: entropy valid.
 *                - 0: entropy invalid.
 */
static inline uint32_t TRNG_isEntropyValid (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->MCTL.WORDVAL, TRNG_MCTL_ENTVAL_M)? 1UL : 0UL;
}

/**
 * \brief  Check if TRNG frequency count valid.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG error status.
 *                - 1: frequency count valid.
 *                - 0: frequency count invalid.
 */
static inline uint32_t TRNG_isFreqCountValid (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->MCTL.WORDVAL, TRNG_MCTL_FCTVAL_M)? 1UL : 0UL;
}

/**
 * \brief  Check if TRNG frequency count fail.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG error status.
 *                - 1: The frequency counter has detected a failure.
 *                - 0: The frequency counter has not detected a failure.
 */
static inline uint32_t TRNG_isFreqCountFail (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->MCTL.WORDVAL, TRNG_MCTL_FCTFAIL_M)? 1UL : 0UL;
}

/**
 * \brief  Set TRNG clock source.
 * \note   This bit is writable only if PRGM bit is 1, or PRGM bit is being
 *          written to 1 simultaneously to writing this bit. This bit is
 *          cleared by writing the RST_DEF bit to 1.
 * \param  trng    pointer to a TRNG_TypeDef structure
 *                  - TRNG: TRNG base address
 * \param  source  the TRNG clock source select.
 *                  This parameter can be any value of @ref TRNG_CLOCKSOURCE
 */
static inline void TRNG_setClockSource (TRNG_TypeDef *trng, TRNG_ClockSource source)
{
    MODIFY_REG(trng->MCTL.WORDVAL, TRNG_MCTL_FORSCLK_M, (uint32_t)source << TRNG_MCTL_FORSCLK_S);
}

/**
 * \brief  Reset TRNG registers.
 * \note   This bit is writable only if PRGM bit is 1, or PRGM bit is being
 *          written to 1 simultaneously to writing this bit.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 */
static inline void TRNG_restDefault (TRNG_TypeDef *trng)
{
    SET_BIT(trng->MCTL.WORDVAL, TRNG_MCTL_RSTDEF_M);
}

/**
 * \brief  enable TRNG access mode.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 */
static inline void TRNG_enableAccessMode (TRNG_TypeDef *trng)
{
    SET_BIT(trng->MCTL.WORDVAL, TRNG_MCTL_TRNGACC_M);
}

/**
 * \brief  disable TRNG access mode.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 */
static inline void TRNG_disableAccessMode (TRNG_TypeDef *trng)
{
    CLEAR_BIT(trng->MCTL.WORDVAL, TRNG_MCTL_TRNGACC_M);
}

/**
 * \brief  Set TRNG oscillator divide.
 * \note   This bit is writable only if PRGM bit is 1, or PRGM bit is being
 *          written to 1 simultaneously to writing this bit.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  div   TRNG ring oscillator divide
 *                This parameter can be any value of @ref TRNG_RINGOSCDIV
 */

static inline void TRNG_setRingOscDivide (TRNG_TypeDef *trng, TRNG_RingOscDivide div)
{
    MODIFY_REG(trng->MCTL.WORDVAL, TRNG_MCTL_OSCDIV_M, (uint32_t)div << TRNG_MCTL_OSCDIV_S);
}

/**
 * \brief  Set TRNG sample mode.
 * \note   This bit is writable only if PRGM bit is 1, or PRGM bit is being
 *          written to 1 simultaneously to writing this bit.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  mode  TRNG sample mode
 *                This parameter can be any value of @ref TRNG_SAMPLEMODE
 */
static inline void TRNG_setSampleMode (TRNG_TypeDef *trng, TRNG_SampleMode mode)
{
    MODIFY_REG(trng->MCTL.WORDVAL, TRNG_MCTL_SAMPMODE_M, (uint32_t)mode << TRNG_MCTL_SAMPMODE_S);
}

/**
 * \brief  Set TRNG retry count.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng   pointer to a TRNG_TypeDef structure
 *                 - TRNG: TRNG base address
 * \param  count  TRNG retry count
 *                 - This parameter can be one value range from 0 to 0xF.
 */
static inline void TRNG_setRetryCount (TRNG_TypeDef *trng, uint16_t count)
{
    MODIFY_REG(trng->SCMISC.WORDVAL, TRNG_SCMISC_RTYCT_M, ((uint32_t)count << TRNG_SCMISC_RTYCT_S) & TRNG_SCMISC_RTYCT_M);
}

/**
 * \brief  Set TRNG long run max limit.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  max   TRNG long run max limit
 *                - This parameter can be one value range from 0 to 0xFF.
 */
static inline void TRNG_setLongRunMax (TRNG_TypeDef *trng, uint16_t max)
{
    MODIFY_REG(trng->SCMISC.WORDVAL, TRNG_SCMISC_LRUNMAX_M, ((uint32_t)max << TRNG_SCMISC_LRUNMAX_S) & TRNG_SCMISC_LRUNMAX_M);
}

/**
 * \brief  Set TRNG poker range.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng   pointer to a TRNG_TypeDef structure
 *                 - TRNG: TRNG base address
 * \param  range  poker range
 *                 - This parameter can be one value range from 0 to 0xFFFF.
 */
static inline void TRNG_setPokerRange (TRNG_TypeDef *trng, uint16_t range)
{
    MODIFY_REG(trng->PKRRNG.WORDVAL, TRNG_PKRRNG_PKRRNG_M, ((uint32_t)range << TRNG_PKRRNG_PKRRNG_S) & TRNG_PKRRNG_PKRRNG_M);
}

/**
 * \brief  Set TRNG poker maximum limit.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  max   poker maximum limit
 *                - This parameter can be one value range from 0 to 0xFFFFFF.
 */
static inline void TRNG_setPokerMax (TRNG_TypeDef *trng, uint32_t max)
{
    MODIFY_REG(trng->PKRMAX.WORDVAL, TRNG_PKRMAX_PKRMAX_M, ((uint32_t)max << TRNG_PKRMAX_PKRMAX_S) & TRNG_PKRMAX_PKRMAX_M);
}

/**
 * \brief  Get TRNG poker square calculation result.
 * \note   The resulting value may be read through this register, if TRNG_MCTL[PRGM] bit is 0.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG poker square calculation result
 *                - The value range from 0 to 0xFFFFFF.
 */
static inline uint32_t TRNG_getPokerSquareResult (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->PKRMAX.WORDVAL, TRNG_PKRSQ_PKRSQ_M) >> TRNG_PKRSQ_PKRSQ_S;
}

/**
 * \brief  Set TRNG Entropy delay.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng   pointer to a TRNG_TypeDef structure
 *                 - TRNG: TRNG base address
 * \param  delay  entropy delay
 *                 - This parameter can be one value range from 0 to 0xFFFF.
 */
static inline void TRNG_setEntropyDelay (TRNG_TypeDef *trng, uint16_t delay)
{
    MODIFY_REG(trng->SDCTL.WORDVAL, TRNG_SDCTL_ENTDLY_M, ((uint32_t)delay << TRNG_SDCTL_ENTDLY_S) & TRNG_SDCTL_ENTDLY_M);
}

/**
 * \brief  Set TRNG sample size.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  size  sample size
 *                - This parameter can be one value range from 0 to 0xFFFF.
 */
static inline void TRNG_setSampleSize (TRNG_TypeDef *trng, uint16_t size)
{
    MODIFY_REG(trng->SDCTL.WORDVAL, TRNG_SDCTL_SAMPSIZE_M, ((uint32_t)size << TRNG_SDCTL_SAMPSIZE_S) & TRNG_SDCTL_SAMPSIZE_M);
}

/**
 * \brief  Set TRNG sparse bit limit.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  size  sparse bit limit
 *                - This parameter can be one value range from 0 to 0x1FF.
 */
static inline void TRNG_setSparseBitLimit (TRNG_TypeDef *trng, uint16_t size)
{
    MODIFY_REG(trng->SBLIM.WORDVAL, TRNG_SBLIM_SBLIM_M, ((uint32_t)size << TRNG_SBLIM_SBLIM_S) & TRNG_SBLIM_SBLIM_M);
}

/**
 * \brief  Get TRNG total samples.
 * \note   The count may be read through this register, if TRNG_MCTL[PRGM] bit is 0.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG total samples
 *                - The value range from 0 to 0xFFFFF.
 */
static inline uint32_t TRNG_getTotalSample (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->TOTSAM.WORDVAL, TRNG_TOTSAM_TOTSAM_M) >> TRNG_TOTSAM_TOTSAM_S;
}

/**
 * \brief  Set TRNG frequency count minimum limit.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  count frequency count minimum limit
 *                - This parameter can be one value range from 0 to 0x3FFFFF.
 */
static inline void TRNG_setFrequencyCountMin (TRNG_TypeDef *trng, uint32_t count)
{
    MODIFY_REG(trng->FRQMIN.WORDVAL, TRNG_FRQMIN_FRQMIN_M, ((uint32_t)count << TRNG_FRQMIN_FRQMIN_S) & TRNG_FRQMIN_FRQMIN_M);
}

/**
 * \brief  Get TRNG frequency count.
 * \note   The count may be read through this register, if TRNG_MCTL[PRGM] bit is 0.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG frequency count
 *                - The value range from 0 to 0x3FFFFF.
 */
static inline uint32_t TRNG_getFrequencyCount (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->FRQCNT.WORDVAL, TRNG_FRQCNT_FRQCT_M) >> TRNG_FRQCNT_FRQCT_S;
}

/**
 * \brief  Set TRNG frequency count maximum limit.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  count frequency count maximum limit
 *                - This parameter can be one value range from 0 to 0x3FFFFF.
 */
static inline void TRNG_setFrequencyCountMax (TRNG_TypeDef *trng, uint32_t count)
{
    MODIFY_REG(trng->FRQMAX.WORDVAL, TRNG_FRQMAX_FRQMAX_M, ((uint32_t)count << TRNG_FRQMAX_FRQMAX_S) & TRNG_FRQMAX_FRQMAX_M);
}

/**
 * \brief  Get TRNG monobit count.
 * \note   The count may be read through this register, if TRNG_MCTL[PRGM] bit is 0.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG monobit count
 *                - The value range from 0 to 0xFFFF.
 */
static inline uint32_t TRNG_getMonobitCount (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->SCMC.WORDVAL, TRNG_SCMC_MONOCT_M) >> TRNG_SCMC_MONOCT_S;
}

/**
 * \brief  Set TRNG monobit range.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  count monobit range
 *                - This parameter can be one value range from 0 to 0xFFFF.
 */
static inline void TRNG_setMonobitRange (TRNG_TypeDef *trng, uint16_t count)
{
    MODIFY_REG(trng->SCML.WORDVAL, TRNG_SCML_MONORNG_M, ((uint32_t)count << TRNG_SCML_MONORNG_S) & TRNG_SCML_MONORNG_M);
}

/**
 * \brief  Set TRNG monobit maximum limit.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  count monobit maximum limit
 *                - This parameter can be one value range from 0 to 0xFFFF.
 */
static inline void TRNG_setMonobitMax (TRNG_TypeDef *trng, uint16_t count)
{
    MODIFY_REG(trng->SCML.WORDVAL, TRNG_SCML_MONOMAX_M, ((uint32_t)count << TRNG_SCML_MONOMAX_S) & TRNG_SCML_MONOMAX_M);
}

/**
 * \brief  Get TRNG runs of one, length 1 count.
 * \note   The count may be read through this register, if TRNG_MCTL[PRGM] bit is 0.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG runs of one, length 1 count
 *                - The value range from 0 to 0x7FFF.
 */
static inline uint32_t TRNG_getRun1Length1Count (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->SCR1C.WORDVAL, TRNG_SCR1C_R11CT_M) >> TRNG_SCR1C_R11CT_S;
}

/**
 * \brief  Get TRNG runs of zero, length 1 count.
 * \note   The count may be read through this register, if TRNG_MCTL[PRGM] bit is 0.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG runs of zero, length 1 count
 *                - The value range from 0 to 0x7FFF.
 */
static inline uint32_t TRNG_getRun0Length1Count (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->SCR1C.WORDVAL, TRNG_SCR1C_R10CT_M) >> TRNG_SCR1C_R10CT_S;
}

/**
 * \brief  Set TRNG run length 1 range.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  count run length 1 range
 *                - This parameter can be one value range from 0 to 0x7FFF.
 */
static inline void TRNG_setRunLength1Range (TRNG_TypeDef *trng, uint16_t count)
{
    MODIFY_REG(trng->SCR1L.WORDVAL, TRNG_SCR1L_RUN1RNG_M, ((uint32_t)count << TRNG_SCR1L_RUN1RNG_S) & TRNG_SCR1L_RUN1RNG_M);
}

/**
 * \brief  Set TRNG run length 1 maximum limit.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  count run length 1 maximum limit
 *                - This parameter can be one value range from 0 to 0x7FFF.
 */
static inline void TRNG_setRunLength1Max (TRNG_TypeDef *trng, uint16_t count)
{
    MODIFY_REG(trng->SCR1L.WORDVAL, TRNG_SCR1L_RUN1MAX_M, ((uint32_t)count << TRNG_SCR1L_RUN1MAX_S) & TRNG_SCR1L_RUN1MAX_M);
}

/**
 * \brief  Get TRNG runs of one, length 2 count.
 * \note   The count may be read through this register, if TRNG_MCTL[PRGM] bit is 0.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG runs of one, length 2 count
 *                - Thie value range from 0 to 0x3FFF.
 */
static inline uint32_t TRNG_getRun1Length2Count (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->SCR2C.WORDVAL, TRNG_SCR2C_R21CT_M) >> TRNG_SCR2C_R21CT_S;
}

/**
 * \brief  Get TRNG runs of zero, length 2 count.
 * \note   The count may be read through this register, if TRNG_MCTL[PRGM] bit is 0.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG runs of zero, length 2 count
 *                - The range from 0 to 0x3FFF.
 */
static inline uint32_t TRNG_getRun0Length2Count (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->SCR2C.WORDVAL, TRNG_SCR2C_R20CT_M) >> TRNG_SCR2C_R20CT_S;
}

/**
 * \brief  Set TRNG run length 2 range.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  count run length 2 range
 *                - This parameter can be one value range from 0 to 0x3FFF.
 */
static inline void TRNG_setRunLength2Range (TRNG_TypeDef *trng, uint16_t count)
{
    MODIFY_REG(trng->SCR2L.WORDVAL, TRNG_SCR2L_RUN2RNG_M, ((uint32_t)count << TRNG_SCR2L_RUN2RNG_S) & TRNG_SCR2L_RUN2RNG_M);
}

/**
 * \brief  Set TRNG run length 2 maximum limit.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  count run length 2 maximum limit
 *                - This parameter can be one value range from 0 to 0x3FFF.
 */
static inline void TRNG_setRunLength2Max (TRNG_TypeDef *trng, uint16_t count)
{
    MODIFY_REG(trng->SCR2L.WORDVAL, TRNG_SCR2L_RUN2MAX_M, ((uint32_t)count << TRNG_SCR2L_RUN2MAX_S) & TRNG_SCR2L_RUN2MAX_M);
}

/**
 * \brief  Get TRNG runs of one, length 3 count.
 * \note   The count may be read through this register, if TRNG_MCTL[PRGM] bit is 0.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG runs of one, length 3 count
 *                - The range from 0 to 0x1FFF.
 */
static inline uint32_t TRNG_getRun1Length3Count (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->SCR3C.WORDVAL, TRNG_SCR3C_R31CT_M) >> TRNG_SCR3C_R31CT_S;
}

/**
 * \brief  Get TRNG runs of zero, length 3 count.
 * \note   The count may be read through this register, if TRNG_MCTL[PRGM] bit is 0.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG runs of zero, length 3 count
 *                - The range from 0 to 0x1FFF.
 */
static inline uint32_t TRNG_getRun0Length3Count (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->SCR3C.WORDVAL, TRNG_SCR3C_R30CT_M) >> TRNG_SCR3C_R30CT_S;
}

/**
 * \brief  Set TRNG run length 3 range.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  count run length 3 range
 *                - This parameter can be one value range from 0 to 0x1FFF.
 */
static inline void TRNG_setRunLength3Range (TRNG_TypeDef *trng, uint16_t count)
{
    MODIFY_REG(trng->SCR3L.WORDVAL, TRNG_SCR3L_RUN3RNG_M, ((uint32_t)count << TRNG_SCR3L_RUN3RNG_S) & TRNG_SCR3L_RUN3RNG_M);
}

/**
 * \brief  Set TRNG run length 3 maximum limit.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  count run length 3 maximum limit
 *                - This parameter can be one value range from 0 to 0x1FFF.
 */
static inline void TRNG_setRunLength3Max (TRNG_TypeDef *trng, uint16_t count)
{
    MODIFY_REG(trng->SCR3L.WORDVAL, TRNG_SCR3L_RUN3MAX_M, ((uint32_t)count << TRNG_SCR3L_RUN3MAX_S) & TRNG_SCR3L_RUN3MAX_M);
}

/**
 * \brief  Get TRNG runs of one, length 4 count.
 * \note   The count may be read through this register, if TRNG_MCTL[PRGM] bit is 0.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG runs of one, length 4 count
 *                - The range from 0 to 0xFFF.
 */
static inline uint32_t TRNG_getRun1Length4Count (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->SCR4C.WORDVAL, TRNG_SCR4C_R41CT_M) >> TRNG_SCR4C_R41CT_S;
}

/**
 * \brief  Get TRNG runs of zero, length 4 count.
 * \note   The count may be read through this register, if TRNG_MCTL[PRGM] bit is 0.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG runs of zero, length 4 count
 *                - The value range from 0 to 0xFFF.
 */
static inline uint32_t TRNG_getRun0Length4Count (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->SCR4C.WORDVAL, TRNG_SCR4C_R40CT_M) >> TRNG_SCR4C_R40CT_S;
}

/**
 * \brief  Set TRNG run length 4 range.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  count run length 4 range
 *                - This parameter can be one value range from 0 to 0xFFF.
 */
static inline void TRNG_setRunLength4Range (TRNG_TypeDef *trng, uint16_t count)
{
    MODIFY_REG(trng->SCR4L.WORDVAL, TRNG_SCR4L_RUN4RNG_M, ((uint32_t)count << TRNG_SCR4L_RUN4RNG_S) & TRNG_SCR4L_RUN4RNG_M);
}

/**
 * \brief  Set TRNG run length 4 maximum limit.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  count run length 4 maximum limit
 *                - This parameter can be one value range from 0 to 0xFFF.
 */
static inline void TRNG_setRunLength4Max (TRNG_TypeDef *trng, uint16_t count)
{
    MODIFY_REG(trng->SCR4L.WORDVAL, TRNG_SCR4L_RUN4MAX_M, ((uint32_t)count << TRNG_SCR4L_RUN4MAX_S) & TRNG_SCR4L_RUN4MAX_M);
}

/**
 * \brief  Get TRNG runs of one, length 5 count.
 * \note   The count may be read through this register, if TRNG_MCTL[PRGM] bit is 0.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG runs of one, length 5 count
 *                - The value range from 0 to 0x7FF.
 */
static inline uint32_t TRNG_getRun1Length5Count (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->SCR5C.WORDVAL, TRNG_SCR5C_R51CT_M) >> TRNG_SCR5C_R51CT_S;
}

/**
 * \brief  Get TRNG runs of zero, length 5 count.
 * \note   The count may be read through this register, if TRNG_MCTL[PRGM] bit is 0.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG runs of zero, length 5 count
 *                - The value range from 0 to 0x7FF.
 */
static inline uint32_t TRNG_getRun0Length5Count (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->SCR5C.WORDVAL, TRNG_SCR5C_R50CT_M) >> TRNG_SCR5C_R50CT_S;
}

/**
 * \brief  Set TRNG run length 5 range.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  count run length 5 range
 *                - This parameter can be one value range from 0 to 0x7FF.
 */
static inline void TRNG_setRunLength5Range (TRNG_TypeDef *trng, uint16_t count)
{
    MODIFY_REG(trng->SCR5L.WORDVAL, TRNG_SCR5L_RUN5RNG_M, ((uint32_t)count << TRNG_SCR5L_RUN5RNG_S) & TRNG_SCR5L_RUN5RNG_M);
}

/**
 * \brief  Set TRNG run length 5 maximum limit.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  count run length 5 maximum limit
 *                - This parameter can be one value range from 0 to 0x7FF.
 */
static inline void TRNG_setRunLength5Max (TRNG_TypeDef *trng, uint16_t count)
{
    MODIFY_REG(trng->SCR5L.WORDVAL, TRNG_SCR5L_RUN5MAX_M, ((uint32_t)count << TRNG_SCR5L_RUN5MAX_S) & TRNG_SCR5L_RUN5MAX_M);
}

/**
 * \brief  Get TRNG runs of one, length 6+ count.
 * \note   The count may be read through this register, if TRNG_MCTL[PRGM] bit is 0.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG runs of one, length 6+ count
 *                - The value range from 0 to 0x7FF.
 */
static inline uint32_t TRNG_getRun1Length6PlusCount (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->SCR6PC.WORDVAL, TRNG_SCR6PC_R6P1CT_M) >> TRNG_SCR6PC_R6P1CT_S;
}

/**
 * \brief  Get TRNG runs of zero, length 6+ count.
 * \note   The count may be read through this register, if TRNG_MCTL[PRGM] bit is 0.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG runs of zero, length 6+ count
 *                - The value range from 0 to 0x7FF.
 */
static inline uint32_t TRNG_getRun0Length6PlusCount (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->SCR6PC.WORDVAL, TRNG_SCR6PC_R6P0CT_M) >> TRNG_SCR6PC_R6P0CT_S;
}

/**
 * \brief  Set TRNG run length 6+ range.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  count run length 6+ range
 *                - This parameter can be one value range from 0 to 0x7FF.
 */
static inline void TRNG_setRunLength6PlusRange (TRNG_TypeDef *trng, uint16_t count)
{
    MODIFY_REG(trng->SCR6PL.WORDVAL, TRNG_SCR6PL_RUN6PRNG_M, ((uint32_t)count << TRNG_SCR6PL_RUN6PRNG_S) & TRNG_SCR6PL_RUN6PRNG_M);
}

/**
 * \brief  Set TRNG run length 6+ maximum limit.
 * \note   This field is writable only if TRNG_MCTL[PRGM] bit is 1.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \param  count run length 6+ maximum limit
 *                - This parameter can be one value range from 0 to 0x7FF.
 */
static inline void TRNG_setRunLength6PlusMax (TRNG_TypeDef *trng, uint16_t count)
{
    MODIFY_REG(trng->SCR6PL.WORDVAL, TRNG_SCR6PL_RUN6PMAX_M, ((uint32_t)count << TRNG_SCR6PL_RUN6PMAX_S) & TRNG_SCR6PL_RUN6PMAX_M);
}

/**
 * \brief  Get TRNG retry count.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG retry count
 *                - The value range from 0 to 0xF.
 */
static inline uint32_t TRNG_getRetryCount (TRNG_TypeDef *trng)
{
    return READ_BIT(trng->STATUS.WORDVAL, TRNG_STATUS_RETRYCT_M) >> TRNG_STATUS_RETRYCT_S;
}

/**
 * \brief  Get TRNG test result.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG test result
 *                This parameter can be one or more value of @ref TRNG_TEST_RESULT
 */
static inline uint32_t TRNG_getTestResult(TRNG_TypeDef *trng)
{
    return READ_BIT(trng->STATUS.WORDVAL, TRNG_STATUS_TEST_RESULT_M);
}

/**
 * \brief  Get TRNG entropy value.
 * \param  trng   pointer to a TRNG_TypeDef structure
 *                 - TRNG: TRNG base address
 * \param  index  one value of @ref TRNG_ENTROPYINDEX
 * \return Returns the TRNG entropy value
 *                 - The value range from 0 to 0xFFFFFFFF.
 */
static inline uint32_t TRNG_getEntropyValue (TRNG_TypeDef *trng, TRNG_EntropyIndex index)
{
    return (uint32_t)(trng->ENTX[index].WORDVAL);
}

/**
 * \brief  Get TRNG poker count
 * \param  trng   pointer to a TRNG_TypeDef structure
 *                 - TRNG: TRNG base address
 * \param  count  count type
 * \return Returns the TRNG poker count value
 *                 - The value range from 0 to 0xFFFF.
 */
static inline uint32_t TRNG_getPokerCount (TRNG_TypeDef *trng, TRNG_PokerCountType count)
{
    uint32_t val;
    __IO uint32_t *addrPkrcnt;

    addrPkrcnt = (uint32_t *)(&(trng->PKRCNT10) + (count >> 1));
    val = READ_BIT(*addrPkrcnt >> (TRNG_PKRCNT_PKR_HI_CT_S * (count & 0x1UL)), TRNG_PKRCNT_PKR_LOW_CT_M);

    return val;
}

/**
 * \brief  enable TRNG register program.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 */
static inline void TRNG_enableRegisterProgram (TRNG_TypeDef *trng)
{
    CLEAR_BIT(trng->SECCFG.WORDVAL, TRNG_SECCFG_NOPRGM_M);
}

/**
 * \brief  disable TRNG register program.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 */
static inline void TRNG_disableRegisterProgram (TRNG_TypeDef *trng)
{
    SET_BIT(trng->SECCFG.WORDVAL, TRNG_SECCFG_NOPRGM_M);
}

/**
 * \brief  enable TRNG interrupt.
 * \param  trng     pointer to a TRNG_TypeDef structure
 *                   - TRNG: TRNG base address
 * \param  intflag  enable TRNG interrupt
 *                   This parameter can be one or more value of @ref TRNG_INT
 */
static inline void TRNG_enableInterruptSource (TRNG_TypeDef *trng, uint32_t intflag)
{
    SET_BIT(trng->INTMASK.WORDVAL, (intflag & TRNG_INT_MASK_M));
}

/**
 * \brief  disable TRNG interrupt.
 * \param  trng     pointer to a TRNG_TypeDef structure
 *                   - TRNG: TRNG base address
 * \param  intflag  disable TRNG interrupt
 *                   This parameter can be one or more value of @ref TRNG_INT
 */
static inline void TRNG_disableInterruptSource (TRNG_TypeDef *trng, uint32_t intflag)
{
    CLEAR_BIT(trng->INTMASK.WORDVAL, (intflag & TRNG_INT_MASK_M));
}

/**
 * \brief  clear TRNG interrupt status.
 * \param  trng     pointer to a TRNG_TypeDef structure
 *                   - TRNG: TRNG base address
 * \param  intflag  clear TRNG interrupt
 *                   This parameter can be one or more value of @ref TRNG_INT
 */
static inline void TRNG_clearInterruptStatus (TRNG_TypeDef *trng, uint32_t intflag)
{
    CLEAR_BIT(trng->INTCTRL.WORDVAL, (intflag & TRNG_INT_CTRL_M));
}

/**
 * \brief  Get TRNG interrupt status.
 * \param  trng  pointer to a TRNG_TypeDef structure
 *                - TRNG: TRNG base address
 * \return Returns the TRNG interrupt status.
 *                This parameter can be one or more value of @ref TRNG_INT
 */
static inline uint32_t TRNG_getInterruptStatus (TRNG_TypeDef *trng)
{
    return (READ_REG(trng->INTSTATUS.WORDVAL) & TRNG_INT_STATUS_M);
}


#ifdef __cplusplus
}
#endif


#endif /* __TRNG_H__ */
