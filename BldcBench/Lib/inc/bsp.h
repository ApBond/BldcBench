#ifndef MC_BSP
#define MC_BSP

#include "stm32f411xe.h"
#include "stm32f411xe.h"
#include "FreeRTOS.h"                   // ARM.FreeRTOS::RTOS:Core
#include "queue.h"                      // ARM.FreeRTOS::RTOS:Core
#include "semphr.h"                     // ARM.FreeRTOS::RTOS:Core
#include "task.h"                       // ARM.FreeRTOS::RTOS:Core
#include "MCP.h"


#define UART_MAX_TIMEOUT_MS 20

void uart2Init(uint32_t coreFreq, uint32_t baudRate);
void uart1Init(uint32_t coreFreq, uint32_t baudRate);
void uartTransmitt(uint8_t data,USART_TypeDef * UART);
void uartTransmittBuff(uint8_t* data,uint32_t size,USART_TypeDef * UART);
uint8_t uartRecive(USART_TypeDef * UART);

#endif