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


void seven_segment_mapping(u8 num);


int main()
{
	DIO_setPinDir(B, 1, output);
	DIO_setPinval(B, 1, HIGH);
	DIO_setPortDir(A,output);
	//switch_init(B,0);
	//u8 count=0;
	//u8 flag=0;
	while(1)
	{
		PORTA=0x05;
		/*if(check_switch(B, 0))
		{
			_delay_ms(30);
			if(check_switch(B, 0))
			{
				if(flag==0)
				{
					seven_segment_mapping(count);
					count++;
					if(count>9)
					{
						count=0;
					}
					flag=1;
					_delay_ms(100);
				}
				else
				{
					flag=0;
				}
			}
		}*/
	}
}

void seven_segment_mapping(u8 num)
{
	PORTA=(PORTA&0x0f)|(num<<4);
}

