/**
  * @file       flexcan.c
  * @author     Gordon-Zheng
  * @brief      Function file for NS800RT7xxx flexcan module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
/*******************************************************************************
 * the includes
 ******************************************************************************/
#include "flexcan.h"


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
  * @brief  Convert message buff size to the corresponding RAM size
  * @param  MBSizeCode    message buff size
  *                        - 0: FLEXCANDRV_MB_SIZE_BYTE_8
  *                        - 1: FLEXCANDRV_MB_SIZE_BYTE_16
  *                        - 2: FLEXCANDRV_MB_SIZE_BYTE_32
  *                        - 3: FLEXCANDRV_MB_SIZE_BYTE_64
  * @return Returns the corresponding RAM size
  *                        - This parameter is one of the data elements in the
  *                          following array [0, 16, 24, 40, 72]
  */
uint8_t FLEXCANDRV_ConvertMsgBufSizeSel (uint8_t MBSizeCode)
{
    uint8_t result = 0;

    switch (MBSizeCode)
    {
        case FLEXCANDRV_MB_SIZE_BYTE_8:
            result = 16;
            break;

        case FLEXCANDRV_MB_SIZE_BYTE_16:
            result = 24;
            break;

        case FLEXCANDRV_MB_SIZE_BYTE_32:
            result = 40;
            break;

        case FLEXCANDRV_MB_SIZE_BYTE_64:
            result = 72;
            break;

        default:
            result = 0;
    }

    return result;
}

/**
  * @brief  Get the message buff start address
  * @param  obj         pointer to a FLEXCANDRV_Type structure
  * @param  msgBufId    message buffer index to store the message object
  *                      - This parameter is an unsigned integer that is greater
  *                        than or equal to 0x00 and less than or equal to 0x7F
  * @return Returns the message buff start address
  *                      - This parameter is an unsigned integer that is greater
  *                        than or equal to 0x00 and less than or equal to 0xFFFFFFFF
  */
uint32_t FLEXCANDRV_GetMsgBufStartAddr (FLEXCANDRV_Type *obj, uint16_t msgBufId)
{
    /* get the first message buffer start address */
    uint32_t addr = FLEXCANREG_GetMsgBufferStartAddr(obj->flexCanReg);
    uint8_t  msgBufSize;

    /* get the message buffer size */
    uint8_t msgBufSizeSel = FLEXCANDRV_MB_SIZE_BYTE_8;
    if (FLEXCANREG_GetFdEnable(obj->flexCanReg))
    {
        msgBufSizeSel = FLEXCANREG_GetRegionDataSizeSel(obj->flexCanReg, 0);
    }

    msgBufSize = (FLEXCANDRV_ConvertMsgBufSizeSel(msgBufSizeSel) / 4);

    if (msgBufSizeSel == FLEXCANDRV_MB_SIZE_BYTE_8)
    {
        addr += (msgBufSize * msgBufId) * 4;
    }
    else if (msgBufSizeSel == FLEXCANDRV_MB_SIZE_BYTE_16)
    {
        addr += (msgBufSize * msgBufId + (2 * (msgBufId / 21))) * 4;
    }
    else if (msgBufSizeSel == FLEXCANDRV_MB_SIZE_BYTE_32)
    {
        addr += (msgBufSize * msgBufId + (8 * (msgBufId / 12))) * 4;
    }
    else if (msgBufSizeSel == FLEXCANDRV_MB_SIZE_BYTE_64)
    {
        if (msgBufId < 28)
        {
            addr += (msgBufSize * msgBufId + (2 * (msgBufId / 7))) * 4;
        }
        else
        {
            addr += 0xF80;
            addr += (((msgBufSize * (msgBufId - 28)) + (2 * ((msgBufId - 28) / 7))) * 4);
        }
    }

    return addr;
}

/**
  * @brief  Convert message buff DLC type to message buff data length
  * @param  dlc    message buff size
  *                 - This parameter can be any value of @ref FLEXCANDRV_DATALENCODETYPE
  * @return Returns the corresponding message buff data length
  *                 - This parameter is one of the data elements in the following array
  *                   [0 ~ 8, 12, 16, 24, 32, 48, 64]
  */
uint8_t FLEXCANDRV_DLC2DataLen (FLEXCANDRV_DataLenCodeType dlc)
{
    uint8_t dataLen = 0;

    switch (dlc)
    {
        case DLC_BYTE_0:
        case DLC_BYTE_1:
        case DLC_BYTE_2:
        case DLC_BYTE_3:
        case DLC_BYTE_4:
        case DLC_BYTE_5:
        case DLC_BYTE_6:
        case DLC_BYTE_7:
        case DLC_BYTE_8:
            dataLen = (uint8_t)dlc;
            break;

        case DLC_BYTE_12:
            dataLen = 12;
            break;

        case DLC_BYTE_16:
            dataLen = 16;
            break;

        case DLC_BYTE_20:
            dataLen = 20;
            break;

        case DLC_BYTE_24:
            dataLen = 24;
            break;

        case DLC_BYTE_32:
            dataLen = 32;
            break;
        case DLC_BYTE_48:
            dataLen = 48;
            break;

        case DLC_BYTE_64:
            dataLen = 64;
            break;

        default:
            break;
    }

    return dataLen;
}

/**
  * @brief  Get the message buff data length for the specified message buff ID 
  * @param  obj         pointer to a FLEXCANDRV_Type structure
  * @param  msgBufId    message buffer index to store the message object
  *                      - This parameter is an unsigned integer that is greater
  *                        than or equal to 0x00 and less than or equal to 0x7F
  * @return Returns the corresponding message buff data length
  *                      - This parameter is one of the data elements in the following 
  *                        array [0 ~ 8, 12, 16, 24, 32, 48, 64]
  */
uint8_t FLEXCANDRV_GetMsgBufDataLen (FLEXCANDRV_Type *obj, uint16_t msgBufId)
{
    uint32_t *msgBufPtr = NULL;
    uint8_t   dlc     = 0;
    uint8_t   dataLen = 0;

    /* get current message buffer start address */
    msgBufPtr = (uint32_t *)FLEXCANDRV_GetMsgBufStartAddr(obj, msgBufId);

    /* get DLC code from message buffer */
    dlc = (*msgBufPtr & MESSAGE_BUFFER_CS_DLC_MASK) >> MESSAGE_BUFFER_CS_DLC_SHIFT;

    /* convert DLC code to data length */
    dataLen = FLEXCANDRV_DLC2DataLen((FLEXCANDRV_DataLenCodeType)dlc);

    return dataLen;
}

/**
  * @brief  Set the message ID and ID type
  * @param  msgBufPtr    pointer to the message buff address
  * @param  msgId        11-bit or 29-bit message ID
  *                       - This parameter is an unsigned integer that is greater 
  *                         than or equal to 0x00 and less than or equal to 0x1FFFFFFF
  * @param  isExt        the message ID is standard ID or extended ID
  *                       - 0: standard ID
  *                       - 1: extended ID
  */
void FLEXCANDRV_SetMsgId (uint32_t *msgBufPtr, uint32_t msgId, bool isExt)
{
    uint32_t tempVar = 0;

    if (isExt)
    {
        /* set extended message ID bit (IDE) */
        msgBufPtr[MESSAGE_BUFFER_CS_WORD_NUM] |= (MESSAGE_BUFFER_CS_IDE_MASK | MESSAGE_BUFFER_CS_SRR_MASK);

        /* set extended message ID */
        tempVar = msgBufPtr[MESSAGE_BUFFER_ID_WORD_NUM];
        tempVar &= ~(MESSAGE_BUFFER_ID_EXT_ID_MASK);
        tempVar |= ((msgId << MESSAGE_BUFFER_ID_EXT_ID_SHIFT) & MESSAGE_BUFFER_ID_EXT_ID_MASK);
        msgBufPtr[MESSAGE_BUFFER_ID_WORD_NUM] = tempVar;
    }
    else
    {
        /* clear extended message ID bit (IDE) */
        msgBufPtr[MESSAGE_BUFFER_CS_WORD_NUM] &= ~(MESSAGE_BUFFER_CS_IDE_MASK | MESSAGE_BUFFER_CS_SRR_MASK);

        /* load standard message ID */
        tempVar = msgBufPtr[MESSAGE_BUFFER_ID_WORD_NUM];
        tempVar &= ~(MESSAGE_BUFFER_ID_STD_ID_MASK);
        tempVar |= ((msgId << MESSAGE_BUFFER_ID_STD_ID_SHIFT) & MESSAGE_BUFFER_ID_STD_ID_MASK);
        msgBufPtr[MESSAGE_BUFFER_ID_WORD_NUM] = tempVar;
    }
}

/**
  * @brief  Set the message buff DLC
  * @param  msgBufPtr    pointer to the message buff address
  * @param  dlc          CODE for message buff data length
  *                       - This parameter can be any value of @ref FLEXCANDRV_DATALENCODETYPE
  */
void FLEXCANDRV_SetMsgDLC (uint32_t *msgBufPtr, FLEXCANDRV_DataLenCodeType dlc)
{
    msgBufPtr[MESSAGE_BUFFER_CS_WORD_NUM] &= (~MESSAGE_BUFFER_CS_DLC_MASK);
    msgBufPtr[MESSAGE_BUFFER_CS_WORD_NUM] |= (((uint32_t)dlc) << MESSAGE_BUFFER_CS_DLC_SHIFT & \
                                              MESSAGE_BUFFER_CS_DLC_MASK);
}

/**
  * @brief  Set message buff DODE for CAN-FD feature
  * @param  msgBufPtr    pointer to the message buff address
  * @param  fdEnable     enable the CAN-FD feature
  *                       - 0: disable the CAN-FD feature
  *                       - 1: enable the CAN-FD feature
  */
void FLEXCANDRV_SetFDEnable (uint32_t *msgBufPtr, bool fdEnable)
{
    /* clear EDL bit */
    msgBufPtr[MESSAGE_BUFFER_CS_WORD_NUM] &= (~MESSAGE_BUFFER_CS_EDL_MASK);
    /* clear BRS bit */
    msgBufPtr[MESSAGE_BUFFER_CS_WORD_NUM] &= (~MESSAGE_BUFFER_CS_BRS_MASK);

    if (fdEnable)
    {
        /* set EDL bit */
        msgBufPtr[MESSAGE_BUFFER_CS_WORD_NUM] |= MESSAGE_BUFFER_CS_EDL_MASK;
        /* set BRS bit */
        msgBufPtr[MESSAGE_BUFFER_CS_WORD_NUM] |= MESSAGE_BUFFER_CS_BRS_MASK;
    }
    else
    {
        /* non CAN-FD keep EDL, BRS bit clear */
    }
}

/**
  * @brief  Set the message type for TX or RX
  * @param  msgBufPtr    pointer to the message buff address
  * @param  msgType      the message type for TX or RX
  *                       - This parameter can be any value of @ref FLEXCANDRV_MSGTYPE
  */
void FLEXCANDRV_SetMsgType (uint32_t *msgBufPtr, FLEXCANDRV_MsgType msgType)
{
    if (msgType == FLEXCANDRV_MSGTYPE_TX)
    {
        /* tx message set CODE as INACTIVE */
        msgBufPtr[MESSAGE_BUFFER_CS_WORD_NUM] &= (~MESSAGE_BUFFER_CS_CODE_MASK);
        msgBufPtr[MESSAGE_BUFFER_CS_WORD_NUM] |= ((FLEXCANDRV_MSG_BUF_CODE_INACTIVE << MESSAGE_BUFFER_CS_CODE_SHIFT) \
                                                 & MESSAGE_BUFFER_CS_CODE_MASK);
    }
    else if (msgType == FLEXCANDRV_MSGTYPE_RX)
    {
        /* rx message set CODE as RX_ACTIVE */
        msgBufPtr[MESSAGE_BUFFER_CS_WORD_NUM] &= (~MESSAGE_BUFFER_CS_CODE_MASK);
        msgBufPtr[MESSAGE_BUFFER_CS_WORD_NUM] |= ((FLEXCANDRV_MSG_BUF_CODE_RX_ACTIVE << MESSAGE_BUFFER_CS_CODE_SHIFT) \
                                                 & MESSAGE_BUFFER_CS_CODE_MASK);
    }
    else
    {
        /* msgType is invalid, do nothing */
    }
}

/**
  * @brief  Initialize the RAM space of FLEXCAN
  * @param  obj    pointer to a FLEXCANDRV_Type structure
  */
void FLEXCANDRV_InitCanRAM (FLEXCANDRV_Type *obj)
{
    uint32_t *u32Ptr = (uint32_t *)FLEXCANREG_GetMsgBufferStartAddr(obj->flexCanReg);
    uint32_t *tempPtr = NULL;
    uint32_t  i = 0;

    /* 0x80 - 0x880: message buffer 512 byte * 4 region */
    for (i = 0; i < 512; i++)
    {
        tempPtr = (u32Ptr + i);
        *tempPtr = 0;
    }

    /* 0x880 - 0xA80: RXIMR Rx Individual Mask Registers 4 byte * 128 */
    for (i = 0; i < 128; i++)
    {
        tempPtr = (u32Ptr + 512 + i);
        *tempPtr = 0;
    }

    /* 0xA80 - 0xAAC: RXFIR(0xA80 - 0xA94) + RXMASK(0xAA0 - 0xAAC) */
    for (i = 0; i < 11; i++)
    {
        tempPtr = (u32Ptr + 640 + i);
        *tempPtr = 0;
    }

    /* 0xAB0 - 0xADC: SMBs (normal CAN) */
    for (i = 0; i < 11; i++)
    {
        tempPtr = (u32Ptr + 652 + i);
        *tempPtr = 0;
    }

    /* 0xC20 - 0xC2C: Rx SMBs timestamp */
    for (i = 0; i < 4; i++)
    {
        tempPtr = (u32Ptr + 744 + i);
        *tempPtr = 0;
    }

    /* 0xC30 - 0xE2C: HR STAMPs, for FD only */
    for (i = 0; i < 128; i++)
    {
        tempPtr = (u32Ptr + 748 + i);
        *tempPtr = 0;
    }

    /* 0xF28 - 0xFFC: SMBs (CAN-FD) */
    for (i = 0; i < 53; i++)
    {
        tempPtr = (u32Ptr + 938 + i);
        *tempPtr = 0;
    }

    /* 0x1000 - 0x17FC: enhanced message buffer maximum 2MB, for FD only */
    for (i = 0; i < 512; i++)
    {
        tempPtr = (u32Ptr + 992 + i);
        *tempPtr = 0;
    }        

    /* 0x2000 - 0x29FC: Enhance rx fifo(CAN-FD) */
    u32Ptr = (uint32_t *)FLEXCANREG_GetEnhRxFifoStartAddr(obj->flexCanReg);
    for (i = 0; i < 640; i++)
    {
        tempPtr = (u32Ptr + i);
        *tempPtr = 0;
    }

    /* 0x3000 - 0x31FC: Enhance rx filter element 0-127 (CAN-FD) */
    u32Ptr = (uint32_t *)FLEXCANREG_GetEnhRxFifoFilterStartAddr(obj->flexCanReg, 0);
    for (i = 0; i < 128; i++)
    {
        tempPtr = (u32Ptr + i);
        *tempPtr = 0;
    }
}

