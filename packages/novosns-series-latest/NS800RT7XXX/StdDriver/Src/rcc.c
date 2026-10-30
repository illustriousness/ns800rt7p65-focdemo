/**
  * @file       rcc.c
  * @author     bilang.xiong
  * @brief      Function file for NS800RT7xxx rcc module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "rcc.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/** @defgroup RCC_Private_Constants RCC Private Constants
  * @{
  * @brief  This macro defines the RCC wait timeout and the oscillator frequency.
  */

/** @defgroup RCC_OVERTIME RCC Private Over Time Constants
  * @{
  * @brief  This macro defines the timeout value for operations, ensuring that
  *         the system does not wait indefinitely.
  *         The value can be adjusted based on specific requirements.
  */
#define MIRC1_READY_TIME    (500UL)        /*!< MIRC1 Ready Time */
#define MIRC2_READY_TIME    (500UL)        /*!< MIRC2 Ready Time */
#define LIRC_READY_TIME     (500000UL)     /*!< LIRC Ready Time */
#define HXTL_READY_TIME     (5000000UL)    /*!< HXTL Ready Time */
#define PLL_READY_TIME      (65535UL)            /*!< PLL Ready Time */
#define SYSCLK_SW_TIME      (5000UL)       /*!< System Clock Switch Time */

/**
  * @}
  */

/** @defgroup RCC_FREQUENCY RCC Private Frequency Constants
  * @{
  * @brief  This macro defines the value of the oscillator in Hz.
  */
#define HXTL_FREQ     HXTL_FREQ_VALUE     /*!< Frequency of HXTL in Hz */
#define MIRC1_FREQ    MIRC1_FREQ_VALUE    /*!< Frequency of MIRC1 in Hz */
#define MIRC2_FREQ    MIRC2_FREQ_VALUE    /*!< Frequency of MIRC2 in Hz */

/**
  * @}
  */

/**
  * @}
  */

/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Functions
 ******************************************************************************/

/**
 * @brief  Get the PLL Clock Frequency.
 * @note   This function determines the current PLL clock frequency based on the clock source
 *         and PLL configuration. It reads the software clock switch status and calculates the
 *         frequency accordingly.
 * @return Returns the pll clock frequency in Hz.
 *          - HXTL_FREQ: If the system clock source is HXTL.
 *          - MIRC1_FREQ: If the system clock source is MIRC1.
 *          - MIRC2_FREQ: If the system clock source is MIRC2.
 *          - Calculated frequency: If the system clock source is PLL, 
 *            based on PLLM, PLLN, PLLP, and PLL source.
 */
static uint32_t RCC_getPllFrequency (void)
{
    uint32_t pllFreq = 0;

    switch (RCC_readPllClockSource())
    {
        case 0:
            pllFreq = MIRC2_FREQ;
            break;
        case 1:
            pllFreq = HXTL_FREQ;
            break;
        default:
            pllFreq = MIRC1_FREQ;
            break;
    }
    pllFreq = pllFreq * (RCC_readPllmValue()) / (RCC_readPllnValue() + 1) / ((RCC_readPllpValue() + 1) << 1);

    return pllFreq;
}

/**
 * @brief  Get the System Clock Frequency.
 * @note   This function determines the current system clock frequency based on the clock source
 *         and PLL configuration. It reads the software clock switch status and calculates the
 *         frequency accordingly.
 * @return Returns the system clock frequency in Hz.
 *          - HXTL_FREQ: If the system clock source is HXTL.
 *          - MIRC1_FREQ: If the system clock source is MIRC1.
 *          - MIRC2_FREQ: If the system clock source is MIRC2.
 *          - Calculated frequency: If the system clock source is PLL, 
 *            based on PLLM, PLLN, PLLP, and PLL source.
 */
uint32_t RCC_getSysClockFrequency (void)
{
    uint32_t sysClockFreq = 0;

    switch (RCC_readSysClkSwitchStatus())
    {
        case 0:
            sysClockFreq = MIRC2_FREQ;
            break;
        /* system clock source is HXTL */
        case 1:
            sysClockFreq = HXTL_FREQ;
            break;
        /* system clock source is PLL */
        case 2:
            sysClockFreq = RCC_getPllFrequency();
            break;
        /* system clock source is MIRC1 */
        case 3:
            sysClockFreq = MIRC1_FREQ;
            break;
        /* Register not supported, return max value is error */
        default:
            sysClockFreq = 0xFFFFFFFF;
            break;
    }

    return sysClockFreq;
}

/**
 * \brief  Get the CPU Clock Source Frequency.
 * \note   This function determines the current CPU clock Source frequency
 * \return Returns the CPU Source clock frequency in Hz.
 */
uint32_t RCC_getCpuclkFrequency (void)
{
    return (RCC_getSysClockFrequency() >> (uint16_t)RCC_getSysClkDiv());
}

/**
 * \brief  Get the HCLK (AHB) Clock Frequency.
 * \note   This function determines the current HCLK (AHB) clock frequency based on the system clock frequency
 *         and the AHB prescaler. It reads the system clock frequency and divides it by the AHB prescaler value.
 * \return Returns the HCLK (AHB) clock frequency in Hz.
 */
uint32_t RCC_getHclkFrequency (void)
{
    return (RCC_getCpuclkFrequency() >> ((uint16_t)RCC_getHclkClkSelecton()));
}

/**
 * @brief  Get the PCLK1 (APB1) Clock Frequency.
 * @note   This function determines the current PCLK1 (APB1) clock frequency based on the HCLK (AHB) clock frequency
 *         and the APB1 prescaler. It reads the HCLK frequency and divides it by the APB1 prescaler value.
 * @return Returns the PCLK1 (APB1) clock frequency in Hz.
 */
uint32_t RCC_getPclk1Frequency (void)
{
    return (RCC_getHclkFrequency() >> ((uint16_t)RCC_getApb1ClkDiv()));
}

/**
 * @brief  Get the PCLK2 (APB2,4) Clock Frequency.
 * @note   This function determines the current PCLK2 (APB2,4) clock frequency based on the HCLK (AHB) 
 *         clock frequency and the APB2,4 prescaler. It reads the HCLK frequency and divides it 
 *         by the APB2,4 prescaler value.
 * @return Returns the PCLK2 (APB2,4) clock frequency in Hz.
 */
