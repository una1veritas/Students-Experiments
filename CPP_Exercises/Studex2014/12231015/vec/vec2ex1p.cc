//
// vec2ex1p.cc -kadai5 
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "vector2p.h"
#include "mat.h"
//
// main() - テストプログラム
//
int main(int argc, char *argv[])
{
  Vector2 a,b;
  Mat2 c,d;

// a, b ,c,dを入力
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan(); 
	printf("c = ? ");
	c.scan();
	printf("d = ? ");
	d.scan();
// a + b を出力
	printf("a + b = ");
	(a.add(b)).print();
	printf("\n");
// a - b を出力
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");
	
// a * b を出力
	printf("a * b = ");
	(a.mul(b)).print();
	printf("\n");
	
// c + d を出力
	printf("c + d = ");
	c = c.add(d);
	c.print();
	//(c.add(d)).print();
	printf("\n");
// c - d を出力
	printf("c - d = ");
	c = c.sub(d);
	c.print();
	//(a.sub(b)).print();
	printf("\n");
	
// c * d を出力
	printf("c * d = ");
	c = c.mul(d);
	c.print();
	//	(a.mul(b)).print();
	printf("\n");
	return 0;
}
