/*
 * PWM.c
 *
 * Created: 2/21/2019 11:45:38 AM
 *  Author: AVE-LAB-047
 */ 
#include "../Includes/PWM/PWM.h"
#include "../Includes/PWM/PWMcnfg.h"
#include "../Includes/DIO/DIO.h"
#include "../Includes/DIO/Bitwiseoperations.h"

 static uint16 prescaller ;
 #define PRESCALLER_MASK 7  
 #define OC1A_BIT    29
 #define OC1B_BIT    28
 #define INP         0
 #define OUT         1
 #define EIGHT       8
 
 void fast_PWM_init_A(PRESCALLER_T1_t prescaller_t){
	 prescaller=prescaller_t;
	 ICR1H=0x00;
	 ICR1L=0xff;
	 /*inverting mode*/
	 Set_Bit(TCCR1A,COM1A0);
	 Set_Bit(TCCR1A,COM1A1);
	 /*wave generation mode 14 */
	Clear_Bit(TCCR1A,WGM10);
	Set_Bit(TCCR1A,WGM11);
	Set_Bit(TCCR1B,WGM12);
	Set_Bit(TCCR1B,WGM13);
 }
 void fast_PWM_init_B(PRESCALLER_T1_t prescaller_t){
	 prescaller=prescaller_t;
	 ICR1H=0x00;
	 ICR1L=0xff;
	 /*inverting mode*/
	 Set_Bit(TCCR1A,COM1B0);
	 Set_Bit(TCCR1A,COM1B1);
	 /*wave generation mode 14 */
	 Clear_Bit(TCCR1A,WGM10);
	 Set_Bit(TCCR1A,WGM11);
	 Set_Bit(TCCR1B,WGM12);
	 Set_Bit(TCCR1B,WGM13);
 }

 void phase_corr_PWM_init_A(PRESCALLER_T1_t prescaller_t){
	 prescaller=prescaller_t;
	 ICR1H=(TOP>>EIGHT);
	 ICR1L=TOP;
	 /*inverting mode*/
	 Set_Bit(TCCR1A,COM1A0);
	 Set_Bit(TCCR1A,COM1A1);
	 /*wave generation mode 10 */
	 Clear_Bit(TCCR1A,WGM10);
	 Set_Bit(TCCR1A,WGM11);
	 Clear_Bit(TCCR1B,WGM12);
	 Set_Bit(TCCR1B,WGM13);
	 	
 }
 
 void phase_corr_PWM_init_B(PRESCALLER_T1_t prescaller_t){
	 prescaller=prescaller_t;
	 ICR1H=(TOP>>EIGHT);
	 ICR1L=TOP;
	 /*inverting mode*/
	 Set_Bit(TCCR1A,COM1B0);
	 Set_Bit(TCCR1A,COM1B1);
	 /*wave generation mode 10 */
	 Clear_Bit(TCCR1A,WGM10);
	 Set_Bit(TCCR1A,WGM11);
	 Clear_Bit(TCCR1B,WGM12);
	 Set_Bit(TCCR1B,WGM13);
	 
 }
 void PWM_A_start(){
	 TCCR1B|=prescaller&PRESCALLER_MASK;
	 DIO_SetPinDirection(OC1A_BIT,OUT);
 }
void PWM_B_start(){
	TCCR1B|=prescaller&PRESCALLER_MASK;
	DIO_SetPinDirection(OC1B_BIT,OUT);
}
 void PWM_A_stop(){
	 /*clear the prescaller to stop the timer */
	 Clear_Bit(TCCR1B,CS10);
	 Clear_Bit(TCCR1B,CS11);
	 Clear_Bit(TCCR1B,CS12);
	 /*change the direction of the OC1A to stop the output  */
	 DIO_SetPinDirection(OC1A_BIT,INP);
 }
 void PWM_B_stop(){
	 /*clear the prescaller to stop the timer */
	 Clear_Bit(TCCR1B,CS10);
	 Clear_Bit(TCCR1B,CS11);
	 Clear_Bit(TCCR1B,CS12);
	 /*change the direction of the OC1A to stop the output  */
	 DIO_SetPinDirection(OC1B_BIT,INP);
 }

 void PWM_set_dutycycle_A(uint8 DutyCycle){
	 uint16 value ;
	 //uint16 top ;
	 //top=ICR1L|(ICR1H<<8) ;
	 //value=((DutyCycle*TOP) /100);
     value=TOP-(uint16)((DutyCycle*TOP) /100);
	 OCR1AH=value>>EIGHT ;
	 OCR1AL=value;
 }

void PWM_set_dutycycle_B(uint8 DutyCycle){
	uint16 value ;
	//uint16 top;
	//top=ICR1L|(ICR1H<<8) ;
	value=((DutyCycle*TOP) /100);
	OCR1BH=value>>EIGHT ;
	OCR1BL=value;
}

