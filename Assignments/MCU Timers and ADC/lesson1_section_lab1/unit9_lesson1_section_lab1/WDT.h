/*
 * WDT.h
 *
 * Created: 7/2/2024 12:42:58 PM
 *  Author: fadye
 */ 


#ifndef WDT_H_
#define WDT_H_
#include "avr/io.h"
//The Watchdog Timer is clocked from a separate On-chip Oscillator which runs at 1MHz. 
//By controlling the Watchdog Timer prescaler, the Watchdog Reset interval can be adjusted.
//The Watchdog Timer is also reset when it is disabled and when a Chip Reset occurs.

void WDT_OFF(void);
void WDT_ON(void);




#endif /* WDT_H_ */