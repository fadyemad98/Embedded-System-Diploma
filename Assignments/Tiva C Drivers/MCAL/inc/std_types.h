/*
 * std_types.h
 *
 *  Created on: Oct 6, 2023
 *  Author: Abdelrhman Hesham
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


/*CREATING A NEW TYPE CALLED BOOLEAN*/
typedef unsigned char boolean;


/*BOOLEAN VALUES*/
#ifndef FALSE
#define FALSE   (0u)
#endif


#ifndef ERROR
#define ERROR   (-1)
#endif




#ifndef TRUE
#define TRUE    (1u)
#endif

#ifndef LOGIC_LOW
#define LOGIC_LOW   (0u)
#endif

#ifndef LOGIC_HIGH
#define LOGIC_HIGH    (1u)
#endif
/*******************/

/*NULL POINTER*/
#define NULL_PTR  ((void*)0)

/*TYPES TO BE USED*/

typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short uint16;
typedef signed short sint16;
typedef unsigned long uint32;
typedef signed long sint32;
typedef unsigned long long uint64;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

typedef char* ptoc;
typedef short* ptos;
typedef int* ptoi;
typedef void* ptov;
typedef int** ptop;


#endif /* STD_TYPES_H_ */
