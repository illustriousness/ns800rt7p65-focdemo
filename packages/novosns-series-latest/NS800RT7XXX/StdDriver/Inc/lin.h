/**
  * @file       lin.h
  * @author     Alex-J
  * @brief      Header file for NS800RTxxx lin module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __LIN_H__
#define __LIN_H__

#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/** @defgroup LIN_EXPORTED_TYPES LIN Exported Types
 * @{
 * @brief  Macro definitions are used with all files publicly about 'LIN' module.
 */

/** @defgroup LIN_MODESELECT LIN Module Master or Slave Mode Select
 * @{
 * @brief  Values are used to configure LIN to work in master or slave mode.
 */
typedef enum {
    LIN_SLAVE_MODE = 0x0U,    /*!< LIN module master mode */
    LIN_MASTER_MODE           /*!< LIN module slave mode */
} LIN_ModeSelect;

/**
 * @}
 */

/** @defgroup LIN_BUFFERLOCKMODE LIN Module Receive Buffer Lock Mode
 * @{
 * @brief  Values are used to configure LIN to work in receive buffer lock
 *         mode.
 */
typedef enum {
    LIN_RECV_BUFF_UNLOCK = 0x0U,    /*!< LIN receive buffer unlock */
    LIN_RECV_BUFF_LOCK              /*!< LIN receive buffer lock */
} LIN_BufferLockMode;

/**
 * @}
 */

/** @defgroup LIN_SLAVEBREAKLEN LIN Module Slave Break Length
 * @{
 * @brief  Values are used to configure the break length of the slave.
 */
typedef enum {
    LIN_SLV_BREAK_LEN_11_BIT = 0x0U,    /*!< LIN slave break 11 bits length */
    LIN_SLV_BREAK_LEN_10_BIT            /*!< LIN slave break 10 bits length */
} LIN_SlaveBreakLen;

/**
 * @}
 */

/** @defgroup LIN_MSTBREAKLEN LIN Module Master Break Length
 * @{
 * @brief  Values ​​are the break lengths controlled in LIN master mode.
 */
typedef enum {
    LIN_BREAK_10_BIT = 0x00U,    /*!< LIN break 10 bits length */
    LIN_BREAK_11_BIT,            /*!< LIN break 11 bits length */
    LIN_BREAK_12_BIT,            /*!< LIN break 12 bits length */
    LIN_BREAK_13_BIT,            /*!< LIN break 13 bits length */
    LIN_BREAK_14_BIT,            /*!< LIN break 14 bits length */
    LIN_BREAK_15_BIT,            /*!< LIN break 15 bits length */
    LIN_BREAK_16_BIT,            /*!< LIN break 16 bits length */
    LIN_BREAK_17_BIT,            /*!< LIN break 17 bits length */
    LIN_BREAK_18_BIT,            /*!< LIN break 18 bits length */
    LIN_BREAK_19_BIT,            /*!< LIN break 19 bits length */
    LIN_BREAK_20_BIT,            /*!< LIN break 20 bits length */
    LIN_BREAK_21_BIT,            /*!< LIN break 21 bits length */
    LIN_BREAK_22_BIT,            /*!< LIN break 22 bits length */
    LIN_BREAK_23_BIT,            /*!< LIN break 23 bits length */
    LIN_BREAK_36_BIT,            /*!< LIN break 36 bits length */
    LIN_BREAK_50_BIT             /*!< LIN break 50 bits length */
} LIN_MstBreakLen;

/**
 * @}
 */

/** @defgroup LIN_CHECKSUMFRAME LIN Module Checksum Frame
 * @{
 * @brief  Values are used to configure the checksum frame of the LIN.
 */
typedef enum {
    LIN_CS_FRAM_ENABLE = 0x0U,    /*!< LIN checksum frame enable */
    LIN_CS_FRAM_DISABLE           /*!< LIN checksum frame disable */
} LIN_ChecksumFrame;

/**
 * @}
 */

/** @defgroup LIN_CHECKSUMCALC LIN Module Checksum Calculation
 * @{
 * @brief  Values are used to configure the checksum calculation of the LIN.
 */
typedef enum {
    LIN_CS_CALC_ENABLE = 0x0U,    /*!< LIN checksum calculation enable */
    LIN_CS_CALC_DISABLE           /*!< LIN checksum calculation disable */
} LIN_ChecksumCalc;

/**
 * @}
 */

/** @defgroup LIN_STATUS LIN Module Status
 * @{
 * @brief  Values ​​are the LIN module current status.
 */
typedef enum {
    LIN_SLEEP_MODE_STATUS = 0x00U,    /*!< Sleep mode status */
    LIN_INIT_MODE_STATUS,             /*!< Init mode status */
    LIN_IDLE_MODE_STATUS,             /*!< Idle mode status */
    LIN_BREAK_STATUS,                 /*!< Break status */
    LIN_BREAK_DELIMITER_STATUS,       /*!< Break delimiter status */
    LIN_SYNC_FIELD_STATUS,            /*!< Synchronous filed status */
    LIN_IDENTIFIER_FIELD_STATUS,      /*!< Identifier filed status */
    LIN_HEADER_RX_OR_TX_STATUS,       /*!< Header reception / transmission status */
    LIN_DATA_RX_OR_TX_STATUS,         /*!< Data reception / transmission status */
    LIN_CHECKSUM_STATUS               /*!< Checksum status */
} LIN_Status;

/**
 * @}
 */

/** @defgroup LIN_TIMEOUTCTRLMODE LIN Module Time Out Control Mode
 * @{
 * @brief  Values ​​are the LIN module time out control mode.
 */
typedef enum {
    LIN_NORMAL_MODE = 0x00U,    /*!< LIN normal mode */
    LIN_OUT_COMPARE_MODE        /*!< LIN out compare mode */
} LIN_TimeOutCtrlMode;

/**
 * @}
 */

/** @defgroup LIN_FRACBAUDRATE LIN Module fractional baud rate
 * @{
 * @brief  Values ​​are the LIN module fractional baud rate.
 */
typedef enum {
    LIN_F_BAUD_NO_DIV = 0x00U,    /*!< LIN FBR = 0 / 16 */
    LIN_F_BAUD_1_DIV_16,          /*!< LIN FBR = 1 / 16 */
    LIN_F_BAUD_DIV_8,             /*!< LIN FBR = 2 / 16 */
    LIN_F_BAUD_3_DIV_16,          /*!< LIN FBR = 3 / 16 */
    LIN_F_BAUD_DIV_4,             /*!< LIN FBR = 4 / 16 */
    LIN_F_BAUD_5_DIV_16,          /*!< LIN FBR = 5 / 16 */
    LIN_F_BAUD_6_DIV_16,          /*!< LIN FBR = 6 / 16 */
    LIN_F_BAUD_7_DIV_16,          /*!< LIN FBR = 7 / 16 */
    LIN_F_BAUD_DIV_2,             /*!< LIN FBR = 8 / 16 */
    LIN_F_BAUD_9_DIV_16,          /*!< LIN FBR = 9 / 16 */
    LIN_F_BAUD_10_DIV_16,         /*!< LIN FBR = 10 / 16 */
    LIN_F_BAUD_11_DIV_16,         /*!< LIN FBR = 11 / 16 */
    LIN_F_BAUD_12_DIV_16,         /*!< LIN FBR = 12 / 16 */
    LIN_F_BAUD_13_DIV_16,         /*!< LIN FBR = 13 / 16 */
    LIN_F_BAUD_14_DIV_16,         /*!< LIN FBR = 14 / 16 */
    LIN_F_BAUD_15_DIV_16,         /*!< LIN FBR = 15 / 16 */
} LIN_FracBaudRate;

/**
 * @}
 */

/** @defgroup LIN_CTRLCHECKSUM LIN Module Control Checksum
 * @{
 * @brief  Values are used to control the checksum of the LIN.
 */
typedef enum {
    LIN_CHECKSUM_ENHANCE = 0x0U,    /*!< LIN enhanced checksum */
    LIN_CHECKSUM_CLASSIC            /*!< LIN classic checksum */
} LIN_CtrlChecksum;

/**
 * @}
 */

/** @defgroup LIN_CTRLDIRECTION LIN Module Control Data Direction
 * @{
 * @brief  Values are used to control the data direction of the LIN.
 */
typedef enum {
    LIN_BUFFER_RECV_DATA = 0x0U,    /*!< LIN receiving data from module buffer */
    LIN_BUFFER_SEND_DATA            /*!< LIN module buffer data sending */
} LIN_CtrlDirection;

/**
 * @}
 */

/** @defgroup LIN_UARTFBMODE LIN Module's Uart Fifo/Buffer Mode
 * @{
 * @brief  Values are used to control the uart Fifo/Buffer mode.
 */
typedef enum {
    LIN_UART_BUFFER_MODE = 0x0U,    /*!< Uart buffer mode */
    LIN_UART_FIFO_MODE              /*!< Uart fifo mode */
} LIN_UartFBMode;

/**
 * @}
 */

/** @defgroup LIN_UARTTRDFL LIN Module's Uart Transmitter/Reception
 *            Data Field Length
 * @{
 * @brief  Values are used to control the uart transmitter/reception
 *         data field length.
 */
