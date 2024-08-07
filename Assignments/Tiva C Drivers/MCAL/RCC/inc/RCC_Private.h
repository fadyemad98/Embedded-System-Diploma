/**********************************************************************
[FILE NAME]: <RCC_Private.h>
Author : Abdelrhman El Kheshen
Version: V0
Description: Private Header file for the RCC Driver.
Date Created: 28/04/2024
Micro-Controller: TM4C123GH6PM (TIVA C)
Micro-Processor: ARM Cortex-M4
***********************************************************************/
/*Guarding of the file*/
#ifndef _RCC_PRIVATE_H_
#define _RCC_PRIVATE_H_
/*****************************/

/*Including Created Header File*/ 
#include "std_types.h"
/*****************************/

/*Defining RCC Addresses to access them*/
#define SYSTEM_CONTROL_BASE_ADDRESS         (0x400FE000)
#define SYSTEM_CONTROL_RIS_REG_OFFSET       (0x050)
#define SYSTEM_CONTROL_RCC_REG_OFFSET       (0x060)
#define SYSTEM_CONTROL_RCC2_REG_OFFSET      (0x070)
/***************************************************************************/

/*Defining RCC Registers to access them*/
#define SYSTEM_CONTROL_RCC_REGISTER         (*(volatile unsigned long*)0x400FE060)
#define SYSTEM_CONTROL_RCC2_REGISTER        (*(volatile unsigned long*)0x400FE070)
#define SYSTEM_CONTROL_RIS_REGISTER         (*(volatile unsigned long*)0x400FE050)

//GPIO CLK ENABLE//***********
#define SYSTEM_CONTROL_RCGC2_REGISTER       (*(volatile unsigned long*)0x400FE108)







/***************************************************************************/

/*************************RCC_OSCSRC_BITS OR RCC2_OSCRC2******************************************/
#define MOSC_CLOCK_SOURCE                         ((uint8)0x0)
#define PIOSC_CLOCK_SOURCE                        ((uint8)0x1)
#define PIOSC_DIV4_CLOCK_SOURCE                   ((uint8)0x2)
#define LFIOSC_CLOCK_SOURCE                       ((uint8)0x3)
/*********************************************************************************/

/*************************RCC2_OSCSRC2******************************************/
#define THIRTYTWO_KHZ_CLOCK_SOURCE                ((uint8)0x7)


/*****Defining Masks to Clear the Bits***/
#define RCC2_USRRCC2_BIT_MASK                     (0x7FFFFFFF)
#define RCC2_DIV400_BIT_MASK                      (0xBFFFFFFF)
#define RCC2_SYSDIV2_BIT_MASK                     (0xE07FFFFF)
#define RCC2_SYSDIV2LSB_USED_MASK                 (0xE03FFFFF)
#define RCC2_SYSDIV2LSB_BIT_MASK                  (0xFFBFFFFF)
#define RCC2_USBPWRDN_BIT_MASK                    (0xFFFFBFFF)
#define RCC2_PWRDN2_BIT_MASK                      (0xFFFFDFFF)
#define RCC2_BYPASS2_BIT_MASK                     (0xFFFFF7FF)
#define RCC2_OSCSRC2_BIT_MASK                     (0xFFFFFF8F)

#define RCC_MOSCDIS_BIT_MASK                      (0xFFFFFFFE)
#define RCC_OSCSRC_BIT_MASK                       (0xFFFFFFCF)
#define RCC_XTAL_BIT_MASK                         (0xFFFFF83F)
#define RCC_BYPASS2_BIT_MASK                      (0xFFFFF7FF)
#define RCC_PWRDN_BIT_MASK                        (0xFFFFDFFF)
#define RCC_PWMDIV_BIT_MASK                       (0xFFF1FFFF)
#define RCC_USEPWMDIV_BIT_MASK                    (0xFFEFFFFF)
#define RCC_USESYSDIV_BIT_MASK                    (0xFFBFFFFF)
#define RCC_SYSDIV_BIT_MASK                       (0xF87FFFFF)
#define RCC_ACG_BIT_MASK                          (0xF7FFFFFF)


#define RCC_XTAL_START_BIT                        ((uint8)6U)
#define RCC2_OSCSRC2_START_BIT                    ((uint8)4U)
#define RCC_XTAL_16MHZ                            ((uint8)0x15)
#define RCC_XTAL_8MHZ                             ((uint8)0x0E)
#define RCC2_DIV400_START_BIT                     ((uint8)30U)
#define RCC2_SYSDIV2LSB_START_BIT                 ((uint8)22U)
#define RCC2_SYSDIV2_START_BIT                    ((uint8)23U)

#define PLL_RIS_FLAG_BIT_NO                       ((uint8)6U)

#define RCC_XTAL_16MHZ                            (0x00000540)  /* 16 MHz Crystal Value  0x15 */

#define FOUR_HUNDRED_MHZ                          ((uint32)400000000)
#define TWO_HUNDRED_MHZ                           ((uint32)200000000)
























#endif
