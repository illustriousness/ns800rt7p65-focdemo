#ifndef FOC_SENSORLESS_H
#define FOC_SENSORLESS_H

#include <math.h>
#include <stdint.h>
#include "SguanFOC.h"

/* Board-side supervision only: never generate angles or change library gains. */
struct foc_sensorless_monitor {
    uint32_t elapsed_ms, valid_ms, lost_ms;
    unsigned closed;
};

static inline void foc_sensorless_reset(struct foc_sensorless_monitor *state)
{
    *state = (struct foc_sensorless_monitor){0};
}

/* Called at 1 kHz after the library high/low loops. The original IF algorithm
 * selects the observer by Speed_abs; confirmed closed is only a board status. */
static inline int foc_sensorless_tick(struct foc_sensorless_monitor *state,
                                      const SguanFOC_System_STRUCT *motor)
{
    float ea = motor->transfer.SMO.alpha.Output_Ex;
    float eb = motor->transfer.SMO.beta.Output_Ex;
    float reference = motor->foc.Speed_in;
    float speed = motor->encoder.Real_Speed;
    state->elapsed_ms++;
    float emf = sqrtf(ea*ea + eb*eb);
    float threshold = state->closed ? motor->value.Sensorless_Stop : motor->value.Sensorless_AbsMin;
    int observer = motor->value.Speed_abs > threshold;
    if (!isfinite(speed) || !isfinite(reference) || !isfinite(emf)) return 0;
    if (!state->closed)
    {
        int tracking = observer && emf > .35f && speed*reference > 0.0f &&
                       fabsf(speed-reference) < .2f*fabsf(reference);
        state->valid_ms = tracking ? state->valid_ms + 1U : 0U;
        if (state->valid_ms >= 50U) state->closed = 1U;
        return state->closed || state->elapsed_ms < 10000U;
    }
    int lost = !observer || emf < .2f || speed*reference <= 0.0f ||
               fabsf(speed-reference) > .6f*fabsf(reference);
    state->lost_ms = lost ? state->lost_ms + 1U : 0U;
    return state->lost_ms < 100U;
}

#endif
