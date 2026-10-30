/**
  * @file       cmpss.c
  * @author     zhoukai
  * @brief      Function file for NS800RT7xxx cmpss module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "cmpss.h"


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
  * @brief  Config High Comparator Filter.
  * @param  cmpss             The base address of the CMPSS module.
  *                            - CMPSS1: CMPSS1 base address index
  *                            - CMPSS2: CMPSS2 base address index
  *                            - CMPSS3: CMPSS3 base address index
  *                            - CMPSS4: CMPSS4 base address index
  *                            - CMPSS5: CMPSS5 base address index
  *                            - CMPSS6: CMPSS6 base address index
  *                            - CMPSS7: CMPSS7 base address index
  *                            - CMPSS8: CMPSS8 base address index
  *                            - CMPSS9: CMPSS9 base address index
  *                            - CMPSS10: CMPSS10 base address index
  *                            - CMPSS11: CMPSS11 base address index
  * @param  samplePrescale    High filter sample clock prescale. samplePrescale used is CLKPRESCALE+1.
  *                            - uint16_t: 0 - 65535
  * @param  sampleWindow      High filter sample window size.
  *                            - uint16_t: 2 - 33
  * @param  threshold         High filter majority voting threshold.
  *                            - uint16_t: 2 - 33
  */
void CMPSS_configFilterHigh (CMPSS_TypeDef *cmpss, uint16_t samplePrescale,
                             uint16_t sampleWindow, uint16_t threshold)
{
    uint32_t regValue;

    sampleWindow = (sampleWindow < 2) ? 2 : sampleWindow;
    threshold    = (threshold < 2) ? 2 : threshold;

    /* Shift the sample window and threshold values into the correct positions */
    regValue = ((uint32_t)((sampleWindow - 2UL) << CMPSS_CTRIPHFILCTL_SAMPWIN_S) | \
                (uint32_t)((threshold - 2UL) << CMPSS_CTRIPHFILCTL_THRESH_S));

    MODIFY_REG(cmpss->CTRIPHFILCTL.WORDVAL,
               CMPSS_CTRIPHFILCTL_SAMPWIN_M | CMPSS_CTRIPHFILCTL_THRESH_M,
               regValue);

    /* Set the filter sample clock prescale for the high comparator. */
    CMPSS_setFilterHighPrescale(cmpss, samplePrescale);
}

/**
  * @brief  Config Low Comparator Filter.
  * @param  cmpss             The base address of the CMPSS module.
  *                            - CMPSS1: CMPSS1 base address index
  *                            - CMPSS2: CMPSS2 base address index
  *                            - CMPSS3: CMPSS3 base address index
  *                            - CMPSS4: CMPSS4 base address index
  *                            - CMPSS5: CMPSS5 base address index
  *                            - CMPSS6: CMPSS6 base address index
  *                            - CMPSS7: CMPSS7 base address index
  *                            - CMPSS8: CMPSS8 base address index
  *                            - CMPSS9: CMPSS9 base address index
  *                            - CMPSS10: CMPSS10 base address index
  *                            - CMPSS11: CMPSS11 base address index
  * @param  samplePrescale    Low filter sample clock prescale. samplePrescale used is CLKPRESCALE+1.
  *                            - uint16_t: 0 - 65535
  * @param  sampleWindow      Low filter sample window size.
  *                            - uint16_t: 2 - 33
  * @param  threshold         Low filter majority voting threshold.
  *                            - uint16_t: 2 - 33
  */
void CMPSS_configFilterLow (CMPSS_TypeDef *cmpss, uint16_t samplePrescale,
                            uint16_t sampleWindow, uint16_t threshold)
{
    uint32_t regValue;

    sampleWindow = (sampleWindow < 2) ? 2 : sampleWindow;
    threshold    = (threshold < 2) ? 2 : threshold;

    /* Shift the sample window and threshold values into the correct positions */
    regValue = ((uint32_t)((sampleWindow - 2UL) << CMPSS_CTRIPLFILCTL_SAMPWIN_S) | \
                (uint32_t)((threshold - 2UL) << CMPSS_CTRIPLFILCTL_THRESH_S));

    MODIFY_REG(cmpss->CTRIPLFILCTL.WORDVAL,
               CMPSS_CTRIPLFILCTL_SAMPWIN_M | CMPSS_CTRIPLFILCTL_THRESH_M,
               regValue);

    /* Set the filter sample clock prescale for the low comparator. */
    CMPSS_setFilterLowPrescale(cmpss, samplePrescale);
}

