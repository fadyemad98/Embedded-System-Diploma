/*
 * fifo.c
 *
 *  Created on: Feb 21, 2024
 *      Author: fadye
 */
#include "fifo.h"

FIFO_Buf_Status FIFO_init (FIFO_Buf_t *fBuf,element_type *Buf,unsigned int length);
FIFO_Buf_Status FIFO_ENQUEUE (FIFO_Buf_t *fBuf,element_type item);
FIFO_Buf_Status FIFO_DEQUEUE (FIFO_Buf_t *fBuf,element_type* item);
FIFO_Buf_Status FIFO_IS_Full (FIFO_Buf_t *fBuf);
FIFO_Buf_Status FIFO_IS_Empty (FIFO_Buf_t *fBuf);
void FIFO_print (FIFO_Buf_t *fBuf);

FIFO_Buf_Status FIFO_init(FIFO_Buf_t *fBuf,element_type *Buf,unsigned int length){
	//check for valid buffer
	if(Buf==NULL)
		return FIFO_null;

	fBuf->base =Buf;
	fBuf->head =Buf;
	fBuf->tail =Buf;
	fBuf->count =0;
	fBuf->length = length;
	return FIFO_no_error;
}
FIFO_Buf_Status FIFO_ENQUEUE(FIFO_Buf_t*fBuf,element_type item){
	if(!fBuf->head || !fBuf->base || !fBuf->tail)
		return FIFO_null;

	if(fBuf->count==fBuf->length)
			return FIFO_full;
	*(fBuf->head)=item;
	fBuf->count++;
	//if circular
	if(fBuf->head==(fBuf->base+(fBuf->length*sizeof(element_type))))
		fBuf->head=fBuf->base;
	else
		fBuf->head++;
	return FIFO_no_error;
}
FIFO_Buf_Status FIFO_DEQUEUE(FIFO_Buf_t *fBuf,element_type* item){
	if(!fBuf->head || !fBuf->base || !fBuf->tail)
			return FIFO_null;
	//check empty
	if(fBuf->count==0)
			return FIFO_empty;

    *(item) = *(fBuf->tail);
    fBuf->count--;
    //if circular
    if(fBuf->tail==(fBuf->base+(fBuf->length*sizeof(element_type))))
    		fBuf->tail=fBuf->base;
    	else
    		fBuf->tail++;
    return FIFO_no_error;
}
FIFO_Buf_Status FIFO_IS_Full(FIFO_Buf_t*fBuf){
	if(!fBuf->head || !fBuf->base || !fBuf->tail)
		return FIFO_null;
	if(fBuf->count==fBuf->length)
		return FIFO_full;
}
FIFO_Buf_Status FIFO_IS_Empty(FIFO_Buf_t *fBuf){
	if(fBuf->count==0)
		return FIFO_empty;
}
//just a func tp print what is inside the fifo withou dequeue
void FIFO_print(FIFO_Buf_t *fBuf){
	int i;
	element_type* temp;
	if (fBuf->count==0)
		printf("======fifo is empty======");
	else
	{
		temp=(fBuf->tail);
		printf("========fifo print========");
		for(i=0;i<fBuf->count;i++){
		printf("\t %X \n",*temp);
		//if circular
		if(temp==(fBuf->base+(fBuf->length*sizeof(element_type))))
			temp=fBuf->base;
		else
			temp++;
	}
	}
}
