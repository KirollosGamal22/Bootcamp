/*
 * keypad.c
 *
 * Created: 2/18/2019 10:18:38 AM
 *  Author: AVE-LAB-047
 */ 
#include "../Includes/DIO/DIO.h"
#include "../Includes/Keypad/keypad.h"

/** Keypad_init                                                         *
*Description :                                                          *
*function to initialize the keypad                                      *
************************************************************************/
void keypad_init(){
	/* set the three Rows as INPUTS and write HIGH on them to get the pull-up mode*/
	DIO_SetPinDirection(ROW1,INP); 
	DIO_WritePin(ROW1,HIGH);
	DIO_SetPinDirection(ROW2,INP);
	DIO_WritePin(ROW2,HIGH);
	DIO_SetPinDirection(ROW3,INP);
	DIO_WritePin(ROW3,HIGH);
	/*set the three columns as OUTPUTS and write HIGH on them */
	DIO_SetPinDirection(COLUMN1,OUT);
	DIO_WritePin(COLUMN1,HIGH);
	DIO_SetPinDirection(COLUMN2,OUT);
	DIO_WritePin(COLUMN2,HIGH);
	DIO_SetPinDirection(COLUMN3,OUT);
	DIO_WritePin(COLUMN3,HIGH);
}

/** get_key                                                             *   
*Parameters:                                                            *
*O/p : the pressed k                                                    *
*Description :                                                          *
*function to get the pressed key in  keypad                             *
************************************************************************/
uint8 get_key(){
	uint8 i ,j ;
	while(1){
		/*change in the columns */
		for(i=ZERO;i<COL_NUM;i++)
		{
		/*return back the initial conditions */	
			keypad_init();
			DIO_WritePin(i+COLUMN1,LOW);
			for(j=ZERO;j<ROWS_NUM;j++){
				/*check which input row we pressed*/
				if(!(DIO_ReadPin(j+ROW1)))
				{
						/*return the pressed key */
						return ((COL_NUM*j)+i+ONE);
				}
			}	
				
		}
	}
}