/*
 * lifo.h
 *
 *  Created on: Feb 19, 2024
 *      Author: fadye
 */

#ifndef LIFO_H_
#define LIFO_H_
typedef struct{
	unsigned char* base;
	unsigned int length;
	unsigned char* head; //we made it pointer as it will point on addresses and char to r/w with one byte;
	unsigned int count;
} LIFO_Buf_t;

typedef enum {
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_not_full,
	LIFO_not_empty,
	LIFO_Null,
}Buffer_Status_t;

// in add func. we need inputs of buffer type (ex.: uart buffer) and the item to be added;
Buffer_Status_t LIFO_Add_item (LIFO_Buf_t* lBuf,unsigned char item);
// in get func. we need to make the item as pointer as it will points every time on specific address to return value from it;
Buffer_Status_t LIFO_get_item (LIFO_Buf_t* lBuf, unsigned char* item);
// in init func. we need the length of array and array will be used in buffering;
Buffer_Status_t LIFO_init (LIFO_Buf_t* lBuf, unsigned int* buf, unsigned int length);
#endif /* LIFO_H_ */
