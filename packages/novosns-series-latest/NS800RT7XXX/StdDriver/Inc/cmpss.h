/**
  * @file       cmpss.h
  * @author     zhoukai
  * @brief      Header file for NS800RT7xxx cmpss module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __CMPSS_H__
#define __CMPSS_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_cmpss.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup CMPSS_EXPORTED_TYPES CMPSS Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'CMPSS' module.
  */

/** @defgroup CMPSS_CMPTRIPOUTSEL CMPSS Tripout Source Select.
  * @{
  * @brief  Macro definitions about CMPSS tripout source select.
  *         Values that can be passed to CMPSS_configCtripOutLow() \ CMPSS_configCtripOutHigh() as the \e sel parameter.
  */ 
typedef enum {                                          
    CMPSS_TRIPOUT_ASYNC_COMP = 0x00UL,    /*!< Asynchronous comparator output drives CTRIPOUT */
    CMPSS_TRIPOUT_SYNC_COMP  = 0x10UL,    /*!< Synchronous comparator output drives CTRIPOUT */
    CMPSS_TRIPOUT_FILTER     = 0x20UL,    /*!< Filter output drives CTRIPOUT */
    CMPSS_TRIPOUT_LATCH      = 0x30UL     /*!< Latched filter output drives CTRIPOUT */
} CMPSS_TripoutSelect;

/**
  * @}
  */

/** @defgroup CMPSS_CMPTRIPSEL CMPSS Trip Source Select.
  * @{
  * @brief  Macro definitions about CMPSS trip source select.
  *         Values that can be passed to CMPSS_configCtripLow() \ CMPSS_configCtripHigh() as the \e sel parameter.
  */ 
typedef enum {                                          
    CMPSS_TRIP_ASYNC_COMP = 0x00UL,    /*!< Asynchronous comparator output drives CTRIP */
    CMPSS_TRIP_SYNC_COMP  = 0x04UL,    /*!< Synchronous comparator output drives CTRIP */
    CMPSS_TRIP_FILTER     = 0x08UL,    /*!< Filter output drives CTRIP */
    CMPSS_TRIP_LATCH      = 0x0CUL     /*!< Latched filter output drives CTRIP */
} CMPSS_TripSelect;

/**
  * @}
  */

/** @defgroup CMPSS_LPMSEL Low Power Wakeup Selection Register.
  * @{
  * @brief  Macro definitions about CMPSS Low power wakeup selection register.
  *         Values that can be passed to CMPSS_enableAsyncInvExti() as the \e sel parameter.
  */ 
typedef enum {                                          
    CMPSS_1  = 0x01UL,     /*!< CMPSS 1 */
    CMPSS_2  = 0x02UL,     /*!< CMPSS 2 */
    CMPSS_3  = 0x04UL,     /*!< CMPSS 3 */
    CMPSS_4  = 0x08UL,     /*!< CMPSS 4 */
    CMPSS_5  = 0x10UL,     /*!< CMPSS 5 */
    CMPSS_6  = 0x20UL,     /*!< CMPSS 6 */
    CMPSS_7  = 0x40UL,     /*!< CMPSS 7 */
    CMPSS_8  = 0x80UL,     /*!< CMPSS 8 */
    CMPSS_9  = 0x100U,     /*!< CMPSS 9 */
    CMPSS_10 = 0x200UL,    /*!< CMPSS 10 */
    CMPSS_11 = 0x400UL     /*!< CMPSS 11 */
} CMPSS_LPMSelect;

/**
  * @}
  */

/** @defgroup CMPSS_COMPHYSL CMPSS Hysteresis Select.
  * @{
  * @brief  Macro definitions about CMPSS hysteresis select.
  *         Values that can be passed to CMPSS_setHysteresis() as the \e mode parameter.
  */ 
typedef enum {                                          
    CMPSS_COMPHYS_NONE = 0x00UL,    /*!< No hysteresis */
    CMPSS_COMPHYS_TYPICAL,          /*!< Set hysteresis as typical value  */
    CMPSS_COMPHYS_TYPICAL2,         /*!< Set hysteresis as 2 times typical value */
    CMPSS_COMPHYS_TYPICAL3,         /*!< Set hysteresis as 3 times typical value */
    CMPSS_COMPHYS_TYPICAL4          /*!< Set hysteresis as 4 times typical value */
} CMPSS_COMPHYSelect;

/**
  * @}
  */

/** @defgroup CMPSS_FREESOFTMODE CMPSS FreeSoft Mode Select.
  * @{
  * @brief  Macro definitions about CMPSS freesoft mode select.
  *         Values that can be passed to CMPSS_configFreesoft() as the \e mode parameter.
  */ 
typedef enum {                                          
    CMPSS_FREESOFT_0 = 0x00UL,    /*!< Ramp generator stops immediately during emulation suspend */
    CMPSS_FREESOFT_1,             /*!< Ramp generator completes current ramp and stops at next EPWMSYNCPER during emulation suspend */
    CMPSS_FREESOFT_2,             /*!< Ramp generator runs freely */
    CMPSS_FREESOFT_3              /*!< Ramp generator runs freely */
} CMPSS_FreeSoftSelect;

/**
  * @}
  */

/** @defgroup CMPSS_EPWMBLANKSEL CMPSS EpwmBlank Source Select.
  * @{
  * @brief  Macro definitions about CMPSS epwmblank source select.  
  *         Values that can be passed to CMPSS_configBlanking() as the \e pwmBlankSrc parameter.
  */ 
typedef enum {                                          
    CMPSS_EPWM1_BLANK = 0x00UL,    /*!< EPWM1BLANK Signal */
    CMPSS_EPWM2_BLANK,             /*!< EPWM2BLANK Signal */
    CMPSS_EPWM3_BLANK,             /*!< EPWM3BLANK Signal */
    CMPSS_EPWM4_BLANK,             /*!< EPWM4BLANK Signal */
    CMPSS_EPWM5_BLANK,             /*!< EPWM5BLANK Signal */
    CMPSS_EPWM6_BLANK,             /*!< EPWM6BLANK Signal */
    CMPSS_EPWM7_BLANK,             /*!< EPWM7BLANK Signal */
    CMPSS_EPWM8_BLANK,             /*!< EPWM8BLANK Signal */
    CMPSS_EPWM9_BLANK,             /*!< EPWM9BLANK Signal */
    CMPSS_EPWM10_BLANK,            /*!< EPWM10BLANK Signal */
    CMPSS_EPWM11_BLANK,            /*!< EPWM11BLANK Signal */
    CMPSS_EPWM12_BLANK,            /*!< EPWM12BLANK Signal */
    CMPSS_EPWM13_BLANK,            /*!< EPWM13BLANK Signal */
    CMPSS_EPWM14_BLANK,            /*!< EPWM14BLANK Signal */
    CMPSS_EPWM15_BLANK,            /*!< EPWM15BLANK Signal */
    CMPSS_EPWM16_BLANK             /*!< EPWM16BLANK Signal */
} CMPSS_EpwmBlankSelect;

/**
  * @}
  */

/** @defgroup CMPSS_EPWMSYNCPERSEL CMPSS EpwmSyncPer Source Select.
  * @{
  * @brief  Macro definitions about CMPSS epwmsyncper source select. 
  *         Values that can be passed to CMPSS_configureSyncSource() as the \e syncPerSource parameter.
  */ 
typedef enum {                                          
    CMPSS_EPWM1_SYNCPER = 0x00UL,    /*!< EPWM1SYNCPER Signal */
    CMPSS_EPWM2_SYNCPER,             /*!< EPWM2SYNCPER Signal */
    CMPSS_EPWM3_SYNCPER,             /*!< EPWM3SYNCPER Signal */
    CMPSS_EPWM4_SYNCPER,             /*!< EPWM4SYNCPER Signal */
    CMPSS_EPWM5_SYNCPER,             /*!< EPWM5SYNCPER Signal */
    CMPSS_EPWM6_SYNCPER,             /*!< EPWM6SYNCPER Signal */
    CMPSS_EPWM7_SYNCPER,             /*!< EPWM7SYNCPER Signal */
    CMPSS_EPWM8_SYNCPER,             /*!< EPWM8SYNCPER Signal */
    CMPSS_EPWM9_SYNCPER,             /*!< EPWM9SYNCPER Signal */
    CMPSS_EPWM10_SYNCPER,            /*!< EPWM10SYNCPER Signal */
    CMPSS_EPWM11_SYNCPER,            /*!< EPWM11SYNCPER Signal */
    CMPSS_EPWM12_SYNCPER,            /*!< EPWM12SYNCPER Signal */
    CMPSS_EPWM13_SYNCPER,            /*!< EPWM13SYNCPER Signal */
    CMPSS_EPWM14_SYNCPER,            /*!< EPWM14SYNCPER Signal */
    CMPSS_EPWM15_SYNCPER,            /*!< EPWM15SYNCPER Signal */
    CMPSS_EPWM16_SYNCPER             /*!< EPWM16SYNCPER Signal */
} CMPSS_EpwmSyncPerSelect;

/**
  * @}
  */

/** @defgroup CMPSS_DEACTIVESEL CMPSS Deactive Source Select.
  * @{
  * @brief  Macro definitions about CMPSS epwmdeactive source select. 
  *         Values that can be passed to CMPSS_selectDEACTIVESource() as the \e syncPerSource parameter.
  */ 
