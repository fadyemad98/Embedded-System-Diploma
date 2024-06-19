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


#define Slave_mode


u8 Dummy=0xFF;
u8 SlaveReceive;
u8 buffer[1];
int main(void)
{
	LCD_Init();
	SPI_Init(Slave);
	LCD_String("Slave Device");
	LCD_String_xy(1,0,"Receive Data:");
    while (1) {
		SlaveReceive = SPI_SlaveReceive(Dummy);
		sprintf(buffer, "%d", SlaveReceive);
		LCD_String_xy(1,13,buffer);
    }
}

