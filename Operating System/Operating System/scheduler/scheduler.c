/*
 * scheduler.c
 *
 * Created: 2/23/2019 4:14:01 PM
 *  Author: AVE-LAB-047
 */ 
#include "Tasks.h"
#include "scheduler.h"
#include "../Timer0/Timer 0.h"

tasktype tasks[]={LED1_on,LED2_on,LED3_on};
volatile uint16 count=0;
extern flag;	
#define TRUE 1
#define FALSE 0
#define ZERO 0

/**scheduler_init_start                                                 *
*Parameters : has no i/p or o/p                                         *
*Description :                                                          *
*function to initialize and start the scheduler                         *
************************************************************************/
void scheduler_init_start(void){
	timer0_init(PRESCALLER_64);
	timer0_CM_inter_enable();
	enable_global_inter();
	timer0_start();
	set_callback(set_flag);
	prefilled(tasks);	
}

/**set_callback                                                         *
*Parameters : has i/p ->>pointer to the function to be called           *
*Description :                                                          *
*function to set the call back in the ISR to a specific function        *
************************************************************************/
void set_callback(void (*ptr)(void)){
	callback_func=ptr;
}

/**set_flag                                                             *
*Parameters : has no i/p or o/p                                         *
*Description :                                                          *
*function to set the flag in the ISR                                    *
************************************************************************/
void set_flag(){
	flag=TRUE;
}

/**prefilled                                                            *
*Parameters : has    i/p->> array of structs(tasks)                     *
*Description :                                                          *
*the function of the scheduler                                          *
************************************************************************/
void prefilled (tasktype tasks[]){
	uint8 i;
	while (1){
		
		if(flag==TRUE){
			flag=FALSE;
			for (i=ZERO;i<NUM_TASKS;i++)
			{
					increase_count();	
					tasks[i]();	
			}
		}
	}
	
}
/**increase_count                                                       *
*Parameters : has no i/p or o/p                                         *
*Description :                                                          *
*function to increase the tick counter in the ISR                       *
************************************************************************/
void increase_count(void){
	count++;
}
