/*
 * LCD.h
 *
 * Created: 6/2/2024 1:01:10 PM
 *  Author: fadye
 */ 


#ifndef LCD_H_
#define LCD_H_

//includes
#define F_CPU 1000000UL
#include <avr/io.h>						/* Include AVR std. library file */
#include <util/delay.h>					/* Include inbuilt defined Delay header file */

//MODE SELECTION
//#define EIGHT_MODE
#define FOUR_MODE

//macros
#define LCD_Data_Dir			 DDRA				/* Define LCD data port direction */
#define LCD_Command_Dir			 DDRB				/* Define LCD command port direction register */
#define LCD_Data_Port			 PORTA				/* Define LCD data port */
#define LCD_Command_Port		 PORTB				/* Define LCD data port */
#define RS PB0										/* Define Register Select (data reg./command reg.) signal pin */
#define RW PB1										/* Define Read/Write signal pin */
#define EN PB2										/* Define Enable signal pin */



#define eight_bit_mode								0x38
#define four_bit_mode								0x02		//0x28
#define four_bit_font								0x28		//5*7 matrix in 4-bit mode Font
#define Display_ON_Cursor_OFF						0x0C
#define Auto_Increment_cursor						0x06
#define clear_display								0x01
#define cursor_at_home_position						0x80
#define	Go_to_2nd_line								0xc0



//API's
void LCD_Command(unsigned char cmnd);
void LCD_Char (unsigned char char_data);					/* LCD data write function */
void LCD_Init (void);										/* LCD Initialize function */
void LCD_String (char *str)	;								/* Send string to LCD function */
void LCD_String_xy (char row, char pos, char *str);			/* Send string to LCD with xy position */
void LCD_Clear();
void LCD_Roll_Display(void);

#endif /* LCD_H_ */