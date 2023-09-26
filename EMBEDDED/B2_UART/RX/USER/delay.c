#include "Delay.h"

#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"

static uint16_t miliSecond;

void TIM2_Init(){

	/* INIT STRUCT */
	TIM_TimeBaseInitTypeDef timeBaseInitStruct;
	
	/* ENABLE CLOCK*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	/* INIT TIM2*/
	timeBaseInitStruct.TIM_Prescaler = 1000;
	timeBaseInitStruct.TIM_Period    = 31;     // 1ms     timer count: 0 -> 31
	timeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	timeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM2, &timeBaseInitStruct);
	
	/* TIM2 INTERRUPT*/
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	/* START TIM2*/
	TIM_Cmd(TIM2,ENABLE);
	
	/* INIT INTERRUPT */
	NVIC_InitTypeDef nvicInitStruct;
	
	nvicInitStruct.NVIC_IRQChannel                     = TIM2_IRQn;
	nvicInitStruct.NVIC_IRQChannelPreemptionPriority   = 0x00;
	nvicInitStruct.NVIC_IRQChannelSubPriority          = 0x00;
	nvicInitStruct.NVIC_IRQChannelCmd                  = ENABLE;
	
	NVIC_Init(&nvicInitStruct);
	
}

void configurationLed(){
	
	/* INIT STRUCT */
	GPIO_InitTypeDef gpio;
	
	/* ENABLE CLOCK*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	gpio.GPIO_Mode  = GPIO_Mode_Out_OD;
	gpio.GPIO_Pin   = GPIO_Pin_13;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &gpio);
}

static void RCC_Configuration(void){

	RCC_DeInit();
	
	RCC_HSEConfig(RCC_HSE_ON);
	while(RCC_WaitForHSEStartUp() != SUCCESS ){};
		
	RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_4);  // Config clock : 32MHz
	while(RCC_GetFlagStatus(RCC_FLAG_HSERDY) != SET){};
		
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	while(RCC_GetSYSCLKSource() != 0x08){};
	
}

void TIM2_IRQHandler(){
	
	miliSecond ++;
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	
}

void delayMs(uint32_t time){
	
	miliSecond = 0;
	
	while( miliSecond < time){};

}