/**
  * @file       pmbus.h
  * @author     Favian
  * @brief      Header file for NS800RT7xxx pmbus module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __PMBUS_H__
#define __PMBUS_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_pmbus.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup PMBUS_EXPORTED_TYPES PMBUS Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'PMBUS' module.
  */

/** @defgroup PMBUS_SPEEDMODE PMBUS Speed Mode
  * @{
  * @brief  Macro definitions about PMBUS Speed Mode.
  *         This is the data type used for setting and getting the speed mode.
  *         It is also used when specifying the scl count values.
  */
typedef enum {
    PMBUS_SPEED_STANDARD = 0x1U,    /*!< standard speed (100 kbps) */
    PMBUS_SPEED_FAST                /*!< fast/ultra-fast speed (400 kbps) */
} PMBUS_SpeedMode;

/**
  * @}
  */

/** @defgroup PMBUS_SCLPHASE PMBUS SCL Phase
  * @{
  * @brief  Macro definitions about PMBUS SCL Phase.
  *         This is the data type used for specifying whether the high or low
  *         count of the scl clock for whatever speed is being read/modified.
  */
typedef enum {
    PMBUS_SCL_LOW = 0x0U,    /*!< SCL clock count low phase */
    PMBUS_SCL_HIGH           /*!< SCL clock count high phase */
} PMBUS_SclPhase;

/**
  * @}
  */

/** @defgroup PMBUS_ADDRESSMDOE PMBUS SCL Phase
  * @{
  * @brief  Macro definitions about PMBUS SCL Phase.
  *         This is the data type used for specifying the addressing mode used
  *         for transfers.
  *         An PMBUS master begins all transfer with the
  *         specified addressing mode.  An PMBUS slave only responds to
  *         transfers of the same type as its addressing mode.
  */
typedef enum {
    PMBUS_ADDRESS_7BIT = 0x0U,    /*!< 7-bit address mode. Only the 7 LSBs of the slave and/or target address are relevant. */
    PMBUS_ADDRESS_10BIT           /*!< 10-bit address mode. The 10 LSBs of the slave and/or target address are relevant. */
} PMBUS_AddressMode;

/**
  * @}
  */

/** @defgroup PMBUS_TXMODE PMBUS Transmit Mode
  * @{
  * @brief  Macro definitions about PMBUS Transmit Mode.
  *         This is the data type used for specifying what type of the transfer
  *         is initiated upon the next write to the transmit FIFO.  There are
  *         three possible types of transfers that may be initiated by an PMBUS
  *         master:
  *          - Start condition followed by the programmed target address.
  *          - Start byte protocol. This is identical to the start condition
  *            except that a start byte is issued before the target address.
  *          - General call. Addresses every slave attached to the PMBUS bus.
  */
typedef enum {
    PMBUS_TX_TARGET = 0x0,    /*!< normal transfer using target address */
    PMBUS_TX_GC     = 0x2,    /*!< issue a general call */
    PMBUS_TX_START  = 0x3     /*!< issue a start byte PMBUS command */
} PMBUS_TxMode;

/**
  * @}
  */

/** @defgroup PMBUS_SLAVE_STOP_INT_MODE PMBUS Slave Stop Detected Trig Interrupt Mode
  * @{
  * @brief  Macro definitions about PMBUS Slave Stop Detected Trig Interrupt Mode.
  *         This is the data type used for specifying PMBUS which work as Slaver
  *         how to trig a STOP Interrupt when PMBUS detected a STOP.
  */
typedef enum {
    PMBUS_SLAVESTOP_ALWAYS = 0x0U,    /*!< always mode. */
    PMBUS_SLAVESTOP_ADDRONLY          /*!< address match only mode. */
} PMBUS_SlaveStopIntMode;

/**
  * @}
  */

/** @defgroup PMBUS_WORKMODE PMBUS Work Mode
  * @{
  * @brief  Macro definitions about PMBUS Work Mode.
  *         This is the data type used for specifying what mode of PMBUS work.
  */
typedef enum {
    PMBUS_WORK_MASTER = PMBUS_CR_DISSLV_M | PMBUS_CR_MSTEN_M,         /*!< PMBUS work as master mode. */
    PMBUS_WORK_SLAVE = 0x0U                                           /*!< PMBUS work as slave mode. */
} PMBUS_WorkMode;

/**
  * @}
  */

/** @defgroup PMBUS_TXABORT PMBUS Transmission Abort Flag
  * @{
  * @brief  Macro definitions about PMBUS Transmission Abort Flag.
  *         This is the data type used for reporting one or more transmit
  *         transfer aborts.
  *         The value returned by @ref PMBUS_getTxAbortSource() should be compared
  *         to these enumerations to determine what caused the last transfer to abort.
  *
  * @note   If PMBUS_ABORT_SLV_ARBLOST is true, PMBUS_ABORT_ARB_LOST is also
  *         true.  The way to distinguish between slave and master arbitration
  *         loss is to first check PMBUS_ABORT_SLV_ARBLOST (slave arbitration loss)
  *         and then check PMBUS_ABORT_ARB_LOST (master or slave arbitration loss).
  */
