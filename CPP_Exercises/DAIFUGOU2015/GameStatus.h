/*
 * GameStatus.h
 *
 *  Created on: 2015/05/07
 *      Author: sin
 */

#ifndef GAMESTATUS_H_
#define GAMESTATUS_H_



struct GameStatus {
	static const int MAXIMUM_NUM_OF_PLAYERS = 8;

	int numOfPlayers;
	int numOfCards[MAXIMUM_NUM_OF_PLAYERS];
	int pauperOfThisGame;
	int currentLeader;

	GameStatus(void) { numOfPlayers = 0; numOfCards[0] = 0; }  // Empty instance

	GameStatus(const int nofp, const int * nofc, const int pog, const int cl) :
		numOfPlayers( nofp > MAXIMUM_NUM_OF_PLAYERS ? MAXIMUM_NUM_OF_PLAYERS : nofp),
		pauperOfThisGame(pog), currentLeader(cl)
	{
		for(int i = 0; i < numOfPlayers; i++) {
			numOfCards[i] = nofc[i];
		}
	}

	std::ostream & printOn(std::ostream & out) {
		out << "Game status: ";
		out << "Num. of cards = [";
		for(int i = 0; i < numOfPlayers; i++) {
			out << numOfCards[i];
			out << " ";
		}
		out << "], ";
		out << "current leader = ";
		out << currentLeader;

		out << std::endl;
		return out;
	}
};



#endif /* GAMESTATUS_H_ */
