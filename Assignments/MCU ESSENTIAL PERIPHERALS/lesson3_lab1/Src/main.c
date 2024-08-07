/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include "STM32F103x6.h"
#include "STM32_F103C6_GPIO_Driver.h"
typedef volatile unsigned int vuint32_t;

void clock_init(){

	// enable clock for gpio port a & b
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}


void GPIO_init(){
	GPIO_PINConfig_t PinCnfg;
	//PA1 input Hi-z  FLOATING INPUT
	PinCnfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCnfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinCnfg);

	//PB1 output push pull mode
	PinCnfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCnfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCnfg.GPIO_Output_Speed= GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCnfg);

	//PA13 input Hi-z FLOATING INPUT
	PinCnfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCnfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinCnfg);

	//PB13 output push pull mode
	PinCnfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCnfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCnfg.GPIO_Output_Speed= GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCnfg);
}

void my_wait(int x){
	unsigned int i,j;
	for (i=0; i<x;i++){
		for(j=0;j<255;j++);
	}
}

int main(void) {
	clock_init();
	GPIO_init();

	while(1){
		//PORTA1 connected >>PUR externally
		if( MCAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==0 )  //press ==0
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)==0 );  //single press (won't exit loop as long as buttom pressed)

		}
		//PORTA13 connected <<PDR>> externally
		if( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13)==1 )  //press ==1
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);// multi press

		}
		my_wait(1);

	}
}
