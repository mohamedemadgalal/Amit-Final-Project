#ifndef UART_H_
#define UART_H_

#include "STD_TYPES.h"

void UART_INIT(void);
void UART_SEND(u8);
u8 UART_RECIEVE(void);
void UART_SEND_NUM(u32);

#endif /* UART_H_ */