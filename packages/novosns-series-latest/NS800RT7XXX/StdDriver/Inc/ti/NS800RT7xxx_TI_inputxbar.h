/**
  * @file       NS800RT7xxx_TI_inputxbar.h
  * @author     wuxiao
  * @brief      Header file for NS800RT7xxx inputxbar module(TI).
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __NS800RT7XXX_TI_INPUTXBAR_H__
#define __NS800RT7XXX_TI_INPUTXBAR_H__


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
#define XBAR_O_INPUT1SELECT       (0x0UL)     /* INPUT1 Input Select Register (GPIO0 to x) */ 
#define XBAR_O_INPUT2SELECT       (0x4UL)     /* INPUT2 Input Select Register (GPIO0 to x) */ 
#define XBAR_O_INPUT3SELECT       (0x8UL)     /* INPUT3 Input Select Register (GPIO0 to x) */ 
#define XBAR_O_INPUT4SELECT       (0xCUL)     /* INPUT4 Input Select Register (GPIO0 to x) */ 
#define XBAR_O_INPUT5SELECT       (0x10UL)    /* INPUT5 Input Select Register (GPIO0 to x) */ 
#define XBAR_O_INPUT6SELECT       (0x14UL)    /* INPUT6 Input Select Register (GPIO0 to x) */ 
#define XBAR_O_INPUT7SELECT       (0x18UL)    /* INPUT7 Input Select Register (GPIO0 to x) */ 
#define XBAR_O_INPUT8SELECT       (0x1CUL)    /* INPUT8 Input Select Register (GPIO0 to x) */ 
#define XBAR_O_INPUT9SELECT       (0x20UL)    /* INPUT9 Input Select Register (GPIO0 to x) */ 
#define XBAR_O_INPUT10SELECT      (0x24UL)    /* INPUT10 Input Select Register (GPIO0 to x) */ 
#define XBAR_O_INPUT11SELECT      (0x28UL)    /* INPUT11 Input Select Register (GPIO0 to x) */ 
#define XBAR_O_INPUT12SELECT      (0x2CUL)    /* INPUT12 Input Select Register (GPIO0 to x) */ 
#define XBAR_O_INPUT13SELECT      (0x30UL)    /* INPUT13 Input Select Register (GPIO0 to x) */ 
#define XBAR_O_INPUT14SELECT      (0x34UL)    /* INPUT14 Input Select Register (GPIO0 to x) */ 
#define XBAR_O_INPUT15SELECT      (0x38UL)    /* INPUT15 Input Select Register (GPIO0 to x) */ 
#define XBAR_O_INPUT16SELECT      (0x3CUL)    /* INPUT16 Input Select Register (GPIO0 to x) */ 
#define XBAR_O_INPUTSELECTLOCK    (0x40UL)    /* Input Select Lock Register */ 

/* The following are defines for the bit fields in the INPUTSELECTLOCK register */
#define XBAR_INPUTSELECTLOCK_INPUT1SELECT     (0x1UL)       /* Lock bit for INPUT1SELECT Register */ 
#define XBAR_INPUTSELECTLOCK_INPUT2SELECT     (0x2UL)       /* Lock bit for INPUT2SELECT Register */ 
#define XBAR_INPUTSELECTLOCK_INPUT3SELECT     (0x4UL)       /* Lock bit for INPUT3SELECT Register */ 
#define XBAR_INPUTSELECTLOCK_INPUT4SELECT     (0x8UL)       /* Lock bit for INPUT4SELECT Register */ 
#define XBAR_INPUTSELECTLOCK_INPUT5SELECT     (0x10UL)      /* Lock bit for INPUT5SELECT Register */ 
#define XBAR_INPUTSELECTLOCK_INPUT6SELECT     (0x20UL)      /* Lock bit for INPUT6SELECT Register */ 
#define XBAR_INPUTSELECTLOCK_INPUT7SELECT     (0x40UL)      /* Lock bit for INPUT7SELECT Register */ 
#define XBAR_INPUTSELECTLOCK_INPUT8SELECT     (0x80UL)      /* Lock bit for INPUT8SELECT Register */ 
#define XBAR_INPUTSELECTLOCK_INPUT9SELECT     (0x100UL)     /* Lock bit for INPUT9SELECT Register */ 
#define XBAR_INPUTSELECTLOCK_INPUT10SELECT    (0x200UL)     /* Lock bit for INPUT10SELECT Register */ 
#define XBAR_INPUTSELECTLOCK_INPUT11SELECT    (0x400UL)     /* Lock bit for INPUT11SELECT Register */ 
#define XBAR_INPUTSELECTLOCK_INPUT12SELECT    (0x800UL)     /* Lock bit for INPUT12SELECT Register */ 
#define XBAR_INPUTSELECTLOCK_INPUT13SELECT    (0x1000UL)    /* Lock bit for INPUT13SELECT Register */ 
#define XBAR_INPUTSELECTLOCK_INPUT14SELECT    (0x2000UL)    /* Lock bit for INPUT14SELECT Register */ 
#define XBAR_INPUTSELECTLOCK_INPUT15SELECT    (0x4000UL)    /* Lock bit for INPUT15SELECT Register */ 
#define XBAR_INPUTSELECTLOCK_INPUT16SELECT    (0x8000UL)    /* Lock bit for INPUT16SELECT Register */ 


#ifdef __cplusplus
}
#endif


#endif  /* __NS800RT7XXX_TI_INPUTXBAR_H__ */
