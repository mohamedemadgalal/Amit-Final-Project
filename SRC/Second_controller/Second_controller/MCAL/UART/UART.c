#include "UART.h"
#include "UART_CFG.h"
#include "BIT_MATH.h"
#include "REG.h"
#include "DIO.h"

void UART_INIT(void){
    PIN_MODE(PD0,INPUT);
    PIN_MODE(PD1,OUTPUT);
    //9600 BUAD RATE,NO PARITY CHECK,1 STOP BIT
    UCSRA = 0x00;
    UCSRB = 0x18;
    UCSRC = 0x86;
    UBRRL = 103;
    UBRRH = 0;
}

void UART_SEND(u8 data){
    UDR = data;
    while (GET_BIT(UCSRA,5) == 0){
        
    }
}

u8 UART_RECIEVE(void){
    while(GET_BIT(UCSRA,7) == 0){
        
    }
    return UDR;
}

void UART_SEND_NUM(u32 num){
    u32 rem = 0;
    u8 arr [20];
    s8 i = 0;
    while(num){
        rem = num % 10;
        arr[i] = rem + 48;
        i++;
        num = num / 10;
    }
    i--;
    while(i > -1)
    {
        UART_SEND(arr[i]);
        i--;
    }
}