//
//
// cardsetextra.cc - トランプカードの集合型(C++版)テストプログラム
//	作者: 福田真実; 日付: 4/28
//
#include <iostream>
#include "cardset.h"

//
// main() - トランプカードの集合型テストプログラム
//

int main (int argc, char * const argv[]) {
	
		Card c;
		CardSet cs;
		int num;
		
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

		// 入力がエラーになるまで指定したカードを削除する
		  std::cout << "remove: c = ? ";
		while (true) {
		  c.scan();
		  if (!c.isValid())
		    break;
		  if (cs.remove(c))
		  std::cout << "\tremove error\n";
		  cs.print();
		  std::cout << "remove: c = ? ";
		}

		// 入力がエラーになるまで指定した数字のカードを削除する
		std::cout << "remove(number): num = ? ";
		while (true) {
		  std::cin >> num;
		  if (num < 1 || 13 < num)
		    break;
		  if (cs.remove(num))
		    std::cout << "\tremove error\n";
		  cs.print();
		  std::cout << "remove(number): num = ? ";
		}

		return 0;
}
