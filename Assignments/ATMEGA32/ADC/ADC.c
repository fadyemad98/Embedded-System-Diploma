/*
 * ADC.c
 *
 * Created: 7/7/2024 11:03:52 AM
 *  Author: fadye
 */ 
#include "ADC.h"
#include "avr/io.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"


void ADC_init(ADC_Vref_t VREF,ADC_PRESCALER_t PRESCALER){
	//1. select reference or max voltage
	
	switch (VREF)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_AVCC:
		//select  Vref = AVCC
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_256:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
		
	}
		
	//2.Select left adjustment or right adjustment
	//this affect result present in ADC data register
	// Right adjustment
	CLR_BIT(ADMUX,ADLAR);
	
	//3. Disable auto trigger enable
	//single conversion mode --> each conversion has to start ADC conversion by itself 
	CLR_BIT(ADCSRA,ADATE);
	
	//4.Adjust Prescaler
	ADCSRA &= 0xF8; //keep MSB 5 bit value
	ADCSRA |= PRESCALER;
	//select Prescaler 128 for 16MHZ = 125 KHZ
	
	
	//5.ADC Enable
	SET_BIT(ADCSRA,ADEN);
	
}
u16 ADC_GetDigitalVal(ADC_Channel_t ChannelNumber){
	//1. SELECT CHANNEL NUMBER
	//Clear ADMUX channel bits
	ADMUX &= 0b11100000;  //(0xE0)
	//select channel
	ADMUX |= ChannelNumber;
	
	//2. ADC START CONVERSION
	SET_BIT(ADCSRA, ADSC);
	
	//3. WAIT FOR FLAG OF ADC (POLLING)
	while(0 == GET_BIT(ADCSRA,ADIF));
	
	//4.Clear ADIF flag by setting if using polling (automatic clear in case of interrupt)
	SET_BIT(ADCSRA,ADIF);

	//5. READ DIGITAL VALUE
	return ADC_u16;
	
}
