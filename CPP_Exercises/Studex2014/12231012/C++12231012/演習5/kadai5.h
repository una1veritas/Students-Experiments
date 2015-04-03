//
// kadai5.h - 2次元正方行列型(C++版)
//	作者:浦川楓; 日付: 2014/4/17
//
#ifndef VECTOR2P_H
#define VECTOR2P_H

//
// Vector2 - 2次元正方行列型
//
class Vector2 {
  // メンバ変数
 private:
  double x;	// x値
  double y;	// y値
  
  // メンバ関数
 public:
  Vector2(){
    x = 0;
    y = 0;
  }
  
  // デフォルトコンストラクタ(初期値不定)
  Vector2(double x0, double y0);
  // x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
  
  Vector2(const Vector2 & v);
  
  Vector2 add(Vector2 u);
  // 自身のベクトルとベクトル u との和を求める
  Vector2 sub(Vector2 u);
  // 自身のベクトルとベクトル u との差を求める
  void scan(void);
  // ベクトルの値を標準入力から自身に入力する
  void print(void);
  // 自身のベクトルの値を標準出力に出力する
};

//
// Matrix - 2次元ベクトル型
//

class Matrix {
 private:
  double val[2][2];	// 2次元ベクトルの配列の定義
 public:
  
  Matrix(){
    val[0][0] = 0;
    val[0][1] = 0;
    val[1][0] = 0;
    val[1][1] = 0;
  }
  
  Matrix(double x0, double y0, double x1, double y1);
  // x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
  
  Matrix(const Matrix & v);
  
  Matrix add(Matrix u);
  // 自身の行列と行列 u との和を求める
  Matrix sub(Matrix u);
  // 自身の行列と行列 u との差を求める
  void scan(void);
  // 行列の値を標準入力から自身に入力する
  void print(void);
  // 自身の行列の値を標準出力に出力する
};

#endif
