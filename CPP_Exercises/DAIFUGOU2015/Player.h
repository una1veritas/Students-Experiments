/*
 *  Player.h
 *  PlayingCard
 *
 *  Created by 下薗 真一 on 09/04/12.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "GameStatus.h"

/*
 * プレイヤークラスの基底クラス．
 * Player を public の基底クラスとし，グループのプレイヤーを拡張クラスとして
 * 実装する．
 * 他のグループのプレイヤークラス，大会プログラムと互換性がなくなりコンパイルできなく
 * なる可能性があるので，Player クラスの定義とソースコードは，変更しないこと．
 */
class Player {
	friend class Dealer;
private:
	int id;
	std::string name;

protected:
	CardSet hand;

public:
	bool takeCards(CardSet &);

	static const int NO_MORE_PLAYERS = -1;

public:
	Player(const char * myname = "Novita");
    virtual ~Player() { }

	void setId(int);
	int getId();

	void clearHand();
	bool isEmptyHanded();

	bool pickup(Card );
	CardSet & inHand() { return hand; }
	int size() { return hand.size(); }
	std::string getName() { return name; }
	std::string playerName();

	virtual void startNewGame(void) { hand.makeEmpty(); } // hand.clear(); }

	virtual bool follow(CardSet & pile, CardSet & cards, GameStatus & status);
	virtual bool approve(CardSet & pile, int cardnum[] );

	// backward compatibility
	virtual bool follow(CardSet & pile, CardSet & cards) {
		GameStatus status;
		return follow(pile, cards, status);
	}

	std::ostream & printStream(std::ostream & out) const;

};

#endif
