#include <iostream>
#include <iomanip>
#include <map>

#include <stdio.h>
#include <string.h>

#include "Card.h"
#include "CardSet.h"
#include "Dealer.h"

#include "LittleThinkPlayer.h"
#include "ThinkTA1.h"

int main (int argc, char * const argv[]) {
	
	Dealer d;
	char dummy[32];
	
	std::cout << "Daifugou match starting." << std::endl;
	std::cin.getline(dummy,31); // 標準入力から dummy に改行まで最大31文字を読む

	d.regist(new Player("Player 0"));
	d.regist(new Player("Player 1"));
	d.regist(new Player("Player 2"));
	d.regist(new ThinkTA1("TA"));
	d.regist(new LittleThinkPlayer("Little"));

	d.hailPlayers();

	for (int g = 1; g < 5; g++) {
		std::cout << std::endl << "Starting Game " << g << std::endl;
		d.newGame();
		std::cin.getline(dummy,31);
		d.deal(Dealer::NUM_OF_ALL_CARDS);
		d.setAsLeader(0);
		bool passed = true;
		while (true) {
			while (true) {
				if (passed && d.playerInTurnIsLeader() ) {
					d.clearDiscardPile();
					std::cout << "flushed. " << std::endl;
					std::cin.getline(dummy,31);
					d.show();
				}
				std::cout << d.playerInTurn().playerName() << "'s turn: " << std::endl ;
				CardSet opened;
				GameState state = d.gameState();
				d.playerInTurn().follow(state, opened);
				std::cout << opened;
				if (opened.isEmpty() || !d.accept(opened)) {
					if ( !opened.isEmpty() ) {
						d.playerInTurn().takeCards(opened);
						std::cout << ", rejected";
					}
					std::cout << ", pass.";
					passed = true;
				} else {
					passed = false;
				}
				std::cout << std::endl << std::endl;
				if (!passed) {
					d.setAsLeader();
					std::cout << "--- Lead " << d.discardPile() << " by " << d.currentLeader().playerName() << ". " << std::endl;
				}
				if (d.playerInTurn().isEmptyHanded())
					break;

				d.showDiscardedToPlayers();

				d.nextPlayer();
			}
			std::cout << d.playerInTurn().playerName() << " finished. " << std::endl << std::endl;
			//d.show();
			d.playerInTurnFinished();
			if (d.howManyPlayers() == 1) {
				d.playerInTurnFinished();
				break;
			}
		}
		std::cout << std::endl 
			<< "This game's result: " << std::endl;
		for (int i = 0; i < d.howManyParticipants() ; i++) {
			std::cout << i+1 << ": " << d.player(d.howManyParticipants() - (i + 1) ).playerName() << std::endl;
		}
	}
    return 0;
}
