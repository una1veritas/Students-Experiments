//
//*vector2c.h - 2次元ベクトル型(C版)
// 	作者: (あなたの名前); 日付: (完成した日付)
//[注意] 以降の演習では，上記を適切に書き換えること

#ifndef VECTOR2C_H
#define VECTOR2C_H
#include <stdio.h>

/* データ定義・宣言 */
class Vector22 {

private:
        double x[2][2];

public:
	Vector22(void){
	  x[0][0]= 0;
	  x[0][1]= 0;
	  x[1][0]= 0;
	  x[1][1]= 0;
	}
        Vector22(double x0, double x1, double y0, double y1);
	/* x0, y0 を与えて，定数 (x0, y0) を得る */
	Vector22 addv22(Vector22);
	/* ベクトル u と v の和 u + v を求める */
	Vector22 subv22(Vector22 u);
	/* ベクトル u と v の差 u - v を求める */
	Vector22 mulv22(Vector22 v);
	void scanv22(void);
	/* ベクトルの値を標準入力から *pu に入力する */
	void printv22(void);
	/* ベクトル u の値を標準出力に出力する */
};
#endif
