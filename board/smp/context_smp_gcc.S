/*
 * Copyright (c) 2006-2026, RT-Thread Development Team
 * SPDX-License-Identifier: Apache-2.0
 *
 * Cortex-M7 SMP PendSV port for NS800RT7P65D.
 */

    .cpu cortex-m7
    .syntax unified
    .thumb
    .text

    .equ MCM_CPUID, 0xE0080000

    .global PendSV_Handler
    .type PendSV_Handler, %function
PendSV_Handler:
    mrs     r2, PRIMASK
    cpsid   i

    /* MCM CPUID is 1 for CPU1 and 2 for CPU2. */
    ldr     r0, =MCM_CPUID
    ldr     r1, [r0]
    ands    r1, r1, #3
    subs    r1, r1, #1
    lsls    r1, r1, #4
    ldr     r3, =g_ns800_smp_switch
    add     r3, r3, r1

    ldr     r1, [r3, #0]
    cbz     r1, pendsv_exit
    movs    r1, #0
    str     r1, [r3, #0]

    /* Save the old thread's callee-saved registers. */
    ldr     r0, [r3, #4]
    cbz     r0, switch_to_thread
    mrs     r1, PSP

#if defined(__VFP_FP__) && !defined(__SOFTFP__)
    tst     lr, #0x10
    it      eq
    vstmdbeq r1!, {d8-d15}
#endif

    stmdb   r1!, {r4-r11}

#if defined(__VFP_FP__) && !defined(__SOFTFP__)
    mov     r12, #0
    tst     lr, #0x10
    it      eq
    moveq   r12, #1
    stmdb   r1!, {r12}
#endif

    str     r1, [r0]

switch_to_thread:
    /* Restore the selected thread's callee-saved registers. */
    ldr     r1, [r3, #8]
    ldr     r1, [r1]

#if defined(__VFP_FP__) && !defined(__SOFTFP__)
    ldmia   r1!, {r12}
#endif

    ldmia   r1!, {r4-r11}

#if defined(__VFP_FP__) && !defined(__SOFTFP__)
    cmp     r12, #0
    it      ne
    vldmiane r1!, {d8-d15}
#endif

    msr     PSP, r1

#if defined(__VFP_FP__) && !defined(__SOFTFP__)
    orr     lr, lr, #0x10
    cmp     r12, #0
    it      ne
    bicne   lr, lr, #0x10
#endif

    /* Complete RT-Thread's per-CPU scheduler handoff. */
    push    {r2, lr}
    ldr     r0, [r3, #12]
    bl      rt_cpus_lock_status_restore
    bl      ns800_smp_context_switch_complete
    pop     {r2, lr}

pendsv_exit:
    msr     PRIMASK, r2
    /* Thread mode must use PSP; nested exceptions must return to MSP first. */
    tst     lr, #8
    it      ne
    orrne   lr, lr, #4
    bx      lr

    .size PendSV_Handler, . - PendSV_Handler

    .global HardFault_Handler
    .type HardFault_Handler, %function
HardFault_Handler:
    mrs     r0, MSP
    tst     lr, #4
    beq     hardfault_sp_ready
    mrs     r0, PSP

hardfault_sp_ready:
    stmdb   r0!, {r4-r11}
#if defined(__VFP_FP__) && !defined(__SOFTFP__)
    stmdb   r0!, {lr}
#endif
    stmdb   r0!, {lr}

    tst     lr, #4
    beq     hardfault_update_msp
    msr     PSP, r0
    b       hardfault_call

hardfault_update_msp:
    msr     MSP, r0

hardfault_call:
    push    {lr}
    bl      rt_hw_hard_fault_exception
    pop     {lr}
    orr     lr, lr, #4
    bx      lr

    .global rt_hw_interrupt_check
    .type rt_hw_interrupt_check, %function
rt_hw_interrupt_check:
    mrs     r0, IPSR
    bx      lr

    .global rt_hw_interrupt_thread_switch
    .type rt_hw_interrupt_thread_switch, %function
rt_hw_interrupt_thread_switch:
    bx      lr
