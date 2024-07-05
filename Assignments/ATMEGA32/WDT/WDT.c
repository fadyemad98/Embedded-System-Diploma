/*
 * WDT.c
 *
 * Created: 7/2/2024 12:42:44 PM
 *  Author: fadye
 */ 

#include "WDT.h"
//The Watchdog Timer is clocked from a separate On-chip Oscillator which runs at 1MHz.
//By controlling the Watchdog Timer prescaler, the Watchdog Reset interval can be adjusted.
//The Watchdog Timer is also reset when it is disabled and when a Chip Reset occurs.


/*
WDP2 WDP1 WDP0						VCC = 3.0V		VCC = 5.0V
0     0    0 						17.1ms			16.3ms
0     0    1 						34.3ms			32.5ms
0	  1    0 						68.5ms			65ms
0     1    1						0.14s			0.13s
1     0    0						0.27s			0.26s
1     0    1						0.55s			0.52s
1     1    0						1.1s			1.0s
1     1    1						2.2s			2.1s
*/













void WDT_OFF(void){
	// write logic level one to WDE and WDTOE
	WDTCR |= (1<<WDE) | (1<<WDTOE);
	// disable WDT
	WDTCR = 0x00 ;
}


void WDT_ON(void){
	
	//set prescaler to 1 sec and enable WDT
	//WDTCR &= ~(1<<WDP0);
	WDTCR |= (1<<WDP2)|(1<<WDP1)|(1<<WDE);
}