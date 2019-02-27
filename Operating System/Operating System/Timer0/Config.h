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
#define SREG (*(volatile uint8*)(0x5F))
#define GICR (*(volatile uint8*)(0x5B))


#define G_INTERRUPT 7
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

typedef enum TIFR_REG_t{
		TOV0=0,
		OCF0 ,
		TOV1 ,
		OCF1B ,
		OCF1A ,
		ICF1 ,
		TOV2,
		OCF2
	}TIFR_REG_t;

typedef enum TIMSK_REG_t{
	TOIE0=0,
	OCIE0,
	TOIE1,
	OCIE1B,
	OCIE1A,
	TICIE2,
	OCIE2
	}TIMSK_REG_t;
#endif /* CONFIG_H_ */