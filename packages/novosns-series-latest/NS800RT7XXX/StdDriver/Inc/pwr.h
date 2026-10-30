/**
  * @file       pwr.h
  * @author     Alex-J
  * @brief      Header file for NS800RTxxx PWR module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __PWR_H__
#define __PWR_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup PWR_EXPORTED_TYPES PWR Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'PWR' module.
  */

// /** @defgroup PWR_MRLDOVOLT PWR Module's Main regulator of LDO Voltage
//   * @{
//   * @brief  Values are used to control the ldo voltage of the PWR.
//   */
// typedef enum {
//     PWR_STOP_LDO_1_1V = 0U,    /*!< LDO output 1.1v in stop mode */
//     PWR_STOP_LDO_0_9V          /*!< LDO output 0.9v in stop mode */
// } PWR_MrLdoVolt;

// /**
//   * @}
//   */

/** @defgroup PWR_ACTLDOVOLT PWR Module's Active Mode of LDO Voltage
  * @{
  * @brief  Values are used to control the ldo voltage of the PWR.
  */
typedef enum {
    PWR_ACTIVE_LDO_1_1V = 0U,    /*!< LDO output 1.1v in active mode */
    PWR_ACTIVE_LDO_1_15V         /*!< LDO output 1.15v in active mode */
} PWR_ActLdoVolt;

/**
  * @}
  */

/** @defgroup PWR_FLASHPWRDOWN PWR Module's Flash enters Power Down
  * @{
  * @brief  Values are used to control the ldo voltage of the PWR.
  */
typedef enum {
    PWR_STOP_FLASH_NO_PWR_DOWN = 0U,    /*!< Flash doesn't enter power down in stop mode */
    PWR_STOP_FLASH_PWR_DOWN             /*!< Flash enters power down in stop mode */
} PWR_FlashPwrDown;

/**
  * @}
  */

/** @defgroup PWR_LVDDNFSELCT PWR Module's Digital Noise Filter
  *            Sampling Clock Selection
  * @{
  * @brief  Values are used to control the LVD digital noise filter 
  *         sampling clock selection of the PWR.
  */
typedef enum {
    PWR_LVD_DNF_4_FILT_CLK_CYCLES = 0U,    /*!< 4 filter clock (LIRC) cycles */
    PWR_LVD_DNF_16_FILT_CLK_CYCLES,        /*!< 16 filter clock (LIRC) cycles */
    PWR_LVD_DNF_64_FILT_CLK_CYCLES,        /*!< 64 filter clock (LIRC) cycles */
    PWR_LVD_DNF_128_FILT_CLK_CYCLES        /*!< 128 filter clock (LIRC) cycles */
} PWR_LVDDNFSelct;

/**
  * @}
  */

/** @defgroup PWR_LVDIRSELCT PWR Module's LVD Interrupt and Reset
  *            Selection
  * @{
  * @brief  Values are used to control the LVD interrupt and reset 
  *         selection of the PWR.
  */
typedef enum {
    PWR_LVD_INTERRUPT_MODE = 0U,    /*!< LVD Interrupt */
    PWR_LVD_RESET_MODE              /*!< LVD Reset  */
} PWR_LVDIRSelct;

/**
  * @}
  */

/** @defgroup PWR_WKUPPINPARITY PWR Module's Wakeup Pin Parity
  * @{
  * @brief  Values are used to control the wakeup pin parity 
  *         of the PWR.
  */
typedef enum {
    PWR_WKUP_DETC_HIGH = 0U,    /*!< Detect at high level (rising edge)  */
    PWR_WKUP_DETC_LOW           /*!< Detect at low level (falling edge)  */
} PWR_WkupPinParity;

/**
  * @}
  */

/** @defgroup PWR_DEEPSLEEPMODE PWR Module's Deep Sleep Mode
  * @{
  * @brief  Values are used to select the deep sleep mode
  *         of the PWR.
  */
typedef enum {
    PWR_CPUn_DSLP_KEEP_STOP_MODE = 0U,    /*!< CPUn keep stop mode in deep sleep mode */
    PWR_CPUn_DSLP_INTO_STANDBY_MODE       /*!< CPUn into standby mode in deep sleep mode */
} PWR_DeepSleepMode;

/**
  * @}
  */

/** @defgroup PWR_LOWPOWERSTATUS PWR Module's Low Power Status
  * @{
  * @brief  Values are used to show the low power status
  *         of the PWR.
  */
typedef enum {
    PWR_CPUn_KEEP_RUN_STATUS = 0U,    /*!< CPUn keep run status in low power mode */
    PWR_CPUn_INTO_SLEEP_STATUS,       /*!< CPUn into sleep status in low power mode */
    PWR_CPUn_INTO_STOP_STATUS         /*!< CPUn into slop status in low power mode */
} PWR_LowPowerStatus;

