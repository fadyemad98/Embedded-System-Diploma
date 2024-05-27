/*
 * keypad.c
 *
 * Created: 4/22/2024 9:09:54 PM
 *  Author: Fady Emad
 */ 
#include"STM32F103x6.h"
#include"STM32_F103C6_GPIO_Driver.h"
#include "keypad.h"
GPIO_PINConfig_t PinCnfg;
int KEYPAD_ROW[] = {R0,R1,R2,R3};
int KEYPAD_COLOUMN[] = {C0,C1,C2,C3}; 



void KEYPAD_INIT(void){

	//set first 4 pins as input ROW
	//Data_Dir_KEYPAD &= ~(0b0000<<R0);
	PinCnfg.GPIO_PinNumber = R0;
	PinCnfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCnfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB,&PinCnfg);

	PinCnfg.GPIO_PinNumber = R1;
	PinCnfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCnfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCnfg);

	PinCnfg.GPIO_PinNumber = R2;
	PinCnfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCnfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCnfg);

	PinCnfg.GPIO_PinNumber = R3;
	PinCnfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCnfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCnfg);
	//set second 4 pins as output  COLOUMN
	//	Data_Dir_KEYPAD |= (0b1111<<C0);

	PinCnfg.GPIO_PinNumber = C0;
	PinCnfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCnfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCnfg);

	PinCnfg.GPIO_PinNumber = C1;
	PinCnfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCnfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCnfg);

	PinCnfg.GPIO_PinNumber = C2;
	PinCnfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCnfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCnfg);

	PinCnfg.GPIO_PinNumber = C3;
	PinCnfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCnfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCnfg);


	//	KEYPAD_PORT = 0xFF;
	MCAL_GPIO_WritePort(KEYPAD_PORT, 0XFF);

}

char KEYPAD_GetChar(void){
	int i , j;
	for (i=0; i<4 ; i++)
	{	
		//		KEYPAD_PORT |= 	((1<<KEYPAD_COLOUMN[0]) | (1<<KEYPAD_COLOUMN[1]) | (1<<KEYPAD_COLOUMN[2]) | (1<<KEYPAD_COLOUMN[3]));
		MCAL_GPIO_WritePin(KEYPAD_PORT, KEYPAD_COLOUMN[0], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KEYPAD_COLOUMN[1], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KEYPAD_COLOUMN[2], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KEYPAD_COLOUMN[3], GPIO_PIN_SET);

		//		KEYPAD_PORT &= ~(1<<KEYPAD_COLOUMN[i]);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KEYPAD_COLOUMN[i], GPIO_PIN_RESET);
		for (j=0;j<4;j++)
		{	if (MCAL_GPIO_ReadPin(KEYPAD_PORT, KEYPAD_ROW[j])==0)
				{
			while (MCAL_GPIO_ReadPin(KEYPAD_PORT, KEYPAD_ROW[j])==0);
			switch(i){
			case(0):
				if (j == 0)
					return '7';
				else if (j == 1)
					return '4';
				else if (j == 2)
					return '1';
				else if (j == 3)
					return '!';
				break;

			case(1):
				if (j == 0)
					return '8';
				else if (j == 1)
					return '5';
				else if (j == 2)
					return '2';
				else if (j == 3)
					return '0';
				break;

			case(2):
				if (j == 0)
					return '9';
				else if (j == 1)
					return '6';
				else if (j == 2)
					return '3';
				else if (j == 3)
					return '=';
				break;

			case(3):
				if (j == 0)
					return '/';
				else if (j == 1)
					return '*';
				else if (j == 2)
					return '-';
				else if (j == 3)
					return '+';
				break;


			}
				}

		}
	}

	return 'A';
}
