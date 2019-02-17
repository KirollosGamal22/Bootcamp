/*
 * CFile1.c
 *
 * Created: 2/14/2019 10:15:21 AM
 *  Author: AVE-LAB-047
 */ 

#include "Timer 0.h"
#include "../DIO/DIO.h"
void main (){
	
	timer0_init(PRESCALLER_1024);//always use 1024 prescaler .. i will change it to be generic
	DIO_SetPinDirection(14,1);
	DIO_SetPinDirection(13,1);
	DIO_SetPinDirection(12,1);
	DIO_SetPinDirection(10,1);
	uint8 i;
	while(1){
		
		DIO_WritePin(12,1);
		for(i=0;i<10;i++){
			time_delay(50);
			while(DIO_ReadPin(10)){
				DIO_WritePin(12,0);
				DIO_WritePin(14,1);
				time_delay(500);
			}
		}
		DIO_WritePin(12,0);
		DIO_WritePin(14,1);
		for(i=0;i<10;i++){
			time_delay(50);
			while(DIO_ReadPin(10)){
				DIO_WritePin(14,1);
				time_delay(500);
			}
		}
		DIO_WritePin(14,0);
		DIO_WritePin(13,1);
		for(i=0;i<10;i++){
			time_delay(50);
			while(DIO_ReadPin(10)){
				DIO_WritePin(13,0);
				DIO_WritePin(14,1);
				time_delay(500);
				}
			}
		DIO_WritePin(13,0);
	}
}
