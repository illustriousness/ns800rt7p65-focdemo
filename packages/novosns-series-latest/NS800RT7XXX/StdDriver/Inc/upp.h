/**
  * @file       upp.h
  * @author     Alex-J
  * @brief      Header file for NS800RT7xxx upp module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __UPP_H__
#define __UPP_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup UPP_EXPORTED_TYPES UPP Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'UPP' module.
  */

/** @defgroup UPP_MSGRAM_PARAMETER UPP MSGRAM Parameter
  * @{
  * @brief   Since the addresses for Tx & Rx MSG RAMs are
  *          same for CPU & DMA views, these defines can be used as DMA descriptor
  *          addresses.
  */
#define UPP_TX_MSG_RAM_BASE    0x90000000UL
#define UPP_RX_MSG_RAM_BASE    0x90000200UL

#define UPP_DMA_TX_MSGRAM_STARTADDR    UPP_TX_MSG_RAM_BASE
#define UPP_DMA_RX_MSGRAM_STARTADDR    UPP_RX_MSG_RAM_BASE

#define UPP_CPU_TX_MSGRAM_STARTADDR    UPP_TX_MSG_RAM_BASE
#define UPP_CPU_RX_MSGRAM_STARTADDR    UPP_RX_MSG_RAM_BASE

#define UPP_TX_MSGRAM_MAX_SIZE    0x200U
#define UPP_RX_MSGRAM_MAX_SIZE    0x200U

/**
  * @}
  */

/** @defgroup UPP_CYCLE_NOP UPP 32 Cycle NOP
  * @{
  * @brief   Define to specify 32 cycle delay between software reset issue & release in
  *          UPP_performSoftReset().
  */
#ifndef UPP_32_CYCLE_NOP
#define UPP_32_CYCLE_NOP    nop_delay_asm(32)
#endif

/**
  * @}
  */

/** @defgroup UPP_SOFT_FREE_MASK UPP Soft and Free Mode Mask
  * @{
  * @brief   Define to specify mask for setting emulation mode in 
  *          UPP_setEmulationMode().
  */
#define UPP_SOFT_FREE_M    (UPP_PERCTL_SOFT_M | UPP_PERCTL_FREE_M)

/**
  * @}
  */

/** @defgroup UPP_TX_RX_SIGNAL_MODE UPP Tx & Rx Signal Mode
  * @{
  * @brief   Defines to specify masks for enabling/disabling uPP Tx/Rx control signals in
  *          UPP_setTxControlSignalMode() & UPP_setRxControlSignalMode() respectively.
  */
#define UPP_TX_SIGNAL_MODE_M    UPP_IFCFG_WAITA_M
#define UPP_RX_SIGNAL_MODE_M    (UPP_IFCFG_STARTA_M | UPP_IFCFG_ENAA_M)

/**
  * @}
  */

/** @defgroup UPP_SIGNAL_POLARITY UPP Signal Polarity
  * @{
  * @brief   Define to specify mask for configuring polarities for uPP control signals
  *          in UPP_setControlSignalPolarity().
  */
#define UPP_SIGNAL_POLARITY_M    (UPP_IFCFG_WAITPOLA_M | UPP_IFCFG_WAITPOLA_M | UPP_IFCFG_WAITPOLA_M)

/**
  * @}
  */

/** @defgroup UPP_INT_MASK UPP Interrupt Mask
  * @{
  * @brief   Define to specify masks for returning interrupt status in
  *          UPP_getInterruptStatus() & UPP_getRawInterruptStatus().
  */
#define UPP_INT_M    (UPP_ENINTST_DPEI_M | UPP_ENINTST_DPEI_M | \
                      UPP_ENINTST_EOWI_M | UPP_ENINTST_EOLI_M | \
                      UPP_ENINTST_DPEQ_M | UPP_ENINTST_UOEQ_M | \
                      UPP_ENINTST_EOWQ_M | UPP_ENINTST_EOLQ_M)

/**
  * @}
  */

/** @defgroup UPP_INT_PARAMETER UPP Interrupt Parameter
  * @{
  * @brief   Values that can be passed to UPP_enableInterrupt(),
  *          UPP_disableInterrupt() and UPP_clearInterruptStatus() as the
  *          intFlags parameter and returned by UPP_getInterruptStatus() &
  *          UPP_getRawInterruptStatus().
  */
#define UPP_INT_CHI_DMA_PROG_ERR      UPP_ENINTST_DPEI_M    /*!< DMA Channel I Programming Error */
#define UPP_INT_CHI_UNDER_OVER_RUN    UPP_ENINTST_UOEI_M    /*!< DMA Channel I Underrun/Overrun */
#define UPP_INT_CHI_END_OF_WINDOW     UPP_ENINTST_EOWI_M    /*!< DMA Channel I EndOfWindow Event */
#define UPP_INT_CHI_END_OF_LINE       UPP_ENINTST_EOLI_M    /*!< DMA Channel I EndOfLine Event */
#define UPP_INT_CHQ_DMA_PROG_ERR      UPP_ENINTST_DPEQ_M    /*!< DMA Channel Q Programming Error */
#define UPP_INT_CHQ_UNDER_OVER_RUN    UPP_ENINTST_UOEQ_M    /*!< DMA Channel Q Underrun/Overrun */
#define UPP_INT_CHQ_END_OF_WINDOW     UPP_ENINTST_EOWQ_M    /*!< DMA Channel Q EndOfWindow Event */
#define UPP_INT_CHQ_END_OF_LINE       UPP_ENINTST_EOLQ_M    /*!< DMA Channel Q EndOfLine Eventc */

