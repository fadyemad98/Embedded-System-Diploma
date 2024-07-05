/*
 * timer.h
 *
 * Created: 7/2/2024 7:05:48 PM
 *  Author: fady emad
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "STD_TYPES.h"


typedef enum{
	NORMAL,
	CTC = 0x08,
	PWM_PhaseCorrect = 0x40,
	Fast_PWM = 0x48
}TIMER0_Mode_t ;

typedef enum waveform_generator{
	No_PWM,										//The normal port operation, OC0 disconnected
	Non_inverted_FastPWM = 0x20,				//Clear OC0 on compare match, set OC0 at TOP
	Inverted_PWM_FastPWM = 0x30,				//Set OC0 on compare match, clear OC0 at TOP
	ClrUP_SetDown_Phase_correct_PWM = 0x20,		//Clear OC0 on compare match when up-counting, set OC0 on compare match when down-counting
	SetUP_ClrDown_Phase_correct_PWM = 0x30		//Set OC0 on compare match when up-counting, Clear OC0 on compare match when down-counting
}PWM_Mode_t ;



typedef enum{
	NO_CLK,
	NO_CLK_PRESCALING,
	PRESCAING_CLK8,
	PRESCAING_CLK64,
	PRESCAING_CLK256,
	PRESCAING_CLK1024,
	EXT_CLK_FALLING,
	EXT_CLK_RISING
}TIMER0_CLK_t;

typedef enum{
	OCIE_DISABLE,
	OCIE_ENABLE=0x02
}TIMER0_OCIE_t ;

typedef enum{
	TOVIE_DISABLE,
	TOVIE_ENABLE = 0x01
}TIMER0_TOVIE0_t ;

typedef struct{
	TIMER0_Mode_t 		mode;
	TIMER0_CLK_t  		prescaler;
	TIMER0_OCIE_t		CompMatchInterrupt;
	TIMER0_TOVIE0_t		OvrFlowInterrupt;
	PWM_Mode_t			PWM_Mode;				// in case of Normal or CTC set this to No_PWM
	
}ST_TIMER0Config_t;


E_STATUS_t	TIMER0_Init(ST_TIMER0Config_t* TimConfig);
E_STATUS_t	TIMER0_Stop(void);

E_STATUS_t 	TIMER0_GetCompareValue(ptr_uint8_t pu8_Ticks);
E_STATUS_t 	TIMER0_SetCompareValue(uint8_t u8_Ticks );

E_STATUS_t 	TIMER0_GetDutyValue(ptr_uint8_t pu8_Ticks);	 //used in PWM
E_STATUS_t 	TIMER0_SetDutyValue(uint8_t u8_Ticks );		 //used in PWM


E_STATUS_t 	TIMER0_GetCounterValue(ptr_uint8_t pu8_Ticks);
E_STATUS_t 	TIMER0_SetCounterValue(uint8_t u8_Ticks );

E_STATUS_t 	TIMER0_GetOvrFlowValue(ptr_uint8_t pu8_Ticks);
E_STATUS_t 	TIMER0_SetOvrFlowValue(uint8_t u8_Ticks );

void TIMER0_SetCallback_OvrFlowInterrupt(ptr_VoidFunVoid_t callback);
void TIMER0_SetCallback_CompareInterrupt(ptr_VoidFunVoid_t callback);



#endif /* TIMER_H_ */