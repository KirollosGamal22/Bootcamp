/*
 * Timer.h
 *
 * Created: 2/13/2019 5:35:36 PM
 *  Author: AVE-LAB-047
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "Bitwiseoperations.h"
#include "Types.h"

#define ZERO      0
#define NUM_1     1
#define NUM_2     2
#define NUM_3     3
#define NUM_4     4
#define NUM_5     5
#define NUM_6     6
#define NUM_7     7
#define NUM_8     8
#define NUM_64    64
#define NUM_256  256
#define NUM_1024 1024
#define U8_MAX_SIZE  256
#define U8_MAX_NUM  255

#define HIGH      1
#define LOW       0 
typedef enum PRESCALLER_t{
	NO_PRESCALLER=1,
	PRESCALLER_8,
	PRESCALLER_64,
	PRESCALLER_256,
	PRESCALLER_1024
}PRESCALLER_t;
typedef void(*callback)(void);
volatile callback callback_func ;

void enable_external_int2(void);
void timer0_init(PRESCALLER_t prescaller);
void timer0_start(void);
void timer0_stop(void);
void time_delay(uint32 value);
void timer0_CM_inter_enable(void);
void timer0_CM_inter_disble(void);
void enable_global_inter(void);
void disable_global_inter(void);

#endif /* TIMER_H_ */