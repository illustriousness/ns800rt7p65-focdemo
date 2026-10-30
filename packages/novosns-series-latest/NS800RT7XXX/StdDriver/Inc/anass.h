/**
  * @file       anass.h
  * @author     zhoukai
  * @brief      Header file for NS800RT7xxx anass module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __ANASS_H__
#define __ANASS_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_anass.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup ANASS_EXPORTED_TYPES ANASS Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'ANASS' module.
  */

/** @defgroup ANASS_CMPHPMUXSELECT ANASS CMPSS HP Mux Sel  
  * @{
  * @brief  Macro definitions about ANASS cmpss hp mux select
  *         Values that can be passed to ANASS_selectCMPHPMux() as the \e select parameter.
  */ 
typedef enum {
    ANASS_CMPHPMUX_SELECT_1  = 0U,     /*!< CMPHPMUX select 1 */
    ANASS_CMPHPMUX_SELECT_2  = 3U,     /*!< CMPHPMUX select 2 */
    ANASS_CMPHPMUX_SELECT_3  = 6U,     /*!< CMPHPMUX select 3 */
    ANASS_CMPHPMUX_SELECT_4  = 9U,     /*!< CMPHPMUX select 4 */
    ANASS_CMPHPMUX_SELECT_5  = 12U,    /*!< CMPHPMUX select 5 */
    ANASS_CMPHPMUX_SELECT_6  = 15U,    /*!< CMPHPMUX select 6 */
    ANASS_CMPHPMUX_SELECT_7  = 18U,    /*!< CMPHPMUX select 7 */
    ANASS_CMPHPMUX_SELECT_8  = 21U,    /*!< CMPHPMUX select 8 */
    ANASS_CMPHPMUX_SELECT_9  = 24U,    /*!< CMPHPMUX select 9 */
    ANASS_CMPHPMUX_SELECT_10 = 27U,    /*!< CMPHPMUX select 10 */
    ANASS_CMPHPMUX_SELECT_11 = 30U     /*!< CMPHPMUX select 11 */
} ANASS_CMPHPMuxSelect;                                      

/**
 * @}
 */
 
/** @defgroup ANASS_CMPLPMUXSELECT ANASS CMPSS LP Mux Sel 
  * @{
  * @brief  Macro definitions about ANASS cmpss lp mux select
  *         Values that can be passed to ANASS_selectCMPLPMux() as the \e select parameter.
  */                                                              
typedef enum {                                                            
    ANASS_CMPLPMUX_SELECT_1  = 0U,     /*!< CMPLPMUX select 1 */
    ANASS_CMPLPMUX_SELECT_2  = 3U,     /*!< CMPLPMUX select 2 */
    ANASS_CMPLPMUX_SELECT_3  = 6U,     /*!< CMPLPMUX select 3 */
    ANASS_CMPLPMUX_SELECT_4  = 9U,     /*!< CMPLPMUX select 4 */
    ANASS_CMPLPMUX_SELECT_5  = 12U,    /*!< CMPLPMUX select 5 */
    ANASS_CMPLPMUX_SELECT_6  = 15U,    /*!< CMPLPMUX select 6 */
    ANASS_CMPLPMUX_SELECT_7  = 18U,    /*!< CMPLPMUX select 7 */
    ANASS_CMPLPMUX_SELECT_8  = 21U,    /*!< CMPLPMUX select 8 */
    ANASS_CMPLPMUX_SELECT_9  = 24U,    /*!< CMPLPMUX select 9 */
    ANASS_CMPLPMUX_SELECT_10 = 27U,    /*!< CMPLPMUX select 10 */
    ANASS_CMPLPMUX_SELECT_11 = 30U     /*!< CMPLPMUX select 11 */
} ANASS_CMPLPMuxSelect;

/**
 * @}
 */
 
/** @defgroup ANASS_CMPHNMUXSELECT ANASS CMPSS HN Mux Sel
  * @{
  * @brief  Macro definitions about ANASS cmpss hn mux select
  *         Values that can be passed to ANASS_selectCMPHNMux() as the \e select parameter.
  */ 
