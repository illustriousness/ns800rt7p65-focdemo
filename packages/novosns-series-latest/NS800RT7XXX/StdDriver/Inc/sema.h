/**
  * @file       sema.h
  * @author     Alex-J
  * @brief      Header file for NS800RT7xxx SEMA module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __SEMA_H__
#define __SEMA_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/** @defgroup SEMA_EXPORTED_TYPES SEMA Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'SEMA' module.
  */

/** @defgroup SEMA_GATENUM SEMA Module's Gate Number
  * @{
  * @brief  Values are used to select the gate index number
  *         of the SEMA.
  */
typedef enum {
    SEMA_GATE_3 = 0U,    /*!< Gate 3 Index */
    SEMA_GATE_2,         /*!< Gate 2 Index */
    SEMA_GATE_1,         /*!< Gate 1 Index */
    SEMA_GATE_0,         /*!< Gate 0 Index */
    SEMA_GATE_7,         /*!< Gate 7 Index */
    SEMA_GATE_6,         /*!< Gate 6 Index */
    SEMA_GATE_5,         /*!< Gate 5 Index */
    SEMA_GATE_4,         /*!< Gate 4 Index */
    SEMA_GATE_11,        /*!< Gate 11 Index */
    SEMA_GATE_10,        /*!< Gate 10 Index */
    SEMA_GATE_9,         /*!< Gate 9 Index */
    SEMA_GATE_8,         /*!< Gate 8 Index */
    SEMA_GATE_15,        /*!< Gate 15 Index */
    SEMA_GATE_14,        /*!< Gate 14 Index */
    SEMA_GATE_13,        /*!< Gate 13 Index */
    SEMA_GATE_12         /*!< Gate 12 Index */
} SEMA_GateNum;

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
 * \brief  Lock Gate via the SEMA_GATEx Register.
 * \note   This function locks the gate via the SEMA_GATEx Register.
 *           (x = 0~15)
 * \param  sema       sema pointer to a SEMA_TypeDef structure
 *                      - SEMA: SEMA base address index
 * \param  gateNum    a value that index of gate 
 */
static inline void SEMA_lockGate (SEMA_TypeDef *sema, SEMA_GateNum gateNum)
{
    uint8_t lockVal           = (uint8_t)READ_BIT(MCM->CPUID.WORDVAL, 0x3) + 1;
    volatile uint8_t *regAddr = (volatile uint8_t *)(&sema->GATE3.reg + gateNum);

    WRITE_REG(TYPE8(regAddr), lockVal);
}

/**
 * \brief  Unlock Gate via the SEMA_GATEx Register.
 * \note   This function unlocks the gate via the SEMA_GATEx Register.
 *           (x = 0~15)
 * \param  sema       sema pointer to a SEMA_TypeDef structure
 *                      - SEMA: SEMA base address index
 * \param  gateNum    a value that index of gate 
 */
static inline void SEMA_unlockGate (SEMA_TypeDef *sema, SEMA_GateNum gateNum)
{
    volatile uint8_t *regAddr = (volatile uint8_t *)(&sema->GATE3.reg + gateNum);

    WRITE_REG(TYPE8(regAddr), 0x0);
}

/**
 * \brief  Get the Gate State via the SEMA_GATEx Register.
 * \note   This function gets the gate state via the SEMA_GATEx Register.
 *           (x = 0~15)
 * \param  sema       sema pointer to a SEMA_TypeDef structure
 *                      - SEMA: SEMA base address index
 * \param  gateNum    a value that index of gate 
 * 
 * \return Returns the gate state.
 */
static inline uint8_t SEMA_getGateState (SEMA_TypeDef *sema, SEMA_GateNum gateNum)
{
    volatile uint8_t *regAddr = (volatile uint8_t *)(&sema->GATE3.reg + gateNum);

    return ((uint8_t)TYPE8(regAddr));
}

/**
 * \brief  Get the Reset Gate State via the SEMA_RSTGT_R Register.
 * \note   This function gets the reset gate state via the SEMA_RSTGT_R Register.
 * \param  sema    sema pointer to a SEMA_TypeDef structure
 *                   - SEMA: SEMA base address index
 * 
 * \return Returns the reset gate state.
 */
static inline uint16_t SEMA_getResetGateRead (SEMA_TypeDef *sema)
{
    return (uint16_t)(sema->RSTGT_R.reg);
}

/**
 * \brief  Set Gate Write via the SEMA_RSTGT_W Register.
 * \note   This function sets the gate write via the SEMA_RSTGT_W Register.
 * \param  sema   sema pointer to a SEMA_TypeDef structure
 *                  - SEMA: SEMA base address index
 * \param  num    a value that the gate to be reset
 */
static inline void SEMA_setResetGateWrite (SEMA_TypeDef *sema, uint8_t num)
{
    WRITE_REG(sema->RSTGT_W.reg, 0xE2U << 8);
    __DSB();
    WRITE_REG(sema->RSTGT_W.reg, ((uint16_t)num | (0x1DU << 8)));
    __DSB();
}


#ifdef __cplusplus
}
#endif

#endif /* __SEMA_H__ */
