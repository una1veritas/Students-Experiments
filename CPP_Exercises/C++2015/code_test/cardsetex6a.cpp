//
//
// cardsetextra.cc - トランプカードの集合型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <iostream>
#include "card.h"
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
		do {
			std::cout << "Type 'suit number', or e'x'it: ";
			if ( !c.scan() )
				break;
			c.print();
			// std::cout << c << std::endl; // C++ 風に出力するには，operator<< を定義する．
			std::cout << std::endl;
		} while ( cs.insert(c) >= 0 ); // 常に ture のはず
		std::cout << "CardSet contents: " << std::endl;
		cs.print();
		std::cout << std::endl;
		
		std::cout << "Remove the same card." << std::endl;
		// カード入力がエラーになるまで指定したカードを入れる
		do {
			std::cout << "Type 'suit number', or e'x'it: ";
			if ( !c.scan() )
				break;
			c.print();
			// std::cout << c << std::endl; // C++ 風に出力するには，operator<< を定義する．
			std::cout << std::endl;
		} while ( cs.remove(c) >= 0 ); // あれば true
		std::cout << "CardSet contents: " << std::endl;
		cs.print();
		std::cout << std::endl;

		std::cout << "Remove a card of the same number." << std::endl;
		// カード入力がエラーになるまで指定したカードを入れる
		do {
			std::cout << "Type 'suit number', or e'x'it: ";
			if ( !c.scan() )
				break;
			c.print();
			// std::cout << c << std::endl; // C++ 風に出力するには，operator<< を定義する．
			std::cout << std::endl;
		} while ( cs.remove(c.getNumber()) >= 0 ); // あれば true
		std::cout << "CardSet contents: " << std::endl;
		cs.print();
		std::cout << std::endl;

		return 0;
}
