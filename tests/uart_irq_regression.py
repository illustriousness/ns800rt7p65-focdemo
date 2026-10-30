#!/usr/bin/env python3
"""Execute the real UART ISR/control C functions against an interrupt model."""
from pathlib import Path
import subprocess
import tempfile


def function(source, name):
    start = source.index("static ", source.index(name) - 24)
    brace = source.index("{", source.index(name, start))
    depth = 0
    for end in range(brace, len(source)):
        depth += (source[end] == "{") - (source[end] == "}")
        if not depth:
            return source[start:end + 1]
    raise ValueError(name)


root = Path(__file__).resolve().parents[1]
source = (root / "libraries/HAL_Drivers/drivers/drv_uart.c").read_text()
prefix = r'''
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
typedef int rt_err_t;
typedef uintptr_t rt_uint32_t;
#define RT_NULL NULL
#define RT_ASSERT assert
#define RT_EOK 0
#define RT_ERROR 1
#define rt_container_of(p,t,m) ((t*)((char*)(p)-offsetof(t,m)))
enum {UART_RX_OVERRUN, UART_NOISE_DETECT, UART_FRAME_ERR, UART_PARITY_ERR,
      UART_RX_DATA_REG_FULL, UART_TX_COMPLETE, UART_INT_RX_DATA_REG_FULL,
      UART_INT_TX_COMPLETE, RT_SERIAL_EVENT_RX_IND, RT_SERIAL_EVENT_TX_DONE,
      RT_DEVICE_CTRL_CLR_INT, RT_DEVICE_CTRL_SET_INT, RT_DEVICE_CTRL_CLOSE,
      UART_CTRL_SET_BLOCK_TIMEOUT, RT_DEVICE_FLAG_INT_RX, RT_DEVICE_FLAG_INT_TX,
      UART_INT_RX_OVERRUN, UART_INT_FRAME_ERR_FLAG, UART_INT_NOISE_ERR_FLAG,
      UART_INT_PARITY_ERR_FLAG, UART_FIFO_RX0=0};
struct hardware {unsigned flags, error_interrupts, fifo_count; bool rx_enabled, tx_enabled;};
struct rt_serial_device {void *serial_tx;};
struct configuration {int rx_irq_type, tx_irq_type; void (*irq_handler)(void);};
struct ns800_uart {
    struct {struct hardware *Instance;} handle;
    struct configuration *config;
    unsigned tx_block_timeout;
    struct rt_serial_device serial;
};
static bool nvic[2];
static unsigned rx_events, tx_events, errors;
static void Interrupt_enable(int irq) {nvic[irq]=true;}
static void Interrupt_disable(int irq) {nvic[irq]=false;}
static void Interrupt_register(int irq,void (*handler)(void)) {(void)irq;(void)handler;}
static bool UART_getIntMode(struct hardware *h,int i) {
    return i==UART_INT_TX_COMPLETE?h->tx_enabled:h->rx_enabled;
}
static bool UART_getStatusFlag(struct hardware *h,int f) {return !!(h->flags&(1U<<f));}
static void UART_enableInterrupt(struct hardware *h,int i) {
    if(i==UART_INT_TX_COMPLETE)h->tx_enabled=true;
    else if(i==UART_INT_RX_DATA_REG_FULL)h->rx_enabled=true;
    else h->error_interrupts|=1U<<i;
}
static void UART_disableInterrupt(struct hardware *h,int i) {
    if(i==UART_INT_TX_COMPLETE)h->tx_enabled=false;
    else if(i==UART_INT_RX_DATA_REG_FULL)h->rx_enabled=false;
    else h->error_interrupts&=~(1U<<i);
}
static unsigned UART_getRxFifoStatus(struct hardware *h) {return h->fifo_count;}
static unsigned UART_readChar(struct hardware *h) {assert(h->fifo_count);h->fifo_count--;return 'A';}
static void UART_disableTxModule(struct hardware *h) {(void)h;}
static void UART_disableRxModule(struct hardware *h) {(void)h;}
static void ns800_uart_clear_errors(struct hardware *h) {h->flags&=~15U;errors++;}
static void rt_hw_serial_isr(struct rt_serial_device *s,int event) {
    if(event==RT_SERIAL_EVENT_TX_DONE) {assert(s->serial_tx);tx_events++;}
    else rx_events++;
}
'''
suffix = r'''
int main(void) {
    struct hardware h={.flags=1U<<UART_TX_COMPLETE,.rx_enabled=true};
    struct configuration c={.rx_irq_type=0,.tx_irq_type=1};
    struct ns800_uart u={.handle={&h},.config=&c};
    uart_isr(&u.serial);
    assert(rx_events==0 && tx_events==0); /* polling TX, idle TC: original crash */
    h.flags|=1U<<UART_RX_OVERRUN;
    uart_isr(&u.serial);
    assert(errors==1 && tx_events==0);
    h.flags|=1U<<UART_RX_DATA_REG_FULL;
    uart_isr(&u.serial);
    assert(rx_events==1 && tx_events==0);
    u.serial.serial_tx=&u;
    h.tx_enabled=true;
    uart_isr(&u.serial);
    assert(rx_events==2 && tx_events==1 && !h.tx_enabled);
    h.rx_enabled=false;h.tx_enabled=true;
    uart_isr(&u.serial);
    assert(rx_events==2 && tx_events==2);
    h.rx_enabled=true;h.tx_enabled=true;nvic[0]=nvic[1]=true;
    assert(ns800_control(&u.serial,RT_DEVICE_CTRL_CLR_INT,
                        (void*)(uintptr_t)RT_DEVICE_FLAG_INT_TX)==RT_EOK);
    assert(nvic[0] && h.rx_enabled && !nvic[1] && !h.tx_enabled);
    h.tx_enabled=true;nvic[1]=true;
    assert(ns800_control(&u.serial,RT_DEVICE_CTRL_CLR_INT,
                        (void*)(uintptr_t)RT_DEVICE_FLAG_INT_RX)==RT_EOK);
    assert(!nvic[0] && !h.rx_enabled && nvic[1] && h.tx_enabled);
    assert(ns800_control(&u.serial,RT_DEVICE_CTRL_SET_INT,
                        (void*)(uintptr_t)RT_DEVICE_FLAG_INT_RX)==RT_EOK);
    assert(nvic[0] && h.rx_enabled);
    assert(h.error_interrupts!=0);
    /* Empty FIFO with stale RDRF must not be read (would underflow). */
    assert(ns800_getc(&u.serial)==-1);
    h.fifo_count=2;
    assert(ns800_getc(&u.serial)=='A' && ns800_getc(&u.serial)=='A');
    assert(ns800_getc(&u.serial)==-1);
    puts("UART idle/error/RX/TX dispatch and independent interrupt controls passed");
}
'''
with tempfile.TemporaryDirectory(prefix="ns800-uart-regression-") as folder:
    path = Path(folder)
    test = path / "uart_irq.c"
    test.write_text(prefix + function(source, "ns800_control(") +
                    function(source, "ns800_getc(") + function(source, "uart_isr(") + suffix)
    executable = path / "uart_irq"
    subprocess.run(["cc", "-O2", "-Wall", "-Wextra", "-Werror", str(test),
                    "-o", str(executable)], check=True)
    subprocess.run([str(executable)], check=True)
