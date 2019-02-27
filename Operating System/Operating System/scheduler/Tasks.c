/*
 * Tasks.c
 *
 * Created: 2/23/2019 3:55:33 PM
 *  Author: AVE-LAB-047
 */ 
#include "../DIO/DIO.h"
#define LED1 12
#define LED2 13
#define LED3 14
#define HIGH 1
#define LOW 0
#define ZERO 0
#define ONE_SEC 1000
#define TWO_SEC 2000
#define THREE_SEC 3000
#define FOUR_SEC 4000
#define FIVE_SEC 5000
#define SIX_SEC 6000

extern count ;

void LED1_on(void){

if(count<ONE_SEC){
DIO_WritePin(LED1,HIGH);
DIO_WritePin(LED2,LOW);
DIO_WritePin(LED3,LOW);
}
}

void LED2_on(void){
	if (count>ONE_SEC && count<= THREE_SEC)
	{
	DIO_WritePin(LED1,LOW);
	DIO_WritePin(LED3,LOW);	
	DIO_WritePin(LED2,HIGH);
	}
}

void LED3_on(void){
	if(count>THREE_SEC && count< SIX_SEC){
	DIO_WritePin(LED1,LOW);
	DIO_WritePin(LED2,LOW);
	DIO_WritePin(LED3,HIGH);
	}
	if(count==SIX_SEC){
		count=ZERO;

	}
	
	}
	