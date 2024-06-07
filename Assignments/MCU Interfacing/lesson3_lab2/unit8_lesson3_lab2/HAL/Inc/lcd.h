/*
 * lcd.h
 *
 * Created: 4/21/2024 11:02:10 AM
 *  Author: fadye
 */ 


#ifndef LCD_H_
#define LCD_H_

//----------------------------------------------INCLUDES-------------------------------//
#include"STM32F103x6.h"
#include"STM32_F103C6_GPIO_Driver.h"

//---------------------------------------------CONFIGS---------------------------------//
#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

#ifdef EIGHT_BIT_MODE
#define DATA_shift 0
#endif

/*#ifdef FOUR_BIT_MODE
#define DATA_shift 4
#endif*/

//-------------------------------------------MACROS------------------------------------//
//data
#define lcd_port GPIOA
//#define Data_Dir_lcd_port DDRA
//ctrl
#define lcd_ctrl GPIOA
//#define Data_Dir_lcd_ctrl DDRB

#define RS_SWITCH GPIO_PIN_11
#define RW_SWITCH GPIO_PIN_12
#define EN_SWITCH GPIO_PIN_15


	
//----------------------------------------COMMAND MACROS-----------------------------------------------//
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
void LCD_WriteChar(char data);
void LCD_WriteString( char* String);
void LCD_Clear_Screen(void);
void LCD_GOTO_XY(int line , int position);
void LCD_Wirte_Special_Char(void);




#endif /* LCD_H_ */
