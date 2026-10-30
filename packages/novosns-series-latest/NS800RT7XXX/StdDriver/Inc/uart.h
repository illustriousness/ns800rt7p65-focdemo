/**
  * @file       uart.h
  * @author     yangjun
  * @brief      Header file for NS800RT7xxx uart module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __UART_H__
#define __UART_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_uart.h"


#include <stdbool.h>


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup UART_EXPORTED_TYPES UART Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'UART' module.
  */

/** @defgroup UART_STAT_REG_FLAGS_MASK UART Status Register Flags Mask
  * @{
  * @brief  Macro definitions about flag clearance mask for STAT register.
  */
#define UART_STAT_REG_FLAGS_MASK    (0xC01FC000UL)    /*!< STAT register flags clearance mask */

/**
  * @}
  */

/** @defgroup UART_FIFO_RESET_MASK UART FIFO Register Reset Mask
  * @{
  * @brief  Macro definitions about reset mask for FIFO register.
  */
#define UART_FIFO_RESET_MASK    (0x0003C000UL)    /*!< FIFO register reset mask */

/**
  * @}
  */

/** @defgroup UART_O_REG UART Register Offsets
  * @{
  * @brief  Macro definitions about UART register offsets.
  */
#define UART_O_GLOBAL    (0x08UL)    /*!< UART GLOBAL register offset */
#define UART_O_BAUD      (0x10UL)    /*!< UART BAUD register offset */
#define UART_O_STAT      (0x14UL)    /*!< UART STAT register offset */
#define UART_O_CTRL      (0x18UL)    /*!< UART CTRL register offset */
#define UART_O_DATA      (0x1CUL)    /*!< UART DATA register offset */
#define UART_O_MATCH     (0x20UL)    /*!< UART MATCH register offset */
#define UART_O_MODIR     (0x24UL)    /*!< UART MODIR register offset */
#define UART_O_FIFO      (0x28UL)    /*!< UART FIFO register offset */
#define UART_O_WATER     (0x2CUL)    /*!< UART WATER register offset */

/**
  * @}
  */

/** @defgroup UART_STATUSFLAG UART Status Flag
  * @{
  * @brief  Macro definitions about the UART status flags for use in the UART functions.
  */
typedef enum {
    UART_IDLE_LINE_DETECT = 0U,        /*!< Idle line detect flag */
    UART_RX_OVERRUN,                   /*!< Rx overrun flag */
    UART_NOISE_DETECT,                 /*!< Noise flag */
    UART_FRAME_ERR,                    /*!< Frame error flag */
    UART_PARITY_ERR,                   /*!< Parity error flag */
    UART_RX_ACTIVE_EDGE_DETECT,        /*!< Active edge flag */
    UART_MATCH_ADDR_ONE,               /*!< Address one match flag */
    UART_MATCH_ADDR_TWO,               /*!< Address two match flag */
    UART_FIFO_TX_OF,                   /*!< Tx fifo buffer overflow flag */
    UART_FIFO_RX_UF,                   /*!< Rx fifo buffer underflow flag */
    UART_RX_DATA_REG_FULL,             /*!< Rx data register full flag */
    UART_TX_DATA_REG_EMPTY ,           /*!< Tx data register empty flag */
    UART_TX_COMPLETE,                  /*!< Tx complete flag */
    UART_RX_ACTIVE,                    /*!< Rx active flag */
    UART_NOISE_IN_CURRENT_WORD,        /*!< Noise in current received data */
    UART_PARITY_ERR_IN_CURRENT_WORD    /*!< Parity error in current received data */
} UART_StatusFlag;

/**
  * @}
  */

/** @defgroup UART_INTERRUPTSOURCE UART Interrupt Source
  * @{
  * @brief  Macro definitions about the UART interrupt source.
  */
typedef enum {
    UART_INT_RX_ACTIVE_EDGE = 0U,    /*!< RX active edge interrupt */
    UART_INT_RX_DATA_REG_FULL,       /*!< Rx data register full interrupt */
    UART_INT_RX_OVERRUN,             /*!< Rx overrun interrupt */
    UART_INT_FIFO_RXUF,              /*!< Rx fifo buffer interrupt */
    UART_INT_TX_DATA_REG_EMPTY,      /*!< Tx data register empty interrupt */
    UART_INT_TX_COMPLETE,            /*!< Tx complete interrupt */
    UART_INT_FIFO_TXOF,              /*!< Tx fifo buffer interrupt */
    UART_INT_IDLE_LINE,              /*!< Idle line interrupt */
    UART_INT_NOISE_ERR_FLAG,         /*!< Noise error interrupt */
    UART_INT_FRAME_ERR_FLAG,         /*!< Framing error interrupt */
    UART_INT_PARITY_ERR_FLAG,        /*!< Parity error interrupt */
    UART_INT_MATCH_ADDR_ONE,         /*!< Match address one interrupt */
    UART_INT_MATCH_ADDR_TWO          /*!< Match address two interrupt */
} UART_InterruptSource;

/**
  * @}
  */

  /** @defgroup UART_PARITYTYPE UART Parity Types
  * @{
  * @brief  Macro definitions about the parity of the UART.
  */
