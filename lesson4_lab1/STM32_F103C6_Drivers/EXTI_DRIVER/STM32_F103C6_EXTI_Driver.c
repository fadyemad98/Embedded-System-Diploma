/*
 * EXTI.c
 *
 *  Created on: May 3, 2024
 *      Author: Fady Emad
 */

//Includes
#include "STM32F103x6.h"
#include "STM32_F103C6_GPIO_Driver.h"
#include "STM32_F103C6_EXTI_Driver.h"

//=============================

/*
 * =======================================================================================
 * 							Generic Variables
 * =======================================================================================
 */

void(* GP_IRQ_CallBack[15])(void) ;

/*
 * =======================================================================================
 * 							Generic Macros
 * =======================================================================================
 */



#define AFIO_GPIO_EXTI_Mapping(x)		(   (x==GPIOA)?0:\
											(x==GPIOB)?1:\
											(x==GPIOC)?2:\
											(x==GPIOD)?3:0  )






/*
 * =======================================================================================
 * 							Generic Functions
 * =======================================================================================
 */

void Enable_NVIC (uint16_t IRQ)
{
	switch (IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Enable ;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable ;
		break ;
	case 2:
		NVIC_IRQ8_EXTI2_Enable ;
		break ;
	case 3:
		NVIC_IRQ9_EXTI3_Enable ;
		break ;
	case 4:
		NVIC_IRQ10_EXTI4_Enable ;
		break ;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Enable;
		break ;

	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Enable;
		break ;

	}
}

void Disable_NVIC (uint16_t IRQ)
{
	switch (IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Disable ;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Disable ;
		break ;
	case 2:
		NVIC_IRQ8_EXTI2_Disable ;
		break ;
	case 3:
		NVIC_IRQ9_EXTI3_Disable ;
		break ;
	case 4:
		NVIC_IRQ10_EXTI4_Disable ;
		break ;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Disable;
		break ;

	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Disable;
		break ;

	}

}










