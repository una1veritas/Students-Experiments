/* 
 * File:   Group3.h
 * Author: yuuya
 *
 * Created on 2015/05/17, 20:34
 */
#include "Player.h"
 
#define N 14
 
class Group3 : public Player {
  CardSet memory;
  CardSet trump;
 
 private:
  int pairlist[N]; 
  int cardlist[6][15];
  int discard[N];
  int maxNumber;
 
 public:
 Group3(const char * name = "Little John") : Player(name) {
       
  }
 
  /*
   * グループで実態を作成し思考処理を追加する関数．
   */
  // ゲームを始めるにあたり必要な初期化をする．
  virtual void ready();
  // カードを出す思考処理を組み込む．
  virtual bool follow(const GameState &, CardSet &);
 
  virtual bool approve(const GameState &);
   
  /*
   *　思考処理用の関数群
   */
  // 手札のソーティング
  void HandOrder(void);
  // ペアのフラグを管理する
  void PairFlag(void);
  // ペアのフラグ配列の操作
  void PF_Sort(int);
  // 範囲内のカードかどうか
  bool Field(int, int, int);
  // 相手の手札か5枚以下になったことを示すフラグ（戦術切り替え）
  bool Active(const GameState &);
  // 役確認用、捨て札確認用の配列の初期化
  void InitArray(void);
  // 捨て札の枚数だけを確認する
  void Check(void);
  // ジョーカーが場に出ているか
  bool JokerFlag(void);

  bool HaveJoker(void);
  // 自身の出すカードより強いカードが何枚あるか
  int Stronger(int);
};