typedef enum {                                          
    ANASS_CMPHNMUX_SELECT_1  = 0x1UL,      /*!< CMPHNMUX select 1 */
    ANASS_CMPHNMUX_SELECT_2  = 0x2UL,      /*!< CMPHNMUX select 2 */
    ANASS_CMPHNMUX_SELECT_3  = 0x4UL,      /*!< CMPHNMUX select 3 */
    ANASS_CMPHNMUX_SELECT_4  = 0x8UL,      /*!< CMPHNMUX select 4 */
    ANASS_CMPHNMUX_SELECT_5  = 0x10UL,     /*!< CMPHNMUX select 5 */
    ANASS_CMPHNMUX_SELECT_6  = 0x20UL,     /*!< CMPHNMUX select 6 */
    ANASS_CMPHNMUX_SELECT_7  = 0x40UL,     /*!< CMPHNMUX select 7 */
    ANASS_CMPHNMUX_SELECT_8  = 0x80UL,     /*!< CMPHNMUX select 8 */
    ANASS_CMPHNMUX_SELECT_9  = 0x100UL,    /*!< CMPHNMUX select 9 */
    ANASS_CMPHNMUX_SELECT_10 = 0x200UL,    /*!< CMPHNMUX select 10 */
    ANASS_CMPHNMUX_SELECT_11 = 0x400UL     /*!< CMPHNMUX select 11 */
} ANASS_CMPHNMuxSelect;

/**
 * @}
 */
 
/** @defgroup ANASS_CMPLNMUXSELECT ANASS CMPSS LN Mux Sel
  * @{
  * @brief  Macro definitions about ANASS cmpss ln mux select
  *         Values that can be passed to ANASS_selectCMPLNMux() as the \e select parameter.
  */
typedef enum {                                          
    ANASS_CMPLNMUX_SELECT_1  = 0x1UL,      /*!< CMPLNMUX select 1 */
    ANASS_CMPLNMUX_SELECT_2  = 0x2UL,      /*!< CMPLNMUX select 2 */
    ANASS_CMPLNMUX_SELECT_3  = 0x4UL,      /*!< CMPLNMUX select 3 */
    ANASS_CMPLNMUX_SELECT_4  = 0x8UL,      /*!< CMPLNMUX select 4 */
    ANASS_CMPLNMUX_SELECT_5  = 0x10UL,     /*!< CMPLNMUX select 5 */
    ANASS_CMPLNMUX_SELECT_6  = 0x20UL,     /*!< CMPLNMUX select 6 */
    ANASS_CMPLNMUX_SELECT_7  = 0x40UL,     /*!< CMPLNMUX select 7 */
    ANASS_CMPLNMUX_SELECT_8  = 0x80UL,     /*!< CMPLNMUX select 8 */
    ANASS_CMPLNMUX_SELECT_9  = 0x100UL,    /*!< CMPLNMUX select 9 */
    ANASS_CMPLNMUX_SELECT_10 = 0x200UL,    /*!< CMPLNMUX select 10 */
    ANASS_CMPLNMUX_SELECT_11 = 0x400UL     /*!< CMPLNMUX select 11 */
} ANASS_CMPLNMuxSelect;

/**
 * @}
 */
 
/** @defgroup ANASS_INTERNALTESTCTL ANASS Internal Test Ctl
  * @{
  * @brief  Macro definitions about ANASS internal test control
  *         Values that can be passed to ANASS_selectInternalTest() as the \e select parameter.
  */
