/**
  * @file       upp.c
  * @author     Alex-J
  * @brief      Function file for NS800RT7xxx uPP module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "upp.h"


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
 * @brief  Sets uPP Internal DMA Channel Descriptors.
 * @note   This function configures DMA descriptors for either channel I or Q which
 *         includes starting address of DMA transfer, line count, byte count & line
 *         offset address for DMA transfer. In Tx mode, starting address is the
 *         address of data buffer to be transmitted while in Rx mode it is the
 *         address of buffer where recieved data is to be copied.
 * 
 * @param  upp      upp pointer to a UPP_TypeDef structure
 *                    - UPP: UPP base address index
 * @param  channel  the required uPP internal DMA channel to be configured.
 *                  The \e channel parameter can take any of the following values:
 *                    - \b UPP_DMA_CHANNEL_I - uPP DMA channel I
 *                    - \b UPP_DMA_CHANNEL_Q - uPP DMA channel Q
 * @param  desc     the required DMA descriptor setting.
 */
void UPP_setDMADescriptor (UPP_TypeDef *upp, UPP_DMAChannel channel, const UPP_DMADescriptor *const desc)
{
    if (channel == UPP_DMA_CHANNEL_I)
    {
        /* Sets DMA descriptors for channel I. */
        WRITE_REG(upp->CHIDESC0.WORDVAL, desc->addr);
        WRITE_REG(upp->CHIDESC1.WORDVAL,
                  ((uint32_t)desc->byteCount | (((uint32_t)desc->lineCount) << UPP_CHIDESC1_LCNT_S)));
        WRITE_REG(upp->CHIDESC2.WORDVAL, (uint32_t)desc->lineOffset);
    }
    else
    {
        /* Sets DMA descriptors for channel Q. */
        WRITE_REG(upp->CHQDESC0.WORDVAL, desc->addr);
        WRITE_REG(upp->CHQDESC1.WORDVAL,
                  ((uint32_t)desc->byteCount | (((uint32_t)desc->lineCount) << UPP_CHQDESC1_LCNT_S)));
        WRITE_REG(upp->CHQDESC2.WORDVAL, (uint32_t)desc->lineOffset);
    }
}

/**
 * @brief  Returns current status of uPP internal DMA channel transfer.
 * @note   This function returns the current status for either channel I or Q active
 *         transfer which includes current DMA transfer address, current line & byte
 *         number of the transfer.
 * 
 * @param  upp      upp pointer to a UPP_TypeDef structure
 *                    - UPP: UPP base address index
 * @param  channel  the required uPP internal DMA channel to be configured.
 *                  The \e channel parameter can take any of the following values:
 *                    - \b UPP_DMA_CHANNEL_I - uPP DMA channel I
 *                    - \b UPP_DMA_CHANNEL_Q - uPP DMA channel Q
 * @param  status   current status for DMA channel returned by the api.
 */
void UPP_getDMAChannelStatus (UPP_TypeDef *upp, UPP_DMAChannel channel, UPP_DMAChannelStatus *const status)
{
    uint32_t cntStatus;

    if (channel == UPP_DMA_CHANNEL_I)
    {
        /* Return the current status for channel I. */
        cntStatus            = upp->CHIST1.WORDVAL;
        status->curAddr      = upp->CHIST0.WORDVAL;
        status->curByteCount = (uint16_t)(cntStatus & UPP_CHIDESC1_BCNT_M);
        status->curLineCount = (uint16_t)(cntStatus >> UPP_CHIDESC1_LCNT_S);
    }
    else
    {
        /* Return the current status for channel Q. */
        cntStatus            = upp->CHQST1.WORDVAL;
        status->curAddr      = upp->CHQST0.WORDVAL;
        status->curByteCount = (uint16_t)(cntStatus & UPP_CHQDESC1_BCNT_M);
        status->curLineCount = (uint16_t)(cntStatus >> UPP_CHQDESC1_LCNT_S);
    }
}

/**
 * @brief  Returns Pend status of uPP internal DMA channel descriptor.
 * @note   This function returns the Pend status for DMA channel I or Q descriptor
 *         which specifies whether previous descriptor is copied from shadow register
 *         to original register & new descriptor can be programmed or the previous
 *         descriptor is still pending & new descriptor cannot be programmed.
 * 
 * @param  upp      upp pointer to a UPP_TypeDef structure
 *                    - UPP: UPP base address index
 * @param  channel  the required uPP internal DMA channel to be configured.
 *                  The \e channel parameter can take any of the following values:
 *                    - \b UPP_DMA_CHANNEL_I - uPP DMA channel I
 *                    - \b UPP_DMA_CHANNEL_Q - uPP DMA channel Q
 * 
 * @return Returns pend status of DMA channel I descriptor. It can return
 *         following values:
 *           - \b true  - specifies that writing of new DMA descriptor is not allowed.
 *           - \b false - specifies that writing of new DMA descriptor is allowed.
 */
