#include "LED.h"
#include "TIMERS.h"
#include "DIO.h"

void LED_INIT(void){
    PIN_MODE(PD7,OUTPUT);
    PWM_2_INIT();
}

void LED_LEVEL(u8 level){
    switch(level){
        case LEVEL_0:
        PWM_2_STOP();
        PWM_2_SET_DUYT_CYCLE(0);
        PWM_2_START();
        break;
        case LEVEL_1:
        PWM_2_STOP();
        PWM_2_SET_DUYT_CYCLE(25);
        PWM_2_START();
        break;
        case LEVEL_2:
        PWM_2_STOP();
        PWM_2_SET_DUYT_CYCLE(50);
        PWM_2_START();
        break;
        case LEVEL_3:
        PWM_2_STOP();
        PWM_2_SET_DUYT_CYCLE(75);
        PWM_2_START();
        break;
        case LEVEL_4:
        PWM_2_STOP();
        PWM_2_SET_DUYT_CYCLE(99);
        PWM_2_START();
        break;
        default:
        break;
    }
}

void LED_ON(void){
    LED_LEVEL(LEVEL_4);
}
void LED_OFF(void){
    LED_LEVEL(LEVEL_0);
}