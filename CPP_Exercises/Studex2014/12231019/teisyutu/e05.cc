#include <stdio.h>
#include "e05.h"

Matrix22::Matrix22(){

  int i, j;
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      x[i][j]= 0;
      printf("x[%d][%d]= %lf\n", i, j, x[i][j]);
    }
  }
}

Matrix22 Matrix22::add(Matrix22 u){
  Matrix22 ret;  
  int i, j;
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      ret.x[i][j] = x[i][j] + u.x[i][j];
    }
  }
  return ret;
}
Matrix22  Matrix22::sub(Matrix22 u){
 Matrix22 ret;  
  int i, j;
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      ret.x[i][j] = x[i][j] - u.x[i][j];
    }
  }
  return ret;
}
Matrix22 Matrix22::mul(Matrix22 u){
  Matrix22 ret;  
  int i, j, k;
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      for(k=0;k<2;k++){
	ret.x[i][j] += x[i][k] * u.x[k][j];
      }
    }
  }
  return ret;
 }
void Matrix22::scan(void){
  int i, j;
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      scanf("%lf",&x[i][j]);
    }
  }
  
}
void Matrix22::print(void){
  int i, j;
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      printf("x[%d][%d] = %lf\n",i,j,x[i][j]);
    }
  }
  
}



Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;
	printf("x0,y0\n");
}

Vector2::Vector2(const Vector2& u)
{
  	x = u.x;
  	y = u.y;
 	 printf("\nconst\n");
}
//
// Vector2::add() - 自身のベクトルとベクトル u との和を求める
//
Vector2 Vector2::add(Vector2 u)
{
	Vector2 ret;

	ret.x = x + u.x;
	ret.y = y + u.y;
	printf("add\n");

	return ret;
}

Vector2 Vector2::sub(Vector2 u)
{
	Vector2 ret;

	ret.x = x - u.x;
	ret.y = y - u.y;

	return ret;
	printf("sub\n");
}

double Vector2::nai(Vector2 u)
{
	Vector2 ret;

	ret.x= x * u.x;
	ret.y= y * u.y;
	printf("nai\n");

	return ret.x+ret.y;
}

double Vector2::gai(Vector2 u)
{
	Vector2 ret;

	ret.x= x * u.y;
	ret.y= y * u.x;
	printf("gai\n");

	return ret.x-ret.y;
}
//
// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
//
void Vector2::scan(void)
{
	scanf("%lf %lf", &x, &y);
	printf("scan\n");
}

//
// Vector2::print() - 自身のベクトルの値を標準出力に出力する
//
void Vector2::print(void)
{
	printf("( %f %f )", x, y);
	printf("printf\n");
}
