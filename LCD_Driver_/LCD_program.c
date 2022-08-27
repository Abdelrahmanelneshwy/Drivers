/*
 * LCD_program.c
 *
 *  Created on: Aug 27, 2022
 *      Author: abdelrahman
 */
#include "LCD_interface.h"
#include "DIO_interface.h"
#include <util/delay.h>
void LCD_init()
{
	DIO_setPinDir(LCD_Ctr_Port, LCD_RS_PIN, output);
	DIO_setPinDir(LCD_Ctr_Port, LCD_RW_PIN, output);
	DIO_setPinDir(LCD_Ctr_Port, LCD_EN_PIN, output);

	DIO_setPinDir(LCD_Data_Port, Data_PIN0, output);
	DIO_setPinDir(LCD_Data_Port, Data_PIN1, output);
	DIO_setPinDir(LCD_Data_Port, Data_PIN2, output);
	DIO_setPinDir(LCD_Data_Port, Data_PIN3, output);

	_delay_ms(50);

	LCD_CMD(LCD_RETURN_HOME);
	LCD_CMD(LCD_4BIT_MODE_2LINES_5X7);
	_delay_ms(1);

	LCD_CMD(LCD_ON_CURSOR_OFF);
	_delay_ms(1);

	LCD_CMD(LCD_CLEAR_SCREEN);
	_delay_ms(20);

	LCD_CMD(LCD_SHIFT_CURSOR_RIGHT);
	LCD_CMD(LCD_SET_CURSOR_1LINE);
}

void LCD_CMD(u8 CMD)
{
	/***************active LCD to take command**************/
	DIO_setPinval(LCD_Ctr_Port, LCD_RS_PIN, LOW);
	DIO_setPinval(LCD_Ctr_Port, LCD_RW_PIN, LOW);
	/**************higher bits command**************/
	PORTA=(PORTA & 0x0f)|(CMD & 0xf0);
	LCD_ENABLE();
	/**************lower bits command**************/
	PORTA=(PORTA & 0x0f)|(CMD << 4);
	LCD_ENABLE();
	_delay_ms(2);
}

void LCD_Data(u8 Data)
{
	/***************active LCD to take Data**************/
		DIO_setPinval(LCD_Ctr_Port, LCD_RS_PIN, HIGH);
		DIO_setPinval(LCD_Ctr_Port, LCD_RW_PIN, LOW);
		/**************higher bits data**************/
		PORTA=(PORTA & 0x0f)|(Data & 0xf0);
		LCD_ENABLE();
		/**************lower bits data**************/
		PORTA=(PORTA & 0x0f)|(Data << 4);
		LCD_ENABLE();
		_delay_ms(2);
}

void LCD_CLEAR()
{
 LCD_CMD(LCD_CLEAR_SCREEN);
 _delay_ms(20);
}

void LCD_ENABLE()
{
	DIO_setPinval(LCD_Ctr_Port, LCD_EN_PIN, HIGH);
	_delay_ms(2);
	DIO_setPinval(LCD_Ctr_Port, LCD_EN_PIN, LOW);
	_delay_ms(2);
}
