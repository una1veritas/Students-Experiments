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
		int n=0,m=0;
		cs.print();
	   
                // 入力がエラーになるか５枚入力されるまで指定したカードを入れる
                std::cout << "insert: c = ? ";
                while(true) {
                  c.scan();
                  if (! c.isValid())
                    break;
                  if(cs.insert(c))
                    std::cout << "\tinsert error\n";
		  cs.print();

		  if(n==4)
		    break;
                  std::cout << "insert: c = ? ";
		  n++;
                }


		std::cout << "remove: c = ? ";
		while(true) {
		  scanf("%d",&m);
		  if(m==0)
		  c.scan();
		  if (! c.isValid())
		    break;
		  if(cs.remove(c))   
		    if(cs.remove(m))
		      std::cout << "\tremove error\n";
		  if(n==0)
		    break;
		  cs.print();
	      
		  
		  std::cout << "remove: c = ? ";
		  n--;
		  
		  m=0;
		}

		cs.print();
		
		return 0;
}
