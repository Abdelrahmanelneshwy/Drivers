/*
 * main.c
 *
 *  Created on: Aug 21, 2022
 *      Author: Abdelrahman
 */

#include "switch_interface.h"

int main()
{
	 DIO_setPinDir(B, PIN0, input);
	 DIO_setPinDir(C,PIN2, output);
	 while(1)
	 {
		 if(check_switch(B, PIN0))
		 {
			_delay_ms(30);
			 if(check_switch(B, PIN0))
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
