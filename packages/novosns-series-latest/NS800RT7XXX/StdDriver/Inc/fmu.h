/**
  * @file       fmu.h
  * @author     yangjun
  * @brief      Header file for NS800RT7xxx fmu module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __FMU_H__
#define __FMU_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup FMU_EXPORTED_TYPES FMU Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'FMU' module.
  */

/** @defgroup FMU_MODE FMU Work Mode
  * @{
  * @brief  Macro definitions about FMU Work Mode.
  */
typedef enum {
    FMU_NORMAL      = 0x0U,    /*!< FMU Mode:Normal Mode */
    FMU_ERROR_FORCE = 0xAU,    /*!< FMU Mode:Inject Error Mode */
    FMU_DISABLE     = 0xFU     /*!< FMU Mode:Forbidden Mode*/
} FMU_Mode;

/**
  * @}
  */

/** @defgroup FMU_ERRORPINMODE Error Pin Mode
  * @{
  * @brief  Macro definitions about Error Pin Mode.
  */
typedef enum {
    FMU_PINMODE_NORMAL      = 0x0U,    /*!< Error Pin Control:Normal Mode */
    FMU_PINMODE_ERROR_FORCE = 0xAU,    /*!< Error Pin Control:Force to be active */
    FMU_PINMODE_CLR_ERROR   = 0x5U     /*!< Error Pin Control:Clear Error pin Status */
} FMU_ErrorPinMode;

/**
  * @}
  */

/** @defgroup FMU_ERRORPINPOLARITY Error Pin Polarity
  * @{
  * @brief  Macro definitions about Error Pin Polarity.
  */
typedef enum {
    FMU_ERRORPIN_LOW  = 0x0U,    /*!< Set Error Pin Low When Error occurs */
    FMU_ERRORPIN_HIGH = 0x10U    /*!< Set Error Pin HIGH When Error occurs */
} FMU_ErrorPinPolarity;

/**
  * @}
  */

/** @defgroup FMU_EVENT FMU Event index
  * @{
  * @brief  Macro definitions about FMU Event index.
  */
