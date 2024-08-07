/**********************************************************************
[FILE NAME]: <DIO_Private.h>
Author : Abdelrhman El Kheshen
Version: V0
Description: Private Header file for the DIO Driver.
Date Created: 28/04/2024
Micro-Controller: TM4C123GH6PM (TIVA C)
Micro-Processor: ARM Cortex-M4
***********************************************************************/
/*Guarding of the File*/
#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_
/*****************************/

/*Including Created Header File*/ 
#include "std_types.h"
/*****************************/

/*Regiter to Enable the Clock for GPIO*/
#define GPIO_RCGC_CLOCK_REGISTER                (*(volatile unsigned long*)0x400FE608)
#define GPIO_RCGC2_CLOCK_REGISTER               (*(volatile unsigned long*)0x400FE108)


/*****************************GPIO PORTS BASE ADRRESS********************************************/

/*PORT A Base Address*/
#define GPIOA_BASE_ADDRESS_APB                    (0x40004000)
#define GPIOA_BASE_ADDRESS_AHB                    (0x40058000)

/*PORT B Base Address*/
#define GPIOB_BASE_ADDRESS_APB                    (0x40005000)
#define GPIOB_BASE_ADDRESS_AHB                    (0x40059000)

/*PORT C Base Address*/
#define GPIOC_BASE_ADDRESS_APB                    (0x40006000)
#define GPIOC_BASE_ADDRESS_AHB                    (0x4005A000)

/*PORT D Base Address*/
#define GPIOD_BASE_ADDRESS_APB                    (0x40007000)
#define GPIOD_BASE_ADDRESS_AHB                    (0x4005B000)

/*PORT E Base Address*/
#define GPIOE_BASE_ADDRESS_APB                    (0x40024000)
#define GPIOE_BASE_ADDRESS_AHB                    (0x4005C000)

/*PORT F Base Address*/
#define GPIOF_BASE_ADDRESS_APB                    (0x40025000)
#define GPIOF_BASE_ADDRESS_AHB                    (0x4005D000)
/*****************************************************************************************************/


/******************REGISTERS OFFSET ADDRESS***********************************************************/
#define GPIO_DATA_REG_OFFSET                      (0x000)
#define GPIO_DIR_REG_OFFSET                       (0x400)
#define GPIO_IS_REG_OFFSET                        (0x404)
#define GPIO_IBE_REG_OFFSET                       (0x408)
#define GPIO_IEV_REG_OFFSET                       (0x40C)
#define GPIO_IM_REG_OFFSET                        (0x410)
#define GPIO_RIS_REG_OFFSET                       (0x414)
#define GPIO_MIS_REG_OFFSET                       (0x418)
#define GPIO_ICR_REG_OFFSET                       (0x41C)
#define GPIO_AFSEL_REG_OFFSET                     (0x420)
#define GPIO_DR2R_REG_OFFSET                      (0x500)
#define GPIO_DR4R_REG_OFFSET                      (0x504)
#define GPIO_DR8R_REG_OFFSET                      (0x508)
#define GPIO_ODR_REG_OFFSET                       (0x50C)
#define GPIO_PUR_REG_OFFSET                       (0x510)
#define GPIO_PDR_REG_OFFSET                       (0x514)
#define GPIO_SLR_REG_OFFSET                       (0x518)
#define GPIO_DEN_REG_OFFSET                       (0x51C)
#define GPIO_LOCK_REG_OFFSET                      (0x520)
#define GPIO_CR_REG_OFFSET                        (0x524)
#define GPIO_AMSEL_REG_OFFSET                     (0x528)
#define GPIO_PCTL_REG_OFFSET                      (0x52C)
#define GPIO_ADCCTL_REG_OFFSET                    (0x530)
#define GPIO_DMACTL_REG_OFFSET                    (0x534)
/*****************************************************************************************************/

/**********************************************REGISTERS*******************************************************/
/******PORT A REGISTERS******/
/*Data Register to write and read access*/
#define GPIOA_DATA_REGISTER_APB                   (*(volatile unsigned long*)0x40004000)
#define GPIOA_DATA_REGISTER_AHB                   (*(volatile unsigned long*)0x40058000)


/*Direction Register to specify whether input  or output pin*/
#define GPIOA_DIR_REGISTER_APB                    (*(volatile unsigned long*)0x40004400)
#define GPIOA_DIR_REGISTER_AHB                    (*(volatile unsigned long*)0x40058400)


/*Interrupt Sense Register to specify whether edge or level triggered interrupt pin*/
#define GPIOA_IS_REGISTER_APB                     (*(volatile unsigned long*)0x40004404)
#define GPIOA_IS_REGISTER_AHB                     (*(volatile unsigned long*)0x40058404)


/*Interrupt Both Edges Register to specify that it's triggered for rising and falling edge interrupt pin*/
#define GPIOA_IBE_REGISTER_APB                     (*(volatile unsigned long*)0x40004408)
#define GPIOA_IBE_REGISTER_AHB                     (*(volatile unsigned long*)0x40058408)

/*Interrupt Event Register to specify whether rising edge or falling edge triggered interrupt pin*/
#define GPIOA_IEV_REGISTER_APB                     (*(volatile unsigned long*)0x4000440C)
#define GPIOA_IEV_REGISTER_AHB                     (*(volatile unsigned long*)0x4005840C)

/*Interrupt Mask Register to specify whether the interrupt requested is sent to NVIC or not*/
#define GPIOA_IM_REGISTER_APB                      (*(volatile unsigned long*)0x40004410)
#define GPIOA_IM_REGISTER_AHB                      (*(volatile unsigned long*)0x40058410)