uint32_t RCC_getPclk2Frequency (void)
{
    return (RCC_getHclkFrequency() >> ((uint16_t)RCC_getApb2ClkDiv()));
}

/**
 * @brief  Get the PCLK5 (APB5) Clock Frequency.
 * @note   This function determines the current PCLK5 (APB5) clock frequency based on the HCLK (AHB) clock frequency
 *         and the APB5 prescaler. It reads the HCLK frequency and divides it by the APB5 prescaler value.
 * @return Returns the PCLK5 (APB5) clock frequency in Hz.
 */
uint32_t RCC_getPclk5Frequency (void)
{
    return (RCC_getHclkFrequency() >> ((uint16_t)RCC_getApb5ClkDiv()));
}

/**
 * @brief  Get the EPWM Clock Frequency.
 * @note   This function determines the current EPWM clock frequency based on the HCLK Source clock frequency
 *         and the EPWMCLKDIV prescaler. It reads the HCLK Source frequency and divides it by the HCLK Source prescaler value.
 * @return Returns the EPWM clock frequency in Hz.
 */
uint32_t RCC_getEpwmFrequency (void)
{
    return (RCC_getPclk1Frequency() >> (READ_BIT(RCC->CFGR2.WORDVAL, RCC_CFGR2_EPWMCLKDIV_M) >> 12));
}

/**
 * @brief  Get the Trace Clock Frequency.
 * @note   This function determines the current Trace clock frequency based on the HCLK (AHB) clock frequency
 *         and the Trace prescaler. It reads the HCLK frequency and divides it by the Trace prescaler value.
 * @return Returns the Trace clock frequency in Hz.
 */
uint32_t RCC_getTraceClockFrequency (void)
{
    return (RCC_getHclkFrequency() >> ((uint16_t)RCC_getTraceClockDiv()));
}

/**
 * @brief  Get the Flash Clock Frequency.
 * @note   This function determines the current Flash clock frequency based on the HCLK (AHB) clock frequency
 *         and the Flash prescaler. It reads the HCLK frequency and divides it by the Flash prescaler value.
 * @return Returns the Flash clock frequency in Hz.
 */
uint32_t RCC_getFlashClockFrequency (void)
{
    return (RCC_getHclkFrequency() >> ((uint16_t)RCC_getFlashClockDiv()));
}

/**
 * @brief  Sets the trace clock division.
 * @note   Before switching the clock, make sure the trace clock division is correct.
 * @param  freq  Specifies the system clock frequency.
 */
static void RCC_setTraceClockDiv (uint32_t freq)
{
    RCC_TraceClockDivSelection div = RCC_TRACE_DIV_1;

    while((freq > 100000000UL) && (++div <= RCC_TRACE_DIV_16))
    {
        freq = (freq >> div);
    }

    RCC_selectTraceClockDiv(div);
}

/**
 * @brief  Sets the flash clock division.
 * @note   Before switching the clock, make sure the flash clock division is correct.
 * @param  freq  Specifies the system clock frequency.
 */
static void RCC_setFlashClockDiv (uint32_t freq)
{
    uint32_t div=0,latency=0;

    if(freq <= 30000000)
    {
        latency = 0;
    }
    if((freq > 30000000) && (freq <= 60000000))
    {
        latency = 1;
    }
    else if((freq > 60000000) && (freq <= 90000000))
    {
        latency = 2;
    }
    else if((freq > 90000000) && (freq <= 120000000))
    {
        latency = 3;
    }
    else if((freq > 120000000) && (freq <= 150000000))
    {
        latency = 4;
    }
    else if((freq > 150000000) && (freq <= 180000000))
    {
        div = 1;
        latency = 2;
    }
    else if((freq > 180000000) && (freq <= 240000000))
    {
        div = 1;
        latency = 3;
    }
    else if((freq > 240000000) && (freq <= 300000000))
    {
        div = 1;
        latency = 4;
    }
    else if((freq > 300000000) && (freq <= 360000000))
    {
        div = 2;
        latency = 2;
    }
    else if((freq > 360000000) && (freq <= 480000000))
    {
        div = 2;
        latency = 3;
    }
    if(div != 0)
    {
        RCC->CFGR2.BIT.FLASHDIV = div;
    }
    FLASH->ACR.BIT.LATENCY = latency;
}


/**
 * @brief  Configures the system clock source and related clock dividers.
 * @note   Before switching the clock, ensure that the clock source is enabled and ready.
 * @param  sysClockConfig    Specifies the system clock source.
 *                            This parameter can be any value of @ref RCC_SYSCLKSRC
 * @return Returns 0 if the clock configuration is successful, otherwise returns 1.
 */
uint32_t RCC_setClock (RCC_SysclkSrc sysClockConfig)
{
    uint32_t wait_time = SYSCLK_SW_TIME;
    uint32_t curClkFreq = MIRC2_FREQ;
    uint32_t status    = 1;
    uint32_t clockstatus;

    RCC_unlockRccRegister();

    clockstatus = RCC_readSysClkSwitchStatus();

    switch (sysClockConfig)
    {
        case RCC_SYSCLKSOURCE_HXTL:
            if (RCC_readHxtlRdyFlag())
            {
                /* configure HXTL as the system clock source */
                RCC_selectSystemClock(RCC_SYSCLKSOURCE_HXTL);
                while ((RCC_readSysClkSwitchStatus() != RCC_SYSCLKSTATUS_HXTL) && (--wait_time))
                    ;
                curClkFreq = HXTL_FREQ;
            }
            break;

        case RCC_SYSCLKSOURCE_PLL:
            if (RCC_readPllLockFlag())
            {
                /* get the current pll frequency */
                uint32_t frequency = RCC_getPllFrequency();
                /* configure trace clock div according to pll frequency */
                RCC_setTraceClockDiv(frequency);
                /* configure flash clock div according to pll frequency */
                RCC_setFlashClockDiv(frequency);
                /* configure PLL as the system clock source */
                RCC_selectSystemClock(RCC_SYSCLKSOURCE_PLL);

                while ((RCC_readSysClkSwitchStatus() != RCC_SYSCLKSTATUS_PLL) && (--wait_time))
                    ;
            }
            break;

        case RCC_SYSCLKSOURCE_MIRC1:
            if (RCC_readMirc1RdyFlag())
            {
                RCC_selectSystemClock(RCC_SYSCLKSOURCE_MIRC1);
                while ((RCC_readSysClkSwitchStatus() != RCC_SYSCLKSTATUS_MIRC1) && (--wait_time))
                    ;

                curClkFreq = MIRC1_FREQ;
            }
            break;

        default:
            if (RCC_readMirc2RdyFlag())
            {
                RCC_selectSystemClock(RCC_SYSCLKSOURCE_MIRC2);
                while ((RCC_readSysClkSwitchStatus() != RCC_SYSCLKSTATUS_MIRC2) && (--wait_time))
                    ;

                curClkFreq = MIRC2_FREQ;
            }
            break;
    }

    if (wait_time)
    {
        if (sysClockConfig != RCC_SYSCLKSOURCE_PLL)
        {
            /* configure trace clock div according to pll frequency */
            RCC_setTraceClockDiv(curClkFreq);
            /* configure flash clock div according to pll frequency */
            RCC_setFlashClockDiv(curClkFreq);
        }

        status = 0;
    }
    else
    {
        RCC_selectSystemClock((RCC_SysclkSrc)(clockstatus));
    }

    RCC_lockRccRegister();

    return status;
}