typedef enum {                                          
    CMPSS_EPWM1_Deactive = 0x00UL,    /*!< EPWM1SYNCPER Signal */
    CMPSS_EPWM2_Deactive,             /*!< EPWM2SYNCPER Signal */
    CMPSS_EPWM3_Deactive,             /*!< EPWM3SYNCPER Signal */
    CMPSS_EPWM4_Deactive,             /*!< EPWM4SYNCPER Signal */
    CMPSS_EPWM5_Deactive,             /*!< EPWM5SYNCPER Signal */
    CMPSS_EPWM6_Deactive,             /*!< EPWM6SYNCPER Signal */
    CMPSS_EPWM7_Deactive,             /*!< EPWM7SYNCPER Signal */
    CMPSS_EPWM8_Deactive,             /*!< EPWM8SYNCPER Signal */
    CMPSS_EPWM9_Deactive,             /*!< EPWM9SYNCPER Signal */
    CMPSS_EPWM10_Deactive,            /*!< EPWM10SYNCPER Signal */
    CMPSS_EPWM11_Deactive,            /*!< EPWM11SYNCPER Signal */
    CMPSS_EPWM12_Deactive,            /*!< EPWM12SYNCPER Signal */
    CMPSS_EPWM13_Deactive,            /*!< EPWM13SYNCPER Signal */
    CMPSS_EPWM14_Deactive,            /*!< EPWM14SYNCPER Signal */
    CMPSS_EPWM15_Deactive,            /*!< EPWM15SYNCPER Signal */
    CMPSS_EPWM16_Deactive,            /*!< EPWM16SYNCPER Signal */
    CMPSS_EPWM17_Deactive,            /*!< EPWM17SYNCPER Signal */
    CMPSS_EPWM18_Deactive             /*!< EPWM18SYNCPER Signal */
} CMPSS_DeactiveSelect;

/**
  * @}
  */

/** @defgroup CMPSS_XTRIGCFG CMPSS Cross Trigger Config.
  * @{
  * @brief  Macro definitions about CMPSS cross trigger config. 
  *         Values that can be passed to CMPSS_configureSyncSource() as the \e syncPerSource parameter.
  */ 
typedef enum {                                          
    CMPSS_XTRIGCFG_H_INDEPEND_L = 0x00UL,    /*!< RAMPH & RAMPL work independent */
    CMPSS_XTRIGCFG_H_XTRIG_L,                /*!< RAMPL cross trigged by RAMPH */
    CMPSS_XTRIGCFG_L_XTRIG_H                 /*!< RAMPH cross trigged by RAMPL */
} CMPSS_RampXTrigger;

/**
  * @}
  */

/** @defgroup CMPSS_RAMPDIRECTION CMPSS Ramp Direction Config.
  * @{
  * @brief  Macro definitions about CMPSS cross trigger config. 
  *         Values that can be passed to CMPSS_configRampxxx() as the \e syncPerSource parameter.
  */ 
typedef enum
{
    CMPSS_RAMP_DIR_DOWN = 0x00UL,      /*!< RAMP decrease direction control */
    CMPSS_RAMP_DIR_UP   = 0x10000UL    /*!< RAMP increase direction control */
} CMPSS_RampDirection;

/**
  * @}
  */

/** @defgroup CMPSS_FILTINSEL Filter Input Select Register.
  * @{
  * @brief  Macro definitions about CMPSS filter input select register.
  *         Values that can be passed to CMPSS_enableAsyncInvExti() as the \e sel parameter.
  */ 
typedef enum {                                          
    CMPSS_FILTINSEL_COMP        = 0x00UL,    /*!< Select COMP output as the input of filter */
    CMPSS_FILTINSEL_EXT_FILTIN1 = 0x01UL,    /*!< Select exti filterIn_1 as the input of filter */
    CMPSS_FILTINSEL_EXT_FILTIN2 = 0x02UL,    /*!< Select exti filterIn_2 as the input of filter */
    CMPSS_FILTINSEL_EXT_FILTIN3 = 0x03UL,    /*!< Select exti filterIn_3 as the input of filter */
    CMPSS_FILTINSEL_EXT_FILTIN4 = 0x04UL,    /*!< Select exti filterIn_4 as the input of filter */
    CMPSS_FILTINSEL_EXT_FILTIN5 = 0x05UL,    /*!< Select exti filterIn_5 as the input of filter */
    CMPSS_FILTINSEL_EXT_FILTIN6 = 0x06UL,    /*!< Select exti filterIn_6 as the input of filter */
    CMPSS_FILTINSEL_EXT_FILTIN7 = 0x07UL     /*!< Select exti filterIn_7 as the input of filter */
} CMPSS_FilterInputSelect;

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
  * \brief  Enable the Lowcomparator low power mode.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_enableLowComparatorLpm (CMPSS_TypeDef *cmpss)
{
    SET_BIT(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_COMPLLPMEN);
}

/**
  * \brief  Low Comparator Asynchronous Output Software Control.
  * \param  cmpss      The base address of the CMPSS module.
  *                     - CMPSS1: CMPSS1 base address index
  *                     - CMPSS2: CMPSS2 base address index
  *                     - CMPSS3: CMPSS3 base address index
  *                     - CMPSS4: CMPSS4 base address index
  *                     - CMPSS5: CMPSS5 base address index
  *                     - CMPSS6: CMPSS6 base address index
  *                     - CMPSS7: CMPSS7 base address index
  *                     - CMPSS8: CMPSS8 base address index
  *                     - CMPSS9: CMPSS9 base address index
  *                     - CMPSS10: CMPSS10 base address index
  *                     - CMPSS11: CMPSS11 base address index
  * \param  control    The asynchronous output of the comparator is either forced to 0 or 
  *                    depends on the actual result.
  *                     - 0: The asynchronous output of the comparator depends on the 
  *                          actual comparison result.
  *                     - 1: The asynchronous output of the comparator is forcibly 
  *                          configured to 0 by software.
  */
static inline void CMPSS_configLowComparatorAsynOut (CMPSS_TypeDef *cmpss, bool control)
{
    if (control)
    {
        SET_BIT(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_COMPLANAVOSW);
    }
    else
    {
        CLEAR_BIT(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_COMPLANAVOSW);
    }
}

/**
  * \brief  Enable the high comparator low power mode.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_enableHighComparatorLpm (CMPSS_TypeDef *cmpss)
{
    SET_BIT(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_COMPHLPMEN);
}

/**
  * \brief  High Comparator Asynchronous Output Software Control.
  * \param  cmpss      The base address of the CMPSS module.
  *                     - CMPSS1: CMPSS1 base address index
  *                     - CMPSS2: CMPSS2 base address index
  *                     - CMPSS3: CMPSS3 base address index
  *                     - CMPSS4: CMPSS4 base address index
  *                     - CMPSS5: CMPSS5 base address index
  *                     - CMPSS6: CMPSS6 base address index
  *                     - CMPSS7: CMPSS7 base address index
  *                     - CMPSS8: CMPSS8 base address index
  *                     - CMPSS9: CMPSS9 base address index
  *                     - CMPSS10: CMPSS10 base address index
  *                     - CMPSS11: CMPSS11 base address index
  * \param  control    The asynchronous output of the comparator is either forced to 0 or 
  *                    depends on the actual result.
  *                     - 0: The asynchronous output of the comparator depends on the actual comparison result.
  *                     - 1: The asynchronous output of the comparator is forcibly configured to 0 by software.
  */
static inline void CMPSS_configHighComparatorAsynOut (CMPSS_TypeDef *cmpss, bool control)
{
    if (control)
    {
        SET_BIT(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_COMPHANAVOSW);
    }
    else
    {
        CLEAR_BIT(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_COMPHANAVOSW);
    }
}

/**
  * \brief  Enable the Low CMPSS module.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_enableLowModule (CMPSS_TypeDef *cmpss)
{
    SET_BIT(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_COMPDACEL);
}

/**
  * \brief  Disable the Low CMPSS module.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_disableLowModule (CMPSS_TypeDef *cmpss)
{
    CLEAR_BIT(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_COMPDACEL);
}

/**
  * \brief  Enable the High CMPSS module.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_enableHighModule (CMPSS_TypeDef *cmpss)
{
    SET_BIT(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_COMPDACEH);
}

/**
  * \brief  Disable the High CMPSS module.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_disableHighModule (CMPSS_TypeDef *cmpss)
{
    CLEAR_BIT(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_COMPDACEH);
}

/**
  * \brief  Enable Low comparator asynchronous path enable.
  * \param  cmpss      The base address of the CMPSS module.
  *                     - CMPSS1: CMPSS1 base address index
  *                     - CMPSS2: CMPSS2 base address index
  *                     - CMPSS3: CMPSS3 base address index
  *                     - CMPSS4: CMPSS4 base address index
  *                     - CMPSS5: CMPSS5 base address index
  *                     - CMPSS6: CMPSS6 base address index
  *                     - CMPSS7: CMPSS7 base address index
  *                     - CMPSS8: CMPSS8 base address index
  *                     - CMPSS9: CMPSS9 base address index
  *                     - CMPSS10: CMPSS10 base address index
  *                     - CMPSS11: CMPSS11 base address index
  * \param  control    Low comparator asynchronous path enable.
  *                     - 0: Asynchronous comparator output does not feed into OR gate with latched digital filter output.
  *                     - 1: Asynchronous comparator output feeds into OR gate with latched digital filter output.
  */