/**
  * @brief  Config the related parameters for High RAMP.
  * @param  cmpss             The base address of the CMPSS module.
  *                            - CMPSS1: CMPSS1 base address index
  *                            - CMPSS2: CMPSS2 base address index
  *                            - CMPSS3: CMPSS3 base address index
  *                            - CMPSS4: CMPSS4 base address index
  *                            - CMPSS5: CMPSS5 base address index
  *                            - CMPSS6: CMPSS6 base address index
  *                            - CMPSS7: CMPSS7 base address index
  *                            - CMPSS8: CMPSS8 base address index
  *                            - CMPSS9: CMPSS9 base address index
  *                            - CMPSS10: CMPSS10 base address index
  *                            - CMPSS11: CMPSS11 base address index
  * @param  rampDir           Ramp direction of high ramp generator .
  *                            - 0: Ramp direction decrease
  *                            - 1: Ramp direction increase
  * @param  refRampVal        Reference ramp value to the shadow register .
  *                            - uint16_t: 0x00 - 0xFFF
  * @param  stepVal           StepVal: ramp step value to the shadow register.
  *                            - uint16_t: 0x00 - 0xFFF
  * @param  delayVal          Ramp delay value to the shadow register.
  *                            - uint16_t: 0x00 - 0x1FFF
  * @param  pwmSyncSrc        Determines which EPWMnSYNCPER signal is used within the CMPSS module.
  *                            - CMPSS_EpwmSyncPerSelect: 0x00 - 0x0F
  * @param  useRampValShdw    Determines whether DACxVALA is updated from DACxVALS on SYSCLK or EPWMSYNCPER.
  *                            - 0: DACHVALA is updated from DACHVALS
  *                            - 1: DACHVALA is updated from the ramp generator
  */
void CMPSS_configRampHigh (CMPSS_TypeDef *cmpss, CMPSS_RampDirection rampDir, uint16_t refRampVal, uint16_t stepVal, \
                           uint16_t delayVal, CMPSS_EpwmSyncPerSelect pwmSyncSrc, uint8_t useRampValShdw)
{

    CMPSS_configureSyncSourceHigh(cmpss, pwmSyncSrc);
    /* Set or clear the bit that determines from where the max ramp value should be loaded. */
    if (useRampValShdw)
    {
        SET_BIT(cmpss->COMPDACHCTL.WORDVAL, CMPSS_COMPDACHCTL_RAMPHLOADSEL);
    }
    else
    {
        CLEAR_BIT(cmpss->COMPDACHCTL.WORDVAL, CMPSS_COMPDACHCTL_RAMPHLOADSEL);
    }

    CMPSS_setRAMPDirectionHigh(cmpss, rampDir);

    /* Write the reference ramp value to the shadow register. */
    CMPSS_setRampReferenceHigh(cmpss, refRampVal);

    /* Write the ramp decrement value to the shadow register. */
    CMPSS_setRampStepHigh(cmpss, stepVal);

    /* Write the ramp delay value to the shadow register. */
    CMPSS_setRampDelayHigh(cmpss, delayVal);
}

