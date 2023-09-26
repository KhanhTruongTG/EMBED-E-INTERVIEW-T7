#ifndef _DELAY_H
#define _DELAY_H

#include "stm32f10x.h"

void TIM2_Init(void);

void configurationLed(void);

void delayMs(uint32_t time);

#endif