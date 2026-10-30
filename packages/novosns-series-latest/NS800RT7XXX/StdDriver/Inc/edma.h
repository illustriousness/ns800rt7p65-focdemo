/**
  * @file       edma.h
  * @author     yangjun
  * @brief      Header file for NS800RT7xxx edma module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __EDMA_H__
#define __EDMA_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_edma.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup EDMA_EXPORTED_TYPES EDMA Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'EDMA' module.
  */

/** @defgroup EDMA_DCHPRI_CONFIG EDMA Channel Priority Configuration
  * @{
  * @brief  Macro definitions about EDMA channel priority configuration.
  *         Recommending byte-level read and write operations
  */
#define EDMA_DCHPRI_INDEX(channel) ((channel) ^ 0x03UL)                         /*!< Compute the offset unit from DCHPRI0 */
#define EDMA_DCHPRIn(base, channel) \
        ((volatile uint8_t *) &(base->DCHPRI0))[EDMA_DCHPRI_INDEX(channel)]     /*!< Get the pointer of DCHPRIn */

/**
  * @}
  */

/** @defgroup EDMA_TRANSFERSIZE EDMA Source/Destination Data Transfer Size
  * @{
  * @brief  Macro definitions about EDMA source/destination data transfer size.
  *         Values that can be passed to EDMA_configTransfer() as the \e srcStep/destStep parameter.
  */
typedef enum {
    EDMA_TRANSFERSIZE1BYTES  = 0x0U,    /*!< Source/Destination data transfer size is 1 byte every time */
    EDMA_TRANSFERSIZE2BYTES,            /*!< Source/Destination data transfer size is 2 bytes every time */
    EDMA_TRANSFERSIZE4BYTES,            /*!< Source/Destination data transfer size is 4 bytes every time */
    EDMA_TRANSFERSIZE8BYTES,            /*!< Source/Destination data transfer size is 8 bytes every time */
    EDMA_TRANSFERSIZE32BYTES = 0x05U    /*!< Source/Destination data transfer size is 32 bytes every time */
} EDMA_TransferSize;

/**
  * @}
  */

/** @defgroup EDMA_INTERRUPTENABLEMASK EDMA Interrupt Enable Mask
  * @{
  * @brief  Macro definitions about EDMA interrupt enable mask.
  *         Values that can be passed to EDMA_enableChannelInterrupts() as the \e mask parameter.
  */
typedef enum {
    EDMA_ERRORINTERRUPTENABLE = 0x1U,    /*!< Enable interrupt while channel error occurs */
    EDMA_MAJORINTERRUPTENABLE = 0x2U,    /*!< Enable interrupt while major count exhausted */
    EDMA_HALFINTERRUPTENABLE  = 0x4U     /*!< Enable interrupt while major count to half value */
} EDMA_InterruptEnableMask;

/**
  * @}
  */

/** @defgroup EDMA_MODULOCFG EDMA Modulo Configuration
  * @{
  * @brief  Macro definitions about EDMA modulo configuration.
  *         Values that can be passed to EDMA_configChannel() as the \e config parameter.
  */
typedef enum {
    EDMA_MODULODISABLE = 0x0U,    /*!< Disable modulo */
    EDMA_MODULO2BYTES,            /*!< Circular buffer size is 2 bytes */
    EDMA_MODULO4BYTES,            /*!< Circular buffer size is 4 bytes */
    EDMA_MODULO8BYTES,            /*!< Circular buffer size is 8 bytes  */
    EDMA_MODULO16BYTES,           /*!< Circular buffer size is 16 bytes */
    EDMA_MODULO32BYTES,           /*!< Circular buffer size is 32 bytes */
    EDMA_MODULO64BYTES,           /*!< Circular buffer size is 64 bytes */
    EDMA_MODULO128BYTES,          /*!< Circular buffer size is 128 bytes */
    EDMA_MODULO256BYTES,          /*!< Circular buffer size is 256 bytes */
    EDMA_MODULO512BYTES,          /*!< Circular buffer size is 512 bytes */
    EDMA_MODULO1KBYTES,           /*!< Circular buffer size is 1 K bytes */
    EDMA_MODULO2KBYTES,           /*!< Circular buffer size is 2 K bytes */
    EDMA_MODULO4KBYTES,           /*!< Circular buffer size is 4 K bytes */
    EDMA_MODULO8KBYTES,           /*!< Circular buffer size is 8 K bytes */
    EDMA_MODULO16KBYTES,          /*!< Circular buffer size is 16 K bytes */
    EDMA_MODULO32KBYTES,          /*!< Circular buffer size is 32 K bytes */
    EDMA_MODULO64KBYTES,          /*!< Circular buffer size is 64 K bytes*/
    EDMA_MODULO128KBYTES,         /*!< Circular buffer size is 128 K bytes */
    EDMA_MODULO256KBYTES,         /*!< Circular buffer size is 256 K bytes */
    EDMA_MODULO512KBYTES,         /*!< Circular buffer size is 512 K bytes */
    EDMA_MODULO1MBYTES,           /*!< Circular buffer size is 1 M bytes */
    EDMA_MODULO2MBYTES,           /*!< Circular buffer size is 2 M bytes */
    EDMA_MODULO4MBYTES,           /*!< Circular buffer size is 4 M bytes */
    EDMA_MODULO8MBYTES,           /*!< Circular buffer size is 8 M bytes */
    EDMA_MODULO16MBYTES,          /*!< Circular buffer size is 16 M bytes */
    EDMA_MODULO32MBYTES,          /*!< Circular buffer size is 32 M bytes */
    EDMA_MODULO64MBYTES,          /*!< Circular buffer size is 64 M bytes */
    EDMA_MODULO128MBYTES,         /*!< Circular buffer size is 128 M bytes */
    EDMA_MODULO256MBYTES,         /*!< Circular buffer size is 256 M bytes */
    EDMA_MODULO512MBYTES,         /*!< Circular buffer size is 512 M bytes */
    EDMA_MODULO1GBYTES,           /*!< Circular buffer size is 1 G bytes */
    EDMA_MODULO2GBYTES            /*!< Circular buffer size is 2 G bytes */
} EDMA_ModuloCfg;

