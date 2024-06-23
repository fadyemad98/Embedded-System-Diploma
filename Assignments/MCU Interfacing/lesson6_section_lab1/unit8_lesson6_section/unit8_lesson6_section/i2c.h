/*
 * i2c.h
 *
 * Created: 6/22/2024 1:03:39 PM
 *  Author: fadye
 */ 


#ifndef I2C_H_
#define I2C_H_

#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/io.h"
#include "util/delay.h"



void I2C_Master_init(unsigned long SCL_clock);
u8 I2C_Start(s8 write_address);
u8 I2C_Repeated_Start(s8 read_address);
u8 I2C_Write(s8 data);
s8 I2C_Read_Ack();
s8 I2C_Read_Nack();
void I2C_Slave_Init(u8 slave_address);
u8 I2C_Slave_Listen();
u8 I2C_Slave_Transmit(char data);
char I2C_Slave_Receive();



void I2C_Stop(void);





#endif /* I2C_H_ */