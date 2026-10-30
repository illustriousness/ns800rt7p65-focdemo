/**
  * @file       btim.h
  * @author     Haven-X
  * @brief      Header file for NS800RT7xxx btim module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __BTIM_H__
#define __BTIM_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_btim.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup BTIM_EXPORTED_TYPES BTIM Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'BTIM' module.
  */

/** @defgroup BTIM_COUNTERMODE BTIM Counter Mode
  * @{
  * @brief  Macro definitions about BTIM counter mode.
  */
typedef enum {
    BTIM_COUNTERMODE_FREE     = 0U,               /*!< Timer periodicity counts from 0xFFFFFFFF/0xFFFF to 0 */
    BTIM_COUNTERMODE_PERIODIC = BTIM_CR_MODE_M    /*!< Timer periodicity counts from reload value(ARR/PARR) to 0 */
} BTIM_CounterMode;

/**
  * @}
  */

/** @defgroup BTIM_BITWIDTH BTIM Bit Width
  * @{
  * @brief  Macro definitions about BTIM bit width.
  */
typedef enum {
    BTIM_BITWIDTH_16BIT = 0U,               /*!< Counter bit width is 16bit */
    BTIM_BITWIDTH_32BIT = BTIM_CR_SIZE_M    /*!< Counter bit width is 32bit */
} BTIM_BitWidth;

/**
  * @}
  */

/** @defgroup BTIM_ONESHOTMODE BTIM One Shot Mode
  * @{
  * @brief  Macro definitions about BTIM one shot mode.
  */
typedef enum {
    BTIM_ONESHOTMODE_REPETITIVE = 0U,                  /*!< Counter counts repeatedly */
    BTIM_ONESHOTMODE_SINGLE     = BTIM_CR_ONESHOT_M    /*!< Counter is run only once */
} BTIM_OneShotMode;

/**
  * @}
  */

/** @defgroup BTIM_PRESCALER BTIM Prescaler
  * @{
  * @brief  Macro definitions about BTIM perscaler.
  */
typedef enum {
    BTIM_PRESCALER_DIV1 = 0U,    /*!< Timer prescaler OFF */
    BTIM_PRESCALER_DIV16,        /*!< Timer frequency is divided by 16 */
    BTIM_PRESCALER_DIV32,        /*!< Timer frequency is divided by 32 */
    BTIM_PRESCALER_DIV64,        /*!< Timer frequency is divided by 64 */
    BTIM_PRESCALER_DIV128,       /*!< Timer frequency is divided by 128 */
    BTIM_PRESCALER_DIV256,       /*!< Timer frequency is divided by 256 */
    BTIM_PRESCALER_DIV512,       /*!< Timer frequency is divided by 512 */
    BTIM_PRESCALER_DIV1024       /*!< Timer frequency is divided by 1024 */
} BTIM_Prescaler;

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
  * \brief  Enable timer counter.
  * \param  btim    BTIMx pointer to a BTIM_TypeDef structure
  *                  - BTIM1: BTIM1 base address index
  *                  - BTIM2: BTIM2 base address index
  */
static inline void BTIM_enableCounter (BTIM_TypeDef *btim)
{
    __IO uint32_t arrReg = READ_REG(btim->ARR.WORDVAL);

    if (READ_BIT(btim->CR.WORDVAL, BTIM_CR_ONESHOT_M) && (arrReg != 0UL))
    {   /* Rewrite the arr register in oneshot mode to restart the counter, but the arr value cannot be 0 */
        btim->ARR.WORDVAL = arrReg;
    }
    SET_BIT(btim->CR.WORDVAL, BTIM_CR_EN_M);
}

/**
  * \brief  Disable timer counter.
  * \param  btim    BTIMx pointer to a BTIM_TypeDef structure
  *                  - BTIM1: BTIM1 base address index
  *                  - BTIM2: BTIM2 base address index
  */
static inline void BTIM_disableCounter (BTIM_TypeDef *btim)
{
    CLEAR_BIT(btim->CR.WORDVAL, BTIM_CR_EN_M);
}

