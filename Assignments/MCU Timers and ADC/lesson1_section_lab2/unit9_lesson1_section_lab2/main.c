/*
 * unit9_lesson1_section_lab2.c
 *
 * Created: 7/2/2024 7:05:09 PM
 * Author : fadye
 */ 

#include <avr/io.h>
#include "timer.h"

void TIMER0_OVF_CallBack(void){
	PORTA = ~ PORTA;
	
}


int main(void)
{
    DDRA = 0xFF;
	sei();
	TIMER0_SetCallback_CompareInterrupt(TIMER0_OVF_CallBack);
	ST_TIMER0Config_t TimCnfg = {CTC, PRESCAING_CLK8,OCIE_ENABLE,TOVIE_DISABLE};
    TIMER0_SetOvrFlowValue(0xF0);
	TIMER0_Init(&TimCnfg);
	while (1) 
    {
    }
}

