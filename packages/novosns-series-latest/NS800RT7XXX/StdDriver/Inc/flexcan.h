/**
  * @file       flexcan.h
  * @author     Gordon-Zheng
  * @brief      Header file for NS800RT7xxx flexcan module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __FLEXCAN_H__
#define __FLEXCAN_H__


#ifdef __cplusplus
extern "C"{
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_flexcan.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup FLEXCAN_EXPORTED_TYPES FLEXCAN Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'FLEXCAN' module.
  */

/** @defgroup FLEXCANDRV_MB_SIZE FLEXCAN Message Buff Size Byte
  * @{
  * @brief  Macro definitions about FLEXCAN message buff size byte.
  */
#define FLEXCANDRV_MB_SIZE_BYTE_8     (0UL)    /*!< Message buff size is 8byte */
#define FLEXCANDRV_MB_SIZE_BYTE_16    (1UL)    /*!< Message buff size is 16byte */
#define FLEXCANDRV_MB_SIZE_BYTE_32    (2UL)    /*!< Message buff size is 32byte */
#define FLEXCANDRV_MB_SIZE_BYTE_64    (3UL)    /*!< Message buff size is 64byte */

/**
  * @}
  */

/** @defgroup FLEXCANDRV_MSG_BUF_CODE FLEXCAN Message Buff Code
  * @{
  * @brief  Macro definitions about FLEXCAN message buff code.
  */
#define FLEXCANDRV_MSG_BUF_CODE_INACTIVE       (0x0UL)    /*!< Message buff status is inactive */
#define FLEXCANDRV_MSG_BUF_CODE_RX_ACTIVE      (0x4UL)    /*!< Message buff status is rx active */
#define FLEXCANDRV_MSG_BUF_CODE_TX_REQUEST     (0xCUL)    /*!< Message buff status is tx request */
#define FLEXCANDRV_MSG_BUF_CODE_TX_INACTIVE    (0x8UL)    /*!< Message buff status is tx inactive */
#define FLEXCANDRV_MSG_BUF_CODE_ABORT          (0x9UL)    /*!< Message buff status is abort */
#define FLEXCANDRV_MSG_BUF_CODE_MASK           (0xFUL)    /*!< Message buff code mask */
#define FLEXCANDRV_MSG_BUF_CODE_SHIFT          (24UL)     /*!< Message buff code offset */
#define FLEXCANDRV_MSG_FILTER_ELEMENTS_NUM     (128UL)    /*!< Message buff filter numbers */

/**
  * @}
  */

/** @defgroup FLEXCANDRV_CAN_ACCESS_MODE FLEXCAN Access Mode Configuration 
  * @{
  * @brief  Macro definitions about FLEXCAN access mode configuration.
  */
#define FLEXCANDRV_CAN_ACCESS_MODE_USER    (0UL)    /*!< Flexcan access in user mode */
#define FLEXCANDRV_CAN_ACCESS_MODE_SUP     (1UL)    /*!< Flexcan access in supervisor mode */

/**
  * @}
  */

/** @defgroup RXFIFOFILTERELEMENTNUM FLEXCAN Rx Fifo Element Num Calculate
* @{
* @brief  Macro definitions about FLEXCAN Rx Fifo Element Num Calculate.
*/
#define RXFIFOFILTERELEMENTNUM(x)    (((x) + 1UL) * 8UL)    /*!< Flexcan rx fifo element num */

/**
  * @}
  */

/** @defgroup FLEXCAN_DRV_CAN_RAM FLEXCAN Driver Can RAM Size Define
  * @{
  * @brief  Macro definitions about FLEXCAN driver parameters.
  */
#define FLEXCAN_DRV_CAN_RAM_SIZE    (512UL)     /*!< Flexcan ram memory size */

/**
  * @}
  */

/** @defgroup TX_PENDING_ABORT FLEXCAN Tx Pending Abort Status Define
  * @{
  * @brief  Macro definitions about FLEXCAN tx pending abort status.
  */
#define TX_PENDING_ABORT_SUCCESS         (1UL)       /*!< Flexcan Tx pending abort succeeded */
#define TX_PENDING_ABORT_NO_TRANSFER     (0UL)       /*!< Flexcan Tx pending abort no transmission */
#define TX_PENDING_ABORT_FAILED          (0xFFUL)    /*!< Flexcan Tx pending abort faild */

/**
  * @}
  */

/** @defgroup MESSAGE_BUFFER Message Buff Address Offset Define
  * @{
  * @brief  Macro definitions about The Message buff address offset.
  */
#define MESSAGE_BUFFER_ADDR_OFF    (0x80UL)    /*!< Flexcan message buff address offset */

/**
  * @}
  */
 
/** @defgroup MESSAGE_BUFFER Message Buff CS and ID Location Define
  * @{
  * @brief  Macro definitions about The Message buff CS and ID location.
  */
#define MESSAGE_BUFFER_CS_WORD_NUM    (0UL)    /*!< Flexcan message buff CS location */
#define MESSAGE_BUFFER_ID_WORD_NUM    (1UL)    /*!< Flexcan message buff ID location */

/**
  * @}
  */

/** @defgroup MESSAGE_BUFFER_CS Message Buff Control and Status Field
  * @{
  * @brief  Macro definitions about Message buff control and status field.
  */
#define MESSAGE_BUFFER_CS_EDL_SHIFT     (31UL)                                      /*!< Flexcan message buff EDL offset */
#define MESSAGE_BUFFER_CS_EDL_MASK      (0x1UL << MESSAGE_BUFFER_CS_EDL_SHIFT)      /*!< Flexcan message buff EDL */
#define MESSAGE_BUFFER_CS_BRS_SHIFT     (30UL)                                      /*!< Flexcan message buff BRS offset */
#define MESSAGE_BUFFER_CS_BRS_MASK      (0x1UL << MESSAGE_BUFFER_CS_BRS_SHIFT)      /*!< Flexcan message buff BRS */
#define MESSAGE_BUFFER_CS_CODE_SHIFT    (24UL)                                      /*!< Flexcan message buff CODE offset */
#define MESSAGE_BUFFER_CS_CODE_MASK     (0xFUL << MESSAGE_BUFFER_CS_CODE_SHIFT)     /*!< Flexcan message buff CODE */
#define MESSAGE_BUFFER_CS_SRR_SHIFT     (22UL)                                      /*!< Flexcan message buff SRR offset */
#define MESSAGE_BUFFER_CS_SRR_MASK      (0x1UL << MESSAGE_BUFFER_CS_SRR_SHIFT)      /*!< Flexcan message buff SRR */
#define MESSAGE_BUFFER_CS_IDE_SHIFT     (21UL)                                      /*!< Flexcan message buff IDE offset */
#define MESSAGE_BUFFER_CS_IDE_MASK      (0x1UL << MESSAGE_BUFFER_CS_IDE_SHIFT)      /*!< Flexcan message buff IDE */
#define MESSAGE_BUFFER_CS_RTR_SHIFT     (20UL)                                      /*!< Flexcan message buff RTR offset */
#define MESSAGE_BUFFER_CS_RTR_MASK      (0x1UL << MESSAGE_BUFFER_CS_RTR_SHIFT)      /*!< Flexcan message buff RTR */
#define MESSAGE_BUFFER_CS_DLC_SHIFT     (16UL)                                      /*!< Flexcan message buff DLC offset */
#define MESSAGE_BUFFER_CS_DLC_MASK      (0xFUL << MESSAGE_BUFFER_CS_DLC_SHIFT)      /*!< Flexcan message buff DLC */
#define MESSAGE_BUFFER_CS_TS_SHIFT      (0UL)                                       /*!< Flexcan message buff TS offset */
#define MESSAGE_BUFFER_CS_TS_MASK       (0xFFFFUL << MESSAGE_BUFFER_CS_TS_SHIFT)    /*!< Flexcan message buff TS */

/**
  * @}
  */

/** @defgroup LEGACY_FF_CS Legacy Rx Fifo Control and Status Field 
  * @{
  * @brief  Macro definitions about legacy rx fifo control and status field.
  */
#define LEGACY_FF_CS_IDHIT_SHIFT    (23UL)                                   /*!< Flexcan legacy fifo IDHIT offset */
#define LEGACY_FF_CS_IDHIT_MASK     (0x1FFUL << LEGACY_FF_CS_IDHIT_SHIFT)    /*!< Flexcan legacy fifo IDHIT */
#define LEGACY_FF_CS_SRR_SHIFT      (22UL)                                   /*!< Flexcan legacy fifo SRR offset */
#define LEGACY_FF_CS_SRR_MASK       (0x1UL << LEGACY_FF_CS_SRR_SHIFT)        /*!< Flexcan legacy fifo SRR */
#define LEGACY_FF_CS_IDE_SHIFT      (21UL)                                   /*!< Flexcan legacy fifo IDE offset */
#define LEGACY_FF_CS_IDE_MASK       (0x1UL << LEGACY_FF_CS_IDE_SHIFT)        /*!< Flexcan legacy fifo IDE */
#define LEGACY_FF_CS_RTR_SHIFT      (20UL)                                   /*!< Flexcan legacy fifo RTR offset */
#define LEGACY_FF_CS_RTR_MASK       (0x1UL << LEGACY_FF_CS_RTR_SHIFT)        /*!< Flexcan legacy fifo RTR */
#define LEGACY_FF_CS_DLC_SHIFT      (16UL)                                   /*!< Flexcan legacy fifo DLC offset */
#define LEGACY_FF_CS_DLC_MASK       (0xFUL << LEGACY_FF_CS_DLC_SHIFT)        /*!< Flexcan legacy fifo DLC */
#define LEGACY_FF_CS_TS_SHIFT       (0UL)                                    /*!< Flexcan legacy fifo TS offset */
#define LEGACY_FF_CS_TS_MASK        (0xFFFFUL << LEGACY_FF_CS_TS_SHIFT)      /*!< Flexcan legacy fifo TS */

/**
  * @}
  */

/** @defgroup MESSAGE_BUFFER_ID Message Buff ID Field
  * @{
  * @brief  Macro definitions about Message buff ID field.
  */
#define MESSAGE_BUFFER_ID_EXT_ID_SHIFT    (0UL)                                               /*!< Flexcan message buff
                                                                                                   ext ID offset */
#define MESSAGE_BUFFER_ID_EXT_ID_MASK     (0x1FFFFFFFUL << MESSAGE_BUFFER_ID_EXT_ID_SHIFT)    /*!< Flexcan message buff 
                                                                                                   ext ID */
#define MESSAGE_BUFFER_ID_STD_ID_SHIFT    (18UL)                                              /*!< Flexcan message buff 
                                                                                                   std ID offset */
#define MESSAGE_BUFFER_ID_STD_ID_MASK     (0x7FFUL << MESSAGE_BUFFER_ID_STD_ID_SHIFT)         /*!< Flexcan message buff 
                                                                                                   std ID */
/**
  * @}
  */

/** @defgroup FLEXCAN_RX_FIFO_ID_FILTER FLEXCAN Rx Fifo ID Filter Foramt Configuration
  * @{
  * @brief  Macro definitions about FLEXCAN rx fifo ID filter Configuration definition.
  */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATAB_RTR_SHIFT       (31UL)            /*!< Format A&B RTR shift */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATAB_IDE_SHIFT       (30UL)            /*!< Format A&B IDE shift */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_RTR_SHIFT        (15UL)            /*!< Format B RTR shift */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_IDE_SHIFT        (14UL)            /*!< Format B IDE shift */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATA_EXT_MASK         (0x3FFFFFFFUL)    /*!< Format A extended mask */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATA_EXT_SHIFT        (1UL)             /*!< Format A extended shift */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATA_STD_MASK         (0x3FF80000UL)    /*!< Format A standard mask */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATA_STD_SHIFT        (19UL)            /*!< Format A standard shift */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_EXT_MASK         (0x1FFF8000UL)    /*!< Format B extended mask */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_EXT_MASK1        (0x3FFFUL)        /*!< Format B extended mask1 */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_EXT_SHIFT1       (16UL)            /*!< Format B extended shift1 */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_EXT_SHIFT2       (0UL)             /*!< Format B extended shift2 */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_STD_MASK         (0x7FFUL)         /*!< Format B standard mask */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_STD_SHIFT1       (19UL)            /*!< Format B standard shift1 */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_STD_SHIFT2       (3UL)             /*!< Format B standard shift2 */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT    (15UL)            /*!< Format B extended compare shift */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_EXT_MASK         (0x1FE00000UL)    /*!< Format C mask */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_STD_MASK         (0x7F8UL)         /*!< Format C mask */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_SHIFT1           (24UL)            /*!< Format C shift1 */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_SHIFT2           (16UL)            /*!< Format C shift2 */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_SHIFT3           (8UL)             /*!< Format C shift3 */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_SHIFT4           (0UL)             /*!< Format C shift4 */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT    (21UL)            /*!< Format C extended compare shift */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT    (3UL)             /*!< Format C standard compare shift */
#define FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_MASK             (0xFFUL)          /*!< Format C mask */

/**
  * @}
  */

/** @defgroup FLEXCANDRV_DATALENCODETYPE FLEXCAN Data Length Code Configuration
  * @{
  * @brief  Macro definitions about FLEXCAN data length code definition.
  */
