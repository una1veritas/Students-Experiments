//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "vector2p.h"

//
// main() - テストプログラム
//
int main(void)
{
	Vector2 v1;
        Vector2 v2(2.4,5.5);
        Vector2 v3=v2;
        
        v1.print(); printf("\n");
        printf("( %lf %lf )\n",v1.getx(),v1.gety());
        v2.print(); printf("\n");
        v3.print(); printf("\n");
        return 0;
}
