/*
 * keypad.c
 *
 * Created: 4/22/2024 9:09:54 PM
 *  Author: fadye
 */ 
#include "keypad.h"

int KEYPAD_ROW[] = {R0,R1,R2,R3};
int KEYPAD_COLOUMN[] = {C0,C1,C2,C3}; 

void KEYPAD_INIT(void){
//set first 4 pins as input ROW
	Data_Dir_KEYPAD &= ~(0b0000<<R0);
//set second 4 pins as output  COLOUMN
	Data_Dir_KEYPAD |= (0b1111<<C0);

	KEYPAD_PORT = 0xFF;
}

char KEYPAD_GetChar(void){
	 int i , j;
	for (i=0; i<4 ; i++)
	{	
		KEYPAD_PORT |= 	((1<<KEYPAD_COLOUMN[0]) | (1<<KEYPAD_COLOUMN[1]) | (1<<KEYPAD_COLOUMN[2]) | (1<<KEYPAD_COLOUMN[3]));
		KEYPAD_PORT &= ~(1<<KEYPAD_COLOUMN[i]);
		for (j=0;j<4;j++)
		{	if (!(KEYPAD_PIN & (1<<KEYPAD_ROW[j])))
			{
				while (!(KEYPAD_PIN & (1<<KEYPAD_ROW[j])));
				switch(i){
					case(0):{
						if (j == 0)
						return '7'; 
						else if (j == 1)
						return '4';
						else if (j == 2)
						return '1';
						else if (j == 3)
						return '!';
						break;
					}
					case(1):{
						if (j == 0)
						return '8';
						else if (j == 1)
						return '5';
						else if (j == 2)
						return '2';
						else if (j == 3)
						return '0';
						break;
					}
					case(2):{
						if (j == 0)
						return '9';
						else if (j == 1)
						return '6';
						else if (j == 2)
						return '3';
						else if (j == 3)
						return '=';
						break;
					}
					case(3):{
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
	}
	
	return 'N';
}
