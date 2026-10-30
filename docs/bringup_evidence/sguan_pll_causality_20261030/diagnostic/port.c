/* Single ADCA/EPWM owner for the Sguan FOC library. Logical CPU0 only. */
#include <rtthread.h>
#include <board.h>
#include <adc.h>
#include <epwm.h>
#include <interrupt.h>
#include <rcc.h>
#include <syscon.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "SguanFOC.h"
#include "ns800_foc_port.h"
#include "foc_sensorless.h"

#define PWM_HZ 20000U
#define OFFSET_SAMPLES 256U
#define CURRENT_GAIN (-3.3f / (4096.0f * 6.0f * .020f))
#define VBUS_GAIN (3.3f * 25.0f / 4096.0f)
#define PORT_FAST __attribute__((section(".fast")))

/* The Sguan library owns control and slow protection.  The port only keeps
 * the hardware kill path, ADC-overrun detection, and a bridge from the
 * library's error states to that kill path. */
enum port_fault { PORT_OK, PORT_ADC, PORT_LIB, PORT_OBSERVER };
static const char *const fault_names[] = {"none", "adc", "library", "observer"};
static EPWM_TypeDef *const pwm[3] = {EPWM8, EPWM9, EPWM10};
static uint16_t period;
static volatile uint16_t raw[4];
static uint32_t offset_sum[3];
static float offsets[3];
static volatile float current[3], vbus, peak_current;
static volatile uint32_t ready, calibrated, running, adc_count, adc_overflows;
static volatile uint32_t adc_overflow_streak;
static struct foc_mailbox command_mailbox;
static struct foc_snapshot_channel status_channel;
static int command_result;
_Static_assert(sizeof(struct ns800_foc_status) % sizeof(uint32_t) == 0 &&
               sizeof(struct ns800_foc_status) <= FOC_SNAPSHOT_WORDS * sizeof(uint32_t),
               "FOC status must fit the word-atomic snapshot channel");
static volatile enum port_fault fault;
static uint32_t align_count, high_count, transitions;
static struct foc_sensorless_monitor sensorless;
static volatile uint32_t isr_last, isr_max, control_last, control_max;
static volatile uint32_t low_last, low_max;
static struct sguan_math_stats SguanMath; /* Zero: original software math, no eMATH. */
void ADCA_CONV_IRQHandler(void);
static void foc_status_publish(void);

static void pwm_safe_off(enum port_fault reason)
{
    GPIO_clearPin(GPIO_23);
    for (unsigned i = 0; i < 3; ++i)
        EPWM_forceTripZoneEvent(pwm[i], EPWM_TZ_FORCE_EVENT_OST);
    running = 0;
    fault = reason;
    /* Sampling keeps running, including while stopped or faulted. */
}

void ns800_foc_user_start(void) { /* Gates remain off until initialization ends. */ }
#include "foc_trace_diag.h"
void ns800_foc_delay(uint32_t ms) { rt_thread_mdelay(ms); }
int32_t ns800_foc_adc_raw(int32_t ch) { return raw[ch == 0 ? 0 : ch == 1 ? 1 : 2]; }
float ns800_foc_vbus(void) { return vbus; }

