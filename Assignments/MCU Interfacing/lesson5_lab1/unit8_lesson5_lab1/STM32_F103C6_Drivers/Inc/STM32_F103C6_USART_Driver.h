/*
 * STM32_F103C6_USART_Driver.h
 *
 *  Created on: Jun 4, 2024
 *      Author: Fady Emad
 */

#ifndef INC_STM32_F103C6_USART_DRIVER_H_
#define INC_STM32_F103C6_USART_DRIVER_H_

//includes
#include "STM32F103x6.h"
#include "STM32_F103C6_GPIO_Driver.h"
#include "STM32_F103C6_RCC_Driver.h"


//Configuration structure
typedef struct
{

	uint8_t USART_Mode;     				// Specifies the TX/RX Mode.
											// This parameter must be set based on @ref UART_Mode_define

	uint32_t BaudRate ; 		    		// This member configures the UART communication baud rate
											// This parameter must be set based on @ref UART_BaudRate_define

	uint8_t Payload_Length;					// Specifies the number of data bits transmitted or received in a frame.
											// This parameter must be set based on @ref UART_Payload_Length_define.

	uint8_t Parity ;						//Specifies the parity mode.
											//@ref UART_Parity_define

	uint8_t StopBits ;						//Specifies the number of stop bits transmitted
											//@ref UART_StopBits_define

	uint8_t HwFlowCtl ;						//Specifies whether the hardware flow control mode is enabled or disabled
											//@ref UART_HwFlowCtl_define


	uint8_t	IRQ_Enable;						//enable or disable UART IRQ TX/RX
											//@ref UART_IRQ_Enable_define , you can select two or three parameters EX.UART_IRQ_Enable_TXE |UART_IRQ_Enable_TC


	void(* P_IRQ_CallBack)(void) ;			//Set the C Function() which will be called once the IRQ  Happen

}UART_Config;



// * =======================================================================================
//Reference Macros
// * =======================================================================================

//UART_Mode_define

#define UART_MODE_RX                        (uint32_t) (1<<2)  //RE =1
#define UART_MODE_TX                       	(uint32_t) (1<<3) //TE =1
#define UART_MODE_TX_RX                     ((uint32_t)(1<<2 | 1<<3))

//UART_BaudRate_define

#define UART_BaudRate_2400                   2400
#define UART_BaudRate_9600                   9600
#define UART_BaudRate_19200                  19200
#define UART_BaudRate_57600                  57600
#define UART_BaudRate_115200                 115200
#define UART_BaudRate_230400                 230400
#define UART_BaudRate_460800                 460800
#define UART_BaudRate_921600                 921600
#define UART_BaudRate_2250000                2250000
#define UART_BaudRate_4500000                4500000


//UART_Payload_Length_define
/*	Bit 12 M: Word length
	This bit determines the word length. It is set or cleared by software.
	0: 1 Start bit, 8 Data bits, n Stop bit
	1: 1 Start bit, 9 Data bits, n Stop bit
	Note: The M bit must not be modified during a data transfer (both transmission and reception)
 */

#define UART_Payload_Length_8B               (uint32_t)(0)
#define UART_Payload_Length_9B               (uint32_t)(1<<12)

//@ref UART_Parity_define
/*	Bit 10 PCE: Parity control enable
	This bit selects the hardware parity control (generation and detection). When the parity
	control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit
	if M=0) and parity is checked on the received data. This bit is set and cleared by software.
	Once it is set, PCE is active after the current byte (in reception and in transmission).
	0: Parity control disabled
	1: Parity control enabled

  	Bit 9 PS: Parity selection
	This bit selects the odd or even parity when the parity generation/detection is enabled (PCE
	bit set). It is set and cleared by software. The parity will be selected after the current byte.
	0: Even parity
	1: Odd parity

*/
#define UART_Parity__NONE                    (uint32_t)(0)
#define UART_Parity__EVEN                    ((uint32_t)1<<10)			// enable parity control && by default even is zero
#define UART_Parity__ODD                     ((uint32_t)(1<<10 | 1<<9)) //enable parity control && odd parity

//@ref UART_StopBits_define
/*
 * Bits 13:12 STOP: STOP bits
	These bits are used for programming the stop bits.
	00: 1 Stop bit
	01: 0.5 Stop bit
	10: 2 Stop bits
	11: 1.5 Stop bit
	The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5
*/
#define UART_StopBits__half                  (uint32_t)(1<<12)
#define UART_StopBits__1                     (uint32_t)(0)
#define UART_StopBits__1_half                (uint32_t)(3<<12)
#define UART_StopBits__2                     (uint32_t)(2<<12)


