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

<<<<<<< HEAD
#include "GameStatus.h"
=======
#include "GameState.h"
>>>>>>> master

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
	virtual bool takeCards(CardSet &);

	static const int NO_MORE_PLAYERS = -1;

public:
	Player(const char * myname = "Novita");
    virtual ~Player() { }

	void setId(int);
<<<<<<< HEAD
	int getId();
	bool isEmptyHanded();
	void clearHand();

=======
	int getId() const;
	void clearHand();
	bool isEmptyHanded() const;
>>>>>>> master
	bool pickup(Card );
	CardSet & inHand() { return hand; }
	int size() const { return hand.size(); }
	std::string playerName() const { return name; }

<<<<<<< HEAD
	virtual void startNewGame(void) { hand.clear(); }
	virtual bool approve(CardSet & pile, int cardnum[] );

	virtual bool follow(CardSet & pile, CardSet & cards, GameStatus & status);

	// backward compatibility
	virtual bool follow(CardSet & pile, CardSet & cards) {
		GameStatus status;
		return follow(pile, cards, status);
	}

	std::ostream & printStream(std::ostream & out) const;
=======
	std::ostream & printOn(std::ostream & out) const;

	// 拡張した派生クラスでオーバーライドする関数
	virtual void ready(void) { }
	virtual bool follow(const GameState & gstat, CardSet & cards);
	virtual bool approve(const GameState & gstat);
>>>>>>> master

};

#endif
