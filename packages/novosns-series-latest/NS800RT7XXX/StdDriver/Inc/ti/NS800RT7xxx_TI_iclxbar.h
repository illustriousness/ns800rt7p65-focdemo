/**
  * @file       NS800RT7xxx_TI_iclxbar.h
  * @author     wuxiao
  * @brief      Header file for NS800RT7xxx iclxbar module(TI).
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __NS800RT7XXX_TI_ICLXBAR_H__
#define __NS800RT7XXX_TI_ICLXBAR_H__


#ifdef __cplusplus
extern "C" {
#endif


#if defined (NS800RT7P65X)
  #include "NS800RT7P65x.h"
#endif


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* The following are defines for the XBAR register offsets */
#define XBAR_O_ICL1SELECT         (0x00UL)    /* ICL1SELECT Input Select Register */
#define XBAR_O_ICL2SELECT         (0x04UL)    /* ICL2SELECT Input Select Register */
#define XBAR_O_ICL3SELECT         (0x08UL)    /* ICL3SELECT Input Select Register */
#define XBAR_O_ICL4SELECT         (0x0CUL)    /* ICL4SELECT Input Select Register */
#define XBAR_O_ICL5SELECT         (0x10UL)    /* ICL5SELECT Input Select Register */
#define XBAR_O_ICL6SELECT         (0x14UL)    /* ICL6SELECT Input Select Register */
#define XBAR_O_ICL7SELECT         (0x18UL)    /* ICL7SELECT Input Select Register */
#define XBAR_O_ICL8SELECT         (0x1CUL)    /* ICL8SELECT Input Select Register */
#define XBAR_O_ICL9SELECT         (0x20UL)    /* ICL9SELECT Input Select Register */
#define XBAR_O_ICL10SELECT        (0x24UL)    /* ICL10SELECT Input Select Register */
#define XBAR_O_ICL11SELECT        (0x28UL)    /* ICL11SELECT Input Select Register */
#define XBAR_O_ICL12SELECT        (0x2CUL)    /* ICL12SELECT Input Select Register */
#define XBAR_O_ICL13SELECT        (0x30UL)    /* ICL13SELECT Input Select Register */
#define XBAR_O_ICL14SELECT        (0x34UL)    /* ICL14SELECT Input Select Register */
#define XBAR_O_ICL15SELECT        (0x38UL)    /* ICL15SELECT Input Select Register */
#define XBAR_O_ICL16SELECT        (0x3CUL)    /* ICL16SELECT Input Select Register */
#define XBAR_O_INPUTSELECTLOCK    (0x40UL)    /* Input Select Lock Register */

/* The following are defines for the bit fields in the INPUTSELECTLOCK register */
#define XBAR_INPUTSELECTLOCK_ICL1SELECT     (0x1UL)       /*  Lock bit for ICL1SELECT Register */
#define XBAR_INPUTSELECTLOCK_ICL2SELECT     (0x2UL)       /*  Lock bit for ICL2SELECT Register */
#define XBAR_INPUTSELECTLOCK_ICL3SELECT     (0x4UL)       /*  Lock bit for ICL3SELECT Register */
#define XBAR_INPUTSELECTLOCK_ICL4SELECT     (0x8UL)       /*  Lock bit for ICL4SELECT Register */
#define XBAR_INPUTSELECTLOCK_ICL5SELECT     (0x10UL)      /*  Lock bit for ICL5SELECT Register */
#define XBAR_INPUTSELECTLOCK_ICL6SELECT     (0x20UL)      /*  Lock bit for ICL6SELECT Register */
#define XBAR_INPUTSELECTLOCK_ICL7SELECT     (0x40UL)      /*  Lock bit for ICL7SELECT Register */
#define XBAR_INPUTSELECTLOCK_ICL8SELECT     (0x80UL)      /*  Lock bit for ICL8SELECT Register */
#define XBAR_INPUTSELECTLOCK_ICL9SELECT     (0x100UL)     /*  Lock bit for ICL9SELECT Register */
#define XBAR_INPUTSELECTLOCK_ICL10SELECT    (0x200UL)     /*  Lock bit for ICL10SELECT Register */
#define XBAR_INPUTSELECTLOCK_ICL11SELECT    (0x400UL)     /*  Lock bit for ICL11SELECT Register */
#define XBAR_INPUTSELECTLOCK_ICL12SELECT    (0x800UL)     /*  Lock bit for ICL12SELECT Register */
#define XBAR_INPUTSELECTLOCK_ICL13SELECT    (0x1000UL)    /*  Lock bit for ICL13SELECT Register */
#define XBAR_INPUTSELECTLOCK_ICL14SELECT    (0x2000UL)    /*  Lock bit for ICL14SELECT Register */
#define XBAR_INPUTSELECTLOCK_ICL15SELECT    (0x4000UL)    /*  Lock bit for ICL15SELECT Register */
#define XBAR_INPUTSELECTLOCK_ICL16SELECT    (0x8000UL)    /*  Lock bit for ICL16SELECT Register */


#ifdef __cplusplus
}
#endif


#endif  /* __NS800RT7XXX_TI_ICLXBAR_H__ */
