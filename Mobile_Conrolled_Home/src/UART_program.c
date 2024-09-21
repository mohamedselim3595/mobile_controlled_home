/*
 * UART_program.c
 *
 *  Created on: Jul 13, 2024
 *      Author: dell
 */


#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Calc.h"

#include <util/delay.h>

#include "DIO_Interface.h"
#include "UART_Config.h"

#include "UART_Interface.h"
#include "UART_Private.h"



void UART_voidInit()
{
	/* Set baud rate */

	UART_UBRRH = 0b00000000;

	UART_UBRRL = 51;

	/* Enable receiver and transmitter */

	UART_UCSRB = 0b00011000;

	/* Set frame format: 8data, 2stop bit */

	UART_UCSRC = 0b10000110;
}


void UART_voidSendByte( u8 data ){

	/* Wait for empty transmit buffer */
	while ( !( UART_UCSRA & (1<<5)) )
		;
	/* Put data into buffer, sends the data */
	UART_UDR = data;
}


u8 UART_voidReceiveByte( void )
{
	/* Wait for data to be received */
	while ( !(UART_UCSRA & (1<<7)) );
	/* Get and return received data from buffer */
	return UART_UDR;
}


void UART_voidSendString(u8 *str)
{
	u8 i = 0;
	while(str[i] != '\0')
	{
		UART_voidSendByte(str[i]);
		i++;
	}
}

void UART_Flush( void ){

	u8 dummy;
	while ( UART_UCSRA & (1<<7) )
		dummy = UART_UDR;
}
