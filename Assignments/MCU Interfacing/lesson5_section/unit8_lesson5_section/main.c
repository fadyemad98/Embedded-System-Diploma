/*
 * unit8_lesson5_section.c
 *
 * Created: 6/18/2024 6:32:15 PM
 * Author : Fady Emad
 */ 


#define F_CPU 1000000UL
#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "SPI.h"
#include "LCD.h"
#include "util/delay.h"
#include "avr/interrupt.h"

#define Master_mode




u8 ch='A';
u8 Dummy;
u8 MasterReceive;

int main(void)
{
	LCD_Init();
	SPI_Init(Master);	
	LCD_String("Master MCU!!!");
	LCD_xy(1,1);
    while (1) 
    {
		MasterReceive = SPI_MasterTransmit(ch);
		ch++;
		_delay_ms(500);
	
    }
}