/**
  * @}
  */

/** @defgroup EDMA_CHANNELLINKTYPE EDMA Channel Link Type
  * @{
  * @brief  Macro definitions about EDMA channel link type.
  *         Values that can be passed to EDMA_setChannelLink() as the \e type parameter.
  */
typedef enum {
    EDMA_LINKNONE = 0x0U,    /*!< No channel link */
    EDMA_MINORLINK,          /*!< Channel link after each minor loop */
    EDMA_MAJORLINK           /*!< Channel link while major loop count exhausted */
} EDMA_ChannelLinkType;

/**
  * @}
  */

/** @defgroup EDMA_CHANNELSTATUS EDMA Channel Status
  * @{
  * @brief  Macro definitions about EDMA channel status.
  */
typedef enum {
    EDMA_DONEFLAG      = 0x1U,    /*!< DONE flag, set while transfer finished, CITER value exhausted */
    EDMA_ERRORFLAG     = 0x2U,    /*!< EDMA error flag, an error occurred in a transfer */
    EDMA_INTERRUPTFLAG = 0x4U     /*!< EDMA interrupt flag, set while an interrupt occurred of this channel */
} EDMA_ChannelStatus;

/**
  * @}
  */

/** @defgroup EDMA_GRPNUM EDMA Group Number
  * @{
  * @brief  Macro definitions about EDMA group number.
  */
typedef enum {
    EDMA_GRP0 = 0x0U,    /*!< EDMA Group 0 is included Channel 0~15 */
    EDMA_GRP1            /*!< EDMA Group 1 is included Channel 16~31 */
} EDMA_GrpNum;

/**
  * @}
  */

/** @defgroup EDMA_GRPPRI EDMA Group Priority
  * @{
  * @brief  Macro definitions about EDMA group priority.
  */
typedef enum {
    EDMA_GRP_PRI_LOW = 0x0U,    /*!< EDMA group lower priority */
    EDMA_GRP_PRI_HIGH           /*!< EDMA group higher priority */
} EDMA_GrpPri;

/**
  * @}
  */

/** @defgroup EDMA_MINOROFFSETCONFIG EDMA Minor Loop Mapping Configuration
  * @{
  * @brief  Macro definitions about EDMA minor loop mapping configuration.
  *         Values that can be passed to EDMA_setMinorOffsetConfig() as the \e config parameter.
  */
typedef struct {
    bool enableSrcMinorOffset;     /*!< Enable(true) or Disable(false) source minor loop offset */
    bool enableDestMinorOffset;    /*!< Enable(true) or Disable(false) destination minor loop offset */
    int32_t minorOffset;           /*!< Offset for a minor loop mapping */
} EDMA_MinorOffsetConfig;

/**
  * @}
  */

/** @defgroup EDMA_CHANNELPREEMPTIONCONFIG EDMA Channel Priority Configuration
  * @{
  * @brief  Macro definitions about EDMA channel priority configuration.
  *         Values that can be passed to EDMA_setChannelPreemptionConfig() or EDMA_configChannelPriority() as the \e config parameter.
  */
typedef struct {
    bool enableChannelPreemption;    /*!< Channel can be suspended by other channel with higher priority */
    bool enablePreemptAbility;       /*!< Channel can suspend other channel with low priority */
    uint8_t channelPriority;         /*!< Channel priority */
} EDMA_ChannelPreemptionConfig, EDMA_ChannelPriority;