typedef enum {
    FMU_IRQ_LVD = 0U,               /*< FMU Event Source: LVD Voltage Alarm */
    FMU_IRQ_CPU1_FPU_ERR,           /*< FMU Event Source: CPU1 FPU Error */
    FMU_IRQ_CPU2_FPU_ERR,           /*< FMU Event Source: CPU2 FPU Error */
    FMU_IRQ_CPU1_TCM_ECC_ERR,       /*< FMU Event Source: CPU1 TCM ECC 2 bit Error */
    FMU_IRQ_CPU2_TCM_ECC_ERR,       /*< FMU Event Source: CPU2 TCM ECC 2 bit Error */
    FMU_IRQ_OCRAM_ECC_ERR,          /*< FMU Event Source: OCRAM ECC 2 bit Error */
    FMU_IRQ_FLASH_ECC_ERR,          /*< FMU Event Source: FLASH ECC 1/2 bit Error */
    FMU_IRQ_RCC_ERR,                /*< FMU Event Source: RCC Clock Error */
    FMU_IRQ_VDDRDY = 9U,            /*< FMU Event Source: VDD Voltage Lower */
    FMU_IRQ_CPU1_WWDG_PRE_WAKEUP,   /*< FMU Event Source: CPU1 WWDG Wakeup/Error */
    FMU_IRQ_CPU2_WWDG_PRE_WAKEUP,   /*< FMU Event Source: CPU2 WWDG Wakeup/Error */
    FMU_IRQ_CPU1_IWDG1_ERR,         /*< FMU Event Source: CPU1 IWDG1 Underflow/Error */
    FMU_IRQ_CPU2_IWDG1_ERR,         /*< FMU Event Source: CPU2 IWDG1 Underflow/Error */
    FMU_IRQ_IWDG2_ERR,              /*< FMU Event Source: IWDG2 Underflow */
    FMU_IRQ_EDMA0_ERR,              /*< FMU Event Source: EDMA0 Error */
    FMU_IRQ_EDMA1_ERR,              /*< FMU Event Source: EDMA1 Error */
    FMU_IRQ_ADCA_EVENT,             /*< FMU Event Source: ADCA Event(Error) */
    FMU_IRQ_ADCB_EVENT,             /*< FMU Event Source: ADCB Event(Error) */
    FMU_IRQ_ADCC_EVENT,             /*< FMU Event Source: ADCC Event(Error) */
    FMU_IRQ_ADCD_EVENT,             /*< FMU Event Source: ADCD Event(Error) */
    FMU_IRQ_CPU1_ADC_SAFE_CHK,      /*< FMU Event Source: CPU1 ADC Safe Check(Error) */
    FMU_IRQ_EPWM1_TZ_EVENT,         /*< FMU Event Source: EPWM1 TripZone Event */
    FMU_IRQ_EPWM2_TZ_EVENT,         /*< FMU Event Source: EPWM2 TripZone Event */
    FMU_IRQ_EPWM3_TZ_EVENT,         /*< FMU Event Source: EPWM3 TripZone Event */
    FMU_IRQ_EPWM4_TZ_EVENT,         /*< FMU Event Source: EPWM4 TripZone Event */
    FMU_IRQ_EPWM5_TZ_EVENT,         /*< FMU Event Source: EPWM5 TripZone Event */
    FMU_IRQ_EPWM6_TZ_EVENT,         /*< FMU Event Source: EPWM6 TripZone Event */
    FMU_IRQ_EPWM7_TZ_EVENT,         /*< FMU Event Source: EPWM7 TripZone Event */
    FMU_IRQ_EPWM8_TZ_EVENT,         /*< FMU Event Source: EPWM8 TripZone Event */
    FMU_IRQ_EPWM9_TZ_EVENT,         /*< FMU Event Source: EPWM9 TripZone Event */
    FMU_IRQ_EPWM10_TZ_EVENT,        /*< FMU Event Source: EPWM10 TripZone Event */
    FMU_IRQ_EPWM11_TZ_EVENT,        /*< FMU Event Source: EPWM11 TripZone Event */
    FMU_IRQ_EPWM12_TZ_EVENT,        /*< FMU Event Source: EPWM12 TripZone Event */
    FMU_IRQ_EPWM13_TZ_EVENT,        /*< FMU Event Source: EPWM13 TripZone Event */
    FMU_IRQ_EPWM14_TZ_EVENT,        /*< FMU Event Source: EPWM14 TripZone Event */
    FMU_IRQ_EPWM15_TZ_EVENT,        /*< FMU Event Source: EPWM15 TripZone Event */
    FMU_IRQ_EPWM16_TZ_EVENT,        /*< FMU Event Source: EPWM16 TripZone Event */
    FMU_IRQ_EPWM17_TZ_EVENT,        /*< FMU Event Source: EPWM17 TripZone Event */
    FMU_IRQ_EPWM18_TZ_EVENT,        /*< FMU Event Source: EPWM18 TripZone Event */
    FMU_IRQ_CAN1_ERR,               /*< FMU Event Source: CAN1 Error */
    FMU_IRQ_CAN1_ECC_ERR,           /*< FMU Event Source: CAN1 ECC Error */
    FMU_IRQ_CANFD1_ERR,             /*< FMU Event Source: CANFD1 Error */
    FMU_IRQ_CANFD1_ECC_ERR,         /*< FMU Event Source: CANFD1 ECC Error */
    FMU_IRQ_CANFD2_ERR,             /*< FMU Event Source: CANFD2 Error */
    FMU_IRQ_CANFD2_ECC_ERR,         /*< FMU Event Source: CANFD2 ECC Error */
    FMU_IRQ_LIN1_ERR,               /*< FMU Event Source: LIN1 Error */
    FMU_IRQ_LIN2_ERR,               /*< FMU Event Source: LIN2 Error */
    FMU_IRQ_BACKUP_SRAM_PAR_ERR,    /*< FMU Event Source: LIN2 Error */
    FMU_IRQ_SDFM1_ERR,              /*< FMU Event Source: SDFM1 Error */
    FMU_IRQ_SDFM2_ERR,              /*< FMU Event Source: SDFM2 Error */
    FMU_IRQ_SDFM3_ERR,              /*< FMU Event Source: SDFM3 Error */
    FMU_IRQ_SDFM4_ERR,              /*< FMU Event Source: SDFM4 Error */
    FMU_IRQ_CPU1_LOCKUP_EVENT,      /*< FMU Event Source: CPU1 Lockup Event */
    FMU_IRQ_CPU2_LOCKUP_EVENT,      /*< FMU Event Source: CPU2 Lockup Event */
    FMU_IRQ_CPU2_ADC_SAFE_CHK,      /*< FMU Event Source: CPU2 ADC Safe Check(Error) */
    FMU_IRQ_EQEP1 = 58U,            /*< FMU Event Source: EQEP1 */
    FMU_IRQ_EQEP2,                  /*< FMU Event Source: EQEP2 */
    FMU_IRQ_EQEP3,                  /*< FMU Event Source: EQEP3 */
    FMU_IRQ_EQEP4,                  /*< FMU Event Source: EQEP4 */
    FMU_IRQ_EQEP5,                  /*< FMU Event Source: EQEP5 */
    FMU_IRQ_EQEP6                   /*< FMU Event Source: EQEP6 */
} FMU_Event;

