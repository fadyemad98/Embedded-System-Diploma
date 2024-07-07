/*
 * unit9_lesson2_section_lab2.c
 *
 * Created: 7/7/2024 8:09:34 PM
 * Author : fadye
 */ 

#include <avr/io.h>
#include "ADC.h"
#include "LCD.h"
#include "STD_TYPES.h "
#include <stdio.h>
#include "BIT_MATH.h"


int main(void)
{	
	u16 Temp, volt ,String1[5],String2[5];
	float temp;
	//set PA1 as input for ADC
	CLR_BIT(DDRA,PA1);
    LCD_Init();
	ADC_init(VREF_AVCC,ADC_PRESCALER_128);
	LCD_String("temp =     C");
	LCD_String_xy(1,0,"volt =       mV");
    while (1) 
    {	
		Temp = ADC_GetDigitalVal(ADC_Channel_1);
		
		temp = Temp*4.88;
		if(Temp>=10){temp = temp/10.00;}
		
		Temp = (int)temp;
		sprintf(String1,"%d",Temp);
		LCD_String_xy(0,8,String1);
		volt = ((u32) ADC_GetDigitalVal(ADC_Channel_2)*5000)/1024;
		sprintf(String2,"%d",volt);
		LCD_String_xy(1,8,String2);
		_delay_ms(500);
    }
}

