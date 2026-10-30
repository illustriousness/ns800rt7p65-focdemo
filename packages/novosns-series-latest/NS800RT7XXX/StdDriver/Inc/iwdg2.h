/**
  * @file       iwdg2.h
  * @author     bilang.xiong
  * @brief      Header file for NS800RT7xxx iwdg2 module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __IWDG2_H__
#define __IWDG2_H__


#ifdef __cplusplus
extern "C"{
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_iwdg2.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup IWDG2_EXPORTED_TYPES IWDG2 Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'IWDG2' module.
  */

/** @defgroup IWDG2_RESIRQSEL IWDG2 Select Reset or IRQ
  * @{
  * @brief  Macro definitions about IWDG2 reset interrupt function select.
  */
typedef enum {
    IRQ_SEL = 0U,    /*!< IWDG2 irq enable */
    RESET_SEL        /*!< IWDG2 reset enable */
} IWDG2_ResIrqSel;

/**
  * @}
  */

/** @defgroup IWDG2_PRESCALER IWDG2 Clock Divsion
  * @{
  * @brief  Macro definitions about IWDG2 clock divsion.
  */
typedef enum {
    IWDG2_PRESCALE_DIV128 = 0x0U,    /*!< IWDG1 clock divided by 128 */
    IWDG2_PRESCALE_DIV2048,          /*!< IWDG1 clock divided by 2048 */
    IWDG2_PRESCALE_DIV1024,          /*!< IWDG1 clock divided by 1024 */
    IWDG2_PRESCALE_DIV512,           /*!< IWDG1 clock divided by 512 */
    IWDG2_PRESCALE_DIV256,           /*!< IWDG1 clock divided by 256 */
    IWDG2_PRESCALE_DIV64,            /*!< IWDG1 clock divided by 64 */
    IWDG2_PRESCALE_DIV32,            /*!< IWDG1 clock divided by 32 */
    IWDG2_PRESCALE_DIV16,            /*!< IWDG1 clock divided by 16 */
    IWDG2_PRESCALE_DIV8,             /*!< IWDG1 clock divided by 8 */
    IWDG2_PRESCALE_DIV4              /*!< IWDG1 clock divided by 4 */
} IWDG2_Prescaler;

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
  * \brief  Enable the specified IWDG2x peripheral
  * \param  iwdg    IWDG2 pointer to a IWDG2_TypeDef structure
  *                  - IWDG2: IWDG2 base address index
  */
static inline void IWDG2_enableModule (IWDG2_TypeDef *iwdg)
{
    WRITE_REG(iwdg->KR.WORDVAL, 0x0000CCCC);
}

/**
  * \brief  Refresh the specified IWDG2x peripheral
  * \param  iwdg    IWDG2 pointer to a IWDG2_TypeDef structure
  *                  - IWDG2: IWDG2 base address index
  */
static inline void IWDG2_refreshModule (IWDG2_TypeDef *iwdg)
{
    WRITE_REG(iwdg->KR.WORDVAL, 0x0000AAAA);
}

/**
  * \brief  Enables the specified IWDG2x IRQ function
  * \param  iwdg    IWDG2 pointer to a IWDG2_TypeDef structure
  *                  - IWDG2: IWDG2 base address index
  */
static inline void IWDG2_enableInterrupt (IWDG2_TypeDef *iwdg)
{
    WRITE_REG(iwdg->KR.WORDVAL, 0x00005555);
    SET_BIT(iwdg->CR.WORDVAL, IWDG2_CR_IRQ_EN_M);
}

/**
  * \brief  Disables the specified IWDG2x IRQ function
  * \param  iwdg    IWDG2 pointer to a IWDG2_TypeDef structure
  *                  - IWDG2: IWDG2 base address index
  */
static inline void IWDG2_disableInterrupt (IWDG2_TypeDef *iwdg)
{
    WRITE_REG(iwdg->KR.WORDVAL, 0x00005555);
    CLEAR_BIT(iwdg->CR.WORDVAL, IWDG2_CR_IRQ_EN_M);
}

/**
  * \brief  Sets the IWDG2x Clock Division value
  * \param  iwdg         IWDG2 pointer to a IWDG2_TypeDef structure
  *                       - IWDG2: IWDG2 base address index
  * \param  prescaler    IWDG2 clock division value
  *                       - This parameter can be any value of @ref IWDG2_PRESCALER
  */
static inline void IWDG2_setPrescaler (IWDG2_TypeDef *iwdg, IWDG2_Prescaler prescaler)
{
    WRITE_REG(iwdg->KR.WORDVAL, 0x00005555);
    MODIFY_REG(iwdg->CR.WORDVAL, IWDG2_CR_PR_M, ((uint32_t)prescaler << IWDG2_CR_PR_S));
}