typedef enum {                                          
    ANASS_INTERNALTEST_NONE = 0x0UL,       /*!< INTERNALTEST node select none */
    ANASS_INTERNALTEST_CORE_VDD,           /*!< INTERNALTEST node select Core VDD */
    ANASS_INTERNALTEST_VDDA,               /*!< INTERNALTEST node select VDDA */
    ANASS_INTERNALTEST_VSSA,               /*!< INTERNALTEST node select VSSA */
    ANASS_INTERNALTEST_VREFLOA,            /*!< INTERNALTEST node select VREFLOA */
    ANASS_INTERNALTEST_VREFLOB,            /*!< INTERNALTEST node select VREFLOB */
    ANASS_INTERNALTEST_VREFLOC,            /*!< INTERNALTEST node select VREFLOC */
    ANASS_INTERNALTEST_CMPSS1_H,           /*!< INTERNALTEST node select CMPSS1 high DAC */
    ANASS_INTERNALTEST_CMPSS1_L,           /*!< INTERNALTEST node select CMPSS1 low DAC  */
    ANASS_INTERNALTEST_CMPSS2_H,           /*!< INTERNALTEST node select CMPSS2 high DAC */
    ANASS_INTERNALTEST_CMPSS2_L,           /*!< INTERNALTEST node select CMPSS2 low DAC  */
    ANASS_INTERNALTEST_CMPSS3_H,           /*!< INTERNALTEST node select CMPSS3 high DAC */
    ANASS_INTERNALTEST_CMPSS3_L,           /*!< INTERNALTEST node select CMPSS3 low DAC  */
    ANASS_INTERNALTEST_CMPSS4_H,           /*!< INTERNALTEST node select CMPSS4 high DAC */
    ANASS_INTERNALTEST_CMPSS4_L,           /*!< INTERNALTEST node select CMPSS4 low DAC  */
    ANASS_INTERNALTEST_CMPSS5_H,           /*!< INTERNALTEST node select CMPSS5 high DAC */
    ANASS_INTERNALTEST_CMPSS5_L,           /*!< INTERNALTEST node select CMPSS5 low DAC  */
    ANASS_INTERNALTEST_CMPSS6_H,           /*!< INTERNALTEST node select CMPSS6 high DAC */
    ANASS_INTERNALTEST_CMPSS6_L,           /*!< INTERNALTEST node select CMPSS6 low DAC  */
    ANASS_INTERNALTEST_CMPSS7_H,           /*!< INTERNALTEST node select CMPSS7 high DAC */
    ANASS_INTERNALTEST_CMPSS7_L,           /*!< INTERNALTEST node select CMPSS7 low DAC  */
    ANASS_INTERNALTEST_CMPSS8_H,           /*!< INTERNALTEST node select CMPSS8 high DAC */
    ANASS_INTERNALTEST_CMPSS8_L,           /*!< INTERNALTEST node select CMPSS8 low DAC  */
    ANASS_INTERNALTEST_CMPSS9_H,           /*!< INTERNALTEST node select CMPSS9 high DAC */
    ANASS_INTERNALTEST_CMPSS9_L,           /*!< INTERNALTEST node select CMPSS9 low DAC  */
    ANASS_INTERNALTEST_CMPSS10_H,          /*!< INTERNALTEST node select CMPSS10 high DAC */
    ANASS_INTERNALTEST_CMPSS10_L,          /*!< INTERNALTEST node select CMPSS10 low DAC */
    ANASS_INTERNALTEST_CMPSS11_H,          /*!< INTERNALTEST node select CMPSS11 high DAC */
    ANASS_INTERNALTEST_CMPSS11_L,          /*!< INTERNALTEST node select CMPSS11 low DAC */
    ANASS_INTERNALTEST_VSS = 0x2BUL,       /*!< INTERNALTEST node select VSS */
    ANASS_INTERNALTEST_VREFLOD = 0x2FUL    /*!< INTERNALTEST node select VREFLOD */
} ANASS_InternalTestCtl;

/**
 * @}
 */
 
/** @defgroup ANASS_ADCSOCFRCGB ANASS ADC Global SOC Force
  * @{
  * @brief  Macro definitions about ANASS ADC global soc force
  *         Values that can be passed to ANASS_configADCSocForceGlobal() as the \e select parameter.
  */
