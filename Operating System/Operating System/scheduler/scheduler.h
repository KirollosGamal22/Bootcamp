/*
 * scheduler.h
 *
 * Created: 2/23/2019 3:58:52 PM
 *  Author: AVE-LAB-047
 */ 


#ifndef SCHEDULER_H_
#define SCHEDULER_H_
#include "../DIO/Types.h"
#include "../Timer0/Timer 0.h"
typedef void (*tasktype)(void);
void scheduler_init_start(void);
void prefilled (tasktype tasks[]);
void set_callback(void (*ptr)(void));
extern tasktype tasks[];
void set_flag();
void increase_count(void);
#endif /* SCHEDULER_H_ */