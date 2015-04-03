/*
 *  Player.h
 *  PlayingCard
 *
 *  Created by 下薗 真一 on 09/04/12.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

class LittleThinkPlayer : public Player {
  CardSet memory;

public:
	LittleThinkPlayer(const char *);
	bool follow(CardSet &, CardSet &);
	bool approve(CardSet &, int[]);
	
};
