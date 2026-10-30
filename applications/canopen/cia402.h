#ifndef NS800_CIA402_H
#define NS800_CIA402_H
#include <stdbool.h>
#include <stdint.h>
#include "ns800_foc_port.h"
enum cia402_state { CIA402_NOT_READY, CIA402_DISABLED, CIA402_READY, CIA402_SWITCHED_ON,
    CIA402_ENABLED, CIA402_QUICK_STOP, CIA402_FAULT_REACTION, CIA402_FAULT };
struct cia402
{
    enum cia402_state state, stop_state;
    enum foc_operation pending; /* zero means no outstanding motor request */
    uint16_t previous_controlword, error_code;
    uint32_t sequence;
    int32_t pending_velocity, velocity; /* requested and last acknowledged rpm */
};
#define CIA402_ERROR_REFERENCE 0xFF01U
#define CIA402_ERROR_REQUEST   0xFF02U
#define CIA402_ERROR_LOCAL     0xFF03U
#define CIA402_ERROR_FEEDBACK  0xFF04U
#define CIA402_ERROR_LINK      0x8100U
void cia402_reset(struct cia402 *drive);
bool cia402_velocity_valid(int32_t rpm);
void cia402_fault(struct cia402 *drive, uint16_t code);
/* Latch stop/disable intent before CANopen's latest-value PDO buffer can replace it. */
void cia402_control_received(struct cia402 *drive, uint16_t controlword, int32_t target);
void cia402_process(struct cia402 *drive, bool operational, bool control_live, bool bus_off);
#endif