static inline void CMPSS_enableAsyncL (CMPSS_TypeDef *cmpss, bool control)
{
    if (control)
    {
        SET_BIT(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_ASYNCLEN);
    }
    else
    {
        CLEAR_BIT(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_ASYNCLEN);
    }
}

/**
  * \brief  Enable High comparator asynchronous path enable.
  * \param  cmpss      The base address of the CMPSS module.
  *                     - CMPSS1: CMPSS1 base address index
  *                     - CMPSS2: CMPSS2 base address index
  *                     - CMPSS3: CMPSS3 base address index
  *                     - CMPSS4: CMPSS4 base address index
  *                     - CMPSS5: CMPSS5 base address index
  *                     - CMPSS6: CMPSS6 base address index
  *                     - CMPSS7: CMPSS7 base address index
  *                     - CMPSS8: CMPSS8 base address index
  *                     - CMPSS9: CMPSS9 base address index
  *                     - CMPSS10: CMPSS10 base address index
  *                     - CMPSS11: CMPSS11 base address index
  * \param  control    High comparator asynchronous path enable.
  *                     - 0: Asynchronous comparator output does not feed into OR gate with latched digital filter output.
  *                     - 1: Asynchronous comparator output feeds into OR gate with latched digital filter output.
  */
static inline void CMPSS_enableAsyncH (CMPSS_TypeDef *cmpss, bool control)
{
    if (control)
    {
        SET_BIT(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_ASYNCHEN);
    }
    else
    {
        CLEAR_BIT(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_ASYNCHEN);
    }
}

/**
  * \brief  Low Comparator CtripOut Select.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  sel      Low Comparator CtripOut Select.
  *                   This parameter can be any value of @ref CMPSS_CMPTRIPOUTSEL. 
  */
static inline void CMPSS_configCtripOutLow (CMPSS_TypeDef *cmpss, CMPSS_TripoutSelect sel)
{
    MODIFY_REG(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_CTRIPOUTLSEL_M, (uint32_t)(sel << CMPSS_COMPCTL_CTRIPOUTLSEL_S));
}

/**
  * \brief  Low Comparator Ctrip Select.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  sel      Low Comparator Ctrip Select.
  *                   This parameter can be any value of @ref CMPSS_CMPTRIPSEL. 
  */
static inline void CMPSS_configCtripLow (CMPSS_TypeDef *cmpss, CMPSS_TripSelect sel)
{
    MODIFY_REG(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_CTRIPLSEL_M, (uint32_t)(sel << CMPSS_COMPCTL_CTRIPLSEL_S));
}

/**
  * \brief  Sets the configuration for the high comparator.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  * \param  config    The \e config parameter is the result of a logical OR operation between 
  *                   a \b CMPSS_COMPCTL_COMPHSOURCE value and the \b CMPSS_COMPCTL_COMPHINV 
  *                   and \b CMPSS_COMPCTL_ASYNCHEN values.  
  */
static inline void CMPSS_configHighComparator (CMPSS_TypeDef *cmpss, uint32_t config)
{
    MODIFY_REG(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_COMPHSOURCE | CMPSS_COMPCTL_COMPHINV | CMPSS_COMPCTL_ASYNCHEN,
               (uint32_t)config);
}    

/**
  * \brief  Sets the configuration for the low comparator.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  * \param  config    The \e config parameter is the result of a logical OR operation between 
  *                   a \b CMPSS_COMPCTL_COMPLSOURCE value and the \b CMPSS_COMPCTL_COMPLINV 
  *                   and \b CMPSS_COMPCTL_ASYNCLEN values. 
  */
static inline void CMPSS_configLowComparator (CMPSS_TypeDef *cmpss, uint32_t config)
{
    MODIFY_REG(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_COMPLSOURCE | CMPSS_COMPCTL_COMPLINV | CMPSS_COMPCTL_ASYNCLEN,
               (uint32_t)config);
}

/**
  * \brief  Sets the output signal configuration for the high comparator.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  * \param  config    The \e config parameter is the result of a logical OR operation between the 
  *                   \b CMPSS_TRIPOUT_xxx and \b CMPSS_TRIP_xxx values.
  *                   The \b CMPSS_TRIPOUT_xxx term can take on the following values to specify which 
  *                   signal drives CTRIPOUTL:
  *                    - CMPSS_TRIPOUT_ASYNC_COMP 
  *                    - CMPSS_TRIPOUT_SYNC_COMP 
  *                    - CMPSS_TRIPOUT_FILTER 
  *                    - CMPSS_TRIPOUT_LATCH 
  *                   The \b CMPSS_TRIP_xxx term can take on the following values to specify which 
  *                   signal drives CTRIPL:
  *                    - CMPSS_TRIP_ASYNC_COMP 
  *                    - CMPSS_TRIP_SYNC_COMP 
  *                    - CMPSS_TRIP_FILTER 
  *                    - CMPSS_TRIP_LATCH 
  */
static inline void CMPSS_configOutputsHigh (CMPSS_TypeDef *cmpss, uint16_t config)
{
    MODIFY_REG(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_CTRIPOUTHSEL_M | CMPSS_COMPCTL_CTRIPHSEL_M, (uint32_t)config);
}

/**
  * \brief  Sets the output signal configuration for the low comparator.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  * \param  config    The \e config parameter is the result of a logical OR operation between the 
  *                   \b CMPSS_TRIPOUT_xxx and \b CMPSS_TRIP_xxx values.
  *                   The \b CMPSS_TRIPOUT_xxx term can take on the following values to specify which 
  *                   signal drives CTRIPOUTL:
  *                    - CMPSS_TRIPOUT_ASYNC_COMP 
  *                    - CMPSS_TRIPOUT_SYNC_COMP 
  *                    - CMPSS_TRIPOUT_FILTER 
  *                    - CMPSS_TRIPOUT_LATCH 
  *                   The \b CMPSS_TRIP_xxx term can take on the following values to specify which 
  *                   signal drives CTRIPL:
  *                    - CMPSS_TRIP_ASYNC_COMP 
  *                    - CMPSS_TRIP_SYNC_COMP 
  *                    - CMPSS_TRIP_FILTER 
  *                    - CMPSS_TRIP_LATCH 
  */
static inline void CMPSS_configOutputsLow (CMPSS_TypeDef *cmpss, uint16_t config)
{
    MODIFY_REG(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_CTRIPOUTLSEL_M | CMPSS_COMPCTL_CTRIPLSEL_M,
               (uint32_t)(config << 8UL));
}

/**
  * \brief  Enable the comparator's asynchronous output to be inverted and then output to EXTI.
  * \param  cmpss      The index of the CMPSS module.
  *                     This parameter can be any value of @ref CMPSS_LPMSelect
  * \param  control    Low Comparator CtripOut Select.
  *                     - 0: enable.
  *                     - 1: disable.
  */
static inline void CMPSS_enableAsyncInvExti (CMPSS_LPMSelect cmpss, bool control)
{
    if (control)
    {
        SET_BIT(SYSCON->CMPSSLPMSEL.WORDVAL, cmpss);
    }
    else
    {
        CLEAR_BIT(SYSCON->CMPSSLPMSEL.WORDVAL, cmpss);
    }
}

/**
  * \brief  High Comparator CtripOut Select.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  sel      High Comparator CtripOut Select.
  *                   This parameter can be any value of @ref CMPSS_CMPTRIPOUTSEL 
  */
static inline void CMPSS_configCtripOutHigh (CMPSS_TypeDef *cmpss, CMPSS_TripoutSelect sel)
{
    MODIFY_REG(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_CTRIPOUTHSEL_M, (uint32_t)(sel << CMPSS_COMPCTL_CTRIPOUTHSEL_S));
}

/**
  * \brief  High Comparator Ctrip Select.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  sel      High Comparator Ctrip Select.
  *                   This parameter can be any value of @ref CMPSS_CMPTRIPSEL 
  */
static inline void CMPSS_configCtripHigh (CMPSS_TypeDef *cmpss, CMPSS_TripSelect sel)
{
    MODIFY_REG(cmpss->COMPCTL.WORDVAL, CMPSS_COMPCTL_CTRIPHSEL_M, (uint32_t)(sel << CMPSS_COMPCTL_CTRIPHSEL_S));
}

/**
  * \brief  Sets the comparator hysteresis settings.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  value    Value is the amount of hysteresis on the comparator inputs.
  *                   This parameter can be any value of @ref CMPSS_COMPHYSelect
  */
static inline void CMPSS_setHysteresis (CMPSS_TypeDef *cmpss, CMPSS_COMPHYSelect value)
{
    MODIFY_REG(cmpss->COMPHYSCTL.WORDVAL, CMPSS_COMPHYSCTL_COMPLHYS_M,
               (uint32_t)(value << CMPSS_COMPHYSCTL_COMPLHYS_S));
}

/**
  * \brief  Gets the current comparator status.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \return Returns the current interrupt status
  */
static inline uint32_t CMPSS_getStatus (CMPSS_TypeDef *cmpss)
{
    return READ_REG(cmpss->COMPSTS.WORDVAL);
}

