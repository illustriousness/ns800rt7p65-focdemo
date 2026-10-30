/**
  * @file       spi.h
  * @author     Zhoukai, Alex-j
  * @brief      Header file for NS800RT7xxx spi module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __SPI_H__
#define __SPI_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup SPI_EXPORTED_TYPES SPI Exported Types
 *  @{
 *  @brief  Macro definitions are used with all files publicly about 'SPI' module.
 */

/** @defgroup SPI_CMD_NUM_MAX SPI Command Number Maxium
 *  @{
 *  @brief  Macro definitions about the SPI maxium of command-number
 */
#define SPI_CMD_NUM_MAX    (8UL)    /*!< SPI CMD number max */

/**
 *  @}
 */

/** @defgroup SPI_NCS_CONFIG SPI Negative Chip Select Config
 *  @{
 *  @brief  Macro definitions about the spi negative chip select config to low/high for application
 */
#define SPI_NCS_LOW     (0x00000000UL)    /*!< SPI NCS LOW */
#define SPI_MCS_HIGH    (0x00000001UL)    /*!< SPI NCS HIGH */

/**
 *  @}
 */

/** @defgroup SPI_CLK_DIV SPI Master Clk Divider Boundary Value
 *  @{
 *  @brief  Macro definitions about the spi clk divider boundary value for application
 */
#define SPI_CLK_N_DIV_MULTIPLIER    (0x00000200UL)    /*!< Maximum divider for N=0 */
#define SPI_CLK_MAX_DIV             (0x00001000UL)    /*!< Maximum SPI CLK divider */
#define SPI_CLK_MIN_DIV             (0x00000002UL)    /*!< Minimum SPI CLK divider */

/**
 *  @}
 */

/** @defgroup SPI_INTERRUPT_SOURCE SPI Interrupt Source
 *  @{
 *  @brief  Macro definitions about the spi Interrupt Source for application
 */
#define SPI_INT_ERROR    (SPI_SPCR1_SPEIE_M)     /*!< SPI error interrupt source */
#define SPI_INT_RF       (SPI_SPCR1_SPRIE_M)     /*!< SPI receive data full interrupt source */
#define SPI_INT_IDLN     (SPI_SPCR1_SPIIE_M)     /*!< SPI not idle interrupt source */
#define SPI_INT_TE       (SPI_SPCR1_SPTIE_M)     /*!< SPI transmit data empty interrupt source */
#define SPI_INT_CEND     (SPI_SPCR1_CENDIE_M)    /*!< SPI communication end interrupt source */

/**
 *  @}
 */

/** @defgroup SPI_FLAGS SPI Flags
 *  @{
 *  @brief  Macro definitions about the spi flags for application
 */
#define SPI_FLAG_DR      (SPI_SPSR_SPDRF_M)    /*!< SPI data ready flag */
#define SPI_FLAG_OVR     (SPI_SPSR_OVRF_M)     /*!< SPI rxfifo overflow flag */
#define SPI_FLAG_IDLN    (SPI_SPSR_IDLNF_M)    /*!< SPI not idle flag */
#define SPI_FLAG_MODE    (SPI_SPSR_MODF_M)     /*!< SPI mode error flag */
#define SPI_FLAG_PER     (SPI_SPSR_PERF_M)     /*!< SPI parity error flag */
#define SPI_FLAG_UDR     (SPI_SPSR_UDRF_M)     /*!< SPI txfifo underflow flag */
#define SPI_FLAG_TE      (SPI_SPSR_SPTEF_M)    /*!< SPI transmit data empty flag */
#define SPI_FLAG_CEND    (SPI_SPSR_CENDF_M)    /*!< SPI communication end flag */
#define SPI_FLAG_RF      (SPI_SPSR_SPRF_M)     /*!< SPI receive data full flag */

/**
 *  @}
 */

/** @defgroup SPI_CLEAR_FLAGS SPI Clear Flags
 *  @{
 *  @brief  Macro definitions about the spi clear flags for application
 */
#define SPI_CLEAR_DR      (SPI_SPSCR_RFDN_M)      /*!< SPI data ready clear flag */
#define SPI_CLEAR_OVR     (SPI_SPSCR_OVRFC_M)     /*!< SPI rxfifo overflow clear flag */
#define SPI_CLEAR_MODE    (SPI_SPSCR_MODFC_M)     /*!< SPI mode error clear flag */
#define SPI_CLEAR_PER     (SPI_SPSCR_PERFC_M)     /*!< SPI parity error clear flag */
#define SPI_CLEAR_UDR     (SPI_SPSCR_UDRFC_M)     /*!< SPI txfifo underflow clear flag */
#define SPI_CLEAR_TE      (SPI_SPSCR_SPTEFC_M)    /*!< SPI transmit data empty clear flag */
#define SPI_CLEAR_CEND    (SPI_SPSCR_CENDFC_M)    /*!< SPI communication end clear flag */
#define SPI_CLEAR_RF      (SPI_SPSCR_SPRFC_M)     /*!< SPI receive data full clear flag */

/**
 *  @}
 */

/** @defgroup SPI_TRANSFERPROTOCOL SPI Transport Protocol
 *  @{
 *  @brief  Macro definitions about the SPI PHA & POL for application
 */
typedef enum {
    SPI_PROT_POL0PHA0 = 0U,    /*!< Mode 0. Polarity 0, phase 0. */
    SPI_PROT_POL0PHA1,         /*!< Mode 1. Polarity 0, phase 1. */
    SPI_PROT_POL1PHA0,         /*!< Mode 2. Polarity 1, phase 0. */
    SPI_PROT_POL1PHA1          /*!< Mode 3. Polarity 1, phase 1. */
} SPI_TransferProtocol;

/**
 *  @}
 */

/** @defgroup SPI_MODE SPI Mode Config
 *  @{
 *  @brief  Macro definitions about the SPI number of slave/master for application
 */
typedef enum {
    SPI_SLAVE_MODE = 0U,    /*!< SPI slave mode */
    SPI_MASTER_MODE         /*!< SPI master mode */
} SPI_Mode;

/**
 *  @}
 */

/** @defgroup SPI_NCSPOL SPI Negative Chip Select Polarity Config
 *  @{
 *  @brief  Macro definitions about SPI negative chip select polarity active low or high for application
 */
typedef enum {
    SPI_NCS_POLARITY_ACTIVE_LOW = 0U,    /*!< SPI NCS polarity low*/
    SPI_NCS_POLARITY_ACTIVE_HIGH         /*!< SPI NCS polarity high*/
} SPI_NcsPol;

/**
 *  @}
 */

/** @defgroup SPI_BITORDER SPI Bit Order Config
 *  @{
 *  @brief  Macro definitions about SPI bit order MSB or LSB config for application
 */
