/* NS800 PWM/ADC owner: voltage open loop and sensorless current/speed loops. */
#include <rtthread.h>
#include <board.h>
#include <adc.h>
#include <epwm.h>
#include <interrupt.h>
#include <rcc.h>
#include <syscon.h>
#include <math.h>
#include <stdlib.h>
#include "motor_sensorless.h"
#include "emath.h"

/* Existing ATK adapter wiring: U/V/W = EPWM8/9/10, enable = GP23.
 * ADCA0/1/2 = IU/IV/IW (20 mOhm, gain 6), ADCA3 = VBUS (25:1).
 * Frequencies below are ELECTRICAL Hz, not measured shaft speed. */
#define PWM_HZ          20000U
#define OFFSET_SAMPLES  256U
/* A positive motor phase current flows UP through the conducting low-side
 * shunt. ATK's non-inverting amplifier therefore reports a negative delta. */
#define CURRENT_GAIN    (-3.3f / (4096.0f * 6.0f * 0.020f))
#define VBUS_GAIN       (3.3f * 25.0f / 4096.0f)
#define CURRENT_LIMIT   3.0f
#define VBUS_MIN        12.0f
#define VBUS_MAX        30.0f
#define ALIGN_VOLTS     0.6f
#define RUN_VOLTS       1.0f
#define DEFAULT_HZ     5.0f
#define RAMP_HZ_PER_S   2.0f

enum motor_state { MOTOR_IDLE, MOTOR_ALIGN, MOTOR_RAMP, MOTOR_RUN, MOTOR_FAULT };
enum motor_fault { FAULT_NONE, FAULT_VBUS, FAULT_CURRENT, FAULT_ADC,
                   FAULT_OFFSET, FAULT_OBSERVER };
static EPWM_TypeDef *const pwm[3] = {EPWM8, EPWM9, EPWM10};
static const char *const state_names[] = {"idle", "align", "ramp", "run", "fault"};
static const char *const fault_names[] = {"none", "vbus", "current", "adc", "offset", "observer"};
static const char *const loop_names[] = {"align", "current-ramp", "blend", "closed", "fault"};
static uint16_t period;
static float sample_hz;
static volatile enum motor_state state;
static volatile enum motor_fault fault;
static volatile uint32_t adc_count, adc_overflows, calibrated, ready;
static volatile uint16_t raw[4];
static volatile float current[3], vbus, frequency, peak_current;
static float offsets[3], phase, target_hz = DEFAULT_HZ, target_volts = RUN_VOLTS;
static uint32_t offset_sum[3], align_count;
static volatile uint32_t request; /* 1=open, 2=stop, 3=closed, 4=speed */
static float requested_hz, requested_volts;
static float requested_rpm, requested_current;
static volatile uint32_t sensorless_mode, isr_last_cycles, isr_max_cycles;
static volatile uint32_t control_last_cycles, control_max_cycles;
static struct motor_sensorless control;
static float applied_alpha, applied_beta;

static void motor_off(enum motor_fault reason)
{
    unsigned i;
    GPIO_clearPin(GPIO_23);
    /* Trip acts AFTER dead band, so BOTH outputs are forced low. */
    for (i = 0; i < 3U; i++)
        EPWM_forceTripZoneEvent(pwm[i], EPWM_TZ_FORCE_EVENT_OST);
    frequency = 0.0f;
    applied_alpha = applied_beta = 0.0f;
    fault = reason;
    state = reason == FAULT_NONE ? MOTOR_IDLE : MOTOR_FAULT;
    /* Keep the time bases running for ADC sampling with gates disabled. */
}

static void motor_voltage_ab(float alpha, float beta)
{
    float volts[3] = {alpha, -0.5f * alpha + 0.866025404f * beta,
                     -0.5f * alpha - 0.866025404f * beta};
    float actual[3];
    unsigned i;
    /* Compensation for the duty lost to dead time. Smooth the sign near zero
     * current; all three low-side shunts are sampled at TBCTR=PERIOD. */
    for (i = 0; i < 3U; i++)
    {
        float drop = vbus * (float)PWM_HZ * 0.000001f *
                     current[i] / (fabsf(current[i]) + 0.1f);
        float duty = 0.5f + (volts[i] + drop) / vbus;
        uint16_t compare;
        if (duty < 0.1f) duty = 0.1f;
        if (duty > 0.9f) duty = 0.9f;
        compare = (uint16_t)(duty * period);
        EPWM_setCounterCompareValue(pwm[i], EPWM_COUNTER_COMPARE_A, compare);
        actual[i] = ((float)compare / period - 0.5f) * vbus - drop;
    }
    applied_alpha = (2.0f * actual[0] - actual[1] - actual[2]) / 3.0f;
    applied_beta = (actual[1] - actual[2]) * 0.577350269f;
}

