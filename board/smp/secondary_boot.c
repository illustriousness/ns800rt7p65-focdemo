#include <stdint.h>

#include "NS800RTxxxx.h"

#define NS800_CPU2_BOOT_MAGIC       0x534d5032UL
#define NS800_CPU2_BOOT_MAILBOX     0x2013ff00UL

struct ns800_cpu2_boot_mailbox
{
    volatile uint32_t magic;
    volatile uint32_t entry;
};

/* The CPU2 bootstrap has no C library state or constructors to initialize. */
void __libc_init_array(void)
{
}

void entry(void)
{
    volatile struct ns800_cpu2_boot_mailbox *mailbox =
        (volatile struct ns800_cpu2_boot_mailbox *)NS800_CPU2_BOOT_MAILBOX;
    void (*secondary_start)(void);

    __disable_irq();
    if ((SCB->CCR & SCB_CCR_DC_Msk) != 0U)
    {
        SCB_DisableDCache();
    }
    SCB->VTOR = 0x08000000UL;
    __DSB();
    __ISB();

    while (mailbox->magic != NS800_CPU2_BOOT_MAGIC)
    {
        __WFE();
    }

    __DMB();
    secondary_start = (void (*)(void))(uintptr_t)mailbox->entry;
    secondary_start();

    while (1)
    {
        __WFI();
    }
}