/*Interrupt Raw Status Register to specify whether the interrupt occured on the corresponding pin or not*/
#define GPIOA_RIS_REGISTER_APB                      (*(volatile unsigned long*)0x40004414)
#define GPIOA_RIS_REGISTER_AHB                      (*(volatile unsigned long*)0x40058414)

/*Interrupt Masked Status Register to specify whether the interrupt occured on the corresponding pin or not on the interrupt controller*/
#define GPIOA_MIS_REGISTER_APB                      (*(volatile unsigned long*)0x40004418)
#define GPIOA_MIS_REGISTER_AHB                      (*(volatile unsigned long*)0x40058418)


/*Interrupt CLear Register to Clear the interrupt flag on RIS or MIS Register*/
#define GPIOA_ICR_REGISTER_APB                      (*(volatile unsigned long*)0x4000441C)
#define GPIOA_ICR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005841C)


/*Alternative Function Select Register to indicate whether I'll work with this pin as a GPIO pin or alternative Function*/
#define GPIOA_AFSEL_REGISTER_APB                    (*(volatile unsigned long*)0x40004420)
#define GPIOA_AFSEL_REGISTER_AHB                    (*(volatile unsigned long*)0x40058420)


/*Drive 2mA Select Register to be driven out of the output pin*/
#define GPIOA_DR2R_REGISTER_APB                     (*(volatile unsigned long*)0x40004500)
#define GPIOA_DR2R_REGISTER_AHB                     (*(volatile unsigned long*)0x40058500)


/*Drive 4mA Select Register to be driven out of the output pin*/
#define GPIOA_DR4R_REGISTER_APB                     (*(volatile unsigned long*)0x40004504)
#define GPIOA_DR4R_REGISTER_AHB                     (*(volatile unsigned long*)0x40058504)


/*Drive 8mA Select Register to be driven out of the output pin*/
#define GPIOA_DR8R_REGISTER_APB                     (*(volatile unsigned long*)0x40004508)
#define GPIOA_DR8R_REGISTER_AHB                     (*(volatile unsigned long*)0x40058508)


/*Open Drain Select Register to indicate whether I'll work with this input pin as open drain configuration or not*/
#define GPIOA_ODR_REGISTER_APB                      (*(volatile unsigned long*)0x4000450C)
#define GPIOA_ODR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005850C)


/*Pull-Up Select Register to indicate whether I'll work with this input pin as pull-up resistor configuration or not*/
#define GPIOA_PUR_REGISTER_APB                      (*(volatile unsigned long*)0x40004510)
#define GPIOA_PUR_REGISTER_AHB                      (*(volatile unsigned long*)0x40058510)


/*Pull-Down Select Register to indicate whether I'll work with this input pin as pull-down resistor configuration or not*/
#define GPIOA_PDR_REGISTER_APB                      (*(volatile unsigned long*)0x40004514)
#define GPIOA_PDR_REGISTER_AHB                      (*(volatile unsigned long*)0x40058514)


/*Slew Rate Control Select Register*/
#define GPIOA_SLR_REGISTER_APB                      (*(volatile unsigned long*)0x40004518)
#define GPIOA_SLR_REGISTER_AHB                      (*(volatile unsigned long*)0x40058518)


/*Digital Enable Register to work this GPIO pin as a Digital Component with digital signals*/
#define GPIOA_DEN_REGISTER_APB                      (*(volatile unsigned long*)0x4000451C)
#define GPIOA_DEN_REGISTER_AHB                      (*(volatile unsigned long*)0x4005851C)


/*Lock Register to unlock the locked GPIO pins*/
#define GPIOA_LOCK_REGISTER_APB                     (*(volatile unsigned long*)0x40004520)
#define GPIOA_LOCK_REGISTER_AHB                     (*(volatile unsigned long*)0x40058520)


/*Commit Register to apply changes on unlocked pins*/
#define GPIOA_CR_REGISTER_APB                       (*(volatile unsigned long*)0x40004524)
#define GPIOA_CR_REGISTER_AHB                       (*(volatile unsigned long*)0x40058524)


/*Analog Mode Select Register to work this GPIO pin as a Analog Component with analog signals*/
#define GPIOA_AMSEL_REGISTER_APB                    (*(volatile unsigned long*)0x40004528)
#define GPIOA_AMSEL_REGISTER_AHB                    (*(volatile unsigned long*)0x40058528)


/*Port Contorl Register to Select the mode on which the pin is working on whether GPIO or CAN or UART,etc*/
#define GPIOA_PCTL_REGISTER_APB                     (*(volatile unsigned long*)0x4000452C)
#define GPIOA_PCTL_REGISTER_AHB                     (*(volatile unsigned long*)0x4005852C)


/*ADC Contorl Register to enable ADC on the pin or not*/
#define GPIOA_ADCCTL_REGISTER_APB                   (*(volatile unsigned long*)0x40004530)
#define GPIOA_ADCCTL_REGISTER_AHB                   (*(volatile unsigned long*)0x40058530)


/*DMA Contorl Register to enable DMA on the pin or not*/
#define GPIOA_DMACTL_REGISTER_APB                   (*(volatile unsigned long*)0x40004534)
#define GPIOA_DMACTL_REGISTER_AHB                   (*(volatile unsigned long*)0x40058534)
/*****************************************************************************************************************/

/******PORT B REGISTERS******/
/*Data Register to write and read access*/
#define GPIOB_DATA_REGISTER_APB                    (*(volatile unsigned long*)0x40005000)
#define GPIOB_DATA_REGISTER_AHB                    (*(volatile unsigned long*)0x40059000)


/*Direction Register to specify whether input  or output pin*/
#define GPIOB_DIR_REGISTER_APB                     (*(volatile unsigned long*)0x40005400)
#define GPIOB_DIR_REGISTER_AHB                     (*(volatile unsigned long*)0x40059400)


