//
// vector2p.h - 2次正方行列型(C++版)
//      作者: 竹下純哉; 日付: 14/04/10
//
#ifndef ENSYU4_H
#define ENSYU4_H

//
// Gyoretu2 - 2次正方行列型
//
class Gyoretu2 {
// メンバ変数
private:
  double x[2][2];
// メンバ関数
public:
  Gyoretu2(void) { } // デフォルトコンストラクタ
  Gyoretu2 add(Gyoretu2 u); // 自身の行列と行列 u との和を求める
  Gyoretu2 sub(Gyoretu2 u); // 自身の行列と行列 u との差を求める
  Gyoretu2 mult(Gyoretu2 u); // 自身の行列と行列 u との掛け算を求める
  void scan(void); // 行列の値を標準入力から自身に入力する
  void print(void); // 自身の行列の値を標準出力に出力する
};

#endif
