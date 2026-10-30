/**
  * @file       dmamux.h
  * @author     yangjun
  * @brief      Header file for NS800RT7xxx dmamux module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __DMAMUX_H__
#define __DMAMUX_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup  DMAMUX_EXPORTED_TYPES DMAMUX Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'DMAMUX' module.
  */

/** @defgroup DMAMUX_REQ DMAMUX Dmamux Req Source
  * @{
  * @brief  Macro definitions about DMAMUX dmamux request source.
  *         Values that can be passed to DMAMUX_setSource() as the \e source parameter.
  */
typedef enum {
    DMAMUX_ADCA1_REQ = 0U,     /*!< ADCA1 REQUEST */
    DMAMUX_ADCA2_REQ,          /*!< ADCA2 REQUEST */
    DMAMUX_ADCA3_REQ,          /*!< ADCA3 REQUEST */
    DMAMUX_ADCA4_REQ,          /*!< ADCA4 REQUEST */
    DMAMUX_ADCA5_REQ,          /*!< ADCA5 REQUEST */
    DMAMUX_ADCB1_REQ,          /*!< ADCB1 REQUEST */
    DMAMUX_ADCB2_REQ,          /*!< ADCB2 REQUEST */
    DMAMUX_ADCB3_REQ,          /*!< ADCB3 REQUEST */
    DMAMUX_ADCB4_REQ,          /*!< ADCB4 REQUEST */
    DMAMUX_ADCB5_REQ,          /*!< ADCB5 REQUEST */
    DMAMUX_ADCC1_REQ,          /*!< ADCC1 REQUEST */
    DMAMUX_ADCC2_REQ,          /*!< ADCC2 REQUEST */
    DMAMUX_ADCC3_REQ,          /*!< ADCC3 REQUEST */
    DMAMUX_ADCC4_REQ,          /*!< ADCC4 REQUEST */
    DMAMUX_ADCC5_REQ,          /*!< ADCC5 REQUEST */
    DMAMUX_ADCD1_REQ,          /*!< ADCD1 REQUEST */
    DMAMUX_ADCD2_REQ,          /*!< ADCD2 REQUEST */
    DMAMUX_ADCD3_REQ,          /*!< ADCD3 REQUEST */
    DMAMUX_ADCD4_REQ,          /*!< ADCD4 REQUEST */
    DMAMUX_ADCD5_REQ,          /*!< ADCD5 REQUEST */
    DMAMUX_EPWM1_SOCA_REQ,     /*!< EPWM1_SOCA REQUEST */
    DMAMUX_EPWM2_SOCA_REQ,     /*!< EPWM2_SOCA REQUEST */
    DMAMUX_EPWM3_SOCA_REQ,     /*!< EPWM3_SOCA REQUEST */
    DMAMUX_EPWM4_SOCA_REQ,     /*!< EPWM4_SOCA REQUEST */
    DMAMUX_EPWM5_SOCA_REQ,     /*!< EPWM5_SOCA REQUEST */
    DMAMUX_EPWM6_SOCA_REQ,     /*!< EPWM6_SOCA REQUEST */
    DMAMUX_EPWM7_SOCA_REQ,     /*!< EPWM7_SOCA REQUEST */
    DMAMUX_EPWM8_SOCA_REQ,     /*!< EPWM8_SOCA REQUEST */
    DMAMUX_EPWM9_SOCA_REQ,     /*!< EPWM9_SOCA REQUEST */
    DMAMUX_EPWM10_SOCA_REQ,    /*!< EPWM10_SOCA REQUEST */
    DMAMUX_EPWM11_SOCA_REQ,    /*!< EPWM11_SOCA REQUEST */
    DMAMUX_EPWM12_SOCA_REQ,    /*!< EPWM12_SOCA REQUEST */
    DMAMUX_EPWM13_SOCA_REQ,    /*!< EPWM13_SOCA REQUEST */
    DMAMUX_EPWM14_SOCA_REQ,    /*!< EPWM14_SOCA REQUEST */
    DMAMUX_EPWM15_SOCA_REQ,    /*!< EPWM15_SOCA REQUEST */
    DMAMUX_EPWM16_SOCA_REQ,    /*!< EPWM16_SOCA REQUEST */
    DMAMUX_EPWM17_SOCA_REQ,    /*!< EPWM17_SOCA REQUEST */
    DMAMUX_EPWM18_SOCA_REQ,    /*!< EPWM18_SOCA REQUEST */
    DMAMUX_EPWM1_SOCB_REQ,     /*!< EPWM1_SOCB REQUEST */
    DMAMUX_EPWM2_SOCB_REQ,     /*!< EPWM2_SOCB REQUEST */
    DMAMUX_EPWM3_SOCB_REQ,     /*!< EPWM3_SOCB REQUEST */
    DMAMUX_EPWM4_SOCB_REQ,     /*!< EPWM4_SOCB REQUEST */
    DMAMUX_EPWM5_SOCB_REQ,     /*!< EPWM5_SOCB REQUEST */
    DMAMUX_EPWM6_SOCB_REQ,     /*!< EPWM6_SOCB REQUEST */
    DMAMUX_EPWM7_SOCB_REQ,     /*!< EPWM7_SOCB REQUEST */
    DMAMUX_EPWM8_SOCB_REQ,     /*!< EPWM8_SOCB REQUEST */
    DMAMUX_EPWM9_SOCB_REQ,     /*!< EPWM9_SOCB REQUEST */
    DMAMUX_EPWM10_SOCB_REQ,    /*!< EPWM10_SOCB REQUEST */
    DMAMUX_EPWM11_SOCB_REQ,    /*!< EPWM11_SOCB REQUEST */
    DMAMUX_EPWM12_SOCB_REQ,    /*!< EPWM12_SOCB REQUEST */
    DMAMUX_EPWM13_SOCB_REQ,    /*!< EPWM13_SOCB REQUEST */
    DMAMUX_EPWM14_SOCB_REQ,    /*!< EPWM14_SOCB REQUEST */
    DMAMUX_EPWM15_SOCB_REQ,    /*!< EPWM15_SOCB REQUEST */
    DMAMUX_EPWM16_SOCB_REQ,    /*!< EPWM16_SOCB REQUEST */
    DMAMUX_EPWM17_SOCB_REQ,    /*!< EPWM17_SOCB REQUEST */
    DMAMUX_EPWM18_SOCB_REQ,    /*!< EPWM18_SOCB REQUEST */
    DMAMUX_ECAP1_REQ,          /*!< ECAP1 REQUEST */
    DMAMUX_ECAP2_REQ,          /*!< ECAP2 REQUEST */
    DMAMUX_ECAP3_REQ,          /*!< ECAP3 REQUEST */
    DMAMUX_ECAP4_REQ,          /*!< ECAP4 REQUEST */
    DMAMUX_ECAP5_REQ,          /*!< ECAP5 REQUEST */
    DMAMUX_ECAP6_REQ,          /*!< ECAP6 REQUEST */
    DMAMUX_ECAP7_REQ,          /*!< ECAP7 REQUEST */
    DMAMUX_EPG_REQ,            /*!< EPG REQUEST */
    DMAMUX_SDFM1_DR1_REQ,      /*!< SDFM1 DR1 REQUEST */
    DMAMUX_SDFM1_DR2_REQ,      /*!< SDFM1 DR2 REQUEST */
    DMAMUX_SDFM1_DR3_REQ,      /*!< SDFM1 DR3 REQUEST */
    DMAMUX_SDFM1_DR4_REQ,      /*!< SDFM1 DR4 REQUEST */
    DMAMUX_SDFM2_DR1_REQ,      /*!< SDFM2 DR1 REQUEST */
    DMAMUX_SDFM2_DR2_REQ,      /*!< SDFM2 DR2 REQUEST */
    DMAMUX_SDFM2_DR3_REQ,      /*!< SDFM2 DR3 REQUEST */
    DMAMUX_SDFM2_DR4_REQ,      /*!< SDFM2 DR4 REQUEST */
    DMAMUX_SDFM3_DR1_REQ,      /*!< SDFM3 DR1 REQUEST */
    DMAMUX_SDFM3_DR2_REQ,      /*!< SDFM3 DR2 REQUEST */
    DMAMUX_SDFM3_DR3_REQ,      /*!< SDFM3 DR3 REQUEST */
    DMAMUX_SDFM3_DR4_REQ,      /*!< SDFM3 DR4 REQUEST */
    DMAMUX_SDFM4_DR1_REQ,      /*!< SDFM4 DR1 REQUEST */
    DMAMUX_SDFM4_DR2_REQ,      /*!< SDFM4 DR2 REQUEST */
    DMAMUX_SDFM4_DR3_REQ,      /*!< SDFM4 DR3 REQUEST */
    DMAMUX_SDFM4_DR4_REQ,      /*!< SDFM4 DR4 REQUEST */
    DMAMUX_PQ_REQ,             /*!< PQ REQUEST */
    DMAMUX_SPI1_TX_REQ,        /*!< SPI1 TX REQUEST */
    DMAMUX_SPI1_RX_REQ,        /*!< SPI1 RX REQUEST */
    DMAMUX_SPI2_TX_REQ,        /*!< SPI2 TX REQUEST */
    DMAMUX_SPI2_RX_REQ,        /*!< SPI2 RX REQUEST */
    DMAMUX_SPI3_TX_REQ,        /*!< SPI3 TX REQUEST */
    DMAMUX_SPI3_RX_REQ,        /*!< SPI3 RX REQUEST */
    DMAMUX_SPI4_TX_REQ,        /*!< SPI4 TX REQUEST */
    DMAMUX_SPI4_RX_REQ,        /*!< SPI4 RX REQUEST */
    DMAMUX_LIN1_TX_REQ,        /*!< LIN1 TX REQUEST */
    DMAMUX_LIN2_TX_REQ,        /*!< LIN2 TX REQUEST */
    DMAMUX_LIN1_RX_REQ,        /*!< LIN1 RX REQUEST */
    DMAMUX_LIN2_RX_REQ,        /*!< LIN2 RX REQUEST */
    DMAMUX_CAN1_REQ,           /*!< CAN1 REQUEST */
    DMAMUX_CANFD1_REQ,         /*!< CANFD REQUEST */
    DMAMUX_CANFD2_REQ,         /*!< CANFD REQUEST */
    DMAMUX_AES_OUT_REQ,        /*!< AES OUT REQUEST */
    DMAMUX_AES_IN_REQ,         /*!< AES IN REQUEST */
    DMAMUX_I2C1_TX_REQ,        /*!< I2C1 TX REQUEST */
    DMAMUX_I2C1_RX_REQ,        /*!< I2C1 RX REQUEST */
    DMAMUX_I2C2_TX_REQ,        /*!< I2C2 TX REQUEST */
    DMAMUX_I2C2_RX_REQ,        /*!< I2C2 RX REQUEST */
    DMAMUX_PMBUS_TX_REQ,       /*!< PMBUS TX REQUEST */
    DMAMUX_PMBUS_RX_REQ,       /*!< PMBUS RX REQUEST */
    DMAMUX_UART1_TX_REQ,       /*!< UART1 TX REQUEST */
    DMAMUX_UART2_TX_REQ,       /*!< UART2 TX REQUEST */
    DMAMUX_UART3_TX_REQ,       /*!< UART3 TX REQUEST */
    DMAMUX_UART4_TX_REQ,       /*!< UART3 TX REQUEST */
    DMAMUX_UART1_RX_REQ,       /*!< UART1 RX REQUEST */
    DMAMUX_UART2_RX_REQ,       /*!< UART2 RX REQUEST */
    DMAMUX_UART3_RX_REQ,       /*!< UART3 RX REQUEST */
    DMAMUX_UART4_RX_REQ,       /*!< UART3 RX REQUEST */
    DMAMUX_TIM1_TRIG_REQ,      /*!< TIM1 TRIG REQUEST */
    DMAMUX_TIM1_COM_REQ,       /*!< TIM1 COM REQUEST */
    DMAMUX_TIM1_CC4_REQ,       /*!< TIM1 CC4 REQUEST */
    DMAMUX_TIM1_CC3_REQ,       /*!< TIM1 CC3 REQUEST */
    DMAMUX_TIM1_CC2_REQ,       /*!< TIM1 CC2 REQUEST */
    DMAMUX_TIM1_CC1_REQ,       /*!< TIM1 CC1 REQUEST */
    DMAMUX_TIM1_UPDA_REQ,      /*!< TIM1 UPDA REQUEST */
    DMAMUX_TIM2_TRIG_REQ,      /*!< TIM2 TRIG REQUEST */
    DMAMUX_TIM2_COM_REQ,       /*!< TIM2 COM REQUEST */
    DMAMUX_TIM2_CC4_REQ,       /*!< TIM2 CC4 REQUEST */
    DMAMUX_TIM2_CC3_REQ,       /*!< TIM2 CC3 REQUEST */
    DMAMUX_TIM2_CC2_REQ,       /*!< TIM2 CC2 REQUEST */
    DMAMUX_TIM2_CC1_REQ,       /*!< TIM2 CC1 REQUEST */
    DMAMUX_TIM2_UPDA_REQ,      /*!< TIM2 UPDA REQUEST */
    DMAMUX_CPU1_XINT1_REQ,     /*!< CPU1 XINT1 REQUEST */
    DMAMUX_CPU1_XINT2_REQ,     /*!< CPU1 XINT2 REQUEST */
    DMAMUX_CPU1_XINT3_REQ,     /*!< CPU1 XINT3 REQUEST */
    DMAMUX_CPU1_XINT4_REQ,     /*!< CPU1 XINT4 REQUEST */
    DMAMUX_CPU1_XINT5_REQ,     /*!< CPU1 XINT5 REQUEST */
    DMAMUX_CPU2_XINT1_REQ,     /*!< CPU2 XINT1 REQUEST */
    DMAMUX_CPU2_XINT2_REQ,     /*!< CPU2 XINT2 REQUEST */
    DMAMUX_CPU2_XINT3_REQ,     /*!< CPU2 XINT3 REQUEST */
    DMAMUX_CPU2_XINT4_REQ,     /*!< CPU2 XINT4 REQUEST */
    DMAMUX_CPU2_XINT5_REQ,     /*!< CPU2 XINT5 REQUEST */
    DMAMUX_CLB1_REQ,           /*!< CLB1 REQUEST */
    DMAMUX_CLB2_REQ,           /*!< CLB2 REQUEST */
    DMAMUX_CLB3_REQ,           /*!< CLB3 REQUEST */
    DMAMUX_CLB4_REQ,           /*!< CLB4 REQUEST */
    DMAMUX_CLB5_REQ,           /*!< CLB5 REQUEST */
    DMAMUX_CLB6_REQ            /*!< CLB6 REQUEST */
} DMAMUX_Req;