/*Interrupt Sense Register to specify whether edge or level triggered interrupt pin*/
#define GPIOB_IS_REGISTER_APB                      (*(volatile unsigned long*)0x40005404)
#define GPIOB_IS_REGISTER_AHB                      (*(volatile unsigned long*)0x40059404)


/*Interrupt Both Edges Register to specify that it's triggered for rising and falling edge interrupt pin*/
#define GPIOB_IBE_REGISTER_APB                     (*(volatile unsigned long*)0x40005408)
#define GPIOB_IBE_REGISTER_AHB                     (*(volatile unsigned long*)0x40059408)

/*Interrupt Event Register to specify whether rising edge or falling edge triggered interrupt pin*/
#define GPIOB_IEV_REGISTER_APB                     (*(volatile unsigned long*)0x4000540C)
#define GPIOB_IEV_REGISTER_AHB                     (*(volatile unsigned long*)0x4005940C)

/*Interrupt Mask Register to specify whether the interrupt requested is sent to NVIC or not*/
#define GPIOB_IM_REGISTER_APB                      (*(volatile unsigned long*)0x40005410)
#define GPIOB_IM_REGISTER_AHB                      (*(volatile unsigned long*)0x40059410)


/*Interrupt Raw Status Register to specify whether the interrupt occured on the corresponding pin or not*/
#define GPIOB_RIS_REGISTER_APB                      (*(volatile unsigned long*)0x40005414)
#define GPIOB_RIS_REGISTER_AHB                      (*(volatile unsigned long*)0x40059414)

/*Interrupt Masked Status Register to specify whether the interrupt occured on the corresponding pin or not on the interrupt controller*/
#define GPIOB_MIS_REGISTER_APB                      (*(volatile unsigned long*)0x40005418)
#define GPIOB_MIS_REGISTER_AHB                      (*(volatile unsigned long*)0x40059418)


/*Interrupt CLear Register to Clear the interrupt flag on RIS or MIS Register*/
#define GPIOB_ICR_REGISTER_APB                      (*(volatile unsigned long*)0x4000541C)
#define GPIOB_ICR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005941C)


/*Alternative Function Select Register to indicate whether I'll work with this pin as a GPIO pin or alternative Function*/
#define GPIOB_AFSEL_REGISTER_APB                    (*(volatile unsigned long*)0x40005420)
#define GPIOB_AFSEL_REGISTER_AHB                    (*(volatile unsigned long*)0x40059420)


/*Drive 2mA Select Register to be driven out of the output pin*/
#define GPIOB_DR2R_REGISTER_APB                     (*(volatile unsigned long*)0x40005500)
#define GPIOB_DR2R_REGISTER_AHB                     (*(volatile unsigned long*)0x40059500)


/*Drive 4mA Select Register to be driven out of the output pin*/
#define GPIOB_DR4R_REGISTER_APB                     (*(volatile unsigned long*)0x40005504)
#define GPIOB_DR4R_REGISTER_AHB                     (*(volatile unsigned long*)0x40059504)


/*Drive 8mA Select Register to be driven out of the output pin*/
#define GPIOB_DR8R_REGISTER_APB                     (*(volatile unsigned long*)0x40005508)
#define GPIOB_DR8R_REGISTER_AHB                     (*(volatile unsigned long*)0x40059508)


/*Open Drain Select Register to indicate whether I'll work with this input pin as open drain configuration or not*/
#define GPIOB_ODR_REGISTER_APB                      (*(volatile unsigned long*)0x4000550C)
#define GPIOB_ODR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005950C)


/*Pull-Up Select Register to indicate whether I'll work with this input pin as pull-up resistor configuration or not*/
#define GPIOB_PUR_REGISTER_APB                      (*(volatile unsigned long*)0x40005510)
#define GPIOB_PUR_REGISTER_AHB                      (*(volatile unsigned long*)0x40059510)


/*Pull-Down Select Register to indicate whether I'll work with this input pin as pull-down resistor configuration or not*/
#define GPIOB_PDR_REGISTER_APB                      (*(volatile unsigned long*)0x40005514)
#define GPIOB_PDR_REGISTER_AHB                      (*(volatile unsigned long*)0x40059514)


/*Slew Rate Control Select Register*/
#define GPIOB_SLR_REGISTER_APB                      (*(volatile unsigned long*)0x40005518)
#define GPIOB_SLR_REGISTER_AHB                      (*(volatile unsigned long*)0x40059518)


/*Digital Enable Register to work this GPIO pin as a Digital Component with digital signals*/
#define GPIOB_DEN_REGISTER_APB                      (*(volatile unsigned long*)0x4000551C)
#define GPIOB_DEN_REGISTER_AHB                      (*(volatile unsigned long*)0x4005951C)


/*Lock Register to unlock the locked GPIO pins*/
#define GPIOB_LOCK_REGISTER_APB                     (*(volatile unsigned long*)0x40005520)
#define GPIOB_LOCK_REGISTER_AHB                     (*(volatile unsigned long*)0x40059520)


/*Commit Register to apply changes on unlocked pins*/
#define GPIOB_CR_REGISTER_APB                       (*(volatile unsigned long*)0x40005524)
#define GPIOB_CR_REGISTER_AHB                       (*(volatile unsigned long*)0x40059524)


/*Analog Mode Select Register to work this GPIO pin as a Analog Component with analog signals*/
#define GPIOB_AMSEL_REGISTER_APB                    (*(volatile unsigned long*)0x40005528)
#define GPIOB_AMSEL_REGISTER_AHB                    (*(volatile unsigned long*)0x40059528)


