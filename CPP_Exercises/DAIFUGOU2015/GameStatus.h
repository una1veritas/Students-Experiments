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

	CardSet pile;
	int nofPlayers;
	int inTurn;
	int leader;
	int nofCards[MAXIMUM_NUM_OF_PLAYERS];
	int playerIDs[MAXIMUM_NUM_OF_PLAYERS];

	GameStatus(void) { nofPlayers = 0; }  // Empty instance

	std::ostream & printOn(std::ostream & out) const {
		out << "Game status: ";
		out << "pile " << pile << ", ";
		out << nofPlayers << " players, ";
		out << inTurn << "'s turn, ";
		out << "cards = [";
		for(int i = 0; i < nofPlayers; i++) {
			out << nofCards[i];
			out << " ";
		}
		out << "], ";
		out << "IDs = [";
		for(int i = 0; i < nofPlayers; i++) {
			out << playerIDs[i];
			out << " ";
		}
		out << "], ";
		out << "leader = ";
		out << leader;

		out << std::endl;
		return out;
	}

	// おまけ
	friend std::ostream & operator<<(std::ostream& ostr, const GameStatus & stat) {
		return stat.printOn(ostr);
	}

};

#endif /* GAMESTATUS_H_ */
