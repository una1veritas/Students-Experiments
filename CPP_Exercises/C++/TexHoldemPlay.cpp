/*
 * TexHoldemPlay.cpp
 *
 *  Created on: 2015/07/02
 *      Author: sin
 */

#include <iostream>

#include "TexHoldem.h"

int main(int argc, char * argv[]) {

	TexHoldem game;

	for(int i = 0; i < game.numOfPlayers(); i++) {
		std::cout << "Player " << i << ": " << game.inHand(i) << std::endl;
	}
	std::cout << std::endl << "Community cards: " << game.inBoard() << std::endl << std::endl;

	game.advance();
	std::cout << std::endl << "Community cards: " << game.inBoard() << std::endl << std::endl;

	game.advance();
	std::cout << std::endl << "Community cards: " << game.inBoard() << std::endl << std::endl;
return 0; // Exit with no Error.
}