typedef enum {
    LIN_UART_TRDFL_1_BYTE = 0x0U,    /*!< T/RDFL = 1 Byte */
    LIN_UART_TRDFL_2_BYTES,          /*!< T/RDFL = 2 Bytes */
    LIN_UART_TRDFL_3_BYTES,          /*!< T/RDFL = 3 Bytes */
    LIN_UART_TRDFL_4_BYTES           /*!< T/RDFL = 4 Bytes */
} LIN_UartTRDFL;

/**
 * @}
 */

/** @defgroup LIN_UARTSTOPBITS LIN Module's Uart Stop Bits
 * @{
 * @brief  Values are used to control the uart stop bits.
 */
typedef enum {
    LIN_UART_1_STOP_BIT = 0x0U,    /*!< Uart 1 stop bit */
    LIN_UART_2_STOP_BITS,          /*!< Uart 2 stop bits */
    LIN_UART_3_STOP_BITS,          /*!< Uart 3 stop bits */
    RESERVED
} LIN_UartStopBits;

/**
 * @}
 */

/** @defgroup LIN_UARTREDUCEOS LIN Module's Uart Reduce Oversampling Enable
 * @{
 * @brief  Values are used to control the uart Reduce oversampling enable
 *         of the LIN.
 */
typedef enum {
    EVERY_BIT_OS_16 = 0x0U,    /*!< Every bit oversampling 16 times */
    EVERY_BIT_OS_BY_OSR        /*!< Every bit oversampling OSR times */
} LIN_UartReduceOS;

/**
 * @}
 */

/** @defgroup LIN_UARTOSRATE LIN Module's Uart Oversampling Rate
 * @{
 * @brief  Values are used to control the uart oversampling rate
 *         of the LIN.
 */
typedef enum {
    OS_RATE_4 = 4U,    /*!< Oversampling rate 4 */
    OS_RATE_5,         /*!< Oversampling rate 5 */
    OS_RATE_6 = 6U,    /*!< Oversampling rate 6 */
    OS_RATE_8          /*!< Oversampling rate 8 */
} LIN_UartOSRate;

/**
 * @}
 */

/** @defgroup LIN_UARTCFGSAMPLE LIN Module's Uart Configure Sample
 * @{
 * @brief  Values are used to control the uart configure sample
 *         of the LIN.
 */
typedef enum {
    CFG_SAMPLE_2 = 2U,    /*!< Configure 2 times sample */
    CFG_SAMPLE_3,         /*!< Configure 3 times sample */
    CFG_SAMPLE_4,         /*!< Configure 4 times sample */
    CFG_SAMPLE_5          /*!< Configure 5 times sample */
} LIN_UartCfgSample;

/**
 * @}
 */

/** @defgroup LIN_UARTMONITIDLESTA LIN Module's Uart Monitor Idle State
 * @{
 * @brief  Values are used to control the uart configure monitor idle state
 *         of the LIN.
 */
typedef enum {
    MONITOR_RECV_DATA = 0U,    /*!< Monitor number of bits of received data */
    MONITOR_IDLE_STAT          /*!< Monitor idle state */
} LIN_UartMonitIdleSta;

/**
 * @}
 */

/** @defgroup LIN_DATAFRAMELEN LIN Module Data Frame Length
 * @{
 * @brief  Values are used to control the data frame length of the LIN.
 */
typedef enum {
    LIN_DFL_1_BYTE = 0x0U,    /*!< 1-byte data length */
    LIN_DFL_2_BYTES,          /*!< 2-bytes data length */
    LIN_DFL_3_BYTES,          /*!< 3-bytes data length */
    LIN_DFL_4_BYTES,          /*!< 4-bytes data length */
    LIN_DFL_5_BYTES,          /*!< 5-bytes data length */
    LIN_DFL_6_BYTES,          /*!< 6-bytes data length */
    LIN_DFL_7_BYTES,          /*!< 7-bytes data length */
    LIN_DFL_8_BYTES           /*!< 8-bytes data length */
} LIN_DataFrameLen;

/**
 * @}
 */

/** @defgroup LIN_FILTERACT LIN Module Filter Active
 * @{
 * @brief  Values ​​are the LIN module filter active enable.
 */
typedef enum {
    LIN_FILTER_NOT_ACT = 0x0000U,    /*!< LIN filter not active */
    LIN_FILTER_0_ACT = 0x0001U,      /*!< LIN filter0 active */
    LIN_FILTER_1_ACT = 0x0002U,      /*!< LIN filter1 active */
    LIN_FILTER_2_ACT = 0x0004U,      /*!< LIN filter2 active */
    LIN_FILTER_3_ACT = 0x0008U,      /*!< LIN filter3 active */
    LIN_FILTER_4_ACT = 0x0010U,      /*!< LIN filter4 active */
    LIN_FILTER_5_ACT = 0x0020U,      /*!< LIN filter5 active */
    LIN_FILTER_6_ACT = 0x0040U,      /*!< LIN filter6 active */
    LIN_FILTER_7_ACT = 0x0080U,      /*!< LIN filter7 active */
    LIN_FILTER_8_ACT = 0x0100U,      /*!< LIN filter8 active */
    LIN_FILTER_9_ACT = 0x0200U,      /*!< LIN filter9 active */
    LIN_FILTER_10_ACT = 0x0400U,     /*!< LIN filter10 active */
    LIN_FILTER_11_ACT = 0x0800U,     /*!< LIN filter11 active */
    LIN_FILTER_12_ACT = 0x1000U,     /*!< LIN filter12 active */
    LIN_FILTER_13_ACT = 0x2000U,     /*!< LIN filter13 active */
    LIN_FILTER_14_ACT = 0x4000U,     /*!< LIN filter14 active */
    LIN_FILTER_15_ACT = 0x8000U,     /*!< LIN filter15 active */
    LIN_FILTER_ALL_ACT = 0xFFFFU     /*!< LIN filter all active */
} LIN_FilterAct;

/**
 * @}
 */

/** @defgroup LIN_FILTERMSK LIN Module Filter Mask Mode
 * @{
 * @brief  Values ​​are the LIN module filter mask mode enable.
 */
typedef enum {
    LIN_FILTER_NOT_MASK = 0x00U,      /*!< LIN filter not mask */
    LIN_FILTER_0_1_MASK = 0x01U,      /*!< LIN filter0-1 mask */
    LIN_FILTER_2_3_MASK = 0x02U,      /*!< LIN filter2-3 mask */
    LIN_FILTER_4_5_MASK = 0x04U,      /*!< LIN filter4-5 mask */
    LIN_FILTER_6_7_MASK = 0x08U,      /*!< LIN filter6-7 mask */
    LIN_FILTER_8_9_MASK = 0x10U,      /*!< LIN filter8-9 mask */
    LIN_FILTER_10_11_MASK = 0x20U,    /*!< LIN filter10-11 mask */
    LIN_FILTER_12_13_MASK = 0x40U,    /*!< LIN filter12-13 mask */
    LIN_FILTER_14_15_MASK = 0x80U,    /*!< LIN filter14-15 mask */
    LIN_FILTER_ALL_MASK = 0xFFU       /*!< LIN filter0-15 all mask */
} LIN_FilterMsk;

/**
 * @}
 */

/** @defgroup LIN_UARTWORDLEN LIN Module's UART Word Length
 * @{
 * @brief  Values are used to control the word length in UART mode.
 */
typedef enum {
    LIN_UART_7_BITS_DATA = 0x0U,    /*!< 7 bits data in UART mode */
    LIN_UART_8_BITS_DATA,           /*!< 8 bits data in UART mode */
    LIN_UART_15_BITS_DATA,          /*!< 15 bits data in UART mode */
    LIN_UART_16_BITS_DATA           /*!< 16 bits data in UART mode */
} LIN_UartWordLen;

/**
 * @}
 */

/** @defgroup LIN_UARTPARITY LIN Module's UART Parity
 * @{
 * @brief  Values are used to control the parity in UART mode.
 */
typedef enum {
    LIN_UART_EVEN_PARITY = 0x0U,    /*!< Parity sent is Even */
    LIN_UART_ODD_PARITY,            /*!< Parity sent is Odd */
    LIN_UART_LOGIC_0_PARITY,        /*!< A logical 0 is always transmitted/checked as parity bit */
    LIN_UART_LOGIC_1_PARITY,        /*!< A logical 1 is always transmitted/checked as parity bit */
    LIN_UART_NO_PARITY              /*!< Parity sent is None */
} LIN_UartParity;

/**
 * @}
 */

/** @defgroup LIN_BAUDRATE LIN Baudrate
 * @{
 * @brief  Macro definitions about LIN baudrate definition.
 */
#define LIN_BAUDRATE_2400     (2400UL)     /*!< 2400 bps */
#define LIN_BAUDRATE_4800     (4800UL)     /*!< 4800 bps */
#define LIN_BAUDRATE_9600     (9600UL)     /*!< 9600 bps */
#define LIN_BAUDRATE_19200    (19200UL)    /*!< 19200 bps */

/**
 * @}
 */

/** @defgroup LIN_UART_BAUDRATE LIN UART Baudrate
 * @{
 * @brief  Macro definitions about LIN UART baudrate definition.
 */