/**
 * @brief  Configures the clock division settings for the Microcontroller Clock Output (MCO).
 * @param  config    Configuration value for clock division settings.
 *                    This parameter can be value of @ref CLOCKDIVCONFIG
 */
void RCC_configClockDiv (uint32_t config , uint32_t config2)
{
    RCC_unlockRccRegister();
    MODIFY_REG(RCC->CFGR.WORDVAL, 0xFFFFFF00U, config);
    MODIFY_REG(RCC->CFGR2.WORDVAL, 0x1777U, config2);
    RCC_lockRccRegister();
}

/**
 * @brief  Configures the Microcontroller Clock Output 1 (MCO1) settings.
 *
 * @param  mcoSource      Specifies the source for the MCO output.
 *                         This parameter can be any value of @ref RCC_MCOSOURCESEL
 * @param  mcoDiv         Specifies the divider for the MCO output.
 *                         This parameter can be any value of @ref RCC_MCODIVSEL
 * @param  mcoStatus      Specifies whether to enable or disable the MCO output.
 *                         This parameter can be any value of @ref RCC_FUNON
 */
void RCC_configMco1 (RCC_McoSourceSel mcoSource, RCC_McoDivSel mcoDiv, RCC_FunOn mcoEnable)
{
    RCC_unlockRccRegister();
    MODIFY_REG(RCC->MCOCR.WORDVAL, RCC_MCOCR_MCO1DIV_M | RCC_MCOCR_MCO1SRC_M | RCC_MCOCR_MCO1EN_M,
                ((uint32_t)mcoSource << RCC_MCOCR_MCO1SRC_S) | ((uint32_t)mcoDiv << RCC_MCOCR_MCO1DIV_S) |
                    ((uint32_t)mcoEnable << RCC_MCOCR_MCO1EN_S));
    RCC_lockRccRegister();
}

/**
 * @brief  Configures the Microcontroller Clock Output 2 (MCO2) settings.
 *
 * @param  mcoSource      Specifies the source for the MCO output.
 *                         This parameter can be any value of @ref RCC_MCOSOURCESEL
 * @param  mcoDiv         Specifies the divider for the MCO output.
 *                         This parameter can be any value of @ref RCC_MCODIVSEL
 * @param  mcoStatus      Specifies whether to enable or disable the MCO output.
 *                         This parameter can be any value of @ref RCC_FUNON
 */
void RCC_configMco2 (RCC_McoSourceSel mcoSource, RCC_McoDivSel mcoDiv, RCC_FunOn mcoEnable)
{
    RCC_unlockRccRegister();
    MODIFY_REG(RCC->MCOCR.WORDVAL, RCC_MCOCR_MCO2DIV_M | RCC_MCOCR_MCO2SRC_M | RCC_MCOCR_MCO2EN_M,
                ((uint32_t)mcoSource << RCC_MCOCR_MCO2SRC_S) | ((uint32_t)mcoDiv << RCC_MCOCR_MCO2DIV_S) |
                    ((uint32_t)mcoEnable << RCC_MCOCR_MCO2EN_S));
    RCC_lockRccRegister();
}

/**
 * @brief  Set the RCC interrupt enable.
 * 
 * @param  intSource  Specifies the interrupt source to configure.
 *                     This parameter can be any combination of values from @ref RCC_IERMASKS
 *                       RCC_IER_MIRC2RDY_M
 *                       RCC_IER_MIRC1RDY_M
 *                       RCC_IER_LIRCRDY_M
 *                       RCC_IER_HXTLFAULT_M
 *                       RCC_IER_HXTLRDY_M
 *                       RCC_IER_HXTLFAIL_M
 *                       RCC_IER_PLLLOCK_M
 *                       RCC_IER_PLLLOSE_M
 *                       RCC_IER_OSCCLKFAULT_M
 *                       RCC_IER_OSCCLKSTOP_M
 */
void RCC_setInterruptEnable (uint32_t intSource)
{
    RCC_unlockRccRegister();

    SET_BIT(RCC->IER.WORDVAL, intSource);

    RCC_lockRccRegister();
}

/**
 * @brief  Clear the RCC interrupt enable.
 * 
 * @param  intSource  Specifies the interrupt source to configure.
 *                     This parameter can be any combination of values from @ref RCC_IERMASKS
 *                       RCC_IER_MIRC2RDY_M
 *                       RCC_IER_MIRC1RDY_M
 *                       RCC_IER_LIRCRDY_M
 *                       RCC_IER_HXTLFAULT_M
 *                       RCC_IER_HXTLRDY_M
 *                       RCC_IER_HXTLFAIL_M
 *                       RCC_IER_PLLLOCK_M
 *                       RCC_IER_PLLLOSE_M
 *                       RCC_IER_OSCCLKFAULT_M
 *                       RCC_IER_OSCCLKSTOP_M
 */
void RCC_clearInterruptEnable (uint32_t intSource)
{
    RCC_unlockRccRegister();

    CLEAR_BIT(RCC->IER.WORDVAL, intSource);

    RCC_lockRccRegister();
}

