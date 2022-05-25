#include "LED.h"
#include "UART.h"
#include "UART_CFG.h"
#include "BIT_MATH.h"
#include "REG.h"
#include "DIO.h"

void UART_INIT(void){
    //PIN_MODE(PD0,INPUT);
    //PIN_MODE(PD1,OUTPUT);
    //TO GET 9600 BUAD RATE
    //UBRRL = 103;
    //TO SELECT 8 BITS
    //UCSRC = 0b10100110;
    //SET_BIT(UCSRC,1);
    //SET_BIT(UCSRC,2);
    //SET_BIT(UCSRB,2);
    //TO SELECT EVEN PARITY
    //CLR_BIT(UCSRC,4);
    //SET_BIT(UCSRC,5);
    //TO ENABLE TX AND RX
    //SET_BIT(UCSRB,3);
    //SET_BIT(UCSRB,4);
    //------------------------------------------
    PIN_MODE(PD0,INPUT);
    PIN_MODE(PD1,OUTPUT);
    
    /*UBRRL = 103;
    SET_BIT(UCSRB,3);
    SET_BIT(UCSRB,4);
    
    SET_BIT(UCSRC,7);
    SET_BIT(UCSRC,1);
    SET_BIT(UCSRC,2);*/
    //--------------------------
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