/*Port Contorl Register to Select the mode on which the pin is working on whether GPIO or CAN or UART,etc*/
#define GPIOB_PCTL_REGISTER_APB                     (*(volatile unsigned long*)0x4000552C)
#define GPIOB_PCTL_REGISTER_AHB                     (*(volatile unsigned long*)0x4005952C)


/*ADC Contorl Register to enable ADC on the pin or not*/
#define GPIOB_ADCCTL_REGISTER_APB                   (*(volatile unsigned long*)0x40005530)
#define GPIOB_ADCCTL_REGISTER_AHB                   (*(volatile unsigned long*)0x40059530)


/*DMA Contorl Register to enable DMA on the pin or not*/
#define GPIOB_DMACTL_REGISTER_APB                   (*(volatile unsigned long*)0x40005534)
#define GPIOB_DMACTL_REGISTER_AHB                   (*(volatile unsigned long*)0x40059534)
/*****************************************************************************************************************/

/******PORT C REGISTERS******/
/*Data Register to write and read access*/
#define GPIOC_DATA_REGISTER_APB                    (*(volatile unsigned long*)0x40006000)
#define GPIOC_DATA_REGISTER_AHB                    (*(volatile unsigned long*)0x4005A000)


/*Direction Register to specify whether input  or output pin*/
#define GPIOC_DIR_REGISTER_APB                     (*(volatile unsigned long*)0x40006400)
#define GPIOC_DIR_REGISTER_AHB                     (*(volatile unsigned long*)0x4005A400)


/*Interrupt Sense Register to specify whether edge or level triggered interrupt pin*/
#define GPIOC_IS_REGISTER_APB                      (*(volatile unsigned long*)0x40006404)
#define GPIOC_IS_REGISTER_AHB                      (*(volatile unsigned long*)0x4005A404)


/*Interrupt Both Edges Register to specify that it's triggered for rising and falling edge interrupt pin*/
#define GPIOC_IBE_REGISTER_APB                     (*(volatile unsigned long*)0x40006408)
#define GPIOC_IBE_REGISTER_AHB                     (*(volatile unsigned long*)0x4005A408)

/*Interrupt Event Register to specify whether rising edge or falling edge triggered interrupt pin*/
#define GPIOC_IEV_REGISTER_APB                     (*(volatile unsigned long*)0x4000640C)
#define GPIOC_IEV_REGISTER_AHB                     (*(volatile unsigned long*)0x4005A40C)

/*Interrupt Mask Register to specify whether the interrupt requested is sent to NVIC or not*/
#define GPIOC_IM_REGISTER_APB                      (*(volatile unsigned long*)0x40006410)
#define GPIOC_IM_REGISTER_AHB                      (*(volatile unsigned long*)0x4005A410)


/*Interrupt Raw Status Register to specify whether the interrupt occured on the corresponding pin or not*/
#define GPIOC_RIS_REGISTER_APB                      (*(volatile unsigned long*)0x40006414)
#define GPIOC_RIS_REGISTER_AHB                      (*(volatile unsigned long*)0x4005A414)

/*Interrupt Masked Status Register to specify whether the interrupt occured on the corresponding pin or not on the interrupt controller*/
#define GPIOC_MIS_REGISTER_APB                      (*(volatile unsigned long*)0x40006418)
#define GPIOC_MIS_REGISTER_AHB                      (*(volatile unsigned long*)0x4005A418)


/*Interrupt CLear Register to Clear the interrupt flag on RIS or MIS Register*/
#define GPIOC_ICR_REGISTER_APB                      (*(volatile unsigned long*)0x4000641C)
#define GPIOC_ICR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005A41C)


/*Alternative Function Select Register to indicate whether I'll work with this pin as a GPIO pin or alternative Function*/
#define GPIOC_AFSEL_REGISTER_APB                    (*(volatile unsigned long*)0x40006420)
#define GPIOC_AFSEL_REGISTER_AHB                    (*(volatile unsigned long*)0x4005A420)


/*Drive 2mA Select Register to be driven out of the output pin*/
#define GPIOC_DR2R_REGISTER_APB                     (*(volatile unsigned long*)0x40006500)
#define GPIOC_DR2R_REGISTER_AHB                     (*(volatile unsigned long*)0x4005A500)


/*Drive 4mA Select Register to be driven out of the output pin*/
#define GPIOC_DR4R_REGISTER_APB                     (*(volatile unsigned long*)0x40006504)
#define GPIOC_DR4R_REGISTER_AHB                     (*(volatile unsigned long*)0x4005A504)


/*Drive 8mA Select Register to be driven out of the output pin*/
#define GPIOC_DR8R_REGISTER_APB                     (*(volatile unsigned long*)0x40006508)
#define GPIOC_DR8R_REGISTER_AHB                     (*(volatile unsigned long*)0x4005A508)


/*Open Drain Select Register to indicate whether I'll work with this input pin as open drain configuration or not*/
#define GPIOC_ODR_REGISTER_APB                      (*(volatile unsigned long*)0x4000650C)
#define GPIOC_ODR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005A50C)


/*Pull-Up Select Register to indicate whether I'll work with this input pin as pull-up resistor configuration or not*/
#define GPIOC_PUR_REGISTER_APB                      (*(volatile unsigned long*)0x40006510)
#define GPIOC_PUR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005A510)


/*Pull-Down Select Register to indicate whether I'll work with this input pin as pull-down resistor configuration or not*/
#define GPIOC_PDR_REGISTER_APB                      (*(volatile unsigned long*)0x40006514)
#define GPIOC_PDR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005A514)


/*Slew Rate Control Select Register*/
#define GPIOC_SLR_REGISTER_APB                      (*(volatile unsigned long*)0x40006518)
#define GPIOC_SLR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005A518)