/**
 * @brief  Clear the specified RCC interrupt flag.
 * @note   This function clears the specified interrupt flag based on the provided interrupt source.
 * 
 * @param  intSource    Specifies the interrupt source whose flag is to be cleared.
 *                       This parameter can be any combination of values from \e RCC_IntSourceSelection
 *                         RCC_CLR_MIRC2RDY_M
 *                         RCC_CLR_MIRC1RDY_M
 *                         RCC_CLR_LIRCRDY_M
 *                         RCC_CLR_HXTLRDY_M
 *                         RCC_CLR_HXTLFAIL_M
 *                         RCC_CLR_PLLLOCK_M
 *                         RCC_CLR_PLLLOSE_M
 *                         RCC_CLR_OSCCLKSTOP_M
 */
void RCC_clearInterruptFlag (uint32_t intSource)
{
    RCC_unlockRccRegister();
    SET_BIT(RCC->CLR.WORDVAL, intSource);
    RCC_lockRccRegister();
}

/**
 * @brief  Enables the MIRC2 oscillator and waits for it to be ready.
 * @note   This function enables the MIRC2 oscillator and waits for it to become ready.
 * 
 * @return Returns 0 if the MIRC2 oscillator is successfully enabled and ready, otherwise returns 1.
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
uint32_t RCC_enableMirc2Oscillator (void)
{
    uint32_t status = 1;
    uint32_t wait_time = MIRC2_READY_TIME;

    /* Enable MIRC2 */
    RCC_enableMirc2();

    while ((RCC_readMirc2RdyFlag() != 1) && (--wait_time));
    if (wait_time)
    {
        status = 0;
    }

    return status;
}

/**
 * @brief  Enables the MIRC1 oscillator and waits for it to be ready.
 * @note   This function enables the MIRC1 oscillator and waits for it to become ready.
 * 
 * @return Returns 0 if the MIRC1 oscillator is successfully enabled and ready, otherwise returns 1.
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
uint32_t RCC_enableMirc1Oscillator (void)
{
    uint32_t status = 1;
    uint32_t wait_time = MIRC1_READY_TIME;

    /* Enable MIRC1 */
    RCC_enableMirc1();

    while ((RCC_readMirc1RdyFlag() != 1) && (--wait_time));
    if (wait_time)
    {
        status = 0;
    }

    return status;
}

/**
 * @brief  Enables the LIRC oscillator and waits for it to be ready.
 * @note   This function enables the LIRC oscillator and waits for it to become ready.
 * 
 * @return Returns 0 if the LIRC oscillator is successfully enabled and ready, otherwise returns 1.
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
uint32_t RCC_enableLircOscillator (void)
{
    uint32_t status = 1;
    uint32_t wait_time = LIRC_READY_TIME;

    /* Enable LIRC */
    RCC_enableLirc();

    while ((RCC_readLircRdyFlag() != 1) && (--wait_time));
    if (wait_time)
    {
        status = 0;
    }

    return status;
}

/**
 * @brief  Disables the MIRC2 oscillator and waits for it to be disabled.
 * @note   This function disables the MIRC2 oscillator and waits until it is fully disabled.
 * 
 * @return Returns 0 if the MIRC2 oscillator is successfully disabled, otherwise returns 1.
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
uint32_t RCC_disableMirc2Oscillator (void)
{
    uint32_t status = 1;
    uint32_t wait_time = MIRC2_READY_TIME;

    /* Disable MIRC2 */
    RCC_disableMirc2();

    while ((RCC_readMirc2RdyFlag() != 0) && (--wait_time));
    if (wait_time)
    {
        status = 0;
    }

    return status;
}

/**
 * @brief  Disables the MIRC1 oscillator and waits for it to be disabled.
 * @note   This function disables the MIRC1 oscillator and waits until it is fully disabled.
 * 
 * @return Returns 0 if the MIRC1 oscillator is successfully disabled, otherwise returns 1.
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
uint32_t RCC_disableMirc1Oscillator (void)
{
    uint32_t status = 1;
    uint32_t wait_time = MIRC1_READY_TIME;

    /* Disable MIRC1 */
    RCC_disableMirc1();

    while ((RCC_readMirc1RdyFlag() != 0) && (--wait_time));
    if (wait_time)
    {
        status = 0;
    }

    return status;
}

/**
 * @brief  Disables the LIRC oscillator and waits for it to be disabled.
 * @note   This function disables the LIRC oscillator and waits until it is fully disabled.
 * 
 * @return Returns 0 if the LIRC oscillator is successfully disabled, otherwise returns 1.
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
uint32_t RCC_disableLircOscillator (void)
{
    uint32_t status = 1;
    uint32_t wait_time = LIRC_READY_TIME;

    /* Disable LIRC */
    RCC_disableLirc();

    while ((RCC_readLircRdyFlag() != 0) && (--wait_time));
    if (wait_time)
    {
        status = 0;
    }

    return status;
}

/**
 * @brief  Configure the PLL with the specified settings.
 * @note   This function configures the PLL based on the provided configuration parameters.
 * @param  pllConfig       Specifies the PLL configuration settings.
 *                          This parameter can include values from @ref PLLCONFIG
 * @param  pllExtConfig    Specifies the PLL configuration settings.
 *                          This parameter can include values from @ref PLLEXTCONFIG
 * @param  pllStatus       Specifies whether to enable or disable the PLL.
 *                          This parameter can be any value of @ref RCC_FUNON
 * @return Returns 0 if the pll configuration is successful, otherwise returns 1.
 */
