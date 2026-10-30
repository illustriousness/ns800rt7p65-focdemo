/**
  * @file       i2c.h
  * @author     Haven-X
  * @brief      Header file for NS800RT7xxx i2c module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __I2C_H__
#define __I2C_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_i2c.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup I2C_EXPORTED_TYPES I2C Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'I2C' module.
  */

/** @defgroup I2C_MASTER_INTERRUPT I2C Master Interrupt
  * @{
  * @brief  Macro definitions about the interrupt source for master.
  */
#define I2C_MASTER_INTERRUPT_TXREADY         I2C_MIER_TDIE_M     /*!< Transmit Data Interrupt */
#define I2C_MASTER_INTERRUPT_RXREADY         I2C_MIER_RDIE_M     /*!< Receive Data Interrupt */
#define I2C_MASTER_INTERRUPT_ENDOFPACKET     I2C_MIER_EPIE_M     /*!< End Packet Interrupt */
#define I2C_MASTER_INTERRUPT_STOP            I2C_MIER_SDIE_M     /*!< STOP Detect Interrupt */
#define I2C_MASTER_INTERRUPT_NACK            I2C_MIER_NDIE_M     /*!< NACK Detect Interrupt */
#define I2C_MASTER_INTERRUPT_ARBLOST         I2C_MIER_ALIE_M     /*!< Arbitration Lost Interrupt */
#define I2C_MASTER_INTERRUPT_FIFIERR         I2C_MIER_FEIE_M     /*!< FIFO Error Interrupt */
#define I2C_MASTER_INTERRUPT_PNLOWTIMEOUT    I2C_MIER_PLTIE_M    /*!< Pin Low Timeout Interrupt */
#define I2C_MASTER_INTERRUPT_DATAMATCH       I2C_MIER_DMIE_M     /*!< Data Match Interrupt */
#define I2C_MASTER_INTERRUPT_ALL             (I2C_MASTER_INTERRUPT_TXREADY     | I2C_MASTER_INTERRUPT_RXREADY | \
                                              I2C_MASTER_INTERRUPT_ENDOFPACKET | I2C_MASTER_INTERRUPT_STOP    | \
                                              I2C_MASTER_INTERRUPT_NACK        | I2C_MASTER_INTERRUPT_ARBLOST | \
                                              I2C_MASTER_INTERRUPT_FIFIERR     | I2C_MASTER_INTERRUPT_PNLOWTIMEOUT | \
                                              I2C_MASTER_INTERRUPT_DATAMATCH)

/**
  * @}
  */

/** @defgroup I2C_SLAVE_INTERRUPT I2C Slave Interrupt
  * @{
  * @brief  Macro definitions about the interrupt source for slave.
  */
#define I2C_SLAVE_INTERRUPT_TXREADY         I2C_SIER_TDIE_M     /*!< Transmit Data Interrupt */
#define I2C_SLAVE_INTERRUPT_RXREADY         I2C_SIER_RDIE_M     /*!< Receive Data Interrupt */
#define I2C_SLAVE_INTERRUPT_ADDRESSVALID    I2C_SIER_AVIE_M     /*!< Address Valid Interrupt */
#define I2C_SLAVE_INTERRUPT_SENDACK         I2C_SIER_TAIE_M     /*!< Transmit ACK Interrupt */
#define I2C_SLAVE_INTERRUPT_RESTART         I2C_SIER_RSIE_M     /*!< Repeated Start Interrupt */
#define I2C_SLAVE_INTERRUPT_STOP            I2C_SIER_SDIE_M     /*!< STOP Detect Interrupt */
#define I2C_SLAVE_INTERRUPT_BITERR          I2C_SIER_BEIE_M     /*!< Bit Error Interrupt  */
#define I2C_SLAVE_INTERRUPT_FIFOERR         I2C_SIER_FEIE_M     /*!< FIFO Error Interrupt */
#define I2C_SLAVE_INTERRUPT_ADDRMATCH0      I2C_SIER_AM0IE_M    /*!< Address Match 0 Interrupt */
#define I2C_SLAVE_INTERRUPT_ADDRMATCH1      I2C_SIER_AM1IE_M    /*!< Address Match 1 Interrupt */
#define I2C_SLAVE_INTERRUPT_GENERALCALL     I2C_SIER_GCIE_M     /*!< General Call Interrupt */
#define I2C_SLAVE_INTERRUPT_SMBUSALERT      I2C_SIER_SARIE_M    /*!< SMBus Alert Response Interrupt */
#define I2C_SLAVE_INTERRUPT_ALL             (I2C_SLAVE_INTERRUPT_TXREADY      | I2C_SLAVE_INTERRUPT_RXREADY    | \
                                             I2C_SLAVE_INTERRUPT_ADDRESSVALID | I2C_SLAVE_INTERRUPT_SENDACK    | \
                                             I2C_SLAVE_INTERRUPT_RESTART      | I2C_SLAVE_INTERRUPT_STOP       | \
                                             I2C_SLAVE_INTERRUPT_BITERR       | I2C_SLAVE_INTERRUPT_FIFOERR    | \
                                             I2C_SLAVE_INTERRUPT_ADDRMATCH0   | I2C_SLAVE_INTERRUPT_ADDRMATCH1 | \
                                             I2C_SLAVE_INTERRUPT_GENERALCALL  | I2C_SLAVE_INTERRUPT_SMBUSALERT)

/**
  * @}
  */

/** @defgroup I2C_MASTER_FLAG I2C Master Flag
  * @{
  * @brief  Macro definitions about I2C master flag.
  */
typedef enum {
    I2C_MASTER_FLAG_TXREADY       = I2C_MSR_TDF_M,     /*!< Transmit data flag */
    I2C_MASTER_FLAG_RXREADY       = I2C_MSR_RDF_M,     /*!< Receive data flag */
    I2C_MASTER_FLAG_ENDOFPACKET   = I2C_MSR_EPF_M,     /*!< End Packet flag */
    I2C_MASTER_FLAG_STOP          = I2C_MSR_SDF_M,     /*!< Stop detect flag */
    I2C_MASTER_FLAG_NACK          = I2C_MSR_NDF_M,     /*!< NACK detect flag */
    I2C_MASTER_FLAG_ARBLOST       = I2C_MSR_ALF_M,     /*!< Arbitration lost flag */
    I2C_MASTER_FLAG_FIFOERR       = I2C_MSR_FEF_M,     /*!< FIFO error flag */
    I2C_MASTER_FLAG_PINLOWTIMEOUT = I2C_MSR_PLTF_M,    /*!< Pin low timeout flag */
    I2C_MASTER_FLAG_DATAMATCH     = I2C_MSR_DMF_M,     /*!< Data match flag */
    I2C_MASTER_FLAG_BUSY          = I2C_MSR_MBF_M,     /*!< Master busy flag */
    I2C_MASTER_FLAG_BUSBUSY       = I2C_MSR_BBF_M,     /*!< Bus busy flag */

    /*! All flags which are cleared by the driver upon starting a transfer. */
    I2C_MASTER_FLAG_CLEAR         = I2C_MASTER_FLAG_ENDOFPACKET   | I2C_MASTER_FLAG_STOP    | I2C_MASTER_FLAG_NACK |
                                    I2C_MASTER_FLAG_ARBLOST       | I2C_MASTER_FLAG_FIFOERR |
                                    I2C_MASTER_FLAG_PINLOWTIMEOUT | I2C_MASTER_FLAG_DATAMATCH,
    /*! IRQ sources enabled by the non-blocking transactional API. */
    I2C_MASTER_FLAG_IRQ           = I2C_MASTER_FLAG_ARBLOST | I2C_MASTER_FLAG_TXREADY | I2C_MASTER_FLAG_RXREADY |
                                    I2C_MASTER_FLAG_STOP    | I2C_MASTER_FLAG_NACK    | I2C_MASTER_FLAG_PINLOWTIMEOUT |
                                    I2C_MASTER_FLAG_FIFOERR,
    /*! Errors to check for. */
    I2C_MASTER_FLAG_ERROR         = I2C_MASTER_FLAG_NACK | I2C_MASTER_FLAG_ARBLOST |
                                    I2C_MASTER_FLAG_FIFOERR | I2C_MASTER_FLAG_PINLOWTIMEOUT
} I2C_MasterFlags;

/**
  * @}
  */

/** @defgroup I2C_SLAVE_FLAG I2C Slave Flag
  * @{
  * @brief  Macro definitions about I2C slave flag.
  */
