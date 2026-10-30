/**
  * @file       eqep.h
  * @author     Alex-J
  * @brief      Header file for NS800RT7xxx eqep module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __EQEP_H__
#define __EQEP_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_eqep.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/** @defgroup EQEP_EXPORTED_TYPES EQEP Exported Types
 * @{
 * @brief  Macro definitions are used with all files publicly about 'EQEP' module.
 */

/** @defgroup EQEP_QDECCTL_REGBIT EQEP QDECCTL register bits
 * @{
 * @brief  Macro definitions about EQEP QDECCTL register bits definition.
 */
#define EQEP_QDECCTL_QIDIRE    (0x1UL)       /*!< Qep Index Direction Enhancement enable */
#define EQEP_QDECCTL_QSP       (0x20UL)      /*!< QEPS input polarity */
#define EQEP_QDECCTL_QIP       (0x40UL)      /*!< QEPI input polarity */
#define EQEP_QDECCTL_QBP       (0x80UL)      /*!< QEPB input polarity */
#define EQEP_QDECCTL_QAP       (0x100UL)     /*!< QEPA input polarity */
#define EQEP_QDECCTL_IGATE     (0x200UL)     /*!< Index pulse gating option */
#define EQEP_QDECCTL_SWAP      (0x400UL)     /*!< CLK/DIR Signal Source for Position Counter */
#define EQEP_QDECCTL_XCR       (0x800UL)     /*!< External Clock Rate */
#define EQEP_QDECCTL_SPSEL     (0x1000UL)    /*!< Sync output pin selection */
#define EQEP_QDECCTL_SOEN      (0x2000UL)    /*!< Sync output-enable */

/**
 * @}
 */

/** @defgroup EQEP_QEPCTL_REGBIT EQEP QEPCTL register bits
 * @{
 * @brief  Macro definitions about EQEP QEPCTL register bits definition.
 */
#define EQEP_QEPCTL_WDE            (0x1UL)       /*!< QEP watchdog enable */
#define EQEP_QEPCTL_UTE            (0x2UL)       /*!< QEP unit timer enable */
#define EQEP_QEPCTL_QCLM           (0x4UL)       /*!< QEP capture latch mode */
#define EQEP_QEPCTL_QPEN           (0x8UL)       /*!< Quadrature postotion counter enable */
#define EQEP_QEPCTL_SEL            (0x40UL)      /*!< Strobe event latch */
#define EQEP_QEPCTL_SWI            (0x80UL)      /*!< Software init position counter */

/**
 * @}
 */

/** @defgroup EQEP_QCAPCTL_REGBIT EQEP QCAPCTL register bits
 * @{
 * @brief  Macro definitions about EQEP QCAPCTL register bits definition.
 */
#define EQEP_QCAPCTL_CEN       (0x8000UL)    /*!< Enable eQEP capture */

/**
 * @}
 */

/** @defgroup EQEP_QPOSCTL_REGBIT EQEP QPOSCTL register bits
 * @{
 * @brief  Macro definitions about EQEP QPOSCTL register bits definition.
 */
#define EQEP_QPOSCTL_PCE        (0x1000UL)    /*!< Position compare enable/disable */
#define EQEP_QPOSCTL_PCPOL      (0x2000UL)    /*!< Polarity of sync output */
#define EQEP_QPOSCTL_PCLOAD     (0x4000UL)    /*!< Position compare of shadow load */
#define EQEP_QPOSCTL_PCSHDW     (0x8000UL)    /*!< Position compare of shadow enable */

/**
 * @}
 */

/** @defgroup EQEP_QEINT_REGBIT EQEP QEINT register bits
 * @{
 * @brief  Macro definitions about EQEP QEINT register bits definition.
 */
#define EQEP_QEINT_PCE     (0x2UL)       /*!< Position counter error interrupt enable */
#define EQEP_QEINT_QPE     (0x4UL)       /*!< Quadrature phase error interrupt enable */
#define EQEP_QEINT_QDC     (0x8UL)       /*!< Quadrature direction change interrupt enable */
#define EQEP_QEINT_WTO     (0x10UL)      /*!< Watchdog time out interrupt enable */
#define EQEP_QEINT_PCU     (0x20UL)      /*!< Position counter underflow interrupt enable */
#define EQEP_QEINT_PCO     (0x40UL)      /*!< Position counter overflow interrupt enable */
#define EQEP_QEINT_PCR     (0x80UL)      /*!< Position-compare ready interrupt enable */
#define EQEP_QEINT_PCM     (0x100UL)     /*!< Position-compare match interrupt enable */
#define EQEP_QEINT_SEL     (0x200UL)     /*!< Strobe event latch interrupt enable */
#define EQEP_QEINT_IEL     (0x400UL)     /*!< Index event latch interrupt enable */
#define EQEP_QEINT_UTO     (0x800UL)     /*!< Unit time out interrupt enable */
#define EQEP_QEINT_QMAE    (0x1000UL)    /*!< QMA error interrupt enable */

/**
 * @}
 */

/** @defgroup EQEP_QEINT_REGBIT EQEP QEINT register bits
 * @{
 * @brief  Macro definitions about EQEP QEINT register bits definition.
 */
#define EQEP_QEINT_PCE     (0x2UL)       /*!< Position counter error interrupt enable */
#define EQEP_QEINT_QPE     (0x4UL)       /*!< Quadrature phase error interrupt enable */
#define EQEP_QEINT_QDC     (0x8UL)       /*!< Quadrature direction change interrupt enable */
#define EQEP_QEINT_WTO     (0x10UL)      /*!< Watchdog time out interrupt enable */
#define EQEP_QEINT_PCU     (0x20UL)      /*!< Position counter underflow interrupt enable */
#define EQEP_QEINT_PCO     (0x40UL)      /*!< Position counter overflow interrupt enable */
#define EQEP_QEINT_PCR     (0x80UL)      /*!< Position-compare ready interrupt enable */
#define EQEP_QEINT_PCM     (0x100UL)     /*!< Position-compare match interrupt enable */
#define EQEP_QEINT_SEL     (0x200UL)     /*!< Strobe event latch interrupt enable */
#define EQEP_QEINT_IEL     (0x400UL)     /*!< Index event latch interrupt enable */
#define EQEP_QEINT_UTO     (0x800UL)     /*!< Unit time out interrupt enable */
#define EQEP_QEINT_QMAE    (0x1000UL)    /*!< QMA error interrupt enable */

/**
 * @}
 */

/** @defgroup EQEP_QFLG_REGBIT EQEP QFLG register bits
 * @{
 * @brief  Macro definitions about EQEP QFLG register bits definition.
 */
#define EQEP_QFLG_INT     (0x1UL)       /*!< Global interrupt status flag */
#define EQEP_QFLG_PCE     (0x2UL)       /*!< Position counter error interrupt flag */
#define EQEP_QFLG_PHE     (0x4UL)       /*!< Quadrature phase error interrupt flag */
#define EQEP_QFLG_QDC     (0x8UL)       /*!< Quadrature direction change interrupt flag */
#define EQEP_QFLG_WTO     (0x10UL)      /*!< Watchdog timeout interrupt flag */
#define EQEP_QFLG_PCU     (0x20UL)      /*!< Position counter underflow interrupt flag */
#define EQEP_QFLG_PCO     (0x40UL)      /*!< Position counter overflow interrupt flag */
#define EQEP_QFLG_PCR     (0x80UL)      /*!< Position-compare ready interrupt flag */
#define EQEP_QFLG_PCM     (0x100UL)     /*!< eQEP compare match event interrupt flag */
#define EQEP_QFLG_SEL     (0x200UL)     /*!< Strobe event latch interrupt flag */
#define EQEP_QFLG_IEL     (0x400UL)     /*!< Index event latch interrupt flag */
#define EQEP_QFLG_UTO     (0x800UL)     /*!< Unit time out interrupt flag */
#define EQEP_QFLG_QMAE    (0x1000UL)    /*!< QMA error interrupt flag */

/**
 * @}
 */

