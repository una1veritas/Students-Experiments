/*
 * 大富豪　大会用 main プログラムソース
 */

#include "main.h"

void registAllPlayers(Dealer & d) {
	d.regist(new GroupH());
	d.regist(new LittleThinkPlayer());
	d.regist(new ThinkTA1());
	d.regist(new Player());
	d.regist(new ThinkDifferent());
	d.regist(new GroupC());
}

const char * ordinalSuffix(const int n);
unsigned int strmatch(char * s1, char * s2);
void prompt(bool & flag, const char * messg, const char * expected);


const int NumberOfGames = 10;

#define rankingPoint(n)  (n == 0 ? 0.9f : n+1)

int main(int argc, char * const argv[]) {
	// insert code here...
	std::cout << "Welcomte to the Daihugo world!\n";

	bool autorepeat = false;
	bool autocontinue = false;
	if ( argc >= 2 && strcmp(argv[1],"-skip") == 0 )
		autocontinue = true;

	//

	Dealer d;
	CardSet opened;

	registAllPlayers(d);
	d.hailPlayers();


	for (int g = 1; g < NumberOfGames; g++) {
		std::cout << std::endl << "Game " << g << std::endl;
		d.newGame();
		prompt(autorepeat, "Auto-repeat? ", "yes");

		d.dealAll();
		d.setAsLeader();
		bool passed = true;
		while (true) {
			while (true) {
				if (passed && d.playerInTurnIsLeader()) {
					d.clearDiscardPile();
					prompt(autocontinue, "flushed. auto-continue?", "yes");
					d.show();
				}
				std::cout << "Turn: " << d.playerInTurn().playerName() << " ";

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
					std::cout << "Lead ";
					d.discardPile().printStream(std::cout);
					std::cout << " by "
							<< d.currentLeader().playerName() << ". "
							<< std::endl;
				}

				d.showDiscardedToPlayers();

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
