/*
 * SSD.h
 *
 *  Created on: Jul 24, 2024
 *      Author: fadye
 */

#ifndef SSD_SSD_H_
#define SSD_SSD_H_

#include "DIO_Interface.h"






void SSD_init(GPIO_PORT_t port);
void SSD_Write(uint8 Value,GPIO_PORT_t port);


#endif /* SSD_SSD_H_ */
