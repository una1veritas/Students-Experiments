#include<stdio.h>

//
// vector2p.h - 2次元ベクトル型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#ifndef VECTOR2P_H
#define VECTOR2P_H

//
// Vector2 - 2次元ベクトル型
//
class Vector2 {
// メンバ変数
private:
	double x;	// x値
	double y;	// y値
// メンバ関数
public:
	Vector2(void)	
        {
             printf("デフォルトコンストラクタですー\n");
             x=0; y=0; 
        }
		// デフォルトコンストラクタ(初期値不定)
	Vector2(double x0, double y0);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Vector2(const Vector2 &v)
        {
             printf("コピーコンストラクタですー\n"); 
             x=v.x; y=v.y;
        }
	double getx();
        double gety();
	void setx(double dx);
	void sety(double dy);
	Vector2 add(Vector2 u);
		// 自身のベクトルとベクトル u との和を求める
	Vector2 sub(Vector2 u);
		// 自身のベクトルとベクトル u との差を求める
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
	double product(Vector2 u);
	double gaiseki(Vector2 u);
};

class Matrix
{
  private:
	Vector2 m[2];
  public:
	Matrix(void) {}
	Matrix(Vector2 m1, Vector2 m2);
	
	Matrix add(Matrix b);
	Matrix sub(Matrix b);
	Matrix product(Matrix b);
	void scan(void);
	void print(void);
};

#endif