uint32_t RCC_configPll (uint32_t pllConfig, uint32_t pllExtConfig, RCC_FunOn pllStatus)
{
    uint32_t pllm, plln, pllp, pllq, pllr, pllsource, pll_forcelk, pll_lkdt;
    uint32_t wait_time = PLL_READY_TIME;
    uint32_t status = 1;

    RCC_unlockRccRegister();

    if (RCC_readSysClkSwitchStatus() == RCC_SYSCLKSTATUS_PLL)
    {
        if (RCC_enableMirc2Oscillator() == 0)
        {
            if ((RCC_enableMirc2Oscillator() == 0) && (RCC_setClock(RCC_SYSCLKSOURCE_MIRC2) == 0))
            {
                RCC_unlockRccRegister();
                RCC_disablePll();
                while ((RCC_readPllLockFlag() != 0) && (--wait_time));
            }
        }
    }
    else
    {
        RCC_disablePll();
        while ((RCC_readPllLockFlag() != 0) && (--wait_time));
    }

    if ((wait_time != 0) && (pllStatus == RCC_FUN_ON))
    {
        /* Extract PLLM, PLLN and PLLQ values from pllConfig */
        pllm = (pllConfig >> 8) & 0xFFUL;
        plln = (pllConfig >> 4) & 0xFUL;
        pllp = (pllConfig >> 17) & 0x1FUL;
        /* Extract PLLQ and PLLR values from pllExtConfig */
        pllq = (pllExtConfig >> 27) & 0x1FUL;
        pllr = (pllExtConfig >> 22) & 0x1FUL;
        pllsource = (pllConfig) & 0x3UL;
        /* Extract Force Lock Detection and Lock Deviation values from pllExtConfig */
        pll_forcelk = (pllExtConfig >> 18) & 0x1UL;
        pll_lkdt = (pllExtConfig >> 16) & 0x3UL;

        /* Configure PLLM and PLLN */
        MODIFY_REG(RCC->PLLCR1.WORDVAL, RCC_PLLCR1_PLLM_M | RCC_PLLCR1_PLLN_M,
                   (pllm << RCC_PLLCR1_PLLM_S) | (plln << RCC_PLLCR1_PLLN_S));

        /* Configure PLLP and enable its clock output */
        MODIFY_REG(RCC->PLLCR2.WORDVAL,
                   RCC_PLLCR2_PDIV_M | RCC_PLLCR2_PEN_M | RCC_PLLCR2_QDIV_M | RCC_PLLCR2_QEN_M | RCC_PLLCR2_RDIV_M |
                       RCC_PLLCR2_REN_M,
                   (pllp << RCC_PLLCR2_PDIV_S) | (ENABLE << RCC_PLLCR2_PEN_S) | (pllq << RCC_PLLCR2_QDIV_S) |
                       (ENABLE << RCC_PLLCR2_QEN_S) | (pllr << RCC_PLLCR2_RDIV_S) | (ENABLE << RCC_PLLCR2_REN_S));

        /* configure PLL icp, filter and vcorng */
        WRITE_REG(RCC->PLLCR4.WORDVAL, ((pllExtConfig & 0xFFFFUL) | RCC_PLLCR4_KEY));

        /* Configure PLL source */
        MODIFY_REG(RCC->PLLCR.WORDVAL, RCC_PLLCR_SRC_M, pllsource);

        /* Configure Force Lock Detection and Lock Deviation */
        MODIFY_REG(RCC->PLLCR3.WORDVAL, RCC_PLLCR3_FORCELKEN_M | RCC_PLLCR3_PLLLKDTSET_M,
                   (pll_lkdt << RCC_PLLCR3_PLLLKDTSET_S) | (pll_forcelk << RCC_PLLCR3_FORCELKEN_S));

        RCC_enablePll();
        wait_time = PLL_READY_TIME;
        while ((RCC_readPllLockFlag() != 1) && (--wait_time));
        if (wait_time == 0)
        {
            status = 1;
        }  
    }

    RCC_selectHclkClkSource(RCC_HCLKSOURCE_CPUCLK_2);

    RCC_lockRccRegister();

    return status;
}

/**
 * @brief  Configure the High-Speed External Crystal Oscillator (HXTL) settings.
 * @note   This function configures the HXTL based on the provided configuration parameters.
 *         It ensures that the system clock is not using HXTL before disabling it and re-enabling it with new settings.
 * @param  config        Specifies the configuration settings for the HXTL.
 *                        This parameter is a combination of values from @ref HXTLCONFIG
 * @param  hxtlBypass    Specifies whether to enable or disable the HXTL bypass mode.
 *                        This parameter can be one of the values from @ref RCC_HXTLBYPASSSEL
 * @param  hxtlSts       Specifies whether to enable or disable the HXTL.
 *                        This parameter can be ENABLE or DISABLE from @ref RCC_FUNON
 * @return Returns 0 if the hxtl configuration is successful, otherwise returns 1.
 */
uint32_t RCC_configHxtl (uint32_t config, RCC_HxtlBypassSel hxtlBypass, RCC_FunOn hxtlSts)
{
    uint32_t wait_time = HXTL_READY_TIME;
    uint32_t status;

    RCC_unlockRccRegister();

    status = 1;

    if ((RCC_readSysClkSwitchStatus() != RCC_SYSCLKSTATUS_MIRC2) || (RCC_readPllClockSource() != RCC_PLLSOURCE_MIRC2))
    {
        if ((RCC_enableMirc2Oscillator() == 0) && (RCC_setClock(RCC_SYSCLKSOURCE_MIRC2) == 0))
        {
            RCC_unlockRccRegister();
            RCC_disableHxtl();

            while ((RCC_readHxtlRdyFlag() != 0) && (--wait_time))
                ;
        }
    }
    else
    {
        RCC_disableHxtl();

        while ((RCC_readHxtlRdyFlag() != 0) && (--wait_time));
    }

    if ((wait_time != 0) && (hxtlSts == RCC_FUN_ON))
    {
        /* Configure HXTL */
        WRITE_REG(RCC->HXTLCR.WORDVAL, (config | RCC_HXTLCR_KEY));

        RCC_enableHxtl();
        MODIFY_REG(RCC->CR.WORDVAL, RCC_CR_HXTLBYP_M, hxtlBypass << 18);

        wait_time = HXTL_READY_TIME;
        while ((RCC_readHxtlRdyFlag() != 1) && (--wait_time));
        if (wait_time == 0)
        {
            status = 1;
        }
    }

    RCC_lockRccRegister();

    return status;
}

/**
 * @brief  Reset the specified AHB1 peripheral(s).
 * @note   This function resets one or more AHB1 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB1 peripheral reset request.
 * 
 * @param  peripheral    Specifies the AHB1 peripheral(s) to be reset.
 *                        This parameter is a combination of values from @ref RCC_AHBRST1MASKS
 */
void RCC_resetAhb1Peripheral (uint32_t peripheral)
{
    RCC_unlockRccRegister();
    SET_BIT(RCC->AHBRST1.WORDVAL, peripheral);
    __NOP();__NOP();__NOP();
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, peripheral);
    RCC_lockRccRegister();
}

