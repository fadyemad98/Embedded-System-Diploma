/*
 * lcd.c
 *
 * Created: 4/21/2024 11:02:25 AM
 *  Author: fadye
 */ 
#include "lcd.h"
GPIO_PINConfig_t PinCfg;
void my_wait(int x){
	unsigned int i,j;
	for (i=0; i<x;i++){
		for(j=0;j<255;j++);
	}
}

void LCD_init(void){
	/* LCD Power ON delay always >15ms */
	my_wait(20);
//	LCD_IsBusy();
	//set  EN_SWITCH o/p
	PinCfg.GPIO_PinNumber = EN_SWITCH;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	//set  RW_SWITCH o/p
	PinCfg.GPIO_PinNumber = RW_SWITCH;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	//set  RS_SWITCH o/p
	PinCfg.GPIO_PinNumber = RS_SWITCH;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &PinCfg);


	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &PinCfg);


	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	//	Data_Dir_lcd_port |= (0xFF<<DATA_shift);
	MCAL_GPIO_WritePin(lcd_ctrl, EN_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(lcd_ctrl, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(lcd_ctrl, RS_SWITCH, GPIO_PIN_RESET);
	my_wait(15);
	LCD_Clear_Screen();
	//check if 8-bit or 4-bit  mode
#ifdef EIGHT_BIT_MODE
	LCD_Command(LCD_FUNCTION_8BIT_2LINES);
#endif
/*
#ifdef FOUR_BIT_MODE
	LCD_Command(0x02);
	LCD_Command(LCD_FUNCTION_4BIT_2LINES);
#endif*/
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
	MCAL_GPIO_WritePort(lcd_port, command);
//	ClearBit(lcd_ctrl,RW_SWITCH);
	MCAL_GPIO_WritePin(lcd_ctrl, RW_SWITCH, GPIO_PIN_RESET);
//	ClearBit(lcd_ctrl,RS_SWITCH);
	MCAL_GPIO_WritePin(lcd_ctrl, RS_SWITCH, GPIO_PIN_RESET);
	my_wait(1);
#ifdef EIGHT_BIT_MODE
	//Enable and disable pulse
	LCD_kick();
#endif
/*
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
*/

}


void LCD_Clear_Screen(void){
	LCD_Command(LCD_CLEAR_SCREEN);
}

void LCD_kick(void){
//	ClearBit(lcd_ctrl,EN_SWITCH);
	MCAL_GPIO_WritePin(lcd_ctrl, EN_SWITCH, GPIO_PIN_SET);
	my_wait(50);
//	SetBit(lcd_ctrl,EN_SWITCH);
	MCAL_GPIO_WritePin(lcd_ctrl, EN_SWITCH, GPIO_PIN_RESET);
}

void LCD_IsBusy(void){

	//set LCD port as i/p
//	Data_Dir_lcd_port &= ~(0xFF<<DATA_shift) ;
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(lcd_port, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(lcd_port, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(lcd_port, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(lcd_port, &PinCfg);


	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(lcd_port, &PinCfg);


	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(lcd_port, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(lcd_port, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(lcd_port, &PinCfg);

	//LCD read mode 1
//	SetBit(lcd_ctrl,RW_SWITCH);
	MCAL_GPIO_WritePin(lcd_ctrl, RW_SWITCH, GPIO_PIN_SET);
	//LCD command mode 0
//	ClearBit(lcd_ctrl,RS_SWITCH);
	MCAL_GPIO_WritePin(lcd_ctrl, RS_SWITCH, GPIO_PIN_RESET);
	//LCD kick
	LCD_kick();
	MCAL_GPIO_WritePin(lcd_ctrl, RW_SWITCH, GPIO_PIN_RESET);

}


void LCD_WriteChar(char data){
	MCAL_GPIO_WritePort(lcd_port, data);
	//setting data mode
//	SetBit(lcd_ctrl,RS_SWITCH);
	MCAL_GPIO_WritePin(lcd_ctrl, RS_SWITCH, GPIO_PIN_SET);
	//setting write mode
//	ClearBit(lcd_ctrl,RW_SWITCH);
	MCAL_GPIO_WritePin(lcd_ctrl, RW_SWITCH, GPIO_PIN_RESET);
	my_wait(1);
#ifdef EIGHT_BIT_MODE
	//command passed to the function
//	lcd_port =data;

	//Enable and disable pulse

#endif	
/*#ifdef FOUR_BIT_MODE
	//command passed to the function
	lcd_port = (lcd_port & 0x0F)|(data & 0xF0);
	//Enable and disable pulse
	LCD_kick();
	//command passed to the function
	lcd_port = (lcd_port & 0x0F)|(data << DATA_shift);
#endif*/
	LCD_kick();
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
	my_wait(10);


}
