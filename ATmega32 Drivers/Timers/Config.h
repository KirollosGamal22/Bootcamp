/*
 * Config.h
 *
 * Created: 2/13/2019 5:35:21 PM
 *  Author: AVE-LAB-047
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

#define TCNT0 (*(volatile uint8*)(0x52))
#define TCCR0 (*(volatile uint8*)(0x53))
#define OCR0  (*(volatile uint8*)(0x5C))
#define TIFR  (*(volatile uint8*)(0x58))
#define TIMSK (*(volatile uint8*)(0x59))

typedef enum TCCR0_REG_t{
	CS00=0,
	CS01,
	CS02,
	WGM01,
	COM00,
	COM01,
	WGM00,
	FOC0
}TCCR0_REG;

typedef enum PRESCALLER_t{
	NO_PRESCALLER=1,
	PRESCALLER_8,
	PRESCALLER_64,
	PRESCALLER_256,
	PRESCALLER_1024
	}PRESCALLER_t;
#endif /* CONFIG_H_ */