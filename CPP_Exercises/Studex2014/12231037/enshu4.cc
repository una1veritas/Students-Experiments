//
// vector2p.cc - 2次元ベクトル型(C++版)
//      作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "enshu4.h"

Matrix22::Matrix22(void)
{
  int i, j;
  for(i=0; i<2; i++)
    for(j=0; j<2; j++)
      x[i][j] = 0;


}

//
// Matrix22::Matrix22() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Matrix22::Matrix22(double a0, double b0, double c0, double d0)
{
        x[0][0] = a0;
        x[0][1] = b0;
        x[1][0] = c0;
	x[1][1] = d0;

}

//コピーコンストラクタを作成
Matrix22::Matrix22(const Matrix22 & v)
{
  int i, j;

   for(i=0; i<2; i++)
    for(j=0; j<2; j++)
      x[i][j] = v.x[i][j];
}



//
// Matri22::add() - 和を求める
//
Matrix22 Matrix22::add(Matrix22 u)
{
        Matrix22 ret;
	int i, j;

 for(i=0; i<2; i++)
    for(j=0; j<2; j++)
      ret.x[i][j] = x[i][j] + u.x[i][j];

    

        return ret;
}

//自身のベクトルとベクトルuとの差をもとめる

Matrix22 Matrix22::sub(Matrix22 u)
{
        Matrix22 ret;
	int i, j;

   for(i=0; i<2; i++)
    for(j=0; j<2; j++)
      ret.x[i][j] = x[i][j] - u.x[i][j];

    

        return ret;
}

Matrix22 Matrix22::mul(Matrix22 u)
{
        Matrix22 ret;
	ret.x[0][0]=x[0][0] * u.x[0][0] + x[0][1] * u.x[1][0];
    	ret.x[0][1]=x[0][0] * u.x[0][1] + x[0][1] * u.x[1][1];
    	ret.x[1][0]=x[1][0] * u.x[0][0] + x[1][1] * u.x[1][0];
    	ret.x[1][1]=x[1][0] * u.x[0][1] + x[1][1] * u.x[1][1];
    

        return ret;
}


//
// Matrix22::scan() - ベクトルの値を標準入力から自身に入力する
//
void Matrix22::scan(void)
{
  int i, j;

    for(i=0; i<2; i++)
      for(j=0; j<2; j++)
        scanf("%lf", &x[i][j]);
    
        
}

//
// Matrix22::print() - 自身のベクトルの値を標準出力に出力する
//
void Matrix22::print(void)
{
  int i, j;

  printf("(%lf, %lf, %lf, %lf)", x[0][0], x[0][1], x[1][0], x[1][1]);

}