#define LIN_UART_BAUDRATE_2400       LIN_BAUDRATE_2400     /*!< 2400 bps */
#define LIN_UART_BAUDRATE_4800       LIN_BAUDRATE_4800     /*!< 4800 bps */
#define LIN_UART_BAUDRATE_9600       LIN_BAUDRATE_9600     /*!< 9600 bps */
#define LIN_UART_BAUDRATE_19200      LIN_BAUDRATE_19200    /*!< 19200 bps */
#define LIN_UART_BAUDRATE_38400      (38400UL)             /*!< 38400 bps */
#define LIN_UART_BAUDRATE_57600      (57600UL)             /*!< 57600 bps */
#define LIN_UART_BAUDRATE_115200     (115200UL)            /*!< 115200 bps */
#define LIN_UART_BAUDRATE_230400     (230400UL)            /*!< 230400 bps */
#define LIN_UART_BAUDRATE_460800     (460800UL)            /*!< 460800 bps */
#define LIN_UART_BAUDRATE_921600     (921600UL)            /*!< 921600 bps */
#define LIN_UART_BAUDRATE_1000000    (1000000UL)           /*!< 1000000 bps */
#define LIN_UART_BAUDRATE_2000000    (2000000UL)           /*!< 2000000 bps */
#define LIN_UART_BAUDRATE_3000000    (3000000UL)           /*!< 3000000 bps */
#define LIN_UART_BAUDRATE_4000000    (4000000UL)           /*!< 4000000 bps */

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
 * \brief  Requests LIN module to enter init mode.
 * \note   This function puts the LIN module into initialization mode.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 */
static inline void LIN_enterInitMode (LIN_TypeDef *lin)
{
    MODIFY_REG(lin->LINCR1.WORDVAL, LIN_LINCR1_SLEEP_M, LIN_LINCR1_INIT_M);
}

/**
 * \brief  Requests LIN module to enter normal mode.
 * \note   This function puts the LIN module into normal mode.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 */
static inline void LIN_enterNormalMode (LIN_TypeDef *lin)
{
    CLEAR_BIT(lin->LINCR1.WORDVAL, (LIN_LINCR1_SLEEP_M | LIN_LINCR1_INIT_M));
}

/**
 * \brief  Requests LIN module to enter sleep mode.
 * \note   This function puts the LIN module into sleep mode.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 */
static inline void LIN_enterSleepMode (LIN_TypeDef *lin)
{
    SET_BIT(lin->LINSR.WORDVAL, LIN_LINSR_WUF_M);

    MODIFY_REG(lin->LINCR1.WORDVAL, (LIN_LINCR1_INIT_M | LIN_LINCR1_AUTOWU_M), LIN_LINCR1_SLEEP_M);
}

/**
 * \brief  Sets the LIN mode
 * \note   This function sets the mode of the LIN mode to either
 *         master or slave.
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \param  mode  a value of master or slave mode selection.
 */
static inline void LIN_setLINMode (LIN_TypeDef *lin, LIN_ModeSelect mode)
{
    MODIFY_REG(lin->LINCR1.WORDVAL, LIN_LINCR1_MME_M, ((uint32_t)mode << LIN_LINCR1_MME_S));
}

/**
 * \brief  Sets the LIN recevive buffer lock mode
 * \note   This function sets the lock mode of the LIN receive buffer.
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \param  mode  a value of the LIN recevive buffer lock mode.
 */
static inline void LIN_setRecvBufferLockMode (LIN_TypeDef *lin, LIN_BufferLockMode mode)
{
    MODIFY_REG(lin->LINCR1.WORDVAL, LIN_LINCR1_RBLM_M, ((uint32_t)mode << LIN_LINCR1_RBLM_S));
}

/**
 * \brief  Sets the LIN slave break length
 * \note   This function sets the break length of the LIN slave.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  len  a value of the LIN slave break length.
 */
static inline void LIN_setSlaveBreakLength (LIN_TypeDef *lin, LIN_SlaveBreakLen len)
{
    MODIFY_REG(lin->LINCR1.WORDVAL, LIN_LINCR1_SSBL_M, ((uint32_t)len << LIN_LINCR1_SSBL_S));
}

/**
 * \brief  Sets the LIN loop back mode
 * \note   This function sets the loop back mode of the LIN module.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  enable  a value of the LIN loop back mode.
 *                   1: enable; 0: disable
 */
static inline void LIN_setLoopBackMode (LIN_TypeDef *lin, uint32_t enable)
{
    MODIFY_REG(lin->LINCR1.WORDVAL, LIN_LINCR1_LBKM_M, (enable << LIN_LINCR1_LBKM_S));
}

/**
 * \brief  Sets the LIN loop back mode
 * \note   This function sets the loop back mode of the LIN module.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  enable  a value of the LIN loop back mode.
 *                   1: enable; 0: disable
 */
static inline void LIN_setBypassFilter (LIN_TypeDef *lin, uint32_t enable)
{
    MODIFY_REG(lin->LINCR1.WORDVAL, LIN_LINCR1_BF_M, (enable << LIN_LINCR1_BF_S));
}

/**
 * \brief  Sets the LIN master break length
 * \note   This function sets the master break length of the LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  len  a value of the LIN master break length.
 */
static inline void LIN_setMasterBreakLen (LIN_TypeDef *lin, LIN_MstBreakLen len)
{
    MODIFY_REG(lin->LINCR1.WORDVAL, LIN_LINCR1_MBL_M, ((uint32_t)len << LIN_LINCR1_MBL_S));
}

/**
 * \brief  Sets the LIN auto wakeup
 * \note   This function sets the auto wakeup mode of the LIN module.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  enable  a value of the LIN auto wakeup mode.
 *                   1: enable; 0: disable
 */
static inline void LIN_setAutoWakeup (LIN_TypeDef *lin, uint32_t enable)
{
    MODIFY_REG(lin->LINCR1.WORDVAL, LIN_LINCR1_AUTOWU_M, (enable << LIN_LINCR1_AUTOWU_S));
}

/**
 * \brief  Sets the LIN automatic synchronization enable
 * \note   This function sets the automatic synchronization enable of
 *         the LIN module.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  enable  a value of the LIN automatic synchronization enable.
 *                   1: enable; 0: disable
 */
static inline void LIN_setAutoSyncConfig (LIN_TypeDef *lin, uint32_t enable)
{
    MODIFY_REG(lin->LINCR1.WORDVAL, LIN_LINCR1_LASE_M, (enable << LIN_LINCR1_LASE_S));
}

/**
 * \brief  Sets the LIN checksum frame disable
 * \note   This function sets the checksum frame disable of the LIN module.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  chsFrm  a value of the LIN checksum frame disable.
 */
static inline void LIN_setChecksumFrameConfig (LIN_TypeDef *lin, LIN_ChecksumFrame chsFrm)
{
    MODIFY_REG(lin->LINCR1.WORDVAL, LIN_LINCR1_CFD_M, ((uint32_t)chsFrm << LIN_LINCR1_CFD_S));
}

/**
 * \brief  Sets the LIN checksum calculation disable
 * \note   This function sets the checksum calculation disable of the LIN module.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  chscal  a value of the LIN checksum calculation disable.
 */
static inline void LIN_setChecksumCalcConfig (LIN_TypeDef *lin, LIN_ChecksumCalc chscal)
{
    MODIFY_REG(lin->LINCR1.WORDVAL, LIN_LINCR1_CCD_M, ((uint32_t)chscal << LIN_LINCR1_CCD_S));
}

/**
 * \brief  Sets the LIN bit error status enable
 * \note   This function sets the bit error status enable of the LIN module.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  enable  a value of the LIN bit error status enable.
 *                  1: enable; 0: disable
 */
static inline void LIN_setBitErrorStatusConfig (LIN_TypeDef *lin, uint32_t enable)
{
    MODIFY_REG(lin->LINCR1.WORDVAL, LIN_LINCR1_NLSE_M, (enable << LIN_LINCR1_NLSE_S));
}

/**
 * \brief  Enables individual LIN module interrupt sources.
 * \note   This function enables LIN module interrupt sources.
 *
 * \param  lin       lin pointer to a LIN_TypeDef structure
 *                     - LIN1: LIN1 base address index
 *                     - LIN2: LIN2 base address index
 * \param  intFlags  a bit mask of the interrupt sources to be enabled.
 *
 */
static inline void LIN_enableInterrupt (LIN_TypeDef *lin, uint16_t intFlags)
{
    SET_BIT(lin->LINIER.WORDVAL, (uint32_t)intFlags);
}

/**
 * \brief  Disables individual LIN module interrupt sources.
 * \note   This function disables LIN module interrupt sources.
 *
 * \param  lin       lin pointer to a LIN_TypeDef structure
 *                     - LIN1: LIN1 base address index
 *                     - LIN2: LIN2 base address index
 * \param  intFlags  a bit mask of the interrupt sources to be disabled.
 *
 */
static inline void LIN_disableInterrupt (LIN_TypeDef *lin, uint16_t intFlags)
{
    CLEAR_BIT(lin->LINIER.WORDVAL, (uint32_t)intFlags);
}

/**
 * \brief  Gets the current status register value.
 * \note   This function returns the status register value for the LIN module
 *         module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 *
 * \return Returns the current status register value.
 */
static inline uint32_t LIN_getStatusRegValue (LIN_TypeDef *lin)
{
    return (lin->LINSR.WORDVAL);
}

/**
 * \brief  Gets the current status register value.
 * \note   This function returns the status register value for the LIN module
 *         module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 *
 * \param  clr  the value used to clear the status bit.
 */
