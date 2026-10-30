#include "protocol.h"
#include "OD.h"
#include "cia402.h"
#include "301/CO_Emergency.h"
#include "301/CO_NMT_Heartbeat.h"
#include "301/CO_SDOserver.h"
#include "301/CO_PDO.h"

static CO_CANmodule_t can;
static CO_CANrx_t rx[3];
static CO_CANtx_t tx[5]; /* EMCY, heartbeat, SDO, TPDO, raw link test */
static CO_EM_t em;
static CO_EM_fifo_t em_fifo[8];
static CO_NMT_t nmt;
static CO_SDOserver_t sdo;
static CO_RPDO_t rpdo;
static CO_TPDO_t tpdo;
static struct cia402 drive;
static CO_NMT_internalState_t nmt_state;
static uint16_t last_fault;
static uint32_t control_age_us;

static ODR_t controlword_write(OD_stream_t *stream, const void *buf, OD_size_t count, OD_size_t *written)
{
    uint16_t cw;
    if (count != sizeof(cw)) return ODR_TYPE_MISMATCH;
    memcpy(&cw, buf, sizeof(cw));
    ODR_t result = OD_writeOriginal(stream, buf, count, written);
    if (result == ODR_OK && (!(cw & 2) || !(cw & 4) || (cw & 0x100)))
    {
        /* SDO disable/quick-stop/HALT must also survive a following RPDO.
         * Do not interpret velocity here: PDO writes CW before its new target. */
        int32_t reference = drive.pending ? drive.pending_velocity : drive.velocity;
        cia402_control_received(&drive, cw, reference);
    }
    return result;
}

static ODR_t velocity_write(OD_stream_t *stream, const void *buf, OD_size_t count, OD_size_t *written)
{
    int32_t rpm;
    if (count != sizeof(rpm)) return ODR_TYPE_MISMATCH;
    memcpy(&rpm, buf, sizeof(rpm));
    if (!cia402_velocity_valid(rpm)) return ODR_INVALID_VALUE;
    return OD_writeOriginal(stream, buf, count, written);
}
static ODR_t current_write(OD_stream_t *stream, const void *buf, OD_size_t count, OD_size_t *written)
{
    uint16_t current;
    if (count != sizeof(current)) return ODR_TYPE_MISMATCH;
    memcpy(&current, buf, sizeof(current));
    if (current < 500 || current > 1200) return ODR_INVALID_VALUE;
    if (drive.pending || drive.state == CIA402_ENABLED) return ODR_DATA_DEV_STATE;
    return OD_writeOriginal(stream, buf, count, written);
}

static ODR_t mode_write(OD_stream_t *stream, const void *buf, OD_size_t count, OD_size_t *written)
{
    if (count != 1) return ODR_TYPE_MISMATCH;
    if (*(const int8_t *)buf != 3) return ODR_INVALID_VALUE;
    return OD_writeOriginal(stream, buf, count, written);
}
static OD_extension_t mode_extension = {.read = OD_readOriginal, .write = mode_write};
static OD_extension_t velocity_extension = {.read = OD_readOriginal, .write = velocity_write};
static OD_extension_t current_extension = {.read = OD_readOriginal, .write = current_write};
static OD_extension_t controlword_extension = {.read = OD_readOriginal, .write = controlword_write};

int co_protocol_reset(void)
{
    uint32_t info = 0;
    cia402_reset(&drive); /* STOP survives clearing OD and CANopen state below */
    OD_reset();
    control_age_us = (uint32_t)od_control_timeout_ms * 1000U + 1U;
    last_fault = 0;
    memset(&em, 0, sizeof(em)); memset(&nmt, 0, sizeof(nmt));
    memset(&sdo, 0, sizeof(sdo)); memset(&rpdo, 0, sizeof(rpdo)); memset(&tpdo, 0, sizeof(tpdo));
    CO_CANmodule_init(&can, NULL, rx, 3, tx, 5, 1000);
    int result = CO_EM_init(&em, &can, OD_find(OD, 0x1001), em_fifo, 8,
                            OD_find(OD, 0x1014), 0, 1, &info);
    if (result) return result;
    result = CO_NMT_init(&nmt, OD_find(OD, 0x1017), &em, 1, 0, 500,
                         &can, 0, 0, &can, 1, 0x701, &info);
    if (result) return result;
    result = CO_SDOserver_init(&sdo, OD, OD_find(OD, 0x1200), 1, 1000, &can, 1, &can, 2, &info);
    if (result) return result;
    OD_extension_init(OD_find(OD, 0x6060), &mode_extension);
    OD_extension_init(OD_find(OD, 0x60FF), &velocity_extension);
    OD_extension_init(OD_find(OD, 0x2004), &current_extension);
    OD_extension_init(OD_find(OD, 0x6040), &controlword_extension);
    result = CO_RPDO_init(&rpdo, OD, &em, 0x201, OD_find(OD, 0x1400),
                          OD_find(OD, 0x1600), &can, 2, &info);
    if (result) return result;
    result = CO_TPDO_init(&tpdo, OD, &em, 0x181, OD_find(OD, 0x1800),
                          OD_find(OD, 0x1A00), &can, 3, &info);
    if (result) return result;
    CO_CANtxBufferInit(&can, 4, 0x321, false, 8, false);
    nmt_state = CO_NMT_INITIALIZING;
    CO_CANsetNormalMode(&can);
    return 0;
}

