
#include<stdio.h>
#include"Matrix22.h"



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

