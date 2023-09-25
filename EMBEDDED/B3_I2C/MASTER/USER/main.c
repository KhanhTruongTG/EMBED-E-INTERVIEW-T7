#include "stm32f10x.h" 
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stdlib.h"


#define SDA            GPIO_Pin_6
#define SCL            GPIO_Pin_7
#define PORTS          GPIOB

#define SLAVEADDRESS   0x7B
#define ACK            0
#define NACK           1
#define WRITE          0
#define READ           1

void configuration(void);
void checkDataOfLed(void);

void clockForPinSCL(void);
void setInputForPinSDA(void);
void setOutputForPinSDA(void);
void setOriginalStatus(void);
void startFrame(void);
void endFrame(void);
void transmitAddressFrame(uint8_t address);
void transmitDataFrame(uint8_t inputData);

void readDataFromSlave(void);
void writeDataForSlave(void);
void dataOfMaster(uint8_t dataTransmit);


int main(void){
	
	configuration();
	
	uint8_t i = 0;
	uint8_t* dataTransmit = (uint8_t *)malloc(2*sizeof(uint8_t));
	
	dataTransmit[0] = 0x40;
	dataTransmit[1] = 0x80;
	
	while(i < 2){
	
		dataOfMaster(*dataTransmit);
		
		checkDataOfLed();
			
		dataTransmit++;
		i++;
	}
	
	free(dataTransmit);
	return 0;
}

void configuration(){
	
	GPIO_InitTypeDef gpio;
	
	/*ENABLE CLOCK */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	/* PB6 SDA*/     /* PB7 SCL*/
	gpio.GPIO_Pin    = SDA | SCL;
	gpio.GPIO_Mode   = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed  = GPIO_Speed_2MHz;
	GPIO_Init(PORTS, &gpio);
	
	/* PC13 LED*/ 
	gpio.GPIO_Pin    = GPIO_Pin_13;
	gpio.GPIO_Mode   = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed  = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &gpio);
	
}

void clockForPinSCL(){

	GPIO_SetBits(PORTS,SCL);
	delayMs(100);
	GPIO_ResetBits(PORTS,SCL);
	delayMs(100);
}

void checkDataOfLed(){

	GPIO_SetBits(GPIOC,GPIO_Pin_13);
	delayMs(200);
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	delayMs(200);
	
}

void setOriginalStatus(){

	GPIO_SetBits(PORTS, SDA);
	GPIO_SetBits(PORTS, SCL);
	
}

void startFrame(){

	GPIO_ResetBits(PORTS, SDA);
	delayMs(60);
	GPIO_ResetBits(PORTS, SCL);
}

void endFrame(){
	
	GPIO_SetBits(PORTS, SCL);
	delayMs(60);
	GPIO_SetBits(PORTS, SDA);
}

void setInputForPinSDA(){
	
	// Reset Port B
	PORTS->CRL &= ~(GPIO_CRL_CNF6 | GPIO_CRL_MODE6 );
	// Set Input
	PORTS->CRL |= GPIO_CRL_MODE6_1;
	// Set pin SDA
	PORTS->BSRR |= SDA;
}

void setOutputForPinSDA(){
	
	// Reset Port B
	PORTS->CRL &= ~(GPIO_CRL_CNF6 | GPIO_CRL_MODE6 );
	// Set Output
	PORTS->CRL |= GPIO_CRL_MODE6_0;
	// Set pin SDA
	PORTS->BSRR |= SDA;

}

void transmitAddressFrame(uint8_t address){
	
	for(uint8_t i = 0 ; i < 7; i++){
		
	if( address & (1 << 0)) GPIO_SetBits(PORTS,SDA);
		
	else GPIO_ResetBits(PORTS, SDA);	
		
	 clockForPinSCL();
	}
}

void transmitDataFrame(uint8_t inputData){
	
	for(uint8_t i = 0; i < 8; i++){
	
	if(inputData & (1<<0)) GPIO_SetBits(PORTS, SDA);
		
	else GPIO_ResetBits(PORTS, SDA);
		
	clockForPinSCL();
	}

}

void writeDataForSlave(){

	// transmit write bit to Slave
	GPIO_ResetBits(PORTS, SDA);
	clockForPinSCL();
}

void readDataFromSlave(){

	// transmit read bit to Slave
	GPIO_SetBits(PORTS, SDA);
	clockForPinSCL();
}

void dataOfMaster(uint8_t dataTransmit){
	
	uint8_t i = 0;
	again:
	
	setOriginalStatus();
	delayMs(500);
	
	startFrame();
	
	// transmit address format: 7 bit
	transmitAddressFrame(SLAVEADDRESS);
	writeDataForSlave();
	
	
	// transmit data 2 byte and check bit ACK from SLAVE.
	
	for(uint8_t i = 0; i < 2; i++){
		
	setInputForPinSDA();
		
	if(GPIO_ReadInputDataBit(PORTS, SDA) == ACK){
	
		setOutputForPinSDA();
		clockForPinSCL();
		transmitDataFrame(dataTransmit);
	}
	else if (GPIO_ReadInputDataBit(PORTS, SDA) == NACK){
		
		setOutputForPinSDA();	
		goto again;
	}
	
	
}
	
	setInputForPinSDA();

	if (GPIO_ReadInputDataBit(PORTS, SDA) == NACK){
			
			setOutputForPinSDA();	
			goto again;
	}

		setOutputForPinSDA();
	  clockForPinSCL();
	  endFrame();
}