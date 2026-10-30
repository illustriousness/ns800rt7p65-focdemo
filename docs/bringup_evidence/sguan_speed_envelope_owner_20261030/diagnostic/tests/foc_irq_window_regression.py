#!/usr/bin/env python3
"""Exercise actual BSP lock waits with modeled PRIMASK/BASEPRI and FOC IRQs."""
from pathlib import Path
import re
import subprocess
import tempfile

root=Path(__file__).resolve().parents[1]
source=(root/'board/smp/smp_port.c').read_text()
def function(name):
    m=re.search(r'^(?:static )?(?:rt_base_t|void|int) '+name+r'\([^;]+?\)\n\{',source,re.M)
    assert m,name
    depth=1
    for end in range(m.end(),len(source)):
        depth+=(source[end]=='{')-(source[end]=='}')
        if not depth:return source[m.start():end+1]
    raise AssertionError(name)

prefix=r'''
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
typedef unsigned rt_base_t;
typedef uint32_t rt_uint32_t;
typedef int IRQn_Type;
typedef struct {unsigned long slock;} rt_hw_spinlock_t;
#define __NVIC_PRIO_BITS 4
#define NS800_CONTROL_CPU 0
#define RT_EINVAL 22
#define RT_EOK 0
#define WWDG_IRQn 0
#define EXTI_TXEV_IRQn 8
#define ADCA_CONV_IRQn 3
#define SEMA 0
#define SEMA_GATE_0 0
#define MCM_CPUID_CPUID_M 1
static struct {struct {uint32_t WORDVAL;} CPUID;} mcm;
#define MCM (&mcm)
static unsigned primask,basepri,cpu,nops,adc_calls,rt_calls,local_gate,gate,sema_fail;
static unsigned priorities[9],enabled[9];
static unsigned priority_group;
static volatile uint32_t ns800_kernel_free_irq_ready;
static rt_hw_spinlock_t *waiting;
static int rt_hw_cpu_id(void) {return cpu;}
static unsigned __get_PRIMASK(void) {return primask;}
static unsigned __get_BASEPRI(void) {return basepri;}
static void dispatch(void) {
    if(!primask) {
        assert(!local_gate);
        if(waiting)assert(waiting->slock!=cpu+1U);
        adc_calls++;
        if(!basepri || basepri>0x80) rt_calls++;
    }
}
static void __disable_irq(void) {primask=1;}
static void __enable_irq(void) {primask=0;dispatch();}
static void __set_BASEPRI(unsigned v) {basepri=v;}
static void __set_BASEPRI_MAX(unsigned v) {if(!basepri || v<basepri)basepri=v;}
#define __DMB() ((void)0)
#define __DSB() ((void)0)
#define __ISB() ((void)0)
static void __NOP(void) {nops++;dispatch();if(waiting && nops>4)waiting->slock=0;}
static unsigned NVIC_GetEnableIRQ(IRQn_Type n) {return enabled[n];}
static unsigned NVIC_GetPriority(IRQn_Type n) {return priorities[n];}
static unsigned NVIC_GetPriorityGrouping(void) {return priority_group;}
static rt_base_t rt_hw_local_irq_disable(void) {unsigned old=primask;primask=1;return old;}
static void rt_hw_local_irq_enable(rt_base_t v) {primask=v;}
static void SEMA_lockGate(int p,int g) {
    (void)p;(void)g;
    if(sema_fail) {sema_fail--;gate=cpu?1:2;local_gate=0;}
    else {gate=cpu+1;local_gate=1;}
}
static unsigned SEMA_getGateState(int p,int g) {(void)p;(void)g;return gate;}
static void SEMA_unlockGate(int p,int g) {(void)p;(void)g;gate=local_gate=0;}
static void __SEV(void) {}
#include "foc_irq_window.h"
'''
suffix=r'''
static void reset(void) {
    primask=1;basepri=cpu=nops=adc_calls=rt_calls=gate=local_gate=sema_fail=0;
    ns800_kernel_free_irq_ready=0;waiting=NULL;mcm.CPUID.WORDVAL=0;
    priority_group=0;
    for(unsigned n=0;n<9;n++){priorities[n]=15;enabled[n]=0;}
    enabled[ADCA_CONV_IRQn]=1;priorities[ADCA_CONV_IRQn]=0;
}
int main(void) {
    reset();
    uint32_t saved=ns800_foc_irq_window_open(0);
    assert(saved==UINT32_MAX && primask==1 && !adc_calls);ns800_foc_irq_window_close(saved);
    for(unsigned old=0;old<=0x80;old+=0x80) {
        reset();basepri=old;saved=ns800_foc_irq_window_open(1);
        assert(saved==old && !primask && basepri==0x10 && adc_calls==1 && !rt_calls);
        ns800_foc_irq_window_close(saved);assert(primask==1 && basepri==old);
    }
    reset();primask=0;saved=ns800_foc_irq_window_open(1);
    assert(saved==UINT32_MAX && !primask && !basepri);ns800_foc_irq_window_close(saved);assert(!primask);
    reset();assert(ns800_smp_register_kernel_free_irq(ADCA_CONV_IRQn)==0);
    reset();enabled[1]=1;priorities[1]=0;
    assert(ns800_smp_register_kernel_free_irq(ADCA_CONV_IRQn)==-RT_EINVAL && !ns800_kernel_free_irq_ready);
    reset();cpu=mcm.CPUID.WORDVAL=1;
    assert(ns800_smp_register_kernel_free_irq(ADCA_CONV_IRQn)==-RT_EINVAL);
    reset();priority_group=7;
    assert(ns800_smp_register_kernel_free_irq(ADCA_CONV_IRQn)==-RT_EINVAL && !ns800_kernel_free_irq_ready);
    reset();assert(ns800_smp_register_kernel_free_irq(ADCA_CONV_IRQn)==0);
    rt_hw_spinlock_t lock={2};waiting=&lock;
    rt_hw_spin_lock(&lock);
    assert(lock.slock==1 && primask==1 && basepri==0 && adc_calls && !rt_calls && !local_gate);
    waiting=NULL;rt_hw_spin_unlock(&lock);assert(!lock.slock && primask==1);
    reset();ns800_kernel_free_irq_ready=1;sema_fail=2;
    unsigned level=ns800_atomic_guard_lock();
    assert(level==1 && primask==1 && local_gate && adc_calls && !rt_calls);
    ns800_atomic_guard_unlock(level);assert(primask==1 && !local_gate);
    reset();cpu=mcm.CPUID.WORDVAL=1;ns800_kernel_free_irq_ready=1;
    lock.slock=1;waiting=&lock;rt_hw_spin_lock(&lock);
    assert(lock.slock==2 && !adc_calls && primask==1);waiting=NULL;rt_hw_spin_unlock(&lock);
    puts("BSP: priority-zero registration, exact mask restoration, kernel-free ADC in software/SEMA waits, CPU1 unchanged passed");
}
'''
with tempfile.TemporaryDirectory(prefix='ns800-fast-irq-',dir='/tmp/opencode') as name:
    folder=Path(name);test=folder/'test.c';exe=folder/'test'
    test.write_text(prefix+function('ns800_smp_register_kernel_free_irq')+
        function('ns800_atomic_guard_lock')+function('ns800_atomic_guard_unlock')+
        function('rt_hw_spin_lock')+function('rt_hw_spin_unlock')+suffix)
    subprocess.run(['cc','-std=gnu11','-O2','-Wall','-Wextra','-Werror','-fsanitize=undefined',
        '-I'+str(root/'board/smp'),str(test),'-o',str(exe)],check=True)
    subprocess.run([str(exe)],check=True,timeout=30)
