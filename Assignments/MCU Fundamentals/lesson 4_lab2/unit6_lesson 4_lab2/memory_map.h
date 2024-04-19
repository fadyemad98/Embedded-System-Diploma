/*
 * memory_map.h
 *
 * Created: 4/19/2024 7:25:43 PM
 *  Author: fadye
 */ 


#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_

//PORTA
#define PORTA   (*(volatile unsigned char *)(0x3B))
#define DDRA   (*(volatile unsigned char *)(0x3A))
#define PINA   (*(volatile unsigned char *)(0x30))

//PORTB
#define PORTB   (*(volatile unsigned char *)(0x38))
#define DDRB   (*(volatile unsigned char *)(0x37))
#define PINB   (*(volatile unsigned char *)(0x36))

//PORTC
#define PORTC   (*(volatile unsigned char *)(0x35))
#define DDRC   (*(volatile unsigned char *)(0x34))
#define PINC   (*(volatile unsigned char *)(0x33))

//PORTD
#define PORTD   (*(volatile unsigned char *)(0x32))
#define DDRD   (*(volatile unsigned char *)(0x31))
#define PIND   (*(volatile unsigned char *)(0x30))


//INT 

#define MCUCR (*(volatile unsigned char *)(0x55))
#define MCUCSR (*(volatile unsigned char *)(0x54))
#define GICR (*(volatile unsigned char *)(0x5B))
#define GIFR (*(volatile unsigned char *)(0x5A))
#define SREG (*(volatile unsigned char *)(0x5F))

enum E_MCUCR{
	ISC00,
	ISC01,
	ISC10,
	ISC11,
	ISC2 = 6
	}E__MCUCR;
	
	
	
#endif /* MEMORY_MAP_H_ */