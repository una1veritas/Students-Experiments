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
	Vector2 a, b;
	Matrix ma,mb;
	
// a, b を入力
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan();
// a + b を出力
	printf("a + b = ");
	(a.add(b)).print();
	printf("\n");
// a-b を出力 
        printf("a - b  = ");
        (a.sub(b)).print();
        printf("\n");
// aとbの内積
	printf("a・b = %lf\n",a.product(b));
// aとbの外積
       printf("a * b = %lf\n\n",a.gaiseki(b));
	
	printf("ma = \n");
	ma.scan();
	printf("mb = \n");
	mb.scan();
// ma + mb を出力
	printf("ma + mb = \n");
	(ma.add(mb)).print();
// ma-mb を出力 
        printf("ma - mb  = \n");
        (ma.sub(mb)).print();
// maとmbの乗算
	printf("ma・mb = \n");
	(ma.product(mb)).print();
	return 0;
}
