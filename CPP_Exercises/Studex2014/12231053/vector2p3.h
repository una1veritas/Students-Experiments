//
// vector2p.h - 2次元ベクトル型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#ifndef VECTOR2P3_H
#define VECTOR2P3_H

//
// Vector2 - 2次元ベクトル型
//
class Vector2 {
// メンバ変数
private:
  double x;
  double y;	// y値
// メンバ関数
public:
	/*Vector2(void)	{ }
		// デフォルトコンストラクタ(初期値不定)
	Vector2(double x0, double y0);
	        // x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ*/
	Vector2(void)
	  { x = 0;
	    y = 0;
	    printf("デフォルトコンストラクタ");
	  }
	Vector2(double x0, double y0)
	  {x = x0; y = y0;
	    printf("引数あり");
	  }
	Vector2(const Vector2 & v)
	  {x = v.x; y = v.y;
	    printf("コピーコンストラクタ");
	  }
	Vector2 add(Vector2 u);
		// 自身のベクトルとベクトル u との和を求める
	Vector2 sub(Vector2 u);
		// 自身のベクトルとベクトル u との差を求める
	double inpro(Vector2 u);
	  // 自身のベクトルとベクトルuとの内積を求める
	double outpro(Vector2 u);
	  //自身のベクトルとベクトルuとの外積を求める
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
};

#endif
