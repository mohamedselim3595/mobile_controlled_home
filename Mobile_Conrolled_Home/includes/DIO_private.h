/*
 * DIO_private.h
 *
 *  Created on: Jun 19, 2024
 *      Author: dell
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


#define InitErrState         0
#define PortIDErrState       1
#define PinIDErrState        2
#define PinDirErrState       3
#define PinValErrState       4
#define PortDirErrState      5
#define PortValErrState      6
#define SuccessErrState      7


#define MinPortID            0
#define MaxPortID            3

#define MinPinID             0
#define MaxPinID             7

#define MinPortDirection     0b00000000
#define MaxPortDirection     0b11111111

#define MinPortValue         0b00000000
#define MaxPortValue         0b11111111




#define DIO_u8DDRA 		*((volatile u8 *)0x3A)
#define DIO_u8DDRB 		*((volatile u8 *)0x37)
#define DIO_u8DDRC 		*((volatile u8 *)0x34)
#define DIO_u8DDRD 		*((volatile u8 *)0x31)

#define DIO_u8PORTA		*((volatile u8 *)0x3B)
#define DIO_u8PORTB 	*((volatile u8 *)0x38)
#define DIO_u8PORTC 	*((volatile u8 *)0x35)
#define DIO_u8PORTD 	*((volatile u8 *)0x32)

#define DIO_u8PINA 		*((volatile u8 *)0x39)
#define DIO_u8PINB      *((volatile u8 *)0x36)
#define DIO_u8PINC      *((volatile u8 *)0x33)
#define DIO_u8PIND      *((volatile u8 *)0x30)





#endif /* DIO_PRIVATE_H_ */
