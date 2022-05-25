#include "ULTRA_SONIC_CFG.h"
#include "ULTRA_SONIC.h"
#include "UART.h"
#include "BIT_MATH.h"
#define  F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "DIO.h"

u16 SOUND_SPEED = 34300; //AVERAGE SOUND SPEED IN CM/S
u16 timer_overflow_1 = 0;


void ULTRA_SONIC_INIT_1(void){
    //ENABLE GLOBALE INTERUPT
    SET_BIT(SREG,7);
    //TIMER0 OVERFLOW
    SET_BIT(TIMSK,0);
    //PIN MODE FOR TRIGGER
    PIN_MODE(TRIGGER_PIN_1,OUTPUT);
    //PIN MODE FOR ECHO
    PIN_MODE(ECHO_PIN_1,INPUT);
    //NORMAL OPERATION FOR ALL
    TCCR0 = 0;
    PIN_WRITE(TRIGGER_PIN_1,HIGH);
}

u16 MEASURE_DISTANCE_1(void){
    u8 entered=0;
    u8 done=0;
    u64 time_taken;
    u32 distance;
    //SEND A ECHO
    PIN_WRITE(TRIGGER_PIN_1,HIGH);
    _delay_us(10);
    PIN_WRITE(TRIGGER_PIN_1,LOW);
    while(done != 1){
        switch(PIN_READ(ECHO_PIN_1)){
            case 0:
            switch(entered){
                case 0:
                continue;
                break;
                case 1:
                //TIMER STOP
                CLR_BIT(TCCR0,0);
                CLR_BIT(TCCR0,1);
                CLR_BIT(TCCR0,2);
                time_taken = (timer_overflow_1*256) + TCNT0;
                entered=0;
                done=1;
                break;
            }
            break;
            case 1:
            switch(entered){
                case 0:
                //8 PRE SCALLER
                CLR_BIT(TCCR0,0);
                SET_BIT(TCCR0,1);
                CLR_BIT(TCCR0,2);
                entered=1;
                break;
                case 1:
                continue;
                break;
            }
            break;
        }
    }
    //RESET TIMER
    timer_overflow_1 = 0;
    TCNT0 = 0;
    distance = (time_taken * (SOUND_SPEED/(float)2000000))/2;//distance in cm is returned || DIVIDE BY TWO BECAUSE EVERY OSCILATION INCREASE TWO TICKS
    return distance;
}

ISR(TIMER0_OVF_vect){
    timer_overflow_1++;
}