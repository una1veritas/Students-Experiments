// cardsetextra.cc - トランプカードの集合型(C++版)テストプログラム
//	作者: (市川　舞); 日付: (2014/04/18)
#include <iostream>
#include "cardset.h"

// main() - トランプカードの集合型テストプログラム
int main (int argc, char * const argv[]) {
	
                Card c,d;
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
		  std::cout << "remove: d = ?"; // 課題6-(2)にて追加
		  d.scan();
		  if (! d.isValid()) // 存在しないカードを入力すると
		    std::cout << "pass\n"; // passというメッセージを表示して終了
		  
		  else if(cs.remove(d)) //存在するカードの場合
		    std::cout << "\tremove error\n"; //削除可能であれば削除、不可能であればエラー
		  cs.print();
		  std::cout << "insert: c = ? ";
		}
		  
		cs.print();
		
		return 0;
}