typedef enum {
    PMBUS_ABORT_7B_ADDR_NACK    = 0x00000001U,    /*<! Master in 7-bit address mode and the address sent was not acknowledged by any slave. */
    PMBUS_ABORT_10B_ADDR1_NACK  = 0x00000002U,    /*<! Master in 10-bit address mode and the first address byte of the 10-bit address was not acknowledged by the slave. */
    PMBUS_ABORT_10B_ADDR2_NACK  = 0x00000004U,    /*<! Master in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by the slave. */
    PMBUS_ABORT_TXDATA_NACK     = 0x00000008U,    /*<! Master has received an acknowledgement for the address, but when it sent data byte(s) following the address, it did not receive and acknowledge from the remote slave(s). */
    PMBUS_ABORT_GCCALL_NACK     = 0x00000010U,    /*<! Master sent a general call address and no slave on the bus responded with an ack. */
    PMBUS_ABORT_GCCALL_READ     = 0x00000020U,    /*<! Master sent a general call but the user tried to issue a read following this call. */
    PMBUS_ABORT_SBYTE_ACKDET    = 0x00000080U,    /*<! Master sent a start byte and the start byte was acknowledged (wrong behavior). */
    PMBUS_ABORT_SBYTE_NORSTRT   = 0x00000200U,    /*<! The restart is disabled and the user is trying to send a start byte. */
    PMBUS_ABORT_10B_RD_NORSTRT  = 0x00000400U,    /*<! The restart is disabled and the master sends a read command in the 10-bit addressing mode. */
    PMBUS_ABORT_MASTER_DIS      = 0x00000800U,    /*<! User attempted to use disabled master. */
    PMBUS_ABORT_ARB_LOST        = 0x00001000U,    /*<! Arbitration lost. */
    PMBUS_ABORT_SLVFLUSH_TXFIFO = 0x00002000U,    /*<! Slave has received a read command and some data exists in the transmit FIFO so that the slave issues a TX_ABRT to flush old data in the transmit FIFO. */
    PMBUS_ABORT_SLV_ARBLOST     = 0x00005000U,    /*<! Slave lost bus while it is transmitting data to a remote master. */
    PMBUS_ABORT_SLVRD_INTX      = 0x00008000U,    /*<! Slave requests data to transfer and the user issues a read. */
    PMBUS_ABORT_USER_ABORT      = 0x00010000U,    /*<! User set ENABLE.ABORT to 1 */
    PMBUS_ABORT_SDA_LOW         = 0x00020000U     /*<! Master detects the SDA Stuck at low for the PMBUS_SDA_LOW_TIMEOUT value of pmbus_clks. */
} PMBUS_TxAbort;

/**
  * @}
  */

/** @defgroup PMBUS_STATUS PMBUS status
  * @{
  * @brief  Macro definitions about PMBUS status.
  *         This is the data type used for indicating PMBUS status.
  */
#define PMBUS_SR_ACTIVITY              PMBUS_SR_ACTIVITY_M             /*!< PMBUS is in activity state, this state indicates the logic OR of PMBUS_STATU_MST_ACTIVITY and PMBUS_STATU_SLV_ACTIVITY. */
#define PMBUS_SR_TFNF                  PMBUS_SR_TFNF_M                 /*!< PMBUS transmit FIFO not full. */
#define PMBUS_SR_TFE                   PMBUS_SR_TFE_M                  /*!< PMBUS transmit FIFO empty. */
#define PMBUS_SR_RFNE                  PMBUS_SR_RFNE_M                 /*!< PMBUS receive FIFO not empty. */
#define PMBUS_SR_RFF                   PMBUS_SR_RFF_M                  /*!< PMBUS receive FIFO full. */
#define PMBUS_SR_MSTACTY               PMBUS_SR_MSTACTY_M              /*!< PMBUS master is in activity state. */
#define PMBUS_SR_SLVACTY               PMBUS_SR_SLVACTY_M              /*!< PMBUS slave is in activity state. */
#define PMBUS_SR_MSTTFEHD              PMBUS_SR_MSTTFEHD_M             /*!< PMBUS master is in hold state due to transmit FIFO being empty. */
#define PMBUS_SR_MSTRFFHD              PMBUS_SR_MSTRFFHD_M             /*!< PMBUS master is in hold state due to receive FIFO being full. */
#define PMBUS_SR_SLVTFEHD              PMBUS_SR_SLVTFEHD_M             /*!< PMBUS slave is in hold state due to transmit FIFO being empty. */
#define PMBUS_SR_SLVRFFHD              PMBUS_SR_SLVRFFHD_M             /*!< PMBUS slave is in hold state due to receive FIFO being full. */
#define PMBUS_SR_NRECOVER              PMBUS_SR_NRECOVER_M             /*!< SDA Stuck at low is recovered after recovery mechanism. */
#define PMBUS_SR_QC                    PMBUS_SR_QC_M                   /*!< Indicates the R/W bit of the Quick command received.  Clear after read. */
#define PMBUS_SR_AV                    PMBUS_SR_AV_M                   /*!< SMBUS Slave Address is Valid. */
#define PMBUS_SR_AR                    PMBUS_SR_AR_M                   /*!< SMBUS Slave Address is Resolved. */
#define PMBUS_SR_SUSPEND               PMBUS_SR_SUSPEND_M              /*!< SMBUS System is in Suspended mode. */
#define PMBUS_SR_ALERT                 PMBUS_SR_ALERT_M                /*!< SMBUS Alert is asserted. */

/**
  * @}
  */

/** @defgroup PMBUS_INTERRUPT PMBUS Interrupts
  * @{
  * @brief  Macro definitions about PMBUS Interrupts.
  *         This is the data type used for specifying PMBUS interrupts.
  */
#define PMBUS_INT_NONE           (0x0000U)    /*<! Specifies no interrupt. */
#define PMBUS_INT_RX_OVER        (0x0002U)    /*<! Set if the receive FIFO was completely filled and more data arrived.  That data is lost. */
#define PMBUS_INT_RX_FULL        (0x0004U)    /*<! Set when the transmit FIFO reaches or goes above the receive FIFO threshold. It is automatically cleared by hardware when the receive FIFO level goes below the threshold. */
#define PMBUS_INT_TX_EMPTY       (0x0010U)    /*<! Set when the transmit FIFO is at or below the transmit FIFO threshold level. It is automatically cleared by hardware when the transmit FIFO level goes above the threshold. */
#define PMBUS_INT_RD_REQ         (0x0020U)    /*<! Set when the PMBUS is acting as a slave and another PMBUS master is attempting to read data from the slave. */
#define PMBUS_INT_TX_ABRT        (0x0040U)    /*<! In general, this is set when the PMBUS acting as a master is unable to complete a command that the processor has sent. */
#define PMBUS_INT_RX_DONE        (0x0080U)    /*<! When the PMBUS is acting as a slave-transmitter, this is set if the master does not acknowledge a transmitted byte. This occurs on the last byte of the transmission, indicating that the transmission is done. */
#define PMBUS_INT_ACTIVITY       (0x0100U)    /*<! This is set whenever the PMBUS is busy (reading from or writing to the PMBUS bus). */
#define PMBUS_INT_STOP_DET       (0x0200U)    /*<! Indicates whether a stop condition has occurred on the PMBUS bus. */
#define PMBUS_INT_START_DET      (0x0400U)    /*<! Indicates whether a start condition has occurred on the PMBUS bus. */
#define PMBUS_INT_GEN_CALL       (0x0800U)    /*<! Indicates that a general call request was received. The PMBUS stores the received data in the receive FIFO. */
#define PMBUS_INT_RESTART_DET    (0x1000U)    /*<! Indicates whether a re-start condition has occurred on the PMBUS bus. */
#define PMBUS_INT_MST_HOLD       (0x2000U)    /*<! Indicates whether master is holding the bus and TX FIFO is empty. */
#define PMBUS_INT_SCL_LOW        (0x4000U)    /*<! Indicates whether the SCL Line is stuck at low for the IC_SCL_STUCK_LOW_TIMEOUT number of ic_clk periods. */
#define PMBUS_INT_ALL            (0x7fffU)    /*<! Specifies all PMBUS interrupts.  This combined enumeration that can be used with some functions such as PMBUS_clearInterrupt(), PMBUS_maskInterrupt(), and so on. */

