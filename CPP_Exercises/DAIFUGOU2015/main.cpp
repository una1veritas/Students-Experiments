#include "main.h"

int main (int argc, char * const argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
	
	Dealer d;
	char dummy[32];
	
	std::cout << "Ok?" << std::endl;
	std::cin.getline(dummy,31); // dummy に1行，31 文字までよむ．


	d.regist(new Player("Player 0"));
	d.regist(new Player("Player 1"));
	d.regist(new Player("Player 2"));
	d.regist(new ThinkTA1("PlayerTA"));
	d.regist(new LittleThinkPlayer("LTP"));
	d.hailPlayers();

	for (int g = 1; g < 5; g++) {
		std::cout << std::endl << "Game " << g << std::endl;
		d.newGame();
		std::cin.getline(dummy,31);
		d.dealAll();
		d.setAsLeader();
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
				CardSet currentLead(d.discardPile());
				CardSet opened;
				d.playerInTurn().follow(currentLead, opened);
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
				if (d.playerInTurn().isEmptyHanded())
					break;
				if (!passed) {
					d.setAsLeader();
					std::cout << "--- Lead " << d.discardPile() << " by " << d.currentLeader().playerName() << ". " << std::endl;
				}

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