typedef enum {     
    ANASS_ADCSOCFRCGB_SOC_0 = 0UL,    /*!< Select SOC0 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_1,          /*!< Select SOC1 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_2,          /*!< Select SOC2 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_3,          /*!< Select SOC3 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_4,          /*!< Select SOC4 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_5,          /*!< Select SOC5 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_6,          /*!< Select SOC6 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_7,          /*!< Select SOC7 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_8,          /*!< Select SOC8 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_9,          /*!< Select SOC9 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_10,         /*!< Select SOC10 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_11,         /*!< Select SOC11 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_12,         /*!< Select SOC12 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_13,         /*!< Select SOC13 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_14,         /*!< Select SOC14 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_15,         /*!< Select SOC15 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_16,         /*!< Select SOC16 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_17,         /*!< Select SOC17 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_18,         /*!< Select SOC18 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_19,         /*!< Select SOC19 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_20,         /*!< Select SOC20 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_21,         /*!< Select SOC21 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_22,         /*!< Select SOC22 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_23,         /*!< Select SOC23 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_24,         /*!< Select SOC24 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_25,         /*!< Select SOC25 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_26,         /*!< Select SOC26 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_27,         /*!< Select SOC27 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_28,         /*!< Select SOC28 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_29,         /*!< Select SOC29 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_30,         /*!< Select SOC30 as Global Software Trig */
    ANASS_ADCSOCFRCGB_SOC_31          /*!< Select SOC31 as Global Software Trig */
} ANASS_ADCGlobalSocForce;

/**
 * @}
 */
 
/** @defgroup ANASS_ADCSOCFRCGBSEL ANASS ADC SOC FRC Global Select
  * @{
  * @brief  Macro definitions about ANASS ADC soc frc global select
  *         Values that can be passed to ANASS_selectADCSocForceGlobal() as the \e select parameter.
  */
typedef enum {     
    ANASS_ADCSOCFRCGB_SEL_ADC_A = 0x01UL,    /*!< Select ADCA as Global Software Trig */
    ANASS_ADCSOCFRCGB_SEL_ADC_B = 0x02UL,    /*!< Select ADCB as Global Software Trig */
    ANASS_ADCSOCFRCGB_SEL_ADC_C = 0x04UL,    /*!< Select ADCC as Global Software Trig */
    ANASS_ADCSOCFRCGB_SEL_ADC_D = 0x08UL     /*!< Select ADCD as Global Software Trig */
} ANASS_ADCGlobalSocForceSelect;

/**
 * @}
 */
 
/** @defgroup ANASS_AGPIOCTRL ANASS AGPIO Function Ctrl
  * @{
  * @brief  Macro definitions about ANASS AGPIO function ctrl
  *         Values that can be passed to ANASS_configAGpio() as the \e select parameter.
  */
typedef enum {     
    ANASS_AGPIOCTRL_GPIO_198 = 198U,    /*!< Select GPIO198 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_199 = 199U,    /*!< Select GPIO199 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_200 = 200U,    /*!< Select GPIO200 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_201 = 201U,    /*!< Select GPIO201 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_202 = 202U,    /*!< Select GPIO202 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_203 = 203U,    /*!< Select GPIO203 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_204 = 204U,    /*!< Select GPIO204 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_205 = 205U,    /*!< Select GPIO205 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_206 = 206U,    /*!< Select GPIO206 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_207 = 207U,    /*!< Select GPIO207 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_208 = 208U,    /*!< Select GPIO208 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_209 = 209U,    /*!< Select GPIO209 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_210 = 210U,    /*!< Select GPIO210 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_211 = 211U,    /*!< Select GPIO211 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_212 = 212U,    /*!< Select GPIO212 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_213 = 213U,    /*!< Select GPIO213 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_214 = 30U,     /*!< Select GPIO214 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_215 = 28U,     /*!< Select GPIO215 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_216 = 29U,     /*!< Select GPIO216 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_217 = 31U,     /*!< Select GPIO217 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_218 = 32U,     /*!< Select GPIO218 as AGPIO function */
    ANASS_AGPIOCTRL_GPIO_219 = 219U     /*!< Select GPIO219 as AGPIO function */
} ANASS_AGPIOCtrl;

