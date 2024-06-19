/*
 * unit8_lesson5_section.c
 *
 * Created: 6/18/2024 6:32:15 PM
 * Author : Fady Emad
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "SPI.h"
#include "LCD.h"
#include "util/delay.h"
#include "avr/interrupt.h"
#include "string.h"

#define Master_mode




u8 ch=0;
u8 buffer[1];
int main(void)
{
	LCD_Init();
	SPI_Init(Master);	
	LCD_String("Master Device");
	LCD_String_xy(1,0,"Sending Data:");
	_delay_ms(300);
	
    while (1) 
    {
		SPI_MasterTransmit(ch);
		sprintf(buffer, "%d", ch);
		LCD_String_xy(1,13,buffer);
		ch++;
		_delay_ms(100);
	
    }
}

