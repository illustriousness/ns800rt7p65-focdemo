/**
  * @file       stim.h
  * @author     yangjun
  * @brief      Header file for NS800RT7xxx stim module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */

#ifndef __STIM_H__
#define __STIM_H__


#ifdef __cplusplus
extern "C"
{
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup STIM_EXPORTED_TYPES STIM Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'STIM' module.
  */

/** @defgroup STIM_CHANNEL STIM Channel Number with one STIM(STIM1/STIM2/STIM3)
  * @{
  * @brief  Macro definitions about STIM Channels.
  */
typedef enum {
    STIM_CHN1 = 0U,    /*!< STIM channel number 1 */
    STIM_CHN2          /*!< STIM channel number 2 */
} STIM_Channel;

/**
  * @}
  */

/** @defgroup STIM_MODE STIM count Mode
  * @{
  * @brief  Macro definitions about STIM count Mode.
  */
typedef enum {
    STIM_PARALLEL = 0U,    /*!< Each channel counts itself */
    STIM_CASCADE  = 4U     /*!< One channel counts by another channel overcountting */
} STIM_Mode;

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
  * \brief  Enables the specified STIMx peripheral run function.
  * \param  stim    STIM pointer to a STIM_TypeDef structure
  *                  - STIM1: STIM1 base address index
  *                  - STIM2: STIM2 base address index
  *                  - STIM3: STIM3 base address index
  */
static inline void STIM_enableModule (STIM_TypeDef *stim)
{
    CLEAR_BIT(stim->MCR.WORDVAL, STIM_MCR_MDIS_M);
}

/**
  * \brief  Disables the specified STIMx peripheral run function.
  * \param  stim    STIM pointer to a STIM_TypeDef structure
  *                  - STIM1: STIM1 base address index
  *                  - STIM2: STIM2 base address index
  *                  - STIM3: STIM3 base address index
  */
static inline void STIM_disableModule (STIM_TypeDef *stim)
{
    SET_BIT(stim->MCR.WORDVAL, STIM_MCR_MDIS_M);
}

/**
  * \brief  Enables the specified STIMx peripheral Channelx run function.
  * \param  stim    STIM pointer to a STIM_TypeDef structure
  *                  - STIM1: STIM1 base address index
  *                  - STIM2: STIM2 base address index
  *                  - STIM3: STIM3 base address index
  * \param  Chn     STIM Channel Number.
  *                  This parameter can be any value of @ref STIM_CHANNEL
  * \note   The module should be enabled before enabling the channel.
  */
static inline void STIM_enableChannel (STIM_TypeDef *stim, STIM_Channel Chn)
{
    if (Chn == STIM_CHN1)
    {
        SET_BIT(stim->CR1.WORDVAL, STIM_CR1_TEN_M);
    }
    else
    {
        SET_BIT(stim->CR2.WORDVAL, STIM_CR2_TEN_M);
    }
}

/**
  * \brief  Disables the specified STIMx peripheral Channelx run function.
  * \param  stim    STIM pointer to a STIM_TypeDef structure
  *                  - STIM1: STIM1 base address index
  *                  - STIM2: STIM2 base address index
  *                  - STIM3: STIM3 base address index
  * \param  Chn     STIM Channel Number.
  *                  This parameter can be any value of @ref STIM_CHANNEL
  */
static inline void STIM_disableChannel (STIM_TypeDef *stim, STIM_Channel Chn)
{
    if (Chn == STIM_CHN1)
    {
        CLEAR_BIT(stim->CR1.WORDVAL, STIM_CR1_TEN_M);
    }
    else
    {
        CLEAR_BIT(stim->CR2.WORDVAL, STIM_CR2_TEN_M);
    }
}

/**
  * \brief  Enables the specified STIMx peripheral Channelx IE function.
  * \param  stim    STIM pointer to a STIM_TypeDef structure
  *                  - STIM1: STIM1 base address index
  *                  - STIM2: STIM2 base address index
  *                  - STIM3: STIM3 base address index
  * \param  Chn     STIM Channel Number.
  *                  This parameter can be any value of @ref STIM_CHANNEL
  */
static inline void STIM_enableInterrupt (STIM_TypeDef *stim, STIM_Channel Chn)
{
    if (Chn == STIM_CHN1)
    {
        SET_BIT(stim->CR1.WORDVAL, STIM_CR1_TIE_M);
    }
    else
    {
        SET_BIT(stim->CR2.WORDVAL, STIM_CR2_TIE_M);
    }
}

/**
  * \brief  Disables the specified STIMx peripheral Channelx IE function.
  * \param  stim    STIM pointer to a STIM_TypeDef structure
  *                  - STIM1: STIM1 base address index
  *                  - STIM2: STIM2 base address index
  *                  - STIM3: STIM3 base address index
  * \param  Chn     STIM Channel Number.
  *                  This parameter can be any value of @ref STIM_CHANNEL
  */
static inline void STIM_disableInterrupt (STIM_TypeDef *stim, STIM_Channel Chn)
{
    if (Chn == STIM_CHN1)
    {
        CLEAR_BIT(stim->CR1.WORDVAL, STIM_CR1_TIE_M);
    }
    else
    {
        CLEAR_BIT(stim->CR2.WORDVAL, STIM_CR2_TIE_M);
    }
}

/**
  * \brief  Enables the specified STIMx peripheral RunInDebug function.
  * \param  stim    STIM pointer to a STIM_TypeDef structure
  *                  - STIM1: STIM1 base address index
  *                  - STIM2: STIM2 base address index
  *                  - STIM3: STIM3 base address index
  */
static inline void STIM_enableRunInDebug (STIM_TypeDef *stim)
{
    CLEAR_BIT(stim->MCR.WORDVAL, STIM_MCR_FRZ_M);
}

/**
  * \brief  Disables the specified STIMx peripheral RunInDebug function.
  * \param  stim    STIM pointer to a STIM_TypeDef structure
  *                  - STIM1: STIM1 base address index
  *                  - STIM2: STIM2 base address index
  *                  - STIM3: STIM3 base address index
  */
static inline void STIM_disableRunInDebug (STIM_TypeDef *stim)
{
    SET_BIT(stim->MCR.WORDVAL, STIM_MCR_FRZ_M);
}

/**
  * \brief  Set load value, which will restart counter from new value instantly.
  * \param  stim        STIM pointer to a STIM_TypeDef structure
  *                      - STIM1: STIM1 base address index
  *                      - STIM2: STIM2 base address index
  *                      - STIM3: STIM3 base address index
  * \param  Chn         STIM Channel Number.
  *                      This parameter can be any value of @ref STIM_CHANNEL
  * \param  loadValue   STIM Channel Load Value.
  *                      - uint32_t
  */
static inline void STIM_setLoadValue (STIM_TypeDef *stim, STIM_Channel Chn, uint32_t loadValue)
{
    if (Chn == STIM_CHN1)
    {
        WRITE_REG(stim->ARR1.WORDVAL, loadValue);
    }
    else
    {
        WRITE_REG(stim->ARR2.WORDVAL, loadValue);
    }
}

/**
  * \brief  Gets STIM Channelx int flag status.
  * \param  stim    STIM pointer to a STIM_TypeDef structure
  *                  - STIM1: STIM1 base address index
  *                  - STIM2: STIM2 base address index
  *                  - STIM3: STIM3 base address index
  * \param  Chn     STIM Channel Number.
  *                  This parameter can be any value of @ref STIM_CHANNEL
  * \return Returns Channelx Interrupt flag
  *                  - false: The Channelx flag is not set.
  *                  - true : The Channelx flag is set.
  */
static inline bool STIM_getFlag (STIM_TypeDef *stim, STIM_Channel Chn)
{
    uint32_t status = 0UL;
    if (Chn == STIM_CHN1)
    {
        status = READ_BIT(stim->SR1.WORDVAL, STIM_SR1_TIF_M);
    }
    else
    {
        status = READ_BIT(stim->SR2.WORDVAL, STIM_SR2_TIF_M);
    }
    return (bool)status;
}

/**
  * \brief  Clear STIM Channelx int flag status.
  * \param  stim    STIM pointer to a STIM_TypeDef structure
  *                  - STIM1: STIM1 base address index
  *                  - STIM2: STIM2 base address index
  *                  - STIM3: STIM3 base address index
  * \param  Chn     STIM Channel Number.
  *                  This parameter can be any value of @ref STIM_CHANNEL
  */
static inline void STIM_clearFlag (STIM_TypeDef *stim, STIM_Channel Chn)
{
    if (Chn == STIM_CHN1)
    {
        SET_BIT(stim->SR1.WORDVAL, STIM_SR1_TIF_M);
    }
    else
    {
        SET_BIT(stim->SR2.WORDVAL, STIM_SR2_TIF_M);
    }
}

/**
  * \brief  Gets the STIM Channelx current count number.
  * \param  stim    STIM pointer to a STIM_TypeDef structure
  *                  - STIM1: STIM1 base address index
  *                  - STIM2: STIM2 base address index
  *                  - STIM3: STIM3 base address index
  * \param  Chn     STIM Channel Number.
  *                  This parameter can be any value of @ref STIM_CHANNEL
  * \return Returns STIM current count number.
  */
static inline uint32_t STIM_getTimerCount (STIM_TypeDef *stim, STIM_Channel Chn)
{
    if (Chn == STIM_CHN1)
    {
        return stim->CNT1.WORDVAL;
    }
    else
    {
        return stim->CNT2.WORDVAL;
    }
}

/**
  * \brief  Gets the STIM current LifetimeTimerCount number @STIM_Cascade Mode
  * \param  stim    STIM pointer to a STIM_TypeDef structure
  *                  - STIM1: STIM1 base address index
  *                  - STIM2: STIM2 base address index
  *                  - STIM3: STIM3 base address index
  * \return Returns STIM current LifetimeTimerCount number.
  */
static inline uint64_t STIM_getLT64TimerCount (STIM_TypeDef *stim)
{
    return (((uint64_t)(stim->CNT64H.WORDVAL) << 32U) + (uint64_t)(stim->CNT64L.WORDVAL));
}

/**
  * \brief  Sets the STIMx MODE.
  * \param  stim        STIM pointer to a STIM_TypeDef structure
  *                      - STIM1: STIM1 base address index
  *                      - STIM2: STIM2 base address index
  *                      - STIM3: STIM3 base address index
  * \param  cntMode     the STIMx MODE.
  *                      This parameter can be any value of @ref STIM_MODE
  */
 static inline void STIM_setMode (STIM_TypeDef *stim, STIM_Mode cntMode)
{
    MODIFY_REG(stim->CR2.WORDVAL, STIM_CR2_CHN_M, cntMode);
}

/**
  * \brief  Configure the STIM time base unit.
  * \param  stim            STIM pointer to a STIM_TypeDef structure
  *                          - STIM1: STIM1 base address index
  *                          - STIM2: STIM2 base address index
  *                          - STIM3: STIM3 base address index
  * \param  cntMode         the STIMx MODE.
  *                          This parameter can be any value of @ref STIM_MODE
  * \param  ch1LoadValue    STIM Channel1 Load Value.
  *                          - uint32_t
  * \param  ch2LoadValue    STIM Channel2 Load Value.
  *                          - uint32_t
  */
extern void STIM_configModule (STIM_TypeDef *stim, STIM_Mode cntMode, uint32_t ch1LoadValue, uint32_t ch2LoadValue);


#ifdef __cplusplus
}
#endif


#endif /* __STIM_H__ */
