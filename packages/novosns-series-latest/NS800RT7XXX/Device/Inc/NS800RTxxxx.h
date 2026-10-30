/**
  * @file       NS800RTxxxx.h
  * @author     AE-Team
  * @brief      Header file of all chips.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */

#ifndef __NS800RTXXXX_H__
#define __NS800RTXXXX_H__


#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>


//****************************************************************************
//                             Exported macro
//****************************************************************************
#define SET_BIT(REG, BIT)                      ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)                    ((REG) &= ~((uint32_t)BIT))
#define EXTRA_BIT(REG, BIT)                    ((REG) &= (BIT))
#define REV_BIT(REG, BIT)                      ((REG) ^= (BIT))
#define READ_BIT(REG, BIT)                     ((REG) & (BIT))
#define CLEAR_REG(REG)                         ((REG) = (0x0))
#define WRITE_REG(REG, VAL)                    ((REG) = (VAL))
#define READ_REG(REG)                          ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)    WRITE_REG((REG), (((READ_REG(REG)) & (~((uint32_t)CLEARMASK))) | (SETMASK)))

#define TYPE8(addr)                            (*((volatile uint8_t *) (addr)))
#define TYPE16(addr)                           (*((volatile uint16_t *) (addr)))
#define TYPE32(addr)                           (*((volatile uint32_t *) (addr)))

#define MIN(a, b)                              ((a) > (b) ? (b) : (a))

enum logicVal {
    DISABLE = 0U,
    ENABLE
};


/* ########################## Oscillator Values adaptation #################### */
/**
  * @{
  * @brief Adjust the value of High-speed external oscillator (HXTL) used in your
  *        application. This value is used by the RCC module to compute the system
  *        frequency.
  *        (when HXTL is used as system clock source, directly or through the PLL).
  */
#define HXTL_FREQ_VALUE     (20000000UL)    /*!< High-speed external OSC frequency */
#define MIRC1_FREQ_VALUE    (10000000UL)    /*!< Medium speed internal RC OSC 1 frequency */
#define MIRC2_FREQ_VALUE    (10000000UL)    /*!< Medium speed internal RC OSC 2 frequency */
#define LIRC_FREQ_VALUE     (128000UL)      /*!< Low-speed internal RC OSC frequency */

/**
  * @}
  */

/* ########################################################################### */

static inline void nop_delay_asm(uint32_t count) {
    __asm volatile(
      "1: \n"
      "  nop           \n"
      "  subs %0, %0, #1 \n"
      "  bne 1b        \n"
      : "+r" (count)
      :
      : "cc"
    );
}


//****************************************************************************
//                             Exported include
//****************************************************************************
#if defined (NS800RT737X)
  #include "NS800RT737x.h"
#elif defined (NS800RT7P65X)
  #include "NS800RT7P65x.h"
#elif defined (NS800RT507X)
  #include "NS800RT507x.h"
#else
  #error "Please select first the target NS800RTxxxx device used in your application (in NS800RTxxxx.h file)"
#endif

#if defined (NS800RT737X) || defined (NS800RT7P65X) || defined (NS800RT507X)
  #include "version.h"
  #include "interrupt.h"
  #include "adc.h"
  #include "aeshash.h"
  #include "anass.h"
  #include "awk.h"
  #include "bgcrc.h"
  #include "btim.h"
  #include "clb.h"
  #include "cmpss.h"
  #include "crc.h"
  #include "dac.h"
  #include "dcc.h"
  #include "debug.h"
  #include "dmamux.h"
  #include "ecap.h"
  #include "edma.h"
  #include "emath.h"
  #include "epwm.h"
  #include "eqep.h"
  #include "exti.h"
  #include "flash.h"
  #include "flexcan.h"
  #include "fmu.h"
  #include "gpio.h"
  #include "i2c.h"
  #include "iwdg1.h"
  #include "iwdg2.h"
  #include "lptim.h"
  #include "mmath.h"
  #include "mcm.h"
  #include "pwr.h"
  #include "qspi.h"
  #include "rcc.h"
  #include "sdfm.h"
  #include "smpu.h"
  #include "spi.h"
  #include "sram.h"
  #include "stim.h"
  #include "syscon.h"
  #include "tim.h"
  #include "trng.h"
  #include "uart.h"
  #include "wwdg.h"
  #include "xbar.h"
#ifndef NS800RT507X
  #include "epg.h"
  #include "sema.h"
  #include "mu.h"
  #include "upp.h"
  #include "lin.h"
  #include "pmbus.h"
#endif  // NS800RT507X does not have LIN and PMBUS Module.

#else
  #error "Please select first the target NS800RTxxxx device used in your application (in NS800RTxxxx.h file)"
#endif


#endif /* __NS800RTXXXX_H__ */
