/*
 * HC_05.h
 *
 * Created: 30/11/2021 07:06:24 م
 *  Author: dell
 */ 


#ifndef HC_05_H_
#define HC_05_H_

#include "STD_TYPES.h"

enum BLUETOOTH_CODE{SPEED=101,STEERING/*=102*/,LED/*=103*/,ANTI_CLK_WISE_B/*=104*/,CLK_WISE_B/*=105*/,RIGHT/*=106*/,STRAIGHT/*=107*/,LEFT/*=108*/,HORN_ON/*=109*/,HORN_OFF/*=110*/};

void HC_05_INIT(void);
void HC_05_SEND_BYTE(u8);
u8   HC_05_REC_BYTE(void);
u8   DATA_RECIEVED(void);
#endif /* HC_05_H_ */