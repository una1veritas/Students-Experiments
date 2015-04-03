//
// vector2p.cc - 2次元ベクトル型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "vector2p.h"

//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Vector2::Vector2()
{
	x = 0;
	y = 0;
	printf("デフォルトコンストラクタ\n");
       	printf("x=%f, y=%f\n",x,y);
       
       
}

Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;
        printf("Vector2です\n");
       	printf("x=%f, y=%f\n",x,y);
}


Vector2::Vector2(const Vector2 & v)
{
	x = v.x;
	y = v.y;
        printf("コピーコンストラクタ\n");
       	printf("x=%f, y=%f\n",x,y);
}

//
// Vector2::add() - 自身のベクトルとベクトル u との和を求める
//
Vector2 Vector2::add(Vector2 u)
{
	Vector2 ret;

	ret.x = x + u.x;
	ret.y = y + u.y;

	return ret;
}


Vector2 Vector2::sub(Vector2 u)
{
	Vector2 ret;

	ret.x = x - u.x;
	ret.y = y - u.y;

	return ret;
}

//
// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
//
void Vector2::scan(void)
{
	scanf("%lf %lf", &x, &y);
}

//
// Vector2::print() - 自身のベクトルの値を標準出力に出力する
//
void Vector2::print(void)
{
	printf("( %f %f )", x, y);
}

Matrix::Matrix(){
  int i,j; 
printf("デフォルトコンストラクタ\n");
  for(i=0;i<2;i++)
    for(j=0;j<2;j++){
      x[i][j]=0;
      printf("x[%d][%d]=%lf\n",i,j,x[i][j]);}
 
}

Matrix::Matrix(double x0[2][2]){
  int i,j;

  for(i=0;i<2;i++)
    for(j=0;j<2;j++){
      x[i][j]=x0[i][j];
      printf("x[%d][%d]=%lf\n",i,j,x[i][j]);}
  
}

Matrix Matrix::add(Matrix u)
{
	Matrix ret;
	int i,j;

       for(i=0;i<2;i++){
	 for(j=0;j<2;j++){
	   ret.x[i][j]=x[i][j]+u.x[i][j];
	 }
	}

	return ret;
}

Matrix Matrix::sub(Matrix u)
{
	Matrix ret;
	int i,j;

       for(i=0;i<2;i++){
	 for(j=0;j<2;j++){
	   ret.x[i][j]=x[i][j]-u.x[i][j];
	 }
	}

	return ret;
}

Matrix Matrix::mul(Matrix u)
{
	Matrix ret;
	int i,j,k;

       for(i=0;i<2;i++){
	 for(j=0;j<2;j++){
	   for(k=0;k<2;k++){	     
	   ret.x[i][j]+=x[i][k]*u.x[k][j];
	   }
	 }
	}

	return ret;
}

void Matrix::scan(void)
{
  int i,j;
  for(i=0;i<2;i++){
	 for(j=0;j<2;j++){
	scanf("%lf", &x[i][j]);
	 }
  }
}

void Matrix::print(void)
{
  int i,j;
  for(i=0;i<2;i++){
	 for(j=0;j<2;j++){
	   printf("x[%d][%d]=%f\n", i,j,x[i][j]);
	 }
  }
}
