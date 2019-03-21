/*
 * FSM.c
 *
 *  Created on: Mar 20, 2019
 *      Author: AVE-LAP-005
 */
#include <stdint.h>
#include "Manager.h"
#include "FSM.h"
uint8_t FSM(uint8_t distance)
{
//uint8_t distance = Get_Distance();
uint8_t state=0 ;

if((distance <= 160) && (distance>90))
{
    state=1; /*Maintain speed*/
}

else if((distance<= 255) && (distance > 160)  )
{
    state=2; /*increase speed*/
}

else if((distance > 20) && (distance <= 90)  )
{
    state=3; /*decrease speed*/
}

else if((distance > 5) && (distance <= 20)  )
{
    state=4; /*break speed*/
}

else if((distance == 0) && (distance <= 5)  )
{
    state=5; /*fire speed*/
}

return state;/* return state */
}


