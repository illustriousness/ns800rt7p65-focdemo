#ifndef NS800_CANOPEN_PROTOCOL_H
#define NS800_CANOPEN_PROTOCOL_H
#include "co_bus.h"
int co_protocol_reset(void);
void co_protocol_receive(const co_frame *frame);
int co_protocol_process(uint32_t elapsed_us);
int co_protocol_test_tx(void);
unsigned co_protocol_nmt(void);
#endif
