//
//
// cardsetex1.cc - トランプカードの集合型(C++版)テストプログラム
//	作者: 長濱彰秀 日付: 4月24日
//
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include "cardset.h"

//
// main() - トランプカードの集合型テストプログラム
//

int main (int argc, char * const argv[]) {
	
		Card c;
		CardSet cs;
		int d;
		
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
		
		// 入力がエラーになるまで指定したカードを入れる
		std::cout << "remove: c = ? ";
		while(true) {
		  c.scan();
		  if (! c.isValid())
		    break;
		  if(cs.remove(c))
		    std::cout << "\tremove error1\n";
		  cs.print();
		  std::cout << "remove: c = ? ";
		}
		cs.print();
		//
		std::cout << "remove: num = ? ";
		while(true) {
		  std::cin >> d;
		  if(1 > d || 13 < d){
			break;
		  }
		  if(cs.remove(d))
		    std::cout << "\tremove error2\n";
		  cs.print();
		  std::cout << "remove: num = ? ";
		}
		cs.print();

		return 0;
}
