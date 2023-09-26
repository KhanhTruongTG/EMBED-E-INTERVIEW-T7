#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stdlib.h"
#include "Delay.h"

#define Tx      GPIO_Pin_6
#define Rx      GPIO_Pin_7
#define PORTS   GPIOB

#define LED     GPIO_Pin_13

void checkled(void);
void configurationGpioUart(void);
void configurationGpioLed(void);

void waitForStartReceive(void);
void waitForEndReceive(void);
uint8_t receiveData(void);

int main(void){
	
	configurationGpioUart();
	configurationGpioLed();
	
	uint8_t * dataReceive = (uint8_t*)malloc(4*sizeof(uint8_t));
	
	uint8_t i = 0;
	
	GPIO_SetBits(PORTS, Rx);
	delayMs(1000);
	
	while(i < 4){
	
		waitForStartReceive();
			
		*dataReceive = receiveData();
			
		waitForEndReceive();
			
		checkled();                // receive data: 1 byte then turn on Led PC13
		dataReceive++;
		i++;
	}
	free(dataReceive);
	return 0;
}

void configurationGpioUart(){
	
	GPIO_InitTypeDef gpio;
	
	/*ENABLE CLOCK*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	/*PB7 RX*/
	gpio.GPIO_Pin   = Rx;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_IPU;
	GPIO_Init(PORTS, &gpio);
	
	/*PB6 TX*/
	gpio.GPIO_Pin   = Tx;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init(PORTS, &gpio);
}

void configurationGpioLed(){

	// Enable clock Port C
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	// Reset Port C
	GPIOC->CRH &= ~(GPIO_CRH_CNF13 | GPIO_CRH_MODE13);
	// Set output PC13
	GPIOC->CRH |= GPIO_CRH_MODE13_0;
	
}
void waitForStartReceive(){

	while(GPIO_ReadInputDataBit(PORTS, Rx) == 1)
	delayMs(15);
}
void waitForEndReceive(){
	
	while(GPIO_ReadInputDataBit(PORTS, Rx) == 0);
	delayMs(20);
}

void checkled(){
	
	GPIOC->BSRR = GPIO_BSRR_BR13;
	delayMs(100);								 // bit time
	GPIOC->BSRR = GPIO_BSRR_BS13;
	delayMs(100);								 // bit time
	
}

uint8_t receiveData(){

	uint8_t data  = 0;
	uint8_t countBit1 = 0;
			
	for(uint8_t i = 0 ; i < 9; i++ ){
	
	if(GPIO_ReadInputDataBit(PORTS,Rx) == 1) { 
		
		 if(i < 8 ) data |= 1 << i;
			
		 countBit1++;
	}
	
	delayMs(10);
	
	}
	
	if(countBit1 % 2 == 0 ) return data;
	
}