/**
  * @}
  */

/** @defgroup FMU_CFG FMU Register Configuration
  * @{
  * @brief  Macro definitions about FMU Register Configuration.
  * @note   Multiple bit can be set together.
  */
typedef enum {
    FMU_CFG_FMUMOD          = 0x1U,      /*< FMU Register Configuration Error Int/Flag/ClearFlag: FMUMOD Register */
    FMU_CFG_FMU_EVENT_RAW_I = 0x2U,      /*< FMU Register Configuration Error Int/Flag/ClearFlag: FMU_EVENT_RAW_I Register */
    FMU_CFG_FMU_PIN_CTRL    = 0x1000U    /*< FMU Register Configuration Error Int/Flag/ClearFlag: FMU_PIN_CTRL Register */
} FMU_Cfg;

/**
  * @}
  */

/** @defgroup FMU_CORESELECT FMU Event CPU1/2 Selection
  * @{
  * @brief  Macro definitions about FMU event that be assigned to CPU1/2.
  */
typedef enum {
    FMU_CORE_CPU1_2 = 0U,    /*!< CPU1 and CPU2 selected as controller core */
    FMU_CORE_CPU1,           /*!< CPU1 selected as controller core */
    FMU_CORE_CPU2            /*!< CPU2 selected as controller core */
} FMU_CoreSelect;

/**
  * @}
  */

/** @defgroup FMU_UNLOCK FMU Lock and Unlock Macros
  * @{
  * @brief Macro definitions for FMU lock and unlock operations.
  * @note  These macros are used to enable or disable critical sections in the FMU configuration.
  */
#define FMU_UNLOCK    (0x43533636UL)    /*!< Unlock FMU register access */
#define FMU_LOCK      (~ FMU_UNLOCK)    /*!< Lock FMU register access */

/**
  * @}
  */

/** @defgroup FMU_RST FMU RST Macros
  * @{
  * @brief Macro definitions for FMU rst operations.
  * @note  These macros are used to rst FMU Module.
  */
#define FMU_RST    (0xFUL)    /*!< Rst FMU Module */

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
 * \brief  Gets the pid of the specified fmu ip.
 * \param  fmu    FMU pointer to a FMU_TypeDef structure
 *                 - FMU: FMU base address index
 * \return Returns the pid of the specified fmu ip
 *                 - uint32_t: 32bit FMU ID
 */
static inline uint32_t FMU_getPid (FMU_TypeDef *fmu)
{
    return READ_REG(fmu->PID.WORDVAL);
}

/**
 * \brief  Unlock the FMU Register Access.
 * \param  fmu    FMU pointer to a FMU_TypeDef structure
 *                 - FMU: FMU base address index
 * \note   This function unlocks access to certain FMU registers by writing a specific unlock key
 *         to the LOCK register (FMU->LOCK). This is necessary before modifying protected FMU registers.
 */
static inline void FMU_unlockFmuRegister (FMU_TypeDef *fmu)
{
    WRITE_REG(fmu->LOCK.WORDVAL, FMU_UNLOCK);
}

/**
 * \brief  Lock the FMU Register Access.
 * \param  fmu    FMU pointer to a FMU_TypeDef structure
 *                 - FMU: FMU base address index
 * \note   This function locks access to certain FMU registers by writing a specific lock key
 *         to the LOCK register (FMU->LOCK). This prevents accidental modification of protected FMU registers.
 */
static inline void FMU_lockFmuRegister (FMU_TypeDef *fmu)
{
    WRITE_REG(fmu->LOCK.WORDVAL, FMU_LOCK);
}

/**
 * \brief  Reset the FMU Module.
 * \param  fmu    FMU pointer to a FMU_TypeDef structure
 *                 - FMU: FMU base address index
 */
static inline void FMU_rstSft (FMU_TypeDef *fmu)
{
    WRITE_REG(fmu->SFTRST.WORDVAL, FMU_RST);
}