/** 
  * @brief  Initialize the FLEXCAN driver module
  * @param  obj           pointer to a FLEXCANDRV_Type structure
  * @param  flexCanReg    pointer to a FLEXCANREG_TypeDef structure
  * @param  initHwPar     pointer to a FLEXCANDRV_InitHwParType structure
  */ 
void FLEXCANDRV_Init (FLEXCANDRV_Type *obj, FLEXCANREG_TypeDef *flexCanReg, FLEXCANDRV_InitHwParType *initHwPar)
{
    obj->initHwPar.canRamNum      = initHwPar->canRamNum;
    obj->initHwPar.canInstanceIdx = initHwPar->canInstanceIdx;
    obj->flexCanReg               = flexCanReg;
}

/** 
  * @brief  Get the default configuration for FLEXCAN controller
  * @param  controllerCfg    pointer to a FLEXCANDRV_ControllerCfgType structure
  */ 
void FLEXCANDRV_GetDefaultCfg (FLEXCANDRV_ControllerCfgType *controllerCfg)
{
    controllerCfg->clkSrc                      = FLEXCANDRV_CLKSRC_CHICLK;
    controllerCfg->fdEnable                    = 0;
    controllerCfg->fdISOEnable                 = 0;
    controllerCfg->fifoEnable                  = 0;
    controllerCfg->enhancefifoEnable           = 0;
    controllerCfg->dmaEnable                   = 0;
    controllerCfg->bitTiming.prescalerDiv      = 0;
    controllerCfg->bitTiming.propSeg           = 0;
    controllerCfg->bitTiming.phaseSeg1         = 0;
    controllerCfg->bitTiming.phaseSeg2         = 0;
    controllerCfg->bitTiming.resyncJumpWidth   = 0;
    controllerCfg->fdBitTiming.prescalerDiv    = 0;
    controllerCfg->fdBitTiming.propSeg         = 0;
    controllerCfg->fdBitTiming.phaseSeg1       = 0;
    controllerCfg->fdBitTiming.phaseSeg2       = 0;
    controllerCfg->fdBitTiming.resyncJumpWidth = 0;
    controllerCfg->msgBufDataLenSel            = FLEXCANDRV_MB_SIZE_BYTE_8;
    controllerCfg->rxMBGlobalMask              = 0xFFFFFFFF;
    controllerCfg->rxMB14Mask                  = 0xFFFFFFFF;
    controllerCfg->rxMB15Mask                  = 0xFFFFFFFF;
    controllerCfg->rxFifoGlobalMask            = 0xFFFFFFFF;
    controllerCfg->rxFifoFilternum             = 0x8;
    controllerCfg->individualMaskEnable        = 0;
    controllerCfg->loopbackEnable              = 0;
    controllerCfg->listenMode                  = 0;
    controllerCfg->tdcEnable                   = 0;
    controllerCfg->tdcOffset                   = 0;
    controllerCfg->msgNum                      = 0;
    controllerCfg->msgCfg                      = (void *)0;
    controllerCfg->filterIdtable               = (void *)0;
    controllerCfg->edgeWkupEnable              = 0;
    controllerCfg->WkupIntEnable               = 0;
    controllerCfg->txAbortEnable               = 0;
    controllerCfg->busoffIntEnable             = 0;
    controllerCfg->errorIntEnable              = 0;
    controllerCfg->warningIntEnable            = 0;
    controllerCfg->enhRxFFFilterSelection      = FLEXCANDRV_ENHRXFF_FILTER_SELECT_MASK_FITLER;
    controllerCfg->enhRxFifoWatermark          = 0;
    controllerCfg->enhRxFifoufwIntEnable       = 0;
    controllerCfg->enhRxFifoovfIntEnable       = 0;
    controllerCfg->enhRxFifowmIntEnable        = 0;
    controllerCfg->enhRxFifodataIntEnable      = 0;
    controllerCfg->freeRunningByExtTmrEn       = 0;
    controllerCfg->hrTmrCapturePointSelect     = FLEXCANDRV_HR_TIMER_CAPTURE_DISABLE;
    controllerCfg->mbTmrBaseSelect             = FLEXCANDRV_MB_TIMER_BASE_CAN_TMR;
    controllerCfg->selected3bitSampling        = 0;

    memset(controllerCfg->Legacyfifomask, 0x00, sizeof(controllerCfg->Legacyfifomask));
}

/** 
  * @brief  Start FLEXCAN module
  * @param  obj    pointer to a FLEXCANDRV_Type structure
  */
void FLEXCANDRV_Start (FLEXCANDRV_Type *obj)
{
    /* set freeze mode disable */
    FLEXCANREG_SetFreezeMode(obj->flexCanReg, false);
    /* set halt mode disable */
    FLEXCANREG_SetHaltMode(obj->flexCanReg, false);

    /* wait for synchronization */
    while (FLEXCANREG_GetFreezeAck(obj->flexCanReg))
    {
    }
}

/**
  * @brief  Soft reset FLEXCAN module
  * @param  obj    pointer to a FLEXCANDRV_Type structure
  */
void FLEXCANDRV_SoftReset (FLEXCANDRV_Type *obj)
{
    /* check for low power mode */
    if (FLEXCANREG_GetLowPowerAck(obj->flexCanReg))
    {
        /* Enable clock */
        FLEXCANREG_SetModuleDisable(obj->flexCanReg, false);
        /* wait until enabled */
        while (FLEXCANREG_GetLowPowerAck(obj->flexCanReg))
        {
        }
    }

    /* Reset the CAN module */
    FLEXCANREG_SetSoftResetRequest(obj->flexCanReg, true);
    /* Wait for reset cycle to complete */
    while (FLEXCANREG_GetSoftResetRequest(obj->flexCanReg))
    {
    }

    /* set freeze mode enable */
    FLEXCANREG_SetFreezeMode(obj->flexCanReg, true);
    /* set halt mode enable */
    FLEXCANREG_SetHaltMode(obj->flexCanReg, true);

    /* check for freeze Ack */
    while ((FLEXCANREG_GetFreezeAck(obj->flexCanReg) == 0) || (FLEXCANREG_GetNotReadyFlag(obj->flexCanReg) == 0))
    {
        /* soft reset failed */
    }
}

/** 
  * @brief  Configure message object and register the specified CAN message buffer
  * @param  obj         pointer to a FLEXCANDRV_Type structure
  * @param  msgCfg      pointer to a FLEXCANDRV_MsgCfgType structure
  * @param  msgBufId    message buffer index to store the message object
  *                      - This parameter is an unsigned integer that is greater
  *                        than or equal to 0x00 and less than or equal to 0xFF
  */
void FLEXCANDRV_CfgMsgObj (FLEXCANDRV_Type *obj, const FLEXCANDRV_MsgCfgType *msgCfg, uint8_t msgBufId)
{
    uint32_t  *msgBufPtr = NULL;
    /* get current message buffer start address */
    msgBufPtr = (uint32_t *)FLEXCANDRV_GetMsgBufStartAddr(obj, msgBufId);

    /* set message ID */
    FLEXCANDRV_SetMsgId(msgBufPtr, msgCfg->msgId, msgCfg->isExtMsgId);

    /* set message DLC */
    FLEXCANDRV_SetMsgDLC(msgBufPtr, msgCfg->dlc);

    /* set FD configures */
    FLEXCANDRV_SetFDEnable(msgBufPtr, msgCfg->isFd);

    /* set message type */
    FLEXCANDRV_SetMsgType(msgBufPtr, msgCfg->msgType);

    if (msgCfg->intEnable)
    {
        /* set message buffer interrupt enable */
        FLEXCANDRV_EnableMsgObjInterrupt(obj, msgBufId);
    }
    else
    {
        /* message buffer interrupt disable, do nothing */
    }

    if (msgCfg->msgType == FLEXCANDRV_MSGTYPE_RX)
    {
        /* set message buffer individual mask */ 
        FLEXCANREG_SetRxIndividualMask(obj->flexCanReg, msgBufId, msgCfg->individualMask);
    }
}

/** 
  * @brief  Set enhanced rx fifo filter for mask filter type
  * @param  obj              pointer to a FLEXCANDRV_Type structure
  * @param  controllerCfg    pointer to a FLEXCANDRV_ControllerCfgType structure
  * @param  extIdNum         the number of extended ID
  *                           - This parameter is calculated based on the user-defined
  *                             FLEXCANDRV_MsgCfgType structure.
  * @param  stdIdNum         the number of standard ID
  *                           - This parameter is calculated based on the user-defined
  *                             FLEXCANDRV_MsgCfgType structure.
  * @return Returns the status of these operations
  *                           - 0: these operations are failed
  *                           - 1: these operations are suecceed
  */
bool FLEXCANDRV_SetEnhanceRxFifoFilterInMask (FLEXCANDRV_Type *obj, \
                                              const FLEXCANDRV_ControllerCfgType *controllerCfg, \
                                              uint8_t extIdNum, uint8_t stdIdNum)
{
    bool     rtn = false;
    uint8_t  alignedExtIdElementNum = 0, alignedStdIdElementNum = 0, nfe = 0, nexif = 0;
    uint32_t filter = 0, mask = 0, currentSdtIdNum = 0, currentExtIdNum = 0;
    uint16_t filterElementIdx = 0, i = 0;

    if ((((((uint32_t)extIdNum) << 1) + (((uint32_t)((stdIdNum + 1) >> 1)) << 1)) <= \
        FLEXCANDRV_MSG_FILTER_ELEMENTS_NUM) && ((extIdNum + stdIdNum) > 0))
    {
        /* set the number of extended id filter elements */
        if (extIdNum > 0)
        {
            if ((extIdNum & 0x01) != 0x00)
            {
                nexif = (extIdNum + 1);
            }
            else
            {
                nexif = extIdNum;
            }
            if ((extIdNum & 0x01) != 0x00)
            {
                alignedExtIdElementNum = 1;
            }
        }
        else
        {
            nexif = 0;
        }

        if (stdIdNum > 0)
        {
            nfe = nexif + ((stdIdNum + 1) >> 1) - 1;
            if (nfe > ((FLEXCANDRV_MSG_FILTER_ELEMENTS_NUM >> 1) - 1))
            {
                nfe = ((FLEXCANDRV_MSG_FILTER_ELEMENTS_NUM >> 1) - 1);
            }
            /* In this selection mode, one element space are stored with 4 standard id */
            if ((stdIdNum & 0x01) != 0x00)
            {
                alignedStdIdElementNum = 0x01;
            }
        }
        else
        {
            if (extIdNum > 0)
            {
                nfe = nexif - 1;
            }
        }

        FLEXCANREG_SetEnhanceRxFifoFilterElementNum(obj->flexCanReg, nfe);
        FLEXCANREG_SetExtIdFilterElementNum(obj->flexCanReg, nexif);
        
        /* Configure the filter elements */
        /* Notice: the filter ram is used by extend id firstly, then the rest space are used by standard id!!!! */
        for (i = 0; i < controllerCfg->msgNum; i++)
        {
            if (controllerCfg->msgCfg[i].msgType == FLEXCANDRV_MSGTYPE_RX)
            {
                if (controllerCfg->msgCfg[i].isExtMsgId == true)
                {
                    currentExtIdNum++;
                    filter = 0;
                    mask   = 0;

                    /* FSCH = 00 */
                    filter |= (0x00UL << 30);
                    /* RTR Filter */
                    filter |= (((uint32_t)(controllerCfg->msgCfg[i].rtrfilter)) << 29);
                    /* EXT ID Filter */
                    filter |= controllerCfg->msgCfg[i].msgId;

                    /* RTR Mask */
                    mask |= (((uint32_t)(controllerCfg->msgCfg[i].rtrmask)) << 29);
                    /* EXT ID Mask */
                    mask |= (controllerCfg->msgCfg[i].individualMask & 0x1FFFFFFF);

                    FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filter);
                    filterElementIdx++;

                    FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, mask);
                    filterElementIdx++;

                    if (currentExtIdNum == extIdNum)
                    {
                        if (alignedExtIdElementNum > 0)
                        {
                            /* Used the last filter value to fill */
                            FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filter);
                            filterElementIdx++;

                            FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, mask);
                            filterElementIdx++;
                        }
                        break;
                    }
                }
            }
        }

        for (i = 0; i < controllerCfg->msgNum; i++)
        {
            if (controllerCfg->msgCfg[i].msgType == FLEXCANDRV_MSGTYPE_RX)
            {
                if (controllerCfg->msgCfg[i].isExtMsgId == false)
                {
                    currentSdtIdNum++;
                    filter = 0;
                    /* FSCH = 00 */
                    filter |= (0x00UL << 30);
                    /* RTR Filter */
                    filter |= (((uint32_t)(controllerCfg->msgCfg[i].rtrfilter)) << 27);
                    /* RTR Mask */
                    filter |= (((uint32_t)(controllerCfg->msgCfg[i].rtrmask)) << 11);
                    /* STD ID Filter */
                    filter |= (controllerCfg->msgCfg[i].msgId << 16);
                    /* STD ID Mask */
                    filter |= ((controllerCfg->msgCfg[i].individualMask & 0x7FF) << 0);

                    FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filter);
                    filterElementIdx++;

                    if (currentSdtIdNum == stdIdNum)
                    {
                        if (alignedStdIdElementNum > 0)
                        {
                            /* use the last filter value to fill the space for aligning with two element as a group */
                            FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filter);
                        }
                        break;
                    }
                }
            }
        }
        rtn = true;
    }

    return rtn;
}

/** 
  * @brief  Set enhanced rx fifo filter for range filter type
  * @param  obj              pointer to a FLEXCANDRV_Type structure
  * @param  controllerCfg    pointer to a FLEXCANDRV_ControllerCfgType structure
  * @param  extIdNum         the number of extended ID
  *                           - This parameter is calculated based on the user-defined
  *                             FLEXCANDRV_MsgCfgType structure.
  * @param  stdIdNum         the number of standard ID
  *                           - This parameter is calculated based on the user-defined
  *                             FLEXCANDRV_MsgCfgType structure.
  * @return Returns the status of these operations
  *                           - 0: these operations have failed
  *                           - 1: these operations have succeeded
  */
