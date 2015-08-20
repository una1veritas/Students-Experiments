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
const char Card::ranksymbol[][3] = { " X", " A", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K" };

Card Joker(Card::SUIT_JOKER, Card::NUMBER_JOKER);
//
// Card::scan() - 標準出力から自身に入力する(true: エラー; false: 正常終了)
//
bool Card::scan(const char * str)
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
		suit = SUIT_BLANK;
		break;
	}
	if (suit == SUIT_BLANK) {
		number = 0;
		return false;
	}

	for (i=0; isalpha(buf[i]); i++ ) {}
	for (; isspace(buf[i]); i++ ) {}
	number = atoi(buf+i);
	if (number <= 0 || number > 13) {
		number = 0;
		return false;
	}
	return true;
}

/*
bool Card::isGreaterThan(const Card & another) const {
	if (suit == SUIT_JOKER)
		return true;
	if (another.suit == SUIT_JOKER)
		return false;
	return (number + 10) % 13 > (another.number + 10) % 13;
}
*/

bool Card::isValid(void) const {
	if ( ((SUIT_SPADE <= suit) && (suit <= SUIT_CLUB))
		 && (1 <= number && (number <= 13)) )
		return true;
	else if (suit == SUIT_JOKER)
		return true;
	return false;
}

//
// Card::printOn - 自身の値を出力ストリームに出力する
//
std::ostream & Card::printOn(std::ostream& ostr) const {
	ostr << '[' << suitabbrevname[suit];
	if (suit != SUIT_JOKER )
		ostr << ranksymbol[number];
	ostr << ']';
	return ostr;
}
