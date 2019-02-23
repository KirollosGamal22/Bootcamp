/*
 * DIO.h
 *
 * Created: 2/13/2019 9:35:24 AM
 *  Author: AVE-LAB-047
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "Types.h"
#include "Bitwiseoperations.h"
#define ZERO 0
#define EIGHT 8
#define SIXTEEN 16
#define TWINTY_FOUR 24
#define THIRTY_TWO 32
#define HIGH 1
#define LOW 0 
void DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);

void DIO_WritePort(uint8 port ,uint8 value);
void DIO_SetPortDirection(uint8 port,uint8 direction);

#endif /* DIO_H_ */