/**
  * @file       dcc.h
  * @author     bilang.xiong
  * @brief      Header file for NS800RT7xxx dcc module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __DCC_H__
#define __DCC_H__


#ifdef __cplusplus
extern "C"
{
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_dcc.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup DCC_EXPORTED_TYPES DCC Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'DCC' module.
  */

/** @defgroup DCC_CLKSOURCE DCC definition about clock source selection
  * @{
  * @brief  Macro definitions about the bit fields in the DCC CR register definition.
  */
typedef enum {
    DCC_CLKSOURCE_MIRC1 = 0,       /*!< DCC CLK Source Select MIRC1 */
    DCC_CLKSOURCE_MIRC2,           /*!< DCC CLK Source Select MIRC2 */
    DCC_CLKSOURCE_LIRC,            /*!< DCC CLK Source Select LIRC */
    DCC_CLKSOURCE_HXTL,            /*!< DCC CLK Source Select HXTL */
    DCC_CLKSOURCE_PLL,             /*!< DCC CLK Source Select PLL */
    DCC_CLKSOURCE_INPUT15,         /*!< DCC CLK Source Select INPUT15(of INPUTXBAR) */
    DCC_CLKSOURCE_INPUT16,         /*!< DCC CLK Source Select INPUT16(of INPUTXBAR) */
    DCC_CLKSOURCE_AUXCLKIN,        /*!< DCC CLK Source Select AUXCLKIN */
    DCC_CLKSOURCE_CPU1SYSCLK,      /*!< DCC CLK Source Select CPU1 SysClk */
    DCC_CLKSOURCE_CPU2SYSCLK,      /*!< DCC CLK Source Select CPU2 SysClk */
    DCC_CLKSOURCE_DMA1CLK,         /*!< DCC CLK Source Select DMA1 Clock */
    DCC_CLKSOURCE_DMA2CLK,         /*!< DCC CLK Source Select DMA2 Clock */
    DCC_CLKSOURCE_EPWMCLK,         /*!< DCC CLK Source Select EPWM Clock */
    DCC_CLKSOURCE_SPI_UART_CLK,    /*!< DCC CLK Source Select SPI and UART Clock */
    DCC_CLKSOURCE_ADCCLK,          /*!< DCC CLK Source Select ADC Clock */
    DCC_CLKSOURCE_CPU1IWDG1CLK,    /*!< DCC CLK Source Select CPU1IWDG1 Clock */
    DCC_CLKSOURCE_CPU2IWDG1CLK,    /*!< DCC CLK Source Select CPU2IWDG1 Clock */
    DCC_CLKSOURCE_IWDG2CLK,        /*!< DCC CLK Source Select IWDG2 Clock */
    DCC_CLKSOURCE_CPU1WWDGCLK,     /*!< DCC CLK Source Select CPU1WWDG Clock */
    DCC_CLKSOURCE_CPU2WWDGCLK,     /*!< DCC CLK Source Select CPU2WWDG Clock */
    DCC_CLKSOURCE_CAN1CLK,         /*!< DCC CLK Source Select CAN1 Clock */
    DCC_CLKSOURCE_CANFD1CLK,       /*!< DCC CLK Source Select CANFD1 Clock */
    DCC_CLKSOURCE_CANFD2CLK,       /*!< DCC CLK Source Select CANFD2 Clock */
    DCC_CLKSOURCE_FLASHCLK,        /*!< DCC CLK Source Select FLASH Clock */
    DCC_CLKSOURCE_INPUT11,         /*!< DCC CLK Source Select INPUT11(of INPUTXBAR) */
    DCC_CLKSOURCE_INPUT12          /*!< DCC CLK Source Select INPUT12(of INPUTXBAR) */
} DCC_ClkSource;

/**
  * @}
  */

/** @defgroup DCC_STATEFLAG DCC definition about DCC fualt flag
  * @{
  * @brief  Macro definitions about the bit fields in the DCC IFR register definition.
  */
typedef enum {
    DCC_STATE_STOP          = 0x1U,           /*!< DCC STOP STATE */ 
    DCC_STATE_CALCNT_OVF    = 0x2U,           /*!< DCC CALCNT OVF STATE */
    DCC_STATE_CLK_FAULT     = 0x4U,           /*!< CLOCK FAULT STATE */
    DCC_STATE_ALL_FAULT     = 0x7U
} DCC_StateFlag;

/**
  * @}
  */

/** @defgroup DCC_MODE DCC interrupt or reset mode definition
  * @{
  * @brief  Macro definitions about the bit fields in the DCC CR register definition.
  * @note   Values that can be passed to as the \e DCC_setClockMonitor().
  */
