/*
 * fifo.h
 *
 *  Created on: Feb 21, 2024
 *      Author: fadye
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
//user configuration
#define element_type uint8_t
#define width 5
element_type buffer1[width];

typedef struct
{
	element_type* head;
	element_type* tail;
	element_type* base; // @suppress("Type cannot be resolved")
	unsigned int count;
	unsigned int length;
}FIFO_Buf_t;

typedef enum {

	FIFO_no_error,
	FIFO_error,
	FIFO_full,
	FIFO_not_full,
	FIFO_empty,
	FIFO_not_empty,
	FIFO_null,

}FIFO_Buf_Status;

FIFO_Buf_Status FIFO_init (FIFO_Buf_t *fBuf,element_type *Buf,unsigned int length);
FIFO_Buf_Status FIFO_ENQUEUE (FIFO_Buf_t *fBuf,element_type item);
FIFO_Buf_Status FIFO_DEQUEUE (FIFO_Buf_t *fBuf,element_type* item);
FIFO_Buf_Status FIFO_IS_Full (FIFO_Buf_t *fBuf);
FIFO_Buf_Status FIFO_IS_Empty (FIFO_Buf_t *fBuf);
void FIFO_print (FIFO_Buf_t *fBuf);

#endif /* FIFO_H_ */
