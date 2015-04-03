//
// babastate.cc - ババ抜きの状態型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include "babastate.h"
#include <iostream>
#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<cstdlib>
//
// BabaState::reset() - リセット(最初にカードを配った状態にする)
//
void BabaState::reset(void)
{
 	int i,m,n,j=0;
       cs.makedeck();
      for(i=0; i<cs.getnumcard(); i++)
       {
          hand[i]=i%numplayer;
       }
      for(i=0; i<200; i++)
       {
     	   m=random()%cs.getnumcard();
          n=random()%cs.getnumcard();
          cs.swap(m,n);
       }
      n=0;
      do
      {
          for(i=n; i<cs.getnumcard(); i=i+numplayer)
           {
               if(hand[i]!=-1)
                   for(m=i+numplayer; m<cs.getnumcard(); m=m+numplayer)
                       if(hand[m]!=-1 && cs.equalnumber(i,m))
                          {   
                           hand[i]=-1; hand[m]=-1; 
                           break;
                          }
           }
          n++;
     }while(n<numplayer); 
}

bool BabaState::isfinished(int plr)
{
     int j=0;
     for(int i=plr; i<cs.getnumcard(); i+=numplayer)
      {
          if(hand[i]!=-1) return false;
      }
     return true;
}

int BabaState::locate(int plr, int no)
{
   int j=0, ans=-1;
   for(int i=plr; i<cs.getnumcard(); i=i+numplayer)
    {
        if(hand[i]!=-1) j++;
        if(j>=no+1) {ans=i; break;}
    }
    return ans;
}

bool BabaState::insert(int plr, int index)
{
   int ans=-2;
   for(int i=plr; i<cs.getnumcard(); i=i+numplayer)
    {
        if(hand[i]==-1 && ans==-2) ans=i;
        if(hand[i]!=-1 && cs.equalnumber(i,index)) 
        {hand[i]=-1; ans=-1; break;}
    }
    if(ans>=0) 
    {
        cs.swap(index, ans);
        hand[ans]=plr;
        return true;
    }
   return false;
}
//
// BabaState::print() - 自身の状態を標準出力に出力する
//
void BabaState::print(void)
{
  for(int i = 0; i < numplayer; i++) {
    std::cout <<"PLAYER"<<i<<"\t\t";
  }
  cs.print(hand);
  printf("\n");
}

int BabaState::leftcardnum(int plr)
{
   int j=0;
   for(int i=plr; i<cs.getnumcard(); i=i+numplayer)
        if(hand[i]!=-1) j++;
   return j;
}
bool BabaState::move(int from, int to)
{
   int num,i,j=0;
   std::cout<<"プレーヤ"<<to<<"はプレーヤ"<<from<<"のカードを取る。\n";
   std::cout<<"何番目のカードをとるか？(0から"<<leftcardnum(from)-1<<"まで入力): ";
   do
   {
   	std::cin>>num;
   }while(!(0<=num && num<leftcardnum(from)));
   int m=locate(from,num);
   if(m!=-1)
   {
       hand[m]=-1;
       if(insert(to,m)>0) return true;
   }
   return false;
}
