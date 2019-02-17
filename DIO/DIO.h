/*
 * DIO.h
 *
 * Created: 2/13/2019 9:35:24 AM
 *  Author: AVE-LAB-047
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "Types.h"
#include "Config.h"
#include "Bitwiseoperations.h"
void DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);



#endif /* DIO_H_ */