/*Digital Enable Register to work this GPIO pin as a Digital Component with digital signals*/
#define GPIOC_DEN_REGISTER_APB                      (*(volatile unsigned long*)0x4000651C)
#define GPIOC_DEN_REGISTER_AHB                      (*(volatile unsigned long*)0x4005A51C)


/*Lock Register to unlock the locked GPIO pins*/
#define GPIOC_LOCK_REGISTER_APB                     (*(volatile unsigned long*)0x40006520)
#define GPIOC_LOCK_REGISTER_AHB                     (*(volatile unsigned long*)0x4005A520)


/*Commit Register to apply changes on unlocked pins*/
#define GPIOC_CR_REGISTER_APB                       (*(volatile unsigned long*)0x40006524)
#define GPIOC_CR_REGISTER_AHB                       (*(volatile unsigned long*)0x4005A524)


/*Analog Mode Select Register to work this GPIO pin as a Analog Component with analog signals*/
#define GPIOC_AMSEL_REGISTER_APB                    (*(volatile unsigned long*)0x40006528)
#define GPIOC_AMSEL_REGISTER_AHB                    (*(volatile unsigned long*)0x4005A528)


/*Port Contorl Register to Select the mode on which the pin is working on whether GPIO or CAN or UART,etc*/
#define GPIOC_PCTL_REGISTER_APB                     (*(volatile unsigned long*)0x4000652C)
#define GPIOC_PCTL_REGISTER_AHB                     (*(volatile unsigned long*)0x4005A52C)


/*ADC Contorl Register to enable ADC on the pin or not*/
#define GPIOC_ADCCTL_REGISTER_APB                   (*(volatile unsigned long*)0x40006530)
#define GPIOC_ADCCTL_REGISTER_AHB                   (*(volatile unsigned long*)0x4005A530)


/*DMA Contorl Register to enable DMA on the pin or not*/
#define GPIOC_DMACTL_REGISTER_APB                   (*(volatile unsigned long*)0x40006534)
#define GPIOC_DMACTL_REGISTER_AHB                   (*(volatile unsigned long*)0x4005A534)
/*****************************************************************************************************************/

/******PORT D REGISTERS******/
/*Data Register to write and read access*/
#define GPIOD_DATA_REGISTER_APB                    (*(volatile unsigned long*)0x40007000)
#define GPIOD_DATA_REGISTER_AHB                    (*(volatile unsigned long*)0x4005B000)


/*Direction Register to specify whether input  or output pin*/
#define GPIOD_DIR_REGISTER_APB                     (*(volatile unsigned long*)0x40007400)
#define GPIOD_DIR_REGISTER_AHB                     (*(volatile unsigned long*)0x4005B400)


/*Interrupt Sense Register to specify whether edge or level triggered interrupt pin*/
#define GPIOD_IS_REGISTER_APB                      (*(volatile unsigned long*)0x40007404)
#define GPIOD_IS_REGISTER_AHB                      (*(volatile unsigned long*)0x4005B404)


/*Interrupt Both Edges Register to specify that it's triggered for rising and falling edge interrupt pin*/
#define GPIOD_IBE_REGISTER_APB                     (*(volatile unsigned long*)0x40007408)
#define GPIOD_IBE_REGISTER_AHB                     (*(volatile unsigned long*)0x4005B408)

/*Interrupt Event Register to specify whether rising edge or falling edge triggered interrupt pin*/
#define GPIOD_IEV_REGISTER_APB                     (*(volatile unsigned long*)0x4000740C)
#define GPIOD_IEV_REGISTER_AHB                     (*(volatile unsigned long*)0x4005B40C)

/*Interrupt Mask Register to specify whether the interrupt requested is sent to NVIC or not*/
#define GPIOD_IM_REGISTER_APB                      (*(volatile unsigned long*)0x40007410)
#define GPIOD_IM_REGISTER_AHB                      (*(volatile unsigned long*)0x4005B410)


/*Interrupt Raw Status Register to specify whether the interrupt occured on the corresponding pin or not*/
#define GPIOD_RIS_REGISTER_APB                      (*(volatile unsigned long*)0x40007414)
#define GPIOD_RIS_REGISTER_AHB                      (*(volatile unsigned long*)0x4005B414)

/*Interrupt Masked Status Register to specify whether the interrupt occured on the corresponding pin or not on the interrupt controller*/
#define GPIOD_MIS_REGISTER_APB                      (*(volatile unsigned long*)0x40007418)
#define GPIOD_MIS_REGISTER_AHB                      (*(volatile unsigned long*)0x4005B418)


/*Interrupt CLear Register to Clear the interrupt flag on RIS or MIS Register*/
#define GPIOD_ICR_REGISTER_APB                      (*(volatile unsigned long*)0x4000741C)
#define GPIOD_ICR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005B41C)


/*Alternative Function Select Register to indicate whether I'll work with this pin as a GPIO pin or alternative Function*/
#define GPIOD_AFSEL_REGISTER_APB                    (*(volatile unsigned long*)0x40007420)
#define GPIOD_AFSEL_REGISTER_AHB                    (*(volatile unsigned long*)0x4005B420)


/*Drive 2mA Select Register to be driven out of the output pin*/
#define GPIOD_DR2R_REGISTER_APB                     (*(volatile unsigned long*)0x40007500)
#define GPIOD_DR2R_REGISTER_AHB                     (*(volatile unsigned long*)0x4005B500)


/*Drive 4mA Select Register to be driven out of the output pin*/
#define GPIOD_DR4R_REGISTER_APB                     (*(volatile unsigned long*)0x40007504)
#define GPIOD_DR4R_REGISTER_AHB                     (*(volatile unsigned long*)0x4005B504)