/**
  * \brief  Gets the IWDG2 int Flag
  * \param  iwdg    IWDG2 pointer to a IWDG2_TypeDef structure
  *                  - IWDG2: IWDG1 base address index
  * \return Returns the status of IWDG2 int flag
  *                  - 0: IWDG2 int flag is 0
  *                  - 1: IWDG2 int flag is 1
  */
static inline uint32_t IWDG2_getIntStatus (IWDG2_TypeDef *iwdg)
{
    return READ_BIT(iwdg->INTSR.WORDVAL, IWDG2_INTSR_IWDG2INT_M)? 1 : 0;
}

/**
  * \brief  Clears the IWDG2 int Flag
  * \param  iwdg    IWDG2 pointer to a IWDG2_TypeDef structure
  *                  - IWDG2: IWDG1 base address index
  */
static inline void IWDG2_clearIntStatus (IWDG2_TypeDef *iwdg)
{
    SET_BIT(iwdg->INTCLR.WORDVAL, IWDG2_INTCLR_INT_CLR_M);
}

/**
  * \brief  Set the IWDG2 mode for reset or IRQ
  * \param  iwdg    IWDG2 pointer to a IWDG2_TypeDef structure
  *                  - IWDG2: IWDG2 base address index
  * \param  mode    IWDG2 select reset or IRQ
  *                  - This parameter can be any value of @ref IWDG2_RESIRQSEL
  */
static inline void IWDG2_setModule (IWDG2_TypeDef *iwdg, IWDG2_ResIrqSel mode)
{
    WRITE_REG(iwdg->KR.WORDVAL, 0x00005555);
    MODIFY_REG(iwdg->CR.WORDVAL, IWDG2_CR_RSTIRQS_M,\
               ((uint32_t)mode << IWDG2_CR_RSTIRQS_S));
}

/**
  * \brief  Reload the count value to IWDG2_RLR register
  * \param  iwdg         IWDG2 pointer to a IWDG2_TypeDef structure
  *                       - IWDG2: IWDG2 base address index
  * \param  loadvalue    Load value to IWDG2_RLR register
  *                       - This parameter is an unsigned integer that is less than 0xFFFUL
  * \return Returns the status of the operation to reload the IWDG2_RLR value
  *                       - 0: This reload action has failed
  *                       - 1: This reload action has succeeded
  */
static inline void IWDG2_setLoadValue(IWDG2_TypeDef *iwdg, uint32_t loadvalue)
{
    WRITE_REG(iwdg->KR.WORDVAL, 0x00005555);
    WRITE_REG(iwdg->RLR.WORDVAL, (loadvalue & 0x00000FFF));
}

/**
  * \brief  Get the IWDG2_VUSR control register’s value update status
  * \param  iwdg    IWDG2 pointer to a IWDG2_TypeDef structure
  *                  - IWDG2: IWDG2 base address index
  * \return Returns the status of IWDG2_VUSR_PVU flag
  *                  - 0: IWDG2 PVU flag is 0 (idle)
  *                  - 1: IWDG2 PVU flag is 1 (busy)
  */
static inline uint8_t IWDG2_getPVUStatus (IWDG2_TypeDef *iwdg)
{
    return READ_BIT(iwdg->VUSR.WORDVAL, IWDG2_VUSR_PVU_M)? 1 : 0;
}

/**
  * \brief  Get the IWDG2_VUSR counter reload value update status
  * \param  iwdg    IWDG2 pointer to a IWDG2_TypeDef structure
  *                  - IWDG2: IWDG2 base address index
  * \return Returns the status of IWDG2_VUSR_RVU flag
  *                  - 0: IWDG2 RVU flag is 0 (idle)
  *                  - 1: IWDG2 RVU flag is 1 (busy)
  */
static inline uint8_t IWDG2_getRVUStatus (IWDG2_TypeDef *iwdg)
{
    return READ_BIT(iwdg->VUSR.WORDVAL, IWDG2_VUSR_RVU_M)? 1 : 0;
}

/**
  * \brief  Initializes the IWDG2 peripheral according to the specified parameters
  * \param  iwdg         IWDG2 pointer to a IWDG2_TypeDef structure
  *                       - IWDG2: IWDG2 base address index
  * \param  resetsel     IWDG2 select reset or IRQ
  *                       - This parameter can be any value of @ref IWDG2_RESIRQSEL
  * \param  prescaler    IWDG2 clock division value
  *                       - This parameter can be any value of @ref IWDG2_PRESCALER
  * \param  loadvalue    Load value to IWDG2_RLR register
  *                       - This parameter is an unsigned integer that is less
  *                         than 0xFFFUL
  * \return Returns a flag indicates whether the IWDG2 initialization operation
  *                       has been successfully completed
  *                       - 0: the operation has failed
  *                       - 1: the operation has succeeded
  */
extern uint8_t IWDG2_configModule (IWDG2_TypeDef *iwdg, IWDG2_ResIrqSel mode,\
                               IWDG2_Prescaler prescaler, uint32_t loadvalue);


#ifdef __cplusplus
}
#endif


#endif /* __IWDG2_H__ */