typedef enum {
    DLC_BYTE_0 = 0x00U,    /*!< 0 byte(s) data length code */
    DLC_BYTE_1,            /*!< 1 byte(s) data length code */
    DLC_BYTE_2,            /*!< 2 byte(s) data length code */
    DLC_BYTE_3,            /*!< 3 byte(s) data length code */
    DLC_BYTE_4,            /*!< 4 byte(s) data length code */
    DLC_BYTE_5,            /*!< 5 byte(s) data length code */
    DLC_BYTE_6,            /*!< 6 byte(s) data length code */
    DLC_BYTE_7,            /*!< 7 byte(s) data length code */
    DLC_BYTE_8,            /*!< 8 byte(s) data length code */
    DLC_BYTE_12,           /*!< 12 byte(s) data length code */
    DLC_BYTE_16,           /*!< 16 byte(s) data length code */
    DLC_BYTE_20,           /*!< 20 byte(s) data length code */
    DLC_BYTE_24,           /*!< 24 byte(s) data length code */
    DLC_BYTE_32,           /*!< 32 byte(s) data length code */
    DLC_BYTE_48,           /*!< 48 byte(s) data length code */
    DLC_BYTE_64            /*!< 64 byte(s) data length code */
} FLEXCANDRV_DataLenCodeType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_CLKSRCTYPE FLEXCAN Clk Source Type
  * @{
  * @brief  Macro definitions about FLEXCAN clk source type.
  */
typedef enum {
    FLEXCANDRV_CLKSRC_OSC = 0x00U,    /*!< Oscillator clock source */
    FLEXCANDRV_CLKSRC_CHICLK          /*!< Peripherial clock source */
} FLEXCANDRV_ClkSrcType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_MSGTYPE FLEXCAN Message Type
  * @{
  * @brief  Macro definitions about FLEXCAN message type.
  */
typedef enum {
    FLEXCANDRV_MSGTYPE_TX = 0x00U,    /*!< Tx message type */
    FLEXCANDRV_MSGTYPE_RX             /*!< Rx message type */
} FLEXCANDRV_MsgType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_NODESTATTYPE FLEXCAN Node State Type
  * @{
  * @brief  Macro definitions about FLEXCAN node state type.
  */
typedef enum {
    FLEXCANDRV_NODESTAT_IDLE = 0x00U,    /*!< Idle bus state */
    FLEXCANDRV_NODESTAT_RECEIVING,       /*!< Receving bus state */
    FLEXCANDRV_NODESTAT_TRANSMITTING     /*!< Transmitting bus state */
} FLEXCANDRV_NodeStatType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_FLTCONFSTSTYPE FLEXCAN Fault Confinment State
  * @{
  * @brief  Macro definitions about FLEXCAN fault confinment state type.
  */
typedef enum {
    FLEXCANDRV_FLTCONFSTS_ERRACTIVE = 0U,    /*!< Error active state */
    FLEXCANDRV_FLTCONFSTS_ERRPASSIVE,        /*!< Error passive state */
    FLEXCANDRV_FLTCONFSTS_BUSOFF             /*!< Bus off state */
} FLEXCANDRV_FltConfStsType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_ENHANCERXFFISRSRCTYPE FLEXCAN Enhance Rx Fifo Interrupt Source Mask
  * @{
  * @brief  Macro definitions about FLEXCAN enhance rx fifo interrupt source mask type.
  */
typedef enum {
    FLEXCANDRV_ENHANCERXFF_ISR_SRC_DAIE  = 0x10000000U,    /*!< Data available interrupt */
    FLEXCANDRV_ENHANCERXFF_ISR_SRC_WMMIE = 0x20000000U,    /*!< Watermark indication interrupt */
    FLEXCANDRV_ENHANCERXFF_ISR_SRC_OVFIE = 0x40000000U,    /*!< Overflow interrupt */
    FLEXCANDRV_ENHANCERXFF_ISR_SRC_UFWIE = 0x80000000U     /*!< Underflow interrupt */
} FLEXCANDRV_EnhanceRxFFIsrSrcType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_HRTMRCAPTUREPOINTSELECTTYPE FLEXCAN High-Resolution Timer Capture Point Select
  * @{
  * @brief  Macro definitions about FLEXCAN high-resolution timer capture point select type.
  */
typedef enum {
    FLEXCANDRV_HR_TIMER_CAPTURE_DISABLE = 0U,             /*!< Time stamp capture is disabled */
    FLEXCANDRV_HR_TIMER_CAPTURE_EOF,                      /*!< Time stamp is captured at the EOF of CAN frame */
    FLEXCANDRV_HR_TIMER_CAPTURE_SOF,                      /*!< Time stamp is captured at the SOF of CAN frame */
    FLEXCANDRV_HR_TIMER_CAPTURE_CLASSIC_SOF_FD_RES_BIT    /*!< Time stamp is captured at the SOF of frame for
                                                               CAN frame and at the res bit for CANFD frame */
} FLEXCANDRV_HRTmrCapturePointSelectType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_MBTMRBASESELECTTYPE FLEXCAN Message Buffer Time Stamp Base
  * @{
  * @brief  Macro definitions about FLEXCAN message buffer time stamp select base type.
  */
typedef enum {
    FLEXCANDRV_MB_TIMER_BASE_CAN_TMR = 0U,       /*!< Time stamp base is CAN_TIMER */
    FLEXCANDRV_MB_TIMER_BASE_LOW16BIT_HRTMR,     /*!< Time stamp base is lower 16 bits of high-resolution timer */
    FLEXCANDRV_MB_TIMER_BASE_UPPER16BIT_HRTMR    /*!< Time stamp base is upper 16 bits of high-resolution timer */
} FLEXCANDRV_MBTmrBaseSelectType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_PNWKPEVENTTYPE FLEXCAN PN Wakeup by Timeout or Match Message Select
  * @{
  * @brief  Macro definitions about FLEXCAN PN Wakeup by timeout or match message select type.
  */
typedef enum {
    FLEXCANDRV_PN_WKP_EVENT_TIMOUT = 0U,     /*!< PN wakeup by timeout event */
    FLEXCANDRV_PN_WKP_EVENT_MATCH,           /*!< PN wakeup by message match event */
    FLEXCANDRV_PN_WKP_EVENT_ALL              /*!< PN wakeup by timeout & message match event */
} FLEXCANDRV_PnWkpEventType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_PNPAYLOADFILTERSELECTTYPE FLEXCAN PN Payload Filter Select
  * @{
  * @brief  Macro definitions about FLEXCAN PN payload filter select type.
  */
typedef enum {
    FLEXCANDRV_PN_FILTER_SELECT_PLFS00 = 0U,     /*!< A payload contents against an exact target value */
    FLEXCANDRV_PN_FILTER_SELECT_PLFS01,          /*!< A payload value greater than or equal to a specified target value */
    FLEXCANDRV_PN_FILTER_SELECT_PLFS10,          /*!< A payload value smaller than or equal to a specified target value */
    FLEXCANDRV_PN_FILTER_SELECT_PLFS11           /*!< A payload value inside a range, greater than or equal to a specified
                                                      lower limit, and smaller than or equal to a specified upper limit */
} FLEXCANDRV_PnPayloadFilterSelectType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_PNIDFILTERSELECTTYPE FLEXCAN PN ID Filter Select
  * @{
  * @brief  Macro definitions about FLEXCAN PN ID filter select type.
  */
typedef enum {
    FLEXCANDRV_PN_FILTER_SELECT_IDFS00 = 0U,    /*!< PN ID contents against an exact target value */
    FLEXCANDRV_PN_FILTER_SELECT_IDFS01,         /*!< PN ID value greater than or equal to a specified target value */
    FLEXCANDRV_PN_FILTER_SELECT_IDFS10,         /*!< PN ID value smaller than or equal to a specified target value */
    FLEXCANDRV_PN_FILTER_SELECT_IDFS11          /*!< PN ID value inside a range, greater than or equal to a specified
                                                     lower limit, and smaller than or equal to a specified upper limit */
} FLEXCANDRV_PnIdFilterSelectType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_PNFILTERCOMSELTYPE FLEXCAN PN Filter Combination Select
  * @{
  * @brief  Macro definitions about FLEXCAN PN filter combination select type.
  */
typedef enum {
    FLEXCANDRV_FILTER_ID_ONLY = 0U,     /*!< Message id filter only */
    FLEXCANDRV_FILTER_ID_PAYLOAD,       /*!< Message id filter and payload filter */
    FLEXCANDRV_FILTER_ID_WITH_CNT,      /*!< Message id filter occurring a specified number of times */
    FLEXCANDRV_FILTER_ID_PAYLOAD_CNT    /*!< Message id filter and payload filter a specified number of times */
} FLEXCANDRV_PnFilterComSelType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_ERRSTATUSMASKTYPE FLEXCAN Error and Status Mask Configuration
  * @{
  * @brief  Macro definitions about FLEXCAN error status mask configuration type.
  */
typedef enum {
    FLEXCANDRV_ESR_STATUS_BIT1ERR_FAST_MASK = (1UL << 31U),    /*!< Error and status: BIT1ERR_FAST */
    FLEXCANDRV_ESR_STATUS_BIT0ERR_FAST_MASK = (1UL << 30U),    /*!< Error and status: BIT0ERR_FAST */
    FLEXCANDRV_ESR_STATUS_CRCERR_FAST_MASK  = (1UL << 28U),    /*!< Error and status: CRCERR_FAST */
    FLEXCANDRV_ESR_STATUS_FRMERR_FAST_MASK  = (1UL << 27U),    /*!< Error and status: FRMERR_FAST */
    FLEXCANDRV_ESR_STATUS_STFERR_FAST_MASK  = (1UL << 26U),    /*!< Error and status: STFERR_FAST */
    FLEXCANDRV_ESR_STATUS_ERROVR_MASK       = (1UL << 21U),    /*!< Error and status: ERROVERN */
    FLEXCANDRV_ESR_STATUS_ERRINT_FAST_MASK  = (1UL << 20U),    /*!< Error and status: ERRINT_FAST */
    FLEXCANDRV_ESR_STATUS_BOFFDONEINT_MASK  = (1UL << 19U),    /*!< Error and status: BOFFDONEINT */
    FLEXCANDRV_ESR_STATUS_SYNCH_MASK        = (1UL << 18U),    /*!< Error and status: SYNCH */
    FLEXCANDRV_ESR_STATUS_TWRNINT_MASK      = (1UL << 17U),    /*!< Error and status: TWRNINT */
    FLEXCANDRV_ESR_STATUS_RWRNINT_MASK      = (1UL << 16U),    /*!< Error and status: RWRNINT */
    FLEXCANDRV_ESR_STATUS_BIT1ERR_MASK      = (1UL << 15U),    /*!< Error and status: BIT1ERR */
    FLEXCANDRV_ESR_STATUS_BIT0ERR_MASK      = (1UL << 14U),    /*!< Error and status: BIT0ERR */
    FLEXCANDRV_ESR_STATUS_ACKERR_MASK       = (1UL << 13U),    /*!< Error and status: ACKERR */
    FLEXCANDRV_ESR_STATUS_CRCERR_MASK       = (1UL << 12U),    /*!< Error and status: CRCERR */
    FLEXCANDRV_ESR_STATUS_FRMERR_MASK       = (1UL << 11U),    /*!< Error and status: FRMERR */
    FLEXCANDRV_ESR_STATUS_STFERR_MASK       = (1UL << 10U),    /*!< Error and status: STFERR */
    FLEXCANDRV_ESR_STATUS_TXWRN_MASK        = (1UL << 9U),     /*!< Error and status: TXWRN */
    FLEXCANDRV_ESR_STATUS_RXWRN_MASK        = (1UL << 8U),     /*!< Error and status: RXWRN */
    FLEXCANDRV_ESR_STATUS_IDLE_MASK         = (1UL << 7U),     /*!< Error and status: IDLE */
    FLEXCANDRV_ESR_STATUS_TX_MASK           = (1UL << 6U),     /*!< Error and status: TX */
    FLEXCANDRV_ESR_STATUS_FLTCONF_MASK      = (3UL << 5U),     /*!< Error and status: FLTCONF */
    FLEXCANDRV_ESR_STATUS_RX_MASK           = (1UL << 3U),     /*!< Error and status: RX */
    FLEXCANDRV_ESR_STATUS_BOFFINT_MASK      = (1UL << 2U),     /*!< Error and status: BOFFINT */
    FLEXCANDRV_ESR_STATUS_ERRINT_MASK       = (1UL << 1U),     /*!< Error and status: ERRINT */
    FLEXCANDRV_ESR_STATUS_WAKINT_MASK       = (1UL << 0U),     /*!< Error and status: WAKINT */
    FLEXCANDRV_ERR_STATUS_MASK_ALL          = 0xFFFFFFFFUL     /*!< Error and status: ALL ERROR */
} FLEXCANDRV_ErrStatusMaskType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_RXFIFOIDELEMENTFORMAT FLEXCAN Rx Fifo Filter ID Identifier
  * @{
  * @brief  Macro definitions about FLEXCAN rx fifo filter ID identifier type.
  */
typedef enum {
    FLEXCAN_RX_FIFO_ID_FORMAT_A = 0U,    /*!< One full ID per ID filter table element */
    FLEXCAN_RX_FIFO_ID_FORMAT_B,         /*!< Two full standard IDs or two partial 14-bit IDs per ID filter
                                              table element */
    FLEXCAN_RX_FIFO_ID_FORMAT_C,         /*!< Four partial 8-bit Standard IDs per ID filter table element */
    FLEXCAN_RX_FIFO_ID_FORMAT_D          /*!< All frames rejected */
} FLEXCANDRV_RxFifoIDElementFormat;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_ENHANCERXFFFILTERSELECTION FLEXCAN Enhanced Rx Fifo Filter Selection
  * @{
  * @brief  Macro definitions about FLEXCAN enhanced rx fifo filter selection type.
  */
typedef enum {
    FLEXCANDRV_ENHRXFF_FILTER_SELECT_MASK_FITLER = 0U,           /*!< Enhanced fifo filter by mask */
    FLEXCANDRV_ENHRXFF_FILTER_SELECT_RANGE,                      /*!< Enhanced fifo filter by rang */
    FLEXCANDRV_ENHRXFF_FILTER_SELECT_TWO_FILTER_WITHOUT_MASK,    /*!< Enhanced fifo filter by two filter */
} FLEXCANDRV_EnhanceRxFFFilterSelection;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_FIFOFILTERIDTABLE FLEXCAN Rx Fifo ID Filter Structure Group
  * @{
  * @brief  Instance structure for FLEXCAN rx fifo ID filter configuration
  */
 typedef struct _FLEXCANDRV_FifoFilterIdTable_ {
    FLEXCANDRV_RxFifoIDElementFormat idFormat;           /*!< Filter id type */
    bool                             isRemoteFrame;      /*!< Accept remote frame and reject data frame */
    bool                             isExtendedFrame;    /*!< Accept extended frame and reject std frame */
    uint32_t                         id;                 /*!< rx fifo ID */
} FLEXCANDRV_FifoFilterIdTable;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_MSGCFGTYPE FLEXCAN Message Data Configuration Structure Group
  * @{
  * @brief  Instance structure for FLEXCAN message data configuration
  */
typedef struct _FLEXCANDRV_MsgCfgType_ {
    uint16_t                   msgBufId;          /*!< Message buffer index to handle this message object */
    uint16_t                   msgBufLen;         /*!< Defines number of message buffer to handle this specific
                                                       message object configuration, if msgBufLen = 1, then only
                                                       single message buffer allocated to this message object,
                                                       which is also a common use case, if msgBuf > 1, then multiple
                                                       message buffer will allocated to this message object, which
                                                       will operating as a software message buffer with depth n */
    uint32_t                   msgId;             /*!< Message ID can be either 11-bit or 29-bit depends on the
                                                       configuration of isExtMsgId */
    bool                       isExtMsgId;        /*!< Select extended message ID (29-bit) or standard message
                                                       ID (11-bit) */
    FLEXCANDRV_MsgType         msgType;           /*!< Select message type as Tx message or Rx message */
    FLEXCANDRV_DataLenCodeType dlc;               /*!< Message data length code */
    bool                       isFd;              /*!< Select message as classic CAN message or flexible data rate
                                                       message */
    bool                       intEnable;         /*!< Message Tx / Rx complete interrupt enable */
    uint32_t                   individualMask;    /*!< Rx indivudual mask for mailbox n */
    bool                       rtrmask;           /*!< RTR mask bit only for canfd enhanced fifo */
    bool                       rtrfilter;         /*!< RTR filter bit only for canfd enhanced fifo */
} FLEXCANDRV_MsgCfgType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_MSGOBJTYPE FLEXCAN Message Object Data Structure Group
  * @{
  * @brief  Instance structure for FLEXCAN message object data configuration
  */
typedef struct _FLEXCANDRV_MsgObjType_ {
    uint8_t  msgBufId;       /*!< Unique ID for message where it located in message buffer */
    uint32_t msgId;          /*!< 11-bit or 29-bit message ID */
    uint8_t  data[64];       /*!< Message data field. Maximum 64 bytes, the valid length was
                                  determined by message DLC */
    uint8_t  dlc;            /*!< Message DLC get from the latest received message */
    bool     isFd;           /*!< Indicate message is classic CAN message or CANFD message
                                  0: CAN message, 1: CANFD message */
    uint16_t timeStamp;      /*!< time stamp for the received message */
    uint32_t hrTimeStamp;    /*!< high-resolution time stamp for the received message */
} FLEXCANDRV_MsgObjType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_BITTIMINGTYPE FLEXCAN Bit Timing Configure Structure Group
  * @{
  * @brief  Instance structure for FLEXCAN bit timing configuration
  */
typedef struct _FLEXCANDRV_BitTimingType_ {
    uint32_t prescalerDiv;       /*!< Pre-scaler division factor, defines the ratio between CAN module
                                      clock frequency and the serial clock frequency in the data bit
                                      rate portion */
    uint32_t resyncJumpWidth;    /*!< Re-sync jump width, the maximum number of time quanta that a bit
                                      time can be changed by one re-synchronization */
    uint32_t propSeg;            /*!< Propagation segment, defines the length of propagation segment in
                                      the bit time */
    uint32_t phaseSeg1;          /*!< Phase segment 1, defines the length of phase segment 1 in bit time */
    uint32_t phaseSeg2;          /*!< Phase segment 2, defines the length of phase segment 2 in bit time */
} FLEXCANDRV_BitTimingType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_INITHWPARTYPE FLEXCAN Init Paramaters Structure Group
  * @{
  * @brief  Instance structure for FLEXCAN init paramaters configuration
  */
typedef struct _FLEXCANDRV_InitHwParType_ {
    uint8_t canInstanceIdx;    /*!< Idx = 0 means CAN1; Idx = 1 means CANFD */
    uint8_t canRamNum;         /*!< RAM number for FLEXCAN message buffer (each RAM block has 512 bytes) */
} FLEXCANDRV_InitHwParType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_CONTROLLERCFGTYPE FLEXCAN Controller Configuration Structure Group
  * @{
  * @brief  Instance structure for FLEXCAN controller configuration
  */
typedef struct _FLEXCANDRV_ControllerCfgType_ {
    FLEXCANDRV_ClkSrcType                  clkSrc;                     /*!< Select the clock source for CAN module */
    bool                                   fdEnable;                   /*!< Flexible data rate enable */
    bool                                   fdISOEnable;                /*!< ISO CAN FD enable */
    bool                                   fifoEnable;                 /*!< Legacy rx fifo enable */
    bool                                   enhancefifoEnable;          /*!< Enhance rx fifo enable */
    bool                                   dmaEnable;                  /*!< Rx fifo DMA enable */
    FLEXCANDRV_BitTimingType               bitTiming;                  /*!< Nominal CAN bit timing struct */
    FLEXCANDRV_BitTimingType               fdBitTiming;                /*!< FD CAN bit timing struct */
    uint8_t                                msgBufDataLenSel;           /*!< Message buffer data size selection */
    uint32_t                               rxMBGlobalMask;             /*!< Rx mailbox global mask */
    uint32_t                               rxMB14Mask;                 /*!< Rx mailbox 14 mask */
    uint32_t                               rxMB15Mask;                 /*!< Rx mailbox 15 mask */
    uint32_t                               rxFifoGlobalMask;           /*!< Rx fifo global mask */
    uint8_t                                rxFifoFilternum;            /*!< Rx fifo filter table num */
    uint32_t                               Legacyfifomask[128];        /*!< Rx fifo filter id mask array*/
    bool                                   individualMaskEnable;       /*!< Rx individual mask enable */
    bool                                   loopbackEnable;             /*!< Loopback mode enable */
    bool                                   listenMode;                 /*!< Listen mode enable */
    bool                                   tdcEnable;                  /*!< Transceiver delay compensation enable */
    uint8_t                                tdcOffset;                  /*!< Transceiver delay compensation offset */
    uint8_t                                msgNum;                     /*!< Number of messages */
    const FLEXCANDRV_MsgCfgType            *msgCfg;                    /*!< Message configuration array */
    const FLEXCANDRV_FifoFilterIdTable     *filterIdtable;             /*!< Fifo filter id configuration array */
    bool                                   edgeWkupEnable;             /*!< CAN edge wakeup enable */
    bool                                   WkupIntEnable;              /*!< CAN edge wakeup interrupt enable */
    bool                                   txAbortEnable;              /*!< Tx pending message abort mechanism enable */
    bool                                   busoffIntEnable;            /*!< Busoff interrupt enable */
    bool                                   errorIntEnable;             /*!< Error interrupt enable */
    bool                                   warningIntEnable;           /*!< Tx&rx warning interrupt enable */
    FLEXCANDRV_EnhanceRxFFFilterSelection  enhRxFFFilterSelection;     /*!< Enhanced fifo filter type selection */
    uint8_t                                enhRxFifoWatermark;         /*!< Enhanced fifo water mark set */
    bool                                   enhRxFifoufwIntEnable;      /*!< Enhanced fifo underflow int enable */
    bool                                   enhRxFifoovfIntEnable;      /*!< Enhanced fifo overflow int enable */
    bool                                   enhRxFifowmIntEnable;       /*!< Enhanced fifo watermark int enable */
    bool                                   enhRxFifodataIntEnable;     /*!< Enhanced fifo data avaiable int enable */
    bool                                   freeRunningByExtTmrEn;      /*!< Free running timer by 
                                                                            external time tick or not */
    FLEXCANDRV_HRTmrCapturePointSelectType hrTmrCapturePointSelect;    /*!< High-resolution timer capture point select */
    FLEXCANDRV_MBTmrBaseSelectType         mbTmrBaseSelect;            /*!< MBs time stamp base */
    bool                                   selected3bitSampling;       /*!< One or three sample used to determine 
                                                                            the bit value */
    bool                                   pnModeEn;                   /*!< PN mode enable */
    FLEXCANDRV_PnWkpEventType              pnWkpEvent;                 /*!< PN Wake up event select */
    uint8_t                                pnMatchNum;                 /*!< PN match num select  */
    FLEXCANDRV_PnPayloadFilterSelectType   pnPayloadFilterSelect;      /*!< PN payload filter select */
    FLEXCANDRV_PnIdFilterSelectType        pnIdFilterSelect;           /*!< PN ID filter select */
    FLEXCANDRV_PnFilterComSelType          pnFilterCombinSelect;       /*!< PN filter combination select */
    uint16_t                               pnNoMsgTimeoutCnt;          /*!< PN message timeout value */
    uint32_t                               pnFilterId1;                /*!< PN filter 1 */
    uint32_t                               pnMaskId1;                  /*!< PN mask 1 */
    uint8_t                                pnDlcFilter;                /*!< PN dlc filter value */
    uint8_t                                pnPayloadFilterData[8];     /*!< PN payload filter buff */
    uint8_t                                pnPayloadMaskData[8];       /*!< PN payload mask buff */
} FLEXCANDRV_ControllerCfgType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_ERRSTATUSTYPE FLEXCAN Error Status Structure Group
  * @{
  * @brief  Instance structure for FLEXCAN error status configuration
  */
typedef struct _FLEXCANDRV_ErrStatusType_ {
    FLEXCANDRV_FltConfStsType fltConfSts;       /*!< Fault confinement state */
    uint8_t                   bit1FastErr;      /*!< Bit 1 error in FD message data phase */
    uint8_t                   bit0FastErr;      /*!< Bit 0 error in FD message data phase */
    uint8_t                   crcFastErr;       /*!< Crc error in FD message data phase */
    uint8_t                   formFastErr;      /*!< Form error in FD message data phase */
    uint8_t                   stuffFastErr;     /*!< Stuff error in FD message data phase */
    uint8_t                   bit1Err;          /*!< Bit 1 error */
    uint8_t                   bit0Err;          /*!< Bit 0 error */
    uint8_t                   ackErr;           /*!< Acknowledgement error */
    uint8_t                   crcErr;           /*!< Crc error */
    uint8_t                   formErr;          /*!< Form error */
    uint8_t                   stuffErr;         /*!< Stuff error */
    uint8_t                   errOvr;           /*!< Error overrun */
    uint8_t                   busOffDoneInt;    /*!< Busoff done interrupt */
    uint8_t                   errFastInt;       /*!< Rrror interrupt in FD message data phase */
    uint8_t                   synch;            /*!< Synchronization status for CAN bus */
    uint8_t                   txWarnintInt;     /*!< Tx warning interrupt */
    uint8_t                   rxWarningInt;     /*!< Rx warning interrupt */
    uint8_t                   txWarning;        /*!< Tx warning */
    uint8_t                   rxWarning;        /*!< Rx warning */
    uint8_t                   busOffInt;        /*!< Busoff interrupt */
    uint8_t                   errInt;           /*!< Error interrupt */
    uint8_t                   wakeUpInt;        /*!< Wakeup interrupt */
} FLEXCANDRV_ErrStatusType;

/**
  * @}
  */

/** @defgroup FLEXCANDRV_TYPE FLEXCAN Driver Structure Group
  * @{
  * @brief  Instance structure for FLEXCAN driver configuration
  */
typedef struct _FLEXCANDRV_Type_ {
    FLEXCANREG_TypeDef       *flexCanReg;    /*!< Pointer to a FLEXCANREG_TypeDef structure */
    FLEXCANDRV_InitHwParType initHwPar;      /*!< Pointer to a FLEXCANDRV_InitHwParType structure */
} FLEXCANDRV_Type;

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
  * \brief  Get message buffer start address
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the message buffer start address
  */
static inline uint32_t FLEXCANREG_GetMsgBufferStartAddr (FLEXCANREG_TypeDef *obj)
{
    return (uint32_t)(&obj->MSGBUF[0]);
}

/**
  * \brief  Get enhanced rx fifo start address
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the enhanced rx fifo start address
  */
static inline uint32_t FLEXCANREG_GetEnhRxFifoStartAddr (FLEXCANREG_TypeDef *obj)
{
    return (uint32_t)(&obj->ENHRXFIFO[0]);
}

/**
  * \brief  Get enhanced rx fifo filter start address
  * \param  obj              FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  filtElementNo    rx fifo filter element ID
  *                           - This parameter is an unsigned integer that is greater
  *                             than or equal to 0 and less than or equal to 127
  * \return Returns the enhanced rx fifo filter start address
  */
static inline uint32_t FLEXCANREG_GetEnhRxFifoFilterStartAddr (FLEXCANREG_TypeDef *obj, uint8_t filtElementNo)
{
    return (uint32_t)(&obj->ERFFEL[filtElementNo]);
}

/**
  * \brief  Get FLEXCAN module disable status
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the module disable status
  *                 - 0: the FLEXCAN module enabled
  *                 - 1: the FLEXCAN module disabled
  */
static inline uint8_t FLEXCANREG_GetModuleDisable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->MCR & FLEXCAN_MCR_MDIS_MASK) >> FLEXCAN_MCR_MDIS_SHIFT);
}

/**
  * \brief  Set FLEXCAN module enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    module enable
  *                    - 0: enable the FLEXCAN module
  *                    - 1: disable the FLEXCAN module
  */
static inline void FLEXCANREG_SetModuleDisable (FLEXCANREG_TypeDef *obj, uint8_t isDisable)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_MDIS_MASK);
    tempReg |= (((uint32_t)isDisable) << FLEXCAN_MCR_MDIS_SHIFT) & FLEXCAN_MCR_MDIS_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get FLEXCAN freeze mode
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the module freeze mode status
  *                 - 0: not enabled to enter freeze mode
  *                 - 1: enabled to enter freeze mode
  */
static inline uint8_t FLEXCANREG_GetFreezeMode (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->MCR & FLEXCAN_MCR_FRZ_MASK) >> FLEXCAN_MCR_FRZ_SHIFT);
}

/**
  * \brief  Set FLEXCAN freeze mode
  * \param  obj           FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  frzModeReq    freeze mode request
  *                        - 0: disable to enter freeze mode
  *                        - 1: enable to enter freeze mode
  */
static inline void FLEXCANREG_SetFreezeMode (FLEXCANREG_TypeDef *obj, uint8_t frzModeReq)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_FRZ_MASK);
    tempReg |= (((uint32_t)frzModeReq) << FLEXCAN_MCR_FRZ_SHIFT) & FLEXCAN_MCR_FRZ_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get rx fifo enable status
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the module freeze mode
  *                 - 0: rx fifo is disabled
  *                 - 1: rx fifo is enabled
  */
static inline uint8_t FLEXCANREG_GetRxFifoEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->MCR & FLEXCAN_MCR_RFEN_MASK) >> FLEXCAN_MCR_RFEN_SHIFT);
}

/**
  * \brief  Set rx fifo enable status
  * \param  obj           FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  fifoEnable    freeze mode request
  *                        - 0: disbale the rx fifo 
  *                        - 1: enable the rx fifo 
  */
static inline void FLEXCANREG_SetRxFifoEnable (FLEXCANREG_TypeDef *obj, uint8_t fifoEnable)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_RFEN_MASK);
    tempReg |= (((uint32_t)fifoEnable) << FLEXCAN_MCR_RFEN_SHIFT) & FLEXCAN_MCR_RFEN_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get Halt mode status
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the module freeze mode
  *                 - 0: request halt mode
  *                 - 1: no halt mode reuqest
  */
static inline uint8_t FLEXCANREG_GetHaltMode (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->MCR & FLEXCAN_MCR_HALT_MASK) >> FLEXCAN_MCR_HALT_SHIFT);
}

/**
  * \brief  Set Halt mode
  * \param  obj            FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  haltModeReq    halt mode request
  *                         - 0: request halt mode
  *                         - 1: no request halt mode
  */
static inline void FLEXCANREG_SetHaltMode (FLEXCANREG_TypeDef *obj, uint8_t haltModeReq)
{
    uint32_t tempReg;
    
    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_HALT_MASK);
    tempReg |= (((uint32_t)haltModeReq) << FLEXCAN_MCR_HALT_SHIFT) & FLEXCAN_MCR_HALT_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get not ready flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns not ready flag
  *                 - 0: FLEXCAN is either in normal, listen-only, or loop-back mode
  *                 - 1: FLEXCAN is either in module disable, doze, stop, or freeze mode
  */
static inline uint8_t FLEXCANREG_GetNotReadyFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->MCR & FLEXCAN_MCR_NOTRDY_MASK) >> FLEXCAN_MCR_NOTRDY_SHIFT);
}

/**
  * \brief  Get wakeup interrupt mask
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns wakeup interrupt mask
  *                 - 0: disable wakeup interrupt
  *                 - 1: enable wakeup interrupt
  */
static inline uint8_t FLEXCANREG_GetWakupIntMask (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->MCR & FLEXCAN_MCR_WAKMSK_MASK) >> FLEXCAN_MCR_WAKMSK_SHIFT);
}

/**
  * \brief  Set wakeup interrupt mask
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    wakeup interrupt mask enable
  *                    - 0: disable wakeup interrupt
  *                    - 1: enable wakeup interrupt
  */
static inline void FLEXCANREG_SetWakeupIntMask (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_WAKMSK_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_MCR_WAKMSK_SHIFT) & FLEXCAN_MCR_WAKMSK_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get soft reset request
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns soft reset request
  *                 - 0: no reset request
  *                 - 1: reset the registers affected by soft reset
  */
static inline uint8_t FLEXCANREG_GetSoftResetRequest (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->MCR & FLEXCAN_MCR_SOFTRST_MASK) >> FLEXCAN_MCR_SOFTRST_SHIFT);
}

/**
  * \brief  Set soft reset request
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    soft reset request
  *                    - 0: no reset request
  *                    - 1: reset the registers affected by soft reset
  */
static inline void FLEXCANREG_SetSoftResetRequest (FLEXCANREG_TypeDef *obj, uint8_t softRstReq)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_SOFTRST_MASK);
    tempReg |= (((uint32_t)softRstReq) << FLEXCAN_MCR_SOFTRST_SHIFT) & FLEXCAN_MCR_SOFTRST_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get freeze mode acknowledge
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns freeze mode acknowledge
  *                 - 0: FLEXCAN not in freeze mode, prescaler running
  *                 - 1: FLEXCAN in freeze mode, prescaler stopped
  */
static inline uint8_t FLEXCANREG_GetFreezeAck (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->MCR & FLEXCAN_MCR_FRZACK_MASK) >> FLEXCAN_MCR_FRZACK_SHIFT);
}

/**
  * \brief  Get FLEXCAN access mode
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the access mode
  *                 - 0: FLEXCAN is in user mode, affected registers allow both
  *                      supervisor and unrestricted access
  *                 - 1: FLEXCAN is in supervisor mode. Affected registers allow
  *                      only supervisor access. Unrestricted access behaves as
  *                      though the access was done to an unnimplemented register
  *                      location
  */
