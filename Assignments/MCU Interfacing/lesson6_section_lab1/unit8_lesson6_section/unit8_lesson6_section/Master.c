/*
 * unit8_lesson6_section.c
 *
 * Created: 6/22/2024 1:02:38 PM
 * Author : Fady Emad
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include "i2c.h"

int main(void)
{	
	u8 ch=0;
	I2C_init(0x50);
    while (1) 
    {
		_delay_ms(500);
		I2C_Start();				//transmit start condition
		I2C_write(0b11010000+0);    //transmit SLA + W(0)
		while((TWSR) != 0x18);	    //SLA + W(0) hsa been transmitted
		I2C_write(ch++);		    //transmit data
		while((TWSR) !=0x28);       //Data has been transmitted and ACK has been recieved
		I2C_Stop();				    // transmit stop condition
    }
	return 0;
}

