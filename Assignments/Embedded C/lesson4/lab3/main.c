#include <stdio.h>
#include <stdint.h>
/*define register*/
#define STCTL_RCGC2_R     (*(volatile unsigned long*)(0x400FE000+0x108))
#define GPIO_PORTF_DATA_R (*(volatile unsigned long*)(0x40025000+0x3FC))
#define GPIO_PORTF_DIR_R  (*(volatile unsigned long*)(0x40025000+0x400))
#define GPIO_PORTF_DEN_R  (*(volatile unsigned long*)(0x40025000+0x51C))

int  main()
{
	volatile unsigned long delay_counter =0 ; /*to make sure that the compiler keep it */
	STCTL_RCGC2_R = 0x20; 	/* enable GPIO Port */
	for (delay_counter=0;delay_counter<20000;delay_counter++);

	// to make sure that  enable GPIO Port has started successfully 

	GPIO_PORTF_DIR_R  |=(1<<3);	/* set direction of portF Pin 3 =1 output */
	GPIO_PORTF_DEN_R  |=(1<<3); /* Enable GPIO Pin 3 =1 output */
	
	while(1) 
	{
	GPIO_PORTF_DATA_R |=(1<<3);
	for (delay_counter=0; delay_counter <2000 ; delay_counter);
    GPIO_PORTF_DATA_R &=~(1<<3);
	for (delay_counter=0; delay_counter <2000 ; delay_counter);
	}
	
	return 0;
}