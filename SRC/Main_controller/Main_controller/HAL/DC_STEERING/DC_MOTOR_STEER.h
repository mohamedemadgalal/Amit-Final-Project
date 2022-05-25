#ifndef DC_MOTOR_STEER_H_
#define DC_MOTOR_STEER_H_

#include "STD_TYPES.h"

#define  STRAIGHT_ST       0
#define  RIGHT_ST          1
#define  LEFT_ST           2

void DC_MOTOR_STEER_INIT(void);
void DC_MOTOR_STEER(u8);

#endif /* DC_MOTOR_H_ */