/**
  * @}
  */

/** @defgroup PMBUS_SMBUS_INTERRUPT PMBUS SMBUS Interrupts
  * @{
  * @brief  Macro definitions about PMBUS SMBUS Interrupts.
  *         This is the data type used for specifying PMBUS SMBUS interrupts.
  */
#define PMBUS_SMBUS_INT_NONE                (0x0000U)    /*<! Specifies no interrupt. */
#define PMBUS_SMBUS_INT_SEXT_TIMEOUT        (0x0001U)    /*<! Indicates whether the transaction from Slave (i.e from START to STOP) exceeds IC_SMBUS_CLK_LOW_SEXT time. */
#define PMBUS_SMBUS_INT_MEXT_TIMEOUT        (0x0002U)    /*<! Indicates whether the Master device transaction (START-to-ACK, ACK-to-ACK, or ACK-to-STOP) from START to STOP exceeds IC_SMBUS_CLOCK_LOW_MEXT time with in each byte of message. */
#define PMBUS_SMBUS_INT_QUICKCMD_DET        (0x0004U)    /*<! Indicates whether a Quick command has been received on the SMBus interface regardless of whether PMBUS is operating in slave or master mode. */
#define PMBUS_SMBUS_INT_ARP_NOTIFY_DET      (0x0008U)    /*<! Indicates whether a Notify ARP Master ARP command has been received. */
#define PMBUS_SMBUS_INT_ARP_PRE_DET         (0x0010U)    /*<! Indicates whether a prepare to ARP command has been received. */
#define PMBUS_SMBUS_INT_ARP_RST_DET         (0x0020U)    /*<! Indicates whether a General or Directed Reset ARP command has been received. */
#define PMBUS_SMBUS_INT_ARP_UDIDCMD_DET     (0x0040U)    /*<! Indicates whether a Get UDID ARP command has been received. */
#define PMBUS_SMBUS_INT_ARP_ASSGNCMD_DET    (0x0080U)    /*<! Indicates whether an Assign Address ARP command has been received. */
#define PMBUS_SMBUS_INT_ARP_PEC_NACK        (0x0100U)    /*<! Indicates whether a NACK has been sent due to PEC mismatch while working as ARP slave. */
#define PMBUS_SMBUS_INT_SUSPEND             (0x0200U)    /*<! Indicates whether a SMBSUS signal is driven low by the Host. */
#define PMBUS_SMBUS_INT_ALERT               (0x0400U)    /*<! Indicates whether a SMBALERT signal is driven low by the slave. */
#define PMBUS_SMBUS_INT_ALL                 (0x07ffU)    /*<! Specifies all interrupts. */

/**
  * @}
  */

/** @defgroup PMBUS_CMD PMBUS Command for TxFIFO
  * @{
  * @brief  Macro definitions about PMBUS Command for TxFIFO.
  *         This is the data type used for specifying PMBUS Command for TxFIFO.
  */
#define PMBUS_CMD_WRITE      (0x0000U)    /*<! Indicates write perform */
#define PMBUS_CMD_READ       (0x0100U)    /*<! Indicates read perform */
#define PMBUS_CMD_STOP       (0x0200U)    /*<! Indicates whether a STOP is issued after the byte is sent or received. */
#define PMBUS_CMD_RESTART    (0x0400U)    /*<! Indicates whether a RESTART is issued before the byte is sent or received. */

/**
  * @}
  */

/**
  * @brief Values Mask for All PMBUS TxAbort Source.
  */
#define PMBUS_TXABTSRC_ALL                                                                       \
        (PMBUS_TXABTSRC_NAK7B_M    | PMBUS_TXABTSRC_NAK10B1_M    | PMBUS_TXABTSRC_NAK10B2_M    | \
         PMBUS_TXABTSRC_TXNAK_M    | PMBUS_TXABTSRC_GCNAK_M      | PMBUS_TXABTSRC_GCREAD_M     | \
         PMBUS_TXABTSRC_SBYTEACK_M | PMBUS_TXABTSRC_NRSTASBYTE_M | PMBUS_TXABTSRC_NRSTA10BRD_M | \
         PMBUS_TXABTSRC_MSTDIS_M   | PMBUS_TXABTSRC_ARBLOST_M    | PMBUS_TXABTSRC_SLVFLUSH_M   | \
         PMBUS_TXABTSRC_SLVARB_M   | PMBUS_TXABTSRC_SLVRD_M      | PMBUS_TXABTSRC_ABRT_M       | \
         PMBUS_TXABTSRC_SDALOW_M)

/**
  * @brief Constant Values for FIFOs Depth.
  */
#define PMBUS_TXFIFO_DEPTH    (16U)
#define PMBUS_RXFIFO_DEPTH    (16U)

/** @defgroup PMBUS_DMA PMBUS DMA
  * @{
  * @brief  Macro definitions about PMBUS DMA.
  *         This is the data type used for specifying PMBUS DMA.
  */
#define PMBUS_DMA_TX    PMBUS_DCR_TXEN_M
#define PMBUS_DMA_RX    PMBUS_DCR_RXEN_M

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
  * \brief  This function enables the PMBUS.
  * \param  pmbus   Base address of PMBUS module.
  */