typedef enum {
    SPI_BIT_ORDER_MSB_FIRST = 0U,    /*!< SPI bit order first msb */
    SPI_BIT_ORDER_LSB_FIRST          /*!< SPI bit order first lsb */
} SPI_BitOrder;

/**
 *  @}
 */

/** @defgroup SPI_COMMMODE SPI Communication Mode Config
 *  @{
 *  @brief  Macro definitions about SPI communication mode full-duplex/send-only/receive-only config for application
 */
typedef enum {
    SPI_FULL_DUPLEX_COMM_MODE = 0U,    /*!< SPI full duplex comm mode */
    SPI_TX_ONLY_COMM_MODE,             /*!< SPI send only comm mode */
    SPI_RX_ONLY_COMM_MODE              /*!< SPI receive only comm mode */
} SPI_CommMode;

/**
 *  @}
 */

/** @defgroup SPI_MOSIIDLEFIXEDVALUE SPI Master Output Slave Input line Idle Value Config
 *  @{
 *  @brief  Macro definitions about SPI master output slave input line idle status low or high config
 */
typedef enum {
    SPI_MOSI_IDLE_FIXED_VALUE_LOW = 0U,    /*!< MOSI level low during MOSI idling */
    SPI_MOSI_IDLE_FIXED_VALUE_HIGH         /*!< MOSI level high during MOSI idling */
} SPI_MosiIdleFixedValue;

/**
 *  @}
 */

/** @defgroup SPI_PARITY SPI Parity Mode Config
 *  @{
 *  @brief  Macro definitions about SPI parity mode odd or even config
 */
typedef enum {
    SPI_PARITY_MODE_ODD = 0U,    /*!< Select even parity */
    SPI_PARITY_MODE_EVEN         /*!< Select odd parity */
} SPI_Parity;

/**
 *  @}
 */

/** @defgroup SPI_DMATYPE SPI DMA Work Mode Config
 *  @{
 *  @brief  Macro definitions about SPI dma work mode send/receive/duplex config
 */
typedef enum {
    SPI_DMA_MODE_TRANSFER = 0U,    /*!< Select DMA send */
    SPI_DMA_MODE_RECEIVE,          /*!< Select DMA receive */
    SPI_DMA_MODE_DUPLEX            /*!< Select DMA duplex */
} SPI_DmaType;

/**
 *  @}
 */

/** @defgroup SPI_BITWIDTH SPI Data Width Config
 *  @{
 *  @brief  Macro definitions about SPI bit width 4~32 config for application
 */
typedef enum {
    SPI_BIT_WIDTH_4_BITS = 3U,    /*!< SPI WIDTH 4BITS */
    SPI_BIT_WIDTH_5_BITS,         /*!< SPI WIDTH 5BITS */
    SPI_BIT_WIDTH_6_BITS,         /*!< SPI WIDTH 6BITS */
    SPI_BIT_WIDTH_7_BITS,         /*!< SPI WIDTH 7BITS */
    SPI_BIT_WIDTH_8_BITS,         /*!< SPI WIDTH 8BITS */
    SPI_BIT_WIDTH_9_BITS,         /*!< SPI WIDTH 9BITS */
    SPI_BIT_WIDTH_10_BITS,        /*!< SPI WIDTH 10BITS */
    SPI_BIT_WIDTH_11_BITS,        /*!< SPI WIDTH 11BITS */
    SPI_BIT_WIDTH_12_BITS,        /*!< SPI WIDTH 12BITS */
    SPI_BIT_WIDTH_13_BITS,        /*!< SPI WIDTH 13BITS */
    SPI_BIT_WIDTH_14_BITS,        /*!< SPI WIDTH 14BITS */
    SPI_BIT_WIDTH_15_BITS,        /*!< SPI WIDTH 15BITS */
    SPI_BIT_WIDTH_16_BITS,        /*!< SPI WIDTH 16BITS */
    SPI_BIT_WIDTH_17_BITS,        /*!< SPI WIDTH 17BITS */
    SPI_BIT_WIDTH_18_BITS,        /*!< SPI WIDTH 18BITS */
    SPI_BIT_WIDTH_19_BITS,        /*!< SPI WIDTH 19BITS */
    SPI_BIT_WIDTH_20_BITS,        /*!< SPI WIDTH 20BITS */
    SPI_BIT_WIDTH_21_BITS,        /*!< SPI WIDTH 21BITS */
    SPI_BIT_WIDTH_22_BITS,        /*!< SPI WIDTH 22BITS */
    SPI_BIT_WIDTH_23_BITS,        /*!< SPI WIDTH 23BITS */
    SPI_BIT_WIDTH_24_BITS,        /*!< SPI WIDTH 24BITS */
    SPI_BIT_WIDTH_25_BITS,        /*!< SPI WIDTH 25BITS */
    SPI_BIT_WIDTH_26_BITS,        /*!< SPI WIDTH 26BITS */
    SPI_BIT_WIDTH_27_BITS,        /*!< SPI WIDTH 27BITS */
    SPI_BIT_WIDTH_28_BITS,        /*!< SPI WIDTH 28BITS */
    SPI_BIT_WIDTH_29_BITS,        /*!< SPI WIDTH 29BITS */
    SPI_BIT_WIDTH_30_BITS,        /*!< SPI WIDTH 30BITS */
    SPI_BIT_WIDTH_31_BITS,        /*!< SPI WIDTH 31BITS*/
    SPI_BIT_WIDTH_32_BITS         /*!< SPI WIDTH 32BITS */
} SPI_BitWidth;

/**
 *  @}
 */

/** @defgroup SPI_CMDSEQUENCE SPI Command Sequence Length
 *  @{
 *  @brief  Macro definitions about SPI command sequence length for application
 */
typedef enum {
    SPI_CMD_SEQUENCE_0_0 = 0U,    /*!< SPI cmd sequence 0 to 0 */
    SPI_CMD_SEQUENCE_0_1,         /*!< SPI cmd sequence 0 to 1 */
    SPI_CMD_SEQUENCE_0_2,         /*!< SPI cmd sequence 0 to 2 */
    SPI_CMD_SEQUENCE_0_3,         /*!< SPI cmd sequence 0 to 3 */
    SPI_CMD_SEQUENCE_0_4,         /*!< SPI cmd sequence 0 to 4 */
    SPI_CMD_SEQUENCE_0_5,         /*!< SPI cmd sequence 0 to 5 */
    SPI_CMD_SEQUENCE_0_6,         /*!< SPI cmd sequence 0 to 6 */
    SPI_CMD_SEQUENCE_0_7          /*!< SPI cmd sequence 0 to 7 */
} SPI_CmdSequence;

/**
 *  @}
 */

/** @defgroup SPI_SPCR2SPOM SPI Pin Output Mode
 *  @{
 *  @brief  Macro definitions about SPI pin output mode config cmos or opendrain for application
 */
