/**
  * @file       dac.h
  * @author     bilang.xiong
  * @brief      Header file for NS800RT7xxx dac module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __DAC_H__
#define __DAC_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_dac.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup DAC_EXPORTED_TYPES DAC Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'DAC' module.
  */

/** @defgroup DAC_LOADMODE DAC Load Mode
  * @{
  * @brief  Values that can be passed to DAC_setLoadMode() as the \e mode parameter.
  */
typedef enum {
    DAC_LOAD_SYSCLK  = 0U,    /*!< Load on next the SYSCLK rising edge */
    DAC_LOAD_PWMSYNC = 4U     /*!< Load on next PWMSYNC specified by SYNCSEL */
} DAC_LoadMode;

/**
  * @}
  */

/** @defgroup DAC_EPWMSYSNCSEL DAC EPWMxSYNC Signal Select
  * @{
  * @brief  Values that can be passed to DAC_setPWMSyncSignal() as the \e pwmSignal parameter.
  */
typedef enum {
    DAC_SYNCSEL_EPWM1 = 0U,    /*!< Load on next EPWM1SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM2,         /*!< Load on next EPWM2SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM3,         /*!< Load on next EPWM3SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM4,         /*!< Load on next EPWM4SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM5,         /*!< Load on next EPWM5SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM6,         /*!< Load on next EPWM6SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM7,         /*!< Load on next EPWM7SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM8,         /*!< Load on next EPWM8SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM9,         /*!< Load on next EPWM9SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM10,        /*!< Load on next EPWM10SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM11,        /*!< Load on next EPWM11SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM12,        /*!< Load on next EPWM12SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM13,        /*!< Load on next EPWM13SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM14,        /*!< Load on next EPWM14SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM15,        /*!< Load on next EPWM15SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM16,        /*!< Load on next EPWM16SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM17,        /*!< Load on next EPWM17SYNCPER specified by SYNCSEL */
    DAC_SYNCSEL_EPWM18         /*!< Load on next EPWM18SYNCPER specified by SYNCSEL */
} DAC_EpwmSyncSel;

/**
  * @}
  */

/** @defgroup DAC_GAINMODE DAC gain mode
  * @{
  * @brief  Values that can be passed to DAC_setGainMode() as the \e mode parameter.
  */
typedef enum {
    DAC_GAIN_1  = 0U,    /*!< The gain is 1 time. */
    DAC_GAIN_2  = 1U     /*!< The gain is 2 time. */
} DAC_GainMode;

/**
  * @}
  */

/** @defgroup DAC_REFSELMODE DAC reference voltage mode selection
  * @{
  * @brief  Values that can be passed to DAC_setDacVrefMode() as the \e mode parameter.
  */
typedef enum {
    DAC_REFSEL_VDAC    = 0U,    /*!< The gain is 1 time. */
    DAC_REFSEL_VREFHI  = 1U     /*!< The gain is 2 time. */
} DAC_RefSelMode;

/**
  * @}
  */

/** @defgroup DAC_REFSEL DAC reference voltage selection
  * @{
  * @brief  Values that can be passed to DAC_setDacVrefMode() as the \e mode parameter.
  */
typedef enum {
    DAC_REFSEL_1V65 = 0U,    /*!< Select 1.65V voltage.. */
    DAC_REFSEL_2V5 ,         /*!< Select 2.5V voltage.. */
    DAC_REFSEL_EXT           /*!< Select external voltage.. */
} DAC_RefSel;

/**
  * @}
  */

/** @defgroup DAC_LOCK_KEY DAC Lock Key
  * @{
  * @brief  DAC Lock Key.
  */
#define DAC_LOCK_KEY    (0x0000A000UL)    /*!< DAC lock key */

/**
  * @}
  */

/** @defgroup DAC_LOCKCTRL DAC Lock Control
  * @{
  * @brief  Values that defines for the \e reg parameter of the DAC_lockRegister() and
  *         DAC_isRegisterLocked() functions.
  */