typedef enum {
    UART_PAR_NONE = 0U,    /*!< No parity */
    UART_PAR_EVEN = 2U,    /*!< Even parity */
    UART_PAR_ODD           /*!< Odd parity */
} UART_ParityType;

/**
  * @}
  */

/** @defgroup UART_STOPBITCOUNT UART Stop Bits
  * @{
  * @brief  Macro definitions about the number of stop bits.
  */
typedef enum {
    UART_ONE_STOP_BIT = 0U,    /*!< one stop bit */
    UART_TWO_STOP_BIT          /*!< two stop bits */
} UART_StopBitCount;

/**
  * @}
  */

/** @defgroup UART_BITCOUNTPERCHAR UART Bit Count Per Character
  * @{
  * @brief  Macro definitions about the number of bits in a character.
  */
typedef enum {
    UART_8_BITS_PER_CHAR = 0U,    /*!< 8-bit data characters */
    UART_9_BITS_PER_CHAR,         /*!< 9-bit data characters */
    UART_10_BITS_PER_CHAR,        /*!< 10-bit data characters */
    UART_7_BITS_PER_CHAR          /*!< 7-bit data characters */
} UART_BitCountPerChar;

/**
  * @}
  */

/** @defgroup UART_RECEIVERIDLECHARCNT UART Receiver Idle Character Count
  * @{
  * @brief  Macro definitions about receiver idle character count.
  */
typedef enum {
    UART_IDLE_CHARACTER_CNT0 = 0U,    /*!< Disable RDRF if FIFO not full during idle */
    UART_IDLE_CHARACTER_CNT1,         /*!< Enable RDRF if FIFO partially filled after 1 idle char */
    UART_IDLE_CHARACTER_CNT2,         /*!< Enable RDRF if FIFO partially filled after 2 idle char */
    UART_IDLE_CHARACTER_CNT4,         /*!< Enable RDRF if FIFO partially filled after 4 idle char */
    UART_IDLE_CHARACTER_CNT8,         /*!< Enable RDRF if FIFO partially filled after 8 idle char */
    UART_IDLE_CHARACTER_CNT16,        /*!< Enable RDRF if FIFO partially filled after 16 idle char */
    UART_IDLE_CHARACTER_CNT32,        /*!< Enable RDRF if FIFO partially filled after 32 idle char */
    UART_IDLE_CHARACTER_CNT64         /*!< Enable RDRF if FIFO partially filled after 64 idle char */
} UART_ReceiverIdleCharCnt;

/**
  * @}
  */

/** @defgroup UART_TXFIFOLEVEL UART Transmit FIFO Level
  * @{
  * @brief  Macro definitions about the number of datawords in the transmit FIFO.
  */
typedef enum {
    UART_FIFO_TX0 = 0U,    /*!< Transmit empty */
    UART_FIFO_TX1,         /*!< Transmit 1/16 full */
    UART_FIFO_TX2,         /*!< Transmit 2/16 full */
    UART_FIFO_TX3,         /*!< Transmit 3/16 full */
    UART_FIFO_TX4,         /*!< Transmit 4/16 full */
    UART_FIFO_TX5,         /*!< Transmit 5/16 full */
    UART_FIFO_TX6,         /*!< Transmit 6/16 full */
    UART_FIFO_TX7,         /*!< Transmit 7/16 full */
    UART_FIFO_TX8,         /*!< Transmit 8/16 full */
    UART_FIFO_TX9,         /*!< Transmit 9/16 full */
    UART_FIFO_TX10,        /*!< Transmit 10/16 full */
    UART_FIFO_TX11,        /*!< Transmit 11/16 full */
    UART_FIFO_TX12,        /*!< Transmit 12/16 full */
    UART_FIFO_TX13,        /*!< Transmit 13/16 full */
    UART_FIFO_TX14,        /*!< Transmit 14/16 full */
    UART_FIFO_TX15,        /*!< Transmit 15/16 full */
    UART_FIFO_TX16         /*!< Transmit full */
} UART_TxFIFOLevel;

/**
  * @}
  */

/** @defgroup UART_RXFIFOLEVEL UART Receive FIFO Level
  * @{
  * @brief  Macro definitions about the number of datawords in the receive FIFO.
  */
typedef enum {
    UART_FIFO_RX0 = 0U,    /*!< Receive empty */
    UART_FIFO_RX1,         /*!< Receive 1/16 full */
    UART_FIFO_RX2,         /*!< Receive 2/16 full */
    UART_FIFO_RX3,         /*!< Receive 3/16 full */
    UART_FIFO_RX4,         /*!< Receive 4/16 full */
    UART_FIFO_RX5,         /*!< Receive 5/16 full */
    UART_FIFO_RX6,         /*!< Receive 6/16 full */
    UART_FIFO_RX7,         /*!< Receive 7/16 full */
    UART_FIFO_RX8,         /*!< Receive 8/16 full */
    UART_FIFO_RX9,         /*!< Receive 9/16 full */
    UART_FIFO_RX10,        /*!< Receive 10/16 full */
    UART_FIFO_RX11,        /*!< Receive 11/16 full */
    UART_FIFO_RX12,        /*!< Receive 12/16 full */
    UART_FIFO_RX13,        /*!< Receive 13/16 full */
    UART_FIFO_RX14,        /*!< Receive 14/16 full */
    UART_FIFO_RX15,        /*!< Receive 15/16 full */
    UART_FIFO_RX16         /*!< Receive full */
} UART_RxFIFOLevel;