/**
  * @}
  */

/** @defgroup EDMA_COMMONCONFIG EDMA Common Configuration
  * @{
  * @brief  Macro definitions about EDMA common configuration.
  *         Values that can be passed to EDMA_configModule() as the \e config parameter.
  */
typedef struct {
    bool enableContinuousLinkMode;          /*!< Enable (true) continuous link mode */
    bool enableHaltOnError;                 /*!< Enable (true) transfer halt on error */
    bool enableRoundRobinChnArbitration;    /*!< Enable (true) round robin channel arbitration method or \
                                                    fixed priority arbitration is used for channel selection */
    bool enableRoundRobinGrpArbitration;    /*!< Enable (true) round robin group arbitration method or \
                                                    fixed priority arbitration is used for group selection */
    bool enableDebugMode;                   /*!< Enable(true) EDMA debug mode */
    bool enableEmlm;                        /*!< Enable Minor Loop Mapping */
} EDMA_CommonConfig;

/**
  * @}
  */

/** @defgroup EDMA_TRANSFERCONFIG EDMA Transfer Config struct
  * @{
  * @brief  Macro definitions about EDMA transfer configuration.
  *         Values that can be passed to EDMA_configChannel() as the \e config parameter.
  */
typedef struct {
    uint32_t channel;                      /*!< EDMA channel */
    uint32_t srcAddr;                      /*!< Source data address */
    uint32_t destAddr;                     /*!< Destination data address */
    int16_t  srcOffset;                    /*!< Sign-extended offset applied to the current source address to \
                                                form the next-state value as each source read is completed */
    int16_t  destOffset;                   /*!< Sign-extended offset applied to the current destination address \
                                                to form the next-state value as each destination write is completed */
    uint32_t minorLoopBytes;               /*!< Bytes to transfer in a minor loop */
    uint32_t majorLoopCounts;              /*!< Major loop iteration count */
    int32_t  slast;                        /*!< Last Source Address Adjustment */
    int32_t  dlast;                        /*!< Destination last address adjustment */
    bool     enMajorInt;                   /*!< Enable or disable major interrupt */
    bool     enDreq;                       /*!< Enable or disable request by hardware automatically */
    bool     enTrigger;                    /*!< Enable or disable trigger function */
    bool     enErrInt;                     /*!< Enable or disable err interrupt */
    bool     startMode;                    /*!< 0:soft start  1:hardware start */
    EDMA_TransferSize srcTransferSize;     /*!< Source data transfer size */
    EDMA_TransferSize destTransferSize;    /*!< Destination data transfer size */
    EDMA_TCD_TypeDef* nextTcd;             /*!< SCATTER/GATHER next tcd */
} EDMA_TransferConfig;

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
  * \brief  EDMA cancel transfer.
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  *                 - EDMA2: EDMA2 base address index
  */
static inline void EDMA_setTransferCx (EDMA_TypeDef *edma)
{
    SET_BIT(edma->CR.WORDVAL, EDMA_CR_CX_M);
}

/**
  * \brief  EDMA error cancel transfer.
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  *                 - EDMA2: EDMA2 base address index
  */
static inline void EDMA_setTransferEcx (EDMA_TypeDef *edma)
{
    SET_BIT(edma->CR.WORDVAL, EDMA_CR_ECX_M);
}

/**
  * \brief  EDMA group priority setting.
  * \param  edma      The base address of the EDMA module.
  *                    - EDMA1: EDMA1 base address index
  *                    - EDMA2: EDMA2 base address index
  * \param  group     The EDMA group number.
  *                    This parameter can be any value of @ref EDMA_GRPNUM
  * \param  priority  The EDMA group prority.
  *                    This parameter can be any value of @ref EDMA_GRPPRI
  */
static inline void EDMA_setGroupPriority (EDMA_TypeDef *edma, EDMA_GrpNum group, EDMA_GrpPri priority)
{
    uint32_t shift = EDMA_CR_GRP0PRI_S + ((uint32_t)group << 1U);

    MODIFY_REG(edma->CR.WORDVAL, (0x1UL << shift), ((uint32_t)priority << shift));
}

/**
  * \brief  Minor Loop Mapping setting.
  * \param  edma      The base address of the EDMA module.
  *                    - EDMA1: EDMA1 base address index
  *                    - EDMA2: EDMA2 base address index
  * \param  enable    Enable Minor Loop Mapping.
  *                    - false: Disable
  *                    - true : Enable
  */
static inline void EDMA_enableEmlm (EDMA_TypeDef *edma, bool enable)
{
    MODIFY_REG(edma->CR.WORDVAL, EDMA_CR_EMLM_M, (uint32_t)enable << EDMA_CR_EMLM_S);
}

static inline void EDMA_enableMinorLoopMapping (EDMA_TypeDef *edma, bool enable)
{
    EDMA_enableEmlm(edma, enable);
}

