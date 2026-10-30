/**
  * @file       NS800RT7xxx_TI_clb.h
  * @author     Favian
  * @brief      Header file for NS800RT7xxx clb module(TI).
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __NS800RT7XXX_TI_CLB_H__
#define __NS800RT7XXX_TI_CLB_H__


#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define CLB_configSPIBufferLoadSignal    CLB_configDataFIFOLoadSignal
#define CLB_configSPIBufferShift         CLB_configDataFIFOLoadShift
#define CLB_disableSPIBufferAccess       CLB_disableDataFIFOAccess
#define CLB_enableSPIBufferAccess        CLB_enableDataFIFOAccess


#ifdef __cplusplus
}
#endif


#endif /* __NS800RT7XXX_TI_CLB_H__ */