typedef enum {
    I2C_SLAVE_FLAG_TXREADY      = I2C_SSR_TDF_M,     /*!< Transmit data flag */
    I2C_SLAVE_FLAG_RXREADY      = I2C_SSR_RDF_M,     /*!< Receive data flag */
    I2C_SLAVE_FLAG_ADDRESSVALID = I2C_SSR_AVF_M,     /*!< Address valid flag */
    I2C_SLAVE_FLAG_SENDACK      = I2C_SSR_TAF_M,     /*!< Transmit ACK flag */
    I2C_SLAVE_FLAG_RESTART      = I2C_SSR_RSF_M,     /*!< Repeated start detect flag */
    I2C_SLAVE_FLAG_STOP         = I2C_SSR_SDF_M,     /*!< Stop detect flag */
    I2C_SLAVE_FLAG_BITERR       = I2C_SSR_BEF_M,     /*!< Bit error flag */
    I2C_SLAVE_FLAG_FIFOERR      = I2C_SSR_FEF_M,     /*!< FIFO error flag */
    I2C_SLAVE_FLAG_ADDRMATCH0   = I2C_SSR_AM0F_M,    /*!< Address match 0 flag */
    I2C_SLAVE_FLAG_ADDRMATCH1   = I2C_SSR_AM1F_M,    /*!< Address match 1 flag */
    I2C_SLAVE_FLAG_GENERALCALL  = I2C_SSR_GCF_M,     /*!< General call flag */
    I2C_SLAVE_FLAG_SMBUSALERT   = I2C_SSR_SARF_M,    /*!< Smbus alert flag */
    I2C_SLAVE_FLAG_BUSY         = I2C_SSR_SBF_M,     /*!< Master busy flag */
    I2C_SLAVE_FLAG_BUSBUSY      = I2C_SSR_BBF_M,     /*!< Bus busy flag */

    /*! All flags which are cleared by the driver upon starting a transfer */
    I2C_SLAVE_FLAG_CLEAR        = I2C_SLAVE_FLAG_RESTART | I2C_SLAVE_FLAG_STOP |
                                  I2C_SLAVE_FLAG_BITERR  | I2C_SLAVE_FLAG_FIFOERR,
    /*! IRQ sources enabled by the non-blocking transactional API */
    I2C_SLAVE_FLAG_IRQ          = I2C_SLAVE_FLAG_TXREADY | I2C_SLAVE_FLAG_RXREADY | I2C_SLAVE_FLAG_STOP |
                                  I2C_SLAVE_FLAG_RESTART | I2C_SLAVE_FLAG_FIFOERR | I2C_SLAVE_FLAG_BITERR |
                                  I2C_SLAVE_FLAG_SENDACK | I2C_SLAVE_FLAG_ADDRESSVALID,
    /*! Errors to check for */
    I2C_SLAVE_FLAG_ERROR        = I2C_SLAVE_FLAG_FIFOERR | I2C_SLAVE_FLAG_BITERR
} I2C_SlaveFlags;

/**
  * @}
  */

/** @defgroup I2C_STATUS I2C Status Code
  * @{
  * @brief  Macro definitions about I2C status code.
  */
typedef enum {
    I2C_STATUS_SUCCESS = 0U,      /*!< No errors. */
    I2C_STATUS_BUSY,              /*!< The master is already performing a transfer. */
    I2C_STATUS_IDLE,              /*!< The slave driver is idle. */
    I2C_STATUS_NAK,               /*!< The slave device sent a NAK in response to a byte. */
    I2C_STATUS_FIFOERROR,         /*!< FIFO under run or overrun. */
    I2C_STATUS_BITERROR,          /*!< Transferred bit was not seen on the bus. */
    I2C_STATUS_ARBLOST,           /*!< Arbitration lost error. */
    I2C_STATUS_PINLOWTIMEOUT,     /*!< SCL or SDA were held low longer than the timeout. */
    I2C_STATUS_NOTRANSFER,        /*!< Attempt to abort a transfer when one is not in progress. */
    I2C_STATUS_DMAREQUESTFAIL,    /*!< DMA request failed. */
    I2C_STATUS_TIMEOUT,           /*!< Timeout polling status flags. */
    I2C_STATUS_INVALIDARGUMENT    /*!< Invalid parameter. */
} I2C_Status;

/**
  * @}
  */

/** @defgroup I2C_DIRECTION I2C Transmission Direction of Bus
  * @{
  * @brief  Macro definitions about I2C transmission direction of bus.
  */
typedef enum {
    I2C_DIRECTION_WRITE = 0U,    /*!< Master transmits, slave receives */
    I2C_DIRECTION_READ           /*!< Master receives, slave transmits */
} I2C_Direction;

/**
  * @}
  */

/** @defgroup I2C_SUBADDRSIZE I2C Sub Address Size
  * @{
  * @brief  Macro definitions about I2C Length of sub address to send in bytes. Maximum size is 4 bytes.
  */
typedef enum {
    I2C_SUBADDRSIZE_NONE = 0U,    /* There is no I2C device sub-address */
    I2C_SUBADDRSIZE_1BYTE,        /* The I2C device sub-address is 1 byte */
    I2C_SUBADDRSIZE_2BYTE,        /* The I2C device sub-address is 2 byte */
    I2C_SUBADDRSIZE_3BYTE,        /* The I2C device sub-address is 3 byte */
    I2C_SUBADDRSIZE_4BYTE         /* The I2C device sub-address is 4 byte */
} I2C_SubAddressSize;

/**
  * @}
  */

/** @defgroup I2C_COMMAND I2C Command
  * @{
  * @brief  Macro definitions about I2C command.
  */
typedef enum {
    I2C_COMMAND_TXDATA         = (0x0U << I2C_MTDR_CMD_S),    /*!< Transmit DATA[7:0] */
    I2C_COMMAND_RXDATA         = (0x1U << I2C_MTDR_CMD_S),    /*!< Receive (DATA[7:0] + 1) bytes */
    I2C_COMMAND_STOP           = (0x2U << I2C_MTDR_CMD_S),    /*!< Generate STOP condition */
    I2C_COMMAND_RXDATA_DISCARD = (0x3U << I2C_MTDR_CMD_S),    /*!< Receive and discard (DATA[7:0] + 1) bytes */
    I2C_COMMAND_START_EXPACK   = (0x4U << I2C_MTDR_CMD_S),    /*!< Generate (repeated) START and transmit address in DATA[7:0].
                                                                   This transfer expects a ACK to be returned */
    I2C_COMMAND_START_EXPNACK  = (0x5U << I2C_MTDR_CMD_S)     /*!< Generate (repeated) START and transmit address in DATA[7:0].
                                                                   This transfer expects a NACK to be returned */
} I2C_Command;

/**
  * @}
  */

/** @defgroup I2C_FIFORESET I2C FIFO Reset
  * @{
  * @brief  Macro definitions about I2C FIFO reset.
  */
typedef enum {
    I2C_FIFORESET_NONE = 0x0U,                            /*!< I2C master/slave fifo no reset */
    I2C_FIFORESET_TX   = I2C_MCR_RTF_M,                   /*!< I2C master/slave tx-fifo reset */
    I2C_FIFORESET_RX   = I2C_MCR_RRF_M,                   /*!< I2C master/slave rx-fifo reset */
    I2C_FIFORESET_TXRX = I2C_MCR_RTF_M | I2C_MCR_RRF_M    /*!< I2C master/slave tx-fifo and rx-fifo reset */
} I2C_FifoReset;

/**
  * @}
  */

/** @defgroup I2C_MASTER_DMA I2C Master DMA Request
  * @{
  * @brief  Macro definitions about I2C master request.
  */
typedef enum {
    I2C_MASTER_DMA_DISABLE = 0U,    /*!< I2C master DMA TX and RX request disable */
    I2C_MASTER_DMA_TX,              /*!< I2C master DMA TX request enable */
    I2C_MASTER_DMA_RX,              /*!< I2C master DMA RX request enable */
    I2C_MASTER_DMA_TXRX,            /*!< I2C master DMA TX and RX request enable */
} I2C_MasterDma;

/**
  * @}
  */

/** @defgroup I2C_MASTER_RXMATCHDATAONLY I2C Master Receive Match Data Only
  * @{
  * @brief  Macro definitions about I2C master only receives the data that matches.
  */
typedef enum {
    I2C_MASTER_RXMATCHDATAONLY_DISABLE = 0U,                  /* Received data is stored in the receive FIFO */
    I2C_MASTER_RXMATCHDATAONLY_ENABLE  = I2C_MCFGR0_RDMO_M    /* Received data is discarded unless the the Data Match Flag (MSR[DMF]) is set */
} I2C_MasterRxMatchDataOnly;

/**
  * @}
  */

/** @defgroup I2C_MASTER_MATCHMODE I2C Master Data Match Mode
  * @{
  * @brief  Macro definitions about I2C master data match mode.
  */