bool FLEXCANDRV_SetEnhanceRxFifoFilterInRange (FLEXCANDRV_Type *obj, \
                                               const FLEXCANDRV_ControllerCfgType *controllerCfg, \
                                               uint8_t extIdNum, uint8_t stdIdNum)
{
    bool     rtn = false, updateFilterReg = false;
    uint8_t  alignedStdIdElementNum = 0, lastValidRxIdIndex = 0, nfe = 0, nexif = 0;
    uint32_t filterMin = 0, filterMax = 0, currentSdtIdNum = 0, currentExtIdNum = 0;
    uint16_t filterElementIdx = 0, i = 0;

    if ((((((uint32_t)((extIdNum + 1) >> 1)) << 1) + ((uint32_t)((stdIdNum + 1) >> 1))) <= \
        FLEXCANDRV_MSG_FILTER_ELEMENTS_NUM) && ((extIdNum + stdIdNum) > 0))
    {
        /* set the number of extended id filter elements */
        if (extIdNum > 0)
        {
            if ((extIdNum & 0x01) != 0x00)
            {
                nexif = (extIdNum + 1) >> 1;
            }
            else
            {
                nexif = extIdNum >> 1;
            }
        }
        else
        {
            nexif = 0;
        }

        if (stdIdNum > 0)
        {
            nfe = nexif + ((((stdIdNum + 1) >> 1) + 1) >> 1) - 1;
            if (nfe > ((FLEXCANDRV_MSG_FILTER_ELEMENTS_NUM >> 1) - 1))
            {
                nfe = ((FLEXCANDRV_MSG_FILTER_ELEMENTS_NUM >> 1) - 1);
            }

            /* In this selection mode, one element space are stored with 4 standard id */
            if ((stdIdNum & 0x03) != 0x00)
            {
                alignedStdIdElementNum = 0x04 - (stdIdNum & 0x03);
            }
        }
        else
        {
            if (extIdNum > 0)
            {
                nfe = nexif - 1;
            }
        }

        FLEXCANREG_SetEnhanceRxFifoFilterElementNum(obj->flexCanReg, nfe);
        FLEXCANREG_SetExtIdFilterElementNum(obj->flexCanReg, nexif);
        
        /* Configure the filter elements */
        /* Notice: the filter ram is used by extend id firstly, then the rest space are used by standard id!!!! */
        for (i = 0; i < controllerCfg->msgNum; i++)
        {
            if (controllerCfg->msgCfg[i].msgType == FLEXCANDRV_MSGTYPE_RX)
            {
                if (controllerCfg->msgCfg[i].isExtMsgId == true)
                {
                    currentExtIdNum++;
                    if (updateFilterReg == false)
                    {
                        updateFilterReg = true;
                        filterMin       = 0;
                        filterMax       = 0;

                        /* RTR Filter */
                        filterMin |= (((uint32_t)(controllerCfg->msgCfg[i].rtrfilter)) << 29);
                        /* EXT ID Filter */
                        filterMin |= controllerCfg->msgCfg[i].msgId;

                        if (currentExtIdNum == extIdNum)
                        {
                            /* FSCH = 01 */
                            filterMax |= (0x01UL << 30);
                            /* RTR Filter */
                            filterMax |= (((uint32_t)(controllerCfg->msgCfg[i].rtrfilter)) << 29);
                            /* EXT ID Filter */
                            filterMax |= controllerCfg->msgCfg[i].msgId;

                            FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filterMax);
                            filterElementIdx++;

                            FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filterMin);
                            filterElementIdx++;

                            updateFilterReg = false;
                            break;
                        }
                    }
                    else
                    {
                        if (controllerCfg->msgCfg[i].msgId > (filterMin & 0x1FFFFFFF))
                        {
                            /* FSCH = 01 */
                            filterMax |= (0x01UL << 30);
                            /* RTR Filter */
                            filterMax |= (((uint32_t)(controllerCfg->msgCfg[i].rtrfilter)) << 29);
                            /* EXT ID Filter */
                            filterMax |= controllerCfg->msgCfg[i].msgId;
                        }
                        else
                        {
                            filterMax = (filterMin & 0x1FFFFFFF);
                            /* RTR Filter */
                            filterMax |= (((uint32_t)(controllerCfg->msgCfg[i].rtrfilter)) << 29);
                            /* FSCH = 01 */
                            filterMax |= (0x01UL << 30);

                            /* EXT ID Filter */
                            filterMin = controllerCfg->msgCfg[i].msgId; 
                            /* RTR Filter */
                            filterMin |= (((uint32_t)(controllerCfg->msgCfg[i].rtrfilter)) << 29);
                        }

                        FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filterMax);
                        filterElementIdx++;

                        FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filterMin);
                        filterElementIdx++;

                        updateFilterReg = false;

                        if (currentExtIdNum == extIdNum)
                        {
                            break;
                        }
                    }
                }
            }
        }

        for (i = 0; i < controllerCfg->msgNum; i++)
        {
            if (controllerCfg->msgCfg[i].msgType == FLEXCANDRV_MSGTYPE_RX)
            {
                if (controllerCfg->msgCfg[i].isExtMsgId == false)
                {
                    /* ID >= Fitler1, ID <= Fitler2 */
                    currentSdtIdNum++;
                    if (updateFilterReg == false)
                    {
                        updateFilterReg = true;
                        filterMin = 0;
                        /* FSCH = 01 */
                        filterMin |= (0x01UL << 30);

                        /* STD ID Filter1 */
                        filterMin |= (controllerCfg->msgCfg[i].msgId << 0);
                        /* RTR Mask */
                        filterMin |= (((uint32_t)(controllerCfg->msgCfg[i].rtrmask)) << 11);

                        if (currentSdtIdNum == stdIdNum)
                        {
                            lastValidRxIdIndex = i;
                            break;
                        }
                    }
                    else
                    {
                        if (controllerCfg->msgCfg[i].msgId > (filterMin & 0x7FF))
                        {
                            /* set the max filter id as fitler id2 */
                            filterMin |= controllerCfg->msgCfg[i].msgId << 16;
                            /* RTR Filter */
                            filterMin |= (((uint32_t)(controllerCfg->msgCfg[i].rtrfilter)) << 27);
                        }
                        else
                        {
                            filterMax = (filterMin & 0x7FF);
                            /* FSCH = 01 */
                            filterMin = (0x01UL << 30);
                            /* STD ID Filter1 */
                            filterMin |= (controllerCfg->msgCfg[i].msgId << 0);
                            /* RTR Mask */
                            filterMin |= (((uint32_t)(controllerCfg->msgCfg[i].rtrmask)) << 11);
                            filterMin |= filterMax << 16;
                            /* RTR Filter */
                            filterMin |= (((uint32_t)(controllerCfg->msgCfg[i].rtrfilter)) << 27);
                        }
                        
                        FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filterMin);
                        filterElementIdx++;
                        updateFilterReg = false;

                        if (currentSdtIdNum == stdIdNum)
                        {
                            break;
                        }
                    }
                }
            }
        }

        switch (alignedStdIdElementNum)
        {
            case 0x00:
                break;
    
            case 0x01:
                /* RTR Filter */
                filterMin |= (((uint32_t)(controllerCfg->msgCfg[lastValidRxIdIndex].rtrfilter)) << 27);
                filterMin |= (controllerCfg->msgCfg[lastValidRxIdIndex].msgId << 16);
                FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filterMin);
                break;
    
            case 0x02:
                /* Use the last element filter value to fill */
                FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filterMin);
                break;
    
            case 0x03:
                /* Use the last element filter value to fill */
                FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filterMin);
                filterElementIdx++;
                /* Use the last element filter value to fill */
                FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filterMin);
                break;
    
            default:
                break;
        }

        rtn = true;
    }

    return rtn;
}

/** 
  * @brief  Set enhanced rx fifo filter for without mask filter type
  * @param  obj              pointer to a FLEXCANDRV_Type structure
  * @param  controllerCfg    pointer to a FLEXCANDRV_ControllerCfgType structure
  * @param  extIdNum         the number of extended ID
  *                           - This parameter is calculated based on the user-defined
  *                             FLEXCANDRV_MsgCfgType structure.
  * @param  stdIdNum         the number of standard ID
  *                           - This parameter is calculated based on the user-defined
  *                             FLEXCANDRV_MsgCfgType structure.
  * @return Returns the status of these operations
  *                           - 0: these operations have failed
  *                           - 1: these operations have succeeded
  */
bool FLEXCANDRV_SetEnhanceRxFifoFilterInWithoutMask (FLEXCANDRV_Type *obj, \
                                                     const FLEXCANDRV_ControllerCfgType *controllerCfg, \
                                                     uint8_t extIdNum, uint8_t stdIdNum)
{
    bool     rtn = false, updateFilterReg = false;
    uint8_t  alignedStdIdElementNum = 0, lastValidRxIdIndex = 0, nfe = 0, nexif = 0;
    uint32_t filter = 0, mask = 0, currentSdtIdNum = 0, currentExtIdNum = 0;
    uint16_t filterElementIdx = 0, i = 0;

    if ((((((uint32_t)((extIdNum + 1) >> 1)) << 1) + ((((uint32_t)((stdIdNum + 1) >> 1)) << 1) >> 1)) \
         <= FLEXCANDRV_MSG_FILTER_ELEMENTS_NUM) && ((extIdNum + stdIdNum) > 0))
    {
        if (extIdNum > 0)
        {
            if ((extIdNum & 0x01) != 0x00)
            {
                nexif = ((extIdNum + 1) >> 1);
            }
            else
            {
                nexif = (extIdNum >> 1);
            }
        }
        else
        {
            nexif = 0;
        }

        if (stdIdNum > 0)
        {
            nfe = nexif + (((((stdIdNum + 1) >> 1) + 1) >> 1) - 1);
            if (nfe > ((FLEXCANDRV_MSG_FILTER_ELEMENTS_NUM >> 1) - 1))
            {
                nfe = ((FLEXCANDRV_MSG_FILTER_ELEMENTS_NUM >> 1) - 1);
            }

            /* In this selection mode, one element space are stored with 4 standard id */
            if ((stdIdNum & 0x03) != 0x00)
            {
                alignedStdIdElementNum = 0x04 - (stdIdNum & 0x03);
            }
        }
        else
        {
            if (extIdNum > 0)
            {
                nfe = nexif - 1;
            }
        }

        FLEXCANREG_SetEnhanceRxFifoFilterElementNum(obj->flexCanReg, nfe);
        FLEXCANREG_SetExtIdFilterElementNum(obj->flexCanReg, nexif);

        /* Configure the filter elements */
        /* Notice: the filter ram is used by extend id firstly, then the rest space are used by standard id!!!! */
        for (i = 0; i < controllerCfg->msgNum; i++)
        {
            if (controllerCfg->msgCfg[i].msgType == FLEXCANDRV_MSGTYPE_RX)
            {
                if (controllerCfg->msgCfg[i].isExtMsgId == true)
                {
                    currentExtIdNum++;
                    if (updateFilterReg == false)
                    {
                        updateFilterReg = true;
                        filter          = 0;
                        mask            = 0;

                        /* FSCH = 10 */
                        filter |= (0x02UL << 30);
                        /* RTR Filter */
                        filter |= (((uint32_t)(controllerCfg->msgCfg[i].rtrfilter)) << 29);
                        /* EXT ID Filter */
                        filter |= controllerCfg->msgCfg[i].msgId;

                        if (currentExtIdNum == extIdNum)
                        {
                            /* RTR Mask */
                            mask |= (((uint32_t)(controllerCfg->msgCfg[i].rtrfilter)) << 29);
                            /* EXT ID Mask */
                            mask |= controllerCfg->msgCfg[i].msgId;

                            FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filter);
                            filterElementIdx++;

                            FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, mask);
                            filterElementIdx++;

                            updateFilterReg = false;
                            break;
                        }
                    }
                    else
                    {
                        /* RTR Mask */
                        mask |= (((uint32_t)(controllerCfg->msgCfg[i].rtrfilter)) << 29);
                        /* EXT ID Mask */
                        mask |= controllerCfg->msgCfg[i].msgId;

                        FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filter);
                        filterElementIdx++;

                        FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, mask);
                        filterElementIdx++;

                        updateFilterReg = false;

                        if (currentExtIdNum == extIdNum)
                        {
                            break;
                        }
                    }
                }
            }
        }

        for (i = 0; i < controllerCfg->msgNum; i++)
        {
            if (controllerCfg->msgCfg[i].msgType == FLEXCANDRV_MSGTYPE_RX)
            {
                if (controllerCfg->msgCfg[i].isExtMsgId == false)
                {
                    currentSdtIdNum++;
                    if (updateFilterReg == false)
                    {
                        updateFilterReg = true;
                        filter = 0;
                        /* FSCH = 10 */
                        filter |= (0x02UL << 30);

                        /* STD ID Filter1 */
                        filter |= (controllerCfg->msgCfg[i].msgId << 0);
                        /* RTR Mask */
                        filter |= (((uint32_t)(controllerCfg->msgCfg[i].rtrfilter)) << 11);

                        if (currentSdtIdNum == stdIdNum)
                        {
                            lastValidRxIdIndex = i;
                            break;
                        }
                    }
                    else
                    {
                        /* then use the msgid as the second filters */
                        filter |= (controllerCfg->msgCfg[i].msgId << 16);
                        /* RTR Filter */
                        filter |= (((uint32_t)(controllerCfg->msgCfg[i].rtrfilter)) << 27);

                        FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filter);
                        filterElementIdx++;
                        updateFilterReg = false;
                    }
                }
            }
        }

        switch (alignedStdIdElementNum)
        {
            case 0x01:
                filter |= (controllerCfg->msgCfg[lastValidRxIdIndex].msgId << 16);
                /* RTR Filter */
                filter |= (((uint32_t)(controllerCfg->msgCfg[i].rtrfilter)) << 27); 
    
                FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filter);
                break;
    
            case 0x02:
                /* Use the last element filter value to fill */
                FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filter);
                break;
    
            case 0x03:
                filter |= (controllerCfg->msgCfg[lastValidRxIdIndex].msgId << 16);
                /* RTR Filter */
                filter |= (((uint32_t)(controllerCfg->msgCfg[i].rtrfilter)) << 27); 
    
                FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filter);
                filterElementIdx++;
                /* Use the last element filter value to fill */
                FLEXCANREG_SetEnhanceRxFifoElement(obj->flexCanReg, filterElementIdx, filter);
                break;
    
            default:
                break;
        }
    
        rtn = true;
    }

    return rtn;
}

/** 
  * @brief  Initialize the enhanced rx fifo filter element
  * @param  obj              pointer to a FLEXCANDRV_Type structure
  * @param  controllerCfg    pointer to a FLEXCANDRV_ControllerCfgType structure
  */