static void motor_voltage(float volts)
{
    unsigned i;
    float modulation = volts / vbus;
    float sin0, cos0;
    float phase_rad = phase * 6.2831853071795864769f;
    float phase_sin[3];
    /* CPU0 ADC ISR is the sole owner of EMATH. Generate the 120-degree
     * shifted phases algebraically, so this path also has no sine table. */
    EMATH_sincosF32(phase_rad, &sin0, &cos0);
    phase_sin[0] = sin0;
    phase_sin[1] = -0.5f * sin0 + 0.866025403784f * cos0;
    phase_sin[2] = -0.5f * sin0 - 0.866025403784f * cos0;
    for (i = 0; i < 3U; i++)
    {
        float duty = 0.5f + modulation * phase_sin[i];
        /* Leave room for dead time and low-side current sampling. */
        if (duty < 0.1f) duty = 0.1f;
        if (duty > 0.9f) duty = 0.9f;
        EPWM_setCounterCompareValue(pwm[i], EPWM_COUNTER_COMPARE_A,
                                     (uint16_t)(duty * period));
    }
}

void ADCA_CONV_IRQHandler(void)
{
    unsigned i;
    uint32_t entered = DWT->CYCCNT;
    /* High-priority control IRQ uses no RTOS services or SMP atomic locks. */
    for (i = 0; i < 4U; i++)
        raw[i] = ADC_readResult(ADCARESULT, (ADC_SOCNumber)i);
    adc_count++;
    vbus = (float)raw[3] * VBUS_GAIN;
    if (ADC_getInterruptOverflowStatus(ADCA, ADC_INT_NUMBER1))
    {
        adc_overflows++;
        /* Boot/idle kernel critical sections may defer a sample with gates
         * off. A missed sample while driving must shut the bridge down. */
        if (state >= MOTOR_ALIGN && state <= MOTOR_RUN) motor_off(FAULT_ADC);
        ADC_clearInterruptOverflowStatus(ADCA, ADC_INT_NUMBER1);
    }
    ADC_clearInterruptStatus(ADCA, ADC_INT_NUMBER1);

    if (!calibrated)
    {
        for (i = 0; i < 3U; i++) offset_sum[i] += raw[i];
        if (adc_count >= OFFSET_SAMPLES)
        {
            calibrated = 1U;
            for (i = 0; i < 3U; i++)
            {
                offsets[i] = (float)offset_sum[i] / OFFSET_SAMPLES;
                if (offsets[i] < 1024.0f || offsets[i] > 3072.0f)
                {
                    calibrated = 2U;
                    motor_off(FAULT_OFFSET);
                }
            }
        }
        goto done;
    }
    for (i = 0; i < 3U; i++)
    {
        current[i] = ((float)raw[i] - offsets[i]) * CURRENT_GAIN;
        if (state >= MOTOR_ALIGN && state <= MOTOR_RUN)
        {
            float magnitude = fabsf(current[i]);
            if (magnitude > peak_current) peak_current = magnitude;
            if (magnitude > CURRENT_LIMIT || raw[i] < 16U || raw[i] > 4079U)
                motor_off(FAULT_CURRENT);
        }
    }
    if (state < MOTOR_ALIGN || state > MOTOR_RUN) goto done;
    if (vbus < VBUS_MIN || vbus > VBUS_MAX)
    {
        motor_off(FAULT_VBUS);
        goto done;
    }
    /* Both motor modes own shared eMATH only here, on logical CPU0.
     * No thread, nested interrupt or CPU1 code may use that peripheral. */
    if (rt_hw_cpu_id() != 0)
    {
        motor_off(FAULT_OBSERVER);
        goto done;
    }
    if (sensorless_mode)
    {
        float ia = current[0];
        float ib = (current[0] + 2.0f * current[1]) * 0.577350269f;
        uint32_t control_entered = DWT->CYCCNT;
        motor_sensorless_step(&control, ia, ib, applied_alpha, applied_beta, vbus);
        control_last_cycles = DWT->CYCCNT - control_entered;
        if (control_last_cycles > control_max_cycles) control_max_cycles = control_last_cycles;
        if (control.stage == SL_FAULT)
        {
            motor_off(FAULT_OBSERVER);
            goto done;
        }
        motor_voltage_ab(control.v_alpha, control.v_beta);
        frequency = control.stage == SL_CLOSED ? control.speed_hz : control.forced_hz;
        if (align_count < 3U)
        {
            if (align_count == 2U)
            {
                for (i = 0; i < 3U; i++)
                    EPWM_clearTripZoneFlag(pwm[i], EPWM_TZ_FLAG_OST);
                GPIO_setPin(GPIO_23);
            }
            else applied_alpha = applied_beta = 0.0f;
            align_count++;
        }
        state = control.stage == SL_ALIGN ? MOTOR_ALIGN :
                (control.stage == SL_CLOSED ? MOTOR_RUN : MOTOR_RAMP);
        goto done;
    }
    if (state == MOTOR_ALIGN)
    {
        motor_voltage(ALIGN_VOLTS);
        /* Two triggers let all three CMPA shadows load before gate enable. */
        if (align_count == 2U)
        {
            for (i = 0; i < 3U; i++)
                EPWM_clearTripZoneFlag(pwm[i], EPWM_TZ_FLAG_OST);
            GPIO_setPin(GPIO_23);
        }
        if (++align_count >= (uint32_t)(sample_hz * 0.5f)) state = MOTOR_RAMP;
    }
    else
    {
        float step = RAMP_HZ_PER_S / sample_hz;
        float hz = frequency;
        if (hz < target_hz) { hz += step; if (hz > target_hz) hz = target_hz; }
        if (hz > target_hz) { hz -= step; if (hz < target_hz) hz = target_hz; }
        frequency = hz;
        phase += hz / sample_hz;
        if (phase >= 1.0f) phase -= 1.0f;
        if (phase < 0.0f) phase += 1.0f;
        /* Ramp voltage with frequency instead of stepping it after alignment. */
        motor_voltage(ALIGN_VOLTS + (target_volts - ALIGN_VOLTS) *
                      fabsf(hz / target_hz));
        if (hz == target_hz) state = MOTOR_RUN;
    }
done:
    {
        uint32_t elapsed = DWT->CYCCNT - entered;
        isr_last_cycles = elapsed;
        if (elapsed > isr_max_cycles) isr_max_cycles = elapsed;
    }
    return;
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
    sample_hz = (float)tbclk / (2.0f * period);
    motor_sensorless_init(&control, sample_hz);
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
    NVIC_SetPriority(ADCA_CONV_IRQn, 2U);
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

static void motor_entry(void *parameter)
{
    uint32_t last_adc = 0, stale = 0;
    RT_UNUSED(parameter);
    motor_hw_init();
    while (1)
    {
        rt_base_t level = rt_hw_local_irq_disable();
        uint32_t command = request;
        __DMB();
        if (command == 2U) motor_off(FAULT_NONE);
        if ((command == 1U || command == 3U) && state == MOTOR_IDLE && calibrated == 1U)
        {
            if (vbus < VBUS_MIN || vbus > VBUS_MAX) motor_off(FAULT_VBUS);
            else
            {
                target_hz = requested_hz;
                target_volts = requested_volts;
                sensorless_mode = command == 3U;
                if (sensorless_mode)
                    motor_sensorless_start(&control, requested_rpm, requested_current);
                applied_alpha = applied_beta = 0.0f;
                phase = frequency = peak_current = 0.0f;
                isr_last_cycles = isr_max_cycles = 0U;
                control_last_cycles = 0U;
                control_max_cycles = 0U;
                align_count = 0U;
                /* ISR preloads alignment duty, then releases the gate. */
                state = MOTOR_ALIGN;
            }
        }
        if (command == 4U && sensorless_mode && state == MOTOR_RUN)
            (void)motor_sensorless_set_speed(&control, requested_rpm);
        request = 0U;
        if (adc_count == last_adc) stale++;
        else stale = 0U;
        last_adc = adc_count;
        if (stale >= 10U) motor_off(FAULT_ADC);
        rt_hw_local_irq_enable(level);
        rt_thread_mdelay(1);
    }
}

static void motor_status(void)
{
    struct
    {
        enum motor_state state;
        enum motor_fault fault;
        unsigned ready, calibrated, adc, overflows, mode, stage, error, transitions;
        unsigned isr_last, isr_max;
        unsigned control_last, control_max;
        unsigned sincos_last, sincos_max, sincos_calls;
        unsigned trig_last, trig_max, trig_calls;
        unsigned sqrt_last, sqrt_max, sqrt_calls;
        uint16_t raw[4];
        float hz, bus, current[3], peak, target, speed, pll_speed, forced;
        float id, iq, iq_ref, emf, pll_error, lock_time, blend, angle, forced_angle, current_error;
    } s;
    unsigned i;
    rt_base_t level = rt_hw_local_irq_disable();
    s.state = state;
    s.fault = fault;
    s.ready = ready;
    s.calibrated = calibrated;
    s.adc = adc_count;
    s.overflows = adc_overflows;
    s.mode = sensorless_mode;
    s.isr_last = isr_last_cycles;
    s.isr_max = isr_max_cycles;
    s.control_last = control_last_cycles;
    s.control_max = control_max_cycles;
    s.sincos_last = control.emath_sincos_last_cycles;
    s.sincos_max = control.emath_sincos_max_cycles;
    s.sincos_calls = control.emath_sincos_calls;
    s.trig_last = control.emath_trig_last_cycles;
    s.trig_max = control.emath_trig_max_cycles;
    s.trig_calls = control.emath_trig_calls;
    s.sqrt_last = control.emath_sqrt_last_cycles;
    s.sqrt_max = control.emath_sqrt_max_cycles;
    s.sqrt_calls = control.emath_sqrt_calls;
    s.hz = frequency;
    s.bus = vbus;
    s.peak = peak_current;
    for (i = 0; i < 4U; i++) s.raw[i] = raw[i];
    for (i = 0; i < 3U; i++) s.current[i] = current[i];
    s.stage = control.stage;
    s.error = control.fault;
    s.transitions = control.transitions;
    s.target = control.target_rpm;
    s.speed = control.speed_hz;
    s.pll_speed = control.estimated_hz;
    s.forced = control.forced_hz;
    s.id = control.id;
    s.iq = control.iq;
    s.iq_ref = control.iq_target;
    s.emf = control.emf_volts;
    s.pll_error = control.pll_error;
    s.lock_time = control.lock_time;
    s.blend = control.blend;
    s.angle = control.angle;
    s.forced_angle = control.forced_angle;
    s.current_error = control.current_error;
    rt_hw_local_irq_enable(level);
    /* Print only the coherent snapshot, with interrupts enabled. */
    rt_kprintf("motor %s fault=%s ready=%u cal=%u pwm=%uHz adc=%u overflow=%u\n",
               state_names[s.state], fault_names[s.fault], s.ready, s.calibrated,
               (unsigned)sample_hz, s.adc, s.overflows);
    rt_kprintf("electrical_mHz=%d vbus_mV=%d I_mA=%d,%d,%d peak_mA=%d raw=%u,%u,%u,%u\n",
               (int)(s.hz * 1000.0f), (int)(s.bus * 1000.0f),
               (int)(s.current[0] * 1000.0f), (int)(s.current[1] * 1000.0f),
               (int)(s.current[2] * 1000.0f), (int)(s.peak * 1000.0f),
               s.raw[0], s.raw[1], s.raw[2], s.raw[3]);
    rt_kprintf("cpu_hz=%u isr_cycles=%u/%u ISR_ns=%u control_cycles=%u/%u\n",
               (unsigned)RCC_getCpuclkFrequency(), s.isr_last, s.isr_max,
               (unsigned)((uint64_t)s.isr_max * 1000000000U / RCC_getCpuclkFrequency()),
               s.control_last, s.control_max);
    if (s.mode)
    {
        rt_kprintf("loop=%s err=%u target_rpm=%d est_rpm=%d pll_rpm=%d forced_rpm=%d\n",
                   s.state == MOTOR_IDLE ? "stopped" : loop_names[s.stage],
                   s.error, (int)s.target, (int)(s.speed * 30.0f),
                   (int)(s.pll_speed * 30.0f), (int)(s.forced * 30.0f));
        rt_kprintf("Idq_mA=%d,%d Iqref_mA=%d emf_mV=%d pll_mrad=%d lock_ms=%u blend_pct=%u\n",
                   (int)(s.id * 1000.0f), (int)(s.iq * 1000.0f), (int)(s.iq_ref * 1000.0f),
                   (int)(s.emf * 1000.0f), (int)(s.pll_error * 1000.0f),
                   (unsigned)(s.lock_time * 1000.0f), (unsigned)(s.blend * 100.0f));
        /* Keep each formatted line within RT_CONSOLEBUF_SIZE (128 bytes). */
        rt_kprintf("transitions=%u angle_mrad=%d forced_mrad=%d current_error_mA=%d\n",
                   s.transitions,
                   (int)(s.angle * 1000.0f), (int)(s.forced_angle * 1000.0f),
                   (int)(s.current_error * 1000.0f));
        rt_kprintf("emath_sincos=%u/%u/%u emath_trig=%u/%u/%u\n",
                   s.sincos_last, s.sincos_max, s.sincos_calls,
                   s.trig_last, s.trig_max, s.trig_calls);
        rt_kprintf("emath_sqrt=%u/%u/%u\n",
                   s.sqrt_last, s.sqrt_max, s.sqrt_calls);
    }
}

static int motor(int argc, char **argv)
{
    if (argc == 1 || (argc == 2 && !rt_strcmp(argv[1], "status")))
    {
        motor_status();
        return RT_EOK;
    }
    if (argc == 2 && !rt_strcmp(argv[1], "stop"))
    {
        request = 2U;
        return RT_EOK;
    }
    if (argc >= 2 && argc <= 4 && !rt_strcmp(argv[1], "closed"))
    {
        char *end;
        float rpm = 500.0f, amps = 0.8f;
        if (argc >= 3) { rpm = strtof(argv[2], &end); if (end == argv[2] || *end) return -RT_EINVAL; }
        if (argc == 4) { amps = strtof(argv[3], &end); if (end == argv[3] || *end) return -RT_EINVAL; }
        if (!isfinite(rpm) || !isfinite(amps) || fabsf(rpm) < 350.0f || fabsf(rpm) > 800.0f ||
            amps < 0.5f || amps > 1.2f) return -RT_EINVAL;
        if (!ready || calibrated != 1U || state != MOTOR_IDLE || request)
        {
            rt_kprintf("motor: state=%s cal=%u; use motor stop before starting\n",
                       state_names[state], calibrated);
            return -RT_EBUSY;
        }
        requested_rpm = rpm;
        requested_current = amps;
        __DMB();
        request = 3U;
        rt_kprintf("motor: sensorless start requested; acquisition timeout 10 s\n");
        return RT_EOK;
    }
    if (argc == 3 && !rt_strcmp(argv[1], "speed"))
    {
        char *end;
        float rpm = strtof(argv[2], &end);
        if (end == argv[2] || *end || !isfinite(rpm) || fabsf(rpm) < 350.0f || fabsf(rpm) > 800.0f ||
            rpm * control.target_rpm <= 0.0f) return -RT_EINVAL;
        if (!sensorless_mode || state != MOTOR_RUN || control.stage != SL_CLOSED || request) return -RT_EBUSY;
        requested_rpm = rpm;
        __DMB();
        request = 4U;
        return RT_EOK;
    }
    if (argc >= 2 && argc <= 4 && !rt_strcmp(argv[1], "start"))
    {
        char *end;
        float hz = DEFAULT_HZ, volts = RUN_VOLTS;
        if (argc >= 3) { hz = strtof(argv[2], &end); if (end == argv[2] || *end) return -RT_EINVAL; }
        if (argc == 4) { volts = strtof(argv[3], &end); if (end == argv[3] || *end) return -RT_EINVAL; }
        if (!isfinite(hz) || !isfinite(volts) || fabsf(hz) < 0.5f || fabsf(hz) > 10.0f ||
            volts < ALIGN_VOLTS || volts > 2.0f) return -RT_EINVAL;
        if (!ready || calibrated != 1U || state != MOTOR_IDLE || request)
        {
            rt_kprintf("motor: state=%s cal=%u; use motor stop before starting\n",
                       state_names[state], calibrated);
            return -RT_EBUSY;
        }
        requested_hz = hz;
        requested_volts = volts;
        __DMB();
        request = 1U;
        rt_kprintf("motor: start requested; use motor status to check\n");
        return RT_EOK;
    }
    rt_kprintf("motor status | start [Hz] [V] | closed [rpm 350..800] [A 0.5..1.2] | speed <rpm> | stop\n");
    return -RT_EINVAL;
}
MSH_CMD_EXPORT(motor, open loop or sensorless FOC control);

static int motor_app_init(void)
{
    static struct rt_thread thread;
    static rt_uint8_t stack[1536];
    rt_err_t result = rt_thread_init(&thread, "motor", motor_entry, RT_NULL,
                                    stack, sizeof(stack), 16U, 10U);
    if (result != RT_EOK) return result;
    /* Hardware CPU1 owns these peripherals; RT-Thread calls it CPU0. */
    result = rt_thread_control(&thread, RT_THREAD_CTRL_BIND_CPU, (void *)(rt_ubase_t)0);
    if (result != RT_EOK) return result;
    return rt_thread_startup(&thread);
}
INIT_APP_EXPORT(motor_app_init);
