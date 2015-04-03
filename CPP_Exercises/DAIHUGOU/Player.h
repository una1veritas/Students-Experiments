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

class Dealer;

class Player {
	friend class Dealer;
private:
	CardSet hand;
	int id;
	std::string name;
	
	bool takeCards(CardSet &);

public:
	Player(const char *);
	Player(std::string);
        virtual ~Player(){};
	std::string printString(void) const;
	void setId(int);
	int getId();
	void clearHand();
	bool isEmptyHanded();
	bool pickup(Card );
	CardSet & inHand() { return hand; }
	int size() {return hand.size();}
	std::string getName() {return name;}

	std::string playerName();
	virtual bool follow(CardSet &, CardSet &);
	virtual bool approve(CardSet &, int[]);
	void cardSetOfSameRanks(CardSet &, int){}; /* follow()の際に複数のカードを探す::未実装 */	
	
};

#endif
