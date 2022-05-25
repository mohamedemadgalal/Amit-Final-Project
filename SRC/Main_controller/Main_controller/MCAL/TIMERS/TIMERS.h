#ifndef TIMERS_H_
#define TIMERS_H_

#define  NORMAL_MODE  1
#define  CTC_MODE     2

#define NON_INVERTED  0
#define INVERTED  1

#include "STD_TYPES.h"

void TIMER_0_INIT(void);
void TIMER_0_SET_TIME(u32);
void TIMER_0_START(void);
void TIMER_0_STOP(void);
void PWM_0_INIT(void);
void PWM_0_SET_DUYT_CYCLE(u8);
void PWM_0_START(void);
void PWM_0_STOP(void);
void PWM_1_INIT(void);
void PWM_1_SET_DUTY_CYCLE(u16);
void PWM_1_START(void);
void PWM_1_STOP(void);
void TIMER_2_START(void);
void TIMER_2_STOP(void);
void PWM_2_INIT(void);
void PWM_2_SET_DUYT_CYCLE(u8);
void PWM_2_START(void);
void PWM_2_STOP(void);


#endif /* TIMERS_H_ */