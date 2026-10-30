/**
  * @file       awk.h
  * @author     Haven-X
  * @brief      Header file for NS800RT7xxx awk module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __AWK_H__
#define __AWK_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_awk.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup AWK_EXPORTED_TYPES AWK Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'AWK' module.
  */

/** @defgroup AWK_LPCNTSEL AWK Lowpower Mode Counter Conditions Select
  * @{
  * @brief  Macro definitions about AWK low power mode counter conditional selection.
  */
typedef enum {
    AWK_LPCNTSEL_CPU1_ONLY     = 0U,                              /*!< AWK only counts when CPU1 enters the low-power mode. */
    AWK_LPCNTSEL_CPU2_ONLY     = (0x1U << AWK_CR_CONDITION_S),    /*!< AWK only counts when CPU2 enters the low-power mode. */
    AWK_LPCNTSEL_CPU1_AND_CPU2 = (0x2U << AWK_CR_CONDITION_S),    /*!< AWK Counting when both CPU1 and CPU2 enter the low-power mode. */
    AWK_LPCNTSEL_CPU1_OR_CPU2  = (0x3U << AWK_CR_CONDITION_S)     /*!< AWK counts when CPU1 or CPU2 enters the low-power mode. */
} AWK_LowPowerCntSelect;

/**
  * @}
  */

/** @defgroup AWK_CLOCKSOURCE AWK Clock Source
  * @{
  * @brief  Macro definitions about AWK clock source.
  */
typedef enum {
    AWK_CLOCKSOURCE_NONE  = 0U,                            /*!< No select awk clock source, awk will stop */
    AWK_CLOCKSOURCE_LIRC  = (0x1U << AWK_CR_TCLKSRC_S),    /*!< LIRC as awk clock source */
    AWK_CLOCKSOURCE_HXTL  = (0x2U << AWK_CR_TCLKSRC_S),    /*!< HXTL as awk clock source */
    AWK_CLOCKSOURCE_MIRC1 = (0x3U << AWK_CR_TCLKSRC_S)     /*!< MIRC1 as awk clock source */
} AWK_ClockSource;

/**
  * @}
  */

/** @defgroup AWK_PRESCALER AWK Clock Prescaler
  * @{
  * @brief  Macro definitions about AWK clock perscaler.
  */
typedef enum {
    AWK_PRESCALER_DIV2 = 0x0U,    /*!< Awk clock frequency is divided by 2 */
    AWK_PRESCALER_DIV4,           /*!< Awk clock frequency is divided by 4 */
    AWK_PRESCALER_DIV8,           /*!< Awk clock frequency is divided by 8 */
    AWK_PRESCALER_DIV16,          /*!< Awk clock frequency is divided by 16 */
    AWK_PRESCALER_DIV32,          /*!< Awk clock frequency is divided by 32 */
    AWK_PRESCALER_DIV64,          /*!< Awk clock frequency is divided by 64 */
    AWK_PRESCALER_DIV128,         /*!< Awk clock frequency is divided by 128 */
    AWK_PRESCALER_DIV256,         /*!< Awk clock frequency is divided by 256 */
    AWK_PRESCALER_DIV512,         /*!< Awk clock frequency is divided by 512 */
    AWK_PRESCALER_DIV1024,        /*!< Awk clock frequency is divided by 1024 */
    AWK_PRESCALER_DIV2048,        /*!< Awk clock frequency is divided by 2048 */
    AWK_PRESCALER_DIV4096,        /*!< Awk clock frequency is divided by 4096 */
    AWK_PRESCALER_DIV8192,        /*!< Awk clock frequency is divided by 8192 */
    AWK_PRESCALER_DIV16384,       /*!< Awk clock frequency is divided by 16384 */
    AWK_PRESCALER_DIV32768,       /*!< Awk clock frequency is divided by 32768 */
    AWK_PRESCALER_DIV65536        /*!< Awk clock frequency is divided by 65536 */
} AWK_Prescaler;

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
  * \brief  Enable AWK counter.
  * \param  awk    AWK pointer to a AWK_TypeDef structure
  *                 - AWK: AWK base address index
  */