static inline void PMBUS_enable (PMBUS_TypeDef *pmbus)
{
    MODIFY_REG(pmbus->ENR.WORDVAL, PMBUS_ENR_TXBLOCK_M, PMBUS_ENR_EN_M);
}

/**
  * \brief  This functions disables the PMBUS
  * \param  pmbus   Base address of PMBUS module.
  * \note   It should be not busy (determined by the activity interrupt bit).
  */
static inline void PMBUS_disable (PMBUS_TypeDef *pmbus)
{
    WRITE_REG(pmbus->ENR.WORDVAL, PMBUS_ENR_TXBLOCK_M);
}

/**
  * \brief  This function sets the speed mode used for PMBUS transfers.
  * \param  pmbus   Base address of PMBUS module.
  * \param  mode    The speed mode to set.  This parameter can have one
  *                 enumeration value from @ref PMBUS_SPEEDMODE.
  * \note   The PMBUS must be disabled in order to change the speed mode.
  */
static inline void PMBUS_setSpeedMode (PMBUS_TypeDef *pmbus, PMBUS_SpeedMode mode)
{
    WRITE_REG(pmbus->CR.BIT.SPEED, mode);
}

/**
  * \brief  This function sets the master addressing mode (7-bit or 10-bit).
  * \param  pmbus   Base address of PMBUS module.
  * \param  mode    The addressing mode to set.  This parameter can have one
  *                 enumeration value from @ref PMBUS_ADDRESSMODE.
  * \note   The PMBUS must be disabled in order to change the master addressing
  *         mode.
  */
static inline void PMBUS_setMasterAddressMode (PMBUS_TypeDef *pmbus, PMBUS_AddressMode mode)
{
    WRITE_REG(pmbus->TAR.BIT.MSTFMT, mode);
}

/**
  * \brief  This function sets the PMBUS slave addressing mode (7-bit or 10-bit).
  * \param  pmbus   Base address of PMBUS module.
  * \param  mode    The addressing mode to set.  This parameter can have one
  *                 enumeration value from @ref PMBUS_ADDRESSMODE.
  * \note   The PMBUS must be disabled in order to change the slave addressing
  *         mode.
  */
static inline void PMBUS_setSlaveAddressMode (PMBUS_TypeDef *pmbus, PMBUS_AddressMode mode)
{
    WRITE_REG(pmbus->CR.BIT.SLVFMT, mode);
}

/**
  * \brief  This function sets the target address used by the PMBUS master.  When
  *         not issuing a general call or using a start byte, this is the
  *         address the master uses when performing transfers over the PMBUS bus.
  * \param  pmbus   Base address of PMBUS module.
  * \param  mode    Target address to set.
  * \note   The PMBUS must be disabled in order to set the target address.  Only
  *         the 10 least significant bits of the address are relevant.
  */
static inline void PMBUS_setTargetAddress (PMBUS_TypeDef *pmbus, uint16_t address)
{
    WRITE_REG(pmbus->TAR.BIT.ADDR, address);
}

/**
  * \brief  This function returns the current target address in use by the PMBUS
  *         master.
  * \param  pmbus   Base address of PMBUS module.
  * \return The current target address.
  */
static inline uint16_t PMBUS_getTargetAddress (PMBUS_TypeDef *pmbus)
{
    return READ_REG(pmbus->TAR.BIT.ADDR);
}

/**
  * \brief  This function enables the use of restart conditions.
  * \param  pmbus   Base address of PMBUS module.
  * \note   The PMBUS must be disabled in order to enable restart conditions.
  */
static inline void PMBUS_enableRestart (PMBUS_TypeDef *pmbus)
{
    WRITE_REG(pmbus->CR.BIT.RESTARTEN, ENABLE);
}

/**
  * \brief  This function disables the use of restart conditions.
  * \param  pmbus   Base address of PMBUS module.
  * \note   The PMBUS must be disabled in order to disable restart conditions.
  */
static inline void PMBUS_disableRestart (PMBUS_TypeDef *pmbus)
{
    WRITE_REG(pmbus->CR.BIT.RESTARTEN, DISABLE);
}

/**
  * \brief  This function sets the PMBUS module work mode weather Master or Slaver.
  * \param  pmbus   Base address of PMBUS module.
  * \param  mode    Work mode to set.  This parameter can have one
  *                 enumeration value from @ref PMBUS_WORKMODE.
  * \note   The PMBUS must be disabled in order to set the work mode.
  */
static inline void PMBUS_setWorkMode (PMBUS_TypeDef *pmbus, PMBUS_WorkMode mode)
{
    MODIFY_REG(
        pmbus->CR.WORDVAL,
        PMBUS_CR_DISSLV_M | PMBUS_CR_MSTEN_M,
        mode);
}

/**
  * \brief  This function sets the master transmit mode.  That is, whether to
  *         use a start byte, general call, or the programmed target address.
  * \param  pmbus   Base address of PMBUS module.
  * \param  mode    transfer mode to set.  This parameter can have one
  *                 enumeration value from @ref PMBUS_TXMODE.
  * \note   The PMBUS must be disabled in order to set the master transmit mode.
  */
static inline void PMBUS_setTxMode (PMBUS_TypeDef *pmbus, PMBUS_TxMode mode)
{
    MODIFY_REG(
        pmbus->TAR.WORDVAL,
        PMBUS_TAR_GC_M | PMBUS_TAR_SP_M,
        mode << PMBUS_TAR_GC_S);
}

/**
  * \brief  This function sets the slave address to which the PMBUS slave
  *         responds, when enabled.
  * \param  pmbus   Base address of PMBUS module.
  * \param  address Slave address to set.
  * \note   The PMBUS must be disabled in order to set the target address.  Only
  *         the 10 least significant bits of the address are relevant.
  */
static inline void PMBUS_setSlaveAddress (PMBUS_TypeDef *pmbus, uint16_t address)
{
    WRITE_REG(pmbus->SAR.WORDVAL, address);
}

/**
  * \brief  This function sets slave stop interrupt mode, when enabled.
  * \param  pmbus   Base address of PMBUS module.
  * \param  mode    Slave stop interrupt mode to set.  This parameter can have one
  *                 enumeration value from @ref PMBUS_SLAVE_STOP_INT_MODE.
  * \note   The PMBUS must be disabled in order to set the slave STOP interrupt mode.
  */
