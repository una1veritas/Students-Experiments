//
//
// cardsetex1_2.cc - トランプカードの集合型(C++版)テストプログラム()enshu6(2)
//	作者: Dewi; 日付: 2014/4/25
//
#include <iostream>
#include "cardset_2.h"

//
// main() - トランプカードの集合型テストプログラム
//

int main (int argc, char * const argv[]) {
	
		Card c;
		int n;
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
		cs.print();

		std::cout << "remove card: c = ?";
		c.scan();
		cs.remove(c);
		cs.print();

		std::cout << "remove number: n = ?";
		scanf("%d", &n);
		cs.remove(n);
		cs.print();
		
		return 0;
}