typedef enum {
    DCC_INTERRTUP_MODE = 0U,    /*!< DCC INTERRTUP MODE */
    DCC_RESET_MODE              /*!< DCC RESET MODE */
} DCC_Mode;

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
 * \brief  Get the CALCNT register bits value
 * \param  dcc    DCC pointer to DCC_TypeDef structure
 *                 - DCC: DCC base address index
 * \return Returns the REFCNT register uint32_t data
 */
static inline uint32_t DCC_getCalCntValue (DCC_TypeDef *dcc)
{
    return READ_REG(dcc->CALCNT.WORDVAL);
}

/**
 * \brief  Get the REFCNT register bits value
 * \param  dcc    DCC pointer to DCC_TypeDef structure
 *                 - DCC: DCC base address index
 * \return Returns the REFCNT register uint32_t data
 */
static inline uint32_t DCC_getRefCntValue (DCC_TypeDef *dcc)
{
    return READ_REG(dcc->REFCNT.WORDVAL);
}

/**
 * \brief  DCC start counting with CR register start bit
 * \param  dcc    DCC pointer to DCC_TypeDef structure
 *                 - DCC: DCC base address index
 */
static inline void DCC_startCounting (DCC_TypeDef *dcc)
{
    SET_BIT(dcc->CR.WORDVAL, DCC_CR_TRIMSTART_M);
}

/**
 * \brief  DCC stop counting with CR register start bit
 * \param  dcc    DCC pointer to DCC_TypeDef structure
 *                 - DCC: DCC base address index
 */
static inline void DCC_stopCounting (DCC_TypeDef *dcc)
{
    CLEAR_BIT(dcc->CR.WORDVAL, DCC_CR_TRIMSTART_M);
}

/**
 * \brief  Get the IFR register state value
 * \param  dcc     DCC pointer to DCC_TypeDef structure
 *                  - DCC: DCC base address index
 * \param  flag    Monitor parameter about DCC state flag
 *                  - This parameter can be any value of @ref DCC_STATEFLAG
 * \return Returns the status of DCC IFR states flag.
 */
static inline uint32_t DCC_getStatusFlags (DCC_TypeDef *dcc, DCC_StateFlag flag)
{
    return READ_BIT(dcc->ISR.WORDVAL, (uint32_t)flag);
}

/**
 * \brief  Clear the clk fault Status Flag
 * \param  dcc     DCC pointer to DCC_TypeDef structure
 *                  - DCC: DCC base address index
 */
static inline void DCC_clearClkFaultStatusFlag (DCC_TypeDef *dcc)
{
    WRITE_REG(dcc->ICR.WORDVAL, DCC_STATE_CLK_FAULT);
}

/**
 * \brief  Set the REFCON register value
 * \param  dcc     DCC pointer to DCC_TypeDef structure
 *                  - DCC: DCC base address index
 * \param  data    Counting initial value
 *                  - This parameter can be any value from 1~0xFFFFFFFF
 */
static inline void DCC_setREFCON (DCC_TypeDef *dcc, uint32_t data)
{
    /* Set value to REFCON register */
    WRITE_REG(dcc->REFCON.WORDVAL, data);
}

/**
 * \brief  Set the HTCR register bits
 * \param  dcc     DCC pointer to DCC_TypeDef structure
 *                  - DCC: DCC base address index
 * \param  data    Higher limit range data
 *                  - This parameter can be any value from 0~0xFFFFFFFF
 */
static inline void DCC_setHTCR (DCC_TypeDef *dcc, uint32_t data)
{
    /* Set value to REFCON register */
    WRITE_REG(dcc->HTCR.WORDVAL, data);
}

/**
 * \brief  Set the LTCR register bits
 * \param  dcc     DCC pointer to DCC_TypeDef structure
 *                  - DCC: DCC base address index
 * \param  data    Lower limit range data
 *                  - This parameter can be any value from 0~0xFFFFFFFF
 */
static inline void DCC_setLTCR (DCC_TypeDef *dcc, uint32_t data)
{
    /* Set value to REFCON register */
    WRITE_REG(dcc->LTCR.WORDVAL, data);
}

/**
 * \brief  Set the DCC to monitor mode register bits
 * \param  base      DCC pointer to DCC_TypeDef structure
 *                    - DCC: DCC base address index
 * \param  refclk    Monitor parameter about reference clock
 *                    - This parameter can be any value of @ref DCC_CLKSOURCE
 * \param  calclk    Monitor parameter about calibration clock 
 *                    - This parameter can be any value of @ref DCC_CLKSOURCE
 */
