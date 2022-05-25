#include "ULTRA_SONIC.h"
#include "BUZZER.h"
#include "STD_TYPES.h"
#define  F_CPU 16000000UL
#include "util/delay.h"

int main(void){
    ULTRA_SONIC_INIT_1();
    BUZZER_INIT(BUZZER_0);
    u16 reading_1;
    while(1){
        reading_1 = MEASURE_DISTANCE_1();
        if(reading_1 < 5){
            BUZZER_NEAR_1(BUZZER_0);
        }else if(reading_1 < 10){
            BUZZER_NEAR_2(BUZZER_0);
        }else if(reading_1 < 15){
            BUZZER_INTERMEDIATE_1(BUZZER_0);
        }else if(reading_1 < 20){
            BUZZER_INTERMEDIATE_2(BUZZER_0);
        }else if(reading_1 < 25){
            BUZZER_FAR_1(BUZZER_0);
        }else if(reading_1 < 30){
            BUZZER_FAR_2(BUZZER_0);
        }else{
            BUZZER_OFF(BUZZER_0);
        }
    }
}