typedef enum {
    I2C_MASTER_MATCHMODE_DISABLED                    = 0x0U,                             /*!< I2C master match disabled */
    I2C_MASTER_MATCHMODE_1ST_EQUALS_M0ORM1           = (0x2U << I2C_MCFGR1_MATCFG_S),    /*!< I2C master match enabled and 1st data word equals MATCH0 OR MATCH1 */
    I2C_MASTER_MATCHMODE_ANY_EQUALS_M0ORM1           = (0x3U << I2C_MCFGR1_MATCFG_S),    /*!< I2C master match enabled and any data word equals MATCH0 OR MATCH1 */
    I2C_MASTER_MATCHMODE_1STEQUALSM0_2STEQUALSM1     = (0x4U << I2C_MCFGR1_MATCFG_S),    /*!< I2C master match enabled and 1st data word equals MATCH0, 2nd data equals MATCH1 */
    I2C_MASTER_MATCHMODE_ANYEQUALSM0_NEXTEQUALSM1    = (0x5U << I2C_MCFGR1_MATCFG_S),    /*!< I2C master match enabled and any data word equals MATCH0, next data equals MATCH1 */
    I2C_MASTER_MATCHMODE_1STANDM1_EQUALS_M0ANDM1     = (0x6U << I2C_MCFGR1_MATCFG_S),    /*!< I2C master match enabled and 1st data word and MATCH0 equals MATCH0 and MATCH1 */
    I2C_MASTER_MATCHMODE_ANYWORDANDM1_EQUALS_M0ANDM1 = (0x7U << I2C_MCFGR1_MATCFG_S)     /*!< I2C master match enabled and any data word and MATCH0 equals MATCH0 and MATCH1 */
} I2C_MasterMatchMode;

/**
  * @}
  */

/** @defgroup I2C_MASTER_PINLOW I2C Master Pin Low Timeout
  * @{
  * @brief  Macro definitions about I2C master pin low timeout.
  */
typedef enum {
    I2C_MASTER_PINLOW_SCL    = 0x0U,                   /*!< I2C Master SCL pin low timeout */
    I2C_MASTER_PINLOW_SCLSDA = I2C_MCFGR1_TIMECFG_M    /*!< I2C Master SCL or SDA pin low timeout */
} I2C_MasterPinLow;

/**
  * @}
  */

/** @defgroup I2C_MASTER_PRESCALER I2C Clock Prescaler
  * @{
  * @brief  Macro definitions about I2C master clock perscaler.
  */
typedef enum {
    I2C_MASTER_PRESCALER_NONE = 0x0U,    /*!< I2C clock prescaler OFF */
    I2C_MASTER_PRESCALER_DIV2,           /*!< I2C clock frequency is divided by 2 */
    I2C_MASTER_PRESCALER_DIV4,           /*!< I2C clock frequency is divided by 4 */
    I2C_MASTER_PRESCALER_DIV8,           /*!< I2C clock frequency is divided by 8 */
    I2C_MASTER_PRESCALER_DIV16,          /*!< I2C clock frequency is divided by 16 */
    I2C_MASTER_PRESCALER_DIV32,          /*!< I2C clock frequency is divided by 32 */
    I2C_MASTER_PRESCALER_DIV64,          /*!< I2C clock frequency is divided by 64 */
    I2C_MASTER_PRESCALER_DIV128          /*!< I2C clock frequency is divided by 128 */
} I2C_MasterPrescaler;

/**
  * @}
  */

/** @defgroup I2C_MASTER_FILTER I2C Master SDA And SCL Filter
  * @{
  * @brief  Macro definitions about I2C master SDA and SCL filter.
  */
typedef enum {
    I2C_MASTER_FILTER_DISABLED = 0x0U,    /*!< I2C Master SDA or SCL filter Disabled */
    I2C_MASTER_FILTER_PCLK1,              /*!< I2C Master SDA or SCL filter = 1 pclk */
    I2C_MASTER_FILTER_PCLK2,              /*!< I2C Master SDA or SCL filter = 2 pclk */
    I2C_MASTER_FILTER_PCLK3,              /*!< I2C Master SDA or SCL filter = 3 pclk */
    I2C_MASTER_FILTER_PCLK4,              /*!< I2C Master SDA or SCL filter = 4 pclk */
    I2C_MASTER_FILTER_PCLK5,              /*!< I2C Master SDA or SCL filter = 5 pclk */
    I2C_MASTER_FILTER_PCLK6,              /*!< I2C Master SDA or SCL filter = 6 pclk */
    I2C_MASTER_FILTER_PCLK7,              /*!< I2C Master SDA or SCL filter = 7 pclk */
    I2C_MASTER_FILTER_PCLK8,              /*!< I2C Master SDA or SCL filter = 8 pclk */
    I2C_MASTER_FILTER_PCLK9,              /*!< I2C Master SDA or SCL filter = 9 pclk */
    I2C_MASTER_FILTER_PCLK10,             /*!< I2C Master SDA or SCL filter = 10 pclk */
    I2C_MASTER_FILTER_PCLK11,             /*!< I2C Master SDA or SCL filter = 11 pclk */
    I2C_MASTER_FILTER_PCLK12,             /*!< I2C Master SDA or SCL filter = 12 pclk */
    I2C_MASTER_FILTER_PCLK13,             /*!< I2C Master SDA or SCL filter = 13 pclk */
    I2C_MASTER_FILTER_PCLK14,             /*!< I2C Master SDA or SCL filter = 14 pclk */
    I2C_MASTER_FILTER_PCLK15              /*!< I2C Master SDA or SCL filter = 15 pclk */
} I2C_MasterFilter;

/**
  * @}
  */

/** @defgroup I2C_MASTER_WATERMARK I2C Master Water Marks value
  * @{
  * @brief  Macro definitions about I2C master water marks value.
  */
typedef enum {
    I2C_MASTER_WATERMARK_0 = 0x0U,    /*!< I2C Master water mark = 0 */
    I2C_MASTER_WATERMARK_1,           /*!< I2C Master water mark = 1 */
    I2C_MASTER_WATERMARK_2,           /*!< I2C Master water mark = 2 */
    I2C_MASTER_WATERMARK_3,           /*!< I2C Master water mark = 3 */
    I2C_MASTER_WATERMARK_4,           /*!< I2C Master water mark = 4 */
    I2C_MASTER_WATERMARK_5,           /*!< I2C Master water mark = 5 */
    I2C_MASTER_WATERMARK_6,           /*!< I2C Master water mark = 6 */
    I2C_MASTER_WATERMARK_7,           /*!< I2C Master water mark = 7 */
    I2C_MASTER_WATERMARK_8,           /*!< I2C Master water mark = 8 */
    I2C_MASTER_WATERMARK_9,           /*!< I2C Master water mark = 9 */
    I2C_MASTER_WATERMARK_10,          /*!< I2C Master water mark = 10 */
    I2C_MASTER_WATERMARK_11,          /*!< I2C Master water mark = 11 */
    I2C_MASTER_WATERMARK_12,          /*!< I2C Master water mark = 12 */
    I2C_MASTER_WATERMARK_13,          /*!< I2C Master water mark = 13 */
    I2C_MASTER_WATERMARK_14,          /*!< I2C Master water mark = 14 */
    I2C_MASTER_WATERMARK_15           /*!< I2C Master water mark = 15 */
} I2C_MasterWaterMark;

/**
* @}
*/

/** @defgroup I2C_SLAVE_DMA I2C Slave DMA Request
  * @{
  * @brief  Macro definitions about I2C slave DMA request.
  */
typedef enum {
    I2C_SLAVE_DMA_DISABLE = 0U,    /*!< I2C slave DMA request disable */
    I2C_SLAVE_DMA_TX,              /*!< I2C slave DMA TX request enable */
    I2C_SLAVE_DMA_RX,              /*!< I2C slave DMA RX request enable */
    I2C_SLAVE_DMA_TXRX,            /*!< I2C slave DMA TX and RX request enable */
    I2C_SLAVE_DMA_ADDRVAILD,       /*!< I2C slave DMA Address-Valid request enable */
    I2C_SLAVE_DMA_TXADDRVAILD,     /*!< I2C slave DMA TX and Address-Valid request enable */
    I2C_SLAVE_DMA_RXADDRVAILD,     /*!< I2C slave DMA RX and Address-Valid request enable */
    I2C_SLAVE_DMA_TXRXADDRVAILD    /*!< I2C slave DMA TX、RX and Address-Valid request enable */
} I2C_SlaveDma;

/**
  * @}
  */

/** @defgroup I2C_SLAVE_MATCHMODE I2C Slave Address Match Mode
  * @{
  * @brief  Macro definitions about I2C slave address match mode.
  */