bool UPP_isDescriptorPending (UPP_TypeDef *upp, UPP_DMAChannel channel)
{
    bool status;

    if (channel == UPP_DMA_CHANNEL_I)
    {
        /* Return the pend status for channel I descriptor. */
        status = (READ_BIT(upp->CHIST2.WORDVAL, UPP_CHIST2_PEND_M) == UPP_CHIST2_PEND_M);
    }
    else
    {
        /* Return the pend status for channel Q descriptor. */
        status = (READ_BIT(upp->CHQST2.WORDVAL, UPP_CHQST2_PEND_M) == UPP_CHQST2_PEND_M);
    }

    return (status);
}

/**
 * @brief  Returns active status of uPP Internal DMA Channel descriptor.
 * @note   This function returns the active status of uPP internal DMA channel I or Q
 *         descriptor which specifies whether the descriptor is being currently
 *         active(transferring data) or idle.
 * 
 * @param  upp      upp pointer to a UPP_TypeDef structure
 *                    - UPP: UPP base address index
 * @param  channel  the required uPP internal DMA channel to be configured.
 *                  The \e channel parameter can take any of the following values:
 *                    - \b UPP_DMA_CHANNEL_I - uPP DMA channel I
 *                    - \b UPP_DMA_CHANNEL_Q - uPP DMA channel Q
 * 
 * @return Returns active status of uPP internal DMA channel descriptor.
 *         It can return following values:
 *           - \b true  - specifies that desciptor is currently active.
 *           - \b false - specifies that desciptor is currently idle.
 */
bool UPP_isDescriptorActive (UPP_TypeDef *upp, UPP_DMAChannel channel)
{
    bool status;

    if (channel == UPP_DMA_CHANNEL_I)
    {
        /* Returns active status for channel I descriptor. */
        status = (READ_BIT(upp->CHIST2.WORDVAL, UPP_CHIST2_ACT_M) == UPP_CHIST2_ACT_M);
    }
    else
    {
        /* Returns active status for channel Q descriptor. */
        status = (READ_BIT(upp->CHQST2.WORDVAL, UPP_CHQST2_ACT_M) == UPP_CHQST2_ACT_M);
    }

    return (status);
}

/**
 * @brief  Reads the received data from uPP Rx MSG RAM.
 * @note   This function reads the received data from uPP Rx MSG RAM. The sum of
 *         parameters \e length & \e offset should be less than the size of the Rx
 *         MSG RAM.
 * 
 * @param  rxBase  the uPP Rx MSG RAM base address.
 * @param  array   the address of the array of words to be transmitted.
 * @param  length  the number of dwords in the array to be transmitted.
 * @param  offset  offset in Rx Data RAM from where data read will start.
 */
void UPP_readRxMsgRAM (uint32_t rxBase, uint32_t array[], uint16_t length, uint16_t offset)
{
    uint16_t i;

    if ((rxBase != UPP_RX_MSG_RAM_BASE) || ((length + offset) < UPP_RX_MSGRAM_MAX_SIZE))
    {
        return;
    }

    for (i = 0U; i < length; i++)
    {
        /* Read one 32-bit dword. */
        array[i] = TYPE32(rxBase + offset + i);
    }
}

/**
 * @brief  Reads the received data from uPP Rx MSG RAM.
 * @note   This function reads the received data from uPP Rx MSG RAM. The sum of
 *         parameters \e length & \e offset should be less than the size of the Rx
 *         MSG RAM.
 * 
 * @param  rxBase  the uPP Rx MSG RAM base address.
 * @param  array   the address of the array of words to be transmitted.
 * @param  length  the number of dwords in the array to be transmitted.
 * @param  offset  offset in Rx Data RAM from where data read will start.
 */
void UPP_writeTxMsgRAM (uint32_t txBase, const uint32_t array[], uint16_t length, uint16_t offset)
{
    uint16_t i;

    if ((txBase != UPP_TX_MSG_RAM_BASE) || ((length + offset) < UPP_TX_MSGRAM_MAX_SIZE))
    {
        return;
    }

    for (i = 0U; i < length; i++)
    {
        /* Write one 32-bit dword. */
        TYPE32(txBase + offset + i) = array[i];
    }
}