typedef enum {
    SPI_SPOM_CMOS = 0U,    /*!< SPI SPOM CMOS */
    SPI_SPOM_OPENDRAIN     /*!< SPI SPOM OPENDRAIN */
} SPI_Spcr2Spom;

/**
 *  @}
 */

/** @defgroup SPI_SPDRDIRECTION SPI SPDR Read FIFO Direction Config
 *  @{
 *  @brief  Macro definitions about SPI SPDR read fifo direction config for application
 */
typedef enum {
    SPI_SPDRDIR_TXFIFO = 0U,    /*!< SPI spdata read from TX FIFO */
    SPI_SPDRDIR_RXFIFO          /*!< SPI spdata read from RX FIFO */
} SPI_SpdrDirection;

/**
 *  @}
 */

/** @defgroup SPI_TXINTRFIFOTHRESHOLD  SPI Send FIFO Interrupt Threshold Config
 *  @{
 *  @brief  Macro definitions about SPI send fifo interrupt threshold 0x00~0x0F for application
 */
typedef enum {
    SPI_TX_INTERRUPT_FIFO_THRESHOLD0 = 0U,    /*!< Transmit FIFO Interrupt Threshold 0 */
    SPI_TX_INTERRUPT_FIFO_THRESHOLD1,         /*!< Transmit FIFO Interrupt Threshold 1 */
    SPI_TX_INTERRUPT_FIFO_THRESHOLD2,         /*!< Transmit FIFO Interrupt Threshold 2 */
    SPI_TX_INTERRUPT_FIFO_THRESHOLD3,         /*!< Transmit FIFO Interrupt Threshold 3 */
    SPI_TX_INTERRUPT_FIFO_THRESHOLD4,         /*!< Transmit FIFO Interrupt Threshold 4 */
    SPI_TX_INTERRUPT_FIFO_THRESHOLD5,         /*!< Transmit FIFO Interrupt Threshold 5 */
    SPI_TX_INTERRUPT_FIFO_THRESHOLD6,         /*!< Transmit FIFO Interrupt Threshold 6 */
    SPI_TX_INTERRUPT_FIFO_THRESHOLD7,         /*!< Transmit FIFO Interrupt Threshold 7 */
    SPI_TX_INTERRUPT_FIFO_THRESHOLD8,         /*!< Transmit FIFO Interrupt Threshold 8 */
    SPI_TX_INTERRUPT_FIFO_THRESHOLD9,         /*!< Transmit FIFO Interrupt Threshold 9 */
    SPI_TX_INTERRUPT_FIFO_THRESHOLD10,        /*!< Transmit FIFO Interrupt Threshold 10 */
    SPI_TX_INTERRUPT_FIFO_THRESHOLD11,        /*!< Transmit FIFO Interrupt Threshold 11 */
    SPI_TX_INTERRUPT_FIFO_THRESHOLD12,        /*!< Transmit FIFO Interrupt Threshold 12 */
    SPI_TX_INTERRUPT_FIFO_THRESHOLD13,        /*!< Transmit FIFO Interrupt Threshold 13 */
    SPI_TX_INTERRUPT_FIFO_THRESHOLD14,        /*!< Transmit FIFO Interrupt Threshold 14 */
    SPI_TX_INTERRUPT_FIFO_THRESHOLD15         /*!< Transmit FIFO Interrupt Threshold 15 */
} SPI_TxIntrFifoThreshold;

/**
 *  @}
 */

/** @defgroup SPI_RXINTRFIFOTHRESHOLD SPI Receive FIFO Interrupt Threshold Config
 *  @{
 *  @brief  Macro definitions about SPI receive fifo interrupt threshold 0x00~0x0F for application
 */
typedef enum {
    SPI_RX_INTERRUPT_FIFO_THRESHOLD0 = 0U,    /*!< Receive FIFO Interrupt Threshold 0 */
    SPI_RX_INTERRUPT_FIFO_THRESHOLD1,         /*!< Receive FIFO Interrupt Threshold 1 */
    SPI_RX_INTERRUPT_FIFO_THRESHOLD2,         /*!< Receive FIFO Interrupt Threshold 2 */
    SPI_RX_INTERRUPT_FIFO_THRESHOLD3,         /*!< Receive FIFO Interrupt Threshold 3 */
    SPI_RX_INTERRUPT_FIFO_THRESHOLD4,         /*!< Receive FIFO Interrupt Threshold 4 */
    SPI_RX_INTERRUPT_FIFO_THRESHOLD5,         /*!< Receive FIFO Interrupt Threshold 5 */
    SPI_RX_INTERRUPT_FIFO_THRESHOLD6,         /*!< Receive FIFO Interrupt Threshold 6 */
    SPI_RX_INTERRUPT_FIFO_THRESHOLD7,         /*!< Receive FIFO Interrupt Threshold 7 */
    SPI_RX_INTERRUPT_FIFO_THRESHOLD8,         /*!< Receive FIFO Interrupt Threshold 8 */
    SPI_RX_INTERRUPT_FIFO_THRESHOLD9,         /*!< Receive FIFO Interrupt Threshold 9 */
    SPI_RX_INTERRUPT_FIFO_THRESHOLD10,        /*!< Receive FIFO Interrupt Threshold 10 */
    SPI_RX_INTERRUPT_FIFO_THRESHOLD11,        /*!< Receive FIFO Interrupt Threshold 11 */
    SPI_RX_INTERRUPT_FIFO_THRESHOLD12,        /*!< Receive FIFO Interrupt Threshold 12 */
    SPI_RX_INTERRUPT_FIFO_THRESHOLD13,        /*!< Receive FIFO Interrupt Threshold 13 */
    SPI_RX_INTERRUPT_FIFO_THRESHOLD14,        /*!< Receive FIFO Interrupt Threshold 14 */
    SPI_RX_INTERRUPT_FIFO_THRESHOLD15         /*!< Receive FIFO Interrupt Threshold 15 */
} SPI_RxIntrFifoThreshold;

/**
 *  @}
 */

/** @defgroup SPI_TXFIFOLEVEL SPI Send FIFO Level Config
 *  @{
 *  @brief  Macro definitions about SPI send fifo level config 0x00~0x10 for application
 */