/**
  * @}
  */

/**
  * @}
  */


/*******************************************************************************
 * Variables
 ******************************************************************************/
/** @defgroup UART_PUBLIC_VARIABLES UART Public Variables
  * @{
  * @brief  These public static variables do not need to be configured by the user
  */

/** @defgroup INT_REG Interrupt Register Shift Table
  * @{
  * @brief  Register offsets for interrupt-enabled registers
  */
static const uint8_t INT_REG[] = {
    UART_O_BAUD, UART_O_CTRL, UART_O_CTRL, UART_O_FIFO, UART_O_CTRL, UART_O_CTRL, UART_O_FIFO, \
    UART_O_CTRL, UART_O_CTRL, UART_O_CTRL, UART_O_CTRL, UART_O_CTRL, UART_O_CTRL
};

/**
  * @}
  */

/** @defgroup INT_W1C Interrupt Register W1C Mask Table
  * @{
  * @brief  This static constant array identifies W1C bits in interrupt registers
  */
static const uint8_t INT_W1C[] = {
    0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0
};

/**
  * @}
  */

/** @defgroup INT_MASK Interrupt Mask Configuration Table
  * @{
  * @brief  Static constant array for interrupt configuration masks
  */
static const uint32_t INT_MASK[] = {
    UART_BAUD_RXEDGIE_M,    /*!< RX active edge detection */
    UART_CTRL_RIE_M,        /*!< RX data register full */
    UART_CTRL_ORIE_M,       /*!< RX overrun error */
    UART_FIFO_RXUFE_M,      /*!< RX FIFO underflow */
    UART_CTRL_TIE_M,        /*!< TX data register empty */
    UART_CTRL_TCIE_M,       /*!< TX complete */
    UART_FIFO_TXOFE_M,      /*!< TX FIFO overflow */
    UART_CTRL_ILIE_M,       /*!< IDLE line detection */
    UART_CTRL_NEIE_M,       /*!< Noise error */
    UART_CTRL_FEIE_M,       /*!< Framing error */
    UART_CTRL_PEIE_M,       /*!< Parity error */
    UART_CTRL_MA1IE_M,      /*!< Address match 1 */
    UART_CTRL_MA2IE_M       /*!< Address match 2 */
};

/**
  * @}
  */

/** @defgroup STATUS_REG Status Register Offset Table
  * @{
  * @brief  Register offsets for status flag registers
  */
static const uint8_t STATUS_REG[] = {
    UART_O_STAT, UART_O_STAT, UART_O_STAT, UART_O_STAT, UART_O_STAT, UART_O_STAT, UART_O_STAT, \
    UART_O_STAT, UART_O_FIFO, UART_O_FIFO, UART_O_STAT, UART_O_STAT, UART_O_STAT, UART_O_STAT, \
    UART_O_DATA, UART_O_DATA
};

/**
  * @}
  */

/** @defgroup STATUS_W1C Status Register W1C Mask Table
  * @{
  * @brief  This static constant array identifies W1C bits in interrupt registers
  */
static const uint8_t STATUS_W1C[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0
};

/**
  * @}
  */

/** @defgroup STATUS_MASK Status Mask Configuration Table
  * @{
  * @brief  Static constant array for status configuration masks
  */
static const uint32_t STATUS_MASK[] = {
    UART_STAT_IDLE_M,       /*!< IDLE line detected flag */
    UART_STAT_OR_M,         /*!< RX overrun error flag */
    UART_STAT_NF_M,         /*!< Noise detection flag */
    UART_STAT_FE_M,         /*!< Framing error flag */
    UART_STAT_PF_M,         /*!< Parity error flag */
    UART_STAT_RXEDGIF_M,    /*!< RX pin active edge detected */
    UART_STAT_MA1F_M,       /*!< Address match 1 flag */
    UART_STAT_MA2F_M,       /*!< Address match 2 flag */
    UART_FIFO_TXOF_M,       /*!< TX FIFO overflow flag */
    UART_FIFO_RXUF_M,       /*!< RX FIFO underflow flag */
    UART_STAT_RDRF_M,       /*!< RX data register full */
    UART_STAT_TDRE_M,       /*!< TX data register empty */
    UART_STAT_TC_M,         /*!< Transmission complete */
    UART_STAT_RAF_M,        /*!< RX active status */
    UART_DATA_NOISY_M,      /*!< Noise in current data word */
    UART_DATA_PARITYE_M     /*!< Parity error in current word */
};

/**
  * @}
  */

/**
  * @}
  */


/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
  * \brief  Sets the type of parity
  * \note   For 10 bits per char, parity bit cannot be enabled
  * \param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * \param  parity    UART parity
  *                    This parameter can be any value of @ref UART_PARITYTYPE
  */
static inline void UART_setParityMode (UART_TypeDef* uart, UART_ParityType parity)
{
    MODIFY_REG(uart->CTRL.WORDVAL, UART_CTRL_PE_M | UART_CTRL_PT_M, (uint32_t)parity);
}

