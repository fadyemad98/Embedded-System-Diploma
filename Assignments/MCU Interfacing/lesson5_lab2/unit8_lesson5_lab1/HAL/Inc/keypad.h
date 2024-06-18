/*
 * keypad.h
 *
 * Created: 4/22/2024 9:09:36 PM
 *  Author: fadye
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

 //-------------------------INCLUDES---------------------------//
#include"STM32F103x6.h"
#include"STM32_F103C6_GPIO_Driver.h"


 //-------------------------MACROS---------------------------//
 #define KEYPAD_PORT GPIOB
 //#define Data_Dir_KEYPAD DDRC
// #define KEYPAD_PIN PINC
 
 #define R0 GPIO_PIN_0
 #define R1 GPIO_PIN_1
 #define R2 GPIO_PIN_3
 #define R3 GPIO_PIN_4
 #define C0 GPIO_PIN_5
 #define C1 GPIO_PIN_6
 #define C2 GPIO_PIN_7
 #define C3 GPIO_PIN_8
 
 
//-------------------------API'S---------------------------//

void KEYPAD_INIT(void);
char KEYPAD_GetChar(void);

#endif /* KEYPAD_H_ */