static inline uint8_t FLEXCANREG_GetAccessMode (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->MCR & FLEXCAN_MCR_SUPV_MASK) >> FLEXCAN_MCR_SUPV_SHIFT);
}

/**
  * \brief  Set FLEXCAN access mode
  * \param  obj        FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  accMode    access mode
  *                     - 0: FLEXCAN is in user mode, affected registers allow both
  *                          supervisor and unrestricted access
  *                     - 1: FLEXCAN is in supervisor mode. Affected registers allow
  *                          only supervisor access. Unrestricted access behaves as
  *                          though the access was done to an unimplemented register
  *                          location.
  */
static inline void FLEXCANREG_SetAccessMode (FLEXCANREG_TypeDef *obj, uint8_t accMode)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_SUPV_MASK);
    tempReg |= (((uint32_t)accMode) << FLEXCAN_MCR_SUPV_SHIFT) & FLEXCAN_MCR_SUPV_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get self wakeup enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns self wakeup enable
  *                 - 0: FLEXCAN self wakeup feature is disabled
  *                 - 1: FLEXCAN self wakeup feature is enabled
  */
static inline uint8_t FLEXCANREG_GetSelfWakeupEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->MCR & FLEXCAN_MCR_SLFWAK_MASK) >> FLEXCAN_MCR_SLFWAK_SHIFT);
}

/**
  * \brief  Set self wakeup enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    self wakeup enable
  *                    - 0: disable FLEXCAN self wakeup feature
  *                    - 1: enable FLEXCAN self wakeup feature
  */
static inline void FLEXCANREG_SetSelfWakeupEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_SLFWAK_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_MCR_SLFWAK_SHIFT) & FLEXCAN_MCR_SLFWAK_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get self warning interrupt enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns warning interrupt enable
  *                 - 0: warning interrupt is disabled
  *                 - 1: warning interrupt is enabled
  */
static inline uint8_t FLEXCANREG_GetWarningIntEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->MCR & FLEXCAN_MCR_WRNEN_MASK) >> FLEXCAN_MCR_WRNEN_SHIFT);
}

/**
  * \brief  Set self warning interrupt enable
  * \param  obj       pointer to flexCAN register instance
  * \param  enable    warning interrupt enable
  *                    - 0: disable warning interrupt 
  *                    - 1: enable warning interrupt 
  */
static inline void FLEXCANREG_SetWarningIntEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_WRNEN_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_MCR_WRNEN_SHIFT) & FLEXCAN_MCR_WRNEN_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get low power mode acknowledge
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns low power mode acknowledge
  *                 - 0: FLEXCAN is not in a low power mode
  *                 - 1: FLEXCAN is in a low power mode
  */
static inline uint8_t FLEXCANREG_GetLowPowerAck (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->MCR & FLEXCAN_MCR_LPMACK_MASK) >> FLEXCAN_MCR_LPMACK_SHIFT);
}

/**
  * \brief  Get wake up source
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns wake up source
  *                 - 0: use the unfiltered Rx input to detect recessive-to-dominant edges on the CAN bus
  *                 - 1: use the filtered Rx input to detect recessive-to-dominant edges on the CAN bus
  */
static inline uint8_t FLEXCANREG_GetWakeupSource (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->MCR & FLEXCAN_MCR_WAKSRC_MASK) >> FLEXCAN_MCR_WAKSRC_SHIFT);
}

/**
  * \brief  Set wake up source
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    wake up source
  *                    - 0: use the unfiltered Rx input to detect recessive-to-dominant edges on the CAN bus
  *                    - 1: use the filtered Rx input to detect recessive-to-dominant edges on the CAN bus
  */
static inline void FLEXCANREG_SetWakeupSource (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_WAKSRC_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_MCR_WAKSRC_SHIFT) & FLEXCAN_MCR_WAKSRC_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get doze mode enable status
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns doze mode enable status
  *                 - 0: FLEXCAN is not enabled to enter low-power mode when Doze mode is request
  *                 - 1: FLEXCAN is enabled to enter low-power mode when Doze mode is request
  */
static inline uint8_t FLEXCANREG_GetDozeMode (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->MCR & FLEXCAN_MCR_DOZE_MASK) >> FLEXCAN_MCR_DOZE_SHIFT);
}

/**
  * \brief  Set doze mode enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    doze mode enable
  *                    - 0: FLEXCAN is not enabled to enter low-power mode when doze mode is request
  *                    - 1: FLEXCAN is enabled to enter low-power mode when doze mode is request
  */
static inline void FLEXCANREG_SetDozeMode (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_DOZE_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_MCR_DOZE_SHIFT) & FLEXCAN_MCR_DOZE_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get self reception
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns self reception enable
  *                 - 0: self reception is enabled
  *                 - 1: self reception is disabled
  */
static inline uint8_t FLEXCANREG_GetSelfReceptionDisable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->MCR & FLEXCAN_MCR_SRXDIS_MASK) >> FLEXCAN_MCR_SRXDIS_SHIFT);
}

/**
  * \brief  Set self reception
  * \param  obj          pointer to FLEXCAN register instance
  * \param  isDisable    self reception enable
  *                       - 0: enable self reception 
  *                       - 1: disable self reception 
  */
static inline void FLEXCANREG_SetSelfReceptionDisable (FLEXCANREG_TypeDef *obj, uint8_t isDisable)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_SRXDIS_MASK);
    tempReg |= (((uint32_t)isDisable) << FLEXCAN_MCR_SRXDIS_SHIFT) & FLEXCAN_MCR_SRXDIS_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get rx individual mask enable status
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns individual mask enable status
  *                 - 0: individual mask is disabled
  *                 - 1: individual mask is enabled
  */
static inline uint8_t FLEXCANREG_GetIndividualMaskEnable (FLEXCANREG_TypeDef *obj)
{
    return ((obj->MCR & FLEXCAN_MCR_IRMQ_MASK) >> FLEXCAN_MCR_IRMQ_SHIFT);
}

/**
  * \brief  Set rx individual mask
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    self reception enable
  *                    - 0: disable self reception 
  *                    - 1: enable self reception 
  */
static inline void FLEXCANREG_SetIndividualMaskEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_IRMQ_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_MCR_IRMQ_SHIFT) & FLEXCAN_MCR_IRMQ_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get rx fifo dma enable or disable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns rx fifo dma enable
  *                 - 0: rx fifo dma is disabled
  *                 - 1: rx fifo dma is enabled
  */
static inline uint8_t FLEXCANREG_GetRxFifoDmaEnable (FLEXCANREG_TypeDef *obj)
{
    return ((obj->MCR & FLEXCAN_MCR_DMA_MASK) >> FLEXCAN_MCR_DMA_SHIFT);
}

/**
  * \brief  Set rx fifo dma enable or disable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    rx fifo dma enable
  *                    - 0: disable rx fifo dma 
  *                    - 1: enable rx fifo dma 
  */
static inline void FLEXCANREG_SetRxFifoDmaEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_DMA_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_MCR_DMA_SHIFT) & FLEXCAN_MCR_DMA_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get local priority enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns local priority enable
  *                 - 0: local priority is disabled
  *                 - 1: local priority is enabled
  */
static inline uint8_t FLEXCANREG_GetMcrLprioen (FLEXCANREG_TypeDef *obj)
{
    return ((obj->MCR & FLEXCAN_MCR_LPRIOEN_MASK) >> FLEXCAN_MCR_LPRIOEN_SHIFT);
}

/**
  * \brief  Set local priority enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    local priority enable
  *                    - 0: disable local priority 
  *                    - 1: enable local priority 
  */
static inline void FLEXCANREG_SetMcrLprioen (FLEXCANREG_TypeDef *obj, uint8_t value)
{
    uint32_t tmp = obj->MCR;

    tmp &= ~FLEXCAN_MCR_LPRIOEN_MASK;
    tmp |= (((uint32_t)(((uint32_t)(value)) << FLEXCAN_MCR_LPRIOEN_SHIFT)) & FLEXCAN_MCR_LPRIOEN_MASK);
    obj->MCR = tmp;
}

/**
  * \brief  Set rx acceptance id mode
  * \param  obj     FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  idam    rx acceptance id mode
  *                  - 00b: Format-A – One full ID (standard and extended) per ID Filter Table element
  *                  - 01b: Format-B – Two full standard IDs or two partial 14-bit (standard and extended) 
  *                         IDs per ID Filter Table element
  *                  - 10b: Format-C – Four partial 8-bit standard IDs per ID Filter Table element
  *                  - 11b: Format-D – All frames rejected
  */
static inline void FLEXCANREG_SetRxIdAcceptanceMode (FLEXCANREG_TypeDef *obj, uint8_t idam)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_IDAM_MASK);
    tempReg |= (((uint32_t)idam) << FLEXCAN_MCR_IDAM_SHIFT) & FLEXCAN_MCR_IDAM_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get rx acceptance id mode
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns rx acceptance id mode
  *                 - 00b: Format-A – One full ID (standard and extended) per ID Filter Table element
  *                 - 01b: Format-B – Two full standard IDs or two partial 14-bit (standard and extended)
  *                        IDs per ID Filter Table element
  *                 - 10b: Format-C – Four partial 8-bit standard IDs per ID Filter Table element
  *                 - 11b: Format-D – All frames rejected
  */
static inline uint32_t FLEXCANREG_GetRxIdAcceptanceMode (FLEXCANREG_TypeDef *obj)
{
    uint8_t  idam = 0;
    uint32_t tempReg;

    tempReg = obj->MCR;

    idam = ((tempReg & FLEXCAN_MCR_IDAM_MASK) >> FLEXCAN_MCR_IDAM_SHIFT);

    return idam;
}

/**
  * \brief  Set max buffer numbers
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  maxNum    max buffer numbers
  *                    - This parameter is an unsigned integer that is greater 
  *                      than 0x00 and less than or equal to 0x7F
  */
static inline void FLEXCANREG_SetMaxMsgBufferNum (FLEXCANREG_TypeDef *obj, uint8_t maxNum)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_MAXMB_MASK);
    tempReg |= (((uint32_t)maxNum) << FLEXCAN_MCR_MAXMB_SHIFT) & FLEXCAN_MCR_MAXMB_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get max buffer numbers
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns max buffer numbers
  *                 - This parameter is an unsigned integer that is greater 
  *                   than 0x00 and less than or equal to 0x7F
  */
static inline uint32_t FLEXCANREG_GetMaxMsgBufferNum (FLEXCANREG_TypeDef *obj)
{
    uint8_t  maxNum;
    uint32_t tempReg;

    tempReg = obj->MCR;
    maxNum = ((tempReg & FLEXCAN_MCR_MAXMB_MASK) >> FLEXCAN_MCR_MAXMB_SHIFT);

    return maxNum;
}

/**
  * \brief  Get pretended networking enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns Pretended Networking Enable
  *                 - 0: the pretended networking mode is disabled
  *                 - 1: the pretended networking mode is enabled
  */
static inline uint8_t FLEXCANREG_GetMcrPneten (FLEXCANREG_TypeDef *obj)
{
    return ((obj->MCR & FLEXCAN_MCR_PNET_EN_MASK) >> FLEXCAN_MCR_PNET_EN_SHIFT);
}

/**
  * \brief  Enables the pretended networking function
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    enable or disable pn mode 
  *                   - 0: disable pretended networking mode
  *                   - 1: enable pretended networking mode
  */
static inline void FLEXCANREG_SetMcrPneten (FLEXCANREG_TypeDef *obj, uint8_t value)
{
    uint32_t tmp = obj->MCR;

    tmp &= ~FLEXCAN_MCR_PNET_EN_MASK;
    tmp |= (((uint32_t)(((uint32_t)(value)) << FLEXCAN_MCR_PNET_EN_SHIFT)) & FLEXCAN_MCR_PNET_EN_MASK);
    obj->MCR = tmp;
}

/**
  * \brief  Get Tx message pending abort mechanism enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns Tx message pending abort mechanism enable
  *                 - 0: Tx abort is disabled
  *                 - 1: Tx abort is enabled
  */
static inline uint8_t FLEXCANREG_GetTxAbortEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->MCR & FLEXCAN_MCR_AEN_MASK) >> FLEXCAN_MCR_AEN_SHIFT);
}

/**
  * \brief  Set Tx message pending abort mechanism enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    Tx message pending abort mechanism enable
  *                    - 0: disable Tx abort
  *                    - 1: enable Tx abort
  */
static inline void FLEXCANREG_SetTxAbortEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_AEN_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_MCR_AEN_SHIFT) & FLEXCAN_MCR_AEN_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Set CAN FD feature enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    CAN FD feature enable
  *                    - 0: disable canfd feature
  *                    - 1: enable canfd feature
  */
static inline void FLEXCANREG_SetFdEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->MCR;
    tempReg &= (~FLEXCAN_MCR_FDEN_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_MCR_FDEN_SHIFT) & FLEXCAN_MCR_FDEN_MASK;
    obj->MCR = tempReg;
}

/**
  * \brief  Get CAN FD feature enable status
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns CAN FD feature enable status
  *                 - 0: canfd feature is disabled
  *                 - 1: canfd feature is enabled
  */
static inline uint8_t FLEXCANREG_GetFdEnable (FLEXCANREG_TypeDef *obj)
{
    uint8_t  enable = 0;
    uint32_t tempReg;

    tempReg = obj->MCR;

    if (((tempReg & FLEXCAN_MCR_FDEN_MASK) >> FLEXCAN_MCR_FDEN_SHIFT) != 0)
    {
        enable = 1;
    }

    return enable;

}

/**
  * \brief  Get prescaler division factor
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the prescaler division factor
  *                 - This parameter is an unsigned integer that is greater 
  *                   than or equal to 0x00 and less than or equal to 0xFF
  */
static inline uint8_t FLEXCANREG_GetCtrl1Presdiv (FLEXCANREG_TypeDef *obj)
{
    return ((obj->CTRL1 & FLEXCAN_CTRL1_PRESDIV_MASK) >> FLEXCAN_CTRL1_PRESDIV_SHIFT);
}

/**
  * \brief  Set prescaler division factor
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    prescaler division factor value
  *                   - This parameter is an unsigned integer that is greater 
  *                     than or equal to 0x00 and less than or equal to 0xFF
  */
static inline void FLEXCANREG_SetCtrl1Presdiv (FLEXCANREG_TypeDef *obj, uint8_t value)
{
    uint32_t tmp = obj->CTRL1;

    tmp &= ~FLEXCAN_CTRL1_PRESDIV_MASK;
    tmp |= (((uint32_t)(((uint32_t)(value)) << FLEXCAN_CTRL1_PRESDIV_SHIFT)) & FLEXCAN_CTRL1_PRESDIV_MASK);
    obj->CTRL1 = tmp;
}

/**
  * \brief  Get the resync jump width
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the resync jump width
  *                 - This parameter is an unsigned integer that is greater 
  *                   than or equal to 0x0 and less than or equal to 0x3
  */
static inline uint8_t FLEXCANREG_GetCtrl1Rjw (FLEXCANREG_TypeDef *obj)
{
    return ((obj->CTRL1 & FLEXCAN_CTRL1_RJW_MASK) >> FLEXCAN_CTRL1_RJW_SHIFT);
}

/**
  * \brief  Set resync jump width
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    resync jump width
  *                   - This parameter is an unsigned integer that is greater 
  *                     than or equal to 0x0 and less than or equal to 0x3
  */
static inline void FLEXCANREG_SetCtrl1Rjw (FLEXCANREG_TypeDef *obj, uint8_t value)
{
    uint32_t tmp = obj->CTRL1;

    tmp &= ~FLEXCAN_CTRL1_RJW_MASK;
    tmp |= (((uint32_t)(((uint32_t)(value)) << FLEXCAN_CTRL1_RJW_SHIFT)) & FLEXCAN_CTRL1_RJW_MASK);
    obj->CTRL1 = tmp;
}

/**
  * \brief  Get phase segment 1
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the phase segment1 value
  *                 - This parameter is an unsigned integer that is greater 
  *                   than or equal to 0x0 and less than or equal to 0x7
  */
static inline uint8_t FLEXCANREG_GetCtrl1Pseg1 (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CTRL1 & FLEXCAN_CTRL1_PSEG1_MASK) >> FLEXCAN_CTRL1_PSEG1_SHIFT);
}

/**
  * \brief  Set phase segment 1
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    phase segment1
  *                   - This parameter is an unsigned integer that is greater 
  *                     than or equal to 0x0 and less than or equal to 0x7
  */
static inline void FLEXCANREG_SetCtrl1Pseg1 (FLEXCANREG_TypeDef *obj, uint8_t value)
{
    uint32_t tmp = obj->CTRL1;

    tmp &= ~FLEXCAN_CTRL1_PSEG1_MASK;
    tmp |= (((uint32_t)(((uint32_t)(value)) << FLEXCAN_CTRL1_PSEG1_SHIFT)) & FLEXCAN_CTRL1_PSEG1_MASK);
    obj->CTRL1 = tmp;
}

/**
  * \brief  Get phase segment 2
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the phase segment2
  *                 - This parameter is an unsigned integer that is greater 
  *                   than or equal to 0x0 and less than or equal to 0x7
  */
static inline uint8_t FLEXCANREG_GetCtrl1Pseg2 (const FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CTRL1 & FLEXCAN_CTRL1_PSEG2_MASK) >> FLEXCAN_CTRL1_PSEG2_SHIFT);
}

/**
  * \brief  Set phase segment 2
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    phase segment2
  *                   - This parameter is an unsigned integer that is greater 
  *                     than or equal to 0x0 and less than or equal to 0x7
  */
static inline void FLEXCANREG_SetCtrl1Pseg2 (FLEXCANREG_TypeDef *obj, uint8_t value)
{
    uint32_t tmp = obj->CTRL1;

    tmp &= ~FLEXCAN_CTRL1_PSEG2_MASK;
    tmp |= (((uint32_t)(((uint32_t)(value)) << FLEXCAN_CTRL1_PSEG2_SHIFT)) & FLEXCAN_CTRL1_PSEG2_MASK);
    obj->CTRL1 = tmp;
}

/**
  * \brief  Set bus off interrupt enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    bus off interrupt enable
  *                    - 0: bus off interrupt disable
  *                    - 1: bus off interrupt enable
  */
static inline void FLEXCANREG_SetBusOffIntEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->CTRL1;
    tempReg &= (~FLEXCAN_CTRL1_BOFFMSK_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_CTRL1_BOFFMSK_SHIFT) & FLEXCAN_CTRL1_BOFFMSK_MASK;
    obj->CTRL1 = tempReg;
}

/**
  * \brief  Get bus off interrupt enable status
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns bus off interrupt enable status
  *                 - 0: the bus off interrupt is disabled
  *                 - 1: the bus off interrupt is enabled
  */
static inline uint8_t FLEXCANREG_GetBusOffIntEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->CTRL1) & FLEXCAN_CTRL1_BOFFMSK_MASK) >> FLEXCAN_CTRL1_BOFFMSK_SHIFT);
}

/**
  * \brief  Set error interrupt enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    error interrupt enable
  *                    - 0: disable error interrupt 
  *                    - 1: enable error interrupt 
  */
static inline void FLEXCANREG_SetErrorIntEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->CTRL1;
    tempReg &= (~FLEXCAN_CTRL1_ERRMSK_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_CTRL1_ERRMSK_SHIFT) & FLEXCAN_CTRL1_ERRMSK_MASK;
    obj->CTRL1 = tempReg;
}

/**
  * \brief  Get error interrupt enable status
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns error interrupt enable status
  *                 - 0: error interrupt is disabled
  *                 - 1: error interrupt is enabled
  */
static inline uint8_t FLEXCANREG_GetErrorIntEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->CTRL1) & FLEXCAN_CTRL1_ERRMSK_MASK) >> FLEXCAN_CTRL1_ERRMSK_SHIFT);
}

/**
  * \brief  Get module clock source
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the module clock source
  *                 - 0: the PE clock source is the oscillator clock
  *                 - 1: the PE clock source is the peripheral clock
  */
static inline uint8_t FLEXCANREG_GetClockSource (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CTRL1 & FLEXCAN_CTRL1_CLKSRC_MASK) >> FLEXCAN_CTRL1_CLKSRC_SHIFT);
}

/**
  * \brief  Selects the clock source to the PE submodule
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  clkSrc    the clock source to the PE submodule
  *                    - 0: the PE clock source is the oscillator clock
  *                    - 1: the PE clock source is the peripheral clock
  */
static inline void FLEXCANREG_SetClockSource (FLEXCANREG_TypeDef *obj, uint8_t clkSrc)
{
    uint32_t tempReg;

    tempReg = obj->CTRL1;
    tempReg &= (~FLEXCAN_CTRL1_CLKSRC_MASK);
    tempReg |= (((uint32_t)(((uint32_t)clkSrc) << FLEXCAN_CTRL1_CLKSRC_SHIFT)) & FLEXCAN_CTRL1_CLKSRC_MASK);
    obj->CTRL1 = tempReg;
}

/**
  * \brief  Get FLEXCAN loop back mode
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the flexcan loop back mode
  *                 - 0: the loop back mode is disabled
  *                 - 1: the loop back mode is enabled
  */
static inline uint8_t FLEXCANREG_GetLoopbackMode (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CTRL1 & FLEXCAN_CTRL1_LPB_MASK) >> FLEXCAN_CTRL1_LPB_SHIFT);
}

/**
  * \brief  Set can loop back mode
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    loop back mode feature select
  *                    - 0: disable the loop back mode
  *                    - 1: enable the loop back mode
  */
static inline void FLEXCANREG_SetLoopbackMode (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->CTRL1;
    tempReg &= (~FLEXCAN_CTRL1_LPB_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_CTRL1_LPB_SHIFT) & FLEXCAN_CTRL1_LPB_MASK;
    obj->CTRL1 = tempReg;
}

/**
  * \brief  Set tx warning interrupt enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    tx warning interrupt enable
  *                    - 0: disable tx warning interrupt 
  *                    - 1: enable tx warning interrupt 
  */
static inline void FLEXCANREG_SetTxWarnIntEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->CTRL1;
    tempReg &= (~FLEXCAN_CTRL1_TWRNMSK_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_CTRL1_TWRNMSK_SHIFT) & FLEXCAN_CTRL1_TWRNMSK_MASK;
    obj->CTRL1 = tempReg;
}

/**
  * \brief  Get tx warning interrupt enable status
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns tx warning interrupt enable status
  *                 - 0: tx warning interrupt is disabled
  *                 - 1: tx warning interrupt is enabled
  */
static inline uint8_t FLEXCANREG_GetTxWarnIntEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->CTRL1) & FLEXCAN_CTRL1_TWRNMSK_MASK) >> FLEXCAN_CTRL1_TWRNMSK_SHIFT);
}

/**
  * \brief  Set rx warning interrupt enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    rx warning interrupt enable
  *                    - 0: disable rx warning interrupt 
  *                    - 1: enable rx warning interrupt 
  */
static inline void FLEXCANREG_SetRxWarnIntEnable(FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->CTRL1;
    tempReg &= (~FLEXCAN_CTRL1_RWRNMSK_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_CTRL1_RWRNMSK_SHIFT) & FLEXCAN_CTRL1_RWRNMSK_MASK;
    obj->CTRL1 = tempReg;
}

