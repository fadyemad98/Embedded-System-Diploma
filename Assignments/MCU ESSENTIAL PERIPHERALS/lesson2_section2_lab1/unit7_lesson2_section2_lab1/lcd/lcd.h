/*
 * lcd.h
 *
 * Created: 4/21/2024 11:02:10 AM
 *  Author: fadye
 */ 


#ifndef LCD_H_
#define LCD_H_
#include <avr/delay.h>
#include "memory_map.h"
#include "util.h"
//data
#define lcd_port PORTA
#define Data_Dir_lcd_port DDRA
//ctrl
#define lcd_ctrl PORTB
#define Data_Dir_lcd_ctrl DDRB

#define RS_SWITCH 1
#define RW_SWITCH 2
#define EN_SWITCH 3

#define Read_RW SetBit(lcd_ctrl,RW_SWITCH)
#define Write_RW ClearBit(lcd_ctrl,RW_SWITCH)
#define Cmd_RS ClearBit(lcd_ctrl,RS_SWITCH)
#define Data_RS SetBit(lcd_ctrl,RS_SWITCH)
#define Enable_EN SetBit(lcd_ctrl,EN_SWITCH)
#define Disable_EN ClearBit(lcd_ctrl,EN_SWITCH)

//#define DATA_shift 4 // in 8 bit mode 0 and in 4 bit mode 4
	
#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)


//----------------------------------------------- API's -----------------------------------------------//
void LCD_init(void);
void LCD_kick(void);
void LCD_IsBusy(void);
void LCD_Command(unsigned char command);
void LCD_WriteChar(unsigned	char data);
void LCD_WriteString(unsigned char* String);
void LCD_Clear_Screen(void);

enum E_LCD
{
	Not_busy,
	Busy
}LCD_status;
#endif /* LCD_H_ */