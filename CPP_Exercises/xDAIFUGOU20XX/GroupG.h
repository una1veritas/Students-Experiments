/*
 *  Player.h
 *  PlayingCard
 *
 *  Created by 下薗 真一 on 09/04/12.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

class GroupG : public Player {
	CardSet memory;
	CardSet restCards;

	// 追加メンバ変数
	int myCardSize;
	int *rivalCardSize;

public:
	GroupG(const char * name = "George");

	bool follow(CardSet &, CardSet &);
	bool approve(CardSet &, int[]);
	
	// 追加メンバ関数
	void removeCards(CardSet &, CardSet);

	void sort(CardSet &);
	void printDetail();

	void think(CardSet, int &, int &);
	int getRevisedRank(int);
	int getGreater(Card, int);
	int getSizeOfSameRankCard(CardSet, int);
	void setRankCombination(int, int, int);
	int getMinCardSize();

	void sendCard(int, int, CardSet &);
};
