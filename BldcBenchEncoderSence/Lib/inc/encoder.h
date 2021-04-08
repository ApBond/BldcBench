#ifndef __ENCODER
#define __ENCODER

#include "stm32f411xe.h"
#include "delay.h"

#define ENCODER_STEP_COUNT 720

void encoderInit(void);

#endif