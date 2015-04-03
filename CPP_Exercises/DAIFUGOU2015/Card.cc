//
// Card.cpp - トランプカード(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <string>
#include <sstream>

#include "Card.h"

//クラス定数の初期化。
const char Card::suitname[][8] = { "Spade", "Diamond", "Heart", "Club", "Joker" };
const char Card::suitabbrevname[][4] = { "S", "D", "H", "C", "Jkr" };

//
// Card::scan() - 標準出力から自身に入力する(true: エラー; false: 正常終了)
//
Card::Card(const char * str)
{
	std::stringstream input(str);
	char buf[16];
	int i;

	input >> buf; // skip delimiters in the head.
	switch (buf[0]) {
	case 'S':
		suit = SUIT_SPADE;
		break;
	case 'D':
		suit = SUIT_DIAMOND;
		break;
	case 'H':
		suit = SUIT_HEART;
		break;
	case 'C':
		suit = SUIT_CLUB;
		break;
	case 'J':
		suit = SUIT_JOKER;
		break;
	default:
		suit = SUIT_INVALID;
		break;
	}
	if (suit == SUIT_INVALID) {
		rank = RANK_INVALID;
		return;
	}

	for (i=0; isalpha(buf[i]); i++ ) {}
	for (; isspace(buf[i]); i++ ) {}
	rank = atoi(buf+i);
//	std::cout << "Hey !" << *this << std::endl;
	/*

	// 4組のいずれかなら番号も入力する
	if(scanf("%s", buf) < 1)
		return true;
	for(int s = SUIT_SPADE; s <= SUIT_CLUB; s++)
		if(!strcmp(buf, suitname[s]) || !strcmp(buf, suitabbrevname[s])) {
			suit = s;
			if(scanf("%d", &rank) < 1)
				return true;
			if(rank < 1 || rank > 13)
				return true;
			return false;
		}
// joker はそのまま(rank は 0 とする)
	if(!strcmp(buf, "joker")) {
		suit = SUIT_JOKER;
		rank = 0x0f;
		return false;
	}

	return true;	// エラー
	*/
}

bool Card::isGreaterThan(Card another) {
	if (suit == SUIT_JOKER)
		return true;
	if (another.suit == SUIT_JOKER)
		return false;
	return (rank + 10) % 13 > (another.rank + 10) % 13;
}

//
// Card::print() - 自身の値を標準出力に出力する
//
void Card::print(void)
{
	const char* suitname[] = { "S", "D", "H", "C" };
	const char* symbol[] = { " X", " A", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K" };

	if(suit < SUIT_JOKER)
		printf("[%s%s]", suitname[suit], symbol[rank]);
	else if(suit == SUIT_JOKER)
		printf("[Jkr]");
}

std::ostream& Card::printOn(std::ostream& out) const {
	const char* suitname[] = { "S", "D", "H", "C", " " };
	const char* symbol[] = { "  ", " A", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K" };
	out << '[';
	switch (suit) {
	case SUIT_SPADE:
	case SUIT_DIAMOND:
	case SUIT_HEART:
	case SUIT_CLUB:
		out << suitname[suit] << symbol[rank];
		break;
	case SUIT_JOKER:
		out <<  "Jkr";
		break;
	default:
		out << "XXX";
		break;
	}
	out << ']';
	return out;
}
