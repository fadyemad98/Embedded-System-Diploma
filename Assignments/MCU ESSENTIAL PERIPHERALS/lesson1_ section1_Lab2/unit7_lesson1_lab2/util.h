/*
 * util.h
 *
 * Created: 4/15/2024 12:52:25 PM
 *  Author: fadye
 */ 


#ifndef UTIL_H_
#define UTIL_H_

#define SetBit(REG,BIT)		(REG|= (1<<BIT))
#define ClearBit(REG,BIT)	(REG &= ~(1<<BIT))
#define ToggleBit(REG,BIT)	(REG ^= (1<<BIT))
#define ReadBit(REG,BIT)	((REG>>BIT)&1)


#endif /* UTIL_H_ */