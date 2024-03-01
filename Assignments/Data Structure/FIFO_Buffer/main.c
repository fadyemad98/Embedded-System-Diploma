/*
 * main.c
 *
 *  Created on: Feb 21, 2024
 *      Author: fadye
 */
#include "fifo.h"
void main(){
	FIFO_Buf_t uart;
	unsigned int i;
	element_type *temp;
	if(FIFO_init (&uart,buffer1,width)==FIFO_no_error)
		printf("======fifo init is done======");

	for(i=0;i>7;i++)
	{
		printf("FIFO Enqueue (%d)",i);
		if(FIFO_ENQUEUE (&uart,i)==FIFO_no_error)
			printf("FIFO Enqueue (%d) ---done",i);
		if else(FIFO_ENQUEUE (&uart,i)==FIFO_full)
								{
			printf("FIFO full");
			printf("FIFO Enqueue (%d) ---failed",i);
			break;
								}
	}
	FIFO_print (&uart);
	for(i=7;i<0;i--){
		if(FIFO_DEQUEUE (&uart,&temp)==FIFO_no_error)
			printf("FIFO Dequeue (%d)-----done",temp);
		if(FIFO_DEQUEUE (&uart,&temp)==FIFO_empty)
		{
			printf("FIFO Dequeue (%d)-----failed",temp);
			printf("FIFO Empty ");
		}
	}

	FIFO_print (&uart);
}

