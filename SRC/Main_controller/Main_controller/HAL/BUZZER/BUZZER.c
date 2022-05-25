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