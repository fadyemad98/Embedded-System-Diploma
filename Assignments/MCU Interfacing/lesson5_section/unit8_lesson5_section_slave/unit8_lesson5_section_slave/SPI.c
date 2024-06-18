/*
 * SPI.c
 *
 * Created: 6/13/2024 11:43:23 AM
 *  Author: fadye
 */ 

#include "SPI.h"

void SPI_Init(SPI_Mode_t Mode){
	if (Mode == Master)
		SPI_Masterinit();
	else //Slave
		SPI_SlaveInit();
}




void SPI_Masterinit(void){
//	set MOSI Pin as O/P	
	DDR_SPI |= (1<<MOSI);
	
//	set MISO Pin as I/P
	DDR_SPI &= ~(1<<MISO);
	
//	set SS Pin as O/P
	DDR_SPI |= (1<<SS);
	
//	set SCK Pin as O/P
	DDR_SPI |= (1<<SCK);

//	set SCK frequency fosc/16
//	SPCR |= (1<<SPR0);
	
//	Bit 4 – MSTR: Master/Slave Select
//	This bit selects Master SPI mode when written to one, and Slave SPI mode when written logic zero. 
	SPCR |= (1<<MSTR);
	
//	set ss as low
	PORTB &= ~(1<<SS);
	
//	Bit 6 – SPE:SPI Enable
//	When the SPE bit is written to one, the SPI is enabled. This bit must be set to enable any SPI operations.
	SPCR |= (1<<SPE);	
	
}

void SPI_SlaveInit(void){
//	set MOSI Pin as I/P
	DDR_SPI &= ~(1<<MOSI);	
	
//	set MISO Pin as O/P
	DDR_SPI |= (1<<MISO);

//	set SS Pin as I/P
	DDR_SPI &= ~(1<<SS);
	
//	set SCK Pin as I/P
	DDR_SPI &= ~(1<<SCK);
	
//	Bit 4 – MSTR : Master/Slave Select
//	This bit selects Master SPI mode when written to one, and Slave SPI mode when written logic zero. 
	SPCR &= ~(1<<MSTR);
	
//	Bit 6 – SPE : SPI Enable
//	When the SPE bit is written to one, the SPI is enabled. This bit must be set to enable any SPI operations.
	SPCR |= (1<<SPE);

}

u8 SPI_SlaveReceive(u8 cdata){
	SPDR = cdata;
	while (!(SPSR & (1<<SPIF ) )); //as long as flag is not set
	//when flag is set ---> recieve complete
	return SPDR;
	
}

u8 SPI_MasterTransmit(u8 cdata){
	SPDR = cdata;
	while (!(SPSR & (1<<SPIF ) )); //as long as flag is not set
	//when flag is set ---> transmit complete
	
//	set ss as low
	PORTB |= (1<<SS);
	
	return SPDR;
}