static inline void LIN_clearStatusRegValue (LIN_TypeDef *lin, uint32_t clr)
{
    SET_BIT(lin->LINSR.WORDVAL, clr);
}

/**
 * \brief  Clear the DRBNE bit in the LINSR register of the LIN module.
 * \note   This function clears LIN module data receive buffer not empty flag.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 */
static inline void LIN_clearRecvBufNotEmptyFlag (LIN_TypeDef *lin)
{
    SET_BIT(lin->LINSR.WORDVAL, LIN_LINSR_DRBNE_M);
}

/**
 * \brief  Clear the DRBNE bit in the LINSR register of the LIN module.
 * \note   This function clears LIN module data received flag.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 */
static inline void LIN_clearDataReceivedFlag (LIN_TypeDef *lin)
{
    SET_BIT(lin->LINSR.WORDVAL, LIN_LINSR_DRF_M);
}

/**
 * \brief  Release the RMB bit in the LINSR register of the LIN module.
 * \note   This function releases LIN module message buffer.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 */
static inline void LIN_releaseMsgBuffer (LIN_TypeDef *lin)
{
    SET_BIT(lin->LINSR.WORDVAL, LIN_LINSR_RMB_M);
}

/**
 * \brief  Clear the AUTOSYNC_COMP bit in the LINSR register of the LIN module.
 * \note   This function clears LIN module auto synchronization complete flag.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 */
static inline void LIN_clearAutoSyncComplete (LIN_TypeDef *lin)
{
    SET_BIT(lin->LINSR.WORDVAL, LIN_LINSR_AUTOSYNCCOMP_M);
}

/**
 * \brief  Gets the current status.
 * \note   This function returns the status for the LIN module
 *         module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 *
 * \return Returns the current status.
 */
static inline uint8_t LIN_getStatus (LIN_TypeDef *lin)
{
    return (uint8_t)(READ_BIT(lin->LINSR.WORDVAL, LIN_LINSR_LINS_M) >> LIN_LINSR_LINS_S);
}

/**
 * \brief  Gets the received data count.
 * \note   This function gets the received data count for the LIN
 *         module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 *
 * \return Returns the received data count.
 */
static inline uint8_t LIN_getRecvDataCount (LIN_TypeDef *lin)
{
    return (uint8_t)(READ_BIT(lin->LINSR.WORDVAL, LIN_LINSR_RDC_M) >> LIN_LINSR_RDC_S);
}

/**
 * \brief  Gets the error status
 * \note   This function gets the error status for the LIN module
 *         module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 *
 * \return Returns the error status.
 */
static inline uint16_t LIN_getErrorStatus (LIN_TypeDef *lin)
{
    return (uint16_t)(lin->LINESR.WORDVAL);
}

/**
 * \brief  Clear the error status.
 * \note   This function clears LIN module error status.
 *
 * \param  lin       lin pointer to a LIN_TypeDef structure
 *                     - LIN1: LIN1 base address index
 *                     - LIN2: LIN2 base address index
 * \param  clearSta  a bit mask of the error status to be cleared.
 */
static inline void LIN_clearErrorStatus (LIN_TypeDef *lin, uint16_t clearSta)
{
    SET_BIT(lin->LINESR.WORDVAL, (uint32_t)clearSta);
}

/**
 * \brief  Gets the time out counter value.
 * \note   This function gets the time out counter value for the LIN
 *         module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 *
 * \return Returns the time out counter value.
 */
static inline uint8_t LIN_getTimeOutCounterVal (LIN_TypeDef *lin)
{
    return (uint8_t)(READ_BIT(lin->LINTCSR.WORDVAL, LIN_LINTCSR_CNT_M));
}

/**
 * \brief  Set the time out counter enable.
 * \note   This function sets LIN module time out counter enable.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  enable  a bit mask of the time out counter to be set.
 */
static inline void LIN_setTimeOutCounterEnable (LIN_TypeDef *lin, uint32_t enable)
{
    MODIFY_REG(lin->LINTCSR.WORDVAL, LIN_LINTCSR_TOCE_M, (enable << LIN_LINTCSR_TOCE_S));
}

/**
 * \brief  Set the idle of the counter time out.
 * \note   This function sets LIN module into the idle of the counter time out.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  enable  a bit mask of the idle configuration to be set.
 */
static inline void LIN_setIdleOfTimeOut (LIN_TypeDef *lin, uint32_t enable)
{
    MODIFY_REG(lin->LINTCSR.WORDVAL, LIN_LINTCSR_IOT_M, (enable << LIN_LINTCSR_IOT_S));
}

/**
 * \brief  Set the time out counter mode.
 * \note   This function sets LIN module time out counter mode.
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \param  mode  a value of the time out control mode.
 */
static inline void LIN_setTimeOutCounterMode (LIN_TypeDef *lin, LIN_TimeOutCtrlMode mode)
{
    MODIFY_REG(lin->LINTCSR.WORDVAL, LIN_LINTCSR_MODE_M, ((uint32_t)mode << LIN_LINTCSR_MODE_S));
}

/**
 * \brief  Set the time out counter mode.
 * \note   This function sets LIN module time out counter mode.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  ocVal1  a value of the output compare 1.
 * \param  ocVal2  a value of the output compare 2.
 */
static inline void LIN_setOutputCompare (LIN_TypeDef *lin, uint8_t ocVal1, uint8_t ocVal2)
{
    WRITE_REG(lin->LINOCR.WORDVAL, (((uint32_t)ocVal1 << LIN_LINOCR_OC1_S) | ((uint32_t)ocVal2 << LIN_LINOCR_OC2_S)));
}

/**
 * \brief  Gets the value of output compare 1.
 * \note   This function gets the value of output compare 1 for the LIN
 *         module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 *
 * \return Returns the value of output compare 1.
 */
static inline uint8_t LIN_getOutputCompare1Val (LIN_TypeDef *lin)
{
    return (uint8_t)(lin->LINOCR.BIT.OC1);
}

/**
 * \brief  Gets the value of output compare 2.
 * \note   This function gets the value of output compare 2 for the LIN
 *         module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 *
 * \return Returns the value of output compare 2.
 */
static inline uint8_t LIN_getOutputCompare2Val (LIN_TypeDef *lin)
{
    return (uint8_t)(lin->LINOCR.BIT.OC2);
}

/**
 * \brief  Set the time out control register.
 * \note   This function sets LIN module time out control register.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  htoVal  a value of the header time out.
 * \param  rtoVal  a value of the reponse time out.
 */
static inline void LIN_setTimeOutControl (LIN_TypeDef *lin, uint8_t htoVal, uint8_t rtoVal)
{
    lin->LINTOCR.BIT.RTO = (uint32_t)rtoVal;
    if (lin->LINCR1.BIT.MME == LIN_SLAVE_MODE)
    {
        lin->LINTOCR.BIT.HTO = (uint32_t)htoVal;
    }
}

/**
 * \brief  Set the fractional baud rate.
 * \note   This function sets LIN module the fractional baud rate.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  fbrVal  a value of the fractional baud rate.
 */
static inline void LIN_setFracBaudrate (LIN_TypeDef *lin, LIN_FracBaudRate fbrVal)
{
    WRITE_REG(lin->LINFBRR.WORDVAL, (uint32_t)fbrVal);
}

/**
 * \brief  Set the integer baud rate.
 * \note   This function sets LIN module the integer baud rate.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  intVal  a value of the integer baud rate.
 */
static inline void LIN_setIntegerBaudrate (LIN_TypeDef *lin, uint32_t intVal)
{
    WRITE_REG(lin->LINIBRR.WORDVAL, intVal);
}

/**
 * \brief  Set the checksum frame configuration.
 * \note   This function sets LIN module the checksum frame.
 *         (Can only be used with LINCR1.CCD = 1)
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \param  chsf  a value of the checksum frame.
 */
static inline void LIN_setChecksumFrame (LIN_TypeDef *lin, uint8_t chsf)
{
    if (lin->LINCR1.BIT.CCD == 1)
    {
        WRITE_REG(lin->LINCFR.WORDVAL, (uint32_t)chsf);
    }
}

/**
 * \brief  Get the checksum frame value.
 * \note   This function gets LIN module the checksum value.
 *         (Can only be used with LINCR1.CCD = 1)
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \return the value of the checksum frame value.
 */
static inline uint8_t LIN_getChecksumFrame (LIN_TypeDef *lin)
{
    return (uint8_t)(lin->LINCFR.BIT.CF);
}

/**
 * \brief  Set the control register 2 conguration.
 * \note   This function sets LIN module the control register 2 conguration.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  config  a value of the control register 2 conguration.
 */
static inline void LIN_setControlReg2Config (LIN_TypeDef *lin, uint16_t config)
{
    MODIFY_REG(lin->LINCR2.WORDVAL, 0xFF00UL, (uint32_t)config);
}

/**
 * \brief  Get the control register 2 conguration.
 * \note   This function gets LIN module the control register 2 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \return Returns the value of config register
 */
static inline uint16_t LIN_getControlReg2Config (LIN_TypeDef *lin)
{
    return (uint16_t)(lin->LINCR2.WORDVAL & 0xFF00);
}

/**
 * \brief  Set the header transmission request
 * \note   This function sets LIN module the header transmission request.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  enable  a value of the LIN auto wakeup mode.
 *                   1: enable; 0: disable
 */
