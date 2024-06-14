/*
 * SPI.h
 *
 * Created: 6/13/2024 11:43:35 AM
 *  Author: Fady Emad
 */ 


#ifndef SPI_H_
#define SPI_H_
#define F_CPU 8000000UL
#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "util/delay.h"
#include "avr/interrupt.h"


#define MOSI PB5
#define MISO PB6
#define SCK	 PB7
#define SS PB4
#define DD_MOSI DDB5
#define DD_MISO DDB6
#define DDR_SPI DDRB

void SPI_Masterinit(void);
void SPI_SlaveInit(void);
u8 SPI_SlaveReceive(u8 cdata);
u8 SPI_MasterTransmit(u8 cdata);







#endif /* SPI_H_ */