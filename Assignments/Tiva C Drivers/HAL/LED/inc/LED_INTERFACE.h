/*
 * LED.h
 *
 *  Created on: Jul 24, 2024
 *      Author: fadye
 */

#ifndef LED_INC_LED_INTERFACE_H_
#define LED_INC_LED_INTERFACE_H_
#include "DIO_Interface.h"
#include "std_types.h"

void LED_init(uint8 port, uint8 pin);
//void LED_toggle(uint8 Port, uint8 Pin);
void LED_On(uint8 Port, uint8 Pin);
void LED_Off(uint8 Port, uint8 Pin);





#endif /* LED_INC_LED_INTERFACE_H_ */
