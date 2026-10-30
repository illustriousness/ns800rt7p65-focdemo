/**
  * @file       iwdg1.h
  * @author     bilang.xiong
  * @brief      Header file for NS800RT7xxx iwdg1 module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __IWDG1_H__
#define __IWDG1_H__


#ifdef __cplusplus
extern "C"{
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_iwdg1.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup IWDG1_EXPORTED_TYPES IWDG1 Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'IWDG1' module.
  */

/** @defgroup IWDG1_RESIRQSEL IWDG1 Select Reset or IRQ
  * @{
  * @brief  Macro definitions about IWDG1 select reset or interrupt function.
  */
typedef enum {
    IRQ_EN = 0x0U,    /*!< IWDG1 irq enable */
    RESET_EN          /*!< IWDG1 reset enable */
} IWDG1_ResIrqSel;

/**
  * @}
  */

/** @defgroup IWDG1_WINDOWHEAD IWDG1 Window Head
  * @{
  * @brief  Macro definitions about IWDG1 window head config.
  */
typedef enum {
    HEAD_PERCENT25 = 0x0U,    /*!< Window head location 25% */
    HEAD_PERCENT50,           /*!< Window head location 50% */
    HEAD_PERCENT75,           /*!< Window head location 75% */
    HEAD_PERCENT100           /*!< Window head location 100% */
} IWDG1_WindowHead;

/**
  * @}
  */

/** @defgroup IWDG1_WINDOWEND IWDG1 Window End
  * @{
  * @brief  Macro definitions about IWDG1 window end config.
  */
typedef enum {
    END_PERCENT75 = 0x0U,    /*!< Window end location 75% */
    END_PERCENT50,           /*!< Window end location 50% */
    END_PERCENT25,           /*!< Window end location 25% */
    END_PERCENT0             /*!< Window end location 0% */
} IWDG1_WindowEnd;

/**
  * @}
  */

/** @defgroup IWDG1_PRESCALER IWDG1 Clock Divsion
  * @{
  * @brief  Macro definitions about IWDG1 clock divsion.
  */
typedef enum {
    IWDG1_PRESCALE_DIV1 = 0x0U,      /*!< IWDG1 clock divided by 1 */
    IWDG1_PRESCALE_DIV2,             /*!< IWDG1 clock divided by 2 */
    IWDG1_PRESCALE_DIV4,             /*!< IWDG1 clock divided by 4 */
    IWDG1_PRESCALE_DIV8,             /*!< IWDG1 clock divided by 8 */
    IWDG1_PRESCALE_DIV16,            /*!< IWDG1 clock divided by 16 */
    IWDG1_PRESCALE_DIV32,            /*!< IWDG1 clock divided by 32 */
    IWDG1_PRESCALE_DIV128 = 0x8U,    /*!< IWDG1 clock divided by 128 */
    IWDG1_PRESCALE_DIV256,           /*!< IWDG1 clock divided by 256 */
    IWDG1_PRESCALE_DIV512,           /*!< IWDG1 clock divided by 512 */
    IWDG1_PRESCALE_DIV1024,          /*!< IWDG1 clock divided by 1024 */
    IWDG1_PRESCALE_DIV2048,          /*!< IWDG1 clock divided by 2048 */
    IWDG1_PRESCALE_DIV4096,          /*!< IWDG1 clock divided by 4096 */
    IWDG1_PRESCALE_DIV8192,          /*!< IWDG1 clock divided by 8192 */
    IWDG1_PRESCALE_DIV64             /*!< IWDG1 clock divided by 64 */
} IWDG1_Prescaler;

/**
  * @}
  */

/** @defgroup IWDG1_LOWPOWERMODE IWDG1 Work Mode in Lowpower Mode
  * @{
  * @brief  Macro definitions about IWDG1 work mode in lowpower mode.
  */
typedef enum {
    LPRUN  = 0x0U,    /*!< IWDG1 continues counting in lowpower mode */
    LPSTOP            /*!< IWDG1 stops counting in lowpower mode */
} IWDG1_LowpowerMode;

/**
  * @}
  */

/** @defgroup IWDG1_TIMEOUT IWDG1 Timeout Periods
  * @{
  * @brief  Macro definitions about IWDG1 timeout periods.
  */
typedef enum {
    IWDG1_TIMEOUT_1024 = 0x0U,    /*!< IWDG1 timeout for 1024 clock cycles */
    IWDG1_TIMEOUT_4096,           /*!< IWDG1 timeout for 4096 clock cycles */
    IWDG1_TIMEOUT_8192,           /*!< IWDG1 timeout for 8192 clock cycles */
    IWDG1_TIMEOUT_16384           /*!< IWDG1 timeout for 16384 clock cycles */
} IWDG1_Timeout;  