/**
  * @}
  */


/** @defgroup PWR_WAITMODE PWR Module's Wait Mode
  * @{
  * @brief  Values are used to control the wait mode of the PWR.
  */
typedef enum {
    PWR_WAIT_MODE_WFI = 0U,    /*!< Wait mode using WFI */
    PWR_WAIT_MODE_WFE          /*!< Wait mode using WFE */
} PWR_WaitMode;

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
 * \brief  Sets the PWR Control Register 1 
 * \note   This function sets the control register 1 of the PWR
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  config  a value of control register 1 configuration.
 */
static inline void PWR_setCtrlReg1 (PWR_TypeDef *pwr, uint16_t config)
{
    SET_BIT(pwr->CR1.WORDVAL, (uint32_t)config);
}

/**
 * \brief  Clears the PWR Control Register 1 
 * \note   This function clears the control register 1 of the PWR
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  config  a value of control register 1 configuration.
 */
static inline void PWR_clearCtrlReg1 (PWR_TypeDef *pwr, uint16_t config)
{
    CLEAR_BIT (pwr->CR1.WORDVAL, (uint32_t)config);
}

/**
 * \brief  Gets the PWR Control Register 1 .
 * \note   This function returns the value for the PWR Control Register 1.
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \return Returns the value of Control Register 1.
 */
static inline uint16_t PWR_getCtrlReg1 (PWR_TypeDef *pwr)
{
    return (uint16_t)(pwr->CR1.WORDVAL);
}

/**
 * \brief  Enables the system to enter low power in PWR Control Register 1 .
 * \note   This function enables the system to enter low power in Control Register 1 
 *         of the PWR.
 *
 * \param  pwr   pwr pointer to a PWR_TypeDef structure
 *                 - PWR: PWR base address index
 */
static inline void PWR_enableSystemLowPower (PWR_TypeDef *pwr)
{
    MODIFY_REG(pwr->CR1.WORDVAL, PWR_CR1_SYSLPEN_M, (uint32_t)ENABLE);
}

/**
 * \brief  Disables the system to enter low power in PWR Control Register 1 .
 * \note   This function disables the system to enter low power in Control Register 1 
 *         of the PWR.
 *
 * \param  pwr   pwr pointer to a PWR_TypeDef structure
 *                 - PWR: PWR base address index
 */
static inline void PWR_disableSystemLowPower (PWR_TypeDef *pwr)
{
    MODIFY_REG(pwr->CR1.WORDVAL, PWR_CR1_SYSLPEN_M, (uint32_t)DISABLE);
}

// /**
//  * \brief  Selects the Main Regulator of LDO Voltage Selection in Stop Mode.
//  * \note   This function selects the main regulator of stop mode LDO voltage
//  *         in Control Register 1 of the PWR.
//  *
//  * \param  pwr  pwr pointer to a PWR_TypeDef structure
//  *                - PWR: PWR base address index
//  * \param  ldo  the value is used to select the ldo voltage in stop mode
//  */
// static inline void PWR_selectStopLdoVolt (PWR_TypeDef *pwr, PWR_MrLdoVolt ldo)
// {
//     MODIFY_REG(pwr->CR1.WORDVAL, PWR_CR1_MRLVOS_M, ((uint32_t)ldo << PWR_CR1_MRLVOS_S));
// }

/**
 * \brief  Selects the Main Regulator of LDO Voltage Selection in Active Mode.
 * \note   This function selects the main regulator of active mode LDO voltage
 *         in Control Register 1 of the PWR.
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ldo  the value is used to select the ldo voltage in active mode
 */
static inline void PWR_selectActiveLdoVolt (PWR_TypeDef *pwr, PWR_ActLdoVolt ldo)
{
    MODIFY_REG(pwr->CR1.WORDVAL, PWR_CR1_ACTVOS_M, ((uint32_t)ldo << PWR_CR1_ACTVOS_S));
}


/**
 * \brief  Selects the Flash to enter power down .
 * \note   This function selects the flash to enter power down
 *         in Control Register 1 of the PWR.
 *
 * \param  pwr       pwr pointer to a PWR_TypeDef structure
 *                     - PWR: PWR base address index
 * \param  flashPwr  the value is used to control the flash power
 */
static inline void PWR_selectFlashPwr (PWR_TypeDef *pwr, PWR_FlashPwrDown flashPwr)
{
    MODIFY_REG(pwr->CR1.WORDVAL, PWR_CR1_FDPDE_M, ((uint32_t)flashPwr << PWR_CR1_FDPDE_S));
}

