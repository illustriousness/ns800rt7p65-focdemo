#include "cia402.h"
#include "OD.h"
#include <limits.h>
#include <math.h>

static bool powered(uint32_t state)
{ return state == FOC_STATE_STARTING || state == FOC_STATE_CLOSED; }

bool cia402_velocity_valid(int32_t rpm)
{ return rpm == 0 || (rpm >= 350 && rpm <= 800) || (rpm >= -800 && rpm <= -350); }

static void stop(struct cia402 *d, enum cia402_state next)
{
    if (d->error_code) next = CIA402_FAULT;
    if (d->pending == FOC_STOP)
    {
        if (next == CIA402_FAULT || next == CIA402_DISABLED) d->stop_state = next;
        return;
    }
    if (ns800_foc_submit(FOC_STOP, 0, 0, &d->sequence) == 0)
    { d->pending = FOC_STOP; d->stop_state = next; }
    else if (!d->error_code) d->error_code = CIA402_ERROR_REQUEST;
    if (d->error_code) d->state = CIA402_FAULT_REACTION;
}

void cia402_control_received(struct cia402 *d, uint16_t cw, int32_t target)
{
    if (d->error_code) return;
    bool active = d->state == CIA402_ENABLED || d->pending == FOC_START || d->pending == FOC_SPEED;
    int32_t reference = d->pending ? d->pending_velocity : d->velocity;
    bool reverse = (target < 0 && reference > 0) || (target > 0 && reference < 0);
    bool disable = !(cw & 2) || !(cw & 4) || (cw & 0x100) ||
                   (target == 0 && (active || (cw & 0x8F) == 15)) || reverse;
    if (disable)
    {
        if (active)
        {
            if ((cw & 2) && !(cw & 4)) d->state = CIA402_QUICK_STOP;
            stop(d, CIA402_DISABLED);
        }
        else if (!d->pending) d->state = CIA402_DISABLED;
    }
    else if (active && (cw & 0x8F) == 7) stop(d, CIA402_SWITCHED_ON);
    else if (active && (cw & 0x87) == 6) stop(d, CIA402_READY);
}

void cia402_reset(struct cia402 *d)
{
    /* A communication reset does not erase a motor fault or an in-flight START.
     * Publish STOP before resetting protocol commands; await CPU0's stop_seq. */
    d->previous_controlword = 0;
    d->velocity = 0;
    stop(d, CIA402_DISABLED);
    if (!d->error_code) d->state = CIA402_NOT_READY;
}

void cia402_fault(struct cia402 *d, uint16_t code)
{
    if (!d->error_code) d->error_code = code;
    d->state = CIA402_FAULT_REACTION;
    stop(d, CIA402_FAULT);
}

static void submit(struct cia402 *d, enum foc_operation op, int32_t velocity)
{
    if (ns800_foc_submit(op, (float)velocity, od_start_current_ma * .001f, &d->sequence) != 0)
    { cia402_fault(d, CIA402_ERROR_REQUEST); return; }
    d->pending = op;
    d->pending_velocity = velocity;
}

static void report(const struct cia402 *d, bool operational, bool voltage)
{
    static const uint16_t states[] = {0, 0x40, 0x21, 0x23, 0x27, 0x07, 0x0F, 0x08};
    od_statusword = states[d->state] | (operational ? 0x200 : 0) | (voltage ? 0x10 : 0);
    od_error_code = d->error_code;
}

