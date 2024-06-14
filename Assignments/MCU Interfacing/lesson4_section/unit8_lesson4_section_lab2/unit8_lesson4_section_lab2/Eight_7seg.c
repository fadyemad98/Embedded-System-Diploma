/*
 * Eight_7seg.c
 *
 * Created: 6/14/2024 12:43:14 PM
 *  Author: fadye
 */ 

#include "Eight_7seg.h"

void EIGHT_7SEG_init(){
	/*   EIGHT_7SEG_Disp(0x09, 0xFF); //decode all display
	   EIGHT_7SEG_Disp(0x0A, 0x07); //set scan limit 
	   EIGHT_7SEG_Disp(0x0B, 0x0F);	//max intensity
	   EIGHT_7SEG_Disp(0x0C, 0x01);	//turn on display
	   */
	   EIGHT_7SEG_Disp(DisplayTestReg, TestModeOff);  //display test register - test mode off
	   EIGHT_7SEG_Disp(shutdown_modeReg, normal_operation); //shutdown register - normal operation
	   EIGHT_7SEG_Disp(ScanLimitReg(4)); //scan limit register - display digits 0 thru 7
	   EIGHT_7SEG_Disp(IntensityReg, MaxBrightness);  //intensity register - max brightness
	   EIGHT_7SEG_Disp(DecodeModeReg, DecodeAll);   //decode mode register - CodeB decode all digits
	  
}

void EIGHT_7SEG_Disp(u8 address, u8 data)
{
	PORTB &= ~(1 << SS);
	SPDR = address;
	while (!(SPSR & (1 << SPIF)));
	SPDR = data;
	while (!(SPSR & (1 << SPIF)));
	PORTB |= (1 << SS);
}