static inline void AWK_enableCounter (AWK_TypeDef *awk)
{
    SET_BIT(awk->CR.WORDVAL, AWK_CR_EN_M);
}

/**
  * \brief  Disable AWK counter.
  * \param  awk    AWK pointer to a AWK_TypeDef structure
  *                 - AWK: AWK base address index
  */
static inline void AWK_disableCounter (AWK_TypeDef *awk)
{
    CLEAR_BIT(awk->CR.WORDVAL, AWK_CR_EN_M);
}

/**
  * \brief  Get whether the AWK is enabled.
  * \param  awk    AWK pointer to a AWK_TypeDef structure
  *                 - AWK: AWK base address index
  * \return Returned the status of whether the AWK is enabled or not
  *                 - true : The AWK is enable.
  *                 - false: The AWK is not enable.
  */
static inline bool AWK_getCounterEnabledStatus (AWK_TypeDef *awk)
{
    return (READ_BIT(awk->CR.WORDVAL, AWK_CR_EN_M) ? true : false);
}

/**
  * \brief  Clear the AWK underflow interrupt flag.
  * \param  awk    AWK pointer to a AWK_TypeDef structure
  *                 - AWK: AWK base address index
  */
static inline void AWK_clearFlag (AWK_TypeDef *awk)
{
    WRITE_REG(awk->ICR.WORDVAL, AWK_ICR_AWUF_M);
}

/**
  * \brief  Get whether the AWK underflow interrupt flag.
  * \param  awk    AWK pointer to a AWK_TypeDef structure
  *                 - AWK: AWK base address index
  * \return Returned Interrupt flag
  *                 - 0: The AWK underflow flag is not set.
  *                 - 1: The AWK underflow flag is set.
  */
static inline uint32_t AWK_getFlag (AWK_TypeDef *awk)
{
    return READ_BIT(awk->SR.WORDVAL, 1UL);
}

/**
  * \brief  Enable the AWK underflow interrupt.
  * \param  awk    AWK pointer to a AWK_TypeDef structure
  *                 - AWK: AWK base address index
  */
static inline void AWK_enableInterrupt (AWK_TypeDef *awk)
{
    SET_BIT(awk->CR.WORDVAL, AWK_CR_IE_M);
}

/**
  * \brief  Disable the AWK underflow interrupt.
  * \param  awk    AWK pointer to a AWK_TypeDef structure
  *                 - AWK: AWK base address index
  */
static inline void AWK_disableInterrupt (AWK_TypeDef *awk)
{
    CLEAR_BIT(awk->CR.WORDVAL, AWK_CR_IE_M);
}

/**
  * \brief  Get whether the AWK underflow interrupt is enabled.
  * \param  awk    AWK pointer to a AWK_TypeDef structure
  *                 - AWK: AWK base address index
  * \return Returned the status of whether the AWK underflow interrupt is enabled or not
  *                 - true : The AWK underflow interrupt is enable.
  *                 - false: The AWK underflow interrupt is not enable.
  */
static inline bool AWK_getInterrupt (AWK_TypeDef *awk)
{
    return (READ_BIT(awk->CR.WORDVAL, AWK_CR_IE_M) ? true : false);
}

/**
  * \brief  Set the AWK clock source.
  * \param  awk            AWK pointer to a AWK_TypeDef structure
  *                         - AWK: AWK base address index
  * \param  clockSource    Clock source
  *                         This value can be any value of @ref AWK_CLOCKSOURCE
  */
static inline void AWK_setClockSource (AWK_TypeDef *awk, AWK_ClockSource clockSource)
{
    MODIFY_REG(awk->CR.WORDVAL, AWK_CR_TCLKSRC_M, clockSource);
}

/**
  * \brief  Get the AWK clock source.
  * \param  awk    AWK pointer to a AWK_TypeDef structure
  *                 - AWK: AWK base address index
  * \return Returned the clock source
  *                 This value can be any value of @ref AWK_CLOCKSOURCE
  */