void co_protocol_receive(const co_frame *frame)
{
    if (frame->ident == 0 && frame->DLC == 2 &&
        (frame->data[1] == 0 || frame->data[1] == 1) &&
        (frame->data[0] == 2 || frame->data[0] == 128 ||
         frame->data[0] == 129 || frame->data[0] == 130))
    {
        cia402_reset(&drive);
        od_controlword = 0;
        od_target_velocity = 0;
        control_age_us = (uint32_t)od_control_timeout_ms * 1000U + 1U;
    }
    if (frame->ident == 0x201)
    {
        if (nmt_state != CO_NMT_OPERATIONAL) return;
        int32_t rpm = 0;
        if (frame->DLC == 6) memcpy(&rpm, frame->data + 2, sizeof(rpm));
        if (frame->DLC != 6 || !cia402_velocity_valid(rpm))
        { cia402_fault(&drive, CIA402_ERROR_REFERENCE); return; }
        uint16_t cw;
        memcpy(&cw, frame->data, sizeof(cw));
        cia402_control_received(&drive, cw, rpm);
        control_age_us = 0; /* only a valid operational RPDO renews control */
    }
    if (frame->ident == 0x123)
    {
        CO_CANtx_t *echo = &tx[4];
        if (!echo->bufferFull)
        {
            echo->ident = 0x321; echo->DLC = frame->DLC;
            memcpy(echo->data, frame->data, frame->DLC);
            CO_CANsend(&can, echo);
        }
        return;
    }
    co_driver_receive(&can, frame);
}

int co_protocol_process(uint32_t elapsed_us)
{
    CO_CANmodule_process(&can);
    CO_NMT_reset_cmd_t reset = CO_NMT_process(&nmt, &nmt_state, elapsed_us, NULL);
    if (reset != CO_RESET_NOT) { cia402_reset(&drive); return 1; }
    bool operational = nmt_state == CO_NMT_OPERATIONAL;
    bool pre_or_operational = operational || nmt_state == CO_NMT_PRE_OPERATIONAL;
    CO_SDOserver_process(&sdo, pre_or_operational, elapsed_us, NULL);
    CO_RPDO_process(&rpdo, operational, false);
    uint32_t timeout_us = (uint32_t)od_control_timeout_ms * 1000U;
    if (elapsed_us > timeout_us || control_age_us > timeout_us - elapsed_us)
        control_age_us = timeout_us + 1U;
    else control_age_us += elapsed_us;
    if (!operational)
    {
        /* SDO fault-reset is allowed in Pre-operational, never run/enable bits. */
        od_controlword &= 0x80U;
        control_age_us = timeout_us + 1U;
    }
    cia402_process(&drive, operational, control_age_us <= timeout_us,
                   (can.CANerrorStatus & CO_CAN_ERRTX_BUS_OFF) != 0);
    if (drive.error_code != last_fault)
    {
        if (last_fault) CO_errorReset(&em, 0x30, 0);
        if (drive.error_code) CO_errorReport(&em, 0x30, drive.error_code, od_foc_error);
        last_fault = drive.error_code;
    }
    CO_EM_process(&em, pre_or_operational, elapsed_us, NULL);
    CO_TPDO_process(&tpdo, elapsed_us, NULL, operational, false);
    co_driver_flush(&can);
    return 0;
}

int co_protocol_test_tx(void)
{
    CO_CANtx_t *b = &tx[4];
    if (b->bufferFull) return -1;
    b->ident = 0x456; b->DLC = 8;
    for (unsigned i = 0; i < 8; ++i) b->data[i] = 0x80 + i;
    return CO_CANsend(&can, b);
}

unsigned co_protocol_nmt(void) { return nmt_state; }
