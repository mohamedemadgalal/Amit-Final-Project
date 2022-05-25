#include "UART.h"
#include "HC_05.h"
#include "REG.h"
#include "BIT_MATH.h"
#define  F_CPU 16000000UL
#include "util/delay.h"

void HC_05_INIT(void){
	UART_INIT();
}
void HC_05_SEND_BYTE(u8 data){
	UART_SEND(data);
}

u8   HC_05_REC_BYTE(void){
	u8 data = 0;
	data = UART_RECIEVE();
	return data;
}

u8 DATA_RECIEVED(void){
    return GET_BIT(UCSRA,7);
}