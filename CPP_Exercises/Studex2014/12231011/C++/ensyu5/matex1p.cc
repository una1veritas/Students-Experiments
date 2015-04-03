//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "matrix.h"
#include "vector2p.h"

//
// main() - テストプログラム
//
int main(void)
{
int num=0;
printf("put number vec2 1 mat 2 other num exit\n");
scanf("%d",&num);
	if(num==1){
	printf("a");
// a, b を入力
	Vector2 a,b;
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan();
	//	a.print();
	//	b.print();
	//	printf("\n");
// a + b を出力
	printf("a + b = ");
	(a.add(b)).print();
	printf("\n");
// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2, 1))).print();
	printf("\n");
// a - b を出力
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");
// a - (2, 1) を出力
	printf("a - (2,1) = ");
	(a.sub(Vector2(2, 1))).print();
	printf("\n");
	//	a.print();
	//	b.print();
	//	printf("\n");
	
	}
 	else if(num==2){
	Matrix a, b;

		//	a.print();
	//	b.print();
	//	printf("\n");
// a, b を入力
	printf("a = ? ");
	a.scan();
	printf("\n");
	printf("b = ? ");
	b.scan();
	//	a.print();
	//	b.print();
	//	printf("\n");
// a + b を出力
	printf("a + b = ");
	(a.add(b)).print();
	printf("\n");
// a - b を出
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");
	printf("a * b = ");
	(a.mul(b)).print();
	printf("\n");
	//	a.print();
	//	b.print();
	//	printf("\n");
	}
	return 0;
}
	
