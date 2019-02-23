/*
 * keypad.h
 *
 * Created: 2/18/2019 10:18:58 AM
 *  Author: AVE-LAB-047
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "KeyConfig.h"
/** Keypad_init                                                         *
*Description :                                                          *
*function to initialize the keypad                                      *
************************************************************************/

void keypad_init(void);

/** get_key                                                             *
*Parameters:                                                            *
*O/p : the pressed k                                                    *
*Description :                                                          *
*function to get the pressed key in  keypad                             *
************************************************************************/
uint8 get_key(void);




#endif /* KEYPAD_H_ */