/** @defgroup EQEP_QCLR_REGBIT EQEP QCLR register bits
 * @{
 * @brief  Macro definitions about EQEP QCLR register bits definition.
 */
#define EQEP_QCLR_INT     (0x1UL)       /*!< Global interrupt clear flag */
#define EQEP_QCLR_PCE     (0x2UL)       /*!< Clear position counter error interrupt flag */
#define EQEP_QCLR_PHE     (0x4UL)       /*!< Clear quadrature phase error interrupt flag */
#define EQEP_QCLR_QDC     (0x8UL)       /*!< Clear quadrature direction change interrupt flag */
#define EQEP_QCLR_WTO     (0x10UL)      /*!< Clear watchdog timeout interrupt flag */
#define EQEP_QCLR_PCU     (0x20UL)      /*!< Clear position counter underflow interrupt flag */
#define EQEP_QCLR_PCO     (0x40UL)      /*!< Clear position counter overflow interrupt flag */
#define EQEP_QCLR_PCR     (0x80UL)      /*!< Clear position-compare ready interrupt flag */
#define EQEP_QCLR_PCM     (0x100UL)     /*!< Clear eQEP compare match event interrupt flag */
#define EQEP_QCLR_SEL     (0x200UL)     /*!< Clear strobe event latch interrupt flag */
#define EQEP_QCLR_IEL     (0x400UL)     /*!< Clear index event latch interrupt flag */
#define EQEP_QCLR_UTO     (0x800UL)     /*!< Clear unit time out interrupt flag */
#define EQEP_QCLR_QMAE    (0x1000UL)    /*!< Clear QMA error interrupt flag */

/**
 * @}
 */

/** @defgroup EQEP_QFRC_REGBIT EQEP QFRC register bits
 * @{
 * @brief  Macro definitions about EQEP QFRC register bits definition.
 */
#define EQEP_QFRC_PCE     (0x2UL)       /*!< Force position counter error interrupt */
#define EQEP_QFRC_PHE     (0x4UL)       /*!< Force quadrature phase error interrupt */
#define EQEP_QFRC_QDC     (0x8UL)       /*!< Force quadrature direction change interrupt */
#define EQEP_QFRC_WTO     (0x10UL)      /*!< Force watchdog time out interrupt */
#define EQEP_QFRC_PCU     (0x20UL)      /*!< Force position counter underflow interrupt */
#define EQEP_QFRC_PCO     (0x40UL)      /*!< Force position counter overflow interrupt */
#define EQEP_QFRC_PCR     (0x80UL)      /*!< Force position-compare ready interrupt */
#define EQEP_QFRC_PCM     (0x100UL)     /*!< Force position-compare match interrupt */
#define EQEP_QFRC_SEL     (0x200UL)     /*!< Force strobe event latch interrupt */
#define EQEP_QFRC_IEL     (0x400UL)     /*!< Force index event latch interrupt */
#define EQEP_QFRC_UTO     (0x800UL)     /*!< Force unit time out interrupt */
#define EQEP_QFRC_QMAE    (0x1000UL)    /*!< Force QMA error interrupt */

/**
 * @}
 */

/** @defgroup EQEP_QEPSTS_REGBIT EQEP QEPSTS register bits
 * @{
 * @brief  Macro definitions about EQEP QEPSTS register bits definition.
 */
#define EQEP_QEPSTS_PCEF      (0x1UL)     /*!< Position counter error flag. */
#define EQEP_QEPSTS_FIMF      (0x2UL)     /*!< First index marker flag */
#define EQEP_QEPSTS_CDEF      (0x4UL)     /*!< Capture direction error flag */
#define EQEP_QEPSTS_COEF      (0x8UL)     /*!< Capture overflow error flag */
#define EQEP_QEPSTS_QDLF      (0x10UL)    /*!< eQEP direction latch flag */
#define EQEP_QEPSTS_QDF       (0x20UL)    /*!< Quadrature direction flag */
#define EQEP_QEPSTS_FIDF      (0x40UL)    /*!< The first index marker */
#define EQEP_QEPSTS_UPEVNT    (0x80UL)    /*!< Unit position event flag */

/**
 * @}
 */

/** @defgroup EQEP_INT_REGBIT EQEP Interrupt Register Bits
 * @{
 * @brief  Values that can be passed to EQEP_enableInterrupt(),
 *         EQEP_disableInterrupt(), and EQEP_clearInterruptStatus() as the
 *         intFlags parameter and returned by EQEP_getInterruptStatus().
 * 
 * @note   The following macro definition needs to be shifted left by 
 *         1bit(<< 1) when used in EQEP_clearInterruptStatus() and 
 *         EQEP_getInterruptStatus().
 */
#define EQEP_INT_POS_CNT_ERROR        (0x0001UL)    /*!< Position counter error */
#define EQEP_INT_PHASE_ERROR          (0x0002UL)    /*!< Quadrature phase error */
#define EQEP_INT_DIR_CHANGE           (0x0004UL)    /*!< Quadrature direction change */
#define EQEP_INT_WATCHDOG             (0x0008UL)    /*!< Watchdog time-out */
#define EQEP_INT_UNDERFLOW            (0x0010UL)    /*!< Position counter underflow */
#define EQEP_INT_OVERFLOW             (0x0020UL)    /*!< Position counter overflow */
#define EQEP_INT_POS_COMP_READY       (0x0040UL)    /*!< Position-compare ready */
#define EQEP_INT_POS_COMP_MATCH       (0x0080UL)    /*!< Position-compare match */
#define EQEP_INT_STROBE_EVNT_LATCH    (0x0100UL)    /*!< Strobe event latch */
#define EQEP_INT_INDEX_EVNT_LATCH     (0x0200UL)    /*!< Index event latch */
#define EQEP_INT_UNIT_TIME_OUT        (0x0400UL)    /*!< Unit time-out */
#define EQEP_INT_QMA_ERROR            (0x0800UL)    /*!< QMA error */

/**
 * @}
 */

/** @defgroup EQEP_STS_REGBIT EQEP Status Register Bits
 * @{
 * @brief  Values that can be returned by EQEP_getStatus().
 */
#define EQEP_STS_UNIT_POS_EVNT       (0x0080UL)    /*!< Unit position event detected */
#define EQEP_STS_DIR_ON_1ST_IDX      (0x0040UL)    /*!< Direction was clockwise on first index event */
#define EQEP_STS_DIR_FLAG            (0x0020UL)    /*!< Direction is CW (forward) */
#define EQEP_STS_DIR_LATCH           (0x0010UL)    /*!< Direction was CW on index */
#define EQEP_STS_CAP_OVRFLW_ERROR    (0x0008UL)    /*!< Capture timer overflow */
#define EQEP_STS_CAP_DIR_ERROR       (0x0004UL)    /*!< Direction changed between position capture events */
#define EQEP_STS_1ST_IDX_FLAG        (0x0002UL)    /*!< First index pulse occurred */
#define EQEP_STS_POS_CNT_ERROR       (0x0001UL)    /*!< Position counter error */

/**
 * @}
 */

/** @defgroup EQEP_CFG_PARAMETER EQEP Config Parameter
 * @{
 * @brief  Values that can be passed to EQEP_setDecoderConfig() as the config
 *         parameter.
 */
/* Operation Mode */
#define EQEP_CONFIG_QUADRATURE       (0x0000UL)    /*!< Quadrature-clock mode */
#define EQEP_CONFIG_CLOCK_DIR        (0x4000UL)    /*!< Direction-count mode */
#define EQEP_CONFIG_UP_COUNT         (0x8000UL)    /*!< Up-count mode, QDIR = 1 */
#define EQEP_CONFIG_DOWN_COUNT       (0xC000UL)    /*!< Down-count mode, QDIR = 0 */
/* Resolution */
#define EQEP_CONFIG_2X_RESOLUTION    (0x0000UL)    /*!< Count rising and falling edge */
#define EQEP_CONFIG_1X_RESOLUTION    (0x0800UL)    /*!< Count rising edge only */
/* Swap QEPA and QEPB */
#define EQEP_CONFIG_NO_SWAP          (0x0000UL)    /*!< Do not swap QEPA and QEPB */
#define EQEP_CONFIG_SWAP             (0x0400UL)    /*!< Swap QEPA and QEPB */
/* Index pulse gating option */
#define EQEP_CONFIG_IGATE_DISABLE    (0x0000UL)    /*!< Disable gating of Index pulse */
#define EQEP_CONFIG_IGATE_ENABLE     (0x0200UL)    /*!< Gate the index pin with strobe */

