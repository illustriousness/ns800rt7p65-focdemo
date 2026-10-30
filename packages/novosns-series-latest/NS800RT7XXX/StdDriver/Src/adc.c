/**
  * @file       adc.c
  * @author     wangyi
  * @brief      Function file for NS800RT7xxx adc module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "adc.h"


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
  * @brief  Configures the ADC module's reference mode and offset trim
  * @note   In this device, the bandgaps are common for all the ADC instances,
  *         hence common Vref configuration needs to be done for all the ADCs. This
  *         API configures same Vref configuration for all the supported ADCs in the device.
  * @param  base          ADC base address
  *                        - ADCA: ADC A base address
  *                        - ADCB: ADC B base address
  *                        - ADCC: ADC C base address
  * @param  refMode       ADC reference Mode
  *                        This parameter can be one of the following @ref ADC_ReferenceMode:
  * @param  refVoltage    ADC reference Voltage
  *                        This parameter can be one of the following @ref ADC_ReferenceVoltage:
  */
void ADC_setVREF (ADC_TypeDef *base, ADC_ReferenceMode refMode, ADC_ReferenceVoltage refVoltage)
{
    /* Analog reference mode selection */
    if (refMode == ADC_REFERENCE_INTERNAL)
    {
        ANASS_setAnalogReferenceInternal();
        /* Analog reference voltage level selection */
        if (refVoltage == ADC_REFERENCE_3_3V)
        {
            ANASS_setAnalogReference1P65();
            ADC_selectSgain(base, ADC_SGAIN_1DIV2);
        }
        else if ((refVoltage == ADC_REFERENCE_2_5V))
        {
            ANASS_setAnalogReference2P5();
            ADC_selectSgain(base, ADC_SGAIN_1);
        }
        else if ((refVoltage == ADC_REFERENCE_1_65V))
        {
            ANASS_setAnalogReference1P65();
            ADC_selectSgain(base, ADC_SGAIN_1);
        }
        else
        {
            ANASS_setAnalogReference1P65();
            ADC_selectSgain(base, ADC_SGAIN_1);
        }
    }
    else if ((refMode == ADC_REFERENCE_EXTERNAL))
    {
        ANASS_setAnalogReferenceExternal();
        ADC_selectSgain(base, ADC_SGAIN_1);
    }

    /* Only single-ended input mode is supported */
    ADC_setSingleInput(base);

    /* normal mode*/
    ADC_setNormalMethod(base);
}

/**
  * @brief  Configures the offset trim for the desired ADC instance
  * @note   This function loads the offset trims for the desired ADC instance.
  * @param  base       ADC base address
  *                     - ADCA: ADCA_BASE
  *                     - ADCB: ADCB_BASE
  *                     - ADCC: ADCC_BASE
  * @param  trimVal    ADC offset trim value
  *                     the value scope: 0~0x1f, but the mask is 0x3f, for example:
  *                       if trimVal=0x1F, the offset trim value is +0x1F;
  *                       if trimVal=0x3F, the offset trim value is -0x1F;
  * 
  * @note  The ADC offset trim value of the NS800RTxxx series chips is automatically
  *        loaded upon chip power-on! There is no need to call this function to 
  *        load it.
  */
void ADC_setOffsetTrim (ADC_TypeDef *base, uint8_t trimVal)
{
    MODIFY_REG(base->TRIMPN.WORDVAL, ADC_TRIMPN_OFFSET_M,
               ((uint32_t)trimVal << ADC_TRIMPN_OFFSET_S) & ADC_TRIMPN_OFFSET_M);
}

/**
  * @brief  Sets the windowed trip limits for a PPB.
  * @note   This function sets the windowed trip limits for a PPB. These values set
  *         the digital comparator trip high and low limits.
  *         The trip limits are used to determine when the PPB is tripped.
  * @param  base           ADC base address
  *                         - ADCA: ADC A base address
  *                         - ADCB: ADC B base address
  *                         - ADCC: ADC C base address
  * @param  ppbNumber      ADC PPB Number
  *                         This parameter can be one of the following @ref ADC_PPBNUMBER:
  * @param  sybol          ADC PPB Symbol
  *                         This parameter can be one of the following @ref ADC_PPBSYMBOL:
  * @param  tripHiLimit    ADC PPB Trip Hi Limit,tripHiLimit is the value is the digital comparator trip high limit.
  * @param  tripLoLimit    ADC PPB Trip Lo Limit,tripLoLimit is the value is the digital comparator trip low limit.
  */
void ADC_setPPBTripLimits (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, ADC_PPBSymbol sybol, uint32_t tripHiLimit, uint32_t tripLoLimit)
{
    MODIFY_REG(TYPE32(&(base->PPB1TRIPHI.WORDVAL) + (ppbNumber * 6UL)), ADC_PPBTRIP_SYBOL_MASK, \
               ((sybol << ADC_PPBTRIPSIGN_OFFSET) & ADC_PPBTRIP_SYBOL_MASK));
    MODIFY_REG(TYPE32(&(base->PPB1TRIPHI.WORDVAL) + (ppbNumber * 6UL)), ADC_PPBTRIP_MASK, (tripHiLimit & ADC_PPBTRIP_MASK));

    MODIFY_REG(TYPE32(&(base->PPB1TRIPLO.WORDVAL) + (ppbNumber * 6UL)), ADC_PPBTRIP_SYBOL_MASK, \
               ((sybol << ADC_PPBTRIPSIGN_OFFSET) & ADC_PPBTRIP_SYBOL_MASK));
    MODIFY_REG(TYPE32(&(base->PPB1TRIPLO.WORDVAL) + (ppbNumber * 6UL)), ADC_PPBTRIP_MASK, (tripLoLimit & ADC_PPBTRIP_MASK));
}


/**
  * \brief  Configures the trigger repeater.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  repInstance  ADC repeater instance
  *
  * \param  config    ADC desired repeater configuration
  *
  * \return None
  *
  */
void
ADC_configureRepeater(ADC_TypeDef *base, uint16_t repInstance,
                      ADC_RepeaterConfig *config)
{

    __IO uint32_t *addr;

    addr = (uint32_t *)(&(base->REP1CTL.WORDVAL) + ((uint32_t)repInstance * 4U));

    MODIFY_REG(*addr, (ADC_REP1CTL_TRIGGER_M | ADC_REP1CTL_MODE_M | ADC_REP1CTL_SYNCINSEL_M), \
                      (((uint32_t)config->repMode) |
                      ((uint32_t)config->repTrigger << ADC_REP1CTL_TRIGGER_S) |
                      ((uint32_t)config->repSyncin << ADC_REP1CTL_SYNCINSEL_S)));

    MODIFY_REG(TYPE32(&(base->REP1N.WORDVAL)), (ADC_REP1N_NSEL_M), \
                      (config->repCount));

    MODIFY_REG(TYPE32(&(base->REP1PHASE.WORDVAL)), (ADC_REP1PHASE_PHASE_M), \
                      (config->repPhase));

    MODIFY_REG(TYPE32(&(base->REP1SPREAD.WORDVAL)), (ADC_REP1SPREAD_SPREAD_M), \
                      (config->repSpread));

}
