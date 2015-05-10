/*
 *  LittleThinkPlayer.cpp
 *  PlayingCard
 *
 *  Created by 下薗 真一 on 09/04/12.
 *  Modified by Kazutaka Shimada on 09/04/21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <iostream>
#include <string>

#include "Card.h"
#include "CardSet.h"
#include "Player.h"
#include "LittleThinkPlayer.h"

void LittleThinkPlayer::ready() {
	hand.makeEmpty(); //hand.clear();
	memory.makeEmpty(); //memory.clear();
	trump.makeEmpty(); //trump.clear();
}

bool LittleThinkPlayer::follow(const GameStatus & gstat, CardSet & s) {
	Card tmp;
	std::cout << gstat << std::endl;
	s.makeEmpty(); //clear();
	sortInHand();
	std::cout << "( " << inHand() << " )" << std::endl;
	inHand().pickup(tmp, -1); // とにかく選ぶ．
	s.insert(tmp);
	// the card idential to tmp is already removed from the hand. 
	// cardSetOfSameRanks(s, pile.size());
	// たとえば、複数枚のカードを探す関数。ただしこの関数は未実装。
	// 現状ではこの follow は Player.cc のものと等価
	return true;
}

/*
 * ソートに使う順序関数の例．
 * 自分のならべたい順序の定義を作成する．
 * これはカード同士の比較であり，カードの集合同士の比較ではない．
 */
bool LittleThinkPlayer::cardLessThan(const Card & c1, const Card & c2) {
	if ( c1.getNumber() < c2.getNumber() )
		return true;
	return false;
}

/*
 * 順序関数と整合性のある同値（等しい）関係．
 */
bool LittleThinkPlayer::cardEquals(const Card & c1, const Card & c2) {
	return !cardLessThan(c1, c2) && !cardLessThan(c2, c2);
}

/*
 * 順序関係 compareCards を使うナイーヴな naive ソートの例．
 * 枚数は少ないので，効率は気にしない．
 */
void LittleThinkPlayer::sortInHand(void) {
	for(int i = 0; i+1 < hand.size(); i++) {
		for(int j = i+1; j < hand.size(); j++) {
			if ( cardLessThan(hand[i], hand[j]) ) {
				Card t = hand[i];
				hand[i] = hand[j];
				hand[j] = t;
			}
		}
	}
}

