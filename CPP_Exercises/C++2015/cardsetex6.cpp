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

int main (int argc, char * const argv[]) {
	
		Card c;
		CardSet cs;
		
		cs.print();
		std::cout << std::endl; // 行末記号 end of line を標準出力に出力．

		// カード入力がエラーになるまで指定したカードを入れる
		while(true) {
			std::cout << "Card (suit number) or x (end) ? ";
			if ( !c.scan() )
				break;
			c.print();
			std::cout << std::endl;
			cs.insert(c);
		}
		cs.print();
		
		return 0;
}