/**
  * \brief  Clear high comparator digital filter output latch.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_clearFilterLatchHigh (CMPSS_TypeDef *cmpss)
{
    SET_BIT(cmpss->COMPSTSCLR.WORDVAL, CMPSS_COMPSTSCLR_HLATCHCLR);
}

/**
  * \brief  Clear low comparator digital filter output latch.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_clearFilterLatchLow (CMPSS_TypeDef *cmpss)
{
    SET_BIT(cmpss->COMPSTSCLR.WORDVAL, CMPSS_COMPSTSCLR_LLATCHCLR);
}

/**
  * \brief  Enables reset of HIGH comparator digital filter output latch on PWMSYNC
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_enableLatchResetOnPWMSYNCHigh (CMPSS_TypeDef *cmpss)
{
    SET_BIT(cmpss->COMPSTSCLR.WORDVAL, CMPSS_COMPSTSCLR_HSYNCCLREN);
}

/**
  * \brief  Disables reset of HIGH comparator digital filter output latch on PWMSYNC
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_disableLatchResetOnPWMSYNCHigh (CMPSS_TypeDef *cmpss)
{
    CLEAR_BIT(cmpss->COMPSTSCLR.WORDVAL, CMPSS_COMPSTSCLR_HSYNCCLREN);
}

/**
  * \brief  Enables reset of LOW comparator digital filter output latch on PWMSYNC
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_enableLatchResetOnPWMSYNCLow (CMPSS_TypeDef *cmpss)
{
    SET_BIT(cmpss->COMPSTSCLR.WORDVAL, CMPSS_COMPSTSCLR_LSYNCCLREN);
}

/**
  * \brief  Disables reset of LOW comparator digital filter output latch on PWMSYNC
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_disableLatchResetOnPWMSYNCLow (CMPSS_TypeDef *cmpss)
{
    CLEAR_BIT(cmpss->COMPSTSCLR.WORDVAL, CMPSS_COMPSTSCLR_LSYNCCLREN);
}

/**
  * \brief  Sets the configuration for the internal comparator high DACs.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  * \param  config    The \e config parameter is the result of a logical OR operation between the 
  *                   \b CMPSS_DACSRC_xxx, \b CMPSS_DACREF_xxx, and \b CMPSS_DACVAL_xxx.  
  *                   The \b CMPSS_DACSRC_xxx term can take on the following values to specify 
  *                   the DAC value source for the high comparator's internal DAC:
  *                    - CMPSS_DACSRC_SHDW
  *                    - CMPSS_DACSRC_RAMP 
  *                   The \b CMPSS_DACREF_xxx term can take on the following values to specify 
  *                   which voltage supply is used as reference for the DACs:
  *                    - CMPSS_DACREF_VDDA
  *                    - CMPSS_DACREF_VREF
  *                    - CMPSS_DACREF_VDAC 
  *                   The \b CMPSS_DACVAL_xxx term can take on the following values to specify 
  *                   when the DAC value is loaded from its shadow register:
  *                    - CMPSS_DACVAL_SYSCLK 
  *                    - CMPSS_DACVAL_PWMSYNC 
  */
static inline void CMPSS_configHighDAC (CMPSS_TypeDef *cmpss, uint16_t config)
{
    MODIFY_REG(cmpss->COMPDACHCTL.WORDVAL,
               CMPSS_COMPDACHCTL_DACSOURCE | CMPSS_COMPDACHCTL_DACSELREF_M | CMPSS_COMPDACHCTL_SWLOADSEL,
               (uint32_t)config);
}

/**
  * \brief  Sets the ePWM module blanking signal that holds trip in reset of High DACs.
  * \param  cmpss          The base address of the CMPSS module.
  *                         - CMPSS1: CMPSS1 base address index
  *                         - CMPSS2: CMPSS2 base address index
  *                         - CMPSS3: CMPSS3 base address index
  *                         - CMPSS4: CMPSS4 base address index
  *                         - CMPSS5: CMPSS5 base address index
  *                         - CMPSS6: CMPSS6 base address index
  *                         - CMPSS7: CMPSS7 base address index
  *                         - CMPSS8: CMPSS8 base address index
  *                         - CMPSS9: CMPSS9 base address index
  *                         - CMPSS10: CMPSS10 base address index
  *                         - CMPSS11: CMPSS11 base address index
  * \param  pwmBlankSrc    Is the number of the PWMBLANK source.
  *                         This parameter can be any value of @ref CMPSS_EPWMBLANKSEL
  */
static inline void CMPSS_configBlankingSourceHigh (CMPSS_TypeDef *cmpss, CMPSS_EpwmBlankSelect pwmBlankSrc)  
{
    MODIFY_REG(cmpss->COMPDACHCTL.WORDVAL, CMPSS_COMPDACHCTL_BLANKSOURCE_M,
               (uint32_t)(pwmBlankSrc << CMPSS_COMPDACHCTL_BLANKSOURCE_S));
}

/**
  * \brief  Enables an ePWM blanking signal to hold trip in reset of High DACs.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_enableBlankingHigh (CMPSS_TypeDef *cmpss)
{
    SET_BIT(cmpss->COMPDACHCTL.WORDVAL, CMPSS_COMPDACHCTL_BLANKEN);
}

/**
  * \brief  Disables an ePWM blanking signal to hold trip in reset.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_disableBlankingHigh (CMPSS_TypeDef *cmpss)
{
    CLEAR_BIT(cmpss->COMPDACHCTL.WORDVAL, CMPSS_COMPDACHCTL_BLANKEN);
}

/**
  * \brief  Select which EPWMnSYNCPER signal is used within the High CMPSS module. 
  * \param  cmpss            The base address of the CMPSS module.
  *                           - CMPSS1: CMPSS1 base address index
  *                           - CMPSS2: CMPSS2 base address index
  *                           - CMPSS3: CMPSS3 base address index
  *                           - CMPSS4: CMPSS4 base address index
  *                           - CMPSS5: CMPSS5 base address index
  *                           - CMPSS6: CMPSS6 base address index
  *                           - CMPSS7: CMPSS7 base address index
  *                           - CMPSS8: CMPSS8 base address index
  *                           - CMPSS9: CMPSS9 base address index
  *                           - CMPSS10: CMPSS10 base address index
  *                           - CMPSS11: CMPSS11 base address index
  * \param  syncPerSource    Determines which EPWMnSYNCPER signal is used within the high CMPSS module.
  *                           This parameter can be any value of @ref CMPSS_EPWMSYNCPERSEL
  */
static inline void CMPSS_configureSyncSourceHigh (CMPSS_TypeDef *cmpss, CMPSS_EpwmSyncPerSelect syncPerSource)  
{
    MODIFY_REG(cmpss->COMPDACHCTL.WORDVAL, CMPSS_COMPDACHCTL_SYNCPERSOURCE_M,
               (uint32_t)(syncPerSource << CMPSS_COMPDACHCTL_SYNCPERSOURCE_S));
}

/**
  * \brief  Config Free-run or software-run emulation behavior for High DACs. 
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  mode     Behavior of the ramp generator during emulation suspend.
  *                   This parameter can be any value of @ref CMPSS_FREESOFTMODE
  */
static inline void CMPSS_configFreesoftHigh (CMPSS_TypeDef *cmpss, CMPSS_FreeSoftSelect mode)
{
    MODIFY_REG(cmpss->COMPDACHCTL.WORDVAL, CMPSS_COMPDACHCTL_FREESOFT_M,
               (uint32_t)(mode << CMPSS_COMPDACHCTL_FREESOFT_S));
}

/**
  * \brief  Config   High ramp generator direction.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  dir      High RAMP direction.
  *                   This parameter can be any value of @ref CMPSS_RampDirection
  */
static inline void CMPSS_setRAMPDirectionHigh (CMPSS_TypeDef *cmpss, CMPSS_RampDirection dir)
{
    if(CMPSS_RAMP_DIR_UP == dir)
    {
        SET_BIT(cmpss->COMPDACHCTL.WORDVAL, CMPSS_COMPDACHCTL_RAMPHDIR);
    }
    else
    {
        CLEAR_BIT(cmpss->COMPDACHCTL.WORDVAL, CMPSS_COMPDACHCTL_RAMPHDIR);
    }
}
    

/**
  * \brief  Config EPWM Deactive source for CMPSS. 
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  * \param  source    Source of EPWM deactive.
  *                    This parameter can be any value of @ref CMPSS_DeactiveSelect
  */
static inline void CMPSS_selectDEACTIVESource (CMPSS_TypeDef *cmpss, CMPSS_DeactiveSelect source)
{
    MODIFY_REG(cmpss->COMPDACHCTL2.WORDVAL, CMPSS_COMPDACHCTL2_DEACTIVESEL_M,
               (uint32_t)(source << CMPSS_COMPDACHCTL2_DEACTIVESEL_S));
}

/**
  * \brief  Configures high ramp generator cross trigger feature. 
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  source    Cross trigger config.
  *                   This parameter can be any value of @ref CMPSS_RampXTrigger
  */
static inline void CMPSS_configureRampXTriggerHigh (CMPSS_TypeDef *cmpss, CMPSS_RampXTrigger source)
{
    MODIFY_REG(cmpss->COMPDACHCTL2.WORDVAL, CMPSS_COMPDACHCTL2_XTRIGCFG_M,
               (uint32_t)(source << CMPSS_COMPDACHCTL2_XTRIGCFG_S));
}

