/*
 * unit9_lesson1_section_lab1.c
 *
 * Created: 7/2/2024 11:21:01 AM
 * Author : fady emad
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include "util/delay.h"
#include "WDT.h"
#define LED_PORT		PORTC
#define LED_DDR			DDRC
#define LED_PIN			1


int main(void)
{	// set led pin as o/p
	LED_DDR	|= (1<<LED_PIN);
	//turn on led 
	LED_PORT |= (1<<LED_PIN);
	_delay_ms(500);
	
    while (1) 
    {
		//enable wdt
		WDT_ON();
		LED_PORT ^= (1<<LED_PIN);
		_delay_ms(100);
		WDT_OFF();
    }
}