typedef enum {
    I2C_SLAVE_MATCHMODE_ADDR0_7B               = 0x0U,                              /*!< I2C slave address match 0 (7-bit) */
    I2C_SLAVE_MATCHMODE_ADDR0_10B              = (0x1U << I2C_SCFGR1_ADDRCFG_S),    /*!< I2C slave address match 0 (10-bit) */
    I2C_SLAVE_MATCHMODE_ADDR0_7B_OR_ADDR1_7B   = (0x2U << I2C_SCFGR1_ADDRCFG_S),    /*!< I2C slave address match 0 (7-bit) or address match 1 (7-bit) */
    I2C_SLAVE_MATCHMODE_ADDR0_10B_OR_ADDR1_10B = (0x3U << I2C_SCFGR1_ADDRCFG_S),    /*!< I2C slave address match 0 (10-bit) or address match 1 (10-bit) */
    I2C_SLAVE_MATCHMODE_ADDR0_7B_OR_ADDR1_10B  = (0x4U << I2C_SCFGR1_ADDRCFG_S),    /*!< I2C slave address match 0 (7-bit) or address match 1 (10-bit) */
    I2C_SLAVE_MATCHMODE_ADDR0_10B_OR_ADDR1_7B  = (0x5U << I2C_SCFGR1_ADDRCFG_S),    /*!< I2C slave address match 0 (10-bit) or address match 1 (7-bit) */
    I2C_SLAVE_MATCHMODE_ADDR0_7B_TO_ADDR1_7B   = (0x6U << I2C_SCFGR1_ADDRCFG_S),    /*!< I2C slave from Address match 0 (7-bit) to address match 1 (7-bit) */
    I2C_SLAVE_MATCHMODE_ADDR0_10B_TO_ADDR1_10B = (0x7U << I2C_SCFGR1_ADDRCFG_S)     /*!< I2C slave from Address match 0 (10-bit) to address match 1 (10-bit) */
} I2C_SlaveMatchMode;

/**
  * @}
  */

/** @defgroup I2C_SLAVE_IGNOREACK I2C Slave Ignore Ack
  * @{
  * @brief  Macro definitions about I2C slave ignore ack.
  */
typedef enum {
    I2C_SLAVE_IGNORENACK_DISABLE = 0U,                    /*!< I2C slave ignore ack disable */
    I2C_SLAVE_IGNORENACK_ENABLE  = I2C_SCFGR1_IGNACK_M    /*!< I2C slave ignore ack enable */
} I2C_SlaveIgnoreNack;

/**
  * @}
  */

/** @defgroup I2C_SLAVE_RXDATACFG I2C Slave Receive Data Configuration
  * @{
  * @brief  Macro definitions about I2C slave receive data configuration.
  */
typedef enum {
    I2C_SLAVE_RXDATACFG_DATA       = 0U,                   /* Reading the receive data register will return the
                                                              received data and clear the receive data flag. */
    I2C_SLAVE_RXDATACFG_DATAORADDR = I2C_SCFGR1_RXCFG_M    /* When the SSR[AVF] = 1, reading the receive data register will return
                                                              the address status register and clear the address validity flag.
                                                              When the SSR[AVF] = 0, reading the receive data register will return
                                                              the received data and clear the receive data flag. */
} I2C_SlaveRxDataCfg;

/**
  * @}
  */

/** @defgroup I2C_SLAVE_TXFLAGCFG I2C Slave Transmit Flag Configuration
  * @{
  * @brief  Macro definitions about I2C slave transmit flag configuration.
  */
typedef enum {
    I2C_SLAVE_TXFLAGCFG_NEED2SEND = 0U,                   /* The transmission data flag will be set only when the slave device 
                                                             is transmitting data and the transmission data register is empty */
    I2C_SLAVE_TXFLAGCFG_FIFOEMPTY = I2C_SCFGR1_TXCFG_M    /* The transmission data flag will be set, when the data transmission
                                                             register is empty */
} I2C_SlaveTxFlagCfg;

/**
  * @}
  */

/** @defgroup I2C_SLAVE_SMBUSALERT I2C Slave SMBus Alert
  * @{
  * @brief  Macro definitions about I2C slave smbus alert.
  */
typedef enum {
    I2C_SLAVE_SMBUSALERT_DISABLE = 0U,                  /*!< I2C slave smbus alert disable */
    I2C_SLAVE_SMBUSALERT_ENABLE  = I2C_SCFGR1_SAEN_M    /*!< I2C slave smbus alert enable */
} I2C_SlaveSMBusAlert;

/**
  * @}
  */

/** @defgroup I2C_SLAVE_GENERALCALL I2C Slave General Call
  * @{
  * @brief  Macro definitions about I2C slave general call.
  */
typedef enum {
    I2C_SLAVE_GENERALCALL_DISABLE = 0U,                  /*!< I2C slave general call disable */
    I2C_SLAVE_GENERALCALL_ENABLE  = I2C_SCFGR1_GCEN_M    /*!< I2C slave general call enable */
} I2C_SlaveGeneralCall;

/**
  * @}
  */

/** @defgroup I2C_SLAVE_ACKSTALL I2C Slave ACK Clock Stretching
  * @{
  * @brief  Macro definitions about I2C slave ACK clock stretching.
  * @note   Clock stretching occurs following the 9th bit.
  * @note   When ACKSTALL is enabled, there is no need to set either RX-Stall or Address-Stall.
  */
typedef enum {
    I2C_SLAVE_ACKSTALL_DISABLE = 0U,                      /*!< I2C slave ACK clock stretching is disable */
    I2C_SLAVE_ACKSTALL_ENABLE  = I2C_SCFGR1_ACKSTALL_M    /*!< I2C slave ACK clock stretching is enable */
} I2C_SlaveAckStall;

/**
  * @}
  */

/** @defgroup I2C_SLAVE_TXSTALL I2C Slave TX Data Clock Stretching
  * @{
  * @brief  Macro definitions about I2C slave TX data clock stretching.
  * @note   Clock stretching occurs following the 9th bit.
  */
typedef enum {
    I2C_SLAVE_TXSTALL_DISABLE = 0U,                      /*!< I2C slave TX data clock stretching is disable */
    I2C_SLAVE_TXSTALL_ENABLE  = I2C_SCFGR1_TXDSTALL_M    /*!< I2C slave TX data clock stretching is enable */
} I2C_SlaveTxStall;

/**
  * @}
  */

/** @defgroup I2C_SLAVE_RXSTALL I2C Slave RX Clock Stretching
  * @{
  * @brief  Macro definitions about I2C slave RX clock stretching.
  * @note   Clock stretching occurs following the 9th bit.
  */
typedef enum {
    I2C_SLAVE_RXSTALL_DISABLE = 0U,                     /*!< I2C slave RX clock stretching is disable */
    I2C_SLAVE_RXSTALL_ENABLE  = I2C_SCFGR1_RXSTALL_M    /*!< I2C slave RX clock stretching is enable */
} I2C_SlaveRxStall;

/**
  * @}
  */

/** @defgroup I2C_SLAVE_ADRSTALL I2C Slave Address-valid Clock Stretching
  * @{
  * @brief  Macro definitions about I2C slave Address-valid clock stretching.
  */
typedef enum {
    I2C_SLAVE_ADRSTALL_DISABLE = 0U,                      /*!< I2C slave Address-valid clock stretching is disable */
    I2C_SLAVE_ADRSTALL_ENABLE  = I2C_SCFGR1_ADRSTALL_M    /*!< I2C slave Address-valid clock stretching is enable */
} I2C_SlaveAdrStall;

/**
  * @}
  */

/** @defgroup I2C_SLAVE_FILTER I2C Slave SDA And SCL Filter
  * @{
  * @brief  Macro definitions about I2C slave SDA and SCL filter.
  */
typedef enum {
    I2C_SLAVE_FILTER_DISABLED = 0x0U,    /*!< I2C Slave SDA or SCL filter Disabled */
    I2C_SLAVE_FILTER_PCLK4,              /*!< I2C Slave SDA or SCL filter = 4 pclk */
    I2C_SLAVE_FILTER_PCLK5,              /*!< I2C Slave SDA or SCL filter = 5 pclk */
    I2C_SLAVE_FILTER_PCLK6,              /*!< I2C Slave SDA or SCL filter = 6 pclk */
    I2C_SLAVE_FILTER_PCLK7,              /*!< I2C Slave SDA or SCL filter = 7 pclk */
    I2C_SLAVE_FILTER_PCLK8,              /*!< I2C Slave SDA or SCL filter = 8 pclk */
    I2C_SLAVE_FILTER_PCLK9,              /*!< I2C Slave SDA or SCL filter = 9 pclk */
    I2C_SLAVE_FILTER_PCLK10,             /*!< I2C Slave SDA or SCL filter = 10 pclk */
    I2C_SLAVE_FILTER_PCLK11,             /*!< I2C Slave SDA or SCL filter = 11 pclk */
    I2C_SLAVE_FILTER_PCLK12,             /*!< I2C Slave SDA or SCL filter = 12 pclk */
    I2C_SLAVE_FILTER_PCLK13,             /*!< I2C Slave SDA or SCL filter = 13 pclk */
    I2C_SLAVE_FILTER_PCLK14,             /*!< I2C Slave SDA or SCL filter = 14 pclk */
    I2C_SLAVE_FILTER_PCLK15,             /*!< I2C Slave SDA or SCL filter = 15 pclk */
    I2C_SLAVE_FILTER_PCLK16,             /*!< I2C Slave SDA or SCL filter = 16 pclk */
    I2C_SLAVE_FILTER_PCLK17,             /*!< I2C Slave SDA or SCL filter = 17 pclk */
    I2C_SLAVE_FILTER_PCLK18              /*!< I2C Slave SDA or SCL filter = 18 pclk */
} I2C_SlaveFilter;

/**
  * @}
  */

