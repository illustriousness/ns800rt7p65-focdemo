#include <rthw.h>
#include <rtthread.h>

#include "board.h"

#if defined(RT_USING_FINSH) && defined(RT_USING_HOOK)
#include <shell.h>

static void ns800_console_thread_bind(void)
{
    /* Bind before opening UART1: NVIC and writable vectors are per-core. */
    rt_err_t result = rt_thread_control(rt_thread_self(),
                                        RT_THREAD_CTRL_BIND_CPU,
                                        (void *)(rt_ubase_t)NS800_COMM_CPU);
    RT_ASSERT(result == RT_EOK);
}

static int ns800_console_smp_init(void)
{
    finsh_thread_entry_sethook(ns800_console_thread_bind);
    return RT_EOK;
}
INIT_PREV_EXPORT(ns800_console_smp_init);
#endif

#define NS800_CPU_COUNT             2U
#define NS800_CPU2_BOOT_MAGIC       0x534d5032UL
#define NS800_CPU2_BOOT_MAILBOX     0x2013ff00UL
#define NS800_CPU2_STARTING_MAGIC   0xc0200002UL
#define NS800_CPU2_READY_MAGIC      0xc020c020UL

struct ns800_smp_switch_context
{
    volatile rt_ubase_t flag;
    rt_ubase_t from;
    rt_ubase_t to;
    struct rt_thread *to_thread;
};

struct ns800_cpu2_boot_mailbox
{
    volatile rt_uint32_t magic;
    volatile rt_uint32_t entry;
};

struct ns800_smp_switch_context g_ns800_smp_switch[NS800_CPU_COUNT]
    __attribute__((aligned(32)));
volatile rt_uint32_t g_ns800_smp_secondary_ready;
volatile rt_uint32_t g_ns800_smp_ipi_count[NS800_CPU_COUNT];

extern volatile uint32_t SystemCoreClock;
void MU_IRQHandler(void);

static rt_base_t ns800_atomic_guard_lock(void)
{
    while (1)
    {
        rt_uint32_t backoff;
        rt_base_t level = rt_hw_local_irq_disable();
        uint8_t owner =
            (uint8_t)(MCM->CPUID.WORDVAL & MCM_CPUID_CPUID_M) + 1U;

        SEMA_lockGate(SEMA, SEMA_GATE_0);
        if (SEMA_getGateState(SEMA, SEMA_GATE_0) == owner)
        {
            __DMB();
            return level;
        }

        rt_hw_local_irq_enable(level);
        backoff = rt_hw_cpu_id() == 0 ? 8U : 16U;
        while (backoff-- != 0U)
        {
            __NOP();
        }
    }
}

static void ns800_atomic_guard_unlock(rt_base_t level)
{
    __DMB();
    SEMA_unlockGate(SEMA, SEMA_GATE_0);
    __DSB();
    rt_hw_local_irq_enable(level);
}

static void ns800_smp_ipi_init(void)
{
    Interrupt_register(MU_IRQn, MU_IRQHandler);

    MU_clearStatusRegister(MU, MU_SR_GIP0_M);
    MU_setControlRegister(MU, MU_CR_GIE0_M);
    NVIC_ClearPendingIRQ(MU_IRQn);
    NVIC_SetPriority(MU_IRQn, 15U);
    NVIC_EnableIRQ(MU_IRQn);
}

static void ns800_smp_irq_priority_init(void)
{
    int irqn;

    for (irqn = WWDG_IRQn; irqn <= EXTI_TXEV_IRQn; irqn++)
    {
        NVIC_SetPriority((IRQn_Type)irqn, 15U);
    }
}

static void ns800_smp_disable_dcache(void)
{
    if ((SCB->CCR & SCB_CCR_DC_Msk) != 0U)
    {
        SCB_DisableDCache();
    }
}

int rt_hw_cpu_id(void)
{
    uint32_t core = MCM->CPUID.WORDVAL & MCM_CPUID_CPUID_M;

    return core == MCM_CORE_2 ? 1 : 0;
}

