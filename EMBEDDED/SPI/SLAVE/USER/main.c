#include "stm32f10x.h"

#define SCLK    GPIO_Pin_6
#define MOSI    GPIO_Pin_7
#define SS      GPIO_Pin_8
#define PORTS   GPIOB

#define LED     GPIO_Pin_13

void delay(int time){
	for(int i = 0; i < time; i++);
}

void config(){

	GPIO_InitTypeDef gpio;
	
	RCC_APB2PeriphClockCmd(RCC_APB2ENR_IOPBEN, ENABLE);
	
	gpio.GPIO_Pin   = SCLK | MOSI ;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_IPD;
	GPIO_Init(PORTS, &gpio);
	
	gpio.GPIO_Pin   = SS;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_IPU;
	GPIO_Init(PORTS, &gpio);
	
	gpio.GPIO_Pin   = LED;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC,&gpio);
}

void receiveData(){
	while(GPIO_ReadInputDataBit(PORTS, SS) == 1);
	int dataReceive;
	for(int i = 0; i < 8 ; i++){
	while(GPIO_ReadInputDataBit(PORTS, SCLK) == 0);
	if(GPIO_ReadInputDataBit(PORTS, MOSI) == 1)  dataReceive |= 1<< i;
	while(GPIO_ReadInputDataBit(PORTS, SCLK) == 1);
	}
}

void dataReceptionSignal(){
		GPIO_SetBits(GPIOC,LED);
		delay(200);
		GPIO_ResetBits(GPIOC,LED);
		delay(200);
}

int main(){
	config();
	receiveData();     //receive data: 1 byte after turning on the led PC13
	dataReceptionSignal();
	return 0;
}