/**
 * @brief  Reset the specified AHB2 peripheral(s).
 * @note   This function resets one or more AHB2 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB2 peripheral reset request.
 * 
 * @param  peripheral    Specifies the AHB2 peripheral(s) to be reset.
 *                        This parameter is a combination of values from @ref RCC_AHBRST2MASKS
 */
void RCC_resetAhb2Peripheral (uint32_t peripheral)
{
    RCC_unlockRccRegister();
    SET_BIT(RCC->AHBRST2.WORDVAL, peripheral);
    __NOP();__NOP();__NOP();
    CLEAR_BIT(RCC->AHBRST2.WORDVAL, peripheral);
    RCC_lockRccRegister();
}

/**
 * @brief  Reset the specified APB1 peripheral(s).
 * @note   This function resets one or more APB1 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB1 peripheral reset request.
 * 
 * @param  peripheral    Specifies the APB1 peripheral(s) to be reset.
 *                        This parameter is a combination of values from @ref RCC_APBRST1MASKS
 */
void RCC_resetApb1Peripheral (uint32_t peripheral)
{
    RCC_unlockRccRegister();
    SET_BIT(RCC->APBRST1.WORDVAL, peripheral);
    __NOP();__NOP();__NOP();
    CLEAR_BIT(RCC->APBRST1.WORDVAL, peripheral);
    RCC_lockRccRegister();
}

/**
 * @brief  Reset the specified APB2 peripheral(s).
 * @note   This function resets one or more APB2 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB2 peripheral reset request.
 * 
 * @param  peripheral    Specifies the APB2 peripheral(s) to be reset.
 *                        This parameter is a combination of values from @ref RCC_APBRST2MASKS
 */
void RCC_resetApb2Peripheral (uint32_t peripheral)
{
    RCC_unlockRccRegister();
    SET_BIT(RCC->APBRST2.WORDVAL, peripheral);
    __NOP();__NOP();__NOP();
    CLEAR_BIT(RCC->APBRST2.WORDVAL, peripheral);
    RCC_lockRccRegister();
}

/**
 * @brief  Reset the specified APB3 peripheral(s).
 * @note   This function resets one or more APB3 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB3 peripheral reset request.
 * 
 * @param  peripheral    Specifies the APB3 peripheral(s) to be reset.
 *                        This parameter is a combination of values from @ref RCC_APBRST3MASKS
 */
void RCC_resetApb3Peripheral (uint32_t peripheral)
{
    RCC_unlockRccRegister();
    SET_BIT(RCC->APBRST3.WORDVAL, peripheral);
    __NOP();__NOP();__NOP();
    CLEAR_BIT(RCC->APBRST3.WORDVAL, peripheral);
    RCC_lockRccRegister();
}

/**
 * @brief  Reset the specified APB5 peripheral(s).
 * @note   This function resets one or more APB5 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB5 peripheral reset request.
 * 
 * @param  peripheral    Specifies the APB5 peripheral(s) to be reset.
 *                        This parameter is a combination of values from @ref RCC_APBRST5MASKS
 */
void RCC_resetApb5Peripheral (uint32_t peripheral)
{
    RCC_unlockRccRegister();
    SET_BIT(RCC->APBRST5.WORDVAL, peripheral);
    __NOP();__NOP();__NOP();
    CLEAR_BIT(RCC->APBRST5.WORDVAL, peripheral);
    RCC_lockRccRegister();
}

/**
 * @brief  Reset the specified APB6 peripheral(s).
 * @note   This function resets one or more APB6 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB5 peripheral reset request.
 * 
 * @param  peripheral    Specifies the APB6 peripheral(s) to be reset.
 *                        This parameter is a combination of values from @ref RCC_APBRST6MASKS
 */
void RCC_resetApb6Peripheral (uint32_t peripheral)
{
    RCC_unlockRccRegister();
    SET_BIT(RCC->APBRST6.WORDVAL, peripheral);
    __NOP();__NOP();__NOP();
    CLEAR_BIT(RCC->APBRST6.WORDVAL, peripheral);
    RCC_lockRccRegister();
}

/**
 * @brief  Reset the specified APB8 peripheral(s).
 * @note   This function resets one or more APB5 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB5 peripheral reset request.
 * 
 * @param  peripheral    Specifies the APB8 peripheral(s) to be reset.
 *                        This parameter is a combination of values from @ref RCC_APBRST8MASKS
 */
void RCC_resetApb8Peripheral (uint32_t peripheral)
{
    RCC_unlockRccRegister();
    SET_BIT(RCC->APBRST8.WORDVAL, peripheral);
    __NOP();__NOP();__NOP();
    CLEAR_BIT(RCC->APBRST8.WORDVAL, peripheral);
    RCC_lockRccRegister();
}

