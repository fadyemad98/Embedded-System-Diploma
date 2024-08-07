/**********************************************************************
[FILE NAME]: <DIO_Program.c>
Author : Abdelrhman El Kheshen
Version: V0
Description: Program Source file for the DIO Driver.
Date Created: 28/04/2024
Micro-Controller: TM4C123GH6PM (TIVA C)
Micro-Processor: ARM Cortex-M4
***********************************************************************/
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "Common_Macros.h"

/******Easy Techniques******/
void  DIO_Start(uint8 port)
{
    if(port >= MAX_PORTS)
    {
      //  #error "Invalid Port Number"
    }
    else
    {
        SET_BIT(GPIO_RCGC_CLOCK_REGISTER,port);  /*Enable Clock For The Selected GPIO Port*/
        while(!(GET_BIT(GPIO_RCGC2_CLOCK_REGISTER,port)));
    }
}

void  DIO_writePin(uint8 Port,uint8 pin,uint8 level)
{
    /*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin >= MAX_PINS) || (Port >= MAX_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the pin value as required */
		switch(Port)
		{
		case PORTA_ID:
			if(level == LOGIC_HIGH)
			{
		        SET_BIT(GPIOA_DATA_REGISTER_APB,pin);
		    }
		    else
		    {
		        CLEAR_BIT(GPIOA_DATA_REGISTER_APB,pin);
		    }
			break;
		case PORTB_ID:
			if(level == LOGIC_HIGH)
			{
		        SET_BIT(GPIOB_DATA_REGISTER_APB,pin);
		    }
		    else
		    {
		        CLEAR_BIT(GPIOB_DATA_REGISTER_APB,pin);
		    }
			break;
		case PORTC_ID:
			if(level == LOGIC_HIGH)
			{
		        SET_BIT(GPIOC_DATA_REGISTER_APB,pin);
		    }
		    else
		    {
		        CLEAR_BIT(GPIOC_DATA_REGISTER_APB,pin);
		    }
			break;
		case PORTD_ID:
			if(level == LOGIC_HIGH)
			{
		        SET_BIT(GPIOD_DATA_REGISTER_APB,pin);
		    }
		    else
		    {
		        CLEAR_BIT(GPIOD_DATA_REGISTER_APB,pin);
		    }
			break;
        case PORTE_ID:
           if(level == LOGIC_HIGH)
			{
		        SET_BIT(GPIOE_DATA_REGISTER_APB,pin);
		    }
		    else
		    {
		        CLEAR_BIT(GPIOE_DATA_REGISTER_APB,pin);
		    }
            break;
        case PORTF_ID:
            if(level == LOGIC_HIGH)
			{
		        SET_BIT(GPIOF_DATA_REGISTER_APB,pin);
		    }
		    else
		    {
		        CLEAR_BIT(GPIOF_DATA_REGISTER_APB,pin);
		    }
            break;
		}
	}
}


