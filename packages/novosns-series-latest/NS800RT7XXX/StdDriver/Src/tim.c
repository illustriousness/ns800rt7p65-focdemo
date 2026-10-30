/**
  * @file       tim.c
  * @author     Haven-X
  * @brief      Function file for NS800RT7xxx tim module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "tim.h"


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
  * @brief  Configure the TIMx time base unit.
  * @param  tim           TIMx pointer to a TIM_TypeDef structure
  *                        - TIM1: TIM1 base address index
  *                        - TIM2: TIM2 base address index
  * @param  prescaler     The prescaler value used to divide the TIMx clock
  *                        This parameter can be a number between Min_Data=0x0000 and Max_Data=0xFFFF.
  *                        This feature can be modified afterwards using function @ref TIM_setPrescaler().
  * @param  autoReload    The auto reload value to be loaded into the ARR Register at the next update event
  *                        This parameter can be a number between Min_Data=0x0000 and Max_Data=0xFFFF.
  *                        This feature can be modified afterwards using unitary function @ref TIM_setAutoReload().
  * @param  configure     Configurable combination
  *                        All parameters can be or together, and the parameters include the following sections:
  *                        @ref TIM_PWMMODE, Specifies the PWM comparison mode, choosing single-point comparison or 
  *                             double-point comparison. 
  *                             This feature can be modified afterwards using unitary function
  *                             @ref TIM_enablePwm2PointMode() or @ref TIM_disablePwm2PointMode()
  *                        @ref TIM_CLOCKDIVISION, Specifies the clock division.
  *                             This feature can be modified afterwards using unitary function @ref TIM_setClockDivision()
  *                        @ref TIM_AUTORELOADPRELOAD, Specifies whether to enable Auto-reload preload function.
  *                             This feature can be modified afterwards using unitary function 
  *                             @ref TIM_enableAutoReloadPreload() or @ref disableAutoReloadPreload()
  *                        @ref TIM_COUNTERMODE, Specifies the counting mode, which includes the counting direction 
  *                             and alignment mode. 
  *                             This feature can be modified afterwards using unitary function @ref TIM_setCounterMode()
  *                        @ref TIM_ONEPULSEMODE, Specifies single mode or repetitive mode.
  *                             This feature can be modified afterwards using unitary function @ref TIM_setOnePulseMode()
  * @note   In the end you need to call the TIM_enableCounter() function to start the TIM.
  * @note   When the value of the auto-reload is empty, the TIM does not work.
  */
void TIM_configTimeBase (TIM_TypeDef *tim, uint16_t prescaler, uint16_t autoReload, uint32_t configure)
{
    /* Config TIMx CR1 */
    MODIFY_REG(tim->CR1.WORDVAL, 
               TIM_CR1_PWMS_M  | TIM_CR1_CKD_M | TIM_CR1_ARPE_M | TIM_CR1_DIR_M | 
               TIM_CR1_CMS_M | TIM_CR1_OPM_M, 
               configure & 0x7F8);

    /* Set the Autoreload value */
    WRITE_REG(tim->ARR.WORDVAL, autoReload);

    /* Set the Prescaler value */
    WRITE_REG(tim->PSC.WORDVAL, prescaler);

    /* Generate an update event to reload the Prescaler */
    TIM_generateEvent(tim, TIM_EVENTSOURCE_UPDATE);

    /* Check if the update flag is set after the Update Generation, if so clear the UIF flag */
    if (TIM_getFlags(tim, TIM_FLAG_UPDATE))
    {
        /* Clear the update flag */
        TIM_clearFlags(tim, TIM_FLAG_UPDATE);
    }
}

/**
  * @brief  Configure the TIMx output channel.
  * @param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * @param  channel         TIMx Channel
  *                          This parameter can be any value of @ref TIM_CHANNEL
  * @param  compareValue    Combination compare values
  *                          The compare value of the channel is placed in the lower 16 bits, 
  *                          and if a two-point compare is required, the value of CCRxB is placed in the upper 16 bits.
  *                          eg: if compareValue = 0x5555AAAAU, means CCRxA = 0xAAAAU and CCRxB = 0x5555U.
  * @param  configure       Output configuration combination
  *                          All parameters can be or together, and the parameters include the following sections:
  *                          @ref TIM_OCMODE, Specifies the output mode.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setOcMode()
  *                          @ref TIM_OC_ACTIVE, Specifies the TIM Output Compare state.
  *                               This feature can be modified afterwards using unitary functions 
  *                               @ref TIM_enableChannel() or @ref TIM_disableChannel()
  *                          @ref TIM_OC_POLARITY, Specifies the output polarity.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setOcPolarity()
  *                          @ref TIM_OC_IDLESTATE, Specifies the TIM Output Compare pin state during Idle state.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setOcIdleState()
  * @note   Before this function is called, you need to use the TIM_configTimeBase() function to configure the basic 
  *         parameters of TIM, in the end you need to call the TIM_enableCounter() function to start the TIM.
  * @note   If you need to output PWM to the pins, you also need to use TIM_enableMainOutput().
  */