static inline void PMBUS_setSlaveStopIntMode (PMBUS_TypeDef *pmbus, PMBUS_SlaveStopIntMode mode)
{
    WRITE_REG(pmbus->CR.BIT.SLVSTOPINT, mode << PMBUS_CR_SLVSTOPINT_S);
}

/**
  * \brief  This function Sets the required SDA hold time in units of pmbus_clk period.
  * \param  pmbus   Base address of PMBUS module.
  * \param  tx_hold SDA hold time to set, when PMBUS acts as a transmitter.
  *                 The valid range for this parameter is 0x00 to 0xFF.​
  * \param  rx_hold SDA hold time to set, when PMBUS acts as a receiver.
  *                 The valid range for this parameter is 0x00 to 0xFFFF.​
  * \note   The PMBUS must be disabled in order to set the SDA hold time.
  */
static inline void PMBUS_setSDAHoldTime (PMBUS_TypeDef *pmbus, uint8_t tx_hold, uint16_t rx_hold)
{
    rx_hold &= PMBUS_SDAVHD_RXHD_M >> PMBUS_SDAVHD_RXHD_S;
    WRITE_REG(pmbus->SDAVHD.WORDVAL,
        (uint32_t)(rx_hold << PMBUS_SDAVHD_RXHD_S) | (uint32_t)(tx_hold << PMBUS_SDAVHD_TXHD_S));
}

/**
  * \brief  This function writes a single byte to the PMBUS transmit FIFO.
  * \param  pmbus       Base address of PMBUS module.
  * \param  character   Byte to write to FIFO.
  * \note   This function does not check whether the PMBUS FIFO is full or not
  *         before writing to it.  As such, it can result in a transmit FIFO
  *         overflow if used improperly.
  */
static inline void PMBUS_write (PMBUS_TypeDef *pmbus, uint8_t character)
{
    WRITE_REG(pmbus->DATA.WORDVAL, character);
}

/**
  * \brief  This function writes a read command to the PMBUS transmit FIFO.  This
  *         is used during master-receiver/slave-transmitter transfers and is
  *         typically followed by a read from the master receive FIFO after the
  *         slave responds with data.
  * \param  pmbus   Base address of PMBUS module.
  * \note   This function does not check whether the PMBUS FIFO is full or not
  *         before writing to it.  As such, it can result in a transmit FIFO
  *         overflow if used improperly.
  */
static inline void PMBUS_issueRead (PMBUS_TypeDef *pmbus)
{
    WRITE_REG(pmbus->DATA.WORDVAL, PMBUS_DATA_CMD_M);
}

/**
  * \brief  This function writes togather a single byte with a command to the PMBUS
  *         transmit FIFO.  This could write a single byte with a specified
  *         Command such as stop or restart to the PMBUS transmit FIFO.  This also
  *         can issue a read command, which replaces @ref PMBUS_issueRead(),
  *         by command \b PMBUS_CMD_READ from @ref PMBUS_CMD.
  * \param  pmbus       Base address of PMBUS module.
  * \param  cmd_data    A single byte with command, which to write to FIFO. Here command
  *                     can have one enumeration value from @ref PMBUS_CMD.
  * \note   This function does not check whether the PMBUS FIFO is full or not
  *         before writing to it.  As such, it can result in a transmit FIFO
  *         overflow if used improperly.
  */
static inline void PMBUS_writeCmd (PMBUS_TypeDef *pmbus, uint16_t cmd_data)
{
    WRITE_REG(pmbus->DATA.WORDVAL, cmd_data);
}

/**
  * \brief  This function reads a single byte from the PMBUS receive FIFO.
  * \param  pmbus   Base address of PMBUS module.
  * \return The character read from the PMBUS FIFO.
  * \note   This function also does not check whether there is valid data or not
  *         in the FIFO beforehand.  As such, it can cause an receive underflow
  *         error if used improperly.
  */
static inline uint8_t PMBUS_read (PMBUS_TypeDef *pmbus)
{
    return READ_REG(pmbus->DATA.BIT.DATA);
}

/**
  * \brief  This function abort a master transfer.
  *         After call this function, PMBUS master will generate a STOP to
  *         abort this transfer, than clear all the transmit FIFO.
  * \param  pmbus   Base address of PMBUS module.
  * \note   The software can only configure this when the ENABLE bit has been set.
  */
static inline void PMBUS_abort (PMBUS_TypeDef *pmbus)
{
    WRITE_REG(pmbus->ENR.BIT.ABT, ENABLE);
}

/**
  * \brief  This function returns module's Status.
  * \param  pmbus   Base address of PMBUS module.
  * \return PMBUS module Status, which is a bitwise OR combination of one or more
  *         values from the @ref PMBUS_STATUS.
  */
static inline uint32_t PMBUS_getStatus (PMBUS_TypeDef *pmbus)
{
    return (uint32_t)READ_REG(pmbus->SR.WORDVAL);
}

/**
  * \brief  This function returns the number of valid data entries currently
  *         present in the receiver FIFO.
  * \param  pmbus   base address of PMBUS module.
  * \return Number of valid data entries in the receive FIFO.
  */
static inline uint16_t PMBUS_getRxFifoLevel (PMBUS_TypeDef *pmbus)
{
    return READ_REG(pmbus->RFL.WORDVAL);
}

/**
  * \brief  This function returns the number of valid data entries currently
  *         present in the transmit FIFO.
  * \param  pmbus   base address of PMBUS module.
  * \return Number of valid data entries in the transmit FIFO.
  */
static inline uint16_t PMBUS_getTxFifoLevel (PMBUS_TypeDef *pmbus)
{
    return READ_REG(pmbus->TFL.WORDVAL);
}

/**
  * \brief  This function sets the threshold level for the transmit FIFO.  When
  *         the number of data entries in the transmit FIFO is at or below this
  *         level, the tx_empty interrupt is triggered.
  * \param  pmbus   Base address of PMBUS module.
  * \param  level   Level at which to set threshold.
  */
static inline void PMBUS_setTxThreshold (PMBUS_TypeDef *pmbus, uint8_t level)
{
    WRITE_REG(pmbus->TFTL.WORDVAL, level << PMBUS_TFTL_TX_TL_S);
}

