#ifndef NS800_CO_DRIVER_TARGET_H
#define NS800_CO_DRIVER_TARGET_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define CO_LITTLE_ENDIAN
#define CO_SWAP_16(x) (x)
#define CO_SWAP_32(x) (x)
#define CO_SWAP_64(x) (x)
typedef uint_fast8_t bool_t;
typedef float float32_t;
typedef double float64_t;

/* One CPU1 thread owns both the stack and OD. The hardware ISR only feeds the
 * RT-Thread CAN queue, never calls into this stack or application objects. */
#define CO_CONFIG_NMT 0
#define CO_CONFIG_EM CO_CONFIG_EM_PRODUCER
#define CO_CONFIG_SDO_SRV CO_CONFIG_SDO_SRV_SEGMENTED
#define CO_CONFIG_PDO (CO_CONFIG_RPDO_ENABLE | CO_CONFIG_TPDO_ENABLE | CO_CONFIG_TPDO_TIMERS_ENABLE | CO_CONFIG_PDO_OD_IO_ACCESS)
#define CO_CONFIG_SYNC 0
#define CO_CONFIG_GLOBAL_FLAG_OD_DYNAMIC 0
#define CO_CONFIG_ERR_CONDITION_MANUFACTURER (em->errorStatusBits[6] != 0)
#define CO_LOCK_CAN_SEND(m)
#define CO_UNLOCK_CAN_SEND(m)
#define CO_LOCK_EMCY(m)
#define CO_UNLOCK_EMCY(m)
#define CO_LOCK_OD(m)
#define CO_UNLOCK_OD(m)
#define CO_FLAG_READ(x) ((x) != NULL)
#define CO_FLAG_SET(x) ((x) = (void *)1)
#define CO_FLAG_CLEAR(x) ((x) = NULL)

typedef struct { uint16_t ident; uint8_t DLC; uint8_t data[8]; } co_frame;
#define CO_CANrxMsg_readIdent(m) (((const co_frame *)(m))->ident)
#define CO_CANrxMsg_readDLC(m) (((const co_frame *)(m))->DLC)
#define CO_CANrxMsg_readData(m) (((const co_frame *)(m))->data)
typedef struct {
    uint16_t ident, mask;
    void *object;
    void (*CANrx_callback)(void *, void *);
} CO_CANrx_t;
typedef struct {
    uint32_t ident;
    uint8_t DLC, data[8];
    bool_t bufferFull, syncFlag;
} CO_CANtx_t;
typedef struct {
    void *CANptr;
    CO_CANrx_t *rxArray;
    CO_CANtx_t *txArray;
    uint16_t rxSize, txSize, CANerrorStatus, CANtxCount;
    bool_t CANnormal, useCANrxFilters, bufferInhibitFlag, firstCANtxMessage;
    uint32_t errOld;
} CO_CANmodule_t;
#endif
