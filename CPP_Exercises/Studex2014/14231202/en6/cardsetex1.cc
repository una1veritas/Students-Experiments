//
//
// cardsetextra.cc - トランプカードの集合型(C++版)テストプログラム
//	大高弥  4/24
//
#include <iostream>
#include "cardset.h"

//
// main() - トランプカードの集合型テストプログラム
//

int main (int argc, char * const argv[]) {
	
		Card c,c_pick;
		CardSet cs;
		int n;
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
		
		std::cout << "pickup: c = ? ";
		std::cin >>n;
		//cs.makedeck();
		cs.pickup(&c_pick,n);
		cs.print();
		return 0;
}