/**
  * \brief  Continuous link mode setting.
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  *                 - EDMA2: EDMA2 base address index
  * \param  on     Continuous link mode is off/on.
  *                 - false: Off
  *                 - true : On
  */
static inline void EDMA_enableClm (EDMA_TypeDef *edma, bool on)
{
    MODIFY_REG(edma->CR.WORDVAL, EDMA_CR_CLM_M, (uint32_t)on << EDMA_CR_CLM_S);
}

static inline void EDMA_enableContinuousLinkMode (EDMA_TypeDef *edma, bool on)
{
    EDMA_enableClm(edma, on);
}

/**
  * \brief  Halt EDMA Operations.
  * \param  edma    The base address of the EDMA module.
  *                  - EDMA1: EDMA1 base address index
  *                  - EDMA2: EDMA2 base address index
  * \param  halt    Halt EDMA Operations.
  *                  - false: Normal operation
  *                  - true : EDMA operations halted
  */
static inline void EDMA_haltTransfer (EDMA_TypeDef *edma, bool halt)
{
    MODIFY_REG(edma->CR.WORDVAL, EDMA_CR_HALT_M, (uint32_t)halt << EDMA_CR_HALT_S);
}

/**
  * \brief  Enable Round Robin Group Arbitration.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  control    Round Robin Group Arbitration selection.
  *                     - false: Fixed priority arbitration
  *                     - true : Round robin arbitratio
  */
static inline void EDMA_enableErga (EDMA_TypeDef *edma, bool control)
{
    MODIFY_REG(edma->CR.WORDVAL, EDMA_CR_ERGA_M, (uint32_t)control << EDMA_CR_ERGA_S);
}

static inline void EDMA_enablePollingGroupArbitration (EDMA_TypeDef *edma, bool control)
{
    EDMA_enableErga(edma, control);
}

/**
  * \brief  Enable Round Robin Channel Arbitration.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  control    Enable Round Robin Channel Arbitration.
  *                     - false: Fixed priority arbitration within each group
  *                     - true : Round robin arbitration within each group
  */
static inline void EDMA_enableErca (EDMA_TypeDef *edma, bool control)
{
    MODIFY_REG(edma->CR.WORDVAL, EDMA_CR_ERCA_M, (uint32_t)control << EDMA_CR_ERCA_S);
}

static inline void EDMA_enablePollingChannelArbitration (EDMA_TypeDef *edma, bool control)
{
    EDMA_enableErca(edma, control);
}

/**
  * \brief  Enable debugging and determine the EDMA operation when in debug mode.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  control    Enable Debug mode.
  *                     - false: When the chip is in Debug mode, the EDMA continues to operate.
  *                     - true : When the chip is in Debug mode, the EDMA stalls the start of a new channel.
  *                              but executing channels are allowed to complete.
  */
static inline void EDMA_enableEdbg (EDMA_TypeDef *edma, bool control)
{
    MODIFY_REG(edma->CR.WORDVAL, EDMA_CR_EDBG_M, (uint32_t)control << EDMA_CR_EDBG_S);
}

static inline void EDMA_enableDebugMode (EDMA_TypeDef *edma, bool control)
{
    EDMA_enableEdbg(edma, control);
}

/**
  * \brief  Gets the EDMA error status flags.
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  *                 - EDMA2: EDMA2 base address index
  * \return Returns the status of error status.
  *                 - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
static inline uint32_t EDMA_getErrorStatusFlags (EDMA_TypeDef *edma)
{
    return READ_REG(edma->ES.WORDVAL);
}

/**
  * \brief  Enables the multiple EDMA hardware channel request.
  * \param  edma    The base address of the EDMA module.
  *                  - EDMA1: EDMA1 base address index
  *                  - EDMA2: EDMA2 base address index
  * \param  data    Enable Multiple EDMA Channels Request.
  *                  - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
static inline void EDMA_enableMultiChannelRequest (EDMA_TypeDef *edma, uint32_t data)
{
    WRITE_REG(edma->ERQ.WORDVAL, data);
}

/**
  * \brief  Enables the EDMA hardware channel request.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  */
static inline void EDMA_enableChannelRequest (EDMA_TypeDef *edma, uint8_t channel)
{
    WRITE_REG(edma->SERQ, channel);
}

/**
  * \brief  Disable the EDMA hardware channel request.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  */
static inline void EDMA_disableChannelRequest (EDMA_TypeDef *edma, uint8_t channel)
{
    WRITE_REG(edma->CERQ, channel);
}

