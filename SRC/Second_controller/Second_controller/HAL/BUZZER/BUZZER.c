#include "BUZZER.h"
#define F_CPU 16000000
#include "util/delay.h"
#include "DIO.h"

void BUZZER_INIT(u8 buzzer_no){
	PIN_MODE(buzzer_no,OUTPUT);
}

void BUZZER_ON(u8 buzzer_no){
	PIN_WRITE(buzzer_no,HIGH);
}

void BUZZER_OFF(u8 buzzer_no){
	PIN_WRITE(buzzer_no,LOW);
}

void BUZZER_NEAR_1(u8 buzzer_no){
	BUZZER_ON(buzzer_no);
	_delay_ms(100);
	BUZZER_OFF(buzzer_no);
}

void BUZZER_NEAR_2(u8 buzzer_no){
    BUZZER_ON(buzzer_no);
    _delay_ms(200);
    BUZZER_OFF(buzzer_no);
}

void BUZZER_INTERMEDIATE_1(u8 buzzer_no){
    BUZZER_ON(buzzer_no);
    _delay_ms(300);
    BUZZER_OFF(buzzer_no);
}

void BUZZER_INTERMEDIATE_2(u8 buzzer_no){
    BUZZER_ON(buzzer_no);
    _delay_ms(400);
    BUZZER_OFF(buzzer_no);
}

void BUZZER_FAR_1(u8 buzzer_no){
    BUZZER_ON(buzzer_no);
    _delay_ms(500);
    BUZZER_OFF(buzzer_no);
}

void BUZZER_FAR_2(u8 buzzer_no){
    BUZZER_ON(buzzer_no);
    _delay_ms(600);
    BUZZER_OFF(buzzer_no);
}