/**
  * \brief  Get rx warning interrupt enable status
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns rx warning interrupt enable status
  *                 - 0: rx warning interrupt is disabled
  *                 - 1: rx warning interrupt is enabled
  */
static inline uint8_t FLEXCANREG_GetRxWarnIntEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->CTRL1) & FLEXCAN_CTRL1_RWRNMSK_MASK) >> FLEXCAN_CTRL1_RWRNMSK_SHIFT);
}

/**
  * \brief  Get FLEXCAN bit sampling mode
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns FLEXCAN bit sampling mode
  *                 - 0: one sample is used to determine the bit value
  *                 - 1: three samples are used to determine the bit value
  */
static inline uint8_t FLEXCANREG_GetBitSamplingType (FLEXCANREG_TypeDef *obj)
{
    return ((obj->CTRL1 & FLEXCAN_CTRL1_SMP_MASK) >> FLEXCAN_CTRL1_SMP_SHIFT);
}

/**
  * \brief  Set FLEXCAN bit sampling type
  * \param  obj                FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  threeSamplingEn    FLEXCAN bit sampling
  *                             - 0: one sample is used to determine the bit value
  *                             - 1: three samples are used to determine the bit value
  */
static inline void FLEXCANREG_SetBitSamplingType (FLEXCANREG_TypeDef *obj, uint8_t threeSamplingEn)
{
    uint32_t tempReg;

    tempReg = obj->CTRL1;
    tempReg &= (~FLEXCAN_CTRL1_SMP_MASK);
    tempReg |= (((uint32_t)threeSamplingEn) << FLEXCAN_CTRL1_SMP_SHIFT) & FLEXCAN_CTRL1_SMP_MASK;
    obj->CTRL1 = tempReg;
}

/**
  * \brief  Set bus off automatic recovering enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    bus off automatic recovering enable
  *                    - 0: bus off automatic recovering is enabled
  *                    - 1: bus off automatic recovering disabled
  */
static inline void FLEXCANREG_SetBusOffRecEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->CTRL1;
    tempReg &= (~FLEXCAN_CTRL1_BOFFREC_MASK);
    if (enable == 1)
    {
        tempReg |= (((uint32_t)0UL) << FLEXCAN_CTRL1_BOFFREC_SHIFT) & FLEXCAN_CTRL1_BOFFREC_MASK;
    }
    else
    {
        tempReg |= (((uint32_t)1UL) << FLEXCAN_CTRL1_BOFFREC_SHIFT) & FLEXCAN_CTRL1_BOFFREC_MASK;
    }
    obj->CTRL1 = tempReg;
}

/**
  * \brief  Get bus off automatic recovering enable status
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns bus off automatic recovering enable status
  *                 - 0: bus off automatic recovering is disabled
  *                 - 1: bus off automatic recovering is enabled
  */
static inline uint8_t FLEXCANREG_GetBusOffRecEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->CTRL1) & FLEXCAN_CTRL1_BOFFREC_MASK) >> FLEXCAN_CTRL1_BOFFREC_SHIFT);
}

/**
  * \brief  Set timer synchronze feature enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    timer synchronze feature enable
  *                    - 0: disable timer sync feature
  *                    - 1: enable timer sync feature
  */
static inline void FLEXCANREG_SetTimerSyncEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->CTRL1;
    tempReg &= (~FLEXCAN_CTRL1_TSYN_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_CTRL1_TSYN_SHIFT) & FLEXCAN_CTRL1_TSYN_MASK;
    obj->CTRL1 = tempReg;
}

/**
  * \brief  Get timer synchronze feature enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the synchronze feature enable stauts
  *                  - 0: timer sync feature is disabled
  *                  - 1: timer sync feature is enabled
  */
static inline uint8_t FLEXCANREG_GetTimerSyncEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->CTRL1) & FLEXCAN_CTRL1_TSYN_MASK) >> FLEXCAN_CTRL1_TSYN_SHIFT);
}

/**
  * \brief  Set lowest buffer transmit first enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    set lowest buffer transmit first 
  *                    - 0: disable lowest buffer transmit first
  *                    - 1: enable lowest buffer transmit first
  */
static inline void FLEXCANREG_SetLowestBufTxFirstEna (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->CTRL1;
    tempReg &= (~FLEXCAN_CTRL1_LBUF_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_CTRL1_LBUF_SHIFT) & FLEXCAN_CTRL1_LBUF_MASK;
    obj->CTRL1 = tempReg;
}

/**
  * \brief  Get lowest buffer transmit first enable status
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns lowest buffer transmit first enable status
  *                 - 0: lowest buffer transmit first is disabled
  *                 - 1: lowest buffer transmit first is enabled
  */
static inline uint8_t FLEXCANREG_GetLowestBufTxFirstEna (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->CTRL1) & FLEXCAN_CTRL1_LBUF_MASK) >> FLEXCAN_CTRL1_LBUF_SHIFT);
}

/**
  * \brief  Set listen only mode enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    listen only mode enable
  *                    - 0: disable listen only mode 
  *                    - 1: enable listen only mode 
  */
static inline void FLEXCANREG_SetListenOnlyModeEna (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->CTRL1;
    tempReg &= (~FLEXCAN_CTRL1_LOM_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_CTRL1_LOM_SHIFT) & FLEXCAN_CTRL1_LOM_MASK;
    obj->CTRL1 = tempReg;
}

/**
  * \brief  Get listen only mode enable status 
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns listen only mode enable
  *                 - 0: listen only mode disabled
  *                 - 1: listen only mode enabled
  */
static inline uint8_t FLEXCANREG_GetListenOnlyModeEna (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->CTRL1) & FLEXCAN_CTRL1_LOM_MASK) >> FLEXCAN_CTRL1_LOM_SHIFT);
}

/**
  * \brief  Get propagation segment
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns propagation segment length
  *                 - This parameter is an unsigned integer that is greater 
  *                   than or equal to 0x0 and less than or equal to 0x7
  */
static inline uint8_t FLEXCANREG_GetCtrl1Propseg (const FLEXCANREG_TypeDef *obj)
{
    return ((obj->CTRL1 & FLEXCAN_CTRL1_PROPSEG_MASK) >> FLEXCAN_CTRL1_PROPSEG_SHIFT);
}

/**
  * \brief  Set propagation segment
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    propagation segment length
  *                   - This parameter is an unsigned integer that is greater 
  *                     than or equal to 0x0 and less than or equal to 0x7
  */
static inline void FLEXCANREG_SetCtrl1Propseg (FLEXCANREG_TypeDef *obj, uint8_t value)
{
    uint32_t tmp = obj->CTRL1;

    tmp &= ~FLEXCAN_CTRL1_PROPSEG_MASK;
    tmp |= (((uint32_t)(((uint32_t)(value)) << FLEXCAN_CTRL1_PROPSEG_SHIFT)) & FLEXCAN_CTRL1_PROPSEG_MASK);
    obj->CTRL1 = tmp;
}

/**
  * \brief  Get free running timer
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the free running timer counter
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x0000 and less than or equal to 0xFFFF
  */
static inline uint32_t FLEXCANREG_GetFreeRunningTimer (FLEXCANREG_TypeDef *obj)
{
    return obj->TIMER;
}

/**
  * \brief  Get receive error counter for fast bits
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the receive error counter for fast bits
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0xFF
  */
static inline uint8_t FLEXCANREG_GetEcrRxerrcntfast (const FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->ECR & FLEXCAN_ECR_RXERRCNTFAST_MASK) >> FLEXCAN_ECR_RXERRCNTFAST_SHIFT);
}

/**
  * \brief  Set receive error counter for fast bits
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    the receive error counter for fast bits
  *                   - This parameter is an unsigned integer that is greater
  *                     than or equal to 0x00 and less than or equal to 0xFF
  */ 
static inline void FLEXCANREG_SetEcrRxerrcntfast (FLEXCANREG_TypeDef *obj, uint8_t value)
{
    uint32_t tmp = obj->ECR;

    tmp &= ~FLEXCAN_ECR_RXERRCNTFAST_MASK;
    tmp |= (((uint32_t)(((uint32_t)(value)) << FLEXCAN_ECR_RXERRCNTFAST_SHIFT)) & FLEXCAN_ECR_RXERRCNTFAST_MASK);
    obj->ECR = tmp;
}

/**
  * \brief  Get transmit error counter for fast bits
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the transmit error counter for fast bits
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0xFF
  */
static inline uint8_t FLEXCANREG_GetEcrTxerrcntfast (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->ECR & FLEXCAN_ECR_TXERRCNTFAST_MASK) >> FLEXCAN_ECR_TXERRCNTFAST_SHIFT);
}

/**
  * \brief  Set transmit error counter for fast bits
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    transmit error counter for fast bits
  *                   - This parameter is an unsigned integer that is greater
  *                     than or equal to 0x00 and less than or equal to 0xFF
  */
static inline void FLEXCANREG_SetEcrTxerrcntfast (FLEXCANREG_TypeDef *obj, uint8_t value)
{
    uint32_t tmp = obj->ECR;

    tmp &= ~FLEXCAN_ECR_TXERRCNTFAST_MASK;
    tmp |= (((uint32_t)(((uint32_t)(value)) << FLEXCAN_ECR_TXERRCNTFAST_SHIFT)) & FLEXCAN_ECR_TXERRCNTFAST_MASK);
    obj->ECR = tmp;
}

/**
  * \brief  Set fast error interrupt enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    fast error interrupt enable
  *                    - 0: disable fast error interrupt 
  *                    - 1: enable fast error interrupt 
  */
static inline void FLEXCANREG_SetFastErrIntEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->CTRL2;
    tempReg &= (~FLEXCAN_CTRL2_ERRMSKFAST_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_CTRL2_ERRMSKFAST_SHIFT) & FLEXCAN_CTRL2_ERRMSKFAST_MASK;
    obj->CTRL2 = tempReg;
}

/**
  * \brief  Get fast error interrupt enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the fast error interrupt enable
  *                 - 0: fast error interrupt is disabled
  *                 - 1: fast error interrupt is enabled
  */
static inline uint8_t FLEXCANREG_GetFastErrIntEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->CTRL2) & FLEXCAN_CTRL2_ERRMSKFAST_MASK) >> FLEXCAN_CTRL2_ERRMSKFAST_SHIFT);
}

/**
  * \brief  Get error correction configuration register write enable status
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the error correction configuration register write enable status 
  *                 - 0: error correction configuration register write is disabled
  *                 - 1: error correction configuration register write is enabled
  */
static inline uint8_t FLEXCANREG_GetMemErrCtrlRegWriteEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CTRL2 & FLEXCAN_CTRL2_ECRWRE_MASK) >> FLEXCAN_CTRL2_ECRWRE_SHIFT);
}

/**
  * \brief  Set error correction configuration register write enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable error correction configuration register write enable
  *                 - 0: disable error correction configuration register write 
  *                 - 1: enable error correction configuration register write 
  */
static inline void FLEXCANREG_SetMemErrCtrlRegWriteEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->CTRL2;
    tempReg &= (~FLEXCAN_CTRL2_ECRWRE_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_CTRL2_ECRWRE_SHIFT) & FLEXCAN_CTRL2_ECRWRE_MASK;
    obj->CTRL2 = tempReg;
}

/**
  * \brief  Get the config of write access to memory in freeze mode
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the config of write access to memory in freeze mode
  *                 - 0: write access to memory in freeze mode is disabled
  *                 - 1: write access to memory in freeze mode is enabled
  */
static inline uint8_t FLEXCANREG_GetFreezeModeWriteAcc (const FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CTRL2 & FLEXCAN_CTRL2_WRMFRZ_MASK) >> FLEXCAN_CTRL2_WRMFRZ_SHIFT);
}

/**
  * \brief  Set write access to memory in freeze mode enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    write access to memory in freeze mode enable
  *                    - 0: disable write access to memory in freeze mode
  *                    - 1: enable write access to memory in freeze mode
  */
static inline void FLEXCANREG_SetFreezeModeWriteAcc (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->CTRL2;
    tempReg &= (~FLEXCAN_CTRL2_WRMFRZ_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_CTRL2_WRMFRZ_SHIFT) & FLEXCAN_CTRL2_WRMFRZ_MASK;
    obj->CTRL2 = tempReg;
}

/**
  * \brief  Select free running timer clock source
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    free running timer source selection
  *                 - 0: clocked by CAN bit clock
  *                 - 1: clocked by an external time tick
  */
static inline void FLEXCANREG_SetFreeRunTimerSrc (FLEXCANREG_TypeDef *obj, uint8_t val)
{
    uint32_t tempReg;

    tempReg = obj->CTRL2;
    tempReg &= (~FLEXCAN_CTRL2_TIMERSRC_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_CTRL2_TIMERSRC_SHIFT) & FLEXCAN_CTRL2_TIMERSRC_MASK;
    obj->CTRL2 = tempReg;
}

/**
  * \brief  Get free running timer clock source
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns free running timer source selection
  *                 - 0: clocked by CAN bit clock
  *                 - 1: clocked by an external time tick
  */
static inline uint8_t FLEXCANREG_GetFreeRunTimerSrc (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->CTRL2) & FLEXCAN_CTRL2_TIMERSRC_MASK) >> FLEXCAN_CTRL2_TIMERSRC_SHIFT);
}

/**
  * \brief  Set mailboxes reception priority
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  mrp    mailboxes reception priority
  *                 - 1: matching starts from mailboxes and continues on legacy rx ff
  *                 - 0: matching starts from legacy rx ff and continues on mailboxes
  */
static inline void FLEXCANREG_SetMailboxesReceptionPrio (FLEXCANREG_TypeDef *obj, bool mrp)
{
    uint32_t tempReg;

    tempReg = obj->CTRL2;
    tempReg &= (~FLEXCAN_CTRL2_MRP_MASK);
    tempReg |= (((uint32_t)mrp) << FLEXCAN_CTRL2_MRP_SHIFT) & FLEXCAN_CTRL2_MRP_MASK;
    obj->CTRL2 = tempReg;
}

/**
  * \brief  Set mailboxes reception priority
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Rerutns mailboxes reception priority
  *                 - 1: matching starts from mailboxes and continues on legacy rx ff
  *                 - 0: matching starts from legacy rx ff and continues on mailboxes
  */
static inline uint8_t FLEXCANREG_GetMailboxesReceptionPrio (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->CTRL2) & FLEXCAN_CTRL2_MRP_MASK) >> FLEXCAN_CTRL2_MRP_SHIFT);
}

/**
  * \brief  Get remote request storing mode
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns remote request storing
  *                 - 0: remote response frame is generated
  *                 - 1: remote request frame is stored
  */
static inline uint8_t FLEXCANREG_GetCtrl2Rrs (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CTRL2 & FLEXCAN_CTRL2_RRS_MASK) >> FLEXCAN_CTRL2_RRS_SHIFT);
}

/**
  * \brief  Set remote request storing mode
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    remote request storing
  *                   - 0: generate remote response frame
  *                   - 1: store remote request frame
  */
static inline void FLEXCANREG_SetCtrl2Rrs (FLEXCANREG_TypeDef *obj, uint8_t value)
{
    uint32_t tmp = obj->CTRL2;

    tmp &= ~FLEXCAN_CTRL2_RRS_MASK;
    tmp |= (((uint32_t)(((uint32_t)(value)) << FLEXCAN_CTRL2_RRS_SHIFT)) & FLEXCAN_CTRL2_RRS_MASK);
    obj->CTRL2 = tmp;
}

/**
  * \brief  Get entire frame arbitration field comparison enable for rx mailboxes
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Retruns entire frame arbitration field comparison enable for rx mailboxes
  *                 - 0: rx mailbox filter's IDE bit is always compared and RTR is never
  *                      compared, regardless of mask bits
  *                 - 1: enable the comparison of both the IDE and RTR bits of an Rx mailbox 
  *                      filter with the corresponding bits of the incoming frame
  */
static inline uint8_t FLEXCANREG_GetCtrl2Eacen (const FLEXCANREG_TypeDef *obj)
{
    return ((obj->CTRL2 & FLEXCAN_CTRL2_EACEN_MASK) >> FLEXCAN_CTRL2_EACEN_SHIFT);
}

/**
  * \brief  Set entire frame arbitration field comparison enable for rx mailboxes
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    entire frame arbitration field comparison enable for rx mailboxes
  *                   - 0: rx mailbox filter's IDE bit is always compared and RTR is never
  *                        compared, regardless of mask bits
  *                   - 1: enable the comparison of both the IDE and RTR bits of an Rx mailbox
  *                        filter with the corresponding bits of the incoming frame
  */
static inline void FLEXCANREG_SetCtrl2Eacen (FLEXCANREG_TypeDef *obj, uint8_t value)
{
    uint32_t tmp = obj->CTRL2;

    tmp &= ~FLEXCAN_CTRL2_EACEN_MASK;
    tmp |= (((uint32_t)(((uint32_t)(value)) << FLEXCAN_CTRL2_EACEN_SHIFT)) & FLEXCAN_CTRL2_EACEN_MASK);
    obj->CTRL2 = tmp;
}

/**
  * \brief  Set number of legacy rx fifo filter
  * \param  obj     FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  rffn    number of legacy rx fifo filter
  *                  - This parameter is an unsigned integer that is greater
  *                    than or equal to 0x0 and less than or equal to 0xF
  */
static inline void FLEXCANREG_SetLegacyRxFifoFilterNums (FLEXCANREG_TypeDef *obj, uint8_t rffn)
{
    uint32_t tempReg;

    tempReg = obj->CTRL2;
    tempReg &= (~FLEXCAN_CTRL2_RFFN_MASK);
    tempReg |= (((uint32_t)(((uint32_t)rffn) << FLEXCAN_CTRL2_RFFN_SHIFT)) & FLEXCAN_CTRL2_RFFN_MASK);
    obj->CTRL2 = tempReg;
}

/**
  * \brief  Get number of legacy rx fifo filter
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the number of legacy rx fifo filter
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x0 and less than or equal to 0xF
  */
static inline uint8_t FLEXCANREG_GetLegacyRxFifoFilterNums (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->CTRL2) & FLEXCAN_CTRL2_RFFN_MASK) >> FLEXCAN_CTRL2_RFFN_SHIFT);
}

/**
  * \brief  Get Tx arbitration start delay
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns Tx arbitration start delay
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x0 and less than or equal to 0x1F
  */
static inline uint8_t FLEXCANREG_GetCtrl2Tasd (const FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CTRL2 & FLEXCAN_CTRL2_TASD_MASK) >> FLEXCAN_CTRL2_TASD_SHIFT);
}

/**
  * \brief  Set Tx arbitration start delay
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    Tx arbitration start delay
  *                   - This parameter is an unsigned integer that is greater
  *                     than or equal to 0x0 and less than or equal to 0x1F
  */
static inline void FLEXCANREG_SetCtrl2Tasd (FLEXCANREG_TypeDef *obj, uint8_t value)
{
    uint32_t tmp = obj->CTRL2;

    tmp &= ~FLEXCAN_CTRL2_TASD_MASK;
    tmp |= (((uint32_t)(((uint32_t)(value)) << FLEXCAN_CTRL2_TASD_SHIFT)) & FLEXCAN_CTRL2_TASD_MASK);
    obj->CTRL2 = tmp;
}

/**
  * \brief  Set bus off done interrupt mask
  * \param  obj             FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  boffdoneMask    bus off done interrupt mask
  *                          - 1: enable bus off done interrupt
  *                          - 0: disable bus off done interrupt
  */
static inline void FLEXCANREG_SetBusOffDoneIntMask (FLEXCANREG_TypeDef *obj, bool boffdoneMask)
{
    uint32_t tempReg;

    tempReg = obj->CTRL2;
    tempReg &= (~FLEXCAN_CTRL2_BOFFDONEMSK_MASK);
    tempReg |= (((uint32_t)boffdoneMask) << FLEXCAN_CTRL2_BOFFDONEMSK_SHIFT) & FLEXCAN_CTRL2_BOFFDONEMSK_MASK;
    obj->CTRL2 = tempReg;
}

/**
  * \brief  Get bus off done interrupt mask
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns bus off done interrupt mask
  *                 - 1: bus off done interrupt is enabled
  *                 - 0: bus off done interrupt is disabled
  */
static inline uint8_t FLEXCANREG_GetBusOffDoneIntMask (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->CTRL2) & FLEXCAN_CTRL2_BOFFDONEMSK_MASK) >> FLEXCAN_CTRL2_BOFFDONEMSK_SHIFT);
}

/**
  * \brief  Set enahnced bit timing enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    enhanced bit timing enable
  *                    - 0: disable enhanced bit timing
  *                    - 1: enable enhanced bit timing
  */
static inline void FLEXCANREG_SetEnhBitTimingEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->CTRL2;
    tempReg &= (~FLEXCAN_CTRL2_BTE_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_CTRL2_BTE_SHIFT) & FLEXCAN_CTRL2_BTE_MASK;
    obj->CTRL2 = tempReg;
}

/**
  * \brief  Get enahnced bit timing enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns enahnced bit timing enable
  *                 - 0: enhanced bit timing is disabled
  *                 - 1: enhanced bit timing is enabled
  */
static inline uint8_t FLEXCANREG_GetEnhBitTimingEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->CTRL2) & FLEXCAN_CTRL2_BTE_MASK) >> FLEXCAN_CTRL2_BTE_SHIFT);
}

/**
  * \brief  Set free running timer base
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    free running timer base selection
  *                 - 00b: select CAN_TIMER as free running timer base
  *                 - 01b: select lower 16 bits of high resolution timer as free running timer base
  *                 - 10b: select upper 16 bits of high resolution timer as free running timer base
  *                 - 11b: reversed
  */
static inline void FLEXCANREG_SetFreeRunTimerBase (FLEXCANREG_TypeDef *obj, uint8_t val)
{
    uint32_t tempReg;

    tempReg = obj->CTRL2;
    tempReg &= (~FLEXCAN_CTRL2_MBTSBASE_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_CTRL2_MBTSBASE_SHIFT) & FLEXCAN_CTRL2_MBTSBASE_MASK;
    obj->CTRL2 = tempReg;
}

/**
  * \brief  Get free running timer base
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns free running timer base selection
  *                 - 00b: select CAN_TIMER as free running timer base
  *                 - 01b: select lower 16 bits of high resolution timer as free running timer base
  *                 - 10b: select upper 16 bits of high resolution timer as free running timer base
  *                 - 11b: reversed
  */
static inline uint8_t FLEXCANREG_GetFreeRunTimerBase (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->CTRL2) & FLEXCAN_CTRL2_MBTSBASE_MASK) >> FLEXCAN_CTRL2_MBTSBASE_SHIFT);
}

/**
  * \brief  Set high resolution time stamp mode
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    high resolution time stamp mode
  *                 - 00b: select high-resolution time stamp mode is disabled
  *                 - 01b: select high-resolution time stamp mode is at the end of the CAN frame
  *                 - 10b: select high-resolution time stamp mode is at the start of the CAN frame
  *                 - 11b: select high-resolution time stamp mode is at the RES bit of the CAN frame
  */
static inline void FLEXCANREG_SetHighResTimeStampMode (FLEXCANREG_TypeDef *obj, uint8_t val)
{
    uint32_t tempReg;

    tempReg = obj->CTRL2;
    tempReg &= (~FLEXCAN_CTRL2_TSTAMPCAP_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_CTRL2_TSTAMPCAP_SHIFT) & FLEXCAN_CTRL2_TSTAMPCAP_MASK;
    obj->CTRL2 = tempReg;
}

