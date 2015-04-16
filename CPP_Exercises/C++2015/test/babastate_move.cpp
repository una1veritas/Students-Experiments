//
// babastate.cc - ババ抜きの状態型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include "../babastate.h"
#include <iostream>

		// to 番のプレーヤが from 番のプレーヤからカードを取る
		// (true: 成功; false: 失敗)
bool BabaState::move(int from, int to) {
	Card c;
	hand[from].pickup(c);
	if ( hand[to].remove(c.getNumber()) == -1 ) {
		hand[to].insert(c);
	}
	return true;
}
