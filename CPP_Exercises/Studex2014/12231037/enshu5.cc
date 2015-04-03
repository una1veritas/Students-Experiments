#include <stdio.h>
#include "enshu4.h"
#include "enshu3.h"

//
// main() - テストプログラム
//
int main(void)
{

  Vector2 x, y;
  Matrix22 a, b;


//ベクトルx, yを入力
        printf("vector x = ?");
        x.scan();
	printf("vector y = ? ");
	y.scan();

// 行列a, b を入力
        printf("Matrix a = ? ");
        a.scan();
        printf("Matrix b = ? ");
        b.scan();

//ベクトルの和x +　yを出力　
        printf("Vector x + y = ");
        (x.add(y)).print();
        printf("\n");

// 行列の和a + b を出力
        printf("Matrix a + b = ");
        (a.add(b)).print();
        printf("\n");

//ベクトルの和x - yを出力　
        printf("Vector x - y = ");
        (x.sub(y)).print();
        printf("\n");

// 行列の和a - b を出力
        printf("Matrix a - b = ");
        (a.sub(b)).print();
        printf("\n");

        return 0;
}