void TIM_configOutputChannel (TIM_TypeDef *tim, TIM_Channel channel, uint32_t compareValue, uint32_t configure)
{
    __IO uint32_t *pTmpReg;
    uint32_t channelShift = SHIFT_TAB_CCER[channel];
    uint32_t oisShift = (uint32_t)channel << 1UL;

    /* Disable the Channel 1: Reset the CC1E / CC1NE Bit */
    CLEAR_BIT(tim->CCER.WORDVAL, (TIM_CCER_CC1E_M | TIM_CCER_CC1NE_M) << channelShift);
    
    /* Set the Output Idle state, Set the complementary output Idle state */
    MODIFY_REG(tim->CR2.WORDVAL, 
               (TIM_CR2_OIS1_M | TIM_CR2_OIS1N_M) << oisShift, 
               (configure & (TIM_CR2_OIS1_M | TIM_CR2_OIS1N_M)) << oisShift);
    
    /* Get the TIMx CCMRx register address */
    pTmpReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    
    /* Reset Capture/Compare selection Bits */
    /* Set the Output Compare Mode */
    MODIFY_REG(*pTmpReg,
               (TIM_CCMR1_CC1S_M | TIM_CCMR1_OC1M_M) << SHIFT_TAB_CCMR[channel],
               (configure & TIM_CCMR1_OC1M_M) << SHIFT_TAB_CCMR[channel]);
    
    /* Get the TIMx CCRxA register address */
    pTmpReg = (__IO uint32_t *)((uint32_t)&tim->CCR1A.WORDVAL + channelShift);
    
    /* Set the TIMx CCRxA compare value */
    WRITE_REG(*pTmpReg, compareValue & 0xFFFFUL);
    
    /* Get the TIMx CCRxB register address */
    pTmpReg = (__IO uint32_t *)((uint32_t)&tim->CCR1B.WORDVAL + channelShift);
    
    /* Set the TIMx CCRxB compare value */
    WRITE_REG(*pTmpReg, (compareValue >> 16UL) & 0xFFFFUL);
    
    /* Set the Output Compare Polarity, Set the complementary output Polarity */
    /* Set the Output State, Set the complementary output State */
    MODIFY_REG(tim->CCER.WORDVAL, 
               (TIM_CCER_CC1P_M | TIM_CCER_CC1NP_M | TIM_CCER_CC1E_M | TIM_CCER_CC1NE_M) << channelShift, 
               (configure & (TIM_CCER_CC1P_M | TIM_CCER_CC1NP_M | TIM_CCER_CC1E_M | TIM_CCER_CC1NE_M)) << channelShift);
}

/**
  * @brief  Configure the TIMx input channel.
  * @param  tim           TIMx pointer to a TIM_TypeDef structure
  *                        - TIM1: TIM1 base address index
  *                        - TIM2: TIM2 base address index
  * @param  channel       TIMx Channel
  *                        This parameter can be any value of @ref TIM_CHANNEL
  * @param  configure     Input configuration combination
  *                        All parameters can be or together, and the parameters include the following sections:
  *                        @ref TIM_IC_ACTIVE, Specifies the input.
  *                             This feature can be modified afterwards using unitary function @ref TIM_setIcActiveInput()
  *                        @ref TIM_IC_PSC, Specifies the Input Capture Prescaler.
  *                             This feature can be modified afterwards using unitary function @ref TIM_setIcPrescaler()
  *                        @ref TIM_IC_FILTER, Specifies the input capture filter.
  *                             This feature can be modified afterwards using unitary function @ref TIM_setIcFilter()
  *                        @ref TIM_IC_POLARITY, Specifies the active edge of the input signal.
  *                             This feature can be modified afterwards using unitary function @ref TIM_setIcPolarity()
  * @note   Before this function is called, you need to use the TIM_configTimeBase() function to configure the basic 
  *         parameters of TIM, in the end you need to call the TIM_enableCounter() function to start the TIM.
  */
