//
// ex4.cc - 2次元ベクトル型(C++版)
//	作者:藤戸梨乃; 日付: (完成した日付)
//
#include <stdio.h>
#include "ex4.h"

void Matrix22::scan(void){
    scanf("%lf %lf\n %lf %lf", &x[0][0], &x[0][1], &x[1][0], &x[1][1]);
}
          
void Matrix22::print(void){
    printf("( %f %f %f %f)\n", x[0][0], x[0][1], x[1][0], x[1][1]);
}
  
Matrix22 Matrix22::add(Matrix22 z){
            Matrix22 ret;
  
            ret.x[0][0] = x[0][0] + z.x[0][0];
            ret.x[0][1] = x[0][1] + z.x[0][1];
            ret.x[1][0] = x[1][0] + z.x[1][0];
            ret.x[1][1] = x[1][1] + z.x[1][1];
              
            return ret;
}     
  
Matrix22 Matrix22::sub(Matrix22 z){
            Matrix22 ret;
  
            ret.x[0][0] = x[0][0] - z.x[0][0];
            ret.x[0][1] = x[0][1] - z.x[0][1];
            ret.x[1][0] = x[1][0] - z.x[1][0];
            ret.x[1][1] = x[1][1] - z.x[1][1];
      
            return ret;
}
  
Matrix22 Matrix22::mul(Matrix22 z){
        Matrix22 ret;
  
            ret.x[0][0] = x[0][0] * z.x[0][0] + x[0][1] * z.x[1][0];
            ret.x[0][1] = x[0][0] * z.x[0][1] + x[0][1] * z.x[1][1];
            ret.x[1][0] = x[1][0] * z.x[0][0] + x[1][1] * z.x[1][0];
            ret.x[1][1] = x[1][0] * z.x[0][1] + x[1][1] * z.x[1][1];
  
            return ret;
}