/**
 * \brief  Set the FMU Work Mode.
 * \param  fmu    FMU pointer to a FMU_TypeDef structure
 *                 - FMU: FMU base address index
 * \param  mod    FMU Work Mode
 *                 This parameter can be any value of @ref FMU_MODE
 */
static inline void FMU_setMod (FMU_TypeDef *fmu, FMU_Mode mod)
{
    WRITE_REG(fmu->MODE.WORDVAL, (uint32_t)mod);
}

/**
 * \brief  Configure the Error Pin.
 * \param  fmu    FMU pointer to a FMU_TypeDef structure
 *                 - FMU: FMU base address index
 * \param  mod    Error Pin Mode
 *                 This parameter can be any value of @ref FMU_ERRORPINMODE
 * \param  pol    Error Pin Polarity
 *                 This parameter can be any value of @ref FMU_ERRORPINPOLARITY
 */
static inline void FMU_setErrorPin (FMU_TypeDef *fmu, FMU_ErrorPinMode mod, FMU_ErrorPinPolarity pol)
{
    MODIFY_REG(fmu->PINCTRL.WORDVAL, FMU_PINCTRL_PINCTRL_M | FMU_PINCTRL_ERRPINPOL_M, (uint32_t)pol | (uint32_t)mod);
}

/**
 * \brief  Get the Error Pin Status.
 * \param  fmu    FMU pointer to a FMU_TypeDef structure
 *                 - FMU: FMU base address index
 * \return Returns the status of Error Pin
 *                 - 0: the Error Pin is low.
 *                 - 1: the Error Pin is high.
 */
static inline uint8_t FMU_getErrPinSts (FMU_TypeDef *fmu)
{
    return ((READ_BIT(fmu->PINCTRL.WORDVAL, FMU_PINCTRL_ERRPINSTS_M) == 0UL) ? 0UL : 1UL);
}

/**
 * \brief  Enable FDTH.
 * \param  fmu    FMU pointer to a FMU_TypeDef structure
 *                 - FMU: FMU base address index
 */
static inline void FMU_enableFdth (FMU_TypeDef *fmu)
{
    SET_BIT(fmu->PINCTRL.WORDVAL, FMU_PINCTRL_FDTHEN_M);
}

/**
 * \brief  Disable FDTH.
 * \param  fmu    FMU pointer to a FMU_TypeDef structure
 *                 - FMU: FMU base address index
 */
static inline void FMU_disableFdth (FMU_TypeDef *fmu)
{
    CLEAR_BIT(fmu->PINCTRL.WORDVAL, FMU_PINCTRL_FDTHEN_M);
}

/**
 * \brief  Set Error Pin active last time.
 * \param  fmu      FMU pointer to a FMU_TypeDef structure
 *                   - FMU: FMU base address index
 * \param  count    This is the value that will be pre-loaded in to the counter
 *                   - uint32_t: between 0x0UL and 0x00FFFFFFUL
 */
static inline void FMU_setCntPre (FMU_TypeDef *fmu, uint32_t count)
{
    WRITE_REG(fmu->CNTPRE.WORDVAL, count);
}

/**
 * \brief  Get Error Pin active last time.
 * \param  fmu    FMU pointer to a FMU_TypeDef structure
 *                 - FMU: FMU base address index
 * \return Returns the value that will be pre-loaded in to the counter
 *                 - uint32_t: between 0x0UL and 0x00FFFFFFUL
 */
static inline uint32_t FMU_getCntPre (FMU_TypeDef *fmu)
{
    return READ_REG(fmu->CNTPRE.WORDVAL);
}

/**
 * \brief  Enable Cgf Error Interrupt.
 * \param  fmu       FMU pointer to a FMU_TypeDef structure
 *                    - FMU: FMU base address index
 * \param  cfgVal    This is the register that may cause error
 *                    - This parameter can be any value of @ref FMU_CFG
 */
static inline void FMU_enableCfgInt (FMU_TypeDef *fmu, FMU_Cfg cfgVal)
{
    SET_BIT(fmu->CFGINTEN.WORDVAL, cfgVal);
}

/**
 * \brief  Disable Cgf Error Interrupt.
 * \param  fmu       FMU pointer to a FMU_TypeDef structure
 *                    - FMU: FMU base address index
 * \param  cfgVal    This is the register that may cause error
 *                    - This parameter can be any value of @ref FMU_CFG
 */
