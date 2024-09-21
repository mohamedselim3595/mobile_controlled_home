/*
 * program.c
 *
 *  Created on: Jun 19, 2024
 *      Author: dell
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Calc.h"


#include "DIO_Interface.h"
#include "DIO_private.h"
#include "DIO_Config.h"


u8 DIO_u8SetPinDirection(u8 A_u8PortID , u8 A_u8PinID , u8 A_u8Direction){

		u8 L_u8Status = InitErrState;

		if( (A_u8PortID < MinPortID) || (A_u8PortID > MaxPortID) ){

			/* Wrong Port */
			L_u8Status = PortIDErrState;

		} else if( (A_u8PinID < MinPinID) || (A_u8PinID > MaxPinID) ) {

			/* Wrong Pin */
			L_u8Status = PinIDErrState;

		} else if( (A_u8Direction != INPUT) && (A_u8Direction != OUTPUT)  ){

			/* Wrong Direction */
			L_u8Status = PinDirErrState;
		} else{

			switch(A_u8PortID){

			case PORTA:
				if(A_u8Direction == INPUT)  Clr_Bit(DIO_u8DDRA,A_u8PinID);
				if(A_u8Direction == OUTPUT) Set_Bit(DIO_u8DDRA,A_u8PinID);
				break;

			case PORTB:
				if(A_u8Direction == INPUT)  Clr_Bit(DIO_u8DDRB,A_u8PinID);
				if(A_u8Direction == OUTPUT) Set_Bit(DIO_u8DDRB,A_u8PinID);
				break;

			case PORTC:
				if(A_u8Direction == INPUT)  Clr_Bit(DIO_u8DDRC,A_u8PinID);
				if(A_u8Direction == OUTPUT) Set_Bit(DIO_u8DDRC,A_u8PinID);
				break;

			case PORTD:
				if(A_u8Direction == INPUT)  Clr_Bit(DIO_u8DDRD,A_u8PinID);
				if(A_u8Direction == OUTPUT) Set_Bit(DIO_u8DDRD,A_u8PinID);
				break;
		}

			L_u8Status = SuccessErrState;
	}

		return L_u8Status;
}

u8 DIO_u8SetPinValue(u8 A_u8PortID , u8 A_u8PinID , u8 A_u8Value){

	u8 L_u8Status = InitErrState;

		if( (A_u8PortID < MinPortID) || (A_u8PortID > MaxPortID) ){

			/* Wrong Port */
			L_u8Status = PortIDErrState;

		} else if( (A_u8PinID < MinPinID) || (A_u8PinID > MaxPinID) ) {

			/* Wrong Pin */
			L_u8Status = PinIDErrState;

		} else if( (A_u8Value != LOW) && (A_u8Value != HIGH)  ){

			/* Wrong Value */
			L_u8Status = PinValErrState;

		} else{

			switch(A_u8PortID){

			case PORTA:
				if(A_u8Value == LOW)  Clr_Bit(DIO_u8PORTA,A_u8PinID);
				if(A_u8Value == HIGH) Set_Bit(DIO_u8PORTA,A_u8PinID);
				break;

			case PORTB:
				if(A_u8Value == LOW)  Clr_Bit(DIO_u8PORTB,A_u8PinID);
				if(A_u8Value == HIGH) Set_Bit(DIO_u8PORTB,A_u8PinID);
				break;

			case PORTC:
				if(A_u8Value == LOW)  Clr_Bit(DIO_u8PORTC,A_u8PinID);
				if(A_u8Value == HIGH) Set_Bit(DIO_u8PORTC,A_u8PinID);
				break;

			case PORTD:
				if(A_u8Value == LOW)  Clr_Bit(DIO_u8PORTD,A_u8PinID);
				if(A_u8Value == HIGH) Set_Bit(DIO_u8PORTD,A_u8PinID);
				break;
		}

			L_u8Status = SuccessErrState;

	}

		return L_u8Status;
}

u8 DIO_u8GetPinValue(u8 A_u8PortID , u8 A_u8PinID , u8 *AP_u8ValuePointer){

	u8 L_u8Status = InitErrState;

	if( (A_u8PortID < MinPortID) || (A_u8PortID > MaxPortID) ){

		/* Wrong Port */
		L_u8Status = PortIDErrState;


	} else if( (A_u8PinID < MinPinID) || (A_u8PinID > MaxPinID) ) {

		/* Wrong Pin */
		L_u8Status = PinIDErrState;


	} else{

		switch (A_u8PortID){

		case PORTA:*AP_u8ValuePointer = Get_Bit(DIO_u8PINA,A_u8PinID); break;

		case PORTB:*AP_u8ValuePointer = Get_Bit(DIO_u8PINB,A_u8PinID); break;

		case PORTC:*AP_u8ValuePointer = Get_Bit(DIO_u8PINC,A_u8PinID); break;

		case PORTD:*AP_u8ValuePointer = Get_Bit(DIO_u8PIND,A_u8PinID); break;

		}

		L_u8Status = SuccessErrState;

	}

	return L_u8Status;

}

u8 DIO_u8SetPortDirection(u8 A_u8PortID, u8 A_u8Direction ){

	u8 L_u8Status = InitErrState;

	if( (A_u8PortID < MinPortID) || (A_u8PortID > MaxPortID) ){

		/* Wrong Port */
		L_u8Status = PortIDErrState;

	} else if( (A_u8Direction < MinPortDirection) || (A_u8Direction > MaxPortDirection)  ){

		/* Wrong Direction */
		L_u8Status = PortDirErrState;

	} else{

		switch (A_u8PortID){

		case PORTA: DIO_u8DDRA = A_u8Direction; break;

		case PORTB: DIO_u8DDRB = A_u8Direction; break;

		case PORTC: DIO_u8DDRC = A_u8Direction; break;

		case PORTD: DIO_u8DDRD = A_u8Direction; break;

		}

		L_u8Status = SuccessErrState;

	}

	return L_u8Status;

}

u8 DIO_u8SetPortValue(u8 A_u8PortID, u8 A_u8Value){

	u8 L_u8Status = InitErrState;

	if( (A_u8PortID < MinPortID) || (A_u8PortID > MaxPortID) ){

		/* Wrong Port */
		L_u8Status = PortIDErrState;

	} else if( (A_u8Value < MinPortValue) || (A_u8Value > MaxPortValue)  ){

		/* Wrong Value */
		L_u8Status = PortValErrState;

	} else{

		switch (A_u8PortID){

		case PORTA: DIO_u8PORTA = A_u8Value; break;

		case PORTB: DIO_u8PORTB = A_u8Value; break;

		case PORTC: DIO_u8PORTC = A_u8Value; break;

		case PORTD: DIO_u8PORTD = A_u8Value; break;

		}

		L_u8Status = SuccessErrState;

	}

	return L_u8Status;

}

u8 DIO_u8GetPortValue(u8 A_u8PortID, u8 * AP_u8ValuePointer){

	u8 L_u8Status = InitErrState;

	if( (A_u8PortID < MinPortID) || (A_u8PortID > MaxPortID) ){

		/* Wrong Port */
		L_u8Status = PortIDErrState;

	} else{

		switch (A_u8PortID){

		case PORTA: *AP_u8ValuePointer = DIO_u8PORTA; break;

		case PORTB: *AP_u8ValuePointer = DIO_u8PORTB; break;

		case PORTC: *AP_u8ValuePointer = DIO_u8PORTC; break;

		case PORTD: *AP_u8ValuePointer = DIO_u8PORTD; break;

		}

		L_u8Status = SuccessErrState;

	}

	return L_u8Status;

}
