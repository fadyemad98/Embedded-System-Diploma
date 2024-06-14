/*
 * unit8_lesson4_section_lab1.c
 *
 * Created: 6/13/2024 11:40:09 AM
 * Author : fadye
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>	
#include "BIT_MATH.h"		
#include "STD_TYPES.h"			
#include "util/delay.h"			
#include "avr/interrupt.h"	
#include "SPI.h"


int main(void)
{	SPI_Masterinit();
	DDRD = 0xFF;
	u8 data = 1;
    while (data < 99) 
    {
		PORTD = SPI_MasterTransmit(data);
		_delay_ms(1000);
		data++;
    }
}

