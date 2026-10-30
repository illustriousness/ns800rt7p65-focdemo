/*
 * Copyright (c) 2006-2026, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author           Notes
 * 2026-05-06     Jiawei.Deng      first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

/* defined the LED1 pin: GPIO_68 = PC4 */
#define LED1_PIN    PIN_NUM(GPIO_68)

#define SMP_WORKER_COUNT        2
#define SMP_WORKER_STACK_SIZE   512
#define SMP_WORKER_PRIORITY     20
#define SMP_STRESS_ROUNDS       300U

static struct rt_thread smp_worker[SMP_WORKER_COUNT];
static rt_uint8_t smp_worker_stack[SMP_WORKER_COUNT][SMP_WORKER_STACK_SIZE];
static struct rt_spinlock smp_counter_lock;
static volatile rt_uint32_t smp_worker_count[SMP_WORKER_COUNT];
static volatile rt_uint32_t smp_worker_core_mask[SMP_WORKER_COUNT];
static volatile rt_uint32_t smp_shared_count;
static struct rt_semaphore smp_worker_trigger[SMP_WORKER_COUNT];
static rt_uint32_t smp_worker_busy[SMP_WORKER_COUNT];

extern volatile rt_uint32_t g_ns800_smp_secondary_ready;
extern volatile rt_uint32_t g_ns800_smp_ipi_count[SMP_WORKER_COUNT];

static void smp_worker_entry(void *parameter)
{
    rt_ubase_t worker = (rt_ubase_t)parameter;
    smp_worker_core_mask[worker] = 1UL << (rt_uint32_t)rt_hw_cpu_id();

    while (1)
    {
        /* No periodic diagnostic workload on CPU0 during motor control.
         * Explicit 'smp stress' runs a bounded three-second lock test. */
        rt_sem_take(&smp_worker_trigger[worker], RT_WAITING_FOREVER);
        for (unsigned i = 0; i < SMP_STRESS_ROUNDS; ++i)
        {
            int cpu = rt_hw_cpu_id();

            smp_worker_count[worker]++;
            smp_worker_core_mask[worker] |= 1UL << (rt_uint32_t)cpu;

            rt_spin_lock(&smp_counter_lock);
            smp_shared_count++;
            rt_spin_unlock(&smp_counter_lock);

            rt_thread_mdelay(10);
        }
        __atomic_store_n(&smp_worker_busy[worker], 0, __ATOMIC_RELEASE);
    }
}

static int smp(int argc, char **argv)
{
    if (argc == 2 && !rt_strcmp(argv[1], "stress"))
    {
        for (unsigned i = 0; i < SMP_WORKER_COUNT; ++i)
            if (__atomic_load_n(&smp_worker_busy[i], __ATOMIC_ACQUIRE)) return -RT_EBUSY;
        for (unsigned i = 0; i < SMP_WORKER_COUNT; ++i)
        {
            __atomic_store_n(&smp_worker_busy[i], 1, __ATOMIC_RELEASE);
            rt_sem_release(&smp_worker_trigger[i]);
        }
        rt_kprintf("SMP stress: 3 seconds; run only with motor stopped\n");
    }
    else if (argc != 1) return -RT_EINVAL;

    rt_kprintf("smp ready=%08x cpu0=%u mask0=%x cpu1=%u mask1=%x "
               "shared=%u ipi0=%u ipi1=%u shell_cpu=%d\n",
               (unsigned int)g_ns800_smp_secondary_ready,
               (unsigned int)smp_worker_count[0],
               (unsigned int)smp_worker_core_mask[0],
               (unsigned int)smp_worker_count[1],
               (unsigned int)smp_worker_core_mask[1],
               (unsigned int)smp_shared_count,
               (unsigned int)g_ns800_smp_ipi_count[0],
               (unsigned int)g_ns800_smp_ipi_count[1],
               rt_hw_cpu_id());

    return 0;
}
MSH_CMD_EXPORT(smp, show NS800 dual-core SMP status);

static int resetinfo(int argc, char **argv)
{
    RT_UNUSED(argc);
    RT_UNUSED(argv);
    rt_kprintf("boot reset sys=%08x cpu1=%08x cpu2=%08x\n",
               (unsigned)g_ns800_boot_reset_status,
               (unsigned)g_ns800_boot_cpu1_reset_status,
               (unsigned)g_ns800_boot_cpu2_reset_status);
    return RT_EOK;
}
MSH_CMD_EXPORT(resetinfo, show captured boot reset causes);

int main(void)
{
    rt_ubase_t cpu;

    (void)rt_thread_control(rt_thread_self(), RT_THREAD_CTRL_BIND_CPU,
                            (void *)(rt_ubase_t)NS800_COMM_CPU);
    rt_spin_lock_init(&smp_counter_lock);

    for (cpu = 0; cpu < SMP_WORKER_COUNT; cpu++)
    {
        rt_err_t result = rt_sem_init(&smp_worker_trigger[cpu],
                                     cpu == 0 ? "cpu0test" : "cpu1test", 0, RT_IPC_FLAG_FIFO);
        RT_ASSERT(result == RT_EOK);
        result = rt_thread_init(&smp_worker[cpu],
                                cpu == 0U ? "cpu0w" : "cpu1w",
                                smp_worker_entry,
                                (void *)(rt_ubase_t)cpu,
                                smp_worker_stack[cpu],
                                sizeof(smp_worker_stack[cpu]),
                                SMP_WORKER_PRIORITY,
                                10);
        RT_ASSERT(result == RT_EOK);
        (void)rt_thread_control(&smp_worker[cpu], RT_THREAD_CTRL_BIND_CPU,
                                (void *)(rt_ubase_t)cpu);
        rt_thread_startup(&smp_worker[cpu]);
    }

    rt_kprintf("NS800RT7P65 RT-Thread full BSP + SMP\n");
    resetinfo(0, RT_NULL);
    rt_kprintf("CANopen/CiA402 controls REAL FOC; startup is idle, cyclic RPDO enable required.\n");
    rt_kprintf("CANopen owns motor commands; local motor status/stop remain available.\n");

    rt_pin_mode(LED1_PIN, PIN_MODE_OUTPUT);

    while (1)
    {
        rt_pin_write(LED1_PIN, PIN_HIGH);
        rt_thread_mdelay(1000);
        rt_pin_write(LED1_PIN, PIN_LOW);
        rt_thread_mdelay(1000);
    }
}