/**
  * \brief  Enable the interrupt source for the EDMA transfer.
  * \param  edma         The base address of the EDMA module.
  *                       - EDMA1: EDMA1 base address index
  *                       - EDMA2: EDMA2 base address index
  * \param  channel      Channel num.
  *                       - uint8_t: 0x00 - 0x1F
  * \param  interrupt    Interrupt mask.
  *                       This parameter can be any value of @ref EDMA_INTERRUPTENABLEMASK
  */
static inline void EDMA_enableChannelInterrupts (EDMA_TypeDef *edma,
                                                 uint8_t channel,
                                                 EDMA_InterruptEnableMask interrupt)
{
    /* Enable error interrupt */
    if (interrupt & EDMA_ERRORINTERRUPTENABLE)
    {
        SET_BIT(edma->EEI.WORDVAL, (0x1U << channel));
    }

    /* Enable Major interrupt */
    if (interrupt & EDMA_MAJORINTERRUPTENABLE)
    {
        SET_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_INTMAJOR_M);
    }

    /* Enable Half major interrupt */
    if (interrupt & EDMA_HALFINTERRUPTENABLE)
    {
        SET_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_INTHALF_M);
    }
}

/**
  * \brief  Disable the interrupt source for the EDMA transfer.
  * \param  edma         The base address of the EDMA module.
  *                       - EDMA1: EDMA1 base address index
  *                       - EDMA2: EDMA2 base address index
  * \param  channel      Channel num.
  *                       - uint8_t: 0x00 - 0x1F
  * \param  interrupt    Interrupt mask.
  *                       This parameter can be any value of @ref EDMA_INTERRUPTENABLEMASK
  */
static inline void EDMA_disableChannelInterrupts (EDMA_TypeDef *edma,
                                                  uint8_t channel,
                                                  EDMA_InterruptEnableMask interrupt)
{
    /* Disable error interrupt */
    if (interrupt & EDMA_ERRORINTERRUPTENABLE)
    {
        CLEAR_BIT(edma->EEI.WORDVAL, (0x1U << channel));
    }

    /* Disable Major interrupt */
    if (interrupt & EDMA_MAJORINTERRUPTENABLE)
    {
        CLEAR_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_INTMAJOR_M);
    }

    /* Disable Half major interrupt */
    if (interrupt & EDMA_HALFINTERRUPTENABLE)
    {
        CLEAR_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_INTHALF_M);
    }
}

/**
  * \brief  Gets the EDMA channel done flags.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  * \return Returns the current channel done flag
  *                     - bool: false/true
  */
static inline bool EDMA_getChannelDoneFlags(EDMA_TypeDef *edma, uint8_t channel)
{
    return (bool)(READ_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_DONE_M) >> EDMA_TCD_BITER_ELINKNO_DONE_S);
}

/**
  * \brief  Clears the EDMA channel status done flags.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  */
static inline void EDMA_clearChannelStatusDoneFlags (EDMA_TypeDef *edma, uint8_t channel)
{
    /* Clear DONE bit flag */
    WRITE_REG(edma->CDNE, channel);
}

/**
  * \brief  Clears the EDMA channel status error flags.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  */
static inline void EDMA_clearChannelStatusErrorFlags (EDMA_TypeDef *edma, uint8_t channel)
{
    /* Clear ERROR bit flag */
    WRITE_REG(edma->CERR, channel);
}

/**
  * \brief  Gets the EDMA all channel error flags.
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  *                 - EDMA2: EDMA2 base address index
  * \return Returns the channel error flag.
  *                 - uint32_t: 0x00UL - 0xFFFFFFFFUL
  *                 - bit x: EDMA channel x error flag.
  */
static inline uint32_t EDMA_getAllChannelErrorFlags (EDMA_TypeDef *edma)
{
    return READ_REG(edma->ERR.WORDVAL);
}

/**
  * \brief  Clear the EDMA all channel error flags .
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  *                 - EDMA2: EDMA2 base address index
  */
static inline void EDMA_clearAllChannelErrorFlags (EDMA_TypeDef *edma)
{
    WRITE_REG(edma->ERR.WORDVAL, 0xFFFFFFFFUL);
}

/**
  * \brief  Gets the EDMA all channel hardware request status.
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  *                 - EDMA2: EDMA2 base address index
  * \return Returns the channel hardware request status.
  *                 - uint32_t: 0x00UL - 0xFFFFFFFFUL
  *                 - bit x: EDMA channel x hardware request status.
  */
static inline uint32_t EDMA_getAllChannelHardwareRequestStatus (EDMA_TypeDef *edma)
{
    return READ_REG(edma->HRS.WORDVAL);
}

/**
  * \brief  Clears the EDMA channel status int flags.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  */
static inline void EDMA_clearChannelStatusIntFlags (EDMA_TypeDef *edma, uint8_t channel)
{
    /* Clear INT bit flag */
    WRITE_REG(edma->CINT, channel);
}

/**
  * \brief  Start the EDMA transfer.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  */