/**
 * @}
 */
 
/** @defgroup ANASS_ADCSYNC ANASS ADC Sync
  * @{
  * @brief  Macro definitions about ANASS ADC Sync
  *         Values that can be passed to ANASS_setADCSync() as the \e select parameter.
  */
typedef enum {     
    ANASS_ADCSYNC_ADC_A = 0x01UL,    /*!< Confirm ADCA Clock frequency division phase synchronization */
    ANASS_ADCSYNC_ADC_B = 0x02UL,    /*!< Confirm ADCB Clock frequency division phase synchronization */
    ANASS_ADCSYNC_ADC_C = 0x04UL     /*!< Confirm ADCC Clock frequency division phase synchronization */
} ANASS_ADCSync;

/**
 * @}
 */

/** @defgroup ANASS_INTERNALTESTCTL ANASS Internal Test Node Control Register
  * @{
  * @brief  Macro definitions about INTERNALTESTCTL register bits definition.
  */
#define ANASS_INTERNALTESTCTL_KEY          (0xA5A50000UL)    /*!< Write permissions key */

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
  * \brief  Locks all AGPIOCTRL Register.
  */
static inline void ANASS_configLock (void)
{
    SET_BIT(ANASS->CONFIGLOCK.WORDVAL, ANASS_CONFIGLOCK_AGPIOCTRL_M);
}

/**
  * \brief  VRBUF Discharge Enable.
  * \param  enable    VRBUF Discharge Enable.
  *                    - 0: No effect
  *                    - 1: Discharge
  */
static inline void ANASS_enableDischarge (bool enable)
{
    if (enable)
    {
        SET_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_DISCHARGE_M);
    }
    else
    {
        CLEAR_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_DISCHARGE_M);
    }
}

/**
  * \brief  Set the analog voltage reference selection to internal.
  */
static inline void ANASS_setAnalogReferenceInternal (void)
{
    CLEAR_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_ANAREFSEL_M);
}

/**
  * \brief  Set the analog voltage reference selection to external.
  */
static inline void ANASS_setAnalogReferenceExternal (void)
{
    SET_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_ANAREFSEL_M);
}

/**
  * \brief  Set the internal analog voltage reference selection to 2.5V.
  */
static inline void ANASS_setAnalogReference2P5 (void)
{
    SET_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_ANAREF2P5SEL_M);
}

/**
  * \brief  Set the internal analog voltage reference selection to 1.65V.
  */
static inline void ANASS_setAnalogReference1P65 (void)
{
    CLEAR_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_ANAREF2P5SEL_M);
}

/**
  * \brief  VREFHIA 0.9 Partial Pressure Enable.
  * \param  enable    VREFHIA 0.9 Partial Pressure Enable.
  *                    - 0: Disable
  *                    - 1: Enable
  */
static inline void ANASS_configVrefHA0P9 (bool enable)
{
    if (enable)
    {
        SET_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_VREFHIA0P9_M);
    }
    else
    {
        CLEAR_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_VREFHIA0P9_M);
    }
}

/**
  * \brief  VREFHIB 0.9 Partial Pressure Enable.
  * \param  enable    VREFHIB 0.9 Partial Pressure Enable.
  *                    - 0: Disable
  *                    - 1: Enable
  */
static inline void ANASS_configVrefHB0P9 (bool enable)
{
    if (enable)
    {
        SET_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_VREFHIB0P9_M);
    }
    else
    {
        CLEAR_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_VREFHIB0P9_M);
    }
}

/**
  * \brief  VREFHIC 0.9 Partial Pressure Enable.
  * \param  enable    VREFHIC 0.9 Partial Pressure Enable.
  *                    - 0: Disable
  *                    - 1: Enable
  */