/**
  * \brief  Select the Blank source group for high comparator.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  * \param  config    The \e config parameter is the result of a logical OR operation between the 
  *                   \b CMPSS_BLANKSOURCESEL_xxx and \b CMPSS_RAMPSOURCESEL_xxx.  
  *                   The \b CMPSS_BLANKSOURCESEL_xxx term can take on the following values to specify 
  *                   the BLANK source for COMPH:
  *                    - CMPSS_BLANKSOURCESEL_EPWM1_16
  *                    - CMPSS_BLANKSOURCESEL_EPWM17_18 
  */
static inline void CMPSS_selectBlankSourceGroupHigh (CMPSS_TypeDef *cmpss, uint16_t config)
{                                        
    MODIFY_REG(cmpss->COMPDACHCTL2.WORDVAL, CMPSS_COMPDACHCTL2_BLANKSOURCESEL, (uint32_t)config);
}

/**
  * \brief  Select the Ramp source group for high comparator.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  * \param  config    The \b CMPSS_RAMPSOURCESEL_xxx term can take on the following values to specify 
  *                   the RAMP source for RAMPH:
  *                    - CMPSS_RAMPSOURCESEL_EPWM1_16
  *                    - CMPSS_RAMPSOURCESEL_EPWM17_18
  */
static inline void CMPSS_selectRampSourceGroupHigh (CMPSS_TypeDef *cmpss, uint16_t config)
{                                        
    MODIFY_REG(cmpss->COMPDACHCTL2.WORDVAL, CMPSS_COMPDACHCTL2_RAMPSOURCESEL, (uint32_t)config);
}

/**
  * \brief  Enables Diode simulation mode.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_enableDEMode (CMPSS_TypeDef *cmpss)
{
    SET_BIT(cmpss->COMPDACHCTL2.WORDVAL, CMPSS_COMPDACHCTL2_DEENABLE);
}

/**
  * \brief  Disables Diode simulation mode.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_disableDEMode (CMPSS_TypeDef *cmpss)
{
    CLEAR_BIT(cmpss->COMPDACHCTL2.WORDVAL, CMPSS_COMPDACHCTL2_DEENABLE);
}

/**
  * \brief  Sets the value of the internal DAC of the high comparator.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  value    Value is the value actively driven by the DAC.
  *                   - uint8_t: 0x00 - 0xFF 
  */
static inline void CMPSS_setDACValueHigh (CMPSS_TypeDef *cmpss, uint8_t value)
{
    WRITE_REG(cmpss->DACHVALS.WORDVAL, (uint32_t)value);
}

/**
  * \brief  Sets the value of the internal DAC of the low comparator.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  value    Value is the value actively driven by the DAC.
  *                   - uint8_t: 0x00 - 0xFF 
  */
static inline void CMPSS_setDACValueLow (CMPSS_TypeDef *cmpss, uint8_t value)
{
    WRITE_REG(cmpss->DACLVALS.WORDVAL, (uint32_t)value);
}

/**
  * \brief  Sets the shadow value 2 (used in DE mode) of the internal DAC of the high comparator.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  value    Value is the value actively driven by the DAC.
  *                   - uint8_t: 0x00 - 0xFF 
  */
static inline void CMPSS_configHighDACShadowValueDE (CMPSS_TypeDef *cmpss, uint8_t value)
{
    WRITE_REG(cmpss->DACHVALS2.WORDVAL, (uint32_t)value);
}

/**
  * \brief  Sets the shadow value 2 (used in DE mode) of the internal DAC of the low comparator.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  value    Value is the value actively driven by the DAC.
  *                   - uint8_t: 0x00 - 0xFF 
  */
static inline void CMPSS_configLowDACShadowValueDE (CMPSS_TypeDef *cmpss, uint8_t value)
{
    WRITE_REG(cmpss->DACLVALS2.WORDVAL, (uint32_t)value);
}

/**
  * \brief  Gets the value of the internal DAC of the high comparator.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \return Returns the value driven by the internal DAC of the high comparator.
  *                   - uint8_t: 0x00 - 0xFF
  */
static inline uint8_t CMPSS_getDACValueHigh (CMPSS_TypeDef *cmpss)
{
    return (uint8_t)READ_REG(cmpss->DACHVALA.WORDVAL);
}

/**
  * \brief  Gets the value of the internal DAC of the low comparator.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \return Returns the value driven by the internal DAC of the low comparator.
  *                   - uint8_t: 0x00 - 0xFF
  */
static inline uint8_t CMPSS_getDACValueLow (CMPSS_TypeDef *cmpss)
{
    return (uint8_t)READ_REG(cmpss->DACLVALA.WORDVAL);
}

/**
  * \brief  Sets the high ramp generator reference value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  value    The ramp maximum reference value.
  *                   - uint16_t: 0x00 - 0xFFF
  */
static inline void CMPSS_setRampReferenceHigh (CMPSS_TypeDef *cmpss,  uint16_t value)
{
    WRITE_REG(cmpss->RAMPHREFS.WORDVAL, (uint32_t)value);
}

/**
  * \brief  Gets the high ramp generator reference value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \return Returns the latched ramp active reference value that will be loaded into the ramp generator.
  *                   - uint16_t: 0x00 - 0xFFF
  */
static inline uint16_t CMPSS_getRampReferenceHigh (CMPSS_TypeDef *cmpss)
{
    return (uint16_t)READ_REG(cmpss->RAMPHREFA.WORDVAL);
}

/**
  * \brief  Gets the high ramp generator active reference value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \return Returns the latched ramp active reference value that will be loaded into the ramp generator.
  *                   - uint16_t: 0x00 - 0xFFF
  */
static inline uint16_t CMPSS_getRampActValueHigh (CMPSS_TypeDef *cmpss)
{
    return (uint16_t)READ_REG(cmpss->RAMPHREFA.WORDVAL);
}

/**
  * \brief  Sets the high ramp generator step value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  value    Value is the ramp step value.
  *                   - uint16_t: 0x00 - 0xFFF
  */
static inline void CMPSS_setRampStepHigh (CMPSS_TypeDef *cmpss, uint16_t value)
{
    WRITE_REG(cmpss->RAMPHSTEPVALS.WORDVAL, (uint32_t)value);
}

/**
  * \brief  Gets the high ramp generator step value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \return Returns the latched ramp step value that is subtracted from the ramp value on 
  *         every system clock cycle.    
  *                   - uint16_t: 0x00 - 0xFFF
  */
static inline uint16_t CMPSS_getRampStepHigh (CMPSS_TypeDef *cmpss)
{
    return (uint16_t)READ_REG(cmpss->RAMPHSTEPVALA.WORDVAL);
}

/**
  * \brief  Sets the high ramp generator clock divid value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  value    Value is the clk divid value.
  *                   - uint16_t: 0x00 - 0xF
  */
static inline void CMPSS_setRampClockDividerHigh (CMPSS_TypeDef *cmpss, uint16_t value)
{
    WRITE_REG(cmpss->RAMPHCTLS.WORDVAL, (uint32_t)value);
}

/**
  * \brief  Gets the high ramp generator clock divid value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \return Returns the latched ramp clock divid value that will be loaded into the ramp generator.    
  *                   - uint16_t: 0x00 - 0xF
  */
static inline uint16_t CMPSS_getRampClockDividerHigh (CMPSS_TypeDef *cmpss)
{
    return (uint16_t)READ_REG(cmpss->RAMPHCTLA.WORDVAL);
}

/**
  * \brief  Sets the high ramp generator delay value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  value    Value is the 13-bit ramp delay value.
  *                   - uint16_t: 0x00 - 0x1FFF
  */
static inline void CMPSS_setRampDelayHigh (CMPSS_TypeDef *cmpss, uint16_t value)
{
    WRITE_REG(cmpss->RAMPHDLYS.WORDVAL, (uint32_t)value);
}

/**
  * \brief  Gets the high ramp generator delay value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  ** \return Returns the latched ramp delay value that configures the number
  *          of system clock cycles to delay the start of the ramp generator incrementor/
  *          decrementor after a PWMSYNC event is received.    
  *                   - uint16_t: 0x00 - 0x1FFF
  */
static inline uint16_t CMPSS_getRampDelayHigh (CMPSS_TypeDef *cmpss)
{
    return (uint16_t)(cmpss->RAMPHDLYA.WORDVAL);
}

/**
  * \brief  Sets the high ramp delay value of the second and later slopes.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  value    Value is the 13-bit ramp delay value2.
  *                   - uint16_t: 0x00 - 0xFFFF
  */
static inline void CMPSS_setRampDelay2High (CMPSS_TypeDef *cmpss, uint16_t value)
{
    WRITE_REG(cmpss->RAMPHDLY2.WORDVAL, (uint32_t)value);
}

/**
  * \brief  Gets the high ramp generator value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \return Returns the Ramp value. Present value of ramp generator. 
  *                   - uint16_t: 0x00 - 0xFFF
  */
static inline uint16_t CMPSS_getRampValueHigh (CMPSS_TypeDef *cmpss)
{
    return (uint16_t)READ_REG(cmpss->RAMPHSTS.WORDVAL);
}

/**
  * \brief  Gets the high ramp generator delay value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \return Returns the Ramp delay. 
  *                   - uint16_t: 0x00 - 0x1FFF
  */
static inline uint16_t CMPSS_getRampDelayValueHigh (CMPSS_TypeDef *cmpss)
{
    return (uint16_t)READ_REG(cmpss->RAMPHDLYA.WORDVAL);
}

