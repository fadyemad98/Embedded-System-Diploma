/*
 * main.c
 *
 *  Created on: Feb 19, 2024
 *      Author: fadye
 */

#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"
unsigned int buffer1[5];
unsigned int buffer2[5];
//unsigned int buffer3[5];
//unsigned int buffer4[5];
//unsigned int buffer5[5];
void main (void)
{
int i, temp=0;
LIFO_Buf_t Uart_lifo;
LIFO_init (&Uart_lifo, buffer1, sizeof(buffer1)/sizeof(buffer1[0]));
for (i=0;i<7;i++)
{
	if (LIFO_Add_item (&Uart_lifo,i)== LIFO_no_error)
	printf("Uart_lifo add : %d\n",i);
}
printf("\n\n");
for (i=0;i<7;i++)
{
	if (LIFO_get_item (&Uart_lifo,&temp)== LIFO_no_error)
	printf("Uart_lifo get : %d\n",temp);
}

}


