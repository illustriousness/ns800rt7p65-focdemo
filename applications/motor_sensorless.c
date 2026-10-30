/* Two-current FOC with a sliding-mode back-EMF observer and independent PLL.
 * Motor initial estimates: Y phase Rs=0.2 ohm, Ls=0.4 mH, two pole pairs.
 * These are bring-up values, not parameter identification results.
 * Observer model: Microchip AN1078/AN4398; implementation is board-local. */
#include "motor_sensorless.h"
#include <math.h>
#include <string.h>
#include <stddef.h>

#ifdef NS800_EMATH_TARGET
#include "emath.h"
#endif

#define PI          3.14159265358979323846f
#define TWO_PI      (2.0f * PI)
#define POLE_PAIRS  2.0f
#define RS          0.2f
#define LS          0.0004f
#define CURRENT_KP  0.5f
#define CURRENT_KI  250.0f
#define SMO_GAIN    6.0f
#define SMO_BAND    0.8f
#define EMF_POLE    800.0f
#define PLL_KP      200.0f
#define PLL_KI      10000.0f
#define SPEED_KP    0.0015f
#define SPEED_KI    0.004f
#define IQ_LIMIT    1.2f

static float limit(float value, float low, float high)
{
    return value < low ? low : (value > high ? high : value);
}

#ifdef NS800_EMATH_TARGET
static inline uint32_t sensorless_dwt_now(void)
{
    __asm volatile("" ::: "memory");
    return DWT->CYCCNT;
}
#endif

static float sensorless_sqrt(struct motor_sensorless *s, float value)
{
#ifdef NS800_EMATH_TARGET
    uint32_t entered = sensorless_dwt_now();
    float result = EMATH_sqrtF32(value);
    uint32_t elapsed = sensorless_dwt_now() - entered;
    s->emath_sqrt_last_cycles = elapsed;
    if (elapsed > s->emath_sqrt_max_cycles) s->emath_sqrt_max_cycles = elapsed;
    s->emath_sqrt_calls++;
    return result;
#else
    (void)s;
    return sqrtf(value);
#endif
}

static float sensorless_atan2(struct motor_sensorless *s, float y, float x)
{
#ifdef NS800_EMATH_TARGET
    uint32_t entered = sensorless_dwt_now();
    float result = EMATH_atan2F32(y, x);
    uint32_t elapsed = sensorless_dwt_now() - entered;
    s->emath_trig_last_cycles = elapsed;
    if (elapsed > s->emath_trig_max_cycles) s->emath_trig_max_cycles = elapsed;
    s->emath_trig_calls++;
    return result;
#else
    (void)s;
    return atan2f(y, x);
#endif
}

static float sensorless_atan(struct motor_sensorless *s, float value)
{
#ifdef NS800_EMATH_TARGET
    uint32_t entered = sensorless_dwt_now();
    float result = EMATH_atanF32(value, 1.0f);
    uint32_t elapsed = sensorless_dwt_now() - entered;
    s->emath_trig_last_cycles = elapsed;
    if (elapsed > s->emath_trig_max_cycles) s->emath_trig_max_cycles = elapsed;
    s->emath_trig_calls++;
    return result;
#else
    (void)s;
    return atanf(value);
#endif
}

static float wrap(float angle)
{
    if (angle >= PI) angle -= TWO_PI;
    if (angle < -PI) angle += TWO_PI;
    return angle;
}

static void sincos_angle(struct motor_sensorless *s, float angle,
                         float *sn, float *cs)
{
#ifdef NS800_EMATH_TARGET
    uint32_t entered = sensorless_dwt_now();
    EMATH_sincosF32(angle, sn, cs);
    uint32_t elapsed = sensorless_dwt_now() - entered;
    s->emath_sincos_last_cycles = elapsed;
    if (elapsed > s->emath_sincos_max_cycles)
        s->emath_sincos_max_cycles = elapsed;
    s->emath_sincos_calls++;
    return;
#else
    (void)s;
    *sn = sinf(angle);
    *cs = cosf(angle);
#endif
}

void motor_sensorless_init(struct motor_sensorless *s, float sample_hz)
{
    memset(s, 0, sizeof(*s));
    s->dt = 1.0f / sample_hz;
}

void motor_sensorless_start(struct motor_sensorless *s, float rpm, float current)
{
    /* Retain the sample period; reset dynamic states and timing counters. */
    float dt = s->dt;
    memset(s, 0, sizeof(*s));
    s->dt = dt;
    s->target_rpm = rpm;
    s->startup_current = current;
}

int motor_sensorless_set_speed(struct motor_sensorless *s, float rpm)
{
    if (s->stage != SL_CLOSED || !isfinite(rpm) || fabsf(rpm) < 350.0f ||
        fabsf(rpm) > 800.0f || rpm * s->target_rpm <= 0.0f) return -1;
    s->target_rpm = rpm;
    return 0;
}