/**
  * @}
  */

/** @defgroup UPP_EMULATION_MODE UPP Emulation Mode Parameter
  * @{
  * @brief   Values that can be passed to UPP_setEmulationMode() as \e emuMode
  *          parameter.
  */
typedef enum
{
    UPP_EMULATIONMODE_HARDSTOP = 0x0U,    /*!< uPP stops immediately */
    UPP_EMULATIONMODE_RUNFREE  = 0x1U,    /*!< uPP unaffected by suspend */
    UPP_EMULATIONMODE_SOFTSTOP = 0x2U     /*!< uPP stops at DMA transaction finish */
} UPP_EmulationMode;

/**
  * @}
  */

/** @defgroup UPP_OPERATION_MODE UPP Operation Mode Parameter
  * @{
  * @brief   Values that can be passed to UPP_setOperationMode() as \e opMode 
  *          parameter.
  */
typedef enum
{
    UPP_RECEIVE_MODE  = 0x0U,    /*!< uPP to be configured as Receiver */
    UPP_TRANSMIT_MODE = 0x1U     /*!< uPP to be configured as Transmitter */
} UPP_OperationMode;

/**
  * @}
  */

/** @defgroup UPP_DATARATE UPP Data Rate Parameter
  * @{
  * @brief   Values that can be passed to UPP_setDataRate() as \e dataRate
  *          parameter.
  */
typedef enum
{
    UPP_DATA_RATE_SDR = 0x00000U,    /*!< uPP to operate in Single Data Rate Mode */
    UPP_DATA_RATE_DDR = 0x10000U     /*!< uPP to operate in Double Data Rate Mode */
} UPP_DataRate;

/**
  * @}
  */

/** @defgroup UPP_TX_SDR_INTERLEAVE_MODE UPP TX SDR InterLeave Mode Parameter
  * @{
  * @brief   Values that can be passed to UPP_setTxSDRInterleaveMode() as \e mode
  *          parameter.
  */
typedef enum
{
    UPP_TX_SDR_INTERLEAVE_DISABLE = 0x0U,    /*!< Interleaving disabled in Tx SDR */
    UPP_TX_SDR_INTERLEAVE_ENABLE  = 0x8U     /*!< Interleaving enabled in Tx SDR */
} UPP_TxSDRInterleaveMode;

/**
  * @}
  */

/** @defgroup UPP_DDR_DEMUX_MODE UPP DDR Demux Mode Parameter
  * @{
  * @brief   Values that can be passed to UPP_setDDRDemuxMode() as \e mode
  *          parameter.
  */
typedef enum
{
    UPP_DDR_DEMUX_DISABLE = 0x00U,    /*!< Demultiplexing disabled in DDR mode */
    UPP_DDR_DEMUX_ENABLE  = 0x10U     /*!< Demultiplexing enabled in DDR mode */
} UPP_DDRDemuxMode;

/**
  * @}
  */

/** @defgroup UPP_SIGNAL_POLARITY UPP Signal Polarity Parameter
  * @{
  * @brief   Values that can be passed to UPP_setControlSignalPolarity() as \e waitPola,
  *          \e enablePola & \e startPola parameters.
  */
typedef enum
{
    UPP_SIGNAL_POLARITY_HIGH  = 0x0U,    /*!< Signal polarity is active high */
    UPP_SIGNAL_POLARITY_LOW   = 0x1U     /*!< Signal polarity is active low */
} UPP_SignalPolarity;

/**
  * @}
  */

/** @defgroup UPP_SIGNAL_MODE UPP Signal Mode Parameter
  * @{
  * @brief   Values that can be passed to UPP_setTxControlSignalMode() &
  *          UPP_setRxControlSignalMode() as \e waitMode & \e startMode, \e enableMode
  *          parameters respectively.
  */
typedef enum
{
    UPP_SIGNAL_DISABLE = 0x0U,    /*!< Control Signal is disabled for uPP */
    UPP_SIGNAL_ENABLE  = 0x1U     /*!< Control Signal is enabled for uPP */
} UPP_SignalMode;

/**
  * @}
  */

/** @defgroup UPP_CLOCK_POLARITY UPP Clock Polarity Parameter
  * @{
  * @brief   Values that can be passed to UPP_setClockPolarity() as \e clkPolarity
  *          parameter.
  */
typedef enum
{
    UPP_CLK_NOT_INVERTED = 0x0000U,    /*!< uPP Clock is not inverted */
    UPP_CLK_INVERTED     = 0x1000U     /*!< uPP clock is inverted */
} UPP_ClockPolarity;

/**
  * @}
  */

/** @defgroup UPP_CLOCK_POLARITY UPP Clock Polarity Parameter
  * @{
  * @brief   Values that can be passed to UPP_setClockPolarity() as \e clkPolarity
  *          parameter.
  */
typedef enum
{
    UPP_TX_IDLE_DATA_IDLE      = 0x0000U,    //!<Data lines will drive idle val */
    UPP_TX_IDLE_DATA_TRISTATED = 0x2000U     //!<Data lines will be tristated */
} UPP_TxIdleDataMode;

/**
  * @}
  */

