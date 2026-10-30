#ifndef NS800_FOC_PORT_H
#define NS800_FOC_PORT_H

#include "foc_ipc.h"
#include "foc_limits.h"

enum ns800_foc_owner { FOC_OWNER_CAN, FOC_OWNER_UART, FOC_OWNER_SWITCHING };

enum ns800_foc_state
{
    FOC_STATE_NOT_READY,
    FOC_STATE_CALIBRATING,
    FOC_STATE_IDLE,
    FOC_STATE_STARTING,
    FOC_STATE_CLOSED,
    FOC_STATE_FAULT,
    FOC_STATE_ARMING         /* command accepted, initial PWM release still pending */
};

enum ns800_foc_error_source
{
    FOC_ERROR_NONE,
    FOC_ERROR_ADC,
    FOC_ERROR_LIBRARY,
    FOC_ERROR_OBSERVER,
    FOC_ERROR_CURRENT,
    FOC_ERROR_SPEED,
    FOC_ERROR_BUS
};

struct ns800_foc_status
{
    uint32_t state;          /* enum ns800_foc_state; zero means not yet initialized */
    uint32_t error;          /* source in bits 31..16, library status in bits 15..0 */
    uint32_t command_seq, stop_seq;
    int32_t command_result;  /* execution result for command_seq */
    float speed;            /* estimated mechanical rad/s; meaningful while running */
};

/* Comm-core thread API. Submission is asynchronous; status acknowledges the
 * applied command, not merely receipt. No caller may modify Sguan directly. */
int ns800_foc_request(enum foc_operation operation, float rpm, float current);
/* Returns the exact published command/STOP sequence, for asynchronous clients. */
int ns800_foc_submit(enum foc_operation operation, float rpm, float current, uint32_t *sequence);
int ns800_foc_status_read(struct ns800_foc_status *status);
/* Communications-core APIs. Handover grants ownership only after STOP ack. */
enum ns800_foc_owner ns800_foc_owner_get(void);
int ns800_foc_owner_set(enum ns800_foc_owner owner);

#endif
