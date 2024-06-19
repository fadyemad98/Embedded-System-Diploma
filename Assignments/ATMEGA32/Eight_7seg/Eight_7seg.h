/*
 * Eight_7seg.h
 *
 * Created: 6/14/2024 12:43:52 PM
 *  Author: fadye
 */ 


#ifndef EIGHT_7SEG_H_
#define EIGHT_7SEG_H_
#define F_CPU 1000000UL
#include "STD_TYPES.h"
#include "avr/io.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "SPI.h"

//cmd register
#define ScanLimitReg(x)			0x0b, 0x0##x-1     //x should range from 1-->7
#define	IntensityReg			0x0a
#define MaxBrightness			0x0f
#define shutdown_modeReg		0x0c
#define normal_operation		0x01
#define TestModeOff				0x00
#define DisplayTestReg			0x0f
#define DecodeModeReg			0x09
#define DecodeAll				0xff


//data macros
#define E			0x0b
#define	H			0x0c
#define	L			0x0d
#define	P			0x0e

//postion macros
#define digit_1		0x01			
#define digit_2		0x02
#define digit_3		0x03
#define digit_4		0x04
#define digit_5		0x05
#define digit_6		0x06
#define digit_7		0x07
#define digit_8		0x08

//numbers macros
#define	eight		0x08
#define	seven		0x07
#define	six			0x06
#define	five		0x05
#define	four		0x04
#define	three		0x03
#define	two			0x02
#define	one			0x01
#define	zero		0x00


void EIGHT_7SEG_init();
void EIGHT_7SEG_Disp(u8 address, u8 data);


#endif /* EIGHT_7SEG_H_ */