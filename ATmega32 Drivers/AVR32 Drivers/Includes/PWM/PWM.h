/*
 * PWM.h
 *
 * Created: 2/21/2019 11:46:46 AM
 *  Author: AVE-LAB-047
 */ 


#ifndef PWM_H_
#define PWM_H_
#include "../DIO/DIO.h"
typedef enum PRESCALLER_T1_t{
	NO_PRESCALLER_T1=1,
	PRESCALLER_T1_8,
	PRESCALLER_T1_64,
	PRESCALLER_T1_256,
	PRESCALLER_T1_1024
}PRESCALLER_T1_t;

 void fast_PWM_init(uint8 prescaller_t);
 void phase_corr_PWM_init_A(uint8 prescaller_t);
 void phase_corr_PWM_init_B(uint8 prescaller_t);
 void PWM_A_start();
 void PWM_A_stop();
 void PWM_set_dutycycle_A(uint8 DutyCycle);
 
 void PWM_B_start();
 void PWM_B_stop();
 void PWM_set_dutycycle_B(uint8 DutyCycle);




#endif /* PWM_H_ */