/** @defgroup I2C_SLAVE_CLKHOLD I2C Slave Clock Hold
  * @{
  * @brief  Macro definitions about I2C slave clock hold.
  */
typedef enum {
    I2C_SLAVE_CLKHOLD_PCLK3 = 0x0U,    /*!< I2C Slave clk hold time = 3 clk */
    I2C_SLAVE_CLKHOLD_PCLK4,           /*!< I2C Slave clk hold time = 4 clk */
    I2C_SLAVE_CLKHOLD_PCLK5,           /*!< I2C Slave clk hold time = 5 clk */
    I2C_SLAVE_CLKHOLD_PCLK6,           /*!< I2C Slave clk hold time = 6 clk */
    I2C_SLAVE_CLKHOLD_PCLK7,           /*!< I2C Slave clk hold time = 7 clk */
    I2C_SLAVE_CLKHOLD_PCLK8,           /*!< I2C Slave clk hold time = 8 clk */
    I2C_SLAVE_CLKHOLD_PCLK9,           /*!< I2C Slave clk hold time = 9 clk */
    I2C_SLAVE_CLKHOLD_PCLK10,          /*!< I2C Slave clk hold time = 10 clk */
    I2C_SLAVE_CLKHOLD_PCLK11,          /*!< I2C Slave clk hold time = 11 clk */
    I2C_SLAVE_CLKHOLD_PCLK12,          /*!< I2C Slave clk hold time = 12 clk */
    I2C_SLAVE_CLKHOLD_PCLK13,          /*!< I2C Slave clk hold time = 13 clk */
    I2C_SLAVE_CLKHOLD_PCLK14,          /*!< I2C Slave clk hold time = 14 clk */
    I2C_SLAVE_CLKHOLD_PCLK15,          /*!< I2C Slave clk hold time = 15 clk */
    I2C_SLAVE_CLKHOLD_PCLK16,          /*!< I2C Slave clk hold time = 16 clk */
    I2C_SLAVE_CLKHOLD_PCLK17,          /*!< I2C Slave clk hold time = 17 clk */
    I2C_SLAVE_CLKHOLD_PCLK18           /*!< I2C Slave clk hold time = 18 clk */
} I2C_SlaveClkHold;

/**
  * @}
  */

/** @defgroup I2C_SLAVE_RESPONSE I2C Slave Response
  * @{
  * @brief  Macro definitions about I2C slave response.
  */
typedef enum {
    I2C_SLAVE_RESPONSE_ACK = 0U,    /*!< I2C slave response ACK */
    I2C_SLAVE_RESPONSE_NACK         /*!< I2C slave response NACK */
} I2C_SlaveResponse;

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
  * \brief  Reset master
  * \note   Resets all internal master logic and registers, except the Master Control (MCR) register.
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  */
static inline void I2C_resetMaster (I2C_TypeDef *i2c)
{
    SET_BIT(i2c->MCR.WORDVAL, I2C_MCR_RST_M);
    CLEAR_BIT(i2c->MCR.WORDVAL, I2C_MCR_RST_M);
}

/**
  * \brief  Reset master TX-FIFO or RX-FIFO
  * \param  i2c          I2C pointer to a I2C_TypeDef structure
  *                       - I2C1: I2C1 base address index
  *                       - I2C2: I2C2 base address index
  * \param  fifoReset    I2C master TX-FIFO or RX-FIFO reset select
  *                       This parameter can be any value of @ref I2C_FIFORESET
  */
static inline void I2C_resetMasterFIFO (I2C_TypeDef *i2c, I2C_FifoReset fifoReset)
{
    SET_BIT(i2c->MCR.WORDVAL, fifoReset);
}

/**
  * \brief  Master is enabled in debug mode
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  */
static inline void I2C_enableMasterDebug (I2C_TypeDef *i2c)
{
    SET_BIT(i2c->MCR.WORDVAL, I2C_MCR_DBGEN_M);
}

/**
  * \brief  Master is disabled in debug mode
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  */
static inline void I2C_disableMasterDebug (I2C_TypeDef *i2c)
{
    CLEAR_BIT(i2c->MCR.WORDVAL, I2C_MCR_DBGEN_M);
}

/**
  * \brief  Enable master module
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  */
static inline void I2C_enableMasterModule (I2C_TypeDef *i2c)
{
    SET_BIT(i2c->MCR.WORDVAL, I2C_MCR_MEN_M);
}

/**
  * \brief  Disable master module
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  */
static inline void I2C_disableMasterModule (I2C_TypeDef *i2c)
{
    CLEAR_BIT(i2c->MCR.WORDVAL, I2C_MCR_MEN_M);
}

/**
  * \brief  Enable master interrupts
  * \param  i2c           I2C pointer to a I2C_TypeDef structure
  *                        - I2C1: I2C1 base address index
  *                        - I2C2: I2C2 base address index
  * \param  interrupts    I2C master interrupt source
  *                        This parameter can be any value of @ref I2C_MASTER_INTERRUPT
  *                        All members of the parameters can be combined together.
  *
  */
static inline void I2C_enableMasterInterrupts (I2C_TypeDef *i2c, uint32_t interrupts)
{
    SET_BIT(i2c->MIER.WORDVAL, interrupts & 0x7F03UL);
}

/**
  * \brief  Disable master interrupts
  * \param  i2c           I2C pointer to a I2C_TypeDef structure
  *                        - I2C1: I2C1 base address index
  *                        - I2C2: I2C2 base address index
  * \param  interrupts    I2C master interrupt source
  *                        This parameter can be any value of @ref I2C_MASTER_INTERRUPT
  *                        All members of the parameters can be combined together.
  */
static inline void I2C_disableMasterInterrupts (I2C_TypeDef *i2c, uint32_t interrupts)
{
    CLEAR_BIT(i2c->MIER.WORDVAL, interrupts & 0x7F03UL);
}

/**
  * \brief  Get master interrupts source
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  * \return Returned the master interrupts
  */
static inline uint32_t I2C_getMasterEnabledInterrupts (I2C_TypeDef *i2c)
{
    return READ_REG(i2c->MIER.WORDVAL);
}

/**
  * \brief  Get the master status flags
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  * \return Returned the master status flags
  */
static inline uint32_t I2C_getMasterStatusFlags (I2C_TypeDef *i2c)
{
    return READ_REG(i2c->MSR.WORDVAL);
}

/**
  * \brief  Clear the master status flags
  * \param  i2c      I2C pointer to a I2C_TypeDef structure
  *                   - I2C1: I2C1 base address index
  *                   - I2C2: I2C2 base address index
  * \param  flags    I2C master status flags
  *                   This parameter can be one of the values in @ref I2C_MASTER_FLAG or a combination of several values
  */
static inline void I2C_clearMasterStatusFlags (I2C_TypeDef *i2c, uint32_t flags)
{
    WRITE_REG(i2c->MSR.WORDVAL, flags);
}

/**
  * \brief  Set the master DMA request
  * \param  i2c           I2C pointer to a I2C_TypeDef structure
  *                        - I2C1: I2C1 base address index
  *                        - I2C2: I2C2 base address index
  * \param  dmaRequest    I2C master dma request
  *                        This parameter can be any value of @ref I2C_MASTER_DMA
  */
static inline void I2C_setMasterDmaRequst (I2C_TypeDef *i2c, I2C_MasterDma dmaRequest)
{
    WRITE_REG(i2c->MDER.WORDVAL, (uint32_t)dmaRequest);
}

/**
  * \brief  Enable the master auto-stop function
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  */
static inline void I2C_enableMasterAutoStop (I2C_TypeDef *i2c)
{
    SET_BIT(i2c->MCFGR1.WORDVAL, I2C_MCFGR1_AUTOSTOP_M);
}

/**
  * \brief  Disable the master auto-stop function
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  */
static inline void I2C_disableMasterAutoStop (I2C_TypeDef *i2c)
{
    CLEAR_BIT(i2c->MCFGR1.WORDVAL, I2C_MCFGR1_AUTOSTOP_M);
}

/**
  * \brief  Set the prescaler of the master.
  * \param  i2c          I2C pointer to a I2C_TypeDef structure
  *                       - I2C1: I2C1 base address index
  *                       - I2C2: I2C2 base address index
  * \param  prescaler    I2C master clock prescaler
  *                       This parameter can be any value of @ref I2C_MASTER_PRESCALER
  */
static inline void I2C_setMasterPrescaler (I2C_TypeDef *i2c, I2C_MasterPrescaler prescaler)
{
    MODIFY_REG(i2c->MCFGR1.WORDVAL, I2C_MCFGR1_PRESCALER_M, prescaler);
}

/**
  * \brief  Set the filtering for the master SCL and SDA.
  * \param  i2c          I2C pointer to a I2C_TypeDef structure
  *                       - I2C1: I2C1 base address index
  *                       - I2C2: I2C2 base address index
  * \param  sclFilter    I2C master SCL filter
  *                       This parameter can be any value of @ref I2C_MASTER_FILTER
  * \param  sdaFilter    I2C master SDA filter
  *                       This parameter can be any value of @ref I2C_MASTER_FILTER
  */
