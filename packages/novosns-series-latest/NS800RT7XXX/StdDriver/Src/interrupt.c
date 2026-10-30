
/**
  * @file       interrupt.c
  * @author     Alex-J, Haven-X
  * @brief      Interrupt API for NS800RTxxx driver.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */

#include "interrupt.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/
__attribute__((section (".vt_dtcm"))) volatile uint32_t vectorTableDTCM[VECTOR_SIZE]; 


/*******************************************************************************
 * Functions
 ******************************************************************************/

/**
 * @brief  The default interrupt handler.
 * @note   This function is used as the default handler for all interrupts 
 *         after the vector table is initialized.
 */
void Interrupt_defaultHandler (void)
{
    uint32_t irq_number = __get_IPSR() - 16;

    printf("Unhandled IRQ: %d", irq_number);
    __asm("BKPT #0");

    while (1)
    {
        ;
    }
}

/**
 * @brief  Interrupt_initModule.
 */
void Interrupt_initModule (void)
{
    (void)Interrupt_disableGlobal();

    uint8_t irqn;

    for (irqn = WWDG_IRQn; irqn <= EXTI_TXEV_IRQn; irqn++)
    {
        NVIC_ClearPendingIRQ((IRQn_Type)irqn);
    }
}

/**
 * @brief  Interrupt_initVectorTable.
 */
void Interrupt_initVectorTable (void)
{
    uint32_t n;
    uint32_t *vector_table_flash = (uint32_t *)(SCB->VTOR);
    
    for (n = 0; n < NVIC_USER_IRQ_OFFSET; n++) {
        vectorTableDTCM[n] = vector_table_flash[n];
    }

    SCB->VTOR = (uint32_t)vectorTableDTCM;
    __DSB();
    __ISB();
    
    for (n = NVIC_USER_IRQ_OFFSET; n < VECTOR_SIZE; n++)
    {
        vectorTableDTCM[n] = (uint32_t)&Interrupt_defaultHandler;
    }
}

/**
 * @brief  Interrupt_enable.
 * 
 * @param  IRQn  specifies the interrupt.
 */
void Interrupt_enable (IRQn_Type IRQn)
{
    bool intsDisabled;

    intsDisabled = Interrupt_disableGlobal();

    NVIC_EnableIRQ(IRQn);

    if (intsDisabled)
    {
        (void)Interrupt_enableGlobal();
    }
}

/**
 * @brief  Interrupt_disable.
 * 
 * @param  IRQn  specifies the interrupt.
 */
void Interrupt_disable (IRQn_Type IRQn)
{
    bool intsDisabled;

    intsDisabled = Interrupt_disableGlobal();

    NVIC_DisableIRQ(IRQn);

    if (intsDisabled)
    {
        (void)Interrupt_enableGlobal();
    }
}
