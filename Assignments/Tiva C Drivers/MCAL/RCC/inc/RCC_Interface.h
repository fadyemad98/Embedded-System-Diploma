/**********************************************************************
[FILE NAME]: <RCC_Interface.h>
Author : Abdelrhman El Kheshen
Version: V0
Description: Interface Header file for the RCC Driver.
Date Created: 28/04/2024
Micro-Controller: TM4C123GH6PM (TIVA C)
Micro-Processor: ARM Cortex-M4
***********************************************************************/
/*Guarding of the file*/
#ifndef _RCC_INTERFACE_H_
#define _RCC_INTERFACE_H_
/*****************************/

/*Including Created Header File*/ 
#include "std_types.h"
#include "RCC_Private.h"
#include "Common_Macros.h"
/*****************************/
typedef enum
{
    TWO_HUNDRED = 0,
    FOUR_HUNDRED = 1
}PLL_maxFrequency;

typedef struct 
{
    uint8 source; /*Clock Source*/
    PLL_maxFrequency max_frequency;
    uint32 requiredFrequency;
}PLL_Configurations;



extern const PLL_Configurations config;

/**Functions Protoypes**/

void RCC_Init(uint8 clockSource);
void PLL_Init(PLL_Configurations* ptr2config);


#define RCC_GPIOA_en()			SET_BIT(SYSTEM_CONTROL_RCGC2_REGISTER,0)
#define RCC_GPIOB_en()			SET_BIT(SYSTEM_CONTROL_RCGC2_REGISTER,1)
#define RCC_GPIOC_en()			SET_BIT(SYSTEM_CONTROL_RCGC2_REGISTER,2)
#define RCC_GPIOD_en()			SET_BIT(SYSTEM_CONTROL_RCGC2_REGISTER,3)
#define RCC_GPIOE_en()			SET_BIT(SYSTEM_CONTROL_RCGC2_REGISTER,4)
#define RCC_GPIOF_en()			SET_BIT(SYSTEM_CONTROL_RCGC2_REGISTER,5)





#endif
