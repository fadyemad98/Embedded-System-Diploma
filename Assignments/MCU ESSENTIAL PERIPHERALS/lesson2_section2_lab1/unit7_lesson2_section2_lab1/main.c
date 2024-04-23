/*
 * unit7_lesson2_section2_lab1.c
 *
 * Created: 4/21/2024 10:57:14 AM
 * Author : fady emad
 */ 
#define F_CPU 1000000UL
#include "lcd.h"
#include "keypad.h"
#include <util/delay.h>
#include "memory_map.h"
#include "util.h"
int main(void)
{	
	LCD_init();
	KEYPAD_INIT();
	//LCD_WriteString("        Hello        ");
	//LCD_WriteString("   EMAD  KOFTAA");
	LCD_Wirte_Special_Char();
	char pressed_key;
	while (1)
	{
		pressed_key = KEYPAD_GetChar();
		switch (pressed_key){
			case ('!'):
			{
				LCD_Clear_Screen();
				break;
			}
			case ('N'):
				break;
			default:
				LCD_WriteChar(pressed_key);
				break;
		}
	}
}