#define DAC_LOCK_CTL     (DAC_DACLOCK_DACCTL_M)     /*!< Lock the control register */
#define DAC_LOCK_VALS    (DAC_DACLOCK_DACVALS_M)    /*!< Lock the shadow value register */
#define DAC_LOCK_TIME    (DAC_DACLOCK_DACTIME_M)    /*!< Lock the time register */
#define DAC_LOCK_TRIM    (DAC_DACLOCK_DACTRIM_M)    /*!< Lock the offset trim register */

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
  * \brief  Set the DAC load mode.
  * \param  base  the DAC module base address.
  *                - DAC1: DAC1 module
  *                - DAC3: DAC3 module
  * \param  mode  the DAC selected load mode.
  *                This parameter can be any value of @ref DAC_LOADMODE
  */
static inline void DAC_setLoadMode (DAC_TypeDef *base, DAC_LoadMode mode)
{
    MODIFY_REG(base->DACCTL.WORDVAL, DAC_DACCTL_LOADMODE_M, (uint32_t)mode);
}

/**
  * \brief  Set the DAC PWMSYNC Signal
  * \param  base       the DAC module base address.
  *                     - DAC1: DAC1 module
  *                     - DAC3: DAC3 module
  * \param  pwmSignal  the selected PWMx sync signal
  *                     This parameter can be any value of @ref DAC_EPWMSYSNCSEL
  */
static inline void DAC_setPWMSyncSignal (DAC_TypeDef *base, DAC_EpwmSyncSel pwmSignal)
{
    MODIFY_REG(base->DACCTL.WORDVAL, DAC_DACCTL_SYNCSEL_M, ((uint32_t)pwmSignal << DAC_DACCTL_SYNCSEL_S));
}

/**
  * \brief  Set the DAC data update delay.
  * \param  base  the DAC module base address.
  *                - DAC1: DAC1 module
  *                - DAC3: DAC3 module
  * \param  time   the selected prescaler
  *                This parameter can be set one value that range from 0x0 to 0xFFFF
  */
static inline void DAC_setDetaDelayTime (DAC_TypeDef *base, uint32_t time)
{
    MODIFY_REG(base->DACTIME.WORDVAL, DAC_DACTIME_DELAY_M, ((uint32_t)time << DAC_DACTIME_DELAY_S));
}

/**
  * \brief  Set the DAC settling time.
  * \param  base  the DAC module base address.
  *                - DAC1: DAC1 module
  *                - DAC3: DAC3 module
  * \param  time   the selected prescaler
  *                 This parameter can be set one value that range from 0x0 to 0xFFFF
  */
static inline void DAC_setSettlingTime (DAC_TypeDef *base, uint32_t time)
{
    MODIFY_REG(base->DACTIME.WORDVAL, DAC_DACTIME_SETTLE_M, ((uint32_t)time << DAC_DACTIME_SETTLE_S));
}

/**
  * \brief  Set the DAC gain mode.
  * \param  base  the DAC module base address.
  *                - DAC1: DAC1 module
  *                - DAC3: DAC3 module
  * \param  gain   the selected prescaler
  *                 This parameter can be any value of @ref DAC_GAINMODE
  */
static inline void DAC_setGainMode (DAC_TypeDef *base, DAC_GainMode gain)
{
    MODIFY_REG(base->DACCTL.WORDVAL, DAC_DACCTL_GAINMODE_M, ((uint32_t)gain << DAC_DACCTL_GAINMODE_S));
}

/**
  * \brief  Set the DAC VREF.
  * \param  base  the DAC module base address.
  *                - DAC1: DAC1 module
  *                - DAC3: DAC3 module
  * \param  vref   the selected prescaler
  *                 This parameter can be any value of @ref DAC_REFSEL
  */
static inline void DAC_setDacVrefMode (DAC_TypeDef *base, DAC_RefSelMode vrefmodesel)
{

    MODIFY_REG(base->DACCTL.WORDVAL, DAC_DACCTL_DACREFSEL_M, ((uint32_t)vrefmodesel << DAC_DACCTL_DACREFSEL_S));
    
}

/**
  * \brief Get the DAC active output value
  * \param base  the DAC module base address.
  *               - DAC1: DAC1 module
  *               - DAC3: DAC3 module
  * \return Returns the DAC active output value.
  */
