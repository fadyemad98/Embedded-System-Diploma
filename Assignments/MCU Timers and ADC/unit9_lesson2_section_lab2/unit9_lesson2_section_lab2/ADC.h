/*
 * ADC.h
 *
 * Created: 7/7/2024 11:04:09 AM
 *  Author: fadye
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "STD_TYPES.h"
#define ADC_u16		(*(volatile u16*)0x24)   //to read both ADCL & ADCH

typedef enum ADC_Channel{
	ADC_Channel_0,
	ADC_Channel_1,
	ADC_Channel_2,
	ADC_Channel_3,
	ADC_Channel_4,
	ADC_Channel_5,
	ADC_Channel_6,
	ADC_Channel_7
	}ADC_Channel_t;

typedef enum{
	VREF_AREF,
	VREF_AVCC,
	VREF_256,
}ADC_Vref_t;

typedef enum ADC_PRESCALER{
	ADC_PRESCALER_0,
	ADC_PRESCALER_2,
	ADC_PRESCALER_4,
	ADC_PRESCALER_8,
	ADC_PRESCALER_16,
	ADC_PRESCALER_32,
	ADC_PRESCALER_64,
	ADC_PRESCALER_128 
}ADC_PRESCALER_t;


			/*********API'S PROTOTYPES************/

void ADC_init(ADC_Vref_t VREF,ADC_PRESCALER_t PRESCALER);
u16 ADC_GetDigitalVal(ADC_Channel_t Channel_Number);
	

#endif /* ADC_H_ */