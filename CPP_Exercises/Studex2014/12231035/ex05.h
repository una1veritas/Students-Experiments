//
// ex05.h - 2次元正方行列型と2次元ベクトル型(C++版)
//	作者: 島内拓海; 日付: 4/17
//
#ifndef ex05_H
#define ex05_H

//
// row2 - 2次元正方行列型
//
class row2 {
// メンバ変数
private:
  double x[2][2];     // x値
// メンバ関数
public:
  row2(void){
    x[0][0]=0; x[0][1]=0; x[1][0]=0; x[1][1]=0;
  }		// デフォルトコンストラクタ
	row2(double x0,double x1, double y0, double y1);
		// x0, x1, y0, y1  を与えて定数を得るコンストラクタ
	row2 add(row2 u);
		// 自身の行列と行列 u との和を求める
	row2 sub(row2 u);
		// 自身の行列と行列 u との差を求める
	row2 mul(row2 u);
        	// 自身の行列と行列 u との積を求める
	void scan(void);
		// 行列の値を標準入力から自身に入力する
	void print(void);
		// 自身の行列の値を標準出力に出力する
};

#endif