void FLEXCANDRV_InitEnhanceRxFFFilterElement (FLEXCANDRV_Type *obj, const FLEXCANDRV_ControllerCfgType *controllerCfg)
{
    uint8_t extIdNum = 0, stdIdNum = 0, i = 0;
    uint8_t maxRxByteNum = 0, dataByteLen = 0;

    /* Get the total number of std id and ext id */
    for (i = 0; i < controllerCfg->msgNum; i++)
    {
        if (controllerCfg->msgCfg[i].msgType == FLEXCANDRV_MSGTYPE_RX)
        {
            if (controllerCfg->msgCfg[i].isExtMsgId == false)
            {
                stdIdNum++;
            }
            else
            {
                extIdNum++;
            }

            dataByteLen = FLEXCANDRV_DLC2DataLen(controllerCfg->msgCfg[i].dlc);

            if (maxRxByteNum < dataByteLen)
            {
                maxRxByteNum = dataByteLen;
            }
        }
    }

    if (controllerCfg->dmaEnable == true)
    {
        uint8_t dmaLA = 0;

        /* Define the last DMA address for each enhanced rx fifo element */
        dmaLA = ((maxRxByteNum + 16) / 4) - 1;
        FLEXCANREG_SetEnhanceRxFifoDmaLastWord(obj->flexCanReg, dmaLA);
    }

    switch (controllerCfg->enhRxFFFilterSelection)
    {
        case FLEXCANDRV_ENHRXFF_FILTER_SELECT_MASK_FITLER:
            FLEXCANDRV_SetEnhanceRxFifoFilterInMask(obj, controllerCfg, extIdNum, stdIdNum);
            break;
    
        case FLEXCANDRV_ENHRXFF_FILTER_SELECT_RANGE:
            FLEXCANDRV_SetEnhanceRxFifoFilterInRange(obj, controllerCfg, extIdNum, stdIdNum);
            break;
    
        case FLEXCANDRV_ENHRXFF_FILTER_SELECT_TWO_FILTER_WITHOUT_MASK:
            FLEXCANDRV_SetEnhanceRxFifoFilterInWithoutMask(obj, controllerCfg, extIdNum, stdIdNum);
            break;
    
        default:
            break;
    }
}

/** 
  * @brief  Set the enhanced rx fifo filter configuration
  * @param  obj              pointer to a FLEXCANDRV_Type structure
  * @param  controllerCfg    pointer to a FLEXCANDRV_ControllerCfgType structure
  */
void FLEXCANDRV_SetEnhanceRxFifoConfig (FLEXCANDRV_Type *obj, const FLEXCANDRV_ControllerCfgType *controllerCfg)
{
    /* set rx fifo disable */
    FLEXCANREG_SetRxFifoEnable(obj->flexCanReg, false);
    /* set enhanced rx fifo enable */
    FLEXCANREG_SetEnhanceRxFifoEnable(obj->flexCanReg, true);

    /* Reset enhanced rx fifo engine */
    FLEXCANREG_ClearEnhanceRxFifoContent(obj->flexCanReg);

    /* Set ERFUFW ERFOVF ERFWMI ERFDA */
    FLEXCANREG_SetEnhanceRxFifoUnderflowIntEnable(obj->flexCanReg, controllerCfg->enhRxFifoufwIntEnable);
    FLEXCANREG_SetEnhanceRxFifoOverflowIntEnable(obj->flexCanReg, controllerCfg->enhRxFifoovfIntEnable);
    FLEXCANREG_SetEnhanceRxFifoWatrmarkIntEnable(obj->flexCanReg, controllerCfg->enhRxFifowmIntEnable);
    FLEXCANREG_SetEnhanceRxFifoDataAvailableIntEnable(obj->flexCanReg, controllerCfg->enhRxFifodataIntEnable);

    /* Configure the rx ff filter elements */
    FLEXCANDRV_InitEnhanceRxFFFilterElement(obj, controllerCfg);

    /* Set default water mark */
    FLEXCANREG_SetEnhanceRxFifoWatermark(obj->flexCanReg, controllerCfg->enhRxFifoWatermark - 1);
}

/** 
  * @brief  Configure and initialize FLEXCAN controller from user configuration
  * @param  obj              pointer to a FLEXCANDRV_Type structure
  * @param  controllerCfg    pointer to a FLEXCANDRV_ControllerCfgType structure
  */
void FLEXCANDRV_Configure (FLEXCANDRV_Type *obj, const FLEXCANDRV_ControllerCfgType *controllerCfg)
{
    uint8_t msgBufSize = 0;
    uint8_t msgBufNum = 0;

    /* disable FlexCan module */
    FLEXCANREG_SetModuleDisable(obj->flexCanReg, true);
  
    /* make sure that the module has enter into low power mode successfully */
    while (FLEXCANREG_GetLowPowerAck(obj->flexCanReg) == 0)
    {
    }

    /* configure FlexCan clock source */
    FLEXCANREG_SetClockSource(obj->flexCanReg, controllerCfg->clkSrc);

    /* delay for clock to stablize */
    for (uint16_t delay = 0; delay < 100; delay++)
    {
    }

    /* reset CAN internal status */
    FLEXCANDRV_SoftReset(obj);
    /* switch to supervisor mode */
    FLEXCANREG_SetAccessMode(obj->flexCanReg, FLEXCANDRV_CAN_ACCESS_MODE_SUP);
    /* enable write access in freeze mode */
    FLEXCANREG_SetFreezeModeWriteAcc(obj->flexCanReg, true);

    /* initial can ram */
    FLEXCANDRV_InitCanRAM(obj);

    /* calculate the total message number according to the message buffer size per region */
    msgBufSize = FLEXCANDRV_ConvertMsgBufSizeSel(controllerCfg->msgBufDataLenSel);
    if (msgBufSize != 0)
    {
        msgBufNum = ((FLEXCAN_DRV_CAN_RAM_SIZE / msgBufSize) * obj->initHwPar.canRamNum) - 1;
        msgBufNum = msgBufNum > 127 ? 127 : msgBufNum;
    }
    /* set message buffer maximum number */
    FLEXCANREG_SetMaxMsgBufferNum(obj->flexCanReg, msgBufNum);

    /* Set can bit sampling type, make sure the can fd is in disabled! */
    FLEXCANREG_SetBitSamplingType(obj->flexCanReg, controllerCfg->selected3bitSampling);

    /* set standard CAN bit timing */
    /* enable CAN extended bit timing */
    FLEXCANREG_SetExtendedBitTimingEnable(obj->flexCanReg, true);
    /* set prescaler division */
    FLEXCANREG_SetExtPresalerDivision(obj->flexCanReg, controllerCfg->bitTiming.prescalerDiv - 1);
    /* set resync jump width */
    FLEXCANREG_SetExtResyncJumpWidth(obj->flexCanReg, controllerCfg->bitTiming.resyncJumpWidth - 1);
    /* set propagation segment */
    FLEXCANREG_SetExtPorpSeg(obj->flexCanReg, controllerCfg->bitTiming.propSeg - 1);
    /* set phase segment 1 */
    FLEXCANREG_SetExtPhaseSeg1(obj->flexCanReg, controllerCfg->bitTiming.phaseSeg1 - 1);
    /* set phase segment 2 */
    FLEXCANREG_SetExtPhaseSeg2(obj->flexCanReg, controllerCfg->bitTiming.phaseSeg2 - 1);

    if (controllerCfg->fdEnable)
    {
        /* set CAN FD operation enable */
        FLEXCANREG_SetFdEnable(obj->flexCanReg, controllerCfg->fdEnable);
        /* enable FD rate switch */
        FLEXCANREG_SetFdRateSwitch(obj->flexCanReg, true);
        /* set FD prescaler division */
        FLEXCANREG_SetFdPrescalerDivision(obj->flexCanReg, controllerCfg->fdBitTiming.prescalerDiv - 1);
        /* set FD resync jump width */
        FLEXCANREG_SetFdResyncJumpWidth(obj->flexCanReg, controllerCfg->fdBitTiming.resyncJumpWidth - 1);
        /* set FD propagation segment */
        FLEXCANREG_SetFdPorpSeg(obj->flexCanReg, controllerCfg->fdBitTiming.propSeg);
        /* set FD phase segment 1 */
        FLEXCANREG_SetFdPhaseSeg1(obj->flexCanReg, controllerCfg->fdBitTiming.phaseSeg1 - 1);
        /* set FD phase segment 2 */
        FLEXCANREG_SetFdPhaseSeg2(obj->flexCanReg, controllerCfg->fdBitTiming.phaseSeg2 - 1);

        /* set region 0 data size selection */
        FLEXCANREG_SetRegionDataSizeSel(obj->flexCanReg, 0, controllerCfg->msgBufDataLenSel);
        /* set region 1 data size selection */
        FLEXCANREG_SetRegionDataSizeSel(obj->flexCanReg, 1, controllerCfg->msgBufDataLenSel);
        /* set region 2 data size selection */
        FLEXCANREG_SetRegionDataSizeSel(obj->flexCanReg, 2, controllerCfg->msgBufDataLenSel);
        /* set region 3 data size selection */
        FLEXCANREG_SetRegionDataSizeSel(obj->flexCanReg, 3, controllerCfg->msgBufDataLenSel);

        if (controllerCfg->loopbackEnable == false)
        {
            /* set TDC enable */
            FLEXCANREG_SetTdcEnable(obj->flexCanReg, controllerCfg->tdcEnable);
            /* set TDC offset */
            FLEXCANREG_SetTdcOffset(obj->flexCanReg, controllerCfg->tdcOffset);
        }

        /* set CAN-FD ISO enable */
        FLEXCANREG_SetIsoFdEnable(obj->flexCanReg, controllerCfg->fdISOEnable);
    }

    /* lagecy rx fifo */
    if (controllerCfg->fifoEnable)
    {
        /* node 0 not support the feature of enhance rx fifo */
        if (obj->initHwPar.canInstanceIdx == 0)
        {
            /* Make sure the ehnhance is in disable mode */
            FLEXCANREG_SetEnhanceRxFifoEnable(obj->flexCanReg, false);
        }

        /* set rx fifo enable */
        FLEXCANREG_SetRxFifoEnable(obj->flexCanReg, true);

        /* set rx fifo global mask */
        FLEXCANREG_SetRxFifoGlobalMask(obj->flexCanReg, controllerCfg->rxFifoGlobalMask);

        /* set rx mailbox global mask */
        FLEXCANREG_SetRxMailboxGlobalMask(obj->flexCanReg, controllerCfg->rxMBGlobalMask);
        /* set rx mailbox 14 mask */
        FLEXCANREG_SetRxMailbox14Mask(obj->flexCanReg, controllerCfg->rxMB14Mask);
        /* set rx mailbox 15 mask */
        FLEXCANREG_SetRxMailbox15Mask(obj->flexCanReg, controllerCfg->rxMB15Mask);

        /* set individual Rx masking and queue enable */
        FLEXCANREG_SetIndividualMaskEnable(obj->flexCanReg, controllerCfg->individualMaskEnable); 
        /* Set number of legacy rx fifo filter */
        FLEXCANREG_SetLegacyRxFifoFilterNums(obj->flexCanReg, ((controllerCfg->rxFifoFilternum - 8) / 8));
        /* set Rx Fifo Filter ID */
        FLEXCANDRV_SetRxFifoFilter(obj->flexCanReg, controllerCfg->filterIdtable); 

        for (uint8_t i = 0; i < 128; i ++) 
        {
            /* set individual mask for legacy fifo ID */
            FLEXCANREG_SetRxIndividualMask(obj->flexCanReg, i, controllerCfg->Legacyfifomask[i]);
        }
    }
    else if (controllerCfg->enhancefifoEnable)
    {
        /* Only node 0 do not support the feature of enhance rx fifo */
        if (obj->initHwPar.canInstanceIdx != 0)
        {
            FLEXCANDRV_SetEnhanceRxFifoConfig(obj, controllerCfg);
        }
    }
    else
    {
        /* set rx fifo disable */
        FLEXCANREG_SetRxFifoEnable(obj->flexCanReg, false);
        FLEXCANREG_SetEnhanceRxFifoEnable(obj->flexCanReg, false);
        /* reset enhanced rx fifo engine */
        FLEXCANREG_ClearEnhanceRxFifoContent(obj->flexCanReg);
        /* clear ERFUFW ERFOVF ERFWMI ERFDA */
        FLEXCANREG_SetEnhanceRxFifoUnderflowIntEnable(obj->flexCanReg, false);
        FLEXCANREG_SetEnhanceRxFifoOverflowIntEnable(obj->flexCanReg, false);
        FLEXCANREG_SetEnhanceRxFifoWatrmarkIntEnable(obj->flexCanReg, false);
        FLEXCANREG_SetEnhanceRxFifoDataAvailableIntEnable(obj->flexCanReg, false);

        /* set rx mailbox global mask */
        FLEXCANREG_SetRxMailboxGlobalMask(obj->flexCanReg, controllerCfg->rxMBGlobalMask);
        /* set rx mailbox 14 mask */
        FLEXCANREG_SetRxMailbox14Mask(obj->flexCanReg, controllerCfg->rxMB14Mask);
        /* set rx mailbox 15 mask */
        FLEXCANREG_SetRxMailbox15Mask(obj->flexCanReg, controllerCfg->rxMB15Mask);

        /* set individual Rx masking and queue enable */
        FLEXCANREG_SetIndividualMaskEnable(obj->flexCanReg, controllerCfg->individualMaskEnable);
    }

    /* set rx fifo DMA enable */
    FLEXCANREG_SetRxFifoDmaEnable(obj->flexCanReg, controllerCfg->dmaEnable);

    /* loopback mode configuration */
    if (controllerCfg->loopbackEnable)
    {
        /* enable self reception */
        FLEXCANREG_SetSelfReceptionDisable(obj->flexCanReg, false);
        /* enable loop-back */
        FLEXCANREG_SetLoopbackMode(obj->flexCanReg, true);
    }
    else
    {
        /* disable self reception */
        FLEXCANREG_SetSelfReceptionDisable(obj->flexCanReg, true);
        /* disable loop-back */
        FLEXCANREG_SetLoopbackMode(obj->flexCanReg, false);
    }

    FLEXCANREG_SetListenOnlyModeEna(obj->flexCanReg, controllerCfg->listenMode);

    /* edge wakeup configuration */
    if (controllerCfg->edgeWkupEnable)
    {
        /* enable edge(self) wakeup */
        FLEXCANREG_SetSelfWakeupEnable(obj->flexCanReg, 1); 
        /* enable edge(self) wakeup interrupt */
        FLEXCANREG_SetWakeupIntMask(obj->flexCanReg, controllerCfg->WkupIntEnable);
        /* enable doze mode request */
        FLEXCANREG_SetDozeMode(obj->flexCanReg, 1);
    }
    else
    {
        /* disable edge(self) wakeup */
        FLEXCANREG_SetSelfWakeupEnable(obj->flexCanReg, 0);
        /* disable edge(self) wakeup interrupt */
        FLEXCANREG_SetWakeupIntMask(obj->flexCanReg, 0);
        /* disable doze mode request */
        FLEXCANREG_SetDozeMode(obj->flexCanReg, 0);
    }

    /* BusOff recovery */
    FLEXCANREG_SetBusOffRecEnable(obj->flexCanReg, true);

    /* set Tx message abort enable */
    FLEXCANREG_SetTxAbortEnable(obj->flexCanReg, controllerCfg->txAbortEnable);

    /* set busoff interrupt enable mask */
    FLEXCANREG_SetBusOffIntEnable(obj->flexCanReg, controllerCfg->busoffIntEnable);
    /* set error interrupt enable mask */
    FLEXCANREG_SetErrorIntEnable(obj->flexCanReg, controllerCfg->errorIntEnable);
    /* set warning interrupt enable */
    FLEXCANREG_SetWarningIntEnable(obj->flexCanReg, controllerCfg->warningIntEnable);
    FLEXCANREG_SetTxWarnIntEnable(obj->flexCanReg, controllerCfg->warningIntEnable);
    FLEXCANREG_SetRxWarnIntEnable(obj->flexCanReg, controllerCfg->warningIntEnable);
    
    if ((controllerCfg->enhancefifoEnable == false) && (controllerCfg->fifoEnable == false))
    {
        /* configure messages */
        uint8_t i = 0;

        for (i = 0; i < controllerCfg->msgNum; i++)
        {
            uint16_t j = 0;
            /* configure messages according to the message buffer Id and message buffer length parameters */
            for (j = controllerCfg->msgCfg[i].msgBufId; j < controllerCfg->msgCfg[i].msgBufId + \
                                                            controllerCfg->msgCfg[i].msgBufLen; j++)
            {
                FLEXCANDRV_CfgMsgObj(obj, &controllerCfg->msgCfg[i], j);
            }
        }
    }
    else
    {
        /* configure messages */
        uint8_t i = 0;

        for (i = 0; i < controllerCfg->msgNum; i++)
        {
            uint16_t j = 0;
            /* configure messages according to the message buffer Id and message buffer length parameters */
            for (j = controllerCfg->msgCfg[i].msgBufId; j < controllerCfg->msgCfg[i].msgBufId + \
                                                            controllerCfg->msgCfg[i].msgBufLen; j++)
            {
                /* MB used for Tx if enhance rx fifo enabled */
                if (controllerCfg->msgCfg[i].msgType == FLEXCANDRV_MSGTYPE_TX)
                {
                    FLEXCANDRV_CfgMsgObj(obj, &controllerCfg->msgCfg[i], j);
                }
            }
        }
    }

    /* set the free running timer is by external timer tick or not */
    FLEXCANREG_SetFreeRunTimerSrc(obj->flexCanReg, controllerCfg->freeRunningByExtTmrEn);

    /* select which time base is used for capture in Message buffer time stamp */
    FLEXCANREG_SetFreeRunTimerBase(obj->flexCanReg, controllerCfg->mbTmrBaseSelect);

    /* select the point in time at which a 32-bit time base is captured and stored in the HR-TimeStamp */
    FLEXCANREG_SetHighResTimeStampMode(obj->flexCanReg, controllerCfg->hrTmrCapturePointSelect);

    /* clear all message buffer flags */
    FLEXCANDRV_ClearAllMsgObjFlags(obj);

    /* clear all enhance rx fifo flags */
    /* only node 0 support the feature of enhance rx fifo */
    if (obj->initHwPar.canInstanceIdx != 0)
    {
        if (controllerCfg->enhancefifoEnable == true)
        {
            FLEXCANDRV_ClearEnhanceRxFFIsrFlag(obj, FLEXCANDRV_ENHANCERXFF_ISR_SRC_DAIE |  \
                                                    FLEXCANDRV_ENHANCERXFF_ISR_SRC_WMMIE | \
                                                    FLEXCANDRV_ENHANCERXFF_ISR_SRC_OVFIE | \
                                                    FLEXCANDRV_ENHANCERXFF_ISR_SRC_UFWIE);
        }
    }

    /* enable FlexCan module */
    FLEXCANDRV_Start(obj);
    /* switch to user mode */
    FLEXCANREG_SetAccessMode(obj->flexCanReg, FLEXCANDRV_CAN_ACCESS_MODE_USER);
}

