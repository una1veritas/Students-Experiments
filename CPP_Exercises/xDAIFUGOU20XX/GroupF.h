/*
 * Created by Group F
 */

class GroupF : public Player {
  CardSet memory;

 public:
  GroupF(const char *);
  bool follow(CardSet &, CardSet &); // 現在は出せる最小のカードを出すだけ
  bool approve(CardSet &, int[]); // 現在は変更無し

  void sort(CardSet &); // 手札をソート
  void setstren(int[],CardSet); // 配列の準備
  int seekstren(int, int, int[]); // 出せるカードがあるか判定
  int rankTostren(int); // rank を stren に
  int strenTorank(int); // stren を rank に
  int SelectNextNum(CardSet &, int[]); // 出すカードの手札位置を返す
  void cardSetOfSameRanks(CardSet &, int); // 出すカードの枚数をあわせる
  void printstren(int[]); // 配列を表示
  int findpair(int,int[]); // ペアの個数を返す
  int pairsnum(int[]); // 手札のペア数を返す
  int havecards(int,int[]); // 手札にある引数のカードの枚数を返す
  int SelectNum(int); // 引数の数のカードの位置を返す
  int first_half(CardSet,int[]); //前半の戦略
  int latter_half(CardSet,int[]); //後半の戦略

};
