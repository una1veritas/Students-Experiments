/*
 *  Dealer.h
 *  PlayingCard
 *
 *  Created by 下薗 真一 on 09/04/12.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef _DEALER_H_
#define _DEALER_H_

#include "GameState.h"
#include "Player.h"

class Dealer {
public:
	const static int NUM_OF_ALL_CARDS = 53;

private:
	CardSet theDeck;
	CardSet discarded;
	Card discardedRank;
	
	Player * players[8];
	float rankingById[8];
	int numberOfPlayingPlayers;
	int pauper;
	int turn;
	int leaderIndex;

	// Rule flags
	bool noMillionaire;

public:
	Dealer();

	void newGame();
	bool regist(Player *);
	bool deal(int);
	void show();
	
	int howManyPlayers() const { return numberOfPlayingPlayers; }
	int howManyParticipants() const;
		
	void hailPlayers() { return; }
	void showDiscardedToPlayers();
	void chooseLeader();
	
	void promptNext(CardSet & t);
	
	bool accept(CardSet & opened);
	bool checkRankUniqueness(CardSet &);
	Card getCardRank(CardSet &);

//	void replaceWith(CardSet &, CardSet &);
	const CardSet & discardPile();
	void clearDiscardPile();
	bool playerInTurnIsLeader();
	void setAsLeader(void);
	void setAsLeader(const int id);
	Player & player(int);
	int numberOfFinishedPlayers();
	void withdrawPlayer(int);

	float & point(const int id) { return rankingById[id]; }

	Player & playerInTurnFinished();
	
	Player & playerInTurn();
	Player & nextPlayer();
	Player & currentLeader();
	
	void putBackOpened(CardSet &);

	GameState gameState(void) const;

};

#endif
