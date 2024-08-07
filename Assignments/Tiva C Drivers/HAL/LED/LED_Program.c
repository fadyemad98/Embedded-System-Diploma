/*
 * LED_Program.c
 *
 *  Created on: Jul 24, 2024
 *      Author: fadye emad
 */


#include "DIO_Interface.h"
#include "Common_Macros.h"


void LED_init(uint8 port, uint8 pin){
	DIO_Start(port);
	DIO_setPinDirection(port, pin, PIN_OUTPUT);
}


void LED_On(uint8 Port, uint8 Pin){
	DIO_writePin(Port,Pin,LOGIC_HIGH);
}

void LED_Off(uint8 Port, uint8 Pin){
	DIO_writePin(Port,Pin,LOGIC_LOW);
}


/*void LED_toggle(uint8 Port, uint8 Pin){
	TOGGLE_BIT(Port, Pin);*/
}
