/**
 * @file       NS800RT7xxx_TI_flexcan.h
 * @author     Gordon-Zheng
 * @brief      Header file for NS800RT7xxx FLEXCAN module(TI).
 *
 * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
 * All rights reserved.</center></h2>
 */

#ifndef __NS800RT7XXX_TI_FLEXCAN_H__
#define __NS800RT7XXX_TI_FLEXCAN_H__


#ifdef __cplusplus
extern "C" {
#endif


#if defined (NS800RT7P65X)
  #include "NS800RT7P65x.h"
#endif


/*******************************************************************************
 * the defines
 ******************************************************************************/

/** @defgroup FLEXCAN_EXPORTED_TYPES FLEXCAN Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'FLEXCAN' module.
  */

/** @defgroup FLEXCANREG_TYPEDEF the definition of FLEXCAN Registers 
  * @{
  * @brief  Macro definitions about FLEXCAN registers.
  */
typedef struct _FlexCanRegType_ {
    volatile uint32_t MCR;                   /*!< module configuration register, offset: 0000H */
    volatile uint32_t CTRL1;                 /*!< control1 register, offset: 0004H */
    volatile uint32_t TIMER;                 /*!< free running timer register, offset: 0008H */
    volatile uint32_t REVERSED0;             /*!< resverd register, offset: 000CH */
    volatile uint32_t RXMGMASK;              /*!< rx mailbox global mask register, offset: 0010H */
    volatile uint32_t RX14MASK;              /*!< rx 14 mask register, offset: 0014H */
    volatile uint32_t RX15MASK;              /*!< rx 15 mask register, offset: 0018H */
    volatile uint32_t ECR;                   /*!< error countner register, offset: 001CH */
    volatile uint32_t ESR1;                  /*!< error and status 1 register, offset: 0020H */
    volatile uint32_t IMASK2;                /*!< interrupt mask 2 register, offset: 0024H */
    volatile uint32_t IMASK1;                /*!< interrupt mask 1 register, offset: 0028H */
    volatile uint32_t IFLAG2;                /*!< interrupt flags 2 register, offset: 002CH */
    volatile uint32_t IFLAG1;                /*!< interrupt flags 1 register, offset: 0030H */
    volatile uint32_t CTRL2;                 /*!< control 2 register, offset: 0034H */
    volatile uint32_t ESR2;                  /*!< error and status 2 register, offset: 0038H */
    volatile uint32_t REVERSED1[2];          /*!< reversed register, offset: 003CH */
    volatile uint32_t CRCR;                  /*!< crc register, offset: 0044H */
    volatile uint32_t RXFGMASK;              /*!< rx fifo global mask register, offset: 0048H */
    volatile uint32_t RXFIR;                 /*!< rx fifo information register, offset: 004CH */
    volatile uint32_t CBT;                   /*!< CAN bit timing register, offset: 0050H */
    volatile uint32_t REVERSED2[5];          /*!< reversed register, offset: 0054H */
    volatile uint32_t IMASK4;                /*!< interrupt mask 4 register, offset: 0068H */
    volatile uint32_t IMASK3;                /*!< interrupt mask 3 register, offset: 006CH */
    volatile uint32_t IFLAG4;                /*!< interrupt flags 4 register, offset: 0070H */
    volatile uint32_t IFLAG3;                /*!< interrupt flags 3 register, offset: 0074H */
    volatile uint32_t REVERSED3[2];          /*!< reversed registers, offset: 0078H */
    volatile uint32_t MSGBUF[512];           /*!< message buffers, offset: 0080H */
    volatile uint32_t RXIMR[128];            /*!< rx individual mask registers, offset: 0880H */
    volatile uint32_t REVERSED4[24];         /*!< reversed register, offset: 0A80H */
    volatile uint32_t MECR;                  /*!< memory error control register, offset: 0AE0H */
    volatile uint32_t ERRIAR;                /*!< error injection address register, offset: 0AE4H */
    volatile uint32_t ERRIDPR;               /*!< error injection data pattern register, offset: 0AE8H */
    volatile uint32_t ERRIPPR;               /*!< error injection parity pattern register, offset: 0AECH */
    volatile uint32_t RERRAR;                /*!< error report address register, offset: 0AF0H */
    volatile uint32_t RERRDR;                /*!< error report data register, offset: 0AF4H */
    volatile uint32_t RERRSYNR;              /*!< error report syndrome register, offset: 0AF8H */
    volatile uint32_t ERRSR;                 /*!< error status register, offset: 0AFCH */
    volatile uint32_t CTRL1_PN;              /*!< pretended networking control 1 register, offset: 0B00H */
    volatile uint32_t CTRL2_PN;              /*!< pretended networking control 2 register, offset: 0B04H */
    volatile uint32_t WU_MTC;                /*!< pretended networking wake up match register, offset: 0B08H */
    volatile uint32_t FLT_ID1;               /*!< pretended networking ID filter 1 register, offset: 0B0CH */
    volatile uint32_t FLT_DLC;               /*!< pretended networking DLC filter register, offset: 0B10H */
    volatile uint32_t PL1_LO;                /*!< pretended networking payload low filter 1 register, offset: 0B14H */
    volatile uint32_t PL1_HI;                /*!< pretended networking payload high filter 1 register, offset: 0B18H */
    volatile uint32_t FLT_ID2_IDMASK;        /*!< pretended networking ID filter 2 register / ID mask register, offset: 0B1CH */
    volatile uint32_t PL2_PLMASK_LO;         /*!< pretended networking payload low filter 2 register, offset: 0B20H */
    volatile uint32_t PL2_PLMASK_HI;         /*!< pretended networking payload high filter 2 register, offset: 0B24H */
    volatile uint32_t REVERSED5[6];          /*!< reversed registers, offset: 0B28H */
    volatile uint32_t WMB0_CS;               /*!< wakeup message buffer 0 register for C/S, offset: 0B40H */
    volatile uint32_t WMB0_ID;               /*!< wakeup message buffer 0 register for ID, offset: 0B44H */
    volatile uint32_t WMB0_D03;              /*!< wakeup message buffer 0 register for data 0 - 3, offset: 0B48H */
    volatile uint32_t WMB0_D47;              /*!< wakeup message buffer 0 register for data 4 - 7, offset: 0B4CH */
    volatile uint32_t WMB1_CS;               /*!< wakeup message buffer 1 register for C/S, offset: 0B50H */
    volatile uint32_t WMB1_ID;               /*!< wakeup message buffer 1 register for ID, offset: 0B54H */
    volatile uint32_t WMB1_D03;              /*!< wakeup message buffer 1 register for data 0 - 3, offset: 0B58H */
    volatile uint32_t WMB1_D47;              /*!< wakeup message buffer 1 register for data 4 - 7, offest: 0B5CH */
    volatile uint32_t WMB2_CS;               /*!< wakeup message buffer 2 register for C/S, offset: 0B60H */
    volatile uint32_t WMB2_ID;               /*!< wakeup message buffer 2 register for ID, offset: 0B64H */
    volatile uint32_t WMB2_D03;              /*!< wakeup message buffer 2 register for data 0 - 3, offset: 0B68H */
    volatile uint32_t WMB2_D47;              /*!< wakeup message buffer 2 register for data 4 - 7, offest: 0B6CH */
    volatile uint32_t WMB3_CS;               /*!< wakeup message buffer 3 register for C/S, offset: 0B70H */
    volatile uint32_t WMB3_ID;               /*!< wakeup message buffer 3 register for ID, offset: 0B74H */
    volatile uint32_t WMB3_D03;              /*!< wakeup message buffer 3 register for data 0 - 3, offset: 0B78H */
    volatile uint32_t WMB3_D47;              /*!< wakeup message buffer 3 register for data 4 - 7, offest: 0B7CH */
    volatile uint32_t REVERSED6[28];         /*!< reversed registers, offset: 0B80H */
    volatile uint32_t EPRS;                  /*!< enhanced CAN Bit timing prescalers register, offset: 0BF0H */
    volatile uint32_t ENCBT;                 /*!< enhanced nominal CAN Bit timing register, offset: 0BF4H */
    volatile uint32_t EDCBT;                 /*!< enhanced data phase CAN bit timing register, offset: 0BF8H */
    volatile uint32_t REVERSED7;             /*!< reversed registers, offset: 0BFCH */
    volatile uint32_t FDCTRL;                /*!< CAN FD control register, offset: 0C00H */
    volatile uint32_t FDCBT;                 /*!< CAN FD bit timing register, offset: 0C04H */
    volatile uint32_t FDCRC;                 /*!< CAN FD CRC register, offset: 0C08H */
    volatile uint32_t ERFCR;                 /*!< enhanced rx fifo control register, offset: 0C0CH */
    volatile uint32_t ERFIER;                /*!< enhanced rx fifo interrupt enable register, offset: 0C10H */
    volatile uint32_t ERFSR;                 /*!< enhanced rx fifo status register, offset: 0C14H */
    volatile uint32_t REVERSED8[6];          /*!< reversed registers, offset: 0C18H */
    volatile uint32_t HR_TIME_STAMP[128];    /*!< high resolution time stamp registers, offset: 0C30H */
    volatile uint32_t REVERSED9[1140];       /*!< reversed registers, offset: 0E30H */
    volatile uint32_t ENHRXFIFO[640];        /*!< enhanced rx fifo, offset: 2000H */
    volatile uint32_t REVERSED10[384];       /*!< reversed registers, offset: 0E30H */
    volatile uint32_t ERFFEL[128];           /*!< enhanced rx fifo filter element reigster, offset: 3000H */
} FLEXCANREG_TypeDef;

/**
  * @}
  */

/** @defgroup FLEXCAN_MCR FLEXCAN Module Configuration Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_MCR register definition.
  */
#define FLEXCAN_MCR_MDIS_SHIFT       (31UL)
#define FLEXCAN_MCR_MDIS_MASK        (0x1UL << FLEXCAN_MCR_MDIS_SHIFT)
#define FLEXCAN_MCR_MDIS_WIDTH       (1UL)
#define FLEXCAN_MCR_FRZ_SHIFT        (30UL)
#define FLEXCAN_MCR_FRZ_MASK         (0x1UL << FLEXCAN_MCR_FRZ_SHIFT)
#define FLEXCAN_MCR_FRZ_WIDTH        (1UL)
#define FLEXCAN_MCR_RFEN_SHIFT       (29UL)
#define FLEXCAN_MCR_RFEN_MASK        (0x1UL << FLEXCAN_MCR_RFEN_SHIFT)
#define FLEXCAN_MCR_RFEN_WIDTH       (1UL)
#define FLEXCAN_MCR_HALT_SHIFT       (28UL)
#define FLEXCAN_MCR_HALT_MASK        (0x1UL << FLEXCAN_MCR_HALT_SHIFT)
#define FLEXCAN_MCR_HALT_WIDTH       (1UL)
#define FLEXCAN_MCR_NOTRDY_SHIFT     (27UL)
#define FLEXCAN_MCR_NOTRDY_MASK      (0x1UL << FLEXCAN_MCR_NOTRDY_SHIFT)
#define FLEXCAN_MCR_WAKMSK_SHIFT     (26UL)
#define FLEXCAN_MCR_WAKMSK_MASK      (0x1UL << FLEXCAN_MCR_WAKMSK_SHIFT)
#define FLEXCAN_MCR_SOFTRST_SHIFT    (25UL)
#define FLEXCAN_MCR_SOFTRST_MASK     (0x1UL << FLEXCAN_MCR_SOFTRST_SHIFT)
#define FLEXCAN_MCR_SOFTRST_WIDTH    (1UL)
#define FLEXCAN_MCR_FRZACK_SHIFT     (24UL)
#define FLEXCAN_MCR_FRZACK_MASK      (0x1UL << FLEXCAN_MCR_FRZACK_SHIFT)
#define FLEXCAN_MCR_FRZACK_WIDTH     (1UL)
#define FLEXCAN_MCR_SUPV_SHIFT       (23UL)
#define FLEXCAN_MCR_SUPV_MASK        (0x1UL << FLEXCAN_MCR_SUPV_SHIFT)
#define FLEXCAN_MCR_SUPV_WIDTH       (1UL)
#define FLEXCAN_MCR_SLFWAK_SHIFT     (22UL)
#define FLEXCAN_MCR_SLFWAK_MASK      (0x1UL << FLEXCAN_MCR_SLFWAK_SHIFT)
#define FLEXCAN_MCR_SLFWAK_WIDTH     (1UL)
#define FLEXCAN_MCR_WRNEN_SHIFT      (21UL)
#define FLEXCAN_MCR_WRNEN_MASK       (0x1UL << FLEXCAN_MCR_WRNEN_SHIFT)
#define FLEXCAN_MCR_WRNEN_WIDTH      (1UL)
#define FLEXCAN_MCR_LPMACK_SHIFT     (20UL)
#define FLEXCAN_MCR_LPMACK_MASK      (0x1UL << FLEXCAN_MCR_LPMACK_SHIFT)
#define FLEXCAN_MCR_LPMACK_WIDTH     (1UL)
#define FLEXCAN_MCR_WAKSRC_SHIFT     (19UL)
#define FLEXCAN_MCR_WAKSRC_MASK      (0x1UL << FLEXCAN_MCR_WAKSRC_SHIFT)
#define FLEXCAN_MCR_WAKSRC_WIDTH     (1UL)
#define FLEXCAN_MCR_DOZE_SHIFT       (18UL)
#define FLEXCAN_MCR_DOZE_MASK        (0x1UL << FLEXCAN_MCR_DOZE_SHIFT)
#define FLEXCAN_MCR_DOZE_WIDTH       (1UL)
#define FLEXCAN_MCR_SRXDIS_SHIFT     (17UL)
#define FLEXCAN_MCR_SRXDIS_MASK      (0x1UL << FLEXCAN_MCR_SRXDIS_SHIFT)
#define FLEXCAN_MCR_SRXDIS_WIDTH     (1UL)
#define FLEXCAN_MCR_IRMQ_SHIFT       (16UL)
#define FLEXCAN_MCR_IRMQ_MASK        (0x1UL << FLEXCAN_MCR_IRMQ_SHIFT)
#define FLEXCAN_MCR_IRMQ_WIDTH       (1UL)
#define FLEXCAN_MCR_DMA_SHIFT        (15UL)
#define FLEXCAN_MCR_DMA_MASK         (0x1UL << FLEXCAN_MCR_DMA_SHIFT)
#define FLEXCAN_MCR_DMA_WIDTH        (1UL)
#define FLEXCAN_MCR_PNET_EN_MASK     (0x4000UL)
#define FLEXCAN_MCR_PNET_EN_SHIFT    (14UL)
#define FLEXCAN_MCR_PNET_EN_WIDTH    (1UL)
#define FLEXCAN_MCR_LPRIOEN_MASK     (0x2000UL)
#define FLEXCAN_MCR_LPRIOEN_SHIFT    (13UL)
#define FLEXCAN_MCR_LPRIOEN_WIDTH    (1UL)
#define FLEXCAN_MCR_AEN_SHIFT        (12UL)
#define FLEXCAN_MCR_AEN_MASK         (0x1UL << FLEXCAN_MCR_AEN_SHIFT)
#define FLEXCAN_MCR_AEN_WIDTH        (1UL)
#define FLEXCAN_MCR_FDEN_SHIFT       (11UL)
#define FLEXCAN_MCR_FDEN_MASK        (0x1UL << FLEXCAN_MCR_FDEN_SHIFT)
#define FLEXCAN_MCR_FDEN_WIDTH       (1UL)
#define FLEXCAN_MCR_IDAM_SHIFT       (8UL)
#define FLEXCAN_MCR_IDAM_MASK        (0x3UL << FLEXCAN_MCR_IDAM_SHIFT)
#define FLEXCAN_MCR_IDAM_WIDTH       (2UL)
#define FLEXCAN_MCR_MAXMB_SHIFT      (0UL)
#define FLEXCAN_MCR_MAXMB_MASK       (0x7FUL << FLEXCAN_MCR_MAXMB_SHIFT)
#define FLEXCAN_MCR_MAXMB_WIDTH      (7UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_CTRL1 FLEXCAN Control1 Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_CTRL1 register definition.
  */
#define FLEXCAN_CTRL1_PRESDIV_MASK     (0xFF000000UL)
#define FLEXCAN_CTRL1_PRESDIV_SHIFT    (24UL)
#define FLEXCAN_CTRL1_PRESDIV_WIDTH    (8UL)
#define FLEXCAN_CTRL1_RJW_MASK         (0xC00000UL)
#define FLEXCAN_CTRL1_RJW_SHIFT        (22UL)
#define FLEXCAN_CTRL1_RJW_WIDTH        (2UL)
#define FLEXCAN_CTRL1_PSEG1_MASK       (0x380000UL)
#define FLEXCAN_CTRL1_PSEG1_SHIFT      (19UL)
#define FLEXCAN_CTRL1_PSEG1_WIDTH      (3UL)
#define FLEXCAN_CTRL1_PSEG2_MASK       (0x70000UL)
#define FLEXCAN_CTRL1_PSEG2_SHIFT      (16UL)
#define FLEXCAN_CTRL1_PSEG2_WIDTH      (3UL)
#define FLEXCAN_CTRL1_BOFFMSK_SHIFT    (15UL)
#define FLEXCAN_CTRL1_BOFFMSK_MASK     (0x1UL << FLEXCAN_CTRL1_BOFFMSK_SHIFT)
#define FLEXCAN_CTRL1_BOFFMSK_WIDTH    (1UL)
#define FLEXCAN_CTRL1_ERRMSK_SHIFT     (14UL)
#define FLEXCAN_CTRL1_ERRMSK_MASK      (0x1UL << FLEXCAN_CTRL1_ERRMSK_SHIFT)
#define FLEXCAN_CTRL1_ERRMSK_WIDTH     (1UL)
#define FLEXCAN_CTRL1_CLKSRC_SHIFT     (13UL)
#define FLEXCAN_CTRL1_CLKSRC_MASK      (0x1UL << FLEXCAN_CTRL1_CLKSRC_SHIFT)
#define FLEXCAN_CTRL1_CLKSRC_WIDTH     (1UL)
#define FLEXCAN_CTRL1_LPB_SHIFT        (12UL)
#define FLEXCAN_CTRL1_LPB_MASK         (0x1UL << FLEXCAN_CTRL1_LPB_SHIFT)
#define FLEXCAN_CTRL1_LPB_WIDTH        (1UL)
#define FLEXCAN_CTRL1_TWRNMSK_SHIFT    (11UL)
#define FLEXCAN_CTRL1_TWRNMSK_MASK     (0x1UL << FLEXCAN_CTRL1_TWRNMSK_SHIFT)
#define FLEXCAN_CTRL1_TWRNMSK_WIDTH    (1UL)
#define FLEXCAN_CTRL1_RWRNMSK_SHIFT    (10UL)
#define FLEXCAN_CTRL1_RWRNMSK_MASK     (1UL << FLEXCAN_CTRL1_RWRNMSK_SHIFT)
#define FLEXCAN_CTRL1_RWRNMSK_WIDTH    (1UL)
#define FLEXCAN_CTRL1_SMP_SHIFT        (7UL)
#define FLEXCAN_CTRL1_SMP_MASK         (1UL << FLEXCAN_CTRL1_SMP_SHIFT)
#define FLEXCAN_CTRL1_SMP_WIDTH        (1UL)
#define FLEXCAN_CTRL1_BOFFREC_SHIFT    (6UL)
#define FLEXCAN_CTRL1_BOFFREC_MASK     (1UL << FLEXCAN_CTRL1_BOFFREC_SHIFT)
#define FLEXCAN_CTRL1_BOFFREC_WIDTH    (1UL)
#define FLEXCAN_CTRL1_TSYN_SHIFT       (5UL)
#define FLEXCAN_CTRL1_TSYN_MASK        (0x1UL << FLEXCAN_CTRL1_TSYN_SHIFT)
#define FLEXCAN_CTRL1_TSYN_WIDTH       (1UL)
#define FLEXCAN_CTRL1_LBUF_SHIFT       (4UL)
#define FLEXCAN_CTRL1_LBUF_MASK        (0x1UL << FLEXCAN_CTRL1_LBUF_SHIFT)
#define FLEXCAN_CTRL1_LBUF_WIDTH       (1UL)
#define FLEXCAN_CTRL1_LOM_SHIFT        (3UL)
#define FLEXCAN_CTRL1_LOM_MASK         (0x1UL << FLEXCAN_CTRL1_LOM_SHIFT)
#define FLEXCAN_CTRL1_LOM_WIDTH        (1UL)
#define FLEXCAN_CTRL1_PROPSEG_MASK     (0x7UL)
#define FLEXCAN_CTRL1_PROPSEG_SHIFT    (0UL)
#define FLEXCAN_CTRL1_PROPSEG_WIDTH    (3UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_TIMER FLEXCAN Timer Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_TIMER register definition.
  */
#define FLEXCAN_TIMER_TIMER_MASK     (0xFFFFUL)
#define FLEXCAN_TIMER_TIMER_SHIFT    (0UL)
#define FLEXCAN_TIMER_TIMER_WIDTH    (16UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_RXMGMASK FLEXCAN Rx Mailboxes Global Mask Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_RXMGMASK register definition.
  */
#define FLEXCAN_RXMGMASK_MG_MASK     (0xFFFFFFFFUL)
#define FLEXCAN_RXMGMASK_MG_SHIFT    (0UL)
#define FLEXCAN_RXMGMASK_MG_WIDTH    (32UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_R14MASK FLEXCAN R14 Mask Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_R14MASK register definition.
  */
#define FLEXCAN_RX14MASK_RX14M_MASK     (0xFFFFFFFFUL)
#define FLEXCAN_RX14MASK_RX14M_SHIFT    (0UL)
#define FLEXCAN_RX14MASK_RX14M_WIDTH    (32UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_R15MASK FLEXCAN R15 Mask Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_R15MASK register definition.
  */
#define FLEXCAN_RX15MASK_RX15M_MASK     (0xFFFFFFFFUL)
#define FLEXCAN_RX15MASK_RX15M_SHIFT    (0UL)
#define FLEXCAN_RX15MASK_RX15M_WIDTH    (32UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_ECR FLEXCAN Error Count Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_ECR register definition.
  */
#define FLEXCAN_ECR_RXERRCNTFAST_MASK     (0xFF000000UL)
#define FLEXCAN_ECR_RXERRCNTFAST_SHIFT    (24UL)
#define FLEXCAN_ECR_RXERRCNTFAST_WIDTH    (8UL)
#define FLEXCAN_ECR_TXERRCNTFAST_MASK     (0xFF0000UL)
#define FLEXCAN_ECR_TXERRCNTFAST_SHIFT    (16UL)
#define FLEXCAN_ECR_TXERRCNTFAST_WIDTH    (8UL)
#define FLEXCAN_ECR_RXERRCNT_MASK         (0xFF00UL)
#define FLEXCAN_ECR_RXERRCNT_SHIFT        (8UL)
#define FLEXCAN_ECR_RXERRCNT_WIDTH        (8UL)
#define FLEXCAN_ECR_TXERRCNT_MASK         (0xFFUL)
#define FLEXCAN_ECR_TXERRCNT_SHIFT        (0UL)
#define FLEXCAN_ECR_TXERRCNT_WIDTH        (8UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_ESR1 FLEXCAN Error and Status1 Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_ESR1 register definition.
  */
#define FLEXCAN_ESR1_BIT1ERR_FAST_SHIFT    (31UL)
#define FLEXCAN_ESR1_BIT1ERR_FAST_MASK     (1UL << FLEXCAN_ESR1_BIT1ERR_FAST_SHIFT)
#define FLEXCAN_ESR1_BIT1ERR_FAST_WIDTH    (1UL)
#define FLEXCAN_ESR1_BIT0ERR_FAST_SHIFT    (30UL)
#define FLEXCAN_ESR1_BIT0ERR_FAST_MASK     (1UL << FLEXCAN_ESR1_BIT0ERR_FAST_SHIFT)
#define FLEXCAN_ESR1_BIT0ERR_FAST_WIDTH    (1UL)
#define FLEXCAN_ESR1_CRCERR_FAST_SHIFT     (28UL)
#define FLEXCAN_ESR1_CRCERR_FAST_MASK      (1UL << FLEXCAN_ESR1_CRCERR_FAST_SHIFT)
#define FLEXCAN_ESR1_CRCERR_FAST_WIDTH     (1UL)
#define FLEXCAN_ESR1_FRMERR_FAST_SHIFT     (27UL)
#define FLEXCAN_ESR1_FRMERR_FAST_MASK      (1UL << FLEXCAN_ESR1_FRMERR_FAST_SHIFT)
#define FLEXCAN_ESR1_FRMERR_FAST_WIDTH     (1UL)
#define FLEXCAN_ESR1_STFERR_FAST_SHIFT     (26UL)
#define FLEXCAN_ESR1_STFERR_FAST_MASK      (1UL << FLEXCAN_ESR1_STFERR_FAST_SHIFT)
#define FLEXCAN_ESR1_STFERR_FAST_WIDTH     (1UL)
#define FLEXCAN_ESR1_ERROVR_SHIFT          (21UL)
#define FLEXCAN_ESR1_ERROVR_MASK           (1UL << FLEXCAN_ESR1_ERROVR_SHIFT)
#define FLEXCAN_ESR1_ERROVR_WIDTH          (1UL)
#define FLEXCAN_ESR1_ERRINT_FAST_SHIFT     (20UL)
#define FLEXCAN_ESR1_ERRINT_FAST_MASK      (1UL << FLEXCAN_ESR1_ERRINT_FAST_SHIFT)
#define FLEXCAN_ESR1_ERRINT_FAST_WIDTH     (1UL)
#define FLEXCAN_ESR1_BOFFDONEINT_SHIFT     (19UL)
#define FLEXCAN_ESR1_BOFFDONEINT_MASK      (1UL << FLEXCAN_ESR1_BOFFDONEINT_SHIFT)
#define FLEXCAN_ESR1_BOFFDONEINT_WIDTH     (1UL)
#define FLEXCAN_ESR1_SYNCH_SHIFT           (18UL)
#define FLEXCAN_ESR1_SYNCH_MASK            (1UL << FLEXCAN_ESR1_SYNCH_SHIFT)
#define FLEXCAN_ESR1_SYNCH_WIDTH           (1UL)
#define FLEXCAN_ESR1_TWRNINT_SHIFT         (17UL)
#define FLEXCAN_ESR1_TWRNINT_MASK          (1UL << FLEXCAN_ESR1_TWRNINT_SHIFT)
#define FLEXCAN_ESR1_TWRNINT_WIDTH         (1UL)
#define FLEXCAN_ESR1_RWRNINT_SHIFT         (16UL)
#define FLEXCAN_ESR1_RWRNINT_MASK          (1UL << FLEXCAN_ESR1_RWRNINT_SHIFT)
#define FLEXCAN_ESR1_RWRNINT_WIDTH         (1UL)
#define FLEXCAN_ESR1_BIT1ERR_SHIFT         (15UL)
#define FLEXCAN_ESR1_BIT1ERR_MASK          (1UL << FLEXCAN_ESR1_BIT1ERR_SHIFT)
#define FLEXCAN_ESR1_BIT1ERR_WIDTH         (1UL)
#define FLEXCAN_ESR1_BIT0ERR_SHIFT         (14UL)
#define FLEXCAN_ESR1_BIT0ERR_MASK          (1UL << FLEXCAN_ESR1_BIT0ERR_SHIFT)
#define FLEXCAN_ESR1_BIT0ERR_WIDTH         (1UL)
#define FLEXCAN_ESR1_ACKERR_SHIFT          (13UL)
#define FLEXCAN_ESR1_ACKERR_MASK           (1UL << FLEXCAN_ESR1_ACKERR_SHIFT)
#define FLEXCAN_ESR1_ACKERR_WIDTH          (1UL)
#define FLEXCAN_ESR1_CRCERR_SHIFT          (12UL)
#define FLEXCAN_ESR1_CRCERR_MASK           (1UL << FLEXCAN_ESR1_CRCERR_SHIFT)
#define FLEXCAN_ESR1_CRCERR_WIDTH          (1UL)
#define FLEXCAN_ESR1_FRMERR_SHIFT          (11UL)
#define FLEXCAN_ESR1_FRMERR_MASK           (1UL << FLEXCAN_ESR1_FRMERR_SHIFT)
#define FLEXCAN_ESR1_FRMERR_WIDTH          (1UL)
#define FLEXCAN_ESR1_STFERR_SHIFT          (10UL)
#define FLEXCAN_ESR1_STFERR_MASK           (1UL << FLEXCAN_ESR1_STFERR_SHIFT)
#define FLEXCAN_ESR1_STFERR_WIDTH          (1UL)
#define FLEXCAN_ESR1_TXWRN_SHIFT           (9UL)
#define FLEXCAN_ESR1_TXWRN_MASK            (0x1UL << FLEXCAN_ESR1_TXWRN_SHIFT)
#define FLEXCAN_ESR1_TXWRN_WIDTH           (1UL)
#define FLEXCAN_ESR1_RXWRN_SHIFT           (8UL)
#define FLEXCAN_ESR1_RXWRN_MASK            (0x1UL << FLEXCAN_ESR1_RXWRN_SHIFT)
#define FLEXCAN_ESR1_RXWRN_WIDTH           (1UL)
#define FLEXCAN_ESR1_IDLE_SHIFT            (7UL)
#define FLEXCAN_ESR1_IDLE_MASK             (1UL << FLEXCAN_ESR1_IDLE_SHIFT)
#define FLEXCAN_ESR1_IDLE_WIDTH            (1UL)
#define FLEXCAN_ESR1_TX_SHIFT              (6UL)
#define FLEXCAN_ESR1_TX_MASK               (1UL << FLEXCAN_ESR1_TX_SHIFT)
#define FLEXCAN_ESR1_TX_WIDTH              (1UL)
#define FLEXCAN_ESR1_FLTCONF_SHIFT         (4UL)
#define FLEXCAN_ESR1_FLTCONF_MASK          (3UL << FLEXCAN_ESR1_FLTCONF_SHIFT)
#define FLEXCAN_ESR1_FLTCONF_WIDTH         (2UL)
#define FLEXCAN_ESR1_RX_SHIFT              (3UL)
#define FLEXCAN_ESR1_RX_MASK               (1UL << FLEXCAN_ESR1_RX_SHIFT)
#define FLEXCAN_ESR1_RX_WIDTH              (1UL)
#define FLEXCAN_ESR1_BOFFINT_SHIFT         (2UL)
#define FLEXCAN_ESR1_BOFFINT_MASK          (0x1UL << FLEXCAN_ESR1_BOFFINT_SHIFT)
#define FLEXCAN_ESR1_BOFFINT_WIDTH         (1UL)
#define FLEXCAN_ESR1_ERRINT_SHIFT          (1UL)
#define FLEXCAN_ESR1_ERRINT_MASK           (0x1UL << FLEXCAN_ESR1_ERRINT_SHIFT)
#define FLEXCAN_ESR1_ERRINT_WIDTH          (1UL)
#define FLEXCAN_ESR1_WAKINT_SHIFT          (0UL)
#define FLEXCAN_ESR1_WAKINT_MASK           (0x1UL << FLEXCAN_ESR1_WAKINT_SHIFT)
#define FLEXCAN_ESR1_WAKINT_WIDTH          (1UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_CTRL2 FLEXCAN Control 2 Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_CTRL2 register definition.
  */
#define FLEXCAN_CTRL2_ERRMSKFAST_MASK      (0x80000000UL)
#define FLEXCAN_CTRL2_ERRMSKFAST_SHIFT     (31UL)
#define FLEXCAN_CTRL2_ERRMSKFAST_WIDTH     (1UL)
#define FLEXCAN_CTRL2_BOFFDONEMSK_MASK     (0x40000000UL)
#define FLEXCAN_CTRL2_BOFFDONEMSK_SHIFT    (30UL)
#define FLEXCAN_CTRL2_BOFFDONEMSK_WIDTH    (1UL)
#define FLEXCAN_CTRL2_ECRWRE_SHIFT         (29UL)
#define FLEXCAN_CTRL2_ECRWRE_MASK          (0x1UL << FLEXCAN_CTRL2_ECRWRE_SHIFT)
#define FLEXCAN_CTRL2_ECRWRE_WIDTH         (1UL)
#define FLEXCAN_CTRL2_WRMFRZ_SHIFT         (28UL)
#define FLEXCAN_CTRL2_WRMFRZ_MASK          (0x1UL << FLEXCAN_CTRL2_WRMFRZ_SHIFT)
#define FLEXCAN_CTRL2_WRMFRZ_WIDTH         (1UL)
#define FLEXCAN_CTRL2_RFFN_SHIFT           (24UL)
#define FLEXCAN_CTRL2_RFFN_MASK            (0xFUL << FLEXCAN_CTRL2_RFFN_SHIFT)
#define FLEXCAN_CTRL2_RFFN_WIDTH           (4UL)
#define FLEXCAN_CTRL2_TASD_MASK            (0xF80000UL)
#define FLEXCAN_CTRL2_TASD_SHIFT           (19UL)
#define FLEXCAN_CTRL2_TASD_WIDTH           (5UL)
#define FLEXCAN_CTRL2_MRP_MASK             (0x40000UL)
#define FLEXCAN_CTRL2_MRP_SHIFT            (18UL)
#define FLEXCAN_CTRL2_MRP_WIDTH            (1UL)
#define FLEXCAN_CTRL2_RRS_MASK             (0x20000UL)
#define FLEXCAN_CTRL2_RRS_SHIFT            (17UL)
#define FLEXCAN_CTRL2_RRS_WIDTH            (1UL)
#define FLEXCAN_CTRL2_EACEN_MASK           (0x10000UL)
#define FLEXCAN_CTRL2_EACEN_SHIFT          (16UL)
#define FLEXCAN_CTRL2_EACEN_WIDTH          (1UL)
#define FLEXCAN_CTRL2_TIMERSRC_MASK        (0x8000UL)
#define FLEXCAN_CTRL2_TIMERSRC_SHIFT       (15UL)
#define FLEXCAN_CTRL2_TIMERSRC_WIDTH       (1UL)
#define FLEXCAN_CTRL2_PREXCEN_MASK         (0x4000UL)
#define FLEXCAN_CTRL2_PREXCEN_SHIFT        (14UL)
#define FLEXCAN_CTRL2_PREXCEN_WIDTH        (1UL)
#define FLEXCAN_CTRL2_BTE_MASK             (0x2000UL)
#define FLEXCAN_CTRL2_BTE_SHIFT            (13UL)
#define FLEXCAN_CTRL2_BTE_WIDTH            (1UL)
#define FLEXCAN_CTRL2_ISOCANFDEN_SHIFT     (12UL)
#define FLEXCAN_CTRL2_ISOCANFDEN_MASK      (0x1UL << FLEXCAN_CTRL2_ISOCANFDEN_SHIFT)
#define FLEXCAN_CTRL2_ISOCANFDEN_WIDTH     (1UL)
#define FLEXCAN_CTRL2_EDFLTDIS_MASK        (0x800UL)
#define FLEXCAN_CTRL2_EDFLTDIS_SHIFT       (11UL)
#define FLEXCAN_CTRL2_EDFLTDIS_WIDTH       (1UL)
#define FLEXCAN_CTRL2_MBTSBASE_MASK        (0x300UL)
#define FLEXCAN_CTRL2_MBTSBASE_SHIFT       (8UL)
#define FLEXCAN_CTRL2_MBTSBASE_WIDTH       (2UL)
#define FLEXCAN_CTRL2_TSTAMPCAP_MASK       (0xC0UL)
#define FLEXCAN_CTRL2_TSTAMPCAP_SHIFT      (6UL)
#define FLEXCAN_CTRL2_TSTAMPCAP_WIDTH      (2UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_ESR2 FLEXCAN Error and Status2 Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_CTRL2 register definition.
  */
#define FLEXCAN_ESR2_LPTM_MASK     (0x7F0000UL)
#define FLEXCAN_ESR2_LPTM_SHIFT    (16UL)
#define FLEXCAN_ESR2_LPTM_WIDTH    (7UL)
#define FLEXCAN_ESR2_VPS_MASK      (0x4000UL)
#define FLEXCAN_ESR2_VPS_SHIFT     (14UL)
#define FLEXCAN_ESR2_VPS_WIDTH     (1UL)
#define FLEXCAN_ESR2_IMB_MASK      (0x2000UL)
#define FLEXCAN_ESR2_IMB_SHIFT     (13UL)
#define FLEXCAN_ESR2_IMB_WIDTH     (1UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_CRCR FLEXCAN CRC Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_CRCR register definition.
  */
#define FLEXCAN_CRCR_MBCRC_MASK     (0x7F0000UL)
#define FLEXCAN_CRCR_MBCRC_SHIFT    (16UL)
#define FLEXCAN_CRCR_MBCRC_WIDTH    (7UL)
#define FLEXCAN_CRCR_TXCRC_MASK     (0x7FFFUL)
#define FLEXCAN_CRCR_TXCRC_SHIFT    (0UL)
#define FLEXCAN_CRCR_TXCRC_WIDTH    (15UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_RXFGMASK FLEXCAN Rx Fifo Global Mask Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_RXFGMASK register definition.
  */
#define FLEXCAN_RXFGMASK_FGM_MASK     (0xFFFFFFFFUL)
#define FLEXCAN_RXFGMASK_FGM_SHIFT    (0UL)
#define FLEXCAN_RXFGMASK_FGM_WIDTH    (32UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_RXFIR FLEXCAN Rx Fifo Information Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_RXFIR register definition.
  */
#define FLEXCAN_RXFIR_IDHIT_MASK     (0x1FFUL)
#define FLEXCAN_RXFIR_IDHIT_SHIFT    (0UL)
#define FLEXCAN_RXFIR_IDHIT_WIDTH    (9UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_CBT FLEXCAN CAN Bit Timing Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_CBT register definition.
  */
#define FLEXCAN_CBT_BTF_SHIFT         (31UL)
#define FLEXCAN_CBT_BTF_MASK          (0x1UL << FLEXCAN_CBT_BTF_SHIFT)
#define FLEXCAN_CBT_BTF_WIDTH         (1UL)
#define FLEXCAN_CBT_EPRESDIV_SHIFT    (21UL)
#define FLEXCAN_CBT_EPRESDIV_MASK     (0x3FFUL << FLEXCAN_CBT_EPRESDIV_SHIFT)
#define FLEXCAN_CBT_EPRESDIV_WIDTH    (10UL)
#define FLEXCAN_CBT_ERJW_SHIFT        (16UL)
#define FLEXCAN_CBT_ERJW_MASK         (0x1FUL << FLEXCAN_CBT_ERJW_SHIFT)
#define FLEXCAN_CBT_ERJW_WIDTH        (5UL)
#define FLEXCAN_CBT_EPROPSEG_SHIFT    (10UL)
#define FLEXCAN_CBT_EPROPSEG_MASK     (0x3FUL << FLEXCAN_CBT_EPROPSEG_SHIFT)
#define FLEXCAN_CBT_EPROPSEG_WIDTH    (6UL)
#define FLEXCAN_CBT_EPSEG1_SHIFT      (5UL)
#define FLEXCAN_CBT_EPSEG1_MASK       (0x1FUL << FLEXCAN_CBT_EPSEG1_SHIFT)
#define FLEXCAN_CBT_EPSEG1_WIDTH      (5UL)
#define FLEXCAN_CBT_EPSEG2_SHIFT      (0UL)
#define FLEXCAN_CBT_EPSEG2_MASK       (0x1FUL << FLEXCAN_CBT_EPSEG2_SHIFT)

/**
  * @}
  */

/** @defgroup FLEXCAN_IMASK4 FLEXCAN Interrupt Mask4 Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_IMASK4 register definition.
  */
#define FLEXCAN_IMASK4_BUF127TO96M_MASK     (0xFFFFFFFFUL)
#define FLEXCAN_IMASK4_BUF127TO96M_SHIFT    (0UL)
#define FLEXCAN_IMASK4_BUF127TO96M_WIDTH    (32UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_IMASK3 FLEXCAN Interrupt Mask3 Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_IMASK3 register definition.
  */
#define FLEXCAN_IMASK3_BUF95TO64M_MASK     (0xFFFFFFFFUL)
#define FLEXCAN_IMASK3_BUF95TO64M_SHIFT    (0UL)
#define FLEXCAN_IMASK3_BUF95TO64M_WIDTH    (32UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_IFLAG4 FLEXCAN Interrupt Flag4 Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_IFLAG4 register definition.
  */
#define FLEXCAN_IFLAG4_BUF127TO96_MASK     (0xFFFFFFFFUL)
#define FLEXCAN_IFLAG4_BUF127TO96_SHIFT    (0UL)
#define FLEXCAN_IFLAG4_BUF127TO96_WIDTH    (32UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_IFLAG3 FLEXCAN Interrupt Flag3 Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_IFLAG3 register definition.
  */
#define FLEXCAN_IFLAG3_BUF95TO64_MASK     (0xFFFFFFFFUL)
#define FLEXCAN_IFLAG3_BUF95TO64_SHIFT    (0UL)
#define FLEXCAN_IFLAG3_BUF95TO64_WIDTH    (32UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_RXIMRN FLEXCAN Rx Individual Mask Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_RXIMRN register definition.
  */
#define FLEXCAN_RXIMRN_MI_MASK     (0xFFFFFFFFUL)
#define FLEXCAN_RXIMRN_MI_SHIFT    (0UL)
#define FLEXCAN_RXIMRN_MI_WIDTH    (32UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_MECR FLEXCAN Memory Error Control Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_MECR register definition.
  */
#define FLEXCAN_MECR_ECRWRDIS_SHIFT     (31UL)
#define FLEXCAN_MECR_ECRWRDIS_MASK      (0x1UL << FLEXCAN_MECR_ECRWRDIS_SHIFT)
#define FLEXCAN_MECR_ECRWRDIS_WIDTH     (1UL)
#define FLEXCAN_MECR_HANCEIMSK_MASK     (0x80000UL)
#define FLEXCAN_MECR_HANCEIMSK_SHIFT    (19UL)
#define FLEXCAN_MECR_HANCEIMSK_WIDTH    (1UL)
#define FLEXCAN_MECR_FANCEIMSK_MASK     (0x40000UL)
#define FLEXCAN_MECR_FANCEIMSK_SHIFT    (18UL)
#define FLEXCAN_MECR_FANCEIMSK_WIDTH    (1UL)
#define FLEXCAN_MECR_CEIMSK_MASK        (0x10000UL)
#define FLEXCAN_MECR_CEIMSK_SHIFT       (16UL)
#define FLEXCAN_MECR_CEIMSK_WIDTH       (1UL)
#define FLEXCAN_MECR_HAERRIE_MASK       (0x8000UL)
#define FLEXCAN_MECR_HAERRIE_SHIFT      (15UL)
#define FLEXCAN_MECR_HAERRIE_WIDTH      (1UL)
#define FLEXCAN_MECR_FAERRIE_MASK       (0x4000UL)
#define FLEXCAN_MECR_FAERRIE_SHIFT      (14UL)
#define FLEXCAN_MECR_FAERRIE_WIDTH      (1UL)
#define FLEXCAN_MECR_EXTERRIE_MASK      (0x2000UL)
#define FLEXCAN_MECR_EXTERRIE_SHIFT     (13UL)
#define FLEXCAN_MECR_EXTERRIE_WIDTH     (1UL)
#define FLEXCAN_MECR_RERRDIS_MASK       (0x200UL)
#define FLEXCAN_MECR_RERRDIS_SHIFT      (9UL)
#define FLEXCAN_MECR_RERRDIS_WIDTH      (1UL)
#define FLEXCAN_MECR_ECCDIS_SHIFT       (8UL)
#define FLEXCAN_MECR_ECCDIS_MASK        (0x1UL << FLEXCAN_MECR_ECCDIS_SHIFT)
#define FLEXCAN_MECR_ECCDIS_WIDTH       (1UL)
#define FLEXCAN_MECR_NCEFAFRZ_SHIFT     (7UL)
#define FLEXCAN_MECR_NCEFAFRZ_MASK      (0x1UL << FLEXCAN_MECR_NCEFAFRZ_SHIFT)
#define FLEXCAN_MECR_NCEFAFRZ_WIDTH     (1UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_EPRS FLEXCAN Enhanced Can Bit Timing Prescalers Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_EPRS register definition.
  */
#define FLEXCAN_EPRS_EDPRESDIV_SHIFT    (16UL)
#define FLEXCAN_EPRS_EDPRESDIV_MASK     (0x3FFUL << FLEXCAN_EPRS_EDPRESDIV_SHIFT)
#define FLEXCAN_EPRS_EDPRESDIV_WIDTH    (10UL)
#define FLEXCAN_EPRS_ENPRESDIV_SHIFT    (0UL)
#define FLEXCAN_EPRS_ENPRESDIV_MASK     (0x3FFUL << FLEXCAN_EPRS_ENPRESDIV_SHIFT)
#define FLEXCAN_EPRS_ENPRESDIV_WIDTH    (10UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_ENCBT FLEXCAN Enhanced Nominal Can Bit Timing Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_ENCBT register definition.
  */
#define FLEXCAN_ENCBT_NRJW_SHIFT      (22UL)
#define FLEXCAN_ENCBT_NRJW_MASK       (0x7FUL << FLEXCAN_ENCBT_NRJW_SHIFT)
#define FLEXCAN_ENCBT_NRJW_WIDTH      (7UL)
#define FLEXCAN_ENCBT_NTSEG2_SHIFT    (12UL)
#define FLEXCAN_ENCBT_NTSEG2_MASK     (0x7FUL << FLEXCAN_ENCBT_NTSEG2_SHIFT)
#define FLEXCAN_ENCBT_NTSEG2_WIDTH    (7UL)
#define FLEXCAN_ENCBT_NTSEG1_SHIFT    (0UL)
#define FLEXCAN_ENCBT_NTSEG1_MASK     (0xFFUL << FLEXCAN_ENCBT_NTSEG1_SHIFT)
#define FLEXCAN_ENCBT_NTSEG1_WIDTH    (8UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_EDCBT FLEXCAN Enhanced Data Phase Can Bit Timing Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_EDCBT register definition.
  */
#define FLEXCAN_EDCBT_DRJW_SHIFT      (22UL)
#define FLEXCAN_EDCBT_DRJW_MASK       (0xFUL << FLEXCAN_EDCBT_DRJW_SHIFT)
#define FLEXCAN_EDCBT_DRJW_WIDTH      (4UL)
#define FLEXCAN_EDCBT_DTSEG2_SHIFT    (12UL)
#define FLEXCAN_EDCBT_DTSEG2_MASK     (0xFUL << FLEXCAN_EDCBT_DTSEG2_SHIFT)
#define FLEXCAN_EDCBT_DTSEG2_WIDTH    (4UL)
#define FLEXCAN_EDCBT_DTSEG1_SHIFT    (0UL)
#define FLEXCAN_EDCBT_DTSEG1_MASK     (0x1FUL << FLEXCAN_EDCBT_DTSEG1_SHIFT)
#define FLEXCAN_EDCBT_DTSEG1_WIDTH    (5UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_FDCTRL FLEXCAN Canfd Control Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_FDCTRL register definition.
  */
#define FLEXCAN_FDCTRL_FDRATE_SHIFT     (31UL)
#define FLEXCAN_FDCTRL_FDRATE_MASK      (0x1UL << FLEXCAN_FDCTRL_FDRATE_SHIFT)
#define FLEXCAN_FDCTRL_FDRATE_WIDTH     (1UL)
#define FLEXCAN_FDCTRL_MBDSR3_SHIFT     (25UL)
#define FLEXCAN_FDCTRL_MBDSR3_MASK      (0x3UL << FLEXCAN_FDCTRL_MBDSR3_SHIFT)
#define FLEXCAN_FDCTRL_MBDSR3_WIDTH     (2UL)
#define FLEXCAN_FDCTRL_MBDSR2_SHIFT     (22UL)
#define FLEXCAN_FDCTRL_MBDSR2_MASK      (0x3UL << FLEXCAN_FDCTRL_MBDSR2_SHIFT)
#define FLEXCAN_FDCTRL_MBDSR2_WIDTH     (2UL)
#define FLEXCAN_FDCTRL_MBDSR1_SHIFT     (19UL)
#define FLEXCAN_FDCTRL_MBDSR1_MASK      (0x3UL << FLEXCAN_FDCTRL_MBDSR1_SHIFT)
#define FLEXCAN_FDCTRL_MBDSR1_WIDTH     (2UL)
#define FLEXCAN_FDCTRL_MBDSR0_SHIFT     (16UL)
#define FLEXCAN_FDCTRL_MBDSR0_MASK      (0x3UL << FLEXCAN_FDCTRL_MBDSR0_SHIFT)
#define FLEXCAN_FDCTRL_MBDSR0_WIDTH     (2UL)
#define FLEXCAN_FDCTRL_TDCEN_SHIFT      (15UL)
#define FLEXCAN_FDCTRL_TDCEN_MASK       (0x1UL << FLEXCAN_FDCTRL_TDCEN_SHIFT)
#define FLEXCAN_FDCTRL_TDCEN_WIDTH      (1UL)
#define FLEXCAN_FDCTRL_TDCFAIL_MASK     (0x4000UL)
#define FLEXCAN_FDCTRL_TDCFAIL_SHIFT    (14UL)
#define FLEXCAN_FDCTRL_TDCFAIL_WIDTH    (1UL)
#define FLEXCAN_FDCTRL_TDCOFF_SHIFT     (8UL)
#define FLEXCAN_FDCTRL_TDCOFF_MASK      (0x1FUL << FLEXCAN_FDCTRL_TDCOFF_SHIFT)
#define FLEXCAN_FDCTRL_TDCOFF_WIDTH     (5UL)
#define FLEXCAN_FDCTRL_TDCVAL_MASK      (0x3FUL)
#define FLEXCAN_FDCTRL_TDCVAL_SHIFT     (0UL)
#define FLEXCAN_FDCTRL_TDCVAL_WIDTH     (6UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_FDCBT FLEXCAN Canfd Bit Timing Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_FDCBT register definition.
  */
#define FLEXCAN_FDCBT_FPRESDIV_SHIFT    (20UL)
#define FLEXCAN_FDCBT_FPRESDIV_MASK     (0x3FFUL << FLEXCAN_FDCBT_FPRESDIV_SHIFT)
#define FLEXCAN_FDCBT_FPRESDIV_WIDTH    (10UL)
#define FLEXCAN_FDCBT_FRJW_SHIFT        (16UL)
#define FLEXCAN_FDCBT_FRJW_MASK         (0x7UL << FLEXCAN_FDCBT_FRJW_SHIFT)
#define FLEXCAN_FDCBT_FPJW_WIDTH        (3UL)
#define FLEXCAN_FDCBT_FPROPSEG_SHIFT    (10UL)
#define FLEXCAN_FDCBT_FPROPSEG_MASK     (0x1FUL << FLEXCAN_FDCBT_FPROPSEG_SHIFT)
#define FLEXCAN_FDCBT_FPROPSEG_WIDTH    (5UL)
#define FLEXCAN_FDCBT_FPSEG1_SHIFT      (5UL)
#define FLEXCAN_FDCBT_FPSEG1_MASK       (0x7UL << FLEXCAN_FDCBT_FPSEG1_SHIFT)
#define FLEXCAN_FDCBT_FPSEG1_WIDTH      (3UL)
#define FLEXCAN_FDCBT_FPSEG2_SHIFT      (0UL)
#define FLEXCAN_FDCBT_FPSEG2_MASK       (0x7UL << FLEXCAN_FDCBT_FPSEG2_SHIFT)
#define FLEXCAN_FDCBT_FPSEG2_WIDTH      (3UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_FDCRC FLEXCAN Canfd CRC Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_FDCRC register definition.
  */
#define FLEXCAN_FDCRC_FDMBCRC_MASK     (0x7F000000UL)
#define FLEXCAN_FDCRC_FDMBCRC_SHIFT    (24UL)
#define FLEXCAN_FDCRC_FDMBCRC_WIDTH    (7UL)
#define FLEXCAN_FDCRC_FDTXCRC_MASK     (0x1FFFFFUL)
#define FLEXCAN_FDCRC_FDTXCRC_SHIFT    (0UL)
#define FLEXCAN_FDCRC_FDTXCRC_WIDTH    (21UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_ERFCR FLEXCAN Enhanced Rx Fifo Control Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_ERFCR register definition.
  */
#define FLEXCAN_ERFCR_ERFEN_SHIFT    (31UL)
#define FLEXCAN_ERFCR_ERFEN_MASK     (1UL << FLEXCAN_ERFCR_ERFEN_SHIFT)
#define FLEXCAN_ERFCR_ERFEN_WIDTH    (1UL)
#define FLEXCAN_ERFCR_DMALW_SHIFT    (26UL)
#define FLEXCAN_ERFCR_DMALW_MASK     (0x1FUL << FLEXCAN_ERFCR_DMALW_SHIFT)
#define FLEXCAN_ERFCR_DMALW_WIDTH    (5UL)
#define FLEXCAN_ERFCR_NEXIF_SHIFT    (16UL)
#define FLEXCAN_ERFCR_NEXIF_MASK     (0x7FUL << FLEXCAN_ERFCR_NEXIF_SHIFT)
#define FLEXCAN_ERFCR_NEXIF_WIDTH    (7UL)
#define FLEXCAN_ERFCR_NFE_SHIFT      (8UL)
#define FLEXCAN_ERFCR_NFE_MASK       (0x3FUL << FLEXCAN_ERFCR_NFE_SHIFT)
#define FLEXCAN_ERFCR_NFE_WIDTH      (6UL)
#define FLEXCAN_ERFCR_ERFWM_SHIFT    (0UL)
#define FLEXCAN_ERFCR_ERFWM_MASK     (0x1FUL << FLEXCAN_ERFCR_ERFWM_SHIFT)
#define FLEXCAN_ERFCR_ERFWM_WIDTH    (5UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_ERFIER FLEXCAN Enhanced Rx Fifo Interrupt Enable Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_ERFIER register definition.
  */
#define FLEXCAN_ERFIER_ERFUFWIE_SHIFT    (31UL)
#define FLEXCAN_ERFIER_ERFUFWIE_MASK     (1UL << FLEXCAN_ERFIER_ERFUFWIE_SHIFT)
#define FLEXCAN_ERFIER_ERFUFWIE_WIDTH    (1UL)
#define FLEXCAN_ERFIER_ERFOVFIE_SHIFT    (30UL)
#define FLEXCAN_ERFIER_ERFOVFIE_MASK     (1UL << FLEXCAN_ERFIER_ERFOVFIE_SHIFT)
#define FLEXCAN_ERFIER_ERFOVFIE_WIDTH    (1UL)
#define FLEXCAN_ERFIER_ERFWMIIE_SHIFT    (29UL)
#define FLEXCAN_ERFIER_ERFWMIIE_MASK     (1UL << FLEXCAN_ERFIER_ERFWMIIE_SHIFT)
#define FLEXCAN_ERFIER_ERFWMIIE_WIDTH    (1UL)
#define FLEXCAN_ERFIER_ERFDAIE_SHIFT     (28UL)
#define FLEXCAN_ERFIER_ERFDAIE_MASK      (1UL << FLEXCAN_ERFIER_ERFDAIE_SHIFT)
#define FLEXCAN_ERFIER_ERFDAIE_WIDTH     (1UL)

/**
  * @}
  */

/** @defgroup FLEXCAN_ERFSR FLEXCAN Enhanced Rx Fifo Status Register Bit Fields
  * @{
  * @brief  Macro definitions about the bit fields in the FLEXCAN_ERFSR register definition.
  */
#define FLEXCAN_ERFSR_ERFUFW_SHIFT    (31UL)
#define FLEXCAN_ERFSR_ERFUFW_MASK     (1UL << FLEXCAN_ERFSR_ERFUFW_SHIFT)
#define FLEXCAN_ERFSR_ERFUFW_WIDTH    (1UL)
#define FLEXCAN_ERFSR_ERFOVF_SHIFT    (30UL)
#define FLEXCAN_ERFSR_ERFOVF_MASK     (1UL << FLEXCAN_ERFSR_ERFOVF_SHIFT)
#define FLEXCAN_ERFSR_ERFOVF_WIDTH    (1UL)
#define FLEXCAN_ERFSR_ERFWMI_SHIFT    (29UL)
#define FLEXCAN_ERFSR_ERFWMI_MASK     (1UL << FLEXCAN_ERFSR_ERFWMI_SHIFT)
#define FLEXCAN_ERFSR_ERFWMI_WIDTH    (1UL)
#define FLEXCAN_ERFSR_ERFDA_SHIFT     (28UL)
#define FLEXCAN_ERFSR_ERFDA_MASK      (1UL << FLEXCAN_ERFSR_ERFDA_SHIFT)
#define FLEXCAN_ERFSR_ERFDA_WIDTH     (1UL)
#define FLEXCAN_ERFSR_ERFCLR_SHIFT    (27UL)
#define FLEXCAN_ERFSR_ERFCLR_MASK     (1UL << FLEXCAN_ERFSR_ERFCLR_SHIFT)
#define FLEXCAN_ERFSR_ERFCLR_WIDTH    (1UL)
#define FLEXCAN_ERFSR_ERFE_SHIFT      (17UL)
#define FLEXCAN_ERFSR_ERFE_MASK       (1UL << FLEXCAN_ERFSR_ERFE_SHIFT)
#define FLEXCAN_ERFSR_ERFE_WIDTH      (1UL)
#define FLEXCAN_ERFSR_ERFF_SHIFT      (16UL)
#define FLEXCAN_ERFSR_ERFF_MASK       (1UL << FLEXCAN_ERFSR_ERFF_SHIFT)
#define FLEXCAN_ERFSR_ERFF_WIDTH      (1UL)
#define FLEXCAN_ERFSR_ERFEL_SHIFT     (0UL)
#define FLEXCAN_ERFSR_ERFEL_MASK      (0x3FUL << FLEXCAN_ERFSR_ERFEL_SHIFT)
#define FLEXCAN_ERFSR_ERFEL_WIDTH     (6UL)

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


#ifdef __cplusplus
}
#endif


#endif /* __NS800RT7XXX_TI_FLEXCAN_H__ */
