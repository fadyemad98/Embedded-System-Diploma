/*
 * lcd_driver.c
 *
 * Created: 6/7/2024 6:53:13 PM
 * Author : fady emad 
 */ 

#define F_CPU 1000000UL 
#include <avr/io.h>
#include "LCD.h"

int main(void)
{
    LCD_Init();
	LCD_Clear();
	LCD_String("fady emad");
	_delay_ms(20);
	LCD_String_xy(1,0,"welcome test !!!!");
	_delay_ms(20);
	LCD_Roll_Display();
	LCD_Clear();
    while (1) 
    {
		
    }
}

