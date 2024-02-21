/*
 * lifo.c
 *
 *  Created on: Feb 19, 2024
 *      Author: fadye
 */
#include "lifo.h"

Buffer_Status_t LIFO_Add_item (LIFO_Buf_t* lBuf,unsigned char item){
	//check for valid lifo
	//if(buf==NULL) i think we could do it like this if the func takes the array buff
	if(!lBuf->head||!lBuf->base)
		return LIFO_Null;
	//check if lifo is full
	if(lBuf->count==lBuf->length)
		return LIFO_full;
	*(lBuf->head)=item;
	lBuf->count++;
	lBuf->head++;
	return LIFO_no_error;
}

Buffer_Status_t LIFO_get_item (LIFO_Buf_t* lBuf, unsigned char* item){
	//check for valid lifo
	//if(buf==NULL)
	if(!lBuf->head||!lBuf->base)
		return LIFO_Null;
	if(lBuf->count==0)
		return LIFO_not_empty;
	lBuf->head--;
	lBuf->count--;
	//this time item gets the data from the head;
	*item=*(lBuf->head);
	return LIFO_no_error;
}
Buffer_Status_t LIFO_init (LIFO_Buf_t* lBuf, unsigned int* buf, unsigned int length){
	if(!buf){
		return LIFO_Null;
	}
	else{
		lBuf->base=buf;
		lBuf->count=0;
		lBuf->head=buf;
		lBuf->length=length;
		return LIFO_no_error;
	}
}

