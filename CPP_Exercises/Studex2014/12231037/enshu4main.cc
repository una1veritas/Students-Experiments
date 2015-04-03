//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//      作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "enshu4.h"

//
// main() - テストプログラム
//
int main(void)
{
  Matrix22 a, b;

  /*a, b の初期値を出力
        printf("行列の初期値");
        a.print();
        b.print();
        printf("\n");
  */

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
        (a.mul(b)).print();
        printf("\n");




        return 0;
}