typedef enum {
    SPI_FIFO_TXFULL = 0x0000U,     /*!< Transmit FIFO full */
    SPI_FIFO_TX0 = 0x0000U,        /*!< Transmit FIFO full */
    SPI_FIFO_TX1,                  /*!< Transmit FIFO 15/16 full */
    SPI_FIFO_TX2,                  /*!< Transmit FIFO 14/16 full */
    SPI_FIFO_TX3,                  /*!< Transmit FIFO 13/16 full */
    SPI_FIFO_TX4,                  /*!< Transmit FIFO 12/16 full */
    SPI_FIFO_TX5,                  /*!< Transmit FIFO 11/16 full */
    SPI_FIFO_TX6,                  /*!< Transmit FIFO 10/16 full */
    SPI_FIFO_TX7,                  /*!< Transmit FIFO 9/16 full */
    SPI_FIFO_TX8,                  /*!< Transmit FIFO 8/16 full */
    SPI_FIFO_TX9,                  /*!< Transmit FIFO 7/16 full */
    SPI_FIFO_TX10,                 /*!< Transmit FIFO 6/16 full */
    SPI_FIFO_TX11,                 /*!< Transmit FIFO 5/16 full */
    SPI_FIFO_TX12,                 /*!< Transmit FIFO 4/16 full */
    SPI_FIFO_TX13,                 /*!< Transmit FIFO 3/16 full */
    SPI_FIFO_TX14,                 /*!< Transmit FIFO 2/16 full */
    SPI_FIFO_TX15,                 /*!< Transmit FIFO 1/16 full */
    SPI_FIFO_TX16,                 /*!< Transmit FIFO empty */
    SPI_FIFO_TXEMPTY = 0x0010U     /*!< Transmit FIFO empty */
} SPI_TxFifoLevel;

/**
 *  @}
 */

/** @defgroup SPI_RXFIFOLEVEL SPI Receive FIFO Level Config
 *  @{
 *  @brief  Macro definitions about SPI Receive fifo level config 0x00~0x10 for application
 */
typedef enum {
    SPI_FIFO_RXEMPTY = 0x0000U,     /*!< Receive FIFO empty */
    SPI_FIFO_RX0 = 0x0000U,         /*!< Receive FIFO empty */
    SPI_FIFO_RX1,                   /*!< Receive FIFO 1/16 full */
    SPI_FIFO_RX2,                   /*!< Receive FIFO 2/16 full */
    SPI_FIFO_RX3,                   /*!< Receive FIFO 3/16 full */
    SPI_FIFO_RX4,                   /*!< Receive FIFO 4/16 full */
    SPI_FIFO_RX5,                   /*!< Receive FIFO 5/16 full */
    SPI_FIFO_RX6,                   /*!< Receive FIFO 6/16 full */
    SPI_FIFO_RX7,                   /*!< Receive FIFO 7/16 full */
    SPI_FIFO_RX8,                   /*!< Receive FIFO 8/16 full */
    SPI_FIFO_RX9,                   /*!< Receive FIFO 9/16 full */
    SPI_FIFO_RX10,                  /*!< Receive FIFO 10/16 full */
    SPI_FIFO_RX11,                  /*!< Receive FIFO 11/16 full */
    SPI_FIFO_RX12,                  /*!< Receive FIFO 12/16 full */
    SPI_FIFO_RX13,                  /*!< Receive FIFO 13/16 full */
    SPI_FIFO_RX14,                  /*!< Receive FIFO 14/16 full */
    SPI_FIFO_RX15,                  /*!< Receive FIFO 15/16 full */
    SPI_FIFO_RX16,                  /*!< Receive FIFO full */
    SPI_FIFO_RXFULL = 0x0010U       /*!< Receive FIFO full */
} SPI_RxFifoLevel;

/**
 *  @}
 */

/** @defgroup SPI_ENDIANNESS SPI Endianness Config
 *  @{
 *  @brief  Macro definitions about SPI endianness config litter or big endian mode
 */
typedef enum {
    SPI_DATA_LITTLE_ENDIAN = 0U,    /*!< LITTLE ENDIAN */
    SPI_DATA_BIG_ENDIAN             /*!< BIG ENDIAN */
} SPI_Endianness;

/**
 *  @}
 */

/**
 *  @}
 */


/******************************************************************************
 * Functions
 ******************************************************************************/

/**
 * \brief  SPI enale module
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_enableModule (SPI_TypeDef *spi)
{
    SET_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPE_M);
}

/**
 * \brief  SPI disable module
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_disableModule (SPI_TypeDef *spi)
{
    CLEAR_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPE_M);
}

/**
 * \brief  SPI send/receive data, used in full duplex mode
 * \param  spi   SPI pointer to a SPI_TypeDef structure
 *                - SPI1: SPI1 base address index
 *                - SPI2: SPI2 base address index
 *                - SPI3: SPI3 base address index
 *                - SPI4: SPI4 base address index
 * \param  data  Data spi wish to send
 * \return returned spi receive data
 */
static inline uint32_t SPI_transmitReceive (SPI_TypeDef *spi, uint32_t data)
{
    WRITE_REG(spi->SPDR.WORDVAL, data);
    while (spi->SPRFSR.BIT.RFDN == SPI_FIFO_RXEMPTY)
    {
    }

    return READ_REG(spi->SPDR.WORDVAL);
}

/**
 * \brief  SPI receive/send data config DMA
 * \param  spi   SPI pointer to a SPI_TypeDef structure
 *                - SPI1: SPI1 base address index
 *                - SPI2: SPI2 base address index
 *                - SPI3: SPI3 base address index
 *                - SPI4: SPI4 base address index
 * \param  mode  SPI DMA Typedef
 *                This parameter can be any value of @ref SPI_DMATYPE
 */
static inline void SPI_configDMASendAndReceive (SPI_TypeDef *spi, SPI_DmaType mode)
{
    SPI_disableModule(spi);

    if (mode == SPI_DMA_MODE_RECEIVE)
    {
        SET_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_RXDMAEN_M);
    }
    else if (mode == SPI_DMA_MODE_TRANSFER)
    {
        SET_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_TXDMAEN_M);
    }
    else
    {
        SET_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_RXDMAEN_M | SPI_SPCR1_TXDMAEN_M);
    }
}

/**
 * \brief  SPI enable MOSI idle fixed value
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_enableMOSIIdleValue (SPI_TypeDef *spi)
{
    SET_BIT(spi->SPCR2.WORDVAL, SPI_SPCR2_MOIFE_M);
}

/**
 * \brief  SPI disable MOSI idle fixed value
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_disableMOSIIdleValue (SPI_TypeDef *spi)
{
    CLEAR_BIT(spi->SPCR2.WORDVAL, SPI_SPCR2_MOIFE_M);
}

/**
 * \brief  SPI Set MOSI idle fixed value
 * \param  spi    SPI pointer to a SPI_TypeDef structure
 *                 - SPI1: SPI1 base address index
 *                 - SPI2: SPI2 base address index
 *                 - SPI3: SPI3 base address index
 *                 - SPI4: SPI4 base address index
 * \param  value  SPOM CMOS/OPEN DRIVER
 *                 This parameter can be any value of @ref SPI_MosiIdleFixedValue
 */
static inline void SPI_setMOSIIdleValue (SPI_TypeDef *spi, SPI_MosiIdleFixedValue value)
{
    MODIFY_REG(spi->SPCR2.WORDVAL, SPI_SPCR2_MOIFV_M, (value << SPI_SPCR2_MOIFV_S));
}