/**
  * @}
  */

/** @defgroup IWDG1_STATUS IWDG1 Status Configuration
  * @{
  * @brief  Macro definitions about IWDG1 status configuration definition.
  */
#define IWDG1_STATUS_OK       (0x00UL)    /*!< IWDG1 status is OK */
#define IWDG1_STATUS_UNDFF    (0x01UL)    /*!< IWDG1 status is underflow error */
#define IWDG1_STATUS_REFEF    (0x02UL)    /*!< IWDG1 status is refresh error */

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
  * \brief  Enable the specified IWDG1 peripheral
  * \param  iwdg    IWDG1 pointer to a IWDG1_TypeDef structure
  *                  - IWDG1: IWDG1 base address index
  */
static inline void IWDG1_enableModule (IWDG1_TypeDef *iwdg)
{
    WRITE_REG(iwdg->RR.WORDVAL, 0x00000000);
    __DSB();
    WRITE_REG(iwdg->RR.WORDVAL, 0x000000FF);
}

/**
  * \brief  Refresh the specified IWDG1x peripheral
  * \param  iwdg    IWDG1 pointer to a IWDG1_TypeDef structure
  *                  - IWDG1: IWDG1 base address index
  */
static inline void IWDG1_refreshModule (IWDG1_TypeDef *iwdg)
{
    WRITE_REG(iwdg->RR.WORDVAL, 0x00000000);
    __DSB();
    WRITE_REG(iwdg->RR.WORDVAL, 0x000000FF);
}

/**
  * \brief  Get IWDG1 peripheral status
  * \param  iwdg    IWDG1 pointer to a IWDG1_TypeDef structure
  *                  - IWDG1: IWDG1 base address index
  * \return Returns the status of IWDG1 peripheral
  *                  This parameter can be any value of 
  *                  @ref IWDG1_STATUS
  */
static inline uint8_t IWDG1_getErrorStatus (IWDG1_TypeDef *iwdg)
{
    if (READ_BIT(iwdg->SR.WORDVAL, IWDG_SR_REFEF_M))
    {
        return IWDG1_STATUS_REFEF;
    }
    else if (READ_BIT(iwdg->SR.WORDVAL, IWDG_SR_UNDFF_M))
    {
        return IWDG1_STATUS_UNDFF;
    }
    else
    {
        return IWDG1_STATUS_OK;
    }
}

/**
  * \brief  Clear the IWDG1 error flag
  * \param  iwdg    IWDG1 pointer to a IWDG1_TypeDef structure
  *                  - IWDG1: IWDG1 base address index
  */
static inline void IWDG1_clearErrorStatus (IWDG1_TypeDef *iwdg)
{
    CLEAR_BIT(iwdg->SR.WORDVAL, IWDG_SR_REFEF_M);
    __NOP();
    CLEAR_BIT(iwdg->SR.WORDVAL, IWDG_SR_UNDFF_M);
}

/**
  * \brief  Gets the IWDG1 int Flag
  * \param  iwdg    IWDG1 pointer to a IWDG1_TypeDef structure
  *                  - IWDG1: IWDG1 base address index
  * \return Returns the status of IWDG1 int flag
  *                  - 0: IWDG1 int flag is 0
  *                  - 1: IWDG1 int flag is 1
  */
static inline uint8_t IWDG1_getIntStatus (IWDG1_TypeDef *iwdg)
{
    return READ_BIT(iwdg->INTSR.WORDVAL, 1)? 1 : 0;
}

/**
  * \brief  Clear the IWDG1 int Flag
  * \param  iwdg    IWDG1 pointer to a IWDG1_TypeDef structure
  *                  - IWDG1: IWDG1 base address index
  */
static inline void IWDG1_clearIntStatus (IWDG1_TypeDef *iwdg)
{
    SET_BIT(iwdg->INTCLR.WORDVAL, 1);
}

/**
  * \brief  Set the IWDG1 mode for reset or IRQ
  * \param  iwdg    IWDG1 pointer to a IWDG1_TypeDef structure
  *                  - IWDG1: IWDG1 base address index
  * \param  mode    IWDG1 select reset or IRQ
  *                  - This parameter can be any value of @ref IWDG1_RESIRQSEL
  */
static inline void IWDG1_setModule (IWDG1_TypeDef *iwdg, IWDG1_ResIrqSel resetsel)
{
    MODIFY_REG(iwdg->CR.WORDVAL, IWDG_CR_RSTIRQS_M, ((uint32_t)resetsel << IWDG_CR_RSTIRQS_S));
}

