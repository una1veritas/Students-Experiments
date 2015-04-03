//
//
// cardsetextra.cc - トランプカードの集合型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <iostream>
#include <stdlib.h>
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
		  if(cs.insert(c)){
		    std::cout << "\tinsert error\n";
		    break;
		  }
		  std::cout << "insert: c = ? ";
		}
		cs.print();
			// 入力がエラーになるまで指定したカードをremove
		int num;
		std::cout << "remove: num = ? ";
		while(true) {
		  scanf("%d",&num); 
		  if (!(0 < num && num < 13))
		    break;
		  /*else
		    if(! c.isValid())
		    break;*/
		  if(cs.remove(num) < 0)
		    break;
		  else{
		    while(!(cs.remove(num))){}
		    break;
		  }
		  std::cout << "remove: num = ? ";
		  
		}
		cs.print();	
		
		
		return 0;
}
