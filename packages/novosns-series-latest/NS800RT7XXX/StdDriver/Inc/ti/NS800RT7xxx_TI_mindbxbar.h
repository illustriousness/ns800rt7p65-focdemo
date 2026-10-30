/**
  * @file       NS800RT7xxx_TI_mindbxbar.h
  * @author     wuxiao
  * @brief      Header file for NS800RT7xxx mindbxbar module(TI).
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __NS800RT7XXX_TI_MINDBXBAR_H__
#define __NS800RT7XXX_TI_MINDBXBAR_H__


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
#define XBAR_O_MDL1SELECT         (0x0UL)     /*  MDL1SELECT Input Select Register */
#define XBAR_O_MDL2SELECT         (0x4UL)     /*  MDL2SELECT Input Select Register */
#define XBAR_O_MDL3SELECT         (0x8UL)     /*  MDL3SELECT Input Select Register */
#define XBAR_O_MDL4SELECT         (0xCUL)     /*  MDL4SELECT Input Select Register */
#define XBAR_O_MDL5SELECT         (0x10UL)    /*  MDL5SELECT Input Select Register */
#define XBAR_O_MDL6SELECT         (0x14UL)    /*  MDL6SELECT Input Select Register */
#define XBAR_O_MDL7SELECT         (0x18UL)    /*  MDL7SELECT Input Select Register */
#define XBAR_O_MDL8SELECT         (0x1CUL)    /*  MDL8SELECT Input Select Register */
#define XBAR_O_MDL9SELECT         (0x20UL)    /*  MDL9SELECT Input Select Register */
#define XBAR_O_MDL10SELECT        (0x24UL)    /*  MDL10SELECT Input Select Register */
#define XBAR_O_MDL11SELECT        (0x28UL)    /*  MDL11SELECT Input Select Register */
#define XBAR_O_MDL12SELECT        (0x2CUL)    /*  MDL12SELECT Input Select Register */
#define XBAR_O_MDL13SELECT        (0x30UL)    /*  MDL13SELECT Input Select Register */
#define XBAR_O_MDL14SELECT        (0x34UL)    /*  MDL14SELECT Input Select Register */
#define XBAR_O_MDL15SELECT        (0x38UL)    /*  MDL15SELECT Input Select Register */
#define XBAR_O_MDL16SELECT        (0x3CUL)    /*  MDL16SELECT Input Select Register */
#define XBAR_O_INPUTSELECTLOCK    (0x40UL)    /*  Input Select Lock Register */

/* The following are defines for the bit fields in the INPUTSELECTLOCK register */
#define XBAR_INPUTSELECTLOCK_MDL1SELECT     (0x1UL)      /* Lock bit for MDL1SELECT Register */
#define XBAR_INPUTSELECTLOCK_MDL2SELECT     (0x2UL)      /* Lock bit for MDL2SELECT Register */
#define XBAR_INPUTSELECTLOCK_MDL3SELECT     (0x4UL)      /* Lock bit for MDL3SELECT Register */
#define XBAR_INPUTSELECTLOCK_MDL4SELECT     (0x8UL)      /* Lock bit for MDL4SELECT Register */
#define XBAR_INPUTSELECTLOCK_MDL5SELECT     (0x10UL)     /* Lock bit for MDL5SELECT Register */
#define XBAR_INPUTSELECTLOCK_MDL6SELECT     (0x20UL)     /* Lock bit for MDL6SELECT Register */
#define XBAR_INPUTSELECTLOCK_MDL7SELECT     (0x40UL)     /* Lock bit for MDL7SELECT Register */
#define XBAR_INPUTSELECTLOCK_MDL8SELECT     (0x80UL)     /* Lock bit for MDL8SELECT Register */
#define XBAR_INPUTSELECTLOCK_MDL9SELECT     (0x100UL)    /* Lock bit for MDL9SELECT Register */
#define XBAR_INPUTSELECTLOCK_MDL10SELECT    (0x200UL)    /* Lock bit for MDL10SELECT Register */
#define XBAR_INPUTSELECTLOCK_MDL11SELECT    (0x400UL)    /* Lock bit for MDL11SELECT Register */
#define XBAR_INPUTSELECTLOCK_MDL12SELECT    (0x800UL)    /* Lock bit for MDL12SELECT Register */
#define XBAR_INPUTSELECTLOCK_MDL13SELECT    (0x1000UL)   /* Lock bit for MDL13SELECT Register */
#define XBAR_INPUTSELECTLOCK_MDL14SELECT    (0x2000UL)   /* Lock bit for MDL14SELECT Register */
#define XBAR_INPUTSELECTLOCK_MDL15SELECT    (0x4000UL)   /* Lock bit for MDL15SELECT Register */
#define XBAR_INPUTSELECTLOCK_MDL16SELECT    (0x8000UL)   /* Lock bit for MDL16SELECT Register */


#ifdef __cplusplus
}
#endif


#endif  /* __NS800RT7XXX_TI_MINDBXBAR_H__ */