/**
 * @}
 */

/** @defgroup EQEP_COMPARE_PARAMETER EQEP Compare Parameter
 * @{
 * @brief  Values that can be passed to EQEP_setCompareConfig() as the config
 *         parameter.
 */
/* Sync pulse pin */
#define EQEP_COMPARE_NO_SYNC_OUT      (0x0000UL)    /*!< Disable sync output */
#define EQEP_COMPARE_IDX_SYNC_OUT     (0x2000UL)    /*!< Sync output on index pin */
#define EQEP_COMPARE_STROBE_SYNC_OUT  (0x3000UL)    /*!< Sync output on strobe pin */
/* Shadow register use */
#define EQEP_COMPARE_NO_SHADOW        (0x0000UL)    /*!< Disable shadow of QPOSCMP */
#define EQEP_COMPARE_LOAD_ON_ZERO     (0x8000UL)    /*!< Load on QPOSCNT = 0 */
#define EQEP_COMPARE_LOAD_ON_MATCH    (0xC000UL)    /*!< Load on QPOSCNT = QPOSCMP */

/**
 * @}
 */

/** @defgroup EQEP_LATCHMODE_PARAMETER EQEP Latch Mode Parameter
 * @{
 * @brief  Values that can be passed to EQEP_setLatchMode() as the latchMode parameter.
 */
/* Position counter latch event */
#define EQEP_LATCH_CNT_READ_BY_CPU    (0x0000UL)    /*!< On position counter read */
#define EQEP_LATCH_UNIT_TIME_OUT      (0x0004UL)    /*!< On unit time-out event */
/* Strobe position counter latch event */
#define EQEP_LATCH_RISING_STROBE      (0x0000UL)    /*!< On rising edge of strobe */
#define EQEP_LATCH_EDGE_DIR_STROBE    (0x0040UL)    /*!< On rising edge when clockwise, on falling when counter clockwise */
/* Index position counter latch event */
#define EQEP_LATCH_RISING_INDEX       (0x0010UL)    /*!< On rising edge of index */
#define EQEP_LATCH_FALLING_INDEX      (0x0020UL)    /*!< On falling edge of index */
#define EQEP_LATCH_SW_INDEX_MARKER    (0x0030UL)    /*!< On software index marker */

/**
 * @}
 */

/** @defgroup EQEP_IINTMODE_PARAMETER EQEP Init Mode Parameter
 * @{
 * @brief  Values that can be passed to EQEP_setPositionInitMode() as the initMode
 *         parameter.
 */
#define EQEP_INIT_DO_NOTHING         (0x0000UL)    /*!< Action is disabled */
/* Strobe events */
#define EQEP_INIT_RISING_STROBE      (0x0800UL)    /*!< On rising edge of strobe */
#define EQEP_INIT_EDGE_DIR_STROBE    (0x0C00UL)    /*!< On rising edge when clockwise, on falling when counter clockwise */
/* Index events */
#define EQEP_INIT_RISING_INDEX       (0x0200UL)    /*!< On rising edge of index */
#define EQEP_INIT_FALLING_INDEX      (0x0300UL)    /*!< On falling edge of index */

/**
 * @}
 */

/** @defgroup EQEP_POSITIONRESETMODE EQEP Position Reset Mode Parameter
 * @{
 * @brief  Values that can be passed to EQEP_setPositionCounterConfig() as the \e mode parameter.
 */
typedef enum {
    EQEP_POSITION_RESET_IDX           = 0x0000U,    /*!< Reset position on index pulse */
    EQEP_POSITION_RESET_MAX_POS       = 0x1000U,    /*!< Reset position on maximum position */
    EQEP_POSITION_RESET_1ST_IDX       = 0x2000U,    /*!< Reset position on the first index pulse */
    EQEP_POSITION_RESET_UNIT_TIME_OUT = 0x3000U     /*!< Reset position on a unit time event */
} EQEP_PositionResetMode;

/**
 * @}
 */

/** @defgroup EQEP_CAPCLKPRESCALE EQEP Capture timer Clock freq Prescale Parameter
 * @{
 * @brief  Values that can be passed to EQEP_setCaptureConfig() as the \e capPrescale parameter.
 */
typedef enum {
    EQEP_CAPTURE_CLK_DIV_1   = 0x00U,    /*!< CAPCLK = SYSCLKOUT/1 */
    EQEP_CAPTURE_CLK_DIV_2   = 0x10U,    /*!< CAPCLK = SYSCLKOUT/2 */
    EQEP_CAPTURE_CLK_DIV_4   = 0x20U,    /*!< CAPCLK = SYSCLKOUT/4 */
    EQEP_CAPTURE_CLK_DIV_8   = 0x30U,    /*!< CAPCLK = SYSCLKOUT/8 */
    EQEP_CAPTURE_CLK_DIV_16  = 0x40U,    /*!< CAPCLK = SYSCLKOUT/16 */
    EQEP_CAPTURE_CLK_DIV_32  = 0x50U,    /*!< CAPCLK = SYSCLKOUT/32 */
    EQEP_CAPTURE_CLK_DIV_64  = 0x60U,    /*!< CAPCLK = SYSCLKOUT/64 */
    EQEP_CAPTURE_CLK_DIV_128 = 0x70U     /*!< CAPCLK = SYSCLKOUT/128 */
} EQEP_CAPCLKPrescale;

/**
 * @}
 */

/** @defgroup EQEP_UPEVNTPRESCALE EQEP Unit Position Event freq Prescale Parameter
 * @{
 * @brief  Values that can be passed to EQEP_setCaptureConfig() as the \e evntPrescale parameter.
 */
typedef enum {
    EQEP_UNIT_POS_EVNT_DIV_1 = 0U,    /*!< UPEVNT = QCLK/1 */
    EQEP_UNIT_POS_EVNT_DIV_2,         /*!< UPEVNT = QCLK/2 */
    EQEP_UNIT_POS_EVNT_DIV_4,         /*!< UPEVNT = QCLK/4 */
    EQEP_UNIT_POS_EVNT_DIV_8,         /*!< UPEVNT = QCLK/8 */
    EQEP_UNIT_POS_EVNT_DIV_16,        /*!< UPEVNT = QCLK/16 */
    EQEP_UNIT_POS_EVNT_DIV_32,        /*!< UPEVNT = QCLK/32 */
    EQEP_UNIT_POS_EVNT_DIV_64,        /*!< UPEVNT = QCLK/64 */
    EQEP_UNIT_POS_EVNT_DIV_128,       /*!< UPEVNT = QCLK/128 */
    EQEP_UNIT_POS_EVNT_DIV_256,       /*!< UPEVNT = QCLK/256 */
    EQEP_UNIT_POS_EVNT_DIV_512,       /*!< UPEVNT = QCLK/512 */
    EQEP_UNIT_POS_EVNT_DIV_1024,      /*!< UPEVNT = QCLK/1024 */
    EQEP_UNIT_POS_EVNT_DIV_2048       /*!< UPEVNT = QCLK/2048 */
} EQEP_UPEVNTPrescale;

/**
 * @}
 */

/** @defgroup EQEP_STROBESOURCE EQEP Strobe Source Parameter
 * @{
 * @brief  Values that can be passed to EQEP_setStrobeSource() as the \e strobeSrc parameter.
 */
typedef enum {
    EQEP_STROBE_FROM_GPIO  = 0U,    /*!< GPIO */
    EQEP_STROBE_OR_ADCSOCA = 2U,    /*!< Strobe signal OR'd with ADCSOCA */
    EQEP_STROBE_OR_ADCSOCB = 3U     /*!< Strobe signal OR'd with ADCSOCB */
} EQEP_StrobeSource;