static inline void EDMA_startTransfer (EDMA_TypeDef *edma, uint8_t channel)
{
    EDMA_enableChannelRequest(edma, channel);
}

/**
  * \brief  Soft start the EDMA transfer.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  */
static inline void EDMA_startTransfersoft (EDMA_TypeDef *edma, uint8_t channel)
{
    WRITE_REG(edma->SSRT, channel);
}

/**
  * \brief  Gets the EDMA channel interrupt status flags.
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  *                 - EDMA2: EDMA2 base address index
  * \return Returns the EDMA channel interrupt status flags.
  *                 - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
static inline uint32_t EDMA_getChannelIntStatus (EDMA_TypeDef *edma)
{
    return READ_REG(edma->INT.WORDVAL);
}

/**
  * \brief  Reset the EDMA TCD.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  */
static inline void EDMA_resetTcd (EDMA_TypeDef *edma, uint8_t channel)
{
    memset((void *)&(edma->TCD[channel]), 0UL, sizeof(EDMA_TCD_TypeDef));
}

/**
  * \brief  Push content of TCD structure into hardware TCD register.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  * \param  tcd        Tcd Point to TCD structure.
  *                     This parameter can be any value of @ref EDMA_TCD_TypeDef
  */
static inline void EDMA_installTCD (EDMA_TypeDef *edma, uint32_t channel, EDMA_TCD_TypeDef *tcd)
{
    /* Push tcd into hardware TCD register */
    edma->TCD[channel].SADDR.WORDVAL    = tcd->SADDR.WORDVAL;
    edma->TCD[channel].DADDR.WORDVAL    = tcd->DADDR.WORDVAL;
    edma->TCD[channel].TO.WORDVAL       = tcd->TO.WORDVAL;
    edma->TCD[channel].NBYTES           = tcd->NBYTES;
    edma->TCD[channel].SLAST.WORDVAL    = tcd->SLAST.WORDVAL;
    edma->TCD[channel].DLASTSGA.WORDVAL = tcd->DLASTSGA.WORDVAL;
    edma->TCD[channel].CITER            = tcd->CITER;
    edma->TCD[channel].BITER            = tcd->BITER;
}

/**
  * \brief  Sets the minor offset for the EDMA TCD.
  * \note   This function must call after the EDMA_configChannel, otherwise the value written will be overwritten.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  * \param  config     config A pointer to the minor offset configuration structure.
  *                     This parameter can be any value of @ref EDMA_MINOROFFSETCONFIG
  */
static inline void EDMA_setMinorOffsetConfig (EDMA_TypeDef *edma,
                                              uint8_t channel,
                                              EDMA_MinorOffsetConfig *config)
{
    uint32_t data = READ_REG(edma->TCD[channel].NBYTES) & (uint32_t)(EDMA_TCD_NBYTES_MLOFFNO_NBYTES_M);

    data = ((uint32_t)config->enableSrcMinorOffset << EDMA_TCD_NBYTES_MLOFFYES_SMLOE_S) | 
           ((uint32_t)config->enableDestMinorOffset << EDMA_TCD_NBYTES_MLOFFYES_DMLOE_S) |
           (((uint32_t)config->minorOffset << EDMA_TCD_NBYTES_MLOFFYES_MLOFF_S) & EDMA_TCD_NBYTES_MLOFFYES_MLOFF_M) |
           data;

    WRITE_REG(edma->TCD[channel].NBYTES, data);
}

/**
  * \brief  Sets the source modulo and the destination modulo for the EDMA TCD.
  * \param  edma          The base address of the EDMA module.
  *                        - EDMA1: EDMA1 base address index
  *                        - EDMA2: EDMA2 base address index
  * \param  channel       Channel num.
  *                        - uint8_t: 0x00 - 0x1F
  * \param  srcModulo     srcModulo A source modulo value
  *                        This parameter can be any value of @ref EDMA_MODULOCFG
  * \param  destModulo    destModulo A destination modulo value
  *                        This parameter can be any value of @ref EDMA_MODULOCFG
  */
static inline void EDMA_setModulo (EDMA_TypeDef *edma, uint32_t channel,
                                   EDMA_ModuloCfg srcModulo, EDMA_ModuloCfg destModulo)
{
    MODIFY_REG(edma->TCD[channel].TO.WORDVAL,
               (uint32_t)(EDMA_TCD_TO_SMOD_M | EDMA_TCD_TO_DMOD_M),
               (uint32_t)(srcModulo << EDMA_TCD_TO_SMOD_S) | (uint32_t)(destModulo << EDMA_TCD_TO_DMOD_S));
}

/**
  * \brief  Enable/Disable auto stop requeset.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  * \param  enable     Enable or Disable auto stop request
  *                     - false: The channel's ERQ field is not affected
  *                     - true : The channel's ERQ field value changes to 0 when the major loop is complete
  */
