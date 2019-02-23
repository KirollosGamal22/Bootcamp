/*
 * LCD.h
 *
 * Created: 2/19/2019 10:36:02 AM
 *  Author: AVE-LAB-047
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_config.h"
#include "../DIO/Types.h"

/** LCD_send_command                                                    *
*Parameters :                                                           *
*i/p : command >> the command we want to send to the LCD                *
*Description :                                                          *
*function to send command to the LCD                                    *
************************************************************************/
void LCD_send_command (LCD_COMMAND_t command);

/** LCD_init                                                            *
*Parameters :                                                           *
*Description :                                                          *
*function to initialize the LCD                                         *
************************************************************************/
void LCD_init (void);

/** LCD_send_data                                                       *
*Parameters :                                                           *
*i/p : data >> the character we want to display on the LCD              *
*Description :                                                          *
*function to display character to the LCD                               *
************************************************************************/
void LCD_send_data	(uint8 data);

/** LCD_clear_display                                                   *
*Parameters :                                                           *
*Description :                                                          *
*function to clear the LCD                                              *
************************************************************************/
void LCD_clear_display(void);

/** LCD_display_string                                                  *
*Parameters :                                                           *
*i/p : data >> the string we want to display on the LCD                 *
*Description :                                                          *
*function to display string on the LCD                                  *
************************************************************************/
void LCD_display_string (uint8 data[]);

/** LCD_go_to                                                           *
*Parameters :                                                           *
*i/p : row >> the row number                                            *
*i/p : column >> the column number                                      *
*Description :                                                          *
*function to move on the LCD screen depend on the row and column        *
************************************************************************/
void LCD_go_to (uint8 row , uint8 column);

/** LCD_Send_string_RowCOL                                              *
*Parameters :                                                           *
*i/p : data>> the string we want to siplay                              *
*i/p : row >> the row number                                            *
*i/p : column >> the column number                                      *
*Description :                                                          *
*function to display a string in a specific row and column              *
************************************************************************/
void LCD_send_string_RowCOL (uint8 data[],uint8 row,uint8 col);

/* Test Functions */
void LCD_send_command_test (LCD_COMMAND_t command);
void LCD_init_test (void);
void LCD_send_data_test	(uint8 data);
void LCD_clear_display_test(void);
void LCD_display_string_test (uint8 data[]);
void LCD_go_to_test (uint8 row , uint8 column);
void LCD_send_string_RowCOL_test (uint8 data[],uint8 row,uint8 col);
#endif /* LCD_H_ */