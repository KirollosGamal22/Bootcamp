/*
 * _7_seg.c
 *
 * Created: 2/18/2019 10:20:49 AM
 *  Author: AVE-LAB-047
 */
#include "../Includes/7-seg/seven-seg.h"
#include "../Includes/DIO/DIO.h"

/** BCD_seven_segment_enable                                            *
*Parameters :                                                           *
*i/p : num >> unsigned character for the display number                 *
*Description :                                                          *
*function to enable the desired display                                 *
************************************************************************/
void BCD_Sevensegment_enable(SEVEN_SEG_NUM_ENABLE_t num){
	/*set the display number enable */
	DIO_WritePin(num,HIGH);
}

/** BCD_seven_segment_disable                                           *
*Parameters :                                                           *
*i/p : num >> unsigned character for the display number                 *
*Description :                                                          *
*function to disable the desired display                                *
************************************************************************/
void BCD_Sevensegment_disable(SEVEN_SEG_NUM_ENABLE_t num){
	/*clear the display number enable */
	DIO_WritePin(num,LOW);
}

/** BCD_seven_segment_display                                           *
*Parameters :                                                           *
*i/p : num >> unsigned character for the number you want to display     *
*Description :                                                          *
*function to display numbers from 0 to 9                                *
************************************************************************/
void BCD_Sevensegment_display(uint8 num){
	
	/*choose which display*/

	switch(num)
	{
	case 0 : 
		DIO_WritePin(SEVEN_SEG_1ST_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_2ND_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_3RD_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_4TH_BIT,LOW);
		break;
		 
	case 1: 
		DIO_WritePin(SEVEN_SEG_1ST_BIT,HIGH);
		DIO_WritePin(SEVEN_SEG_2ND_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_3RD_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_4TH_BIT,LOW);
		break;
		
	case 2: 
		DIO_WritePin(SEVEN_SEG_1ST_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_2ND_BIT,HIGH);
		DIO_WritePin(SEVEN_SEG_3RD_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_4TH_BIT,LOW);
		break;
	
	case 3: 
		DIO_WritePin(SEVEN_SEG_1ST_BIT,HIGH);
		DIO_WritePin(SEVEN_SEG_2ND_BIT,HIGH);
		DIO_WritePin(SEVEN_SEG_3RD_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_4TH_BIT,LOW);
		break;
	
	case 4: 
		DIO_WritePin(SEVEN_SEG_1ST_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_2ND_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_3RD_BIT,HIGH);
		DIO_WritePin(SEVEN_SEG_4TH_BIT,LOW);
		break; 
	
	case 5: 
		DIO_WritePin(SEVEN_SEG_1ST_BIT,HIGH);
		DIO_WritePin(SEVEN_SEG_2ND_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_3RD_BIT,HIGH);
		DIO_WritePin(SEVEN_SEG_4TH_BIT,LOW);
		break;
	
	case 6: 
		DIO_WritePin(SEVEN_SEG_1ST_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_2ND_BIT,HIGH);
		DIO_WritePin(SEVEN_SEG_3RD_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_4TH_BIT,HIGH);
		break;
	
	case 7: 
		DIO_WritePin(SEVEN_SEG_1ST_BIT,HIGH);
		DIO_WritePin(SEVEN_SEG_2ND_BIT,HIGH);
		DIO_WritePin(SEVEN_SEG_3RD_BIT,HIGH);
		DIO_WritePin(SEVEN_SEG_4TH_BIT,LOW);
		break;
	
	case 8: 
		DIO_WritePin(SEVEN_SEG_1ST_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_2ND_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_3RD_BIT,HIGH);
		DIO_WritePin(SEVEN_SEG_4TH_BIT,LOW);
		break;
	
	case 9: 
		DIO_WritePin(SEVEN_SEG_1ST_BIT,HIGH);
		DIO_WritePin(SEVEN_SEG_2ND_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_3RD_BIT,LOW);
		DIO_WritePin(SEVEN_SEG_4TH_BIT,HIGH);
		break;
	
	}	
	
}