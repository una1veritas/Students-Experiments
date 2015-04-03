//
//
// cardsetextra.cc - トランプカードの集合型(C++版)テストプログラム
//	作者: 道下　真人; 日付: 2014/04/17
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
		cs.print();//選択したカードを表示
		
		printf("\n");
		std::cout << "remove: c = ? ";
		while(true) {
		  c.scan();
		  if (! c.isValid())
		    break;
		  if(cs.remove(c))
		    std::cout << "\tremove error\n";
		  std::cout << "remove: c = ? ";
		}
		cs.print();
	return 0;
}