/**
 * @}
 */

/** @defgroup EQEP_QMAMODE EQEP QMA Mode Parameter
 * @{
 * @brief  Values that can be passed to EQEP_setQMAModuleMode() as the \e qmaMode parameter.
 */
typedef enum {
    EQEP_QMA_MODE_BYPASS = 0U,    /*!< QMA module is bypassed */
    EQEP_QMA_MODE_1,              /*!< QMA mode-1 operation */
    EQEP_QMA_MODE_2               /*!< QMA mode-2 operation */
} EQEP_QMAMode;

/**
 * @}
 */

/** @defgroup EQEP_SOURCE EQEP Source Parameter
 * @{
 * @brief  Possible values of sources for QEPA,QEPB and Index signal which are passed
 *         as a structure to EQEP_selectSource() as \e sourceConfig.
 */
typedef enum {
    EQEP_SOURCE_DEVICE_PIN = 0x0000U,    /*!< Device Pin */
    EQEP_SOURCE_CMPSS1     = 0x0001U,    /*!< CMPSS1 */
    EQEP_SOURCE_CMPSS2     = 0x0002U,    /*!< CMPSS2 */
    EQEP_SOURCE_CMPSS3     = 0x0003U,    /*!< CMPSS3 */
    EQEP_SOURCE_CMPSS4     = 0x0004U,    /*!< CMPSS4 */
    EQEP_SOURCE_ZERO       = 0x0008U,    /*!< Tie to zero */
    EQEP_SOURCE_PWMXBAR1   = 0x0009U,    /*!< PWMXBAR1 */
    EQEP_SOURCE_PWMXBAR2   = 0x000AU,    /*!< PWMXBAR2 */
    EQEP_SOURCE_PWMXBAR3   = 0x000BU,    /*!< PWMXBAR3 */
    EQEP_SOURCE_PWMXBAR4   = 0x000CU,    /*!< PWMXBAR4 */
    EQEP_SOURCE_PWMXBAR5   = 0x000DU,    /*!< PWMXBAR5 */
    EQEP_SOURCE_PWMXBAR6   = 0x000EU,    /*!< PWMXBAR6 */
    EQEP_SOURCE_PWMXBAR7   = 0x000FU     /*!< PWMXBAR7 */
} EQEP_Source;

/**
 * @}
 */

/** @defgroup EQEP_EMULATIONMODE EQEP Emulation Mode Parameter
 * @{
 * @brief  Values that can be passed to EQEP_setEmulationMode() as the \e emuMode
 *         parameter.
 */
typedef enum {
    EQEP_EMULATIONMODE_STOPIMMEDIATELY = 0U,    /*!< Counters stop immediately */
    EQEP_EMULATIONMODE_STOPATROLLOVER,          /*!< Counters stop at period rollover */
    EQEP_EMULATIONMODE_RUNFREE                  /*!< Counter unaffected by suspend */
} EQEP_EmulationMode;

/**
 * @}
 */

/** @defgroup EQEP_SOURCESELECT EQEP Source Select Structure
 * @{
 * @brief  Structure to be passed to EQEP_selectSource() as \e sourceConfig.
 */
typedef struct {
    EQEP_Source sourceA;
    EQEP_Source sourceB;
    EQEP_Source sourceIndex;
} EQEP_SourceSelect;

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
 * \brief  Enable the eQEP module.
 * \note   This function enables operation of the enhanced quadrature encoder pulse
 *         (eQEP) module.  The module must be configured before it is enabled.
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 */
static inline void EQEP_enableModule (EQEP_TypeDef *eqep)
{
    SET_BIT(eqep->QEPCTL.WORDVAL, EQEP_QEPCTL_QPEN);
}

/**
 * \brief  Disable the eQEP module.
 * \note   This function disables operation of the eQEP module.
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 */
static inline void EQEP_disableModule (EQEP_TypeDef *eqep)
{
    CLEAR_BIT(eqep->QEPCTL.WORDVAL, EQEP_QEPCTL_QPEN);
}

/**
 * \brief  Configures eQEP module's quadrature decoder unit.
 * \note   This function configures the operation of the eQEP module's quadrature
 *         decoder unit.
 * \param  eqep    eqep pointer to a EQEP_TypeDef structure
 *                   - EQEP1: eQEP1 base address index
 *                   - EQEP2: eQEP2 base address index
 *                   - EQEP3: eQEP2 base address index
 *                   - EQEP4: eQEP2 base address index
 *                   - EQEP5: eQEP2 base address index
 *                   - EQEP6: eQEP2 base address index
 * \param  config  the configuration for the eQEP module decoder unit.
 *
 */
static inline void EQEP_setDecoderConfig (EQEP_TypeDef *eqep, uint16_t config)
{
    MODIFY_REG(eqep->QDECCTL.WORDVAL, ~((uint16_t)EQEP_QDECCTL_QIDIRE), config);
}

/**
 * \brief  Configures eQEP module position counter unit.
 * \note   This function configures the operation of the eQEP module position
 *         counter.
 * \param  eqep         eqep pointer to a EQEP_TypeDef structure
 *                        - EQEP1: eQEP1 base address index
 *                        - EQEP2: eQEP2 base address index
 *                        - EQEP3: eQEP2 base address index
 *                        - EQEP4: eQEP2 base address index
 *                        - EQEP5: eQEP2 base address index
 *                        - EQEP6: eQEP2 base address index
 * \param  mode         the configuration for the eQEP module decoder unit.
 * \param  maxPosition  specifies the maximum position value.
 *
 */
static inline void EQEP_setPositionCounterConfig (EQEP_TypeDef *eqep, EQEP_PositionResetMode mode,
                                                  uint32_t maxPosition)
{
    MODIFY_REG(eqep->QEPCTL.WORDVAL, EQEP_QEPCTL_PCRM_M, (uint16_t)mode);

    WRITE_REG(eqep->QPOSMAX.WORDVAL, maxPosition);
}

/**
 * \brief  Configures eQEP module position-compare value.
 * \note   This function configures the operation of the eQEP module
 *         position-compare value.
 * \param  eqep        eqep pointer to a EQEP_TypeDef structure
 *                       - EQEP1: eQEP1 base address index
 *                       - EQEP2: eQEP2 base address index
 *                       - EQEP3: eQEP2 base address index
 *                       - EQEP4: eQEP2 base address index
 *                       - EQEP5: eQEP2 base address index
 *                       - EQEP6: eQEP2 base address index
 * \param  posCompare  specifies the position-compare value.
 *
 */
static inline void EQEP_setPositionCompareConfig (EQEP_TypeDef *eqep, uint32_t posCompare)
{
    WRITE_REG(eqep->QPOSCMP.WORDVAL, posCompare);
}

/**
 * \brief  Gets the current encoder position.
 * \note   This function returns the current position of the encoder.  Depending upon
 *         the configuration of the encoder, and the incident of an index pulse, this
 *         value may or may not contain the expected data (that is, if in reset on
 *         index mode, if an index pulse has not been encountered, the position
 *         counter is not yet aligned with the index pulse).
 *
 * \param  eqep   eqep pointer to a EQEP_TypeDef structure
 *                  - EQEP1: eQEP1 base address index
 *                  - EQEP2: eQEP2 base address index
 *                  - EQEP3: eQEP2 base address index
 *                  - EQEP4: eQEP2 base address index
 *                  - EQEP5: eQEP2 base address index
 *                  - EQEP6: eQEP2 base address index
 *
 * \return The current position of the encoder.
 */
static inline uint32_t EQEP_getPosition (EQEP_TypeDef *eqep)
{
    return (eqep->QPOSCNT.WORDVAL);
}

/**
 * \brief  Sets the current encoder position.
 * \note   This function sets the current position of the encoder; the encoder
 *         position is then measured relative to this value.
 *
 * \param  eqep      eqep pointer to a EQEP_TypeDef structure
 *                     - EQEP1: eQEP1 base address index
 *                     - EQEP2: eQEP2 base address index
 *                     - EQEP3: eQEP2 base address index
 *                     - EQEP4: eQEP2 base address index
 *                     - EQEP5: eQEP2 base address index
 *                     - EQEP6: eQEP2 base address index
 * \param  position  the new position for the encoder.
 *
 */
