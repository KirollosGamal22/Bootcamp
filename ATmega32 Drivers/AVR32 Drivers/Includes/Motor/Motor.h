/*
 * Motor.h
 *
 * Created: 22/02/2019 15:14:58
 *  Author: Kirollos Gamal
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_
#include "../DIO/Types.h"
void Motor1_init();
void Motor2_init();
void Motor1_SetDirection_left();
void Motor1_SetDirection_right();
void Motor1_stop();
void Motor1_ChangeSpeed(uint8 dutycycle);
void Motor2_SetDirection_left();
void Motor2_SetDirection_right();
void Motor2_stop();
void Motor2_ChangeSpeed(uint8 dutycycle);



#endif /* MOTOR_H_ */