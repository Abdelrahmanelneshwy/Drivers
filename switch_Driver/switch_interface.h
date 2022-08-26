/*
 * switch_interface.h
 *
 *  Created on: Aug 21, 2022
 *      Author: Abdelrahman
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"
#include <util/delay.h>

/**************check value on pin***************/
u8 check_switch(u8 PORTID,u8 PINID);

#endif /* SWITCH_INTERFACE_H_ */