/**
 * \brief  Sets the PWR Control Register 2 
 * \note   This function sets the control register 2 of the PWR
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  config  a value of control register 2 configuration.
 */
static inline void PWR_setCtrlReg2 (PWR_TypeDef *pwr, uint16_t config)
{
    SET_BIT(pwr->CR2.WORDVAL, (uint32_t)config);
}

/**
 * \brief  Clears the PWR Control Register 2 
 * \note   This function clears the control register 2 of the PWR
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  config  a value of control register 2 configuration.
 */
static inline void PWR_clearCtrlReg2 (PWR_TypeDef *pwr, uint16_t config)
{
    CLEAR_BIT(pwr->CR2.WORDVAL, (uint32_t)config);
}

/**
 * \brief  Gets the PWR Control Register 2 .
 * \note   This function returns the value for the PWR Control Register 2.
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \return Returns the value of Control Register 2.
 */
static inline uint16_t PWR_getCtrlReg2 (PWR_TypeDef *pwr)
{
    return (uint16_t)(pwr->CR2.WORDVAL);
}

// /**
//  * \brief  Enables Over-Temperature Protection in PWR Control Register 2.
//  * \note   This function enables the Over-Temperature protection in 
//  *         Control Register 2 of the PWR.
//  *
//  * \param  pwr     pwr pointer to a PWR_TypeDef structure
//  *                   - PWR: PWR base address index
//  * \param  enable  the value is used to enable Over-Temperature protection
//  *                 0: disable; 1: enable
//  */
// static inline void PWR_enableOverTempProtect (PWR_TypeDef *pwr, uint8_t enable)
// {
//     MODIFY_REG(pwr->CR2.WORDVAL, PWR_CR2_OVTPE_M, (uint32_t)enable << PWR_CR2_OVTPE_S);
// }

/**
 * \brief  Enables Backup LDO in PWR Control Register 2.
 * \note   This function enables the backup LDO in Control Register 2 
 *         of the PWR.
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  enable  the value is used to enable the backup LDO
 *                 0: disable; 1: enable
 */
static inline void PWR_enableBackLdo (PWR_TypeDef *pwr, uint8_t enable)
{
    MODIFY_REG(pwr->CR2.WORDVAL, PWR_CR2_BKREN_M, (uint32_t)enable << PWR_CR2_BKREN_S);
}

/**
 * \brief  Enables LVD Interrupt and Reset Function in PWR Control Register 2.
 * \note   This function enables the LVD interrupt and reset function 
 *         in Control Register 2 of the PWR.
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  enable  the value is used to enable the LVD interrupt and reset function 
 *                 0: disable; 1: enable
 */
static inline void PWR_enableLvdIrFunction (PWR_TypeDef *pwr, uint8_t enable)
{
    MODIFY_REG(pwr->CR2.WORDVAL, PWR_CR2_LVDIRE_M, (uint32_t)enable << PWR_CR2_LVDIRE_S);
}

/**
 * \brief  Selects LVD Interrupt and Reset in PWR Control Register 2.
 * \note   This function selects the LVD interrupt and reset
 *         in Control Register 2 of the PWR.
 *
 * \param  pwr   pwr pointer to a PWR_TypeDef structure
 *                 - PWR: PWR base address index
 * \param  selc  the value is used to select the LVD interrupt and reset
 */
static inline void PWR_setLvdIrSelection (PWR_TypeDef *pwr, PWR_LVDIRSelct selc)
{
    MODIFY_REG(pwr->CR2.WORDVAL, PWR_CR2_LVDIRS_M, (uint32_t)selc << PWR_CR2_LVDIRS_S);
}

/**
 * \brief  Enables LVD Voltage Detection in PWR Control Register 2.
 * \note   This function enables the LVD voltage detection in Control Register 2 
 *         of the PWR.
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  enable  the value is used to enable the LVD voltage detection
 *                 0: disable; 1: enable
 */
static inline void PWR_enableLvd (PWR_TypeDef *pwr, uint8_t enable)
{
    MODIFY_REG(pwr->CR2.WORDVAL, PWR_CR2_LVDEN_M, (uint32_t)enable << PWR_CR2_LVDEN_S);
}

/**
 * \brief  Selects LVD Digital Noise Filter Sampling Clock
 *         in PWR Control Register 2.
 * \note   This function selects the LVD digital noise filter sampling clock
 *         in Control Register 2 of the PWR.
 *
 * \param  pwr   pwr pointer to a PWR_TypeDef structure
 *                 - PWR: PWR base address index
 * \param  selc  the value is used to select the LVD digital noise filter 
 *  `            sampling clock
 */
