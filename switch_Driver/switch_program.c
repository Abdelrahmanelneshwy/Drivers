/*
 * switch_program.c
 *
 *  Created on: Aug 21, 2022
 *      Author: Abdelrahman
 */

#include "switch_interface.h"

/**************check value on pin***************/
u8 check_switch(u8 PORTID,u8 PINID)
{
	return DIO_getPinval(PORTID,PINID);
}
