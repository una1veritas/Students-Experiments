#include <string>
#include <iostream>
#include <iomanip>
#include <map>

#include <stdio.h>

#include "Card.h"
#include "CardSet.h"
#include "Player.h"
#include "LittleThinkPlayer.h"
#include "ThinkTA1.h"
#include "ThinkDifferent.h"
#include "Dealer.h"

/*
#include "GroupA_MT.h"
#include "GroupB.h"
#include "GroupC.h"
#include "GroupD.h"
#include "GroupEPlayer.h"
#include "groupf.h"
#include "GroupG.h"
#include "GroupH.h"
#include "GroupI.h"
*/

const int NumberOfGames = 10;
const int NumberOfPlayers = 5;

int points[] = { 1, 2, 3, 4, 5, 0, 0, 0, 0, 0, 0, 0};

int main(int argc, char * const argv[]) {
	// insert code here...
	std::cout << "Welcomte to the Daihugo world!\n";

	bool prompt_on_newgame = true;
	bool prompt_after_flushed = true;
	if ( argc >= 2 && strcmp(argv[1],"-skip") == 0 )
		prompt_after_flushed = true;

	//

	Dealer d;
	CardSet opened;
	char dummy[16];

	d.regist(new Player("Player"));
	d.regist(new Player("Player 2"));
	d.regist(new LittleThinkPlayer("LittleThinker"));
	d.regist(new ThinkTA1("TAOne"));
	d.regist(new ThinkDifferent("Think different."));
	d.hailThePlayers();

	for (int g = 1; g < NumberOfGames; g++) {
		std::cout << std::endl << "Game " << g << std::endl;
		d.newGame();
		if ( prompt_on_newgame ) {
			std::cout << "start? " << std::endl;
			std::cin.getline(dummy, 15);
			if ( strcmp(dummy, "skip") == 0 )
				prompt_on_newgame = false;
		}
		d.dealAll();
		d.setAsLeader();
		bool passed = true;
		while (true) {
			while (true) {
				if (passed && d.playerInTurnIsLeader()) {
					d.clearDiscardPile();
					if ( prompt_after_flushed ) {
						std::cout << "flushed. " << std::endl << "? ";
						std::cin.getline(dummy, 15);
						if ( strcmp(dummy, "skip") == 0 )
							prompt_after_flushed = false;
					}
					d.letemShow();
				}
				std::cout << "Turn: " << d.playerInTurn().name() << " "; //<< std::endl;
				d.playerInTurn().follow(d.discardPile(), opened);
				std::cout << opened; // the set of opened cards.
				if (opened.isempty() || !d.accept(opened)) {
					if (!opened.isempty()) {
						std::cout << " --- ";
						//d.playerInTurn().takeCards(opened);
						d.putBackOpened(opened);
						std::cout << "Reject; ";
					}
					std::cout << "Pass." << std::endl;
					passed = true;
				} else {
					passed = false;
				}
				std::cout << std::endl;
				if (d.playerInTurn().isEmptyHanded())
					break;
				if (!passed) {
					d.setAsLeader();
					std::cout << "Lead " << d.discardPile().printString() << " by "
							<< d.currentLeader().name() << ". "
							<< std::endl;
				}

				d.showDiscardedAround();

				d.nextPlayer();
			}
			std::cout << d.playerInTurn().name() << " finished. "
					<< std::endl << std::endl;
			//d.letemShow();
			d.playerInTurnFinished();
			if (d.howManyPlayers() == 1) {
				d.playerInTurnFinished();
				break;
			}
		}
		//
		std::cout << std::endl << "This game's result: " << std::endl;
		for (int i = 0; i < d.howManyParticipants(); i++) {
			std::cout << i + 1;
			switch (i + 1) {
			case 1:
				std::cout << "st ";
				break;
			case 2:
				std::cout << "nd ";
				break;
			case 3:
				std::cout << "rd ";
				break;
			default:
				std::cout << "th ";
				break;
			}
			d.playersPoint(d.player(d.howManyParticipants() - i - 1).name()) += points[i];

			std::cout << " player " << d.player(d.howManyParticipants() - i - 1).name()
					<< " total point "
					<< d.playersPoint(d.player(d.howManyParticipants() - i - 1).name())
					<< std::endl;

			std::cout << "place: "
					<< d.player(d.howManyParticipants() - i - 1).name()
					// << " " << ranking[i].point
					<< std::endl;
		}
	}
	std::cout << std::endl << "Now all " << NumberOfGames << " games have been finished." << std::endl;
	std::cout << "Total ranking points: " << std::endl;
	for(int i = 0; i < NumberOfPlayers; i++) {
		std::cout << d.player(i).name() << "\t"
				<< d.playersPoint(d.player(i).name()) << std::endl;
	}
	std::cout << "Bye." << std::endl;

	return 0;
}