static inline void DCC_setMonitorMode (DCC_TypeDef *dcc, DCC_ClkSource refClk, DCC_ClkSource calClk)
{
    /* Set Reference & Calibration clock */ 
    if (refClk != calClk)
    {
        MODIFY_REG(dcc->CR.WORDVAL, DCC_CR_CALCLKSEL_M | DCC_CR_REFCLKSEL_M,
                   ((uint32_t)refClk << DCC_CR_REFCLKSEL_S) | ((uint32_t)calClk << DCC_CR_CALCLKSEL_S) | \
                   DCC_CR_MONEN_M | DCC_CR_CLKEN_M);
    }
}

/**
 * \brief  Set the DCC to trim mode register bits
 * \param  base      DCC pointer to DCC_TypeDef structure
 *                    - DCC: DCC base address index
 * \param  refclk    Trim parameter about reference clock
 *                    - This parameter can be any value of @ref DCC_CLKSOURCE
 * \param  calclk    Trim parameter about calibration clock
 *                    - This parameter can be any value of @ref DCC_CLKSOURCE
 */
static inline void DCC_setTrimMode (DCC_TypeDef *dcc, DCC_ClkSource refclk, DCC_ClkSource calclk)
{
    /* Set Reference & Calibration clock */ 
    if (refclk != calclk)
    {
        MODIFY_REG(dcc->CR.WORDVAL, DCC_CR_CALCLKSEL_M | DCC_CR_REFCLKSEL_M | DCC_CR_MONEN_M,
                   ((uint32_t)refclk << DCC_CR_REFCLKSEL_S) | ((uint32_t)calclk << DCC_CR_CALCLKSEL_S) | DCC_CR_CLKEN_M);
    }
}

/**
 * \brief  DCC enable interrupt register in DCC module 
 * \param  dcc    DCC pointer to DCC_TypeDef structure
 *                 - DCC: DCC base address index
 */
static inline void DCC_enableInterrupt (DCC_TypeDef *dcc)
{
    MODIFY_REG(dcc->CR.WORDVAL, DCC_CR_RSTIE_M, DCC_CR_IRQEN_M);
}

/**
 * \brief  DCC disable interrupt register in DCC module 
 * \param  dcc    DCC pointer to DCC_TypeDef structure
 *                 - DCC: DCC base address index
 */
static inline void DCC_disableInterrupt (DCC_TypeDef *dcc)
{
    CLEAR_BIT(dcc->CR.WORDVAL, (DCC_CR_RSTIE_M | DCC_CR_IRQEN_M));
}

/**
  * \brief  Set the Clock DCC monitor function
  * \param  dcc       DCC pointer to DCC_TypeDef structure
  *                    - DCC: DCC base address index
  * \param  refclk    DCC CR register REFCLKSEL value
  *                    - This parameter can be any value of @ref DCC_CLKSOURCE
  * \param  calClk    DCC CR register CALCLKSEL value
  *                    - This parameter can be any value of @ref DCC_CLKSOURCE
  * \param  rstEn     DCC CR register RST_IE value
  *                    - This parameter can be any value of @ref DCC_MODE
  * \param  refCon    DCC DCC_REFCON register value
  *                    - This parameter can be any value from 1~0xFFFFFFFF
  * \param  htCr      DCC DCC_HTCR register value
  *                    - This parameter can be any value from 0~0xFFFFFFFF
  * \param  ltCr      DCC DCC_ register value
  *                    - This parameter can be any value from 0~0xFFFFFFFF
  * \return Returns the DCC monitor mode status set whether success
  *                    - true : set success
  *                    - false: set false
  */
extern bool DCC_setClockMonitor (DCC_TypeDef *dcc, DCC_ClkSource refClk, DCC_ClkSource calClk, \
                                 DCC_Mode rstEn, uint32_t refCon, uint32_t htCr, uint32_t ltCr);

/**
  * \brief  Set the Clock DCC trim function
  * \param  dcc          DCC pointer to DCC_TypeDef structure
  *                       - DCC: DCC base address index
  * \param  refclk       DCC CR register REFCLKSEL value
  *                       - This parameter can be any value of @ref DCC_CLKSOURCE
  * \param  calClk       DCC CR register CALCLKSEL value
  *                       - This parameter can be any value of @ref DCC_CLKSOURCE
  * \param  refCon       DCC DCC_REFCON register value
  *                       - This parameter can be any value from 1~0xFFFFFFFF
  * \param  irqEnable    DCC CR register IRQ_EN value
  *                       - true : ENABLE IRQ
  *                       - false: DISABLE IRQ
  * \return Returns the DCC trim mode status set whether success
  *                       - true : set success
  *                       - false: set false
  */
extern bool DCC_setClockTrim (DCC_TypeDef *dcc, DCC_ClkSource refClk, DCC_ClkSource calClk, \
                              uint32_t refCon, bool irqEnable);


#ifdef __cplusplus
}
#endif


#endif /* __DCC_H__ */
