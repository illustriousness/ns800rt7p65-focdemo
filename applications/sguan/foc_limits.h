#ifndef NS800_FOC_LIMITS_H
#define NS800_FOC_LIMITS_H

/* Verified unloaded bench envelope, 24 V supply with 2.5 A DC current limit.
 * DC source current is not the same as motor phase current. */
#define FOC_START_MIN_RPM       350
#define FOC_START_MAX_RPM       800
#define FOC_RUN_MIN_RPM         350
#define FOC_RUN_MAX_RPM         2500
#define FOC_EST_OVERSPEED_RPM   2750
#define FOC_PHASE_LIMIT_A       3.0f
#define FOC_BUS_MIN_V           22.0f
#define FOC_BUS_MAX_V           27.0f

#endif
