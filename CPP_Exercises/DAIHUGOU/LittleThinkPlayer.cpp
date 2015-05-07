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

LittleThinkPlayer::LittleThinkPlayer(const char * s) :
		Player(s) {
}

bool LittleThinkPlayer::approve(CardSet & pile, int numCards[]) {
	/*
	memory.insert(pile);
	// memoryには他のプレイヤーが場に出したカードがストックされる

	// 自分自身のidは getId() で獲得できる
	std::cout << getName() << " " << getId() << std::endl;

	for (int i = 0; numCards[i] != 99; i++) {
		// numCardsには自分を含めたそれぞれの持ち札の数が格納されている
		// 配列の最後には終端検知のため"99"という値が入っている
		// numCardsの添字はプレイヤーのidを表す
		std::cout << i << " " << numCards[i] << std::endl;
	}
*/
	return true;
}

bool LittleThinkPlayer::follow(CardSet & pile, CardSet & s) {
	Card tmp;
	s.makeempty();
	inHand().pickup(&tmp, -1); // anyway, choose a card.
	// hand は Player の private な変数なので直接さわれないことに注意
	s.insert(tmp);
	// the card idential to tmp is already removed from the hand. 
	cardSetOfSameRanks(s, pile.size());
	// たとえば、複数枚のカードを探す関数。ただしこの関数は未実装。
	// 現状ではこの follow は Player.cc のものと等価
	return true;
}