/**
  * \brief  Gets the high ramp generator delay value2.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \return Returns the Ramp delay2. 
  *                   - uint16_t: 0x00 - 0xFFFF
  */
static inline uint16_t CMPSS_getRampDelayValue2High (CMPSS_TypeDef *cmpss)
{
    return (uint16_t)READ_REG(cmpss->RAMPHDLY2.WORDVAL);
}

/**
  * \brief  Initializes the digital filter of the low comparator.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_initFilterLow (CMPSS_TypeDef *cmpss)
{
    SET_BIT(cmpss->CTRIPLFILCTL.WORDVAL, CMPSS_CTRIPLFILCTL_FILINIT);
}

/**
  * \brief  Set the sampling threshold for the low filter.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  * \param  thresh    The sampling threshold for the low filter.
  *                    - uint8_t: 0x00 - 0x3F
  */
static inline void CMPSS_setFilterLowThresh (CMPSS_TypeDef *cmpss, uint8_t thresh)
{
    MODIFY_REG(cmpss->CTRIPLFILCTL.WORDVAL, CMPSS_CTRIPLFILCTL_THRESH_M,
               (uint32_t)(thresh << CMPSS_CTRIPLFILCTL_THRESH_S));
}

/**
  * \brief  Set the sampling window for the low filter.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  win      The sampling window for the low filter.
  *                   - uint8_t: 0x00 - 0x3F
  */
static inline void CMPSS_setFilterLowSampWin (CMPSS_TypeDef *cmpss, uint8_t win)
{
    MODIFY_REG(cmpss->CTRIPLFILCTL.WORDVAL, CMPSS_CTRIPLFILCTL_SAMPWIN_M,
               (uint32_t)(win << CMPSS_CTRIPLFILCTL_SAMPWIN_S));
}

/**
  * \brief  Configure input source for low filter. 
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  * \param  source    Low filter input source.
  *                    This parameter can be any value of @ref CMPSS_FilterInputSelect
  */
static inline void CMPSS_configureFilterInputLow (CMPSS_TypeDef *cmpss, CMPSS_FilterInputSelect source)
{
    MODIFY_REG(cmpss->CTRIPLFILCTL.WORDVAL, CMPSS_CTRIPLFILCTL_FILTINSEL_M,
               (uint32_t)(source << CMPSS_CTRIPLFILCTL_FILTINSEL_S));
}

/**
  * \brief  Set the sampling clock prescaler value for the low filter.
  * \param  cmpss       The base address of the CMPSS module.
  *                      - CMPSS1: CMPSS1 base address index
  *                      - CMPSS2: CMPSS2 base address index
  *                      - CMPSS3: CMPSS3 base address index
  *                      - CMPSS4: CMPSS4 base address index
  *                      - CMPSS5: CMPSS5 base address index
  *                      - CMPSS6: CMPSS6 base address index
  *                      - CMPSS7: CMPSS7 base address index
  *                      - CMPSS8: CMPSS8 base address index
  *                      - CMPSS9: CMPSS9 base address index
  *                      - CMPSS10: CMPSS10 base address index
  *                      - CMPSS11: CMPSS11 base address index
  * \param  prescale    The sampling clock prescaler value for the low filter.
  *                      - uint32_t: 0x00 - 0xFFFFFF
  */
static inline void CMPSS_setFilterLowPrescale (CMPSS_TypeDef *cmpss, uint32_t prescale)
{
    WRITE_REG(cmpss->CTRIPLFILCLKCTL.WORDVAL, (uint32_t)(prescale & 0xFFFFUL));
    WRITE_REG(cmpss->CTRIPLFILCLKCTL2.WORDVAL, (uint32_t)((prescale >> 16) & 0xFFUL));
}

/**
  * \brief  Initializes the digital filter of the high comparator.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_initFilterHigh (CMPSS_TypeDef *cmpss)
{
    SET_BIT(cmpss->CTRIPHFILCTL.WORDVAL, CMPSS_CTRIPHFILCTL_FILINIT);
}

/**
  * \brief  Set the sampling threshold for the high filter.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  * \param  thresh    The sampling threshold for the high filter.
  *                    - uint8_t: 0x00 - 0x3F
  */
static inline void CMPSS_setFilterHighThresh (CMPSS_TypeDef *cmpss, uint8_t thresh)
{
    MODIFY_REG(cmpss->CTRIPHFILCTL.WORDVAL, CMPSS_CTRIPHFILCTL_THRESH_M,
               (uint32_t)(thresh << CMPSS_CTRIPHFILCTL_THRESH_S));
}

/**
  * \brief  Set the sampling window for the high filter.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  win      The sampling window for the high filter.
  *                   - uint8_t: 0x00 - 0x3F
  */
static inline void CMPSS_setFilterHighSampWin (CMPSS_TypeDef *cmpss, uint8_t win)
{
    MODIFY_REG(cmpss->CTRIPHFILCTL.WORDVAL, CMPSS_CTRIPHFILCTL_SAMPWIN_M,
               (uint32_t)(win << CMPSS_CTRIPHFILCTL_SAMPWIN_S));
}

/**
  * \brief  Configure input source for high filter. 
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  * \param  source    Low filter input source.
  *                   This parameter can be any value of @ref CMPSS_FilterInputSelect
  */
static inline void CMPSS_configureFilterInputHigh (CMPSS_TypeDef *cmpss, CMPSS_FilterInputSelect source)
{
    MODIFY_REG(cmpss->CTRIPHFILCTL.WORDVAL, CMPSS_CTRIPHFILCTL_FILTINSEL_M,
               (uint32_t)(source << CMPSS_CTRIPHFILCTL_FILTINSEL_S));
}

/**
  * \brief  Set the sampling clock prescaler value for the high filter.
  * \param  cmpss       The base address of the CMPSS module.
  *                      - CMPSS1: CMPSS1 base address index
  *                      - CMPSS2: CMPSS2 base address index
  *                      - CMPSS3: CMPSS3 base address index
  *                      - CMPSS4: CMPSS4 base address index
  *                      - CMPSS5: CMPSS5 base address index
  *                      - CMPSS6: CMPSS6 base address index
  *                      - CMPSS7: CMPSS7 base address index
  *                      - CMPSS8: CMPSS8 base address index
  *                      - CMPSS9: CMPSS9 base address index
  *                      - CMPSS10: CMPSS10 base address index
  *                      - CMPSS11: CMPSS11 base address index
  * \param  prescale    The sampling clock prescaler value for the low filter.
  *                      - uint32_t: 0x00 - 0xFFFFFF
  */
static inline void CMPSS_setFilterHighPrescale (CMPSS_TypeDef *cmpss, uint32_t prescale)
{
    WRITE_REG(cmpss->CTRIPHFILCLKCTL.WORDVAL, (uint32_t)(prescale & 0xFFFFUL));
    WRITE_REG(cmpss->CTRIPHFILCLKCTL2.WORDVAL, (uint32_t)((prescale >> 16) & 0xFFUL));
}

/**
  * \brief  Lock the COMPCTL register.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_lockCOMPTCL (CMPSS_TypeDef *cmpss)
{
    WRITE_REG(cmpss->COMPLOCK.WORDVAL, CMPSS_COMPLOCK_KEY | CMPSS_COMPLOCK_COMPCTL);
}

/**
  * \brief  Lock the COMPHYSCTL register.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_lockCOMPHYSCTL (CMPSS_TypeDef *cmpss)
{
    WRITE_REG(cmpss->COMPLOCK.WORDVAL, CMPSS_COMPLOCK_KEY | CMPSS_COMPLOCK_COMPHYSCTL);
}

/**
  * \brief  Lock the DACxCTL* register.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_lockDACCTL (CMPSS_TypeDef *cmpss)
{
    WRITE_REG(cmpss->COMPLOCK.WORDVAL, CMPSS_COMPLOCK_KEY | CMPSS_COMPLOCK_DACCTL);
}

/**
  * \brief  Lock the CTRIPxFILTCTL/CTRIPxFILTCLKCTL* register.
  * \param  cmpss       The base address of the CMPSS module.
  *                      - CMPSS1: CMPSS1 base address index
  *                      - CMPSS2: CMPSS2 base address index
  *                      - CMPSS3: CMPSS3 base address index
  *                      - CMPSS4: CMPSS4 base address index
  *                      - CMPSS5: CMPSS5 base address index
  *                      - CMPSS6: CMPSS6 base address index
  *                      - CMPSS7: CMPSS7 base address index
  *                      - CMPSS8: CMPSS8 base address index
  *                      - CMPSS9: CMPSS9 base address index
  *                      - CMPSS10: CMPSS10 base address index
  *                      - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_lockCTRIP (CMPSS_TypeDef *cmpss)
{
    WRITE_REG(cmpss->COMPLOCK.WORDVAL, CMPSS_COMPLOCK_KEY | CMPSS_COMPLOCK_CTRIP);
}

/**
  * \brief  Sets the configuration for the internal comparator low DACs.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  * \param  config    the DAC value source for the low comparator's internal DAC:
  *                    - CMPSS_DACSRC_SHDW
  *                    - CMPSS_DACSRC_RAMP 
  */
