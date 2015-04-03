//
//
// cardsetextra.cc - トランプカードの集合型(C++版)テストプログラム
//	作者: 佐藤彰哉; 日付: 4/24
//
#include <iostream>
#include "cardset.h"

//
// main() - トランプカードの集合型テストプログラム
//

int main (int argc, char * const argv[]) {
	
		Card c;
		CardSet cs;
		int number;

		cs.print();//csの内容を表示する
		// 入力がエラーになるまで指定したカードを入れる
		std::cout << "insert: c = ? ";
		while(true) {
		  c.scan();//読み込む
		  if (! c.isValid())
		    break;
		  if(cs.insert(c))
		    std::cout << "\tinsert error\n";
		  std::cout << "insert: c = ? ";
		}
		cs.print();

		// 入力がエラーになるまで指定したカードを削除
		std::cout << "remove: c = ? ";
		while(true) {
		  c.scan();
		  if (! c.isValid())
		    break;
		  if(cs.remove(c)){
		    std::cout << "\tremove error\n";
		}
		  std::cout << "remove: c = ? ";
		}
		cs.print();

		// 入力がエラーになるまで指定したカードを削除
		std::cout << "remove: n = ? ";
		while(true) {
		  std::cin >> number;
		  if(number < 1 || number > 13)
		    break;
		  if(cs.remove(number))
		    std::cout << "\tremove error\n";
		  cs.print();
		  std::cout << "remove: n = ? ";
		}
		cs.print();
		return 0;
}