static inline void EQEP_setPosition (EQEP_TypeDef *eqep, uint32_t position)
{
    if (position == 0)
    {
        WRITE_REG(eqep->QEPCTL.BIT.SWI, 1);
    }
}

/**
 * \brief  Gets the current direction of rotation.
 * \note   This function returns the current direction of rotation.  In this case,
 *         current means the most recently detected direction of the encoder; it may
 *         not be presently moving but this is the direction it last moved before it
 *         stopped.
 *
 * \param  eQEP  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 *
 * \return Returns 1 if moving in the forward direction or -1 if moving in the
 *         reverse direction.
 */
static inline int16_t EQEP_getDirection (EQEP_TypeDef *eqep)
{
    int16_t direction;

    if ((eqep->QEPSTS.WORDVAL & EQEP_QEPSTS_QDF) != 0U)
    {
        direction = 1;
    }
    else
    {
        direction = -1;
    }

    return (direction);
}

/**
 * \brief  Enables individual eQEP module interrupt sources.
 * \note   This function enables eQEP module interrupt sources.
 *
 * \param  eqep      eqep pointer to a EQEP_TypeDef structure
 *                     - EQEP1: eQEP1 base address index
 *                     - EQEP2: eQEP2 base address index
 *                     - EQEP3: eQEP2 base address index
 *                     - EQEP4: eQEP2 base address index
 *                     - EQEP5: eQEP2 base address index
 *                     - EQEP6: eQEP2 base address index
 * \param  intFlags  a bit mask of the interrupt sources to be enabled.
 *
 */
static inline void EQEP_enableInterrupt (EQEP_TypeDef *eqep, uint16_t intFlags)
{
    SET_BIT(eqep->QEINT.WORDVAL, intFlags);
}

/**
 * \brief  Disables individual eQEP module interrupt sources.
 * \note   This function disables eQEP module interrupt sources.
 *
 * \param  eqep      eqep pointer to a EQEP_TypeDef structure
 *                     - EQEP1: eQEP1 base address index
 *                     - EQEP2: eQEP2 base address index
 *                     - EQEP3: eQEP2 base address index
 *                     - EQEP4: eQEP2 base address index
 *                     - EQEP5: eQEP2 base address index
 *                     - EQEP6: eQEP2 base address index
 * \param  intFlags  a bit mask of the interrupt sources to be disabled.
 *
 */
static inline void EQEP_disableInterrupt (EQEP_TypeDef *eqep, uint16_t intFlags)
{
    CLEAR_BIT(eqep->QEINT.WORDVAL, intFlags);
}

/**
 * \brief  Gets the current interrupt status.
 * \note   This function returns the interrupt status for the eQEP module
 *         module.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 *
 * \return Returns the current interrupt status.
 */
static inline uint16_t EQEP_getInterruptStatus (EQEP_TypeDef *eqep)
{
    return (eqep->QFLG.WORDVAL);
}

/**
 * \brief  Clears eQEP module interrupt sources.
 * \note   This function clears eQEP module interrupt flags.
 *
 * \param  eqep      eqep pointer to a EQEP_TypeDef structure
 *                     - EQEP1: eQEP1 base address index
 *                     - EQEP2: eQEP2 base address index
 *                     - EQEP3: eQEP2 base address index
 *                     - EQEP4: eQEP2 base address index
 *                     - EQEP5: eQEP2 base address index
 *                     - EQEP6: eQEP2 base address index
 * \param  intFlags  a bit mask of the interrupt sources to be cleared.
 *
 */
static inline void EQEP_clearInterruptStatus (EQEP_TypeDef *eqep, uint16_t intFlags)
{
    WRITE_REG(eqep->QCLR.WORDVAL, (uint32_t)intFlags);
}

/**
 * \brief  Forces individual eQEP module interrupts.
 * \note   This function forces eQEP module interrupt flags.
 *
 * \param  eqep      eqep pointer to a EQEP_TypeDef structure
 *                     - EQEP1: eQEP1 base address index
 *                     - EQEP2: eQEP2 base address index
 *                     - EQEP3: eQEP2 base address index
 *                     - EQEP4: eQEP2 base address index
 *                     - EQEP5: eQEP2 base address index
 *                     - EQEP6: eQEP2 base address index
 * \param  intFlags  a bit mask of the interrupt sources to be forced.
 *
 */
static inline void EQEP_forceInterrupt (EQEP_TypeDef *eqep, uint16_t intFlags)
{
    SET_BIT(eqep->QFRC.WORDVAL, intFlags);
}

/**
 * \brief  Gets the encoder error indicator.
 * \note   This function returns the error indicator for the eQEP module.  It is an
 *         error for both of the signals of the quadrature input to change at the same
 *         time.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 *
 * \return Returns \b true if an error has occurred and \b false otherwise.
 */
static inline bool EQEP_getError (EQEP_TypeDef *eqep)
{
    return (READ_BIT(eqep->QFLG.WORDVAL, EQEP_QFLG_PHE) != 0U);
}

/**
 * \brief  Returns content of the eQEP module status register
 * \note   This function returns the contents of the status register.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 *
 * \return Returns the value of the QEP status register.
 */   
static inline uint16_t EQEP_getStatus (EQEP_TypeDef *eqep)
{
    return READ_BIT(eqep->QEPSTS.WORDVAL, 0x00FFU);
}

/**
 * \brief  Clears selected fields of the eQEP module status register
 * \note   This function clears the status register fields indicated by
 *         \e statusFlags.
 * \note   Only the above status fields can be cleared. All others are
 *         read-only, non-sticky fields.
 *
 * \param  eqep         eqep pointer to a EQEP_TypeDef structure
 *                        - EQEP1: eQEP1 base address index
 *                        - EQEP2: eQEP2 base address index
 *                        - EQEP3: eQEP2 base address index
 *                        - EQEP4: eQEP2 base address index
 *                        - EQEP5: eQEP2 base address index
 *                        - EQEP6: eQEP2 base address index
 * \param  statusFlags  the bit mask of the status flags to be clear
 */
static inline void EQEP_clearStatus (EQEP_TypeDef *eqep, uint16_t statusFlags)
{
    WRITE_REG(eqep->QEPSTS.WORDVAL, statusFlags);
}

/**
 * \brief  Configures eQEP module edge-capture unit.
 * \note   This function configures the operation of the eQEP module edge-capture
 *         unit.
 *
 * \param  eqep          eqep pointer to a EQEP_TypeDef structure
 *                         - EQEP1: eQEP1 base address index
 *                         - EQEP2: eQEP2 base address index
 *                         - EQEP3: eQEP2 base address index
 *                         - EQEP4: eQEP2 base address index
 *                         - EQEP5: eQEP2 base address index
 *                         - EQEP6: eQEP2 base address index
 * \param  capPrescale   the prescaler setting of the eQEP capture timer clk.
 * \param  evntPrescale  the prescaler setting of the unit position event frequency.
 */
static inline void EQEP_setCaptureConfig (EQEP_TypeDef *eqep, EQEP_CAPCLKPrescale capPrescale,
                                          EQEP_UPEVNTPrescale evntPrescale)
{
    MODIFY_REG(eqep->QCAPCTL.WORDVAL, (EQEP_QCAPCTL_UPPS_M | EQEP_QCAPCTL_CCPS_M),
               ((uint16_t)evntPrescale | (uint16_t)capPrescale));
}

/**
 * \brief  Enables the eQEP module edge-capture unit.
 * \note   This function enables operation of the eQEP module's edge-capture unit.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 */
static inline void EQEP_enableCapture (EQEP_TypeDef *eqep)
{
    SET_BIT(eqep->QCAPCTL.WORDVAL, EQEP_QCAPCTL_CEN);
}

/**
 * \brief  Disables the eQEP module edge-capture unit.
 * \note   This function disables operation of the eQEP module's edge-capture unit.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 */
