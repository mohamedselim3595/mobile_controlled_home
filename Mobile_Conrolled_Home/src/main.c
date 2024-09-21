/*
 * main.c
 *
 *  Created on: Jul 25, 2024
 *      Author: Mohamed Bassem
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Calc.h"
#include <util/delay.h>
#include "string.h"

#include "DIO_Interface.h"
#include "DIO_private.h"

#include "UART_Private.h"
#include "UART_Interface.h"

#include "MCH_config.h"
#include "MCH_interface.h"
#include "MCH_private.h"




void main(void){


	MCH_voidINIT();

	UART_voidInit();

	/******* user names and passwords **********/
	u8 user_1[]="user01";
	u8 user_2[]="user02";
	u8 user_3[]="user03";
	u8 user_4[]="user04";
	u8 user_5[]="user05";
	u8 user_6[]="user06";
	u8 user_7[]="user07";
	u8 user_8[]="user08";
	u8 user_9[]="user09";
	u8 user_10[]="user10";

	u8 p1[]= "1111";
	u8 p2[]= "2222";
	u8 p3[]= "3333";
	u8 p4[]= "4444";
	u8 p5[]= "5555";
	u8 p6[]= "6666";
	u8 p7[]= "7777";
	u8 p8[]= "8888";
	u8 p9[]= "9999";
	u8 p10[]="1010";

	/****** flag to check ******/
	u8 user_num=0;
	u8 pass_num=0;
	u8 user_found = 0;

	/****** username and password array ******/
	u8 user_Enter[7];
	u8 pass_Enter[5];

	/****** Variables ******/
	u8 receive;
	u8 error_counter = 0;
	u8 choice;


	while(1){



		UART_voidSendString("please write your user name :");

		UART_Flush();

		for(u8 i = 0 ; i<6 ; i++){

			 receive = UART_voidReceiveByte();
			 user_Enter[i]=receive;

			 }

		user_Enter[6]= '\0';

		UART_voidSendString(user_Enter);

		UART_Flush();

		UART_voidSendString("\n");

		UART_voidSendString("please write your Password :");

		for(u8 i = 0 ; i<4 ; i++)
			 {
				  receive = UART_voidReceiveByte();
				  pass_Enter[i]=receive;
			 }

		pass_Enter[4]='\0';

		UART_voidSendString(pass_Enter);

		UART_voidSendString("\n");

		/*to check user is valid or not*/
		 if(strcmp(user_Enter , user_1) == 0)
		 {
			 user_num = 1;
		 }

		 else if(strcmp(user_Enter , user_2) == 0)
		 {
			 user_num = 2;
		 }

		 else if(strcmp(user_Enter , user_3) == 0)
		 {
			 user_num = 3;
		 }

		 else if(strcmp(user_Enter , user_4) == 0)
		 {
			 user_num = 4;
		 }

		 else if(strcmp(user_Enter , user_5) == 0)
		 {
			 user_num = 5;
		 }

		 else if(strcmp(user_Enter , user_6) == 0)
		 {
			 user_num = 6;
		 }

		 else if(strcmp(user_Enter , user_7) == 0)
		 {
			 user_num = 7;
		 }

		 else if(strcmp(user_Enter , user_8) == 0)
		 {
			 user_num = 8;
		 }
		 else if(strcmp(user_Enter , user_9) == 0)
		 {
			 user_num = 9;
		 }
		 else if(strcmp(user_Enter , user_10) == 0)
		 {
			 user_num = 10;
		 }
		 else
		 {
			 user_num = 0 ;
		 }



		 /*to check password is valid or not*/
		 if(strcmp(pass_Enter , p1) == 0)
		 {
			 pass_num = 1;
		 }

		 else if(strcmp(pass_Enter , p2) == 0)
		 {
			 pass_num = 2;
		 }

		 else if(strcmp(pass_Enter , p3) == 0)
		 {
			 pass_num = 3;
		 }

		 else if(strcmp(pass_Enter , p4) == 0)
		 {
			 pass_num = 4;
		 }

		 else if(strcmp(pass_Enter , p5) == 0)
		 {
			 pass_num = 5;
		 }

		 else if(strcmp(pass_Enter , p6) == 0)
		 {
			 pass_num = 6;
		 }

		 else if(strcmp(pass_Enter , p7) == 0)
		 {
			 pass_num = 7;
		 }

		 else if(strcmp(pass_Enter , p8) == 0)
		 {
			 pass_num = 8;
		 }
		 else if(strcmp(pass_Enter , p9) == 0)
		 {
			 pass_num = 9;
		 }
		 else if(strcmp(pass_Enter , p10) == 0)
		 {
			 pass_num = 10;
		 }
		 else
		 {
			 pass_num = 0 ;
		 }



		 if(user_num == 0 ||  pass_num == 0 || user_num != pass_num)
		 {
			 UART_voidSendString("error\n");
			 error_counter ++;
			 if(error_counter == 3)
			 {
				 UART_voidSendString("You are a Thief");
				 MCH_VoidSirenOn();

			 }
		 }

		 else
		 {
			 error_counter = 0 ;
			 UART_voidSendString("Welcome In your Home\n");
			 user_found = 1;
		 }

		 while(user_found){

			 UART_voidSendString("This Is Your choices");

			 UART_voidSendString("\n");

			 UART_voidSendString("1-> To open Door");

			 UART_voidSendString("\n");

			 UART_voidSendString("2-> To Lock Door");

			 UART_voidSendString("\n");

			 UART_voidSendString("3-> To On LED");

			 UART_voidSendString("\n");

			 UART_voidSendString("4-> To Off LED");

			 UART_voidSendString("\n");

			 UART_voidSendString("5-> To Log Out");

			 UART_Flush();

			 choice = 0;

			 while(!choice)
			 choice = UART_voidReceiveByte();

			 switch(choice){

			 case '1':

				 MCH_VoidOpenLock();
				 break;

			 case '2':

				 MCH_VoidCloseLock();
				 break;

			 case '3':

				 MCH_VoidTurnOnLED();
				 break;

			 case '4':

				 MCH_VoidTurnOffLED();
				 break;

			 case '5' :
			 	 user_found = 0;
			 	 break;

			 default:
			 	 UART_voidSendString("Enter right choice");
			 	 break;

			 }

		 }
	}
}