static inline void EDMA_enableAutoStopRequest (EDMA_TypeDef *edma, uint8_t channel, bool enable)
{
    MODIFY_REG(edma->TCD[channel].BITER,
               EDMA_TCD_BITER_ELINKNO_DREQ_M,
               (uint32_t)enable << EDMA_TCD_BITER_ELINKNO_DREQ_S);
}

/**
  * \brief  Get the group priority about EDMA channel.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  */
static inline uint8_t EDMA_getChannelGroupPriority (EDMA_TypeDef *edma, uint32_t channel)
{
    return (uint8_t)((EDMA_DCHPRIn(edma, channel) & EDMA_DCHPRI0_GRPPRI3_M) >> EDMA_DCHPRI0_GRPPRI3_S);
}

/**
  * \brief  Configures the EDMA TCD Source Address Register and Destination Address Register.
  * \param  edma        The base address of the EDMA module.
  *                      - EDMA1: EDMA1 base address index
  *                      - EDMA2: EDMA2 base address index
  * \param  channel     Channel num.
  *                      - uint8_t: 0x00 - 0x1F
  * \param  destAddr    Destnationadddress.
  *                      - uint32_t: 0x00UL - 0xFFFFFFFFUL
  * \param  srcAddr     Source address.
  *                      - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
extern void EDMA_configAddresses (EDMA_TypeDef *edma, uint8_t channel, uint32_t destAddr, uint32_t srcAddr);

/**
  * \brief  Configures the EDMA TCD Source Address Register.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  * \param  srcAddr    Source address.
  *                     - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
extern void EDMA_configTcdSrcAddresses (EDMA_TypeDef *edma, uint8_t channel, uint32_t srcAddr);

/**
  * \brief  Configures the EDMA TCD Destination Address Register.
  * \param  edma        The base address of the EDMA module.
  *                      - EDMA1: EDMA1 base address index
  *                      - EDMA2: EDMA2 base address index
  * \param  channel     Channel num.
  *                      - uint8_t: 0x00 - 0x1F
  * \param  destAddr    Destnation adddress.
  *                      - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
extern void EDMA_configTcdDestAddresses (EDMA_TypeDef *edma, uint8_t channel, uint32_t destAddr);

/**
  * @brief  Configures the EDMA mode.
  * @param  dma              The base address of the EDMA module.
  *                           - EDMA1: EDMA1 base address index
  *                           - EDMA2: EDMA2 base address index
  * @param  channel          Channel num.
  *                           - uint8_t: 0x00 - 0x1F
  * @param  enableTrigger    Enable trigger.
  *                           - bool: false or true
  * @param  enableDreq       Disable request.
  *                           - false: not disable request
  *                           - true: disable request
  */
extern void EDMA_configMode (EDMA_TypeDef *edma, uint8_t channel, bool enableTrigger, bool enableDreq);

/**
  * \brief  Configures the EDMA transfer structure configurations.
  * \param  edma              The base address of the EDMA module.
  *                            - EDMA1: EDMA1 base address index
  *                            - EDMA2: EDMA2 base address index
  * \param  channel           Channel num.
  *                            - uint8_t: 0x00 - 0x1F
  * \param  srcStepSize       Source data transfer size.
  *                            - This parameter can be any value of @ref EDMA_TRANSFERSIZE
  * \param  destStepSize      Destination data transfer size.
  *                            - This parameter can be any value of @ref EDMA_TRANSFERSIZE
  * \param  srcAddrOffset     Source address signed offset.
  *                            - int16_t: -2^15 - 2^15-1
  * \param  destAddrOffset    Destination address signed offset.
  *                            - int16_t: -2^15 - 2^15-1
  */
extern void EDMA_configTransfer (EDMA_TypeDef *edma, uint8_t channel, 
                                 EDMA_TransferSize srcStepSize, EDMA_TransferSize destStepSize,
                                 int16_t srcAddrOffset, int16_t destAddrOffset);

/**
  * \brief  Configures the EDMA TCD Minor Byte Count.
  * \param  edma           The base address of the EDMA module.
  *                         - EDMA1: EDMA1 base address index
  *                         - EDMA2: EDMA2 base address index
  * \param  channel        Channel num.
  *                         - uint8_t: 0x00 - 0x1F
  * \param  minor_bytes    Minor Byte Transfer Count.
  *                         - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
extern void EDMA_configMinorloop (EDMA_TypeDef *edma, uint8_t channel, uint32_t minor_bytes);

/**
  * \brief  Configures the EDMA TCD Major Loop Count.
  * \param  edma           The base address of the EDMA module.
  *                         - EDMA1: EDMA1 base address index
  *                         - EDMA2: EDMA2 base address index
  * \param  channel        Channel num.
  *                         - uint8_t: 0x00 - 0x1F
  * \param  minor_bytes    Minor Byte Transfer Count.
  *                         - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
extern void EDMA_configMajorloop (EDMA_TypeDef *edma, uint8_t channel, uint32_t majorLoopCounts);

/**
  * \brief  Configures the EDMA TCD Last Source Address and Last Destination Address.
  * \param  edma            The base address of the EDMA module.
  *                          - EDMA1: EDMA1 base address index
  *                          - EDMA2: EDMA2 base address index
  * \param  channel         Channel num.
  * \param  srcLastAddr     set the SLAST value.
  *                          - int32_t: -2^31 - 2^31-1
  * \param  destLastAddr    set the DLAST value.
  *                          - int32_t: -2^31 - 2^31-1
  */
