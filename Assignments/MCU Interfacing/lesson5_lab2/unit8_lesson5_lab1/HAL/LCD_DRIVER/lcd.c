/*
 * lcd.c
 *
 * Created: 4/21/2024 11:02:25 AM
 *  Author: fadye
 */ 
#include "lcd.h"
GPIO_PINConfig_t LCDPinCfg;
void wait(int x){
	unsigned int i,j;
	for (i=0; i<x;i++){
		for(j=0;j<255;j++);
	}
}



void LCD_init(void){
	/* LCD Power ON delay always >15ms */
	wait(20);
//	LCD_IsBusy();
	//set  EN_SWITCH o/p
	LCDPinCfg.GPIO_PinNumber = EN_SWITCH;
	LCDPinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	LCDPinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOB, &LCDPinCfg);
#ifdef RW_SWITCH
	//set  RW_SWITCH o/p
	LCDPinCfg.GPIO_PinNumber = RW_SWITCH;
	LCDPinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	LCDPinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOB, &LCDPinCfg);
#endif
	//set  RS_SWITCH o/p
	LCDPinCfg.GPIO_PinNumber = RS_SWITCH;
	LCDPinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	LCDPinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOB, &LCDPinCfg);
#ifdef EIGHT_BIT_MODE
	LCDPinCfg.GPIO_PinNumber = GPIO_PIN_0;
	LCDPinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	LCDPinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &LCDPinCfg);

	LCDPinCfg.GPIO_PinNumber = GPIO_PIN_1;
	LCDPinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	LCDPinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &LCDPinCfg);

	LCDPinCfg.GPIO_PinNumber = GPIO_PIN_2;
	LCDPinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	LCDPinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &LCDPinCfg);

	LCDPinCfg.GPIO_PinNumber = GPIO_PIN_3;
	LCDPinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	LCDPinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &LCDPinCfg);
#endif

	LCDPinCfg.GPIO_PinNumber = GPIO_PIN_4;
	LCDPinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	LCDPinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &LCDPinCfg);


	LCDPinCfg.GPIO_PinNumber = GPIO_PIN_5;
	LCDPinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	LCDPinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &LCDPinCfg);

	LCDPinCfg.GPIO_PinNumber = GPIO_PIN_6;
	LCDPinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	LCDPinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &LCDPinCfg);

	LCDPinCfg.GPIO_PinNumber = GPIO_PIN_7;
	LCDPinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	LCDPinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(GPIOA, &LCDPinCfg);


	MCAL_GPIO_WritePin(lcd_ctrl, EN_SWITCH, GPIO_PIN_RESET);	/* LCD_EN = 0 */
#ifdef RW_SWITCH
	MCAL_GPIO_WritePin(lcd_ctrl, RW_SWITCH, GPIO_PIN_RESET);	/* LCD_RW = 0 */
#endif
	MCAL_GPIO_WritePin(lcd_ctrl, RS_SWITCH, GPIO_PIN_RESET);	/* LCD_RS = 0 */

	wait(15);
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

/* RS = 0 for command */
	MCAL_GPIO_WritePin(lcd_ctrl, RS_SWITCH, GPIO_PIN_RESET);
	wait(1);

#ifdef RW_SWITCH
/* RW = 0 for WRITE */
	MCAL_GPIO_WritePin(lcd_ctrl, RW_SWITCH, GPIO_PIN_RESET);
#endif

#ifdef EIGHT_BIT_MODE
//write command on port
	MCAL_GPIO_WritePort(lcd_port,command);
	//Enable and disable pulse
		LCD_kick();
#endif


#ifdef FOUR_BIT_MODE
	uint16_t portVal;
	char CMD;
	portVal = MCAL_GPIO_ReadPort(lcd_port);
	CMD =	(portVal & 0x0F) | (command & 0xF0);
//write command on port
	MCAL_GPIO_WritePort(lcd_port, CMD);
	//Enable and disable pulse
	LCD_kick();
	CMD =	(portVal & 0x0F) | (command << 4);
	MCAL_GPIO_WritePort(lcd_port, CMD);
	LCD_kick();
#endif

}


void LCD_Clear_Screen(void){
	LCD_Command(LCD_CLEAR_SCREEN);
}

void LCD_kick(void){
//	ClearBit(lcd_ctrl,EN_SWITCH);
	MCAL_GPIO_WritePin(lcd_ctrl, EN_SWITCH, GPIO_PIN_SET);
	wait(50);
//	SetBit(lcd_ctrl,EN_SWITCH);
	MCAL_GPIO_WritePin(lcd_ctrl, EN_SWITCH, GPIO_PIN_RESET);
}



void LCD_WriteChar(char data){
/* RS = 1 for data */
	MCAL_GPIO_WritePin(lcd_ctrl, RS_SWITCH, GPIO_PIN_SET);
#ifdef RW_SWITCH
//setting write mode
	MCAL_GPIO_WritePin(lcd_ctrl, RW_SWITCH, GPIO_PIN_RESET);
#endif
	wait(1);

#ifdef EIGHT_BIT_MODE
//write command on port
	MCAL_GPIO_WritePort(lcd_port,data);
	//Enable and disable pulse
		LCD_kick();
#endif


#ifdef FOUR_BIT_MODE
	uint16_t portVal;
	char DATA;
	portVal = MCAL_GPIO_ReadPort(lcd_port);
	DATA =	(portVal & 0x0F) | (data & 0xF0);
//write command on port
	MCAL_GPIO_WritePort(lcd_port, DATA);
	//Enable and disable pulse
	LCD_kick();
	DATA =	(portVal & 0x0F) | (data << 4);
	MCAL_GPIO_WritePort(lcd_port, DATA);
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


