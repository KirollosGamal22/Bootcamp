/*
 * Timer.c
 *
 * Created: 2/13/2019 5:35:53 PM
 *  Author: AVE-LAB-047
 */ 
#include "Timer 0.h"
#include "Config.h"
#include "avr/interrupt.h"
volatile uint8 flag=0;

static uint32 prescaller_t;
static uint8 timer0_Prescaller ;
#define PRESCALLER_MASK 7
#define XTAL 8000UL 
#define OCR0_1MS 249
/** timer0_init                                                         *
*Parameters :                                                           *
*i/p : prescaller>> set the prescaller of timer0                        *
*Description :                                                          *
*function to initialize timer 0                                         *
************************************************************************/
void timer0_init(PRESCALLER_t prescaller){
	TCCR0=0x08; //CTC MODE 
	TCNT0=0x00;
	OCR0=OCR0_1MS;
	timer0_Prescaller=prescaller;
	if(prescaller==NUM_1)
	prescaller_t=NUM_1;
	else if(prescaller==NUM_2)
	prescaller_t=NUM_8;
	else if(prescaller==NUM_3)
	prescaller_t=NUM_64;
	else if (prescaller==NUM_4)
	prescaller_t=NUM_256;
	else if(prescaller==NUM_5)
	prescaller_t=NUM_1024;
	}

/** timer0_start                                                        *
*Parameters : no input or output parameters                             *
*Description :                                                          *
*function to start the  timer 0                                         *
************************************************************************/
void timer0_start(){
	TCCR0|=timer0_Prescaller&PRESCALLER_MASK ;
}
/** timer0_stop                                                         *
*Parameters : no input or output parameters                             *
*Description :                                                          *
*function to stop the  timer 0                                          *
************************************************************************/
void timer0_stop(){
	TCCR0&=~(HIGH<<CS00)|(HIGH<<CS01)|(HIGH<<CS00);
}

/** timer0_start                                                        *
*Parameters :                                                           *
*input :value >> the desired time to delay in millysecond               *
*Description :                                                          *
*function to generate delay using timer 0                               *
************************************************************************/
void time_delay(uint32 value){
		uint32 clk_num ;
		uint32 sys_freq ;
		uint16 loops,i;
		uint8 num;
		sys_freq=XTAL/prescaller_t ;
		clk_num=value* sys_freq;
		
		if(clk_num<U8_MAX_SIZE){
			OCR0=clk_num ;
			timer0_start();
			while (!(Get_Bit(TIFR,OCF0)))
			{
			;}
			TIFR=Set_Bit(TIFR,OCF0);
			timer0_stop();	
		}
		else{
			loops=clk_num / U8_MAX_NUM ;
			num=clk_num % U8_MAX_NUM;
			for(i=ZERO;i<loops;i++)
			{
			OCR0=U8_MAX_NUM;
			timer0_start();
			
			while (!(Get_Bit(TIFR,OCF0)))
			{
			;}
			
			TIFR=Set_Bit(TIFR,OCF0);
			}
			OCR0=num ;
			while (!(Get_Bit(TIFR,OCF0))){
				;}
			TIFR=Set_Bit(TIFR,OCF0);
			timer0_stop();	
	}


}

/** enable_global_inter                                                 *
*Parameters : no input or output parameters                             *
*Description :                                                          *
*function to enable the global interrupt                                *
************************************************************************/
void enable_global_inter(void){
	SREG|=(HIGH<<G_INTERRUPT);
}

/** disable_global_inter                                                *
*Parameters : no input or output parameters                             *
*Description :                                                          *
*function to disable the global interrupt                               *
************************************************************************/
void disable_global_inter(void){
	SREG|=(HIGH<<G_INTERRUPT);
}

/** timer0_CM_inter_enable                                              *
*Parameters : no input or output parameters                             *
*Description :                                                          *
*function to enable timer0 Compare Match interrupt                      *
************************************************************************/
void timer0_CM_inter_enable(void){
	TIMSK|=(HIGH<<OCIE0);
}

/** timer0_CM_inter_disable                                             *
*Parameters : no input or output parameters                             *
*Description :                                                          *
*function to disable timer0 Compare Match interrupt                     *
************************************************************************/
void timer0_CM_inter_disble(void){
	TIMSK&=~(HIGH<<OCIE0);
}

/** enable_external_int2                                                *
*Parameters : no input or output parameters                             *
*Description :                                                          *
*function to enable external interrupt two                              *
************************************************************************/
void enable_external_int2(void){
	GICR|=(1<<5);
}
ISR(TIMER0_COMP_vect){
	callback_func();
	
}