/** @defgroup UPP_DMA_CHANNEL  UPP DMA Channel Parameter
  * @{
  * @brief   Values that can be passed to UPP_setDMAReadThreshold(),
  *          UPP_getDMAChannelStatus(), UPP_setDMADescriptor(), UPP_isDescriptorPending(),
  *          UPP_isDescriptorActive() & UPP_getDMAFIFOWatermark() as \e channel
  *          parameter.
  */
typedef enum
{
    UPP_DMA_CHANNEL_I = 0U,    /*!< uPP internal DMA channel I */
    UPP_DMA_CHANNEL_Q = 1U     /*!< uPP internal DMA channel Q */
} UPP_DMAChannel;

/**
  * @}
  */

/** @defgroup UPP_INPUT_DELAY  UPP Input Delay Parameter
  * @{
  * @brief   Values that can be passed to UPP_setInputDelay() as \e delay parameter. All
  *          the following values lead to 2 cycle delay on clock pin.
  */
typedef enum
{
    UPP_INPUT_DLY_4  = 0x0U,    /*!< 4 cycle delay for data & control pins */
    UPP_INPUT_DLY_6  = 0x2U,    /*!< 6 cycle delay for data & control pins */
    UPP_INPUT_DLY_9  = 0x4U,    /*!< 9 cycle delay for data & control pins */
    UPP_INPUT_DLY_14 = 0x6U     /*!< 14 cycle delay for data & control pins */
} UPP_InputDelay;

/**
  * @}
  */

/** @defgroup UPP_DMA_DESCRIPTOR  UPP DMA Discriptor Structure
  * @{
  * @brief   Values that can be passed to UPP_setDMADescriptor() as \e desc
  *          parameter.
  */
typedef struct
{
    uint32_t addr;          /*!< Starting address of DMA channel transfer */
    uint16_t lineCount;     /*!< No. of lines in a window for a DMA channel */
    uint16_t byteCount;     /*!< No. of bytes in a line for a DMA channel */
    uint16_t lineOffset;    /*!< Offset between start address of two lines */
} UPP_DMADescriptor;

/**
  * @}
  */

/** @defgroup UPP_DMA_CHANNELSTATUS  UPP DMA Channel Status Structure
  * @{
  * @brief   Values that can be returned by UPP_getDMAChannelStatus() as uPP internal
  *          DMA channel current status.
  */
typedef struct
{
    uint32_t curAddr;         /*!< Current address of transfer for a DMA channel */
    uint16_t curByteCount;    /*!< Current line no. of transfer for a DMA channel */
    uint16_t curLineCount;    /*!< Current byte no of transfer for a DMA channel */
} UPP_DMAChannelStatus;

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
 * \brief  Resets the uPP module.
 * \note   This function initiates software reset in uPP.
 * \param  upp  upp pointer to a UPP_TypeDef structure
 *                - UPP: UPP base address index
 */
static inline void UPP_performSoftReset (UPP_TypeDef *upp)
{
    SET_BIT(upp->PERCTL.WORDVAL, UPP_PERCTL_SOFTRST_M);

    UPP_32_CYCLE_NOP;

    CLEAR_BIT(upp->PERCTL.WORDVAL, UPP_PERCTL_SOFTRST_M);
}

/**
 * \brief  Enables the uPP module.
 * \note   This function enables the uPP module.
 * \param  upp  upp pointer to a UPP_TypeDef structure
 *                - UPP: UPP base address index
 */
static inline void UPP_enableModule (UPP_TypeDef *upp)
{
    SET_BIT(upp->PERCTL.WORDVAL, UPP_PERCTL_PEREN_M);
}

/**
 * \brief  Disables the uPP module.
 * \note   This function disables the uPP module.
 * \param  upp  upp pointer to a UPP_TypeDef structure
 *                - UPP: UPP base address index
 */
static inline void UPP_disableModule (UPP_TypeDef *upp)
{
    CLEAR_BIT(upp->PERCTL.WORDVAL, UPP_PERCTL_PEREN_M);
}

/**
 * \brief  Enables real time emulation mode for uPP module.
 * \note   This function enables real time emulation mode in uPP module.
 * \param  upp  upp pointer to a UPP_TypeDef structure
 *                - UPP: UPP base address index
 */
static inline void UPP_enableEmulationMode (UPP_TypeDef *upp)
{
    SET_BIT(upp->PERCTL.WORDVAL, UPP_PERCTL_RTEMU_M);
}

/**
 * \brief  Disables real time emulation mode for uPP module.
 * \note   This function disables real time emulation mode in uPP module.
 * \param  upp  upp pointer to a UPP_TypeDef structure
 *                - UPP: UPP base address index
 */
static inline void UPP_disableEmulationMode (UPP_TypeDef *upp)
{
    CLEAR_BIT(upp->PERCTL.WORDVAL, UPP_PERCTL_RTEMU_M);
}

/**
 * \brief  Sets the emulation mode for the uPP module.
 * \note   This function sets the uPP module's emulation mode. This mode determines
 *         how the uPP module is affected by an emulation suspend.
 * \param  upp      upp pointer to a UPP_TypeDef structure
 *                    - UPP: UPP base address index
 * \param  emuMode  the mode of operation upon an emulation suspend.
 *                  Valid values for \e emuMode parameter are the following:
 *                  - \b UPP_EMULATIONMODE_HARDSTOP - The uPP module stops immediately.
 *                  - \b UPP_EMULATIONMODE_RUNFREE  - The uPP module is unaffected by an
 *                       emulation suspend.
 *                  - \b UPP_EMULATIONMODE_SOFTSTOP - The uPP module stops after completing
 *                       current DMA burst transaction.
 */
