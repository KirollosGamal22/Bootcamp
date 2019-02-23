/*
 * LCD_config.h
 *
 * Created: 2/19/2019 10:36:18 AM
 *  Author: AVE-LAB-047
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_COL_NUM 16
#define LCD_ROWS_NUM 2
 
#define RS 1
#define RW 2
#define EN 3
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7
#define OUTPUT 1
#define INPUT 0
#define FIRST_ROW 1
#define SECOND_ROW 2
#define TWO_MS 2
#define FIVE_MS 5
#define HIGH 1
#define LOW 0
#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7

typedef enum LCD_COMMAND_t {
	LCD_clear=0x01,
	LCD_4_bits=0x32,
	LCD_8_bits=0x33,
	LCD_return_home=0x02,
	LCD_shift_cursor_left=0x04,
	LCD_shift_cursor_right=0x06,
	LCD_shift_display_left=0x05,
	LCD_shift_display_right=0x07,
	LCD_shift_curs_pos_right=0x14,
	LCD_shift_curs_pos_left=0x10,
	LCD_begin_1st_line=0x80,
	LCD_begin_2nd_line=0xc0,
	LCD_4_bits_2x8x25=0x28,
	LCD_display_ON_and_cursor_blinking=0x0E,
}LCD_COMMAND_t;



#endif /* LCD-CONFIG_H_ */