/**
  * \brief  Get whether the timer counter is enabled.
  * \param  btim    BTIMx pointer to a BTIM_TypeDef structure
  *                  - BTIM1: BTIM1 base address index
  *                  - BTIM2: BTIM2 base address index
  * \return Returned the status of whether the timer counter is enabled or not
  *                  - 0: The timer counter is not enable.
  *                  - 1: The timer counter is enable.
  */
static inline uint32_t BTIM_getCounterEnabledStatus (BTIM_TypeDef *btim)
{
    return ((READ_BIT(btim->CR.WORDVAL, BTIM_CR_EN_M) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Set the timer counter mode.
  * \param  btim           BTIMx pointer to a BTIM_TypeDef structure
  *                         - BTIM1: BTIM1 base address index
  *                         - BTIM2: BTIM2 base address index
  * \param  counterMode    Counter mode
  *                         This parameter can be any value of @ref BTIM_COUNTERMODE
  */
static inline void BTIM_setCounterMode (BTIM_TypeDef *btim, BTIM_CounterMode counterMode)
{
    MODIFY_REG(btim->CR.WORDVAL, BTIM_CR_MODE_M, counterMode);
}

/**
  * \brief  Get actual counter mode.
  * \param  btim    BTIMx pointer to a BTIM_TypeDef structure
  *                  - BTIM1: BTIM1 base address index
  *                  - BTIM2: BTIM2 base address index
  * \return Returned actual counter mode
  *                  This value can be any value of @ref BTIM_COUNTERMODE
  */
static inline BTIM_CounterMode BTIM_getCounterMode (BTIM_TypeDef *btim)
{
    return (BTIM_CounterMode)(READ_BIT(btim->CR.WORDVAL, BTIM_CR_MODE_M));
}

/**
  * \brief  Set the counter bit width.
  * \param  btim        BTIMx pointer to a BTIM_TypeDef structure
  *                      - BTIM1: BTIM1 base address index
  *                      - BTIM2: BTIM2 base address index
  * \param  bitWidth    Counter bit width
  *                      This value can be any value of @ref BTIM_BITWIDTH
  */
static inline void BTIM_setBitWidth (BTIM_TypeDef *btim, BTIM_BitWidth bitWidth)
{
    MODIFY_REG(btim->CR.WORDVAL, BTIM_CR_SIZE_M, bitWidth);
}

/**
  * \brief  Get the prescaler value.
  * \param  btim    BTIMx pointer to a BTIM_TypeDef structure
  *                  - BTIM1: BTIM1 base address index
  *                  - BTIM2: BTIM2 base address index
  * \return Returned the counter bit width
  *                  This value can be any value of @ref BTIM_BITWIDTH
  */
static inline BTIM_BitWidth BTIM_getBitWidth (BTIM_TypeDef *btim)
{
    return (BTIM_BitWidth)(READ_BIT(btim->CR.WORDVAL, BTIM_CR_SIZE_M));
}

/**
  * \brief  Set one shot mode (single v.s. repetitive).
  * \param  btim           BTIMx pointer to a BTIM_TypeDef structure
  *                         - BTIM1: BTIM1 base address index
  *                         - BTIM2: BTIM2 base address index
  * \param  oneShotMode    One pulse Mode
  *                         This parameter can be any value of @ref BTIM_ONESHOTMODE
  */
static inline void BTIM_setOneShotMode (BTIM_TypeDef *btim, BTIM_OneShotMode oneShotMode)
{
    MODIFY_REG(btim->CR.WORDVAL, BTIM_CR_ONESHOT_M, oneShotMode);
}

/**
  * \brief  Get actual one shot mode.
  * \param  btim    BTIMx pointer to a BTIM_TypeDef structure
  *                  - BTIM1: BTIM1 base address index
  *                  - BTIM2: BTIM2 base address index
  * \return Returned actual one shot mode
  *                  This value can be any value of @ref BTIM_ONESHOTMODE
  */
static inline BTIM_OneShotMode BTIM_getOneShotMode (BTIM_TypeDef *btim)
{
    return (BTIM_OneShotMode)(READ_BIT(btim->CR.WORDVAL, BTIM_CR_ONESHOT_M));
}

/**
  * \brief  Set the prescaler value.
  * \param  btim         BTIMx pointer to a BTIM_TypeDef structure
  *                       - BTIM1: BTIM1 base address index
  *                       - BTIM2: BTIM2 base address index
  * \param  prescaler    Prescaler value
  *                       This value can be any value of @ref BTIM_PRESCALER
  */
static inline void BTIM_setPrescaler (BTIM_TypeDef *btim, BTIM_Prescaler prescaler)
{
    MODIFY_REG(btim->CR.WORDVAL, BTIM_CR_PSC_M, prescaler);
}

/**
  * \brief  Get the prescaler value.
  * \param  btim    BTIMx pointer to a BTIM_TypeDef structure
  *                  - BTIM1: BTIM1 base address index
  *                  - BTIM2: BTIM2 base address index
  * \return Returned the prescaler value
  *                  This value can be any value of @ref BTIM_PRESCALER
  */
static inline BTIM_Prescaler BTIM_getPrescaler (BTIM_TypeDef *btim)
{
    return (BTIM_Prescaler)(READ_BIT(btim->CR.WORDVAL, BTIM_CR_PSC_M));
}

/**
  * \brief  Get the counter value.
  * \param  btim    BTIMx pointer to a BTIM_TypeDef structure
  *                  - BTIM1: BTIM1 base address index
  *                  - BTIM2: BTIM2 base address index
  * \return Returned counter value
  *                  This value between Min_Data=0 and Max_Data=0xFFFF/0xFFFFFFFF,
  *                  the Max_Data depends on the bit width setting.
  */
static inline uint32_t BTIM_getCounter (BTIM_TypeDef *btim)
{
    __IO uint32_t bitWidthMsk = btim->CR.BIT.SIZE ? 0xFFFFFFFFUL : 0x0000FFFFUL;
    return (uint32_t)(READ_REG(btim->CNT.WORDVAL) & bitWidthMsk);
}

/**
  * \brief  Set the auto-reload value.
  * \param  btim          BTIMx pointer to a BTIM_TypeDef structure
  *                        - BTIM1: BTIM1 base address index
  *                        - BTIM2: BTIM2 base address index
  * \param  autoReload    AutoReload value
  *                        This parameter between Min_Data=1 and Max_Data=0xFFFF/0xFFFFFFFF,
  *                        the Max_Data depends on the bit width setting.
  */
static inline void BTIM_setAutoReload (BTIM_TypeDef *btim, uint32_t autoReload)
{
    WRITE_REG(btim->ARR.WORDVAL, autoReload);
}

/**
  * \brief  Get the auto-reload value.
  * \param  btim    BTIMx pointer to a BTIM_TypeDef structure
  *                  - BTIM1: BTIM1 base address index
  *                  - BTIM2: BTIM2 base address index
  * \return Returned the auto-reload value
  *                  This value between Min_Data=0 and Max_Data=0xFFFF/0xFFFFFFFF,
  *                  the Max_Data depends on the bit width setting.
  */
static inline uint32_t BTIM_getAutoReload (BTIM_TypeDef *btim)
{
    __IO uint32_t bitWidthMsk = btim->CR.BIT.SIZE ? 0xFFFFFFFFUL : 0x0000FFFFUL;
    return (uint32_t)(READ_REG(btim->ARR.WORDVAL) & bitWidthMsk);
}

/**
  * \brief  Clear the interrupt flag.
  * \param  btim    BTIMx pointer to a BTIM_TypeDef structure
  *                  - BTIM1: BTIM1 base address index
  *                  - BTIM2: BTIM2 base address index
  */
static inline void BTIM_clearFlag (BTIM_TypeDef *btim)
{
    WRITE_REG(btim->ICR.WORDVAL, 0UL);
}

/**
  * \brief  Get whether the interrupt flag.
  * \param  btim    BTIMx pointer to a BTIM_TypeDef structure
  *                  - BTIM1: BTIM1 base address index
  *                  - BTIM2: BTIM2 base address index
  * \return Returned Interrupt flag
  *                  - 0: The timer flag is not set.
  *                  - 1: The timer flag is set.
  */
static inline uint32_t BTIM_getFlag (BTIM_TypeDef *btim)
{
    return READ_BIT(btim->ISR.WORDVAL, BTIM_ISR_UD_M);
}

/**
  * \brief  Enable the interrupt.
  * \param  btim    BTIMx pointer to a BTIM_TypeDef structure
  *                  - BTIM1: BTIM1 base address index
  *                  - BTIM2: BTIM2 base address index
  */
static inline void BTIM_enableInterrupt (BTIM_TypeDef *btim)
{
    SET_BIT(btim->CR.WORDVAL, BTIM_CR_IE_M);
}

/**
  * \brief  Disable the interrupt.
  * \param  btim    BTIMx pointer to a BTIM_TypeDef structure
  *                  - BTIM1: BTIM1 base address index
  *                  - BTIM2: BTIM2 base address index
  */
static inline void BTIM_disableInterrupt (BTIM_TypeDef *btim)
{
    CLEAR_BIT(btim->CR.WORDVAL, BTIM_CR_IE_M);
}

/**
  * \brief  Get whether the interrupt is enabled.
  * \param  btim    BTIMx pointer to a BTIM_TypeDef structure
  *                  - BTIM1: BTIM1 base address index
  *                  - BTIM2: BTIM2 base address index
  * \return Returned the status of whether the timer interrupt is enabled or not
  *                  - 0: The timer interrupt is not enable.
  *                  - 1: The timer interrupt is enable.
  */
static inline uint32_t BTIM_getInterrupt (BTIM_TypeDef *btim)
{
    return ((READ_BIT(btim->CR.WORDVAL, BTIM_CR_IE_M) == 0UL) ? 0UL : 1UL);
}

/**
  * \brief  Configure the BTIMx time base unit.
  * \param  btim          BTIMx pointer to a BTIM_TypeDef structure
  *                        - BTIM1: BTIM1 base address index
  *                        - BTIM2: BTIM2 base address index
  * \param  prescaler     The prescaler value used to divide the BTIMx clock
  *                        This parameter can be any value of @ref BTIM_PRESCALER
  *                        This feature can be modified afterwards using function @ref BTIM_setPrescaler().
  * \param  autoReload    The auto reload value to be loaded into the ARR and PARR Register
  *                        This parameter can be a number between Min_Data=0x0001 and Max_Data=0xFFFF/0xFFFFFFFF,
  *                        the Max_Data depends on the bit width setting. This feature can be modified afterwards
  *                        using unitary function @ref BTIM_setAutoReload() or @ref BTIM_setAutoReloadPreload().
  * \param  configure     Configurable combination
  *                        All parameters can be or together, and the parameters include the following sections:
  *                        @ref BTIM_COUNTERMODE, Specifies the counter mode.
  *                        This feature can be modified afterwards using unitary function @ref BTIM_setCounterMode()
  *                        @ref BTIM_BITWIDTH, Specifies the bit width.
  *                        This feature can be modified afterwards using unitary function @ref BTIM_setBitWidth()
  *                        @ref BTIM_ONESHOTMODE, Specifies the one shot mode.
  *                        This feature can be modified afterwards using unitary function @ref BTIM_setOneShotMode()
  * \note   In the end you need to call the BTIM_enableCounter() function to start the BTIM.
  */
extern void BTIM_configTimeBase (BTIM_TypeDef *btim, BTIM_Prescaler prescaler, uint32_t autoReload, uint32_t configure);

/**
  * \brief  Restart the oneshot mode and use the new ARR value.
  * \note   In the oneshot mode, call the BTIM_enableCounter() function to make the timer run,
  *         the timer will automatically stop after the count reaches 0. After that, you can use
  *         @ref BTIM_enableCounter() or @ref BTIM_oneShotRestart() to restart the timer in OneShot mode again.
  * \param  btim          BTIMx pointer to a BTIM_TypeDef structure
  *                        - BTIM1: BTIM1 base address index
  *                        - BTIM2: BTIM2 base address index
  * \param  autoReload    The new auto reload value to be loaded into the ARR and PARR Register
  *                        This parameter can be a number between Min_Data=0x0001 and Max_Data=0xFFFF/0xFFFFFFFF,
  *                        the Max_Data depends on the bit width setting.
  */
extern void BTIM_oneShotRestart (BTIM_TypeDef *btim, uint32_t autoReload);


#ifdef __cplusplus
}
#endif


#endif /* __BTIM_H__ */
