//
// en5.cc - 2次元ベクトル型(C++版)テストプログラム
//      大高弥  4/17
//

#include <stdio.h>
#include "en5.h"
#include "vector2p.h"


//
// main() - テストプログラム
//

int main(void){
	Matrix m,n;
	Vector2 a, b;
	//行列入力
	m.scan();
	printf("m=\n");
	m.print();
	n.scan();
	printf("n=\n");
	n.print();

	printf("加算\n");
	(m.add(n)).print();

	printf("減算\n");
	(m.sub(n)).print();
		
	printf("乗算\n");
	(m.pro(n)).print();

	//ベクトル入力
	// a, b を入力
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan();
	// a + b を出力 
	printf("a + b = ");
	(a.add(b)).print();
	printf("\n");
// a - b を出力 
    printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");
	return  0;

}
