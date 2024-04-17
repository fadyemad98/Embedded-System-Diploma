/*
 * unit7_lesson1_lab2.c
 *
 * Created: 4/13/2024 9:59:50 PM
 * Author : fadye
 */ 
#define F_CPU 800000000UL
#include "memory_map.h"
#include <util/delay.h>
//#include <avr/io.h>
#include "util.h"

void GPIO_init(void){
//set PORT A AS OUTPUT
	DDRA |= 0xFF ;
//set PORT A AS PUSH-PULL
	PORTA =0xFF ;
}

static unsigned char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	
int main(void)
{
    GPIO_init();
	
	unsigned char i=0 ;
    while (1) 
    {	
		for(i=0;i<=9;i++)
		{
			PORTA=arr[i];
			_delay_ms(20);
}
}
	}

