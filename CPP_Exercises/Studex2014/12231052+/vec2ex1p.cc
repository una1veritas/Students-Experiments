//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: 長濱彰秀; 日付: 4月２４日
//
#include <stdio.h>
#include "vector2p.h"
#include "matrix22.h"

//
// main() - テストプログラム
//
int main(void) {
	Vector2 a, b;
	Matrix22 c, d;

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
// ベクトルAとBの内積を出力　 //
	printf("内積 = %lf",a.dot(b));
       	printf("\n");
// ベクトルAとBの外積を出力  //
	printf("外積 = %lf",a.cross(b));
   	printf("\n");


// a * b を出力
	//printf("a * b = ");
	//(a.mul(b)).print();
	//printf("\n");

// c, d を入力
	printf("c = ? ");
	c.scan();
	printf("d = ? ");
	d.scan();
// c + d  を出力
	printf("c + d = ");
	(c.add(d)).print();
	printf("\n");
// c - d を出力
	printf("c - d = ");
	(c.sub(d)).print();
	printf("\n");
// c * d を出力
	printf("c * d = ");
	(c.mul(d)).print();
	printf("\n");








	return 0;
}