void TIM_configInputChannel (TIM_TypeDef *tim, TIM_Channel channel, uint32_t configure)
{
    __IO uint32_t *pTmpReg;
    uint32_t channelShift = SHIFT_TAB_CCER[channel];

    /* Disable the Channel 1: Reset the CC1E Bit */
    CLEAR_BIT(tim->CCER.WORDVAL, TIM_CCER_CC1E_M << channelShift);

    /* Get the TIMx CCMRx register address */
    pTmpReg = (__IO uint32_t *)((channel < TIM_CHANNEL_CH3) ? (&tim->CCMR1.WORDVAL) : (&tim->CCMR2.WORDVAL));
    
    /* Select the Input and set the filter and the prescaler value */
    MODIFY_REG(*pTmpReg,
               (TIM_CCMR1_CAP_CC1S_M | TIM_CCMR1_CAP_IC1PSC_M | TIM_CCMR1_CAP_IC1F_M) << SHIFT_TAB_CCMR[channel],
               (configure & (TIM_CCMR1_CAP_CC1S_M | TIM_CCMR1_CAP_IC1PSC_M | TIM_CCMR1_CAP_IC1F_M)) << SHIFT_TAB_CCMR[channel]);

    /* Select the Polarity and set the CCxE Bit */
    MODIFY_REG(tim->CCER.WORDVAL,
               (TIM_CCER_CC1P_M | TIM_CCER_CC1NP_M) << channelShift, 
               ((((uint32_t)configure >> 16UL) & TIM_CCER_CC1P_M) | TIM_CCER_CC1E_M) << channelShift);
}

/**
  * @brief  Configure the encoder interface of the timer instance.
  * @param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * @param  encoderMode     Specifies the encoder resolution
  *                          This parameter can be any value of @ref TIM_ENCODERMODE
  *                          This feature can be modified afterwards using unitary function @ref TIM_setEncoderMode()
  * @param  ic1Configure    Encode input ch1 configuration combination
  *                          All parameters can be or together, and the parameters include the following sections:
  *                          @ref TIM_IC_ACTIVE, Specifies the input.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setIcActiveInput()
  *                          @ref TIM_IC_PSC, Specifies the Input Capture Prescaler.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setIcPrescaler()
  *                          @ref TIM_IC_FILTER, Specifies the input capture filter.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setIcFilter()
  *                          @ref TIM_IC_POLARITY, Specifies the active edge of the input signal.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setIcPolarity()
  * @param  ic2Configure    Encode input ch2 configuration combination
  *                          All parameters can be or together, and the parameters include the following sections:
  *                          @ref TIM_IC_ACTIVE, Specifies the input.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setIcActiveInput()
  *                          @ref TIM_IC_PSC, Specifies the Input Capture Prescaler.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setIcPrescaler()
  *                          @ref TIM_IC_FILTER, Specifies the input capture filter.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setIcFilter()
  *                          @ref TIM_IC_POLARITY, Specifies the active edge of the input signal.
  *                               This feature can be modified afterwards using unitary function @ref TIM_setIcPolarity()
  * @note   Before this function is called, you need to use the TIM_configTimeBase() function to configure the basic 
  *         parameters of TIM, in the end you need to call the TIM_enableCounter() function to start the TIM.
  */
void TIM_configEncoder (TIM_TypeDef *tim, TIM_EncoderMode encoderMode, uint32_t ic1Configure, uint32_t ic2Configure)
{
    /* Disable the CC1 and CC2: Reset the CC1E and CC2E Bits */
    CLEAR_BIT(tim->CCER.WORDVAL, (TIM_CCER_CC1E_M | TIM_CCER_CC2E_M));

    /* Set encoder mode */
    MODIFY_REG(tim->SMCR.WORDVAL, TIM_SMCR_SMS_M, encoderMode);
    
    /* Configure TI1 and TI2 */
    MODIFY_REG(tim->CCMR1.WORDVAL, 
               TIM_CCMR1_CAP_CC1S_M | TIM_CCMR1_CAP_IC1F_M | TIM_CCMR1_CAP_IC1PSC_M |
               TIM_CCMR1_CAP_CC2S_M | TIM_CCMR1_CAP_IC2F_M | TIM_CCMR1_CAP_IC2PSC_M,
               (((ic1Configure & TIM_CCMR1_CAP_CC1S_M) | (ic1Configure & TIM_CCMR1_CAP_IC1F_M) | 
                 (ic1Configure & TIM_CCMR1_CAP_IC1PSC_M))) | 
               (((ic2Configure & TIM_CCMR1_CAP_CC1S_M) | (ic2Configure & TIM_CCMR1_CAP_IC1F_M) | 
                 (ic2Configure & TIM_CCMR1_CAP_IC1PSC_M)) << 8UL));

    /* Set TI1 and TI2 polarity and enable TI1 and TI2 */
    MODIFY_REG(tim->CCER.WORDVAL, 
               TIM_CCER_CC1P_M | TIM_CCER_CC1NP_M | TIM_CCER_CC2P_M | TIM_CCER_CC2NP_M,
               ((ic1Configure >> 16UL) & TIM_CCER_CC1P_M) | TIM_CCER_CC1E_M |
               ((ic1Configure >> 11UL) & TIM_CCER_CC2P_M) | TIM_CCER_CC2E_M);
}

