/*
 * main.c
 *
 *  Created on: Aug 21, 2022
 *      Author: Abdelrahman
 */

#include "LED_interface.h"
int main()
{
	LED_init(C,PIN2);
	LED_init(C,PIN7);
	LED_init(D,PIN3);
	while(1)
	{
		LED_toggle(C,PIN2,500);
		_delay_ms(1000);
		LED_toggle(C,PIN7,500);
		_delay_ms(1000);
		LED_toggle(D,PIN3,500);
		_delay_ms(1000);
	}
}

