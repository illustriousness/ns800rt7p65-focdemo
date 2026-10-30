/**
  * @file       edma.c
  * @author     yangjun
  * @brief      Function file for NS800RT7xxx dma module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "edma.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Functions
 ******************************************************************************/

/**
  * @brief  Configures the EDMA TCD Source Address Register and Destination Address Register.
  * @param  edma        The base address of the EDMA module.
  *                      - EDMA1: EDMA1 base address index
  *                      - EDMA2: EDMA2 base address index
  * @param  channel     Channel num.
  *                      - uint8_t: 0x00 - 0x1F
  * @param  destAddr    Destnation adddress.
  *                      - uint32_t: 0x00UL - 0xFFFFFFFFUL
  * @param  srcAddr     Source address.
  *                      - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
void EDMA_configAddresses (EDMA_TypeDef *edma, uint8_t channel, uint32_t destAddr, uint32_t srcAddr)
{
    WRITE_REG(edma->TCD[channel].SADDR.WORDVAL, srcAddr);
    WRITE_REG(edma->TCD[channel].DADDR.WORDVAL, destAddr);
}

/**
  * @brief  Configures the EDMA TCD Source Address Register.
  * @param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * @param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  * @param  srcAddr    Source address.
  *                     - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
void EDMA_configTcdSrcAddresses (EDMA_TypeDef *edma, uint8_t channel, uint32_t srcAddr)
{
    WRITE_REG(edma->TCD[channel].SADDR.WORDVAL, srcAddr);
}

/**
  * @brief  Configures the EDMA TCD Destination Address Register.
  * @param  edma        The base address of the EDMA module.
  *                      - EDMA1: EDMA1 base address index
  *                      - EDMA2: EDMA2 base address index
  * @param  channel     Channel num.
  *                      - uint8_t: 0x00 - 0x1F
  * @param  destAddr    Destnation adddress.
  *                      - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
void EDMA_configTcdDestAddresses (EDMA_TypeDef *edma, uint8_t channel, uint32_t destAddr)
{
    WRITE_REG(edma->TCD[channel].DADDR.WORDVAL, destAddr);
}

/**
  * @brief  Configures the EDMA mode.
  * @param  edma             The base address of the EDMA module.
  *                           - EDMA1: EDMA1 base address index
  *                           - EDMA2: EDMA2 base address index
  * @param  channel          Channel num.
  *                           - uint8_t: 0x00 - 0x1F
  * @param  enableTrigger    Enable trigger.
  *                           - bool: false or true
  * @param  enableDreq       Disable request.
  *                           - bool: false or true
  */
void EDMA_configMode (EDMA_TypeDef *edma, uint8_t channel, bool enableTrigger, bool enableDreq)
{
    if (enableTrigger == 0)
    {
        if (enableDreq)
        {
            SET_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_DREQ_M);
        }
        else
        {
            CLEAR_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_DREQ_M);
        }
    }
}

/**
  * @brief  Configures the EDMA transfer structure configurations.
  * @param  edma              The base address of the EDMA module.
  *                            - EDMA1: EDMA1 base address index
  *                            - EDMA2: EDMA2 base address index
  * @param  channel           Channel num.
  *                            - uint8_t: 0x00 - 0x1F
  * @param  srcStepSize       Source data transfer size.
  *                            - This parameter can be any value of @ref EDMA_TRANSFERSIZE
  * @param  destStepSize      Destination data transfer size.
  *                            - This parameter can be any value of @ref EDMA_TRANSFERSIZE
  * @param  srcAddrOffset     Source address signed offset.
  *                            - int16_t: -2^15 - 2^15-1
  * @param  destAddrOffset    Destination address signed offset.
  *                            - int16_t: -2^15 - 2^15-1
  */