static inline void PWR_setLvdDnfSelection (PWR_TypeDef *pwr, PWR_LVDDNFSelct selc)
{
    MODIFY_REG(pwr->CR2.WORDVAL, PWR_CR2_LVDDNFS_M, (uint32_t)selc << PWR_CR2_LVDDNFS_S);
}

/**
 * \brief  Enables LVD Digital Noise Filter in PWR Control Register 2.
 * \note   This function enables the LVD digital noise filter 
 *         in Control Register 2 of the PWR.
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  enable  the value is used to enable the LVD digital noise filter 
 *                 0: disable; 1: enable
 */
static inline void PWR_enableLvdDnf (PWR_TypeDef *pwr, uint8_t enable)
{
    MODIFY_REG(pwr->CR2.WORDVAL, PWR_CR2_LVDDNFE_M, (uint32_t)enable << PWR_CR2_LVDDNFE_S);
}

/**
 * \brief  Sets the PWR Control Register 3 
 * \note   This function sets the control register 3 of the PWR
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  config  a value of control register 3 configuration.
 */
static inline void PWR_setCtrlReg3 (PWR_TypeDef *pwr, uint16_t config)
{
    SET_BIT(pwr->CR3.WORDVAL, (uint32_t)config);
}

/**
 * \brief  Clears the PWR Control Register 3 
 * \note   This function clears the control register 3 of the PWR
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  config  a value of control register 3 configuration.
 */
static inline void PWR_clearCtrlReg3 (PWR_TypeDef *pwr, uint16_t config)
{
    CLEAR_BIT(pwr->CR3.WORDVAL, (uint32_t)config);
}

/**
 * \brief  Gets the PWR Control Register 3 .
 * \note   This function returns the value for the PWR Control Register 3.
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \return Returns the value of Control Register 3.
 */
static inline uint16_t PWR_getCtrlReg3 (PWR_TypeDef *pwr)
{
    return (uint16_t)(pwr->CR3.WORDVAL);
}

/**
 * \brief  Enables Wakeup Pins in PWR Control Register 3.
 * \note   This function enables the wakeup pins in Control Register 3 
 *         of the PWR.
 *
 * \param  pwr      pwr pointer to a PWR_TypeDef structure
 *                    - PWR: PWR base address index
 * \param  wkupNum  the value is used to enable the wakeup pins 
 *                  Range \e 0~3 corresponds to \e WKUPE1~4
 */
static inline void PWR_enableWakeupPin (PWR_TypeDef *pwr, uint8_t wkupNum)
{
    if (wkupNum > 3)
    {
        return;
    }

    SET_BIT(pwr->CR3.WORDVAL, (uint32_t)1 << wkupNum);
}

/**
 * \brief  Disables Wakeup Pins in PWR Control Register 3.
 * \note   This function disables the wakeup pins in Control Register 3 
 *         of the PWR.
 *
 * \param  pwr      pwr pointer to a PWR_TypeDef structure
 *                    - PWR: PWR base address index
 * \param  wkupNum  the value is used to disable the wakeup pins 
 *                  Range \e 0~3 corresponds to \e WKUPE1~4
 */
static inline void PWR_disableWakeupPin (PWR_TypeDef *pwr, uint8_t wkupNum)
{
    if (wkupNum > 3)
    {
        return;
    }

    CLEAR_BIT(pwr->CR3.WORDVAL, (uint32_t)1 << wkupNum);
}

/**
 * \brief  Sets the PWR Control Register 4 
 * \note   This function sets the control register 4 of the PWR
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  config  a value of control register 4 configuration.
 */
static inline void PWR_setCtrlReg4 (PWR_TypeDef *pwr, uint16_t config)
{
    SET_BIT(pwr->CR4.WORDVAL, (uint32_t)config);
}

/**
 * \brief  Clears the PWR Control Register 4 
 * \note   This function clears the control register 4 of the PWR
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  config  a value of control register 4 configuration.
 */
static inline void PWR_clearCtrlReg4 (PWR_TypeDef *pwr, uint16_t config)
{
    CLEAR_BIT(pwr->CR4.WORDVAL, (uint32_t)config);
}

/**
 * \brief  Gets the PWR Control Register 4 .
 * \note   This function returns the value for the PWR Control Register 4.
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \return Returns the value of Control Register 4.
 */
static inline uint16_t PWR_getCtrlReg4 (PWR_TypeDef *pwr)
{
    return (uint16_t)(pwr->CR4.WORDVAL);
}

/**
 * \brief  Sets Wakeup Pin Parity in PWR Control Register 4.
 * \note   This function sets the wakeup pin parity in Control Register 4 
 *         of the PWR.
 *
 * \param  pwr      pwr pointer to a PWR_TypeDef structure
 *                    - PWR: PWR base address index
 * \param  wkupNum  the value is used to set the wakeup pin parity 
 *                  Range \e 0~3 corresponds to \e WKUPE1~4
 * \param  parity   the value is used to select the parity
 */
