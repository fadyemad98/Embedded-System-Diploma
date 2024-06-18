/*
 * seven_seg.c
 *
 *  Created on: May 2, 2024
 *      Author: fadye
 */

#include "seven_seg.h"
unsigned char LCD_DISPLAY[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
unsigned char DISPLAY[11] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};
unsigned char* P_LCD_DISPLAY = LCD_DISPLAY;
unsigned char* P_DISPLAY = DISPLAY;


void SevenSeg_init(){
	GPIO_PINConfig_t PinCfg;

	PinCfg.GPIO_PinNumber = GPIO_PIN_9;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_10;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_11;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_12;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);
	PinCfg.GPIO_PinNumber = GPIO_PIN_14;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_15;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);
}






