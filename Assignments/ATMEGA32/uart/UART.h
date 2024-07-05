/*
 * UART.h
 *
 * Created: 6/8/2024 12:24:54 PM
 *  Author: FADY EMAD
 */ 


#ifndef UART_H_
#define UART_H_

void UART_init(long USART_BAUDRATE);
unsigned char UART_RxChar();
void UART_TxChar(char ch);
void UART_SendString(char *str);

#endif /* UART_H_ */