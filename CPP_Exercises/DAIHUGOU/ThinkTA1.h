/*
 *  ThinkTA.h
 *  PlayingCard
 *
 *  Created by TA (Ryosuke Tadano) @ 2009
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

class ThinkTA1 : public Player {

public:
	ThinkTA1(const char *);
	bool follow(CardSet &, CardSet &);
	bool approve(CardSet &, int[] );
	bool sort(CardSet&);
};
