/*
 * unit9_lesson1_section_lab2.c
 *
 * Created: 7/2/2024 7:05:09 PM
 * Author : fadye
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include "util/delay.h"
#include "timer.h"
#include "LCD.h"
#include "STD_TYPES.h"





int main(void)
{	volatile uint8_t dutyRead;
	ST_TIMER0Config_t TimCnfg = {PWM_PhaseCorrect, PRESCAING_CLK256,OCIE_DISABLE,TOVIE_DISABLE,ClrUP_SetDown_Phase_correct_PWM};
	TIMER0_Init(&TimCnfg);
	LCD_Init();
	LCD_String(" Duty cycle=   %");
	while (1) 
    {	int i =50;
		while (i>0)
		{
			TIMER0_SetDutyValue(i);
			i--;
			LCD_xy(1,11);
			dutyRead = i;
			LCD_Char(dutyRead);
			_delay_ms(100000);
		}
		_delay_ms(1000);
    }
}

