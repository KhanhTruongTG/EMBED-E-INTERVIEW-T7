#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "Delay.h"


#define Tx   		GPIO_Pin_6
#define Rx   		GPIO_Pin_7
#define PORTS 		GPIOB

#define LED     GPIO_Pin_13

void configurationGpioUart(){

	GPIO_InitTypeDef gpio;
	
	/*ENABLE CLOCK*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	/*PB6 TX*/
	gpio.GPIO_Pin   = Tx;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init(PORTS, &gpio);
	
	/*PB7 RX*/
	gpio.GPIO_Pin   = Rx;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_IPU;
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

void checkled(){
	
	GPIOC->BSRR = GPIO_BSRR_BR13;
	delayMs(100);                 // bit time
	GPIOC->BSRR = GPIO_BSRR_BS13;
	delayMs(100); 
}

void startCondition(){

	GPIO_ResetBits(PORTS,Tx);
	delayMs(10);                 // bit time
	
}

uint8_t transmitData(uint8_t data){
	
	uint8_t countBit = 0;
	
	for(uint8_t i = 0 ; i< 8; i++){
		
		 if(data & (1 << 0)) {
			
				countBit ++;
				GPIO_SetBits(PORTS, Tx);
			
		 } else GPIO_ResetBits(PORTS, Tx);
		 
		 delayMs(10);             // bit time
	}
	
	return countBit;

}

void bitParity(uint8_t countBit){
	
	if( countBit % 2 != 0) GPIO_SetBits(PORTS, Tx);
	
	else GPIO_ResetBits(PORTS, Tx);
	
	delayMs(10);      // bit time

}

void endCondition(){
	
	GPIO_SetBits(PORTS, Tx);
	delayMs(20);      // bit time
}

int main(){
	
	configurationGpioUart();
	configurationGpioLed();
	
	uint8_t *transmitdata = (uint8_t*)malloc(4*sizeof(uint8_t));
	
	transmitdata[0] = 0x2A;
	transmitdata[1] = 0x3B;
	transmitdata[2] = 0x4C;
	transmitdata[3] = 0x5D;
	
	uint8_t i = 0;
	uint8_t countBit = 0;
	
	GPIO_SetBits(PORTS, Tx);
	delayMs(1000);
	
	while(i < 4){
	
			startCondition();
			
		  countBit = transmitData(*transmitdata);
			
			bitParity(countBit);
			
			endCondition();
			
		  checkled();                  // transmit data: 1 byte then turn on Led PC13
			
		  transmitdata++;
		  i++;
	}
	
	free(transmitdata);
  return 0;
}