#!/usr/bin/env python3
"""Exercise the real IPC primitives and CPU0 request loop without motor hardware."""
from pathlib import Path
import re
import subprocess
import tempfile

root = Path(__file__).resolve().parents[1]
port = root / "applications/sguan"
source = (port / "ns800_foc_port.c").read_text()


def function(name):
    match = re.search(r"^(?:static )?(?:void|int|enum ns800_foc_owner) " + name + r"\([^;]+?\)\n\{", source, re.M)
    assert match, name
    depth = 1
    for end in range(match.end(), len(source)):
        depth += (source[end] == "{") - (source[end] == "}")
        if depth == 0:
            return source[match.start():end + 1]
    raise AssertionError(name)


ipc_test = r'''
#include <assert.h>
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include "ns800_foc_port.h"
_Static_assert(__atomic_always_lock_free(4, 0), "word atomics must not take locks");
_Static_assert(sizeof(struct ns800_foc_status) == 24, "Only six status fields may be published");
_Static_assert(sizeof(struct foc_snapshot_channel) == 28, "No oversized status buffer");
struct sample { uint32_t value, inverse, square, duplicate, duplicate2, inverse2; };
_Static_assert(sizeof(struct sample) == sizeof(struct ns800_foc_status), "Exercise every snapshot word");
static struct foc_snapshot_channel channel;
static struct foc_mailbox mailbox;
static uint32_t finished;
static void *publish(void *unused) {
    (void)unused;
    for (uint32_t i = 1; i < 100000; ++i) {
        struct sample sample = {i, ~i, i * i, i, i, ~i};
        foc_snapshot_publish(&channel, &sample, sizeof(sample));
    }
    __atomic_store_n(&finished, 1, __ATOMIC_RELEASE);
    return NULL;
}
static void *offer(void *unused) {
    (void)unused;
    for (uint32_t i = 1; i <= 20000; ++i) {
        struct foc_request request = {FOC_SPEED, (float)i, -(float)i};
        while (!foc_mailbox_offer(&mailbox, &request)) sched_yield();
    }
    return NULL;
}
int main(void) {
    struct foc_request request = {FOC_START, 500, .8f}, copy;
    uint32_t seq;
    assert(foc_mailbox_offer(&mailbox, &request));
    assert(!foc_mailbox_offer(&mailbox, &request));
    assert(foc_mailbox_peek(&mailbox, &copy, &seq) && copy.rpm == 500 && seq == 1);
    foc_mailbox_stop(&mailbox);
    assert(foc_mailbox_stop_pending(&mailbox));
    foc_mailbox_complete(&mailbox, seq);
    __atomic_store_n(&mailbox.stopped, mailbox.stop, __ATOMIC_RELEASE);
    assert(!foc_mailbox_stop_pending(&mailbox));
    mailbox.offered = mailbox.completed = UINT32_MAX;
    assert(foc_mailbox_offer(&mailbox, &request));
    assert(foc_mailbox_peek(&mailbox, &copy, &seq) && seq == 0);
    foc_mailbox_complete(&mailbox, seq);
    assert(!foc_mailbox_peek(&mailbox, &copy, &seq));

    pthread_t writer;
    struct sample initial = {1, ~1U, 1, 1, 1, ~1U}, sample;
    channel.sequence = UINT32_MAX - 1U;
    foc_snapshot_publish(&channel, &initial, sizeof(initial));
    assert(channel.sequence == 0 && foc_snapshot_read(&channel, &sample, sizeof(sample)));
    channel.sequence = 1;
    assert(!foc_snapshot_read(&channel, &sample, sizeof(sample))); /* bounded busy read */
    channel.sequence = 0;
    assert(pthread_create(&writer, NULL, publish, NULL) == 0);
    unsigned reads = 0;
    do {
        if (foc_snapshot_read(&channel, &sample, sizeof(sample))) {
            assert(sample.inverse == ~sample.value && sample.duplicate == sample.value);
            assert(sample.square == sample.value * sample.value);
            assert(sample.duplicate2 == sample.value && sample.inverse2 == ~sample.value);
            reads++;
        }
    } while (!__atomic_load_n(&finished, __ATOMIC_ACQUIRE));
    assert(pthread_join(writer, NULL) == 0 && reads);

    memset(&mailbox, 0, sizeof(mailbox));
    assert(pthread_create(&writer, NULL, offer, NULL) == 0);
    for (uint32_t i = 1; i <= 20000; ++i) {
        while (!foc_mailbox_peek(&mailbox, &copy, &seq)) sched_yield();
        assert(seq == i && copy.rpm == (float)i && copy.current == -(float)i);
        foc_mailbox_complete(&mailbox, seq);
    }
    assert(pthread_join(writer, NULL) == 0);
    puts("IPC: bounded snapshots, concurrent publication, mailbox ordering and wrap passed");
}
'''

