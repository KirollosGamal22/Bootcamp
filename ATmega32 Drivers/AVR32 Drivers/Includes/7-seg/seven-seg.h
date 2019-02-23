/*
 * _7_seg.h
 *
 * Created: 2/18/2019 10:20:04 AM
 *  Author: AVE-LAB-047
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_
#include "../DIO/DIO.h"
#include "seven_config.h"

/** BCD_seven_segment_enable                                            *
*Parameters :                                                           *
*i/p : num >> unsigned character for the display number                 * 
*Description :                                                          * 
*function to enable the desired display                                 *
************************************************************************/
void BCD_Sevensegment_enable(SEVEN_SEG_NUM_ENABLE_t num);

/** BCD_seven_segment_disable                                           *
*Parameters :                                                           *
*i/p : num >> unsigned character for the display number                 *
*Description :                                                          *
*function to disable the desired display                                *
************************************************************************/
void BCD_Sevensegment_disable(SEVEN_SEG_NUM_ENABLE_t num);
/** BCD_seven_segment_display                                           *
*Parameters :                                                           *
*i/p : num >> unsigned character for the number you want to display     *
*Description :                                                          *
*function to display numbers from 0 to 9                                *
************************************************************************/
void BCD_Sevensegment_display(uint8 num);

#endif /* SEVEN-SEG_H_ */