static inline void PWR_setWakeupPinParity (PWR_TypeDef *pwr, uint8_t wkupNum, PWR_WkupPinParity parity)
{
    if (wkupNum > 3)
    {
        return;
    }

    MODIFY_REG(pwr->CR4.WORDVAL, ((uint32_t)1 << wkupNum), ((uint32_t)parity << wkupNum));
}

/**
 * \brief  Gets the PWR Status Register 1.
 * \note   This function returns the value for the PWR Status Register 1.
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \return Returns the value of Status Register 1.
 */
static inline uint16_t PWR_getStatusReg1 (PWR_TypeDef *pwr)
{
    return (uint16_t)(pwr->SR1.WORDVAL);
}

/**
 * \brief  Gets the PWR Status Register 2.
 * \note   This function returns the value for the PWR Status Register 2.
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \return Returns the value of Status Register 2.
 */
static inline uint16_t PWR_getStatusReg2 (PWR_TypeDef *pwr)
{
    return (uint16_t)(pwr->SR2.WORDVAL);
}

/**
 * \brief  Sets the PWR Status Clear flag Register 
 * \note   This function sets the status clear flag register of the PWR
 *
 * \param  pwr      pwr pointer to a PWR_TypeDef structure
 *                    - PWR: PWR base address index
 * \param  clrFlag  a value used to clear the status clear flag register.
 */
static inline void PWR_setStatusClr (PWR_TypeDef *pwr, uint16_t clrFlag)
{
    SET_BIT(pwr->SCR.WORDVAL, (uint32_t)clrFlag);
}

