/*
 * unit8_lesson6_section_Slave.c
 *
 * Created: 6/22/2024 8:28:21 PM
 * Author : fadye
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include "i2c.h"

int main(void){	
	
	DDRA =0xFF; //PORTA is output
    I2C_Slave_Init(0b11010000); //enable and set slave address and do not accept general call
    while (1) 
    {	I2C_Slave_Listen();
		
		PORTA = I2C_Slave_Receive();// receive byte and sent ack
    }
	return 0;
}