static inline void I2C_setMasterGlitchFilter (I2C_TypeDef *i2c, I2C_MasterFilter sclFilter, I2C_MasterFilter sdaFilter)
{
    MODIFY_REG(i2c->MCFGR2.WORDVAL, I2C_MCFGR2_FILTSCL_M | I2C_MCFGR2_FILTSDA_M,
               ((sclFilter << I2C_MCFGR2_FILTSCL_S) & I2C_MCFGR2_FILTSCL_M) |
               ((sdaFilter << I2C_MCFGR2_FILTSDA_S) & I2C_MCFGR2_FILTSDA_M));
}

/**
  * \brief  Set the bus idle timeout for the master.
  * \param  i2c             I2C pointer to a I2C_TypeDef structure
  *                          - I2C1: I2C1 base address index
  *                          - I2C2: I2C2 base address index
  * \param  timeoutPclk     I2C master bus idle timeout, The timing unit is pclk.
  *                          The range of this parameter's value is from 0 to 4095.
  */
static inline void I2C_setMasterBusIdleTimeout (I2C_TypeDef *i2c, uint16_t timeoutPclk)
{
    MODIFY_REG(i2c->MCFGR2.WORDVAL, I2C_MCFGR2_BUSIDLE_M, timeoutPclk & I2C_MCFGR2_BUSIDLE_M);
}

/**
  * \brief  Set the pin low timeout for the master.
  * \param  i2c            I2C pointer to a I2C_TypeDef structure
  *                         - I2C1: I2C1 base address index
  *                         - I2C2: I2C2 base address index
  * \param  pinLowCfg      I2C master pin low config, only SCL pin low or SCL and SDA pin low.
  *                         This parameter can be any value of @ref I2C_MASTER_PINLOW
  * \param  timeoutPclk    I2C master bus idle timeout, The timing unit is pclk.
  *                         The range of this parameter's value is from 0 to 4095.
  *                         When the value is 0, disable the pin low timeout function.
  *                         When the value is not zero, it indicates that the low timeout duration is
  *                         timeoutPclk multiplied by 256 pclk cycles.
  */
static inline void I2C_setMasterPinLowTimeout (I2C_TypeDef *i2c, I2C_MasterPinLow pinLowCfg, uint16_t timeoutPclk)
{
    MODIFY_REG(i2c->MCFGR1.WORDVAL, I2C_MCFGR1_TIMECFG_M, pinLowCfg);
    MODIFY_REG(i2c->MCFGR3.WORDVAL, I2C_MCFGR3_PINLOW_M, (timeoutPclk << I2C_MCFGR3_PINLOW_S) & I2C_MCFGR3_PINLOW_M);
}

/**
  * \brief  Set the master FIFO water marks.
  * \param  i2c             I2C pointer to a I2C_TypeDef structure
  *                          - I2C1: I2C1 base address index
  *                          - I2C2: I2C2 base address index
  * \param  txWaterMarks    I2C master TX-FIFO water marks
  *                          This parameter can be any value of @ref I2C_MASTER_WATERMARK
  * \param  rxWaterMarks    I2C master RX-FIFO water marks
  *                          This parameter can be any value of @ref I2C_MASTER_WATERMARK
  */
static inline void I2C_setMasterWatermarks (I2C_TypeDef *i2c, I2C_MasterWaterMark txWaterMarks, I2C_MasterWaterMark rxWaterMarks)
{
    MODIFY_REG(i2c->MFCR.WORDVAL, I2C_MFCR_RXWATER_M | I2C_MFCR_TXWATER_M,
               (uint32_t)txWaterMarks | (uint32_t)rxWaterMarks);
}

/**
  * \brief  Get the number of bytes in the RX-FIFO.
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  * \return Returned the number of bytes in the RX-FIFO.
  */
static inline uint8_t I2C_getMasterRxFifoCounts (I2C_TypeDef *i2c)
{
    return (uint8_t)(READ_BIT(i2c->MFSR.WORDVAL, I2C_MFSR_RXCOUNT_M) >> I2C_MFSR_RXCOUNT_S);
}

/**
  * \brief  Get the number of bytes in the TX-FIFO.
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  * \return Returned the number of bytes in the TX-FIFO.
  */
static inline uint8_t I2C_getMasterTxFifoCounts (I2C_TypeDef *i2c)
{
    return (uint8_t)(READ_BIT(i2c->MFSR.WORDVAL, I2C_MFSR_TXCOUNT_M) >> I2C_MFSR_TXCOUNT_S);
}

/**
  * \brief  Get the bus idle state of master.
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  * \return Returned the bus idle status of master.
  *                 - 0: I2C bus is idle
  *                 - 0: I2C bus is busy
  */
static inline uint8_t I2C_getMasterBusIdleState (I2C_TypeDef *i2c)
{
    return (READ_BIT(i2c->MSR.WORDVAL, I2C_MSR_BBF_M) == 0U) ? 0U : 1U;
}

/**
  * \brief  Reset slave
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  */
static inline void I2C_resetSlave (I2C_TypeDef *i2c)
{
    SET_BIT(i2c->SCR.WORDVAL, I2C_SCR_RST_M);
    CLEAR_BIT(i2c->SCR.WORDVAL, I2C_SCR_RST_M);
}

/**
  * \brief  Reset slave TX-FIFO or RX-FIFO
  * \param  i2c          I2C pointer to a I2C_TypeDef structure
  *                       - I2C1: I2C1 base address index
  *                       - I2C2: I2C2 base address index
  * \param  fifoReset    I2C slave TX-FIFO or RX-FIFO reset select
  *                       This parameter can be any value of @ref I2C_FIFORESET
  */
static inline void I2C_resetSlaveFIFO (I2C_TypeDef *i2c, I2C_FifoReset fifoReset)
{
    SET_BIT(i2c->SCR.WORDVAL, fifoReset);
}

/**
  * \brief  Enable slave module
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  */
static inline void I2C_enableSlaveModule (I2C_TypeDef *i2c)
{
    SET_BIT(i2c->SCR.WORDVAL, I2C_SCR_SEN_M);
}

/**
  * \brief  Disable slave module
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  */
static inline void I2C_disableSlaveModule (I2C_TypeDef *i2c)
{
    CLEAR_BIT(i2c->SCR.WORDVAL, I2C_SCR_SEN_M);
}

/**
  * \brief  Enable slave interrupts
  * \param  i2c           I2C pointer to a I2C_TypeDef structure
  *                        - I2C1: I2C1 base address index
  *                        - I2C2: I2C2 base address index
  * \param  interrupts    I2C slave interrupt source
  *                        This parameter can be any value of @ref I2C_SLAVE_INTERRUPT
  *                        All members of the parameters can be combined together.
  *
  */
static inline void I2C_enableSlaveInterrupts (I2C_TypeDef *i2c, uint32_t interrupts)
{
    SET_BIT(i2c->SIER.WORDVAL, interrupts & 0xFF0FUL);
}

/**
  * \brief  Disable slave interrupts
  * \param  i2c           I2C pointer to a I2C_TypeDef structure
  *                        - I2C1: I2C1 base address index
  *                        - I2C2: I2C2 base address index
  * \param  interrupts    I2C slave interrupt source
  *                        This parameter can be any value of @ref I2C_SLAVE_INTERRUPT
  *                        All members of the parameters can be combined together.
  */
static inline void I2C_disableSlaveInterrupts (I2C_TypeDef *i2c, uint32_t interrupts)
{
    CLEAR_BIT(i2c->SIER.WORDVAL, interrupts & 0xFF0FUL);
}

/**
  * \brief  Get slave interrupts source
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  * \return Returned the slave interrupts
  */
static inline uint32_t I2C_getSlaveEnabledInterrupts (I2C_TypeDef *i2c)
{
    return READ_REG(i2c->SIER.WORDVAL);
}

/**
  * \brief  Get the slave status flags
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  * \return Returned the slave status flags
  */
static inline uint32_t I2C_getSlaveStatusFlags (I2C_TypeDef *i2c)
{
    return READ_REG(i2c->SSR.WORDVAL);
}

/**
  * \brief  Clear the slave status flags
  * \param  i2c      I2C pointer to a I2C_TypeDef structure
  *                   - I2C1: I2C1 base address index
  *                   - I2C2: I2C2 base address index
  * \param  flags    I2C slave status flags
  *                   This parameter can be one of the values in @ref I2C_SLAVE_FLAG or a combination of several values
  */
static inline void I2C_clearSlaveStatusFlags (I2C_TypeDef *i2c, uint32_t flags)
{
    WRITE_REG(i2c->SSR.WORDVAL, flags);
}

/**
  * \brief  Set the slave DMA request
  * \param  i2c           I2C pointer to a I2C_TypeDef structure
  *                        - I2C1: I2C1 base address index
  *                        - I2C2: I2C2 base address index
  * \param  dmaRequest    I2C slave dma request
  *                        This parameter can be any value of @ref I2C_SLAVE_DMA
  */