void Update_EXTI(EXTI_PinConfig_t* EXTI_Config){



	//1- Configure GPIO to be AF Input -> Floating INPUT

	GPIO_PINConfig_t PinCfg;
	//Update the GPIO Pin To Be Floating Input
	PinCfg.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port , &PinCfg);
	//==============================================

	//2- UPDATE AFIO to Route between EXTI Line with PORT A,B,C,D

	uint8_t  AFIO_EXTICR_index = EXTI_Config->EXTI_PIN.EXTI_InputLineNumber / 4 ;

	uint8_t	AFIO_EXTICR_Postion = (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber % 4) * 4 ;

	//clear the four bit
	AFIO->AFIO_EXTICR[AFIO_EXTICR_index ] &= ~(0xF <<AFIO_EXTICR_Postion );           //clear register index with specific line(position)

	AFIO->AFIO_EXTICR[AFIO_EXTICR_index ] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port) &0xF) << AFIO_EXTICR_Postion);

	//==============================================


	//3- Update Rising or falling Register
	// first clearing exti line before updating trigger edge
	EXTI->EXTI_RTSR &= ~(1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	EXTI->EXTI_FTSR &= ~(1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

	if (EXTI_Config->Trigger_Case == EXTI_Trigger_RISING)
	{
		EXTI->EXTI_RTSR |=  (1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

	}else if  (EXTI_Config->Trigger_Case == EXTI_Trigger_FALLING)
	{
		EXTI->EXTI_FTSR |= (1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);


	}else if  (EXTI_Config->Trigger_Case == EXTI_Trigger_RisingAndFalling)
	{
		EXTI->EXTI_RTSR |=  (1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		EXTI->EXTI_FTSR|= (1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}


	//==============================================
	//4- Update IRQ Handling CALLBACK

	GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.EXTI_InputLineNumber] = EXTI_Config->P_IRQ_CallBack ;
	//==============================================
	//5- Enable/Disable IRQ EXTI & NVIC

	if (EXTI_Config->IRQ_EN == EXTI_IRQ_Enable )
	{
		EXTI->EXTI_IMR |= (1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber );
		Enable_NVIC (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber ) ;
	}else
	{
		EXTI->EXTI_IMR &= ~(1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber );
		Disable_NVIC (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber) ;
	}

}



/*
 * ===============================================
 * * APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 */



/**================================================================
 * @Fn				-MCAL_EXTI_GPIO_Init
 * @brief 			-this is used to inialize EXTI from SpecifiC GPIO PIN and specify the Mask/Trigger Condition and IRQ CallBack
 * @param [in]   	-EXTI_Config set by @ref EXTI_define, EXTI_Trigger_define and EXTI_IRQ_define
 * @retval 			-none
 * Note				-Stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 				 	But LQFP48 Package has only GPIO A,B,PART of C/D exported as external PINS from the MCU
 * 				 	-Also Mandatory to Enable RCC Clock for AFIO and the corresponding GPIO
 */
void MCAL_EXTI_GPIO_Init (EXTI_PinConfig_t* EXTI_Config){

	Update_EXTI(EXTI_Config) ;
}



/**================================================================
 * @Fn					-MCAL_EXTI_GPIO_DeInit
 * @brief 				-reset  EXTI Registers and NVIC corresponding IRQ Mask
 * @retval 				-none
 * Note					-none
 */
void MCAL_EXTI_GPIO_DeInit (void){
	//reset  EXTI Registers
	EXTI->EXTI_IMR = 0x00000000;

	EXTI->EXTI_EMR = 0x00000000;

	EXTI->EXTI_RTSR = 0x00000000;

	EXTI->EXTI_FTSR = 0x00000000;

	EXTI->EXTI_SWIER = 0x00000000;

	//rc_w1  cleared by writing a ‘1’ into the PR

	EXTI->EXTI_PR = 0xFFFFFFFF;

	//Disable EXTI IRQ From NVIC
	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI5_9_Disable;
	NVIC_IRQ40_EXTI10_15_Disable;




}


/**================================================================
 * @Fn				-MCAL_EXTI_GPIO_Update
 * @brief 			-this is used to inialize EXTI from SpecifiC GPIO PIN and specify the Mask/Trigger Condition and IRQ CallBack
 * @param [in]   	-EXTI_Config set by @ref EXTI_define, EXTI_Trigger_define and EXTI_IRQ_define
 * @retval 			-none
 * Note				-Stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 				 	But LQFP48 Package has only GPIO A,B,PART of C/D exported as external PINS from the MCU
 * 				 	- Also Mandatory to Enable RCC Clock for AFIO and the corresponding GPIO
 */
void MCAL_EXTI_GPIO_Update (EXTI_PinConfig_t* EXTI_Config){
	Update_EXTI(EXTI_Config) ;
}





///**================================================================
///**================================================================
///**===========			ISR  Functions        =========================
///**================================================================
// */

void EXTI0_IRQHandler(void)
{
	//cleared by writing a ‘1’ into the bit Pending register (EXTI_PR)
	EXTI->EXTI_PR |= (1<<0) ;
	//CALL IRQ_CALL
	GP_IRQ_CallBack[0]() ;
}

void EXTI1_IRQHandler(void) {
	EXTI->EXTI_PR |=  (1<<1) ;

	GP_IRQ_CallBack[1]() ;
}


void EXTI2_IRQHandler (void) {
	EXTI->EXTI_PR |=  (1<<2) ;

	GP_IRQ_CallBack[2]() ; }


void EXTI3_IRQHandler (void) {
	EXTI->EXTI_PR |=  (1<<3) ;

	GP_IRQ_CallBack[3]() ; }


void EXTI4_IRQHandler (void) {
	EXTI->EXTI_PR |=  (1<<4) ;
	GP_IRQ_CallBack[4]() ; }


void EXTI9_5_IRQHandler (void)
{
	if (EXTI->EXTI_PR & 1<<5 ) {	EXTI->EXTI_PR |=  (1<<5)    ; GP_IRQ_CallBack[5]() ;   }
	if (EXTI->EXTI_PR & 1<<6 ) {	EXTI->EXTI_PR |=  (1<<6)    ; GP_IRQ_CallBack[6]() ;   }
	if (EXTI->EXTI_PR & 1<<7 ) {	EXTI->EXTI_PR |=  (1<<7)    ; GP_IRQ_CallBack[7]() ;   }
	if (EXTI->EXTI_PR & 1<<8 ) {	EXTI->EXTI_PR |=  (1<<8)    ; GP_IRQ_CallBack[8]() ;   }
	if (EXTI->EXTI_PR & 1<<9 ) {	EXTI->EXTI_PR |=  (1<<9)    ; GP_IRQ_CallBack[9]() ;   }

}
void EXTI15_10_IRQHandler (void)
{
	if (EXTI->EXTI_PR & 1<<10 ) {	EXTI->EXTI_PR |=  (1<<10)    ; GP_IRQ_CallBack[10]() ;   }
	if (EXTI->EXTI_PR & 1<<11 ) {	EXTI->EXTI_PR |=  (1<<11)    ; GP_IRQ_CallBack[11]() ;   }
	if (EXTI->EXTI_PR & 1<<12 ) {	EXTI->EXTI_PR |=  (1<<12)    ; GP_IRQ_CallBack[12]() ;   }
	if (EXTI->EXTI_PR & 1<<13 ) {	EXTI->EXTI_PR |=  (1<<13)    ; GP_IRQ_CallBack[13]() ;   }
	if (EXTI->EXTI_PR & 1<<14 ) {	EXTI->EXTI_PR |=  (1<<14)    ; GP_IRQ_CallBack[14]() ;   }
	if (EXTI->EXTI_PR & 1<<15 ) {	EXTI->EXTI_PR |=  (1<<15)    ; GP_IRQ_CallBack[15]() ;   }


}