void EDMA_configTransfer (EDMA_TypeDef *edma, uint8_t channel, 
                         EDMA_TransferSize srcStepSize, EDMA_TransferSize destStepSize,
                         int16_t srcAddrOffset, int16_t destAddrOffset)
{
    uint16_t mask;

    MODIFY_REG(edma->TCD[channel].TO.WORDVAL, (EDMA_TCD_TO_DSIZE_S | EDMA_TCD_TO_SSIZE_M),
               ((uint32_t)(srcStepSize << EDMA_TCD_TO_SSIZE_S)) |
               ((uint32_t)(destStepSize << EDMA_TCD_TO_DSIZE_S)));

    /* Source address signed offset */
    mask = (uint16_t)(srcAddrOffset & (uint16_t)EDMA_TCD_TO_SOFF_M);
    MODIFY_REG(edma->TCD[channel].TO.WORDVAL, (EDMA_TCD_TO_SOFF_M), (uint32_t)mask);

    /* Destination address signed offset */
    mask = (uint16_t)(destAddrOffset & (uint16_t)EDMA_TCD_CITER_ELINKNO_DOFF_M);
    MODIFY_REG(edma->TCD[channel].CITER, EDMA_TCD_CITER_ELINKNO_DOFF_M, (uint32_t)mask);
}

/**
  * @brief  Configures the EDMA TCD Minor Byte Count.
  * @param  edma          The base address of the EDMA module.
  *                        - EDMA1: EDMA1 base address index
  *                        - EDMA2: EDMA2 base address index
  * @param  channel       Channel num.
  *                        - uint8_t: 0x00 - 0x1F
  * @param  minorBytes    Minor Byte Transfer Count.
  *                        - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
void EDMA_configMinorloop (EDMA_TypeDef *edma, uint8_t channel, uint32_t minorBytes)
{
    /* Minor byte transfer count */
    if (edma->CR.BIT.EMLM == 0U)
    {
        WRITE_REG(edma->TCD[channel].NBYTES, minorBytes);
    }
    else if ((edma->TCD[channel].NBYTES_MLOFFNO.BIT.SMLOE == 0U) && (edma->TCD[channel].NBYTES_MLOFFNO.BIT.DMLOE == 0U))
    {
        MODIFY_REG(edma->TCD[channel].NBYTES, EDMA_TCD_NBYTES_MLOFFNO_NBYTES_M,
                   minorBytes & EDMA_TCD_NBYTES_MLOFFNO_NBYTES_M);
    }
    else
    {
        MODIFY_REG(edma->TCD[channel].NBYTES, EDMA_TCD_NBYTES_MLOFFYES_NBYTES_M,
                   minorBytes & EDMA_TCD_NBYTES_MLOFFYES_NBYTES_M);
    }
}

/**
  * @brief  Configures the EDMA TCD Major Loop Count.
  * @param  edma               The base address of the EDMA module.
  *                             - EDMA1: EDMA1 base address index
  *                             - EDMA2: EDMA2 base address index
  * @param  channel            Channel num.
  *                             - uint8_t: 0x00 - 0x1F
  * @param  majorLoopCounts    Major Loop Count.
  *                             - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
void EDMA_configMajorloop (EDMA_TypeDef *edma, uint8_t channel, uint32_t majorLoopCounts)
{
    uint32_t mask;

    /* Current major iteration count */
    if (edma->TCD[channel].CITER_ELINKNO.BIT.ELINK == 0U)
    {
        mask = (majorLoopCounts << EDMA_TCD_CITER_ELINKNO_CITER_S) & EDMA_TCD_CITER_ELINKNO_CITER_M;
        MODIFY_REG(edma->TCD[channel].CITER, EDMA_TCD_CITER_ELINKNO_CITER_M, mask);
    }
    else
    {
        mask = (majorLoopCounts << EDMA_TCD_CITER_ELINKYES_CITER_S) & EDMA_TCD_CITER_ELINKYES_CITER_M;
        MODIFY_REG(edma->TCD[channel].CITER, EDMA_TCD_CITER_ELINKYES_CITER_M, mask);
    }

    /* Starting major iteration count */
    if (edma->TCD[channel].BITER_ELINKNO.BIT.ELINK == 0U)
    {
        mask = (majorLoopCounts << EDMA_TCD_BITER_ELINKNO_BITER_S) & EDMA_TCD_BITER_ELINKNO_BITER_M;
        MODIFY_REG(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_BITER_M, mask);
    }
    else
    {
        mask = (majorLoopCounts << EDMA_TCD_BITER_ELINKYES_BITER_S) & EDMA_TCD_BITER_ELINKYES_BITER_M;
        MODIFY_REG(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKYES_BITER_M, mask);
    }
}