/**
 * @brief  Enable the specified AHB1 peripheral(s) clock.
 * @note   This function enables the clock for one or more AHB1 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB1 peripheral clock enable request.
 *  
 * @param  peripheral    Specifies the AHB1 peripheral(s) clock to be enabled.
 *                        This parameter is a combination of values from @ref RCC_HCLKEN1MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_enableAhb1PeripheralClock (uint32_t peripheral)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, peripheral);
}

/**
 * @brief  Enable the specified AHB2 peripheral(s) clock.
 * @note   This function enables the clock for one or more AHB2 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB2 peripheral clock enable request.
 * 
 * @param  peripheral    Specifies the AHB2 peripheral(s) clock to be enabled.
 *                        This parameter is a combination of values from @ref RCC_HCLKEN2MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_enableAhb2PeripheralClock (uint32_t peripheral)
{
    SET_BIT(RCC->HCLKEN2.WORDVAL, peripheral);
}

/**
 * @brief  Enable the specified APB1 peripheral(s) clock.
 * @note   This function enables the clock for one or more APB1 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB1 peripheral clock enable request.
 * 
 * @param  peripheral    Specifies the APB1 peripheral(s) clock to be enabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN1MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_enableApb1PeripheralClock (uint32_t peripheral)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, peripheral);
}

/**
 * @brief  Enable the specified APB2 peripheral(s) clock.
 * @note   This function enables the clock for one or more APB2 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB2 peripheral clock enable request.
 * 
 * @param  peripheral    Specifies the APB2 peripheral(s) clock to be enabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN2MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_enableApb2PeripheralClock (uint32_t peripheral)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, peripheral);
}

/**
 * @brief  Enable the specified APB3 peripheral(s) clock.
 * @note   This function enables the clock for one or more APB3 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB3 peripheral clock enable request.
 * 
 * @param  peripheral    Specifies the APB3 peripheral(s) clock to be enabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN3MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_enableApb3PeripheralClock (uint32_t peripheral)
{
    SET_BIT(RCC->PCLKEN3.WORDVAL, peripheral);
}

/**
 * @brief  Enable the specified APB5 peripheral(s) clock.
 * @note   This function enables the clock for one or more APB5 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB5 peripheral clock enable request.
 * 
 * @param  peripheral    Specifies the APB5 peripheral(s) clock to be enabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN5MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_enableApb5PeripheralClock (uint32_t peripheral)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, peripheral);
}

/**
 * @brief  Enable the specified APB6 peripheral(s) clock.
 * @note   This function enables the clock for one or more APB6 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB6 peripheral clock enable request.
 * 
 * @param  peripheral    Specifies the APB6 peripheral(s) clock to be enabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN6MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_enableApb6PeripheralClock (uint32_t peripheral)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, peripheral);
}

/**
 * @brief  Enable the specified APB8 peripheral(s) clock.
 * @note   This function enables the clock for one or more APB8 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB8 peripheral clock enable request.
 * 
 * @param  peripheral    Specifies the APB8 peripheral(s) clock to be enabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN8MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_enableApb8PeripheralClock (uint32_t peripheral)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, peripheral);
}

/**
 * @brief  Disable the specified AHB1 peripheral(s) clock.
 * @note   This function disables the clock for one or more AHB1 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB1 peripheral clock disable request.
 * 
 * @param  peripheral    Specifies the AHB1 peripheral(s) clock to be disabled.
 *                        This parameter is a combination of values from @ref RCC_HCLKEN1MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_disableAhb1PeripheralClock (uint32_t peripheral)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, peripheral);
}

/**
 * @brief  Disable the specified AHB2 peripheral(s) clock.
 * @note   This function disables the clock for one or more AHB2 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB2 peripheral clock disable request.
 * 
 * @param  peripheral    Specifies the AHB2 peripheral(s) clock to be disabled.
 *                        This parameter is a combination of values from @ref RCC_HCLKEN2MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_disableAhb2PeripheralClock (uint32_t peripheral)
{
    CLEAR_BIT(RCC->HCLKEN2.WORDVAL, peripheral);
}

/**
 * @brief  Disable the specified APB1 peripheral(s) clock.
 * @note   This function disables the clock for one or more APB1 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB1 peripheral clock disable request.
 * 
 * @param  peripheral    Specifies the APB1 peripheral(s) clock to be disabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN1MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_disableApb1PeripheralClock (uint32_t peripheral)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, peripheral);
}

/**
 * @brief  Disable the specified APB2 peripheral(s) clock.
 * @note   This function disables the clock for one or more APB2 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB2 peripheral clock disable request.
 * 
 * @param  peripheral    Specifies the APB2 peripheral(s) clock to be disabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN2MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_disableApb2PeripheralClock (uint32_t peripheral)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, peripheral);
}

/**
 * @brief  Disable the specified APB3 peripheral(s) clock.
 * @note   This function disables the clock for one or more APB3 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB3 peripheral clock disable request.
 * 
 * @param  peripheral    Specifies the APB3 peripheral(s) clock to be disabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN3MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_disableApb3PeripheralClock (uint32_t peripheral)
{
    CLEAR_BIT(RCC->PCLKEN3.WORDVAL, peripheral);
}

/**
 * @brief  Disable the specified APB5 peripheral(s) clock.
 * @note   This function disables the clock for one or more APB5 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB5 peripheral clock disable request.
 * 
 * @param  peripheral    Specifies the APB5 peripheral(s) clock to be disabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN5MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_disableApb5PeripheralClock (uint32_t peripheral)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, peripheral);
}

/**
 * @brief  Disable the specified APB6 peripheral(s) clock.
 * @note   This function disables the clock for one or more APB6 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB6 peripheral clock disable request.
 * 
 * @param  peripheral    Specifies the APB6 peripheral(s) clock to be disabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN6MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_disableApb6PeripheralClock (uint32_t peripheral)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, peripheral);
}

/**
 * @brief  Disable the specified APB8 peripheral(s) clock.
 * @note   This function disables the clock for one or more APB8 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB8 peripheral clock disable request.
 * 
 * @param  peripheral    Specifies the APB8 peripheral(s) clock to be disabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN8MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_disableApb8PeripheralClock (uint32_t peripheral)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, peripheral);
}

/**
 * @brief  Enable the specified AHB1 peripheral(s) clock in sleep mode.
 * @note   This function enables the clock for one or more AHB1 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB1 peripheral clock enable request in sleep mode.
 * 
 * @param  peripheral    Specifies the AHB1 peripheral(s) clock to be enabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_HCLKLPEN1MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_enableAhb1PeripheralClockInSleepMode (uint32_t peripheral)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, peripheral);
}

/**
 * @brief  Enable the specified AHB2 peripheral(s) clock in sleep mode.
 * @note   This function enables the clock for one or more AHB2 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB2 peripheral clock enable request in sleep mode.
 * 
 * @param  peripheral    Specifies the AHB2 peripheral(s) clock to be enabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_HCLKLPEN2MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_enableAhb2PeripheralClockInSleepMode (uint32_t peripheral)
{
    SET_BIT(RCC->HCLKLPEN2.WORDVAL, peripheral);
}

/**
 * @brief  Enable the specified APB1 peripheral(s) clock in sleep mode.
 * @note   This function enables the clock for one or more APB1 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB1 peripheral clock enable request in sleep mode.
 * 
 * @param  peripheral    Specifies the APB1 peripheral(s) clock to be enabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN1MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_enableApb1PeripheralClockInSleepMode (uint32_t peripheral)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, peripheral);
}

/**
 * @brief  Enable the specified APB2 peripheral(s) clock in sleep mode.
 * @note   This function enables the clock for one or more APB2 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB2 peripheral clock enable request in sleep mode.
 * 
 * @param  peripheral    Specifies the APB2 peripheral(s) clock to be enabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN2MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_enableApb2PeripheralClockInSleepMode (uint32_t peripheral)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, peripheral);
}

/**
 * @brief  Enable the specified APB3 peripheral(s) clock in sleep mode.
 * @note   This function enables the clock for one or more APB3 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB3 peripheral clock enable request in sleep mode.
 * 
 * @param  peripheral    Specifies the APB3 peripheral(s) clock to be enabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN3MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_enableApb3PeripheralClockInSleepMode (uint32_t peripheral)
{
    SET_BIT(RCC->PCLKLPEN3.WORDVAL, peripheral);
}

/**
 * @brief  Enable the specified APB5 peripheral(s) clock in sleep mode.
 * @note   This function enables the clock for one or more APB5 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB5 peripheral clock enable request in sleep mode.
 * 
 * @param  peripheral    Specifies the APB5 peripheral(s) clock to be enabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN5MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_enableApb5PeripheralClockInSleepMode (uint32_t peripheral)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, peripheral);
}

/**
 * @brief  Enable the specified APB6 peripheral(s) clock in sleep mode.
 * @note   This function enables the clock for one or more APB6 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB6 peripheral clock enable request in sleep mode.
 * 
 * @param  peripheral    Specifies the APB6 peripheral(s) clock to be enabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN6MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_enableApb6PeripheralClockInSleepMode (uint32_t peripheral)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, peripheral);
}

/**
 * @brief  Enable the specified APB8 peripheral(s) clock in sleep mode.
 * @note   This function enables the clock for one or more APB8 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB8 peripheral clock enable request in sleep mode.
 * 
 * @param  peripheral    Specifies the APB8 peripheral(s) clock to be enabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN8MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_enableApb8PeripheralClockInSleepMode (uint32_t peripheral)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, peripheral);
}

/**
 * @brief  Disable the specified AHB1 peripheral(s) clock in sleep mode.
 * @note   This function disables the clock for one or more AHB1 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB1 peripheral clock disable request in sleep mode.
 * 
 * @param  peripheral    Specifies the AHB1 peripheral(s) clock to be disabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_HCLKLPEN1MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_disableAhb1PeripheralClockInSleepMode (uint32_t peripheral)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, peripheral);
}

/**
 * @brief  Disable the specified AHB2 peripheral(s) clock in sleep mode.
 * @note   This function disables the clock for one or more AHB2 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB2 peripheral clock disable request in sleep mode.
 * 
 * @param  peripheral    Specifies the AHB2 peripheral(s) clock to be disabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_HCLKLPEN2MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_disableAhb2PeripheralClockInSleepMode (uint32_t peripheral)
{
    CLEAR_BIT(RCC->HCLKLPEN2.WORDVAL, peripheral);
}

/**
 * @brief  Disable the specified APB1 peripheral(s) clock in sleep mode.
 * @note   This function disables the clock for one or more APB1 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB1 peripheral clock disable request in sleep mode.
 * 
 * @param  peripheral    Specifies the APB1 peripheral(s) clock to be disabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN1MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_disableApb1PeripheralClockInSleepMode (uint32_t peripheral)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, peripheral);
}

/**
 * @brief  Disable the specified APB2 peripheral(s) clock in sleep mode.
 * @note   This function disables the clock for one or more APB2 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB2 peripheral clock disable request in sleep mode.
 * 
 * @param  peripheral    Specifies the APB2 peripheral(s) clock to be disabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN2MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_disableApb2PeripheralClockInSleepMode (uint32_t peripheral)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, peripheral);
}

/**
 * @brief  Disable the specified APB3 peripheral(s) clock in sleep mode.
 * @note   This function disables the clock for one or more APB3 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB3 peripheral clock disable request in sleep mode.
 * 
 * @param  peripheral    Specifies the APB3 peripheral(s) clock to be disabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN3MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_disableApb3PeripheralClockInSleepMode (uint32_t peripheral)
{
    CLEAR_BIT(RCC->PCLKLPEN3.WORDVAL, peripheral);
}

/**
 * @brief  Disable the specified APB5 peripheral(s) clock in sleep mode.
 * @note   This function disables the clock for one or more APB5 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB5 peripheral clock disable request in sleep mode.
 * 
 * @param  peripheral    Specifies the APB5 peripheral(s) clock to be disabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN5MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_disableApb5PeripheralClockInSleepMode (uint32_t peripheral)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, peripheral);
}

/**
 * @brief  Disable the specified APB6 peripheral(s) clock in sleep mode.
 * @note   This function disables the clock for one or more APB6 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB6 peripheral clock disable request in sleep mode.
 * 
 * @param  peripheral    Specifies the APB6 peripheral(s) clock to be disabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN6MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_disableApb6PeripheralClockInSleepMode (uint32_t peripheral)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, peripheral);
}

/**
 * @brief  Disable the specified APB8 peripheral(s) clock in sleep mode.
 * @note   This function disables the clock for one or more APB8 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB8 peripheral clock disable request in sleep mode.
 * 
 * @param  peripheral    Specifies the APB8 peripheral(s) clock to be disabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN8MASKS
 * 
 * @attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
 */
