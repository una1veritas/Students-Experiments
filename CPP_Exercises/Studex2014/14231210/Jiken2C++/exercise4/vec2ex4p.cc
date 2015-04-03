//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "vector2p.h"

//
// main() - テストプログラム
//
int main(void)
{
	Matrix ma,mb;
	
	printf("ma = \n");
	ma.scan();
	printf("mb = \n");
	mb.scan();
// ma + mb を出力
	printf("ma + mb = \n");
	(ma.add(mb)).print();
	printf("\n");
// ma-mb を出力 
        printf("ma - mb  = \n");
        (ma.sub(mb)).print();
        printf("\n");
// maとmbの乗算
	printf("ma・mb = \n");
	(ma.product(mb)).print();
	return 0;
}
