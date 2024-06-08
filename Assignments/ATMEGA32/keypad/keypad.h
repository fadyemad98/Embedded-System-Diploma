/*
 * keypad.h
 *
 * Created: 4/22/2024 9:09:36 PM
 *  Author: fadye
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
 #define F_CPU 1000000UL
 #include <util/delay.h>
 #include "memory_map.h"
 #include "util.h"
 
 //-------------------------MACROS---------------------------//
 #define KEYPAD_PORT PORTC	
 #define Data_Dir_KEYPAD DDRC
 #define KEYPAD_PIN PINC
 
 #define R0 0
 #define R1 1
 #define R2 2
 #define R3 3
 #define C0 4
 #define C1 5
 #define C2 6
 #define C3 7
 
 
//-------------------------API'S---------------------------//

void KEYPAD_INIT(void);
char KEYPAD_GetChar(void);

#endif /* KEYPAD_H_ */