/*
 * Motor.c
 *
 * Created: 22/02/2019 15:14:03
 *  Author: Kirollos Gamal
 */ 

#include "../Includes/Motor/Motor.h"
#include "../Includes/Motor/Motorcnfg.h"
#include "../Includes/DIO/DIO.h"
#include "../Includes/PWM/PWM.h"

void Motor1_init(){
	DIO_SetPinDirection(MOTOR1_ENABLE,OUT);
	DIO_SetPinDirection(MOTOR1_DIREC_A,OUT);
	DIO_SetPinDirection(MOTOR1_DIREC_B,OUT);
	phase_corr_PWM_init_B(PRESCALLER_T1_256);
}
void Motor2_init(){
	DIO_SetPinDirection(MOTOR2_ENABLE,OUT);
	DIO_SetPinDirection(MOTOR2_DIREC_A,OUT);
	DIO_SetPinDirection(MOTOR2_DIREC_B,OUT);
	phase_corr_PWM_init_A(PRESCALLER_T1_256);

}
void Motor1_SetDirection_left(){
	/*disable the H-bridge first  */
	DIO_WritePin(MOTOR1_DIREC_A,LOW);
	DIO_WritePin(MOTOR1_DIREC_B,LOW);
	/*set the direction */
	DIO_WritePin(MOTOR1_DIREC_A,HIGH);
	DIO_WritePin(MOTOR1_DIREC_B,LOW);
}

void Motor1_SetDirection_right(){
	/*disable the H-bridge first  */
	DIO_WritePin(MOTOR1_DIREC_A,LOW);
	DIO_WritePin(MOTOR1_DIREC_B,LOW);
	/*set the direction */
	DIO_WritePin(MOTOR1_DIREC_A,LOW);
	DIO_WritePin(MOTOR1_DIREC_B,HIGH);
}
void Motor1_stop(){
PWM_B_stop();
}

void Motor1_ChangeSpeed(uint8 dutycycle){
	PWM_set_dutycycle_B(dutycycle);
	PWM_B_start();
}
void Motor2_SetDirection_left(){
	/*disable the H-bridge first  */
	DIO_WritePin(MOTOR2_DIREC_A,LOW);
	DIO_WritePin(MOTOR2_DIREC_B,LOW);
	/*set the direction */
	DIO_WritePin(MOTOR2_DIREC_A,HIGH);
	DIO_WritePin(MOTOR2_DIREC_B,LOW);
	
}
void Motor2_SetDirection_right(){
	/*disable the H-bridge first  */
	DIO_WritePin(MOTOR2_DIREC_A,LOW);
	DIO_WritePin(MOTOR2_DIREC_B,LOW);
	/*set the direction */
	DIO_WritePin(MOTOR2_DIREC_A,LOW);
	DIO_WritePin(MOTOR2_DIREC_B,HIGH);
}
void Motor2_stop(){
	PWM_A_stop();
}
void Motor2_ChangeSpeed(uint8 dutycycle){
	PWM_set_dutycycle_A(dutycycle);
	PWM_A_start();
}