uint8 DIO_readPin(uint8 Port,uint8 pin)
{
    uint8 pinValue = LOGIC_LOW;
    /*
	* Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	* Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	* In this case the input is not valid port/pin number
	*/
    if((pin >= MAX_PINS) || (Port >= MAX_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
       	/* Read the pin value as required */
		switch(Port)
		{
		case PORTA_ID:
            pinValue = GET_BIT(GPIOA_DATA_REGISTER_APB,pin);
			break;
		case PORTB_ID:
			pinValue = GET_BIT(GPIOB_DATA_REGISTER_APB,pin);
			break;
		case PORTC_ID:
			pinValue = GET_BIT(GPIOC_DATA_REGISTER_APB,pin);
			break;
		case PORTD_ID:
			pinValue = GET_BIT(GPIOD_DATA_REGISTER_APB,pin);
			break;
        case PORTE_ID:
            pinValue = GET_BIT(GPIOE_DATA_REGISTER_APB,pin);
            break;
        case PORTF_ID:
            pinValue = GET_BIT(GPIOF_DATA_REGISTER_APB,pin);
            break;
        default:
            break;
		}
	}
	return pinValue;
}    

void  DIO_setPinDirection(uint8 port,uint8 pin,uint8 direction)
{
    /*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin >= MAX_PINS) || (port >= MAX_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		switch(port)
		{
		case PORTA_ID:
			if(direction == PIN_OUTPUT)
			{
                CLEAR_BIT(GPIOA_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                GPIOA_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                SET_BIT(GPIOA_DIR_REGISTER_APB,pin);  /* Configure Pin as output pin */
                CLEAR_BIT(GPIOA_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */
                SET_BIT(GPIOA_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
                CLEAR_BIT(GPIOA_DATA_REGISTER_APB,pin);      /* Clear pin in Data regsiter to put zero in initial position */
			}
			else
			{
                CLEAR_BIT(GPIOA_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                GPIOA_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                CLEAR_BIT(GPIOA_DIR_REGISTER_APB,pin);  /* Configure Pin as input pin */
                CLEAR_BIT(GPIOA_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */ 
                SET_BIT(GPIOA_PUR_REGISTER_APB,pin);      /* Enable pull-up on Pin */
                SET_BIT(GPIOA_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
                if(PUR_PDR == PDR_Activate || PUR_Activate){
                	switch (PUR_PDR) {
						case PUR_Activate:

							break;
						case PDR_Activate:

							break;
						default:
							break;
					}
                }
                else{

                }
			}
			break;
		case PORTB_ID:
            if(direction == PIN_OUTPUT)
			{
                CLEAR_BIT(GPIOB_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                GPIOB_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                SET_BIT(GPIOB_DIR_REGISTER_APB,pin);  /* Configure Pin as output pin */
                CLEAR_BIT(GPIOB_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */
                SET_BIT(GPIOB_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
                CLEAR_BIT(GPIOB_DATA_REGISTER_APB,pin);      /* Clear pin in Data regsiter to put zero in initial position */
			}
			else
			{
                CLEAR_BIT(GPIOB_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                GPIOB_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                CLEAR_BIT(GPIOB_DIR_REGISTER_APB,pin);  /* Configure Pin as input pin */
                CLEAR_BIT(GPIOB_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */ 
                SET_BIT(GPIOB_PUR_REGISTER_APB,pin);      /* Enable pull-up on Pin */
                SET_BIT(GPIOB_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
			}
            break;
		case PORTC_ID:
            if(direction == PIN_OUTPUT)
			{
                if((pin == PIN0) || (pin == PIN1) || (pin == PIN2) || (pin == PIN3))
                {
                    GPIOC_LOCK_REGISTER_APB = 0x4C4F434B;
                    SET_BIT(GPIOC_CR_REGISTER_APB,pin);
                    CLEAR_BIT(GPIOC_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                    GPIOC_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                    SET_BIT(GPIOC_DIR_REGISTER_APB,pin);  /* Configure Pin as output pin */
                    CLEAR_BIT(GPIOC_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */
                    SET_BIT(GPIOC_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
                    CLEAR_BIT(GPIOC_DATA_REGISTER_APB,pin);      /* Clear pin in Data regsiter to put zero in initial position */
                }
                else
                {
                    CLEAR_BIT(GPIOC_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                    GPIOC_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                    SET_BIT(GPIOC_DIR_REGISTER_APB,pin);  /* Configure Pin as output pin */
                    CLEAR_BIT(GPIOC_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */
                    SET_BIT(GPIOC_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
                    CLEAR_BIT(GPIOC_DATA_REGISTER_APB,pin);      /* Clear pin in Data regsiter to put zero in initial position */
                }   
			}
			else
			{
                if((pin == PIN0) || (pin == PIN1) || (pin == PIN2) || (pin == PIN3))
                {
                    GPIOC_LOCK_REGISTER_APB = 0x4C4F434B;
                    SET_BIT(GPIOC_CR_REGISTER_APB,pin);
                    CLEAR_BIT(GPIOC_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                    GPIOC_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                    CLEAR_BIT(GPIOC_DIR_REGISTER_APB,pin);  /* Configure Pin as input pin */
                    CLEAR_BIT(GPIOC_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */ 
                    SET_BIT(GPIOC_PUR_REGISTER_APB,pin);      /* Enable pull-up on Pin */
                    SET_BIT(GPIOC_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
                }
                else
                {
                    CLEAR_BIT(GPIOC_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                    GPIOC_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                    SET_BIT(GPIOC_DIR_REGISTER_APB,pin);  /* Configure Pin as output pin */
                    CLEAR_BIT(GPIOC_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */
                    SET_BIT(GPIOC_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
                    CLEAR_BIT(GPIOC_DATA_REGISTER_APB,pin);      /* Clear pin in Data regsiter to put zero in initial position */
                }   
            }           
            break;
		case PORTD_ID:
            if(direction == PIN_OUTPUT)
			{
                if(pin == PIN7)
                {
                    GPIOD_LOCK_REGISTER_APB = 0x4C4F434B;
                    SET_BIT(GPIOD_CR_REGISTER_APB,pin);
                    CLEAR_BIT(GPIOD_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                    GPIOD_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                    SET_BIT(GPIOD_DIR_REGISTER_APB,pin);  /* Configure Pin as output pin */
                    CLEAR_BIT(GPIOD_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */
                    SET_BIT(GPIOD_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
                    CLEAR_BIT(GPIOD_DATA_REGISTER_APB,pin);      /* Clear pin in Data regsiter to put zero in initial position */
                }
                else
                {
                    CLEAR_BIT(GPIOD_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                    GPIOD_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                    SET_BIT(GPIOD_DIR_REGISTER_APB,pin);  /* Configure Pin as output pin */
                    CLEAR_BIT(GPIOD_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */
                    SET_BIT(GPIOD_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
                    CLEAR_BIT(GPIOD_DATA_REGISTER_APB,pin);      /* Clear pin in Data regsiter to put zero in initial position */
                }
			}
			else
			{
                if(pin == PIN7)
                {
                    GPIOD_LOCK_REGISTER_APB = 0x4C4F434B;
                    SET_BIT(GPIOD_CR_REGISTER_APB,pin);
                    CLEAR_BIT(GPIOD_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                    GPIOD_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                    CLEAR_BIT(GPIOD_DIR_REGISTER_APB,pin);  /* Configure Pin as input pin */
                    CLEAR_BIT(GPIOD_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */ 
                    SET_BIT(GPIOD_PUR_REGISTER_APB,pin);      /* Enable pull-up on Pin */
                    SET_BIT(GPIOD_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
                }
                else
                {
                    CLEAR_BIT(GPIOD_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                    GPIOD_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                    CLEAR_BIT(GPIOD_DIR_REGISTER_APB,pin);  /* Configure Pin as input pin */
                    CLEAR_BIT(GPIOD_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */ 
                    SET_BIT(GPIOD_PUR_REGISTER_APB,pin);      /* Enable pull-up on Pin */
                    SET_BIT(GPIOD_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
                }
			}           
            break;
        case PORTE_ID:
            if(direction == PIN_OUTPUT)
			{
                CLEAR_BIT(GPIOE_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                GPIOE_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                SET_BIT(GPIOE_DIR_REGISTER_APB,pin);  /* Configure Pin as output pin */
                CLEAR_BIT(GPIOE_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */
                SET_BIT(GPIOE_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
                CLEAR_BIT(GPIOE_DATA_REGISTER_APB,pin);      /* Clear pin in Data regsiter to put zero in initial position */
			}
			else
			{
                CLEAR_BIT(GPIOE_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                GPIOE_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                CLEAR_BIT(GPIOE_DIR_REGISTER_APB,pin);  /* Configure Pin as input pin */
                CLEAR_BIT(GPIOE_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */ 
                SET_BIT(GPIOE_PUR_REGISTER_APB,pin);      /* Enable pull-up on Pin */
                SET_BIT(GPIOE_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
			}           
            break;
        case PORTF_ID:
            if(direction == PIN_OUTPUT)
			{
                if(pin == PIN0)
                {
                    GPIOF_LOCK_REGISTER_APB = 0x4C4F434B;
                    SET_BIT(GPIOF_CR_REGISTER_APB,pin);
                    CLEAR_BIT(GPIOF_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                    GPIOF_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                    SET_BIT(GPIOF_DIR_REGISTER_APB,pin);  /* Configure Pin as output pin */
                    CLEAR_BIT(GPIOF_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */
                    SET_BIT(GPIOF_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
                    CLEAR_BIT(GPIOF_DATA_REGISTER_APB,pin);      /* Clear pin in Data regsiter to put zero in initial position */
                }
                else
                {
                    CLEAR_BIT(GPIOF_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                    GPIOF_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                    SET_BIT(GPIOF_DIR_REGISTER_APB,pin);  /* Configure Pin as output pin */
                    CLEAR_BIT(GPIOF_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */
                    SET_BIT(GPIOF_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
                    CLEAR_BIT(GPIOF_DATA_REGISTER_APB,pin);      /* Clear pin in Data regsiter to put zero in initial position */
                }
			}
			else
			{
                if(pin == PIN7)
                {
                    GPIOF_LOCK_REGISTER_APB = 0x4C4F434B;
                    SET_BIT(GPIOF_CR_REGISTER_APB,pin);
                    CLEAR_BIT(GPIOF_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                    GPIOF_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                    CLEAR_BIT(GPIOF_DIR_REGISTER_APB,pin);  /* Configure Pin as input pin */
                    CLEAR_BIT(GPIOF_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */ 
                    SET_BIT(GPIOF_PUR_REGISTER_APB,pin);      /* Enable pull-up on Pin */
                    SET_BIT(GPIOF_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
                }
                else
                {
                    CLEAR_BIT(GPIOF_AMSEL_REGISTER_APB,pin);      /* Disable Analog on Pin */
                    GPIOF_PCTL_REGISTER_APB  &= ~(0x0000000F << (pin * 4));   /* Clear PMCx bits for Pin to use it as GPIO pin */
                    CLEAR_BIT(GPIOF_DIR_REGISTER_APB,pin);  /* Configure Pin as input pin */
                    CLEAR_BIT(GPIOF_AFSEL_REGISTER_APB,pin); /* Disable alternative function on Pin */ 
                    SET_BIT(GPIOF_PUR_REGISTER_APB,pin);      /* Enable pull-up on Pin */
                    SET_BIT(GPIOF_DEN_REGISTER_APB,pin);       /* Enable Digital I/O on Pin */
                }
			}           
            break;
            default:
            break;
		}
	}
}

uint8 DIO_readPort(uint8 port)
{
    uint8 portValue = 0;
    if(port >= MAX_PORTS)
    {
        /*DO NOTHING*/
    }
    else
    {
        switch(port)
        {
            case PORTA_ID:
            portValue = GPIOA_DATA_REGISTER_APB;
            break;
            case PORTB_ID:
            portValue = GPIOB_DATA_REGISTER_APB;
            break;
            case PORTC_ID:
            portValue = GPIOC_DATA_REGISTER_APB;
            break;
            case PORTD_ID:
            portValue = GPIOD_DATA_REGISTER_APB;
            break;
            case PORTE_ID:
            portValue = GPIOE_DATA_REGISTER_APB;
            break;
            case PORTF_ID:
            portValue = GPIOF_DATA_REGISTER_APB;
            break;
            default:
            break;
        }
    }
    return portValue;
}  


void DIO_writePort(uint8 port,uint8 value)
{
    if(port >= MAX_PORTS)
    {
        /*Do Nothing*/
    }
    else
    {
        switch(port)
        {
            case PORTA_ID:
            GPIOA_DATA_REGISTER_APB = value;
            break;
            case PORTB_ID:
            GPIOB_DATA_REGISTER_APB = value;
            break;
            case PORTC_ID:
            GPIOC_DATA_REGISTER_APB = value;
            break;
            case PORTD_ID:
            GPIOD_DATA_REGISTER_APB = value;
            break;
            case PORTE_ID:
            GPIOE_DATA_REGISTER_APB = value;
            break;
            case PORTF_ID:
            GPIOF_DATA_REGISTER_APB = value;
            break;
            default:
            break;
        }
    }
}

void DIO_PUR(uint8 Port,uint8 pin){

}
void DIO_PDR(uint8 Port,uint8 pin){

}







/******Advanced Techniques******/

static const DIO_Channel* Dio_PortChannels = NULL_PTR; /* pointer to configuration structure */
void  DIOInit(const DIO_Configurations* ConfigPtr)
{
    if (NULL_PTR == ConfigPtr)
	{
		//#error("Error in COnfigurations")
	}
	else
	{
		/*
		 * Set the module state to initialized and point to the PB configuration structure using a global pointer.
		 * This global pointer is global to be used by other functions to read the PB configuration structures
		 */
		Dio_PortChannels = ConfigPtr->Channels; /* address of the first Channels structure --> Channels[0] */
	}
}


void  DIO_writeChannel(uint8 index,uint8 level)
{
    volatile unsigned long* portPtr = NULL_PTR;
    if (DIO_CONFIGURED_CHANNELS <= index)
	{
        //#error("Error in array of configurations")
	}
    else
    {
        switch(Dio_PortChannels[index].port)
        {
            case PORTA_ID:
            portPtr = (volatile unsigned long*)(GPIOA_BASE_ADDRESS_APB);
            break;
            case PORTB_ID:
            portPtr = (volatile unsigned long*)(GPIOB_BASE_ADDRESS_APB);
            break;
            case PORTC_ID:
            portPtr = (volatile unsigned long*)(GPIOC_BASE_ADDRESS_APB);
            break;
            case PORTD_ID:
            portPtr = (volatile unsigned long*)(GPIOD_BASE_ADDRESS_APB);
            break;
            case PORTE_ID:
            portPtr = (volatile unsigned long*)(GPIOE_BASE_ADDRESS_APB);
            break;
            case PORTF_ID:
            portPtr = (volatile unsigned long*)(GPIOF_BASE_ADDRESS_APB);
            break;
            default:
            break;
        }
        if(level == LOGIC_HIGH)
        {
            SET_BIT(*(volatile unsigned long*)((volatile uint8 *)portPtr + GPIO_DATA_REG_OFFSET),Dio_PortChannels[index].channel);
        }
        else if(level == LOGIC_LOW)
        {
            CLEAR_BIT(*(volatile unsigned long*)((volatile uint8 *)portPtr + GPIO_DATA_REG_OFFSET),Dio_PortChannels[index].channel);
        }   
    }
}

uint8 DIO_readChannel(uint8 index)
{
    volatile unsigned long* portPtr = NULL_PTR;
    uint8 channelValue = LOGIC_LOW;
    if (DIO_CONFIGURED_CHANNELS <= index)
	{
        //#error("Error in array of configurations")
	}
    else
    {
        switch(Dio_PortChannels[index].port)
        {
            case PORTA_ID:
            portPtr = (volatile unsigned long*)(GPIOA_BASE_ADDRESS_APB);
            break;
            case PORTB_ID:
            portPtr = (volatile unsigned long*)(GPIOB_BASE_ADDRESS_APB);
            break;
            case PORTC_ID:
            portPtr = (volatile unsigned long*)(GPIOC_BASE_ADDRESS_APB);
            break;
            case PORTD_ID:
            portPtr = (volatile unsigned long*)(GPIOD_BASE_ADDRESS_APB);
            break;
            case PORTE_ID:
            portPtr = (volatile unsigned long*)(GPIOE_BASE_ADDRESS_APB);
            break;
            case PORTF_ID:
            portPtr = (volatile unsigned long*)(GPIOF_BASE_ADDRESS_APB);
            break;
            default:
            break;
        }
        channelValue = GET_BIT(*(volatile unsigned long*)((volatile uint8 *)portPtr + GPIO_DATA_REG_OFFSET),Dio_PortChannels[index].channel);    
    }
    return channelValue;    
}