static inline void UPP_setEmulationMode (UPP_TypeDef *upp, UPP_EmulationMode emuMode)
{
    MODIFY_REG(upp->PERCTL.WORDVAL, UPP_SOFT_FREE_M, (uint32_t)emuMode);
}

/**
 * \brief  Sets uPP mode of operation.
 * \note   This function sets the uPP mode of opeartion. The \e opMode parameter
 *         determines whether uPP module should be configured as transmitter or
 *         receiver.
 * \param  upp     upp pointer to a UPP_TypeDef structure
 *                   - UPP: UPP base address index
 * \param  opMode  mode of operation for uPP module.
 *                 It should be passed any of the following values:
 *                 - \b UPP_RECEIVE_MODE  - uPP is to be operated in Rx mode.
 *                 - \b UPP_TRANSMIT_MODE - uPP is to be operated in Tx mode.
 */
static inline void UPP_setOperationMode (UPP_TypeDef *upp, UPP_OperationMode opMode)
{
    MODIFY_REG(upp->CHCTL.WORDVAL, UPP_CHCTL_MODE_M, (uint32_t)opMode);
}

/**
 * \brief  Sets uPP data rate mode.
 * \note   This function sets the data rate mode for uPP module as single data rate
 *         or double data rate mode. 
 * 
 * \param  upp       upp pointer to a UPP_TypeDef structure
 *                     - UPP: UPP base address index
 * \param  dataRate  the required uPP data rate mode.
 *                   It should be passed any of the following values:
 *                   - \b UPP_DATA_RATE_SDR - uPP is to be operated in single data rate mode.
 *                   - \b UPP_DATA_RATE_DDR - uPP is to be operated in double data rate mode.
 */
static inline void UPP_setDataRate (UPP_TypeDef *upp, UPP_DataRate dataRate)
{
    MODIFY_REG(upp->CHCTL.WORDVAL, UPP_CHCTL_DRA_M, (uint32_t)dataRate);
}

/**
 * \brief  Sets Tx SDR interleave mode for uPP module.
 * \note   This function sets the required interleave mode for SDR Tx uPP. It is
 *         valid only for Tx SDR mode & not for Rx SDR mode. 
 * 
 * \param  upp   upp pointer to a UPP_TypeDef structure
 *                 - UPP: UPP base address index
 * \param  mode  the required SDR interleave mode.
 *               It should be passed any of the following values:
 *               - \b UPP_TX_SDR_INTERLEAVE_DISABLE - specifies interleaving is disabled
 *               - \b UPP_TX_SDR_INTERLEAVE_ENABLE  - specifies interleaving is enabled
 */
static inline void UPP_setTxSDRInterleaveMode (UPP_TypeDef *upp, UPP_TxSDRInterleaveMode mode)
{
    MODIFY_REG(upp->CHCTL.WORDVAL, UPP_CHCTL_SDRTXILA_M, (uint32_t)mode);
}

/**
 * \brief  Sets DDR de-multiplexing mode for uPP module.
 * \note   This function sets the demultiplexing mode for uPP DDR mode. The \e mode
 *         parameter determines whether demuliplexing to enabled or disabled in DDR
 *         mode.
 * 
 * \param  upp   upp pointer to a UPP_TypeDef structure
 *                 - UPP: UPP base address index
 * \param  mode  the required DDR de-multiplexing mode.
 *               It should be passed any of the following values:
 *               - \b UPP_DDR_DEMUX_DISABLE - specifies demultiplexing is disabled
 *               - \b UPP_DDR_DEMUX_ENABLE  - specifies demultiplexing is enabled
 */
static inline void UPP_setDDRDemuxMode (UPP_TypeDef *upp, UPP_DDRDemuxMode mode)
{
    MODIFY_REG(upp->CHCTL.WORDVAL, UPP_CHCTL_DEMUXA_M, (uint32_t)mode);
}

/**
 * \brief  Sets control signal polarity for uPP module.
 * \note   This function sets the control signal polarity for uPP module. The
 *         \e waitPola, \e enablePola, \e startPola parameters determines the
 *         control signal polarities.
 * 
 * \param  upp         upp pointer to a UPP_TypeDef structure
 *                       - UPP: UPP base address index
 * \param  waitPola    the required wait signal polarity.
 *                     Valid values for these parameters are the following:
 *                     - \b UPP_SIGNAL_POLARITY_HIGH - Signal polarity to be set as active high.
 *                     - \b UPP_SIGNAL_POLARITY_LOW  - Signal polarity to be set as active low.
 * \param  enablePola  the required enable signal polarity.
 * \param  startPola   the required start signal polarity.
 */
static inline void UPP_setControlSignalPolarity (UPP_TypeDef *upp, UPP_SignalPolarity waitPola,
                                                 UPP_SignalPolarity enablePola, UPP_SignalPolarity startPola)
{
    MODIFY_REG(upp->IFCFG.WORDVAL, UPP_SIGNAL_POLARITY_M,
               (((uint32_t)waitPola << UPP_IFCFG_WAITPOLA_S) | ((uint32_t)enablePola << UPP_IFCFG_ENAPOLA_S) |
                ((uint32_t)startPola)));
}