/**
  * @brief  Configure the Hall sensor interface of the timer instance.
  * @note   TIMx CH1, CH2 and CH3 inputs connected through a XOR to the TI1 input channel.
  * @note   TIMx slave mode controller is configured in reset mode. Selected internal trigger is TI1F_ED.
  * @note   Channel 1 is configured as input, IC1 is mapped on TRC.
  * @note   Captured value stored in TIMx_CCR1A correspond to the time elapsed between 2 changes on the inputs. 
  *         It gives information about motor speed.
  * @note   Channel 4 is configured in output PWM 2 mode.
  * @note   Compare value stored in TIMx_CCR4A corresponds to the commutation delay.
  * @note   OC4REF is selected as trigger output on TRGO.
  * @param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * @param  ic1Prescaler    Specifies the TI1 input prescaler value
  *                          This parameter can be any value of @ref TIM_IC_PSC
  *                          This feature can be modified afterwards using unitary function @ref TIM_setIcPrescaler()
  * @param  ic1Filter       Specifies the TI1 input filter
  *                          This parameter can be any value of @ref TIM_IC_FILTER
  *                          This feature can be modified afterwards using unitary function @ref TIM_setIcFilter()
  * @param  comDelay        Specifies the compare value to be loaded into the CCR4A Register
  *                          This parameter can be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF.
  *                          This feature can be modified afterwards using unitary function @ref TIM_setOcCompareCh2A()
  * @note   Before this function is called, you need to use the TIM_configTimeBase() function to configure the basic 
  *         parameters of TIM, in the end you need to call the TIM_enableCounter() function to start the TIM.
  * @note   If you need to output PWM to the pins, you also need to use TIM_enableMainOutput().
  */
void TIM_configHallSensor (TIM_TypeDef *tim, TIM_IcPrescaler ic1Prescaler, TIM_IcFilter ic1Filter, uint32_t comDelay)
{
    /* Disable the CC1 and CC2: Reset the CC1E and CC2E Bits */
    CLEAR_BIT(tim->CCER.WORDVAL, (TIM_CCER_CC1E_M | TIM_CCER_CC2E_M | TIM_CCER_CC3E_M | TIM_CCER_CC4E_M));

    /* Connect TIMx_CH1, CH2 and CH3 pins to the TI1 input */
    /* OC4REF signal is used as trigger output (TRGO) */
    MODIFY_REG(tim->CR2.WORDVAL, TIM_CR2_MMS_M, TIM_CR2_TI1S_M | TIM_TRGO_OC4REF);

    /* Configure channel 1 / channel 2 */
    /* cc1 cc2 need config to input */
    MODIFY_REG(tim->CCMR1.WORDVAL, 
               TIM_CCMR1_CAP_CC1S_M | TIM_CCMR1_CAP_IC1PSC_M | TIM_CCMR1_CAP_IC1F_M |
               TIM_CCMR1_CAP_CC2S_M | TIM_CCMR1_CAP_IC2PSC_M | TIM_CCMR1_CAP_IC2F_M,
               TIM_IC_ACTIVE_TRC | (TIM_IC_ACTIVE_TRC << 8UL) | (uint32_t)ic1Filter | (uint32_t)ic1Prescaler);
    
    /* Configure channel 3 / channel 4 */
    /* cc3 need config to input */
    /* cc4 need config to output */
    MODIFY_REG(tim->CCMR2.WORDVAL,
               TIM_CCMR2_CAP_CC3S_M | TIM_CCMR2_CAP_IC3PSC_M | TIM_CCMR2_CAP_IC3F_M |
               TIM_CCMR2_CC4S_M | TIM_CCMR2_OC4FE_M | TIM_CCMR2_OC4PE_M | TIM_CCMR2_OC4M_M | TIM_CCMR2_OC4CE_M,
               TIM_IC_ACTIVE_TRC | (TIM_OCMODE_PWM2 << 8UL));

    /* Configure the slave mode controller */
    MODIFY_REG(tim->SMCR.WORDVAL, TIM_SMCR_TS_M | TIM_SMCR_SMS_M, (uint32_t)TIM_TS_TI1F_ED | (uint32_t)TIM_SLAVEMODE_RESET);
    
    /* Set Channel 1 polarity and enable Channel 1 and Channel4 */
    MODIFY_REG(tim->CCER.WORDVAL, 
               TIM_CCER_CC4P_M,
               TIM_CCER_CC1P_M | TIM_CCER_CC1NP_M | TIM_CCER_CC1E_M | TIM_CCER_CC4E_M);

    /* Write to TIMx CCR4 */
    WRITE_REG(tim->CCR4A.WORDVAL, comDelay);
}