static inline void LIN_setHeaderTransRequest (LIN_TypeDef *lin, uint8_t enable)
{
    MODIFY_REG(lin->LINCR2.WORDVAL, LIN_LINCR2_HTRQ_M, ((uint32_t)enable << LIN_LINCR2_HTRQ_S));
}

/**
 * \brief  Set the data transmission request
 * \note   This function sets LIN module the data transmission request.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  enable  a value of the LIN auto wakeup mode.
 *                   1: enable; 0: disable
 */
static inline void LIN_setDataTransRequest (LIN_TypeDef *lin, uint8_t enable)
{
    MODIFY_REG(lin->LINCR2.WORDVAL, LIN_LINCR2_DTRQ_M, ((uint32_t)enable << LIN_LINCR2_DTRQ_S));
}

/**
 * \brief  Set the buffer id register conguration.
 * \note   This function sets LIN module the control register 2 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a value of the data frame length.
 */
static inline void LIN_setBufferIdRegConfig (LIN_TypeDef *lin, uint8_t id, LIN_CtrlChecksum ccs, LIN_CtrlDirection dir,
                                             LIN_DataFrameLen dfl)
{
    WRITE_REG(lin->BIDR.WORDVAL, ((((uint32_t)id << LIN_BIDR_ID_S) & LIN_BIDR_ID_M) |
                                  (((uint32_t)ccs << LIN_BIDR_CCS_S) & LIN_BIDR_CCS_M) |
                                  (((uint32_t)dir << LIN_BIDR_DIR_S) & LIN_BIDR_DIR_M) |
                                  (((uint32_t)dfl << LIN_BIDR_DFL_S) & LIN_BIDR_DFL_M)));
}

/**
 * \brief  Set the identifier
 * \note   This function sets LIN module the identifier for master.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the LIN ID
 */
static inline void LIN_setIdentifier (LIN_TypeDef *lin, uint8_t id)
{
    MODIFY_REG(lin->BIDR.WORDVAL, LIN_BIDR_ID_M, ((uint32_t)id << LIN_BIDR_ID_S));
}

/**
 * \brief  Get the ID from BIDR register.
 * \note   This function gets the value of ID from LIN BIDR register.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \return Returns the value of ID.
 */
static inline uint8_t LIN_getIdentifier (LIN_TypeDef *lin)
{
    return (uint8_t)(lin->BIDR.WORDVAL & 0x3F);
}

/**
 * \brief  Set the classis checksum
 * \note   This function sets LIN module the classic checksum.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  ccs  a value used to select the classic checksum
 */
static inline void LIN_setClassicChecksum (LIN_TypeDef *lin, LIN_CtrlChecksum ccs)
{
    MODIFY_REG(lin->BIDR.WORDVAL, LIN_BIDR_CCS_M, ((uint32_t)ccs << LIN_BIDR_CCS_S));
}

/**
 * \brief  Set the direction for LIN module
 * \note   This function sets LIN module the direction.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  dir  a value used to select the direction for LIN
 */
static inline void LIN_setDirection (LIN_TypeDef *lin, LIN_CtrlDirection dir)
{
    MODIFY_REG(lin->BIDR.WORDVAL, LIN_BIDR_DIR_M, ((uint32_t)dir << LIN_BIDR_DIR_S));
}

/**
 * \brief  Set the data field length for LIN Module
 * \note   This function sets LIN module the data field length.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  dfl  a value used to set the data field length
 */
static inline void LIN_setDataFieldLen (LIN_TypeDef *lin, LIN_DataFrameLen dfl)
{
    MODIFY_REG(lin->BIDR.WORDVAL, LIN_BIDR_DFL_M, ((uint32_t)dfl << LIN_BIDR_DFL_S));
}

/**
 * \brief  Set the ID filter enable conguration.
 * \note   This function sets LIN module the ID filter enable conguration.
 *
 * \param  lin      lin pointer to a LIN_TypeDef structure
 *                    - LIN1: LIN1 base address index
 *                    - LIN2: LIN2 base address index
 * \param  factCfg  a value of the ID filter enable conguration.
 */
static inline void LIN_setIdFilterEnableConfig (LIN_TypeDef *lin, uint16_t factCfg)
{
    MODIFY_REG(lin->IFER.WORDVAL, (uint32_t)LIN_FILTER_ALL_ACT, (uint32_t)factCfg);
}

/**
 * \brief  Get the ID filter match index.
 * \note   This function gets LIN module the ID filter match index.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \return the value of the ID filter match index.
 */
static inline uint8_t LIN_getIdFilterMatchIndex (LIN_TypeDef *lin)
{
    return (uint8_t)(lin->IFMI.WORDVAL);
}

/**
 * \brief  Set the ID filter mode conguration.
 * \note   This function sets LIN module the ID filter mode conguration.
 *
 * \param  lin      lin pointer to a LIN_TypeDef structure
 *                    - LIN1: LIN1 base address index
 *                    - LIN2: LIN2 base address index
 * \param  modeCfg  a value of the ID filter mode conguration.
 */
static inline void LIN_setIdFilterModeConfig (LIN_TypeDef *lin, uint8_t modeCfg)
{
    MODIFY_REG(lin->IFMR.WORDVAL, (uint32_t)LIN_FILTER_ALL_MASK, (uint32_t)modeCfg);
}

/**
 * \brief  Set the ID filter control 0 conguration.
 * \note   This function sets LIN module the ID filter control 0 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a value of the data frame length.
 */
static inline void LIN_setIdFilterCtrl0Config (LIN_TypeDef *lin, uint8_t id, uint8_t ccs, uint8_t dir, uint8_t dfl)
{
    WRITE_REG(lin->IFCR[0].WORDVAL, ((((uint32_t)id << LIN_IFCR_ID_S) & LIN_IFCR_ID_M) |
                                     (((uint32_t)ccs << LIN_IFCR_CCS_S) & LIN_IFCR_CCS_M) |
                                     (((uint32_t)dir << LIN_IFCR_DIR_S) & LIN_IFCR_DIR_M) |
                                     (((uint32_t)dfl << LIN_IFCR_DFL_S) & LIN_IFCR_DFL_M)));
}

/**
 * \brief  Set the ID filter control 1 conguration.
 * \note   This function sets LIN module the ID filter control 1 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a val1e of the data frame length.
 */
static inline void LIN_setIdFilterCtrl1Config (LIN_TypeDef *lin, uint8_t id, uint8_t ccs, uint8_t dir, uint8_t dfl)
{
    WRITE_REG(lin->IFCR[1].WORDVAL, ((((uint32_t)id << LIN_IFCR_ID_S) & LIN_IFCR_ID_M) |
                                     (((uint32_t)ccs << LIN_IFCR_CCS_S) & LIN_IFCR_CCS_M) |
                                     (((uint32_t)dir << LIN_IFCR_DIR_S) & LIN_IFCR_DIR_M) |
                                     (((uint32_t)dfl << LIN_IFCR_DFL_S) & LIN_IFCR_DFL_M)));
}

/**
 * \brief  Set the ID filter control 2 conguration.
 * \note   This function sets LIN module the ID filter control 2 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a val1e of the data frame length.
 */
static inline void LIN_setIdFilterCtrl2Config (LIN_TypeDef *lin, uint8_t id, uint8_t ccs, uint8_t dir, uint8_t dfl)
{
    WRITE_REG(lin->IFCR[2].WORDVAL, ((((uint32_t)id << LIN_IFCR_ID_S) & LIN_IFCR_ID_M) |
                                     (((uint32_t)ccs << LIN_IFCR_CCS_S) & LIN_IFCR_CCS_M) |
                                     (((uint32_t)dir << LIN_IFCR_DIR_S) & LIN_IFCR_DIR_M) |
                                     (((uint32_t)dfl << LIN_IFCR_DFL_S) & LIN_IFCR_DFL_M)));
}

/**
 * \brief  Set the ID filter control 3 conguration.
 * \note   This function sets LIN module the ID filter control 3 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a val1e of the data frame length.
 */
static inline void LIN_setIdFilterCtrl3Config (LIN_TypeDef *lin, uint8_t id, uint8_t ccs, uint8_t dir, uint8_t dfl)
{
    WRITE_REG(lin->IFCR[3].WORDVAL, ((((uint32_t)id << LIN_IFCR_ID_S) & LIN_IFCR_ID_M) |
                                     (((uint32_t)ccs << LIN_IFCR_CCS_S) & LIN_IFCR_CCS_M) |
                                     (((uint32_t)dir << LIN_IFCR_DIR_S) & LIN_IFCR_DIR_M) |
                                     (((uint32_t)dfl << LIN_IFCR_DFL_S) & LIN_IFCR_DFL_M)));
}

/**
 * \brief  Set the ID filter control 4 conguration.
 * \note   This function sets LIN module the ID filter control 4 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a val1e of the data frame length.
 */
static inline void LIN_setIdFilterCtrl4Config (LIN_TypeDef *lin, uint8_t id, uint8_t ccs, uint8_t dir, uint8_t dfl)
{
    WRITE_REG(lin->IFCR[4].WORDVAL, ((((uint32_t)id << LIN_IFCR_ID_S) & LIN_IFCR_ID_M) |
                                     (((uint32_t)ccs << LIN_IFCR_CCS_S) & LIN_IFCR_CCS_M) |
                                     (((uint32_t)dir << LIN_IFCR_DIR_S) & LIN_IFCR_DIR_M) |
                                     (((uint32_t)dfl << LIN_IFCR_DFL_S) & LIN_IFCR_DFL_M)));
}

