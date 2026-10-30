/*
 * SPDX-License-Identifier: Apache-2.0
 * NS800RT7P65D Cortex-M7 CPU port declarations.
 */
#ifndef NS800RT_CPUPORT_H__
#define NS800RT_CPUPORT_H__

#include <rtcompiler.h>

#ifdef RT_USING_SMP
typedef union
{
    unsigned long slock;
    struct
    {
        unsigned short owner;
        unsigned short next;
    } tickets;
} rt_hw_spinlock_t;
#endif

rt_inline void rt_hw_isb(void)
{
    __asm volatile ("isb 0xf" ::: "memory");
}

rt_inline void rt_hw_dmb(void)
{
    __asm volatile ("dmb 0xf" ::: "memory");
}

rt_inline void rt_hw_dsb(void)
{
    __asm volatile ("dsb 0xf" ::: "memory");
}

#endif
