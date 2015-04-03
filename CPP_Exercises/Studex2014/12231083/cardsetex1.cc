//
//
// cardsetextra.cc - トランプカードの集合型(C++版)テストプログラム
//	作者: (山本晃也); 日付: (４24)
//
#include <iostream>
#include "cardseta.h"

//
// main() - トランプカードの集合型テストプログラム
//

int main (int argc, char * const argv[]) {
	
		Card c;
		CardSet cs;
		int i;
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
		 std::cout << "num = ?";
		   std::cin>>i;
		   if(cs.remove(i)){
		    std::cout << "\tinsert error\n";
		    }
		      cs.print();
		      
		      	 std::cout << "remove: c = ? ";
		      	while(true) {
		  c.scan();
		  if (! c.isValid())
		    break;
		  if(cs.remove(c))
		    std::cout << "\tinsert error\n";
		  std::cout << "remove: c = ? ";
		  }
	 
		cs.print();
		return 0;
}
