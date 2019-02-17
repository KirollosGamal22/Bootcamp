/*
 * main.c
 *
 * Created: 2/13/2019 1:25:02 PM
 *  Author: AVE-LAB-047
 */ 
#include "DIO.h"
#include <util/delay.h>
int main(){
	DIO_SetPinDirection(14,1);
	DIO_SetPinDirection(13,1);
	DIO_SetPinDirection(12,1);
	while(1){
	_delay_ms(3000);
	DIO_WritePin(12,1);
	_delay_ms(3000);
	DIO_WritePin(12,0);
	_delay_ms(3000);
	DIO_WritePin(13,1);
	_delay_ms(3000);
	DIO_WritePin(13,0);
	_delay_ms(3000);
	DIO_WritePin(14,1);
	_delay_ms(3000);
	DIO_WritePin(14,0);
	}
	/*
	while(DIO_ReadPin(10))
	{
		DIO_WritePin(13,1);
		_delay_ms(5000);
	}
		
		_delay_ms(5000);
		DIO_WritePin(13,0);

	}
	*/
	return 0;
}