/*
 * unit6_lesson 4_lab2.c
 *
 * Created: 4/19/2024 7:19:29 PM
 * Author : fadye
 */ 

#define F_CPU 1000000UL 
#include <util/delay.h>
#include "memory_map.h"
#include "util.h"
#include <avr/interrupt.h>
void GPIO_init(void){
// setting three pins as input
	ClearBit(DDRD,2);
	ClearBit(DDRD,3);
	ClearBit(DDRB,2);
	
//setting pins as output direction for the leds
	SetBit(DDRD,5);
	SetBit(DDRD,6);
	SetBit(DDRD,7);
}
void INT_init(void){
//enable I-Bit in Status Register
	SetBit(SREG,7);
	
//enable general interrupt control for each INT 	
	SetBit(GICR,5);
	SetBit(GICR,6);
	SetBit(GICR,7);
	
// MCUCR CONFIG	:
	//setting INT0 to logical sense
	ClearBit(MCUCR,ISC01);
	SetBit(MCUCR,ISC00);
	//setting INT1 to rising sense 
	SetBit(MCUCR,ISC10);
	SetBit(MCUCR,ISC11);
	//setting INT2 to falling sense
	ClearBit(MCUCSR,ISC2);
	
	
}
int main(void)
{	
	GPIO_init();
	INT_init();
    while (1) 
    {
		ClearBit(PORTD,5);
		ClearBit(PORTD,6);
		ClearBit(PORTD,7);
		_delay_ms(5000);
		
    }
}

ISR(INT0_vect){
	SetBit(PORTD,5);
		
}

ISR(INT1_vect){
	SetBit(PORTD,6);
	
}
ISR(INT2_vect){
	SetBit(PORTD,7);
}