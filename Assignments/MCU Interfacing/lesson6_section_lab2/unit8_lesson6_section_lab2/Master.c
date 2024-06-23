/*
 * unit8_lesson6_section_lab2.c
 *
 * Created: 6/23/2024 11:20:41 AM
 * Author : fady emad
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include "i2c.h"

int main(void)
{	u8 ch;
	DDRA = 0xFF;						//make port A direction as O/P
	
	while (1)
	{	_delay_ms(500);
		I2C_Master_init(0x48);
		I2C_Start(0b11010000+1)	;			//SLA+R(1)
		ch= I2C_Master_Read_Ack();		//read from slave and send ack
		I2C_Stop();
		PORTA =ch;
	}
	return 0;
}



