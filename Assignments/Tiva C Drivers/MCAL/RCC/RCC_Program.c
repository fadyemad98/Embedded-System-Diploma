/**********************************************************************
[FILE NAME]: <RCC_Program.c>
Author : Abdelrhman El Kheshen
Version: V0
Description: Program Source file for the RCC Driver.
Date Created: 28/04/2024
Micro-Controller: TM4C123GH6PM (TIVA C)
Micro-Processor: ARM Cortex-M4
***********************************************************************/
#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "Common_Macros.h"
#include "RCC_Config.h"


void RCC_Init(uint8 clockSource)
{
    SYSTEM_CONTROL_RCC2_REGISTER = ((SYSTEM_CONTROL_RCC2_REGISTER & RCC2_USRRCC2_BIT_MASK) | ~(RCC2_USRRCC2_BIT_MASK));
    if(clockSource == MOSC_CLOCK_SOURCE)
    {
        #ifdef MAIN_OSCILLATOR_16MHZ
        SYSTEM_CONTROL_RCC_REGISTER = ((SYSTEM_CONTROL_RCC_REGISTER & RCC_XTAL_BIT_MASK) | (RCC_XTAL_16MHZ << RCC_XTAL_START_BIT));
        #elif MAIN_OSCILLATOR_8MHZ
        SYSTEM_CONTROL_RCC_REGISTER = ((SYSTEM_CONTROL_RCC_REGISTER & RCC_XTAL_BIT_MASK) | (RCC_XTAL_8MHZ << RCC_XTAL_START_BIT));
        #endif
        SYSTEM_CONTROL_RCC2_REGISTER = ((SYSTEM_CONTROL_RCC2_REGISTER & RCC2_OSCSRC2_BIT_MASK) | (MOSC_CLOCK_SOURCE << RCC2_OSCSRC2_START_BIT));
    }
    else if(clockSource == PIOSC_CLOCK_SOURCE)
    {
        SYSTEM_CONTROL_RCC2_REGISTER = ((SYSTEM_CONTROL_RCC2_REGISTER & RCC2_OSCSRC2_BIT_MASK) | (PIOSC_CLOCK_SOURCE << RCC2_OSCSRC2_START_BIT));
    }
    else if(clockSource == PIOSC_DIV4_CLOCK_SOURCE)
    {
        SYSTEM_CONTROL_RCC2_REGISTER = ((SYSTEM_CONTROL_RCC2_REGISTER & RCC2_OSCSRC2_BIT_MASK) | (PIOSC_DIV4_CLOCK_SOURCE << RCC2_OSCSRC2_START_BIT));
    }
    else if(clockSource == LFIOSC_CLOCK_SOURCE)
    {
        SYSTEM_CONTROL_RCC2_REGISTER = ((SYSTEM_CONTROL_RCC2_REGISTER & RCC2_OSCSRC2_BIT_MASK) | (LFIOSC_CLOCK_SOURCE << RCC2_OSCSRC2_START_BIT));
    }
    else if(clockSource == THIRTYTWO_KHZ_CLOCK_SOURCE)
    {
        SYSTEM_CONTROL_RCC2_REGISTER = ((SYSTEM_CONTROL_RCC2_REGISTER & RCC2_OSCSRC2_BIT_MASK) | (THIRTYTWO_KHZ_CLOCK_SOURCE << RCC2_OSCSRC2_START_BIT));        
    }
    else
    {
        /*Do Nothing*/
    }
}

void PLL_Init(PLL_Configurations* ptr2config)
{
    volatile uint8 dividor = 0;
    SYSTEM_CONTROL_RCC2_REGISTER = ((SYSTEM_CONTROL_RCC2_REGISTER & RCC2_USRRCC2_BIT_MASK) | ~(RCC2_USRRCC2_BIT_MASK)); /*
    1- Configure the system to use RCC2 for advanced features
    */
   /*
   2- Bypass PLL while initializing, Don’t use PLL while init. Precision internal oscillator is used as OSCSRC2 = 0x01
   */
    SYSTEM_CONTROL_RCC2_REGISTER = ((SYSTEM_CONTROL_RCC2_REGISTER & RCC2_BYPASS2_BIT_MASK) | ~(RCC2_BYPASS2_BIT_MASK));
    /*
    3- Select the crystal value and oscillator source
    */
    RCC_Init(ptr2config->source);
    /*
    4- Activate PLL by clearing PWRDN2
    */
    SYSTEM_CONTROL_RCC2_REGISTER = ((SYSTEM_CONTROL_RCC2_REGISTER & RCC2_PWRDN2_BIT_MASK));
    /*
    5- Set the desired system divider and the system divider least significant bit
    */
	SYSTEM_CONTROL_RCC_REGISTER |= (1 << 22);
    SYSTEM_CONTROL_RCC2_REGISTER = ((SYSTEM_CONTROL_RCC2_REGISTER & RCC2_DIV400_BIT_MASK) | (ptr2config->max_frequency << RCC2_DIV400_START_BIT));
    if(ptr2config->max_frequency == FOUR_HUNDRED)
    {
        dividor = FOUR_HUNDRED_MHZ / ptr2config->requiredFrequency;
        SYSTEM_CONTROL_RCC2_REGISTER = ((SYSTEM_CONTROL_RCC2_REGISTER & RCC2_SYSDIV2LSB_USED_MASK) | (dividor << RCC2_SYSDIV2LSB_START_BIT));
    }
    else if(ptr2config->max_frequency == TWO_HUNDRED)
    {
        dividor = TWO_HUNDRED_MHZ / ptr2config->requiredFrequency;
        SYSTEM_CONTROL_RCC2_REGISTER = ((SYSTEM_CONTROL_RCC2_REGISTER & RCC2_SYSDIV2_BIT_MASK) | (dividor << RCC2_SYSDIV2_START_BIT));
    }
    else
    {
        /*Do Nothing*/
    }
    /*
    6- Wait for the PLL to lock by polling PLLLRIS bit
    */
    while(!(GET_BIT(SYSTEM_CONTROL_RIS_REGISTER,PLL_RIS_FLAG_BIT_NO)));
    /*
    7- Enable use of PLL by clearing BYPASS2
    */
    SYSTEM_CONTROL_RCC2_REGISTER = ((SYSTEM_CONTROL_RCC2_REGISTER & RCC2_BYPASS2_BIT_MASK));
}



