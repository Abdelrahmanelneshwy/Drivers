/*
 * main.c
 *
 *  Created on: Aug 20, 2022
 *      Author: abdelrahman
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"
#include <util/delay.h>
int main()
{

 DIO_setPinDir(B, PIN0, input);
 DIO_setPinDir(C,PIN2, output);
 while(1)
 {
	 if(DIO_getPinval(B, PIN0)==HIGH)
	 {
		_delay_ms(30);
		 if(DIO_getPinval(B, PIN0)==HIGH)
		 {
		 DIO_setPinval(C,PIN2, HIGH);
		 }
	 }
	 else
	 {
		 DIO_setPinval(C,PIN2,LOW);
	 }
 }
}
