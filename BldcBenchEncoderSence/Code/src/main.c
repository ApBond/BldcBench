#include "main.h"
#include "math.h"

#define CURRENT_K 2194
#define CURRENT_PI 1463
#define SPEED_K 2000
#define SPEED_PI 500
#define SPEED_D 100
#define APPLICATION_SPEED 500

#define STEP_MAX 1500
#define STEP_MIN 0
#define STEP_T 8000 

#define BUFF_SIZE 10000

extern uint32_t speed;
uint8_t motorState=0;
uint8_t motorStart=0;

typedef struct
{
	float measureSpeed;
	uint16_t timeStamp;
}motorData_t;

//motorData_t measureBuff[BUFF_SIZE];

void EXTI15_10_IRQHandler(void)
{

	EXTI->PR|=EXTI_PR_PR13;
	motorStart=1;
}

void buttonInit(void)
{
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOCEN;//Тактирование порта C
	GPIOC->PUPDR|=GPIO_PUPDR_PUPD13_0;//PC13 Pull up
	NVIC_EnableIRQ(EXTI15_10_IRQn);//Включить прерывание
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



int main()
{
	uint32_t i,j;
	mcpErrorCode error=ERROR_NONE;
	uint32_t measureSpeed;
	uint16_t timeStamp;
 	RccClockInit();
	encoderInit();
	uart2Init(100000000,115200);
	uart1Init(100000000,115200);
	buttonInit();
	Tim4Init();
	delayInit();
	while(1)
	{
		if(motorStart)
		{
			if(!motorState)
			{
				i=0;
				error=setSpeed(APPLICATION_SPEED,1,USART1);
				error=startMotor(USART1);	
				TIM4->CNT=0;
				TIM4->CR1|=TIM_CR1_CEN;
			}
			else
			{			
				error=stopMotor(USART1);	
				TIM4->CR1&=~TIM_CR1_CEN;
			}
			if(error==ERROR_NONE) motorState=~motorState;
			motorStart=0;
		}
		/*if(i==BUFF_SIZE-1)
		{
			stopMotor(USART1);
			motorState=~motorState;
			uartTransmitt(11,USART2);
			for(j=0;j<BUFF_SIZE;j++)
			{
				uartTransmittBuff((uint8_t*)&measureBuff[j].measureSpeed,sizeof(float),USART2);
				uartTransmittBuff((uint8_t*)&measureBuff[j].timeStamp,sizeof(uint16_t),USART2);
			}
			//uartTransmittBuff((uint8_t*)&measureBuff,(sizeof(float)+sizeof(uint16_t))*BUFF_SIZE,USART2);
			
		}*/
		if(motorState)
		{
			measureSpeed=speed;
			timeStamp=TIM4->CNT;
			//i++;
			uartTransmitt(11,USART2);
			uartTransmittBuff((uint8_t*)&measureSpeed,sizeof(uint32_t),USART2);
			uartTransmittBuff((uint8_t*)&timeStamp,sizeof(uint16_t),USART2);
			//delay_ms(1);
		}		
	}
}