/**
  * \brief  Gets the current parity configuration
  * \note   Reads both parity control bits (PE and PT)
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \return Current parity setting
  *                  This parameter can be any value of @ref UART_PARITYTYPE
  */
static inline UART_ParityType UART_getParityMode (UART_TypeDef* uart)
{
    return (UART_ParityType)READ_BIT(uart->CTRL.WORDVAL, UART_CTRL_PE_M | UART_CTRL_PT_M);
}

/**
  * \brief  Sets the send FIFO watermark level
  * \note   Sets the FIFO level at which TDRE flag are generated
  * \param  uart       UART port address
  *                     - UART1: UART1 base address index
  *                     - UART2: UART2 base address index
  *                     - UART3: UART3 base address index
  *                     - UART4: UART4 base address index
  * \param  txLevel    UART transmit FIFO watermark level
  *                     This parameter can be value of @ref UART_TXFIFOLEVEL except UART_FIFO_TX16
  */
static inline void UART_setTxFifoWatermark (UART_TypeDef* uart, UART_TxFIFOLevel txLevel)
{
    MODIFY_REG(uart->WATER.WORDVAL, UART_WATER_TXWATER_M, \
               (uint32_t)txLevel << UART_WATER_TXWATER_S);
}

/**
  * \brief  Sets the receive FIFO watermark level
  * \note   Sets the FIFO level at which RDRF flag are generated
  * \param  uart       UART port address
  *                     - UART1: UART1 base address index
  *                     - UART2: UART2 base address index
  *                     - UART3: UART3 base address index
  *                     - UART4: UART4 base address index
  * \param  rxLevel    UART receive FIFO watermark level
  *                     This parameter can be value of @ref UART_RXFIFOLEVEL except UART_FIFO_RX16
  */
static inline void UART_setRxFifoWatermark (UART_TypeDef* uart, UART_RxFIFOLevel rxLevel)
{
    MODIFY_REG(uart->WATER.WORDVAL, UART_WATER_RXWATER_M, \
               (uint32_t)rxLevel << UART_WATER_RXWATER_S);
}

/**
  * \brief  Gets the transmit FIFO watermark level
  * \param  uart       UART port address
  *                     - UART1: UART1 base address index
  *                     - UART2: UART2 base address index
  *                     - UART3: UART3 base address index
  *                     - UART4: UART4 base address index
  * \param  txLevel    UART transmit FIFO watermark level
  *                     txLevel is a pointer to storage for the transmit FIFO watermark level
  */
static inline void UART_getTxFifoWatermark (UART_TypeDef* uart, UART_TxFIFOLevel *txLevel)
{
    *txLevel = (UART_TxFIFOLevel)(READ_BIT(uart->WATER.WORDVAL, \
                UART_WATER_TXWATER_M) >> UART_WATER_TXWATER_S);
}

/**
  * \brief  Gets the receive FIFO watermark level
  * \param  uart       UART port address
  *                     - UART1: UART1 base address index
  *                     - UART2: UART2 base address index
  *                     - UART3: UART3 base address index
  *                     - UART4: UART4 base address index
  * \param  rxLevel    UART receive FIFO watermark level
  *                     rxLevel is a pointer to storage for the receive FIFO watermark level
  */
static inline void UART_getRxFifoWatermark (UART_TypeDef* uart, UART_RxFIFOLevel *rxLevel)
{
    *rxLevel = (UART_RxFIFOLevel)(READ_BIT(uart->WATER.WORDVAL, \
                UART_WATER_RXWATER_M) >> UART_WATER_RXWATER_S);
}

/**
  * \brief  Enable UART transmitter and receiver
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  */
static inline void UART_enableModule (UART_TypeDef* uart)
{
    SET_BIT(uart->CTRL.WORDVAL, UART_CTRL_TE_M | UART_CTRL_RE_M);
    while (READ_BIT(uart->CTRL.WORDVAL, UART_CTRL_TE_M | UART_CTRL_RE_M) != \
          (UART_CTRL_TE_M | UART_CTRL_RE_M))
    {
        ;
    }
}

/**
  * \brief  Disable UART transmitter and receiver
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  */
static inline void UART_disableModule (UART_TypeDef* uart)
{
    CLEAR_BIT(uart->CTRL.WORDVAL, UART_CTRL_TE_M | UART_CTRL_RE_M);
    while (READ_BIT(uart->CTRL.WORDVAL, UART_CTRL_TE_M | UART_CTRL_RE_M))
    {
        ;
    }
}

/**
  * \brief  Enable UART transmitter
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  */
static inline void UART_enableTxModule (UART_TypeDef* uart)
{
    SET_BIT(uart->CTRL.WORDVAL, UART_CTRL_TE_M);
    while (READ_BIT(uart->CTRL.WORDVAL, UART_CTRL_TE_M) == 0UL)
    {
        ;
    }
}

/**
  * \brief  Disable UART transmitter
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  */
static inline void UART_disableTxModule (UART_TypeDef* uart)
{
    CLEAR_BIT(uart->CTRL.WORDVAL, UART_CTRL_TE_M);
    while (READ_BIT(uart->CTRL.WORDVAL, UART_CTRL_TE_M))
    {
        ;
    }
}

