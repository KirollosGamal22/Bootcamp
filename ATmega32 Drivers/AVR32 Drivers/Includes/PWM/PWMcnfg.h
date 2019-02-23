/*
 * PWMcnfg.h
 *
 * Created: 2/21/2019 12:17:00 PM
 *  Author: AVE-LAB-047
 */ 


#ifndef PWMCNFG_H_
#define PWMCNFG_H_

#define TCCR1A (*(volatile uint8 *)(0x4F))
#define TCCR1B (*(volatile uint8 *)(0x4E))
#define TCNT1H (*(volatile uint8 *)(0x4D))
#define TCNT1L (*(volatile uint8 *)(0x4C))
#define OCR1AH (*(volatile uint8 *)(0x4B))
#define OCR1AL (*(volatile uint8 *)(0x4A))
#define OCR1BH (*(volatile uint8 *)(0x49))
#define OCR1BL (*(volatile uint8 *)(0x48))
#define ICR1H  (*(volatile uint8 *)(0x47))
#define ICR1L  (*(volatile uint8 *)(0x46))

#define TOP 2000
typedef enum TCCR1A_REG_t{
	WGM10=0,
	WGM11=1,
	COM1B0=4,
	COM1B1=5,
	COM1A0=6,
	COM1A1=7
	}TCCR1A_REG_t;
typedef enum TCCR1B_REG_t{
	CS10=0,
	CS11=1,
	CS12=2,
	WGM12=3,
	WGM13=4,
	ICES1=6,
	ICNC1=7,
	}TCCR1B_REG_t;
	
	


#endif /* PWMCNFG_H_ */