/**
 * \brief  Sets the mode for optional control signals for uPP module in Rx mode.
 * \note   This function sets the mode for optional control signal mode in Rx mode
 *         for uPP module.The \e enableMode & \e startMode parameter determine
 *         whether the enable & start signals are to be enabled or disabled while
 *         uPP is in receive mode.
 * 
 * \param  upp         upp pointer to a UPP_TypeDef structure
 *                       - UPP: UPP base address index
 * \param  enableMode  the required mode for wait signal.
 * \param  startMode   the required  mode for start signal.
 *                     These can take following values:
 *                     - \b UPP_SIGNAL_DISABLE - Signal will be disabled.
 *                     - \b UPP_SIGNAL_ENABLE  - Signal will be enabled.
 */
static inline void UPP_setRxControlSignalMode (UPP_TypeDef *upp, UPP_SignalMode enableMode, UPP_SignalMode startMode)
{
    MODIFY_REG(upp->IFCFG.WORDVAL, UPP_RX_SIGNAL_MODE_M,
               (((uint32_t)enableMode << UPP_IFCFG_ENAA_S) | ((uint32_t)startMode << UPP_IFCFG_STARTA_S)));
}

/**
 * \brief  Sets the clock divider when uPP is in Tx mode.
 * \note   This function configures the clock rate of uPP when it is operating in Tx
 *         mode. The \e divider parameter is the value by which SYSCLK rate is divided
 *         to get the desired uPP Tx clock rate.
 * 
 * \param  upp      upp pointer to a UPP_TypeDef structure
 *                    - UPP: UPP base address index
 * \param  divider  the value by which SYSCLK (or CPU1.SYSCLK on a dual
 *                  core device) is divided.
 */
static inline void UPP_setTxClockDivider (UPP_TypeDef *upp, uint16_t divider)
{
    MODIFY_REG(upp->IFCFG.WORDVAL, UPP_IFCFG_CLKDIVA_M, (uint32_t)divider << UPP_IFCFG_CLKDIVA_S);
}

/**
 * \brief  Sets the uPP clock polarity.
 * \note   This function sets the uPP clock polarity. The \e clkPolarity parameter
 *         in Tx mode determines whether output Tx clock is to be inverted or not,
 *         while in Rx mode it determines whether the Rx input clock is to be treated
 *         as inverted or not.
 * 
 * \param  upp          upp pointer to a UPP_TypeDef structure
 *                        - UPP: UPP base address index
 * \param  clkPolarity  the required clock polarity.
 */
static inline void UPP_setClockPolarity (UPP_TypeDef *upp, UPP_ClockPolarity clkPolarity)
{
    MODIFY_REG(upp->IFCFG.WORDVAL, UPP_IFCFG_CLKINVA_M, (uint32_t)clkPolarity);
}

/**
 * \brief  Configures data line behaviour when uPP goes to idle state in Tx mode.
 * \note   This function configures the Tx mode data line behaviour in uPP. The
 *         \e config determines whether tri-state is enabled or disabled for uPP
 *         idlle time.
 * 
 * \param  upp     upp pointer to a UPP_TypeDef structure
 *                   - UPP: UPP base address index
 * \param  config  the required idle mode data line behaviour.  
 *                 It can take following values:
 *                 - \b UPP_TX_IDLE_DATA_IDLE - uPP will drive idle values to data lines
 *                      when it goes to idle mode while operating in Tx mode.
 *                 - \b UPP_TX_IDLE_DATA_TRISTATED - uPP will tri-state data lines when it
 *                      goes to idle mode while operating in Tx mode.
 */
static inline void UPP_configTxIdleDataMode (UPP_TypeDef *upp, UPP_TxIdleDataMode config)
{
    MODIFY_REG(upp->IFCFG.WORDVAL, UPP_IFCFG_TRISENA_M, (uint32_t)config);
}

/**
 * \brief  Sets idle value to be driven by data line when uPP goes to idle state when
 *         operating in Tx mode.
 * \note   This function sets idle value to be driven in idle state while uPP is
 *         operating in Tx mode. The parameter \e idleVal is the value to be driven
 *         \e when Tx uPP is in idle state.
 * 
 * \param  upp      upp pointer to a UPP_TypeDef structure
 *                    - UPP: UPP base address index
 * \param  idleVal  the required idle value to be driven in Tx idle state.
 */
static inline void UPP_setTxIdleValue (UPP_TypeDef *upp, uint16_t idleVal)
{
    MODIFY_REG(upp->IFIVAL.WORDVAL, UPP_IFIVAL_VALA_M, (uint32_t)idleVal);
}

/**
 * \brief  Enables individual uPP module interrupts.
 * \note   This function enables uPP module interrupt sources.
 * 
 * \param  upp       upp pointer to a UPP_TypeDef structure
 *                     - UPP: UPP base address index
 * \param  intFlags  a bit mask of the interrupt sources to be enabled.
 *                   The \e intFlags parameter can be any of the following 
 *                   values OR'd together:
 *                   - \b UPP_INT_CHI_DMA_PROG_ERR   - DMA Channel I Programming Error
 *                   - \b UPP_INT_CHI_UNDER_OVER_RUN - DMA Channel I Underrun/Overrun
 *                   - \b UPP_INT_CHI_END_OF_WINDOW  - DMA Channel I End of Window Event
 *                   - \b UPP_INT_CHI_END_OF_LINE    - DMA Channel I End of Line Event
 *                   - \b UPP_INT_CHQ_DMA_PROG_ERR   - DMA Channel Q Programming Error
 *                   - \b UPP_INT_CHQ_UNDER_OVER_RUN - DMA Channel Q Underrun/Overrun
 *                   - \b UPP_INT_CHQ_END_OF_WINDOW  - DMA Channel Q End of Window Event
 *                   - \b UPP_INT_CHQ_END_OF_LINE    - DMA Channel Q End of Line Event
 */
