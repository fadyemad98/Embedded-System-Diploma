/*
 * ADC.c
 *
 * Created: 7/7/2024 11:03:12 AM
 * Author : fadye
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include "util/delay.h"
#include "BIT_MATH.h"
#include "ADC.h"
#include "LCD.h"
#include <stdio.h>

int main(void)
{	u16 digitalVALUE=0, analogValue = 0;
	char String[5];
	LCD_Init();
	//set PA1 as input for ADC
	CLR_BIT(DDRA,PA1);
	//set PA2,PA3,PA4 as output for 3 lEDs
	SET_BIT(DDRA,PA2);
	SET_BIT(DDRA,PA3);
	SET_BIT(DDRA,PA4);
    ADC_init();
	LCD_String("ADC value");
	LCD_String_xy(1,9,"mV");
    while (1) 
    {
		LCD_xy(1,5);
		sprintf(String,"%d",analogValue);
		//itoa(analogValue,String,5);
		LCD_String_xy(1,3,String);
		ADC_GetDigitalVal(ADC_Channel_1,&digitalVALUE);
		analogValue = ((u32)digitalVALUE*5000UL)/1024;    //digital * VREF (mv)	/ 2^res 
		if (analogValue < 1500 ) {	//1500 mV
			SET_BIT(PORTA,PA2);
			CLR_BIT(PORTA,PA3);
			CLR_BIT(PORTA,PA4);
		} 
		else if((analogValue < 3000) ){
			SET_BIT(PORTA,PA3);
			CLR_BIT(PORTA,PA2);
			CLR_BIT(PORTA,PA4);
			
			
		}else if((analogValue < 5000)){
			SET_BIT(PORTA,PA4);
			CLR_BIT(PORTA,PA3);
			CLR_BIT(PORTA,PA2);
			
		}
		
		
    }
}