control_prefix = r'''
#include <assert.h>
#include <math.h>
#include <setjmp.h>
#include <stdio.h>
#include "ns800_foc_port.h"
typedef unsigned rt_base_t;
#define RT_EOK 0
#define RT_EBUSY 16
#define RT_EINVAL 22
#define RT_EINTR 4
#define RT_UNUSED(x) (void)(x)
#define Value_2PI 6.28318530718f
#define ADCA 0
#define ADC_INT_NUMBER1 0
#define OFFSET_SAMPLES 256U
static struct foc_mailbox command_mailbox;
static struct foc_snapshot_channel status_channel;
static unsigned offset_count = OFFSET_SAMPLES, running;
static float offsets[2], current[3], vbus;
static unsigned fault, adc_overflow_streak;
static unsigned align_count, high_count;
static int command_result;
static enum ns800_foc_owner control_owner=FOC_OWNER_CAN;
static uint32_t owner_pending,owner_stop_seq;
static unsigned stops, initializations, inject_stop, interrupts;
static struct foc_sensorless_monitor {unsigned closed;} sensorless;
static void foc_sensorless_reset(struct foc_sensorless_monitor *state) {state->closed=0;}
static struct {
    struct {float Target_Speed, Real_VBUS, Ud_in, Uq_in, Target_Id, Target_Iq,
                  Ualpha, Ubeta, Target_IF_Iq, Speed_in;} foc;
    struct {int Current_offset0, Current_offset1;} current;
    struct {unsigned Sensorless_Flag;} value;
    struct {float angle, Real_Speed;} encoder;
    struct {float VBUS_MIN, VBUS_MAX, Current_limit;} safe;
    unsigned status;
    void (*Func_Start)(void);
    void (*Func_Stop)(void);
    void (*Func_Set_Velocity)(float);
} Sguan;
static jmp_buf cycle;
static rt_base_t rt_hw_local_irq_disable(void) { unsigned old=interrupts; interrupts=1; return old; }
static void rt_hw_local_irq_enable(rt_base_t old) { interrupts=old; }
static void ADC_clearInterruptStatus(int base, int irq) { (void)base; (void)irq; }
static void ADC_clearInterruptOverflowStatus(int base, int irq) { (void)base; (void)irq; }
static void pwm_safe_off(unsigned reason) {
    if(reason) fault=(reason<<16) | (reason==FOC_ERROR_LIBRARY ? Sguan.status : 0);
    running=0; stops++;
}
static void start(void) {}
static void stop(void) {Sguan.status=0;}
static void speed(float value) { Sguan.foc.Target_Speed=value; }
static void SguanFOC_main_Loop(void) {
    initializations++;
    if (initializations == 2 && inject_stop) foc_mailbox_stop(&command_mailbox);
}
static void rt_thread_mdelay(unsigned ms) { assert(ms == 1 && !interrupts); longjmp(cycle, 1); }
'''
control_suffix = r'''
static void one_cycle(void) { if (!setjmp(cycle)) sguan_main_entry(NULL); }
static void reset(void) {
    memset(&command_mailbox, 0, sizeof(command_mailbox));
    memset(&status_channel, 0, sizeof(status_channel));
    memset(&Sguan, 0, sizeof(Sguan));
    running=stops=initializations=inject_stop=interrupts=fault=0;
    command_result=0;
    control_owner=FOC_OWNER_UART;owner_pending=owner_stop_seq=0; /* Legacy tests exercise UART ownership. */
    adc_overflow_streak=0;
    offset_count=OFFSET_SAMPLES;
    vbus=24; memset(current,0,sizeof(current));
    Sguan.safe.VBUS_MIN=12; Sguan.safe.VBUS_MAX=30; Sguan.safe.Current_limit=3;
    Sguan.Func_Start=start; Sguan.Func_Stop=stop; Sguan.Func_Set_Velocity=speed;
    sensorless.closed=0;
}
int main(void) {
    struct ns800_foc_status status;
    assert(ns800_foc_owner_get()==FOC_OWNER_CAN); /* Actual zero-initialized boot default. */
    reset();
    assert(ns800_foc_status_read(&status) == RT_EOK && status.state == FOC_STATE_NOT_READY);
    assert(ns800_foc_status_read(NULL) == -RT_EINVAL);
    offset_count=OFFSET_SAMPLES-1;
    foc_status_publish();
    assert(ns800_foc_status_read(&status) == RT_EOK && status.state == FOC_STATE_CALIBRATING);
    ns800_foc_request(FOC_START, 500, .8f); one_cycle();
    assert(command_result == -RT_EBUSY && !running);
    reset();
    assert(ns800_foc_request(FOC_START, 500, .8f) == RT_EOK);
    assert(ns800_foc_request(FOC_SPEED, 600, .8f) == -RT_EBUSY);
    one_cycle();
    assert(running && command_mailbox.completed == 1 && command_result == 0);
    assert(ns800_foc_status_read(&status) == RT_EOK && status.state == FOC_STATE_ARMING);
    assert(status.command_seq == 1 && status.command_result == RT_EOK);
    ns800_foc_request(FOC_RESET_FAULT,0,0); one_cycle();
    assert(command_result==-RT_EBUSY && running); /* reset never disables a running motor implicitly */
    align_count=3; foc_status_publish();
    assert(ns800_foc_status_read(&status) == RT_EOK && status.state == FOC_STATE_STARTING);
    assert(ns800_foc_request(FOC_SPEED, 600, .8f) == 0);
    one_cycle();
    assert(command_result == -RT_EBUSY); /* CPU0, not a stale snapshot, decides */
    sensorless.closed=1;
    assert(ns800_foc_request(FOC_SPEED, 600, .8f) == 0);
    one_cycle();
    assert(command_result == 0);
    assert(ns800_foc_status_read(&status) == RT_EOK && status.state == FOC_STATE_CLOSED);
    assert(ns800_foc_request(FOC_SPEED, -600, .8f) == 0);
    one_cycle();
    assert(command_result == -RT_EBUSY); /* no direct cross-zero reversal */
    assert(ns800_foc_request(FOC_STOP, 0, 0) == 0);
    one_cycle();
    assert(!running && stops == 1 && !foc_mailbox_stop_pending(&command_mailbox));
    assert(ns800_foc_status_read(&status) == RT_EOK && status.state == FOC_STATE_IDLE && status.stop_seq == 1);

    reset();
    ns800_foc_request(FOC_START, 500, .8f);
    ns800_foc_request(FOC_STOP, 0, 0); /* never overwritten by queued START */
    one_cycle();
    assert(!running && stops == 1 && command_result == -RT_EINTR);
    assert(command_mailbox.offered == command_mailbox.completed);

    reset(); inject_stop=1;
    ns800_foc_request(FOC_START, 500, .8f);
    one_cycle();
    assert(!running && command_result == -RT_EINTR && foc_mailbox_stop_pending(&command_mailbox));
    one_cycle();
    assert(!running && stops == 1 && !foc_mailbox_stop_pending(&command_mailbox));
    reset();
    Sguan.encoder.Real_Speed=-42.5f;
    for (unsigned source=FOC_ERROR_NONE; source<=FOC_ERROR_OBSERVER; ++source) {
        fault=(source<<16) | (source==FOC_ERROR_LIBRARY ? 0x1234 : 0); Sguan.status=0;
        command_result=-RT_EBUSY;
        foc_status_publish();
        assert(!interrupts && ns800_foc_status_read(&status) == RT_EOK);
        assert(status.state == (source ? FOC_STATE_FAULT : FOC_STATE_IDLE));
        assert(status.error == ((source<<16) | (source==FOC_ERROR_LIBRARY ? 0x1234 : 0)));
        assert(status.speed == -42.5f && status.command_result == -RT_EBUSY);
    }
    status_channel.sequence |= 1U;
    assert(ns800_foc_status_read(&status) == -RT_EBUSY);
    reset();
    fault=(FOC_ERROR_LIBRARY<<16) | 0x12; Sguan.status=0x12;
    ns800_foc_request(FOC_STOP,0,0); one_cycle();
    assert(ns800_foc_status_read(&status)==0 && status.state==FOC_STATE_FAULT);
    assert(status.error==((FOC_ERROR_LIBRARY<<16)|0x12) && Sguan.status==0);
    ns800_foc_request(FOC_START,500,.8f); one_cycle();
    assert(command_result==-RT_EBUSY && !running);
    adc_overflow_streak=3;
    ns800_foc_request(FOC_RESET_FAULT,0,0); one_cycle();
    assert(command_result==-RT_EBUSY && fault);
    adc_overflow_streak=0;
    vbus=31; ns800_foc_request(FOC_RESET_FAULT,0,0); one_cycle();
    assert(command_result==-RT_EBUSY && fault);
    vbus=24; current[0]=3; ns800_foc_request(FOC_RESET_FAULT,0,0); one_cycle();
    assert(command_result==-RT_EBUSY && fault);
    current[0]=0;
    ns800_foc_request(FOC_RESET_FAULT,0,0); one_cycle();
    assert(command_result==0 && !fault && !running);
    assert(ns800_foc_status_read(&status)==0 && status.state==FOC_STATE_IDLE);
    reset();
    control_owner=FOC_OWNER_CAN;
    command_mailbox.offered=command_mailbox.completed=7; /* published snapshot still says zero */
    uint32_t sequence=0;
    assert(ns800_foc_submit(FOC_START,500,.8f,&sequence)==0 && sequence==8);
    assert(ns800_foc_submit(FOC_STOP,0,0,&sequence)==0 && sequence==1);
    reset();control_owner=FOC_OWNER_CAN;
    assert(ns800_foc_owner_set(FOC_OWNER_SWITCHING)==-RT_EINVAL);
    assert(ns800_foc_owner_set(FOC_OWNER_CAN)==0 && command_mailbox.stop==0);
    assert(ns800_foc_request(FOC_START,500,.8f)==-RT_EBUSY);
    assert(ns800_foc_submit(FOC_START,500,.8f,NULL)==0);
    assert(ns800_foc_owner_set(FOC_OWNER_UART)==0);
    assert(ns800_foc_owner_get()==FOC_OWNER_SWITCHING);
    assert(ns800_foc_submit(FOC_SPEED,600,.8f,NULL)==-RT_EBUSY);
    assert(ns800_foc_request(FOC_START,500,.8f)==-RT_EBUSY);
    assert(ns800_foc_owner_set(FOC_OWNER_CAN)==-RT_EBUSY);
    one_cycle();
    assert(!running && command_result==-RT_EINTR && ns800_foc_owner_get()==FOC_OWNER_UART);
    assert(ns800_foc_submit(FOC_START,500,.8f,NULL)==-RT_EBUSY);
    assert(ns800_foc_request(FOC_START,500,.8f)==0);one_cycle();assert(running);
    assert(ns800_foc_owner_set(FOC_OWNER_CAN)==0 && ns800_foc_owner_get()==FOC_OWNER_SWITCHING);
    one_cycle();assert(!running);
    status_channel.sequence|=1U;
    assert(ns800_foc_owner_get()==FOC_OWNER_SWITCHING); /* No grant from a busy snapshot. */
    status_channel.sequence++;
    assert(ns800_foc_owner_get()==FOC_OWNER_CAN);
    assert(ns800_foc_request(FOC_RESET_FAULT,0,0)==-RT_EBUSY);
    reset();control_owner=FOC_OWNER_CAN;
    fault=FOC_ERROR_CURRENT<<16;foc_status_publish();
    command_mailbox.stop=command_mailbox.stopped=UINT32_MAX;foc_status_publish();
    assert(ns800_foc_owner_set(FOC_OWNER_UART)==0 && owner_stop_seq==0);
    assert(ns800_foc_owner_get()==FOC_OWNER_SWITCHING);one_cycle();
    assert(ns800_foc_owner_get()==FOC_OWNER_UART && fault==(FOC_ERROR_CURRENT<<16));
    reset();
    ns800_foc_request(FOC_START,2500,.8f);one_cycle();assert(command_result==-RT_EINVAL && !running);
    ns800_foc_request(FOC_START,500,.8f);one_cycle();sensorless.closed=1;
    ns800_foc_request(FOC_SPEED,2500,.8f);one_cycle();assert(command_result==0);
    ns800_foc_request(FOC_SPEED,2501,.8f);one_cycle();assert(command_result==-RT_EINVAL);
    puts("Owner: CAN boot default, STOP-before-grant, stale/busy rejection, cancellation, wrap and fault preservation passed");
    puts("Control loop: async requests, state checks, STOP priority and initialization cancellation passed");
    puts("Status: six fields/24 bytes, all states, lossless error source/detail and command acknowledgements passed");
}
'''

with tempfile.TemporaryDirectory(prefix="ns800-foc-ipc-", dir="/tmp/opencode") as folder:
    folder = Path(folder)
    for name, code in (
        ("ipc", ipc_test),
        ("control", control_prefix + function("foc_execute_request") +
         function("foc_status_publish") + function("ns800_foc_status_read") +
          function("sguan_main_entry") + function("ns800_foc_owner_get") + function("ns800_foc_owner_set") +
          function("foc_submit_for_owner") + function("ns800_foc_submit") + function("ns800_foc_request") + control_suffix),
    ):
        cfile, executable = folder / (name + ".c"), folder / name
        cfile.write_text(code)
        subprocess.run(["cc", "-std=gnu11", "-O2", "-Wall", "-Wextra", "-Werror",
                        "-fsanitize=undefined", "-pthread", "-I" + str(port),
                        str(cfile), "-o", str(executable)], check=True)
        subprocess.run([str(executable)], check=True, timeout=30)
