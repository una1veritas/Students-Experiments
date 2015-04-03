//
// vector2p.h - 2次元ベクトル型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
//#ifndef VECTOR2P_H
//#define VECTOR2P_H

//
// Vector2 - 2次元ベクトル型
//

class Matrix22 {
 private:
    double x[2][2];
  
 public:
  Matrix22(void);
  Matrix22(const Matrix22& m);
  Matrix22(double m00, double m01,double m10, double m11);
  Matrix22 add(Matrix22 m);
  void print(void);
  Matrix22 sub(Matrix22 m);
  Matrix22 mul(Matrix22 m);
  void scan(void);
};
#endif
