/*
 * LCD.c
 *
 * Created: 6/2/2024 1:00:29 PM
 *  Author: fadye
 */ 

#include "LCD.h"
void LCD_Command(unsigned char cmnd)
{
	LCD_Data_Port= cmnd;
	LCD_Command_Port &= ~(1<<RS);		/* RS=0 command reg. */
	LCD_Command_Port &= ~(1<<RW);		/* RW=0 Write operation */
	LCD_Command_Port |= (1<<EN);		/* Enable pulse */
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(3);
}

void LCD_Char (unsigned char char_data)	/* LCD data write function */
{
	LCD_Data_Port= char_data;
	LCD_Command_Port |= (1<<RS);		/* RS=1 Data reg. */
	LCD_Command_Port &= ~(1<<RW);		/* RW=0 write operation */
	LCD_Command_Port |= (1<<EN);		/* Enable Pulse */
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(10);
}

void LCD_Init (void)					/* LCD Initialize function */
{
	LCD_Command_Dir = 0xFF;				/* Make LCD command port direction as o/p */
	LCD_Data_Dir = 0xFF;				/* Make LCD data port direction as o/p */
	_delay_ms(20);						/* LCD Power ON delay always >15ms */
	
	LCD_Command (eight_bit_mode);					/* Initialization of 16X2 LCD in 8bit mode */
	LCD_Command (Display_ON_Cursor_OFF);					/* Display ON Cursor OFF */
	LCD_Command (Auto_Increment_cursor);					/* Auto Increment cursor */
	LCD_Command (clear_display);					/* clear display */
	LCD_Command (cursor_at_home_position);					/* cursor at home position */
}

void LCD_String (char *str)				/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)				/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);
		_delay_ms(10);
	}
}

void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|cursor_at_home_position);		/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);		/* Command of first row and required position<16 */
	LCD_String(str);					/* Call LCD string function */
}

void LCD_Clear()
{
	LCD_Command (clear_display);					/* clear display */
	LCD_Command (cursor_at_home_position);					/* cursor at home position */
}