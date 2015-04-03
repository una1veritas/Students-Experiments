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


bool LittleThinkPlayer::approve(CardSet & pile, int numCards[]) {
	/*
	 * たとえば，場に出たカードをすべておぼえておく．
	 * memory.insert(pile);
	 */

	/*
	 * 手札数の状況をみる．
	 * 自分自身のidは getId() で得られる．
	 * std::cerr << getName() << " " << getId() << std::endl;
	 * for (int i = 0; numCards[i] != NO_MORE_PLAYERS; i++) {
	 *	 std::cerr << i << " " << numCards[i] << std::endl;
	 * }
	 */
	return true;
}

bool LittleThinkPlayer::follow(CardSet & pile, CardSet & s) {
	Card tmp;
	s.makeempty();
	sortInHand();
	std::cout << "( " << inHand() << " )" << std::endl;
	inHand().pickup(&tmp, -1); // とにかく選ぶ．
	s.insert(tmp);
	// the card idential to tmp is already removed from the hand. 
	// cardSetOfSameRanks(s, pile.size());
	// たとえば、複数枚のカードを探す関数。ただしこの関数は未実装。
	// 現状ではこの follow は Player.cc のものと等価
	return true;
}

/*
 * ソートに使う順序関数の例．
 * 自分のならべたい順序にの定義を作成する．
 */
bool LittleThinkPlayer::cardsLessThan(const Card & c1, const Card & c2) {
	if ( c1.getrank()  <= c2.getrank() )
		return true;
	return false;
}

/*
 * 順序関数と整合性のある同値（等しい）関係．
 */
bool LittleThinkPlayer::cardsEqualTo(const Card & c1, const Card & c2) {
	return cardsLessThan(c1, c2) && cardsLessThan(c2, c2);
}

/*
 * 順序関係 compareCards を使うナイーヴな naive ソートの例．
 * 枚数は少ないので効率は気にならない．
 */
void LittleThinkPlayer::sortInHand(void) {
	for(int i = 0; i+1 < hand.size(); i++) {
		for(int j = i+1; j < hand.size(); j++) {
			if ( cardsLessThan(hand[i], hand[j]) ) {
				Card t = hand[i];
				hand[i] = hand[j];
				hand[j] = t;
			}
		}
	}
}