/**
 * \brief  Set the ID filter control 5 conguration.
 * \note   This function sets LIN module the ID filter control 5 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a val1e of the data frame length.
 */
static inline void LIN_setIdFilterCtrl5Config (LIN_TypeDef *lin, uint8_t id, uint8_t ccs, uint8_t dir, uint8_t dfl)
{
    WRITE_REG(lin->IFCR[5].WORDVAL, ((((uint32_t)id << LIN_IFCR_ID_S) & LIN_IFCR_ID_M) |
                                     (((uint32_t)ccs << LIN_IFCR_CCS_S) & LIN_IFCR_CCS_M) |
                                     (((uint32_t)dir << LIN_IFCR_DIR_S) & LIN_IFCR_DIR_M) |
                                     (((uint32_t)dfl << LIN_IFCR_DFL_S) & LIN_IFCR_DFL_M)));
}

/**
 * \brief  Set the ID filter control 6 conguration.
 * \note   This function sets LIN module the ID filter control 6 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a val1e of the data frame length.
 */
static inline void LIN_setIdFilterCtrl6Config (LIN_TypeDef *lin, uint8_t id, uint8_t ccs, uint8_t dir, uint8_t dfl)
{
    WRITE_REG(lin->IFCR[6].WORDVAL, ((((uint32_t)id << LIN_IFCR_ID_S) & LIN_IFCR_ID_M) |
                                     (((uint32_t)ccs << LIN_IFCR_CCS_S) & LIN_IFCR_CCS_M) |
                                     (((uint32_t)dir << LIN_IFCR_DIR_S) & LIN_IFCR_DIR_M) |
                                     (((uint32_t)dfl << LIN_IFCR_DFL_S) & LIN_IFCR_DFL_M)));
}

/**
 * \brief  Set the ID filter control 7 conguration.
 * \note   This function sets LIN module the ID filter control 7 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a val1e of the data frame length.
 */
static inline void LIN_setIdFilterCtrl7Config (LIN_TypeDef *lin, uint8_t id, uint8_t ccs, uint8_t dir, uint8_t dfl)
{
    WRITE_REG(lin->IFCR[7].WORDVAL, ((((uint32_t)id << LIN_IFCR_ID_S) & LIN_IFCR_ID_M) |
                                     (((uint32_t)ccs << LIN_IFCR_CCS_S) & LIN_IFCR_CCS_M) |
                                     (((uint32_t)dir << LIN_IFCR_DIR_S) & LIN_IFCR_DIR_M) |
                                     (((uint32_t)dfl << LIN_IFCR_DFL_S) & LIN_IFCR_DFL_M)));
}

/**
 * \brief  Set the ID filter control 8 conguration.
 * \note   This function sets LIN module the ID filter control 8 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a val1e of the data frame length.
 */
static inline void LIN_setIdFilterCtrl8Config (LIN_TypeDef *lin, uint8_t id, uint8_t ccs, uint8_t dir, uint8_t dfl)
{
    WRITE_REG(lin->IFCR[8].WORDVAL, ((((uint32_t)id << LIN_IFCR_ID_S) & LIN_IFCR_ID_M) |
                                     (((uint32_t)ccs << LIN_IFCR_CCS_S) & LIN_IFCR_CCS_M) |
                                     (((uint32_t)dir << LIN_IFCR_DIR_S) & LIN_IFCR_DIR_M) |
                                     (((uint32_t)dfl << LIN_IFCR_DFL_S) & LIN_IFCR_DFL_M)));
}

/**
 * \brief  Set the ID filter control 9 conguration.
 * \note   This function sets LIN module the ID filter control 9 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a val1e of the data frame length.
 */
static inline void LIN_setIdFilterCtrl9Config (LIN_TypeDef *lin, uint8_t id, uint8_t ccs, uint8_t dir, uint8_t dfl)
{
    WRITE_REG(lin->IFCR[9].WORDVAL, ((((uint32_t)id << LIN_IFCR_ID_S) & LIN_IFCR_ID_M) |
                                     (((uint32_t)ccs << LIN_IFCR_CCS_S) & LIN_IFCR_CCS_M) |
                                     (((uint32_t)dir << LIN_IFCR_DIR_S) & LIN_IFCR_DIR_M) |
                                     (((uint32_t)dfl << LIN_IFCR_DFL_S) & LIN_IFCR_DFL_M)));
}

/**
 * \brief  Set the ID filter control 10 conguration.
 * \note   This function sets LIN module the ID filter control 10 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a val1e of the data frame length.
 */
static inline void LIN_setIdFilterCtrl10Config (LIN_TypeDef *lin, uint8_t id, uint8_t ccs, uint8_t dir, uint8_t dfl)
{
    WRITE_REG(lin->IFCR[10].WORDVAL, ((((uint32_t)id << LIN_IFCR_ID_S) & LIN_IFCR_ID_M) |
                                      (((uint32_t)ccs << LIN_IFCR_CCS_S) & LIN_IFCR_CCS_M) |
                                      (((uint32_t)dir << LIN_IFCR_DIR_S) & LIN_IFCR_DIR_M) |
                                      (((uint32_t)dfl << LIN_IFCR_DFL_S) & LIN_IFCR_DFL_M)));
}

/**
 * \brief  Set the ID filter control 11 conguration.
 * \note   This function sets LIN module the ID filter control 11 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a val1e of the data frame length.
 */
static inline void LIN_setIdFilterCtrl11Config (LIN_TypeDef *lin, uint8_t id, uint8_t ccs, uint8_t dir, uint8_t dfl)
{
    WRITE_REG(lin->IFCR[11].WORDVAL, ((((uint32_t)id << LIN_IFCR_ID_S) & LIN_IFCR_ID_M) |
                                      (((uint32_t)ccs << LIN_IFCR_CCS_S) & LIN_IFCR_CCS_M) |
                                      (((uint32_t)dir << LIN_IFCR_DIR_S) & LIN_IFCR_DIR_M) |
                                      (((uint32_t)dfl << LIN_IFCR_DFL_S) & LIN_IFCR_DFL_M)));
}

/**
 * \brief  Set the ID filter control 12 conguration.
 * \note   This function sets LIN module the ID filter control 12 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a val1e of the data frame length.
 */
static inline void LIN_setIdFilterCtrl12Config (LIN_TypeDef *lin, uint8_t id, uint8_t ccs, uint8_t dir, uint8_t dfl)
{
    WRITE_REG(lin->IFCR[12].WORDVAL, ((((uint32_t)id << LIN_IFCR_ID_S) & LIN_IFCR_ID_M) |
                                      (((uint32_t)ccs << LIN_IFCR_CCS_S) & LIN_IFCR_CCS_M) |
                                      (((uint32_t)dir << LIN_IFCR_DIR_S) & LIN_IFCR_DIR_M) |
                                      (((uint32_t)dfl << LIN_IFCR_DFL_S) & LIN_IFCR_DFL_M)));
}

/**
 * \brief  Set the ID filter control 13 conguration.
 * \note   This function sets LIN module the ID filter control 13 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a val1e of the data frame length.
 */
static inline void LIN_setIdFilterCtrl13Config (LIN_TypeDef *lin, uint8_t id, uint8_t ccs, uint8_t dir, uint8_t dfl)
{
    WRITE_REG(lin->IFCR[13].WORDVAL, ((((uint32_t)id << LIN_IFCR_ID_S) & LIN_IFCR_ID_M) |
                                      (((uint32_t)ccs << LIN_IFCR_CCS_S) & LIN_IFCR_CCS_M) |
                                      (((uint32_t)dir << LIN_IFCR_DIR_S) & LIN_IFCR_DIR_M) |
                                      (((uint32_t)dfl << LIN_IFCR_DFL_S) & LIN_IFCR_DFL_M)));
}

/**
 * \brief  Set the ID filter control 14 conguration.
 * \note   This function sets LIN module the ID filter control 14 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a val1e of the data frame length.
 */
static inline void LIN_setIdFilterCtrl14Config (LIN_TypeDef *lin, uint8_t id, uint8_t ccs, uint8_t dir, uint8_t dfl)
{
    WRITE_REG(lin->IFCR[14].WORDVAL, ((((uint32_t)id << LIN_IFCR_ID_S) & LIN_IFCR_ID_M) |
                                      (((uint32_t)ccs << LIN_IFCR_CCS_S) & LIN_IFCR_CCS_M) |
                                      (((uint32_t)dir << LIN_IFCR_DIR_S) & LIN_IFCR_DIR_M) |
                                      (((uint32_t)dfl << LIN_IFCR_DFL_S) & LIN_IFCR_DFL_M)));
}

/**
 * \brief  Set the ID filter control 15 conguration.
 * \note   This function sets LIN module the ID filter control 15 conguration.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  id   a value of the identifier id.
 * \param  ccs  a value of the ccontrol checksum.
 * \param  dir  a value of the ccontrol direction.
 * \param  dfl  a val1e of the data frame length.
 */
