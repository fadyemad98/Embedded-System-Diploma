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
    while (1) 
    {
		_delay_ms(500);
		I2C_Master_init(0x48);
		I2C_Start(0b11010000+0);	//transmit start condition& SLA + W(0)  
		I2C_Write(ch++);		    //transmit data
		I2C_Stop();				    // transmit stop condition
    }
	return 0;
}