static inline void I2C_setSlaveDmaRequst (I2C_TypeDef *i2c, I2C_SlaveDma dmaRequest)
{
    WRITE_REG(i2c->SDER.WORDVAL, (uint32_t)dmaRequest);
}

/**
  * \brief  Set the filtering for the slave SCL and SDA.
  * \note   It can only be called when the slave is disabled.
  * \param  i2c           I2C pointer to a I2C_TypeDef structure
  *                        - I2C1: I2C1 base address index
  *                        - I2C2: I2C2 base address index
  * \param  sclFilter     I2C slave SCL filter
  *                        This parameter can be any value of @ref I2C_SLAVE_FILTER
  * \param  sdaFilter     I2C slave SDA filter
  *                        This parameter can be any value of @ref I2C_SLAVE_FILTER
  */
static inline void I2C_setSalveGlitchFilter (I2C_TypeDef *i2c, I2C_SlaveFilter sclFilter, I2C_SlaveFilter sdaFilter)
{
    __IO uint32_t tmp = 0;
    MODIFY_REG(i2c->SCFGR2.WORDVAL, I2C_SCFGR2_FILTSCL_M | I2C_SCFGR2_FILTSDA_M,
               ((sclFilter << I2C_SCFGR2_FILTSCL_S) & I2C_SCFGR2_FILTSCL_M) |
               ((sdaFilter << I2C_SCFGR2_FILTSDA_S) & I2C_SCFGR2_FILTSDA_M));
    if ((sclFilter != I2C_SLAVE_FILTER_DISABLED) || (sdaFilter != I2C_SLAVE_FILTER_DISABLED))
    {
        tmp = I2C_SCR_FILTEN_M;
    }
    MODIFY_REG(i2c->SCR.WORDVAL, I2C_SCR_FILTEN_M, tmp);
}

/**
  * \brief  Get the bus idle state of slave.
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  * \return Returned the bus idle status of slave.
  *                 - 0:  I2C bus is idle
  *                 - 0:  I2C bus is busy
  */
static inline uint8_t I2C_getSlaveBusIdleState (I2C_TypeDef *i2c)
{
    return (READ_BIT(i2c->SSR.WORDVAL, I2C_SSR_BBF_M) == 0U) ? 0U : 1U;
}

/**
  * \brief  Slave sends a response.
  * \param  i2c          I2C pointer to a I2C_TypeDef structure
  *                       - I2C1: I2C1 base address index
  *                       - I2C2: I2C2 base address index
  * \param  ackOrNack    I2C slave response
  *                       This parameter can be any value of @ref I2C_SLAVE_RESPONSE
  */
static inline void I2C_sendSlaveResponse (I2C_TypeDef *i2c, I2C_SlaveResponse ackOrNack)
{
    WRITE_REG(i2c->STAR.WORDVAL, ackOrNack);
}


/**
  * \brief  Set slave stretching.
  * \param  i2c         I2C pointer to a I2C_TypeDef structure
  *                      - I2C1: I2C1 base address index
  *                      - I2C2: I2C2 base address index
  * \param  ackStall    I2C slave ACK stall
  *                      This parameter can be any value of @ref I2C_SLAVE_ACKSTALL
  * \param  txStall     I2C slave TX stall
  *                      This parameter can be any value of @ref I2C_SLAVE_TXSTALL
  * \param  rxStall     I2C slave RX stall
  *                      This parameter can be any value of @ref I2C_SLAVE_RXSTALL
  * \param  adrStall    I2C slave ADDR stall
  *                      This parameter can be any value of @ref I2C_SLAVE_ADRSTALL
  */
static inline void I2C_setSlaveStall (I2C_TypeDef *i2c, I2C_SlaveAckStall ackStall,
                                                        I2C_SlaveTxStall txStall,
                                                        I2C_SlaveRxStall rxStall,
                                                        I2C_SlaveAdrStall adrStall)
{
    MODIFY_REG(i2c->SCFGR1.WORDVAL,
               I2C_SCFGR1_ACKSTALL_M | I2C_SCFGR1_TXDSTALL_M | I2C_SCFGR1_RXSTALL_M | I2C_SCFGR1_ADRSTALL_M,
               (uint32_t)ackStall    | (uint32_t)txStall     | (uint32_t)rxStall    | (uint32_t)adrStall);
}

/**
  * \brief  Set slave clock hold time.
  * \param  i2c        I2C pointer to a I2C_TypeDef structure
  *                     - I2C1: I2C1 base address index
  *                     - I2C2: I2C2 base address index
  * \param  clkHold    I2C slave clock hold time
  *                     This parameter can be any value of @ref I2C_SLAVE_CLKHOLD
  */
static inline void I2C_setSlaveClkHold (I2C_TypeDef *i2c, I2C_SlaveClkHold clkHold)
{
    MODIFY_REG(i2c->SCFGR2.WORDVAL, I2C_SCFGR2_CLKHOLD_M, clkHold);
}

/**
  * \brief  Set slave data valid delay.
  * \param  i2c          I2C pointer to a I2C_TypeDef structure
  *                       - I2C1: I2C1 base address index
  *                       - I2C2: I2C2 base address index
  * \param  dataValid    I2C slave data valid delay
  *                       The range of this parameter's value is from 0 to 63.
  */
static inline void I2C_setSlaveDataValid (I2C_TypeDef *i2c, uint8_t dataValid)
{
    MODIFY_REG(i2c->SCFGR2.WORDVAL, I2C_SCFGR2_DATAVD_M, (dataValid & 0x3FU) << I2C_SCFGR2_DATAVD_S);
}

/**
  * \brief  Set smbus alert response of slave.
  * \param  i2c           I2C pointer to a I2C_TypeDef structure
  *                        - I2C1: I2C1 base address index
  *                        - I2C2: I2C2 base address index
  * \param  smBusAlert    I2C slave smbus alert
  *                        This parameter can be any value of @ref I2C_SLAVE_SMBUSALERT
  */
static inline void I2C_setSlaveSMBusAlert (I2C_TypeDef *i2c, I2C_SlaveSMBusAlert smBusAlert)
{
    MODIFY_REG(i2c->SCFGR1.WORDVAL, I2C_SCFGR1_SAEN_M, smBusAlert);
}

/**
  * \brief  Set slave to respond to broadcasts.
  * \param  i2c            I2C pointer to a I2C_TypeDef structure
  *                         - I2C1: I2C1 base address index
  *                         - I2C2: I2C2 base address index
  * \param  generalCall    I2C slave general call enable or disable
  *                         This parameter can be any value of @ref I2C_SLAVE_GENERALCALL
  */
static inline void I2C_setSlaveGeneralCall (I2C_TypeDef *i2c, I2C_SlaveGeneralCall generalCall)
{
    MODIFY_REG(i2c->SCFGR1.WORDVAL, I2C_SCFGR1_GCEN_M, generalCall);
}

/**
  * \brief  Set slave to ignore nack.
  * \param  i2c           I2C pointer to a I2C_TypeDef structure
  *                        - I2C1: I2C1 base address index
  *                        - I2C2: I2C2 base address index
  * \param  ignoreNack    I2C slave ignore nack enable or disable
  *                         This parameter can be any value of @ref I2C_SLAVE_IGNORENACK
  */
static inline void I2C_setSlaveIgnoreNack (I2C_TypeDef *i2c, I2C_SlaveIgnoreNack ignoreNack)
{
    MODIFY_REG(i2c->SCFGR1.WORDVAL, I2C_SCFGR1_IGNACK_M, ignoreNack);
}

/**
  * \brief  Set slave expand config.
  * \param  i2c          I2C pointer to a I2C_TypeDef structure
  *                       - I2C1: I2C1 base address index
  *                       - I2C2: I2C2 base address index
  * \param  txFlagCfg    I2C slave receive data configuration
  *                       This parameter can be any value of @ref I2C_SLAVE_TXFLAGCFG
  * \param  rxDataCfg    I2C slave transmit flag configuration
  *                       This parameter can be any value of @ref I2C_SLAVE_RXDATACFG
  */
static inline void I2C_setSlaveTxRxExpand (I2C_TypeDef *i2c, I2C_SlaveTxFlagCfg txFlagCfg, I2C_SlaveRxDataCfg rxDataCfg)
{
    MODIFY_REG(i2c->SCFGR1.WORDVAL, 
               I2C_SCFGR1_TXCFG_M  | I2C_SCFGR1_RXCFG_M,
               (uint32_t)txFlagCfg | (uint32_t)rxDataCfg);
}

/**
  * \brief  Configure master baudrate.
  * \param  i2c            I2C pointer to a I2C_TypeDef structure
  *                         - I2C1: I2C1 base address index
  *                         - I2C2: I2C2 base address index
  * \param  sourceClock    The input clock frequency of the module, use Hz as the unit.
  *                         This frequency can be obtained by using @ref RCC_getPclk2Frequency().
  * \param  baudRate       The expected I2C communication frequency, use Hz as the unit.
  */
