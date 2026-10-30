/**
  * @file       exti.h
  * @author     Alex-J
  * @brief      Header file of exti.c
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */

#ifndef __EXTI_H__
#define __EXTI_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/** @defgroup EXTI_EXPORTED_TYPES EXTI Exported Types
 * @{
 * @brief  Macro definitions are used with all files publicly about 'EXTI' module.
 */

/** @defgroup EXTI_IMR_REGBIT EXTI IMR register bits
 * @{
 * @brief  Macro definitions about EXTI IMR register bits definition.
 */
#define EXTI_IMR_IMR_S    (0UL)             /*!< EXTI_IMR Bit Position (Bit 0) */
#define EXTI_IMR_IMR_M    (0xffffffffUL)    /*!< EXTI interrupt mask register Bitfield-Mask */

/**
 * @}
 */

/** @defgroup EXTI_EMR_REGBIT EXTI EMR register bits
 * @{
 * @brief  Macro definitions about EXTI EMR register bits definition.
 */
#define EXTI_EMR_EMR_S    (0UL)             /*!< EXTI_EMR Bit Position (Bit 0) */
#define EXTI_EMR_EMR_M    (0xffffffffUL)    /*!< EXTI event mask register Bitfield-Mask */

/**
 * @}
 */

/** @defgroup EXTI_RTSR_REGBIT EXTI RTSR register bits
 * @{
 * @brief  Macro definitions about EXTI RTSR register bits definition.
 */
#define EXTI_RTSR_RTSR_S    (0UL)           /*!< EXTI_PTSR Bit Position (Bit 0) */
#define EXTI_RTSR_RTSR_M    (0xffffffUL)    /*!< EXTI rising edge trigger selection register Bitfield-Mask */

/**
 * @}
 */

/** @defgroup EXTI_FTSR_REGBIT EXTI FTSR register bits
 * @{
 * @brief  Macro definitions about EXTI FTSR register bits definition.
 */
#define EXTI_FTSR_FTSR_S    (0UL)           /*!< EXTI_FTSR Bit Position (Bit 0) */
#define EXTI_FTSR_FTSR_M    (0xffffffUL)    /*!< EXTI falling edge trigger selection register Bitfield-Mask */

/**
 * @}
 */

/** @defgroup EXTI_SWIER_REGBIT EXTI SWIER register bits
 * @{
 * @brief  Macro definitions about EXTI SWIER register bits definition.
 */
#define EXTI_SWIER_SWIER_S    (0UL)           /*!< EXTI_SWIER Bit Position (Bit 0) */
#define EXTI_SWIER_SWIER_M    (0xffffffUL)    /*!< EXTI software interrupt event register Bitfield-Mask */

/**
 * @}
 */

/** @defgroup EXTI_PR_REGBIT EXTI PR register bits
 * @{
 * @brief  Macro definitions about EXTI PR register bits definition.
 */
#define EXTI_PR_PR_S    (0UL)           /*!< EXTI_PR Bit Position (Bit 0) */
#define EXTI_PR_PR_M    (0xffffffUL)    /*!< EXTI pending register Bitfield-Mask */

/**
 * @}
 */

/** @defgroup EXTI_IMR2_REGBIT EXTI IMR2 register bits
 * @{
 * @brief  Macro definitions about EXTI IMR2 register bits definition.
 */
#define EXTI_IMR2_IMR_S    (0UL)       /*!< EXTI_IMR2 Bit Position (Bit 0) */
#define EXTI_IMR2_IMR_M    (0x7fUL)    /*!< EXTI interrupt mask register 2 Bitfield-Mask */

/**
 * @}
 */

/** @defgroup EXTI_EMR2_REGBIT EXTI EMR2 register bits
 * @{
 * @brief  Macro definitions about EXTI EMR2 register bits definition.
 */
#define EXTI_EMR2_EMR_S    (0UL)       /*!< EXTI_EMR2 Bit Position (Bit 0) */
#define EXTI_EMR2_EMR_M    (0x7fUL)    /*!< EXTI event mask register 2 Bitfield-Mask */

/**
 * @}
 */

/** @defgroup EXTI_PTSR2_REGBIT EXTI PTSR2 register bits
 * @{
 * @brief  Macro definitions about EXTI PTSR2 register bits definition.
 */
#define EXTI_RTSR2_RTSR_S    (0UL)      /*!< EXTI_PTSR2 Bit Position (Bit 0) */
#define EXTI_RTSR2_RTSR_M    (0xfUL)    /*!< EXTI rising edge trigger selection register 2 Bitfield-Mask */

/**
 * @}
 */

/** @defgroup EXTI_FTSR2_REGBIT EXTI FTSR2 register bits
 * @{
 * @brief  Macro definitions about EXTI FTSR2 register bits definition.
 */
#define EXTI_FTSR2_FTSR_S    (0UL)      /*!< EXTI_FTSR2 Bit Position (Bit 0) */
#define EXTI_FTSR2_FTSR_M    (0xfUL)    /*!< EXTI falling edge trigger selection register 2 Bitfield-Mask */

/**
 * @}
 */

/** @defgroup EXTI_SWIER2_REGBIT EXTI SWIER2 register bits
 * @{
 * @brief  Macro definitions about EXTI SWIER2 register bits definition.
 */
#define EXTI_SWIER2_SWIER_S    (0UL)      /*!< EXTI_SWIER Bit Position (Bit 0) */
#define EXTI_SWIER2_SWIER_M    (0xfUL)    /*!< EXTI software interrupt event register 2 Bitfield-Mask */

/**
 * @}
 */

/** @defgroup EXTI_PR2_REGBIT EXTI PR2 register bits
 * @{
 * @brief  Macro definitions about EXTI PR2 register bits definition.
 */
#define EXTI_PR2_PR_S    (0UL)      /*!< EXTI_PR Bit Position (Bit 0) */
#define EXTI_PR2_PR_M    (0xfUL)    /*!< EXTI pending register 2 Bitfield-Mask */

/**
 * @}
 */

/** @defgroup EXTI_PR_REGBIT EXTI PR register bits
 * @{
 * @brief  Macro definitions about EXTI PR register bits definition.
 */
typedef enum {
    EXTI_CONFIG_GPIO_LINE0     = 0x00000001,    /*!< EXTI config GPIO line 0 */
    EXTI_CONFIG_GPIO_LINE1     = 0x00000002,    /*!< EXTI config GPIO line 1 */
    EXTI_CONFIG_GPIO_LINE2     = 0x00000004,    /*!< EXTI config GPIO line 2 */
    EXTI_CONFIG_GPIO_LINE3     = 0x00000008,    /*!< EXTI config GPIO line 3 */
    EXTI_CONFIG_GPIO_LINE4     = 0x00000010,    /*!< EXTI config GPIO line 4 */
    EXTI_CONFIG_GPIO_LINE5     = 0x00000020,    /*!< EXTI config GPIO line 5 */
    EXTI_CONFIG_GPIO_LINE6     = 0x00000040,    /*!< EXTI config GPIO line 6 */
    EXTI_CONFIG_GPIO_LINE7     = 0x00000080,    /*!< EXTI config GPIO line 7 */
    EXTI_CONFIG_GPIO_LINE8     = 0x00000100,    /*!< EXTI config GPIO line 8 */
    EXTI_CONFIG_GPIO_LINE9     = 0x00000200,    /*!< EXTI config GPIO line 9 */
    EXTI_CONFIG_GPIO_LINE10    = 0x00000400,    /*!< EXTI config GPIO line 10 */
    EXTI_CONFIG_GPIO_LINE11    = 0x00000800,    /*!< EXTI config GPIO line 11 */
    EXTI_CONFIG_GPIO_LINE12    = 0x00001000,    /*!< EXTI config GPIO line 12 */
    EXTI_CONFIG_GPIO_LINE13    = 0x00002000,    /*!< EXTI config GPIO line 13 */
    EXTI_CONFIG_GPIO_LINE14    = 0x00004000,    /*!< EXTI config GPIO line 14 */
    EXTI_CONFIG_GPIO_LINE15    = 0x00008000,    /*!< EXTI config GPIO line 15 */
    EXTI_CONFIG_CMPSS1_LINE16  = 0x00010000,    /*!< EXTI config CMPSS1 line 16 */
    EXTI_CONFIG_CMPSS2_LINE17  = 0x00020000,    /*!< EXTI config CMPSS2 line 17 */
    EXTI_CONFIG_CMPSS3_LINE18  = 0x00040000,    /*!< EXTI config CMPSS3 line 18 */
    EXTI_CONFIG_CMPSS4_LINE19  = 0x00080000,    /*!< EXTI config CMPSS4 line 19 */
    EXTI_CONFIG_CMPSS5_LINE20  = 0x00100000,    /*!< EXTI config CMPSS5 line 20 */
    EXTI_CONFIG_CMPSS6_LINE21  = 0x00200000,    /*!< EXTI config CMPSS6 line 21 */
    EXTI_CONFIG_CMPSS7_LINE22  = 0x00400000,    /*!< EXTI config CMPSS7 line 22 */
    EXTI_CONFIG_CMPSS8_LINE23  = 0x00800000,    /*!< EXTI config CMPSS7 line 23 */
    EXTI_DIRECT_AWK_LINE24     = 0x01000000,    /*!< EXTI direct AWK line 24 */
    EXTI_DIRECT_LPTIMER_LINE25 = 0x02000000,    /*!< EXTI direct LPTIMER line 25 */
    EXTI_DIRECT_LVD_LINE26     = 0x04000000,    /*!< EXTI direct LVD line 26 */
    EXTI_DIRECT_IWDG1_LINE27   = 0x08000000,    /*!< EXTI direct IWDG1 line 27 */
    EXTI_DIRECT_IWDG2_LINE28   = 0x10000000,    /*!< EXTI direct IWDG2 line 28 */
    EXTI_DIRECT_CAN1_LINE29    = 0x20000000,    /*!< EXTI direct CAN1 line 29 */
    EXTI_DIRECT_CANFD1_LINE30  = 0x40000000,    /*!< EXTI direct CANFD1 line 30 */
    EXTI_DIRECT_I2C1_LINE31    = 0x80000000     /*!< EXTI direct I2C1 line 31 */
} EXTI_InputMapIdx;

/**
 * @}
 */

/** @defgroup EXTI_PR2_REGBIT EXTI PR2 register bits
 * @{
 * @brief  Macro definitions about EXTI PR2 register bits definition.
 */
typedef enum {
    EXTI_CONFIG_CMPSS9_LINE32       = 0x00000001,    /*!< EXTI config CMPSS9 line 32 */
    EXTI_CONFIG_CMPSS10_LINE33      = 0x00000002,    /*!< EXTI config CMPSS10 line 33 */
    EXTI_CONFIG_CMPSS11_LINE34      = 0x00000004,    /*!< EXTI config CMPSS11 line 34 */
    EXTI_CONFIG_CPUx_TXEV_LINE35    = 0x00000008,    /*!< EXTI config CPU1/2 TXEV line 35 */
    EXTI_DIRECT_CANFD2_LINE36       = 0x00000010,    /*!< EXTI direct CANFD2 line 36 */
    EXTI_CONFIG_CPUx_MU_LINE37      = 0x00000020,    /*!< EXTI direct CPU1/2 MU line 37 */
    EXTI_DIRECT_CLKFAIL_WKUP_LINE38 = 0x00000040     /*!< EXTI direct CLKFAIL_WKUP line 38 */
} EXTI_InputMap2Idx;

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
 * \brief  Sets the EXTI Interrupt Mask Register.
 * \note   This function sets the interrupt mask register of the EXTI
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \param  mask  a value of the interrupt mask register configuration.
 */
static inline void EXTI_setIntrMaskReg (EXTI_TypeDef *exti, uint32_t mask)
{
    SET_BIT(exti->IMR.WORDVAL, mask);
}

/**
 * \brief  Clears the EXTI Interrupt Mask Register.
 * \note   This function clears the interrupt mask register of the EXTI
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \param  mask  a value of the interrupt mask register configuration.
 */
static inline void EXTI_clearIntrMaskReg (EXTI_TypeDef *exti, uint32_t mask)
{
    CLEAR_BIT(exti->IMR.WORDVAL, mask);
}

/**
 * \brief  Gets the EXTI Interrupt Mask Register.
 * \note   This function returns the value for the EXTI interrupt mask register.
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \return Returns the value of the interrupt mask register.
 */
static inline uint32_t EXTI_getIntrMskReg (EXTI_TypeDef *exti)
{
    return (uint32_t)(exti->IMR.WORDVAL);
}

/**
 * \brief  Sets the EXTI Event Mask Register.
 * \note   This function sets the event mask register of the EXTI
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \param  mask  a value of the event mask register configuration.
 */
static inline void EXTI_setEvtMaskReg (EXTI_TypeDef *exti, uint32_t mask)
{
    SET_BIT(exti->EMR.WORDVAL, mask);
}

/**
 * \brief  Clears the EXTI Event Mask Register.
 * \note   This function clears the event mask register of the EXTI
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \param  mask  a value of the event mask register configuration.
 */
static inline void EXTI_clearEvtMaskReg (EXTI_TypeDef *exti, uint32_t mask)
{
    CLEAR_BIT(exti->EMR.WORDVAL, mask);
}

/**
 * \brief  Gets the EXTI Event Mask Register.
 * \note   This function returns the value for the EXTI event mask register.
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \return Returns the value of the event mask register.
 */
static inline uint32_t EXTI_getEvtMaskReg (EXTI_TypeDef *exti)
{
    return (uint32_t)(exti->EMR.WORDVAL);
}

/**
 * \brief  Sets the EXTI Event Rising Edge Trigger Selection Register.
 * \note   This function sets the rising edge trigger selection register of the EXTI.
 *
 * \param  exti    exti pointer to a EXTI_TypeDef structure
 *                   - EXTI: EXTI base address index
 * \param  select  a value of the rising edge trigger selection register configuration.
 */
static inline void EXTI_setRiseEdgeTrigSelReg (EXTI_TypeDef *exti, uint32_t select)
{
    MODIFY_REG(exti->RTSR.WORDVAL, EXTI_RTSR_RTSR_M, (select & EXTI_RTSR_RTSR_M));
}

/**
 * \brief  Gets the EXTI Event Rising Edge Trigger Selection Register.
 * \note   This function returns the value for the EXTI rising edge trigger selection register.
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \return Returns the value of the rising edge trigger selection register.
 */
static inline uint32_t EXTI_getRiseEdgeTrigSelReg (EXTI_TypeDef *exti)
{
    return (uint32_t)(exti->RTSR.WORDVAL);
}

/**
 * \brief  Sets the EXTI Event Falling Edge Trigger Selection Register.
 * \note   This function sets the falling edge trigger selection register of the EXTI.
 *
 * \param  exti    exti pointer to a EXTI_TypeDef structure
 *                   - EXTI: EXTI base address index
 * \param  select  a value of the falling edge trigger selection register configuration.
 */
static inline void EXTI_setFallEdgeTrigSelReg (EXTI_TypeDef *exti, uint32_t select)
{
    MODIFY_REG(exti->FTSR.WORDVAL, EXTI_RTSR_RTSR_M, (select & EXTI_RTSR_RTSR_M));
}

/**
 * \brief  Gets the EXTI Event Falling Edge Trigger Selection Register.
 * \note   This function returns the value for the EXTI falling edge trigger selection register.
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \return Returns the value of the falling edge trigger selection register.
 */
static inline uint32_t EXTI_getFallEdgeTrigSelReg (EXTI_TypeDef *exti)
{
    return (uint32_t)(exti->FTSR.WORDVAL);
}

/**
 * \brief  Sets the EXTI Event Software Interrupt Event Register.
 * \note   This function sets the software interrupt event register of the EXTI.
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \param  set   a value of the software interrupt event register configuration.
 */
static inline void EXTI_setSoftIntrEvtReg (EXTI_TypeDef *exti, uint32_t set)
{
    MODIFY_REG(exti->SWIER.WORDVAL, EXTI_SWIER_SWIER_M, (set & EXTI_SWIER_SWIER_M));
}

/**
 * \brief  Gets the EXTI Pending Register.
 * \note   This function returns the value for the EXTI pending register.
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \return Returns the value of the pending register.
 */
static inline uint32_t EXTI_getPendReg (EXTI_TypeDef *exti)
{
    return (uint32_t)(exti->PR.WORDVAL);
}

/**
 * \brief  Clears the EXTI Event Pending Register.
 * \note   This function clears the pending register of the EXTI.
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \param  clr   a value used to clear the pending register.
 */
static inline void EXTI_clearPendReg (EXTI_TypeDef *exti, uint32_t clr)
{
    SET_BIT(exti->PR.WORDVAL, clr);
}

/**
 * \brief  Sets the EXTI Interrupt Mask Register 2.
 * \note   This function sets the interrupt mask register 2 of the EXTI
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \param  mask  a value of the interrupt mask register 2 configuration.
 */
static inline void EXTI_setIntrMaskReg2 (EXTI_TypeDef *exti, uint8_t mask)
{
    SET_BIT(exti->IMR2.WORDVAL, ((uint32_t)mask & EXTI_IMR2_IMR_M));
}

/**
 * \brief  Clears the EXTI Interrupt Mask Register 2.
 * \note   This function clears the interrupt mask register 2 of the EXTI
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \param  mask  a value of the interrupt mask register 2 configuration.
 */
static inline void EXTI_clearIntrMaskReg2 (EXTI_TypeDef *exti, uint8_t mask)
{
    CLEAR_BIT(exti->IMR2.WORDVAL, ((uint32_t)mask & EXTI_IMR2_IMR_M));
}

/**
 * \brief  Gets the EXTI Interrupt Mask Register 2.
 * \note   This function returns the value for the EXTI interrupt mask register 2.
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \return Returns the value of the interrupt mask register 2.
 */
static inline uint8_t EXTI_getIntrMskReg2 (EXTI_TypeDef *exti)
{
    return (uint8_t)(exti->IMR2.WORDVAL);
}

/**
 * \brief  Sets the EXTI Event Mask Register 2.
 * \note   This function sets the event mask register 2 of the EXTI
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \param  mask  a value of the event mask register 2 configuration.
 */
static inline void EXTI_setEvtMaskReg2 (EXTI_TypeDef *exti, uint16_t mask)
{
    SET_BIT(exti->EMR2.WORDVAL, ((uint32_t)mask & EXTI_EMR2_EMR_M));
}

/**
 * \brief  Clears the EXTI Event Mask Register 2.
 * \note   This function clears the event mask register 2 of the EXTI
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \param  mask  a value of the event mask register 2 configuration.
 */
static inline void EXTI_clearEvtMaskReg2 (EXTI_TypeDef *exti, uint16_t mask)
{
    CLEAR_BIT(exti->EMR2.WORDVAL, ((uint32_t)mask & EXTI_EMR2_EMR_M));
}

/**
 * \brief  Gets the EXTI Event Mask Register 2.
 * \note   This function returns the value for the EXTI event mask register 2.
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \return Returns the value of the event mask register 2.
 */
static inline uint16_t EXTI_getEvtMaskReg2 (EXTI_TypeDef *exti)
{
    return (uint16_t)(exti->EMR2.WORDVAL);
}

/**
 * \brief  Sets the EXTI Event Rising Edge Trigger Selection Register 2.
 * \note   This function sets the rising edge trigger selection register 2 of the EXTI.
 *
 * \param  exti    exti pointer to a EXTI_TypeDef structure
 *                   - EXTI: EXTI base address index
 * \param  select  a value of the rising edge trigger selection register 2 configuration.
 */
static inline void EXTI_setRiseEdgeTrigSelReg2 (EXTI_TypeDef *exti, uint8_t select)
{
    MODIFY_REG(exti->RTSR2.WORDVAL, EXTI_RTSR2_RTSR_M, ((uint32_t)select & EXTI_RTSR2_RTSR_M));
}

/**
 * \brief  Gets the EXTI Event Rising Edge Trigger Selection Register 2.
 * \note   This function returns the value for the EXTI rising edge trigger selection register 2.
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \return Returns the value of the rising edge trigger selection register 2.
 */
static inline uint8_t EXTI_getRiseEdgeTrigSelReg2 (EXTI_TypeDef *exti)
{
    return (uint8_t)(exti->RTSR2.WORDVAL);
}

/**
 * \brief  Sets the EXTI Event Falling Edge Trigger Selection Register 2.
 * \note   This function sets the falling edge trigger selection register 2 of the EXTI.
 *
 * \param  exti    exti pointer to a EXTI_TypeDef structure
 *                   - EXTI: EXTI base address index
 * \param  select  a value of the falling edge trigger selection register 2 configuration.
 */
static inline void EXTI_setFallEdgeTrigSelReg2 (EXTI_TypeDef *exti, uint8_t select)
{
    MODIFY_REG(exti->FTSR2.WORDVAL, EXTI_FTSR2_FTSR_M, ((uint32_t)select & EXTI_FTSR2_FTSR_M));
}

/**
 * \brief  Gets the EXTI Event Falling Edge Trigger Selection Register 2.
 * \note   This function returns the value for the EXTI falling edge trigger selection register 2.
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \return Returns the value of the falling edge trigger selection register 2.
 */
static inline uint8_t EXTI_getFallEdgeTrigSelReg2 (EXTI_TypeDef *exti)
{
    return (uint8_t)(exti->FTSR2.WORDVAL);
}

/**
 * \brief  Sets the EXTI Event Software Interrupt Event Register 2.
 * \note   This function sets the software interrupt event register 2 of the EXTI.
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \param  set   a value of the software interrupt event register 2 configuration.
 */
static inline void EXTI_setSoftIntrEvtReg2 (EXTI_TypeDef *exti, uint8_t set)
{
    MODIFY_REG(exti->SWIER2.WORDVAL, EXTI_SWIER2_SWIER_M, ((uint32_t)set & EXTI_SWIER2_SWIER_M));
}

/**
 * \brief  Gets the EXTI Pending Register 2.
 * \note   This function returns the value for the EXTI pending register 2.
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \return Returns the value of the pending register 2.
 */
static inline uint8_t EXTI_getPendReg2 (EXTI_TypeDef *exti)
{
    return (uint8_t)(exti->PR2.WORDVAL);
}

/**
 * \brief  Clears the EXTI Event Pending Register 2.
 * \note   This function clears the pending register 2 of the EXTI.
 *
 * \param  exti  exti pointer to a EXTI_TypeDef structure
 *                 - EXTI: EXTI base address index
 * \param  clr   a value used to clear the pending register 2.
 */
static inline void EXTI_clearPendReg2 (EXTI_TypeDef *exti, uint8_t clr)
{
    SET_BIT(exti->PR2.WORDVAL, (uint32_t)clr);
}


#ifdef __cplusplus
}
#endif


#endif /* __EXTI_H__ */
