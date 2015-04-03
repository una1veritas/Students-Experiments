//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "matrix22.h"

//
// main() - テストプログラム
//
int main(void)
{
  
Matrix22 ma, mb(1,2,3,4);

 printf("初期値の確認");
 printf("\n");
 printf("ma = ");ma.print();printf("\n");
 printf("mb = ");mb.print();printf("\n");
 
 Matrix22 mc(mb);
 printf("mc = ");mc.print();printf("\n");
 
 // a, b を入力
 printf("ma = ? ");
 ma.scan();
 printf("mb = ? ");
 mb.scan();
 
 // a + b を出力
 printf("ma + mb = ");
 (ma.add(mb)).print();
 printf("\n");
 // a + (2, 1) を出力
 printf("ma * (2,1,2,1) = ");
 (ma.mul(Matrix22(2, 1, 2, 1))).print();
 printf("\n");
 // a + b を出力
 printf("ma - mb = ");
 (ma.sub(mb)).print();
 printf("\n");
 
 return 0;
}
