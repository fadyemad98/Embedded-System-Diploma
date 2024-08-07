/*
 ============================================================================
 Name        : main.c
 Author      : Fady Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C
 ============================================================================
 */

#include <stdio.h>
#include "RCC_Interface.h"
#include "RCC_Config.h"
#include "LED_INTERFACE.h"
#include "PB.h"

#define NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND  		762
void Delay_MS(unsigned long long n);

void init(void){
	//Controller works at 16MHZ
	RCC_Init(MOSC_CLOCK_SOURCE);
	//Use SW2 (PF0) with pull-up configuration, Activate the internal Pull-Up Resistor
	PB_init(PORTF_ID,PIN0);
	//Use Red Led at PF1 with Positive Logic Configuration
	LED_init(PORTF_ID,PIN1);





}


int main(void)
{
	init();





	while(1){
		//Flash the led every half second when the switch is pressed
		while(read_PB ==0){
			LED_On(PORTF_ID,PIN1);
			Systick_Init(&Systick_Config, polling_on);
			LED_Off(PORTF_ID,PIN1);
			Systick_Init(&Systick_Config, polling_on);
		}
	}

	return 0;
}

void Delay_MS(unsigned long long n)
{
	   volatile unsigned long long count = 0;
	   while(count++ < (NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND * n) );
}