/**
  * @brief  Configure the Break and Dead Time feature of the timer instance.
  * @note   As the bits AOE, BKP, BKE, OSSR, OSSI and DTG[7:0] can be write-locked depending on the LOCK configuration, 
  *         it can be necessary to configure all of them during the first write access to the TIMx_BDTR register.
  * @param  tim          TIMx pointer to a TIM_TypeDef structure
  *                       - TIM1: TIM1 base address index
  *                       - TIM2: TIM2 base address index
  * @param  deadTime     Specifies the delay time between the switching-off and the switching-on of the outputs
  *                       This parameter can be a number between Min_Data = 0x00 and Max_Data = 0xFF.
  *                       This feature can be modified afterwards using unitary function @ref TIM_setOcDeadTime()
  * @param  configure    Break configuration combination
  *                       All parameters can be or together, and the parameters include the following sections:
  *                       @ref TIM_OSSR, Specifies the Off-State selection used in Run mode.
  *                            This feature can be modified afterwards using unitary function @ref TIM_setOffStates()
  *                       @ref TIM_OSSI, Specifies the Off-State used in Idle state.
  *                            This feature can be modified afterwards using unitary function @ref TIM_setOffStates()
  *                       @ref TIM_LOCKLEVEL, Specifies the LOCK level parameters.
  *                            The LOCK bits can be written only once after the reset. Once the TIMx_BDTR 
  *                            register has been written, their content is frozen until the next reset.
  *                       @ref TIM_BREAK_POLARITY, Specifies the TIM Break Input pin polarity.
  *                            This feature can be modified afterwards using unitary function @ref TIM_setBreakPolarity()
  *                       @ref TIM_BREAK, Specifies whether the TIM Break input is enabled or not.
  *                            This feature can be modified afterwards using unitary functions @ref TIM_enableBreak() 
  *                            or @ref TIM_disableBreak()
  *                       @ref TIM_AUTOMATICOUTPUT, Specifies whether the TIM Automatic Output feature is enabled or not.
  *                            This feature can be modified afterwards using unitary functions 
  *                            @ref TIM_enableAutomaticOutput() or @ref TIM_disableAutomaticOutput()
  */
void TIM_configBreakDeadTime (TIM_TypeDef *tim, uint8_t deadTime, uint32_t configure)
{
    /* Set the Lock level, the Break enable Bit and the Polarity, the OSSR State,
       the OSSI State, the dead time value and the Automatic Output Enable Bit */
    MODIFY_REG(tim->BDTR.WORDVAL, 0x7FFFUL, deadTime | (configure & 0x7FFFUL));
}

/**
  * @brief  Configure the external trigger (ETR) input.
  * @param  tim             TIMx pointer to a TIM_TypeDef structure
  *                          - TIM1: TIM1 base address index
  *                          - TIM2: TIM2 base address index
  * @param  etrPolarity     External trigger polarity
  *                          This parameter can be any value of @ref TIM_ETR_POLARITY
  * @param  etrPrescaler    External trigger perscaler
  *                          This parameter can be any value of @ref TIM_ETR_PRESCALER
  * @param  etrFilter       External trigger filter
  *                          This parameter can be any value of @ref TIM_ETR_FILTER
  */
void TIM_configEtr (TIM_TypeDef *tim, TIM_EtrPolarity etrPolarity, TIM_EtrPrescaler etrPrescaler, TIM_EtrFilter etrFilter)
{
    MODIFY_REG(tim->SMCR.WORDVAL, 
               TIM_SMCR_ETP_M | TIM_SMCR_ETPS_M | TIM_SMCR_ETF_M, 
               (uint32_t)etrPolarity | (uint32_t)etrPrescaler | (uint32_t)etrFilter);
}
