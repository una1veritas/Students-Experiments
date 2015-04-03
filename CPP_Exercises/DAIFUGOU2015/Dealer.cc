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

Dealer::Dealer() {
	numberOfPlayers = 0;
	players[numberOfPlayers] = NULL;
	pauper = 0;
	for (int i = 0; i < 11; i++) { numberOfCards[i] = 0; }
	// set rules
	noMillionaire = true;
	return;
}

bool Dealer::regist(Player * pl) {
	int i;
	for (i = 0; players[i]; i++) ;
	players[i] = pl;
	players[i]->setId(i);
	rankingById[players[i]->getId()] = 0;
	players[i+1] = NULL;
	pauper = 0;
	noMillionaire = true;
	return true;
}

Player & Dealer::currentLeader() {
	return * players[leaderIndex];
}

bool Dealer::playerInTurnIsLeader() {
	return leaderIndex == turn;
}

void Dealer::newGame() {
	numberOfPlayers = howManyParticipants();
	if ( !noMillionaire )
		pauper = 0;
	//
	for (int p = 0; players[p] ; p++) {
		players[p]->startNewGame();
	}
}

void Dealer::setAsLeader() {
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
		for (int p = 0; p < numberOfPlayers; p++) {
			if ( theDeck.isEmpty() )
				break;
			theDeck.pickup(top, 0);
			players[ (numberOfPlayers - 1 - p) % numberOfPlayers]->pickup(top);
			numberOfCards[(numberOfPlayers - 1 - p) % numberOfPlayers]++;
		}
	}
	turn = 0;
	return true;
}

bool Dealer::dealAll() {
	return deal(53);
}

void Dealer::clearDiscardPile() {
	discarded.clear();
}

const CardSet & Dealer::discardPile() {
	return discarded;
}

bool Dealer::accept(CardSet & opened) {
        Card openedRank;

	if (discarded.isEmpty() && opened.isEmpty() )
	  return false;  // regarded as "pass for empty discard pile."

	if (!discarded.isEmpty() && discarded.size() != opened.size())  // the number of cards must be match. no five cards w/ Jkr allowed.
	  return false;
	
	if (!checkRankUniqueness(opened))
	  return false;
	
	openedRank = getCardRank(opened);

	if (!discarded.isEmpty()) // 場にカードがでていないのであれば無条件に受理
	  if (!openedRank.isGreaterThan(discardedRank)) 
	    return false;
	

	// passed all the checks.

   discarded.clear();
	discarded.insertAll(opened);
	opened.clear();
	discardedRank=openedRank;

	return true;
}

Card Dealer::getCardRank(CardSet & cs){
  	for (int i = 0; i < cs.size(); i++) {
	  if (!cs[i].isJoker()){return cs[i];}
	}
	return cs[0];
}

bool Dealer::checkRankUniqueness(CardSet & cs) {
	int j = 0;
	if (cs.size() == 0)
		return false;
	if (cs[j].isJoker())
		j++;
	for (int i = j+1; i < cs.size(); i++) {
	  if (cs[i].isJoker()){continue;} // 追加：途中にJkrを許す
	  if (cs[j].getRank() != cs[i].getRank() )
	    return false;
	}
	return true;
}

void Dealer::showDiscardedToPlayers() {
	CardSet aCopy(discarded);
  for (int i = 0, j=0; i < howManyParticipants(); i++) {
    if (numberOfCards[i] == 0){
      continue;
    }
    numberOfCards[players[j]->getId()]=players[j]->size();
    j++;
  }
  numberOfCards[howManyParticipants()] = Player::NO_MORE_PLAYERS;

  for (int i = 1; i < numberOfPlayers; i++) {
    players[(turn + i) % numberOfPlayers]->approve(aCopy, numberOfCards);
  }
  return; 
}

void Dealer::withdrawPlayer(int i) {
	Player * p;
	p = players[i];
	for ( ; i+1 < numberOfPlayers; i++) {
		players[i] = players[i+1];
	}
	if (pauper == numberOfPlayers) {
		players[i] = players[i+1];
		i++;
		pauper--;
	}
	players[i] = p;
	numberOfPlayers--; 
	if (numberOfPlayers > 0) {
		turn = turn % numberOfPlayers;
		leaderIndex = leaderIndex % numberOfPlayers;
	}
}

Player & Dealer::playerInTurnFinished() {
	//int i;
	bool bankrupt = false;
	
	Player * p = 0;
	numberOfCards[players[turn]->getId()]=0;
	if (numberOfPlayers == howManyParticipants() 
		// the first finished person is not the millionaire 
			) { 
		if (turn != howManyParticipants() - 1)
			bankrupt = true;
		withdrawPlayer(turn); // millionaire
		if ( bankrupt && !noMillionaire) {
			pauper = numberOfPlayers-1;
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


int Dealer::howManyParticipants() {
	int i;
	for (i = 0; players[i]; i++) {}
	return i;
}

Player & Dealer::player(int i) {
	return *players[i];
}


int Dealer::numberOfFinishedPlayers() {
	return howManyParticipants() - numberOfPlayers;
}

Player & Dealer::playerInTurn() {
	return * players[turn];
}

Player & Dealer::nextPlayer() {
	turn = (turn+1) % numberOfPlayers;
	return * players[turn];
}

void Dealer::show() {
		for (int p = 0; players[p] ; p++) {
			if ( p==numberOfPlayers)
				std::cout << "-------" << std::endl;
			if ( p == pauper )
				std::cout << "* ";
			else if ( players[p+1] == NULL)
				std::cout << "$ ";
			else 
				std::cout << "  ";
			players[p]->printStream(std::cout);
			std::cout << std::endl;
		}
		std::cout << std::endl;
}

void Dealer::putBackOpened(CardSet & opened) {
	players[turn]->takeCards(opened);
}

