//
//
// cardsetextra.cc - トランプカードの集合型(C++版)テストプログラム
//	作者:核雅瑛 (あなたの名前); 日付:2014/04/17 (完成した日付)
//
#include <iostream>
#include "cardset.h"




void deback(CardSet *cs) {
                int mode;
		int numRemove;
		Card toRemove;
		
		std::cout << "select mode\n";
		std::cout << "Add Continue : type 1\n";
		std::cout << "remove(card) : type 2\n";
		std::cout << "remoce(num)  : type 3\n";
		std::cout << "mode selecte >>";
		
		std::cin >> mode;
		
		switch(mode) {
		        case 1 :
			  break;

		        case 2 :
			  std::cout << "remove card ?type card >>";
			  toRemove.scan();
			  if (! toRemove.isValid())
			    break;
			  (*cs).remove(toRemove);
			  break;

		        case 3 :
			  std::cout << "remove card ?type num >>";
			  std::cin >> numRemove;
			  (*cs).remove(numRemove);
			  break;
			
		        default :
			  std::cout << "type 1~3\n";
			  std::cout << "add again\n";
			  break;
		}
		
}





//
// main() - トランプカードの集合型テストプログラム
//

int main (int argc, char * const argv[]) {
	
                Card c;
		CardSet cs;
		cs.print();
		// 入力がエラーになるまで指定したカードを入れる
       		while(true) {
		  std::cout << "insert: c = ? ";
		  c.scan();
		  if (! c.isValid())
		    break;
		  if(cs.insert(c))
		    std::cout << "\tinsert error\n";
		  
		  deback(&cs);
		  //本番はdebackをコメントして下をはずす
		  //std::cout << "insert: c = ? ";
		  cs.print();
		  std::cout << "\n\n";
		  
		}


		return 0;
}