/**
  * \brief  Enable UART receiver
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  */
static inline void UART_enableRxModule (UART_TypeDef* uart)
{
    SET_BIT(uart->CTRL.WORDVAL, UART_CTRL_RE_M);
    while (READ_BIT(uart->CTRL.WORDVAL, UART_CTRL_RE_M) == 0UL)
    {
        ;
    }
}

/**
  * \brief  Disable UART receiver
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  */
static inline void UART_disableRxModule (UART_TypeDef* uart)
{
    CLEAR_BIT(uart->CTRL.WORDVAL, UART_CTRL_RE_M);
    while (READ_BIT(uart->CTRL.WORDVAL, UART_CTRL_RE_M))
    {
        ;
    }
}

/**
  * \brief  Enable UART transmitter FIFO
  * \note   The transmitter enable (TE) bits must be cleared before modifying TXFE bits
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  */
static inline void UART_enableTxFifo (UART_TypeDef* uart)
{
    MODIFY_REG(uart->FIFO.WORDVAL, UART_FIFO_RESET_MASK, UART_FIFO_TXFE_M);
}

/**
  * \brief  Enable UART receiver FIFO
  * \note   The receiver enable (RE) bits must be cleared before modifying RXFE bits
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  */
static inline void UART_enableRxFifo (UART_TypeDef* uart)
{
    MODIFY_REG(uart->FIFO.WORDVAL, UART_FIFO_RESET_MASK, UART_FIFO_RXFE_M);
}

/**
  * \brief  Disable UART transmitter FIFO
  * \note   The transmitter enable (TE) bits must be cleared before modifying TXFE bits
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  */
static inline void UART_disableTxFifo (UART_TypeDef* uart)
{
    CLEAR_BIT(uart->FIFO.WORDVAL, UART_FIFO_RESET_MASK | UART_FIFO_TXFE_M);
}

/**
  * \brief  Disable UART receiver FIFO
  * \note   The receiver enable (RE) bits must be cleared before modifying RXFE bits
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  */
static inline void UART_disableRxFifo (UART_TypeDef* uart)
{
    CLEAR_BIT(uart->FIFO.WORDVAL, UART_FIFO_RESET_MASK | UART_FIFO_RXFE_M);
}

/**
  * \brief  Checks if transmitter FIFO is enabled
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \return Return \b true if the transmitter FIFO is enabled, \b false if disabled
  */
static inline bool UART_isTxFifoEnabled (UART_TypeDef* uart)
{
    return READ_BIT(uart->FIFO.WORDVAL, UART_FIFO_TXFE_M) ? true : false;
}

/**
  * \brief  Checks if receiver FIFO is enabled
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \return Return \b true if the receiver FIFO is enabled, \b false if disabled
  */
static inline bool UART_isRxFifoEnabled (UART_TypeDef* uart)
{
    return READ_BIT(uart->FIFO.WORDVAL, UART_FIFO_RXFE_M) ? true : false;
}

/**
  * \brief  Resets the receiver FIFO
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  */
static inline void UART_resetRxFifo (UART_TypeDef* uart)
{
    MODIFY_REG(uart->FIFO.WORDVAL, UART_FIFO_RESET_MASK, UART_FIFO_RXFLUSH_M);
}

/**
  * \brief  Resets the transmitter FIFO
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  */
static inline void UART_resetTxFifo (UART_TypeDef* uart)
{
    MODIFY_REG(uart->FIFO.WORDVAL, UART_FIFO_RESET_MASK, UART_FIFO_TXFLUSH_M);
}

/**
  * \brief  Checks if received data is available in UART receive buffer
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \return Return \b true if data is available, otherwise return \b false
  */
static inline bool UART_isDataAvailable (UART_TypeDef* uart)
{
    return READ_BIT(uart->STAT.WORDVAL, UART_STAT_RDRF_M) ? true : false;
}

/**
  * \brief  Checks if transmit buffer is ready for new data
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \return Return \b true if space is available, otherwise return \b false
  */
static inline bool UART_isSpaceAvailable (UART_TypeDef* uart)
{
    return READ_BIT(uart->STAT.WORDVAL, UART_STAT_TDRE_M) ? true : false;
}

/**
  * \brief  Gets the current transmitter FIFO status
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \return Return the current transmitter FIFO status
  *                  This parameter can be any value of @ref UART_TXFIFOLEVEL
  */
static inline UART_TxFIFOLevel UART_getTxFifoStatus (UART_TypeDef* uart)
{
    return (UART_TxFIFOLevel)(READ_BIT(uart->WATER.WORDVAL, UART_WATER_TXCOUNT_M) >> \
            UART_WATER_TXCOUNT_S);
}

/**
  * \brief  Gets the current receiver FIFO status
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \return Return the current receiver FIFO status
  *                  This parameter can be any value of @ref UART_RXFIFOLEVEL
  */
static inline UART_RxFIFOLevel UART_getRxFifoStatus (UART_TypeDef* uart)
{
    return (UART_RxFIFOLevel)(READ_BIT(uart->WATER.WORDVAL, UART_WATER_RXCOUNT_M) >> \
            UART_WATER_RXCOUNT_S);
}

/**
  * \brief  Gets transmitter status
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \return Return \b true if transmitter is busy, otherwise return \b false
  */
