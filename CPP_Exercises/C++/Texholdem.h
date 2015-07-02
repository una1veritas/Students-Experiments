/*
 * Texholdem.h
 *
 *  Created on: 2015/07/02
 *      Author: sin
 */

#ifndef TEXHOLDEM_H_
#define TEXHOLDEM_H_

#include <iostream>

#include "CardSet.h"

class TexHoldem {
private:
	static const int numplayers = 3;

private:
	CardSet deck;
	CardSet players[numplayers];  // 各プレーヤの持ち手
	CardSet board;

public:
	TexHoldem(void);

private:
	void deal_cards(void);

public:
	int numOfPlayers(void) const { return numplayers; }

	const CardSet & inHand(int id) const {
		return players[id];
	}

	const CardSet & inBoard() const {
		return board;
	}

	void advance(void);
};

#endif /* TEXHOLDEM_H_ */
