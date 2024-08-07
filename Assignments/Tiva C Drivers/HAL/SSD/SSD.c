/*
 * SSD.c
 *
 *  Created on: Jul 24, 2024
 *      Author: fadye
 */


#include "SSD.h"
#include "DIO_Interface.h"

int arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void SSD_init(GPIO_PORT_t port){
	DIO_Init(port);
	DIO_setPortDirection(port, GPIO_Port_OUTPUT);
}



void SSD_Write(uint8 Value,GPIO_PORT_t port){
	DIO_writePort(port, arr[Value]);
}
