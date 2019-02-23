/*
 * LCD.c
 *
 * Created: 2/19/2019 10:34:46 AM
 *  Author: AVE-LAB-047
 */ 
#include "../Includes/LCD/LCD.h"
#include "../Includes/DIO/DIO.h"
#include <util/delay.h>

/** LCD_send_command                                                    *
*Parameters :                                                           *
*i/p : command >> the command we want to send to the LCD                *
*Description :                                                          *
*function to send command to the LCD                                    *
************************************************************************/
void LCD_send_command (LCD_COMMAND_t command){
	
	DIO_WritePin(RS,LOW);
	DIO_WritePin(RW,LOW);
	/*send the upper nipple of the command */
	DIO_WritePin(LCD_D4,Get_Bit(command,BIT4));
	DIO_WritePin(LCD_D5,Get_Bit(command,BIT5));
	DIO_WritePin(LCD_D6,Get_Bit(command,BIT6));
	DIO_WritePin(LCD_D7,Get_Bit(command,BIT7));
	/*enable*/
	DIO_WritePin(EN,HIGH);
	_delay_ms(TWO_MS);
	/*disable*/
	DIO_WritePin(EN,LOW);
	_delay_ms(TWO_MS);
	/*send the lower nipple of the command */
	DIO_WritePin(LCD_D4,Get_Bit(command,BIT0));
	DIO_WritePin(LCD_D5,Get_Bit(command,BIT1));
	DIO_WritePin(LCD_D6,Get_Bit(command,BIT2));
	DIO_WritePin(LCD_D7,Get_Bit(command,BIT3));
	/*Enable*/
	DIO_WritePin(EN,HIGH);
	_delay_ms(TWO_MS);
	/*Disable*/
	DIO_WritePin(EN,LOW);
	_delay_ms(TWO_MS);
}

/** LCD_init                                                            *
*Parameters :                                                           *
*Description :                                                          *
*function to initialize the LCD                                         *
************************************************************************/
void LCD_init (void){
	/*Set the direction depend on the board*/
	DIO_SetPinDirection(EN,OUTPUT);
	DIO_SetPinDirection(RS,OUTPUT);
	DIO_SetPinDirection(RW,OUTPUT);
	DIO_SetPinDirection(LCD_D7,OUTPUT);
	DIO_SetPinDirection(LCD_D6,OUTPUT);
	DIO_SetPinDirection(LCD_D5,OUTPUT);
	DIO_SetPinDirection(LCD_D4,OUTPUT);
	_delay_ms(TWO_MS);
	
	/*8-bits mode*/
	LCD_send_command(LCD_8_bits);
	
	/*4-bits mode*/
	LCD_send_command(LCD_4_bits);
	LCD_send_command(LCD_4_bits_2x8x25);
	
	/*some commands for initialization*/
	LCD_send_command(LCD_display_ON_and_cursor_blinking);
	LCD_send_command(LCD_shift_cursor_right);
	
	/*Clear the LCD*/
	LCD_send_command(LCD_clear);
	/*start in the first line */
	LCD_send_command(LCD_begin_1st_line);
	_delay_ms(FIVE_MS);
}

/** LCD_send_data                                                       *
*Parameters :                                                           *
*i/p : data >> the character we want to display on the LCD              *
*Description :                                                          *
*function to display character to the LCD                               *
************************************************************************/
void LCD_send_data	(uint8 data){
DIO_WritePin(RS,HIGH);
DIO_WritePin(RW,LOW);

/*send the upper nipple of the data */
DIO_WritePin(LCD_D4,Get_Bit(data,BIT4));
DIO_WritePin(LCD_D5,Get_Bit(data,BIT5));
DIO_WritePin(LCD_D6,Get_Bit(data,BIT6));
DIO_WritePin(LCD_D7,Get_Bit(data,BIT7));

/*Enable*/
DIO_WritePin(EN,HIGH);
_delay_ms(TWO_MS);

/*Disable*/
DIO_WritePin(EN,LOW);
_delay_ms(TWO_MS);

/*send the lower nipple of the data */
DIO_WritePin(LCD_D4,Get_Bit(data,BIT0));
DIO_WritePin(LCD_D5,Get_Bit(data,BIT1));
DIO_WritePin(LCD_D6,Get_Bit(data,BIT2));
DIO_WritePin(LCD_D7,Get_Bit(data,BIT3));

/*Enable*/
DIO_WritePin(EN,HIGH);
_delay_ms(TWO_MS);

/*Disable*/
DIO_WritePin(EN,LOW);
_delay_ms(TWO_MS);


}

/** LCD_clear_display                                                   *
*Parameters :                                                           *
*Description :                                                          *
*function to clear the LCD                                              *
************************************************************************/
void LCD_clear_display(){
	/*Clear the screen*/
	LCD_send_command(LCD_clear);
}

/** LCD_display_string                                                  *
*Parameters :                                                           *
*i/p : data >> the string we want to display on the LCD                 *
*Description :                                                          *
*function to display string on the LCD                                  *
************************************************************************/
void LCD_display_string (uint8 data[]){
	uint8 i;
	/* wait till reaching the last character in the string*/
	for(i=0;data[i]!='\0';i++) 
	{
		/*display the i-th character*/
		LCD_send_data(data[i]); 
	}
}

/** LCD_go_to                                                           *
*Parameters :                                                           *
*i/p : row >> the row number                                            *
*i/p : column >> the column number                                      *
*Description :                                                          *
*function to move on the LCD screen depend on the row and column        *
************************************************************************/
void LCD_go_to (uint8 row , uint8 column){
	uint8 i;
	/*check if the user want the first row*/
	if(row==FIRST_ROW)
	{
		/* go to the first row*/
		LCD_send_command(LCD_begin_1st_line);
		
		/*wait to reach the column which the user want to go*/
		for(i=0;i<column;i++)
		{
			LCD_send_command(LCD_shift_curs_pos_right);
		}
	}
	/*check if the user want the second row*/
	else if(row==SECOND_ROW){
		
		/* go to the second row*/
		LCD_send_command(LCD_begin_2nd_line);
		
		/*wait to reach the column which the user want to go*/
		for(i=0;i<column;i++)
		{
			LCD_send_command(LCD_shift_curs_pos_right);
		}
	}
}

/** LCD_Send_string_RowCOL                                              *
*Parameters :                                                           *
*i/p : data>> the string we want to siplay                              *
*i/p : row >> the row number                                            *
*i/p : column >> the column number                                      *
*Description :                                                          *
*function to display a string in a specific row and column              *
************************************************************************/
void LCD_send_string_RowCOL (uint8 data[],uint8 row,uint8 col){
	
	/*call the go to function to set the row and the column*/
	LCD_go_to(row,col);
	
	/*call display the string*/
	LCD_display_string(data);
}

/*test functions*/
void LCD_send_command_test (LCD_COMMAND_t command){
	LCD_send_command(command);
}
void LCD_init_test (void){
	LCD_init();
}
void LCD_send_data_test	(uint8 data){
	LCD_send_data(data);
}
void LCD_clear_display_test(){
	LCD_clear_display();
}
void LCD_display_string_test (uint8 data[]){
	LCD_display_string(data);
}
void LCD_go_to_test (uint8 row , uint8 column){
	LCD_go_to(row,column);
}
void LCD_send_string_RowCOL_test (uint8 data[],uint8 row,uint8 col){
	LCD_send_string_RowCOL(data,row,col);
}