/**
  * @}
  */

/** @defgroup DMAMUX_CHCONFIG DMAMUX Channel Configuration
  * @{
  * @brief  Macro definitions about the bit fields in the DMAMUX channel configuration register definition.
  */
#define DMAMUX_CHCONFIG_MASK    (DMAMUX_CHCONFIG_EN_M | DMAMUX_CHCONFIG_TRIG_M | \
                                 DMAMUX_CHCONFIG_ALWAYSON_M | DMAMUX_CHCONFIG_SOURCE_M)    /*!< CHCONFIG byte Mask */

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
 * \brief  Enables the DMAMUX channel.
 * \param  dmamux     The base address of the DMAMUX module.
 *                     - DMAMUX1: DMAMUX1 base address index
 *                     - DMAMUX2: DMAMUX2 base address index
 * \param  channel    Channel num.
 *                     - uint8_t: channel num is range from 0 to 31
 */
static inline void DMAMUX_enableChannel (DMAMUX_TypeDef *dmamux, uint8_t channel)
{
    SET_BIT(dmamux->CHCONFIG[channel].WORDVAL, DMAMUX_CHCONFIG_EN_M);
}

/**
 * \brief  Disable the DMAMUX channel.
 * \param  dmamux     The base address of the DMAMUX module.
 *                     - DMAMUX1: DMAMUX1 base address index
 *                     - DMAMUX2: DMAMUX2 base address index
 * \param  channel    Channel num.
 *                     - uint8_t: channel num is range from 0 to 31
 */
