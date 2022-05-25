#include "DC_MOTOR_CFG.h"
#include "DC_MOTOR.h"
#include "TIMERS.h"
#include "DIO.h"

void DC_MOTOR_INIT(void){
    PIN_MODE(DC_MOTOR_DIRECTION_PIN_1,OUTPUT);
    PIN_MODE(DC_MOTOR_DIRECTION_PIN_2,OUTPUT);
    PIN_MODE(DC_MOTOR_PIN_1,OUTPUT);
    PIN_WRITE(DC_MOTOR_DIRECTION_PIN_1,HIGH);
    PIN_WRITE(DC_MOTOR_DIRECTION_PIN_2,LOW);
    PWM_0_INIT();
}
void DC_MOTOR_START(void){
    PWM_0_START();
}
void DC_MOTOR_STOP(void){
    PWM_0_STOP();
}
void DC_MOTOR_SET_SPEED(u8 speed){
    DC_MOTOR_STOP();
    PWM_0_SET_DUYT_CYCLE(speed);
    DC_MOTOR_START();
}

void DC_MOTOR_SET_DIRECTION(u8 direction){
    DC_MOTOR_STOP();
    switch(direction){
        case CLK_WISE:
        PIN_WRITE(DC_MOTOR_DIRECTION_PIN_1,LOW);
        PIN_WRITE(DC_MOTOR_DIRECTION_PIN_2,HIGH);
        break;
        case ANTI_CLK_WISE:
        PIN_WRITE(DC_MOTOR_DIRECTION_PIN_1,HIGH);
        PIN_WRITE(DC_MOTOR_DIRECTION_PIN_2,LOW);
        break;
        default:
        break;
    }
    DC_MOTOR_START();
}