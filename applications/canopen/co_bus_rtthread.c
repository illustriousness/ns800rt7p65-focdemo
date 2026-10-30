#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include <drv_can.h>
#include "co_bus.h"
#include "OD.h"

static rt_device_t device;

int co_bus_open(void)
{
    device = rt_device_find("canfd1");
    if (!device) return -RT_ENOSYS;
    /* Configure before the first open/init. CANFD1 hardware, classic CAN wire. */
    struct rt_can_device *can = (struct rt_can_device *)device;
    can->config.baud_rate = CAN1MBaud;
    can->config.enable_canfd = 0;
    return rt_device_open(device, RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_INT_TX);
}

int co_bus_send(const co_frame *frame)
{
    struct rt_can_msg msg = {0};
    msg.id = frame->ident;
    msg.len = frame->DLC;
    msg.nonblocking = 1;
    memcpy(msg.data, frame->data, frame->DLC);
    if (rt_device_write(device, 0, &msg, sizeof(msg)) != sizeof(msg)) return 0;
    od_tx_count++;
    return 1;
}

int co_bus_receive(co_frame *frame)
{
    struct rt_can_msg msg = {0};
    msg.hdr_index = -1;
    if (rt_device_read(device, 0, &msg, sizeof(msg)) != sizeof(msg)) return 0;
    if (msg.ide || msg.rtr || msg.fd_frame || msg.len > 8) return -1;
    frame->ident = msg.id;
    frame->DLC = msg.len;
    memcpy(frame->data, msg.data, msg.len);
    od_rx_count++;
    return 1;
}

void co_bus_errors(unsigned *rx, unsigned *tx, unsigned *busoff)
{
    struct rt_can_status status = {0};
    rt_device_control(device, RT_CAN_CMD_GET_STATUS, &status);
    *rx = status.rcverrcnt;
    *tx = status.snderrcnt;
    ns800rt7_can *can = device->user_data;
    *busoff = FLEXCANREG_GetFltConfinementState(can->CanHandle.flexCanReg) >=
              FLEXCANDRV_FLTCONFSTS_BUSOFF;
}
