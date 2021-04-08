#include "main.h"
#include "math.h"

#define CURRENT_K 2194
#define CURRENT_PI 1463
#define SPEED_K 2000
#define SPEED_PI 500
#define SPEED_D 100
#define APPLICATION_SPEED 1500

#define STEP_MAX 2000
#define STEP_MIN 0
#define STEP_T 10000 

extern float speed;
uint8_t motorState=0;
uint8_t changeSpeed=0;

xQueueHandle commandQueue;
TaskHandle_t measureTaskHandle;
TaskHandle_t speedCntrTaskHandle;
SemaphoreHandle_t uart2ReciveSemaphore;
SemaphoreHandle_t buttonClickSemaphore;


typedef struct
{
	//int32_t referenceSpeed;
	int32_t measureSpeed;
	//int16_t regulatorReferenceTorque;
	//int16_t measureTorque;
	uint16_t timeStamp;
}motorData_t;

void speedCntrTask(void* pvParameters)
{
	mcpErrorCode err;
	while(1)
	{
		//err=setSpeed((uint32_t)(APPLICATION_SPEED+APPLICATION_SPEED*sinf((float)(TIM5->CNT)/(float)(10000))),1,USART1);
		//vTaskDelay(1);
		setSpeed(STEP_MAX,1,USART1);
		vTaskDelay(STEP_T/2);
		setSpeed(STEP_MIN,1,USART1);
		vTaskDelay(STEP_T/2);
	}

}
void measureTask(void* pvParameters)
{
	motorData_t data;
	mcpErrorCode error[4];
	while(1)
	{
		taskENTER_CRITICAL(); 
		{
			getSpeed(USART1,&data.measureSpeed);
			//data.measureSpeed=(int32_t)speed;
			//error[1]=getTorque(USART1,&data.measureTorque);
			//error[2]=getRegulatorTorqueRef(USART1,&data.regulatorReferenceTorque);
			//data.regulatorReferenceTorque=data.measureTorque;
			//error[2]=ERROR_NONE;
			//error[3]=getReferenceSpeed(USART1,&data.referenceSpeed);
			data.timeStamp=TIM4->CNT;
		}			
		taskEXIT_CRITICAL(); 
		uartTransmitt(11,USART2);
		uartTransmittBuff((uint8_t*)&data.measureSpeed,sizeof(int32_t),USART2);
		uartTransmittBuff((uint8_t*)&data.timeStamp,sizeof(uint16_t),USART2);
		//uartTransmittBuff((uint8_t*)&data,sizeof(motorData_t),USART2);
		/*taskENTER_CRITICAL(); 
		{
			data.measureSpeed=(uint16_t)speed;
			data.timeStamp=(uint16_t)TIM4->CNT;
		}
		taskEXIT_CRITICAL();
		uartTransmitt(11,USART2);
		uartTransmittBuff((uint8_t*)&data,sizeof(motorData_t),USART2);*/
	}
}

void controlTask(void* pvParameters)
{
	controlCommand_t command;
	mcpErrorCode error=ERROR_NONE;
	while(1)
	{
		if(xSemaphoreTake(buttonClickSemaphore,portMAX_DELAY)==pdTRUE)
		{
			error=ERROR_NONE;
			if(!motorState)
			{
				GPIOA->BSRR=GPIO_BSRR_BS5;
				setSpeed(0,1,USART1);
				error=startMotor(USART1);	
				TIM4->CNT=0;
				TIM4->CR1|=TIM_CR1_CEN;
				xTaskCreate(speedCntrTask,"speedCntrTask",configMINIMAL_STACK_SIZE,NULL,configMAX_PRIORITIES-2,&speedCntrTaskHandle);
				vTaskResume(measureTaskHandle);
			}
			else
			{
				GPIOA->BSRR=GPIO_BSRR_BR5;
				vTaskDelete(speedCntrTaskHandle);
				vTaskSuspend(measureTaskHandle);				
				error=stopMotor(USART1);	
				TIM4->CR1&=~TIM_CR1_CEN;
			}
			if(error==ERROR_NONE) motorState=~motorState;
		}
		 /*if(xQueueReceive(commandQueue,&command,portMAX_DELAY) == pdTRUE )
		 {
			 switch(command.command)
			 {
				 case START:
					 GPIOA->BSRR=GPIO_BSRR_BS5;
					 startMotor(USART1);
					 break;
				 case STOP:
					 stopMotor(USART1);
					 break;
				 case CHANGE_SPEED:
					 break;
			 }
		 }*/		
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
						uart2ReciveState=0;
						dataLen=0;
						xQueueSendToBack(commandQueue,(const void*)&command,1000);
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

void Tim4Init()
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM4EN;
	TIM4->CNT=0;
	TIM4->PSC=10000-1; 
	TIM4->EGR|=TIM_EGR_UG;//!!Генерация update event для запись предделителя!!
	TIM4->ARR=0xFFFF;	
	TIM4->CR1|=TIM_CR1_CEN;
} 
mcpErrorCode err;
int main()
{
 	RccClockInit();
	//encoderInit();
	uart2Init(100000000,115200);
	uart1Init(100000000,115200);
	buttonInit();
	/*err=setTorquePID(CURRENT_K,CURRENT_PI,0,USART1);
	err=setFluxPID(CURRENT_K,CURRENT_PI,0,USART1);
	err=setSpeedPID(SPEED_K,SPEED_PI,SPEED_D,USART1);*/
	//err=setSpeed(APPLICATION_SPEED,1,USART1);
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER|=GPIO_MODER_MODE5_0;
	commandQueue = xQueueCreate(5, sizeof(controlCommand_t));
	buttonClickSemaphore=xSemaphoreCreateBinary();
	uart2ReciveSemaphore=xSemaphoreCreateBinary();
	xTaskCreate(measureTask,"measureTask",configMINIMAL_STACK_SIZE,NULL,configMAX_PRIORITIES-3,&measureTaskHandle);
	//xTaskCreate(speedCntrTask,"speedCntrTask",configMINIMAL_STACK_SIZE,NULL,configMAX_PRIORITIES-2,&speedCntrTaskHandle);
	vTaskSuspend(measureTaskHandle);
	//vTaskSuspend(speedCntrTaskHandle);
	xTaskCreate(controlTask,"controlTask",configMINIMAL_STACK_SIZE,NULL,configMAX_PRIORITIES-1,NULL);
	
	//xTaskCreate(commandReciveTask,"commandReciveTask",configMINIMAL_STACK_SIZE,NULL,configMAX_PRIORITIES-1,NULL);
	Tim4Init();
	vTaskStartScheduler();
	while(1)
	{
		
	}
}
