/*
 * Buzzer_program.c
 *
 *  Created on: Sep 3, 2022
 *      Author: Abdelrahman
 */
#include "Buzzer_interface.h"

void BUZ_init(u8 PORTID,u8 PINID)
{
	DIO_setPinDir(PORTID,PINID,output);
}

void BUZ_on(u8 PORTID,u8 PINID)
{
	DIO_setPinval(PORTID,PINID,HIGH);
}

void BUZ_off(u8 PORTID,u8 PINID)
{
	DIO_setPinval(PORTID,PINID,LOW);
}
