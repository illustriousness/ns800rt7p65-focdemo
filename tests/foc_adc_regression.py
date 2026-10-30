#!/usr/bin/env python3
"""Run the actual ADC ISR against a register-free model after removing telemetry."""
from pathlib import Path
import re
import subprocess
import tempfile

root = Path(__file__).resolve().parents[1]
port = root / 'applications/sguan'
source = (port / 'ns800_foc_port.c').read_text()
def function(pattern):
    match = re.search(pattern, source, re.M)
    assert match
    depth = 1
    for end in range(match.end(), len(source)):
        depth += (source[end] == '{') - (source[end] == '}')
        if not depth:
            return source[match.start():end + 1]
    raise AssertionError('Unterminated C function')


handler = function(r'^PORT_FAST void ADCA_CONV_IRQHandler\(void\)\n\{')
safe_off = function(r'^static void pwm_safe_off\([^;]+\)\n\{')

prefix = r'''
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "ns800_foc_port.h"
#define PORT_FAST
#define OFFSET_SAMPLES 256U
#define CURRENT_GAIN 1.0f
#define VBUS_GAIN 1.0f
#define ADCA 0
#define ADCARESULT 0
#define ADC_INT_NUMBER1 0
#define ADC_SOC_NUMBER3 3
#define EPWM_TZ_FLAG_OST 4
#define EPWM_TZ_FORCE_EVENT_OST 4
#define GPIO_23 23
#define MOTOR_STATUS_OVERVOLTAGE 10
#define Value_2PI 6.283185307179586f
typedef unsigned ADC_SOCNumber;
static uint16_t input[4]={100,200,300,24}, raw[3];
static uint32_t offset_sum[3], offset_count, adc_overflow_streak, align_count, high_count;
static float offsets[3], current[3], vbus;
static unsigned running, overflow, clear_count, high_calls, low_calls, monitor_calls;
static unsigned gates_enabled, trips_cleared, fault, observer_ok=1;
static int pwm[3]={8,9,10}, sensorless;
static struct {struct {float Real_VBUS, Ualpha, Ubeta;} foc; struct {float Real_Speed;} encoder; unsigned status;} Sguan;
static unsigned ADC_readResult(int base, unsigned channel) {(void)base; return input[channel];}
static int ADC_getInterruptOverflowStatus(int base,int irq) {(void)base;(void)irq;return overflow;}
static void ADC_clearInterruptOverflowStatus(int base,int irq) {(void)base;(void)irq;}
static void ADC_clearInterruptStatus(int base,int irq) {(void)base;(void)irq;clear_count++;}
static void GPIO_clearPin(unsigned pin) {assert(pin==23);}
static void EPWM_forceTripZoneEvent(int instance,unsigned flags) {assert(instance>=8 && instance<=10 && flags==4);}
static void SguanFOC_High_Loop(void) {high_calls++;Sguan.foc.Ualpha=1;Sguan.foc.Ubeta=2;}
static void SguanFOC_Low_Loop(void) {low_calls++;}
static int foc_sensorless_tick(void *monitor,void *motor) {(void)monitor;(void)motor;monitor_calls++;return observer_ok;}
static void EPWM_clearTripZoneFlag(int instance,unsigned flags) {assert(instance>=8 && instance<=10 && flags==4);trips_cleared++;}
static void GPIO_setPin(unsigned pin) {assert(pin==23);gates_enabled++;}
'''
suffix = r'''
int main(void) {
    for (unsigned i=0;i<OFFSET_SAMPLES;++i) {
        ADCA_CONV_IRQHandler();
        assert(offset_count==i+1 && high_calls==0);
    }
    assert(offsets[0]==100 && offsets[1]==200 && offsets[2]==300);
    input[0]=101;input[1]=198;input[2]=302;
    ADCA_CONV_IRQHandler();
    assert(offset_count==256 && current[0]==1 && current[1]==-2 && current[2]==2 && vbus==24);
    running=1;
    ADCA_CONV_IRQHandler();assert(!gates_enabled && Sguan.foc.Ualpha==0 && Sguan.foc.Ubeta==0);
    ADCA_CONV_IRQHandler();assert(!gates_enabled && Sguan.foc.Ualpha==0);
    ADCA_CONV_IRQHandler();assert(gates_enabled==1 && trips_cleared==3 && Sguan.foc.Ualpha==1);
    for (unsigned i=3;i<20;++i) ADCA_CONV_IRQHandler();
    assert(high_calls==20 && low_calls==1 && monitor_calls==1 && Sguan.foc.Real_VBUS==24);
    unsigned before=high_calls;
    overflow=1;
    ADCA_CONV_IRQHandler();assert(running && adc_overflow_streak==1);
    ADCA_CONV_IRQHandler();assert(running && adc_overflow_streak==2);
    ADCA_CONV_IRQHandler();assert(!running && adc_overflow_streak==3 && fault==(FOC_ERROR_ADC<<16));
    assert(high_calls==before+2 && gates_enabled==1);
    overflow=0;ADCA_CONV_IRQHandler();assert(adc_overflow_streak==0 && offset_count==256);
    running=1;high_count=19;observer_ok=0;
    ADCA_CONV_IRQHandler();assert(!running && fault==(FOC_ERROR_OBSERVER<<16));
    running=1;Sguan.status=MOTOR_STATUS_OVERVOLTAGE;
    ADCA_CONV_IRQHandler();assert(!running && fault==((FOC_ERROR_LIBRARY<<16)|MOTOR_STATUS_OVERVOLTAGE));
    Sguan.status=0;pwm_safe_off(FOC_ERROR_NONE);
    assert(fault==((FOC_ERROR_LIBRARY<<16)|MOTOR_STATUS_OVERVOLTAGE));
    running=1;input[0]=104;before=high_calls;
    ADCA_CONV_IRQHandler();assert(!running && high_calls==before && fault==(FOC_ERROR_CURRENT<<16));
    running=1;input[0]=96;
    ADCA_CONV_IRQHandler();assert(!running && fault==(FOC_ERROR_CURRENT<<16));
    input[0]=100;running=1;Sguan.encoder.Real_Speed=300;
    ADCA_CONV_IRQHandler();assert(!running && fault==(FOC_ERROR_SPEED<<16));
    Sguan.encoder.Real_Speed=0;running=1;input[3]=21;
    ADCA_CONV_IRQHandler();assert(!running && fault==(FOC_ERROR_BUS<<16));
    running=1;input[3]=28;
    ADCA_CONV_IRQHandler();assert(!running && fault==(FOC_ERROR_BUS<<16));
    assert(offset_count==256 && clear_count>256);
    puts("ADC ISR: 256-sample calibration, phase/bus conversion, loop division, gate sequence and existing fault paths passed");
}
'''
with tempfile.TemporaryDirectory(prefix='ns800-foc-adc-', dir='/tmp/opencode') as folder:
    test, binary = Path(folder) / 'adc.c', Path(folder) / 'adc'
    test.write_text(prefix + safe_off + handler + suffix)
    subprocess.run(['cc', '-std=gnu11', '-O2', '-Wall', '-Wextra', '-Werror',
                    '-fsanitize=undefined', '-I' + str(port), str(test), '-o', str(binary)], check=True)
    subprocess.run([str(binary)], check=True, timeout=30)