/*Drive 8mA Select Register to be driven out of the output pin*/
#define GPIOD_DR8R_REGISTER_APB                     (*(volatile unsigned long*)0x40007508)
#define GPIOD_DR8R_REGISTER_AHB                     (*(volatile unsigned long*)0x4005B508)


/*Open Drain Select Register to indicate whether I'll work with this input pin as open drain configuration or not*/
#define GPIOD_ODR_REGISTER_APB                      (*(volatile unsigned long*)0x4000750C)
#define GPIOD_ODR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005B50C)


/*Pull-Up Select Register to indicate whether I'll work with this input pin as pull-up resistor configuration or not*/
#define GPIOD_PUR_REGISTER_APB                      (*(volatile unsigned long*)0x40007510)
#define GPIOD_PUR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005B510)


/*Pull-Down Select Register to indicate whether I'll work with this input pin as pull-down resistor configuration or not*/
#define GPIOD_PDR_REGISTER_APB                      (*(volatile unsigned long*)0x40007514)
#define GPIOD_PDR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005B514)


/*Slew Rate Control Select Register*/
#define GPIOD_SLR_REGISTER_APB                      (*(volatile unsigned long*)0x40007518)
#define GPIOD_SLR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005B518)


/*Digital Enable Register to work this GPIO pin as a Digital Component with digital signals*/
#define GPIOD_DEN_REGISTER_APB                      (*(volatile unsigned long*)0x4000751C)
#define GPIOD_DEN_REGISTER_AHB                      (*(volatile unsigned long*)0x4005B51C)


/*Lock Register to unlock the locked GPIO pins*/
#define GPIOD_LOCK_REGISTER_APB                     (*(volatile unsigned long*)0x40007520)
#define GPIOD_LOCK_REGISTER_AHB                     (*(volatile unsigned long*)0x4005B520)


/*Commit Register to apply changes on unlocked pins*/
#define GPIOD_CR_REGISTER_APB                       (*(volatile unsigned long*)0x40007524)
#define GPIOD_CR_REGISTER_AHB                       (*(volatile unsigned long*)0x4005B524)


/*Analog Mode Select Register to work this GPIO pin as a Analog Component with analog signals*/
#define GPIOD_AMSEL_REGISTER_APB                    (*(volatile unsigned long*)0x40007528)
#define GPIOD_AMSEL_REGISTER_AHB                    (*(volatile unsigned long*)0x4005B528)


/*Port Contorl Register to Select the mode on which the pin is working on whether GPIO or CAN or UART,etc*/
#define GPIOD_PCTL_REGISTER_APB                     (*(volatile unsigned long*)0x4000752C)
#define GPIOD_PCTL_REGISTER_AHB                     (*(volatile unsigned long*)0x4005B52C)


/*ADC Contorl Register to enable ADC on the pin or not*/
#define GPIOD_ADCCTL_REGISTER_APB                   (*(volatile unsigned long*)0x40007530)
#define GPIOD_ADCCTL_REGISTER_AHB                   (*(volatile unsigned long*)0x4005B530)


/*DMA Contorl Register to enable DMA on the pin or not*/
#define GPIOD_DMACTL_REGISTER_APB                   (*(volatile unsigned long*)0x40007534)
#define GPIOD_DMACTL_REGISTER_AHB                   (*(volatile unsigned long*)0x4005B534)
/*****************************************************************************************************************/

/******PORT E REGISTERS******/
/*Data Register to write and read access*/
#define GPIOE_DATA_REGISTER_APB                    (*(volatile unsigned long*)0x40024000)
#define GPIOE_DATA_REGISTER_AHB                    (*(volatile unsigned long*)0x4005C000)


/*Direction Register to specify whether input  or output pin*/
#define GPIOE_DIR_REGISTER_APB                     (*(volatile unsigned long*)0x40024400)
#define GPIOE_DIR_REGISTER_AHB                     (*(volatile unsigned long*)0x4005C400)


/*Interrupt Sense Register to specify whether edge or level triggered interrupt pin*/
#define GPIOE_IS_REGISTER_APB                      (*(volatile unsigned long*)0x40024404)
#define GPIOE_IS_REGISTER_AHB                      (*(volatile unsigned long*)0x4005C404)


/*Interrupt Both Edges Register to specify that it's triggered for rising and falling edge interrupt pin*/
#define GPIOE_IBE_REGISTER_APB                     (*(volatile unsigned long*)0x40024408)
#define GPIOE_IBE_REGISTER_AHB                     (*(volatile unsigned long*)0x4005C408)

/*Interrupt Event Register to specify whether rising edge or falling edge triggered interrupt pin*/
#define GPIOE_IEV_REGISTER_APB                     (*(volatile unsigned long*)0x4002440C)
#define GPIOE_IEV_REGISTER_AHB                     (*(volatile unsigned long*)0x4005C40C)

/*Interrupt Mask Register to specify whether the interrupt requested is sent to NVIC or not*/
#define GPIOE_IM_REGISTER_APB                      (*(volatile unsigned long*)0x40024410)
#define GPIOE_IM_REGISTER_AHB                      (*(volatile unsigned long*)0x4005C410)


/*Interrupt Raw Status Register to specify whether the interrupt occured on the corresponding pin or not*/
#define GPIOE_RIS_REGISTER_APB                      (*(volatile unsigned long*)0x40024414)
#define GPIOE_RIS_REGISTER_AHB                      (*(volatile unsigned long*)0x4005C414)

/*Interrupt Masked Status Register to specify whether the interrupt occured on the corresponding pin or not on the interrupt controller*/
#define GPIOE_MIS_REGISTER_APB                      (*(volatile unsigned long*)0x40024418)
#define GPIOE_MIS_REGISTER_AHB                      (*(volatile unsigned long*)0x4005C418)


