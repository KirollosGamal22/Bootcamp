/*
 * Timer.h
 *
 * Created: 2/13/2019 5:35:36 PM
 *  Author: AVE-LAB-047
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "Config.h"
#include "Bitwiseoperations.h"
#include "Types.h"
void timer0_init(uint8 prescaller);
void timer0_start(void);
void timer0_stop(void);
void time_delay(uint32 value);


#endif /* TIMER_H_ */