//
//
// cardsetextra.cc - トランプカードの集合型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <iostream>
#include "cardset.h"

//
// main() - トランプカードの集合型テストプログラム
//

int main(int argc, char * const argv[]) {

	Card card;
	CardSet cs;
	char buf[16];
	int st, num;
	const char * suitnames[] = {
			"spade",
			"diamond",
			"heart",
			"club",
			"joker"
	};

	cs.print();
	// 入力がエラーになるまで指定したカードを入れる
	do {
		std::cout << "card = ? ";
		std::cin >> buf;
		for(st = 0; st < Card::SUIT_NUMBER; st++) {
			if ( strcmp(suitnames[st], buf) == 0 )
				break;
		}
		if ( st >= Card::SUIT_NUMBER ) {
			std::cout << "Wrong suit name." << std::endl;
			break;
		}
		if ( st != Card::SUIT_JOKER )
		  std::cin >> num;
		card.set(st, num);
		if ( !card.isValid() )
			break;
		if ( cs.insert(card) )
			std::cout << "\t" << "insert error" << std::endl;
	} while (1);
	cs.print();

	do {
	        std::cout << "card = ? ";
		std::cin >> buf;
		for(st = 0; st < Card::SUIT_NUMBER; st++) {
			if ( strcmp(suitnames[st], buf) == 0 )
				break;
		}
		if ( st >= Card::SUIT_NUMBER ) {
			std::cout << "Wrong suit name." << std::endl;
			break;
		}
		if ( st != Card::SUIT_JOKER )
		  std::cin >> num;
		card.set(st, num);
		if ( !card.isValid() )
			break;
		if ( cs.remove(card) )
			std::cout << "\t" << "remove error" << std::endl;
	} while (1);
	cs.print();

	return 0;
}
