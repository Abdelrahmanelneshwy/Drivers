/*
 * main.c
 *
 *  Created on: Aug 26, 2022
 *      Author: abdelrahman
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"
#include "LED_interface.h"
#include "switch_interface.h"
#include <util/delay.h>

int main()
{
	LED_init(C,2);
	switch_init(B,0);
	int LED=0;
	while(1)
	{

		if(check_switch(B, 0))
		{
			if(check_switch(B, 0))
			{
				_delay_ms(30);
				if(LED==0)
				{
					LED_toggle(C,2);
					LED=1;
				}
			}

		}
		else
		{
			LED=0;
		}
	}
}
