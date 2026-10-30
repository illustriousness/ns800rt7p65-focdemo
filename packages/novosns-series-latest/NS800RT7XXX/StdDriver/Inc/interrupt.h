/**
  * @file       interrupt.h
  * @author     Alex-J
  * @brief      Header file of interrupt.c
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */

#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__


#ifdef __cplusplus
extern "C"
{
#endif


#include <stdio.h>
#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define  VECTOR_SIZE     (NVIC_USER_IRQ_OFFSET + EXTI_TXEV_IRQn - WWDG_IRQn + 1)


/*******************************************************************************
 * Variables
 ******************************************************************************/
extern __attribute__((section (".vt_dtcm"))) volatile uint32_t vectorTableDTCM[VECTOR_SIZE]; 


/*******************************************************************************
 * Functions
 ******************************************************************************/

/**
 * \brief  The default interrupt handler.
 * \note   This function is used as the default handler for all interrupts 
 *         after the vector table is initialized.
 */
extern void Interrupt_defaultHandler (void);

/**
 * \brief   Enable global interrupts for the mcu.
 * \note    This functio enables the global interrupt in the mcu, 
 *          allowing the processor to respond to interrupts.
 * 
 * \return  Returns \b true if interrupts were enabled when the function was
 *          called or \b false if they were still disabled.
 */
static inline bool Interrupt_enableGlobal (void)
{
    __enable_irq();

    return (__get_PRIMASK() ? false : true);
}

/**
 * \brief   Disable global interrupts for the mcu.
 * \note    This functio disables the global interrupt in the mcu, 
 *          preventing the processor to respond to interrupts.
 * 
 * \return  Returns \b true if interrupts were disabled when the function was
 *          called or \b false if they were still enabled.
 */
static inline bool Interrupt_disableGlobal (void)
{
    __disable_irq();

    return (__get_PRIMASK() ? true : false);
}

/**
 * \brief  Registers a function to be called when an interrupt occurs.
 * \note   This function is used to specify the handler function to be called 
 *         when the given interrupt is asserted to the processor.
 * 
 * \param  IRQn     specifies the interrupt.
 * \param  handler  a pointer to the function to be called.
 */
static inline void Interrupt_register (IRQn_Type IRQn, void (*handler)(void))
{
    NVIC_SetVector(IRQn, (uint32_t)handler);
}

/**
 * \brief  Unregisters the function to be called when an interrupt occurs.
 * \note   This function is used to indicate that a default handler
 *         Interrupt_defaultHandler() should be called when the given interrupt is
 *         asserted to the processor.
 * 
 * \param  IRQn  specifies the interrupt.
 */
static inline void Interrupt_unregister (IRQn_Type IRQn)
{
    NVIC_SetVector(IRQn, (uint32_t)&Interrupt_defaultHandler);
}

/**
 * \brief  Interrupt_initModule.
 */
extern void Interrupt_initModule (void);

/**
 * \brief  Interrupt_initVectorTable.
 */
extern void Interrupt_initVectorTable (void);

/**
 * \brief  Interrupt_enable.
 * 
 * \param  IRQn  specifies the interrupt.
 */
extern void Interrupt_enable (IRQn_Type IRQn);

/**
 * \brief  Interrupt_disable.
 * 
 * \param  IRQn  specifies the interrupt.
 */
extern void Interrupt_disable (IRQn_Type IRQn);


#ifdef __cplusplus
}
#endif


#endif  /* __INTERRUPT_H__ */