/**
  * \brief  This function returns the current threshold level for the transmit
  *         FIFO.
  * \param  pmbus   Base address of PMBUS module.
  * \return The transmit FIFO threshold level.
  */
static inline uint8_t PMBUS_getTxThreshold (PMBUS_TypeDef *pmbus)
{
    return (uint8_t)READ_REG(pmbus->TFTL.WORDVAL);
}

/**
  * \brief  This function sets the threshold level for the receive FIFO.  When
  *         the number of data entries in the receive FIFO is at or above this
  *         level, the rx_full interrupt is triggered.
  * \param  pmbus   Base address of PMBUS module.
  * \param  level   Level at which to set threshold.
  */
static inline void PMBUS_setRxThreshold (PMBUS_TypeDef *pmbus, uint8_t level)
{
    WRITE_REG(pmbus->RFTL.WORDVAL, level << PMBUS_RFTL_RX_TL_S);
}

/**
  * \brief  This function returns the current threshold level for the receive
  *         FIFO.
  * \param  pmbus   Base address of PMBUS module.
  * \return The receive FIFO threshold level.
  */
static inline uint8_t PMBUS_getRxThreshold (PMBUS_TypeDef *pmbus)
{
    return (uint8_t)READ_REG(pmbus->RFTL.WORDVAL);
}

/**
  * \brief  Enable Tx/Rx DMA.
  * \param  pmbus       Base address of PMBUS module.
  * \param  dmaRequest  DMA request mask.
  *                     This parameter takes a bitwise OR combination of one or more
  *                     values from the  @ref PMBUS_DMA.
  */
static inline void PMBUS_enableDMA (PMBUS_TypeDef *pmbus, uint32_t dmaRequest)
{
    SET_BIT(pmbus->DCR.WORDVAL, dmaRequest);
}

/**
  * \brief  Disable Tx/Rx DMA.
  * \param  pmbus       Base address of PMBUS module.
  * \param  dmaRequest  DMA request mask.
  *                     This parameter takes a bitwise OR combination of one or more
  *                     values from the  @ref PMBUS_DMA.
  */
static inline void PMBUS_disableDMA (PMBUS_TypeDef *pmbus, uint32_t dmaRequest)
{
    CLEAR_BIT(pmbus->DCR.WORDVAL, dmaRequest);
}

/**
  * \brief  Disable specified Interrupt(s).
  * \param  pmbus       Base address of PMBUS module.
  * \param  interrupts  interrupt(s) to enable.
  *                     This parameter takes a bitwise OR combination of one or more
  *                     values from the @ref PMBUS_INTERRUPT.
  */
static inline void PMBUS_disableInterrupt (PMBUS_TypeDef *pmbus, uint32_t interrupts)
{
    CLEAR_BIT(pmbus->IMR.WORDVAL, interrupts);
}

/**
  * \brief  Enable specified Interrupt(s).
  * \param  pmbus       Base address of PMBUS module.
  * \param  interrupts  interrupt(s) to enable.
  *                     This parameter takes a bitwise OR combination of one or more
  *                     values from the @ref PMBUS_INTERRUPT.
  */
static inline void PMBUS_enableInterrupt (PMBUS_TypeDef *pmbus, uint32_t interrupts)
{
    SET_BIT(pmbus->IMR.WORDVAL, interrupts);
}

/**
  * \brief  Returns enabled Interrupt(s).  For each bitfield, a value of
  *         '0' indicates that an interrupt is masked while a value of '1'
  *         indicates that an interrupt is enabled.
  * \param  pmbus   Base address of PMBUS module.
  * \return Enabled interrupt(s).  A bitwise OR combination of one or more
  *         values from the @ref PMBUS_INTERRUPT.
  */
static inline uint32_t PMBUS_getEnabledInterrupt (PMBUS_TypeDef *pmbus)
{
    return (uint32_t)READ_REG(pmbus->IMR.WORDVAL);
}

/**
  * \brief  Returns the current masked interrupt status.  For each bitfield, a value of
  *         '0' indicates that an interrupt is not active while a value of '1'
  *         indicates that an interrupt is active.
  * \param  pmbus   Base address of PMBUS module.
  * \return Current masked interrupt status.
  *         This value takes a bitwise OR combination of one or more
  *         values from the @ref PMBUS_INTERRUPT.
  */
static inline uint32_t PMBUS_getMaskedInterruptStatus (PMBUS_TypeDef *pmbus)
{
    return READ_REG(pmbus->ISR.WORDVAL);
}

/**
  * \brief  Returns the current raw interrupt status.  For each bitfield, a value
  *         of '0' indicates that an raw interrupt is not active while a value
  *         of '1' indicates that an raw interrupt is active.
  * \param  pmbus   Base address of PMBUS module.
  * \return Current raw interrupt status.
  *         This value takes a bitwise OR combination of one or more
  *         values from the @ref PMBUS_INTERRUPT.
  */
static inline uint32_t PMBUS_getInterruptStatus (PMBUS_TypeDef *pmbus)
{
    return READ_REG(pmbus->RISR.WORDVAL);
}

/**
  * \brief  Clears single PMBUS interrupt status of RXOVER.
  * \param  pmbus   Base address of PMBUS module.
  */
static inline void PMBUS_clearInterruptStatusRXOVER (PMBUS_TypeDef *pmbus)
{
    READ_REG(pmbus->CLRRXOV.WORDVAL);
}

/**
  * \brief  Clears single PMBUS interrupt status of RDREQ.
  * \param  pmbus   Base address of PMBUS module.
  */
static inline void PMBUS_clearInterruptStatusRDREQ (PMBUS_TypeDef *pmbus)
{
    READ_REG(pmbus->CLRREQ.WORDVAL);
}

/**
  * \brief  Clears single PMBUS interrupt status of TXABORT.
  * \param  pmbus   Base address of PMBUS module.
  */
static inline void PMBUS_clearInterruptStatusTXABORT (PMBUS_TypeDef *pmbus)
{
    READ_REG(pmbus->CLRTXABT.WORDVAL);
}