/**
 * \brief  SPI Set output pin work mode
 * \param  spi   SPI pointer to a SPI_TypeDef structure
 *                - SPI1: SPI1 base address index
 *                - SPI2: SPI2 base address index
 *                - SPI3: SPI3 base address index
 *                - SPI4: SPI4 base address index
 * \param  mode  SPOM CMOS/OPEN DRIVER
 *                This parameter can be any value of @ref SPI_SPCR2SPOM
 */
static inline void SPI_setPinMode (SPI_TypeDef *spi, SPI_Spcr2Spom mode)
{
    if (mode == SPI_SPOM_CMOS)
    {
        CLEAR_BIT(spi->SPCR2.WORDVAL, SPI_SPCR2_SPOM_M);
    }
    else
    {
        SET_BIT(spi->SPCR2.WORDVAL, SPI_SPCR2_SPOM_M);
    }
}

/**
 * \brief  SPI config Read Data Direction 
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 * \param  dir  SPDR RECEIVE/SEND
 *               This parameter can be any value of @ref SPI_SpdrDirection
 */
static inline void SPI_configDataDirection (SPI_TypeDef *spi, SPI_SpdrDirection dir)
{
    MODIFY_REG(spi->SPDCR1.WORDVAL, SPI_SPDCR1_SPRDTD_M, (dir << SPI_SPDCR1_SPRDTD_S));
}

/**
 * \brief  SPI Enable Data Swapping
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_enableDataSwapping (SPI_TypeDef *spi)
{
    SET_BIT(spi->SPDCR1.WORDVAL, SPI_SPDCR1_BYSW_M);
}

/**
 * \brief  SPI Disable Data Swapping
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_disableDataSwapping (SPI_TypeDef *spi)
{
    CLEAR_BIT(spi->SPDCR1.WORDVAL, SPI_SPDCR1_BYSW_M);
}

/**
 * \brief  SPI Enable Serial Data Inversion
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_enableSerialDataInversion (SPI_TypeDef *spi)
{
    SET_BIT(spi->SPDCR1.WORDVAL, SPI_SPDCR1_SINV_M);
}

/**
 * \brief  SPI Disable Serial Data Inversion
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_disableSerialDataInversion (SPI_TypeDef *spi)
{
    CLEAR_BIT(spi->SPDCR1.WORDVAL, SPI_SPDCR1_SINV_M);
}

/**
 * \brief  SPI Set fifo send trg
 * \param  spi    SPI pointer to a SPI_TypeDef structure
 *                 - SPI1: SPI1 base address index
 *                 - SPI2: SPI2 base address index
 *                 - SPI3: SPI3 base address index
 *                 - SPI4: SPI4 base address index
 * \param  Depth  Sending FIFO empty flag threshold setting
 *                 This parameter is an unsigned integer that is greater
 *                 than or equal to 0x0UL and less than or equal to 0x0FUL
 */
static inline void SPI_setFifoTxtrg (SPI_TypeDef *spi, uint32_t Depth)
{
    MODIFY_REG(spi->SPDCR2.WORDVAL, SPI_SPDCR2_TTRG_M, (uint32_t)(Depth << SPI_SPDCR2_TTRG_S));
}

/**
 * \brief  SPI Set fifo receive trg
 * \param  spi    SPI pointer to a SPI_TypeDef structure
 *                 - SPI1: SPI1 base address index
 *                 - SPI2: SPI2 base address index
 *                 - SPI3: SPI3 base address index
 *                 - SPI4: SPI4 base address index
 * \param  Depth  Sending FIFO empty flag threshold setting
 *                 This parameter is an unsigned integer that is greater
 *                 than or equal to 0x0UL and less than or equal to 0x0FUL
 */
static inline void SPI_setFifoRxtrg (SPI_TypeDef *spi, uint32_t Depth)
{
    MODIFY_REG(spi->SPDCR2.WORDVAL, SPI_SPDCR2_RTRG_M, (uint32_t)(Depth << SPI_SPDCR2_RTRG_S));
}

/**
 * \brief  SPI Enable Burst transmission insert frame delay
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_enableBurstFrameDelay (SPI_TypeDef *spi)
{
    CLEAR_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_BFDS_M);
}

/**
 * \brief  SPI Disable Burst transmission insert frame delay
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_disableBurstFrameDelay (SPI_TypeDef *spi)
{
    SET_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_BFDS_M);
}

/**
 * \brief  SPI Enable spck auto stop function in Master Mode
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_enableSpckAutoStopFunction (SPI_TypeDef *spi)
{
    SET_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SCKASE_M);
}

/**
 * \brief  SPI Disable spck auto stop function in Master Mode
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_disableSpckAutoStopFunction (SPI_TypeDef *spi)
{
    CLEAR_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SCKASE_M);
}

/**
 * \brief  SPI get Status register value
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 * \return returned spi Status register value
 */
static inline uint32_t SPI_getStatusRegister (SPI_TypeDef *spi)
{
    return READ_REG(spi->SPSR.WORDVAL);
}

/**
 * \brief  SPI Set send data Length
 * \param  spi         SPI pointer to a SPI_TypeDef structure
 *                      - SPI1: SPI1 base address index
 *                      - SPI2: SPI2 base address index
 *                      - SPI3: SPI3 base address index
 *                      - SPI4: SPI4 base address index
 * \param  charLength  send data length
 *                      This parameter can be any value of @ref SPI_BitWidth
 */
static inline void SPI_setcharLength (SPI_TypeDef *spi, SPI_BitWidth charLength)
{
    SPI_disableModule(spi);
    MODIFY_REG(spi->SPCMD[0].WORDVAL, SPI_SPCMD_SPB_M, (charLength << SPI_SPCMD_SPB_S));
}

/**
 * \brief  SPI reset send/receive fifo
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_resetFifo (SPI_TypeDef *spi)
{
    /* Reset the TX/RX FIFO.*/
    SET_BIT(spi->SPFCR.WORDVAL, SPI_SPFCR_SPFRST_M);
}

/**
 * \brief  SPI set fifo interrupt level
 * \param  spi      SPI pointer to a SPI_TypeDef structure
 *                   - SPI1: SPI1 base address index
 *                   - SPI2: SPI2 base address index
 *                   - SPI3: SPI3 base address index
 *                   - SPI4: SPI4 base address index
 * \param  txLevel  SPI send fifo level
 *                   This parameter can be any value of @ref SPI_TxIntrFIFOThreshold
 * \param  rxLevel  SPI receive fifo level
 *                   This parameter can be any value of @ref SPI_RxIntrFIFOThreshold
 */
static inline void SPI_setFifoInterruptLevel (SPI_TypeDef *spi, SPI_TxIntrFifoThreshold txLevel,
                                              SPI_RxIntrFifoThreshold rxLevel)
{
    /* Set the FIFO interrupt levels.*/
    WRITE_REG(spi->SPDCR2.WORDVAL, ((uint32_t)txLevel << SPI_SPDCR2_TTRG_S) | ((uint32_t)rxLevel << SPI_SPDCR2_RTRG_S));
}

