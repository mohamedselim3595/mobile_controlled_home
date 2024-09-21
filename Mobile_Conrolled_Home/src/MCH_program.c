/*
 * MCH_program.c
 *
 *  Created on: Jul 25, 2024
 *      Author: dell
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Calc.h"
#include <util/delay.h>

#include "DIO_Interface.h"
#include "DIO_private.h"

#include "MCH_config.h"
#include "MCH_interface.h"
#include "MCH_private.h"

#include "UART_Private.h"
#include "UART_Interface.h"


void MCH_voidINIT(void){

	DIO_u8SetPinDirection( LED_PORT, LED_PIN, OUTPUT);

	DIO_u8SetPinDirection( DoorLock_PORT, DoorLock_PIN1, OUTPUT);

	DIO_u8SetPinDirection( DoorLock_PORT, DoorLock_PIN2, OUTPUT);

	DIO_u8SetPinDirection( SIREN_PORT, SIREN_PIN, OUTPUT);

}


void MCH_VoidOpenLock(void){

	DIO_u8SetPinValue( DoorLock_PORT , DoorLock_PIN1 , HIGH);

	DIO_u8SetPinValue( DoorLock_PORT , DoorLock_PIN2 , LOW);

	_delay_ms(2000);

	DIO_u8SetPinValue( DoorLock_PORT , DoorLock_PIN1 , LOW);

	_delay_ms(2000);


}


void MCH_VoidCloseLock(void){

	DIO_u8SetPinValue( DoorLock_PORT , DoorLock_PIN2 , HIGH);

	DIO_u8SetPinValue( DoorLock_PORT , DoorLock_PIN1 , LOW);

	_delay_ms(2000);

	DIO_u8SetPinValue( DoorLock_PORT , DoorLock_PIN2 , LOW);


}

void MCH_VoidTurnOnLED(void){

	DIO_u8SetPinValue( LED_PORT , LED_PIN , HIGH);

}

void MCH_VoidTurnOffLED(void){

	DIO_u8SetPinValue( LED_PORT , LED_PIN , LOW);

}

void MCH_VoidSirenOn(void){

	for(u8 i ; i < 5; i++){
		DIO_u8SetPinValue( SIREN_PORT , SIREN_PIN , HIGH);
		_delay_ms(1000);
		DIO_u8SetPinValue( SIREN_PORT , SIREN_PIN , LOW);
		_delay_ms(1000);
	}

	DIO_u8SetPinValue( SIREN_PORT , SIREN_PIN , LOW);

}