/**
  * \brief  Get high resolution time stamp mode
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns high resolution time stamp mode
  *                 - 00b: select high-resolution time stamp mode is disabled
  *                 - 01b: select high-resolution time stamp mode is at the end of the CAN frame
  *                 - 10b: select high-resolution time stamp mode is at the start of the CAN frame
  *                 - 11b: select high-resolution time stamp mode is at the RES bit of the CAN frame
  */
static inline uint8_t FLEXCANREG_GetHighResTimeStampMode (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->CTRL2) & FLEXCAN_CTRL2_TSTAMPCAP_MASK) >> FLEXCAN_CTRL2_MBTSBASE_SHIFT);
}

/**
  * \brief  Get error overrun interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns fast error interrupt flag
  *                 - 0: error overrun has not occurred
  *                 - 1: error overrun has occurred
  */
static inline uint8_t FLEXCANREG_GetErrOverrunIntFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_ERROVR_MASK) >> FLEXCAN_ESR1_ERROVR_SHIFT);
}

/**
  * \brief  Clear error overrun interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  */
static inline void FLEXCANREG_ClearErrOverrunIntFlag (FLEXCANREG_TypeDef *obj)
{
    obj->ESR1 |= FLEXCAN_ESR1_ERROVR_MASK;
}

/**
  * \brief  Get fast error interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns fast error interrupt flag
  *                 - 0: fast error interrupt deassert 
  *                 - 1: fast error interrupt assert
  */
static inline uint8_t FLEXCANREG_GetFastErrIntFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_ERRINT_FAST_MASK) >> FLEXCAN_ESR1_ERRINT_FAST_SHIFT);
}

/**
  * \brief  Clear fast error interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  */
static inline void FLEXCANREG_ClearFastErrIntFlag (FLEXCANREG_TypeDef *obj)
{
    obj->ESR1 |= FLEXCAN_ESR1_ERRINT_FAST_MASK;
}

/**
  * \brief  Get tx warning interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns tx warning interrupt flag
  *                 - 0: tx warning interrupt deassert 
  *                 - 1: tx warning interrupt assert
  */
static inline uint8_t FLEXCANREG_GetTxWarnIntFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_TWRNINT_MASK) >> FLEXCAN_ESR1_TWRNINT_SHIFT);
}

/**
  * \brief  Clear tx warning interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  *
  */
static inline void FLEXCANREG_ClearTxWarnIntFlag (FLEXCANREG_TypeDef *obj)
{
    obj->ESR1 |= FLEXCAN_ESR1_TWRNINT_MASK;
}

/**
  * \brief  Get bus off done interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns bus off done interrupt flag
  *                 - 0: no such occurrence
  *                 - 1: flexcan has completed bus off process
  */
static inline uint8_t FLEXCANREG_GetBusOffDoneIntFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_BOFFDONEINT_MASK) >> FLEXCAN_ESR1_BOFFDONEINT_SHIFT);
}

/**
  * \brief  Clear bus off done interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  */
static inline void FLEXCANREG_ClearBusOffDoneIntFlag (FLEXCANREG_TypeDef *obj)
{
    obj->ESR1 |= FLEXCAN_ESR1_BOFFDONEINT_MASK;
}

/**
  * \brief  Get synchronized status
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns synchronized status
  *                 - 0: flexcan is not synchronized to the can bus
  *                 - 1: flexcan is synchronized to the can bus
  */
static inline uint8_t FLEXCANREG_GetSynchFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_SYNCH_MASK) >> FLEXCAN_ESR1_SYNCH_SHIFT);
}

/**
  * \brief  Get rx warning interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns rx warning interrupt flag
  *                 - 0: rx warning interrupt deassert 
  *                 - 1: rx warning interrupt assert
  */
static inline uint8_t FLEXCANREG_GetRxWarnIntFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_RWRNINT_MASK) >> FLEXCAN_ESR1_RWRNINT_SHIFT);
}

/**
  * \brief  Clear rx warning interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  */
static inline void FLEXCANREG_ClearRxWarnIntFlag (FLEXCANREG_TypeDef *obj)
{
    obj->ESR1 |= FLEXCAN_ESR1_RWRNINT_MASK;
}

/**
  * \brief  Get tx warning flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns tx warning flag
  *                 - 0: tx warning deassert 
  *                 - 1: tx warning deassert
  */
static inline uint8_t FLEXCANREG_GetTxWarnFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_TXWRN_MASK) >> FLEXCAN_ESR1_TXWRN_SHIFT);
}

/**
  * \brief  Get rx warning flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns rx warning flag
  *                 - 0: rx warning deassert 
  *                 - 1: rx warning assert
  */
static inline uint8_t FLEXCANREG_GetRxWarnFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_RXWRN_MASK) >> FLEXCAN_ESR1_RXWRN_SHIFT);
}

/**
  * \brief  Get bus off interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns bus off interrupt flag
  *                 - 0: bus off interrupt deassert
  *                 - 1: bus off interrupt assert
  */
static inline uint8_t FLEXCANREG_GetBusoffIntFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_BOFFINT_MASK) >> FLEXCAN_ESR1_BOFFINT_SHIFT);
}

/**
  * \brief  Clear bus off interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  */
static inline void FLEXCANREG_ClearBusoffIntFlag (FLEXCANREG_TypeDef *obj)
{
    obj->ESR1 |= FLEXCAN_ESR1_BOFFINT_MASK;
}

/**
  * \brief  Get error interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns error interrupt flag
  *                 - 0: error interrupt deassert 
  *                 - 1: error interrupt assert
  */
static inline uint8_t FLEXCANREG_GetErrIntFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_ERRINT_MASK) >> FLEXCAN_ESR1_ERRINT_SHIFT);
}

/**
  * \brief  Clear error interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  */
static inline void FLEXCANREG_ClearErrIntFlag (FLEXCANREG_TypeDef *obj)
{
    obj->ESR1 |= FLEXCAN_ESR1_ERRINT_MASK;
}

/**
  * \brief  Get edge wakeup interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns edge wakeup interrupt flag
  *                 - 0: wakeup interrupt deassert
  *                 - 1: wakeup interrupt assert
  */
static inline uint8_t FLEXCANREG_GetEdgeWakeIntFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_WAKINT_MASK) >> FLEXCAN_ESR1_WAKINT_SHIFT);
}

/**
  * \brief  Clear edge wakeup interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  */
static inline void FLEXCANREG_ClearEdgeWakeIntFlag (FLEXCANREG_TypeDef *obj)
{
    obj->ESR1 |= FLEXCAN_ESR1_WAKINT_MASK;
}

/**
  * \brief  Clear error state with mask
  * \param  obj        FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  errMask    err mask bits 
  *                     - user needs to customize their own mask value 
  *                       based on the definition of the ESR1 register
  */
static inline void FLEXCANREG_ClearErrFlag (FLEXCANREG_TypeDef *obj, uint32_t errMask)
{
    obj->ESR1 |= errMask;
}

/**
  * \brief  Get Rx mailboxes global mask
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns Rx mailboxes global mask
  *                 - This parameter is an unsigned integer that is greater 
  *                   than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline uint32_t FLEXCANREG_GetRxMailboxGlobalMask (FLEXCANREG_TypeDef *obj)
{
    return obj->RXMGMASK;
}

/**
  * \brief  Set Rx mailboxes global mask
  * \param  obj     FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  mask    Rx mailboxes global mask
  *                  - This parameter is an unsigned integer that is greater 
  *                    than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline void FLEXCANREG_SetRxMailboxGlobalMask (FLEXCANREG_TypeDef *obj, uint32_t mask)
{
    obj->RXMGMASK = mask;
}

/**
  * \brief  Set Rx mailbox 14 mask
  * \param  obj     FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  mask    mask for Rx mailbox 14
  *                  - This parameter is an unsigned integer that is greater 
  *                    than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline void FLEXCANREG_SetRxMailbox14Mask (FLEXCANREG_TypeDef *obj, uint32_t mask)
{
    obj->RX14MASK = mask;
}

/**
  * \brief  Get Rx mailbox 14 mask
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns mask for Rx mailbox 14
  *                 - This parameter is an unsigned integer that is greater 
  *                   than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline uint32_t FLEXCANREG_GetRxMailbox14Mask (FLEXCANREG_TypeDef *obj)
{
    return (obj->RX14MASK);
}

/**
  * \brief  Set Rx mailbox 15 mask
  * \param  obj     FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  mask    mask for Rx mailbox 15
  *                  - This parameter is an unsigned integer that is greater
  *                    than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline void FLEXCANREG_SetRxMailbox15Mask (FLEXCANREG_TypeDef *obj, uint32_t mask)
{
    obj->RX15MASK = mask;
}

/**
  * \brief  Get Rx mailbox 15 mask
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns mask for Rx mailbox 15
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline uint32_t FLEXCANREG_GetRxMailbox15Mask (FLEXCANREG_TypeDef *obj)
{
    return (obj->RX15MASK);
}

/**
  * \brief  Get bit 1 error in FD frame data phase
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns bit 1 error in FD frame data phase
  *                 - 0: no such error occurrence
  *                 - 1: at least one bit sent as recessive is received as dominant
  */
static inline uint8_t FLEXCANREG_GetBit1FastError (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_BIT1ERR_FAST_MASK) >> FLEXCAN_ESR1_BIT1ERR_FAST_SHIFT);
}

/**
  * \brief  Get bit 0 error in FD frame data phase
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns bit 0 error in FD frame data phase
  *                 - 0: no such error occurrence
  *                 - 1: at least one bit sent as dominant is received as recessive
  */
static inline uint8_t FLEXCANREG_GetBit0FastError (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_BIT0ERR_FAST_MASK) >> FLEXCAN_ESR1_BIT0ERR_FAST_SHIFT);
}

/**
  * \brief  Get CRC error in FD frame data phase
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns CRC error in FD frame data phase
  *                 - 0: no such error occurrence
  *                 - 1: a CRC error occurred since last read of this register
  */
static inline uint8_t FLEXCANREG_GetCrcFastError (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_CRCERR_FAST_MASK) >> FLEXCAN_ESR1_CRCERR_FAST_SHIFT);
}

/**
  * \brief  Get form error in FD frame data phase
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns form error in FD frame data phase
  *                 - 0: no such error occurrence
  *                 - 1: a form error occurred since last read of this register
  */
static inline uint8_t FLEXCANREG_GetFormFastError (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_FRMERR_FAST_MASK) >> FLEXCAN_ESR1_FRMERR_FAST_SHIFT);
}

/**
  * \brief  Get stuff error in FD frame data phase
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns stuff error in FD frame data phase
  *                 - 0: no such error occurrence
  *                 - 1: a stuff error occurred since last read of this register
  */
static inline uint8_t FLEXCANREG_GetStuffFastError (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_STFERR_FAST_MASK) >> FLEXCAN_ESR1_STFERR_FAST_SHIFT);
}

/**
  * \brief  Get bit 1 error
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns bit 1 error
  *                 - 0: no such error occurrence
  *                 - 1: at least one bit sent as recessive is received as dominant
  */
static inline uint8_t FLEXCANREG_GetBit1Error (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_BIT1ERR_MASK) >> FLEXCAN_ESR1_BIT1ERR_SHIFT);
}

/**
  * \brief  Get bit 0 error
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns bit 0 error
  *                 - 0: no such error occurrence
  *                 - 1: at least one bit sent as dominant is received as recessive
  */
static inline uint8_t FLEXCANREG_GetBit0Error (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_BIT0ERR_MASK) >> FLEXCAN_ESR1_BIT0ERR_SHIFT);
}

/**
  * \brief  Get ACK error
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns ACK error
  *                 - 0: no such error occurrence
  *                 - 1: an ACK error occurred since last read of this register
  */
static inline uint8_t FLEXCANREG_GetAckError (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_ACKERR_MASK) >> FLEXCAN_ESR1_ACKERR_SHIFT);
}

/**
  * \brief  Get CRC error
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns CRC error
  *                 - 0: no such error occurrence
  *                 - 1: an CRC error occurred since last read of this register
  */
static inline uint8_t FLEXCANREG_GetCrcError (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_CRCERR_MASK) >> FLEXCAN_ESR1_CRCERR_SHIFT);
}

/**
  * \brief  Get form error
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns form error
  *                 - 0: no such error occurrence
  *                 - 1: an form error occurred since last read of this register
  */
static inline uint8_t FLEXCANREG_GetFormError (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_FRMERR_MASK) >> FLEXCAN_ESR1_FRMERR_SHIFT);
}

/**
  * \brief  Get stuff error
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns stuff error
  *                 - 0: no such error occurrence
  *                 - 1: an stuff error occurred since last read of this register
  */
static inline uint8_t FLEXCANREG_GetStuffError (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_STFERR_MASK) >> FLEXCAN_ESR1_STFERR_SHIFT);
}

/**
  * \brief  Get Tx error warning
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns Tx error warning
  *                 - 0: no such error occurrence
  *                 - 1: TXERRCNT is greater than or equal to 96
  */
static inline uint8_t FLEXCANREG_GetTxErrWarning (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_TXWRN_MASK) >> FLEXCAN_ESR1_TXWRN_SHIFT);
}

/**
  * \brief  Get Rx error warning
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns Rx error warning
  *                 - 0: no such error occurrence
  *                 - 1: RXERRCNT is greater than or equal to 96
  */
static inline uint8_t FLEXCANREG_GetRxErrWarning (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_RXWRN_MASK) >> FLEXCAN_ESR1_RXWRN_SHIFT);
}

/**
  * \brief  Get idle state
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns idle state
  *                 - 0: no such occurrence
  *                 - 1: CAN bus is now idle
  */
static inline uint8_t FLEXCANREG_GetIdleState (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_IDLE_MASK) >> FLEXCAN_ESR1_IDLE_SHIFT);
}

/**
  * \brief  Get Tx state
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns Tx state
  *                 - 0: FlexCan is not transmitting a message
  *                 - 1: FlexCan is transmitting a message
  */
static inline uint8_t FLEXCANREG_GetTxState (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_TX_MASK) >> FLEXCAN_ESR1_TX_SHIFT);
}

/**
  * \brief  Get fault confinement state
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns fault confinement state
  *                 - 00b: error active 
  *                 - 01b: error passive
  *                 - 1xb: bus off
  */
static inline uint8_t FLEXCANREG_GetFltConfinementState (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_FLTCONF_MASK) >> FLEXCAN_ESR1_FLTCONF_SHIFT);
}

/**
  * \brief  Get rx state
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns FlexCan Rx state
  *                 - 0: FlexCan is not receiving a message
  *                 - 1: FlexCan is receiving a message
  */
static inline uint8_t FLEXCANREG_GetRxState (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ESR1) & FLEXCAN_ESR1_RX_MASK) >> FLEXCAN_ESR1_RX_SHIFT);
}

/**
  * \brief  Set FLEXCAN message buffer interrupt enable mask
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  regId    register index
  *                   - 0: IMASK1
  *                   - 1: IMASK2
  *                   - 2: IMASK3
  *                   - 3: IMASK4
  * \param  val      message buffer interrupt enable mask
  *                   - This parameter is an unsigned integer that is greater
  *                     than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline void FLEXCANREG_SetMsgBufInterruptEnable (FLEXCANREG_TypeDef *obj, uint32_t regId, uint32_t val)
{
    switch (regId)
    {
        case 0:
            obj->IMASK1 |= val;
            break;

        case 1:
            obj->IMASK2 |= val;
            break;

        case 2:
            obj->IMASK3 |= val;
            break;

        case 3:
            obj->IMASK4 |= val;
            break;

        default:
            break;
    }
}

/**
  * \brief  Set FLEXCAN message buffer interrupt disable mask
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  regId    register index
  *                   - 0: IMASK1
  *                   - 1: IMASK2
  *                   - 2: IMASK3
  *                   - 3: IMASK4
  * \param  val      message buffer interrupt disable mask
  *                   - This parameter is an unsigned integer that is greater
  *                     than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline void FLEXCANREG_SetMsgBufInterruptDisable (FLEXCANREG_TypeDef *obj, uint32_t regId, uint32_t val)
{
    switch (regId)
    {
        case 0:
            obj->IMASK1 &= val;
            break;

        case 1:
            obj->IMASK2 &= val;
            break;

        case 2:
            obj->IMASK3 &= val;
            break;

        case 3:
            obj->IMASK4 &= val;
            break;

        default:
            break;
    }
}

/**
  * \brief  Get FLEXCAN message buffer interrupt flag register mask
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  regId    register index
  *                   - 0: IFLAG1
  *                   - 1: IFLAG2
  *                   - 2: IFLAG3
  *                   - 3: IFLAG4
  * \return Returns FLEXCAN message buffer interrupt flag register[n] mask
  *                   - This parameter is an unsigned integer that is greater
  *                     than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline uint32_t FLEXCANREG_GetMsgBufInterruptFlagReg (FLEXCANREG_TypeDef *obj, uint32_t regId)
{
    uint32_t retVal = 0;

    switch (regId)
    {
        case 0:
            retVal = obj->IFLAG1;
            break;

        case 1:
            retVal = obj->IFLAG2;
            break;

        case 2:
            retVal = obj->IFLAG3;
            break;

        case 3:
            retVal = obj->IFLAG4;
            break;

        default:
            break;
    }

    return retVal;
}

/**
  * \brief  Set FLEXCAN message buffer interrupt flag
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  regId    register index
  *                   - 0: IFLAG1
  *                   - 1: IFLAG2
  *                   - 2: IFLAG3
  *                   - 3: IFLAG4
  * \param  val      message buffer interrupt flag
  *                   - This parameter is an unsigned integer that is greater
  *                     than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline void FLEXCANREG_SetMsgBufInterruptFlagReg (FLEXCANREG_TypeDef *obj, uint32_t regId, uint32_t val)
{
    switch (regId)
    {
        case 0:
            obj->IFLAG1 = val;
            break;

        case 1:
            obj->IFLAG2 = val;
            break;
            
        case 2:
            obj->IFLAG3 = val;
            break;

        case 3:
            obj->IFLAG4 = val;
            break;

        default:
            break;
    }
}

/**
  * \brief  Set rx fifo global mask
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    rx fifo global mask
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline void FLEXCANREG_SetRxFifoGlobalMask (FLEXCANREG_TypeDef *obj, uint32_t val)
{
    obj->RXFGMASK = val;
}

/**
  * \brief  Get rx fifo global mask
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns rx fifo global mask
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline uint32_t FLEXCANREG_GetRxFifoGlobalMask (FLEXCANREG_TypeDef *obj)
{
    return (obj->RXFGMASK);
}

/**
  * \brief  Get identifier acceptance filter hit indicator
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns identifier acceptance filter hit indicator
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x1FF
  */
static inline uint16_t FLEXCANREG_GetRxfirIdhit (FLEXCANREG_TypeDef *obj)
{
    return (uint16_t)((obj->RXFIR & FLEXCAN_RXFIR_IDHIT_MASK) >> FLEXCAN_RXFIR_IDHIT_SHIFT);
}

/**
  * \brief  Get extended bit timing format enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns extended bit timing format enable
  *                 - 0: extended bit timing format disabled
  *                 - 1: extended bit timing format enabled
  */
static inline uint8_t FLEXCANREG_GetExtendedBitTimingEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CBT & FLEXCAN_CBT_BTF_MASK) >> FLEXCAN_CBT_BTF_SHIFT);
}

/**
  * \brief  Set extended bit timing feature
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    extended bit timing feature
  *                    - 0: extended bit timing format disabled
  *                    - 1: extended bit timing format enabled
  */
static inline void FLEXCANREG_SetExtendedBitTimingEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->CBT;
    tempReg &= (~FLEXCAN_CBT_BTF_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_CBT_BTF_SHIFT) & FLEXCAN_CBT_BTF_MASK;
    obj->CBT = tempReg;
}

/**
  * \brief  Get extended prescaler division factor
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns extended prescaler division factor
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x3FF
  */
static inline uint16_t FLEXCANREG_GetExtPresalerDivision (FLEXCANREG_TypeDef *obj)
{
    return (uint16_t)((obj->CBT & FLEXCAN_CBT_EPRESDIV_MASK) >> FLEXCAN_CBT_EPRESDIV_SHIFT);
}

/**
  * \brief  Set extended presaler div
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    extended presaler div
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x3FF
  */
static inline void FLEXCANREG_SetExtPresalerDivision (FLEXCANREG_TypeDef *obj, uint16_t val)
{
    uint32_t tempReg;

    tempReg = obj->CBT;
    tempReg &= (~FLEXCAN_CBT_EPRESDIV_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_CBT_EPRESDIV_SHIFT) & FLEXCAN_CBT_EPRESDIV_MASK;
    obj->CBT = tempReg;
}

/**
  * \brief  Get extended resync jump width
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns extended resync jump width
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x1F
  */
static inline uint8_t FLEXCANREG_GetExtResyncJumpWidth (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CBT & FLEXCAN_CBT_ERJW_MASK) >> FLEXCAN_CBT_ERJW_SHIFT);
}

/**
  * \brief  Set extended resynce jump width
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    extended resynce jump width
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x1F
  */
static inline void FLEXCANREG_SetExtResyncJumpWidth (FLEXCANREG_TypeDef *obj, uint16_t val)
{
    uint32_t tempReg;

    tempReg = obj->CBT;
    tempReg &= (~FLEXCAN_CBT_ERJW_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_CBT_ERJW_SHIFT) & FLEXCAN_CBT_ERJW_MASK;
    obj->CBT = tempReg;
}

/**
  * \brief  Get extended propagation segment
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns extended propagation segment
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x3F
  */
static inline uint8_t FLEXCANREG_GetExtPorpSeg (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CBT & FLEXCAN_CBT_EPROPSEG_MASK) >> FLEXCAN_CBT_EPROPSEG_SHIFT);
}

/**
  * \brief  Set extended porp seg
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    extended porp seg
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x3F
  */
static inline void FLEXCANREG_SetExtPorpSeg (FLEXCANREG_TypeDef *obj, uint16_t val)
{
    uint32_t tempReg;

    tempReg = obj->CBT;
    tempReg &= (~FLEXCAN_CBT_EPROPSEG_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_CBT_EPROPSEG_SHIFT) & FLEXCAN_CBT_EPROPSEG_MASK;
    obj->CBT = tempReg;
}

/**
  * \brief  Get extended phase segment 1
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns extended phase segment 1
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x1F
  */
static inline uint8_t FLEXCANREG_GetExtPhaseSeg1 (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CBT & FLEXCAN_CBT_EPSEG1_MASK) >> FLEXCAN_CBT_EPSEG1_SHIFT);
}

/**
  * \brief  Set extended phase segment 1
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    extended phase segment 1
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x1F
  */
static inline void FLEXCANREG_SetExtPhaseSeg1 (FLEXCANREG_TypeDef *obj, uint16_t val)
{
    uint32_t tempReg;

    tempReg = obj->CBT;
    tempReg &= (~FLEXCAN_CBT_EPSEG1_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_CBT_EPSEG1_SHIFT) & FLEXCAN_CBT_EPSEG1_MASK;
    obj->CBT = tempReg;
}

/**
  * \brief  Get extended phase segment 2
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns extended phase segment 2
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x1F
  */
static inline uint8_t FLEXCANREG_GetExtPhaseSeg2 (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CBT & FLEXCAN_CBT_EPSEG2_MASK) >> FLEXCAN_CBT_EPSEG2_SHIFT);
}

