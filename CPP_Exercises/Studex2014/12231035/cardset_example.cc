//
//
// cardsetextra.cc - トランプカードの集合型(C++版)テストプログラム
//	作者: 島内拓海; 日付: 4/24
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
		  cs.print();
		  std::cout << "insert: c = ? ";
		}
		cs.print();

	        cs.print();
		// 入力がエラーになるまで指定したカードを取り除く
		std::cout << "remove: c ";
		while(true) {
		  c.scan();
		  if (! c.isValid())
		    break;
		  if(cs.remove(c))
		    std::cout << "\tremove error\n";
		  cs.print();
		  std::cout << "remove: c = ? ";
		}
		cs.print();
		
		std::cout << "remove number: n ";
		while(true) {
		  int n;
		  scanf("%d",&n);
		  if (! (13>=n && (n>=1)))
		    break;
		  if(cs.remove(n))
		    std::cout << "\tremove error\n";
		  cs.print();
		  std::cout << "remove: n = ? ";
		}
		cs.print();
		
		return 0;
}