/**
 * \brief  Sets the PWR PORT A PULL Enable Control Register 1 
 * \note   This function sets the port A pull enable control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortAPullEnCtrl1 (PWR_TypeDef *pwr, uint16_t pe)
{
    SET_BIT(pwr->PAPECR1.WORDVAL, (uint32_t)pe);
}

/**
 * \brief  Sets the PWR PORT A PULL Enable Control Register 2 
 * \note   This function sets the port A pull enable control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortAPullEnCtrl2 (PWR_TypeDef *pwr, uint16_t pe)
{
    SET_BIT(pwr->PAPECR2.WORDVAL, (uint32_t)pe);
}

/**
 * \brief  Sets the PWR PORT A PULL Selection Control Register 1 
 * \note   This function sets the port A pull selection control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortAPullSelCtrl1 (PWR_TypeDef *pwr, uint16_t ps)
{
    SET_BIT(pwr->PAPSCR1.WORDVAL, (uint32_t)ps);
}

/**
 * \brief  Sets the PWR PORT A PULL Selection Control Register 2 
 * \note   This function sets the port A pull selection control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortAPullSelCtrl2 (PWR_TypeDef *pwr, uint16_t ps)
{
    SET_BIT(pwr->PAPSCR2.WORDVAL, (uint32_t)ps);
}

/**
 * \brief  Sets the PWR PORT B PULL Enable Control Register 1 
 * \note   This function sets the port B pull enable control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortBPullEnCtrl1 (PWR_TypeDef *pwr, uint16_t pe)
{
    SET_BIT(pwr->PBPECR1.WORDVAL, (uint32_t)pe);
}

/**
 * \brief  Sets the PWR PORT B PULL Enable Control Register 2 
 * \note   This function sets the port B pull enable control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortBPullEnCtrl2 (PWR_TypeDef *pwr, uint16_t pe)
{
    SET_BIT(pwr->PBPECR2.WORDVAL, (uint32_t)(pe & PWR_PBPECR2_PE_M));
}

/**
 * \brief  Sets the PWR PORT B PULL Selection Control Register 1 
 * \note   This function sets the port B pull selection control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortBPullSelCtrl1 (PWR_TypeDef *pwr, uint16_t ps)
{
    SET_BIT(pwr->PBPSCR1.WORDVAL, (uint32_t)ps);
}

/**
 * \brief  Sets the PWR PORT B PULL Selection Control Register 2 
 * \note   This function sets the port B pull selection control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortBPullSelCtrl2 (PWR_TypeDef *pwr, uint16_t ps)
{
    SET_BIT(pwr->PBPSCR2.WORDVAL, (uint32_t)(ps & PWR_PBPSCR2_PS_M));
}

/**
 * \brief  Sets the PWR PORT C PULL Enable Control Register 1 
 * \note   This function sets the port C pull enable control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortCPullEnCtrl1 (PWR_TypeDef *pwr, uint16_t pe)
{
    SET_BIT(pwr->PCPECR1.WORDVAL, (uint32_t)(pe & PWR_PCPECR1_PE_M));
}

/**
 * \brief  Sets the PWR PORT C PULL Enable Control Register 2 
 * \note   This function sets the port C pull enable control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortCPullEnCtrl2 (PWR_TypeDef *pwr, uint16_t pe)
{
    SET_BIT(pwr->PCPECR2.WORDVAL, (uint32_t)(pe & PWR_PCPECR2_PE_M));
}

/**
 * \brief  Sets the PWR PORT C PULL Selection Control Register 1 
 * \note   This function sets the port C pull selection control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortCPullSelCtrl1 (PWR_TypeDef *pwr, uint16_t ps)
{
    SET_BIT(pwr->PCPSCR1.WORDVAL, (uint32_t)(ps & PWR_PCPSCR1_PS_M));
}

/**
 * \brief  Sets the PWR PORT C PULL Selection Control Register 2 
 * \note   This function sets the port C pull selection control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortCPullSelCtrl2 (PWR_TypeDef *pwr, uint16_t ps)
{
    SET_BIT(pwr->PCPSCR2.WORDVAL, (uint32_t)(ps & PWR_PCPSCR2_PS_M));
}

/**
 * \brief  Sets the PWR PORT D PULL Enable Control Register 1 
 * \note   This function sets the port D pull enable control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortDPullEnCtrl1 (PWR_TypeDef *pwr, uint16_t pe)
{
    SET_BIT(pwr->PDPECR1.WORDVAL, (uint32_t)(pe & PWR_PDPECR1_PE_M));
}

/**
 * \brief  Sets the PWR PORT D PULL Selection Control Register 1 
 * \note   This function sets the port D pull selection control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortDPullSelCtrl1 (PWR_TypeDef *pwr, uint16_t ps)
{
    SET_BIT(pwr->PDPSCR1.WORDVAL, (uint32_t)(ps & PWR_PDPSCR1_PS_M));
}

/**
 * \brief  Sets the PWR PORT E PULL Enable Control Register 1 
 * \note   This function sets the port E pull enable control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortEPullEnCtrl1 (PWR_TypeDef *pwr, uint8_t pe)
{
    SET_BIT(pwr->PEPECR1.WORDVAL, (uint32_t)(pe & PWR_PEPECR1_PE_M));
}

/**
 * \brief  Sets the PWR PORT E PULL Selection Control Register 1 
 * \note   This function sets the port E pull selection control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortEPullSelCtrl1 (PWR_TypeDef *pwr, uint8_t ps)
{
    SET_BIT(pwr->PEPSCR1.WORDVAL, (uint32_t)(ps & PWR_PEPSCR1_PS_M));
}

/**
 * \brief  Sets the PWR PORT F PULL Enable Control Register 1 
 * \note   This function sets the port F pull enable control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortFPullEnCtrl1 (PWR_TypeDef *pwr, uint16_t pe)
{
    SET_BIT(pwr->PFPECR1.WORDVAL, (uint32_t)(pe & PWR_PFPECR1_PE_M));
}

/**
 * \brief  Sets the PWR PORT F PULL Enable Control Register 2 
 * \note   This function sets the port F pull enable control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortFPullEnCtrl2 (PWR_TypeDef *pwr, uint16_t pe)
{
    SET_BIT(pwr->PFPECR2.WORDVAL, (uint32_t)(pe & PWR_PFPECR2_PE_M));
}

/**
 * \brief  Sets the PWR PORT F PULL Selection Control Register 1 
 * \note   This function sets the port F pull selection control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortFPullSelCtrl1 (PWR_TypeDef *pwr, uint16_t ps)
{
    SET_BIT(pwr->PFPSCR1.WORDVAL, (uint32_t)(ps & PWR_PFPSCR1_PS_M));
}

/**
 * \brief  Sets the PWR PORT F PULL Selection Control Register 2 
 * \note   This function sets the port F pull selection control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortFPullSelCtrl2 (PWR_TypeDef *pwr, uint16_t ps)
{
    SET_BIT(pwr->PFPSCR2.WORDVAL, (uint32_t)(ps & PWR_PFPSCR2_PS_M));
}

/**
 * \brief  Sets the PWR PORT G PULL Enable Control Register 1 
 * \note   This function sets the port G pull enable control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortGPullEnCtrl1 (PWR_TypeDef *pwr, uint16_t pe)
{
    SET_BIT(pwr->PGPECR1.WORDVAL, (uint32_t)(pe & PWR_PGPECR1_PE_M));
}

/**
 * \brief  Sets the PWR PORT G PULL Enable Control Register 2 
 * \note   This function sets the port G pull enable control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortGPullEnCtrl2 (PWR_TypeDef *pwr, uint16_t pe)
{
    SET_BIT(pwr->PGPECR2.WORDVAL, (uint32_t)(pe & PWR_PGPECR2_PE_M));
}

/**
 * \brief  Sets the PWR PORT G PULL Selection Control Register 1 
 * \note   This function sets the port G pull selection control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortGPullSelCtrl1 (PWR_TypeDef *pwr, uint16_t ps)
{
    SET_BIT(pwr->PGPSCR1.WORDVAL, (uint32_t)(ps & PWR_PGPSCR1_PS_M));
}

/**
 * \brief  Sets the PWR PORT G PULL Selection Control Register 2 
 * \note   This function sets the port G pull selection control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortGPullSelCtrl2 (PWR_TypeDef *pwr, uint16_t ps)
{
    SET_BIT(pwr->PGPSCR2.WORDVAL, (uint32_t)(ps & PWR_PGPSCR2_PS_M));
}

/**
 * \brief  Sets the PWR PORT H PULL Enable Control Register 1 
 * \note   This function sets the port H pull enable control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortHPullEnCtrl1 (PWR_TypeDef *pwr, uint16_t pe)
{
    SET_BIT(pwr->PHPECR1.WORDVAL, (uint32_t)(pe & PWR_PHPECR1_PE_M));
}

/**
 * \brief  Sets the PWR PORT H PULL Enable Control Register 2 
 * \note   This function sets the port H pull enable control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortHPullEnCtrl2 (PWR_TypeDef *pwr, uint16_t pe)
{
    SET_BIT(pwr->PHPECR2.WORDVAL, (uint32_t)(pe & PWR_PHPECR2_PE_M));
}

/**
 * \brief  Sets the PWR PORT H PULL Selection Control Register 1 
 * \note   This function sets the port H pull selection control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortHPullSelCtrl1 (PWR_TypeDef *pwr, uint8_t ps)
{
    SET_BIT(pwr->PHPSCR1.WORDVAL, (uint32_t)(ps & PWR_PHPSCR1_PS_M));
}

/**
 * \brief  Selects the power-down mode of CPU1 in Deep Sleep Mode。
 *
 * \note   This function selects he power-down mode of CPU1 in deep sleep mode
 *         through CPU1 control register of the PWR.
 *
 * \param  pwr   pwr pointer to a PWR_TypeDef structure
 *                 - PWR: PWR base address index
 * \param  mode  the value is used to select the the power-down mode 
 *  
 */