static void observer(struct motor_sensorless *s, float ia, float ib,
                      float va, float vb)
{
    float za = SMO_GAIN * limit((s->estimated_i_alpha - ia) / SMO_BAND, -1.0f, 1.0f);
    float zb = SMO_GAIN * limit((s->estimated_i_beta - ib) / SMO_BAND, -1.0f, 1.0f);
    float k = s->dt * EMF_POLE / (1.0f + s->dt * EMF_POLE);
    s->estimated_i_alpha = limit(s->estimated_i_alpha + s->dt / LS *
                                (va - RS * s->estimated_i_alpha - za), -10.0f, 10.0f);
    s->estimated_i_beta = limit(s->estimated_i_beta + s->dt / LS *
                               (vb - RS * s->estimated_i_beta - zb), -10.0f, 10.0f);
    s->emf_alpha += k * (za - s->emf_alpha);
    s->emf_beta += k * (zb - s->emf_beta);

    /* PLL at 2 kHz. The observer itself stays at the ADC/PWM rate. */
    if (s->cycles % 10U == 0U)
    {
        float dt = 10.0f * s->dt;
        float direction = s->target_rpm > 0.0f ? 1.0f : -1.0f;
        float omega, measured;
        s->emf_volts = sensorless_sqrt(s, s->emf_alpha * s->emf_alpha +
                                       s->emf_beta * s->emf_beta);
        if (s->emf_volts > 0.15f)
        {
            measured = sensorless_atan2(s, -direction * s->emf_alpha,
                                        direction * s->emf_beta);
            /* Compensate the first-order back-EMF filter's phase lag. */
            measured = wrap(measured + sensorless_atan(s,
                                                       TWO_PI * s->estimated_hz / EMF_POLE));
            s->pll_error = wrap(measured - s->pll_angle);
            s->pll_integral = limit(s->pll_integral + PLL_KI * dt * s->pll_error,
                                    -TWO_PI * 50.0f, TWO_PI * 50.0f);
            omega = limit(s->pll_integral + PLL_KP * s->pll_error,
                           -TWO_PI * 50.0f, TWO_PI * 50.0f);
            s->estimated_hz += 0.08f * (omega / TWO_PI - s->estimated_hz);
            s->pll_omega = omega;
        }
        else
        {
            s->pll_integral *= 0.98f;
            s->estimated_hz *= 0.98f;
            s->pll_omega = 0.0f;
            s->pll_error = PI;
        }
    }
    s->pll_angle = wrap(s->pll_angle + s->dt * s->pll_omega);
}

static int observation_valid(const struct motor_sensorless *s)
{
    float hz = fabsf(s->forced_hz);
    return hz >= 8.0f && s->emf_volts > 0.35f &&
           fabsf(s->estimated_hz - s->forced_hz) < 0.25f * hz &&
           fabsf(wrap(s->pll_angle - s->forced_angle)) < 1.05f &&
           fabsf(s->pll_error) < 0.35f;
}

static float current_pi(float error, float *integral, float dt, float max_voltage)
{
    float proposed = *integral + CURRENT_KI * dt * error;
    float output = CURRENT_KP * error + proposed;
    if (fabsf(output) <= max_voltage || output * error < 0.0f)
        *integral = limit(proposed, -max_voltage, max_voltage);
    return limit(CURRENT_KP * error + *integral, -max_voltage, max_voltage);
}