extern void EDMA_adjustAddr (EDMA_TypeDef *edma, uint8_t channel, int32_t srcLastAddr, int32_t destLastAddr);

/**
  * \brief  Configures the EDMA tcd structure and link the next tcd.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  config     Tcd config param.
  *                     This parameter can be any value of @ref EDMA_TRANSFERCONFIG
  * \param  nextTcd    next tcd
  *                     This parameter can be any value of @ref EDMA_TCD_TypeDef
  */
extern void EDMA_configTcdTransfer (EDMA_TypeDef *edma, const EDMA_TransferConfig *config, EDMA_TCD_TypeDef *nextTcd);

/**
  * \brief  Configure the corresponding EDMA channel.
  * \param  edma      The base address of the EDMA module.
  *                    - EDMA1: EDMA1 base address index
  *                    - EDMA2: EDMA2 base address index
  * \param  config    EDMA transfer config.
  *                    This parameter can be any value of @ref EDMA_TRANSFERCONFIG
  */
extern void EDMA_configChannel (EDMA_TypeDef *edma, EDMA_TransferConfig *config);

/**
  * \brief  Configures the EDMA channel preemption feature.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  * \param  type       EDMA channel priority configuration.
  *                     This parameter can be any value of @ref EDMA_CHANNELPREEMPTIONCONFIG
  */
extern void EDMA_setChannelPreemption (EDMA_TypeDef *edma, uint32_t channel, const EDMA_ChannelPreemptionConfig *config);

/**
  * \brief  Configures the EDMA channel preemption feature.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  * \param  type       EDMA channel priority configuration.
  *                     This parameter can be any value of @ref EDMA_CHANNELPREEMPTIONCONFIG
  */
extern void EDMA_setChannelPreemptionConfig (EDMA_TypeDef *edma, uint32_t channel, const EDMA_ChannelPreemptionConfig *config);

/**
  * \brief  Configures the EDMA channel Config.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  * \param  type       EDMA channel priority configuration.
  *                     This parameter can be any value of @ref EDMA_CHANNELPRIORITY
  */
extern void EDMA_configChannelPriority (EDMA_TypeDef *edma, uint32_t channel, const EDMA_ChannelPriority *config);

/**
  * \brief  Initialize the basic configuration of the EDMA peripheral.
  * \param  edma      The base address of the EDMA module.
  *                    - EDMA1: EDMA1 base address index
  *                    - EDMA2: EDMA2 base address index
  * \param  config    EDMA common config.
  *                    This parameter can be any value of @ref EDMA_COMMONCONFIG
  */
extern void EDMA_configModule (EDMA_TypeDef *edma, const EDMA_CommonConfig *config);

/**
  * \brief  Initializes the EDMA peripheral.
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  *                 - EDMA2: EDMA2 base address index
  */
extern void EDMA_initialize (EDMA_TypeDef *edma);

/**
  * \brief  Get the Absolute Address for EDMA.
  * \param  edma         The base address of the EDMA module.
  *                       - EDMA1: EDMA1 base address index
  *                       - EDMA2: EDMA2 base address index
  * \param  virtualAddr  a value is the virtual address to be pass in.
  */
extern uint32_t EDMA_getAbsAddrForMultiCore (uint32_t virtualAddr);

/**
  * \brief  Sets the channel link for the EDMA transfer.
  * \param  edma             The base address of the EDMA module.
  *                           - EDMA1: EDMA1 base address index
  *                           - EDMA2: EDMA2 base address index
  * \param  channel          Channel num.
  *                           - uint8_t: 0x00 - 0x1F
  * \param  type             Channel Link type.
  *                           This parameter can be any value of @ref EDMA_CHANNELLINKTYPE
  * \param  linkedChannel    Linked Channel num.
  *                           - uint8_t: 0x00 - 0x1F
  */
extern void EDMA_setChannelLink (EDMA_TypeDef *edma, uint32_t channel,
                                 EDMA_ChannelLinkType type, uint32_t linkedChannel);


#ifdef __cplusplus
}
#endif


#endif /* __EDMA_H__ */
