/*
 * Operating System.c
 *
 * Created: 2/23/2019 3:54:46 PM
 * Author : AVE-LAB-047
 */ 

#include <avr/io.h>
#include "scheduler/scheduler.h"

int main(void)
{
	DIO_SetPinDirection(12,1);
	DIO_SetPinDirection(13,1);
	DIO_SetPinDirection(14,1);
	scheduler_init_start();
    /* Replace with your application code */
    while (1) 
    {
	
    }
}