static inline void FMU_disableCfgInt (FMU_TypeDef *fmu, FMU_Cfg cfgVal)
{
    CLEAR_BIT(fmu->CFGINTEN.WORDVAL, cfgVal);
}

/**
 * \brief  Get Cgf Error Status.
 * \param  fmu       FMU pointer to a FMU_TypeDef structure
 *                    - FMU: FMU base address index
 * \param  cfgVal    This is the register that may cause error
 *                    - This parameter can be any value of @ref FMU_CFG
 * \return Returns FMU Cfg Error Status.
 *                    - 0: The FMU Cfg Error did not happen.
 *                    - 1: The FMU Cfg Error happened.
 */
static inline uint32_t FMU_getCfgErrorStatus (FMU_TypeDef *fmu, FMU_Cfg cfgVal)
{
    return READ_BIT(fmu->CFGSTS.WORDVAL, cfgVal)? 1UL : 0UL;
}

/**
 * \brief  Clear Cgf Error Status.
 * \param  fmu       FMU pointer to a FMU_TypeDef structure
 *                    - FMU: FMU base address index
 * \param  cfgVal    This is the register that may cause error
 *                    - This parameter can be any value of @ref FMU_CFG
 */
static inline void FMU_clrCfgErrorStatus (FMU_TypeDef *fmu, FMU_Cfg cfgVal)
{
    WRITE_REG(fmu->CFGCLR.WORDVAL, cfgVal);
}

/**
 * \brief  Enable FMU Event Interrupt.
 * \param  fmu        FMU pointer to a FMU_TypeDef structure
 *                     - FMU: FMU base address index
 * \param  eventID    This is the Event that may cause FMU error
 *                     - This parameter can be any value of @ref FMU_EVENT
 */
static inline void FMU_enableEventInt (FMU_TypeDef *fmu, FMU_Event eventID)
{
    SET_BIT(fmu->EVTINTCFG[eventID >> 5U].INTENSET.WORDVAL, 0x1UL << (eventID & 0x1FU));
}

/**
 * \brief  Disable FMU Event Interrupt.
 * \param  fmu        FMU pointer to a FMU_TypeDef structure
 *                     - FMU: FMU base address index
 * \param  eventID    This is the Event that may cause FMU error
 *                     - This parameter can be any value of @ref FMU_EVENT
 */
static inline void FMU_disableEventInt (FMU_TypeDef *fmu, FMU_Event eventID)
{
    WRITE_REG(fmu->EVTINTCFG[eventID >> 5U].INTENCLR.WORDVAL, 0x1UL << (eventID & 0x1FU));
}

/**
 * \brief  Get FMU Interrupt Status.
 * \param  fmu        FMU pointer to a FMU_TypeDef structure
 *                     - FMU: FMU base address index
 * \param  eventID    This is the Event that may cause FMU error
 *                     - This parameter can be any value of @ref FMU_EVENT
 * \return Returns FMU Interrupt Status.
 *                     - 0: The FMU Interrupt did not happen.
 *                     - 1: The FMU Interrupt happened.
 */
static inline uint32_t FMU_getIntStatus (FMU_TypeDef *fmu, FMU_Event eventID)
{
    return READ_BIT(fmu->EVTINTCFG[eventID >> 5U].INTSTS.WORDVAL, 0x1UL << (eventID & 0x1FU))? 1UL : 0UL;
}

/**
 * \brief  Clear FMU Interrupt Status.
 * \param  fmu        FMU pointer to a FMU_TypeDef structure
 *                     - FMU: FMU base address index
 * \param  eventID    This is the Event that may cause FMU error
 *                     - This parameter can be any value of @ref FMU_EVENT
 */
static inline void FMU_clrIntStatus (FMU_TypeDef *fmu, FMU_Event eventID)
{
    WRITE_REG(fmu->EVTINTCFG[eventID >> 5U].INTCLR.WORDVAL, 0x1UL << (eventID & 0x1FU));
}

/**
 * \brief  Get FMU Event Status.
 * \param  fmu        FMU pointer to a FMU_TypeDef structure
 *                     - FMU: FMU base address index
 * \param  eventID    This is the Event that may cause FMU error
 *                     - This parameter can be any value of @ref FMU_EVENT
 * \return Returns FMU Event Status
 *                     - 0: The specified FMU Event did not happen.
 *                     - 1: The specified FMU Event happened.
 */
static inline uint32_t FMU_getEventStatus (FMU_TypeDef *fmu, FMU_Event eventID)
{
    return READ_BIT(fmu->EVTINTCFG[eventID >> 5U].EVTSTS.WORDVAL, 0x1UL << (eventID & 0x1FU))? 1UL : 0UL;
}