/**
  * \brief  Clears single PMBUS interrupt status of RXDONE.
  * \param  pmbus   Base address of PMBUS module.
  */
static inline void PMBUS_clearInterruptStatusRXDONE (PMBUS_TypeDef *pmbus)
{
    READ_REG(pmbus->CLRRXDO.WORDVAL);
}

/**
  * \brief  Clears single PMBUS interrupt status of ACTIVITY.
  * \param  pmbus   Base address of PMBUS module.
  */
static inline void PMBUS_clearInterruptStatusACTIVITY (PMBUS_TypeDef *pmbus)
{
    READ_REG(pmbus->CLRACTY.WORDVAL);
}

/**
  * \brief  Clears single PMBUS interrupt status of STOP.
  * \param  pmbus   Base address of PMBUS module.
  */
static inline void PMBUS_clearInterruptStatusSTOP (PMBUS_TypeDef *pmbus)
{
    READ_REG(pmbus->CLRSTOP.WORDVAL);
}

/**
  * \brief  Clears single PMBUS interrupt status of START.
  * \param  pmbus   Base address of PMBUS module.
  */
static inline void PMBUS_clearInterruptStatusSTART (PMBUS_TypeDef *pmbus)
{
    READ_REG(pmbus->CLRSTART.WORDVAL);
}

/**
  * \brief  Clears single PMBUS interrupt status of GC.
  * \param  pmbus   Base address of PMBUS module.
  */
static inline void PMBUS_clearInterruptStatusGC (PMBUS_TypeDef *pmbus)
{
    READ_REG(pmbus->CLRGC.WORDVAL);
}

/**
  * \brief  Clears single PMBUS interrupt status of RESTART.
  * \param  pmbus   Base address of PMBUS module.
  */
static inline void PMBUS_clearInterruptStatusRESTART (PMBUS_TypeDef *pmbus)
{
    READ_REG(pmbus->CLRRESTART.WORDVAL);
}

/**
  * \brief  Clears single PMBUS interrupt status of SCLLOW.
  * \param  pmbus   Base address of PMBUS module.
  */
static inline void PMBUS_clearInterruptStatusSCLLOW (PMBUS_TypeDef *pmbus)
{
    READ_REG(pmbus->CLRSCLL.WORDVAL);
}

/**
  * \brief  This function returns the current value of the PMBUS transmit abort
  *         status register.
  *         The transmit abort status register is cleared by the PMBUS upon
  *         reading.  Note that it is possible for more than one bit of this
  *         register to be active simultaneously and this should be dealt with
  *         properly by any function operating on this return value.
  * \param  pmbus   Base address of PMBUS module.
  * \return The current transmit abort status.
  * \note   The transmit abort status register is cleared by the PMBUS upon
  *         reading.  Note that it is possible for more than one bit of this
  *         register to be active simultaneously and this should be dealt with
  *         properly by any function operating on this return value.
  */
static inline PMBUS_TxAbort PMBUS_getTxAbortSource (PMBUS_TypeDef *pmbus)
{
    return (PMBUS_TxAbort)(READ_REG(pmbus->TXABTSRC.WORDVAL) & PMBUS_TXABTSRC_ALL);
}

/**
  * \brief  This function sets SCL Low SEXT count.
  *         This is used to detect the Slave Clock Extend timeout (tLOW:SEXT)
  *         in master mode extended by the slave device in one message from the
  *         initial START to the STOP.
  * \param  pmbus   Base address of PMBUS module.
  * \param  count   value to set.  This parameter is in units of
  *         ic_clk period, and valid arrange for it is 0x00000000 to 0xFFFFFFFF.
  * \note   The PMBUS must be disabled in order to set the SCL Low SEXT.
  */
static inline void PMBUS_setSMBUSTLOWSEXT (PMBUS_TypeDef *pmbus, uint32_t count)
{
    WRITE_REG(pmbus->SEXT.WORDVAL, count);
}

/**
  * \brief  This function sets SCL Low MEXT count.
  *         This is used to detect the Master extend SMBus clock (SCLK) timeout
  *         defined from START-to-ACK, ACK-to-ACK, or ACK-to-STOP in Master mode.
  * \param  pmbus   Base address of PMBUS module.
  * \param  count   value to set.  This parameter is in units of
  *         ic_clk period, and valid arrange for it is 0x00000000 to 0xFFFFFFFF.
  * \note   The PMBUS must be disabled in order to set the SCL Low MEXT.
  */
static inline void PMBUS_setSMBUSTLOWMEXT (PMBUS_TypeDef *pmbus, uint32_t count)
{
    WRITE_REG(pmbus->MEXT.WORDVAL, count);
}

/**
  * \brief  This function sets SMBUS Master THigh MAX Bus-idle count.
  *         This is used to set the required Bus-Idle time period used when a master
  *         has been dynamically added to the bus and may not have detected a state
  *         transition on the SMBCLK or SMBDAT lines.  In this case, the master
  *         must wait long enough to ensure that a transfer is not currently in
  *         progress.
  * \param  pmbus   Base address of PMBUS module.
  * \param  count   value to set.  This parameter is in units of ic_clk period,
  *         and valid arrange for it is 0x0000 to 0xFFFF.
  * \note   The PMBUS must be disabled in order to set the SMBUS Master THigh
  *         MAX Bus-idle count.
  */
static inline void PMBUS_setSMBUSTHighMaxBusIdleCount (PMBUS_TypeDef *pmbus, uint32_t count)
{
    WRITE_REG(pmbus->IDLECNT.WORDVAL, count);
}

/**
  * \brief  This function enable specified SMBUS Interrupt(s).
  * \param  pmbus   Base address of PMBUS module.
  * \param  SMBUSInterrupts
  *                 Interrupts to enable.
  *                 This parameter takes a bitwise OR combination of one or more
  *                 values from the @ref PMBUS_SMBUS_INTERRUPT.
  */
static inline void PMBUS_enableSMBUSInterrupt (PMBUS_TypeDef *pmbus, uint32_t SMBUSInterrupts)
{
    SET_BIT(pmbus->SMBIMR.WORDVAL, SMBUSInterrupts);
}

