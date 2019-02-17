/*
 * DIO.c
 *
 * Created: 2/13/2019 9:35:04 AM
 *  Author: AVE-LAB-047
 */ 
#include "DIO.h"
#include <avr/io.h>
void DIO_WritePin(uint8 PinNum,uint8 PinValue){
	if(PinNum>=0 && PinNum<8){
		if(PinValue==1)
			{
				PORTA=Set_Bit(PORTA,PinNum);
			}
			else
			{
				PORTA=Clear_Bit(PORTA,PinNum);
			}
	}
	
	else if(PinNum>=8 && PinNum<16){
		if(PinValue==1)
			{
				PORTB=Set_Bit(PORTB,(PinNum-8));
				//PORTB|=(1<<PinNum);
			}
			else
			{
				PORTB=Clear_Bit(PORTB,(PinNum-8));
			}
	}
	else if(PinNum>=16 && PinNum<24){
		if(PinValue==1)
			{
				PORTC=Set_Bit(PORTC,(PinNum-16));
			}
			else
			{
				PORTC=Clear_Bit(PORTC,(PinNum-16));
			}
	}
	else if(PinNum>=24 && PinNum<32){
		if(PinValue==1)
			{
				PORTB=Set_Bit(PORTB,(PinNum-24));
			}
			else
			{
				PORTB=Clear_Bit(PORTB,(PinNum-24));
			}
	}
}

uint8 DIO_ReadPin(uint8 PinNum){
	if(PinNum>=0 && PinNum<8){
		return Get_Bit(PINA,PinNum);		
	}
	if(PinNum>=8 && PinNum<16){
		return Get_Bit(PINB,(PinNum-8));		
	}
	if(PinNum>=16 && PinNum<24){
		return Get_Bit(PINC,(PinNum-16));		
	}
	if(PinNum>=24 && PinNum<32){
		return Get_Bit(PIND,(PinNum-24));		
	}
}

void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection){
	 if(PinNum>=0 && PinNum<8){
		if(PinDirection==1)
			{
				DDRA=Set_Bit(DDRA,PinNum);
			}
			else
			{
				DDRA=Clear_Bit(DDRA,PinNum);
			}
	}
	
		
	
	else if(PinNum>=8 && PinNum<16){
		if(PinDirection==1)
			{
				DDRB=Set_Bit(DDRB,(PinNum-8));
			}
			else
			{
				DDRB=Clear_Bit(DDRB,(PinNum-8));
			}
	}
	else if(PinNum>=16 && PinNum<24){
		if(PinDirection==1)
			{
				DDRC=Set_Bit(DDRC,(PinNum-16));
			}
			else
			{
				DDRC=Clear_Bit(DDRC,(PinNum-16));
			}
	}
	else if(PinNum>=24 && PinNum<32){
		if(PinDirection)
			{
				DDRD=Set_Bit(DDRD,(PinNum-24));
			}
			else
			{
				DDRD=Clear_Bit(DDRD,(PinNum-24));
			}
	}
}

	