static inline void UPP_enableInterrupt (UPP_TypeDef *upp, uint16_t intFlags)
{
    WRITE_REG(upp->INTENSET.WORDVAL, intFlags);
}

/**
 * \brief  Disables individual uPP module interrupts.
 * \note   This function disables uPP module interrupt sources.
 * 
 * \param  upp       upp pointer to a UPP_TypeDef structure
 *                     - UPP: UPP base address index
 * \param  intFlags  a bit mask of the interrupt sources to be enabled.
 *                   The \e intFlags parameter can be any of the following 
 *                   values OR'd together:
 *                   - \b UPP_INT_CHI_DMA_PROG_ERR   - DMA Channel I Programming Error
 *                   - \b UPP_INT_CHI_UNDER_OVER_RUN - DMA Channel I Underrun/Overrun
 *                   - \b UPP_INT_CHI_END_OF_WINDOW  - DMA Channel I End of Window Event
 *                   - \b UPP_INT_CHI_END_OF_LINE    - DMA Channel I End of Line Event
 *                   - \b UPP_INT_CHQ_DMA_PROG_ERR   - DMA Channel Q Programming Error
 *                   - \b UPP_INT_CHQ_UNDER_OVER_RUN - DMA Channel Q Underrun/Overrun
 *                   - \b UPP_INT_CHQ_END_OF_WINDOW  - DMA Channel Q End of Window Event
 *                   - \b UPP_INT_CHQ_END_OF_LINE    - DMA Channel Q End of Line Event
 */
static inline void UPP_disableInterrupt (UPP_TypeDef *upp, uint16_t intFlags)
{
    WRITE_REG(upp->INTENCLR.WORDVAL, intFlags);
}

/**
 * \brief  Gets the current uPP interrupt status for enabled interrupts.
 * \note   This function returns the interrupt status of enabled interrupts for the
 *         uPP module.
 * 
 * \param  upp  upp pointer to a UPP_TypeDef structure
 *                - UPP: UPP base address index
 * 
 *  \return Returns current interrupt status for enabled interrupts, 
 *          enumerated as a bit field of any of the following values:
 *           - \b UPP_INT_CHI_DMA_PROG_ERR   - DMA Channel I Programming Error
 *           - \b UPP_INT_CHI_UNDER_OVER_RUN - DMA Channel I Underrun/Overrun
 *           - \b UPP_INT_CHI_END_OF_WINDOW  - DMA Channel I End of Window Event
 *           - \b UPP_INT_CHI_END_OF_LINE    - DMA Channel I End of Line Event
 *           - \b UPP_INT_CHQ_DMA_PROG_ERR   - DMA Channel Q Programming Error
 *           - \b UPP_INT_CHQ_UNDER_OVER_RUN - DMA Channel Q Underrun/Overrun
 *           - \b UPP_INT_CHQ_END_OF_WINDOW  - DMA Channel Q End of Window Event
 *           - \b UPP_INT_CHQ_END_OF_LINE    - DMA Channel Q End of Line Event
 */
static inline uint16_t UPP_getInterruptStatus (UPP_TypeDef *upp)
{
    return (uint16_t)(READ_BIT(upp->ENINTST.WORDVAL, UPP_INT_M));
}

/**
 * \brief  Gets the current uPP interrupt status for all the interrupts.
 * \note   This function returns the interrupt status of all the interrupts for the
 *         uPP module.
 * 
 * \param  upp  upp pointer to a UPP_TypeDef structure
 *                - UPP: UPP base address index
 * 
 *  \return Returns current interrupt status for all the interrupts, 
 *          enumerated as a bit field of any of the following values:
 *           - \b UPP_INT_CHI_DMA_PROG_ERR   - DMA Channel I Programming Error
 *           - \b UPP_INT_CHI_UNDER_OVER_RUN - DMA Channel I Underrun/Overrun
 *           - \b UPP_INT_CHI_END_OF_WINDOW  - DMA Channel I End of Window Event
 *           - \b UPP_INT_CHI_END_OF_LINE    - DMA Channel I End of Line Event
 *           - \b UPP_INT_CHQ_DMA_PROG_ERR   - DMA Channel Q Programming Error
 *           - \b UPP_INT_CHQ_UNDER_OVER_RUN - DMA Channel Q Underrun/Overrun
 *           - \b UPP_INT_CHQ_END_OF_WINDOW  - DMA Channel Q End of Window Event
 *           - \b UPP_INT_CHQ_END_OF_LINE    - DMA Channel Q End of Line Event
 */
static inline uint16_t UPP_getRawInterruptStatus (UPP_TypeDef *upp)
{
    return (uint16_t)(READ_BIT(upp->RAWINTST.WORDVAL, UPP_INT_M));
}