/**
 * \brief  SPI get fifo interrupt level
 * \param  spi      SPI pointer to a SPI_TypeDef structure
 *                   - SPI1: SPI1 base address index
 *                   - SPI2: SPI2 base address index
 *                   - SPI3: SPI3 base address index
 *                   - SPI4: SPI4 base address index
 * \param  txLevel  SPI send fifo level
 *                   This parameter can be any value of @ref SPI_TxIntrFifoThreshold
 * \param  rxLevel  SPI receive fifo level
 *                   This parameter can be any value of @ref SPI_RxIntrFifoThreshold
 */
static inline void SPI_getFifoInterruptLevel (SPI_TypeDef *spi, SPI_TxIntrFifoThreshold *txLevel,
                                              SPI_RxIntrFifoThreshold *rxLevel)
{
    /* Extract the transmit and receive FIFO levels.*/
    *txLevel =
        (SPI_TxIntrFifoThreshold)(((uint32_t)READ_REG(spi->SPDCR2.WORDVAL) & SPI_SPDCR2_TTRG_M) >> SPI_SPDCR2_TTRG_S);
    *rxLevel = (SPI_RxIntrFifoThreshold)((uint32_t)(READ_REG(spi->SPDCR2.WORDVAL) & SPI_SPDCR2_RTRG_M));
}

/**
 * \brief  SPI get send fifo empty level
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 * \return returned spi send fifo empty level
 *               This parameter is an unsigned integer that is greater
 *               than or equal to 0x0UL and less than or equal to 8UL
 */
static inline SPI_TxFifoLevel SPI_getTxFifoEmptyStatus (SPI_TypeDef *spi)
{
    /* Get the current FIFO status */
    return (SPI_TxFifoLevel)(READ_REG(spi->SPTFSR.WORDVAL) & SPI_SPTFSR_TFDN_M);
}

/**
 * \brief  SPI get receive fifo level
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 * \return returned spi receive fifo value
 *               This parameter is an unsigned integer that is greater
 *               than or equal to 0x0UL and less than or equal to 8UL
 */
static inline SPI_RxFifoLevel SPI_getRxFifoStatus (SPI_TypeDef *spi)
{
    /* Get the current FIFO status */
    return (SPI_RxFifoLevel)(READ_REG(spi->SPRFSR.WORDVAL) & SPI_SPRFSR_RFDN_M);
}

/**
 * \brief  SPI is busy detect. Only used in SPI Master Mode.
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 * \return returned spi busy status
 *               - 1: busy
 *               - 0: no busy
 */
static inline bool SPI_isBusy (SPI_TypeDef *spi)
{
    /* Determine if the SPI is busy.*/
    return ((READ_REG(spi->SPSR.WORDVAL) & SPI_SPSR_IDLNF_M) != 0UL) ? 0x1UL : 0x0UL;
}

/**
 * \brief  SPI write data to DR register
 * \param  spi   SPI pointer to a SPI_TypeDef structure
 *                - SPI1: SPI1 base address index
 *                - SPI2: SPI2 base address index
 *                - SPI3: SPI3 base address index
 *                - SPI4: SPI4 base address index
 * \param  data  SPI sending data
 *                This parameter is an unsigned integer that is greater
 *                than or equal to 0x0UL and less than or equal to 0xFFFFFFFFUL
 */
static inline void SPI_writeDataNonBlocking (SPI_TypeDef *spi, uint32_t data)
{
    /* Write data to the transmit buffer.*/
    WRITE_REG(spi->SPDR.WORDVAL, data);
}

/**
 * \brief  SPI read data from DR register
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 * \return returned spi read data
 *               This parameter is an unsigned integer that is greater
 *               than or equal to 0x0UL and less than or equal to 0xFFFFFFFFUL
 */
static inline uint32_t SPI_readDataNonBlocking (SPI_TypeDef *spi)
{
    /* Check for data to read.*/
    return (READ_REG(spi->SPDR.WORDVAL));
}

/**
 * \brief  SPI write data to DR register in blocking fifo
 * \param  spi   SPI pointer to a SPI_TypeDef structure
 *                - SPI1: SPI1 base address index
 *                - SPI2: SPI2 base address index
 *                - SPI3: SPI3 base address index
 *                - SPI4: SPI4 base address index
 * \param  data  SPI sending data or SPI_TIMEOUT_ERROR
 *                This parameter is an unsigned integer that is greater
 *                than or equal to 0x0UL and less than or equal to 0xFFFFFFFFUL
 */
static inline void SPI_writeDataBlockingFifo (SPI_TypeDef *spi, uint32_t data)
{
    /* Wait until the transmit buffer is not full.*/
    while(SPI_getTxFifoEmptyStatus(spi) == SPI_FIFO_TXFULL)
    {
    }

    WRITE_REG(spi->SPDR.WORDVAL, data);
}

/**
 * \brief  SPI read data from DR register in blocking fifo
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 * \return returned spi read data or SPI_TIMEOUT_ERROR
 *               This parameter is an unsigned integer that is greater
 *               than or equal to 0x0UL and less than or equal to 0xFFFFFFFFUL
 */
static inline uint32_t SPI_readDataBlockingFifo (SPI_TypeDef *spi)
{
    /* Check for data to read.*/
    while(SPI_getRxFifoStatus(spi) == SPI_FIFO_RXEMPTY)
    {
    }

    return READ_REG(spi->SPDR.WORDVAL);
}

/**
 * \brief  SPI Enable Parity
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_enableParity (SPI_TypeDef *spi)
{
    SET_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPPE_M);
}

/**
 * \brief  SPI Set Parity Mode
 * \param  spi     SPI pointer to a SPI_TypeDef structure
 *                  - SPI1: SPI1 base address index
 *                  - SPI2: SPI2 base address index
 *                  - SPI3: SPI3 base address index
 *                  - SPI4: SPI4 base address index
 * \param  parity  SPI pointer to a SPI_TypeDef structure
 *                  This parameter can be any value of @ref SPI_Parity
 */
static inline void SPI_setParityMode (SPI_TypeDef *spi, SPI_Parity parity)
{
    MODIFY_REG(spi->SPCR1.WORDVAL, SPI_SPCR1_SPOE_M, (parity << SPI_SPCR1_SPOE_S));
}

/**
 * \brief  SPI Disable Parity
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_disableParity (SPI_TypeDef *spi)
{
    CLEAR_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPPE_M);
}

/**
 * \brief  SPI enable tri wires
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_enableTriWire (SPI_TypeDef *spi)
{
    /* Set the tri-wire bit to enable 3-wire mode.*/
    SET_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPMS_M);
}