static inline void ANASS_configVrefHC0P9 (bool enable)
{
    if (enable)
    {
        SET_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_VREFHIC0P9_M);
    }
    else
    {
        CLEAR_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_VREFHIC0P9_M);
    }
}

/**
  * \brief  Select the value for CMPHPMXSEL.
  * \param  select    select is of type ANASS_CMPHPMuxSelect.
  *                    This parameter can be any value of @ref ANASS_CMPHPMUXSELECT
  * \param  value     CMPSS HP Mux Sel
  *                    - uint8_t: 0,1,2,3,4,5,6
  */
static inline void ANASS_selectCMPHPMux (ANASS_CMPHPMuxSelect select, uint8_t value)
{
    if (ANASS_CMPHPMUX_SELECT_11 == select)
    {
        WRITE_REG(ANASS->CMPHPMXSEL1.WORDVAL, (uint32_t)(value << (uint32_t)ANASS_CMPHPMXSEL1_CMP11HPMXSEL_S));
    }
    else
    {
        MODIFY_REG(ANASS->CMPHPMXSEL.WORDVAL, (uint32_t)(ANASS_CMPHPMXSEL_CMP1HPMXSEL_M << (uint32_t)select),
                   (uint32_t)(value << (uint32_t)select));
    }
}

/**
  * \brief  Select the value for CMPLPMXSEL.
  * \param  select    select is of type ANASS_CMPLPMuxSelect.
  *                    This parameter can be any value of @ref ANASS_CMPLPMUXSELECT
  * \param  value     CMPSS LP Mux Sel
  *                    - uint8_t: 0,1,2,3,4,5,6
  */
static inline void ANASS_selectCMPLPMux (ANASS_CMPLPMuxSelect select, uint8_t value)
{
    if (ANASS_CMPLPMUX_SELECT_11 == select)
    {
        WRITE_REG(ANASS->CMPLPMXSEL1.WORDVAL, (uint32_t)(value << (uint32_t)ANASS_CMPLPMXSEL1_CMP11LPMXSEL_S));
    }
    else
    {
        MODIFY_REG(ANASS->CMPLPMXSEL.WORDVAL, (uint32_t)(ANASS_CMPLPMXSEL_CMP1LPMXSEL_M << (uint32_t)select),
                   (uint32_t)(value << (uint32_t)select));
    }
}

/**
  * \brief  Select the value for CMPHNMXSEL.
  * \param  select    select is of type ANASS_CMPHNMuxSelect.
  *                    This parameter can be can be any value of @ref ANASS_CMPHNMUXSELECT.
  * \param  value     value is 0 or 1.
  *                    - 0: clear
  *                    - 1: set
  */
static inline void ANASS_selectCMPHNMuxValue (ANASS_CMPHNMuxSelect select, bool value)
{
    if (value)
    {
        SET_BIT(ANASS->CMPHNMXSEL.WORDVAL, (uint32_t)select);
    }
    else
    {
        CLEAR_BIT(ANASS->CMPHNMXSEL.WORDVAL, (uint32_t)select);
    }
}

/**
  * \brief  Select the value for CMPLNMXSEL.
  * \param  select    select is of type ANASS_CMPLNMuxSelect.
  *                    This parameter can be can be any value of @ref ANASS_CMPLNMUXSELECT.
  * \param  value     value is 0 or 1.
  *                    - 0: clear
  *                    - 1: set
  */
static inline void ANASS_selectCMPLNMuxValue (ANASS_CMPLNMuxSelect select, bool value)
{
    if (value)
    {
        SET_BIT(ANASS->CMPLNMXSEL.WORDVAL, (uint32_t)select);
    }
    else
    {
        CLEAR_BIT(ANASS->CMPLNMXSEL.WORDVAL, (uint32_t)select);
    }
}

/**
  * \brief  Locks the analog reference control register.
  */
static inline void ANASS_lockANAREF (void)
{
    SET_BIT(ANASS->LOCK.WORDVAL, ANASS_LOCK_ANAREFCTL_M);
}

