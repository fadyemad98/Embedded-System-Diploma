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
	ADC_Channel_1 =1,
	ADC_Channel_2,
	ADC_Channel_3,
	ADC_Channel_4,
	ADC_Channel_5,
	ADC_Channel_6,
	ADC_Channel_7
	}ADC_Channel_t;

			/*********API'S PROTOTYPES************/

void ADC_init(void);
void ADC_GetDigitalVal(ADC_Channel_t Channel_Number,u16 *DigitalVal);
	

#endif /* ADC_H_ */