/*
 * unit8_lesson2_section.c
 *
 * Created: 6/8/2024 12:23:58 PM
 * Author : fadye
 */ 

#include <avr/io.h>
#include "UART.h"
#include "LCD.h"
int main(void)
{
	LCD_Init();
   char c;
   UART_init(9600);
   LCD_String("hello");
   _delay_ms(100);
   LCD_Clear();
   UART_SendString("\n\t Echo Test \n");
   while(1)
   {
	  c=UART_RxChar();
	  _delay_ms(5);
	 LCD_Char(c);
	  UART_TxChar(c);
   }
}

