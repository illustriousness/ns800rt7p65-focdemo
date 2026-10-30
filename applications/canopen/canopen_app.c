#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "protocol.h"
#include "OD.h"
#include "ns800_foc_port.h"

static unsigned started;
static void canopen_entry(void *parameter)
{
    RT_UNUSED(parameter);
    int result = co_bus_open();
    if (result == 0) result = co_protocol_reset();
    if (result)
    { rt_kprintf("CANopen init failed: %d\n", result); return; }
    started = 1;
    rt_kprintf("CANopen node=1 bitrate=1000000 cpu=%d controls=FOC_BRIDGE; explicit RPDO enable required\n", rt_hw_cpu_id());
    rt_tick_t previous = rt_tick_get();
    while (1)
    {
        for (unsigned i = 0; i < 32; ++i)
        {
            co_frame frame;
            int received = co_bus_receive(&frame);
            if (!received) break;
            if (received > 0) co_protocol_receive(&frame);
        }
        rt_tick_t now = rt_tick_get();
        uint32_t us = (uint32_t)(now - previous) * (1000000U / RT_TICK_PER_SECOND);
        previous = now;
        if (co_protocol_process(us))
        {
            result = co_protocol_reset();
            if (result) { rt_kprintf("CANopen reset failed: %d\n", result); return; }
        }
        rt_thread_mdelay(1);
    }
}

static int canopen_init(void)
{
    static struct rt_thread thread;
    static uint8_t stack[4096];
    rt_err_t result = rt_thread_init(&thread, "canopen", canopen_entry, RT_NULL,
                                    stack, sizeof(stack), 17, 10);
    if (result != RT_EOK) return result;
    rt_thread_control(&thread, RT_THREAD_CTRL_BIND_CPU, (void *)(rt_ubase_t)NS800_COMM_CPU);
    return rt_thread_startup(&thread);
}
INIT_APP_EXPORT(canopen_init);

static int co(int argc, char **argv)
{
    if (!started) { rt_kprintf("CANopen not started\n"); return -RT_ERROR; }
    if (argc == 2 && !rt_strcmp(argv[1], "tx"))
    {
        rt_base_t level = rt_hw_local_irq_disable();
        int result = co_protocol_test_tx();
        rt_hw_local_irq_enable(level);
        return result;
    }
    unsigned rx, tx, off;
    co_bus_errors(&rx, &tx, &off);
    rt_kprintf("co cpu=%d node=1 classic=1 bitrate=1000000 nmt=%u rx=%u tx=%u RXE=%u TXE=%u busoff=%u\n",
               rt_hw_cpu_id(), co_protocol_nmt(), od_rx_count, od_tx_count, rx, tx, off);
    rt_kprintf("controls=FOC_BRIDGE motor_connected=%u cw=%04x sw=%04x mode=%d target=%d actual=%d error=%04x\n",
               od_motor_connected, od_controlword, od_statusword, od_mode_display,
               od_target_velocity, od_actual_velocity, od_error_code);
    static const char *const owners[] = {"can", "uart", "switching"};
    rt_kprintf("motor_owner=%s\n", owners[ns800_foc_owner_get()]);
    return RT_EOK;
}
MSH_CMD_EXPORT(co, CANopen FOC bridge status or independent tx);
