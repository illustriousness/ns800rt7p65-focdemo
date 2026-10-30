/**
  * @file       system_NS800RT7xxx.c
  * @author     yangjun
  * @brief      System Init and Core Clock Frequency.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "system_NS800RT7xxx.h"

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define  SYSTEM_CLOCK    HXTL_FREQ_VALUE

/*----------------------------------------------------------------------------
  Define Vector 
 *----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
  Vector Table space in DTCM 
 *----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
  System Core Clock Variable
 *----------------------------------------------------------------------------*/
/* System Core Clock ---div--> Advanced High-performance Bus Clock
                     ---div--> Advanced High-performance Bus X Clock
                             & Advanced Peripheral Bus X Clock
                             & Module Clock */
volatile uint32_t CPUCLKClock      = SYSTEM_CLOCK;    /* CPUCLK Clock Frequency */
volatile uint32_t SystemCoreClock  = SYSTEM_CLOCK;    /* System Core Clock Frequency */
volatile uint32_t HCLKClock        = SYSTEM_CLOCK;    /* Advanced High-performance Bus Clock Frequency */
volatile uint32_t PCLK1Clock       = SYSTEM_CLOCK;    /* Advanced Peripheral Bus 1,3,6 Clock Frequency */
volatile uint32_t PCLK2Clock       = SYSTEM_CLOCK;    /* Advanced Peripheral Bus 2,4 Clock Frequency */
volatile uint32_t PCLK5Clock       = SYSTEM_CLOCK;    /* Advanced Peripheral Bus 5 Clock Frequency */
volatile uint32_t TraceClock       = SYSTEM_CLOCK;    /* Trace Clock Frequency */
volatile uint32_t FlashClock       = SYSTEM_CLOCK;    /* Flash Clock Frequency */
volatile uint32_t EPWMClock        = SYSTEM_CLOCK;    /* EPWM Clock Frequency */

/*----------------------------------------------------------------------------
  Clock Functions
 *----------------------------------------------------------------------------*/
/**
 * @brief   Setup the microcontroller system
 */
void SystemInit (void) {
    /************************************** SCB register start **************************************/
//    SCB_EnableICache();
//    SCB_EnableDCache();
    SCB->CACR |= SCB_CACR_FORCEWT_Msk;
    /* Enable CP10/CP11 Full Access */
    SCB->CPACR |= ((3U << 10U*2U) | (3U << 11U*2U));
    
    /* Determine whether the program is currently running on CPU1 or CPU2. */
    if((MCM->CPUID.WORDVAL & 0x01) == 0x01)
    {
        /* Set the base address of interrupt vector table */
        SCB->VTOR = 0x08000000;
    /*************************************** SCB register end ***************************************/

    /************************************** system clock start **************************************/
        RCC->UNLOCK.WORDVAL = 0x55AA6699;
        /* Enable MIRC2 & Check MIRC2 is ready */
        RCC->CR.BIT.MIRC2EN = 1;
        while (!RCC->CR.BIT.MIRC2RDY) {;}
        /* Set MIRC2 as system clock */
        RCC->CFGR.BIT.SWSEL = 0;
        /* Lock rcc register */
        RCC->UNLOCK.WORDVAL = 0x55AA6698;
    /*************************************** system clock end ***************************************/
    }
    else
    {
        /* Set the base address of interrupt vector table */
        SCB->VTOR = 0x08080000;
    }
}

/**
 * @brief   Update SystemCoreClock variable
 */
void SystemCoreClockUpdate (void)
{
    CPUCLKClock     = RCC_getCpuclkFrequency();
    SystemCoreClock = CPUCLKClock;
    HCLKClock       = RCC_getHclkFrequency();
    PCLK1Clock      = RCC_getPclk1Frequency();
    PCLK2Clock      = RCC_getPclk2Frequency();
    PCLK5Clock      = RCC_getPclk5Frequency();
    TraceClock      = RCC_getTraceClockFrequency();
    FlashClock      = RCC_getFlashClockFrequency();
    EPWMClock       = RCC_getEpwmFrequency();
}

#if 0
/**
 * @brief  Delay us function constructed using systick
 * @param  us  the us time value you want to delay
 */
__attribute__ ((section (".itcm") )) void Delay_us(uint32_t us)
{
    uint32_t ticks;
    uint32_t told, tnow, tcnt = 0;
    uint32_t reload;
    reload = SysTick->LOAD; 
    ticks = (reload+1) * us; 
    told = SysTick->VAL; 

    while(1)
    {
        tnow = SysTick->VAL;

        if (tnow != told)
        {
            if (tnow < told)
            {
                tcnt += told - tnow;    /*  */
            }
            else
            {
                tcnt += reload - tnow + told;
            }

            told = tnow;

            if (tcnt >= ticks) break;   /*  */
        }
    }
}

/**
 * @brief  Delay ms function constructed using systick
 * @param  ms  the ms time value you want to delay
 */
__attribute__ ((section (".itcm") )) void Delay_ms(uint32_t ms)
{
    if (ms == 0)
    {
        return;
    }

    while(ms--)
    {
        Delay_us(1000);
    }
}
#endif
