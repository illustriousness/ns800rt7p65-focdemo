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
static EPWM_TypeDef *const pwm[3] = {EPWM8, EPWM9, EPWM10};
static uint16_t period;
static volatile uint16_t raw[3];
static uint32_t offset_sum[3];
static float offsets[3];
static volatile float current[3], vbus;
static volatile uint32_t offset_count, running;
static volatile uint32_t adc_overflow_streak;
static struct foc_mailbox command_mailbox;
static struct foc_snapshot_channel status_channel;
static int command_result;
/* Communications-core state only; boot owner is always CAN. */
static enum ns800_foc_owner control_owner = FOC_OWNER_CAN;
static uint32_t owner_pending, owner_stop_seq;
_Static_assert(sizeof(struct ns800_foc_status) == FOC_SNAPSHOT_WORDS * sizeof(uint32_t),
               "FOC status must exactly fill the six-word snapshot channel");
static volatile uint32_t fault; /* packed error survives STOP and library state reset */
static uint32_t align_count, high_count;
static struct foc_sensorless_monitor sensorless;
void ADCA_CONV_IRQHandler(void);
static void foc_status_publish(void);

static void pwm_safe_off(enum ns800_foc_error_source reason)
{
    GPIO_clearPin(GPIO_23);
    for (unsigned i = 0; i < 3; ++i)
        EPWM_forceTripZoneEvent(pwm[i], EPWM_TZ_FORCE_EVENT_OST);
    running = 0;
    if (reason != FOC_ERROR_NONE)
    {
        fault = (uint32_t)reason << 16;
        if (reason == FOC_ERROR_LIBRARY) fault |= (uint32_t)Sguan.status & 0xFFFFU;
    }
    /* Sampling keeps running, including while stopped or faulted. */
}

void ns800_foc_user_start(void) { /* Gates remain off until initialization ends. */ }
#include "speed_diag.h"
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
        if(d<.1f || d>.9f) sd_pwm_clips++;
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
}


void ns800_foc_user_initial(void) { motor_hw_init(); }

PORT_FAST void ADCA_CONV_IRQHandler(void)
{
    uint32_t entered=DWT->CYCCNT;sd_adc++;
    for (unsigned i = 0; i < 3; ++i) raw[i] = ADC_readResult(ADCARESULT, (ADC_SOCNumber)i);
    vbus = ADC_readResult(ADCARESULT, ADC_SOC_NUMBER3) * VBUS_GAIN;
    if (ADC_getInterruptOverflowStatus(ADCA, ADC_INT_NUMBER1))
    {
        sd_overflow++;
        if(running) sd_stop(2);
        if (adc_overflow_streak < 1000U) adc_overflow_streak++;
        /* A single deferred conversion can occur while the shell/RTOS
         * briefly masks interrupts. Only a persistent ADC overrun is a
         * control fault. */
        if (running && adc_overflow_streak >= 3U) pwm_safe_off(FOC_ERROR_ADC);
        ADC_clearInterruptOverflowStatus(ADCA, ADC_INT_NUMBER1);
    }
    else adc_overflow_streak = 0U;
    ADC_clearInterruptStatus(ADCA, ADC_INT_NUMBER1);
    if (offset_count < OFFSET_SAMPLES)
    {
        for (unsigned i = 0; i < 3; ++i) offset_sum[i] += raw[i];
        if (++offset_count == OFFSET_SAMPLES)
        {
            for (unsigned i = 0; i < 3; ++i)
                offsets[i] = (float)offset_sum[i] / OFFSET_SAMPLES;
        }
        goto sd_done;
    }
    for (unsigned i = 0; i < 3; ++i)
        current[i] = (raw[i] - offsets[i]) * CURRENT_GAIN;
    if (!running) goto sd_done;
    if(!sd_guard()) goto sd_done;
    for (unsigned i = 0; i < 3; ++i)
        if (!isfinite(current[i]) || fabsf(current[i]) >= FOC_PHASE_LIMIT_A)
        { pwm_safe_off(FOC_ERROR_CURRENT); return; }
    if (!isfinite(vbus) || vbus < FOC_BUS_MIN_V || vbus > FOC_BUS_MAX_V)
    { pwm_safe_off(FOC_ERROR_BUS); return; }
    if (!isfinite(Sguan.encoder.Real_Speed) ||
        fabsf(Sguan.encoder.Real_Speed) > FOC_EST_OVERSPEED_RPM*Value_2PI/60.0f)
    { pwm_safe_off(FOC_ERROR_SPEED); return; }
    Sguan.foc.Real_VBUS = vbus;
    uint32_t control_entered=DWT->CYCCNT;
    SguanFOC_High_Loop();
    sd_control_last=DWT->CYCCNT-control_entered;
    if(sd_control_last>sd_control_max) sd_control_max=sd_control_last;
    float vm=Sguan.foc.Ud_in*Sguan.foc.Ud_in+Sguan.foc.Uq_in*Sguan.foc.Uq_in;
    if(vm>.98f*.43f*.43f*vbus*vbus) sd_saturated++;
    if (++high_count % 20U == 0)
    {
        SguanFOC_Low_Loop();
        if (!foc_sensorless_tick(&sensorless, &Sguan)) pwm_safe_off(FOC_ERROR_OBSERVER);
    }
    if (Sguan.status >= MOTOR_STATUS_OVERVOLTAGE)
    { pwm_safe_off(FOC_ERROR_LIBRARY); goto sd_done; }
    if (!running) goto sd_done;
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
sd_done:
    sd_last=DWT->CYCCNT-entered;if(sd_last>sd_max) sd_max=sd_last;
    if(running && (sd_last==0 || sd_last>=20000U)) sd_stop(3);
}