static inline void CMPSS_configLowDAC (CMPSS_TypeDef *cmpss, uint16_t config)
{                                        
    MODIFY_REG(cmpss->COMPDACLCTL.WORDVAL, CMPSS_COMPDACLCTL_DACSOURCE, (uint32_t)config);
}

/**
  * \brief  Sets the ePWM module blanking signal that holds trip in reset of low DACs.
  * \param  cmpss          The base address of the CMPSS module.
  *                         - CMPSS1: CMPSS1 base address index
  *                         - CMPSS2: CMPSS2 base address index
  *                         - CMPSS3: CMPSS3 base address index
  *                         - CMPSS4: CMPSS4 base address index
  *                         - CMPSS5: CMPSS5 base address index
  *                         - CMPSS6: CMPSS6 base address index
  *                         - CMPSS7: CMPSS7 base address index
  *                         - CMPSS8: CMPSS8 base address index
  *                         - CMPSS9: CMPSS9 base address index
  *                         - CMPSS10: CMPSS10 base address index
  *                         - CMPSS11: CMPSS11 base address index
  * \param  pwmBlankSrc    Is the number of the PWMBLANK source.
  *                         This parameter can be any value of @ref CMPSS_EPWMBLANKSEL
  */
static inline void CMPSS_configBlankingSourceLow (CMPSS_TypeDef *cmpss, CMPSS_EpwmBlankSelect pwmBlankSrc)  
{
    MODIFY_REG(cmpss->COMPDACLCTL.WORDVAL, CMPSS_COMPDACLCTL_BLANKSOURCE_M,
               (uint32_t)(pwmBlankSrc << CMPSS_COMPDACLCTL_BLANKSOURCE_S));
}

/**
  * \brief  Enables an ePWM blanking signal to hold trip in reset of low DACs.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_enableBlankingLow (CMPSS_TypeDef *cmpss)
{
    SET_BIT(cmpss->COMPDACLCTL.WORDVAL, CMPSS_COMPDACLCTL_BLANKEN);
}

/**
  * \brief  Disables an ePWM blanking signal to hold trip in reset.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  */
static inline void CMPSS_disableBlankingLow (CMPSS_TypeDef *cmpss)
{
    CLEAR_BIT(cmpss->COMPDACLCTL.WORDVAL, CMPSS_COMPDACLCTL_BLANKEN);
}

/**
  * \brief  Select which EPWMnSYNCPER signal is used within the low CMPSS module. 
  * \param  cmpss            The base address of the CMPSS module.
  *                           - CMPSS1: CMPSS1 base address index
  *                           - CMPSS2: CMPSS2 base address index
  *                           - CMPSS3: CMPSS3 base address index
  *                           - CMPSS4: CMPSS4 base address index
  *                           - CMPSS5: CMPSS5 base address index
  *                           - CMPSS6: CMPSS6 base address index
  *                           - CMPSS7: CMPSS7 base address index
  *                           - CMPSS8: CMPSS8 base address index
  *                           - CMPSS9: CMPSS9 base address index
  *                           - CMPSS10: CMPSS10 base address index
  *                           - CMPSS11: CMPSS11 base address index
  * \param  syncPerSource    Determines which EPWMnSYNCPER signal is used within the low CMPSS module.
  *                           This parameter can be any value of @ref CMPSS_EPWMSYNCPERSEL
  */
static inline void CMPSS_configureSyncSourceLow (CMPSS_TypeDef *cmpss, CMPSS_EpwmSyncPerSelect syncPerSource)  
{
    MODIFY_REG(cmpss->COMPDACLCTL.WORDVAL, CMPSS_COMPDACLCTL_RAMPSOURCE_M,
               (uint32_t)(syncPerSource << CMPSS_COMPDACLCTL_RAMPSOURCE_S));
}

/**
  * \brief  Config low ramp generator direction.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  dir      Low RAMP direction.
  *                   This parameter can be any value of @ref CMPSS_RampDirection
  */
static inline void CMPSS_setRAMPDirectionLow (CMPSS_TypeDef *cmpss, CMPSS_RampDirection dir)
{
  if(CMPSS_RAMP_DIR_UP == dir)
  {
      SET_BIT(cmpss->COMPDACLCTL.WORDVAL, CMPSS_COMPDACLCTL_RAMPLDIR);
  }
  else
  {
      CLEAR_BIT(cmpss->COMPDACLCTL.WORDVAL, CMPSS_COMPDACLCTL_RAMPLDIR);
  }
}

/**
  * \brief  Select the Blank source group for low comparator.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  * \param  config    The \e config parameter is the result of a logical OR operation between the 
  *                   \b CMPSS_BLANKSOURCEUSEL_xxx and \b CMPSS_RAMPSOURCEUSEL_xxx.  
  *                   The \b CMPSS_BLANKSOURCEUSEL_xxx term can take on the following values to specify 
  *                   the BLANK source for COMPH:
  *                    - CMPSS_BLANKSOURCESEL_EPWM1_16
  *                    - CMPSS_BLANKSOURCESEL_EPWM17_18 
  */
static inline void CMPSS_selectBlankSourceGroupLow (CMPSS_TypeDef *cmpss, uint16_t config)
{                                        
    MODIFY_REG(cmpss->COMPDACLCTL2.WORDVAL, CMPSS_COMPDACLCTL2_BLANKSOURCEUSEL, (uint32_t)config);
}

/**
  * \brief  Select the Ramp source group for low comparator.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  * \param  config    The \b CMPSS_RAMPSOURCESEL_xxx term can take on the following values to specify 
  *                   the RAMP source for RAMPH:
  *                    - CMPSS_RAMPSOURCESEL_EPWM1_16
  *                    - CMPSS_RAMPSOURCESEL_EPWM17_18
  */
static inline void CMPSS_selectRampSourceGroupLow (CMPSS_TypeDef *cmpss, uint16_t config)
{                                        
    MODIFY_REG(cmpss->COMPDACLCTL2.WORDVAL, CMPSS_COMPDACHCTL2_RAMPSOURCESEL, (uint32_t)config);
}

/**
  * \brief  Sets the low ramp generator reference value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  value    The ramp maximum reference value.
  *                   - uint16_t: 0x00 - 0xFFF
  */
static inline void CMPSS_setRampReferenceLow (CMPSS_TypeDef *cmpss,  uint16_t value)
{
    WRITE_REG(cmpss->RAMPLREFS.WORDVAL, (uint32_t)value);
}

/**
  * \brief  Gets the low ramp generator active reference value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \return Returns the latched ramp active reference value that will be loaded into the ramp generator.
  *                   - uint16_t: 0x00 - 0xFFF
  */
static inline uint16_t CMPSS_getRampReferenceLow (CMPSS_TypeDef *cmpss)
{
    return (uint16_t)READ_REG(cmpss->RAMPLREFA.WORDVAL);
}

/**
  * \brief  Sets the low ramp generator step value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  value    Value is the ramp step value.
  *                   - uint16_t: 0x00 - 0xFFF
  */
static inline void CMPSS_setRampStepLow (CMPSS_TypeDef *cmpss, uint16_t value)
{
    WRITE_REG(cmpss->RAMPLSTEPVALS.WORDVAL, (uint32_t)value);
}

/**
  * \brief  Gets the low ramp generator step value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \return Returns the latched ramp step value that is subtracted from the ramp value on 
  *         every system clock cycle.    
  *                   - uint16_t: 0x00 - 0xFFF
  */
static inline uint16_t CMPSS_getRampStepLow (CMPSS_TypeDef *cmpss)
{
    return (uint16_t)READ_REG(cmpss->RAMPLSTEPVALA.WORDVAL);
}

/**
  * \brief  Sets the low ramp generator clock divid value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  value    Value is the clk divid value.
  *                   - uint16_t: 0x00 - 0xF
  */
static inline void CMPSS_setRampClockDividerLow (CMPSS_TypeDef *cmpss, uint16_t value)
{
    WRITE_REG(cmpss->RAMPLCTLS.WORDVAL, (uint32_t)value);
}

/**
  * \brief  Gets the low ramp generator clock divid value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \return Returns the latched ramp clock divid value that will be loaded into the ramp generator.    
  *                   - uint16_t: 0x00 - 0xF
  */
static inline uint16_t CMPSS_getRampClockDividerLow (CMPSS_TypeDef *cmpss)
{
    return (uint16_t)READ_REG(cmpss->RAMPLCTLA.WORDVAL);
}

/**
  * \brief  Gets the low ramp generator value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \return Returns the Ramp value. Present value of ramp generator. 
  *                   - uint16_t: 0x00 - 0xFFF
  */
static inline uint16_t CMPSS_getRampValueLow (CMPSS_TypeDef *cmpss)
{
    return (uint16_t)READ_REG(cmpss->RAMPLSTS.WORDVAL);
}

/**
  * \brief  Sets the low ramp generator delay value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  value    Value is the 13-bit ramp delay value.
  *                   - uint16_t: 0x00 - 0x1FFF
  */
static inline void CMPSS_setRampDelayLow (CMPSS_TypeDef *cmpss, uint16_t value)
{
    WRITE_REG(cmpss->RAMPLDLYS.WORDVAL, (uint32_t)value);
}

/**
  * \brief  Gets the low ramp generator delay value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  ** \return Returns the latched ramp delay value that configures the number
  *          of system clock cycles to delay the start of the ramp generator incrementor/
  *          decrementor after a PWMSYNC event is received.    
  *                   - uint16_t: 0x00 - 0x1FFF
  */