static inline void LIN_setIdFilterCtrl15Config (LIN_TypeDef *lin, uint8_t id, uint8_t ccs, uint8_t dir, uint8_t dfl)
{
    WRITE_REG(lin->IFCR[15].WORDVAL, ((((uint32_t)id << LIN_IFCR_ID_S) & LIN_IFCR_ID_M) |
                                      (((uint32_t)ccs << LIN_IFCR_CCS_S) & LIN_IFCR_CCS_M) |
                                      (((uint32_t)dir << LIN_IFCR_DIR_S) & LIN_IFCR_DIR_M) |
                                      (((uint32_t)dfl << LIN_IFCR_DFL_S) & LIN_IFCR_DFL_M)));
}

/**
 * \brief  Requests LIN module to enable software reset.
 * \note   This function enables software reset of the LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 */
static inline void LIN_enableSoftReset (LIN_TypeDef *lin)
{
    SET_BIT(lin->GCR.WORDVAL, LIN_GCR_SR_M);
}

/**
 * \brief  Requests LIN module to disable software reset.
 * \note   This function disables software reset of the LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 */
static inline void LIN_disableSoftReset (LIN_TypeDef *lin)
{
    CLEAR_BIT(lin->GCR.WORDVAL, LIN_GCR_SR_M);
}

/**
 * \brief  Set the global control conguration.
 * \note   This function sets LIN module the global control conguration.
 *
 * \param  lin       lin pointer to a LIN_TypeDef structure
 *                    - LIN1: LIN1 base address index
 *                    - LIN2: LIN2 base address index
 * \param  gcConfig  a value of the global control conguration.
 */
static inline void LIN_setGlobalContrlConfig (LIN_TypeDef *lin, uint8_t gcConfig)
{
    MODIFY_REG(lin->GCR.WORDVAL, LIN_GCR_SR_M, ((uint32_t)gcConfig & 0x3EUL));
}

/**
 * \brief  Requests LIN module to enable DMA TX.
 * \note   This function enables DMA TX of the LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 */
static inline void LIN_enableDmaTx (LIN_TypeDef *lin)
{
    SET_BIT(lin->DMATXE.WORDVAL, LIN_DMATXE_DTE_M);
}

/**
 * \brief  Requests LIN module to disable DMA TX.
 * \note   This function disables DMA TX of the LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 */
static inline void LIN_disableDmaTx (LIN_TypeDef *lin)
{
    CLEAR_BIT(lin->DMATXE.WORDVAL, LIN_DMATXE_DTE_M);
}

/**
 * \brief  Requests LIN module to enable DMA RX.
 * \note   This function enables DMA RX of the LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 */
static inline void LIN_enableDmaRx (LIN_TypeDef *lin)
{
    SET_BIT(lin->DMARXE.WORDVAL, LIN_DMARXE_DRE_M);
}

/**
 * \brief  Requests LIN module to disable DMA RX.
 * \note   This function disables DMA RX of the LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 */
static inline void LIN_disableDmaRx (LIN_TypeDef *lin)
{
    CLEAR_BIT(lin->DMARXE.WORDVAL, LIN_DMARXE_DRE_M);
}

/**
 * \brief  Requests the LIN module to enable DMA HTRQ.
 * \note   This function enables DMA to automatically send the frame header
 *         of the LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 */
static inline void LIN_enableDmaHTRQ (LIN_TypeDef *lin)
{
    SET_BIT(lin->EXTHTRQ.WORDVAL, LIN_EXTHTRQ_DMAHTRQEN_M);
}

/**
 * \brief  Requests LIN module to disable DMA HTRQ.
 * \note   This function disables DMA to automatically send the frame header
 *         of the LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 */
static inline void LIN_disableDmaHTRQ (LIN_TypeDef *lin)
{
    CLEAR_BIT(lin->EXTHTRQ.WORDVAL, LIN_EXTHTRQ_DMAHTRQEN_M);
}

/**
 * \brief  Sets the LIN module baudrate
 * \note   This function sets the baudrate for the LIN module.
 *
 * \param  lin       lin pointer to a LIN_TypeDef structure
 *                     - LIN1: LIN1 base address index
 *                     - LIN2: LIN2 base address index
 * \param  baudrate  a value of baudrate.
 */
extern void LIN_setBaudrateConfig (LIN_TypeDef *lin, uint32_t baudrate);

/**
 * \brief  Sets the byte array of the tx data buffer.
 * \note   This function writes given bytes to the tx data buffer.
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \param  data  send data bytes array.
 * \param  size  send data bytes array size.
 */
extern void LIN_sendData (LIN_TypeDef *lin, uint8_t *data, uint8_t size);

/**
 * \brief  Gets the byte array of the rx data buffer.
 * \note   This function writes given bytes to the rx data buffer.
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \param  data  send data bytes array.
 * \param  size  send data bytes array size.
 */
extern void LIN_getData (LIN_TypeDef *lin, uint8_t *data, uint8_t size);

/*---------------------------------------- LIN Uart Mode -------------------------------------------*/

/**
 * \brief  Configures Uart control register.
 * \note   This function configures the parameters of the LIN module's
 *         Uart control register.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  config  a value of the Uart control register configuration
 */
static inline void LIN_setUartControlRegConfig (LIN_TypeDef *lin, uint32_t config)
{
    MODIFY_REG(lin->UARTCR.WORDVAL, 0xFFFFFFFFUL, config);
}

/**
 * \brief  Requests LIN module to enable UART.
 * \note   This function enables UART of the LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 */
static inline void LIN_enableUart (LIN_TypeDef *lin)
{
    SET_BIT(lin->UARTCR.WORDVAL, LIN_UARTCR_UART_M);
}

/**
 * \brief  Requests LIN module to disable UART.
 * \note   This function disables UART of the LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 */
static inline void LIN_disableUart (LIN_TypeDef *lin)
{
    CLEAR_BIT(lin->DMATXE.WORDVAL, LIN_UARTCR_UART_M);
}

/**
 * \brief  Sets the word length in UART mode
 * \note   This function sets the word length in UART mode of LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  wl0  a value of the word length 0. Value range: 0 or 1.
 * \param  wl1  a value of the word length 1. Value range: 0 or 1.
 */
static inline void LIN_setUartWordLenghth (LIN_TypeDef *lin, uint8_t wl0, uint8_t wl1)
{
    MODIFY_REG(lin->UARTCR.WORDVAL, (LIN_UARTCR_WL0_M | LIN_UARTCR_WL1_M),
               (((uint32_t)READ_BIT(wl0, 0x01UL) << LIN_UARTCR_WL0_S) |
                ((uint32_t)READ_BIT(wl1, 0x01UL) << LIN_UARTCR_WL1_S)));
}

/**
 * \brief  Sets the partiy control in UART mode
 * \note   This function sets the partiy control in UART mode of LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  pce  a value of the partiy control enable.
 *              Value 0: disable; 1: enable
 * \param  pc0  a value of the partiy control 0. Value range: 0 or 1.
 * \param  pc1  a value of the partiy control 1. Value range: 0 or 1.
 */
static inline void LIN_setUartParity (LIN_TypeDef *lin, uint8_t pce, uint8_t pc0, uint8_t pc1)
{
    MODIFY_REG(lin->UARTCR.WORDVAL, (LIN_UARTCR_PCE_M | LIN_UARTCR_PC0_M | LIN_UARTCR_PC1_M),
               (((uint32_t)READ_BIT(pce, 0x01UL) << LIN_UARTCR_PCE_S) |
                ((uint32_t)READ_BIT(pc0, 0x01UL) << LIN_UARTCR_PC0_S) |
                ((uint32_t)READ_BIT(pc1, 0x01UL) << LIN_UARTCR_PC1_S)));
}

/**
 * \brief  Sets the transmitter enable in UART mode
 * \note   This function sets the transmitter enable in UART mode of LIN module.
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \param  txen  a value of the transmitter enable.
 *               Value 0: disable; 1: enable
 */
static inline void LIN_setUartTransEnable (LIN_TypeDef *lin, uint8_t txen)
{
    MODIFY_REG(lin->UARTCR.WORDVAL, LIN_UARTCR_TXE_M, ((uint32_t)READ_BIT(txen, 0x01UL) << LIN_UARTCR_TXE_S));
}

/**
 * \brief  Sets the receiver enable in UART mode
 * \note   This function sets the receiver enable in UART mode of LIN module.
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \param  rxen  a value of the receiver enable.
 *               Value 0: disable; 1: enable
 */
static inline void LIN_setUartRecvEnable (LIN_TypeDef *lin, uint8_t rxen)
{
    MODIFY_REG(lin->UARTCR.WORDVAL, LIN_UARTCR_RXE_M, ((uint32_t)READ_BIT(rxen, 0x01UL) << LIN_UARTCR_RXE_S));
}

/**
 * \brief  Sets the Tx Fifo/Buffer mode configuration in UART mode
 * \note   This function sets the Tx Fifo/Buffer mode configuration in UART
 *         mode of LIN module.
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \param  tfbm  a value of the Tx Fifo/Buffer mode configuration.
 * \param  tdfl  a value of the Transmitter Data Field Length.
 */
static inline void LIN_setUartTxFBModeConfig (LIN_TypeDef *lin, LIN_UartFBMode tfbm, LIN_UartTRDFL tdfl)
{
    MODIFY_REG(lin->UARTCR.WORDVAL, (LIN_UARTCR_TFBM_M | LIN_UARTCR_TDFLTFC_M),
               (((uint32_t)READ_BIT(tfbm, 0x01UL) << LIN_UARTCR_TFBM_S) |
                ((uint32_t)READ_BIT(tdfl, 0x07UL) << LIN_UARTCR_TDFLTFC_S)));
}

