/**
  * @file       system_NS800RT7xxx.h
  * @author     yangjun
  * @brief      the header file about 'system_NS800RT7xxx.c'.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __SYSTEM_NS800RT7XXX_H__
#define __SYSTEM_NS800RT7XXX_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/**
 * \brief   Clock Frequency (System/AHB/APB/Module Clock)
 */
extern volatile uint32_t CPUCLKClock;
extern volatile uint32_t SystemCoreClock;
extern volatile uint32_t HCLKClock;
extern volatile uint32_t PCLK1Clock;
extern volatile uint32_t PCLK2Clock;
extern volatile uint32_t PCLK5Clock;
extern volatile uint32_t TraceClock;
extern volatile uint32_t FlashClock;
extern volatile uint32_t EPWMClock;

/**
 * \brief   Setup the microcontroller system.
 * Initialize the System and update the SystemCoreClock variable.
 */
static inline void Systick_setInterrupt (uint8_t enable)
{
    MODIFY_REG(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk, (uint32_t)enable << SysTick_CTRL_TICKINT_Pos);
}

/**
 * \brief   Setup the microcontroller system.
 * Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit (void);

/**
 * \brief   Update SystemCoreClock variable.
 *  Updates the SystemCoreClock with current core Clock retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);

extern __attribute__ ((section (".itcm") )) void Delay_us(uint32_t us);

extern __attribute__ ((section (".itcm") )) void Delay_ms(uint32_t us);


#ifdef __cplusplus
}
#endif


#endif /* __SYSTEM_NS800RT7XXX_H__ */
