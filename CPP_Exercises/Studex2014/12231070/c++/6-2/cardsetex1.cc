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
	
		int n;
		Card c;
		CardSet cs;
		
		cs.print();
		// 入力がエラーになるまで指定したカードを入れる
		std::cout << "insert: c = ? ";
		while(true) {
		  c.scan();
		  if (! c.isValid())
		    break;
		  if(cs.insert(c)){
		    std::cout << "\tinsert error\n";break;}
		  std::cout << "insert: c = ? ";
		}
		cs.print();

		std::cout << "remove(terget): c = ? ";
		c.scan();
		cs.remove(c);
		cs.print();

		std::cout << "remove(num): n  = ? ";
		std::cin >> n;
		cs.remove(n);
		cs.print();
		
		return 0;
}
