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
  
  
  Card c, target;
  CardSet cs;
  int i, num;
  
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
    std::cout << "continue 1 or remove 2: i = ?";
    scanf("%d", &i);
    if(i == 2){
      std::cout << "remove num 1 or target 2: i = ? ";
      scanf("%d", &i);
      if(i == 1){
	std::cout << "card:num = ?";
	scanf("%d", &num);
	cs.remove(num);
      }
      if(i == 2){
	std::cout << "card:target = ?";
	target.scan();
	cs.remove(target);
	cs.print();
      }
    }
    std::cout << "insert: c = ? ";
  }
  cs.print();
  
  return 0;
}