/**
 * \brief  SPI disable tri wires
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_disableTriWire (SPI_TypeDef *spi)
{
    /* Clear the tri-wire bit to disable 3-wire mode.*/
    CLEAR_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPMS_M);
}

/**
 * \brief  SPI enable loopback1 mode
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_enableLoopback (SPI_TypeDef *spi)
{
    /* Set the bit that enables loopback mode.*/
    SET_BIT(spi->SPCR2.WORDVAL, SPI_SPCR2_SPLP1_M);
}

/**
 * \brief  SPI disable loopback1 mode
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_disableLoopback (SPI_TypeDef *spi)
{
    /* Clear the bit that enables loopback mode.*/
    CLEAR_BIT(spi->SPCR2.WORDVAL, SPI_SPCR2_SPLP1_M);
}

/**
 * \brief  SPI enable loopback2 mode
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_enableLoopback2 (SPI_TypeDef *spi)
{
    /* Set the bit that enables loopback mode.*/
    SET_BIT(spi->SPCR2.WORDVAL, SPI_SPCR2_SPLP2_M);
}

/**
 * \brief  SPI disable loopback2 mode
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 */
static inline void SPI_disableLoopback2 (SPI_TypeDef *spi)
{
    /* Clear the bit that enables loopback mode.*/
    CLEAR_BIT(spi->SPCR2.WORDVAL, SPI_SPCR2_SPLP2_M);
}

/**
 * \brief  SPI Set NCS Signal Polarity
 * \param  spi       SPI pointer to a SPI_TypeDef structure
 *                    - SPI1: SPI1 base address index
 *                    - SPI2: SPI2 base address index
 *                    - SPI3: SPI3 base address index
 *                    - SPI4: SPI4 base address index
 * \param  polarity  SPI pointer to a SPI_TypeDef structure
 *                    This parameter can be any value of @ref SPI_NcsPol
 */
static inline void SPI_setNcsPolarity (SPI_TypeDef *spi, SPI_NcsPol polarity)
{
    /* Set the tri-wire bit to enable 3-wire mode.*/
    MODIFY_REG(spi->SPCR3.WORDVAL, SPI_SPCR3_SSLP_M, (polarity << SPI_SPCR3_SSLP_S));
}

/**
 * \brief  SPI set spclk signal polarity and phase
 * \param  spi       SPI pointer to a SPI_TypeDef structure
 *                    - SPI1: SPI1 base address index
 *                    - SPI2: SPI2 base address index
 *                    - SPI3: SPI3 base address index
 *                    - SPI4: SPI4 base address index
 * \param  protocol  SPI spclk signal polarity and phase
 *                    This parameter can be any value of @ref SPI_TransferProtocol
 */
static inline void SPI_setSignalPolarityPhase (SPI_TypeDef *spi, SPI_TransferProtocol protocol)
{
    /* Write the protocol of the SPIPTE signal to the register.*/
    MODIFY_REG(spi->SPCMD[0].WORDVAL, (SPI_SPCMD_CPHA_M | SPI_SPCMD_CPOL_M), (protocol << SPI_SPCMD_CPHA_S));
}

/**
 * \brief  SPI Set Data Transfer Priority 
 * \param  spi       SPI pointer to a SPI_TypeDef structure
 *                    - SPI1: SPI1 base address index
 *                    - SPI2: SPI2 base address index
 *                    - SPI3: SPI3 base address index
 *                    - SPI4: SPI4 base address index
 * \param  priority  SPI pointer to a SPI_TypeDef structure
 *                    This parameter can be any value of @ref SPI_BitOrder
 */
static inline void SPI_setTransPriority (SPI_TypeDef *spi, SPI_BitOrder priority)
{
    /* Set the tri-wire bit to enable 3-wire mode.*/
    MODIFY_REG(spi->SPCMD[0].WORDVAL, SPI_SPCMD_LSBF_M, (priority << SPI_SPCMD_LSBF_S));
}

/**
 * \brief  SPI enable send fifo transmit delay in Master Mode
 * \param  spi           SPI pointer to a SPI_TypeDef structure
 *                        - SPI1: SPI1 base address index
 *                        - SPI2: SPI2 base address index
 *                        - SPI3: SPI3 base address index
 *                        - SPI4: SPI4 base address index
 * \param  spn_delay_en  SPI next access delay enable
 *                        This parameter can be 0 or 1
 * \param  sln_delay_en  SPI invalidation signal delay enable
 *                        This parameter can be 0 or 1
 * \param  sck_delay_en  SPI clk delay enable
 *                        This parameter can be 0 or 1
 */
static inline void SPI_enableTxFifoTransmitDelay (SPI_TypeDef *spi, uint8_t spn_delay_en, uint8_t sln_delay_en,
                                                  uint8_t sck_delay_en)
{
    MODIFY_REG(spi->SPCMD[0].WORDVAL, (SPI_SPCMD_SPNDEN_M | SPI_SPCMD_SLNDEN_M | SPI_SPCMD_SCKDEN_M),
               (spn_delay_en << SPI_SPCMD_SPNDEN_S) | (sln_delay_en << SPI_SPCMD_SLNDEN_S) |
                   (sck_delay_en << SPI_SPCMD_SCKDEN_S));
}

/**
 * \brief  SPI set send fifo transmit delay in Master Mode
 * \param  spi        SPI pointer to a SPI_TypeDef structure
 *                     - SPI1: SPI1 base address index
 *                     - SPI2: SPI2 base address index
 *                     - SPI3: SPI3 base address index
 *                     - SPI4: SPI4 base address index
 * \param  spn_delay  SPI next access delay
 *                     This parameter is an unsigned integer that is greater
 *                     than or equal to 0x0UL and less than or equal to 0x07UL
 * \param  sln_delay  SPI invalidation signal delay
 *                     This parameter is an unsigned integer that is greater
 *                     than or equal to 0x0UL and less than or equal to 0x07UL
 * \param  sck_delay  SPI clk delay
 *                     This parameter is an unsigned integer that is greater
 *                     than or equal to 0x0UL and less than or equal to 0x07UL
 */
static inline void SPI_setTxFifoTransmitDelay (SPI_TypeDef *spi, uint32_t spn_delay, uint32_t sln_delay,
                                               uint32_t sck_delay)
{
    MODIFY_REG(spi->SPDLR.WORDVAL, (SPI_SPDLR_SCKDL_M | SPI_SPDLR_SLNDL_M | SPI_SPDLR_SPNDL_M),
               (spn_delay << SPI_SPDLR_SPNDL_S) | (sln_delay << SPI_SPDLR_SLNDL_S) | (sck_delay << SPI_SPDLR_SCKDL_S));
}