static inline void EQEP_disableCapture (EQEP_TypeDef *eqep)
{
    CLEAR_BIT(eqep->QCAPCTL.WORDVAL, EQEP_QCAPCTL_CEN);
}

/**
 * \brief  Gets the encoder capture period.
 * \note   This function returns the period count value between the last successive
 *         eQEP position events.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 *
 * \return The period count value between the last successive position events.
 */
static inline uint16_t EQEP_getCapturePeriod (EQEP_TypeDef *eqep)
{
    return (eqep->QCPRD.WORDVAL);
}

/**
 * \brief  Gets the encoder capture timer value.
 * \note   This function returns the time base for the edge capture unit.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 *
 * \return The capture timer value.
 */
static inline uint16_t EQEP_getCaptureTimer (EQEP_TypeDef *eqep)
{
    return (eqep->QCTMR.WORDVAL);
}

/**
 * \brief  Enables the eQEP module position-compare of shadow.
 * \note   This function enables operation of the eQEP module's position-compare
 *         of shadow.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 */
static inline void EQEP_enableShadow (EQEP_TypeDef *eqep)
{
    SET_BIT(eqep->QPOSCTL.WORDVAL, EQEP_QPOSCTL_PCSHDW);
}

/**
 * \brief  Disables the eQEP module position-compare of shadow.
 * \note   This function disables operation of the eQEP module's position-compare
 *         of shadow.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 */
static inline void EQEP_disableShadow (EQEP_TypeDef *eqep)
{
    CLEAR_BIT(eqep->QPOSCTL.WORDVAL, EQEP_QPOSCTL_PCSHDW);
}

/**
 * \brief  Enables the eQEP module position-compare of shadow load.
 * \note   This function enables operation of the eQEP module's position-compare
 *         of shadow load.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 */
static inline void EQEP_enableShadowLoad (EQEP_TypeDef *eqep)
{
    SET_BIT(eqep->QPOSCTL.WORDVAL, EQEP_QPOSCTL_PCLOAD);
}

/**
 * \brief  Disables the eQEP module position-compare of shadow load.
 * \note   This function disables operation of the eQEP module's position-compare
 *         of shadow load.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 */
static inline void EQEP_disableShadowLoad (EQEP_TypeDef *eqep)
{
    CLEAR_BIT(eqep->QPOSCTL.WORDVAL, EQEP_QPOSCTL_PCLOAD);
}

/**
 * \brief  Configures eQEP module polarity of sync output high pluse.
 * \note   This function configures the operation of the eQEP module
 *         polarity of sync output high pluse.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 */
static inline void EQEP_polaritySyncOutputHigh (EQEP_TypeDef *eqep)
{
    SET_BIT(eqep->QPOSCTL.WORDVAL, EQEP_QPOSCTL_PCPOL);
}

/**
 * \brief  Configures eQEP module polarity of sync output low pluse.
 * \note   This function configures the operation of the eQEP module
 *         polarity of sync output low pluse.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 */
static inline void EQEP_polaritySyncOutputLow (EQEP_TypeDef *eqep)
{
    CLEAR_BIT(eqep->QPOSCTL.WORDVAL, EQEP_QPOSCTL_PCPOL);
}

/**
 * \brief  Enables the eQEP module position-compare unit.
 * \note   This function enables operation of the eQEP module's position-compare unit.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 */
static inline void EQEP_enableCompare (EQEP_TypeDef *eqep)
{
    SET_BIT(eqep->QPOSCTL.WORDVAL, EQEP_QPOSCTL_PCE);
}

/**
 * \brief  Disables the eQEP module position-compare unit.
 * \note   This function disables operation of the eQEP module's position-compare unit.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 */
static inline void EQEP_disableCompare (EQEP_TypeDef *eqep)
{
    CLEAR_BIT(eqep->QPOSCTL.WORDVAL, EQEP_QPOSCTL_PCE);
}

/**
 * \brief  Configures the position-compare unit's sync output pulse width.
 * \note   This function configures the width of the sync output pulse.  The width of
 *         the pulse will be \e cycles * 4 * the width of a SYSCLKOUT cycle.  The
 *         maximum width is 4096 * 4 * SYSCLKOUT cycles.
 *
 * \param  eqep    eqep pointer to a EQEP_TypeDef structure
 *                   - EQEP1: eQEP1 base address index
 *                   - EQEP2: eQEP2 base address index
 *                   - EQEP3: eQEP2 base address index
 *                   - EQEP4: eQEP2 base address index
 *                   - EQEP5: eQEP2 base address index
 *                   - EQEP6: eQEP2 base address index
 * \param  cycles  the width of the pulse that can be generated on a position-compare event.
 *                 It is in units of 4 SYSCLKOUT cycles.
 */
static inline void EQEP_setComparePulseWidth (EQEP_TypeDef *eqep, uint16_t cycles)
{
    MODIFY_REG(eqep->QPOSCTL.WORDVAL, (uint16_t)EQEP_QPOSCTL_PCSPW_M, ((cycles - 1U) & 0xFFFU));
}

/**
 * \brief  Loads the eQEP module unit timer period as number of SYSCLK cycles.
 * \note   This function sets the unit time-out interrupt when it matches the value
 *         specified by \e period
 *         The unit timer is clocked by SYSCLKOUT
 *
 * \param  eqep    eqep pointer to a EQEP_TypeDef structure
 *                   - EQEP1: eQEP1 base address index
 *                   - EQEP2: eQEP2 base address index
 *                   - EQEP3: eQEP2 base address index
 *                   - EQEP4: eQEP2 base address index
 *                   - EQEP5: eQEP2 base address index
 *                   - EQEP6: eQEP2 base address index
 * \param  period  period value at which a unit time-out interrupt is set.
 */
static inline void EQEP_loadUnitTimer (EQEP_TypeDef *eqep, uint32_t period)
{
    WRITE_REG(eqep->QUPRD.WORDVAL, period);
}

/**
 * \brief  Enables the eQEP module unit timer.
 * \note   This function enables operation of the eQEP module's peripheral unit timer.
 *         The unit timer is clocked by SYSCLKOUT and will set the unit time-out
 *         interrupt when it matches the value specified by \e period.
 *
 * \param  eqep    eqep pointer to a EQEP_TypeDef structure
 *                   - EQEP1: eQEP1 base address index
 *                   - EQEP2: eQEP2 base address index
 *                   - EQEP3: eQEP2 base address index
 *                   - EQEP4: eQEP2 base address index
 *                   - EQEP5: eQEP2 base address index
 *                   - EQEP6: eQEP2 base address index
 * \param  period  period value at which a unit time-out interrupt is set.
 */
static inline void EQEP_enableUnitTimer (EQEP_TypeDef *eqep, uint32_t period)
{
    WRITE_REG(eqep->QUPRD.WORDVAL, period);

    SET_BIT(eqep->QEPCTL.WORDVAL, EQEP_QEPCTL_UTE);
}

/**
 * \brief  Disables the eQEP module unit timer.
 * \note   This function disables operation of the eQEP module's peripheral
 *         unit timer.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 */
static inline void EQEP_disableUnitTimer (EQEP_TypeDef *eqep)
{
    CLEAR_BIT(eqep->QEPCTL.WORDVAL, EQEP_QEPCTL_UTE);
}

/**
 * \brief  Enables the eQEP module watchdog timer.
 * \note   This function enables operation of the eQEP module's peripheral watchdog
 *         timer.
 * \note   When selecting \e period, note that the watchdog timer is clocked
 *         from SYSCLKOUT/64.
 *
 * \param  eqep    eqep pointer to a EQEP_TypeDef structure
 *                   - EQEP1: eQEP1 base address index
 *                   - EQEP2: eQEP2 base address index
 *                   - EQEP3: eQEP2 base address index
 *                   - EQEP4: eQEP2 base address index
 *                   - EQEP5: eQEP2 base address index
 *                   - EQEP6: eQEP2 base address index
 * \param  period  period value at which a unit time-out interrupt is set.
 */
