/**
  * @file       wwdg.h
  * @author     bilang.xiong
  * @brief      Header file for NS800RT7xxx wwdg module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __WWDG_H__
#define __WWDG_H__


#ifdef __cplusplus
extern "C"{
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_wwdg.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup WWDG_EXPORTED_TYPES WWDG Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'WWDG' module.
  */

/** @defgroup WWDG_INTSEL WWDG Select Reset or Wakeup int
  * @{
  * @brief  Macro definitions about WWDG select reset or wakeup int function.
  */
typedef enum
{
    WWDG_DIRECT_RESET = 0U,    /*!< WWDG reset enable */
    WWDG_EARLY_WAKEUP_INT      /*!< WWDG wakeup interrupt enable */
} WWDG_IntSel;

/**
  * @}
  */

/** @defgroup WWDG_PRESCALER WWDG Clock Divsion
  * @{
  * @brief  Macro definitions about WWDG clock divsion.
  */
typedef enum
{
    WWDG_PRESCALE_DIV1 = 0U,    /*!< WWDG clock divided by 1 */
    WWDG_PRESCALE_DIV2,         /*!< WWDG clock divided by 2 */
    WWDG_PRESCALE_DIV4,         /*!< WWDG clock divided by 4 */
    WWDG_PRESCALE_DIV8,         /*!< WWDG clock divided by 8 */
    WWDG_PRESCALE_DIV16,        /*!< WWDG clock divided by 16 */
    WWDG_PRESCALE_DIV32,        /*!< WWDG clock divided by 32 */
    WWDG_PRESCALE_DIV64,        /*!< WWDG clock divided by 64 */
    WWDG_PRESCALE_DIV128        /*!< WWDG clock divided by 128 */
} WWDG_Prescaler;

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
  * \brief  Clears the WWDG EWIF flag
  * \param  wwdg    WWDG pointer to a WWDG_TypeDef structure
  *                  - WWDG: WWDG base address index
  */
static inline void WWDG_clearIntStatus (WWDG_TypeDef *wwdg)
{
    CLEAR_BIT(wwdg->SR.WORDVAL, 1);
}

/**
  * \brief  Enables the specified WWDGx peripheral
  * \param  wwdg         WWDG pointer to a WWDG_TypeDef structure
  *                       - WWDG: WWDG base address index
  * \param  initvalue    Load init value to WWDG_CR_T register
  *                       - This parameter is an unsigned integer that is greater 
  *                         than or equal to 0x41UL and less than or equal to 0x7FUL
  */
static inline void WWDG_enableModule (WWDG_TypeDef *wwdg, uint32_t initvalue)
{
    uint32_t temp;

    temp = (initvalue & 0x7FUL) | 0x80UL;
    WWDG_clearIntStatus(wwdg);
    WRITE_REG(wwdg->CR.WORDVAL, temp);
}

/**
  * \brief  Refresh the specified WWDGx peripheral
  * \param  wwdg         WWDG pointer to a WWDG_TypeDef structure
  *                       - WWDG: WWDG base address index
  * \param  loadvalue    Load value to WWDG_CR_T register
  *                       - This parameter is an unsigned integer that is greater 
  *                         than or equal to 0x41UL and less than or equal to 0x7FUL
  */
static inline void WWDG_refreshModule (WWDG_TypeDef *wwdg, uint32_t loadvalue)
{
    MODIFY_REG(wwdg->CR.WORDVAL, WWDG_CR_T_M, ((uint32_t)loadvalue << WWDG_CR_T_S));
}

/**
  * \brief  Enables the specified WWDGx IRQ function
  * \param  wwdg    WWDG pointer to a WWDG_TypeDef structure
  *                  - WWDG: WWDG base address index
  */
static inline void WWDG_enableInterrupt (WWDG_TypeDef *wwdg)
{
    SET_BIT(wwdg->CFR.WORDVAL, WWDG_CFR_EWI_M);
}

/**
  * \brief  Disables the specified WWDGx IRQ function
  * \param  wwdg    WWDG pointer to a WWDG_TypeDef structure
  *                  - WWDG: WWDG base address index
  */
static inline void WWDG_disableInterrupt (WWDG_TypeDef *wwdg)
{
    CLEAR_BIT(wwdg->CFR.WORDVAL, WWDG_CFR_EWI_M);
}

/**
  * \brief  Sets the WWDG refresh window value
  * \param  wwdg           WWDG pointer to a WWDG_TypeDef structure
  *                         - WWDG: WWDG base address index
  * \param  windowvalue    Load value to WWDG_CFR_W register
  *                         - This parameter is an unsigned integer that is greater 
  *                           than or equal to 0x41UL and less than or equal to 0x7FUL
  */
static inline void WWDG_setWindow (WWDG_TypeDef *wwdg, uint32_t windowvalue)
{
    MODIFY_REG(wwdg->CFR.WORDVAL, WWDG_CFR_W_M, \
              ((uint32_t)windowvalue << WWDG_CFR_W_S));
}

/**
  * \brief  Sets the WWDG Clock Division value
  * \param  wwdg         WWDG pointer to a WWDG_TypeDef structure
  *                       - WWDG: WWDG base address index
  * \param  prescaler    WWDG clock division value
  *                       - This parameter can be any value of @ref WWDG_PRESCALER
  */
static inline void WWDG_setPrescaler (WWDG_TypeDef *wwdg, WWDG_Prescaler prescaler)
{
    MODIFY_REG(wwdg->CFR.WORDVAL, WWDG_CFR_WDGTB_M, \
              ((uint32_t)prescaler << WWDG_CFR_WDGTB_S));
}


/**
  * \brief  Gets the WWDG int flag
  * \param  wwdg    WWDG pointer to a WWDG_TypeDef structure
  *                  - WWDG: WWDG base address index
  * \return Returns the status of WWDG int flag
  *                  - 0: WWDG int flag is 0
  *                  - 1: WWDG int flag is 1
  */
static inline uint8_t WWDG_getIntStatus (WWDG_TypeDef *wwdg)
{
    return READ_BIT(wwdg->SR.WORDVAL, 1)? 1 : 0;
}

/**
  * \brief  Gets the WWDG count value
  * \param  wwdg    WWDG pointer to a WWDG_TypeDef structure
  *                  - WWDG: WWDG base address index
  * \return Returns the current WWDG count value
  */
static inline uint32_t WWDG_getTimevalue (WWDG_TypeDef *wwdg)
{
    return READ_BIT(wwdg->CR.WORDVAL, 0x7F);
}

/**
  * \brief  Initializes the WWDG peripheral according to the specified parameters
  * \param  iwdg           WWDG pointer to a WWDG_TypeDef structure
  *                         - WWDG: WWDG base address index
  * \param  model_sel      WWDG Select Reset or Wakeup int
  *                         - This parameter can be any value of @ref WWDG_INTSEL
  * \param  prescaler      WWDG clock division value
  *                         - This parameter can be any value of @ref WWDG_PRESCALER
  * \param  windowvalue    WWDG load windows value
  *                         - This parameter is an unsigned integer that is greater 
  *                           than or equal to 0x41UL and less than or equal to 0x7FUL
  */
extern void WWDG_configModule (WWDG_TypeDef *wwdg, WWDG_IntSel model_sel, \
                               WWDG_Prescaler prescaler,  uint32_t windowvalue);


#ifdef __cplusplus
}
#endif


#endif /* __WWDG_H__ */
