#include "DC_MOTOR_STEER_CFG.h"
#include "DC_MOTOR_STEER.h"
#include "DIO.h"

void DC_MOTOR_STEER_INIT(void){
    PIN_MODE(DC_MOTOR_RIGHT,OUTPUT);
    PIN_MODE(DC_MOTOR_LEFT,OUTPUT);
}

void DC_MOTOR_STEER(u8 direction){
    switch(direction){
        case LEFT_ST:
        PIN_WRITE(DC_MOTOR_RIGHT,LOW);
        PIN_WRITE(DC_MOTOR_LEFT,HIGH);
        break;
        case RIGHT_ST:
        PIN_WRITE(DC_MOTOR_RIGHT,HIGH);
        PIN_WRITE(DC_MOTOR_LEFT,LOW);
        break;
        case STRAIGHT_ST:
        PIN_WRITE(DC_MOTOR_RIGHT,LOW);
        PIN_WRITE(DC_MOTOR_LEFT,LOW);
        break;
        default:
        break;
    }
}