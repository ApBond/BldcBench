#ifndef MAIN_H
#define MAIN_H

#include "stm32f411xe.h"
#include "FreeRTOS.h"                   // ARM.FreeRTOS::RTOS:Core
#include "queue.h"                      // ARM.FreeRTOS::RTOS:Core
#include "semphr.h"                     // ARM.FreeRTOS::RTOS:Core
#include "task.h"                       // ARM.FreeRTOS::RTOS:Core
#include "encoder.h"
#include "rcc.h"
#include "bsp.h"
#include "MotorControl.h"
#include "MCP.h"
#include <stdio.h>

typedef enum
{
	START=1,
	STOP=2,
	CHANGE_SPEED=3
}commandCode_t;

typedef struct
{
	commandCode_t command;
	uint8_t dataLen;
	uint8_t data[4];
}controlCommand_t;

#endif