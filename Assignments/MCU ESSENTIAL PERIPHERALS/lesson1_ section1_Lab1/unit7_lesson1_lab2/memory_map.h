/*
 * memory_map.h
 *
 * Created: 4/14/2024 1:24:32 PM
 *  Author: fadye
 */ 


#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_
//GPIO_MEMORY_MAP

//PORTA
#define PORTA   (*(volatile unsigned char *)(0x3B))
#define DDRA   (*(volatile unsigned char *)(0x3A))
#define PINA   (*(volatile unsigned char *)(0x30))

//PORTD
#define PORTD   (*(volatile unsigned char *)(0x32))
#define DDRD   (*(volatile unsigned char *)(0x31))
#define PIND   (*(volatile unsigned char *)(0x30))




#endif /* MEMORY_MAP_H_ */