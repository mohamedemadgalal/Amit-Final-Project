#ifndef LED_H_
#define LED_H_

#include "STD_TYPES.h"

#define LEVEL_0 0
#define LEVEL_1 1
#define LEVEL_2 2
#define LEVEL_3 3
#define LEVEL_4 4

void LED_INIT(void);
void LED_LEVEL(u8);
void LED_ON(void);
void LED_OFF(void);

#endif /* LED_H_ */