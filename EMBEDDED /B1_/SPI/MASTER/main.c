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
	
	gpio.GPIO_Pin 	= SCLK | MOSI | SS;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init(PORTS, &gpio);
	
	gpio.GPIO_Pin   = LED;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC,&gpio);
}

void spiInit(){
	GPIO_SetBits(PORTS, SS);        
	GPIO_ResetBits(PORTS, SCLK); 
	GPIO_ResetBits(PORTS, MOSI);
}

void clockPulse(){                 // Set CPOL : 0   // idle state
	GPIO_SetBits(PORTS, SS);        // CPHA = 0 : leading edge is rising edge
	delay(100000);
	GPIO_ResetBits(PORTS, SS);
	delay(100000);
		
}

void transmitData(int inputData){
	GPIO_ResetBits(PORTS, SS);
	for(uint8_t i = 0; i < 8; i++){
			if(inputData & (1 << 0))   GPIO_SetBits(PORTS, MOSI);
			else GPIO_ResetBits(PORTS, MOSI);
			clockPulse();
	}
	GPIO_SetBits(PORTS, SS);
}

void ledCode(){
	GPIO_SetBits(GPIOC,LED);
	delay(200);
	GPIO_ResetBits(GPIOC,LED);
	delay(200);
}

int main(){
	config();
	ledCode();
	spiInit();
	int transmitdata = 200;
	delay(20000);
	transmitData(transmitdata);
	return 0;
}
