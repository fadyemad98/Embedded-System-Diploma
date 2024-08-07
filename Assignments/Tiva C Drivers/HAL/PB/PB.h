/*
 * PB.h
 *
 *  Created on: Jul 24, 2024
 *      Author: fadye
 */

#ifndef PB_PB_H_
#define PB_PB_H_
#include "std_types.h"

void PB_init(uint8 port, uint8 pin);

uint8 read_PB(uint8 port, uint8 pin);

#endif /* PB_PB_H_ */