/**
  * \brief  Set extended phase segment 2
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    extended phase segment 2
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x1F
  */
static inline void FLEXCANREG_SetExtPhaseSeg2 (FLEXCANREG_TypeDef *obj, uint16_t val)
{
    uint32_t tempReg;

    tempReg = obj->CBT;
    tempReg &= (~FLEXCAN_CBT_EPSEG2_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_CBT_EPSEG2_SHIFT) & FLEXCAN_CBT_EPSEG2_MASK;
    obj->CBT = tempReg;
}

/**
  * \brief  Set Rx individual mask n
  * \param  obj     FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  num     number of Rx individual mask
  *                  - This parameter is an unsigned integer that is greater
  *                    than or equal to 0 and less than or equal to 127
  * \param  mask    mask
  *                  - This parameter is an unsigned integer that is greater
  *                    than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline void FLEXCANREG_SetRxIndividualMask (FLEXCANREG_TypeDef *obj, uint8_t num, uint32_t mask)
{
    obj->RXIMR[num] = mask;
}

/**
  * \brief  Get Rx individual mask n
  * \param  obj     FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  num     number of Rx individual mask
  *                  - This parameter is an unsigned integer that is greater
  *                    than or equal to 0 and less than or equal to 127
  * \return  rx individual mask value
  *                  - This parameter is an unsigned integer that is greater
  *                    than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline uint32_t FLEXCANREG_GetRxIndividualMask (FLEXCANREG_TypeDef *obj, uint8_t num)
{
    return (obj->RXIMR[num]);
}

/**
  * \brief  Error configuration register write disable
  * \param  obj        FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  disable    configuration register write disable
  *                     - 0: write is enabled
  *                     - 1: write is disabled
  */
static inline void FLEXCANREG_SetErrCfgRegWriteDisable (FLEXCANREG_TypeDef *obj, uint8_t disable)
{
    uint32_t tempReg;

    tempReg = obj->MECR;
    tempReg &= (~FLEXCAN_MECR_ECRWRDIS_MASK);
    tempReg |= (((uint32_t)disable) << FLEXCAN_MECR_ECRWRDIS_SHIFT) & FLEXCAN_MECR_ECRWRDIS_MASK;
    obj->MECR = tempReg;
}

/**
  * \brief  Error correction disable
  * \param  obj        FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  disable    error correction disable
  *                     - 0: enable memory error correction
  *                     - 1: disable memory error correction
  */
static inline void FLEXCANREG_SetEccDisable (FLEXCANREG_TypeDef *obj, uint8_t disable)
{
    uint32_t tempReg;

    tempReg = obj->MECR;
    tempReg &= (~FLEXCAN_MECR_ECCDIS_MASK);
    tempReg |= (((uint32_t)disable) << FLEXCAN_MECR_ECCDIS_SHIFT) & FLEXCAN_MECR_ECCDIS_MASK;
    obj->MECR = tempReg;
}

/**
  * \brief  Non-Correctable errors in FLEXCAN access put device in freeze mode
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    enable the device in freeze mode when non-Correctable errors occur
  *                    - 0: keep normal operation
  *                    - 1: put device in freeze mode
  */
static inline void FLEXCANREG_SetNonCorrErrToFrzModeEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->MECR;
    tempReg &= (~FLEXCAN_MECR_NCEFAFRZ_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_MECR_NCEFAFRZ_SHIFT) & FLEXCAN_MECR_NCEFAFRZ_MASK;
    obj->MECR = tempReg;
}

/**
  * \brief  Get bit rate switch enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns bit rate switch enable
  *                 - 0: transmit a frame in nominal rate, the BRS bit in the Tx MB has no effect
  *                 - 1: transmit a frame with bit rate switching if the BRS bit in the Tx MB is
  *                      recessive
  */
static inline uint8_t FLEXCANREG_GetFdRateSwitch (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->FDCTRL & FLEXCAN_FDCTRL_FDRATE_MASK) >> FLEXCAN_FDCTRL_FDRATE_SHIFT);
}

/**
  * \brief  Set fd rate switch
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    fd rate switch
  *                    - 0: disable the effect of the Bit Rate Switch (BRS bit)
  *                    - 1: enable the effect of the Bit Rate Switch (BRS bit)
  */
static inline void FLEXCANREG_SetFdRateSwitch (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->FDCTRL;
    tempReg &= (~FLEXCAN_FDCTRL_FDRATE_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_FDCTRL_FDRATE_SHIFT) & FLEXCAN_FDCTRL_FDRATE_MASK;
    obj->FDCTRL = tempReg;
}

/**
  * \brief  Set message buffer data size for region 0 ~ 3
  * \param  obj        FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  region     ram region index
  *                     - 0: MBDSR0
  *                     - 1: MBDSR1
  *                     - 2: MBDSR2
  *                     - 3: MBDSR3
  * \param  sizeSel    region size
  *                     - 0: selects 8 bytes per message buffer
  *                     - 1: selects 16 bytes per message buffer
  *                     - 2: selects 32 bytes per message buffer
  *                     - 3: selects 64 bytes per message buffer
  */
static inline void FLEXCANREG_SetRegionDataSizeSel (FLEXCANREG_TypeDef *obj, uint8_t region, uint8_t sizeSel)
{
    uint32_t tempReg;

    tempReg = obj->FDCTRL;
    switch (region)
    {
        case 0:
            tempReg &= (~FLEXCAN_FDCTRL_MBDSR0_MASK);
            tempReg |= (((uint32_t)sizeSel) << FLEXCAN_FDCTRL_MBDSR0_SHIFT) & FLEXCAN_FDCTRL_MBDSR0_MASK;
            break;

        case 1:
            tempReg &= (~FLEXCAN_FDCTRL_MBDSR1_MASK);
            tempReg |= (((uint32_t)sizeSel) << FLEXCAN_FDCTRL_MBDSR1_SHIFT) & FLEXCAN_FDCTRL_MBDSR1_MASK;
            break;

        case 2:
            tempReg &= (~FLEXCAN_FDCTRL_MBDSR2_MASK);
            tempReg |= (((uint32_t)sizeSel) << FLEXCAN_FDCTRL_MBDSR2_SHIFT) & FLEXCAN_FDCTRL_MBDSR2_MASK;
            break;

        case 3:
            tempReg &= (~FLEXCAN_FDCTRL_MBDSR3_MASK);
            tempReg |= (((uint32_t)sizeSel) << FLEXCAN_FDCTRL_MBDSR3_SHIFT) & FLEXCAN_FDCTRL_MBDSR3_MASK;
            break;

        default:
            /* size select wrong, do something */
            break;
    }

    obj->FDCTRL = tempReg;
}

/**
  * \brief  Get message buffer data size for region0~3
  * \param  obj        FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  region     ram region index
  *                     - 0: MBDSR0
  *                     - 1: MBDSR1
  *                     - 2: MBDSR2
  *                     - 3: MBDSR3
  * \return Returns the message buffer data size
  *                     - 0: selects 8 bytes per message buffer
  *                     - 1: selects 16 bytes per message buffer
  *                     - 2: selects 32 bytes per message buffer
  *                     - 3: selects 64 bytes per message buffer
  */
static inline uint8_t FLEXCANREG_GetRegionDataSizeSel (FLEXCANREG_TypeDef *obj, uint8_t region)
{
    uint8_t retVal = 0;

    switch(region)
    {
        case 0:
            retVal = (uint8_t)((obj->FDCTRL & FLEXCAN_FDCTRL_MBDSR0_MASK) >> FLEXCAN_FDCTRL_MBDSR0_SHIFT);
            break;

        case 1:
            retVal = (uint8_t)((obj->FDCTRL & FLEXCAN_FDCTRL_MBDSR1_MASK) >> FLEXCAN_FDCTRL_MBDSR1_SHIFT);
            break;

        case 2:
            retVal = (uint8_t)((obj->FDCTRL & FLEXCAN_FDCTRL_MBDSR2_MASK) >> FLEXCAN_FDCTRL_MBDSR2_SHIFT);
            break;

        case 3:
            retVal = (uint8_t)((obj->FDCTRL & FLEXCAN_FDCTRL_MBDSR3_MASK) >> FLEXCAN_FDCTRL_MBDSR3_SHIFT);
            break;
            
        default:
            /* size select wrong, do something */
            break;
    }

    return retVal;
}

/**
  * \brief  Get transceiver delay compensation enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the transceiver delay compensation enable
  *                 - 0: TDC is disabled
  *                 - 1: TDC is enabled
  */
static inline uint8_t FLEXCANREG_GetTdcEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->FDCTRL & FLEXCAN_FDCTRL_TDCEN_MASK) >> FLEXCAN_FDCTRL_TDCEN_SHIFT);
}

/**
  * \brief  Set transceiver delay compensation enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    transceiver delay compensation enable
  *                    - 0: disable the TDC func
  *                    - 1: enable the TDC func
  */
static inline void FLEXCANREG_SetTdcEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->FDCTRL;
    tempReg &= (~FLEXCAN_FDCTRL_TDCEN_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_FDCTRL_TDCEN_SHIFT) & FLEXCAN_FDCTRL_TDCEN_MASK;
    obj->FDCTRL = tempReg;
}

/**
  * \brief  Get transceiver delay compensation fail
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns transceiver delay compensation fail
  *                 - 0: measured loop delay is in range
  *                 - 1: measured loop delay is out of range
  */
static inline uint8_t FLEXCANREG_GetFdctrlTdcfail (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->FDCTRL & FLEXCAN_FDCTRL_TDCFAIL_MASK) >> FLEXCAN_FDCTRL_TDCFAIL_SHIFT);
}

/**
  * \brief  Clear transceiver delay compensation fail
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  */
static inline void FLEXCANREG_ClearFdctrlTdcfail (FLEXCANREG_TypeDef *obj)
{
    uint32_t tmp = obj->FDCTRL;

    tmp |= (((uint32_t)((1UL) << FLEXCAN_FDCTRL_TDCFAIL_SHIFT)) & FLEXCAN_FDCTRL_TDCFAIL_MASK);
    obj->FDCTRL = tmp;
}

/**
  * \brief  Get transceiver delay compensation offset
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns transceiver delay compensation offset
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x1F
  */
static inline uint8_t FLEXCANREG_GetFdctrlTdcoff (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->FDCTRL & FLEXCAN_FDCTRL_TDCOFF_MASK) >> FLEXCAN_FDCTRL_TDCOFF_SHIFT);
}

/**
  * \brief  Set transceiver delay compensation offset
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  offset    transceiver delay compensation offset
  *                    - This parameter is an unsigned integer that is greater
  *                      than or equal to 0x00 and less than or equal to 0x1F
  */
static inline void FLEXCANREG_SetTdcOffset (FLEXCANREG_TypeDef *obj, uint8_t offset)
{
    uint32_t tempReg;

    tempReg = obj->FDCTRL;
    tempReg &= (~FLEXCAN_FDCTRL_TDCOFF_MASK);
    tempReg |= (((uint32_t)offset) << FLEXCAN_FDCTRL_TDCOFF_SHIFT) & FLEXCAN_FDCTRL_TDCOFF_MASK;
    obj->FDCTRL = tempReg;
}

/**
  * \brief  Get transceiver delay compensation value
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns transceiver delay compensation value
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x3F
  */
static inline uint8_t FLEXCANREG_GetFdctrlTdcval (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->FDCTRL & FLEXCAN_FDCTRL_TDCVAL_MASK) >> FLEXCAN_FDCTRL_TDCVAL_SHIFT);
}

/**
  * \brief  Get fast prescaler division factor
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns fast prescaler division factor
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x3FF
  */
static inline uint16_t FLEXCANREG_GetFdPrescalerDivision (FLEXCANREG_TypeDef *obj)
{
    return (uint16_t)((obj->FDCBT & FLEXCAN_FDCBT_FPRESDIV_MASK) >> FLEXCAN_FDCBT_FPRESDIV_SHIFT);
}

/**
  * \brief  Set fast prescaler division factor
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    fast prescaler division factor
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x3FF
  */
static inline void FLEXCANREG_SetFdPrescalerDivision (FLEXCANREG_TypeDef *obj, uint16_t val)
{
    uint32_t tempReg;

    tempReg = obj->FDCBT;
    tempReg &= (~FLEXCAN_FDCBT_FPRESDIV_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_FDCBT_FPRESDIV_SHIFT) & FLEXCAN_FDCBT_FPRESDIV_MASK;
    obj->FDCBT = tempReg;
}

/**
  * \brief  Get fast resync jump width
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns fast resync jump width
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x07
  */
static inline uint8_t FLEXCANREG_GetFdResyncJumpWidth (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->FDCBT & FLEXCAN_FDCBT_FRJW_MASK) >> FLEXCAN_FDCBT_FRJW_SHIFT);
}

/**
  * \brief  Set fast resync jump width
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    fast resync jump width
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x07
  */
static inline void FLEXCANREG_SetFdResyncJumpWidth (FLEXCANREG_TypeDef *obj, uint16_t val)
{
    uint32_t tempReg;

    tempReg = obj->FDCBT;
    tempReg &= (~FLEXCAN_FDCBT_FRJW_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_FDCBT_FRJW_SHIFT) & FLEXCAN_FDCBT_FRJW_MASK;
    obj->FDCBT = tempReg;
}

/**
  * \brief  Get fast propagation segment
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns fast propagation segment
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x1F
  */
static inline uint8_t FLEXCANREG_GetFdPorpSeg (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->FDCBT & FLEXCAN_FDCBT_FPROPSEG_MASK) >> FLEXCAN_FDCBT_FPROPSEG_SHIFT);
}

/**
  * \brief  Set fast propagation segment
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    fast propagation segment
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x1F
  */
static inline void FLEXCANREG_SetFdPorpSeg (FLEXCANREG_TypeDef *obj, uint16_t val)
{
    uint32_t tempReg;

    tempReg = obj->FDCBT;
    tempReg &= (~FLEXCAN_FDCBT_FPROPSEG_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_FDCBT_FPROPSEG_SHIFT) & FLEXCAN_FDCBT_FPROPSEG_MASK;
    obj->FDCBT = tempReg;
}

/**
  * \brief  Get fast phase segment 1
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns fast phase segment 1
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x07
  */
static inline uint8_t FLEXCANREG_GetFdPhaseSeg1 (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->FDCBT & FLEXCAN_FDCBT_FPSEG1_MASK) >> FLEXCAN_FDCBT_FPSEG1_SHIFT);
}

/**
  * \brief  Set fast phase segment 1
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    fast phase segment 1
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x07
  */
static inline void FLEXCANREG_SetFdPhaseSeg1 (FLEXCANREG_TypeDef *obj, uint16_t val)
{
    uint32_t tempReg;

    tempReg = obj->FDCBT;
    tempReg &= (~FLEXCAN_FDCBT_FPSEG1_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_FDCBT_FPSEG1_SHIFT) & FLEXCAN_FDCBT_FPSEG1_MASK;
    obj->FDCBT = tempReg;
}

/**
  * \brief  Get fast phase segment 2
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns fast phase segment 2
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x07
  */
static inline uint8_t FLEXCANREG_GetFdPhaseSeg2 (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->FDCBT & FLEXCAN_FDCBT_FPSEG2_MASK) >> FLEXCAN_FDCBT_FPSEG2_SHIFT);
}

/**
  * \brief  Set fast phase segment 2
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    fast phase segment 2
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x07
  */
static inline void FLEXCANREG_SetFdPhaseSeg2 (FLEXCANREG_TypeDef *obj, uint16_t val)
{
    uint32_t tempReg;

    tempReg = obj->FDCBT;
    tempReg &= (~FLEXCAN_FDCBT_FPSEG2_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_FDCBT_FPSEG2_SHIFT) & FLEXCAN_FDCBT_FPSEG2_MASK;
    obj->FDCBT = tempReg;
}

/**
  * \brief  Get CRC mailbox number for FD_TXCRC
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns CRC mailbox number for FD_TXCRC
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x7F
  */
static inline uint8_t FLEXCANREG_GetFdcrcFdmbcrc (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->FDCRC & FLEXCAN_FDCRC_FDMBCRC_MASK) >> FLEXCAN_FDCRC_FDMBCRC_SHIFT);
}

/**
  * \brief  Get extended transmitted CRC value
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns extended transmitted CRC value
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x1FFFFFF
  */
static inline uint32_t FLEXCANREG_GetFdcrcFdtxcrc (FLEXCANREG_TypeDef *obj)
{
    return (uint32_t)((obj->FDCRC & FLEXCAN_FDCRC_FDTXCRC_MASK) >> FLEXCAN_FDCRC_FDTXCRC_SHIFT);
}

/**
  * \brief  Set extended data phase prescaler division factor
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    value of high resolution extended data phase predivision factor
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x3FF
  */
static inline void FLEXCANREG_SetHighResExtDataPhasePreDiv (FLEXCANREG_TypeDef *obj, uint16_t val)
{
    uint32_t tempReg;

    tempReg = obj->EPRS;
    tempReg &= (~FLEXCAN_EPRS_EDPRESDIV_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_EPRS_EDPRESDIV_SHIFT) & FLEXCAN_EPRS_EDPRESDIV_MASK;
    obj->EPRS = tempReg;
}

/**
  * \brief  Get extended data phase prescaler division factor
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the value of high resolution extended data phase predivision factor
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x3FF
  */
static inline uint16_t FLEXCANREG_GetHighResExtDataPhasePreDiv (FLEXCANREG_TypeDef *obj)
{
    return (uint16_t)(((obj->EPRS) & FLEXCAN_EPRS_EDPRESDIV_MASK) >> FLEXCAN_EPRS_EDPRESDIV_SHIFT);
}

/**
  * \brief  Set extended nominal phase prescaler division factor
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    value of high resolution extended nominal phase predivision factor
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x3FF
  */
static inline void FLEXCANREG_SetHighResExtNominalPhasePreDiv (FLEXCANREG_TypeDef *obj, uint16_t val)
{
    uint32_t tempReg;

    tempReg = obj->EPRS;
    tempReg &= (~FLEXCAN_EPRS_ENPRESDIV_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_EPRS_ENPRESDIV_SHIFT) & FLEXCAN_EPRS_ENPRESDIV_MASK;
    obj->EPRS = tempReg;
}

/**
  * \brief  Get extended nominal phase prescaler division factor
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns value of high resolution extended nominal phase predivision factor
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x3FF
  */
static inline uint16_t FLEXCANREG_GetHighResExtNominalPhasePreDiv (FLEXCANREG_TypeDef *obj)
{
    return (uint16_t)(((obj->EPRS) & FLEXCAN_EPRS_ENPRESDIV_MASK) >> FLEXCAN_EPRS_ENPRESDIV_SHIFT);
}

/**
  * \brief  Set high resolution nominal resynchronization jump width
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    value of high resolution nominal resynchronization jump width
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x7F
  */
static inline void FLEXCANREG_SetHighResNominalResyncJumpWidth (FLEXCANREG_TypeDef *obj, uint8_t val)
{
    uint32_t tempReg;

    tempReg = obj->ENCBT;
    tempReg &= (~FLEXCAN_ENCBT_NRJW_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_ENCBT_NRJW_SHIFT) & FLEXCAN_ENCBT_NRJW_MASK;
    obj->ENCBT = tempReg;
}

/**
  * \brief  Get high resolution nominal resynchronization jump width
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns value of high resolution nominal resynchronization jump width
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x7F
  */
static inline uint8_t FLEXCANREG_GetHighResNominalResyncJumpWidth (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ENCBT) & FLEXCAN_ENCBT_NRJW_MASK) >> FLEXCAN_ENCBT_NRJW_SHIFT);
}

/**
  * \brief  Set high resolution nominal time segment 2
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    value of high resolution nominal time segment 2
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x7F
  */
static inline void FLEXCANREG_SetHighResTimeSeg2 (FLEXCANREG_TypeDef *obj, uint8_t val)
{
    uint32_t tempReg;

    tempReg = obj->ENCBT;
    tempReg &= (~FLEXCAN_ENCBT_NTSEG2_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_ENCBT_NTSEG2_SHIFT) & FLEXCAN_ENCBT_NTSEG2_MASK;
    obj->ENCBT = tempReg;
}

/**
  * \brief  Get high resolution nominal nominal time segment 2
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns value of high resolution nominal nominal time segment 2
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x7F
  */
static inline uint8_t FLEXCANREG_GetHighResTimeSeg2 (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ENCBT) & FLEXCAN_ENCBT_NTSEG2_MASK) >> FLEXCAN_ENCBT_NTSEG2_SHIFT);
}

/**
  * \brief  Set high resolution nominal time segment 1
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    value of high resolution nominal time segment 1
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0xFF
  */
static inline void FLEXCANREG_SetHighResTimeSeg1 (FLEXCANREG_TypeDef *obj, uint8_t val)
{
    uint32_t tempReg;

    tempReg = obj->ENCBT;
    tempReg &= (~FLEXCAN_ENCBT_NTSEG1_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_ENCBT_NTSEG1_SHIFT) & FLEXCAN_ENCBT_NTSEG1_MASK;
    obj->ENCBT = tempReg;
}

/**
  * \brief  Get high resolution nominal nominal time segment 1
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns value of high resolution nominal nominal time segment 1
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0xFF
  */
static inline uint8_t FLEXCANREG_GetHighResTimeSeg1 (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ENCBT) & FLEXCAN_ENCBT_NTSEG1_MASK) >> FLEXCAN_ENCBT_NTSEG1_SHIFT);
}

/**
  * \brief  Set high resolution data phase resynchronization jump width
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    value of data phase resynchronization jump width
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x0F
  */
static inline void FLEXCANREG_SetHighResDataPhaseResynJumpWidth (FLEXCANREG_TypeDef *obj, uint8_t val)
{
    uint32_t tempReg;

    tempReg = obj->EDCBT;
    tempReg &= (~FLEXCAN_EDCBT_DRJW_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_EDCBT_DRJW_SHIFT) & FLEXCAN_EDCBT_DRJW_MASK;
    obj->EDCBT = tempReg;
}

/**
  * \brief  Get high resolution data phase resynchronization jump width
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns value of high resolution data phase resynchronization jump width
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x0F
  */
static inline uint8_t FLEXCANREG_GetHighResDataPhaseResynJumpWidth (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->EDCBT) & FLEXCAN_EDCBT_DRJW_MASK) >> FLEXCAN_EDCBT_DRJW_SHIFT);
}

/**
  * \brief  Set high resolution data phase time segment 2
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    value of data phase time segment 2
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x0F
  */
static inline void FLEXCANREG_SetHighResDataPhaseTimeSeg2 (FLEXCANREG_TypeDef *obj, uint8_t val)
{
    uint32_t tempReg;

    tempReg = obj->EDCBT;
    tempReg &= (~FLEXCAN_EDCBT_DTSEG2_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_EDCBT_DTSEG2_SHIFT) & FLEXCAN_EDCBT_DTSEG2_MASK;
    obj->EDCBT = tempReg;
}

/**
  * \brief  Get high resolution data phase time segment 2
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns value of high resolution data phase time segment 2
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x0F
  */
static inline uint8_t FLEXCANREG_GetHighResDataPhaseTimeSeg2 (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->EDCBT) & FLEXCAN_EDCBT_DTSEG2_MASK) >> FLEXCAN_EDCBT_DTSEG2_SHIFT);
}

