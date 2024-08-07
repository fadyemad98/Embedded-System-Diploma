/**********************************************************************
[FILE NAME]: <DIO_Interface.h>
Author : Abdelrhman El Kheshen
Version: V0
Description: Interface Header file for the DIO Driver.
Date Created: 28/04/2024
Micro-Controller: TM4C123GH6PM (TIVA C)
Micro-Processor: ARM Cortex-M4
***********************************************************************/
/*Guarding of the File*/
#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_
/*****************************/

/*Including Created Header File*/ 
#include "std_types.h"
/*****************************/


typedef struct 
{
    uint8 port;
    uint8 channel;
}DIO_Channel;

#define PORTA_ID     ((uint8)0)
#define PORTB_ID     ((uint8)1)
#define PORTC_ID     ((uint8)2)
#define PORTD_ID     ((uint8)3)
#define PORTE_ID     ((uint8)4)
#define PORTF_ID     ((uint8)5)

#define MAX_PORTS ((uint8)6)

#define PIN0      ((uint8)0)
#define PIN1      ((uint8)1)
#define PIN2      ((uint8)2)
#define PIN3      ((uint8)3)
#define PIN4      ((uint8)4)
#define PIN5      ((uint8)5)
#define PIN6      ((uint8)6)
#define PIN7      ((uint8)7)

#define PIN_OUTPUT ((uint8)1)
#define PIN_INPUT  ((uint8)0)


#define MAX_PINS  			((uint8)8)

#include "DIO_config.h"

typedef struct 
{
    DIO_Channel Channels[DIO_CONFIGURED_CHANNELS];
}DIO_Configurations;


void DIO_Start(uint8 port);
void DIO_setPinDirection(uint8 port,uint8 pin,uint8 direction);
void DIO_writePin(uint8 Port,uint8 pin,uint8 level);
uint8 DIO_readPin(uint8 Port,uint8 pin);
void DIO_PUR(uint8 Port,uint8 pin);
void DIO_PDR(uint8 Port,uint8 pin);



void DIO_writePort(uint8 port,uint8 value);
uint8 DIO_readPort(uint8 port);

void DIO_Init(const DIO_Configurations* ConfigPtr);
void DIO_writeChannel(uint8 index,uint8 level);
uint8 DIO_readChannel(uint8 index);



/****************************/
/* Extern PB structures to be used by Dio and other modules */
extern const DIO_Configurations cfg;


#endif
