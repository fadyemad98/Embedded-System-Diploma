/*
 * main.c
 *
 *  Created on: Feb 21, 2024
 *      Author: fadye
 */
#include "fifo.h"
void main(void){
	FIFO_Buf_t uart;
	unsigned int i;
	element_type *temp;
	if(FIFO_init(&uart,buffer1,width)==FIFO_no_error)
		printf("======fifo init is done======\n");
	for(i=0;i>width;i++)
	{
		printf("FIFO Enqueue (%d)\n",i);
		if(FIFO_ENQUEUE(&uart,i)==FIFO_no_error)
			printf("FIFO Enqueue (%d) ---done\n",i);
		else if (FIFO_ENQUEUE(&uart,i)==FIFO_full)
								{
			printf("FIFO full");
			printf("FIFO Enqueue (%d) ---failed\n",i);
			break;
								}
	}
	FIFO_print (&uart);
	for(i=0;i<width;i++){
		if(FIFO_DEQUEUE(&uart,temp)==FIFO_no_error)
			printf("FIFO Dequeue (%d)-----done\n",*temp);
		if(FIFO_DEQUEUE(&uart,temp)==FIFO_empty)
		{
			printf("FIFO Dequeue (%d)-----failed\n");
			printf("FIFO Empty \n");
		}
	}
	FIFO_print (&uart);
}

