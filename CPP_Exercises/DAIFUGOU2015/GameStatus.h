/*
 * GameStatus.h
 *
 *  Created on: 2015/05/07
 *      Author: sin
 */

#ifndef GAMESTATUS_H_
#define GAMESTATUS_H_

#include "Card.h"
#include "CardSet.h"

struct GameStatus {
	static const int MAXIMUM_NUM_OF_PLAYERS = 8;

	CardSet currentPile;
	int playerInTurn;
	int numOfPlayers;
	int numOfCards[MAXIMUM_NUM_OF_PLAYERS];
	int currentLeader;

	GameStatus(void) { numOfPlayers = 0; numOfCards[0] = 0; }  // Empty instance

	GameStatus(const CardSet & pile, const int inturn, const int nofp, const int * nofc, const int cl) :
		currentPile(pile), playerInTurn(inturn), numOfPlayers(nofp), currentLeader(cl)
	{
		for(int i = 0; i < numOfPlayers; i++) {
			numOfCards[i] = nofc[i];
		}
	}

	std::ostream & printOn(std::ostream & out) const {
		out << "Game status: ";
		out << numOfPlayers << " players, ";
		out << playerInTurn << "'s turn, ";
		out << "cards = [";
		for(int i = 0; i < numOfPlayers; i++) {
			out << numOfCards[i];
			out << " ";
		}
		out << "], ";
		out << "leader = ";
		out << currentLeader;

		out << std::endl;
		return out;
	}

	// おまけ
	friend std::ostream & operator<<(std::ostream& ostr, const GameStatus & stat) {
		return stat.printOn(ostr);
	}

};



#endif /* GAMESTATUS_H_ */