/**
 * \brief  Get the TDFL_TFC value in UART mode.
 * \note   This function gets the TDFL_TFC value in UART mode of LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \return the value of the TDFL_TFC value.
 */
static inline uint8_t LIN_getUartTDFLTFC (LIN_TypeDef *lin)
{
    return (uint8_t)((lin->UARTCR.WORDVAL & LIN_UARTCR_TDFLTFC_M) >> LIN_UARTCR_TDFLTFC_S);
}

/**
 * \brief  Sets the Rx Fifo/Buffer mode configuration in UART mode
 * \note   This function sets the Rx Fifo/Buffer mode configuration in UART
 *         mode of LIN module.
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \param  rfbm  a value of the Rx Fifo/Buffer mode configuration.
 * \param  rdfl  a value of the Reception Data Field Length.
 */
static inline void LIN_setUartRxFBModeConfig (LIN_TypeDef *lin, LIN_UartFBMode rfbm, LIN_UartTRDFL rdfl)
{
    MODIFY_REG(lin->UARTCR.WORDVAL, (LIN_UARTCR_RFBM_M | LIN_UARTCR_RDFLRFC_M),
               (((uint32_t)READ_BIT(rfbm, 0x01UL) << LIN_UARTCR_RFBM_S) |
                ((uint32_t)READ_BIT(rdfl, 0x07UL) << LIN_UARTCR_RDFLRFC_S)));
}

/**
 * \brief  Get the RDFL_RFC value in UART mode.
 * \note   This function gets the RDFL_RFC value in UART mode of LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \return the value of the RDFL_RFC value.
 */
static inline uint8_t LIN_getUartRDFLRFC (LIN_TypeDef *lin)
{
    return (uint8_t)((lin->UARTCR.WORDVAL & LIN_UARTCR_RDFLRFC_M) >> LIN_UARTCR_RDFLRFC_S);
}

/**
 * \brief  Sets the special word length in UART mode
 * \note   This function sets the special word length in UART mode of LIN module
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  wls  a value of the special word length.
 *              Value 0: disable; 1: enable
 */
static inline void LIN_setUartSpecialWordLength (LIN_TypeDef *lin, uint8_t wls)
{
    MODIFY_REG(lin->UARTCR.WORDVAL, LIN_UARTCR_WLS_M, ((uint32_t)READ_BIT(wls, 0x01UL) << LIN_UARTCR_WLS_S));
}

/**
 * \brief  Sets the stop bits in UART reception mode
 * \note   This function sets the stop bits in UART reception mode of LIN module.
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \param  sbur  a value of the the stop bits.
 */
static inline void LIN_setUartStopBit (LIN_TypeDef *lin, LIN_UartStopBits sbur)
{
    MODIFY_REG(lin->UARTCR.WORDVAL, LIN_UARTCR_SBUR_M, ((uint32_t)READ_BIT(sbur, 0x03UL) << LIN_UARTCR_SBUR_S));
}

/**
 * \brief  Configures the timeout in UART mode
 * \note   This function configures the timeout in UART mode of LIN module.
 *
 * \param  lin     lin pointer to a LIN_TypeDef structure
 *                   - LIN1: LIN1 base address index
 *                   - LIN2: LIN2 base address index
 * \param  enable  a value of the enable/disable timeout.
 *                  Value 0: enable; 1: disable
 * \param  nlf     a value of the number of expected frame.
 */
static inline void LIN_configUartTimeout (LIN_TypeDef *lin, uint8_t enable, uint8_t nlf)
{
    MODIFY_REG(lin->UARTCR.WORDVAL, (LIN_UARTCR_DTU_M | LIN_UARTCR_NEF_M),
               (((uint32_t)READ_BIT(~enable, 0x01UL) << LIN_UARTCR_DTU_S) |
                ((uint32_t)READ_BIT(nlf, 0x03UL) << LIN_UARTCR_NEF_S)));
}

/**
 * \brief  Configures the reduce oversampling in UART mode
 * \note   This function configures the reduce oversampling in UART mode of
 *         LIN module.
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \param  rose  a value of the reduce oversampling enable.
 * \param  osr   a value of the oversampling rate.
 * \param  osr   a value of the configuring sample.
 */
static inline void LIN_configUartReduceOverSampling (LIN_TypeDef *lin, LIN_UartReduceOS rose, LIN_UartOSRate osr,
                                                     LIN_UartCfgSample csp)
{
    MODIFY_REG(lin->UARTCR.WORDVAL, (LIN_UARTCR_ROSE_M | LIN_UARTCR_OSR_M | LIN_UARTCR_CSP_M),
               (((uint32_t)rose << LIN_UARTCR_ROSE_S) | ((uint32_t)osr << LIN_UARTCR_OSR_S) |
                ((uint32_t)csp << LIN_UARTCR_CSP_S)));
}

/**
 * \brief  Sets the monitor idle state in UART mode
 * \note   This function sets the monitor idle state in UART mode of LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  sta  a value of the monitor idle state.
 */
static inline void LIN_setUartMonitorIdleState (LIN_TypeDef *lin, LIN_UartMonitIdleSta sta)
{
    MODIFY_REG(lin->UARTCR.WORDVAL, LIN_UARTCR_MIS_M, ((uint32_t)sta << LIN_UARTCR_MIS_S));
}

/**
 * \brief  Get the status in UART mode.
 * \note   This function gets the status in UART mode of LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \return the value of the UART status.
 */
static inline uint32_t LIN_getUartStatus (LIN_TypeDef *lin)
{
    return (lin->UARTSR.WORDVAL);
}

/**
 * \brief  Clear the status in UART mode
 * \note   This function clears the status in UART mode of LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  clr  a value of the UART status clearing.
 */
static inline void LIN_clearUartStatus (LIN_TypeDef *lin, uint32_t clr)
{
    WRITE_REG(lin->UARTSR.WORDVAL, clr);
}

/**
 * \brief  Set the preset timeout in UART mode
 * \note   This function sets the preset timeout in UART mode of LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \param  pto  a value of the UART preset timeout.
 * \note        pto cannot be equal to 0.
 */
static inline void LIN_setUartPresetTimeout (LIN_TypeDef *lin, uint16_t pto)
{
    uint16_t tmpPto = (pto & 0xFFFU);
    if(tmpPto != 0)
    {
        WRITE_REG(lin->UARTPTO.WORDVAL, (uint32_t)tmpPto);
    }
}

/**
 * \brief  Get the current timeout in UART mode.
 * \note   This function gets the current timeout in UART mode of LIN module.
 *
 * \param  lin  lin pointer to a LIN_TypeDef structure
 *                - LIN1: LIN1 base address index
 *                - LIN2: LIN2 base address index
 * \return the value of the UART current timeout.
 */
static inline uint16_t LIN_getUartCurrentTimeout (LIN_TypeDef *lin)
{
    return (uint16_t)(lin->UARTCTO.WORDVAL & 0xFFFU);
}

/**
 * \brief  Configure the word length in UART mode
 * \note   This function configures the word length in UART mode.
 *
 * \param  lin          lin pointer to a LIN_TypeDef structure
 *                        - LIN1: LIN1 base address index
 *                        - LIN2: LIN2 base address index
 * \param  uartWordLen  a value of the word length.
 */
extern void LIN_configUartWordLength (LIN_TypeDef *lin, LIN_UartWordLen uartWordLen);

/**
 * \brief  Configure the parity in UART mode
 * \note   This function configures the parity in UART mode.
 *
 * \param  lin         lin pointer to a LIN_TypeDef structure
 *                       - LIN1: LIN1 base address index
 *                       - LIN2: LIN2 base address index
 * \param  uartParity  a value of the parity.
 */
extern void LIN_configUartParity (LIN_TypeDef *lin, LIN_UartParity uartParity);

/**
 * \brief  Sets the byte array of the UART tx data buffer.
 * \note   This function writes given bytes to the UART tx data buffer.
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \param  data  send data bytes array.
 * \param  size  send data bytes array size.
 */
extern void LIN_uartSendBufferData (LIN_TypeDef *lin, uint8_t *data, uint8_t size);

/**
 * \brief  Receives the byte array of the UART rx data buffer.
 * \note   This function receives bytes to the UART rx data buffer.
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \param  data  receiving data bytes array.
 * \param  size  receiving data bytes array size.
 */
extern void LIN_uartRecvBufferData (LIN_TypeDef *lin, uint8_t *data, uint8_t size);

/**
 * \brief  Sets the byte array of the UART tx fifo data.
 * \note   This function writes given bytes to the UART tx fifo data.
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \param  data  send data bytes array.
 * \param  size  send data bytes array size.
 */
extern void LIN_uartSendFifoData (LIN_TypeDef *lin, uint8_t *data, uint8_t size);

/**
 * \brief  Sets the byte array of the UART rx fifo data.
 * \note   This function writes given bytes to the UART rx fifo data.
 *
 * \param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * \param  data  send data bytes array.
 * \param  size  send data bytes array size.
 */
extern uint8_t LIN_uartRecvFifoData (LIN_TypeDef *lin);

/*--------------------------------------------------------------------------------------------------*/


#ifdef __cplusplus
}
#endif


#endif /* __LIN_H__ */
