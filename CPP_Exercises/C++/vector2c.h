/*
 * vector2c.h - 2次元ベクトル型(C版)
 *	作者: (あなたの名前); 日付: (完成した日付)
 * [注意] 以降の演習では，上記を適切に書き換えること
 */
#ifndef VECTOR2C_H
#define VECTOR2C_H

/* データ定義・宣言 */
struct vector2 { /* 2 次元次元ベクトル型 */
	double x, y;
};

typedef struct vector2 vector2;

/* プロトタイプ宣言 */

vector2 vector2init(double x, double y);
	/* x, y を与えて，二次元ベクトル (x, y) を新しい vector2 型オブジェクトとして返す */

vector2 vector2add(vector2 u, vector2 v);
	/* ベクトル u と v の和 u + v を求め，新しい vector2 型オブジェクトにセットして返す */

vector2 vector2sub(vector2 u, vector2 v);
	/* ベクトル u と v の差 u - v を求め，新しい vector2 型オブジェクトにセットして返す */

vector2 vector2scan(char * str);
	/* vector2 を文字列表現 "(x, y)" から作成して返す */

char * vector2toString(char * str, vector2 v);
	/* ベクトル u の値を文字列表現に変換する */

#endif