/**
 * \brief  Clears individual uPP module interrupts.
 * \note   This function clears uPP module interrupt sources.
 * 
 * \param  upp       upp pointer to a UPP_TypeDef structure
 *                     - UPP: UPP base address index
 * \param  intFlags  a bit mask of the interrupt sources to be enabled.
 *                   The \e intFlags parameter can be any of the following 
 *                   values OR'd together:
 *                   - \b UPP_INT_CHI_DMA_PROG_ERR   - DMA Channel I Programming Error
 *                   - \b UPP_INT_CHI_UNDER_OVER_RUN - DMA Channel I Underrun/Overrun
 *                   - \b UPP_INT_CHI_END_OF_WINDOW  - DMA Channel I End of Window Event
 *                   - \b UPP_INT_CHI_END_OF_LINE    - DMA Channel I End of Line Event
 *                   - \b UPP_INT_CHQ_DMA_PROG_ERR   - DMA Channel Q Programming Error
 *                   - \b UPP_INT_CHQ_UNDER_OVER_RUN - DMA Channel Q Underrun/Overrun
 *                   - \b UPP_INT_CHQ_END_OF_WINDOW  - DMA Channel Q End of Window Event
 *                   - \b UPP_INT_CHQ_END_OF_LINE    - DMA Channel Q End of Line Event
 */
static inline void UPP_clearInterruptStatus (UPP_TypeDef *upp, uint16_t intFlags)
{
    WRITE_REG(upp->ENINTST.WORDVAL, intFlags);
}

/**
 * \brief  Enables uPP global interrupt.
 * \note   This function enables the global interrupt for uPP module which allows
 *         uPP to generate interrupts.
 * \param  upp  upp pointer to a UPP_TypeDef structure
 *                - UPP: UPP base address index
 */
static inline void UPP_enableGlobalInterrupt (UPP_TypeDef *upp)
{
    SET_BIT(upp->GINTEN.WORDVAL, UPP_GINTEN_GINTEN_M);
}

/**
 * \brief  Disables uPP global interrupt.
 * \note   This function disables the global interrupt for uPP module which allows
 *         uPP to generate interrupts.
 * \param  upp  upp pointer to a UPP_TypeDef structure
 *                - UPP: UPP base address index
 */
static inline void UPP_disableGlobalInterrupt (UPP_TypeDef *upp)
{
    CLEAR_BIT(upp->GINTEN.WORDVAL, UPP_GINTEN_GINTEN_M);
}

/**
 * \brief  Get uPP global interrupt status.
 * \note   This function returns whether any of the uPP interrupt is generated.
 * 
 * \param  upp  upp pointer to a UPP_TypeDef structure
 *                - UPP: UPP base address index
 * 
 *  \return Returns global interrupt status. It can return following values:
 *          - \b true  - Interrupt has been generated.
 *          - \b false - No interrupt has been generated.
 */
static inline bool UPP_isInterruptGenerated (UPP_TypeDef *upp)
{
    return (bool)(READ_BIT(upp->GINTFLG.WORDVAL, UPP_GINTFLG_GINTFLG_M));
}

/**
 * \brief  Clears uPP global interrupt status.
 * \note   This function clears global interrupt status for uPP module.
 * 
 * \param  upp  upp pointer to a UPP_TypeDef structure
 *                - UPP: UPP base address index
 */
static inline void UPP_clearGlobalInterruptStatus (UPP_TypeDef *upp)
{
    WRITE_REG(upp->GINTCLR.WORDVAL, UPP_GINTCLR_GINTCLR_M);
}

/**
 * \brief  Enables extra delay on uPP input pins.
 * \note   This function enables configurable extra delay on uPP input pins.
 * 
 * \param  upp  upp pointer to a UPP_TypeDef structure
 *                - UPP: UPP base address index
 */
static inline void UPP_enableInputDelay (UPP_TypeDef *upp)
{
    CLEAR_BIT(upp->DLYCTL.WORDVAL, UPP_DLYCTL_DLYDIS_M);
}

/**
 * \brief  Disables extra delay on uPP input pins.
 * \note   This function disables configurable extra delay on uPP input pins.
 * 
 * \param  upp  upp pointer to a UPP_TypeDef structure
 *                - UPP: UPP base address index
 */
static inline void UPP_disableInputDelay (UPP_TypeDef *upp)
{
    SET_BIT(upp->DLYCTL.WORDVAL, UPP_DLYCTL_DLYDIS_M);
}

/**
 * \brief  Configures delay for uPP input pins.
 * \note   This function sets input delay for uPP input pins. The \e delay parameter
 *         specifies the delay to be introduced to input & clock pins. It can take
 *         following values.
 * 
 * \param  upp    upp pointer to a UPP_TypeDef structure
 *                  - UPP: UPP base address index
 * \param  delay  the delay to be introduced in input & clock pins.
 *                All the following values lead to 2 cycle delay on clock pin.
 *                  - \b UPP_INPUT_DLY_4  - 4 cycle delay for data & control pins
 *                  - \b UPP_INPUT_DLY_6  - 6 cycle delay for data & control pins
 *                  - \b UPP_INPUT_DLY_9  - 9 cycle delay for data & control pins
 *                  - \b UPP_INPUT_DLY_14 - 14 cycle delay for data & control pins
 */
static inline void UPP_setInputDelay (UPP_TypeDef *upp, UPP_InputDelay delay)
{
    MODIFY_REG(upp->DLYCTL.WORDVAL, UPP_DLYCTL_DLYCTL_M, (uint32_t)delay);
}