rt_base_t rt_hw_local_irq_disable(void)
{
    rt_base_t level = (rt_base_t)__get_PRIMASK();

    __disable_irq();
    __DMB();
    return level;
}

void rt_hw_local_irq_enable(rt_base_t level)
{
    __DMB();
    __set_PRIMASK((uint32_t)level);
}

rt_bool_t rt_hw_interrupt_is_disabled(void)
{
    return __get_PRIMASK() != 0U ? RT_TRUE : RT_FALSE;
}

void rt_hw_spin_lock_init(rt_hw_spinlock_t *lock)
{
    lock->slock = 0UL;
    __DMB();
}

void rt_hw_spin_lock(rt_hw_spinlock_t *lock)
{
    unsigned long owner = (unsigned long)rt_hw_cpu_id() + 1UL;

    while (1)
    {
        rt_base_t level = ns800_atomic_guard_lock();

        if (lock->slock == 0UL)
        {
            lock->slock = owner;
            ns800_atomic_guard_unlock(level);
            return;
        }

        ns800_atomic_guard_unlock(level);
        while (*(volatile unsigned long *)&lock->slock != 0UL)
        {
            __NOP();
        }
        __DMB();
    }
}

void rt_hw_spin_unlock(rt_hw_spinlock_t *lock)
{
    rt_base_t level;

    level = ns800_atomic_guard_lock();

    lock->slock = 0UL;
    ns800_atomic_guard_unlock(level);
    __SEV();
}

rt_atomic_t rt_hw_atomic_load(volatile rt_atomic_t *ptr)
{
    rt_base_t level = ns800_atomic_guard_lock();
    rt_atomic_t value = *ptr;
    ns800_atomic_guard_unlock(level);
    return value;
}

void rt_hw_atomic_store(volatile rt_atomic_t *ptr, rt_atomic_t value)
{
    rt_base_t level = ns800_atomic_guard_lock();
    *ptr = value;
    ns800_atomic_guard_unlock(level);
}

rt_atomic8_t rt_hw_atomic_load8(volatile rt_atomic8_t *ptr)
{
    rt_base_t level = ns800_atomic_guard_lock();
    rt_atomic8_t value = *ptr;
    ns800_atomic_guard_unlock(level);
    return value;
}

void rt_hw_atomic_store8(volatile rt_atomic8_t *ptr, rt_atomic8_t value)
{
    rt_base_t level = ns800_atomic_guard_lock();
    *ptr = value;
    ns800_atomic_guard_unlock(level);
}

rt_atomic16_t rt_hw_atomic_load16(volatile rt_atomic16_t *ptr)
{
    rt_base_t level = ns800_atomic_guard_lock();
    rt_atomic16_t value = *ptr;
    ns800_atomic_guard_unlock(level);
    return value;
}

void rt_hw_atomic_store16(volatile rt_atomic16_t *ptr, rt_atomic16_t value)
{
    rt_base_t level = ns800_atomic_guard_lock();
    *ptr = value;
    ns800_atomic_guard_unlock(level);
}

#define NS800_ATOMIC_FETCH_OP(name, type, operation)                         \
type name(volatile type *ptr, type value)                                    \
{                                                                             \
    rt_base_t level = ns800_atomic_guard_lock();                              \
    type old_value = *ptr;                                                    \
    *ptr = (type)(old_value operation value);                                 \
    ns800_atomic_guard_unlock(level);                                         \
    return old_value;                                                         \
}