void RCC_disableApb8PeripheralClockInSleepMode (uint32_t peripheral)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, peripheral);
}

/**
 * @brief  Configure the MIRC2 Oscillator Stop Detection.
 * @note   This function configures the MIRC2 oscillator stop detection based on the provided status.
 * 
 * @param  config    Specifies the configuration settings for the MIRC2.
 *                    This parameter is a combination of values from @ref RCC_MIRC1MIRC2CYCSELECTION
 * @param  mcdSts    Specifies the enable or disable status of the MCD (Main Clock Divider).
 *                    This parameter can be any value of @ref RCC_FUNON
 */
void RCC_configMcd (RCC_McdMircCycleSelection config, RCC_FunOn mcdSts)
{
    RCC_unlockRccRegister();

    if (mcdSts == RCC_FUN_ON)
    {
        RCC_selectMcdMircCycle((RCC_McdMircCycleSelection)(config));
        RCC_enableMcd();
    }
    else
    {
        RCC_disableMcd();
    }

    RCC_lockRccRegister();
}

/**
 * @brief  Clear the RCC reset flag.
 * @note   This function clears the chip reset flag in the RCC register.
 *         It first unlocks the RCC register, clears the reset flag, and then locks the RCC register
 *         to prevent accidental changes.
 */
void RCC_clearRccFlag (void)
{
    RCC_unlockRccRegister();
    RCC_clearResetFlags();
    RCC_lockRccRegister();
}