void motor_sensorless_step(struct motor_sensorless *s, float ia, float ib,
                           float applied_alpha, float applied_beta, float vbus)
{
    float sn, cs, id_target = 0.0f, iq_target = 0.0f;
    float max_voltage = fminf(6.0f, 0.35f * vbus), magnitude;
    float ramp_step = (150.0f * POLE_PAIRS / 60.0f) * s->dt;
    float target_hz = s->target_rpm * POLE_PAIRS / 60.0f;
    if (!isfinite(ia) || !isfinite(ib) || !isfinite(applied_alpha) ||
        !isfinite(applied_beta) || !isfinite(vbus) || vbus < 1.0f ||
        !isfinite(s->dt) || s->dt <= 0.0f)
    {
        s->fault = SL_NUMERIC;
        s->stage = SL_FAULT;
        s->v_alpha = s->v_beta = 0.0f;
        return;
    }
    s->cycles++;
    s->elapsed += s->dt;
    observer(s, ia, ib, applied_alpha, applied_beta);
    /* Reject commutation/EMF harmonics before the outer speed PI. The raw
     * PLL speed remains available for lock tests and diagnostics. */
    s->speed_hz += (30.0f * s->dt / (1.0f + 30.0f * s->dt)) *
                   (s->estimated_hz - s->speed_hz);
    if (s->stage == SL_ALIGN)
    {
        s->angle = 0.0f;
        id_target = 0.5f;
        if (s->elapsed >= 0.5f) { s->stage = SL_START; s->elapsed = 0.0f; }
    }
    else if (s->stage == SL_START || s->stage == SL_BLEND)
    {
        s->forced_hz += limit(target_hz - s->forced_hz, -ramp_step, ramp_step);
        s->forced_angle = wrap(s->forced_angle + TWO_PI * s->dt * s->forced_hz);
        s->angle = s->forced_angle;
        id_target = 0.5f + (s->startup_current - 0.5f) * fminf(s->elapsed / 0.2f, 1.0f);
        if (s->stage == SL_START)
        {
            if (fabsf(s->forced_hz - target_hz) < 0.1f && observation_valid(s)) s->lock_time += s->dt;
            else s->lock_time = 0.0f;
            if (s->lock_time >= 0.4f)
            {
                float delta = wrap(s->pll_angle - s->forced_angle);
                float delta_sin;
                float delta_cos;
                sincos_angle(s, delta, &delta_sin, &delta_cos);
                (void)delta_cos;
                s->speed_integral = limit(-s->startup_current * delta_sin,
                                           -IQ_LIMIT, IQ_LIMIT);
                s->stage = SL_BLEND;
                s->elapsed = 0.0f;
            }
            if (s->elapsed >= 10.0f) { s->fault = SL_NO_LOCK; s->stage = SL_FAULT; }
        }
        else
        {
            s->blend = fminf(s->elapsed, 1.0f);
            s->angle = wrap(s->forced_angle + s->blend * wrap(s->pll_angle - s->forced_angle));
            id_target = s->startup_current * (1.0f - s->blend);
            if (!observation_valid(s)) s->lost_time += s->dt;
            else s->lost_time = 0.0f;
            if (s->lost_time >= 0.2f) { s->fault = SL_LOST_LOCK; s->stage = SL_FAULT; }
            if (s->blend >= 1.0f) { s->stage = SL_CLOSED; s->transitions++; s->elapsed = 0.0f; }
        }
    }
    else if (s->stage == SL_CLOSED)
    {
        /* Forced angle is no longer advanced or used after handover. */
        s->angle = s->pll_angle;
        if (s->emf_volts < 0.2f || s->estimated_hz * target_hz <= 0.0f ||
            fabsf(s->pll_error) > 0.7f) s->lost_time += s->dt;
        else s->lost_time = 0.0f;
        if (s->lost_time >= 0.1f) { s->fault = SL_LOST_LOCK; s->stage = SL_FAULT; }
    }
    if (s->stage == SL_BLEND || s->stage == SL_CLOSED)
    {
        float error = s->target_rpm - s->speed_hz * 60.0f / POLE_PAIRS;
        /* Speed PI at 1 kHz, current PI at 20 kHz. */
        if (s->cycles % 20U == 0U)
        {
            float proposed = s->speed_integral + SPEED_KI * (20.0f * s->dt) * error;
            float output = SPEED_KP * error + proposed;
            if (fabsf(output) <= IQ_LIMIT || output * error < 0.0f)
                s->speed_integral = limit(proposed, -IQ_LIMIT, IQ_LIMIT);
        }
        iq_target = limit(SPEED_KP * error + s->speed_integral, -IQ_LIMIT, IQ_LIMIT);
        if (s->stage == SL_BLEND) iq_target *= s->blend;
    }
    s->iq_target = iq_target;
    sincos_angle(s, s->angle, &sn, &cs);
    s->id = cs * ia + sn * ib;
    s->iq = -sn * ia + cs * ib;
    s->current_error = fmaxf(fabsf(id_target - s->id), fabsf(iq_target - s->iq));
    s->vd = current_pi(id_target - s->id, &s->integral_d, s->dt, max_voltage);
    s->vq = current_pi(iq_target - s->iq, &s->integral_q, s->dt, max_voltage);
    magnitude = sensorless_sqrt(s, s->vd * s->vd + s->vq * s->vq);
    if (magnitude > max_voltage)
    {
        s->vd *= max_voltage / magnitude;
        s->vq *= max_voltage / magnitude;
        /* Track vector saturation as well as each axis's own limit. */
        s->integral_d = s->vd - CURRENT_KP * (id_target - s->id);
        s->integral_q = s->vq - CURRENT_KP * (iq_target - s->iq);
    }
    s->v_alpha = cs * s->vd - sn * s->vq;
    s->v_beta = sn * s->vd + cs * s->vq;
    if (!isfinite(s->v_alpha) || !isfinite(s->v_beta) || !isfinite(s->estimated_hz))
    {
        s->fault = SL_NUMERIC;
        s->stage = SL_FAULT;
    }
    if (s->stage == SL_FAULT) s->v_alpha = s->v_beta = 0.0f;
}