static inline void DMAMUX_disableChannel (DMAMUX_TypeDef *dmamux, uint8_t channel)
{
    CLEAR_BIT(dmamux->CHCONFIG[channel].WORDVAL, DMAMUX_CHCONFIG_EN_M);
}

/**
 * \brief  Enable the DMAMUX trigger function.
 * \param  dmamux     The base address of the DMAMUX module.
 *                     - DMAMUX1: DMAMUX1 base address index
 *                     - DMAMUX2: DMAMUX2 base address index
 * \param  channel    Channel num.
 *                     - uint8_t: channel num is range from 0 to 31
 */
static inline void DMAMUX_enableTrigger (DMAMUX_TypeDef *dmamux, uint8_t channel)
{
    SET_BIT(dmamux->CHCONFIG[channel].WORDVAL, DMAMUX_CHCONFIG_TRIG_M);
}

/**
 * \brief  Disable the DMAMUX trigger function.
 * \param  dmamux     The base address of the DMAMUX module.
 *                     - DMAMUX1: DMAMUX1 base address index
 *                     - DMAMUX2: DMAMUX2 base address index
 * \param  channel    Channel num.
 *                     - uint8_t: channel num is range from 0 to 31
 */
static inline void DMAMUX_disableTrigger (DMAMUX_TypeDef *dmamux, uint8_t channel)
{
    CLEAR_BIT(dmamux->CHCONFIG[channel].WORDVAL, DMAMUX_CHCONFIG_TRIG_M);
}

