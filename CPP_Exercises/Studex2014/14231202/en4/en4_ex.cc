//
// en4_ex.cc - 2次元ベクトル型(C++版)テストプログラム
//      大高弥  4/17
//

#include <stdio.h>
#include "vector2p.h"
#include "en4.h"

//
// main() - テストプログラム
//

int main(void){
	Matrix m,n;
	
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
		
	return  0;

}