/*Interrupt CLear Register to Clear the interrupt flag on RIS or MIS Register*/
#define GPIOE_ICR_REGISTER_APB                      (*(volatile unsigned long*)0x4002441C)
#define GPIOE_ICR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005C41C)


/*Alternative Function Select Register to indicate whether I'll work with this pin as a GPIO pin or alternative Function*/
#define GPIOE_AFSEL_REGISTER_APB                    (*(volatile unsigned long*)0x40024420)
#define GPIOE_AFSEL_REGISTER_AHB                    (*(volatile unsigned long*)0x4005C420)


/*Drive 2mA Select Register to be driven out of the output pin*/
#define GPIOE_DR2R_REGISTER_APB                     (*(volatile unsigned long*)0x40024500)
#define GPIOE_DR2R_REGISTER_AHB                     (*(volatile unsigned long*)0x4005C500)


/*Drive 4mA Select Register to be driven out of the output pin*/
#define GPIOE_DR4R_REGISTER_APB                     (*(volatile unsigned long*)0x40024504)
#define GPIOE_DR4R_REGISTER_AHB                     (*(volatile unsigned long*)0x4005C504)


/*Drive 8mA Select Register to be driven out of the output pin*/
#define GPIOE_DR8R_REGISTER_APB                     (*(volatile unsigned long*)0x40024508)
#define GPIOE_DR8R_REGISTER_AHB                     (*(volatile unsigned long*)0x4005C508)


/*Open Drain Select Register to indicate whether I'll work with this input pin as open drain configuration or not*/
#define GPIOE_ODR_REGISTER_APB                      (*(volatile unsigned long*)0x4002450C)
#define GPIOE_ODR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005C50C)


/*Pull-Up Select Register to indicate whether I'll work with this input pin as pull-up resistor configuration or not*/
#define GPIOE_PUR_REGISTER_APB                      (*(volatile unsigned long*)0x40024510)
#define GPIOE_PUR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005C510)


/*Pull-Down Select Register to indicate whether I'll work with this input pin as pull-down resistor configuration or not*/
#define GPIOE_PDR_REGISTER_APB                      (*(volatile unsigned long*)0x40024514)
#define GPIOE_PDR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005C514)


/*Slew Rate Control Select Register*/
#define GPIOE_SLR_REGISTER_APB                      (*(volatile unsigned long*)0x40024518)
#define GPIOE_SLR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005C518)


/*Digital Enable Register to work this GPIO pin as a Digital Component with digital signals*/
#define GPIOE_DEN_REGISTER_APB                      (*(volatile unsigned long*)0x4002451C)
#define GPIOE_DEN_REGISTER_AHB                      (*(volatile unsigned long*)0x4005C51C)


/*Lock Register to unlock the locked GPIO pins*/
#define GPIOE_LOCK_REGISTER_APB                     (*(volatile unsigned long*)0x40024520)
#define GPIOE_LOCK_REGISTER_AHB                     (*(volatile unsigned long*)0x4005C520)


/*Commit Register to apply changes on unlocked pins*/
#define GPIOE_CR_REGISTER_APB                       (*(volatile unsigned long*)0x40024524)
#define GPIOE_CR_REGISTER_AHB                       (*(volatile unsigned long*)0x4005C524)


/*Analog Mode Select Register to work this GPIO pin as a Analog Component with analog signals*/
#define GPIOE_AMSEL_REGISTER_APB                    (*(volatile unsigned long*)0x40024528)
#define GPIOE_AMSEL_REGISTER_AHB                    (*(volatile unsigned long*)0x4005C528)


/*Port Contorl Register to Select the mode on which the pin is working on whether GPIO or CAN or UART,etc*/
#define GPIOE_PCTL_REGISTER_APB                     (*(volatile unsigned long*)0x4002452C)
#define GPIOE_PCTL_REGISTER_AHB                     (*(volatile unsigned long*)0x4005C52C)


/*ADC Contorl Register to enable ADC on the pin or not*/
#define GPIOE_ADCCTL_REGISTER_APB                   (*(volatile unsigned long*)0x40024530)
#define GPIOE_ADCCTL_REGISTER_AHB                   (*(volatile unsigned long*)0x4005C530)


/*DMA Contorl Register to enable DMA on the pin or not*/
#define GPIOE_DMACTL_REGISTER_APB                   (*(volatile unsigned long*)0x40024534)
#define GPIOE_DMACTL_REGISTER_AHB                   (*(volatile unsigned long*)0x4005C534)
/*****************************************************************************************************************/

/******PORT F REGISTERS******/
/*Data Register to write and read access*/
#define GPIOF_DATA_REGISTER_APB                    (*(volatile unsigned long*)0x40025000)
#define GPIOF_DATA_REGISTER_AHB                    (*(volatile unsigned long*)0x4005D000)


/*Direction Register to specify whether input  or output pin*/
#define GPIOF_DIR_REGISTER_APB                     (*(volatile unsigned long*)0x40025400)
#define GPIOF_DIR_REGISTER_AHB                     (*(volatile unsigned long*)0x4005D400)


/*Interrupt Sense Register to specify whether edge or level triggered interrupt pin*/
#define GPIOF_IS_REGISTER_APB                      (*(volatile unsigned long*)0x40025404)
#define GPIOF_IS_REGISTER_AHB                      (*(volatile unsigned long*)0x4005D404)


/*Interrupt Both Edges Register to specify that it's triggered for rising and falling edge interrupt pin*/
#define GPIOF_IBE_REGISTER_APB                     (*(volatile unsigned long*)0x40025408)
#define GPIOF_IBE_REGISTER_AHB                     (*(volatile unsigned long*)0x4005D408)

