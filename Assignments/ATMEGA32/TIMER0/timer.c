/*
 * timer.c
 *
 * Created: 7/2/2024 7:05:34 PM
 *  Author: fadye
 */ 
#include "timer.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include "BIT_MATH.h"

//===================MACROS====================//
#define TIMER0_DDR							DDRB
#define	TIMER0_Pin							PB3
//===================GLobal & Extern==========//
ptr_VoidFunVoid_t callback_OVF;
ptr_VoidFunVoid_t callback_CM;
uint8_t u8_TOVNumber;
ST_TIMER0Config_t* Timer0Configuration;

//===================API's Implementation==========//
E_STATUS_t	TIMER0_Init(ST_TIMER0Config_t* TimConfig){
	E_STATUS_t u8_RetVal = E_NOK;
	if( NULL_PTR == TimConfig){
		u8_RetVal = E_NOK;
	}
	else{
		Timer0Configuration = TimConfig;
		if((NORMAL == Timer0Configuration->mode ) || (CTC == Timer0Configuration->mode) || (PWM_PhaseCorrect == Timer0Configuration->mode) || (Fast_PWM == Timer0Configuration->mode) ){
			
			TCCR0 |= Timer0Configuration->mode;
			if (  ((PWM_PhaseCorrect == Timer0Configuration->mode) || (Fast_PWM == Timer0Configuration->mode)) && (No_PWM != Timer0Configuration->PWM_Mode)   )
			{	
				TCCR0 |= Timer0Configuration->PWM_Mode;
				SET_BIT(TIMER0_DDR,TIMER0_Pin);				/*set OC0 pin as output*/
			} 
			u8_RetVal =E_OK;
			}else{
				u8_RetVal =E_NOK;
		}
		if( (OCIE_ENABLE == Timer0Configuration->CompMatchInterrupt)  || (OCIE_DISABLE == Timer0Configuration->CompMatchInterrupt) ){   //it is faster in OR gate to check for 1 (enable) first 
			TIMSK |= Timer0Configuration->CompMatchInterrupt;
			if ((OCIE_ENABLE == Timer0Configuration->CompMatchInterrupt))
			{
				sei();
			}
			u8_RetVal =E_OK;
			}else{
				u8_RetVal =E_NOK;
		}
		if( (TOVIE_ENABLE == Timer0Configuration->OvrFlowInterrupt)  || (TOVIE_DISABLE == Timer0Configuration->OvrFlowInterrupt)){  //it is faster in OR gate to check for 1 (enable) first
			
			TIMSK |= Timer0Configuration->OvrFlowInterrupt;
			if ((TOVIE_ENABLE == Timer0Configuration->OvrFlowInterrupt) )
			{
				sei();
			}
			u8_RetVal =E_OK;
			}else{
				u8_RetVal =E_NOK;
		}
		if( (NO_CLK <= Timer0Configuration->prescaler)  && (EXT_CLK_RISING >= Timer0Configuration->prescaler)){
			
			TCCR0 |= Timer0Configuration->prescaler;
			u8_RetVal =E_OK;
			}else{
				u8_RetVal =E_NOK;
		}
	}
	return u8_RetVal;
	
	
}
E_STATUS_t	TIMER0_Stop(void){
	E_STATUS_t u8_RetVal = E_OK;
	
	CLR_BIT(TIMSK,CS00);
	CLR_BIT(TIMSK,CS01);
	CLR_BIT(TIMSK,CS02);
	//TIMSK |= NO_CLK;
	
	return u8_RetVal;
}

E_STATUS_t 	TIMER0_GetCompareValue(ptr_uint8_t pu8_Ticks){
	E_STATUS_t u8_RetVal = E_NOK;
	*pu8_Ticks= OCR0;
	return u8_RetVal;
}
E_STATUS_t 	TIMER0_SetCompareValue(uint8_t u8_Ticks ){
	E_STATUS_t u8_RetVal = E_NOK;
	OCR0 = u8_Ticks;
	
	return u8_RetVal;
	
}



E_STATUS_t 	TIMER0_GetDutyValue(ptr_uint8_t pu8_Ticks){
	E_STATUS_t u8_RetVal = E_NOK;
	*pu8_Ticks= (OCR0/(uint8_t)255)*100;    //% value
	return u8_RetVal;
}

E_STATUS_t 	TIMER0_SetDutyValue(uint8_t u8_Ticks ){
	E_STATUS_t u8_RetVal = E_NOK;
	OCR0 = (u8_Ticks * (uint8_t)255)/100;
	return u8_RetVal;
}
















E_STATUS_t 	TIMER0_GetCounterValue(ptr_uint8_t pu8_Ticks){
	E_STATUS_t u8_RetVal = E_NOK;
	*pu8_Ticks= TCNT0;
	
	return u8_RetVal;
	
}
E_STATUS_t 	TIMER0_SetCounterValue(uint8_t u8_Ticks ){
	E_STATUS_t u8_RetVal = E_NOK;
	TCNT0 = u8_Ticks;
	
	return u8_RetVal;
	
}

E_STATUS_t 	TIMER0_GetOvrFlowValue(ptr_uint8_t pu8_Ticks){
	E_STATUS_t u8_RetVal = E_NOK;
	*pu8_Ticks = u8_TOVNumber;
	
	return u8_RetVal;
	
}
E_STATUS_t 	TIMER0_SetOvrFlowValue(uint8_t u8_Ticks ){
	E_STATUS_t u8_RetVal = E_NOK;
	u8_TOVNumber= u8_Ticks;
	
	return u8_RetVal;
	
}

void TIMER0_SetCallback_OvrFlowInterrupt(ptr_VoidFunVoid_t callback){
	
	
	callback_OVF = callback;
	

	
}
void TIMER0_SetCallback_CompareInterrupt(ptr_VoidFunVoid_t callback){
	
	
	callback_CM = callback;
	
	
}


ISR(TIMER0_COMP_vect){
	
	callback_CM();
	
}

ISR(TIMER0_OVF_vect){
	
	u8_TOVNumber++;
	callback_OVF();
	
}