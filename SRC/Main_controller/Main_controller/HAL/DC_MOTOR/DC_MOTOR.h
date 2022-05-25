#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "STD_TYPES.h"

#define  CLK_WISE       0
#define  ANTI_CLK_WISE  1

void DC_MOTOR_INIT(void);
void DC_MOTOR_START(void);
void DC_MOTOR_STOP(void);
void DC_MOTOR_SET_SPEED(u8);
void DC_MOTOR_SET_DIRECTION(u8);

#endif /* DC_MOTOR_H_ */