/**
  * \brief  Locks the CMPHPMXSEL control register.
  */
static inline void ANASS_lockCMPHPMux (void)
{
    SET_BIT(ANASS->LOCK.WORDVAL, ANASS_LOCK_CMPHPMXSEL_M);
}

/**
  * \brief  Locks the CMPLPMXSEL control register.
  */
static inline void ANASS_lockCMPLPMux (void)
{
    SET_BIT(ANASS->LOCK.WORDVAL, ANASS_LOCK_CMPLPMXSEL_M);
}

/**
  * \brief  Locks the CMPHNMXSEL control register.
  */
static inline void ANASS_lockCMPHNMux (void)
{
    SET_BIT(ANASS->LOCK.WORDVAL, ANASS_LOCK_CMPHNMXSEL_M);
}

/**
  * \brief  Locks the CMPLNMXSEL control register.
  */
static inline void ANASS_lockCMPLNMux (void)
{
    SET_BIT(ANASS->LOCK.WORDVAL, ANASS_LOCK_CMPLNMXSEL_M);
}

/**
  * \brief  Locks the CMPHPMXSEL1 control register.
  */
static inline void ANASS_lockCMPHPMux1 (void)
{
    SET_BIT(ANASS->LOCK.WORDVAL, ANASS_LOCK_CMPHPMXSEL1_M);
}

/**
  * \brief  Locks the CMPLPMXSEL1 control register.
  */
static inline void ANASS_lockCMPLPMux1 (void)
{
    SET_BIT(ANASS->LOCK.WORDVAL, ANASS_LOCK_CMPLPMXSEL1_M);
}

/**
  * \brief  Config the Internal test control register.
  * \param  internalNode    Decide which node connect to ADC internal test.
  *                          This parameter can be any value of @ref ANASS_InternalTestCtl
  */
static inline void ANASS_selectInternalTest (ANASS_InternalTestCtl internalNode)
{
    WRITE_REG(ANASS->INTERNALTESTCTL.WORDVAL, (ANASS_INTERNALTESTCTL_KEY | (uint32_t)internalNode));
}

/**
  * \brief  Config the  ADC global SOC force register.
  * \param  soc_Pos    Indicate which SOC is selected for global SW trigger.
  *                     This parameter can be any value of @ref ANASS_ADCGlobalSocForce
  * \param  enable     Decide whether select soc force global SW trigger or not.
  *                     - 0: Disable
  *                     - 1: Enable
  */
static inline void ANASS_configADCSocForceGlobal (ANASS_ADCGlobalSocForce soc_Pos, bool enable)
{
    if(enable)
    {
        SET_BIT(ANASS->ADCSOCFRCGB.WORDVAL, (uint32_t)(0x01 << (uint32_t)soc_Pos));
    }
    else
    {
        CLEAR_BIT(ANASS->ADCSOCFRCGB.WORDVAL, (uint32_t)(0x01 << (uint32_t)soc_Pos));
    }
}

/**
  * \brief  Select the  ADC global SOC force register.
  * \param  adc_Num    Indicate which ADC is selected for global SW trigger.
  *                     This parameter can be any value of @ref ANASS_ADCGlobalSocForceSelect
  * \param  enable     Decide whether select adc force global SW trigger or not.
  *                     - 0: Disable
  *                     - 1: Enable
  */
static inline void ANASS_selectADCSocForceGlobal (ANASS_ADCGlobalSocForceSelect adc_Num, bool enable)
{
    if(enable)
    {
        SET_BIT(ANASS->ADCSOCFRCGBSEL.WORDVAL, (uint32_t)adc_Num);
    }
    else
    {
        CLEAR_BIT(ANASS->ADCSOCFRCGBSEL.WORDVAL, (uint32_t)adc_Num);
    }
}

/**
  * \brief  Enable GPIO as AGPIO function.
  * \param  pin    Decide which GPIO select as AGPIO function.
  *                 This parameter can be any value of @ref ANASS_AGPIOCtrl
  */