/** 
  * @brief  Transmit the message unconditionally once
  * @param  obj       pointer to a FLEXCANDRV_Type structure
  * @param  msgObj    pointer to a FLEXCANDRV_MsgObjType structure
  */
void FLEXCANDRV_TransmitMsg (FLEXCANDRV_Type *obj, FLEXCANDRV_MsgObjType *msgObj)
{
    uint32_t *msgBufPtr = NULL;

    /* get current message buffer start address */
    msgBufPtr = (uint32_t *)FLEXCANDRV_GetMsgBufStartAddr(obj, msgObj->msgBufId);
    
    /* set transmit code for the message buffer and start transmitting */
    *msgBufPtr |= (((uint32_t)FLEXCANDRV_MSG_BUF_CODE_TX_REQUEST) << FLEXCANDRV_MSG_BUF_CODE_SHIFT);
}

/** 
  * @brief  Set the transmit message object into message buffer
  * @param  obj       pointer to a FLEXCANDRV_Type structure
  * @param  msgObj    pointer to a FLEXCANDRV_MsgObjType structure
  */
void FLEXCANDRV_SetTxMsg (FLEXCANDRV_Type *obj, FLEXCANDRV_MsgObjType *msgObj)
{
    uint32_t *msgBufPtr = NULL;
    uint32_t dataLen;

    /* get current message buffer start address */
    msgBufPtr = (uint32_t *)FLEXCANDRV_GetMsgBufStartAddr(obj, msgObj->msgBufId);
    /* add data field address offset (2 * 32 bit) */
    msgBufPtr += 2;

    /* get data length from message buffer DLC */
    dataLen = FLEXCANDRV_GetMsgBufDataLen(obj, msgObj->msgBufId);

    /* load the data into message buffer */
    uint8_t i = 0;
    for (i = 0; i < dataLen; i++)
    {
        /* load the data in byte length */
        if ((i % 4) == 0)
        {
            /* clean the old data */
            *msgBufPtr = 0;
            /* lowest byte in 32-bit */
            *msgBufPtr |= (((uint32_t)msgObj->data[i]) << 24);
        }
        else if ((i % 4) == 1)
        {
            /* 2nd byte in 32-bit */
            *msgBufPtr |= (((uint32_t)msgObj->data[i]) << 16);
        }
        else if ((i % 4) == 2)
        {
            /* 3rd byte in 32-bit */
            *msgBufPtr |= (((uint32_t)msgObj->data[i]) << 8);
        }
        else if ((i % 4) == 3)
        {
            /* highest byte in 32-bit */
            *msgBufPtr |= ((uint32_t)msgObj->data[i]);
            /* increment the 32-bit data pointer  */
            msgBufPtr++;
        }
    }
}

/** 
  * @brief  Get the message object from message buffer
  * @param  obj       pointer to a FLEXCANDRV_Type structure
  * @param  msgObj    pointer to a FLEXCANDRV_MsgObjType structure
  */
void FLEXCANDRV_GetRxMsg (FLEXCANDRV_Type *obj, FLEXCANDRV_MsgObjType *msgObj)
{
    uint32_t *msgBufPtr = NULL;
    uint8_t   dataLen;
    bool      isExtMsgId;

    /* get current message buffer start address */
    msgBufPtr = (uint32_t *)FLEXCANDRV_GetMsgBufStartAddr(obj, msgObj->msgBufId);

    /* get the rx message DLC */
    msgObj->dlc = FLEXCANDRV_DLC2DataLen((FLEXCANDRV_DataLenCodeType)((*msgBufPtr & MESSAGE_BUFFER_CS_DLC_MASK) >> \
                                                                      MESSAGE_BUFFER_CS_DLC_SHIFT));

    /* get the rx message type */
    msgObj->isFd = (*msgBufPtr & MESSAGE_BUFFER_CS_EDL_MASK) >> MESSAGE_BUFFER_CS_EDL_SHIFT;

    /* get the rx message timestamp */
    msgObj->timeStamp = (*msgBufPtr & MESSAGE_BUFFER_CS_TS_MASK) >> MESSAGE_BUFFER_CS_TS_SHIFT;

    /* get extended message ID bit (CS.IDE) */
    isExtMsgId = (*msgBufPtr & MESSAGE_BUFFER_CS_IDE_MASK) >> MESSAGE_BUFFER_CS_IDE_SHIFT;

    /* set message buffer pointer to ID field */
    msgBufPtr++;

    /* get message ID */
    if (isExtMsgId == true)
    {
        msgObj->msgId = (*msgBufPtr & MESSAGE_BUFFER_ID_EXT_ID_MASK) >> MESSAGE_BUFFER_ID_EXT_ID_SHIFT;
    }
    else
    {
        msgObj->msgId = (*msgBufPtr & MESSAGE_BUFFER_ID_STD_ID_MASK) >> MESSAGE_BUFFER_ID_STD_ID_SHIFT;
    }

    /* set the message buffer pointer to data field */
    msgBufPtr++;

    /* get data length from message buffer DLC */
    dataLen = FLEXCANDRV_GetMsgBufDataLen(obj, msgObj->msgBufId);

    /* load the data from message buffer to data array */
    uint8_t i = 0;
    for (i = 0; i < dataLen; i++)
    {
        if ((i % 4) == 0)
        {
            /* load 1 byte data from highest byte in 32-bit */
            msgObj->data[i] = (*msgBufPtr >> 24);
        }
        else if ((i % 4) == 1)
        {
            /* load 1 byte data from 2nd highest byte in 32-bit */
            msgObj->data[i] = (*msgBufPtr >> 16);
        }
        else if ((i % 4) == 2)
        {
            /* load 1 byte data from 3nd highest byte in 32-bit */
            msgObj->data[i] = (*msgBufPtr >> 8);
        }
        /* when (i % 4) == 3 */
        else
        {
            /* load 1 byte data from lowest byte in 32-bit */
            msgObj->data[i] = (*msgBufPtr >> 0);
            /* increment message buffer 32-bit data pointer */
            msgBufPtr++;
        }
    }

    /* unlock mailbox globally */
    FLEXCANREG_GetFreeRunningTimer(obj->flexCanReg);
}

/**
  * @brief  Get the message object from rx fifo
  * @param  obj       pointer to a FLEXCANDRV_Type structure
  * @param  msgObj    pointer to a FLEXCANDRV_MsgObjType structure
  */
void FLEXCANDRV_GetRxFifoMsg (FLEXCANDRV_Type *obj, FLEXCANDRV_MsgObjType *msgObj)
{
    bool isExtMsgId;
    FLEXCANDRV_MsgObjType tempMsgObj;

    /* get rx fifo out port start address (message buffer 0) */
    uint32_t *msgBufPtr = (uint32_t *)FLEXCANDRV_GetMsgBufStartAddr(obj, 0);

    /* get the rx message DLC */
    msgObj->dlc = FLEXCANDRV_DLC2DataLen((FLEXCANDRV_DataLenCodeType)((*msgBufPtr & MESSAGE_BUFFER_CS_DLC_MASK) >> \
                                         MESSAGE_BUFFER_CS_DLC_SHIFT));
    /* get extended message ID bit (CS.IDE) */
    isExtMsgId = (*msgBufPtr & MESSAGE_BUFFER_CS_IDE_MASK) >> MESSAGE_BUFFER_CS_IDE_SHIFT;

    /* set message buffer pointer to ID field */
    msgBufPtr++;

    /* get message ID */
    if (isExtMsgId == true)
    {
        msgObj->msgId = (*msgBufPtr & MESSAGE_BUFFER_ID_EXT_ID_MASK) >> MESSAGE_BUFFER_ID_EXT_ID_SHIFT;
    }
    else
    {
        msgObj->msgId = (*msgBufPtr & MESSAGE_BUFFER_ID_STD_ID_MASK) >> MESSAGE_BUFFER_ID_STD_ID_SHIFT;
    }

    /* set message buffer pointer to DATA field */
    msgBufPtr++;

    /* load the data from message buffer to data array */
    uint8_t i = 0;
    for (i = 0; i < 8; i++)
    {
        if ((i % 4) == 0)
        {
            /* load 1 byte data from highest byte in 32-bit */
            msgObj->data[i] = (*msgBufPtr >> 24);
        }
        else if ((i % 4) == 1)
        {
            /* load 1 byte data from 2nd highest byte in 32-bit */
            msgObj->data[i] = (*msgBufPtr >> 16);
        }
        else if ((i % 4) == 2)
        {
            /* load 1 byte data from 3nd highest byte in 32-bit */
            msgObj->data[i] = (*msgBufPtr >> 8);
        }
        /* when (i % 4) == 3 */
        else
        {
            /* load 1 byte data from lowest byte in 32-bit */
            msgObj->data[i] = (*msgBufPtr >> 0);
            /* increment message buffer 32-bit data pointer */
            msgBufPtr++;
        }
    }

    /* clear rx fifo available flag to update rx fifo */
    tempMsgObj.msgBufId = 5;
    FLEXCANDRV_ClearMsgObjFlag(obj, tempMsgObj.msgBufId);
}

/** 
  * @brief  Clear message object flag
  * @param  obj             pointer to a FLEXCANDRV_Type structure
  * @param  msgBufferIdx    message buffer index
  *                          - This parameter is an unsigned integer that is greater
  *                            than or equal to 0x00 and less than or equal to 0xFF
  */
void FLEXCANDRV_ClearMsgObjFlag (FLEXCANDRV_Type *obj, uint8_t msgBufferIdx)
{
    uint32_t temp, temp1 = 0;

    temp1 = msgBufferIdx % 32;
    temp  = 0x00000001UL << temp1;

    if (msgBufferIdx > 95)
    {
        FLEXCANREG_SetMsgBufInterruptFlagReg(obj->flexCanReg, 3, temp);
    }
    else if (msgBufferIdx > 63)
    {
        FLEXCANREG_SetMsgBufInterruptFlagReg(obj->flexCanReg, 2, temp);
    }
    else if (msgBufferIdx > 31)
    {
        FLEXCANREG_SetMsgBufInterruptFlagReg(obj->flexCanReg, 1, temp);
    }
    else
    {
        FLEXCANREG_SetMsgBufInterruptFlagReg(obj->flexCanReg, 0, temp);
    }
}

