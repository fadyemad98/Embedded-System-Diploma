/*
 * lcd.c
 *
 * Created: 4/21/2024 11:02:25 AM
 *  Author: fadye
 */ 
#include "lcd/lcd.h"


void LCD_init(void){
//check if 8-bit or 4-bit  mode
#ifdef EIGHT_BIT_MODE
/* Make LCD command port direction as o/p */
	Data_Dir_lcd_ctrl = 0xFF;
/* Make LCD data port direction as o/p */	
	Data_Dir_lcd_port = 0xFF;	
/* LCD Power ON delay always >15ms */
	_delay_ms(20);		
	LCD_IsBusy();
		
//set ctrl pins as output to give order to lcd
	SetBit(Data_Dir_lcd_ctrl,RS_SWITCH);
	SetBit(Data_Dir_lcd_ctrl,RW_SWITCH);
	SetBit(Data_Dir_lcd_ctrl,EN_SWITCH);
//set ctrl as pins as disable, write mode, data mode
	ClearBit(lcd_ctrl,RW_SWITCH);
	ClearBit(lcd_ctrl,RS_SWITCH);
	ClearBit(lcd_ctrl,EN_SWITCH);
//clear screen
	LCD_Clear_Screen();
#endif

//#ifdef FOUR_BIT_MODE

//#endif


}



void LCD_Command(unsigned char command){
#ifdef EIGHT_BIT_MODE
	//command passed to the function
	lcd_ctrl =command;
	//setting command mode
	Cmd_RS;
	//setting write mode
	Write_RW;
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
	SetBit(PORTB,EN_SWITCH);
}

void LCD_IsBusy(void){
	
//set data port as i/p
	Data_Dir_lcd_port = 0x00;
//LCD read mode 1
	SetBit(lcd_ctrl,RW_SWITCH);
//LCD command mode 0
	ClearBit(lcd_ctrl,RS_SWITCH);
	LCD_kick();
	
}


void LCD_WriteChar(unsigned	char data){
#ifdef EIGHT_BIT_MODE
//command passed to the function
	lcd_port =data;
//setting command mode
	Data_RS;
//setting write mode
	Write_RW;
//Enable and disable pulse
	LCD_kick();
#endif	
}

//void LCD_WriteString(unsigned char* String){}
