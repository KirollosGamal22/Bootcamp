/*
 * DIO.c
 *
 * Created: 2/13/2019 9:35:04 AM
 *  Author: AVE-LAB-047
 */ 
#include "../includes/DIO/DIO.h"
#include "../Includes/DIO/Config.h"
void DIO_WritePin(uint8 PinNum,uint8 PinValue){
	if(PinNum>=ZERO && PinNum<EIGHT)
	{
		if(PinValue==HIGH)
			{
				PORTA=Set_Bit(PORTA,PinNum);
			}
			else
			{
				PORTA=Clear_Bit(PORTA,PinNum);
			}
	}
	
	else if(PinNum>=EIGHT && PinNum<SIXTEEN){
		if(PinValue==HIGH)
			{
				PORTB=Set_Bit(PORTB,(PinNum-EIGHT));
			}
			else
			{
				PORTB=Clear_Bit(PORTB,(PinNum-EIGHT));
			}
	}
	else if(PinNum>=SIXTEEN && PinNum<TWINTY_FOUR){
		if(PinValue==HIGH)
			{
				PORTC=Set_Bit(PORTC,(PinNum-SIXTEEN));
			}
			else
			{
				PORTC=Clear_Bit(PORTC,(PinNum-SIXTEEN));
			}
	}
	else if(PinNum>=TWINTY_FOUR && PinNum<THIRTY_TWO){
		if(PinValue==HIGH)
			{
				PORTD=Set_Bit(PORTD,(PinNum-TWINTY_FOUR));
			}
			else
			{
				PORTD=Clear_Bit(PORTD,(PinNum-TWINTY_FOUR));
			}
	}
}
uint8 DIO_ReadPin(uint8 PinNum){
	if(PinNum>=ZERO && PinNum<EIGHT){
		return Get_Bit(PINA,PinNum);		
	}
	if(PinNum>=EIGHT && PinNum<SIXTEEN){
		return Get_Bit(PINB,(PinNum-EIGHT));		
	}
	if(PinNum>=SIXTEEN && PinNum<TWINTY_FOUR){
		return Get_Bit(PINC,(PinNum-SIXTEEN));		
	}
	if(PinNum>=TWINTY_FOUR && PinNum<THIRTY_TWO){
		return Get_Bit(PIND,(PinNum-TWINTY_FOUR));		
	}
}
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection){
	 if(PinNum>=ZERO && PinNum<EIGHT){
		if(PinDirection==HIGH)
			{
				DDRA=Set_Bit(DDRA,PinNum);
			}
			else
			{
				DDRA=Clear_Bit(DDRA,PinNum);
			}
	}
	
		
	
	else if(PinNum>=EIGHT && PinNum<SIXTEEN){
		if(PinDirection==HIGH)
			{
				DDRB=Set_Bit(DDRB,(PinNum-EIGHT));
			}
			else
			{
				DDRB=Clear_Bit(DDRB,(PinNum-EIGHT));
			}
	}
	else if(PinNum>=SIXTEEN && PinNum<TWINTY_FOUR){
		if(PinDirection==HIGH)
			{
				DDRC=Set_Bit(DDRC,(PinNum-SIXTEEN));
			}
			else
			{
				DDRC=Clear_Bit(DDRC,(PinNum-SIXTEEN));
			}
	}
	else if(PinNum>= TWINTY_FOUR && PinNum<THIRTY_TWO){
		if(PinDirection==HIGH)
			{
				DDRD=Set_Bit(DDRD,(PinNum-TWINTY_FOUR));
			}
			else
			{
				DDRD=Clear_Bit(DDRD,(PinNum-TWINTY_FOUR));
			}
	}
}

void DIO_WritePort(uint8 port ,uint8 value){
	switch (port)
	{
		case 'A':
		PORTA=value;
		break;
		case 'B':
		PORTB=value;
		break;
		case 'C':
		PORTC=value;
		break;
		case 'D':
		PORTD=value;
		break;
	}
}	
void DIO_SetPortDirection(uint8 port,uint8 direction){
	switch(port){
		case 'A':
		DDRA=direction;	
		break;
		case 'B':
		DDRB=direction;
		break;
		case 'C':
		DDRC=direction;
		break;
		case 'D':
		DDRD=direction;
		break;
	}
}