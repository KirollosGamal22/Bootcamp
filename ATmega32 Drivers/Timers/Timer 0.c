/*
 * Timer.c
 *
 * Created: 2/13/2019 5:35:53 PM
 *  Author: AVE-LAB-047
 */ 
#include "Timer 0.h"
static uint32 prescaller_t;
static uint8 Prescaller_MASK ;
#define PRESCALLER_MASK 7
#define XTAL 16000000UL 

void timer0_init(uint8 prescaller){
	TCCR0=0x08; //CTC MODE & set OC0 on compare match
	TCNT0=0x00;
	Prescaller_MASK=prescaller;
	if(prescaller==1)
	prescaller_t=1;
	else if(prescaller==2)
	prescaller_t=8;
	else if(prescaller==3)
	prescaller_t=64;
	else if (prescaller==4)
	prescaller_t=256;
	else if(prescaller==5)
	prescaller_t=1024;
	}
void timer0_start(){
	TCCR0|=(1<<0)|(1<<2);
	
}
void timer0_stop(){
	TCCR0&=~(1<<0)|(1<<2);
}
void time_delay(uint32 value){
		uint32 n ;
		uint16 loops,i;
		uint8 num;
		
		n=value*15;
		
		if(n<256){
			OCR0=n ;
			timer0_start();
			while (!(TIFR& 0x02)){
				;}
			TIFR=Set_Bit(TIFR,1);
			timer0_stop();	
		}
		else{
			loops=n/255 ;
			num=n%255;
			for(i=0;i<loops;i++)
			{
			OCR0=250;
			timer0_start();
			
			//while (!(Get_Bit(TIFR,1))){;}
			while (!(TIFR& 0x02));
			TIFR=Set_Bit(TIFR,1);
			}
			OCR0=num ;
			//while (!(Get_Bit(TIFR,1)));
			while (!(TIFR& 0x02));
			TIFR=Set_Bit(TIFR,1);
			timer0_stop();	
	}


}