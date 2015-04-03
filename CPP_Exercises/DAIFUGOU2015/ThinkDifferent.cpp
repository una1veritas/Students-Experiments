/*
 *  ThinkDifferent.cpp
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
#include "ThinkDifferent.h"

bool ThinkDifferent::approve(CardSet & pile, int numCards[]) {
#ifndef TAIKAI_HONBAN
	std::cerr << std::endl << "Pile = " << pile << std::endl;
#endif
	/*
	memory.insert(pile);
	// memoryには他のプレイヤーが場に出したカードがストックされる

	// 自分自身のidは getId() で獲得できる
	std::cerr << getName() << " " << getId() << std::endl;

	for (int i = 0; numCards[i] != NO_MORE_PLAYERS; i++) {
		// numCardsには自分を含めたそれぞれの持ち札の数が格納されている
		// 配列の最後には終端検知のため NO_MORE_PLAYERS (-1) という値が入っている
		// numCardsの添字はプレイヤーのidを表す
		std::cerr << i << " " << numCards[i] << std::endl;
	}
*/
	return true;
}

int ThinkDifferent::countInHand(int rank) {
	int n = 0;
	for(int i = 0; i < inHand().size(); i++) {
		if ( inHand()[i].getRank() == rank ) {
			n++;
		}
	}
	return n;
}

bool ThinkDifferent::follow(CardSet & pile, CardSet & s) {
	Card tmp;
	s.clear();
	sortCardSet();
#ifndef TAIKAI_HONBAN
	std::cerr << std::endl << "following with cards in my hands: " << inHand() << std::endl;
#endif
	if ( pile.size() == 0 ) {
		std::cerr << std::endl << "Yapee!!" << std::endl;
		//
		int n = countInHand(inHand()[0].getRank());
		for(int i = 0; i < n; i++) {
			inHand().pickup(tmp, 0); // anyway, choose a card.
			s.insert(tmp);
		}
	} else {
#ifndef TAIKAI_HONBAN
		std::cerr << "pile is " << pile << ", " << pile.size() << " card(s)." << std::endl;
#endif
		//
		int i;
		for(i = 0; i < inHand().size(); i++) {
			if ( inHand()[i].isGreaterThan(pile[0])
					&& pile.size() <= countInHand(inHand()[i].getRank() ) ) {
#ifndef TAIKAI_HONBAN
				std::cerr << "I have " << inHand()[i] << ", " << countInHand(inHand()[i].getRank()) << std::endl;
#endif
				break;
			}
		}
		if ( i < inHand().size() ) {
			for(int j = 0; j < pile.size(); j++) {
				inHand().pickup(tmp, i);
				s.insert(tmp);
			}
		}
	}
	if ( inHand().size() == 0 ) {
		std::cerr << std::endl << "Yahoo!!" << std::endl;
	}
	return true;
}

void ThinkDifferent::sortCardSet() {
	for(int i = 0; i < inHand().size(); i++) {
		for(int j = i; j < inHand().size(); j++) {
			if ( inHand()[i].isGreaterThan(inHand()[j]) ) {
				Card t = inHand()[i];
				inHand()[i] = inHand()[j];
				inHand()[j] = t;
			}
		}
	}
}