NS800_ATOMIC_FETCH_OP(rt_hw_atomic_add, rt_atomic_t, +)
NS800_ATOMIC_FETCH_OP(rt_hw_atomic_sub, rt_atomic_t, -)
NS800_ATOMIC_FETCH_OP(rt_hw_atomic_and, rt_atomic_t, &)
NS800_ATOMIC_FETCH_OP(rt_hw_atomic_or, rt_atomic_t, |)
NS800_ATOMIC_FETCH_OP(rt_hw_atomic_xor, rt_atomic_t, ^)
NS800_ATOMIC_FETCH_OP(rt_hw_atomic_and8, rt_atomic8_t, &)
NS800_ATOMIC_FETCH_OP(rt_hw_atomic_or8, rt_atomic8_t, |)
NS800_ATOMIC_FETCH_OP(rt_hw_atomic_and16, rt_atomic16_t, &)
NS800_ATOMIC_FETCH_OP(rt_hw_atomic_or16, rt_atomic16_t, |)

rt_atomic_t rt_hw_atomic_exchange(volatile rt_atomic_t *ptr, rt_atomic_t value)
{
    rt_base_t level = ns800_atomic_guard_lock();
    rt_atomic_t old_value = *ptr;
    *ptr = value;
    ns800_atomic_guard_unlock(level);
    return old_value;
}

void rt_hw_atomic_flag_clear(volatile rt_atomic_t *ptr)
{
    rt_hw_atomic_store(ptr, 0);
}

rt_atomic_t rt_hw_atomic_flag_test_and_set(volatile rt_atomic_t *ptr)
{
    return rt_hw_atomic_exchange(ptr, 1);
}

rt_atomic_t rt_hw_atomic_compare_exchange_strong(volatile rt_atomic_t *ptr,
                                                  rt_atomic_t *expected,
                                                  rt_atomic_t desired)
{
    rt_base_t level = ns800_atomic_guard_lock();
    rt_atomic_t old_value = *ptr;
    rt_atomic_t exchanged = old_value == *expected;

    if (exchanged)
    {
        *ptr = desired;
    }
    else
    {
        *expected = old_value;
    }

    ns800_atomic_guard_unlock(level);
    return exchanged;
}

static void ns800_smp_request_switch(rt_ubase_t from,
                                     rt_ubase_t to,
                                     struct rt_thread *to_thread)
{
    struct ns800_smp_switch_context *context =
        &g_ns800_smp_switch[rt_hw_cpu_id()];

    if (context->flag == 0U)
    {
        context->from = from;
    }
    context->to = to;
    context->to_thread = to_thread;
    __DMB();
    context->flag = 1U;
    __DMB();
    SCB->ICSR = SCB_ICSR_PENDSVSET_Msk;
}

void rt_hw_context_switch(rt_ubase_t from,
                          rt_ubase_t to,
                          struct rt_thread *to_thread)
{
    ns800_smp_request_switch(from, to, to_thread);
}

void rt_hw_context_switch_interrupt(void *context,
                                    rt_ubase_t from,
                                    rt_ubase_t to,
                                    struct rt_thread *to_thread)
{
    RT_UNUSED(context);
    ns800_smp_request_switch(from, to, to_thread);
}

void rt_hw_context_switch_to(rt_ubase_t to, struct rt_thread *to_thread)
{
    NVIC_SetPriority(PendSV_IRQn, 15U);
    NVIC_SetPriority(SysTick_IRQn, 15U);
    ns800_smp_request_switch(0U, to, to_thread);
    __DSB();
    __enable_irq();
    __ISB();

    while (1)
    {
        __WFI();
    }
}

void rt_hw_ipi_send(int ipi_vector, unsigned int cpu_mask)
{
    unsigned int self_mask = 1UL << (unsigned int)rt_hw_cpu_id();

    RT_UNUSED(ipi_vector);
    __DMB();

    if ((cpu_mask & ~self_mask & RT_CPU_MASK) != 0U)
    {
        MU_setControlRegister(MU, MU_CR_GIR0_M);
    }

    if ((cpu_mask & self_mask) != 0U)
    {
        SCB->ICSR = SCB_ICSR_PENDSVSET_Msk;
    }
}