/**
 * \brief  Enable the DMAMUX always-on function.
 * \param  dmamux     The base address of the DMAMUX module.
 *                     - DMAMUX1: DMAMUX1 base address index
 *                     - DMAMUX2: DMAMUX2 base address index
 * \param  channel    Channel num.
 *                     - uint8_t: channel num is range from 0 to 31
 */
static inline void DMAMUX_enableAlwaysOn (DMAMUX_TypeDef *dmamux, uint8_t channel)
{
    SET_BIT(dmamux->CHCONFIG[channel].WORDVAL, DMAMUX_CHCONFIG_ALWAYSON_M);
}

/**
 * \brief  Disable the DMAMUX always-on function.
 * \param  dmamux     The base address of the DMAMUX module.
 *                     - DMAMUX1: DMAMUX1 base address index
 *                     - DMAMUX2: DMAMUX2 base address index
 * \param  channel    Channel num.
 *                     - uint8_t: channel num is range from 0 to 31
 */
static inline void DMAMUX_disableAlwaysOn (DMAMUX_TypeDef *dmamux, uint8_t channel)
{
    CLEAR_BIT(dmamux->CHCONFIG[channel].WORDVAL, DMAMUX_CHCONFIG_ALWAYSON_M);
}

/**
 * \brief  Reset the DMAMUX channel.
 * \param  dmamux     The base address of the DMAMUX module.
 *                     - DMAMUX1: DMAMUX1 base address index
 *                     - DMAMUX2: DMAMUX2 base address index
 * \param  channel    Channel num.
 *                     - uint8_t: channel num is range from 0 to 31
 * \param  source     SOURCE specifies which DMA source.
 *                     This parameter can be any value of @ref DMAMUX_REQ
 */
