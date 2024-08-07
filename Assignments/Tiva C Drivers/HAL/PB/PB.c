/*
 * PB.c
 *
 *  Created on: Jul 24, 2024
 *      Author: fadye
 */

#include "DIO_Interface.h"
#include "PB.h"






void PB_init(uint8 port, uint8 pin,){
	DIO_Start(port);
	DIO_setPinDirection(port,pin,PIN_INPUT);




}

uint8 read_PB(uint8 port, uint8 pin){

	return 	DIO_readPin(port, pin);

}
