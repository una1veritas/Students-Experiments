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

#include "Player.h"

struct GameStatus {
	static const int MAXIMUM_NUM_OF_PLAYERS = 8;
	int numOfPlayers;
	int numOfCards[MAXIMUM_NUM_OF_PLAYERS];
	int pauperOfThisGame;
	int inTurnPlayer;
	int leadingPlayer;
	CardSet lead;

	GameStatus(int nofp, int nofc[], int pog, int cl) :
		numOfPlayers( nofp > MAXIMUM_NUM_OF_PLAYERS ? MAXIMUM_NUM_OF_PLAYERS : nofp),
		pauperOfThisGame(pog), currentLeader(cl)
	{
		for(int i = 0; i < numOfPlayers; i++) {
			numOfCards[i] = nofc[i];
		}
	}

};

class Dealer {
	CardSet theDeck;
	CardSet discarded;
	Card discardedRank;
	
	Player * players[8];
	float rankingById[8];
	int numberOfPlayers;
	int pauper;
	int turn;
	int leaderIndex;
	int numberOfCards[8];

	// Rule flags
	bool noMillionaire;

public:
	Dealer();

	void newGame();
	bool regist(Player *);
	bool deal(int);
	bool dealAll();
	void show();
	
	int howManyPlayers() { return numberOfPlayers; }
	int howManyParticipants();
		
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
	void setAsLeader();
	Player & player(int);
	int numberOfFinishedPlayers();
	void withdrawPlayer(int);

	float & point(const int id) { return rankingById[id]; }

	Player & playerInTurnFinished();
	
	Player & playerInTurn();
	Player & nextPlayer();
	Player & currentLeader();
	
	void putBackOpened(CardSet &);
};

#endif
