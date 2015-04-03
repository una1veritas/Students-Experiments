//
//
// cardsetextra.cc - トランプカードの集合型(C++版)テストプログラム
//	作者: Kento Nomiyama; 日付: 2014.04.17
//
#include <iostream>
#include "cardset.h"

//
// main() - トランプカードの集合型テストプログラム
//

int main (int argc, char * const argv[]) {
	
		Card c;
		CardSet cs;
		int num;
		
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
		std::cout << "remove num :";
		std::cin >> num;
		cs.remove(num);
		std::cout << "remove: ";
		while(true) {
		   c.scan();
		   if(! c.isValid())
			   break;
		   if(!cs.remove(c))
			   std::cout << "remove: ";
		}
	 	
		cs.print();

		return 0;
}
