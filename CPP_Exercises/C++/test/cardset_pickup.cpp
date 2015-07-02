/*
 * cardset_pickup.cpp
 *
 *  Created on: 2015/04/16
 *      Author: sin
 */

#include "../Card.h"
#include "../CardSet.h"

int CardSet::pickup(Card & card, int targetpos) {
	if( numcard == 0 )
		return -1;
	if(targetpos == -1 )
		targetpos = random() % numcard;
	else
		targetpos %= numcard;
	card = cdat[targetpos];
	remove(card);
	return targetpos;
}
