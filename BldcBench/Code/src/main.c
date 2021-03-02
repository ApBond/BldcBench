#include "main.h"

#define CURRENT_K 308
#define CURRENT_PI 205
#define SPEED_K 10
#define SPEED_PI 7

extern float speed;
uint8_t motorState=0;
uint8_t changeSpeed=0;

xQueueHandle commandQueue;
TaskHandle_t measureTaskHandle;
SemaphoreHandle_t uart2ReciveSemaphore;
SemaphoreHandle_t buttonClickSemaphore;


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
		//data.regulatorReferenceTorque=data.measureTorque;
		//error[2]=ERROR_NONE;
		error[3]=getReferenceSpeed(USART1,&data.referenceSpeed);
		data.timeStamp=TIM5->CNT;	
		if(error[0]==ERROR_NONE && error[1]==ERROR_NONE && error[2]==ERROR_NONE && error[3]==ERROR_NONE)
		{
			uartTransmitt(11,USART2);
			uartTransmittBuff((uint8_t*)&data,sizeof(motorData_t),USART2);
		}
		//vTaskDelay(100);
	}
}

void controlTask(void* pvParameters)
{
	while(1)
	{
		 if(xSemaphoreTake(buttonClickSemaphore,portMAX_DELAY) == pdTRUE )
		 {
				if(!motorState)
				{
					//if(startMotor(USART1)==ERROR_NONE) motorState=1;
					GPIOA->BSRR=GPIO_BSRR_BS5;
					
				}
				else
				{
					//if(stopMotor(USART1)==ERROR_NONE) motorState=0;
					GPIOA->BSRR=GPIO_BSRR_BR5;
				}
				motorState=~motorState;
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
			//Прием команды по UART
			if(uart2ReciveState==0)
			{
				command.command=USART2->DR;
				uart2ReciveState++;
			}
			else if(uart2ReciveState==1)
			{
				dataLen=USART2->DR;
				uart2ReciveState++;
			}
			else
			{
					if(uart2ReciveState-2==dataLen)
					{
						
					}
					else
					{
						command.data[uart2ReciveState-2]=USART2->DR;
						uart2ReciveState++;
					}
			}
		}
	}
} 

void EXTI15_10_IRQHandler(void)
{
	BaseType_t needCS = pdFALSE;
	EXTI->PR|=EXTI_PR_PR13;
	xSemaphoreGiveFromISR(buttonClickSemaphore, &needCS);
	portYIELD_FROM_ISR(needCS);
}

void buttonInit(void)
{
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOCEN;//Тактирование порта C
	GPIOC->PUPDR|=GPIO_PUPDR_PUPD13_0;//PC13 Pull up
	NVIC_EnableIRQ(EXTI15_10_IRQn);//Включить прерывание
	NVIC_SetPriority(EXTI15_10_IRQn,6);
	SYSCFG->EXTICR[3]|=SYSCFG_EXTICR4_EXTI13_PC;
	EXTI->IMR|=EXTI_IMR_IM13;
	EXTI->FTSR|=EXTI_FTSR_TR13;
	__enable_irq();
}

void Tim5Init()
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM5EN;
	TIM5->CNT=0;
	TIM5->PSC=10000-1; 
	TIM5->EGR|=TIM_EGR_UG;//!!Генерация update event для запись предделителя!!
	TIM5->ARR=0xFFFFFFFF;	
	TIM5->CR1|=TIM_CR1_CEN;
}   
mcpErrorCode err;
int main()
{
 	RccClockInit();
	//encoderInit();
	uart2Init(100000000,115200);
	uart1Init(100000000,115200);
	buttonInit();
	err=setTorquePID(CURRENT_K,CURRENT_PI,0,USART1);
	err=setFluxPID(CURRENT_K,CURRENT_PI,0,USART1);
	err=setSpeedPID(SPEED_K,SPEED_PI,0,USART1);
	err=setSpeed(1000,100,USART1);
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER|=GPIO_MODER_MODE5_0;
	//err=startMotor(USART1);
	//startMotor(USART1);
	//commandQueue = xQueueCreate(5, sizeof(motorData_t));
	buttonClickSemaphore=xSemaphoreCreateBinary();
	xTaskCreate(measureTask,"measureTask",configMINIMAL_STACK_SIZE,NULL,configMAX_PRIORITIES-3,&measureTaskHandle);
	//TaskSuspend(measureTaskHandle);
	xTaskCreate(controlTask,"controlTask",configMINIMAL_STACK_SIZE,NULL,configMAX_PRIORITIES,NULL);
	//xTaskCreate(commandReciveTask,"commandReciveTask",configMINIMAL_STACK_SIZE,NULL,configMAX_PRIORITIES-2,NULL);
	Tim5Init();
	vTaskStartScheduler();
	while(1)
	{
		
	}
}
