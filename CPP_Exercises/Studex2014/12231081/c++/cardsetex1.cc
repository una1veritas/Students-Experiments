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
	       	Card test[5];
		
		test[0].set(0,1);
		test[1].set(2,2);
		test[2].set(4,1);
		test[3].set(3,3);
		test[4].set(1,4);
		cs.insert(test[0]);
		cs.insert(test[1]);
		cs.insert(test[2]);
		cs.print();
		cs.remove(test[2]);
		cs.print();	
		cs.insert(test[3]);
		cs.insert(test[4]);
		cs.print();
		cs.remove(4);	
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
		
		return 0;
}
