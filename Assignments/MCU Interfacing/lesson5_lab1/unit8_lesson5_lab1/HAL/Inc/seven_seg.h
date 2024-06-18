/*
 * seven_seg.h
 *
 *  Created on: May 2, 2024
 *      Author: fadye
 */

#ifndef SEVEN_SEGMENT_SEVEN_SEG_H_
#define SEVEN_SEGMENT_SEVEN_SEG_H_

#include"STM32F103x6.h"
#include"STM32_F103C6_GPIO_Driver.h"

//7-segments
#define ZERO 0x01
#define ONE 0x79
#define TWO 0x24
#define THREE 0x30
#define FOUR 0x66
#define FIVE 0x12
#define SIX 0x02
#define SEVEN 0x19
#define EIGHT 0x00
#define NINE 0x10

extern unsigned char* P_LCD_DISPLAY;
extern unsigned char* P_DISPLAY;
void SevenSeg_init();



#endif /* SEVEN_SEGMENT_SEVEN_SEG_H_ */
