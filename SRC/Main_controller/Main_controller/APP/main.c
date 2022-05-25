#define  F_CPU 16000000UL
#include "util/delay.h"
#include "LED.h"
#include "DC_MOTOR.h"
#include "HC_05.h"
#include "DC_MOTOR_STEER.h"
#include "BUZZER.h"
#include "STD_TYPES.h"

u8 Led_Level = LEVEL_0;
u8 Direction = CLK_WISE;
u8 Speed = 0;

void ChangeSteeringDegree(s8);
void ChangeLedLevel(u8);
void ChangeMotorSpeed(u8);
void ChangeMotorDirection(u8);
void ChangeSteerDirection(u8);

int main(void){
    DC_MOTOR_INIT();
    DC_MOTOR_SET_DIRECTION(Direction);
    DC_MOTOR_SET_SPEED(0);
    LED_INIT();
    HC_05_INIT();
    DC_MOTOR_STEER_INIT();
    LED_LEVEL(Led_Level);
    BUZZER_INIT(BUZZER_0); 
    while (1) {
        if(DATA_RECIEVED() == 1){
            u8 data;
            u8 value=0;
            data = HC_05_REC_BYTE();
            enum BLUETOOTH_CODE B_CODE;
            B_CODE = data;
            switch(B_CODE){
                case SPEED:
                while((data = HC_05_REC_BYTE()) != B_CODE){
                    value = value * 10;
                    value = value + (data-'0');
                }
                ChangeMotorSpeed(value);
                value=0;
                break;
                case ANTI_CLK_WISE_B:
                ChangeMotorDirection(ANTI_CLK_WISE);
                break;
                case CLK_WISE_B:
                ChangeMotorDirection(CLK_WISE);
                break;
                case RIGHT:
                ChangeSteerDirection(RIGHT_ST);
                break;
                case STRAIGHT:
                ChangeSteerDirection(STRAIGHT_ST);
                break;
                case LEFT:
                ChangeSteerDirection(LEFT_ST);
                break;
                case HORN_ON:
                BUZZER_ON(BUZZER_0);
                break;
                case HORN_OFF:
                BUZZER_OFF(BUZZER_0);
                break;
                case LED:
                if(Led_Level == LEVEL_4){
                    Led_Level = LEVEL_0;
                }else{
                    Led_Level++;
                }
                ChangeLedLevel(Led_Level);
                break;
                default:
                break;
            }
        }
    }
}

void ChangeLedLevel(u8 level){
    LED_LEVEL(level);
}

void ChangeMotorSpeed(u8 speed){
    DC_MOTOR_SET_SPEED(speed);
}

void ChangeMotorDirection(u8 direction){
    DC_MOTOR_SET_DIRECTION(direction);
}

void ChangeSteerDirection(u8 direction){
    DC_MOTOR_STEER(direction);
}