/**
 * \brief  Sets uPP Internal DMA Channel Descriptors.
 * \note   This function configures DMA descriptors for either channel I or Q which
 *         includes starting address of DMA transfer, line count, byte count & line
 *         offset address for DMA transfer. In Tx mode, starting address is the
 *         address of data buffer to be transmitted while in Rx mode it is the
 *         address of buffer where recieved data is to be copied.
 * 
 * \param  upp      upp pointer to a UPP_TypeDef structure
 *                    - UPP: UPP base address index
 * \param  channel  the required uPP internal DMA channel to be configured.
 *                  The \e channel parameter can take any of the following values:
 *                    - \b UPP_DMA_CHANNEL_I - uPP DMA channel I
 *                    - \b UPP_DMA_CHANNEL_Q - uPP DMA channel Q
 * \param  desc     the required DMA descriptor setting.
 */
extern void UPP_setDMADescriptor (UPP_TypeDef *upp, UPP_DMAChannel channel, const UPP_DMADescriptor *const desc);

/**
 * \brief  Returns current status of uPP internal DMA channel transfer.
 * \note   This function returns the current status for either channel I or Q active
 *         transfer which includes current DMA transfer address, current line & byte
 *         number of the transfer.
 * 
 * \param  upp      upp pointer to a UPP_TypeDef structure
 *                    - UPP: UPP base address index
 * \param  channel  the required uPP internal DMA channel to be configured.
 *                  The \e channel parameter can take any of the following values:
 *                    - \b UPP_DMA_CHANNEL_I - uPP DMA channel I
 *                    - \b UPP_DMA_CHANNEL_Q - uPP DMA channel Q
 * \param  status   current status for DMA channel returned by the api.
 */
void UPP_getDMAChannelStatus (UPP_TypeDef *upp, UPP_DMAChannel channel, UPP_DMAChannelStatus *const status);

/**
 * \brief  Returns Pend status of uPP internal DMA channel descriptor.
 * \note   This function returns the Pend status for DMA channel I or Q descriptor
 *         which specifies whether previous descriptor is copied from shadow register
 *         to original register & new descriptor can be programmed or the previous
 *         descriptor is still pending & new descriptor cannot be programmed.
 * 
 * \param  upp      upp pointer to a UPP_TypeDef structure
 *                    - UPP: UPP base address index
 * \param  channel  the required uPP internal DMA channel to be configured.
 *                  The \e channel parameter can take any of the following values:
 *                    - \b UPP_DMA_CHANNEL_I - uPP DMA channel I
 *                    - \b UPP_DMA_CHANNEL_Q - uPP DMA channel Q
 * 
 * \return Returns pend status of DMA channel I descriptor. It can return
 *         following values:
 *           - \b true  - specifies that writing of new DMA descriptor is not allowed.
 *           - \b false - specifies that writing of new DMA descriptor is allowed.
 */
bool UPP_isDescriptorPending (UPP_TypeDef *upp, UPP_DMAChannel channel);

/**
 * \brief  Returns active status of uPP Internal DMA Channel descriptor.
 * \note   This function returns the active status of uPP internal DMA channel I or Q
 *         descriptor which specifies whether the descriptor is being currently
 *         active(transferring data) or idle.
 * 
 * \param  upp      upp pointer to a UPP_TypeDef structure
 *                    - UPP: UPP base address index
 * \param  channel  the required uPP internal DMA channel to be configured.
 *                  The \e channel parameter can take any of the following values:
 *                    - \b UPP_DMA_CHANNEL_I - uPP DMA channel I
 *                    - \b UPP_DMA_CHANNEL_Q - uPP DMA channel Q
 * 
 * \return Returns active status of uPP internal DMA channel descriptor.
 *         It can return following values:
 *           - \b true  - specifies that desciptor is currently active.
 *           - \b false - specifies that desciptor is currently idle.
 */
bool UPP_isDescriptorActive (UPP_TypeDef *upp, UPP_DMAChannel channel);

/**
 * \brief  Reads the received data from uPP Rx MSG RAM.
 * \note   This function reads the received data from uPP Rx MSG RAM. The sum of
 *         parameters \e length & \e offset should be less than the size of the Rx
 *         MSG RAM.
 * 
 * \param  rxBase  the uPP Rx MSG RAM base address.
 * \param  array   the address of the array of words to be transmitted.
 * \param  length  the number of dwords in the array to be transmitted.
 * \param  offset  offset in Rx Data RAM from where data read will start.
 */
void UPP_readRxMsgRAM (uint32_t rxBase, uint32_t array[], uint16_t length, uint16_t offset);

/**
 * \brief  Reads the received data from uPP Rx MSG RAM.
 * \note   This function reads the received data from uPP Rx MSG RAM. The sum of
 *         parameters \e length & \e offset should be less than the size of the Rx
 *         MSG RAM.
 * 
 * \param  rxBase  the uPP Rx MSG RAM base address.
 * \param  array   the address of the array of words to be transmitted.
 * \param  length  the number of dwords in the array to be transmitted.
 * \param  offset  offset in Rx Data RAM from where data read will start.
 */
void UPP_writeTxMsgRAM (uint32_t txBase, const uint32_t array[], uint16_t length, uint16_t offset);


#ifdef __cplusplus
}
#endif


#endif  /* __UPP_H__ */