/**
  * \brief  Set the IWDG1 Clock division value
  * \param  iwdg         IWDG1 pointer to a IWDG1_TypeDef structure
  *                       - IWDG1: IWDG1 base address index
  * \param  prescaler    IWDG1 clock division value
  *                       - This parameter can be any value of @ref IWDG1_PRESCALER
  */
static inline void IWDG1_setPrescaler (IWDG1_TypeDef *iwdg, IWDG1_Prescaler prescaler)
{
    MODIFY_REG(iwdg->CR.WORDVAL, IWDG_CR_CKS_M, ((uint32_t)prescaler << IWDG_CR_CKS_S));
}

/**
  * \brief  Set the IWDG1 refresh windowhead and windowend value
  * \param  iwdg    IWDG1 pointer to a IWDG1_TypeDef structure
  *                  - IWDG1: IWDG1 base address index
  * \param  head    IWDG1 refresh windowshead value
  *                  - This parameter can be any value of @ref IWDG1_WINDOWHEAD
  * \param  end     IWDG1 refresh windowsend value
  *                  - This parameter can be any value of @ref IWDG1_WINDOWEND
  */
static inline void IWDG1_setRefreshwindow (IWDG1_TypeDef *iwdg, IWDG1_WindowHead windowhead, IWDG1_WindowEnd windowend)
{
    MODIFY_REG(iwdg->CR.WORDVAL, IWDG_CR_RPSS_M, ((uint32_t)windowhead << IWDG_CR_RPSS_S));
    MODIFY_REG(iwdg->CR.WORDVAL, IWDG_CR_RPES_M, ((uint32_t)windowend << IWDG_CR_RPES_S));
}

/**
  * \brief  Set the IWDG1 work mode in Lowpower mode
  * \param  iwdg    IWDG1 pointer to a IWDG1_TypeDef structure
  *                  - IWDG1: IWDG1 base address index
  * \param  mode    IWDG1 work mode in lowpower mode
  *                  - This parameter can be any value of @ref IWDG1_LOWPOWERMODE
  */
static inline void IWDG1_setLowpowerMode (IWDG1_TypeDef *iwdg, IWDG1_LowpowerMode mode)
{
    MODIFY_REG(iwdg->CR.WORDVAL, IWDG_CR_SLCSTP_M, ((uint32_t)mode << IWDG_CR_SLCSTP_S));
}

/**
  * \brief  Select the IWDG1 timeout periods
  * \param  iwdg    IWDG1 pointer to a IWDG1_TypeDef structure
  *                  - IWDG1: IWDG1 base address index
  * \param  value   IWDG1 timeout periods
  *                  - This parameter can be any value of @ref IWDG1_TIMEOUT
  */
static inline void IWDG1_selectTimeout (IWDG1_TypeDef *iwdg, IWDG1_Timeout value)
{
    MODIFY_REG(iwdg->CR.WORDVAL, IWDG_CR_TOPS_M, ((uint32_t)value << IWDG_CR_TOPS_S));
}

/**
  * \brief  Initializes the IWDG1x Timer Base Unit peripheral
  *         according to the specified parameters in the iwdg1Config
  * \param  iwdg          IWDG1 pointer to a IWDG1_TypeDef structure
  *                        - IWDG1: IWDG1 base address index
  * \param  resetsel      IWDG1 select reset or IRQ
  *                        - This parameter can be any value of @ref IWDG1_RESIRQSEL
  * \param  lpmode        IWDG1 work mode in lowpower mode
  *                        - This parameter can be any value of @ref IWDG1_LOWPOWERMODE
  * \param  prescaler     IWDG1 clock division value
  *                        - This parameter can be any value of @ref IWDG1_PRESCALER
  * \param  windowhead    IWDG1 refresh windowshead value
  *                        - This parameter can be any value of @ref IWDG1_WINDOWHEAD
  * \param  windowend     IWDG1 refresh windowsend value
  *                        - This parameter can be any value of @ref IWDG1_WINDOWEND
  * \param  timeout       IWDG1 timeout periods
  *                        - This parameter can be any value of @ref IWDG1_TIMEOUT
  */
extern void IWDG1_configModule (IWDG1_TypeDef *iwdg, IWDG1_ResIrqSel resetsel, IWDG1_LowpowerMode lpmode,\
                                IWDG1_Prescaler preScale, IWDG1_WindowHead windowhead,\
                                IWDG1_WindowEnd windowend, IWDG1_Timeout timeout);


#ifdef __cplusplus
}
#endif


#endif /* __IWDG1_H__ */
