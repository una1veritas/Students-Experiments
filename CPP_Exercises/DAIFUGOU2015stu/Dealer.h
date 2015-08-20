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
	const static int NUM_OF_MAX_PLAYERS = 8;

private:
	CardSet theDeck;
	CardSet discarded;
	
	Player * players[NUM_OF_MAX_PLAYERS];
	float points[NUM_OF_MAX_PLAYERS];
	int numberOfPlayingPlayers;
	int pauper;
	int turn;
	int leaderIndex;

	// Rule flags
	bool noMillionaire;

public:
	Dealer();

	static bool cardStrongerThan(const CardSet & left, const CardSet & right);
	static bool checkRankUniqueness(const CardSet &);
	static int getCardRank(const CardSet &);

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

//	void replaceWith(CardSet &, CardSet &);
	const CardSet & discardPile();
	void clearDiscardPile();
	bool playerInTurnIsLeader();
	void setAsLeader(void);
	void setAsLeader(const int id);
	Player & player(int);
	int numberOfFinishedPlayers();
	void withdrawPlayer(int);

	float & point(const int id) { return points[id]; }

	Player & playerInTurnFinished();
	
	Player & playerInTurn();
	Player & nextPlayer();
	Player & currentLeader();
	
	void putBackOpened(CardSet &);

	GameState gameState(void) const;

};

#endif