static inline bool UART_isTransmitterBusy (UART_TypeDef* uart)
{
    return (((READ_BIT(uart->CTRL.WORDVAL, UART_CTRL_TE_M) == UART_CTRL_TE_M) &&  \
             (READ_BIT(uart->STAT.WORDVAL, UART_STAT_TC_M) == 0UL)) ? true : false);
}

/**
  * \brief  Writes 7-bit or 8-bit data to UART DATA register
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \param  data    UART data to be written
  */
static inline void UART_writeChar (UART_TypeDef* uart, uint8_t data)
{
    TYPE8(&uart->DATA.WORDVAL) = data;
}

/**
  * \brief  Writes 9-bit data to UART register
  * \note   This function writes the 9th data bit (T8) to the control register and the 8
  *         bits of data to the data register
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \param  data    UART data to be written
  */
static inline void UART_writeChar9 (UART_TypeDef* uart, uint16_t data)
{
    MODIFY_REG(uart->CTRL.WORDVAL, UART_CTRL_R9T8_M, (uint32_t)((data >> 8) & 0x1UL) << \
               UART_CTRL_R9T8_S);
    TYPE8(&uart->DATA.WORDVAL) = (uint8_t)(data & 0xFFUL);
}

/**
  * \brief  Writes 10-bit data to UART register
  * \note   This function writes the 9th (T8) and 10th (T9) data bits to the control register
  *         and the 8 bits of data to the data register
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \param  data    UART data to be written
  */
static inline void UART_writeChar10 (UART_TypeDef* uart, uint16_t data)
{
    /* write to ninth/tenth data bit (T[0:7]=8-bits, T8=9th bit, T9=10th bit) */
    MODIFY_REG(uart->CTRL.WORDVAL, UART_CTRL_R9T8_M | UART_CTRL_R8T9_M, \
              ((uint32_t)((data >> 8) & 0x1UL) << UART_CTRL_R9T8_S) | \
              ((uint32_t)((data >> 9) & 0x1UL) << UART_CTRL_R8T9_S));

    /* write 8-bits to the data register */
    TYPE8(&uart->DATA.WORDVAL) = (uint8_t)(data & 0xFFUL);
}

/**
  * \brief  Gets 7-bit or 8-bit data from the receive buffer
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \return Return the current received data
  */
static inline uint8_t UART_readChar (UART_TypeDef* uart)
{
    return (TYPE8(&uart->DATA.WORDVAL));
}

/**
  * \brief  Gets 9-bit data from the receive buffer
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \return Return the current received data
  */
static inline uint16_t UART_readChar9 (UART_TypeDef* uart)
{
    uint16_t readData;

    readData = (uint16_t)(((READ_REG(uart->CTRL.WORDVAL) >> UART_CTRL_R8T9_S) & 1UL) << 8);
    readData |= TYPE8(&uart->DATA.WORDVAL);

    return readData;
}

/**
  * \brief  Gets 10-bit data from the receive buffer
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \return Return the current received data
  */
static inline uint16_t UART_readChar10 (UART_TypeDef* uart)
{
    uint16_t readData;
    uint32_t tmp32 = READ_REG(uart->CTRL.WORDVAL);

    readData = (uint16_t)(((tmp32 >> UART_CTRL_R9T8_S) & 1UL) << 9);
    readData |= (uint16_t)(((tmp32 >> UART_CTRL_R8T9_S) & 1UL) << 8);
    readData |= (uint8_t)READ_REG(uart->DATA.WORDVAL);

    return readData;
}

/**
  * \brief  Gets the value of the status register
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \return Return current value of status register
  */
static inline uint16_t UART_getStatus (UART_TypeDef* uart)
{
    return (READ_REG(uart->STAT.WORDVAL));
}

/**
  * \brief  Software reset
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  */
static inline void UART_resetModule (UART_TypeDef* uart)
{
    WRITE_REG(uart->GLOBAL.WORDVAL, UART_GLOBAL_RST_M);
    __NOP();
    WRITE_REG(uart->GLOBAL.WORDVAL, 0UL);
}

/**
  * \brief  Enables UART internal loopback mode
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  */
static inline void UART_enableLoopback (UART_TypeDef* uart)
{
    MODIFY_REG(uart->CTRL.WORDVAL, UART_CTRL_RSRC_M, UART_CTRL_LOOPS_M);
}

/**
  * \brief  Disables UART internal loopback mode
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  */
static inline void UART_disableLoopback (UART_TypeDef* uart)
{
    CLEAR_BIT(uart->CTRL.WORDVAL, UART_CTRL_LOOPS_M);
}

/**
  * \brief  Clears the error flags
  * \note   Error flags include OR, NF, FE, PF
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \param  mask    UART error flag mask (supports bitwise OR of multiple flags)
  *                  - UART_STAT_OR_M
  *                  - UART_STAT_NF_M
  *                  - UART_STAT_FE_M
  *                  - UART_STAT_PF_M
  */
static inline void UART_clearErrorFlags (UART_TypeDef* uart, uint32_t mask)
{
    MODIFY_REG(uart->STAT.WORDVAL, UART_STAT_REG_FLAGS_MASK, mask);
}