static inline uint16_t DAC_getActiveValue (DAC_TypeDef *base)
{
    return (uint16_t)(READ_REG(base->DACVALA.WORDVAL) & DAC_DACVALA_DACVALA_M);
}

/**
  * \brief Set the DAC shadow output value
  * \param base   the DAC module base address.
  *                - DAC1: DAC1 module
  *                - DAC3: DAC3 module
  * \param value  the 12-bit code to be loaded into the active value register
  *                This parameter can be set one value that range from 0x0 to 0xFFF
  */
static inline void DAC_setShadowValue (DAC_TypeDef *base, uint16_t value)
{
    WRITE_REG(base->DACVALS.WORDVAL, (value & DAC_DACVALS_DACVALS_M));
}

/**
  * \brief Get the DAC shadow Output Value
  * \param base  the DAC module base address.
  *               - DAC1: DAC1 module
  *               - DAC3: DAC3 module
  * \return Returns the DAC active output value.
  */
static inline uint16_t DAC_getShadowValue (DAC_TypeDef *base)
{
    return (uint16_t)(READ_REG(base->DACVALS.WORDVAL) & DAC_DACVALS_DACVALS_M);
}


/**
  * \brief Enable the DAC module
  * \param base  the DAC module base address.
  *               - DAC1: DAC1 module
  *               - DAC3: DAC3 module
  */
static inline void DAC_enableModule (DAC_TypeDef *base)
{
    SET_BIT(base->DACCTL.WORDVAL, DAC_DACCTL_DACEN_M);
}

/**
  * \brief Disable the DAC module
  * \param base  the DAC module base address.
  *               - DAC1: DAC1 module
  *               - DAC3: DAC3 module
  */
static inline void DAC_disableModule (DAC_TypeDef *base)
{
    CLEAR_BIT(base->DACCTL.WORDVAL, DAC_DACCTL_DACEN_M);
}

/**
  * \brief Set DAC offset trim
  * \param base    the DAC module base address.
  *                 - DAC1: DAC1 module
  *                 - DAC3: DAC3 module
  * \param offset  the specified value for the offset trim
  *                 This parameter can be set one value that range from -128 to 127
  */
static inline void DAC_setOffsetTrim (DAC_TypeDef *base, int8_t offset)
{
    WRITE_REG(base->DACTRIM.WORDVAL, ((uint32_t)offset & DAC_DACTRIM_OFFSETTRIM_M));
}

/**
  * \brief Get DAC offset trim
  * \param base  the DAC module base address.
  *               - DAC1: DAC1 module
  *               - DAC3: DAC3 module
  * \return Returns the DAC offset trim value.
  */
static inline int8_t DAC_getOffsetTrim (DAC_TypeDef *base)
{
    return (int8_t)(READ_REG(base->DACTRIM.WORDVAL) & DAC_DACTRIM_OFFSETTRIM_M);
}

/**
  * \brief Lock write-access to DAC register
  * \note  This function locks the write-access to the specified DAC register. Only a
  *        system reset can unlock the register once locked.
  * \note  Multiple configs can be set together.
  * \param base  the DAC module base address.
  *               - DAC1: DAC1 module
  *               - DAC3: DAC3 module
  * \param reg   the selected DAC registers
  *               This parameter can be any value of @ref DAC_LOCKCTRL
  */
static inline void DAC_lockRegister (DAC_TypeDef *base, uint32_t reg)
{
    SET_BIT(base->DACLOCK.WORDVAL, (DAC_LOCK_KEY | reg));
}

/**
  * \brief Check if DAC register is locked
  * \param base  the DAC module base address.
  *               - DAC1: DAC1 module
  *               - DAC3: DAC3 module
  * \param reg   the selected DAC register locks to check
  *               This parameter can be any value of @ref DAC_LOCKCTRL
  * \return Returns the DAC register lock status.
  *          \b true if any of the registers specified are locked
  *          \b false if all specified registers aren't locked
  */
static inline bool DAC_isRegisterLocked(DAC_TypeDef *base, uint32_t reg)
{
    return READ_BIT(base->DACLOCK.WORDVAL, reg)? true : false;
}


#ifdef __cplusplus
}
#endif


#endif /* __DAC_H__ */