/**
  * @brief  Configures the EDMA TCD Last Source Address and Last Destination Address.
  * @param  edma            The base address of the EDMA module.
  *                          - EDMA1: EDMA1 base address index
  *                          - EDMA2: EDMA2 base address index
  * @param  channel         Channel num.
  *                          - uint8_t: 0x00 - 0x1F
  * @param  srcLastAddr     set the SLAST value.
  *                          - int32_t: -2^31 - 2^31-1
  * @param  destLastAddr    set the DLAST value.
  *                          - int32_t: -2^31 - 2^31-1
  */
void EDMA_adjustAddr (EDMA_TypeDef *edma, uint8_t channel, int32_t srcLastAddr, int32_t destLastAddr)
{
    WRITE_REG(edma->TCD[channel].SLAST.WORDVAL, (uint32_t)srcLastAddr);
    WRITE_REG(edma->TCD[channel].DLASTSGA.WORDVAL, (uint32_t)destLastAddr);
}

/**
  * @brief  Configures the EDMA tcd structure and link the next tcd.
  * @param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * @param  config     Tcd config param.
  *                     This parameter can be any value of @ref EDMA_TRANSFERCONFIG
  * @param  nextTcd    next tcd
  *                     This parameter can be any value of @ref EDMA_TCD_TypeDef
  */
void EDMA_configTcdTransfer (EDMA_TypeDef *edma,
                                           const EDMA_TransferConfig *config,
                                           EDMA_TCD_TypeDef *nextTcd)
{
    EDMA_configAddresses(edma, config->channel, config->destAddr, config->srcAddr);


    EDMA_configTransfer(edma, config->channel,
                        config->srcTransferSize, config->destTransferSize,
                        config->srcOffset, config->destOffset);

    EDMA_configMinorloop(edma, config->channel, config->minorLoopBytes);

    EDMA_configMajorloop(edma, config->channel, config->majorLoopCounts);

    EDMA_adjustAddr(edma, config->channel, config->slast, config->dlast);

    /* Enable scatter/gather processing */
    if (nextTcd)
    {
        WRITE_REG(edma->TCD[config->channel].DLASTSGA.WORDVAL, (uint32_t)nextTcd);

        /* Enable Scatter/Gather Processing */
        SET_BIT(edma->TCD[config->channel].BITER, EDMA_TCD_BITER_ELINKNO_ESG_M);

        /* Clear DREQ */
        CLEAR_BIT(edma->TCD[config->channel].BITER, EDMA_TCD_BITER_ELINKNO_DREQ_M);
    }
}

/**
  * @brief  Configure the corresponding EDMA channel.
  * @param  edma      The base address of the EDMA module.
  *                    - EDMA1: EDMA1 base address index
  *                    - EDMA2: EDMA2 base address index
  * @param  config    EDMA transfer config.
  *                    This parameter can be any value of @ref EDMA_TRANSFERCONFIG
  */
void EDMA_configChannel (EDMA_TypeDef *edma, EDMA_TransferConfig *config)
{
    if (config->enMajorInt)
    {
        /* Enable major int. */
        SET_BIT(edma->TCD[config->channel].BITER, EDMA_TCD_BITER_ELINKNO_INTMAJOR_M);
    }
    if (config->enErrInt)
    {
        /* Enable err int. */
        SET_BIT(edma->EEI.WORDVAL, (0x1UL << config->channel));
    }
    EDMA_configMode(edma, config->channel, config->enTrigger, config->enDreq);

    EDMA_configTcdTransfer(edma, config, (void *)0);
}