/**
  * \brief  Set high resolution data phase time segment 1
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  val    value of data phase time segment 1
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x1F
  */
static inline void FLEXCANREG_SetHighResDataPhaseTimeSeg1 (FLEXCANREG_TypeDef *obj, uint8_t val)
{
    uint32_t tempReg;

    tempReg = obj->EDCBT;
    tempReg &= (~FLEXCAN_EDCBT_DTSEG1_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_EDCBT_DTSEG1_SHIFT) & FLEXCAN_EDCBT_DTSEG1_MASK;
    obj->EDCBT = tempReg;
}

/**
  * \brief  Get high resolution data phase time segment 1
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns value of high resolution data phase time segment 1
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x1F
  */
static inline uint8_t FLEXCANREG_GetHighResDataPhaseTimeSeg1 (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->EDCBT) & FLEXCAN_EDCBT_DTSEG1_MASK) >> FLEXCAN_EDCBT_DTSEG1_SHIFT);
}

/**
  * \brief  Set enhanced rx fifo enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    enhanced rx fifo enable
  *                    - 0: enhanced rx fifo disabled
  *                    - 1: enhanced rx fifo enabled 
  */
static inline void FLEXCANREG_SetEnhanceRxFifoEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->ERFCR;
    tempReg &= (~FLEXCAN_ERFCR_ERFEN_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_ERFCR_ERFEN_SHIFT) & FLEXCAN_ERFCR_ERFEN_MASK;
    obj->ERFCR = tempReg;
}

/**
  * \brief  Get enhanced rx fifo enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns enhanced rx fifo enable
  *                 - 0: enhanced rx fifo disabled
  *                 - 1: enhanced rx fifo enabled
  */
static inline uint8_t FLEXCANREG_GetEnhanceRxFifoEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ERFCR) & FLEXCAN_ERFCR_ERFEN_MASK) >> FLEXCAN_ERFCR_ERFEN_SHIFT);
}

/**
  * \brief  Set the last DMA address for each enhanced rx fifo element
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    last DMA address for each enhanced rx fifo element
  *                   - This parameter is an unsigned integer that is greater
  *                     than or equal to 0x00 and less than or equal to 0x1F
  */
static inline void FLEXCANREG_SetEnhanceRxFifoDmaLastWord (FLEXCANREG_TypeDef *obj, uint8_t val)
{
    uint32_t tempReg;

    tempReg = obj->ERFCR;
    tempReg &= (~FLEXCAN_ERFCR_DMALW_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_ERFCR_DMALW_SHIFT) & FLEXCAN_ERFCR_DMALW_MASK;
    obj->ERFCR = tempReg;
}

/**
  * \brief  Get the last DMA address for each enhanced rx fifo element
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the last DMA address for each enhanced rx fifo element
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x1F
  */
static inline uint8_t FLEXCANREG_GetEnhanceRxFifoDmaLastWord (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ERFCR) & FLEXCAN_ERFCR_DMALW_MASK) >> FLEXCAN_ERFCR_DMALW_SHIFT);
}

/**
  * \brief  Set the number of extended ID filter elemennts in enhannced rx fifo
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    the number of extended ID filter elemennts in enhannced rx fifo
  *                   - This parameter is an unsigned integer that is greater
  *                     than or equal to 0x00 and less than or equal to 0x7F
  */
static inline void FLEXCANREG_SetExtIdFilterElementNum (FLEXCANREG_TypeDef *obj, uint8_t val)
{
    uint32_t tempReg;

    tempReg = obj->ERFCR;
    tempReg &= (~FLEXCAN_ERFCR_NEXIF_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_ERFCR_NEXIF_SHIFT) & FLEXCAN_ERFCR_NEXIF_MASK;
    obj->ERFCR = tempReg;
}

/**
  * \brief  Get the number of extended ID filter elements in enhannced rx fifo
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the number of extended ID filter elemennts in enhannced rx fifo
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x7F
  */
static inline uint8_t FLEXCANREG_GetExtIdFilterElementNum (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ERFCR) & FLEXCAN_ERFCR_NEXIF_MASK) >> FLEXCAN_ERFCR_NEXIF_SHIFT);
}

/**
  * \brief  Set the number of enhanced rx fifo filter elements
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    the number of enhanced rx fifo filter elements
  *                   - This parameter is an unsigned integer that is greater
  *                     than or equal to 0x00 and less than or equal to 0x3F
  */
static inline void FLEXCANREG_SetEnhanceRxFifoFilterElementNum (FLEXCANREG_TypeDef *obj, uint8_t val)
{
    uint32_t tempReg;

    tempReg = obj->ERFCR;
    tempReg &= (~FLEXCAN_ERFCR_NFE_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_ERFCR_NFE_SHIFT) & FLEXCAN_ERFCR_NFE_MASK;
    obj->ERFCR = tempReg;
}

/**
  * \brief  Get the number of enhanced rx fifo filter elements
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the number of enhanced rx fifo filter elements
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x3F
  */
static inline uint8_t FLEXCANREG_GetEnhance (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ERFCR) & FLEXCAN_ERFCR_NFE_MASK) >> FLEXCAN_ERFCR_NFE_SHIFT);
}

/**
  * \brief  Set the enhanced rx fifo watermark
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    the enhanced rx fifo watermark
  *                   - This parameter is an unsigned integer that is greater
  *                     than or equal to 0x00 and less than or equal to 0x1F
  */
static inline void FLEXCANREG_SetEnhanceRxFifoWatermark (FLEXCANREG_TypeDef *obj, uint8_t val)
{
    uint32_t tempReg;

    tempReg = obj->ERFCR;
    tempReg &= (~FLEXCAN_ERFCR_ERFWM_MASK);
    tempReg |= (((uint32_t)val) << FLEXCAN_ERFCR_ERFWM_SHIFT) & FLEXCAN_ERFCR_ERFWM_MASK;
    obj->ERFCR = tempReg;
}

/**
  * \brief  Get the enhanced rx fifo watermark
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns enhanced rx fifo watermark
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x1F
  */
static inline uint8_t FLEXCANREG_GetEnhanceRxFifoWatermark (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ERFCR) & FLEXCAN_ERFCR_ERFWM_MASK) >> FLEXCAN_ERFCR_ERFWM_SHIFT);
}

/**
  * \brief  Set enhanced rx fifo underflow interrupt enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    enhanced rx fifo underflow interrupt enable
  *                    - 0: enhanced rx fifo underflow interrupt disabled
  *                    - 1: enhanced rx fifo underflow interrupt enabled
  */
static inline void FLEXCANREG_SetEnhanceRxFifoUnderflowIntEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->ERFIER;
    tempReg &= (~FLEXCAN_ERFIER_ERFUFWIE_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_ERFIER_ERFUFWIE_SHIFT) & FLEXCAN_ERFIER_ERFUFWIE_MASK;
    obj->ERFIER = tempReg;
}

/**
  * \brief  Get the enhanced rx fifo underflow interrupt enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns enhanced rx fifo underflow interrupt enable
  *                 - 0: enhanced rx fifo underflow interrupt disabled
  *                 - 1: enhanced rx fifo underflow interrupt enabled
  */
static inline uint8_t FLEXCANREG_GetEnhanceRxFifoUnderflowEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ERFIER) & FLEXCAN_ERFIER_ERFUFWIE_MASK) >> FLEXCAN_ERFIER_ERFUFWIE_SHIFT);
}

/**
  * \brief  Set enhanced rx fifo overflow interrupt enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    enhanced rx fifo overflow interrupt enable
  *                    - 0: disable enhanced rx fifo overflow interrupt 
  *                    - 1: enable enhanced rx fifo overflow interrupt 
  */
static inline void FLEXCANREG_SetEnhanceRxFifoOverflowIntEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->ERFIER;
    tempReg &= (~FLEXCAN_ERFIER_ERFOVFIE_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_ERFIER_ERFOVFIE_SHIFT) & FLEXCAN_ERFIER_ERFOVFIE_MASK;
    obj->ERFIER = tempReg;
}

/**
  * \brief  Get the enhanced rx fifo overflow interrupt enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns enhanced rx fifo overflow interrupt enable
  *                 - 0: enhanced rx fifo overflow interrupt disabled
  *                 - 1: enhanced rx fifo overflow interrupt enabled
  */
static inline uint8_t FLEXCANREG_GetEnhanceRxFifoOverflowIntEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ERFIER) & FLEXCAN_ERFIER_ERFOVFIE_MASK) >> FLEXCAN_ERFIER_ERFOVFIE_SHIFT);
}

/**
  * \brief  Set enhanced rx fifo watermark indication interrupt enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    enhanced rx fifo watermark indication interrupt enable
  *                    - 0: disable enhanced rx fifo watermark indication interrupt
  *                    - 1: enable enhanced rx fifo watermark indication interrupt
  */
static inline void FLEXCANREG_SetEnhanceRxFifoWatrmarkIntEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->ERFIER;
    tempReg &= (~FLEXCAN_ERFIER_ERFWMIIE_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_ERFIER_ERFWMIIE_SHIFT) & FLEXCAN_ERFIER_ERFWMIIE_MASK;
    obj->ERFIER = tempReg;
}

/**
  * \brief  Get enhanced rx fifo watermark indication interrupt enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns enhanced rx fifo watermark indication interrupt enable
  *                 - 0: enhanced rx fifo watermark indication interrupt disabled
  *                 - 1: enhanced rx fifo watermark indication interrupt enabled
  */
static inline uint8_t FLEXCANREG_GetEnhanceRxFifoWatrmarkIntEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ERFIER) & FLEXCAN_ERFIER_ERFWMIIE_MASK) >> FLEXCAN_ERFIER_ERFWMIIE_SHIFT);
}

/**
  * \brief  Set enhanced rx fifo data available interrupt enable
  * \param  obj       FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  enable    enhanced rx fifo data available interrupt enable
  *                    - 0: disable enhanced rx fifo data available interrupt
  *                    - 1: enable enhanced rx fifo data available interrupt
  */
static inline void FLEXCANREG_SetEnhanceRxFifoDataAvailableIntEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->ERFIER;
    tempReg &= (~FLEXCAN_ERFIER_ERFDAIE_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_ERFIER_ERFDAIE_SHIFT) & FLEXCAN_ERFIER_ERFDAIE_MASK;
    obj->ERFIER = tempReg;
}

/**
  * \brief  Get enhanced rx fifo watermark data available interrupt enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns enhanced rx fifo watermark data available interrupt enable
  *                 - 0: enhanced rx fifo watermark data available interrupt disabled
  *                 - 1: enhanced rx fifo watermark data available interrupt enabled
  */
static inline uint8_t FLEXCANREG_GetEnhanceRxFifoDataAvailableIntEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ERFIER) & FLEXCAN_ERFIER_ERFDAIE_MASK) >> FLEXCAN_ERFIER_ERFDAIE_SHIFT);
}

/**
  * \brief  Clear enhanced rx fifo underflow interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  */
static inline void FLEXCANREG_ClearEnhanceRxFifoUnderflowFlag (FLEXCANREG_TypeDef *obj)
{
    obj->ERFSR = FLEXCAN_ERFSR_ERFUFW_MASK;
}

/**
  * \brief  Get enhanced rx fifo underflow interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns enhanced rx fifo underflow interrupt flag
  *                 - 0: enhanced rx fifo underflow interrupt flag is 0
  *                 - 1: enhanced rx fifo underflow interrupt flag is 1
  */
static inline uint8_t FLEXCANREG_GetEnhanceRxFifoUnderflowFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ERFSR) & FLEXCAN_ERFSR_ERFUFW_MASK) >> FLEXCAN_ERFSR_ERFUFW_SHIFT);
}

/**
  * \brief  Clear enhanced rx fifo overflow interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  */
static inline void FLEXCANREG_ClearEnhanceRxFifoOverflowFlag (FLEXCANREG_TypeDef *obj)
{
    obj->ERFSR = FLEXCAN_ERFSR_ERFOVF_MASK;
}

/**
  * \brief  Get enhanced rx fifo overflow interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns enhanced rx fifo overflow interrupt flag
  *                 - 0: enhanced rx fifo overflow interrupt flag is 0
  *                 - 1: enhanced rx fifo overflow interrupt flag is 1
  */
static inline uint8_t FLEXCANREG_GetEnhanceRxFifoOverflowFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ERFSR) & FLEXCAN_ERFSR_ERFOVF_MASK) >> FLEXCAN_ERFSR_ERFOVF_SHIFT);
}

/**
  * \brief  Clear enhanced rx fifo watermark indication interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  */
static inline void FLEXCANREG_ClearEnhanceRxFifoWatermarkFlag (FLEXCANREG_TypeDef *obj)
{
    obj->ERFSR = FLEXCAN_ERFSR_ERFWMI_MASK;
}

/**
  * \brief  Get enhanced rx fifo overflow interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns enhanced rx fifo watermark indication interrupt flag
  *                 - 0: enhanced rx fifo watermark indication interrupt flag is 0
  *                 - 1: enhanced rx fifo watermark indication interrupt flag is 1
  */
static inline uint8_t FLEXCANREG_GetEnhanceRxFifoWatermarkFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ERFSR) & FLEXCAN_ERFSR_ERFWMI_MASK) >> FLEXCAN_ERFSR_ERFWMI_SHIFT);
}

/**
  * \brief  Clear enhanced rx fifo data available interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  */
static inline void FLEXCANREG_ClearEnhanceRxFifoDataAvailableFlag (FLEXCANREG_TypeDef *obj)
{
    obj->ERFSR = FLEXCAN_ERFSR_ERFDA_MASK;
}

/**
  * \brief  Get enhanced rx fifo data available interrupt flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns enhanced rx fifo data available interrupt flag
  *                 - 0: enhanced rx fifo data available interrupt flag is 0
  *                 - 1: enhanced rx fifo data available interrupt flag is 1
  */
static inline uint8_t FLEXCANREG_GetEnhanceRxFifoDataAvailableFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ERFSR) & FLEXCAN_ERFSR_ERFDA_MASK) >> FLEXCAN_ERFSR_ERFDA_SHIFT);
}

/**
  * \brief  Clear enhanced rx fifo content
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  */
static inline void FLEXCANREG_ClearEnhanceRxFifoContent (FLEXCANREG_TypeDef *obj)
{
    obj->ERFSR |= FLEXCAN_ERFSR_ERFCLR_MASK;
}

/**
  * \brief  Get enhanced rx fifo empty flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns enhanced rx fifo empty flag
  *                 - 0: enhanced rx fifo is not empty
  *                 - 1: enhanced rx fifo is empty
  */
static inline uint8_t FLEXCANREG_GetEnhanceRxFifoEmptyFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ERFSR) & FLEXCAN_ERFSR_ERFE_MASK) >> FLEXCAN_ERFSR_ERFE_SHIFT);
}

/**
  * \brief  Get enhanced rx fifo full flag
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns enhanced rx fifo full flag
  *                 - 0: enhanced rx fifo is not full
  *                 - 1: enhanced rx fifo is full
  */
static inline uint8_t FLEXCANREG_GetEnhanceRxFifoFullFlag (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ERFSR) & FLEXCAN_ERFSR_ERFF_MASK) >> FLEXCAN_ERFSR_ERFF_SHIFT);
}

/**
  * \brief  Get element number stored in enhanced rx fifo
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the element number stored in enhanced rx fifo
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x3F
  */
static inline uint8_t FLEXCANREG_GetEnhanceRxFifoElementNum (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)(((obj->ERFSR) & FLEXCAN_ERFSR_ERFEL_MASK) >> FLEXCAN_ERFSR_ERFEL_SHIFT);
}

/**
  * \brief  Get message buffer high resolution time stamp
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the message buffer high resolution time stamp
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline uint32_t FLEXCANREG_GetMsgBufHighResTimeStamp (FLEXCANREG_TypeDef *obj, uint16_t msgBufId)
{
    return obj->HR_TIME_STAMP[msgBufId];
}

/**
  * \brief  Read enhanced rx fifo content
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  ptr    pointer to the 32-bit read data buff
  */
static inline void FLEXCANREG_ReadEnhRxFifo (FLEXCANREG_TypeDef *obj, uint32_t *ptr)
{
    for(uint8_t i = 0; i < 20; i++)
    {
        ptr[i] = obj->ENHRXFIFO[i];
    }
}

/**
  * \brief  Set enhanced rx fifo filter element value
  * \param  obj          FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  elementId    rx fifo filter element ID
  *                       - This parameter is an unsigned integer that is greater
  *                         than or equal to 0 and less than or equal to 127
  * \param  val          rx fifo filter value
  *                       - This parameter is an unsigned integer that is greater
  *                         than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline void FLEXCANREG_SetEnhanceRxFifoElement (FLEXCANREG_TypeDef *obj, uint16_t elementId, uint32_t val)
{
    obj->ERFFEL[elementId] = val;
}

/**
  * \brief  Get enhanced rx fifo filter element value
  * \param  obj          FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  elementId    rx fifo filter element ID
  *                       - This parameter is an unsigned integer that is greater
  *                         than or equal to 0 and less than or equal to 127
  * \return Returns the enhanced rx fifo filter element value
  *                       - This parameter is an unsigned integer that is greater
  *                         than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
static inline uint32_t FLEXCANREG_GetEnhanceRxFifoElement (FLEXCANREG_TypeDef *obj, uint16_t elementId)
{
    return obj->ERFFEL[elementId];
}

/**
  * \brief  Get protocol exception enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns protocol exception enable
  *                 - 0: protocol exception disabled
  *                 - 1: protocol exception enabled
  */
static inline uint8_t FLEXCANREG_GetCtrl2Prexcen (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CTRL2 & FLEXCAN_CTRL2_PREXCEN_MASK) >> FLEXCAN_CTRL2_PREXCEN_SHIFT);
}

/**
  * \brief  Set protocol exception enable
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    protocol exception value
  *                   - 0: disable protocol exception
  *                   - 1: enable protocol exception
  */
static inline void FLEXCANREG_SetCtrl2Prexcen (FLEXCANREG_TypeDef *obj, uint8_t value)
{
    uint32_t tmp = obj->CTRL2;

    tmp &= ~FLEXCAN_CTRL2_PREXCEN_MASK;
    tmp |= (((uint32_t)(((uint32_t)(value)) << FLEXCAN_CTRL2_PREXCEN_SHIFT)) & FLEXCAN_CTRL2_PREXCEN_MASK);
    obj->CTRL2 = tmp;
}

/**
  * \brief  Get ISO CAN FD enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns ISO CAN FD enable
  *                 - 0: ISO CAN FD disabled
  *                 - 1: ISO CAN FD enabled
  */
static inline uint8_t FLEXCANREG_GetIsoFdEnable (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CTRL2 & FLEXCAN_CTRL2_ISOCANFDEN_MASK) >> FLEXCAN_CTRL2_ISOCANFDEN_SHIFT);
}

/**
  * \brief  Set ISO CAN FD enable
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    ISO CAN FD enable
  *                   - 0: disable ISO CAN FD
  *                   - 1: enable ISO CAN FD
  */
static inline void FLEXCANREG_SetIsoFdEnable (FLEXCANREG_TypeDef *obj, uint8_t enable)
{
    uint32_t tempReg;

    tempReg = obj->CTRL2;
    tempReg &= (~FLEXCAN_CTRL2_ISOCANFDEN_MASK);
    tempReg |= (((uint32_t)enable) << FLEXCAN_CTRL2_ISOCANFDEN_SHIFT) & FLEXCAN_CTRL2_ISOCANFDEN_MASK;
    obj->CTRL2 = tempReg;
}

/**
  * \brief  Get edge filter enable
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns edge filter enable
  *                 - 0: edge filter is disabled
  *                 - 1: edge filter is enabled
  */
static inline uint8_t FLEXCANREG_GetCtrl2Edfltdis (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CTRL2 & FLEXCAN_CTRL2_EDFLTDIS_MASK) >> FLEXCAN_CTRL2_EDFLTDIS_SHIFT);
}

/**
  * \brief  Set edge filter enable
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    edge filter enable
  *                   - 0: enable edge filter
  *                   - 1: disable edge filter
  */
static inline void FLEXCANREG_SetCtrl2Edfltdis (FLEXCANREG_TypeDef *obj, uint8_t value)
{
    uint32_t tmp = obj->CTRL2;

    tmp &= ~FLEXCAN_CTRL2_EDFLTDIS_MASK;
    tmp |= (((uint32_t)(((uint32_t)(value)) << FLEXCAN_CTRL2_EDFLTDIS_SHIFT)) & FLEXCAN_CTRL2_EDFLTDIS_MASK);
    obj->CTRL2 = tmp;
}

/**
  * \brief  Get lowest priority Tx mailbox 
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the lowest priority Tx mailbox
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x7F
  */
static inline uint8_t FLEXCANREG_GetEsr2Lptm (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->ESR2 & FLEXCAN_ESR2_LPTM_MASK) >> FLEXCAN_ESR2_LPTM_SHIFT);
}

/**
  * \brief  Get valid priority status
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the valid priority status
  *                 - 0: contents of IMB and LPTM are invalid
  *                 - 1: contents of IMB and LPTM are valid
  */
static inline uint8_t FLEXCANREG_GetEsr2Vps (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->ESR2 & FLEXCAN_ESR2_VPS_MASK) >> FLEXCAN_ESR2_VPS_SHIFT);
}

/**
  * \brief  Get inactive mailbox
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the inactive mailbox
  *                 - 0: if CAN_ESR2.VPS is asserted, CAN_ESR2.LPTM is not an inactive mailbox
  *                 - 1: if CAN_ESR2.VPS is asserted, there is at least one inactive maibox,
  *                      CAN_ESR2.LPTM content is the number of the first one
  */
static inline uint8_t FLEXCANREG_GetEsr2Imb (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->ESR2 & FLEXCAN_ESR2_IMB_MASK) >> FLEXCAN_ESR2_IMB_SHIFT);
}

/**
  * \brief  Get CRC mailbox
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the number of the mailbox corresponding to the value in CAN_CRCR.TXCRC field
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x7F
  */
static inline uint8_t FLEXCANREG_GetCrcrMbcrc (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->CRCR & FLEXCAN_CRCR_MBCRC_MASK) >> FLEXCAN_CRCR_MBCRC_SHIFT);
}

/**
  * \brief  Get transmitted CRC mailbox
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the CRC value of the last transmitted message for non-FD frames
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x7FFF
  */
static inline uint16_t FLEXCANREG_GetCrcrTxcrc (FLEXCANREG_TypeDef *obj)
{
    return ((obj->CRCR & FLEXCAN_CRCR_TXCRC_MASK) >> FLEXCAN_CRCR_TXCRC_SHIFT);
}

/**
  * \brief  Get transmit error counter for all errors detected in received message
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns the transmit error counter for all errors detected in received message
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0xFF
  */
static inline uint8_t FLEXCANREG_GetEcrTxerrcnt (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->ECR & FLEXCAN_ECR_TXERRCNT_MASK) >> FLEXCAN_ECR_TXERRCNT_SHIFT);
}

/**
  * \brief  Set transmit error counter
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    transmit error counter
  *                   - This parameter is an unsigned integer that is greater
  *                     than or equal to 0x00 and less than or equal to 0xFF
  */
