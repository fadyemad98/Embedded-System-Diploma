/**********************************************************************
[FILE NAME]: <PLL_Config.c>
Author : Abdelrhman El Kheshen
Version: V0
Description: Configuration Header file for the RCC Driver.
Date Created: 28/04/2024
Micro-Controller: TM4C123GH6PM (TIVA C)
Micro-Processor: ARM Cortex-M4
***********************************************************************/
#include "RCC_Interface.h"
#include "RCC_Private.h"

const PLL_Configurations config = 
{
    .source = PIOSC_CLOCK_SOURCE,
    .max_frequency = FOUR_HUNDRED,
    .requiredFrequency = 10
};