PORT_FAST void ns800_foc_pwm_set(uint32_t u, uint32_t v, uint32_t w)
{
    if (!running) return;
    uint32_t duty[3] = {u, v, w};
    float actual[3];
    for (unsigned i = 0; i < 3; ++i)
    {
        /* Keep the proven low-side sampling window and 1 us dead time. */
        float drop = vbus * PWM_HZ * .000001f * current[i] / (fabsf(current[i]) + .1f);
        float d = (float)duty[i] / 1000.0f + drop / vbus;
        if (d < .1f) d = .1f;
        if (d > .9f) d = .9f;
        uint16_t compare = (uint16_t)(d * period);
        EPWM_setCounterCompareValue(pwm[i], EPWM_COUNTER_COMPARE_A, compare);
        actual[i] = ((float)compare / period - .5f) * vbus - drop;
    }
    /* SMO consumes the voltage actually applied in the preceding period. */
    Sguan.foc.Ualpha = (2 * actual[0] - actual[1] - actual[2]) / 3.0f;
    Sguan.foc.Ubeta = (actual[1] - actual[2]) * Value_INV_SQRT3;
}
static void pwm_init_one(EPWM_TypeDef *epwm, GPIO_PinNum a, GPIO_PinNum b,
                         GPIO_AltFunc mux, uint16_t deadtime)
{
    GPIO_setPinConfig(GPIOA, a, mux);
    GPIO_setPinConfig(GPIOA, b, mux);
    GPIO_setAnalogMode(GPIOA, a, GPIO_ANALOG_DISABLED);
    GPIO_setAnalogMode(GPIOA, b, GPIO_ANALOG_DISABLED);
    GPIO_setPadConfig(GPIOA, a, GPIO_PIN_TYPE_STD);
    GPIO_setPadConfig(GPIOA, b, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(GPIOA, a, GPIO_QUAL_ASYNC);
    GPIO_setQualificationMode(GPIOA, b, GPIO_QUAL_ASYNC);
    EPWM_setTimeBaseCounterMode(epwm, EPWM_COUNTER_MODE_STOP_FREEZE);
    EPWM_setClockPrescaler(epwm, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_2);
    EPWM_disablePhaseShiftLoad(epwm);
    EPWM_setTimeBaseCounter(epwm, 0U);
    EPWM_setTimeBasePeriod(epwm, period);
    EPWM_setCounterCompareShadowLoadMode(epwm, EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareValue(epwm, EPWM_COUNTER_COMPARE_A, period / 2U);
    /* A high around ZERO: actual high-side duty = CMPA / TBPRD. */
    EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(epwm, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    /* Generate both complementary outputs from A, with 1 us dead time. */
    EPWM_setRisingEdgeDeadBandDelayInput(epwm, EPWM_DB_INPUT_EPWMA);
    EPWM_setFallingEdgeDeadBandDelayInput(epwm, EPWM_DB_INPUT_EPWMA);
    EPWM_setDeadBandDelayPolarity(epwm, EPWM_DB_RED, EPWM_DB_POLARITY_ACTIVE_HIGH);
    EPWM_setDeadBandDelayPolarity(epwm, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);
    EPWM_setDeadBandDelayMode(epwm, EPWM_DB_RED, true);
    EPWM_setDeadBandDelayMode(epwm, EPWM_DB_FED, true);
    EPWM_setRisingEdgeDelayCount(epwm, deadtime);
    EPWM_setFallingEdgeDelayCount(epwm, deadtime);
    EPWM_disableTripZoneAdvAction(epwm);
    EPWM_setTripZoneAction(epwm, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_LOW);
    EPWM_setTripZoneAction(epwm, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);
    EPWM_forceTripZoneEvent(epwm, EPWM_TZ_FORCE_EVENT_OST);
    EPWM_setTimeBaseCounterMode(epwm, EPWM_COUNTER_MODE_UP_DOWN);
}

static void motor_hw_init(void)
{
    unsigned i;
    uint32_t tbclk = RCC_getEpwmFrequency() / 2U;
    period = (uint16_t)(tbclk / (2U * PWM_HZ));
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    GPIO_setPinConfig(GPIO_23, ALT0_FUNCTION);
    GPIO_setAnalogMode(GPIO_23, GPIO_ANALOG_DISABLED);
    GPIO_clearPin(GPIO_23);
    GPIO_setPadConfig(GPIO_23, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(GPIO_23, GPIO_DIR_MODE_OUT);
    SYSCON_UNLOCK;
    SYSCON_setTbClkSync(SYSCON, false);
    SYSCON_LOCK;
    pwm_init_one(EPWM8, GPIO_PIN_14, GPIO_PIN_15, ALT1_FUNCTION, tbclk / 1000000U);
    pwm_init_one(EPWM9, GPIO_PIN_16, GPIO_PIN_17, ALT5_FUNCTION, tbclk / 1000000U);
    pwm_init_one(EPWM10, GPIO_PIN_18, GPIO_PIN_19, ALT5_FUNCTION, tbclk / 1000000U);
    ADC_disableInterrupt(ADCA, ADC_INT_NUMBER1);
    ADC_setVREF(ADCA, ADC_REFERENCE_INTERNAL, ADC_REFERENCE_3_3V);
    ADC_setPrescaler(ADCA, ADC_CLK_DIV_4);
    ADC_setInterruptPulsePosMode(ADCA, ADC_PULSE_END_OF_CONV);
    ADC_disableBurstMode(ADCA);
    ADC_setSOCPriority(ADCA, ADC_PRI_ALL_HIPRI);
    for (i = 0; i < 4U; i++)
    {
        GPIO_PinNum pin = (GPIO_PinNum)(GPIO_PIN_3 + i);
        GPIO_setPinConfig(GPIOH, pin, ALT0_FUNCTION);
        GPIO_setAnalogMode(GPIOH, pin, GPIO_ANALOG_ENABLED);
        GPIO_setPadConfig(GPIOH, pin, GPIO_PIN_TYPE_STD);
        GPIO_setQualificationMode(GPIOH, pin, GPIO_QUAL_ASYNC);
        GPIO_setDirectionMode(GPIOH, pin, GPIO_DIR_MODE_IN);
        ADC_setupSOC(ADCA, (ADC_SOCNumber)i, ADC_TRIGGER_EPWM8_SOCA,
                     (ADC_Channel)i, 32U);
    }
    ADC_enableConverter(ADCA);
    rt_thread_mdelay(2); /* reference/converter settling before first trigger */
    ADC_setInterruptSource(ADCA, ADC_INT_NUMBER1, ADC_SOC_NUMBER3);
    ADC_disableContinuousMode(ADCA, ADC_INT_NUMBER1);
    ADC_clearInterruptStatus(ADCA, ADC_INT_NUMBER1);
    ADC_clearInterruptOverflowStatus(ADCA, ADC_INT_NUMBER1);
    Interrupt_register(ADCA_CONV_IRQn, ADCA_CONV_IRQHandler);
    NVIC_SetPriority(ADCA_CONV_IRQn, 0U);
    NVIC_ClearPendingIRQ(ADCA_CONV_IRQn);
    ADC_enableInterrupt(ADCA, ADC_INT_NUMBER1);
    Interrupt_enable(ADCA_CONV_IRQn);
    /* PERIOD is the center of the low-side conduction window. */
    EPWM_setADCTriggerSource(EPWM8, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);
    EPWM_setADCTriggerEventPrescale(EPWM8, EPWM_SOC_A, 1U);
    EPWM_enableADCTrigger(EPWM8, EPWM_SOC_A);
    SYSCON_UNLOCK;
    SYSCON_setTbClkSync(SYSCON, true);
    SYSCON_setTbClkGlobalSync(SYSCON, true);
    SYSCON_LOCK;
    ready = 1U;
}


void ns800_foc_user_initial(void) { memset(&SguanMath, 0, sizeof(SguanMath)); motor_hw_init(); }

PORT_FAST void ADCA_CONV_IRQHandler(void)
{
    uint32_t entered = DWT->CYCCNT;
    for (unsigned i = 0; i < 4; ++i) raw[i] = ADC_readResult(ADCARESULT, (ADC_SOCNumber)i);
    adc_count++;
    vbus = raw[3] * VBUS_GAIN;
    if (ADC_getInterruptOverflowStatus(ADCA, ADC_INT_NUMBER1))
    {
        adc_overflows++;
        if (adc_overflow_streak < 1000U) adc_overflow_streak++;
        /* A single deferred conversion can occur while the shell/RTOS
         * briefly masks interrupts. Only a persistent ADC overrun is a
         * control fault; every event is still counted and cleared. */
        if (running && adc_overflow_streak >= 3U) pwm_safe_off(PORT_ADC);
        ADC_clearInterruptOverflowStatus(ADCA, ADC_INT_NUMBER1);
    }
    else adc_overflow_streak = 0U;
    ADC_clearInterruptStatus(ADCA, ADC_INT_NUMBER1);
    if (!calibrated)
    {
        for (unsigned i = 0; i < 3; ++i) offset_sum[i] += raw[i];
        if (adc_count >= OFFSET_SAMPLES)
        {
            calibrated = 1;
            for (unsigned i = 0; i < 3; ++i)
                offsets[i] = (float)offset_sum[i] / OFFSET_SAMPLES;
        }
        goto done;
    }
    for (unsigned i = 0; i < 3; ++i)
    {
        current[i] = (raw[i] - offsets[i]) * CURRENT_GAIN;
        if (running)
        {
            float mag = fabsf(current[i]);
            if (mag > peak_current) peak_current = mag;
        }
    }
    if (!running) {
        if (__atomic_load_n(&trace_zero_active, __ATOMIC_ACQUIRE)) {
            SMO_Loop(&zero_observer);
            if (++zero_count > 20000U)
                trace_sample_save(&zero_observer, entered, 0, 0, 1);
            if (foc_trace.completed)
                __atomic_store_n(&trace_zero_active, 0, __ATOMIC_RELEASE);
        }
        goto done;
    }
    /* Diagnostic-only fast bounds and an independent 12 s run deadline. */
    if (peak_current >= 3 || adc_overflows != foc_trace.overflow_start || high_count >= 240000U) {
        foc_trace.abort = 1; pwm_safe_off(PORT_ADC); goto done;
    }
    Sguan.foc.Real_VBUS = vbus;
    uint32_t start = DWT->CYCCNT;
    float trace_previous_angle = Sguan.transfer.PLL_encoder.go.OutRe;
    float trace_previous_we = Sguan.transfer.PLL_encoder.go.OutWe;
    SguanFOC_High_Loop();
    if (high_count >= 180000U && foc_trace.count < TRACE_N)
        trace_sample_save(&Sguan.transfer.SMO, entered, trace_previous_angle, trace_previous_we, 0);
    control_last = DWT->CYCCNT - start;
    if (control_last > control_max) control_max = control_last;
    if (++high_count % 20U == 0)
    {
        uint32_t low_start = DWT->CYCCNT;
        SguanFOC_Low_Loop();
        if (!foc_sensorless_tick(&sensorless, &Sguan)) pwm_safe_off(PORT_OBSERVER);
        low_last = DWT->CYCCNT - low_start;
        if (low_last > low_max) low_max = low_last;
    }
    if (Sguan.status >= MOTOR_STATUS_OVERVOLTAGE)
    { pwm_safe_off(PORT_LIB); goto done; }
    if (!running) goto done;
    if (sensorless.closed && transitions == 0) transitions = 1;
    if (align_count < 3U)
    {
        if (align_count == 2U)
        {
            for (unsigned i = 0; i < 3; ++i) EPWM_clearTripZoneFlag(pwm[i], EPWM_TZ_FLAG_OST);
            GPIO_setPin(GPIO_23);
        }
        else Sguan.foc.Ualpha = Sguan.foc.Ubeta = 0;
        align_count++;
    }
done:
    isr_last = DWT->CYCCNT - entered;
    if (isr_last > isr_max) isr_max = isr_last;
    foc_trace.max_isr = isr_max;
    if (running && (isr_last == 0 || isr_last >= foc_trace.cpu_hz/PWM_HZ)) {
        foc_trace.abort = 2; pwm_safe_off(PORT_ADC);
    }
}

static int foc_execute_request(const struct foc_request *request)
{
    if (!ready || calibrated != 1) return -RT_EBUSY;
    if (!isfinite(request->rpm) || fabsf(request->rpm) < 350 || fabsf(request->rpm) > 800 ||
        !isfinite(request->current) || request->current < .5f || request->current > 1.2f)
        return -RT_EINVAL;
    rt_base_t level = rt_hw_local_irq_disable();
    if (request->operation == FOC_SPEED)
    {
        int result = -RT_EBUSY;
        if (running && sensorless.closed && request->rpm * Sguan.foc.Target_Speed > 0)
        { Sguan.Func_Set_Velocity(request->rpm * Value_2PI / 60.0f); result = RT_EOK; }
        rt_hw_local_irq_enable(level);
        return result;
    }
    int busy = running;
    rt_hw_local_irq_enable(level);
    if (request->operation != FOC_START) return -RT_EINVAL;
    if (busy || trace_zero_active) return -RT_EBUSY;
    trace_reset(1);

    /* Library initialization may sleep. Keep gates off and recheck STOP just
     * before arming, so a STOP arriving during initialization cannot be lost. */
    memset(&Sguan.value, 0, sizeof(Sguan.value));
    memset(&Sguan.encoder, 0, sizeof(Sguan.encoder));
    foc_sensorless_reset(&sensorless);
    Sguan.Func_Start();
    SguanFOC_main_Loop();
    level = rt_hw_local_irq_disable();
    if (foc_mailbox_stop_pending(&command_mailbox))
    { rt_hw_local_irq_enable(level); return -RT_EINTR; }
    Sguan.current.Current_offset0 = (int32_t)(offsets[0] + .5f);
    Sguan.current.Current_offset1 = (int32_t)(offsets[1] + .5f);
    Sguan.foc.Real_VBUS = vbus;
    Sguan.foc.Ud_in = 0.0f;
    Sguan.foc.Uq_in = 0.0f;
    Sguan.foc.Target_Id = 0.0f;
    Sguan.foc.Target_Iq = 0.0f;
    Sguan.foc.Ualpha = 0.0f;
    Sguan.foc.Ubeta = 0.0f;
    Sguan.foc.Target_IF_Iq = request->rpm > 0 ? request->current : -request->current;
    Sguan.Func_Set_Velocity(request->rpm * Value_2PI / 60.0f);
    Sguan.foc.Speed_in = 0;
    ADC_clearInterruptStatus(ADCA, ADC_INT_NUMBER1);
    ADC_clearInterruptOverflowStatus(ADCA, ADC_INT_NUMBER1);
    memset(&SguanMath, 0, sizeof(SguanMath));
    fault = PORT_OK;
    peak_current = 0;
    adc_overflow_streak = 0;
    isr_last = isr_max = control_last = control_max = 0;
    align_count = high_count = transitions = 0;
    running = 1;
    rt_hw_local_irq_enable(level);
    return RT_EOK;
}

static void sguan_main_entry(void *unused)
{
    RT_UNUSED(unused);
    trace_reset(0);
    SguanFOC_main_Loop(); /* Peripheral init with gates disabled. */
    while (1)
    {
        if (foc_mailbox_stop_pending(&command_mailbox))
        {
            uint32_t stop = __atomic_load_n(&command_mailbox.stop, __ATOMIC_ACQUIRE);
            uint32_t cancel = __atomic_load_n(&command_mailbox.offered, __ATOMIC_ACQUIRE);
            rt_base_t level = rt_hw_local_irq_disable();
            pwm_safe_off(PORT_OK);
            Sguan.Func_Stop();
            rt_hw_local_irq_enable(level);
            if (cancel != __atomic_load_n(&command_mailbox.completed, __ATOMIC_RELAXED))
                command_result = -RT_EINTR;
            foc_mailbox_complete(&command_mailbox, cancel);
            __atomic_store_n(&command_mailbox.stopped, stop, __ATOMIC_RELEASE);
        }
        else
        {
            struct foc_request request;
            uint32_t seq;
            if (foc_mailbox_peek(&command_mailbox, &request, &seq))
            {
                command_result = foc_execute_request(&request);
                foc_mailbox_complete(&command_mailbox, seq);
            }
        }
        trace_zero_poll();
        foc_status_publish();
        rt_thread_mdelay(1);
    }
}

/* Only CPU0 reads mutable controller fields. CPU1 never tries to protect
 * these fields by masking its own (unrelated) local interrupts. */
static void foc_status_publish(void)
{
    struct ns800_foc_status s = {0};
    rt_base_t level = rt_hw_local_irq_disable();
    s.running = running; s.fault = fault; s.ready = ready; s.cal = calibrated;
    s.adc = adc_count; s.overflow = adc_overflows; s.status = Sguan.status;
    s.closed = sensorless.closed; s.transitions = transitions;
    s.isr_last = isr_last; s.isr_max = isr_max; s.ctrl_last = control_last; s.ctrl_max = control_max;
    s.low_last = low_last; s.low_max = low_max;
    for (unsigned i = 0; i < 4; ++i) s.raw[i] = raw[i];
    for (unsigned i = 0; i < 3; ++i) s.cur[i] = current[i];
    s.bus = vbus; s.peak = peak_current; s.target = Sguan.foc.Target_Speed;
    s.speed = Sguan.encoder.Real_Speed; s.pll_speed = Sguan.value.High_Wm;
    s.forced = Sguan.value.Low_Wm; s.angle = Sguan.encoder.Real_Re;
    s.forced_angle = sensorless.forced_angle;
    s.id = Sguan.current.Real_Id; s.iq = Sguan.current.Real_Iq; s.iqref = Sguan.foc.Target_Iq;
    s.emf = sensorless.emf;
    s.pll_error = Sguan.transfer.PLL_encoder.go.Error;
    s.lock = sensorless.valid_ms * .001f; s.blend = 0.0f;
    s.if_stage = s.running ? (sensorless.observer ? 3U : 1U) : 0U;
    s.startup = sensorless.elapsed_ms * .001f; s.lost = sensorless.lost_ms * .001f;
    s.phase = Sguan.value.High_angle - Sguan.value.Low_angle * Sguan.motor.Poles;
    s.wm_err = Sguan.value.High_Wm - Sguan.value.Low_Wm;
    s.speed_abs = Sguan.value.Speed_abs; s.gain = Sguan.value.Sensorless_Gain;
    float target_id = Sguan.foc.Target_Id;
    s.math = SguanMath;
    rt_hw_local_irq_enable(level);
    s.phase = Value_normalize(s.phase + Value_PI) - Value_PI;
    s.current_error = fmaxf(fabsf(target_id-s.id), fabsf(s.iqref-s.iq));
    s.command_seq = __atomic_load_n(&command_mailbox.completed, __ATOMIC_RELAXED);
    s.stop_seq = __atomic_load_n(&command_mailbox.stopped, __ATOMIC_RELAXED);
    s.command_result = command_result;
    foc_snapshot_publish(&status_channel, &s, sizeof(s));
}

int ns800_foc_status_read(struct ns800_foc_status *status)
{
    if (!status) return -RT_EINVAL;
    return foc_snapshot_read(&status_channel, status, sizeof(*status)) ? RT_EOK : -RT_EBUSY;
}

int ns800_foc_request(enum foc_operation operation, float rpm, float current)
{
    /* No sleeping/kernel locks in this short local producer critical section.
     * All Shell/CAN producers must be bound to the communications core. */
    rt_base_t level = rt_hw_local_irq_disable();
    int result = RT_EOK;
    if (operation == FOC_STOP) foc_mailbox_stop(&command_mailbox);
    else
    {
        struct foc_request request = {operation, rpm, current};
        if (foc_mailbox_stop_pending(&command_mailbox) ||
            !foc_mailbox_offer(&command_mailbox, &request))
            result = -RT_EBUSY;
    }
    rt_hw_local_irq_enable(level);
    return result;
}

static void foc_status(void)
{
    struct ns800_foc_status s;
    if (ns800_foc_status_read(&s) != RT_EOK)
    { rt_kprintf("motor: status publication busy; retry\n"); return; }
    const char *state = s.fault ? "fault" : !s.running ? "idle" : s.closed ? "run" : "ramp";
    const char *loop = !s.running ? "stopped" : s.closed ? "closed" : s.if_stage == 3 ? "observer-acquire" : "current-ramp";
    rt_kprintf("motor %s fault=%s ready=%u cal=%u pwm=%uHz adc=%u overflow=%u\n", state, fault_names[s.fault], s.ready, s.cal, PWM_HZ, s.adc, s.overflow);
    rt_kprintf("controller=sguan mode=SMO lib_status=%u math=upstream smo=diagnostic%u if=upstream\n", s.status, FOC_DIAG_VARIANT);
    rt_kprintf("electrical_mHz=%d vbus_mV=%d I_mA=%d,%d,%d peak_mA=%d raw=%u,%u,%u,%u\n",
        s.running ? (int)(s.speed * 2 / Value_2PI * 1000) : 0, (int)(s.bus*1000),
        (int)(s.cur[0]*1000), (int)(s.cur[1]*1000), (int)(s.cur[2]*1000), (int)(s.peak*1000), s.raw[0],s.raw[1],s.raw[2],s.raw[3]);
    rt_kprintf("cpu_hz=%u isr_cycles=%u/%u ISR_ns=%u control_cycles=%u/%u low_cycles=%u/%u\n", RCC_getCpuclkFrequency(),
        s.isr_last,s.isr_max,(unsigned)((uint64_t)s.isr_max*1000000000/RCC_getCpuclkFrequency()),s.ctrl_last,s.ctrl_max,
        s.low_last,s.low_max);
    rt_kprintf("loop=%s err=%u target_rpm=%d est_rpm=%d pll_rpm=%d forced_rpm=%d\n", loop,s.fault,
        (int)(s.target*60/Value_2PI),(int)(s.speed*60/Value_2PI),(int)(s.pll_speed*60/Value_2PI),(int)(s.forced*60/Value_2PI));
    rt_kprintf("Idq_mA=%d,%d Iqref_mA=%d emf_mV=%d pll_error_mV=%d lock_ms=%u blend_pct=%u\n",
        (int)(s.id*1000),(int)(s.iq*1000),(int)(s.iqref*1000),(int)(s.emf*1000),(int)(s.pll_error*1000),(unsigned)(s.lock*1000),(unsigned)(s.blend*100));
    rt_kprintf("transitions=%u angle_mrad=%d forced_mrad=%d current_error_mA=%d\n",s.transitions,
        (int)(s.angle*1000),(int)(s.forced_angle*1000),(int)(s.current_error*1000));
    rt_kprintf("if_stage=%u startup_ms=%u lost_ms=%u phase_mrad=%d wm_err_mrad=%d speed_abs_mrad=%d gain_pct=%u\n",
        s.if_stage, (unsigned)(s.startup*1000), (unsigned)(s.lost*1000),
        (int)(s.phase*1000), (int)(s.wm_err*1000), (int)(s.speed_abs*1000), (unsigned)(s.gain*100));
    rt_kprintf("emath_sincos=%u/%u/%u emath_trig=%u/%u/%u\n",s.math.sincos_last,s.math.sincos_max,s.math.sincos_calls,s.math.trig_last,s.math.trig_max,s.math.trig_calls);
    rt_kprintf("emath_sqrt=%u/%u/%u\n",s.math.sqrt_last,s.math.sqrt_max,s.math.sqrt_calls);
    rt_kprintf("command_seq=%u result=%d stop_seq=%u comm_cpu=%d\n",
               s.command_seq, s.command_result, s.stop_seq, rt_hw_cpu_id());
}

static int foc_cmd(int argc, char **argv)
{
    if (argc == 1 || (argc == 2 && !rt_strcmp(argv[1], "status"))) { foc_status(); return RT_EOK; }
    if (argc == 2 && !rt_strcmp(argv[1], "stop")) return ns800_foc_request(FOC_STOP, 0, 0);
    int start = !rt_strcmp(argv[1], "start") || !rt_strcmp(argv[1], "closed");
    int speed = !rt_strcmp(argv[1], "speed");
    if ((start && argc <= 4) || (speed && argc == 3))
    {
        float rpm = 500, amp = .8f;
        char *end;
        if (argc >= 3) { rpm = strtof(argv[2], &end); if (*end) return -RT_EINVAL; }
        if (argc == 4) { amp = strtof(argv[3], &end); if (*end) return -RT_EINVAL; }
        if (!isfinite(rpm) || fabsf(rpm) < 350 || fabsf(rpm) > 800)
        {
            rt_kprintf("motor: rpm must be in the range 350..800\n");
            return -RT_EINVAL;
        }
        if (!isfinite(amp) || amp < .5f || amp > 1.2f)
        {
            rt_kprintf("motor: current must be in the range 0.5..1.2 A\n");
            return -RT_EINVAL;
        }
        int result = ns800_foc_request(start ? FOC_START : FOC_SPEED, rpm, amp);
        if (result != RT_EOK) return result;
        rt_kprintf("Sguan: %s requested\n", start ? "sensorless start" : "speed change");
        return RT_EOK;
    }
    rt_kprintf("motor/foc status | start/closed [rpm 350..800] [A .5..1.2] | speed <rpm> | stop\n");
    return -RT_EINVAL;
}
MSH_CMD_EXPORT_ALIAS(foc_cmd, motor, Sguan library FOC control);
MSH_CMD_EXPORT_ALIAS(foc_cmd, foc, Sguan library FOC control);
static int foc_app_init(void)
{
    static struct rt_thread thread;
    static uint8_t stack[4096];
    rt_err_t rc = rt_thread_init(&thread,"sguan",sguan_main_entry,RT_NULL,stack,sizeof(stack),18,10);
    if (rc != RT_EOK) return rc;
    rt_thread_control(&thread,RT_THREAD_CTRL_BIND_CPU,(void *)(rt_ubase_t)NS800_CONTROL_CPU);
    return rt_thread_startup(&thread);
}
INIT_APP_EXPORT(foc_app_init);
