/* Independent PMSM electrical/mechanical plant, not an echo of the command.
 * Build: cc -O2 -Wall -Wextra -Iapplications tests/motor_sensorless_sim.c
 *        applications/motor_sensorless.c -lm -o /tmp/motor_sensorless_sim */
#include "motor_sensorless.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979323846f
struct plant { float ia, ib, theta, omega, va, vb, rs, ls, flux, load; };

static void plant_step(struct plant *p, float dt, int blocked)
{
    float sn = sinf(p->theta), cs = cosf(p->theta);
    float ea = -2.0f * p->omega * p->flux * sn;
    float eb = 2.0f * p->omega * p->flux * cs;
    float iq = -sn * p->ia + cs * p->ib;
    p->ia += dt / p->ls * (p->va - p->rs * p->ia - ea);
    p->ib += dt / p->ls * (p->vb - p->rs * p->ib - eb);
    if (!blocked)
    {
        float load = p->omega > 0.0f ? p->load : -p->load;
        p->omega += dt * (3.0f * p->flux * iq - 0.0001f * p->omega - load) / 0.0000173f;
        p->theta += dt * 2.0f * p->omega;
        if (p->theta > PI) p->theta -= 2.0f * PI;
        if (p->theta < -PI) p->theta += 2.0f * PI;
    }
}

static void require(int condition, const char *message)
{
    if (!condition) { fprintf(stderr, "FAIL: %s\n", message); exit(1); }
}

static void run(float target, float rs, float ls, int blocked)
{
    struct motor_sensorless s;
    struct plant p = {.rs = rs, .ls = ls, .flux = 0.021f};
    float max_current = 0.0f, speed_error = 0.0f;
    unsigned samples = 0, n;
    motor_sensorless_init(&s, 20000.0f);
    motor_sensorless_start(&s, target, 0.8f);
    for (n = 0; n < 240000U; n++)
    {
        float noise = 0.004f * sinf((float)n * 1.37f);
        motor_sensorless_step(&s, p.ia + noise, p.ib - noise, p.va, p.vb, 24.0f);
        if (s.stage == SL_FAULT) break;
        p.va = s.v_alpha;
        p.vb = s.v_beta;
        plant_step(&p, s.dt, blocked);
        max_current = fmaxf(max_current, hypotf(p.ia, p.ib));
        require(isfinite(p.ia) && isfinite(p.ib), "finite plant current");
        require(hypotf(p.va, p.vb) < 6.01f, "voltage limit");
        if (!blocked && n == 160000U)
        {
            require(s.stage == SL_CLOSED, "closed before load/speed change");
            require(motor_sensorless_set_speed(&s, target * 1.2f) == 0, "speed change accepted");
            p.load = 0.01f;
        }
        if (!blocked && n > 200000U)
        {
            speed_error += fabsf(p.omega * 60.0f / (2.0f * PI) - target * 1.2f);
            samples++;
        }
    }
    printf("target=%.0f Rs=%.2f L=%.4f blocked=%d stage=%d fault=%d true=%.1f estimated=%.1f peak=%.2f transition=%u mean_error=%.1f\n",
           target, rs, ls, blocked, s.stage, s.fault, p.omega * 60.0f / (2.0f * PI),
           s.estimated_hz * 30.0f, max_current, s.transitions, samples ? speed_error / samples : 0.0f);
    if (blocked)
    {
        require(s.stage == SL_FAULT && s.fault == SL_NO_LOCK, "blocked rotor fails acquisition");
        require(s.transitions == 0U, "blocked rotor never enters closed loop");
    }
    else
    {
        require(s.stage == SL_CLOSED && s.fault == SL_OK, "sustained closed loop");
        require(s.transitions == 1U, "single successful handover");
        require(max_current < 3.0f, "bounded phase current");
        require(samples && speed_error / samples < 30.0f, "measured plant follows new speed under load");
        require(fabsf(s.estimated_hz * 30.0f - p.omega * 60.0f / (2.0f * PI)) < 30.0f,
                 "estimated speed matches independent plant");
    }
}

int main(void)
{
    struct motor_sensorless s;
    struct plant p = {.rs = 0.2f, .ls = 0.0004f, .flux = 0.021f};
    unsigned n;
    run(500.0f, 0.2f, 0.0004f, 0);
    run(-500.0f, 0.2f, 0.0004f, 0);
    run(500.0f, 0.24f, 0.0005f, 0);
    run(500.0f, 0.2f, 0.0004f, 1);
    motor_sensorless_init(&s, 20000.0f);
    motor_sensorless_start(&s, 500.0f, 0.8f);
    for (n = 0; n < 160000U; n++)
    {
        if (n == 120000U) { require(s.stage == SL_CLOSED, "closed before stall"); p.omega = 0.0f; }
        motor_sensorless_step(&s, p.ia, p.ib, p.va, p.vb, 24.0f);
        if (s.stage == SL_FAULT) break;
        p.va = s.v_alpha; p.vb = s.v_beta;
        plant_step(&p, s.dt, n >= 120000U);
    }
    require(s.stage == SL_FAULT && s.fault == SL_LOST_LOCK, "stall after handover shuts down");
    require(n < 140000U, "stall detected within one second");
    motor_sensorless_start(&s, -500.0f, 0.8f);
    require(s.stage == SL_ALIGN && s.fault == SL_OK && s.transitions == 0U, "restart resets dynamic state");
    require(motor_sensorless_set_speed(&s, 500.0f) < 0, "speed command rejected before handover");
    motor_sensorless_step(&s, NAN, 0.0f, 0.0f, 0.0f, 24.0f);
    require(s.stage == SL_FAULT && s.fault == SL_NUMERIC && s.v_alpha == 0.0f && s.v_beta == 0.0f,
             "invalid sample shuts down before trigonometric lookup");
    puts("stall-after-handover, restart and invalid-sample checks passed");
    return 0;
}