static inline void PWR_setCPU1DeepSleepMode (PWR_TypeDef *pwr, PWR_DeepSleepMode mode)
{
    MODIFY_REG(pwr->CPU1CR.WORDVAL, PWR_CPU1CR_CPDDS_M, (uint32_t)mode << PWR_CPU1CR_CPDDS_S);
}

/**
 * \brief  Gets the CPU1 Low Power Mode Startus .
 * \note   This function returns the value of the CPU1 low power status.
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \return Returns the value of the CPU1 low power status.
 */
static inline uint8_t PWR_getCPU1LowPowerStatus (PWR_TypeDef *pwr)
{
    return (uint8_t)(pwr->CPU1CR.BIT.CLPMS);
}

/**
 * \brief  Gets the CPU1 Stop Mode Flag .
 * \note   This function returns the value of the CPU1 stop mode flag.
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \return Returns the value of the CPU1 stop mode flag.
 */
static inline uint8_t PWR_getCPU1StopFlag (PWR_TypeDef *pwr)
{
    return (uint8_t)(pwr->CPU1CR.BIT.STOPF);
}

/**
 * \brief  Clears the CPU1 Stop Mode Flag
 * \note   This function clears the CPU1 stop mode flag.
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 */
static inline void PWR_clearCPU1StopFlag (PWR_TypeDef *pwr)
{
    SET_BIT(pwr->CPU1CR.WORDVAL, PWR_CPU1CR_CSSF_M);
}

/**
 * \brief  Selects the power-down mode of CPU2 in Deep Sleep Mode。
 *
 * \note   This function selects he power-down mode of CPU2 in deep sleep mode
 *         through CPU2 control register of the PWR.
 *
 * \param  pwr   pwr pointer to a PWR_TypeDef structure
 *                 - PWR: PWR base address index
 * \param  mode  the value is used to select the the power-down mode 
 *  
 */
static inline void PWR_setCPU2DeepSleepMode (PWR_TypeDef *pwr, PWR_DeepSleepMode mode)
{
    MODIFY_REG(pwr->CPU2CR.WORDVAL, PWR_CPU2CR_CPDDS_M, (uint32_t)mode << PWR_CPU2CR_CPDDS_S);
}

