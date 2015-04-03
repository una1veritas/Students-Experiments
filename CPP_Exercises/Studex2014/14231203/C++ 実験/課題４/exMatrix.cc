//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//      作者: (あなたの名前); 日付: (完成した日付)
//

#include <stdio.h>
#include "Matrix.h"
//
// main() - テストプログラム
//

int main(void){
	Matrix a;
	Matrix b;

	printf("a=?");
	a.scan();
	a.print();
	printf("b=?");
	b.scan();
	b.print();
	printf("a + d = \n");
	(a.add(b)).print();
	printf("a");
	printf("\n");	
	printf("a - b = \n");
	(a.sub(b)).print();
	printf("\n");	
	printf("a x d = \n");
	(a.mul(b)).print();
	printf("\n");	
	return  0;

}
