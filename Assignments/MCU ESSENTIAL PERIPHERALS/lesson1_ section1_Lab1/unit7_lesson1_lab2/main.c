/*
 * unit7_lesson1_lab2.c
 *
 * Created: 4/13/2024 9:59:50 PM
 * Author : fadye
 */ 
#define F_CPU 800000000UL
#include "memory_map.h"
#include <util/delay.h>
#include <avr/io.h>

void GPIO_init(void){
//set PORT A AS OUTPUT
	DDRA |= 0xFF ;
//set port D PIN 4,5,6,7 AS OUTPUT
	DDRD |= 0xFF;
}

void delay(void){
	int i;
	for (i=0;i<10000;i++);
}

int main(void)
{
    GPIO_init();
    while (1) 
    { 
		PORTA |= (1<<0); 
		_delay_ms(10);
		PORTA |= (1<<1);
		_delay_ms(10);
		PORTA |= (1<<2);
		_delay_ms(10);
		PORTA |= (1<<3);
		_delay_ms(10);
		PORTA |= (1<<4);
		_delay_ms(10);
		PORTA |= (1<<5);
		_delay_ms(10);
		PORTA |= (1<<6);
		_delay_ms(10);
		PORTA |= (1<<7);
		_delay_ms(10);
		PORTA &= ~(1<<7);
		_delay_ms(10);
		PORTA &= ~(1<<6);
		_delay_ms(10);
		PORTA &= ~(1<<5);
		_delay_ms(10);
		PORTA &= ~(1<<4);
		_delay_ms(10);
		PORTA &= ~(1<<3);
		_delay_ms(10);
		PORTA &= ~(1<<2);
		_delay_ms(10);
		PORTA &= ~(1<<1);
		_delay_ms(10);
		PORTA &= ~(1<<0);
		_delay_ms(10);
/*				
//	set port D pin 4,5,6,7 as source
	    PORTD ^=(1<<5);
		_delay_ms(10);
		PORTD ^=(1<<5);
		_delay_ms(10);
		PORTD ^=(1<<6);
		_delay_ms(10);
		PORTD ^=(1<<6);
		_delay_ms(10);
		PORTD ^=(1<<7);
		_delay_ms(10);
		PORTD ^=(1<<7);
		_delay_ms(100);
		PORTD |=(1<<4);
		_delay_ms(10);
		PORTD &= ~(1<<4);
		_delay_ms(10);
*/		
	   
    }
}

