//
// vec2ex1p.cc - 2次元行列型(C++版)テストプログラム
//      作者: 竹下純哉; 日付: 14/04/10
//
#include <stdio.h>
#include "ensyu4.h"

//
// main() - テストプログラム
//
int main(void)
{
        Gyoretu2 a, b;

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
// a * b を出力
	printf("a * b = ");
	(a.mult(b)).print();
	printf("\n");

        return 0;
}
