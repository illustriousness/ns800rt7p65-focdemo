#include "co_bus.h"

void CO_CANsetConfigurationMode(void *ptr) { (void)ptr; }
void CO_CANsetNormalMode(CO_CANmodule_t *m) { m->CANnormal = true; }
void CO_CANmodule_disable(CO_CANmodule_t *m) { m->CANnormal = false; }

CO_ReturnError_t CO_CANmodule_init(CO_CANmodule_t *m, void *ptr,
    CO_CANrx_t rx[], uint16_t nrx, CO_CANtx_t tx[], uint16_t ntx, uint16_t bitrate)
{
    (void)bitrate;
    memset(m, 0, sizeof(*m));
    memset(rx, 0, nrx * sizeof(*rx));
    memset(tx, 0, ntx * sizeof(*tx));
    m->CANptr = ptr; m->rxArray = rx; m->rxSize = nrx;
    m->txArray = tx; m->txSize = ntx; m->firstCANtxMessage = true;
    return CO_ERROR_NO;
}

CO_ReturnError_t CO_CANrxBufferInit(CO_CANmodule_t *m, uint16_t index,
    uint16_t ident, uint16_t mask, bool_t rtr, void *object, void (*callback)(void *, void *))
{
    if (index >= m->rxSize || rtr) return CO_ERROR_ILLEGAL_ARGUMENT;
    m->rxArray[index] = (CO_CANrx_t){ident, mask, object, callback};
    return CO_ERROR_NO;
}

CO_CANtx_t *CO_CANtxBufferInit(CO_CANmodule_t *m, uint16_t index, uint16_t ident,
    bool_t rtr, uint8_t length, bool_t sync)
{
    if (index >= m->txSize || rtr || length > 8) return NULL;
    CO_CANtx_t *b = &m->txArray[index];
    *b = (CO_CANtx_t){.ident = ident, .DLC = length, .syncFlag = sync};
    return b;
}

CO_ReturnError_t CO_CANsend(CO_CANmodule_t *m, CO_CANtx_t *b)
{
    if (b->bufferFull) { m->CANerrorStatus |= CO_CAN_ERRTX_OVERFLOW; return CO_ERROR_TX_OVERFLOW; }
    b->bufferFull = true;
    m->CANtxCount++;
    return CO_ERROR_NO;
}

void co_driver_flush(CO_CANmodule_t *m)
{
    if (!m->CANnormal) return;
    for (unsigned i = 0; i < m->txSize; ++i)
    {
        CO_CANtx_t *b = &m->txArray[i];
        if (!b->bufferFull) continue;
        co_frame frame = {.ident = (uint16_t)b->ident, .DLC = b->DLC};
        memcpy(frame.data, b->data, b->DLC);
        if (!co_bus_send(&frame)) break;
        b->bufferFull = false;
        m->CANtxCount--;
        m->firstCANtxMessage = false;
    }
}

void co_driver_receive(CO_CANmodule_t *m, const co_frame *frame)
{
    if (!m->CANnormal) return;
    for (unsigned i = 0; i < m->rxSize; ++i)
    {
        CO_CANrx_t *b = &m->rxArray[i];
        if (b->CANrx_callback && ((frame->ident ^ b->ident) & b->mask) == 0)
        { b->CANrx_callback(b->object, (void *)frame); break; }
    }
}

void CO_CANclearPendingSyncPDOs(CO_CANmodule_t *m)
{
    for (unsigned i = 0; i < m->txSize; ++i)
        if (m->txArray[i].bufferFull && m->txArray[i].syncFlag)
        { m->txArray[i].bufferFull = false; m->CANtxCount--; }
}

void CO_CANmodule_process(CO_CANmodule_t *m)
{
    unsigned rx, tx, off;
    co_bus_errors(&rx, &tx, &off);
    uint16_t error = off ? CO_CAN_ERRTX_BUS_OFF : 0;
    if (rx >= 96) error |= CO_CAN_ERRRX_WARNING;
    if (tx >= 96) error |= CO_CAN_ERRTX_WARNING;
    if (rx >= 128) error |= CO_CAN_ERRRX_PASSIVE;
    if (tx >= 128) error |= CO_CAN_ERRTX_PASSIVE;
    m->CANerrorStatus = (m->CANerrorStatus & CO_CAN_ERRTX_OVERFLOW) | error;
}
