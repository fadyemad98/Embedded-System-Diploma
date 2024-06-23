/*
 * unit8_lesson6_section_lab2_Slave.c
 *
 * Created: 6/23/2024 11:23:00 AM
 * Author : Fady Emad
 */ 

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
	u8 status,ch=0;
	I2C_Slave_Init(0b11010000);
	status = I2C_Slave_Listen();
    while (1) 
    {	
		status = I2C_Slave_Listen();

		if (status ==1)
		{
			
			I2C_Slave_Transmit(ch++);
		}
    }
	return 0;
}


