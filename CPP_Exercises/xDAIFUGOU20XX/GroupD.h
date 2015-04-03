/*
 *  Player.h
 *  PlayingCard
 *
 *  Created by  GroupD on 13/05/16.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

class GroupD : public Player {
  CardSet memory;

public:
  GroupD(const char *);
	bool follow(CardSet &, CardSet &);
	bool approve(CardSet &, int[]);
	bool cardSetOfSameRanks(CardSet &, int, int);
};
