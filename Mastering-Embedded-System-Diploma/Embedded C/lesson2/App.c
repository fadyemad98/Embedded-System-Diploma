#include "Uart.h"
unsigned char string_buffer[100]= "learn-in-depth-<Fady>";
unsigned char const string_buffer1[100]= "learn-in-depth-<Fady>";
void main(void){ 

	Uart_Send_String(string_buffer);
	
}
