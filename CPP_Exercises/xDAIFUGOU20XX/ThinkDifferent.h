/*
 *  Player.h
 *  PlayingCard
 *
 *  Created by 下薗 真一 on 09/04/12.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

class ThinkDifferent : public Player {

public:
	ThinkDifferent() : Player("Diffy") { }

	virtual bool follow(CardSet &, CardSet &);
	virtual bool approve(CardSet &, int[]);
	
	void sortCardSet();
	int countInHand(int rank);
};
