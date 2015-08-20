/*
 *  Dealer.cpp
 *  PlayingCard
 *
 *  Created by 下薗 真一 on 09/04/12.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <iostream> 
#include <string>

#include "Card.h"
#include "CardSet.h"
#include "Player.h"
#include "Dealer.h"

// class methods.

Dealer::Dealer() {
	numberOfPlayingPlayers = 0;
	turn = 0;
	players[numberOfPlayingPlayers] = NULL;
	pauper = 0;
	// set rules
	noMillionaire = true;
	return;
}

bool Dealer::checkRankUniqueness(const CardSet & cs) {
	int i = 0;
	int rank = 0;

	if (cs.size() == 0)
		return false;

	if ( cs.size() == 1 && cs.at(0).isJoker() )
		return true;

	for (int i = 0; i < cs.size(); i++) {
	  if (cs.at(i).isJoker())
		  continue;  // Jkrをスキップ
	  if ( rank == 0 ) {
		  rank = cs.at(i).getNumber();
	  } else if ( rank != cs.at(i).getNumber() ) {
	    return false;
	  }
	}
	return true;
}

bool Dealer::cardStrongerThan(const CardSet & left, const CardSet & right) {
	int leftnum, rightnum;

	if (left.isEmpty() && right.isEmpty() )
	  return false;  // regarded as "pass for empty discard pile."

	if (left.size() != right.size())  // the number of cards must be match. no five cards w/ Jkr allowed.
	  return false;

	if (!checkRankUniqueness(left) || !checkRankUniqueness(right))
		return false;

	leftnum = getCardRank(left);
	rightnum = getCardRank(right);

	return leftnum > rightnum;
}

// instance methods.
bool Dealer::regist(Player * pl) {
	int numOfPlayers;
	for (numOfPlayers = 0; players[numOfPlayers]; numOfPlayers++) ;
	players[numOfPlayers] = pl;
	points[numOfPlayers] = 0;
	players[numOfPlayers+1] = NULL;
	return true;
}

Player & Dealer::currentLeader() {
	return * players[leaderIndex];
}

bool Dealer::playerInTurnIsLeader() {
	return leaderIndex == turn;
}

void Dealer::newGame() {
	numberOfPlayingPlayers = howManyParticipants();
	if ( !noMillionaire )
		pauper = 0;
	//
	for (int p = 0; players[p] ; p++) {
		players[p]->inHand().clear();
		players[p]->ready();
	}
}

void Dealer::setAsLeader(void) {
	leaderIndex = turn;
}

void Dealer::setAsLeader(const int id) {
	turn = id;
	leaderIndex = turn;
}

bool Dealer::deal(int c) {
	Card top;

	for (int p = 0; players[p] ; p++) {
		players[p]->clearHand();
	}
	theDeck.setupDeck();
	theDeck.shuffle();
	for (int i = 0; i < c; i++) {
		for (int p = 0; p < numberOfPlayingPlayers; p++) {
			if ( theDeck.isEmpty() )
				break;
			theDeck.pickup(top, 0);
			players[ (numberOfPlayingPlayers - 1 - p) % numberOfPlayingPlayers]->pickup(top);
		}
	}
	return true;
}

void Dealer::clearDiscardPile() {
	discarded.makeEmpty(); //clear();
}

const CardSet & Dealer::discardPile() {
	return discarded;
}


bool Dealer::accept(CardSet & opened) {
    int openedRank, discardedRank;

	if (discarded.isEmpty() && opened.isEmpty() )
	  return false;  // regarded as "pass for empty discard pile."

	if (!discarded.isEmpty() && discarded.size() != opened.size())  // the number of cards must be match. no five cards w/ Jkr allowed.
	  return false;
	
	if (!checkRankUniqueness(opened))
	  return false;
	
	openedRank = getCardRank(opened);

	if (!discarded.isEmpty()) // 場にカードがでていないのであれば無条件に受理
	  if ( !(openedRank > discardedRank) )
	    return false;
	

	// passed all the checks.

	discarded.makeEmpty(); //clear();
	discarded.insert(opened); //	discarded.insertAll(opened);
	opened.makeEmpty(); //clear();
	discardedRank=openedRank;

	return true;
}

int Dealer::getCardRank(const CardSet & cs){
  	for (int i = 0; i < cs.size(); i++) {
	  if (!cs.at(i).isJoker()){ return cs.at(i).getNumber(); }
	}
	return cs.at(0).getNumber();
}

void Dealer::showDiscardedToPlayers() {
	GameState gstat = gameState();
	for (int i = 1; i < numberOfPlayingPlayers; i++) {
		players[(turn + i) % numberOfPlayingPlayers]->approve(gstat);
	}
	return;
}

void Dealer::withdrawPlayer(int i) {
	Player * p;
	p = players[i];
	for ( ; i+1 < numberOfPlayingPlayers; i++) {
		players[i] = players[i+1];
	}
	if (pauper == numberOfPlayingPlayers) {
		players[i] = players[i+1];
		i++;
		pauper--;
	}
	players[i] = p;
	numberOfPlayingPlayers--;
	if (numberOfPlayingPlayers > 0) {
		turn = turn % numberOfPlayingPlayers;
		leaderIndex = leaderIndex % numberOfPlayingPlayers;
	}
}

Player & Dealer::playerInTurnFinished() {
	//int i;
	bool bankrupt = false;
	
	Player * p = 0;
	if (numberOfPlayingPlayers == howManyParticipants()
		// the first finished person is not the millionaire 
			) { 
		if (turn != howManyParticipants() - 1)
			bankrupt = true;
		withdrawPlayer(turn); // millionaire
		if ( bankrupt && !noMillionaire) {
			pauper = numberOfPlayingPlayers-1;
			withdrawPlayer(pauper);
		}
		// 次の１行をコメントアウトすると 都落ちなし
		// noMillionaire = false;
		return *players[pauper];
	}
	withdrawPlayer(turn);
	show();
	return *p;
}


int Dealer::howManyParticipants() const {
	int i;
	for (i = 0; players[i]; i++) {}
	return i;
}

Player & Dealer::player(int i) {
	return *players[i];
}


int Dealer::numberOfFinishedPlayers() {
	return howManyParticipants() - numberOfPlayingPlayers;
}

Player & Dealer::playerInTurn() {
	return * players[turn];
}

Player & Dealer::nextPlayer() {
	turn = (turn+1) % numberOfPlayingPlayers;
	return * players[turn];
}

void Dealer::show() {
		for (int p = 0; players[p] ; p++) {
			if ( p==numberOfPlayingPlayers)
				std::cout << "-------" << std::endl;
			if ( p == pauper )
				std::cout << "* ";
			else if ( players[p+1] == NULL)
				std::cout << "$ ";
			else 
				std::cout << "  ";
			players[p]->printOn(std::cout);
			std::cout << std::endl;
		}
		std::cout << std::endl;
}

void Dealer::putBackOpened(CardSet & opened) {
	players[turn]->takeCards(opened);
}

GameState Dealer::gameState(void) const {
	GameState gstat;
	gstat.pile = discarded;
	gstat.inTurn = turn;
	gstat.nofPlayers = numberOfPlayingPlayers;
	for (int i = 0; i < howManyParticipants(); i++)
		gstat.nofCards[i] = players[i]->size();
	for (int i = 0; i < howManyParticipants(); i++)
		gstat.playerIDs[i] = players[i]->id;
	gstat.leader = leaderIndex;
	return gstat;
}