/**
  * \brief  Enables UART interrupt source
  * \param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * \param  intSrc    UART interrupt source
  *                    This parameter can be any value of @ref UART_INTERRUPTSOURCE
  */
static inline void UART_enableInterrupt (UART_TypeDef* uart, UART_InterruptSource intSrc)
{
    if (!INT_W1C[intSrc])
    {
        SET_BIT(TYPE32((uint32_t)uart + INT_REG[intSrc]), INT_MASK[intSrc]);
    }
    else
    {
        MODIFY_REG(TYPE32((uint32_t)uart + INT_REG[intSrc]), UART_FIFO_RESET_MASK, INT_MASK[intSrc]);
    }
}

/**
  * \brief  Disables UART interrupt source
  * \param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * \param  intSrc    UART interrupt source
  *                    This parameter can be any value of @ref UART_INTERRUPTSOURCE
  */
static inline void UART_disableInterrupt (UART_TypeDef* uart, UART_InterruptSource intSrc)
{
    if (!INT_W1C[intSrc])
    {
        CLEAR_BIT(TYPE32((uint32_t)uart + INT_REG[intSrc]), INT_MASK[intSrc]);
    }
    else
    {
        CLEAR_BIT(TYPE32((uint32_t)uart + INT_REG[intSrc]), UART_FIFO_RESET_MASK | INT_MASK[intSrc]);
    }
}

/**
  * \brief  Checks if UART interrupt source is enabled
  * \param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * \param  intSrc    UART interrupt source
  *                    This parameter can be any value of @ref UART_INTERRUPTSOURCE
  * \return Return \b true if interrupt source is enabled, otherwise return \b false
  */
static inline bool UART_getIntMode (UART_TypeDef* uart, UART_InterruptSource intSrc)
{
    return READ_BIT(TYPE32((uint32_t)uart + INT_REG[intSrc]), INT_MASK[intSrc]) ? true : false;
}

/**
  * \brief  Gets specified status flag
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \param  flag    UART status flag
  *                  This parameter can be any value of @ref UART_STATUSFLAG
  * \return Return \b true if flag is set, otherwise return \b false
  */
static inline bool UART_getStatusFlag (UART_TypeDef* uart, UART_StatusFlag flag)
{
    return READ_BIT(TYPE32((uint32_t)uart + STATUS_REG[flag]), STATUS_MASK[flag]) ? true : false;
}

/**
  * \brief  Clears an individual status flag
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \param  flag    UART status flag
  *                  This parameter can be any value of @ref UART_STATUSFLAG
  */
static inline void UART_clearStatusFlag (UART_TypeDef* uart, UART_StatusFlag flag)
{
    if (flag < UART_RX_DATA_REG_FULL)
    {
        if (!STATUS_W1C[flag])
        {
            MODIFY_REG(TYPE32((uint32_t)uart + STATUS_REG[flag]), UART_STAT_REG_FLAGS_MASK, STATUS_MASK[flag]);
        }
        else
        {
            MODIFY_REG(TYPE32((uint32_t)uart + STATUS_REG[flag]), UART_FIFO_RESET_MASK, STATUS_MASK[flag]);
        }
    }
}

/**
  * \brief  Sets the data bit transmission order (MSB/LSB first)
  * \note   This field should only be changed when the transmitter and receiver are both disabled
  * \param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * \param  enable    UART data order selection
  *                    - true:  MSB first (Most Significant Bit first)
  *                    - false: LSB first (Least Significant Bit first)
  */
static inline void UART_setMSB (UART_TypeDef* uart, bool enable)
{
    MODIFY_REG(uart->STAT.WORDVAL, UART_STAT_REG_FLAGS_MASK, enable ? UART_STAT_MSBF_M : 0UL);
}

/**
  * \brief  Sets the number of bits per character
  * \param  uart               UART port address
  *                             - UART1: UART1 base address index
  *                             - UART2: UART2 base address index
  *                             - UART3: UART3 base address index
  *                             - UART4: UART4 base address index
  * \param  bitCountPerChar    The number of bits per character
  *                              This parameter can be any value of @ref UART_BITCOUNTPERCHAR
  * \param  parity             UART parity
  *                             - true:  Parity will be used (bit count should include parity bit)
  *                             - false: Parity will not be used (bit count does not include parity)
  */
static inline void UART_setBitCountPerChar (UART_TypeDef* uart, UART_BitCountPerChar bitCountPerChar, bool parity)
{
    uint32_t tmpBitCountPerChar = (uint32_t)bitCountPerChar;

    if (parity == true)
    {
        tmpBitCountPerChar += 1UL;
    }

    if (bitCountPerChar == UART_7_BITS_PER_CHAR)
    {
        MODIFY_REG(uart->CTRL.WORDVAL, (UART_CTRL_M_M | UART_CTRL_M7_M), (parity ? 0UL : UART_CTRL_M7_M));
        CLEAR_BIT(uart->BAUD.WORDVAL, UART_BAUD_M10_M);
    }
    else if (tmpBitCountPerChar == UART_10_BITS_PER_CHAR)
    {
        SET_BIT(uart->BAUD.WORDVAL, UART_BAUD_M10_M);
    }
    else
    {
        /* Config 8-bit (M=0) or 9-bits (M=1) */
        MODIFY_REG(uart->CTRL.WORDVAL, UART_CTRL_M_M, tmpBitCountPerChar << 4);

        /* Clear M10 to make sure not 10-bit mode */
        CLEAR_BIT(uart->BAUD.WORDVAL, UART_BAUD_M10_M);
    }
}