/**
  * @brief  Configures the EDMA channel preemption feature.
  * @param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * @param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  * @param  type       EDMA channel priority configuration.
  *                     This parameter can be any value of @ref EDMA_CHANNELPREEMPTIONCONFIG
  */
void EDMA_setChannelPreemption (EDMA_TypeDef *edma, uint32_t channel,
                                const EDMA_ChannelPreemptionConfig *config)
{
    uint8_t cfg = 0;

    cfg = EDMA_DCHPRIn(edma, channel);

    if (config->enablePreemptAbility)
    {
        cfg &= (uint8_t)(~EDMA_DCHPRI0_DPA3_M);
    }
    else
    {
        cfg |= (uint8_t)(EDMA_DCHPRI0_DPA3_M);
    }
    if (config->enableChannelPreemption)
    {
        cfg |= (uint8_t)(EDMA_DCHPRI0_ECP3_M);
    }
    else
    {
        cfg &= (uint8_t)(~EDMA_DCHPRI0_ECP3_M);
    }

    EDMA_DCHPRIn(edma, channel) = cfg;
}

/**
  * @brief  Configures the EDMA channel preemption feature.
  * @param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * @param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  * @param  type       EDMA channel priority configuration.
  *                     This parameter can be any value of @ref EDMA_CHANNELPREEMPTIONCONFIG
  */
void EDMA_setChannelPreemptionConfig (EDMA_TypeDef *edma, uint32_t channel,
                                                    const EDMA_ChannelPreemptionConfig *config)
{
    uint8_t cfg = 0;

    /* Channel can suspend other channel with low priority */
    if (config->enablePreemptAbility)
    {
        cfg &= (uint8_t)(~EDMA_DCHPRI0_DPA3_M);
    }
    else
    {
        cfg |= (uint8_t)(EDMA_DCHPRI0_DPA3_M);
    }
    /* Channel can be suspended by other channel with higher priority */
    if (config->enableChannelPreemption) 
    {
        cfg |= (uint8_t)(EDMA_DCHPRI0_ECP3_M);
    }
    else
    {
        cfg &= (uint8_t)(~EDMA_DCHPRI0_ECP3_M);
    }
    cfg |= config->channelPriority;

    EDMA_DCHPRIn(edma, channel) = cfg;
}

/**
  * @brief  Configures the EDMA channel Priority.
  * @param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  *                     - EDMA2: EDMA2 base address index
  * @param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x1F
  * @param  type       EDMA channel priority configuration.
  *                     This parameter can be any value of @ref EDMA_CHANNELPRIORITY
  */
void EDMA_configChannelPriority (EDMA_TypeDef *edma, uint32_t channel,
                                 const EDMA_ChannelPriority *config)
{
    EDMA_setChannelPreemptionConfig(edma, channel, config);
}

/**
  * @brief  Initialize the basic configuration of the EDMA peripheral.
  * @param  edma      The base address of the EDMA module.
  *                    - EDMA1: EDMA1 base address index
  *                    - EDMA2: EDMA2 base address index
  * @param  config    EDMA common config.
  *                    This parameter can be any value of @ref EDMA_COMMONCONFIG
  */
void EDMA_configModule (EDMA_TypeDef *edma, const EDMA_CommonConfig *config)
{
    uint32_t tmpreg;

    tmpreg = edma->CR.WORDVAL;
    tmpreg &= ~(EDMA_CR_ERCA_M | EDMA_CR_HOE_M | EDMA_CR_CLM_M | EDMA_CR_EDBG_M | EDMA_CR_EMLM_M);

    tmpreg |= ((uint32_t)config->enableRoundRobinChnArbitration << EDMA_CR_ERCA_S) |
              ((uint32_t)config->enableRoundRobinGrpArbitration << EDMA_CR_ERGA_S) |
              ((uint32_t)config->enableHaltOnError << EDMA_CR_HOE_S) |
              ((uint32_t)config->enableContinuousLinkMode << EDMA_CR_CLM_S) |
              ((uint32_t)config->enableDebugMode << EDMA_CR_EDBG_S) |
              ((uint32_t)config->enableEmlm << EDMA_CR_EMLM_S);
    WRITE_REG(edma->CR.WORDVAL, tmpreg);
}

