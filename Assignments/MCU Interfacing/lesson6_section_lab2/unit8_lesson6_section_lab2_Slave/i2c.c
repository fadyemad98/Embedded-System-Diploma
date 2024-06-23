/*
 * i2c.c
 *
 * Created: 6/22/2024 1:03:26 PM
 *  Author: Fady Emad
 */ 


#include "i2c.h"
#define prescaler 1     // 1  4  16  64

void I2C_Master_init(unsigned long SCL_clock){
	
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

u8 I2C_Start(s8 write_address)					/* I2C start function */
{
	u8 status;									/* Declare variable */
	TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);		/* Enable TWI, generate START */
	while(!(TWCR&(1<<TWINT)));					/* Wait until TWI finish its current job */
	status=TWSR&0xF8;							/* Read TWI status register */
	if(status!=0x08)							/* Check weather START transmitted or not? */
	return 0;									/* Return 0 to indicate start condition fail */
	TWDR=write_address;							/* Write SLA+W in TWI data register */
	TWCR=(1<<TWEN)|(1<<TWINT);					/* Enable TWI & clear interrupt flag */
	while(!(TWCR&(1<<TWINT)));					/* Wait until TWI finish its current job */
	status=TWSR&0xF8;							/* Read TWI status register */
	if(status==0x18)							/* Check for SLA+W transmitted &ack received */
	return 1;									/* Return 1 to indicate ack received */
	if(status==0x20)							/* Check for SLA+W transmitted &nack received */
	return 2;									/* Return 2 to indicate nack received */
	else
	return 3;									/* Else return 3 to indicate SLA+W failed */
}

u8 I2C_Repeated_Start(s8 read_address)			/* I2C repeated start function */
{
	u8 status;									/* Declare variable */
	TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);		/* Enable TWI, generate start */
	while(!(TWCR&(1<<TWINT)));					/* Wait until TWI finish its current job */
	status=TWSR&0xF8;							/* Read TWI status register */
	if(status!=0x10)							/* Check for repeated start transmitted */
	return 0;									/* Return 0 for repeated start condition fail */
	TWDR=read_address;							/* Write SLA+R in TWI data register */
	TWCR=(1<<TWEN)|(1<<TWINT);					/* Enable TWI and clear interrupt flag */
	while(!(TWCR&(1<<TWINT)));					/* Wait until TWI finish its current job */
	status=TWSR&0xF8;							/* Read TWI status register */
	if(status==0x40)							/* Check for SLA+R transmitted &ack received */
	return 1;									/* Return 1 to indicate ack received */
	if(status==0x48)							/* Check for SLA+R transmitted &nack received */
	return 2;									/* Return 2 to indicate nack received */
	else
	return 3;									/* Else return 3 to indicate SLA+W failed */
}

u8 I2C_Write(s8 data)							/* I2C write function */
{
	u8 status;									/* Declare variable */
	TWDR=data;									/* Copy data in TWI data register */
	TWCR=(1<<TWEN)|(1<<TWINT);					/* Enable TWI and clear interrupt flag */
	while(!(TWCR&(1<<TWINT)));					/* Wait until TWI finish its current job */
	status=TWSR&0xF8;							/* Read TWI status register */
	if(status==0x28)							/* Check for data transmitted &ack received */
	return 0;									/* Return 0 to indicate ack received */
	if(status==0x30)							/* Check for data transmitted &nack received */
	return 1;									/* Return 1 to indicate nack received */
	else
	return 2;									/* Else return 2 for data transmission failure */
}

s8 I2C_Master_Read_Ack()						/* I2C master read with ack send */
{
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);		/* Enable TWI, generation of ack */
	while(!(TWCR&(1<<TWINT)));					/* Wait until TWI finish its current job */
	return TWDR;								/* Return received data */
}


s8 I2C_Master_Read_Nack()						 /* I2C master read with Nack send */
{
	TWCR=(1<<TWEN)|(1<<TWINT);					/* Enable TWI and clear interrupt flag */
	while(!(TWCR&(1<<TWINT)));					/* Wait until TWI finish its current job */
	return TWDR;								/* Return received data */
}


void I2C_Stop(void){
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);		/* Enable TWI, generate stop */
	while(TWCR&(1<<TWSTO));						/* Wait until stop condition execution */
}

void I2C_Slave_Init(u8 slave_address)
{
	TWAR=slave_address;							/* Assign Address in TWI address register */
	TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);		/* Enable TWI, Enable ack generation */
}

u8 I2C_Slave_Listen()
{
	while(1)
	{
		u8 status;								/* Declare variable */
		while(!(TWCR&(1<<TWINT)));				/* Wait to be addressed */
		status=TWSR&0xF8;						/* Read TWI status register */
		if(status==0x60||status==0x68)			/* Own SLA+W received &ack returned */
		return 0;								/* Return 0 to indicate ack returned */
		if(status==0xA8||status==0xB0)			/* Own SLA+R received &ack returned */
		return 1;								/* Return 0 to indicate ack returned */
		if(status==0x70||status==0x78)			/* General call received &ack returned */
		return 2;								/* Return 1 to indicate ack returned */
		else
		continue;								/* Else continue */
	}
}

u8 I2C_Slave_Transmit(char data)
{
	uint8_t status;
	TWDR=data;									/* Write data to TWDR to be transmitted */
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);		/* Enable TWI & clear interrupt flag */
	while(!(TWCR&(1<<TWINT)));					/* Wait until TWI finish its current job */
	status=TWSR&0xF8;							/* Read TWI status register */
	if(status==0xA0)							/* Check for STOP/REPEATED START received */
	{
		TWCR|=(1<<TWINT);						/* Clear interrupt flag & return -1 */
		return -1;
	}		
	if(status==0xB8)							/* Check for data transmitted &ack received */
	return 0;									/* If yes then return 0 */
	if(status==0xC0)							/* Check for data transmitted &nack received */
	{
		TWCR|=(1<<TWINT);						/* Clear interrupt flag & return -2 */
		return -2;
	}
	if(status==0xC8)							/* Last byte transmitted with ack received */
	return -3;									/* If yes then return -3 */
	else										/* else return -4 */
	return -4;
}


char I2C_Slave_Receive()
{
	u8 status;									/* Declare variable */
	TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);		/* Enable TWI & generation of ack */
	while(!(TWCR&(1<<TWINT)));					/* Wait until TWI finish its current job */
	status=TWSR&0xF8;							/* Read TWI status register */
	if(status==0x80||status==0x90)				/* Check for data received &ack returned */
	return TWDR;								/* If yes then return received data */

												/* Check for data received, nack returned & switched to not addressed slave mode */
	if(status==0x88||status==0x98)
	return TWDR;								/* If yes then return received data */
	if(status==0xA0)							/* Check wether STOP/REPEATED START */
	{
		TWCR|=(1<<TWINT);						/* Clear interrupt flag & return -1 */
		return -1;
	}
	else
	return -2;									/* Else return -2 */
}