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


void ADC_init(void){
	//1. select reference or max voltage
	//select  Vref = AVCC
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	
	//2.Select left adjustment or right adjustment
	//this affect result present in ADC data register
	// Right adjustment
	CLR_BIT(ADMUX,ADLAR);
	
	//3. Disable auto trigger enable
	//single conversion mode --> each conversion has to start ADC conversion by itself 
	CLR_BIT(ADCSRA,ADATE);
	
	//4.Adjust Prescaler
	//select Prescaler 128 for 16MHZ = 125 KHZ
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	
	//5.ADC Enable
	SET_BIT(ADCSRA,ADEN);
	
}
void ADC_GetDigitalVal(ADC_Channel_t ChannelNumber,u16 *DigitalVal){
	//1. SELECT CHANNEL NUMBER
	//Clear ADMUX channel bits
	ADMUX &= 0b11100000;
	//select channel
	ADMUX |= ChannelNumber;
	
	//2. ADC START CONVERSION
	SET_BIT(ADCSRA, ADSC);
	
	//3. WAIT FOR FLAG OF ADC (POLLING)
	while(0 == GET_BIT(ADCSRA,ADIF));
	
	//4.Clear ADIF flag by setting if using polling (automatic clear in case of interrupt)
	SET_BIT(ADCSRA,ADIF);

	//5. READ DIGITAL VALUE
	*DigitalVal = ADC_u16;
	
}