extern void I2C_configMasterBaudRate (I2C_TypeDef *i2c, uint32_t sourceClock, uint32_t baudRate);

/**
  * \brief  Configure master data match.
  * \param  i2c                I2C pointer to a I2C_TypeDef structure
  *                             - I2C1: I2C1 base address index
  *                             - I2C2: I2C2 base address index
  * \param  matchMode          The data match mode for master
  *                             This parameter can be any value of @ref I2C_MASTER_MATCHMODE
  * \param  matchCode0         The match data 0.
  *                             The range of values is from 0 to 255.
  * \param  matchCode1         The match data 1.
  *                             The range of values is from 0 to 255.
  * \param  rxMatchDataOnly    I2C master only receives the data that matches.
  *                             This parameter can be any value of @ref I2C_MASTER_RXMATCHDATAONLY
  */
extern void I2C_configMasterDataMatch (I2C_TypeDef *i2c, I2C_MasterMatchMode matchMode,
                                       uint8_t matchCode0, uint8_t matchCode1, I2C_MasterRxMatchDataOnly rxMatchDataOnly);

/**
  * \brief  check and clear master error.
  * \param  i2c       I2C pointer to a I2C_TypeDef structure
  *                    - I2C1: I2C1 base address index
  *                    - I2C2: I2C2 base address index
  * \param  status    The master status flags
  *                    This parameter can be obtained by reading the MSR register.
  * \return Returned the status of master
  *                    This value can be any value of @ref I2C_STATUS
  */
extern I2C_Status I2C_checkAndClearMasterError (I2C_TypeDef *i2c, uint32_t status);

/**
  * \brief  Waiting for the master TX-FIFO to have space available.
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  * \return Returned the status of master
  *                 This value can be any value of @ref I2C_STATUS
  */
extern I2C_Status I2C_waitMasterTxReady (I2C_TypeDef *i2c);

/**
  * \brief  Check the busy signal on the master bus.
  * \param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  * \return Returned the status of master
  *                 This value can be any value of @ref I2C_STATUS
  */
extern I2C_Status I2C_checkMasterBusyBus (I2C_TypeDef *i2c);

/**
  * \brief  Check if the slave is ready from the master.
  * \param  i2c        I2C pointer to a I2C_TypeDef structure
  *                     - I2C1: I2C1 base address index
  *                     - I2C2: I2C2 base address index
  * \param  address    I2C device address
  *                     The range of this parameter's value is from 0 to 127.
  * \param  trials     The number of times the host sends addressing requests
  *                     When set to 0, it will enter an infinite loop until the device becomes ready.
  *                     When set to non-zero, it will repeat the addressing operation trials times.
  */
extern void I2C_isDeviceReady (I2C_TypeDef *i2c, uint8_t address, uint32_t trials);

/**
  * \brief  The master send start and the address.
  * \param  i2c          I2C pointer to a I2C_TypeDef structure
  *                       - I2C1: I2C1 base address index
  *                       - I2C2: I2C2 base address index
  * \param  address      I2C device address
  *                      The range of this parameter's value is from 0 to 127.
  * \param  direction    I2C transmission direction
  *                       This parameter can be any value of @ref I2C_DIRECTION
  * \return Returned the status of master
  *                       This value can be any value of @ref I2C_STATUS
  */
extern I2C_Status I2C_sendStart (I2C_TypeDef *i2c, uint8_t address, I2C_Direction direction);

/**
  * \brief  The master send re-start and the address.
  * \param  i2c          I2C pointer to a I2C_TypeDef structure
  *                       - I2C1: I2C1 base address index
  *                       - I2C2: I2C2 base address index
  * \param  address      I2C device address
  *                       The range of this parameter's value is from 0 to 127.
  * \param  direction    I2C transmission direction
  *                       This parameter can be any value of @ref I2C_DIRECTION
  * \return Returned the status of master
  *                       This value can be any value of @ref I2C_STATUS
  */
extern I2C_Status I2C_sendReStart (I2C_TypeDef *i2c, uint8_t address, I2C_Direction direction);

/**
  * \brief  The master send stop.
  * \param  i2c          I2C pointer to a I2C_TypeDef structure
  *                       - I2C1: I2C1 base address index
  *                       - I2C2: I2C2 base address index
  * \return Returned the status of master
  *                       This value can be any value of @ref I2C_STATUS
  */
extern I2C_Status I2C_sendStop (I2C_TypeDef *i2c);

/**
  * \brief  The master transmits the memory address of the slave unit.
  * \param  i2c               I2C pointer to a I2C_TypeDef structure
  *                            - I2C1: I2C1 base address index
  *                            - I2C2: I2C2 base address index
  * \param  subAddress        I2C device memory address
  *                            The range of this parameter's value is from 0 to 0xFFFFFFFF.
  * \param  subAddressSize    I2C device memory address size
  *                            This parameter can be any value of @ref I2C_SUBADDRSIZE
  * \return Returned the status of master
  *                            This value can be any value of @ref I2C_STATUS
  */
extern I2C_Status I2C_sendSubAddrMaster (I2C_TypeDef *i2c, uint32_t subAddress, I2C_SubAddressSize subAddressSize);

/**
  * \brief  The master send data.
  * \param  i2c       I2C pointer to a I2C_TypeDef structure
  *                    - I2C1: I2C1 base address index
  *                    - I2C2: I2C2 base address index
  * \param  txBuff    The pointer of the data that the I2C master needs to send
  * \param  txSize    The amount of data that the I2C master needs to send
  * \return Returned the status of master
  *                   This value can be any value of @ref I2C_STATUS
  */
extern I2C_Status I2C_sendDataMaster (I2C_TypeDef *i2c, void *txBuff, uint32_t txSize);

/**
  * \brief  The master receive data.
  * \param  i2c       I2C pointer to a I2C_TypeDef structure
  *                    - I2C1: I2C1 base address index
  *                    - I2C2: I2C2 base address index
  * \param  rxBuff    The pointer of the data that the I2C master needs to receive
  * \param  rxSize    The amount of data that the I2C master needs to receive
  *                    The maximum number of received bytes cannot exceed 3840.
  * \return Returned the status of master
  *                    This value can be any value of @ref I2C_STATUS
  */
extern I2C_Status I2C_receiveDataMaster (I2C_TypeDef *i2c, void *rxBuff, uint32_t rxSize);

/**
  * \brief  Configure slave address matching.
  * \param  i2c          I2C pointer to a I2C_TypeDef structure
  *                       - I2C1: I2C1 base address index
  *                       - I2C2: I2C2 base address index
  * \param  matchMode    I2C slave match mode
  *                       This parameter can be any value of @ref I2C_SLAVE_MATCHMODE
  * \param  address0     I2C slave address 0
  *                       This address can be 7-b or 10-b.
  * \param  address1     I2C slave address 1
  *                       This address can be 7-b or 10-b.
  */
extern void I2C_configSlaveAddressMatch (I2C_TypeDef *i2c, I2C_SlaveMatchMode matchMode, uint16_t address0, uint16_t address1);

/**
  * \brief  check and clear slave error.
  * \param  i2c       I2C pointer to a I2C_TypeDef structure
  *                    - I2C1: I2C1 base address index
  *                    - I2C2: I2C2 base address index
  * \param  status    The slave status flags
  *                    This parameter can be obtained by reading the SSR register.
  * \return Returned the status of slave
  *                    This value can be any value of @ref I2C_STATUS
  */
extern I2C_Status I2C_checkAndClearSlaveError (I2C_TypeDef *i2c, uint32_t status);

/**
  * \brief  The slave send data.
  * \param  i2c             I2C pointer to a I2C_TypeDef structure
  *                          - I2C1: I2C1 base address index
  *                          - I2C2: I2C2 base address index
  * \param  txBuff          The pointer of the data that the I2C slave needs to send
  * \param  txSize          The amount of data that the I2C salve needs to send
  * \param  actualTxSize    The actual number of received data by the I2C slave device
  * \return Returned the status of slave
  *                         This value can be any value of @ref I2C_STATUS
  */
extern I2C_Status I2C_sendDataSlave (I2C_TypeDef *i2c, void *txBuff, uint32_t txSize, uint32_t *actualTxSize);

/**
  * \brief  The slave receive data.
  * \param  i2c             I2C pointer to a I2C_TypeDef structure
  *                          - I2C1: I2C1 base address index
  *                          - I2C2: I2C2 base address index
  * \param  rxBuff          The pointer for the I2C slave expecting to receive data
  * \param  rxSize          The expected quantity of data to be received by the I2C slave device
  * \param  actualTxSize    The actual number of received data by the I2C slave device
  * \return Returned the status of slave
  *                         This value can be any value of @ref I2C_STATUS
  */
extern I2C_Status I2C_receiveDataSlave (I2C_TypeDef *i2c, void *rxBuff, uint32_t rxSize, uint32_t *actualRxSize);


#ifdef __cplusplus
}
#endif


#endif /* __I2C_H__ */