void cia402_process(struct cia402 *d, bool operational, bool control_live, bool bus_off)
{
    /* Isolated speed-envelope bench: UART owns the actuator. No CAN actuation. */
    return;
    uint16_t cw = od_controlword;
    int32_t target = od_target_velocity;
    bool active = d->state == CIA402_ENABLED || d->pending == FOC_START || d->pending == FOC_SPEED;
    /* Link/control loss must publish STOP even if a snapshot happens to be busy. */
    if (active && (bus_off || (operational && !control_live)))
        cia402_fault(d, CIA402_ERROR_LINK);
    else if (!operational && active) stop(d, CIA402_DISABLED);
    else cia402_control_received(d, cw, target);

    struct ns800_foc_status s;
    if (ns800_foc_status_read(&s) != 0)
    { report(d, operational, (od_statusword & 0x10) != 0); return; }
    od_foc_error = s.error;
    bool reset_edge = (cw & 0x80) && !(d->previous_controlword & 0x80);
    d->previous_controlword = cw;
    if (s.error && d->pending != FOC_RESET_FAULT && !d->error_code)
        cia402_fault(d, (uint16_t)(0xFF10U + (s.error >> 16)));

    if (powered(s.state))
    {
        double rpm = round((double)s.speed * (60.0 / 6.283185307179586));
        if (!isfinite(rpm) || rpm < INT32_MIN || rpm > INT32_MAX)
            cia402_fault(d, CIA402_ERROR_FEEDBACK);
        else od_actual_velocity = (int32_t)rpm;
    }
    /* When disabled, hold the last estimate: gate-off is not a shaft-speed sensor. */

    if (d->pending == FOC_STOP)
    {
        /* CPU0 may coalesce our STOP with a later local emergency STOP. A later
         * acknowledgement covers ours too, but must not resume a Ready/On path.
         * STOP serials are ordered modulo 2^32, with <2^31 outstanding requests. */
        if ((uint32_t)(s.stop_seq - d->sequence) < 0x80000000U &&
            !powered(s.state) && s.state != FOC_STATE_ARMING)
        {
            if (s.stop_seq != d->sequence && !d->error_code)
                d->error_code = CIA402_ERROR_LOCAL;
            d->pending = 0;
            d->velocity = 0;
            d->state = d->error_code ? CIA402_FAULT :
                       (s.state == FOC_STATE_NOT_READY || s.state == FOC_STATE_CALIBRATING) ?
                       CIA402_NOT_READY : d->stop_state;
        }
        goto report;
    }
    if (d->pending && s.command_seq == d->sequence)
    {
        if (s.command_result != 0)
        { d->pending = 0; cia402_fault(d, CIA402_ERROR_REQUEST); goto report; }
        if (d->pending == FOC_RESET_FAULT)
        {
            d->pending = 0;
            if (s.state == FOC_STATE_IDLE && !s.error)
            { d->error_code = 0; d->state = CIA402_DISABLED; }
            else cia402_fault(d, CIA402_ERROR_REQUEST);
            goto report;
        }
        if (s.state != FOC_STATE_ARMING)
        {
            if (!powered(s.state))
            { d->pending = 0; cia402_fault(d, CIA402_ERROR_LOCAL); goto report; }
            d->velocity = d->pending_velocity;
            d->pending = 0;
            d->state = CIA402_ENABLED;
        }
    }

    if (d->error_code)
    {
        if (d->state == CIA402_FAULT && reset_edge && !bus_off && !d->pending)
            submit(d, FOC_RESET_FAULT, 0);
        else if (d->state != CIA402_FAULT && !d->pending) stop(d, CIA402_FAULT);
        goto report;
    }
    if (!operational || !control_live || bus_off)
    {
        if (powered(s.state) || s.state == FOC_STATE_ARMING || d->pending)
            stop(d, CIA402_DISABLED);
        else d->state = s.state == FOC_STATE_IDLE ? CIA402_DISABLED : CIA402_NOT_READY;
        goto report;
    }
    active = powered(s.state) || s.state == FOC_STATE_ARMING || d->pending;
    if (!cia402_velocity_valid(target))
    { cia402_fault(d, CIA402_ERROR_REFERENCE); goto report; }
    int32_t reference = d->pending ? d->pending_velocity : d->velocity;
    bool reverse = (target < 0 && reference > 0) || (target > 0 && reference < 0);
    if (cw & 0x100)
    {
        if (active) stop(d, CIA402_DISABLED);
        else d->state = CIA402_DISABLED;
        goto report;
    }
    if (active && (!(cw & 2) || !(cw & 4) || target == 0 || reverse))
    {
        if ((cw & 2) && !(cw & 4)) d->state = CIA402_QUICK_STOP;
        stop(d, CIA402_DISABLED);
        goto report;
    }
    if (active && (cw & 0x8F) == 7)
    { stop(d, CIA402_SWITCHED_ON); goto report; }
    if (active && (cw & 0x87) == 6)
    { stop(d, CIA402_READY); goto report; }
    if (d->pending) goto report;
    if (d->state == CIA402_ENABLED && !powered(s.state))
    { cia402_fault(d, CIA402_ERROR_LOCAL); goto report; }
    if (powered(s.state) && d->state != CIA402_ENABLED)
    { cia402_fault(d, CIA402_ERROR_LOCAL); goto report; }
    if (s.state == FOC_STATE_NOT_READY || s.state == FOC_STATE_CALIBRATING)
    { d->state = CIA402_NOT_READY; goto report; }
    if (!(cw & 2) || !(cw & 4)) { d->state = CIA402_DISABLED; goto report; }
    if (d->state == CIA402_NOT_READY) d->state = CIA402_DISABLED;
    switch (d->state)
    {
    case CIA402_DISABLED:
        if ((cw & 0x87) == 6) d->state = CIA402_READY;
        break;
    case CIA402_READY:
        if ((cw & 0x8F) == 7) d->state = CIA402_SWITCHED_ON;
        else if ((cw & 0x8F) == 15)
        {
            d->state = CIA402_SWITCHED_ON;
            if (target) submit(d, FOC_START, target);
            else d->state = CIA402_DISABLED;
        }
        break;
    case CIA402_SWITCHED_ON:
        if ((cw & 0x87) == 6) d->state = CIA402_READY;
        else if ((cw & 0x8F) == 15)
        {
            if (target) submit(d, FOC_START, target);
            else d->state = CIA402_DISABLED; /* no zero-speed holding backend */
        }
        break;
    case CIA402_ENABLED:
        if (target != d->velocity && s.state == FOC_STATE_CLOSED)
            submit(d, FOC_SPEED, target);
        break;
    default: break;
    }
report:
    report(d, operational, powered(s.state));
}
