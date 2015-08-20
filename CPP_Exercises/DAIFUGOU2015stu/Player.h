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

#include "GameState.h"

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

//	void setId(int); 		// depricated.
//	int getId() const;	// depricated.
	void clearHand();
	bool isEmptyHanded() const;
	bool pickup(Card );
	CardSet & inHand() { return hand; }
	int size() const { return hand.size(); }
	std::string playerName() const { return name; }

	std::ostream & printOn(std::ostream & out) const;

	// 拡張した派生クラスでオーバーライドする関数
	virtual void ready(void) { }
	virtual bool follow(const GameState & gstat, CardSet & cards);
	virtual bool approve(const GameState & gstat);

};

#endif