/**
  * \brief  This function disable specified SMBUS Interrupt(s).
  * \param  pmbus   Base address of PMBUS module.
  * \param  SMBUSInterrupts
  *                 Interrupts to disable.
  *                 This parameter takes a bitwise OR combination of one or more
  *                 values from the @ref PMBUS_SMBUS_INTERRUPT.
  */
static inline void PMBUS_disableSMBUSInterrupt (PMBUS_TypeDef *pmbus, uint32_t SMBUSInterrupts)
{
    CLEAR_BIT(pmbus->SMBIMR.WORDVAL, SMBUSInterrupts);
}

/**
  * \brief  Returns the current masked SMBUS interrupt status.
  *         For each bitfield, a value of '0' indicates that an interrupt is
  *         not active while a value of '1' indicates that an interrupt is active.
  * \param  pmbus   Base address of PMBUS module.
  * \return Current masked SMBUS interrupt status.
  *         This value takes a bitwise OR combination of one or more
  *         values from the @ref PMBUS_SMBUS_INTERRUPT.
  */
static inline uint32_t PMBUS_getSMBUSMaskedInterruptStatus (PMBUS_TypeDef *pmbus)
{
    return READ_REG(pmbus->ISR.WORDVAL);
}

/**
  * \brief  Returns the current SMBUS raw interrupt status.
  *         For each bitfield, a value of '0' indicates that an interrupt is
  *         not active while a value of '1' indicates that an interrupt is active.
  * \param  pmbus   Base address of PMBUS module.
  * \return Current SMBUS raw interrupt status.
  *         This value takes a bitwise OR combination of one or more
  *         values from the @ref PMBUS_SMBUS_INTERRUPT.
  */
static inline uint32_t PMBUS_getSMBUSInterruptStatus (PMBUS_TypeDef *pmbus)
{
    return READ_REG(pmbus->RISR.WORDVAL);
}

/**
  * \brief  Clears specified PMBUS SMBUS interrupt(s).
  * \param  pmbus   Base address of PMBUS module.
  * \param  SMBUSInterrupts
  *                 SMBUS interrupts to clear.
  *                 This parameter takes a bitwise OR combination of one or more
  *                 values from the @ref PMBUS_SMBUS_INTERRUPT.
  */
static inline void PMBUS_clearSMBUSInterruptStatus (PMBUS_TypeDef *pmbus, uint32_t SMBUSInterrupts)
{
    WRITE_REG(pmbus->SMBICR.WORDVAL, SMBUSInterrupts);
}

/**
  * \brief  This function sets optional Slave Address.
  * \param  pmbus   Base address of PMBUS module.
  * \param  address 7bit valid slave address to set.
  * \note   The PMBUS must be disabled in order to set the target address.  Only
  *         the 7 least significant bits of the address are relevant.
  */
static inline void PMBUS_setOptionSlaveAddress (PMBUS_TypeDef *pmbus, uint8_t address)
{
    WRITE_REG(pmbus->OSAR.WORDVAL, address & 0x7FU);
}

/**
  * \brief  This function sets the 128bit value of slave unique device identifier
  *         used in Address Resolution Protocol.
  * \param  pmbus   Base address of PMBUS module.
  * \param  UDID    Pointer to 4 word array.
  * \note   The PMBUS must be disabled in order to set the UDID.
  */
static inline void PMBUS_setARPUDID (PMBUS_TypeDef *pmbus, uint32_t *UDID)
{
    WRITE_REG(pmbus->UDID0.WORDVAL, UDID[0]);
    WRITE_REG(pmbus->UDID1.WORDVAL, UDID[1]);
    WRITE_REG(pmbus->UDID2.WORDVAL, UDID[2]);
    WRITE_REG(pmbus->UDID3.WORDVAL, UDID[3]);
}

/**
  * \brief  Clears specified PMBUS interrupt(s).  Only the following interrupts
  *         can be cleared in this fashion: rx_under, rx_over, tx_over, rd_req,
  *         tx_abrt, rx_done, activity, stop_det, start_det, gen_call.  Although
  *         they can be specified, the tx_empty interrupts cannot be
  *         cleared using this function.
  * \param  pmbus       Base address of PMBUS module.
  * \param  interrupts  Interrupt(s) to clear.
  *                     This parameter takes a bitwise OR combination of one or more
  *                     values from the @ref PMBUS_INTERRUPT.
  */
extern void PMBUS_clearInterruptStatus (PMBUS_TypeDef *pmbus, uint32_t interrupts);

/**
  * \brief  This function set the scl count value for a particular speed mode
  *          (standard, fast) and clock phase (low, high).
  * \param  pmbus   Base address of PMBUS module.
  * \param  mode    Speed mode of count value to set.  This parameter can have one
  *                 enumeration value from @ref PMBUS_SPEEDMODE.
  * \param  phase   SCL phase of count value to set.  This parameter can have one
  *                 enumeration value from @ref PMBUS_SCLPHASE.
  * \param  count   Count value to set.
  * @note   The PMBUS must be disabled in order to set any of the scl count
  *         values.  The programmable value for any of these count
  *         shown below:
  *         ______________________________________________________
  *         | PMBUS_SpeedMode | PMBUS_SclPhase | minimum | maximum |
  *         |        X        | PMBUS_SCL_HIGH |    6    | 0xFFF5  |
  *         |        X        | PMBUS_SCL_LOW  |    8    | 0xFFF5  |
  *         ------------------------------------------------------
  */
extern void PMBUS_setSclCount (PMBUS_TypeDef *pmbus,PMBUS_SpeedMode mode, PMBUS_SclPhase phase, uint16_t count);

/**
  * \brief  This function returns the current scl count value for all speed
  *         modes (standard, fast, high) and phases (low, high).
  * \param  pmbus   Base address of PMBUS module.
  * \param  mode    Speed mode of count value to set.  This parameter can have one
  *                 enumeration value from @ref PMBUS_SPEEDMODE.
  * \param  phase   SCL phase of count value to set.  This parameter can have one
  *                 enumeration value from @ref PMBUS_SCLPHASE.
  * \return The current specified scl count value.
  */
extern uint16_t PMBUS_getSclCount (PMBUS_TypeDef *pmbus,PMBUS_SpeedMode mode, PMBUS_SclPhase phase);


#ifdef __cplusplus
}
#endif


#endif    /* __PMBUS_H__ */