static inline void EQEP_enableWatchdog (EQEP_TypeDef *eqep, uint16_t period)
{
    WRITE_REG(eqep->QWDPRD.WORDVAL, period);

    SET_BIT(eqep->QEPCTL.WORDVAL, EQEP_QEPCTL_WDE);
}

/**
 * \brief  Disables the eQEP module watchdog timer.
 * \note   This function disables operation of the eQEP module's peripheral watchdog
 *         timer.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 */
static inline void EQEP_disableWatchdog (EQEP_TypeDef *eqep)
{
    CLEAR_BIT(eqep->QEPCTL.WORDVAL, EQEP_QEPCTL_WDE);
}

/**
 * \brief  Sets the eQEP module watchdog timer value.
 * \note   This function sets the eQEP module's watchdog timer value.
 *
 * \param  eqep   eqep pointer to a EQEP_TypeDef structure
 *                  - EQEP1: eQEP1 base address index
 *                  - EQEP2: eQEP2 base address index
 *                  - EQEP3: eQEP2 base address index
 *                  - EQEP4: eQEP2 base address index
 *                  - EQEP5: eQEP2 base address index
 *                  - EQEP6: eQEP2 base address index
 * \param  value  the value to be written to the watchdog timer.
 */
//static inline void EQEP_setWatchdogTimerValue (EQEP_TypeDef *eqep, uint16_t value)
//{
//    WRITE_REG(eqep->QWDTMR.WORDVAL, value);
//}

/**
 * \brief  Gets the eQEP module watchdog timer value.
 * \note   This function gets the eQEP module's watchdog timer value.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 *
 * \return Returns the current watchdog timer value.
 */
static inline uint16_t EQEP_getWatchdogTimerValue (EQEP_TypeDef *eqep)
{
    return (eqep->QWDTMR.WORDVAL);
}

/**
 * \brief  Configures the mode in which the position counter is initialized.
 * \note   This function configures the events on which the position count can be
 *         initialized.
 *
 * \param  eqep      eqep pointer to a EQEP_TypeDef structure
 *                     - EQEP1: eQEP1 base address index
 *                     - EQEP2: eQEP2 base address index
 *                     - EQEP3: eQEP2 base address index
 *                     - EQEP4: eQEP2 base address index
 *                     - EQEP5: eQEP2 base address index
 *                     - EQEP6: eQEP2 base address index
 * \param  initMode  the configuration for initializing the position count.
 *
 */
static inline void EQEP_setPositionInitMode (EQEP_TypeDef *eqep, uint16_t initMode)
{
    MODIFY_REG(eqep->QEPCTL.WORDVAL, (EQEP_QEPCTL_IEI_M | EQEP_QEPCTL_SEI_M), initMode);
}

/**
 * \brief  Sets the software initialization of the encoder position counter.
 * \note   This function does a software initialization of the position counter when
 *         the \e initialize parameter is \b true. When \b false, the QEPCTL[SWI] bit
 *         is cleared and no action is taken.
 *
 * \param  eqep        eqep pointer to a EQEP_TypeDef structure
 *                       - EQEP1: eQEP1 base address index
 *                       - EQEP2: eQEP2 base address index
 *                       - EQEP3: eQEP2 base address index
 *                       - EQEP4: eQEP2 base address index
 *                       - EQEP5: eQEP2 base address index
 *                       - EQEP6: eQEP2 base address index
 * \param  initialize  a flag to specify if software initialization of the position
 *                     counter is enabled.
 */
static inline void EQEP_setSWPositionInit (EQEP_TypeDef *eqep, bool initialize)
{
    if (initialize)
    {
        SET_BIT(eqep->QEPCTL.WORDVAL, EQEP_QEPCTL_SWI);
    }
    else
    {
        CLEAR_BIT(eqep->QEPCTL.WORDVAL, EQEP_QEPCTL_SWI);
    }
}

/**
 * \brief  Sets the init value for the encoder position counter.
 * \note   This function sets the init value for position of the encoder. See
 *         EQEP_setPositionInitMode() to set the initialization cause or
 *         EQEP_setSWPositionInit() to cause a software initialization.
 *
 * \param  eqep      eqep pointer to a EQEP_TypeDef structure
 *                     - EQEP1: eQEP1 base address index
 *                     - EQEP2: eQEP2 base address index
 *                     - EQEP3: eQEP2 base address index
 *                     - EQEP4: eQEP2 base address index
 *                     - EQEP5: eQEP2 base address index
 *                     - EQEP6: eQEP2 base address index
 * \param  position  the value to be written to the position counter upon.
 *                     counter is enabled.
 */
static inline void EQEP_setInitialPosition (EQEP_TypeDef *eqep, uint32_t position)
{
    WRITE_REG(eqep->QPOSINIT.WORDVAL, position);
}

/**
 * \brief  Configures the quadrature modes in which the position count can be latched.
 * \note   This function configures the events on which the position count and several
 *         other registers can be latched.
 *
 * \param  eqep       eqep pointer to a EQEP_TypeDef structure
 *                      - EQEP1: eQEP1 base address index
 *                      - EQEP2: eQEP2 base address index
 *                      - EQEP3: eQEP2 base address index
 *                      - EQEP4: eQEP2 base address index
 *                      - EQEP5: eQEP2 base address index
 *                      - EQEP6: eQEP2 base address index
 * \param  latchMode  the configuration for latching of the position count and
 *                    several other registers.  See below for a description of this
 *                    parameter.
 */
static inline void EQEP_setLatchMode (EQEP_TypeDef *eqep, uint32_t latchMode)
{
    MODIFY_REG(eqep->QEPCTL.WORDVAL, (EQEP_QEPCTL_QCLM | EQEP_QEPCTL_IEL_M | EQEP_QEPCTL_SEL), latchMode);
}

/**
 * \brief  Gets the encoder position that was latched on an index event.
 * \note   This function returns the value in the index position latch register. The
 *         position counter is latched into this register on either a rising index
 *         edge, a falling index edge, or a software index marker. This is configured
 *         using EQEP_setLatchMode().
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 *
 * \return The position count latched on an index event.
 */
static inline uint32_t EQEP_getIndexPositionLatch (EQEP_TypeDef *eqep)
{
    return (eqep->QPOSILAT.WORDVAL);
}

/**
 * \brief  Gets the encoder position that was latched on a strobe event.
 * \note   This function returns the value in the strobe position latch register. The
 *         position counter can be configured to be latched into this register on
 *         rising strobe edges only or on rising strobe edges while moving clockwise
 *         and falling strobe edges while moving counter-clockwise. This is configured
 *         using EQEP_setLatchMode().
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 *
 * \return The position count latched on a strobe event.
 */
static inline uint32_t EQEP_getStrobePositionLatch (EQEP_TypeDef *eqep)
{
    return (eqep->QPOSSLAT.WORDVAL);
}

/**
 * \brief  Gets the encoder position that was latched on a unit time-out event.
 * \note   This function returns the value in the position latch register. The
 *         position counter is latched into this register either on a unit time-out
 *         event.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 *
 * \return The position count latch register value.
 */
static inline uint32_t EQEP_getPositionLatch (EQEP_TypeDef *eqep)
{
    return (eqep->QPOSLAT.WORDVAL);
}

/**
 * \brief  Gets the encoder capture timer latch.
 * \note   This function returns the value in the capture timer latch register.  The
 *         event or upon the CPU reading the eQEP position counter. This is configured
 *         using EQEP_setLatchMode().
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 *
 * \return The edge-capture timer latch value.
 */
static inline uint16_t EQEP_getCaptureTimerLatch (EQEP_TypeDef *eqep)
{
    return ((uint16_t)eqep->QCTMRLAT.WORDVAL);
}

/**
 * \brief  Gets the encoder capture period latch.
 * \note   This function returns the value in the capture period latch register.  The
 *         capture period value is latched into this register either on a unit
 *         time-out event or upon the CPU reading the eQEP position counter. This is
 *         configured using EQEP_setLatchMode().
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 *
 * \return The edge-capture period latch value.
 */