static inline void DMAMUX_setSource (DMAMUX_TypeDef *dmamux, uint8_t channel, DMAMUX_Req source)
{
    MODIFY_REG(dmamux->CHCONFIG[channel].WORDVAL, DMAMUX_CHCONFIG_SOURCE_M, source);
}

/**
 * \brief  Reset the DMAMUX all channel.
 * \param  dmamux    The base address of the DMAMUX module.
 *                    - DMAMUX1: DMAMUX1 base address index
 *                    - DMAMUX2: DMAMUX2 base address index
 */
static inline void DMAMUX_resetAllChannel (DMAMUX_TypeDef *dmamux)
{
    for (uint32_t channel = 0; channel < 32; channel ++)
    {
        WRITE_REG(dmamux->CHCONFIG[channel].WORDVAL, 0UL);
    }
}

/**
 * \brief  Reset the DMAMUX channel.
 * \param  dmamux     The base address of the DMAMUX module.
 *                     - DMAMUX1: DMAMUX1 base address index
 *                     - DMAMUX2: DMAMUX2 base address index
 * \param  channel    Channel num.
 *                     - uint8_t: channel num is range from 0 to 31
 */
static inline void DMAMUX_resetChannel (DMAMUX_TypeDef *dmamux, uint8_t channel)
{
    CLEAR_BIT(dmamux->CHCONFIG[channel].WORDVAL, DMAMUX_CHCONFIG_MASK);
}

/**
 * \brief  Initializes the DMAMUX peripheral.
 * \param  dmamux    The base address of the DMAMUX module.
 *                    - DMAMUX1: DMAMUX1 base address index
 *                    - DMAMUX2: DMAMUX2 base address index
 */
extern void DMAMUX_configModule (DMAMUX_TypeDef *dmamux);


#ifdef __cplusplus
}
#endif


#endif /* __DMAMUX_H__ */
