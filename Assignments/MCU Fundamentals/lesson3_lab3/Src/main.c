/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Eng. Fady emad
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

//Learn-in-depth
//Keroles Shenouda
//Mastering_Embedded System online diploma
typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
// register address
#define GPIOA_BASE    0x40010800
#define GPIOA_CRH     *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR     *(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define RCC_BASE      0x40021000
#define RCC_APB2ENR   *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR   *(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_CR   *(volatile uint32_t *)(RCC_BASE + 0x00)

void clock_init(){

	//SET PLLMUL to *8 as HSI is /2
	RCC_CFGR |= (0b0110<<18);
	//Set SW to PLLCLK
	RCC_CFGR |= (0b10<<0);
	//Set SWS to PLL as sysclk
	RCC_CFGR |= (0b10<<2);
	//set PLL ON
	RCC_CR |= (1<<24);
	//set Prescaler of APB2 to 4
	RCC_CFGR |= (0b101<<11);
	//set Prescaler of APB1 to 2
	RCC_CFGR |= (0b100<<8);
	//enable RCC for GPIOA on APB2 bus
	RCC_APB2ENR |=(1<<2);
	//Init GPIOA
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;

}
int main(void)
{
	clock_init();

	while(1)
	{
		GPIOA_ODR |=  1<<13 ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR  &=  ~(1<<13) ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
	}
}
