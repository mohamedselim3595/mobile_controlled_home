/*
 * UART_Interface.h
 *
 *  Created on: Jul 13, 2024
 *      Author: dell
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit( void );
void UART_voidSendByte( u8 data);
u8 UART_voidReceiveByte( void );
void UART_voidSendString(u8 *str);
void UART_Flush( void );

#endif /* UART_INTERFACE_H_ */
