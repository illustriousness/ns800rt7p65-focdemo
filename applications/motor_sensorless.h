#ifndef MOTOR_SENSORLESS_H
#define MOTOR_SENSORLESS_H

#include <stdint.h>

enum sensorless_stage { SL_ALIGN, SL_START, SL_BLEND, SL_CLOSED, SL_FAULT };
enum sensorless_fault { SL_OK, SL_NO_LOCK, SL_LOST_LOCK, SL_NUMERIC };

struct motor_sensorless
{
    enum sensorless_stage stage;
    enum sensorless_fault fault;
    float dt, target_rpm, startup_current;
    float forced_angle, forced_hz, angle, estimated_hz, speed_hz;
    float id, iq, iq_target, vd, vq, v_alpha, v_beta;
    float estimated_i_alpha, estimated_i_beta, emf_alpha, emf_beta;
    float emf_volts, pll_angle, pll_integral, pll_error, pll_omega;
    float integral_d, integral_q, speed_integral;
    float elapsed, blend, lock_time, lost_time, current_error;
    uint32_t cycles, transitions;
    uint32_t emath_sincos_last_cycles, emath_sincos_max_cycles, emath_sincos_calls;
    uint32_t emath_trig_last_cycles, emath_trig_max_cycles, emath_trig_calls;
    uint32_t emath_sqrt_last_cycles, emath_sqrt_max_cycles, emath_sqrt_calls;
};

void motor_sensorless_init(struct motor_sensorless *s, float sample_hz);
void motor_sensorless_start(struct motor_sensorless *s, float rpm, float current);
/* Target step() runs exclusively in the logical CPU0 ADCA ISR and always
 * uses shared eMATH. Host builds use libm as the simulation reference. */
/* Voltage is the actually applied previous PWM cycle, after duty quantization
 * and dead-time estimation. No forced angle/speed enters the observer. */
void motor_sensorless_step(struct motor_sensorless *s, float ia, float ib,
                           float applied_alpha, float applied_beta, float vbus);
int motor_sensorless_set_speed(struct motor_sensorless *s, float rpm);

#endif
