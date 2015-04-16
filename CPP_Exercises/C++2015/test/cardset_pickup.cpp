<<<<<<< HEAD
//
// cardset_pickup.cc - トランプカードの集合型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <iostream>
#include "../card.h"
#include "../cardset.h"


//
// CardSet::pickup() - 自身から targetpos 枚目のカードをぬき card にセットする
//	targetpos が -1 のときはランダムに選ぶ(-1: 失敗; 0以上: 成功)
//
int CardSet::pickup(Card & card, int targetpos /* = -1 */)
{
	if( numcard == 0 )
		return -1;
	if(targetpos < 0)
=======
/*
 * cardset_pickup.cpp
 *
 *  Created on: 2015/04/16
 *      Author: sin
 */

#include "../card.h"
#include "../cardset.h"

int CardSet::pickup(Card & card, int targetpos) {
	if( numcard == 0 )
		return -1;
	if(targetpos == -1 )
>>>>>>> origin/master
		targetpos = random() % numcard;
	else
		targetpos %= numcard;
	card = cdat[targetpos];
<<<<<<< HEAD
	remove(card); // remove() 実現後にコメントを外せ
	return targetpos;
}


=======
	remove(card);
	return targetpos;
}
>>>>>>> origin/master
