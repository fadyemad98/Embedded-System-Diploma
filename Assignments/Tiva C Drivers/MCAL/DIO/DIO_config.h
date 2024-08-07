/**********************************************************************
[FILE NAME]: <DIO_config.h>
Author : Abdelrhman El Kheshen
Version: V0
Description: Configuration Header file for the DIO Driver.
Date Created: 28/04/2024
Micro-Controller: TM4C123GH6PM (TIVA C)
Micro-Processor: ARM Cortex-M4
***********************************************************************/
#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_
#include "std_types.h"

#define DIO_CONFIGURED_CHANNELS                ((uint8)3)

#define DIO_CONF_LED1_CHANNEL_ID_INDEX         ((uint8)0x00)
#define DIO_CONF_LED2_CHANNEL_ID_INDEX         ((uint8)0x01)
#define DIO_CONF_LED3_CHANNEL_ID_INDEX         ((uint8)0x02)


#endif