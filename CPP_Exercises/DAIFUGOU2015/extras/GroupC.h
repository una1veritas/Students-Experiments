/*
 *  Player.h
 *  PlayingCard
 *
 *  Created by 下薗 真一 on 09/04/12.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

class GroupC : public Player {
  CardSet memory;

public:
	GroupC(const char name[] = "Charlie") : Player(name) {}
	bool follow(CardSet &, CardSet &);
	bool approve(CardSet &, int[]);
	
};
