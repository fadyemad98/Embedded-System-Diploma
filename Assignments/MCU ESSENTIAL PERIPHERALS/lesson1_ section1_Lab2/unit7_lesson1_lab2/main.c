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
//set PORT D PIN 4,5,6,7 AS OUTPUT
	DDRD |= 0xFF;
//set PORT C PIN 0 AS INPUT
	ClearBit(DDRC,0);
//set PIN 0 in PORTC as input pull up
	SetBit(PORTC,0);
//set PORT C PIN 1 AS OUTPUT
	SetBit(DDRC,1);	
}

int main(void)
{
	unsigned char flag =0;
	unsigned char reverse_flag =7;
    GPIO_init();
    while (1) 
    {	
		if((ReadBit(PINC,0)==0))
			{
				if (flag==0)
				{	
					ToggleBit(PORTA,0);
					flag++;
					_delay_ms(5);
				} 
				else if (flag==1)
				{
					ToggleBit(PORTA,1);
					flag++;
					_delay_ms(5);
				}
				else if (flag==2)
				{
					ToggleBit(PORTA,2);
					flag++;
					_delay_ms(5);
				}
				else if (flag==3)
				{
					ToggleBit(PORTA,3);
					flag++;
					_delay_ms(5);
				}
				else if (flag==4)
				{
					ToggleBit(PORTA,4);
					flag++;
					_delay_ms(5);
				}
				else if (flag==5)
				{
					ToggleBit(PORTA,5);
					flag++;
					_delay_ms(5);
				}
				else if (flag==6)
				{
					ToggleBit(PORTA,6);
					flag++;
					_delay_ms(5);
				}
				else if (flag==7)
				{
					ToggleBit(PORTA,7);
					flag++;
					_delay_ms(5);
				}
			}	
			
			
			
			if((ReadBit(PINC,0)==0)&&flag==8)
			{
				if (reverse_flag==7)
				{
					ToggleBit(PORTA,7);
					reverse_flag--;
					_delay_ms(5);
				}
				else if (reverse_flag==6)
				{
					ToggleBit(PORTA,6);
					reverse_flag--;
					_delay_ms(5);
				}
				else if (reverse_flag==5)
				{
					ToggleBit(PORTA,5);
					reverse_flag--;
					_delay_ms(5);
				}
				else if (reverse_flag==4)
				{
					ToggleBit(PORTA,4);
					reverse_flag--;
					_delay_ms(5);
				}
				else if (reverse_flag==3)
				{
					ToggleBit(PORTA,3);
					reverse_flag--;
					_delay_ms(5);
				}
				else if (reverse_flag==2)
				{
					ToggleBit(PORTA,2);
					reverse_flag--;
					_delay_ms(5);
				}
				else if (reverse_flag==1)
				{
					ToggleBit(PORTA,1);
					reverse_flag--;
					_delay_ms(5);
				}
				else if (flag==0)
				{
					ToggleBit(PORTA,0);
					_delay_ms(5);
					flag==0;
				}
			}
}
}