static inline AWK_ClockSource AWK_getClockSource (AWK_TypeDef *awk)
{
    return (AWK_ClockSource)(READ_BIT(awk->CR.WORDVAL, AWK_CR_TCLKSRC_M));
}

/**
  * \brief  Set the AWK prescaler value.
  * \param  awk          AWK pointer to a AWK_TypeDef structure
  *                       - AWK: AWK base address index
  * \param  prescaler    Prescaler value
  *                       This value can be any value of @ref AWK_PRESCALER
  */
static inline void AWK_setPrescaler (AWK_TypeDef *awk, AWK_Prescaler prescaler)
{
    MODIFY_REG(awk->CR.WORDVAL, AWK_CR_PSC_M, prescaler);
}

/**
  * \brief  Get the AWK prescaler value.
  * \param  awk    AWK pointer to a AWK_TypeDef structure
  *                 - AWK: AWK base address index
  * \return Returned the prescaler value
  *                   This value can be any value of @ref AWK_PRESCALER
  */
static inline AWK_Prescaler AWK_getPrescaler (AWK_TypeDef *awk)
{
    return (AWK_Prescaler)(READ_BIT(awk->CR.WORDVAL, AWK_CR_PSC_M));
}

/**
  * \brief  Set the AWK auto-reload value.
  * \param  awk           AWK pointer to a AWK_TypeDef structure
  *                        - AWK: AWK base address index
  * \param  autoReload    AutoReload value
  *                        This parameter between Min_Data=0 and Max_Data=0xFFFF.
  */
static inline void AWK_setAutoReload (AWK_TypeDef *awk, uint16_t autoReload)
{
    WRITE_REG(awk->ARR.WORDVAL, autoReload);
}

/**
  * \brief  Get the AWK auto-reload value.
  * \param  awk    AWK pointer to a AWK_TypeDef structure
  *                 - AWK: AWK base address index
  * \return Returned the auto-reload value
  *                 This value between Min_Data=0 and Max_Data=0xFFFF.
  */
static inline uint16_t AWK_getAutoReload (AWK_TypeDef *awk)
{
    return (uint16_t)READ_REG(awk->ARR.WORDVAL);
}

/**
  * \brief  Set the low-power mode counting conditions for AWK.
  * \param  awk                  AWK pointer to a AWK_TypeDef structure
  *                               - AWK: AWK base address index
  * \param  lowPowerCntSelect    Low-power mode counter conditions select
  *                               This value can be any value of @ref AWK_LPCNTSEL
  */
static inline void AWK_setLowPowerCounter (AWK_TypeDef *awk, AWK_LowPowerCntSelect lowPowerCntSelect)
{
    MODIFY_REG(awk->CR.WORDVAL, AWK_CR_CONDITION_M, lowPowerCntSelect);
}

/**
  * \brief  Configure the AWK module.
  * \param  awk            AWK pointer to a AWK_TypeDef structure
  *                         - AWK: AWK base address index
  * \param  clockSource    The clock source acts as the input clock for the prescaler
  *                         This parameter can be any value of @ref AWK_CLOCKSOURCE
  *                         This feature can be modified afterwards using unitary function @ref AWK_setClockSource()
  * \param  prescaler      The prescaler value used to divide the AWK clock
  *                         This parameter can be any value of @ref AWK_PRESCALER
  *                         This feature can be modified afterwards using function @ref AWK_setPrescaler()
  * \param  autoReload     The auto-reload value
  *                         This parameter between Min_Data=0 and Max_Data=0xFFFF.
  *                         This feature can be modified afterwards using function @ref AWK_setAutoReload()
  * @note   If it is necessary to wake up the device from sleep or top mode, after calling this function, it is also
  *         necessary to enable the NVIC interrupt of the AWK.
  */
extern void AWK_configModule (AWK_TypeDef *awk, AWK_ClockSource clockSource, AWK_Prescaler prescaler, uint16_t autoReload);


#ifdef __cplusplus
}
#endif


#endif /* __AWK_H__ */