void MU_IRQHandler(void)
{
    rt_interrupt_enter();

    if ((MU_getStatusRegister(MU) & MU_SR_GIP0_M) != 0U)
    {
        MU_clearStatusRegister(MU, MU_SR_GIP0_M);
        g_ns800_smp_ipi_count[rt_hw_cpu_id()]++;
        rt_scheduler_ipi_handler(RT_SCHEDULE_IPI, RT_NULL);
    }

    rt_interrupt_leave();
    rt_scheduler_do_irq_switch(RT_NULL);
    __DSB();
}

void ns800_smp_primary_init(void)
{
    ns800_smp_disable_dcache();
    ns800_smp_irq_priority_init();
    ns800_smp_ipi_init();
}

void ns800_smp_secondary_start(void)
{
    ns800_smp_disable_dcache();
    SCB->VTOR = 0x08000000UL;
    __DSB();
    __ISB();
    /* DTCM and VTOR are private on each M7. Copy the common system vectors,
     * then install CPU1's own MU/UART/CAN handlers into its writable table.
     * Never write dynamic vectors into the common Flash table. */
    Interrupt_initVectorTable();

    NVIC_SetPriority(PendSV_IRQn, 15U);
    NVIC_SetPriority(SysTick_IRQn, 15U);
    (void)SysTick_Config(SystemCoreClock / RT_TICK_PER_SECOND);
    ns800_smp_irq_priority_init();
    ns800_smp_ipi_init();

    g_ns800_smp_secondary_ready = NS800_CPU2_STARTING_MAGIC;
    __DMB();

    rt_hw_spin_lock(&_cpus_lock);
    rt_system_scheduler_start();

    while (1)
    {
        __WFI();
    }
}

void ns800_smp_context_switch_complete(void)
{
    int cpu = rt_hw_cpu_id();

    if ((cpu == 1) &&
        (g_ns800_smp_secondary_ready == NS800_CPU2_STARTING_MAGIC))
    {
        __DMB();
        g_ns800_smp_secondary_ready = NS800_CPU2_READY_MAGIC;
        __DMB();
        __SEV();
    }
}

void rt_hw_secondary_cpu_up(void)
{
    volatile struct ns800_cpu2_boot_mailbox *mailbox =
        (volatile struct ns800_cpu2_boot_mailbox *)NS800_CPU2_BOOT_MAILBOX;
    rt_base_t level;
    rt_uint32_t timeout = 40000000UL;

    /* Scheduler is not running yet: rt_thread_mdelay() would assert because
     * there is no current thread.  Keep the recovery window as a pure
     * startup busy wait instead. */
    for (volatile rt_uint32_t delay = 0; delay < 2500000UL; delay++)
    {
        __NOP();
    }

    level = rt_hw_local_irq_disable();
    g_ns800_smp_secondary_ready = 0U;
    mailbox->entry = (rt_uint32_t)(rt_ubase_t)ns800_smp_secondary_start;
    __DMB();
    mailbox->magic = NS800_CPU2_BOOT_MAGIC;
    __DMB();

    SYSCON_UNLOCK;
    SYSCON_releaseCore2(SYSCON);
    SYSCON_LOCK;

    /* CPU0 still holds _cpus_lock here. CPU2 cannot complete its first
     * context switch until CPU0 starts the scheduler and releases that lock.
     * Wait for the secondary entry handshake, not scheduler completion. */
    while ((g_ns800_smp_secondary_ready != NS800_CPU2_STARTING_MAGIC) &&
           (g_ns800_smp_secondary_ready != NS800_CPU2_READY_MAGIC) &&
           (timeout-- != 0U))
    {
        __NOP();
    }
    rt_hw_local_irq_enable(level);

    if ((g_ns800_smp_secondary_ready == NS800_CPU2_STARTING_MAGIC) ||
        (g_ns800_smp_secondary_ready == NS800_CPU2_READY_MAGIC))
    {
        rt_kprintf("[smp] CPU2 boot ready\n");
    }
    else
    {
        rt_kprintf("[smp] CPU2 startup timeout\n");
    }
}

void rt_hw_secondary_cpu_idle_exec(void)
{
    __NOP();
}
