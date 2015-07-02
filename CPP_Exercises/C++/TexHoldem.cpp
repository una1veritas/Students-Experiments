/*
 * TexHoldem.cpp
 *
 *  Created on: 2015/07/02
 *      Author: sin
 */

#include "TexHoldem.h"

TexHoldem::TexHoldem(void) { deal_cards(); }

void TexHoldem::deal_cards(void) {
	// 各プレーヤの持ち手を空にする
	deck.makeEmpty();
	for(int i = 0; i < numplayers; i++) {
		players[i].makeEmpty();
	}
	board.makeEmpty();

	// 1デッキのカードを deck に入れる
	deck.setupDeck(false);
	deck.shuffle();

  // 無くなるまで deck から無作為にカードをとり plr 番のプレーヤに配る
  int plr = 0;	// 配る相手のプレーヤ
  Card c;		// 配るカード
  for(int ncards = 0; ncards < 2; ncards++) {
	  for(int i = 0; i < numplayers; i++) {
		  deck.pickup(c);
		  players[i].insert(c);
	  }
  }
  for(int i = 0; i < 3; i++) {
	  deck.pickup(c);
	  board.insert(c);
  }
}

void TexHoldem::advance() {
	Card c;
	this->deck.pickup(c);
	board.insert(c);
}