/**
  * \brief  Sets the number of stop bits
  * \param  uart            UART port address
  *                          - UART1: UART1 base address index
  *                          - UART2: UART2 base address index
  *                          - UART3: UART3 base address index
  *                          - UART4: UART4 base address index
  * \param  stopBitCount    The number of stop bits
  *                          This parameter can be any value of @ref UART_STOPBITCOUNT
  */
static inline void UART_setStopBitCount (UART_TypeDef* uart, UART_StopBitCount stopBitCount)
{
    MODIFY_REG(uart->BAUD.WORDVAL, UART_BAUD_SBNS_M, (uint32_t)stopBitCount << 13);
}

/**
  * \brief  Sets receiver idle empty enable
  * \note   When set, enables the assertion of RDRF when the receiver is idle for a number of idle
  *         characters and the FIFO is not empty
  * \param  uart    UART port address
  *                  - UART1: UART1 base address index
  *                  - UART2: UART2 base address index
  *                  - UART3: UART3 base address index
  *                  - UART4: UART4 base address index
  * \param  cnt     UART receiver idle character count
  *                  This parameter can be any value of @ref UART_RECEIVERIDLECHARCNT
  */
static inline void UART_setRxIdleCharacter (UART_TypeDef* uart, UART_ReceiverIdleCharCnt cnt)
{
    MODIFY_REG(uart->FIFO.WORDVAL, UART_FIFO_RESET_MASK | UART_FIFO_RXIDEN_M, \
               (uint32_t)(cnt << UART_FIFO_RXIDEN_S));
}

/**
  * \brief  Sets DMA request for transmitter
  * \param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * \param  enable    UART DMA request control
  *                    - true:  Enables transmitter DMA request
  *                    - false: Disables transmitter DMA request
  */
static inline void UART_setTxDmaCmd (UART_TypeDef* uart, bool enable)
{
    MODIFY_REG(uart->BAUD.WORDVAL, UART_BAUD_TDMAE_M, (enable ? UART_BAUD_TDMAE_M : 0UL));
}

/**
  * \brief  Sets DMA request for receiver
  * \param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * \param  enable    UART DMA request control
  *                    - true:  Enables receiver DMA request
  *                    - false: Disables receiver DMA request
  */
static inline void UART_setRxDmaCmd (UART_TypeDef* uart, bool enable)
{
    MODIFY_REG(uart->BAUD.WORDVAL, UART_BAUD_RDMAE_M, (enable ? UART_BAUD_RDMAE_M : 0UL));
}

/**
  * \brief  Sets UART baud rate
  * \param  uart        UART port address
  *                      - UART1: UART1 base address index
  *                      - UART2: UART2 base address index
  *                      - UART3: UART3 base address index
  *                      - UART4: UART4 base address index
  * \param  baudrate    UART Baud rate value to set
  */
extern void UART_setBaud (UART_TypeDef* uart, uint32_t baudrate);

/**
  * \brief  Writes a character array to UART transmitter
  * \note   Supports only 7-bit and 8-bit character formats
  * \param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * \param  array     Pointer to transmit data buffer
  * \param  length    Number of bytes to transmit
  */
extern void UART_writeCharArray (UART_TypeDef* uart, const uint8_t *const array, uint16_t length);

/**
  * \brief  Reads a character array from UART receiver
  * \note   Supports only 7-bit and 8-bit character formats
  * \param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * \param  array     Pointer to receive data buffer
  * \param  length    Number of bytes to receive
  */
extern void UART_readCharArray (UART_TypeDef* uart, uint8_t *const array, uint16_t length);

/**
  * \brief  Writes a character array to UART transmitter
  * \note   Supports only 9-bit character formats
  * \param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * \param  array     Pointer to transmit data buffer
  * \param  length    Number of bytes to transmit
  */
extern void UART_writeChar9Array (UART_TypeDef* uart, const uint16_t *const array, uint16_t length);

/**
  * \brief  Reads a character array from UART receiver
  * \note   Supports only 9-bit character formats
  * \param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * \param  array     Pointer to receive data buffer
  * \param  length    Number of bytes to receive
  */
extern void UART_readChar9Array (UART_TypeDef* uart, uint16_t *const array, uint16_t length);

/**
  * \brief  Writes a character array to UART transmitter
  * \note   Supports only 10-bit character formats
  * \param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * \param  array     Pointer to transmit data buffer
  * \param  length    Number of bytes to transmit
  */
extern void UART_writeChar10Array (UART_TypeDef* uart, const uint16_t *const array, uint16_t length);

/**
  * \brief  Reads a character array from UART receiver
  * \note   Supports only 10-bit character formats
  * \param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * \param  array     Pointer to receive data buffer
  * \param  length    Number of bytes to receive
  */
extern void UART_readChar10Array (UART_TypeDef* uart, uint16_t *const array, uint16_t length);


#ifdef __cplusplus
}
#endif


#endif /* __UART_H__ */
