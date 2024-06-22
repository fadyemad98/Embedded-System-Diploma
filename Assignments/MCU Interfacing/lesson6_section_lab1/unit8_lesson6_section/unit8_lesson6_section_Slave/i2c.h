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

void I2C_init(unsigned long SCL_clock);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_write(unsigned char cByte);
void I2C_Set_address(u8 address);
u8 I2C_Read(unsigned char ACK);


#endif /* I2C_H_ */