#ifndef NS800_CO_BUS_H
#define NS800_CO_BUS_H
#include "301/CO_driver.h"
int co_bus_open(void);
int co_bus_send(const co_frame *frame);
int co_bus_receive(co_frame *frame);
void co_bus_errors(unsigned *rx, unsigned *tx, unsigned *busoff);
void co_driver_receive(CO_CANmodule_t *module, const co_frame *frame);
void co_driver_flush(CO_CANmodule_t *module);
#endif
