#include <stdio.h>
#include "main.h"
//-----------------Vec-----------------
void Vec::scan(void)
{
  scanf("%lf %lf",&e[0], &e[1]);
}
void Vec::print(void)
{
  printf(" %f %f " ,e[0] ,e[1]);
}
Vec Vec::add(Vec u)
{
  Vec ret;
  for (int i=0;i<2;i++)
    ret.e[i] = e[i] + u.e[i];
  return ret;
}
Vec Vec::sub(Vec u)
{
  Vec ret;
  for (int i=0;i<2;i++)
    ret.e[i] = e[i] - u.e[i];
  return ret;
}

//-----------------Mat-----------------
void SqMat::scan(void)
{
  scanf("%lf %lf %lf %lf",&e[0][0], &e[0][1], &e[1][0], &e[1][1]);
}
void SqMat::print(void)
{
  printf(" %f %f \n %f %f ", e[0][0], e[0][1], e[1][0], e[1][1]);
}
SqMat SqMat::add(SqMat u)
{
  SqMat ret;
  for (int i=0;i<2;i++)
    for (int j=0;j<2;j++)
      ret.e[i][j] = e[i][j] + u.e[i][j];
  return ret;
}
SqMat SqMat::sub(SqMat u)
{
  SqMat ret;
  for (int i=0;i<2;i++)
    for (int j=0;j<2;j++)
      ret.e[i][j] = e[i][j] - u.e[i][j];
  return ret;
}

//SqMat SqMat::inp(SqMat u)
//{
//  SqMat ret;
//  ret.e[0][0] = e[0][0] * u.e[0][0] + e[0][1] * u.e[1][0];
//  ret.e[0][1] = e[0][0] * u.e[0][1] + e[0][1] * u.e[1][1];
//  ret.e[1][0] = e[1][0] * u.e[0][0] + e[1][1] * u.e[1][0];
//  ret.e[1][1] = e[1][0] * u.e[0][1] + e[1][1] * u.e[1][1];

//  return ret;
//}
