/*
 * i2c.c
 *
 * Created: 6/22/2024 1:03:26 PM
 *  Author: Fady Emad
 */ 


#include "i2c.h"
#define prescaler 1     // 1  4  16  64

void I2C_init(unsigned long SCL_clock){
	
	TWBR = (unsigned char)(((F_CPU/SCL_clock)-16)/(2*prescaler));
	if (prescaler==1)	
		TWSR=0;
	else if(prescaler==4)
		TWSR=1;
	else if(prescaler==16)
		TWSR=2;
	else if(prescaler==64)
		TWSR=3;
}	

void I2C_Start(void){
	//TWINT is set whenever TWI completes its current event (like start, stop, transmit, receive, etc).
	//TWI interrupt flag must be cleared by software by writing a logical one to it.
	//This bit is not automatically cleared by hardware.
	//--->set when event complete
	//--->to clear it write 1.
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);	/*Enable TWI Start, TWI interfacing & clearing TWINT flag by writing 1	*/
	while (((TWCR &(1<<7))==0));   
	while((TWSR) !=0x08);          /*Read status to ensure start condition has been transmitted */
}

void I2C_Stop(void){
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
	
}

void I2C_write(unsigned char cByte){
	 TWDR=cByte;				    /* Copy data in TWI data register */
	 TWCR=(1<<TWEN)|(1<<TWINT);	    /* Enable TWI and clear interrupt flag */
	
	 while ((TWCR & 0x80)==0);
	 
}

void I2C_Set_address(u8 address){
	
	TWAR = address;
	
	
}


u8 I2C_Read(unsigned char ACK){
	
	u8 x= 0;
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);	    /* Enable TWI , clear interrupt flag and enable ack*/  
	while(!(TWCR & (1<<TWINT)));				/* Wait until TWI finish its current job */
	while(TWSR !=0x60) {
		x=TWSR;                 /*own SLA + W(0) has been transmitted and ACK has been returned */
	} 
	
	TWCR=(1<<TWEN)|(1<<TWINT)|(ACK<<TWEA);  
	while(!(TWCR & (1<<TWINT)));
	while((TWSR)!=0x80){
		x=TWSR;				/*data has been transmitted and ACK has been returned */
		}  
	return TWDR;
}