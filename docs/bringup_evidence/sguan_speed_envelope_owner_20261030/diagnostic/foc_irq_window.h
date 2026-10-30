#ifndef NS800_FOC_IRQ_WINDOW_H
#define NS800_FOC_IRQ_WINDOW_H

#include <stdint.h>

/* Only for lock-free wait regions with no kernel calls/shared writes.
 * Registration guarantees priority zero is exclusively the kernel-free FOC
 * ADC ISR on CPU0. All priorities >=1 stay masked while waiting. */
static inline uint32_t ns800_foc_irq_window_open(unsigned allowed)
{
    if (!allowed || !__get_PRIMASK()) return UINT32_MAX;
    uint32_t previous = __get_BASEPRI();
    __set_BASEPRI_MAX(1UL << (8U-__NVIC_PRIO_BITS));
    __DSB();
    __ISB();
    __enable_irq();
    return previous;
}

static inline void ns800_foc_irq_window_close(uint32_t previous)
{
    if (previous == UINT32_MAX) return;
    __disable_irq();
    __set_BASEPRI(previous);
    __DSB();
    __ISB();
}

#endif