static inline void ANASS_enableAGpio (ANASS_AGPIOCtrl pin)
{
    uint16_t pinPos = pin % 32;
    if(pin <= ANASS_AGPIOCTRL_GPIO_214 )
    {
        SET_BIT(ANASS->AGPIOCTRLA.WORDVAL, (uint32_t)(0x01UL << 0x1EUL));
    }
    else if(pin <= ANASS_AGPIOCTRL_GPIO_215 )
    {
        SET_BIT(ANASS->AGPIOCTRLA.WORDVAL, (uint32_t)(0x01UL << 0x1CUL));
    }
    else if(pin <= ANASS_AGPIOCTRL_GPIO_216 )
    {
        SET_BIT(ANASS->AGPIOCTRLA.WORDVAL, (uint32_t)(0x01UL << 0x1DUL));
    }
    else if(pin <= ANASS_AGPIOCTRL_GPIO_217 )
    {
        SET_BIT(ANASS->AGPIOCTRLA.WORDVAL, (uint32_t)(0x01UL << 0x1FUL));
    }
    else if(pin == ANASS_AGPIOCTRL_GPIO_218 )
    {
        SET_BIT(ANASS->AGPIOCTRLB.WORDVAL, (uint32_t)(0x01UL << pinPos));
    }
    else if(pin >= ANASS_AGPIOCTRL_GPIO_198 )
    {
        SET_BIT(ANASS->AGPIOCTRLG.WORDVAL, (uint32_t)(0x01UL << pinPos));
    }
}

/**
  * \brief  Disable GPIO as AGPIO function.
  * \param  pin    Decide which GPIO disable AGPIO function.
  *                 This parameter can be any value of @ref ANASS_AGPIOCtrl
  */
static inline void ANASS_disableAGpio (ANASS_AGPIOCtrl pin)
{
    uint16_t pinPos = pin % 32;
    if(pin <= ANASS_AGPIOCTRL_GPIO_214 )
    {
        CLEAR_BIT(ANASS->AGPIOCTRLA.WORDVAL, (uint32_t)(0x01UL << 0x1EUL));
    }
    else if(pin <= ANASS_AGPIOCTRL_GPIO_215 )
    {
        CLEAR_BIT(ANASS->AGPIOCTRLA.WORDVAL, (uint32_t)(0x01UL << 0x1CUL));
    }
    else if(pin <= ANASS_AGPIOCTRL_GPIO_216 )
    {
        CLEAR_BIT(ANASS->AGPIOCTRLA.WORDVAL, (uint32_t)(0x01UL << 0x1DUL));
    }
    else if(pin <= ANASS_AGPIOCTRL_GPIO_217 )
    {
        CLEAR_BIT(ANASS->AGPIOCTRLA.WORDVAL, (uint32_t)(0x01UL << 0x1FUL));
    }
    else if(pin == ANASS_AGPIOCTRL_GPIO_218 )
    {
        CLEAR_BIT(ANASS->AGPIOCTRLB.WORDVAL, (uint32_t)(0x01UL << pinPos));
    }
    else if(pin >= ANASS_AGPIOCTRL_GPIO_198 )
    {
        CLEAR_BIT(ANASS->AGPIOCTRLG.WORDVAL, (uint32_t)(0x01UL << pinPos));
    }
}

/**
  * \brief  Set ADC synchronous register.
  * \param  adc_Num    Indicate which ADC is selected for global SW trigger.
  *                     This parameter can be any value of @ref ANASS_ADCSync
  * \attention  The relevant bit fields that need to be synchronized by the ADC 
  *             need to be written at once!!!
  *             For example, to synchronize 3 ADCs, adc_sync = 0x07.
  */
static inline void ANASS_setADCSync (uint32_t adc_sync)
{
    SET_BIT(ANASS->ADCSYNC.WORDVAL, adc_sync);
}


#ifdef __cplusplus
}
#endif


#endif /* __ANASS_H__ */
