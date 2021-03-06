/*
 * CONFIG.h
 *
 * Created: 2/18/2019 1:21:47 PM
 *  Author: AVE-LAB-047
 */ 


#ifndef SEVEN_CONFIG_H_
#define SEVEN_CONFIG_H_

#define HIGH 1
#define LOW 0
#define OUT 1
#define INP 0

typedef enum SEVEN_SEG_NUM_ENABLE_t{
	 SEVEN_SEGMENT_A_ENABLE=26,
	 SEVEN_SEGMENT_B_ENABLE=27,
	 SEVEN_SEGMENT_C_ENABLE=30,
	 SEVEN_SEGMENT_D_ENABLE=31,
	}SEVEN_SEG_NUM_ENABLE_t;

#define SEVEN_SEG_1ST_BIT 8
#define SEVEN_SEG_2ND_BIT 9
#define SEVEN_SEG_3RD_BIT 10
#define SEVEN_SEG_4TH_BIT 11

#endif /* CONFIG_H_ */