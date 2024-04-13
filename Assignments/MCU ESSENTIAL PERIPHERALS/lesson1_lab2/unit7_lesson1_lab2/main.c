/*
 * unit7_lesson1_lab2.c
 *
 * Created: 4/13/2024 9:59:50 PM
 * Author : fadye
 */ 
#define F_CPU 800000000UL
#include <util/delay.h>
//#include <avr/io.h>
#define PORTD   (*(volatile unsigned int*)(0x32))
#define DDRD   (*(volatile unsigned int*)(0x31))
#define PIND   (*(volatile unsigned int*)(0x30))


void GPIO_init(void){
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
		
	   
    }
}

