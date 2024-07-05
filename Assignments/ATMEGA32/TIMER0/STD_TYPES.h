/************************************************************************
 *                                                                      *
 *************************  Date    : 30/12/2022      *******************
 *************************  Name    : Fady Emad		  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : STD TYPES       *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef STD_TYPES_H_ 

typedef unsigned char 	uint8_t;

typedef unsigned char* ptr_uint8_t;
typedef char* ptr_sint8_t;

typedef void(*ptr_VoidFunVoid_t) (void);
#define	NULL_PTR 			((void*)(0))

typedef unsigned char E_STATUS_t;
#define E_OK	(E_STATUS_t)(0)
#define E_NOK	(E_STATUS_t)(1)

#endif