/*Interrupt Event Register to specify whether rising edge or falling edge triggered interrupt pin*/
#define GPIOF_IEV_REGISTER_APB                     (*(volatile unsigned long*)0x4002540C)
#define GPIOF_IEV_REGISTER_AHB                     (*(volatile unsigned long*)0x4005D40C)

/*Interrupt Mask Register to specify whether the interrupt requested is sent to NVIC or not*/
#define GPIOF_IM_REGISTER_APB                      (*(volatile unsigned long*)0x40025410)
#define GPIOF_IM_REGISTER_AHB                      (*(volatile unsigned long*)0x4005D410)


/*Interrupt Raw Status Register to specify whether the interrupt occured on the corresponding pin or not*/
#define GPIOF_RIS_REGISTER_APB                      (*(volatile unsigned long*)0x40025414)
#define GPIOF_RIS_REGISTER_AHB                      (*(volatile unsigned long*)0x4005D414)

/*Interrupt Masked Status Register to specify whether the interrupt occured on the corresponding pin or not on the interrupt controller*/
#define GPIOF_MIS_REGISTER_APB                      (*(volatile unsigned long*)0x40025418)
#define GPIOF_MIS_REGISTER_AHB                      (*(volatile unsigned long*)0x4005D418)


/*Interrupt CLear Register to Clear the interrupt flag on RIS or MIS Register*/
#define GPIOF_ICR_REGISTER_APB                      (*(volatile unsigned long*)0x4002541C)
#define GPIOF_ICR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005D41C)


/*Alternative Function Select Register to indicate whether I'll work with this pin as a GPIO pin or alternative Function*/
#define GPIOF_AFSEL_REGISTER_APB                    (*(volatile unsigned long*)0x40025420)
#define GPIOF_AFSEL_REGISTER_AHB                    (*(volatile unsigned long*)0x4005D420)


/*Drive 2mA Select Register to be driven out of the output pin*/
#define GPIOF_DR2R_REGISTER_APB                     (*(volatile unsigned long*)0x40025500)
#define GPIOF_DR2R_REGISTER_AHB                     (*(volatile unsigned long*)0x4005D500)


/*Drive 4mA Select Register to be driven out of the output pin*/
#define GPIOF_DR4R_REGISTER_APB                     (*(volatile unsigned long*)0x40025504)
#define GPIOF_DR4R_REGISTER_AHB                     (*(volatile unsigned long*)0x4005D504)


/*Drive 8mA Select Register to be driven out of the output pin*/
#define GPIOF_DR8R_REGISTER_APB                     (*(volatile unsigned long*)0x40025508)
#define GPIOF_DR8R_REGISTER_AHB                     (*(volatile unsigned long*)0x4005D508)


/*Open Drain Select Register to indicate whether I'll work with this input pin as open drain configuration or not*/
#define GPIOF_ODR_REGISTER_APB                      (*(volatile unsigned long*)0x4002550C)
#define GPIOF_ODR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005D50C)


/*Pull-Up Select Register to indicate whether I'll work with this input pin as pull-up resistor configuration or not*/
#define GPIOF_PUR_REGISTER_APB                      (*(volatile unsigned long*)0x40025510)
#define GPIOF_PUR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005D510)


/*Pull-Down Select Register to indicate whether I'll work with this input pin as pull-down resistor configuration or not*/
#define GPIOF_PDR_REGISTER_APB                      (*(volatile unsigned long*)0x40025514)
#define GPIOF_PDR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005D514)


/*Slew Rate Control Select Register*/
#define GPIOF_SLR_REGISTER_APB                      (*(volatile unsigned long*)0x40025518)
#define GPIOF_SLR_REGISTER_AHB                      (*(volatile unsigned long*)0x4005D518)


/*Digital Enable Register to work this GPIO pin as a Digital Component with digital signals*/
#define GPIOF_DEN_REGISTER_APB                      (*(volatile unsigned long*)0x4002551C)
#define GPIOF_DEN_REGISTER_AHB                      (*(volatile unsigned long*)0x4005D51C)


/*Lock Register to unlock the locked GPIO pins*/
#define GPIOF_LOCK_REGISTER_APB                     (*(volatile unsigned long*)0x40025520)
#define GPIOF_LOCK_REGISTER_AHB                     (*(volatile unsigned long*)0x4005D520)


/*Commit Register to apply changes on unlocked pins*/
#define GPIOF_CR_REGISTER_APB                       (*(volatile unsigned long*)0x40025524)
#define GPIOF_CR_REGISTER_AHB                       (*(volatile unsigned long*)0x4005D524)


/*Analog Mode Select Register to work this GPIO pin as a Analog Component with analog signals*/
#define GPIOF_AMSEL_REGISTER_APB                    (*(volatile unsigned long*)0x40025528)
#define GPIOF_AMSEL_REGISTER_AHB                    (*(volatile unsigned long*)0x4005D528)


/*Port Contorl Register to Select the mode on which the pin is working on whether GPIO or CAN or UART,etc*/
#define GPIOF_PCTL_REGISTER_APB                     (*(volatile unsigned long*)0x4002552C)
#define GPIOF_PCTL_REGISTER_AHB                     (*(volatile unsigned long*)0x4005D52C)


/*ADC Contorl Register to enable ADC on the pin or not*/
#define GPIOF_ADCCTL_REGISTER_APB                   (*(volatile unsigned long*)0x40025530)
#define GPIOF_ADCCTL_REGISTER_AHB                   (*(volatile unsigned long*)0x4005D530)


/*DMA Contorl Register to enable DMA on the pin or not*/
#define GPIOF_DMACTL_REGISTER_APB                   (*(volatile unsigned long*)0x40025534)
#define GPIOF_DMACTL_REGISTER_AHB                   (*(volatile unsigned long*)0x4005D534)
/*****************************************************************************************************************/
#endif