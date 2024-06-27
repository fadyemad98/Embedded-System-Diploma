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
#include "STM32_F103C6_EXTI_Driver.h"
#include "STM32_F103C6_RCC_Driver.h"
#include "STM32_F103C6_USART_Driver.h"
#include "STM32_F103C6_I2C_Driver.h"
#include "I2C_Slave_EEPROM.h"
#include "lcd.h"
#include "keypad.h"
#include "seven_seg.h"


void clock_init(){

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}




int main()
{
	clock_init();
	eeprom_init();



	//test case :1
	uint8_t ch1[]={0x1,0x2,0x3,0x4,0x5,0x6,0x7};
	uint8_t ch2[7]={0};
	eeprom_write_Nbytes(0xAF, ch1, 7);
	eeprom_read_byte(0xAF, ch2, 7);

	//test case :2
	ch1[0]=0xA;
	ch1[1]=0xB;
	ch1[2]=0xC;
	ch1[3]=0xD;

	eeprom_write_Nbytes(0xFFF, ch1, 4);
	eeprom_read_byte(0xFFF, ch2, 4);

	while(1){

	}
}
