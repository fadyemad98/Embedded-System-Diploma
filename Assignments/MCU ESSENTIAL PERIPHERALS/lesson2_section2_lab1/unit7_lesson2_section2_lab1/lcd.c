/*
 * lcd.c
 *
 * Created: 4/21/2024 11:02:25 AM
 *  Author: fadye
 */ 
#include "lcd.h"


void LCD_init(void){
/* LCD Power ON delay always >15ms */
	_delay_ms(20);
	LCD_IsBusy();
	Data_Dir_lcd_ctrl |= ((1<<EN_SWITCH) | (1<<RW_SWITCH) | (1<<RS_SWITCH));
	lcd_ctrl &= ~((1<<EN_SWITCH) | (1<<RW_SWITCH) |(1<<RS_SWITCH));
	Data_Dir_lcd_port |= (0xFF<<DATA_shift);
	LCD_Clear_Screen();
//check if 8-bit or 4-bit  mode
#ifdef EIGHT_BIT_MODE
	LCD_Command(LCD_FUNCTION_8BIT_2LINES);
#endif

#ifdef FOUR_BIT_MODE
	LCD_Command(0x02);
	LCD_Command(LCD_FUNCTION_4BIT_2LINES);
#endif
		LCD_Command(LCD_ENTRY_MODE);
		LCD_Command(LCD_BEGIN_AT_FIRST_ROW);
		LCD_Command(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_GOTO_XY(int line , int position){
// check if 1st line
	if (line == 1)
	{	if (position < 16 && position >= 0 ){	
		LCD_Command(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
// check if 2nd line
	if (line == 2)
	{	if (position < 32 && position >= 0 ){
		LCD_Command(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}

void LCD_Command(unsigned char command){
	ClearBit(lcd_ctrl,RW_SWITCH);
	ClearBit(lcd_ctrl,RS_SWITCH);
	LCD_IsBusy();
#ifdef EIGHT_BIT_MODE
	//command passed to the function
	lcd_port = command;
	//Enable and disable pulse
	LCD_kick();
#endif
#ifdef FOUR_BIT_MODE
	//command passed to the function
	lcd_port = (lcd_port & 0x0F)|(command & 0xF0);
	//Enable and disable pulse
	LCD_kick();
	//command passed to the function
	lcd_port = (lcd_port & 0x0F)|(command << DATA_shift);
	//Enable and disable pulse
	LCD_kick();
	#endif
	
}


void LCD_Clear_Screen(void){
	LCD_Command(LCD_CLEAR_SCREEN);
}

void LCD_kick(void){
	ClearBit(lcd_ctrl,EN_SWITCH);
	_delay_ms(30);
	SetBit(lcd_ctrl,EN_SWITCH);
}

void LCD_IsBusy(void){
	
//set LCD port as i/p
	Data_Dir_lcd_port &= ~(0xFF<<DATA_shift) ;
//LCD read mode 1
	SetBit(lcd_ctrl,RW_SWITCH);
//LCD command mode 0
	ClearBit(lcd_ctrl,RS_SWITCH);
//LCD kick
	LCD_kick();
//return LCD port as o/p 
	Data_Dir_lcd_port |= (0xFF<<DATA_shift);
	ClearBit(lcd_ctrl,RW_SWITCH);
}


void LCD_WriteChar(char data){
		LCD_IsBusy();
//setting data mode
		SetBit(lcd_ctrl,RS_SWITCH);
//setting write mode
		ClearBit(lcd_ctrl,RW_SWITCH);
#ifdef EIGHT_BIT_MODE
//command passed to the function
	lcd_port =data;
//Enable and disable pulse
	LCD_kick();
#endif	
#ifdef FOUR_BIT_MODE
//command passed to the function
	lcd_port = (lcd_port & 0x0F)|(data & 0xF0);
//Enable and disable pulse
	LCD_kick();
//command passed to the function
	lcd_port = (lcd_port & 0x0F)|(data << DATA_shift);
//Enable and disable pulse
	LCD_kick();

#endif
}


void LCD_WriteString( char* data){
	int counter = 0;
	while (*data > 0)
	{
		counter++;
		LCD_WriteChar(*data++);
		if (counter == 16)
		{	
			LCD_GOTO_XY(2 , 0);
		}
		else if (counter == 32)
		{	
// lcd is full must be cleared
			LCD_Clear_Screen();
//begin at first row
			LCD_GOTO_XY(1,0);
//reset counter
			counter = 0;
		}
	}
 }

void LCD_Wirte_Special_Char(void){
	LCD_Command(64);
	LCD_WriteChar(0);
	LCD_WriteChar(14);
	LCD_WriteChar(17);
	LCD_WriteChar(2);
	LCD_WriteChar(4);
	LCD_WriteChar(4);
	LCD_WriteChar(0);
	LCD_WriteChar(4);
	LCD_Command(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WriteChar(0);
	_delay_ms(10);
	
	
}