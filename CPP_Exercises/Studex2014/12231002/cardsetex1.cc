//
//
// cardsetextra.cc - トランプカードの集合型(C++版)テストプログラム
//	作者: 伊佐　真誠; 日付: 4/17
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
		  if (! c.isValid()){
		    break;
		  }
		  if(cs.insert(c))
		    std::cout << "\tinsert error\n";
		  cs.print();
		  std::cout << "insert: c = ? ";
		}
		cs.print();

		while(true){
		  std::cout << "remove: num -> 1  suit ->2  exit -> 3  ";
		  int i;
		  scanf("%d", &i);
		  if(i == 1){
		    std::cout << "remove: num = ? ";
		    int num;
		    scanf("%d", &num);
		    if(cs.remove(num))
		      std::cout << "\tremove error\n";
		  }else if(i == 2){
		    std::cout << "remove: c = ?";
		    c.scan();
		    if(cs.remove(c))
		      std::cout << "\tremove error\n";
		  }else if(i == 3){
		    break;
		  }else{
		    std::cout << "\tremove error\n";
		  }
		  cs.print();
		}
		return 0;
}