/**
 * \brief  Gets the CPU2 Low Power Mode Startus .
 * \note   This function returns the value of the CPU2 low power status.
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \return Returns the value of the CPU2 low power status.
 */
static inline uint8_t PWR_getCPU2LowPowerStatus (PWR_TypeDef *pwr)
{
    return (uint8_t)(pwr->CPU2CR.BIT.CLPMS);
}

/**
 * \brief  Gets the CPU2 Stop Mode Flag .
 * \note   This function returns the value of the CPU2 stop mode flag.
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \return Returns the value of the CPU2 stop mode flag.
 */
static inline uint8_t PWR_getCPU2StopFlag (PWR_TypeDef *pwr)
{
    return (uint8_t)(pwr->CPU2CR.BIT.STOPF);
}

/**
 * \brief  Clears the CPU2 Stop Mode Flag
 * \note   This function clears the CPU2 stop mode flag.
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 */
static inline void PWR_clearCPU2StopFlag (PWR_TypeDef *pwr)
{
    SET_BIT(pwr->CPU2CR.WORDVAL, PWR_CPU2CR_CSSF_M);
}

/**
 * \brief  Sets the RAM Low-Power Control Register 
 * \note   This function sets the ram low-power control register
 *         of the PWR
 *
 * \param  pwr    pwr pointer to a PWR_TypeDef structure
 *                  - PWR: PWR base address index
 * \param  sram1  a value used to control sram1 low-power.
 * \param  sram2  a value used to control sram2 low-power.
 * \param  c1Tcm  a value used to control CPU1 tcm low-power.
 * \param  c2Tcm  a value used to control CPU2 tcm low-power.
 */
static inline void PWR_setRamLpCtrl (PWR_TypeDef *pwr, uint8_t sram1, uint8_t sram2, uint8_t c1Tcm, uint8_t c2Tcm)
{
    WRITE_REG(pwr->RAMLPCR.WORDVAL, (uint32_t)(((sram1 << PWR_RAMLPCR_SRAM1LP_S) & PWR_RAMLPCR_SRAM1LP_M) |
                                               ((sram2 << PWR_RAMLPCR_SRAM2LP_S) & PWR_RAMLPCR_SRAM2LP_M) |
                                               ((c1Tcm << PWR_RAMLPCR_C1SRAMLP_S) & PWR_RAMLPCR_C1SRAMLP_M) |
                                               ((c2Tcm << PWR_RAMLPCR_C2SRAMLP_S) & PWR_RAMLPCR_C2SRAMLP_M)));
}

/**
 * \brief  Sets the PWR BOR Power status Register
 * \note   This function sets the bor power status register
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \return Returns the value of BOR Status Register.
 */
static inline uint16_t PWR_getBorPwrStatus (PWR_TypeDef *pwr)
{
    return (uint16_t)(pwr->BORSR.WORDVAL);
}

/**
 * \brief  Enters the PWR module Sleep Mode
 * \note   This function operates the PWR module to enter sleep mode.
 *
 * \param  mode  the value is used to select the mode of WFI or WFE
 */
extern void PWR_enterSleepMode (PWR_WaitMode mode);

/**
 * \brief  Enters the PWR module Sleep On Exit Mode
 * \note   This function operates the PWR module to enter sleep 
 *         on exit mode.
 *
 * \param  mode  the value is used to select the mode of WFI or WFE
 */
extern void PWR_enterSleepOnExitMode (PWR_WaitMode mode);

/**
 * \brief  Enters the PWR module Stop Mode
 * \note   This function operates the PWR module to enter stop mode.
 *
 * \param  mode  the value is used to select the mode of WFI or WFE
 */
extern void PWR_enterStopMode (PWR_WaitMode mode);

/**
 * \brief  Enters the PWR module Stop On Exit Mode
 * \note   This function operates the PWR module to enter stop 
 *         on exit mode.
 *
 * \param  mode  the value is used to select the mode of WFI or WFE
 */
extern void PWR_enterStopOnExitMode (PWR_WaitMode mode);

/**
 * \brief  Enters the PWR module Standby Mode
 * \note   This function operates the PWR module to enter standby mode.
 *
 * \param  mode  the value is used to select the mode of WFI or WFE
 */
extern void PWR_enterStandbyMode (PWR_WaitMode mode);

/**
 * \brief  Enters the PWR module Standby On Exit Mode
 * \note   This function operates the PWR module to enter standby 
 *         on exit mode.
 *
 * \param  mode  the value is used to select the mode of WFI or WFE
 */
extern void PWR_enterStandbyOnExitMode (PWR_WaitMode mode);


#ifdef __cplusplus
}
#endif


#endif /* __PWR_H__ */
