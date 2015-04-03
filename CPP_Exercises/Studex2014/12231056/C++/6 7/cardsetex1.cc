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
		int number;	
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
		printf("------------------\n");

		// 入力がエラーになるまで指定したカードを削除する
		std::cout << "remove: c = ? ";
		while(true) {
		  c.scan();
		  if (! c.isValid())
		    break;
		  if(cs.remove(c))
		    std::cout << "\t remove target error\n";
		  cs.print();
		  std::cout << "remove: c = ? ";
		}
		printf("------------------\n");

		// 入力がエラーになるまで指定した番号のカードを削除する
		std::cout << "remove: number = ? ";
		while(true) {
		  std::cin >> number;
		  if (number < 1 || 13 < number)
		    break;
		  if(cs.remove(number))
		    std::cout << "\t remove number error\n";
		  cs.print();
		  std::cout << "remove: c = ? ";

		}
		cs.print();
		
		
		return 0;
}
