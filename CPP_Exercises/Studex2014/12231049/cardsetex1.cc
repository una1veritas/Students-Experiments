//
//
// cardsetextra.cc - トランプカードの集合型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <iostream>
using namespace std;
#include "cardset.h"

//
// main() - トランプカードの集合型テストプログラム
//

int main (int argc, char * const argv[]) {
	
		Card c;
		CardSet cs;
		int num, cnum;
		
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
		while(true) {
		  std::cout << "モードを選んでください 1.target 2.number 3.終了";
		  cin >> num;
		  if(num == 1 || num == 2) {
		    if(num == 1) {
		      std::cout << "remove: target = ?";
		      c.scan();
		    }
		    else if(num == 2) {
		      std::cout << "remove: number = ?";
		      cin >> cnum;
		    }
		    if(! c.isValid())
		      break;
		    if(num == 2 && cnum > 13)
		      break;
		    if(num == 1) {
		      if(cs.remove(c))
			std::cout << "\remove error\n";
		    }
		    else if(num == 2) {
		      if(cs.remove(cnum))
			std::cout << "\remove error\n";
		    }
		  }
		  else if(num != 3)
		    std::cout << "1か2か3を選んでください";
		  if(num == 3)
		    break;
		  cs.print();		 
		}
		cs.print();
		
		return 0;
}