/** 
  * @brief  Get message object flag, indicating a successful Rx/Tx operation completed
  * @param  obj             pointer to a FLEXCANDRV_Type structure
  * @param  msgBufferIdx    message buffer index
  *                          - This parameter is an unsigned integer that is greater
  *                            than or equal to 0x00 and less than or equal to 0xFF
  * @return Returns message buffer Tx/Rx operation complete flag
  *                          - 0: the corresponding buffer has no occurrence of successfully
  *                               completed transmission or reception
  *                          - 1: the corresponding buffer has successfully completed
  *                               transmission or reception
  */
uint8_t FLEXCANDRV_GetMsgObjFlag (FLEXCANDRV_Type *obj, uint8_t msgBufferIdx)
{
    uint32_t temp, temp1 = 0;

    temp1 = msgBufferIdx % 32;
    temp  = 0x00000001UL << temp1;

    if (msgBufferIdx > 95)
    {
        temp &= FLEXCANREG_GetMsgBufInterruptFlagReg(obj->flexCanReg, 3);
    }
    else if (msgBufferIdx > 63)
    {
        temp &= FLEXCANREG_GetMsgBufInterruptFlagReg(obj->flexCanReg, 2);
    }
    else if (msgBufferIdx > 31)
    {
        temp &= FLEXCANREG_GetMsgBufInterruptFlagReg(obj->flexCanReg, 1);
    }
    else
    {
        temp &= FLEXCANREG_GetMsgBufInterruptFlagReg(obj->flexCanReg, 0);
    }

    if (temp)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

/** 
  * @brief  Clear all message object flags
  * @param  obj    pointer to a FLEXCANDRV_Type structure
  */
void FLEXCANDRV_ClearAllMsgObjFlags (FLEXCANDRV_Type *obj)
{
    if (obj->initHwPar.canInstanceIdx != 0)
    {
        FLEXCANREG_SetMsgBufInterruptFlagReg(obj->flexCanReg, 3, 0xFFFFFFFF);
        FLEXCANREG_SetMsgBufInterruptFlagReg(obj->flexCanReg, 2, 0xFFFFFFFF);
        FLEXCANREG_SetMsgBufInterruptFlagReg(obj->flexCanReg, 1, 0xFFFFFFFF);
        FLEXCANREG_SetMsgBufInterruptFlagReg(obj->flexCanReg, 0, 0xFFFFFFFF);
    }
    else if (obj->initHwPar.canInstanceIdx == 0)
    {
        FLEXCANREG_SetMsgBufInterruptFlagReg(obj->flexCanReg, 0, 0xFFFFFFFF);
    }
}

/**
  * @brief  Enable interrupt for the corresponding message buffer
  * @param  obj             pointer to a FLEXCANDRV_Type structure
  * @param  msgBufferIdx    message buffer index
  *                          - This parameter is an unsigned integer that is greater
  *                            than or equal to 0x00 and less than or equal to 0x7F
  */
void FLEXCANDRV_EnableMsgObjInterrupt (FLEXCANDRV_Type *obj, uint8_t msgBufferIdx)
{
    uint32_t temp, temp1 = 0;

    temp1 = msgBufferIdx % 32;
    temp  = 0x00000001UL << temp1;

    if (msgBufferIdx > 95)
    {
        FLEXCANREG_SetMsgBufInterruptEnable(obj->flexCanReg, 3, temp);
    }
    else if (msgBufferIdx > 63)
    {
        FLEXCANREG_SetMsgBufInterruptEnable(obj->flexCanReg, 2, temp);
    }
    else if (msgBufferIdx > 31)
    {
        FLEXCANREG_SetMsgBufInterruptEnable(obj->flexCanReg, 1, temp);
    }
    else
    {
        FLEXCANREG_SetMsgBufInterruptEnable(obj->flexCanReg, 0, temp);
    }
}

/** 
  * @brief  Disable interrupt for the corresponding message buffer
  * @param  obj             pointer to a FLEXCANDRV_Type structure
  * @param  msgBufferIdx    message buffer index
  *                          - This parameter is an unsigned integer that is greater
  *                            than or equal to 0x00 and less than or equal to 0x7F
  */
void FLEXCANDRV_DisableMsgObjInterrupt (FLEXCANDRV_Type *obj, uint8_t msgBufferIdx)
{
    uint32_t temp, temp1 = 0;

    temp1 = msgBufferIdx % 32;
    temp  = ~(0x00000001UL << temp1);

    if (msgBufferIdx > 95)
    {
        FLEXCANREG_SetMsgBufInterruptDisable(obj->flexCanReg, 3, temp);
    }
    else if (msgBufferIdx > 63)
    {
        FLEXCANREG_SetMsgBufInterruptDisable(obj->flexCanReg, 2, temp);
    }
    else if (msgBufferIdx > 31)
    {
        FLEXCANREG_SetMsgBufInterruptDisable(obj->flexCanReg, 1, temp);
    }
    else
    {
        FLEXCANREG_SetMsgBufInterruptDisable(obj->flexCanReg, 0, temp);
    }
}

/** 
  * @brief  Get FlexCan error states
  * @param  obj    pointer to a FLEXCANDRV_Type structure
  * @return Returns node status
  *                 -This parameter can be any value of @ref FLEXCANDRV_NODESTATTYPE
  */
FLEXCANDRV_NodeStatType FLEXCANDRV_GetNodeStatus (FLEXCANDRV_Type *obj)
{
    FLEXCANDRV_NodeStatType ret = FLEXCANDRV_NODESTAT_IDLE;

    if (FLEXCANREG_GetTxState(obj->flexCanReg))
    {
        ret = FLEXCANDRV_NODESTAT_TRANSMITTING;
    }
    else if (FLEXCANREG_GetRxState(obj->flexCanReg))
    {
        ret = FLEXCANDRV_NODESTAT_RECEIVING;
    }
    else if (FLEXCANREG_GetIdleState(obj->flexCanReg))
    {
        ret = FLEXCANDRV_NODESTAT_IDLE;
    }
    else
    {
    }

    return ret;
}

/** 
  * @brief  Get FLEXCAN error states
  * @param  obj       pointer to a FLEXCANDRV_Type structure
  * @param  errSts    pointer to a FLEXCANDRV_ErrStatusType structure
  */
void FLEXCANDRV_GetErrorStatusFlag (FLEXCANDRV_Type *obj, FLEXCANDRV_ErrStatusType *errSts)
{
    uint8_t tempSts;

    tempSts = FLEXCANREG_GetFltConfinementState(obj->flexCanReg);
    if (tempSts & 0x2)
    {
        errSts->fltConfSts = FLEXCANDRV_FLTCONFSTS_BUSOFF;
    }
    else
    {
        errSts->fltConfSts = (FLEXCANDRV_FltConfStsType)tempSts;
    }

    errSts->bit1Err       = FLEXCANREG_GetBit1Error(obj->flexCanReg);
    errSts->bit0Err       = FLEXCANREG_GetBit0Error(obj->flexCanReg);
    errSts->ackErr        = FLEXCANREG_GetAckError(obj->flexCanReg);
    errSts->crcErr        = FLEXCANREG_GetCrcError(obj->flexCanReg);
    errSts->formErr       = FLEXCANREG_GetFormError(obj->flexCanReg);
    errSts->stuffErr      = FLEXCANREG_GetStuffError(obj->flexCanReg);
    errSts->errOvr        = FLEXCANREG_GetErrOverrunIntFlag(obj->flexCanReg);
    errSts->busOffInt     = FLEXCANREG_GetBusoffIntFlag(obj->flexCanReg);
    errSts->busOffDoneInt = FLEXCANREG_GetBusOffDoneIntFlag(obj->flexCanReg);
    errSts->synch         = FLEXCANREG_GetSynchFlag(obj->flexCanReg);
    errSts->txWarning     = FLEXCANREG_GetTxWarnFlag(obj->flexCanReg);
    errSts->rxWarning     = FLEXCANREG_GetTxWarnFlag(obj->flexCanReg);
    errSts->txWarnintInt  = FLEXCANREG_GetTxWarnIntFlag(obj->flexCanReg);
    errSts->rxWarningInt  = FLEXCANREG_GetRxWarnIntFlag(obj->flexCanReg);
    errSts->errInt        = FLEXCANREG_GetErrIntFlag(obj->flexCanReg);
    errSts->wakeUpInt     = FLEXCANREG_GetEdgeWakeIntFlag(obj->flexCanReg);

    if (FLEXCANREG_GetFdEnable(obj->flexCanReg) == true)
    {
        errSts->bit1FastErr  = FLEXCANREG_GetBit1FastError(obj->flexCanReg);
        errSts->bit0FastErr  = FLEXCANREG_GetBit0FastError(obj->flexCanReg);
        errSts->crcFastErr   = FLEXCANREG_GetCrcFastError(obj->flexCanReg);
        errSts->formFastErr  = FLEXCANREG_GetFormFastError(obj->flexCanReg);
        errSts->stuffFastErr = FLEXCANREG_GetStuffFastError(obj->flexCanReg);
        errSts->errFastInt   = FLEXCANREG_GetFastErrIntFlag(obj->flexCanReg);
    }
}

/** 
  * @brief  Clear error states flag
  * @param  obj        pointer to a FLEXCANDRV_Type structure
  * @param  errMask    err state bit mask combination
  *                     - This parameter can be any value of @ref FLEXCANDRV_ERRSTATUSMASKTYPE
  */
void FLEXCANDRV_ClearErrStatusFlag (FLEXCANDRV_Type *obj, FLEXCANDRV_ErrStatusMaskType errMask)
{
    FLEXCANREG_ClearErrFlag(obj->flexCanReg, errMask);
}

/** 
  * @brief  Abort pending Tx message
  * @param  obj       pointer to a FLEXCANDRV_Type structure
  * @param  msgObj    pointer to a FLEXCANDRV_MsgObjType structure
  * @return Returns pending Tx message abort result
  *                   - 0: no Tx message transfer pending
  *                   - 1: pending Tx message abort success
  */
uint8_t FLEXCANDRV_AbortPendingTxMsg (FLEXCANDRV_Type *obj, FLEXCANDRV_MsgObjType *msgObj)
{
    uint32_t         *msgBufPtr = NULL;
    volatile uint32_t msgBufCode;
    uint8_t           ret;

    /* set freeze mode enable */
    FLEXCANREG_SetFreezeMode(obj->flexCanReg, true);
    /* set halt mode enable */
    FLEXCANREG_SetHaltMode(obj->flexCanReg, true);

    /* check for freeze Ack */
    while ((FLEXCANREG_GetFreezeAck(obj->flexCanReg) == 0) || (FLEXCANREG_GetNotReadyFlag(obj->flexCanReg) == 0))
    {
        /* soft reset failed */
    }

    FLEXCANREG_SetTxAbortEnable(obj->flexCanReg, true);

    FLEXCANDRV_Start(obj);

    /* disable message buffer interrupt */
    FLEXCANDRV_DisableMsgObjInterrupt(obj, msgObj->msgBufId);

    /* clear message buffer flag */
    FLEXCANDRV_ClearMsgObjFlag(obj, msgObj->msgBufId);

    /* get current message buffer start address */
    msgBufPtr = (uint32_t *)FLEXCANDRV_GetMsgBufStartAddr(obj, msgObj->msgBufId);
    /* clear message buffer CS.CODE field */
    *msgBufPtr &= (~FLEXCANDRV_MSG_BUF_CODE_MASK << FLEXCANDRV_MSG_BUF_CODE_SHIFT);
    /* set the message buffer code as TX ABORT */
    *msgBufPtr |= (((uint32_t)FLEXCANDRV_MSG_BUF_CODE_ABORT) << FLEXCANDRV_MSG_BUF_CODE_SHIFT);

    /* wait until message buffer flag assert */
    while (FLEXCANDRV_GetMsgObjFlag(obj, msgObj->msgBufId) == 0)
    {
        /* message buffer flag not assert */
    }

    msgBufCode = (*msgBufPtr >> FLEXCANDRV_MSG_BUF_CODE_SHIFT) & FLEXCANDRV_MSG_BUF_CODE_MASK;

    /* check the tx pending message abort result */
    if (msgBufCode == FLEXCANDRV_MSG_BUF_CODE_ABORT)
    {
        ret = TX_PENDING_ABORT_SUCCESS;
    }
    else if (msgBufCode == FLEXCANDRV_MSG_BUF_CODE_TX_INACTIVE)
    {
        ret = TX_PENDING_ABORT_NO_TRANSFER;
    }
    else
    {
        ret = TX_PENDING_ABORT_FAILED;
    }

    /* clear message buffer flag */
    FLEXCANDRV_ClearMsgObjFlag(obj, msgObj->msgBufId);

    /* set freeze mode enable */
    FLEXCANREG_SetFreezeMode(obj->flexCanReg, true);
    /* set halt mode enable */
    FLEXCANREG_SetHaltMode(obj->flexCanReg, true);

    /* check for freeze Ack */
    while ((FLEXCANREG_GetFreezeAck(obj->flexCanReg) == 0) || (FLEXCANREG_GetNotReadyFlag(obj->flexCanReg) == 0))
    {
        /* soft reset failed */
    }

    FLEXCANREG_SetTxAbortEnable(obj->flexCanReg, false);

    FLEXCANDRV_Start(obj);

    return ret;
}

/** 
  * @brief  Calculate the CAN bit timing parameters
  * @param  bitTimingPara    pointer to a FLEXCANDRV_BitTimingType structure
  * @param  clkFreq          FLEXCAN module frequency
  * @param  samplePoint      can bit sample point 
  *                           - 0 - 10000 -> 0% - 100%
  * @param  sjw              synchronize jump width 
  *                           - 0 - 10000 -> 0% - 100%
  * @param  isFd             is the bit timing parameter group for CAN-FD
  *                           - 0: bit timing parameter group for CAN
  *                           - 1: bit timing parameter group for CAN-FD
  */
void FLEXCANDRV_BitTimingCalc (FLEXCANDRV_BitTimingType *bitTimingPara, \
                               uint32_t                  moduleFreq,    \
                               uint32_t                  baudrate,      \
                               uint16_t                  samplePoint,   \
                               uint16_t                  sjw,           \
                               uint8_t                   isFd)
{
    int32_t maxPrescaler, maxTseg1, minTseg1, maxTseg2, maxNumTq, minNumTq;
    int32_t tempPrescaler, tempSjw, tempTseg1, tempNumTq;
    float   bestErr = 0;

    /* set default best value for all bit timing parameters */
    int32_t bestPrescaler = 1, bestSjw = 1, bestNumTq = 8, bestTseg1 = 3, bestTseg2 = 2;

    /* set the optimal value for baudrate error, number of time quatna */
    const int32_t optNumTq          = 20;
    const float   optBaudrateErr    = 0.1;
    const float   optSamplePntToler = 0.25;

    /* set the maximum & minimum value for all bit timing parameters */
    if (isFd == false)
    {
        maxPrescaler = FLEXCAN_CBT_EPRESDIV_MASK >> FLEXCAN_CBT_EPRESDIV_SHIFT;
        maxTseg1     = (FLEXCAN_CBT_EPROPSEG_MASK >> FLEXCAN_CBT_EPROPSEG_SHIFT) + (FLEXCAN_CBT_EPSEG1_MASK >> FLEXCAN_CBT_EPSEG1_SHIFT);
        minTseg1     = 3;
        maxTseg2     = FLEXCAN_CBT_EPSEG2_MASK >> FLEXCAN_CBT_EPSEG2_SHIFT;
        maxNumTq     = maxTseg1 + maxTseg2 + 1;
        minNumTq     = 8;
    }
    else
    {
        maxPrescaler = FLEXCAN_FDCBT_FPRESDIV_MASK >> FLEXCAN_FDCBT_FPRESDIV_SHIFT;
        maxTseg1     = (FLEXCAN_FDCBT_FPROPSEG_MASK >> FLEXCAN_FDCBT_FPROPSEG_SHIFT) + (FLEXCAN_FDCBT_FPSEG1_MASK >> FLEXCAN_FDCBT_FPSEG1_SHIFT);
        minTseg1     = 3;
        maxTseg2     = FLEXCAN_FDCBT_FPSEG2_MASK >> FLEXCAN_FDCBT_FPSEG2_SHIFT;
        maxNumTq     = maxTseg1 + maxTseg2 + 1;
        minNumTq     = 8;
    }

    /* calculate prescaler, number of Tq */
    bestErr = (float)baudrate;
    for(tempPrescaler = 1; tempPrescaler <= maxPrescaler; tempPrescaler++)
    {
        /* get the quanta frequency */
        float Fq = (float)moduleFreq / tempPrescaler;
        /* get the number of time quanta */
        tempNumTq = (int32_t)(Fq / baudrate);

        /* To avoid division by 0 and number of Tq less than minmum number of Tq */
        if ((tempNumTq == 0) || (tempNumTq < minNumTq))
        {
            break;
        }

        /* calculate temp baudrate */
        float tempBaudrate = Fq / tempNumTq;
        /* calculate temp baudrate error */
        float tempErr = ((tempBaudrate - baudrate) > 0) ? (tempBaudrate - baudrate) : (baudrate - tempBaudrate);

        if ((tempNumTq <= maxNumTq) && (tempErr <= bestErr))
        {
            /* set temporary prescaler, number of Tq, baudrate error as the best value */
            bestPrescaler = tempPrescaler;
            bestNumTq     = tempNumTq;
            bestErr       = tempErr;

            /* check if get the optimal condition */
            if ((tempNumTq <= optNumTq) && tempErr < optBaudrateErr)
            {
                break;
            }
        }
    }

    /* calculate sample point (time segment 1) */
    bestErr = samplePoint * optSamplePntToler;

    /* saturate max time segment 1 value */
    if (bestNumTq < maxTseg1)
    {
        maxTseg1 = bestNumTq;
    }
    for (tempTseg1 = maxTseg1; tempTseg1 >= minTseg1; tempTseg1--)
    {
        /* get the temporary sample point */
        int32_t tempSamplePnt = ((tempTseg1 + 1) * 10000) / bestNumTq;
        /* get the temporary sample point error */
        int32_t tempErr = (tempSamplePnt - samplePoint) > 0 ? (tempSamplePnt - samplePoint) : (samplePoint - tempSamplePnt);

        /* break the for loop if the temporary sample point less
           than the user required sample point */
        if (tempSamplePnt < samplePoint)
        {
            break;
        }

        /* update the best T_seg1 and best error if met the tolerance */
        if (tempErr < bestErr)
        {
            bestTseg1 = tempTseg1;
            bestErr   = tempErr;
        }
    }

    /* calculate time segment 2 */
    bestTseg2 = bestNumTq - bestTseg1 - 1;

    /* calculate best SJW */
    bestErr = 10000;
    for (tempSjw = 1; tempSjw <= bestTseg2; tempSjw++)
    {
        /* get the temporary synchronize jump width percentage */
        int32_t tempSjwPercent = (tempSjw * 10000) / bestNumTq;
        int32_t tempErr        = ((tempSjwPercent - sjw) > 0) ? (tempSjwPercent - sjw) : (sjw - tempSjwPercent);

        /*  */
        if(tempErr < bestErr)
        {
            bestSjw = tempSjw;
            bestErr = tempErr;
        }
    }

    bitTimingPara->prescalerDiv    = bestPrescaler;
    bitTimingPara->propSeg         = (uint32_t)(bestTseg1 * 0.6);
    bitTimingPara->phaseSeg1       = bestTseg1 - bitTimingPara->propSeg;
    bitTimingPara->phaseSeg2       = bestTseg2;
    bitTimingPara->resyncJumpWidth = bestSjw;
}

/** 
  * @brief  Set enhanced rx fifo water mark
  * @param  obj          pointer to a FLEXCANDRV_Type structure
  * @param  waterMark    the value of enhanced rx fifo watermark
  *                       - This parameter is an unsigned integer that is greater
  *                         than or equal to 0x00 and less than or equal to 0x1F
  */
void FLEXCANDRV_SetEnhanceRxFFWaterMark (FLEXCANDRV_Type *obj, uint8_t waterMark)
{
    /* set freeze mode enable */
    FLEXCANREG_SetFreezeMode(obj->flexCanReg, true);
    /* set halt mode enable */
    FLEXCANREG_SetHaltMode(obj->flexCanReg, true);

    /* check for freeze Ack */
    while ((FLEXCANREG_GetFreezeAck(obj->flexCanReg) == 0) || (FLEXCANREG_GetNotReadyFlag(obj->flexCanReg) == 0))
    {
        /* soft reset failed */
    }

    FLEXCANREG_SetEnhanceRxFifoWatermark(obj->flexCanReg, waterMark);

    /* set freeze mode disable */
    FLEXCANREG_SetFreezeMode(obj->flexCanReg, false);
    /* set halt mode disable */
    FLEXCANREG_SetHaltMode(obj->flexCanReg, false);
}

/** 
  * @brief  Set enhanced rx interrupt request
  * @param  obj           pointer to a FLEXCANDRV_Type structure
  * @param  isrSrcMask    the combine of interrupt source mask
  *                        - user needs to customize their own mask value 
  *                          based on the definition of the ESR1 register
  * @param  enabled       enable or disable these interrupt req
  *                        - 0: disable these interrupt req
  *                        - 1: enable these interrupt req
  */
void FLEXCANDRV_SetEnhanceRxFFIsr (FLEXCANDRV_Type *obj, uint32_t isrSrcMask, bool enabled)
{
    if (enabled == true)
    {
        if ((isrSrcMask & FLEXCANDRV_ENHANCERXFF_ISR_SRC_DAIE) != 0)
        {
            FLEXCANREG_SetEnhanceRxFifoDataAvailableIntEnable(obj->flexCanReg, true);
        }

        if ((isrSrcMask & FLEXCANDRV_ENHANCERXFF_ISR_SRC_WMMIE) != 0)
        {
            FLEXCANREG_SetEnhanceRxFifoWatrmarkIntEnable(obj->flexCanReg, true);
        }

        if ((isrSrcMask & FLEXCANDRV_ENHANCERXFF_ISR_SRC_OVFIE) != 0)
        {
            FLEXCANREG_SetEnhanceRxFifoOverflowIntEnable(obj->flexCanReg, true);
        }

        if ((isrSrcMask & FLEXCANDRV_ENHANCERXFF_ISR_SRC_UFWIE) != 0)
        {
            FLEXCANREG_SetEnhanceRxFifoUnderflowIntEnable(obj->flexCanReg, true);
        }
    }
    else
    {
        if ((isrSrcMask & FLEXCANDRV_ENHANCERXFF_ISR_SRC_DAIE) != 0)
        {
            FLEXCANREG_SetEnhanceRxFifoDataAvailableIntEnable(obj->flexCanReg, false);
        }

        if ((isrSrcMask & FLEXCANDRV_ENHANCERXFF_ISR_SRC_WMMIE) != 0)
        {
            FLEXCANREG_SetEnhanceRxFifoWatrmarkIntEnable(obj->flexCanReg, false);
        }

        if ((isrSrcMask & FLEXCANDRV_ENHANCERXFF_ISR_SRC_OVFIE) != 0)
        {
            FLEXCANREG_SetEnhanceRxFifoOverflowIntEnable(obj->flexCanReg, false);
        }

        if ((isrSrcMask & FLEXCANDRV_ENHANCERXFF_ISR_SRC_UFWIE) != 0)
        {
            FLEXCANREG_SetEnhanceRxFifoUnderflowIntEnable(obj->flexCanReg, false);
        }
    }
}

/** 
  * @brief  Clear enhanced rx interrupt flag
  * @param  obj           pointer to a FLEXCANDRV_Type structure
  * @param  isrSrcMask    the combine of interrupt source mask
  *                        - user needs to customize their own mask value 
  *                          based on the definition of the ESR1 register
  */
void FLEXCANDRV_ClearEnhanceRxFFIsrFlag (FLEXCANDRV_Type *obj, uint32_t isrSrcMask)
{
    if ((isrSrcMask & FLEXCANDRV_ENHANCERXFF_ISR_SRC_DAIE) != 0)
    {
        FLEXCANREG_ClearEnhanceRxFifoDataAvailableFlag(obj->flexCanReg);
    }

    if ((isrSrcMask & FLEXCANDRV_ENHANCERXFF_ISR_SRC_WMMIE) != 0)
    {
        FLEXCANREG_ClearEnhanceRxFifoWatermarkFlag(obj->flexCanReg);
    }

    if ((isrSrcMask & FLEXCANDRV_ENHANCERXFF_ISR_SRC_OVFIE) != 0)
    {
        FLEXCANREG_ClearEnhanceRxFifoOverflowFlag(obj->flexCanReg);
    }

    if ((isrSrcMask & FLEXCANDRV_ENHANCERXFF_ISR_SRC_UFWIE) != 0)
    {
        FLEXCANREG_ClearEnhanceRxFifoUnderflowFlag(obj->flexCanReg);
    }
}

/** 
  * @brief  Get enhanced rx interrupt flag
  * @param  obj       pointer to a FLEXCANDRV_Type structure
  * @param  isrSrc    the interrupt source
  *                    - This parameter can be any value of @ref FLEXCANDRV_ENHANCERXFFISRSRCTYPE
  * @return Returns the enhanced rx interrupt flag
  *                    - 0: rx fifo interrupt flag is 0
  *                    - 1: rx fifo interrupt flag is 1
  */
bool FLEXCANDRV_GetEnhanceRxFFIsrFlag (FLEXCANDRV_Type *obj, FLEXCANDRV_EnhanceRxFFIsrSrcType isrSrc)
{
    bool ret = false;

    switch (isrSrc)
    {
        case FLEXCANDRV_ENHANCERXFF_ISR_SRC_DAIE:
            if (FLEXCANREG_GetEnhanceRxFifoDataAvailableFlag(obj->flexCanReg) != 0)
            {
                ret = true;
            }
            break;

        case FLEXCANDRV_ENHANCERXFF_ISR_SRC_WMMIE:
            if (FLEXCANREG_GetEnhanceRxFifoWatermarkFlag(obj->flexCanReg) != 0)
            {
                ret = true;
            }
            break;

        case FLEXCANDRV_ENHANCERXFF_ISR_SRC_OVFIE:
            if (FLEXCANREG_GetEnhanceRxFifoOverflowFlag(obj->flexCanReg) != 0)
            {
                ret = true;
            }
            break;

        case FLEXCANDRV_ENHANCERXFF_ISR_SRC_UFWIE:
            if (FLEXCANREG_GetEnhanceRxFifoUnderflowFlag(obj->flexCanReg) != 0)
            {
                ret = true;
            }
            break;

        default:
            break;
    }

    return ret;
}

/** 
  * @brief  Get the enhanced rx fifo is empyt or not
  * @param  obj    pointer to a FLEXCANDRV_Type structure
  * @return Returns the enhanced rx fifo is empty or not
  *                 - 0: rx fifo is not empyt
  *                 - 1: rx fifo is empty
  */
bool FLEXCANDRV_GetEnhanceRxFFIsEmpty (FLEXCANDRV_Type *obj)
{
    bool ret = false;

    if (FLEXCANREG_GetEnhanceRxFifoEmptyFlag(obj->flexCanReg) != 0)
    {
        ret = true;
    }

    return ret;
}

/** 
  * @brief  Get the enhanced rx fifo is full or not
  * @param  obj    pointer to a FLEXCANDRV_Type structure
  * @return Returns the enhanced rx fifo is full or not
  *                 - 0: rx fifo is not full
  *                 - 1: rx fifo is full
  */
bool FLEXCANDRV_GetEnhanceRxFFIsFull (FLEXCANDRV_Type *obj)
{
    bool ret = false;

    if (FLEXCANREG_GetEnhanceRxFifoFullFlag(obj->flexCanReg) != 0)
    {
        ret = true;
    }

    return ret;
}

/** 
  * @brief  Get the number of message stored in the enhanced rx fifo
  * @param  obj    pointer to a FLEXCANDRV_Type structure
  * @return Returns the number of message stored in the enhanced rx fifo
  *                 - This parameter is an unsigned integer that is greater
  *                   than or equal to 0x00 and less than or equal to 0x3F
  */
uint8_t FLEXCANDRV_GetEnhanceRxFFMsgNums (FLEXCANDRV_Type *obj)
{
    uint8_t ret = 0;

    ret = FLEXCANREG_GetEnhanceRxFifoElementNum(obj->flexCanReg);

    return ret;
}

/** 
  * @brief  Get the received message from enhanced rx fifo
  * @param  obj       pointer to a FLEXCANDRV_Type structure
  * @param  msgObj    pointer to a FLEXCANDRV_MsgObjType structure
  */
void FLEXCANDRV_GetEnhanceRxFifoMsg (FLEXCANDRV_Type *obj, FLEXCANDRV_MsgObjType *msgObj)
{
    uint32_t *msgBufPtr = (uint32_t *)FLEXCANREG_GetEnhRxFifoStartAddr(obj->flexCanReg);
    uint8_t   dlcCode = 0, i = 0;
    bool      isExtMsgId;

    dlcCode           = ((msgBufPtr[0] >> 16) & 0x0F);
    msgObj->timeStamp = msgBufPtr[0] & 0xFFFF;

    msgObj->dlc = FLEXCANDRV_DLC2DataLen((FLEXCANDRV_DataLenCodeType)dlcCode);
    /* get extended message ID bit (CS.IDE) */
    isExtMsgId = (*msgBufPtr & MESSAGE_BUFFER_CS_IDE_MASK) >> MESSAGE_BUFFER_CS_IDE_SHIFT;

    /* set message buffer pointer to ID field */
    msgBufPtr++;

    /* get message ID */
    if (isExtMsgId == true)
    {
        msgObj->msgId = (*msgBufPtr & MESSAGE_BUFFER_ID_EXT_ID_MASK) >> MESSAGE_BUFFER_ID_EXT_ID_SHIFT;
    }
    else
    {
        msgObj->msgId = (*msgBufPtr & MESSAGE_BUFFER_ID_STD_ID_MASK) >> MESSAGE_BUFFER_ID_STD_ID_SHIFT;
    }

    msgBufPtr++;

    for (i = 0; i < msgObj->dlc; i++)
    {
        if ((i % 4) == 0)
        {
            /* load 1 byte data from highest byte in 32-bit */
            msgObj->data[i] = (*msgBufPtr >> 24);
        }
        else if ((i % 4) == 1)
        {
            /* load 1 byte data from 2nd highest byte in 32-bit */
            msgObj->data[i] = (*msgBufPtr >> 16);
        }
        else if ((i % 4) == 2)
        {
            /* load 1 byte data from 3nd highest byte in 32-bit */
            msgObj->data[i] = (*msgBufPtr >> 8);
        }
        /* when (i % 4) == 3 */
        else
        {
            /* load 1 byte data from lowest byte in 32-bit */
            msgObj->data[i] = (*msgBufPtr >> 0);
            /* increment message buffer 32-bit data pointer */
            msgBufPtr++;
        }
    }

    msgBufPtr++;
    msgObj->hrTimeStamp = *msgBufPtr;

    /* Note: must clear the bit, nor make the internal point to the next rx fifo address */
    FLEXCANDRV_ClearEnhanceRxFFIsrFlag(obj, FLEXCANDRV_ENHANCERXFF_ISR_SRC_DAIE);
}

/** 
  * @brief  Set the leagcy rx fifo ID filter
  * @param  obj              pointer to a FLEXCANREG_TypeDef structure
  * @param  idFilterTable    pointer to a FLEXCANDRV_FIFOFILTERIDTABLE
  */
void FLEXCANDRV_SetRxFifoFilter (FLEXCANREG_TypeDef *obj, const FLEXCANDRV_FifoFilterIdTable *idFilterTable)
{
    /*  Set rx fifo ID filter table elements */
    uint32_t i = 0, j = 0, numOfFilters = 0;
    uint32_t val1 = 0, val2 = 0, val = 0;
    uint32_t formatType = 0;
    uint8_t  rxFifoFilterTableOffset = 0x6;
    volatile uint32_t *filterTable = (uint32_t *)(&obj->MSGBUF[rxFifoFilterTableOffset * 4]);
    
    numOfFilters = FLEXCANREG_GetLegacyRxFifoFilterNums(obj);
    
    FLEXCANREG_SetRxIdAcceptanceMode(obj, idFilterTable[0].idFormat);
    formatType =  idFilterTable[0].idFormat;
    switch (formatType) 
    {
        case (FLEXCAN_RX_FIFO_ID_FORMAT_A):
            /* One full ID (standard and extended) per ID Filter Table element */
            for (i = 0; i < RXFIFOFILTERELEMENTNUM(numOfFilters); i++)
            {
                val = 0;

                if (idFilterTable[i].isRemoteFrame)
                {
                    val = 1UL << FLEXCAN_RX_FIFO_ID_FILTER_FORMATAB_RTR_SHIFT;
                }
                if (idFilterTable[i].isExtendedFrame)
                {
                    val |= 1UL << FLEXCAN_RX_FIFO_ID_FILTER_FORMATAB_IDE_SHIFT;
                    filterTable[i] = val + ((idFilterTable[i].id <<                         \
                                             FLEXCAN_RX_FIFO_ID_FILTER_FORMATA_EXT_SHIFT) & \
                                             FLEXCAN_RX_FIFO_ID_FILTER_FORMATA_EXT_MASK);
                }
                else
                {
                    filterTable[i] = val + ((idFilterTable[i].id <<                         \
                                             FLEXCAN_RX_FIFO_ID_FILTER_FORMATA_STD_SHIFT) & \
                                             FLEXCAN_RX_FIFO_ID_FILTER_FORMATA_STD_MASK);
                }
            }
            break;

        case (FLEXCAN_RX_FIFO_ID_FORMAT_B):
            /*Two full standard IDs or two partial 14-bit (standard and extended) IDs
              per ID Filter Table element */ 
            j = 0;
            for (i = 0; i < RXFIFOFILTERELEMENTNUM(numOfFilters); i++)
            {
                val1 = 0;
                val2 = 0;

                if (idFilterTable[j].isRemoteFrame)
                {
                    val1 = 1UL << FLEXCAN_RX_FIFO_ID_FILTER_FORMATAB_RTR_SHIFT;
                }
                if (idFilterTable[j + 1].isRemoteFrame)
                {
                    val2 = 1UL << FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_RTR_SHIFT;
                }
                if (idFilterTable[j].isExtendedFrame)
                {
                    val1 |= 1UL << FLEXCAN_RX_FIFO_ID_FILTER_FORMATAB_IDE_SHIFT;

                    filterTable[i] = val1 + (((idFilterTable[j].id &                               \
                                               FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_EXT_MASK) >>      \
                                               FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT) << \
                                               FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_EXT_SHIFT1);
                }
                else
                {
                    filterTable[i] = val1 + ((idFilterTable[j].id &                          \
                                              FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_STD_MASK) << \
                                              FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_STD_SHIFT1); 
                }
                if (idFilterTable[j + 1].isExtendedFrame)
                {
                    val2 |= 1UL << FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_IDE_SHIFT;

                    filterTable[i] |= val2 + (((idFilterTable[j + 1].id &                         \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_EXT_MASK) >>      \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT) << \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_EXT_SHIFT2);
                }
                else
                {
                    filterTable[i] |= val2 + ((idFilterTable[j + 1].id &                    \
                                               FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_STD_MASK) << \
                                               FLEXCAN_RX_FIFO_ID_FILTER_FORMATB_STD_SHIFT2);
                }
                j = j + 2;
            }
            break;

        case (FLEXCAN_RX_FIFO_ID_FORMAT_C):
            /* Four partial 8-bit Standard IDs per ID Filter Table element */
            j = 0;
            for (i = 0; i < RXFIFOFILTERELEMENTNUM(numOfFilters); i++)
            {
                if (idFilterTable[j].isExtendedFrame)
                {
                    filterTable[i] |= val1 + (((idFilterTable[j].id &                               \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_EXT_MASK) >>      \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT) << \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_SHIFT1);
                }
                else
                {
                    filterTable[i] |= val1 + (((idFilterTable[j].id &                               \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_STD_MASK) >>      \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT) << \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_SHIFT1);
                }
                if (idFilterTable[j + 1].isExtendedFrame)
                {
                    filterTable[i] |= val1 + (((idFilterTable[j + 1].id &                         \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_EXT_MASK) >>      \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT) << \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_SHIFT2);
                }
                else
                {
                    filterTable[i] |= val1 + (((idFilterTable[j + 1].id &                         \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_STD_MASK) >>      \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT) << \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_SHIFT2);
                }
                if (idFilterTable[j + 2].isExtendedFrame)
                {
                    filterTable[i] |= val1 + (((idFilterTable[j + 2].id &                         \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_EXT_MASK) >>      \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT) << \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_SHIFT3);
                }
                else
                {
                    filterTable[i] |= val1 + (((idFilterTable[j + 2].id &                         \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_STD_MASK) >>      \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT) << \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_SHIFT3);
                }
                if (idFilterTable[j + 3].isExtendedFrame)
                {
                    filterTable[i] |= val1 + (((idFilterTable[j + 3].id &                         \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_EXT_MASK) >>      \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT) << \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_SHIFT4);
                }
                else
                {
                    filterTable[i] |= val1 + (((idFilterTable[j + 3].id &                         \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_STD_MASK) >>      \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT) << \
                                                FLEXCAN_RX_FIFO_ID_FILTER_FORMATC_SHIFT4);
                }
                j = j + 4;
            }
            break;

        case (FLEXCAN_RX_FIFO_ID_FORMAT_D):
            /* All frames rejected */
            break;

        default:
            /* Should not get here */ 
            break;
    }
}

/** 
  * @brief  Set the remote frame msg
  * @param  obj         pointer to a FLEXCANDRV_Type structure
  * @param  msgId       the ID for the remote frame
  *                      - This parameter is an unsigned integer that is greater 
  *                        than or equal to 0x00 and less than or equal to 0x7FF
  * @param  msgBufId    mailbox number used for transmite the remote frame
  *                      - This parameter is an unsigned integer that is greater 
  *                        than or equal to 0x00 and less than or equal to 0x7F
  */
void FLEXCANDRV_SetRemoteTxMsg (FLEXCANDRV_Type *obj, uint32_t msgId, uint16_t msgBufId)
{
    uint32_t *msgBufPtr = NULL;
    uint32_t tempVar;
    /* get current message buffer start address */
    msgBufPtr = (uint32_t *)FLEXCANDRV_GetMsgBufStartAddr(obj, msgBufId);
    
      /* set message ID */
    tempVar = msgBufPtr[MESSAGE_BUFFER_ID_WORD_NUM];
    tempVar &= ~(MESSAGE_BUFFER_ID_STD_ID_MASK); 
    tempVar |= ((msgId << MESSAGE_BUFFER_ID_STD_ID_SHIFT) & MESSAGE_BUFFER_ID_STD_ID_MASK);
    msgBufPtr[MESSAGE_BUFFER_ID_WORD_NUM] = tempVar;

    /* set message RTR */
    tempVar = 0;
    tempVar = msgBufPtr[MESSAGE_BUFFER_CS_WORD_NUM];
    tempVar &= ~(MESSAGE_BUFFER_CS_RTR_MASK); 
    tempVar |= ((0x1UL << MESSAGE_BUFFER_CS_RTR_SHIFT) & MESSAGE_BUFFER_CS_RTR_MASK);
    msgBufPtr[MESSAGE_BUFFER_CS_WORD_NUM] = tempVar;
}

/**
  * @brief  Transmite the remote frame msg
  * @param  obj         pointer to a FLEXCANDRV_Type structure
  * @param  msgBufId    mailbox number used for transmite the remote frame
  *                      - This parameter is an unsigned integer that is greater 
  *                        than or equal to 0x00 and less than or equal to 0x7F
  */
void FLEXCANDRV_TransmitRemoteTxMsg (FLEXCANDRV_Type *obj, uint16_t msgBufId)
{
    uint32_t *msgBufPtr = NULL;
    /* get current message buffer start address */
    msgBufPtr = (uint32_t *)FLEXCANDRV_GetMsgBufStartAddr(obj, msgBufId);
    
    /* send remote frame (CODE = 0b1100) */
    *msgBufPtr |= (((uint32_t)0x0CUL) << FLEXCANDRV_MSG_BUF_CODE_SHIFT);
}

/** 
  * @brief  Set the remote response msg for MB RX
  * @param  obj         pointer to a FLEXCANDRV_Type structure
  * @param  msgId       the ID for the remote frame
  *                      - This parameter is an unsigned integer that is greater 
  *                        than or equal to 0x00 and less than or equal to 0x7FF
  * @param  msgBufId    mailbox number used for transmite the remote frame
  *                      - This parameter is an unsigned integer that is greater 
  *                        than or equal to 0x00 and less than or equal to 0x7F
  * @param  data        pointer to the 8-bit msg data buff that prepared to response the remote frame
  * @param  length      the length for the msg data (byte)
  *                      - This parameter is an unsigned integer that is greater 
  *                        than or equal to 0 and less than or equal to 8
  */
void FLEXCANDRV_SetRemoteResponMsg (FLEXCANDRV_Type *obj, uint32_t msgId, uint16_t msgBufId, \
                                    uint8_t *data, uint8_t length)
{
    uint32_t *msgBufPtr = NULL;
    uint32_t tempVar;
    /* get current message buffer start address */
    msgBufPtr = (uint32_t *)FLEXCANDRV_GetMsgBufStartAddr(obj, msgBufId);

    /* set message ID */
    tempVar = msgBufPtr[MESSAGE_BUFFER_ID_WORD_NUM];
    tempVar &= ~(MESSAGE_BUFFER_ID_STD_ID_MASK);
    tempVar |= ((msgId << MESSAGE_BUFFER_ID_STD_ID_SHIFT) & MESSAGE_BUFFER_ID_STD_ID_MASK);
    msgBufPtr[MESSAGE_BUFFER_ID_WORD_NUM] = tempVar;

    /* set message length */
    tempVar = msgBufPtr[MESSAGE_BUFFER_CS_WORD_NUM];
    tempVar &= ~(MESSAGE_BUFFER_CS_DLC_MASK);
    tempVar |= ((length << MESSAGE_BUFFER_CS_DLC_SHIFT) & MESSAGE_BUFFER_CS_DLC_MASK);
    msgBufPtr[MESSAGE_BUFFER_CS_WORD_NUM] = tempVar;
    
    /* set remote response code (CODE = 0b1010) */
    *msgBufPtr |= (((uint32_t)0x0AUL) << FLEXCANDRV_MSG_BUF_CODE_SHIFT);
    
    /* add data field address offset (2 * 32 bit) */
    msgBufPtr += 2;
    /* load the data into message buffer */
    uint8_t i = 0;
    for (i = 0; i < length; i++)
    {
        /* load the data in byte length */
        if ((i % 4) == 0)
        {
            /* clean the old data */
            *msgBufPtr = 0;
            /* lowest byte in 32-bit */
            *msgBufPtr |= (((uint32_t)data[i]) << 24);
        }
        else if ((i % 4) == 1)
        {
            /* 2nd byte in 32-bit */
            *msgBufPtr |= (((uint32_t)data[i]) << 16);
        }
        else if ((i % 4) == 2)
        {
            /* 3rd byte in 32-bit */
            *msgBufPtr |= (((uint32_t)data[i]) << 8);
        }
        else if ((i % 4) == 3)
        {
            /* highest byte in 32-bit */
            *msgBufPtr |= ((uint32_t)data[i]);
            /* increment the 32-bit data pointer  */
            msgBufPtr++;
        }
    }
}
