#include "main.h"

extern float speed;
uint8_t motorState=0;
uint8_t changeSpeed=0;

xQueueHandle commandQueue;
TaskHandle_t measureTaskHandle;
SemaphoreHandle_t uart2ReciveSemaphore;
SemaphoreHandle_t driveEnableSemaphore;


typedef struct
{
	int32_t referenceSpeed;
	int32_t measureSpeed;
	int16_t regulatorReferenceTorque;
	int16_t measureTorque;
	uint32_t timeStamp;
}motorData_t;

void measureTask(void* pvParameters)
{
	motorData_t data;
	mcpErrorCode error[4];
	while(1)
	{
		error[0]=getSpeed(USART1,&data.measureSpeed);
		error[1]=getTorque(USART1,&data.measureTorque);
		error[2]=getRegulatorTorqueRef(USART1,&data.regulatorReferenceTorque);
		error[3]=getReferenceSpeed(USART1,&data.referenceSpeed);
		data.timeStamp=TIM5->CNT;	
		if(error[0]==ERROR_NONE && error[1]==ERROR_NONE && error[2]==ERROR_NONE && error[3]==ERROR_NONE)
		{
			uartTransmitt(11,USART2);
			uartTransmittBuff((uint8_t*)&data,sizeof(motorData_t),USART2);
		}
	}
}

void controlTask(void* pvParameters)
{
	while(1)
	{
		 if(changeSpeed==1)
		 {
				if(!motorState)
				{
					if(startMotor(USART1)==ERROR_NONE) motorState=1;
				}
				else
				{
					if(stopMotor(USART1)==ERROR_NONE) motorState=0;
				}
				changeSpeed=0;
		 }		
		 //vTaskDelay(1);
	}
}

void commandReciveTask(void* pvParameters)
{
	static uint8_t uart2ReciveState=0;
	controlCommand_t command;
	uint8_t dataLen=0;
	while(1)
	{
		if(xSemaphoreTake(uart2ReciveSemaphore,portMAX_DELAY) == pdTRUE )
		{
			if(uart2ReciveState==0)
			{
				command.command=USART2->DR;
				uart2ReciveState++;
			}
			else if(uart2ReciveState==1)
			{
				dataLen=USART2->DR;
			}
		}
	}
} 

void EXTI15_10_IRQHandler(void)
{
	BaseType_t needCS = pdFALSE;
	EXTI->PR|=EXTI_PR_PR13;
	changeSpeed=1;
}

void buttonInit(void)
{
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOCEN;//Тактирование порта C
	GPIOC->PUPDR|=GPIO_PUPDR_PUPD13_0;//PC13 Pull up
	NVIC_EnableIRQ(EXTI15_10_IRQn);//Включить прерывание
	SYSCFG->EXTICR[3]|=SYSCFG_EXTICR4_EXTI13_PC;
	EXTI->IMR|=EXTI_IMR_IM13;
	EXTI->FTSR|=EXTI_FTSR_TR13;
}

/*void tim5Init()
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM5EN;
	TIM5->PSC=1;
	TIM5->ARR=0xFFFFFFFF;
	TIM5->CNT=0;
	TIM5->CR1|=TIM_CR1_CEN;
}   */

int main()
{
	mcpErrorCode err;
 	RccClockInit();
	encoderInit();
	uart2Init(100000000,115200);
	uart1Init(100000000,14400);
	//buttonInit();
	err=setSpeed(1000,100,USART1);
	//startMotor(USART1);
	//commandQueue = xQueueCreate(5, sizeof(motorData_t));
	//driveEnableSemaphore=xSemaphoreCreateBinary();
	//xTaskCreate(measureTask,"measureTask",configMINIMAL_STACK_SIZE,NULL,configMAX_PRIORITIES-3,&measureTaskHandle);
	//TaskSuspend(measureTaskHandle);
	//xTaskCreate(controlTask,"controlTask",configMINIMAL_STACK_SIZE,NULL,configMAX_PRIORITIES-3,NULL);
	//xTaskCreate(commandReciveTask,"commandReciveTask",configMINIMAL_STACK_SIZE,NULL,configMAX_PRIORITIES-2,NULL);
	//tim5Init();
	//vTaskStartScheduler();
	while(1)
	{
		
	}
}
