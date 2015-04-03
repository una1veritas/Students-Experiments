//
// mat.h - 2次元ベクトル型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#ifndef MAT_H
#define MAT_H

//
// Mat2 - 2次元ベクトル型
//
class Mat2 {
// メンバ変数
private:
  double ret[2][2];
// メンバ関数
public:
	Mat2(void)	{
	  ret[0][0] = 0;
	  ret[0][1] = 0;
	  ret[1][0] = 0;
	  ret[1][1] = 0;
	  
	  printf("OK!!");
	}
	Mat2(double x0, double y0,double x1, double y1);	 
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	//	Mat2(const Mat2 &v);
	        // コピーコンストラクター
	Mat2 add( Mat2 u);
		// 自身のベクトルとベクトル u との和を求める
	Mat2 sub( Mat2 u);
		// 自身のベクトルとベクトル u との差を求める
	Mat2 mul( Mat2  u);
		// 自身のベクトルとベクトル u との積を求める
   	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
};
#endif