/**
 * \brief  SPI enable interrupt
 * \param  spi        SPI pointer to a SPI_TypeDef structure
 *                     - SPI1: SPI1 base address index
 *                     - SPI2: SPI2 base address index
 *                     - SPI3: SPI3 base address index
 *                     - SPI4: SPI4 base address index
 * \param  intSource  SPI interrupt source
 *                     This parameter is the gather of SPI interrupt source,
 *                     interrupt source can be any value of @ref SPI_INTERRUPT_SOURCE
 */
static inline void SPI_enableInterrupt (SPI_TypeDef *spi, uint32_t intSource)
{
    SET_BIT(spi->SPCR1.WORDVAL, intSource);
}

/**
 * \brief  SPI disable interrupt
 * \param  spi        SPI pointer to a SPI_TypeDef structure
 *                     - SPI1: SPI1 base address index
 *                     - SPI2: SPI2 base address index
 *                     - SPI3: SPI3 base address index
 *                     - SPI4: SPI4 base address index
 * \param  intSource  SPI interrupt source
 *                     This parameter is the gather of SPI interrupt source,
 *                     interrupt source can be any value of @ref SPI_INTERRUPT_SOURCE
 */
static inline void SPI_disableInterrupt (SPI_TypeDef *spi, uint32_t intSource)
{
    CLEAR_BIT(spi->SPCR1.WORDVAL, intSource);
}

/**
 * \brief  SPI get interrupt status
 * \param  spi  SPI pointer to a SPI_TypeDef structure
 *               - SPI1: SPI1 base address index
 *               - SPI2: SPI2 base address index
 *               - SPI3: SPI3 base address index
 *               - SPI4: SPI4 base address index
 * \return returned spi interrupt status
 *               This parameter is an unsigned integer and for its
 *               bits can @ref SPI_FLAGS
 */
static inline uint32_t SPI_getInterruptStatus (SPI_TypeDef *spi)
{
    return READ_REG(spi->SPSR.WORDVAL);
}

/**
 * \brief  SPI clear interrupt status
 * \param  spi    SPI pointer to a SPI_TypeDef structure
 *                 - SPI1: SPI1 base address index
 *                 - SPI2: SPI2 base address index
 *                 - SPI3: SPI3 base address index
 *                 - SPI4: SPI4 base address index
 * \param  flags  SPI clear flags
 *                 This parameter is the gather of SPI clear flags,
 *                 flags can be any value of @ref SPI_CLEAR_FLAGS
 */
static inline void SPI_clearInterruptStatus (SPI_TypeDef *spi, uint32_t flags)
{
    WRITE_REG(spi->SPSCR.WORDVAL, flags);
}

/**
 * \brief  SPI set baudrate
 * \param  spi      SPI pointer to a SPI_TypeDef structure
 *                   - SPI1: SPI1 base address index
 *                   - SPI2: SPI2 base address index
 *                   - SPI3: SPI3 base address index
 *                   - SPI4: SPI4 base address index
 * \param  bitRate  SPI bitrate
 *                   This parameter is an unsigned integer that is greater
 *                   than or equal to 0x0UL and less than or equal to 0xFFFFFFFFUL
 */
extern uint32_t SPI_setBaudRate (SPI_TypeDef *spi, uint32_t bitRate);

/**
 * \brief  SPI set config
 * \param  spi        SPI pointer to a SPI_TypeDef structure
 *                     - SPI1: SPI1 base address index
 *                     - SPI2: SPI2 base address index
 *                     - SPI3: SPI3 base address index
 *                     - SPI4: SPI4 base address index
 * \param  protocol   SPI transfer protocol
 *                     This parameter can be any value of @ref SPI_TRANSFERPROTOCOL
 * \param  mode       SPI Work mode
 *                     This parameter can be any value of @ref SPI_MODE
 * \param  commmode   SPI Communication mode
 *                     This parameter can be any value of @ref SPI_COMMMODE
 * \param  bitRate    SPI Transfer bitRate
 *                     This parameter is an unsigned integer that is greater
 *                     than or equal to 0x0UL and less than or equal to 0xFFFFFFFFUL
 * \param  dataWidth  SPI transfer data width
 *                     This parameter can be any value of @ref SPI_BitWidth
 */
extern uint32_t SPI_setConfig (SPI_TypeDef *spi, SPI_TransferProtocol protocol, SPI_Mode mode, SPI_CommMode commmode,
                               uint32_t bitRate, SPI_BitWidth dataWidth);

/**
 * \brief  SPI Multi-Commands configuration
 * \param  spi      SPI pointer to a SPI_TypeDef structure
 *                   - SPI1: SPI1 base address index
 *                   - SPI2: SPI2 base address index
 *                   - SPI3: SPI3 base address index
 *                   - SPI4: SPI4 base address index
 * \param  cmd_len  SPI cmnd length
 *                   This parameter can be any value of @ref SPI_CmdSequence
 */
extern void SPI_configMultiCmds (SPI_TypeDef *spi, SPI_CmdSequence cmd_len);

/**
 * \brief  SPI enable Multi-cmnds into Burst Mode, this function should be called after SPI_configMultiCmnds()
 * \param  spi          SPI pointer to a SPI_TypeDef structure
 *                       - SPI1: SPI1 base address index
 *                       - SPI2: SPI2 base address index
 *                       - SPI3: SPI3 base address index
 *                       - SPI4: SPI4 base address index
 * \param  cmd_len      SPI cmnd length
 *                       This parameter can be any value of @ref SPI_CmdSequence
 */
extern void SPI_enableBurstMode (SPI_TypeDef *spi, SPI_CmdSequence cmd_len);

/**
 * \brief  SPI disable Burst Mode
 * \param  spi      SPI pointer to a SPI_TypeDef structure
 *                   - SPI1: SPI1 base address index
 *                   - SPI2: SPI2 base address index
 *                   - SPI3: SPI3 base address index
 *                   - SPI4: SPI4 base address index
 * \param  cmd_len  SPI cmnd length
 *                   This parameter can be any value of @ref SPI_CmdSequence
 */
extern void SPI_disableBurstMode (SPI_TypeDef *spi, SPI_CmdSequence cmd_len);

/**
 * \brief  SPI polling fifo transaction
 * \param  spi         SPI pointer to a SPI_TypeDef structure
 *                      - SPI1: SPI1 base address index
 *                      - SPI2: SPI2 base address index
 *                      - SPI3: SPI3 base address index
 *                      - SPI4: SPI4 base address index
 * \param  pTxBuffer   SPI Send Buffer pointer
 * \param  pRxBuffer   SPI Receive Buffer pointer
 * \param  numOfWords  SPI Transfer data length
 *                      This parameter is an unsigned integer that is greater
 *                      than or equal to 0x0UL and less than or equal to 0xFFFFFFFFUL
 */
extern void SPI_pollingFifoTransaction (SPI_TypeDef *spi, uint32_t *pTxBuffer, uint32_t *pRxBuffer,
                                        uint32_t numOfWords);


#ifdef __cplusplus
}
#endif


#endif    /* _SPI_H */