/**
  * @brief  Initializes the EDMA peripheral.
  * @param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  *                 - EDMA2: EDMA2 base address index
  */
void EDMA_initialize (EDMA_TypeDef *edma)
{
    /* Init tcd zone */
    memset((void *)&(edma->TCD[0].SADDR), 0x00UL, 1024UL);
}

/**
  * @brief  Get the Absolute Address for EDMA.
  * @param  edma         The base address of the EDMA module.
  *                       - EDMA1: EDMA1 base address index
  *                       - EDMA2: EDMA2 base address index
  * @param  virtualAddr  a value is the virtual address to be pass in.
  * 
  * @return Returns the value of the Absolute Address for EDMA
  */
uint32_t EDMA_getAbsAddrForMultiCore (uint32_t virtualAddr)
{
    static const uint32_t tcm_offsets[] = {
        0,
        MCM_CORE1_TCM_ABSADDR_OFFSET,
        MCM_CORE2_TCM_ABSADDR_OFFSET
    };

    MCM_CoreIndex cpuid = MCM_getCoreIndex(MCM);

    /*The virtual address belongs to the ITCM or DTCM area */
    uint32_t tcmFlag = 0;
    if (virtualAddr <= MCM_ITCM_VRTLADDR_END)
    {
        tcmFlag = 1;    /* ITCM */
    }
    else if ((virtualAddr >= MCM_DTCM_VRTLADDR_START) && (virtualAddr <= MCM_DTCM_VRTLADDR_END))
    {
        tcmFlag = 2;    /* DTCM */
    }

    /* This virtual address does not belong to the ITCM or DTCM area. */
    if (tcmFlag == 0)
    {
        return virtualAddr;
    }
    else
    {
        return (virtualAddr + tcm_offsets[cpuid]);
    }
}

/**
  * @brief  Sets the channel link for the EDMA transfer.
  * @param  edma             The base address of the EDMA module.
  *                           - EDMA1: EDMA1 base address index
  *                           - EDMA2: EDMA2 base address index
  * @param  channel          Channel num.
  *                           - uint8_t: 0x00 - 0x1F
  * @param  type             Channel Link type.
  *                           This parameter can be any value of @ref EDMA_CHANNELLINKTYPE
  * @param  linkedChannel    Linked Channel num.
  *                           - uint8_t: 0x00 - 0x1F
  */
void EDMA_setChannelLink (EDMA_TypeDef *edma, uint32_t channel,
                          EDMA_ChannelLinkType type, uint32_t linkedChannel)
{
    if (type == EDMA_MINORLINK)
    {
        /* Enable minor link */
        SET_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKYES_ELINK_M);
        SET_BIT(edma->TCD[channel].CITER, EDMA_TCD_CITER_ELINKYES_ELINK_M);

        /* Set linked channel */
        MODIFY_REG(edma->TCD[channel].CITER, EDMA_TCD_CITER_ELINKYES_LINKCH_M,
                   (uint32_t)(linkedChannel << EDMA_TCD_CITER_ELINKYES_LINKCH_S));
        MODIFY_REG(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKYES_LINKCH_M,
                   (uint32_t)(linkedChannel << EDMA_TCD_BITER_ELINKYES_LINKCH_S));
    }
    else if (type == EDMA_MAJORLINK)
    {
        /* Enable major link */
        SET_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKYES_MAJORELINK_M);

        /* Set major linked channel */
        MODIFY_REG(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKYES_MAJORLINKCH_M, \
                   (uint32_t)(linkedChannel << EDMA_TCD_BITER_ELINKYES_MAJORLINKCH_S));
    }
    else
    {
        /* Disable minor link */
        CLEAR_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKYES_ELINK_M);
        CLEAR_BIT(edma->TCD[channel].CITER, EDMA_TCD_CITER_ELINKYES_ELINK_M);

        /* Disable major link */
        CLEAR_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKYES_MAJORELINK_M);
    }
}

