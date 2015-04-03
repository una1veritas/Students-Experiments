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
		int n;

		cs.print();
		// 入力がエラーになるまで指定したカードを入れる
		std::cout << "insert: c = ? ";
		while(true) {
		  c.scan();
		  //printf("%d\n",c.gnumber());
		  if (! c.isValid())
		  {
		    break;
		  }
		  if(cs.insert(c))
		    std::cout << "\tinsert error\n";
		  std::cout << "insert: c = ? ";
		}
		cs.print();
		std::cout << "delete card: c = ?";
 		c.scan();
		if(c.isValid()) cs.remove(c);
		else std::cout << "Invalid Card!\n";
		cs.print();

		std::cout << "delete card number: n = ?";
                scanf("%d",&n);
                if(1<=n && n<=13) cs.remove(n);
                else std::cout << "Invalid Number!\n";
                cs.print();
		return 0;
}
