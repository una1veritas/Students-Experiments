/*
 * 大富豪　大会用 main プログラムソース
 */

#include <cstdlib>
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

#include "Group1.h"
#include "Group2.h"
#include "Group3.h"
#include "Group4.h"
#include "Group5.h"
#include "Group6.h"
#include "Group7.h"


void registAllPlayers(Dealer & d) {
	d.regist(new Group1("Group 1"));
//	d.regist(new Group2("Group 2"));
//	d.regist(new Group3("Group 3"));
	d.regist(new Group4("Group 4"));
//	d.regist(new n231054s("Group 5"));
	d.regist(new Group6("Group 6"));
	d.regist(new Group7("Group 7"));
//	d.regist(new ThinkTA1());
}

const char * ordinalSuffix(const int n);
unsigned int strmatch(char * s1, char * s2);
void prompt(bool & flag, const char * messg, const char * expected);


#define rankingPoint(n)  (n == 0 ? 0.9f : n+1)

int main(int argc, char * const argv[]) {
	int NumberOfGames = 10;
	// insert code here...
	std::cout << "Welcomte to the Daihugo world!\n";

	bool autorepeat = false;
	bool autocontinue = false;
	for (int i = 1; i < argc; i++) {
		if ( strcmp(argv[i],"-skip") == 0 )
			autocontinue = true;
		else if ( atoi(argv[i]) != 0 )
			NumberOfGames = atoi(argv[i]);
	}
	//

	Dealer d;
	CardSet opened;

	registAllPlayers(d);
	d.hailPlayers();

	for (int g = 0; g < NumberOfGames; g++) {
		std::cout << std::endl << "Game " << g << std::endl;
		d.newGame();
		prompt(autorepeat, "Auto-repeat? ", "yes");

		d.deal(Dealer::NUM_OF_ALL_CARDS);
		// now random seed is set by shuffle(void) in deal() function.
		d.setAsLeader();
		bool passed = true;
		while (true) {
			while (true) {
				if (passed && d.playerInTurnIsLeader()) {
					d.clearDiscardPile();
					prompt(autocontinue, "flushed. auto-continue?", "yes");
					d.show();
				}
				std::cout << std::endl << "Turn: " << d.playerInTurn().playerName() << " ";
				GameState state = d.gameState();
				d.playerInTurn().follow(state, opened);
				std::cout << opened; // the set of opened cards.
				if (opened.isEmpty() || !d.accept(opened)) {
					if (!opened.isEmpty()) {
						std::cout << " --- ";
						//d.playerInTurn().takeCards(opened);
						d.putBackOpened(opened);
						std::cout << "Reject; ";
					}
					std::cout << " Pass." << std::endl;
					passed = true;
				} else {
					passed = false;
				}
				std::cout << std::endl;
				std::cout.flush();

#error "darekaga agatta baai, aprove ga yobarenai."

				if (d.playerInTurn().isEmptyHanded())
					break;
				if (!passed) {
					d.setAsLeader();
					std::cout << "Lead " << d.discardPile();
					std::cout.flush();
					std::cout << " by "
							<< d.currentLeader().playerName() << ". "
							<< std::endl;
				}
				std::cout.flush();
				d.showDiscardedToPlayers();
				std::cout.flush();

				d.nextPlayer();
			}
			std::cout << d.playerInTurn().playerName() << " finished. "
					<< std::endl << std::endl;
			//d.show();
			d.playerInTurnFinished();
			if (d.howManyPlayers() == 1) {
				d.playerInTurnFinished();
				break;
			}
		}
		//
		std::cout << std::endl << "This game's result: " << std::endl;
		for (int i = 0; i < d.howManyParticipants(); i++) {
			std::cout << i + 1 << ordinalSuffix(i+1) << " ";
			Player & ithplayer = d.player(d.howManyParticipants() - (i + 1) );
			d.point(ithplayer.getId()) += rankingPoint(i);

			std::cout << "place: "
					<< ithplayer.playerName()
					<< ", total rank "
					<< d.point(ithplayer.getId())
					<< std::endl;

		}
	}
	std::cout << std::endl << "Now all " << NumberOfGames << " games have been finished." << std::endl;
	std::cout << "Total ranking points: " << std::endl;
	for(int i = 0; i < d.howManyParticipants(); i++) {
		std::cout << d.player(i).playerName() << "\t"
				<< d.point(d.player(i).getId()) << std::endl;
	}
	std::cout << "Bye." << std::endl;

	return 0;
}

const char * ordinalSuffix(const int n) {
	const char * suff[] = {
			"", "st", "nd", "rd", "th"
	};
	if ( n >= 4 )
		return suff[4];
	return suff[n];
}

unsigned int strmatch(const char * p1, const char * p2) {
	unsigned int res = 0;
	for ( ; *p1 && *p2; p1++, p2++) {
		if ( toupper(*p1) == toupper(*p2) )
			res++;
	}
	return res;
}

void prompt(bool & flag, const char * messg, const char * expected) {
	char dummy[16];

	if ( flag )
		return;
	std::cout << messg << std::endl;
	std::cin.getline(dummy, 15);
	if ( strmatch(dummy, expected) > 0 )
		flag = true;
	return;
}