/**
 * \brief  Clear FMU Event Status.
 * \param  fmu        FMU pointer to a FMU_TypeDef structure
 *                     - FMU: FMU base address index
 * \param  eventID    This is the Event that may cause FMU error
 *                     - This parameter can be any value of @ref FMU_EVENT
 */
static inline void FMU_clrEventStatus (FMU_TypeDef *fmu, FMU_Event eventID)
{
    WRITE_REG(fmu->EVTINTCFG[eventID >> 5U].EVTCLR.WORDVAL, 0x1UL << (eventID & 0x1FU));
}

/**
 * \brief  Generate FMU Event.
 * \param  fmu        FMU pointer to a FMU_TypeDef structure
 *                     - FMU: FMU base address index
 * \param  eventID    This is the Event that may cause FMU error
 *                     - This parameter can be any value of @ref FMU_EVENT
 */
static inline void FMU_generateEvent (FMU_TypeDef *fmu, FMU_Event eventID)
{
    SET_BIT(fmu->EVTINTCFG[eventID >> 5U].EVTSET.WORDVAL, 0x1UL << (eventID & 0x1FU));
}

/**
 * \brief  Enable FMU Event To Change Error Pin.
 * \param  fmu        FMU pointer to a FMU_TypeDef structure
 *                     - FMU: FMU base address index
 * \param  eventID    This is the Event that may cause FMU error
 *                     - This parameter can be any value of @ref FMU_EVENT
 */
static inline void FMU_enableEventToPin (FMU_TypeDef *fmu, FMU_Event eventID)
{
    SET_BIT(fmu->EVTINTCFG[eventID >> 5U].PINENSET.WORDVAL, 0x1UL << (eventID & 0x1FU));
}

/**
 * \brief  Disable FMU Event To Change Error Pin.
 * \param  fmu        FMU pointer to a FMU_TypeDef structure
 *                     - FMU: FMU base address index
 * \param  eventID    This is the Event that may cause FMU error
 *                     - This parameter can be any value of @ref FMU_EVENT
 */
static inline void FMU_disableEventToPin (FMU_TypeDef *fmu, FMU_Event eventID)
{
    WRITE_REG(fmu->EVTINTCFG[eventID >> 5U].PINENCLR.WORDVAL, 0x1UL << (eventID & 0x1FU));
}

/**
 * \brief  Get whether the specified FMU Event affected Error Pin.
 * \param  fmu        FMU pointer to a FMU_TypeDef structure
 *                     - FMU: FMU base address index
 * \param  eventID    This is the Event that may cause FMU error
 *                     - This parameter can be any value of @ref FMU_EVENT
 * \return Returns FMU Event Status
 *                     - 0: The specified FMU Event did not affect Error Pin.
 *                     - 1: The specified FMU Event happened and affected Error Pin.
 */
static inline uint32_t FMU_getEventToPinStatus (FMU_TypeDef *fmu, FMU_Event eventID)
{
    return READ_BIT(fmu->EVTINTCFG[eventID >> 5U].PINSTS.WORDVAL, 0x1UL << (eventID & 0x1FU))? 1UL : 0UL;
}

/**
 * \brief  Clear Error Pin Status.
 * \param  fmu        FMU pointer to a FMU_TypeDef structure
 *                     - FMU: FMU base address index
 * \param  eventID    This is the Event that may cause FMU error
 *                     - This parameter can be any value of @ref FMU_EVENT
 */
static inline void FMU_clrErrorPinStatus (FMU_TypeDef *fmu, FMU_Event eventID)
{
    WRITE_REG(fmu->EVTINTCFG[eventID >> 5U].PINCLR.WORDVAL, 0x1UL << (eventID & 0x1FU));
}

/**
  * \brief  Selects the controller core of a FMU event
  * \param  fmu        FMU pointer to a FMU_TypeDef structure
  *                     - FMU: FMU base address index
  * \param  eventID    This is the Event that may cause FMU error
  *                     - This parameter can be any value of @ref FMU_EVENT
  * \param  core       FMU is the core controller of a FMU event
  *                     This parameter can be any value of @ref FMU_CORESELECT
  */
extern void FMU_setControllerCore (FMU_TypeDef *fmu, FMU_Event eventID, FMU_CoreSelect core);


#ifdef __cplusplus
}
#endif


#endif /* __FMU_H__ */
