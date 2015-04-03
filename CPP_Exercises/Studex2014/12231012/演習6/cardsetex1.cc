//
//
// cardsetextra.cc - トランプカードの集合型(C++版)テストプログラム
//	作者: 浦川楓; 日付: 2014/04/21
//
#include <iostream>
#include "cardset.h"

//
// main() - トランプカードの集合型テストプログラム
//

int main (int argc, char * const argv[]) {
	
		Card c;
		CardSet cs;

		Card card[5];
		card[0].set(0,1);
		card[1].set(1,3);
		card[2].set(2,6);
		card[3].set(3,10);
		card[4].set(0,13);
		card[5].set(4,0);

		cs.insert(card[0]);
		cs.insert(card[1]);
		cs.insert(card[2]);
		cs.insert(card[3]);
		cs.print();
		cs.remove(card[2]);
		cs.print();	
		cs.insert(card[5]);
		cs.insert(card[4]);
		cs.print();
		cs.remove(card[4]);
		cs.print();
		cs.remove(1);
		cs.print();
		
		// 入力がエラーになるまで指定したカードを入れる
		std::cout << "insert: c = ? ";
		while(true) {
		  c.scan();
		  if (! c.isValid())
		    break;
		  if(cs.insert(c))
		    std::cout << "\tinsert error\n";
		  cs.print();
		  std::cout << "insert: c = ? ";
		}
		cs.print();
		
		return 0;
}