static inline uint16_t CMPSS_getRampDelayLow (CMPSS_TypeDef *cmpss)
{
    return (uint16_t)(cmpss->RAMPLDLYA.WORDVAL);
}

/**
  * \brief  Sets the low ramp delay value of the second and later slopes.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \param  value    Value is the 16-bit ramp delay value2.
  *                   - uint16_t: 0x00 - 0xFFFF
  */
static inline void CMPSS_setRampDelay2Low (CMPSS_TypeDef *cmpss, uint16_t value)
{
    WRITE_REG(cmpss->RAMPLDLY2.WORDVAL, (uint32_t)value);
}

/**
  * \brief  Gets the low ramp generator delay value.
  * \param  cmpss    The base address of the CMPSS module.
  *                   - CMPSS1: CMPSS1 base address index
  *                   - CMPSS2: CMPSS2 base address index
  *                   - CMPSS3: CMPSS3 base address index
  *                   - CMPSS4: CMPSS4 base address index
  *                   - CMPSS5: CMPSS5 base address index
  *                   - CMPSS6: CMPSS6 base address index
  *                   - CMPSS7: CMPSS7 base address index
  *                   - CMPSS8: CMPSS8 base address index
  *                   - CMPSS9: CMPSS9 base address index
  *                   - CMPSS10: CMPSS10 base address index
  *                   - CMPSS11: CMPSS11 base address index
  * \return Returns the Ramp delay. 
  *                   - uint16_t: 0x00 - 0x1FFF
  */
static inline uint16_t CMPSS_getRampDelayValueLow (CMPSS_TypeDef *cmpss)
{
    return (uint16_t)READ_REG(cmpss->RAMPLDLYA.WORDVAL);
}

/**
  * \brief  Config the DAC test register.
  * \param  cmpss     The base address of the CMPSS module.
  *                    - CMPSS1: CMPSS1 base address index
  *                    - CMPSS2: CMPSS2 base address index
  *                    - CMPSS3: CMPSS3 base address index
  *                    - CMPSS4: CMPSS4 base address index
  *                    - CMPSS5: CMPSS5 base address index
  *                    - CMPSS6: CMPSS6 base address index
  *                    - CMPSS7: CMPSS7 base address index
  *                    - CMPSS8: CMPSS8 base address index
  *                    - CMPSS9: CMPSS9 base address index
  *                    - CMPSS10: CMPSS10 base address index
  *                    - CMPSS11: CMPSS11 base address index
  * \param  config    The \e config parameter is the result of a logical OR operation between the 
  *                   \b CMPSS_COMP_HIGH_NEGATIVE_OUTPUT_xxx and \b CMPSS_COMP_HIGH_NEGATIVE_OUTPUT_xxx.  
  *                   The \b CMPSS_COMP_HIGH_NEGATIVE_OUTPUT_xxx term can take on the following values to specify 
  *                   the status of high COMP negative output:
  *                    - CMPSS_COMP_HIGH_NEGATIVE_OUTPUT_ENABLE
  *                    - CMPSS_COMP_HIGH_NEGATIVE_OUTPUT_DISABLE 
  *                   The \b CMPSS_COMP_LOW_NEGATIVE_OUTPUT_xxx term can take on the following values to specify 
  *                   the status of low COMP negative output:
  *                    - CMPSS_COMP_LOW_NEGATIVE_OUTPUT_ENABLE
  *                    - CMPSS_COMP_LOW_NEGATIVE_OUTPUT_DISABLE
  */
static inline void CMPSS_configDACTest (CMPSS_TypeDef *cmpss, uint16_t high_status, uint16_t low_status)
{                                        
    WRITE_REG(cmpss->COMPDACTEST.WORDVAL, (uint32_t)(CMPSS_COMPDACTEST_KEY | high_status | low_status));
}

/**
  * \brief  Config High Comparator Filter.
  * \param  cmpss             The base address of the CMPSS module.
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
  * \param  samplePrescale    High filter sample clock prescale. 
  * \param  sampleWindow      High filter sample window size. Number of samples to monitor is SAMPWIN+2.
  *                            - uint16_t: 0x00 - 0x1F
  * \param  threshold         High filter majority voting threshold.Threshold used is THRESH+2.
  *                            - uint16_t: 0x00 - 0x1F
  */
extern void CMPSS_configFilterHigh (CMPSS_TypeDef *cmpss, uint16_t samplePrescale, uint16_t sampleWindow,
                                    uint16_t threshold);

/**
  * \brief  Config Low Comparator Filter.
  * \param  cmpss             The base address of the CMPSS module.
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
  * \param  samplePrescale    Low filter sample clock prescale. 
  * \param  sampleWindow      Low filter sample window size. Number of samples to monitor is SAMPWIN+2.
  *                            - uint16_t: 0x00 - 0x1F
  * \param  threshold         Low filter majority voting threshold.Threshold used is THRESH+2.
  *                            - uint16_t: 0x00 - 0x1F
  */
extern void CMPSS_configFilterLow (CMPSS_TypeDef *cmpss, uint16_t samplePrescale, uint16_t sampleWindow,
                                   uint16_t threshold);

/**
  * \brief  Config the related parameters for High RAMP.
  * \param  cmpss             The base address of the CMPSS module.
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
  * \param  rampDir           Ramp direction of high ramp generator .
  *                            - 0: Ramp direction decrease
  *                            - 1: Ramp direction increase
  * \param  refRampVal        Maximum ramp value to the shadow register .
  *                            - uint16_t: 0x00 - 0xFFF
  * \param  stepVal           StepVal: ramp step value to the shadow register.
  *                            - uint16_t: 0x00 - 0xFFF
  * \param  delayVal          Ramp delay value to the shadow register.
  *                            - uint16_t: 0x00 - 0x1FFF
  * \param  pwmSyncSrc        Determines which EPWMnSYNCPER signal is used within the CMPSS module.
  *                            - CMPSS_EpwmSyncPerSelect: 0x00 - 0x0F
  * \param  useRampValShdw    Determines whether DACxVALA is updated from DACxVALS on SYSCLK or EPWMSYNCPER.
  *                            - 0: DACHVALA is updated from DACHVALS
  *                            - 1: DACHVALA is updated from the ramp generator
  */
extern void CMPSS_configRampHigh (CMPSS_TypeDef *cmpss, CMPSS_RampDirection rampDir, uint16_t refRampVal,
                                  uint16_t stepVal, uint16_t delayVal, CMPSS_EpwmSyncPerSelect pwmSyncSrc,
                                  uint8_t useRampValShdw);

/**
  * \brief  Config the related parameters for Low RAMP.
  * \param  cmpss             The base address of the CMPSS module.
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
  * \param  rampDir           Ramp direction of low ramp generator .
  *                            - 0: Ramp direction decrease
  *                            - 1: Ramp direction increase
  * \param  refRampVal        Maximum ramp value to the shadow register .
  *                            - uint16_t: 0x00 - 0xFFF
  * \param  stepVal           StepVal: ramp step value to the shadow register.
  *                            - uint16_t: 0x00 - 0xFFF
  * \param  delayVal          Ramp delay value to the shadow register.
  *                            - uint16_t: 0x00 - 0x1FFF
  * \param  pwmSyncSrc        Determines which EPWMnSYNCPER signal is used within the CMPSS module.
  *                            - CMPSS_EpwmSyncPerSelect: 0x00 - 0x0F
  * \param  useRampValShdw    Determines whether DACxVALA is updated from DACxVALS on SYSCLK or EPWMSYNCPER.
  *                            - 0: DACHVALA is updated from DACHVALS
  *                            - 1: DACHVALA is updated from the ramp generator
  */
extern void CMPSS_configRampLow (CMPSS_TypeDef *cmpss, CMPSS_RampDirection rampDir, uint16_t refRampVal,
                                 uint16_t stepVal, uint16_t delayVal, CMPSS_EpwmSyncPerSelect pwmSyncSrc,
                                 uint8_t useRampValShdw);

/**
  * \brief  Config low/high comparator latch software clear.
  * \param  cmpss         The base address of the CMPSS module.
  *                        - CMPSS1: CMPSS1 base address index
  *                        - CMPSS2: CMPSS2 base address index
  *                        - CMPSS3: CMPSS3 base address index
  *                        - CMPSS4: CMPSS4 base address index
  *                        - CMPSS5: CMPSS5 base address index
  *                        - CMPSS6: CMPSS6 base address index
  *                        - CMPSS7: CMPSS7 base address index
  *                        - CMPSS8: CMPSS8 base address index
  *                        - CMPSS9: CMPSS9 base address index
  *                        - CMPSS10: CMPSS10 base address index
  *                        - CMPSS11: CMPSS11 base address index
  * \param  highEnable    Set the bit that will enable PWMSYNC to reset the high comparator digital filter latch. 
  *                        - 0: Disable 
  *                        - 1: Enable
  * \param  lowEnable     Set the bit that will enable PWMSYNC to reset the low comparator digital filter latch.
  *                        - 0: Disable 
  *                        - 1: Enable
  */
extern void CMPSS_configLatchOnPWMSYNC (CMPSS_TypeDef *cmpss, uint8_t highEnable, uint8_t lowEnable);


#ifdef __cplusplus
}
#endif


#endif /* __CMPSS_H__ */
