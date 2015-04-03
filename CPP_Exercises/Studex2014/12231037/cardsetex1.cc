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
		int number;
		
		cs.print();
		// 入力がエラーになるまで指定したカードを入れる
	     	std::cout << "insert: c = ? ";
		while(true) {
		  c.scan();
		  if (! c.isValid())
		    break;
		  if(cs.insert(c))
		    std::cout << "\tinsert error\n";
		  std::cout << "insert: c = ? ";
		}
		cs.print();

		std::cout << "remove(target): c = ? ";
		c.scan();
		if(cs.remove(c))
		  std::cout << "error";
		cs.print();

		std::cout << "remove(number): number = ? ";
		scanf("%d", &number);
		if(cs.remove(number))
		  std::cout << "error";
		cs.print();

		return 0;
}