static inline void FLEXCANREG_SetEcrTxerrcnt (FLEXCANREG_TypeDef *obj, uint8_t value)
{
    uint32_t tmp = obj->ECR;

    tmp &= ~FLEXCAN_ECR_TXERRCNT_MASK;
    tmp |= (((uint32_t)(((uint32_t)(value)) << FLEXCAN_ECR_TXERRCNT_SHIFT)) & FLEXCAN_ECR_TXERRCNT_MASK);
    obj->ECR = tmp;
}

/**
  * \brief  Get receive error counter for all errors detected in received message
  * \param  obj    FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \return Returns receive error counter for all errors detected in received message
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0xFF
  */
static inline uint8_t FLEXCANREG_GetEcrRxerrcnt (FLEXCANREG_TypeDef *obj)
{
    return (uint8_t)((obj->ECR & FLEXCAN_ECR_RXERRCNT_MASK) >> FLEXCAN_ECR_RXERRCNT_SHIFT);
}

/**
  * \brief  Set receive error counter
  * \param  obj      FLEXCAN pointer to a FLEXCANREG_TypeDef structure
  * \param  value    receive error counter
  *                   - This parameter is an unsigned integer that is greater
  *                     than or equal to 0x00 and less than or equal to 0xFF
  */
static inline void FLEXCANREG_SetEcrRxerrcnt (FLEXCANREG_TypeDef *obj, uint8_t value)
{
    uint32_t tmp = obj->ECR;

    tmp &= ~FLEXCAN_ECR_RXERRCNT_MASK;
    tmp |= (((uint32_t)(((uint32_t)(value)) << FLEXCAN_ECR_RXERRCNT_SHIFT)) & FLEXCAN_ECR_RXERRCNT_MASK);
    obj->ECR = tmp;
}

/**
  * \brief  Convert message buff size to the corresponding RAM size
  * \param  MBSizeCode    message buff size
  *                        - 0: FLEXCANDRV_MB_SIZE_BYTE_8
  *                        - 1: FLEXCANDRV_MB_SIZE_BYTE_16
  *                        - 2: FLEXCANDRV_MB_SIZE_BYTE_32
  *                        - 3: FLEXCANDRV_MB_SIZE_BYTE_64
  * \return Returns the corresponding RAM size
  *                        - This parameter is one of the data elements in the following array
  *                          [0, 16, 24, 40, 72]
  */
extern uint8_t FLEXCANDRV_ConvertMsgBufSizeSel (uint8_t MBSizeCode);

/** 
  * \brief  Get the message buff start address
  * \param  obj         pointer to a FLEXCANDRV_Type structure
  * \param  msgBufId    message buffer index to store the message object
  *                      - This parameter is an unsigned integer that is greater
  *                        than or equal to 0x00 and less than or equal to 0x7F
  * \return Returns the message buff stars address
  *                      - This parameter is an unsigned integer that is greater
  *                        than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
extern uint32_t FLEXCANDRV_GetMsgBufStartAddr (FLEXCANDRV_Type *obj, uint16_t msgBufId);

/**
  * \brief  Convert message buff DLC type to message buff data length
  * \param  dlc    message buff size
  *                 - This parameter can be any value of @ref FLEXCANDRV_DATALENCODETYPE
  * \return Returns the corresponding message buff data length
  *                 - This parameter is one of the data elements in the following array
  *                   [0 ~ 8, 12, 16, 24, 32, 48, 64]
  */
extern uint8_t FLEXCANDRV_DLC2DataLen (FLEXCANDRV_DataLenCodeType dlc);

/**
  * \brief  Set the message ID and ID type
  * \param  msgBufPtr    pointer to the message buff address
  * \param  msgId        11-bit or 29-bit message ID
  *                       - This parameter is an unsigned integer that is greater 
  *                         than or equal to 0x00 and less than or equal to 0x1FFFFFFF
  * \param  isExt        the message ID is standard ID or extended ID
  *                       - 0: standard ID
  *                       - 1: extended ID
  */
extern void FLEXCANDRV_SetMsgId (uint32_t *msgBufPtr, uint32_t msgId, bool isExt);

/**
  * \brief  Set the message buff DLC
  * \param  msgBufPtr    pointer to the message buff address
  * \param  dlc          CODE for message buff data length
  *                       - This parameter can be any value of @ref FLEXCANDRV_DATALENCODETYPE
  */
extern void FLEXCANDRV_SetMsgDLC (uint32_t *msgBufPtr, FLEXCANDRV_DataLenCodeType dlc);

/**
  * \brief  Set message buff DODE for CAN-FD feature
  * \param  msgBufPtr    pointer to the message buff address
  * \param  fdEnable     enable the CAN-FD feature
  *                       - 0: disable the CAN-FD feature
  *                       - 1: enable the CAN-FD feature
  */
extern void FLEXCANDRV_SetFDEnable (uint32_t *msgBufPtr, bool fdEnable);

/**
  * \brief  Set the message type for TX or RX
  * \param  msgBufPtr    pointer to the message buff address
  * \param  msgType      the message type for TX or RX
  *                       - This parameter can be any value of @ref FLEXCANDRV_MSGTYPE
  */
extern void FLEXCANDRV_SetMsgType (uint32_t *msgBufPtr, FLEXCANDRV_MsgType msgType);

/**
  * \brief  Initialize the RAM space of FLEXCAN
  * \param  obj    pointer to a FLEXCANDRV_Type structure
  */
extern void FLEXCANDRV_InitCanRAM (FLEXCANDRV_Type *obj);

/** 
  * \brief  Initializes the FLEXCAN driver module
  * \param  obj           pointer to a FLEXCANDRV_Type structure
  * \param  flexCanReg    pointer to a FLEXCANREG_TypeDef structure
  * \param  initHwPar     pointer to a FLEXCANDRV_InitHwParType structure
  */
extern void FLEXCANDRV_Init (FLEXCANDRV_Type *obj, FLEXCANREG_TypeDef *flexCanReg, \
                             FLEXCANDRV_InitHwParType *initHwPar);

/**
  * \brief  Get the default configuration for FLEXCAN controller
  * \param  controllerCfg    pointer to a FLEXCANDRV_ControllerCfgType structure
  */ 
extern void FLEXCANDRV_GetDefaultCfg (FLEXCANDRV_ControllerCfgType *controllerCfg);

/**
  * \brief  Soft reset FLEXCAN module
  * \param  obj    pointer to a FLEXCANDRV_Type structure
  */
extern void FLEXCANDRV_SoftReset (FLEXCANDRV_Type *obj);

/** 
  * \brief  Start FLEXCAN module
  * \param  obj    pointer to a FLEXCANDRV_Type structure
  */
extern void FLEXCANDRV_Start (FLEXCANDRV_Type *obj);

/** 
  * \brief  Configure and initialize FLEXCAN controller from user configuration
  * \param  obj              pointer to a FLEXCANDRV_Type structure
  * \param  controllerCfg    pointer to a FLEXCANDRV_ControllerCfgType structure
  */
extern void FLEXCANDRV_Configure (FLEXCANDRV_Type *obj, const FLEXCANDRV_ControllerCfgType *controllerCfg);

/** 
  * \brief  Configure message object and register the specified CAN message buffer
  * \param  obj         pointer to a FLEXCANDRV_Type structure
  * \param  msgCfg      pointer to a FLEXCANDRV_MsgCfgType structure
  * \param  msgBufId    message buffer index to store the message object
  *                      - This parameter is an unsigned integer that is greater
  *                        than or equal to 0x00 and less than or equal to 0x7F
  */
extern void FLEXCANDRV_CfgMsgObj (FLEXCANDRV_Type *obj, const FLEXCANDRV_MsgCfgType *msgCfg, uint8_t msgBufId);

/** 
  * \brief  Set enhanced rx fifo filter for mask filter type
  * \param  obj              pointer to a FLEXCANDRV_Type structure
  * \param  controllerCfg    pointer to a FLEXCANDRV_ControllerCfgType structure
  * \param  extIdNum         the number of extended ID
  * \param  stdIdNum         the number of standard ID
  * \return Returns the status of these operations
  *                          - 0: these operations are failed
  *                          - 1: these operations are suecceed
  */
extern bool FLEXCANDRV_SetEnhanceRxFifoFilterInMask (FLEXCANDRV_Type *obj, \
                                                     const FLEXCANDRV_ControllerCfgType *controllerCfg, \
                                                     uint8_t extIdNum, uint8_t stdIdNum);

/** 
  * \brief  Set enhanced rx fifo filter for range filter type
  * \param  obj              pointer to a FLEXCANDRV_Type structure
  * \param  controllerCfg    pointer to a FLEXCANDRV_ControllerCfgType structure
  * \param  extIdNum         the number of extended ID
  * \param  stdIdNum         the number of standard ID
  * \return Returns the status of these operations
  *                          - 0: these operations have failed
  *                          - 1: these operations have succeeded
  */
extern bool FLEXCANDRV_SetEnhanceRxFifoFilterInRange (FLEXCANDRV_Type *obj, \
                                                      const FLEXCANDRV_ControllerCfgType *controllerCfg, \
                                                      uint8_t extIdNum, uint8_t stdIdNum);

/** 
  * \brief  Set enhanced rx fifo filter for without mask filter type
  * \param  obj              pointer to a FLEXCANDRV_Type structure
  * \param  controllerCfg    pointer to a FLEXCANDRV_ControllerCfgType structure
  * \param  extIdNum         the number of extended ID
  * \param  stdIdNum         the number of standard ID
  * \return Returns the status of these operations
  *                          - 0: these operations have failed
  *                          - 1: these operations have succeeded
  */
extern bool FLEXCANDRV_SetEnhanceRxFifoFilterInWithoutMask (FLEXCANDRV_Type *obj, \
                                                            const FLEXCANDRV_ControllerCfgType *controllerCfg, \
                                                            uint8_t extIdNum, uint8_t stdIdNum);

/** 
  * \brief  Initialize the enhanced rx fifo filter element
  * \param  obj              pointer to a FLEXCANDRV_Type structure
  * \param  controllerCfg    pointer to a FLEXCANDRV_ControllerCfgType structure
  */
extern void FLEXCANDRV_InitEnhanceRxFFFilterElement (FLEXCANDRV_Type *obj, \
                                                     const FLEXCANDRV_ControllerCfgType *controllerCfg);

/** 
  * \brief  Set the enhanced rx fifo filter configuration
  * \param  obj              pointer to a FLEXCANDRV_Type structure
  * \param  controllerCfg    pointer to a FLEXCANDRV_ControllerCfgType structure
  */
extern void FLEXCANDRV_SetEnhanceRxFifoConfig (FLEXCANDRV_Type *obj, \
                                               const FLEXCANDRV_ControllerCfgType *controllerCfg);

/** 
  * \brief  Transmit the message unconditionally once
  * \param  obj       pointer to a FLEXCANDRV_Type structure
  * \param  msgObj    pointer to a FLEXCANDRV_MsgObjType structure
  */
extern void FLEXCANDRV_TransmitMsg (FLEXCANDRV_Type *obj, FLEXCANDRV_MsgObjType *msgObj);

/** 
  * \brief  Set the transmit message object into message buffer
  * \param  obj       pointer to a FLEXCANDRV_Type structure
  * \param  msgObj    pointer to a FLEXCANDRV_MsgObjType structure
  */
extern void FLEXCANDRV_SetTxMsg (FLEXCANDRV_Type *obj, FLEXCANDRV_MsgObjType *msgObj);

/** 
  * \brief  Get the message object from message buffer
  * \param  obj       pointer to a FLEXCANDRV_Type structure
  * \param  msgObj    pointer to a FLEXCANDRV_MsgObjType structure
  */
extern void FLEXCANDRV_GetRxMsg (FLEXCANDRV_Type *obj, FLEXCANDRV_MsgObjType *msgObj);

/**
  * \brief  Get the message object from rx fifo
  * \param  obj       pointer to a FLEXCANDRV_Type structure
  * \param  msgObj    pointer to a FLEXCANDRV_MsgObjType structure
  */
extern void FLEXCANDRV_GetRxFifoMsg (FLEXCANDRV_Type *obj, FLEXCANDRV_MsgObjType *msgObj);

/** 
  * \brief  Get message object flag, indicating a successful Rx/Tx operation completed
  * \param  obj             pointer to a FLEXCANDRV_Type structure
  * \param  msgBufferIdx    message buffer index
  *                          - This parameter is an unsigned integer that is greater
  *                            than or equal to 0x00 and less than or equal to 0xFF
  * \return Returns message buffer Tx/Rx operation complete flag
  *                          - 0: the corresponding buffer has no occurrence of successfully
  *                               completed transmission or reception
  *                          - 1: the corresponding buffer has successfully completed transmission
  *                               or reception
  */
extern uint8_t FLEXCANDRV_GetMsgObjFlag (FLEXCANDRV_Type *obj, uint8_t msgBufferIdx);

/** 
  * \brief  Get the message object from rx fifo
  * \param  obj       pointer to a FLEXCANDRV_Type structure
  * \param  msgObj    pointer to a FLEXCANDRV_MsgObjType structure
  */
extern void FLEXCANDRV_GetRxFifoMsg (FLEXCANDRV_Type *obj, FLEXCANDRV_MsgObjType *msgObj);

/** 
  * \brief  Clear message object flag
  * \param  obj             pointer to a FLEXCANDRV_Type structure
  * \param  msgBufferIdx    message buffer index
  *                          - This parameter is an unsigned integer that is greater
  *                            than or equal to 0x00 and less than or equal to 0xFF
  */
extern void FLEXCANDRV_ClearMsgObjFlag (FLEXCANDRV_Type *obj, uint8_t msgBufferIdx);

/** 
  * \brief  Clear all message object flags
  * \param  obj    pointer to a FLEXCANDRV_Type structure
  */
extern void FLEXCANDRV_ClearAllMsgObjFlags (FLEXCANDRV_Type *obj);

/**
  * \brief  Enable interrupt for the corresponding message buffer
  * \param  obj             pointer to a FLEXCANDRV_Type structure
  * \param  msgBufferIdx    message buffer index
  *                          - This parameter is an unsigned integer that is greater
  *                            than or equal to 0x00 and less than or equal to 0xFF
  */
extern void FLEXCANDRV_EnableMsgObjInterrupt (FLEXCANDRV_Type *obj, uint8_t msgBufferIdx);

/** 
  * \brief  Disable interrupt for the corresponding message buffer
  * \param  obj             pointer to a FLEXCANDRV_Type structure
  * \param  msgBufferIdx    message buffer index
  *                          - This parameter is an unsigned integer that is greater
  *                            than or equal to 0x00 and less than or equal to 0xFF
  */
extern void FLEXCANDRV_DisableMsgObjInterrupt (FLEXCANDRV_Type *obj, uint8_t msgBufferIdx);

/** 
  * \brief  Get the default FlexCan controller configuration parameters
  * \param  controllerCfg    pointer to a FLEXCANDRV_ControllerCfgType structure
  */
extern void FLEXCANDRV_GetDefaultCfg (FLEXCANDRV_ControllerCfgType *controllerCfg);

/** 
  * \brief  Calculate the CAN bit timing parameters
  * \param  bitTimingPara    pointer to a FLEXCANDRV_BitTimingType structure
  * \param  clkFreq          FLEXCAN module frequency
  * \param  samplePoint      can bit sample point (0 - 10000 -> 0 - 100%)
  * \param  sjw              synchronize jump width (0 - 10000 -> 0 - 100%)
  * \param  isFd             is the bit timing parameter group for CAN-FD
  */
extern void FLEXCANDRV_BitTimingCalc (FLEXCANDRV_BitTimingType *bitTimingPara, \
                                      uint32_t                  clkFreq,       \
                                      uint32_t                  baudrate,      \
                                      uint16_t                  samplePoint,   \
                                      uint16_t                  sjw,           \
                                      uint8_t                   isFd);

/** 
  * \brief  Get FlexCan error states
  * \param  obj    pointer to a FLEXCANDRV_Type structure
  * \return Returns node status
  *                 -This parameter can be any value of @ref FLEXCANDRV_NODESTATTYPE
  */
extern FLEXCANDRV_NodeStatType FLEXCANDRV_GetNodeStatus (FLEXCANDRV_Type *obj);

/** 
  * \brief  Get FlexCan error states
  * \param  obj       pointer to a FLEXCANDRV_Type structure
  * \param  errSts    pointer to a FLEXCANDRV_ErrStatusType structure
  */
extern void FLEXCANDRV_GetErrorStatusFlag (FLEXCANDRV_Type *obj, FLEXCANDRV_ErrStatusType *errSts);

/** 
  * \brief  Clear error states flag
  * \param  obj        pointer to a FLEXCANDRV_Type structure
  * \param  errMask    err state bit mask combination
  *                     - This parameter can be any value of @ref FLEXCANDRV_ERRSTATUSMASKTYPE
  */
extern void FLEXCANDRV_ClearErrStatusFlag (FLEXCANDRV_Type *obj, FLEXCANDRV_ErrStatusMaskType errMask);

/** 
  * \brief  Abort pending Tx message
  * \param  obj       pointer to a FLEXCANDRV_Type structure
  * \param  msgObj    pointer to a FLEXCANDRV_MsgObjType structure
  * \return Returns pending Tx message abort result
  *                   - 0: no Tx message transfer pending
  *                   - 1: pending Tx message abort success
  */
extern uint8_t FLEXCANDRV_AbortPendingTxMsg (FLEXCANDRV_Type *obj, FLEXCANDRV_MsgObjType *msgObj);

/** 
  * \brief  Set enhanced rx fifo water mark
  * \param  obj          pointer to a FLEXCANDRV_Type structure
  * \param  waterMark    the value of enhanced rx fifo watermark
  *                       - This parameter is an unsigned integer that is greater
  *                         than or equal to 0x00 and less than or equal to 0x1F
  */
extern void FLEXCANDRV_SetEnhanceRxFFWaterMark (FLEXCANDRV_Type *obj, uint8_t waterMark);

/** 
  * \brief  Set enhanced rx interrupt request
  * \param  obj           pointer to a FLEXCANDRV_Type structure
  * \param  isrSrcMask    the combine of interrupt source mask
  *                        - user needs to customize their own mask value 
  *                          based on the definition of the ESR1 register
  * \param  enabled       disable or enable these interrupt req
  *                        - 0: disable these interrupt req
  *                        - 1: enable these interrupt req
  */
extern void FLEXCANDRV_SetEnhanceRxFFIsr (FLEXCANDRV_Type *obj, uint32_t isrSrcMask, bool enabled);

/** 
  * \brief  Clear enhanced rx interrupt flag
  * \param  obj           pointer to a FLEXCANDRV_Type structure
  * \param  isrSrcMask    the combine of interrupt source mask
  *                        - user needs to customize their own mask value 
  *                          based on the definition of the ESR1 register
  */
extern void FLEXCANDRV_ClearEnhanceRxFFIsrFlag (FLEXCANDRV_Type *obj, uint32_t isrSrcMask);

/** 
  * \brief  Get enhanced rx interrupt flag
  * \param  obj       pointer to a FLEXCANDRV_Type structure
  * \param  isrSrc    the interrupt source
  *                    - This parameter can be any value of @ref FLEXCANDRV_ENHANCERXFFISRSRCTYPE
  * \return Returns the enhanced rx interrupt flag
  *                    - 0: rx fifo interrupt flag is 0
  *                    - 1: rx fifo interrupt flag is 1
  */
extern bool FLEXCANDRV_GetEnhanceRxFFIsrFlag (FLEXCANDRV_Type *obj, \
                                              FLEXCANDRV_EnhanceRxFFIsrSrcType isrSrc);

/** 
  * \brief  Get the enhanced rx fifo is empyt or not
  * \param  obj    pointer to a FLEXCANDRV_Type structure
  * \return Returns the enhanced rx fifo is empty or not
  *                 - 0: rx fifo is not empyt
  *                 - 1: rx fifo is empty
  */
extern bool FLEXCANDRV_GetEnhanceRxFFIsEmpty (FLEXCANDRV_Type *obj);

/** 
  * \brief  Get the enhanced rx fifo is full or not
  * \param  obj    pointer to a FLEXCANDRV_Type structure
  * \return Returns the enhanced rx fifo is full or not
  *                 - 0: rx fifo is not full
  *                 - 1: rx fifo is full
  */
extern bool FLEXCANDRV_GetEnhanceRxFFIsFull (FLEXCANDRV_Type *obj);

/** 
  * \brief  Get the number of message stored in the enhanced rx fifo
  * \param  obj    pointer to a FLEXCANDRV_Type structure
  * \return Returns the number of message stored in the enhanced rx fifo
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x3F
  */
extern uint8_t FLEXCANDRV_GetEnhanceRxFFMsgNums (FLEXCANDRV_Type *obj);

/** 
  * \brief  Get the received message from enhanced rx fifo
  * \param  obj       pointer to a FLEXCANDRV_Type structure
  * \param  msgObj    pointer to a FLEXCANDRV_MsgObjType structure
  */
extern void FLEXCANDRV_GetEnhanceRxFifoMsg (FLEXCANDRV_Type *obj, FLEXCANDRV_MsgObjType *msgObj);

/** 
  * \brief  Set the leagcy rx fifo ID filter
  * \param  obj              pointer to a FLEXCANREG_TypeDef structure
  * \param  idFilterTable    pointer to a FLEXCAN_FIFOFILTERIDTABLE
  */
extern void FLEXCANDRV_SetRxFifoFilter (FLEXCANREG_TypeDef *obj, \
                                        const FLEXCANDRV_FifoFilterIdTable *idFilterTable);

/** 
  * \brief  Set the remote frame msg by CAN
  * \param  obj         pointer to a FLEXCANDRV_Type structure
  * \param  msgId       the ID for the remote frame
  *                      - This parameter is an unsigned integer that is greater 
  *                        than or equal to 0x00 and less than or equal to 0x7FF
  * \param  msgBufId    mailbox number used for transmite the remote frame
  *                      - This parameter is an unsigned integer that is greater 
  *                        than or equal to 0x00 and less than or equal to 0x7F
  */
extern void FLEXCANDRV_SetRemoteTxMsg (FLEXCANDRV_Type *obj, uint32_t msgId, uint16_t msgBufId);

/**
  * \brief  Transmite the remote frame msg
  * \param  obj         pointer to a FLEXCANDRV_Type structure
  * \param  msgBufId    mailbox number used for transmite the remote frame
  *                      - This parameter is an unsigned integer that is greater 
  *                        than or equal to 0x00 and less than or equal to 0x7F
  */
extern void FLEXCANDRV_TransmitRemoteTxMsg (FLEXCANDRV_Type *obj, uint16_t msgBufId);

/** 
  * \brief  Set the remote response msg for MB rx 
  * \param  obj         pointer to a FLEXCANDRV_Type structure
  * \param  msgId       the ID for the remote frame
  *                      - This parameter is an unsigned integer that is greater 
  *                        than or equal to 0x00 and less than or equal to 0x7FF
  * \param  msgBufId    mailbox number used for transmite the remote frame
  *                      - This parameter is an unsigned integer that is greater 
  *                        than or equal to 0x00 and less than or equal to 0x7F
  * \param  data        pointer to the 8-bit msg data buff that prepared to response the remote frame
  * \param  length      the length for the msg data (byte)
  *                      - This parameter is an unsigned integer that is greater 
  *                        than or equal to 0 and less than or equal to 8
  */
extern void FLEXCANDRV_SetRemoteResponMsg (FLEXCANDRV_Type *obj, uint32_t msgId, uint16_t msgBufId, \
                                           uint8_t *data, uint8_t length);

#ifdef __cplusplus
}
#endif


#endif /* __FLEXCAN_H__ */
