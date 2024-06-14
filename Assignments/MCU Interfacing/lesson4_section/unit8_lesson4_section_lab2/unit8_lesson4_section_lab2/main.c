/*
 * unit8_lesson4_section_lab2.c
 *
 * Created: 6/14/2024 11:52:13 AM
 * Author : Fady Emad
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include "util/delay.h"
#include "SPI.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Eight_7seg.h"

int main(void)
{
   unsigned char counter = 0;
   unsigned char i;
   SPI_Masterinit();
   EIGHT_7SEG_init();

	while (1){
		char arr[4]={H,E,L,P};
		char index[4]={digit_1,digit_2,digit_3,digit_4};
	 for (i = 0; i < 5; i++){
		 EIGHT_7SEG_Disp(index[i], arr[i]);
		 _delay_ms(1000);
	 }
		}
}