static int foc_execute_request(const struct foc_request *request)
{
    if (offset_count < OFFSET_SAMPLES) return -RT_EBUSY;
    if (request->operation == FOC_RESET_FAULT)
    {
        rt_base_t level = rt_hw_local_irq_disable();
        int result = -RT_EBUSY;
        int healthy = !fault || (vbus >= FOC_BUS_MIN_V && vbus <= FOC_BUS_MAX_V);
        if (fault)
            for (unsigned i = 0; i < 3; ++i)
                healthy = healthy && fabsf(current[i]) < Sguan.safe.Current_limit;
        if (!running && adc_overflow_streak < 3U && healthy)
        {
            Sguan.Func_Stop();
            foc_sensorless_reset(&sensorless);
            fault = 0;
            result = RT_EOK;
        }
        rt_hw_local_irq_enable(level);
        return result;
    }
    float minimum = request->operation == FOC_START ? FOC_START_MIN_RPM : FOC_RUN_MIN_RPM;
    float maximum = request->operation == FOC_START ? FOC_START_MAX_RPM : FOC_RUN_MAX_RPM;
    if (!isfinite(request->rpm) || fabsf(request->rpm) < minimum || fabsf(request->rpm) > maximum ||
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
    int busy = running || fault != 0;
    rt_hw_local_irq_enable(level);
    if (request->operation != FOC_START) return -RT_EINVAL;
    if (busy) return -RT_EBUSY;
    for(unsigned i=0;i<3;i++) if(fabsf(current[i])>=.2f) return -RT_EINVAL;
    sd_reset();

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
    adc_overflow_streak = 0;
    align_count = high_count = 0;
    running = 1;
    rt_hw_local_irq_enable(level);
    return RT_EOK;
}

static void sguan_main_entry(void *unused)
{
    RT_UNUSED(unused);
    sd_reset();
    SguanFOC_main_Loop(); /* Peripheral init with gates disabled. */
    while (1)
    {
        if (foc_mailbox_stop_pending(&command_mailbox))
        {
            uint32_t stop = __atomic_load_n(&command_mailbox.stop, __ATOMIC_ACQUIRE);
            uint32_t cancel = __atomic_load_n(&command_mailbox.offered, __ATOMIC_ACQUIRE);
            rt_base_t level = rt_hw_local_irq_disable();
            pwm_safe_off(FOC_ERROR_NONE);
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
        foc_status_publish();
        rt_thread_mdelay(1);
    }
}

/* Only CPU0 reads mutable controller fields. CPU1 never tries to protect
 * these fields by masking its own (unrelated) local interrupts. */
static void foc_status_publish(void)
{
    struct ns800_foc_status s;
    rt_base_t level = rt_hw_local_irq_disable();
    s.state = fault != FOC_ERROR_NONE ? FOC_STATE_FAULT :
              offset_count < OFFSET_SAMPLES ? FOC_STATE_CALIBRATING :
              !running ? FOC_STATE_IDLE :
              align_count < 3U ? FOC_STATE_ARMING :
              sensorless.closed ? FOC_STATE_CLOSED : FOC_STATE_STARTING;
    s.error = fault;
    s.speed = Sguan.encoder.Real_Speed;
    rt_hw_local_irq_enable(level);
    s.command_seq = __atomic_load_n(&command_mailbox.completed, __ATOMIC_RELAXED);
    s.stop_seq = __atomic_load_n(&command_mailbox.stopped, __ATOMIC_RELAXED);
    s.command_result = command_result;
    foc_snapshot_publish(&status_channel, &s, sizeof(s));
    sd_publish(&s);
}

int ns800_foc_status_read(struct ns800_foc_status *status)
{
    if (!status) return -RT_EINVAL;
    return foc_snapshot_read(&status_channel, status, sizeof(*status)) ? RT_EOK : -RT_EBUSY;
}

enum ns800_foc_owner ns800_foc_owner_get(void)
{
    rt_base_t level = rt_hw_local_irq_disable();
    if (owner_pending && !foc_mailbox_stop_pending(&command_mailbox))
    {
        struct ns800_foc_status s;
        if (ns800_foc_status_read(&s) == RT_EOK &&
            (s.state == FOC_STATE_IDLE || s.state == FOC_STATE_FAULT) &&
            (uint32_t)(s.stop_seq-owner_stop_seq) < 0x80000000U)
        { control_owner = (enum ns800_foc_owner)(owner_pending-1U); owner_pending = 0; }
    }
    enum ns800_foc_owner owner = owner_pending ? FOC_OWNER_SWITCHING : control_owner;
    rt_hw_local_irq_enable(level);
    return owner;
}

int ns800_foc_owner_set(enum ns800_foc_owner owner)
{
    if (owner != FOC_OWNER_CAN && owner != FOC_OWNER_UART) return -RT_EINVAL;
    rt_base_t level = rt_hw_local_irq_disable();
    enum ns800_foc_owner previous = ns800_foc_owner_get();
    int result = RT_EOK;
    if (previous == FOC_OWNER_SWITCHING) result = -RT_EBUSY;
    else if (previous != owner)
    {
        foc_mailbox_stop(&command_mailbox);
        owner_stop_seq = __atomic_load_n(&command_mailbox.stop, __ATOMIC_RELAXED);
        owner_pending = (uint32_t)owner+1U;
    }
    rt_hw_local_irq_enable(level);
    return result;
}

static int foc_submit_for_owner(enum ns800_foc_owner owner, enum foc_operation operation,
                                float rpm, float current, uint32_t *sequence)
{
    /* No sleeping/kernel locks in this short local producer critical section.
     * All Shell/CAN producers must be bound to the communications core. */
    rt_base_t level = rt_hw_local_irq_disable();
    int result = RT_EOK;
    if (operation == FOC_STOP)
    {
        foc_mailbox_stop(&command_mailbox);
        if (sequence) *sequence = __atomic_load_n(&command_mailbox.stop, __ATOMIC_RELAXED);
    }
    else
    {
        if (ns800_foc_owner_get() != owner)
        { rt_hw_local_irq_enable(level); return -RT_EBUSY; }
        struct foc_request request = {operation, rpm, current};
        if (foc_mailbox_stop_pending(&command_mailbox) ||
            !foc_mailbox_offer(&command_mailbox, &request))
            result = -RT_EBUSY;
        else if (sequence)
            *sequence = __atomic_load_n(&command_mailbox.offered, __ATOMIC_RELAXED);
    }
    rt_hw_local_irq_enable(level);
    return result;
}

int ns800_foc_submit(enum foc_operation operation, float rpm, float current, uint32_t *sequence)
{
    return foc_submit_for_owner(FOC_OWNER_CAN, operation, rpm, current, sequence);
}

int ns800_foc_request(enum foc_operation operation, float rpm, float current)
{
    return foc_submit_for_owner(FOC_OWNER_UART, operation, rpm, current, NULL);
}

static void foc_status(void)
{
    struct ns800_foc_status s;
    if (ns800_foc_status_read(&s) != RT_EOK)
    { rt_kprintf("motor: status publication busy; retry\n"); return; }
    static const char *const states[] = {"not-ready", "calibrating", "idle", "starting", "closed", "fault", "arming"};
    rt_kprintf("motor status_schema=2 state=%s error=%08x speed_mrad_s=%d command_seq=%u result=%d stop_seq=%u\n",
               states[s.state], s.error, (int)(s.speed * 1000.0f),
               s.command_seq, s.command_result, s.stop_seq);
}

static int foc_cmd(int argc, char **argv)
{
    if (argc >= 2 && !rt_strcmp(argv[1], "owner"))
    {
        static const char *const names[] = {"can", "uart", "switching"};
        if (argc == 3)
        {
            enum ns800_foc_owner owner;
            if (!rt_strcmp(argv[2], "can")) owner = FOC_OWNER_CAN;
            else if (!rt_strcmp(argv[2], "uart")) owner = FOC_OWNER_UART;
            else return -RT_EINVAL;
            int result = ns800_foc_owner_set(owner);
            if (result != RT_EOK) return result;
        }
        else if (argc != 2) return -RT_EINVAL;
        rt_kprintf("motor owner=%s (handover waits for STOP acknowledgement)\n", names[ns800_foc_owner_get()]);
        return RT_EOK;
    }
    if (argc == 1 || (argc == 2 && !rt_strcmp(argv[1], "status"))) { foc_status(); return RT_EOK; }
    if (argc == 2 && !rt_strcmp(argv[1], "stop")) return ns800_foc_request(FOC_STOP, 0, 0);
    if (argc == 2 && !rt_strcmp(argv[1], "reset")) return ns800_foc_request(FOC_RESET_FAULT, 0, 0);
    int start = !rt_strcmp(argv[1], "start") || !rt_strcmp(argv[1], "closed");
    int speed = !rt_strcmp(argv[1], "speed");
    if ((start && argc <= 4) || (speed && argc == 3))
    {
        float rpm = 500, amp = .8f;
        char *end;
        if (argc >= 3) { rpm = strtof(argv[2], &end); if (*end) return -RT_EINVAL; }
        if (argc == 4) { amp = strtof(argv[3], &end); if (*end) return -RT_EINVAL; }
        float minimum = start ? FOC_START_MIN_RPM : FOC_RUN_MIN_RPM;
        float maximum = start ? FOC_START_MAX_RPM : FOC_RUN_MAX_RPM;
        if (!isfinite(rpm) || fabsf(rpm) < minimum || fabsf(rpm) > maximum)
        {
            rt_kprintf("motor: start %d..%d rpm; speed %d..%d rpm\n",
                FOC_START_MIN_RPM, FOC_START_MAX_RPM, FOC_RUN_MIN_RPM, FOC_RUN_MAX_RPM);
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
    rt_kprintf("motor/foc status | owner [can|uart] | start/closed [rpm 350..800] [A .5..1.2] | speed <rpm 350..2500> | stop | reset\n");
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