static inline uint16_t EQEP_getCapturePeriodLatch (EQEP_TypeDef *eqep)
{
    return ((uint16_t)eqep->QCPRDLAT.WORDVAL);
}

/**
 * \brief  Set the quadrature mode adapter (QMA) module mode
 * \note   This function sets the quadrature mode adapter module mode. The possible
 *         modes are passed to the function through the \e qmaMode parameter which
 *         can take the values EQEP_QMA_MODE_BYPASS, EQEP_QMA_MODE_1, or
 *         EQEP_QMA_MODE_2.
 *
 * \param  eqep    eqep pointer to a EQEP_TypeDef structure
 *                   - EQEP1: eQEP1 base address index
 *                   - EQEP2: eQEP2 base address index
 *                   - EQEP3: eQEP2 base address index
 *                   - EQEP4: eQEP2 base address index
 *                   - EQEP5: eQEP2 base address index
 *                   - EQEP6: eQEP2 base address index
 * \param qmaMode  the mode in which the QMA module will operate.
 *
 */
static inline void EQEP_setQMAModuleMode (EQEP_TypeDef *eqep, EQEP_QMAMode qmaMode)
{
    MODIFY_REG(eqep->QMACTRL.WORDVAL, EQEP_QMACTRL_MODE_M, (uint16_t)qmaMode);
}

/**
 * \brief  Set the strobe input source of the eQEP module.
 * \note   This function sets the source of the eQEP module's strobe signal.
 *
 * \param  eqep      eqep pointer to a EQEP_TypeDef structure
 *                     - EQEP1: eQEP1 base address index
 *                     - EQEP2: eQEP2 base address index
 *                     - EQEP3: eQEP2 base address index
 *                     - EQEP4: eQEP2 base address index
 *                     - EQEP5: eQEP2 base address index
 *                     - EQEP6: eQEP2 base address index
 * \param strobeSrc  the source of the strobe signal.
 *
 */
static inline void EQEP_setStrobeSource (EQEP_TypeDef *eqep, EQEP_StrobeSource strobeSrc)
{
    MODIFY_REG(eqep->QEPSTROBESEL.WORDVAL, EQEP_QEPSTROBESEL_STROBESEL_M, (uint16_t)strobeSrc);
}

/**
 * \brief  Enables the index direction enhancement mode of the eQEP module
 * \note   This function enables the enhancement mode for direction change
 *         during Index event.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 */
static inline void EQEP_enableDirectionChangeDuringIndex (EQEP_TypeDef *eqep)
{
    SET_BIT(eqep->QDECCTL.WORDVAL, EQEP_QDECCTL_QIDIRE);
}

/**
 * \brief  Disables the index direction enhancement mode of the eQEP module
 * \note   This function disables the enhancement mode for direction change
 *         during Index event.
 *
 * \param  eqep  eqep pointer to a EQEP_TypeDef structure
 *                 - EQEP1: eQEP1 base address index
 *                 - EQEP2: eQEP2 base address index
 *                 - EQEP3: eQEP2 base address index
 *                 - EQEP4: eQEP2 base address index
 *                 - EQEP5: eQEP2 base address index
 *                 - EQEP6: eQEP2 base address index
 */
static inline void EQEP_disableDirectionChangeDuringIndex (EQEP_TypeDef *eqep)
{
    CLEAR_BIT(eqep->QDECCTL.WORDVAL, EQEP_QDECCTL_QIDIRE);
}

/**
 * \brief  Selects the source for eQEPA/B/I signals
 * \note   This function configures the sources for QEPA,QEPB and Index of eQEP module.
 *
 * \param  eqep         eqep pointer to a EQEP_TypeDef structure
 *                        - EQEP1: eQEP1 base address index
 *                        - EQEP2: eQEP2 base address index
 *                        - EQEP3: eQEP2 base address index
 *                        - EQEP4: eQEP2 base address index
 *                        - EQEP5: eQEP2 base address index
 *                        - EQEP6: eQEP2 base address index
 * \param sourceConfig  the structure that contains source configuration
 */
static inline void EQEP_selectSource (EQEP_TypeDef *eqep, EQEP_SourceSelect sourceConfig)
{
    MODIFY_REG(eqep->QEPSRCSEL.WORDVAL,
               (EQEP_QEPSRCSEL_QEPASEL_M | EQEP_QEPSRCSEL_QEPBSEL_M | EQEP_QEPSRCSEL_QEPISEL_M),
               ((uint32_t)((uint32_t)(sourceConfig.sourceA << EQEP_QEPSRCSEL_QEPASEL_S)) |
                (uint32_t)((uint32_t)(sourceConfig.sourceB << EQEP_QEPSRCSEL_QEPBSEL_S)) |
                (uint32_t)((uint32_t)(sourceConfig.sourceIndex << EQEP_QEPSRCSEL_QEPISEL_S))));
}

/**
 * \brief  Set the emulation mode of the eQEP module.
 * \note   This function sets the eQEP module's emulation mode. This mode determines
 *         how the timers are affected by an emulation suspend.
 *
 * \param  eqep     eqep pointer to a EQEP_TypeDef structure
 *                    - EQEP1: eQEP1 base address index
 *                    - EQEP2: eQEP2 base address index
 *                    - EQEP3: eQEP2 base address index
 *                    - EQEP4: eQEP2 base address index
 *                    - EQEP5: eQEP2 base address index
 *                    - EQEP6: eQEP2 base address index
 * \param  emuMode  the mode operation upon an emulation suspend.
 */
static inline void EQEP_setEmulationMode (EQEP_TypeDef *eqep, EQEP_EmulationMode emuMode)
{
    MODIFY_REG(eqep->QEPCTL.WORDVAL, EQEP_QEPCTL_FREE_SOFT_M, (uint16_t)emuMode << EQEP_QEPCTL_FREE_SOFT_S);
}

/**
 * \brief  Configures eQEP module position-compare unit.
 * \note   This function configures the operation of the eQEP module position-compare
 *         unit.
 * \note   You can set the sync pulse width independently using the EQEP_setComparePulseWidth()
 *         function.
 *
 * \param  eqep          eqep pointer to a EQEP_TypeDef structure
 *                         - EQEP1: eQEP1 base address index
 *                         - EQEP2: eQEP2 base address index
 *                         - EQEP3: eQEP2 base address index
 *                         - EQEP4: eQEP2 base address index
 *                         - EQEP5: eQEP2 base address index
 *                         - EQEP6: eQEP2 base address index
 * \param  config        the configuration for the eQEP module position-compare unit.
 * \param  compareValue  the value to which the position count value is compared for
 *                       a position-compare event.
 * \param  cycles        the width of the pulse that can be generated on a position-compare event.
 *                       It is in units of 4 SYSCLKOUT cycles.    
 */
extern void EQEP_setCompareConfig (EQEP_TypeDef *eqep, uint16_t config, uint32_t compareValue, uint16_t cycles);

/**
 * \brief  Sets the polarity of the eQEP module's input signals.
 * \note   This function configures the polarity of the inputs to the eQEP module. To
 *         negate the polarity of any of the input signals, pass \b true into its
 *         corresponding parameter in this function. Pass \b false to leave it as-is.
 *
 * \param  eqep          eqep pointer to a EQEP_TypeDef structure
 *                         - EQEP1: eQEP1 base address index
 *                         - EQEP2: eQEP2 base address index
 *                         - EQEP3: eQEP2 base address index
 *                         - EQEP4: eQEP2 base address index
 *                         - EQEP5: eQEP2 base address index
 *                         - EQEP6: eQEP2 base address index
 * \param  invertQEPA    the flag to negate the QEPA input.
 * \param  invertQEPB    the flag to negate the QEPA input.
 * \param  invertIndex   the flag to negate the index input.
 * \param  invertStrobe  the flag to negate the strobe input.
 *
 */
extern void EQEP_setInputPolarity (EQEP_TypeDef *eqep, bool invertQEPA, bool invertQEPB, bool invertIndex,
                                   bool invertStrobe);


#ifdef __cplusplus
}
#endif


#endif /* __EQEP_H__ */