//@ref UART_HwFlowCtl_define
/*	Bit 9 CTSE: CTS enable
	0: CTS hardware flow control disabled
	1: CTS mode enabled, data is only transmitted when the CTS input is asserted (tied to 0). If
	the CTS input is deasserted while a data is being transmitted, then the transmission is
	completed before stopping. If a data is written into the data register while CTS is deasserted,
	the transmission is postponed until CTS is asserted.
	This bit is not available for UART4 & UART5.

	Bit 8 RTSE: RTS enable
	0: RTS hardware flow control disabled
	1: RTS interrupt enabled, data is only requested when there is space in the receive buffer.
	The transmission of data is expected to cease after the current character has been
	transmitted. The RTS output is asserted (tied to 0) when a data can be received.
	This bit is not available for UART4 & UART5.
 * */
#define UART_HwFlowCtl_NONE                  (uint32_t)(0)
#define UART_HwFlowCtl_RTS                   ((uint32_t)1<<8)
#define UART_HwFlowCtl_CTS                   ((uint32_t)1<<9)
#define UART_HwFlowCtl_RTS_CTS               ((uint32_t)(1<<8 | 1<<9))


//@ref UART_IRQ_Enable_define
#define UART_IRQ_Enable_NONE                 (uint32_t)(0)
#define UART_IRQ_Enable_TXE                  (uint32_t) (1<<7) //Transmit data register empty
#define UART_IRQ_Enable_TC                   ((uint32_t)(1<<6)) //Transmission complete
#define UART_IRQ_Enable_RXNEIE               (uint32_t) (1<<5) //Received data ready to be read & Overrun error detected
#define UART_IRQ_Enable_PE                   (uint32_t) (1<<8) //Parity error



//BaudRate Calculation
//USARTDIV = fclk / (16 * Baudrate)
//USARTDIV_MUL100 =
// uint32((100 *fclk ) / (16 * Baudrate) == (25 *fclk ) / (4* Baudrate) )
//DIV_Mantissa_MUL100 = Integer Part (USARTDIV  )  * 100
//DIV_Mantissa = Integer Part (USARTDIV  )
//DIV_Fraction = (( USARTDIV_MUL100  - DIV_Mantissa_MUL100  ) * 16 ) / 100

#define USARTDIV(_PCLK_, _BAUD_)			(uint32_t) (_PCLK_/(16 * _BAUD_ ))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)		(uint32_t) ( (25 * _PCLK_ ) / (4  * _BAUD_ ))
#define Mantissa_MUL100(_PCLK_, _BAUD_)		(uint32_t) (USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)			(uint32_t) (USARTDIV(_PCLK_, _BAUD_) )
#define DIV_Fraction(_PCLK_, _BAUD_)		(uint32_t) (((USARTDIV_MUL100(_PCLK_, _BAUD_) -  Mantissa_MUL100(_PCLK_, _BAUD_) ) * 16 ) / 100 )
#define UART_BRR_Register(_PCLK_, _BAUD_)	(( Mantissa (_PCLK_, _BAUD_) ) <<4 )|( (DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )


enum Polling_mechism{
	enable ,
	disable
};



// * =======================================================================================

/*
 *
 *
 * =======================================================================================
 * 							APIs Supported by "MCAL GPIO DRIVER"
 * =======================================================================================
 */


/* Initialization/de-initialization functions  **********************************/


void MCAL_UART_Init (USART_TypeDef *USARTx, UART_Config* UART_Config);
void MCAL_UART_DeInit (USART_TypeDef *USARTx);

void MCAL_UART_GPIO_Set_Pins (USART_TypeDef *USARTx);

void MCAL_UART_SendData	(USART_TypeDef *USARTx, uint16_t *pTxBuffer,enum Polling_mechism PollingEn ); ///polling mechanism is necessary to chech if transmission empty is clear or set to prevent overwrite
void MCAL_UART_ReceiveData	(USART_TypeDef *USARTx, uint16_t *pTxBuffer ,enum Polling_mechism PollingEn );

void MCAL_UART_WAIT_TC (USART_TypeDef *USARTx ) ;


//todo MCAL_USART_LIN_Init ()  					//LIN
//todo MCAL_USART_Init ()  						//Synchronous
//todo  MCAL_USART_DMA_Init () 					// Multibuffer Communication


#endif /* INC_STM32_F103C6_USART_DRIVER_H_ */
