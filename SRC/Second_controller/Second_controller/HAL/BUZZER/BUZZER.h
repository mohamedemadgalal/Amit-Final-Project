#ifndef BUZZER_H_
#define BUZZER_H_

#include "STD_TYPES.h"
#include "DIO.h"

#define  BUZZER_0 PA3

void BUZZER_INIT(u8);
void BUZZER_ON(u8);
void BUZZER_OFF(u8);
void BUZZER_NEAR_1(u8);
void BUZZER_NEAR_2(u8);
void BUZZER_INTERMEDIATE_1(u8);
void BUZZER_INTERMEDIATE_2(u8);
void BUZZER_FAR_1(u8);
void BUZZER_FAR_2(u8);

#endif /* BUZZER_H_ */