/**
  * @brief  Config the related parameters for Low RAMP.
  * @param  cmpss             The base address of the CMPSS module.
  *                            - CMPSS1: CMPSS1 base address index
  *                            - CMPSS2: CMPSS2 base address index
  *                            - CMPSS3: CMPSS3 base address index
  *                            - CMPSS4: CMPSS4 base address index
  *                            - CMPSS5: CMPSS5 base address index
  *                            - CMPSS6: CMPSS6 base address index
  *                            - CMPSS7: CMPSS7 base address index
  *                            - CMPSS8: CMPSS8 base address index
  *                            - CMPSS9: CMPSS9 base address index
  *                            - CMPSS10: CMPSS10 base address index
  *                            - CMPSS11: CMPSS11 base address index
  * @param  rampDir           Ramp direction of low ramp generator .
  *                            - 0: Ramp direction decrease
  *                            - 1: Ramp direction increase
  * @param  refRampVal        Reference ramp value to the shadow register .
  *                            - uint16_t: 0x00 - 0xFFF
  * @param  stepVal           StepVal: ramp step value to the shadow register.
  *                            - uint16_t: 0x00 - 0xFFF
  * @param  delayVal          Ramp delay value to the shadow register.
  *                            - uint16_t: 0x00 - 0x1FFF
  * @param  pwmSyncSrc        Determines which EPWMnSYNCPER signal is used within the CMPSS module.
  *                            - CMPSS_EpwmSyncPerSelect: 0x00 - 0x0F
  * @param  useRampValShdw    Determines whether DACxVALA is updated from DACxVALS on SYSCLK or EPWMSYNCPER.
  *                            - 0: DACHVALA is updated from DACHVALS
  *                            - 1: DACHVALA is updated from the ramp generator
  */
void CMPSS_configRampLow (CMPSS_TypeDef *cmpss, CMPSS_RampDirection rampDir, uint16_t refRampVal, uint16_t stepVal, \
                          uint16_t delayVal, CMPSS_EpwmSyncPerSelect pwmSyncSrc, uint8_t useRampValShdw)
{

    CMPSS_configureSyncSourceLow(cmpss, pwmSyncSrc);
    /* Set or clear the bit that determines from where the max ramp value should be loaded. */
    if (useRampValShdw)
    {
        SET_BIT(cmpss->COMPDACLCTL.WORDVAL, CMPSS_COMPDACLCTL_RAMPLLOADSEL);
    }
    else
    {
        CLEAR_BIT(cmpss->COMPDACLCTL.WORDVAL, CMPSS_COMPDACLCTL_RAMPLLOADSEL);
    }

    CMPSS_setRAMPDirectionLow(cmpss, rampDir);

    /* Write the reference ramp value to the shadow register. */
    CMPSS_setRampReferenceLow(cmpss, refRampVal);

    /* Write the ramp decrement value to the shadow register. */
    CMPSS_setRampStepLow(cmpss, stepVal);

    /* Write the ramp delay value to the shadow register. */
    CMPSS_setRampDelayLow(cmpss, delayVal);
}

/**
  * @brief  Config low/high comparator latch software clear.
  * @param  cmpss         The base address of the CMPSS module.
  *                        - CMPSS1: CMPSS1 base address index
  *                        - CMPSS2: CMPSS2 base address index
  *                        - CMPSS3: CMPSS3 base address index
  *                        - CMPSS4: CMPSS4 base address index
  *                        - CMPSS5: CMPSS5 base address index
  *                        - CMPSS6: CMPSS6 base address index
  *                        - CMPSS7: CMPSS7 base address index
  * @param  highEnable    Set the bit that will enable PWMSYNC to reset the high comparator digital filter latch. 
  *                        - 0: Disable 
  *                        - 1: Enable
  * @param  lowEnable     Set the bit that will enable PWMSYNC to reset the low comparator digital filter latch.
  *                        - 0: Disable 
  *                        - 1: Enable
  */
void CMPSS_configLatchOnPWMSYNC (CMPSS_TypeDef *cmpss, uint8_t highEnable, uint8_t lowEnable)
{
    if (highEnable)
    {
        SET_BIT(cmpss->COMPSTSCLR.WORDVAL, CMPSS_COMPSTSCLR_HSYNCCLREN);
    }
    else
    {
        CLEAR_BIT(cmpss->COMPSTSCLR.WORDVAL, CMPSS_COMPSTSCLR_HSYNCCLREN);
    }
    if (lowEnable)
    {
        SET_BIT(cmpss->COMPSTSCLR.WORDVAL, CMPSS_COMPSTSCLR_LSYNCCLREN);
    }
    else
    {
        CLEAR_BIT(cmpss->COMPSTSCLR.WORDVAL, CMPSS_COMPSTSCLR_LSYNCCLREN);
    }
}
