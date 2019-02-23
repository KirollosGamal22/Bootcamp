/*
 * AVR32 Drivers.c
 *
 * Created: 2/20/2019 11:20:20 AM
 * Author : AVE-LAB-047
 */ 

#include <util/delay.h>
#include "Includes/DIO/DIO.h"
#include "Includes/LCD/LCD.h"
#include "Includes/Timers/Timer 0.h"
#include "avr/interrupt.h"
#include "Includes/PWM/PWM.h"
#include "Includes/Motor/Motor.h"

int main (){
	
	//Motor2_init();	
	//Motor2_SetDirection_left();
	//Motor2_ChangeSpeed(10);
	Motor2_init();
	Motor2_SetDirection_left();
	//Motor2_ChangeSpeed(10);
	uint8 i ;
	while(1){
		for(i=0;i<100;i+=10){
		Motor2_ChangeSpeed(i);
		_delay_ms(3000);
		}

	}
}



/*#define SYS_GO 30
#define SYS_READY 60
#define SYS_STOP 90
#define BOTT1    10
#define LED0    12
#define LED1    13
#define LED2    14
#define INP   0
#define OUT   1
volatile uint8 count=0 ;


int main(void)
{
	
	DIO_SetPinDirection(LED0,OUT);
	DIO_SetPinDirection(LED1,OUT);
	DIO_SetPinDirection(LED2,OUT);
	DIO_SetPinDirection(BOTT1,INP);
	
	timer0_init(PRESCALLER_1024);
	enable_external_int2();
	timer0_CM_inter_enable();
	enable_global_inter();
	timer0_start();
	while(1)
	{
		if(count<=SYS_GO){
		DIO_WritePin(LED0,HIGH);
		DIO_WritePin(LED1,LOW);
		DIO_WritePin(LED2,LOW);
		}	
		else if(count<=SYS_READY){
		DIO_WritePin(LED0,LOW);
		DIO_WritePin(LED2,LOW);	
		DIO_WritePin(LED1,HIGH);
		}
		else if(count<=SYS_STOP){
			DIO_WritePin(LED0,LOW);
			DIO_WritePin(LED1,LOW);
			DIO_WritePin(LED2,HIGH);	
		}
		
	}
}
ISR(TIMER0_COMP_vect){
	count++;
	if(count>SYS_STOP)
	count=ZERO;
}

ISR(INT2_vect){
	count=SYS_READY+NUM_1;
}*/