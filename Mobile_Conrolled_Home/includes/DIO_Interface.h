/*
 * DIO_Interface.h
 *
 *  Created on: Jun 19, 2024
 *      Author: dell
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define PORTA      0
#define PORTB      1
#define PORTC      2
#define PORTD      3

#define PIN0       0
#define PIN1       1
#define PIN2       2
#define PIN3       3
#define PIN4       4
#define PIN5       5
#define PIN6       6
#define PIN7       7

#define INPUT      0
#define OUTPUT     1

#define LOW        0
#define HIGH       1



u8 DIO_u8SetPinDirection(u8 A_u8PortID, u8 A_u8PinID , u8 A_u8PinDirection );
u8 DIO_u8SetPinValue(u8 A_u8PortID , u8 A_u8PinID , u8 A_u8PinValue );
u8 DIO_u8GetPinValue(u8 A_u8PortID , u8 A_u8PinID , u8 * AP_u8PinValuePointer );
u8 DIO_u8SetPortDirection(u8 A_u8PortID , u8 A_u8PortDirection );
u8 DIO_u8SetPortValue(u8 A_u8PortID ,  u8 A_u8PortValue );
u8 DIO_u8GetPortValue(u8 A_u8PortID , u8 * AP_u8PortValuePointer );




#endif /* DIO_INTERFACE_H_ */
