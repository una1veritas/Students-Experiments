/*
 * GroupEPlayer1.h
 * Created by 一瀬航 on 13/05/02
 *
 */



class GroupEPlayer1 : public Player {
  CardSet memory;
  int singlcard[13];
  int twocards[13];//添字0~12の配列の中に1~13のカードで2ペアのものに1、それ以外は0
  int threecards[13];
  int fourcards[13];
  int two_flag;
  int three_flag;
  int four_flag;
  int joker_flag;

 public:
  GroupEPlayer1(const char *);
  bool follow(CardSet &, CardSet &);
  bool approve(CardSet &,int[]);
  Card min_card(Card c[],int limit);
  void SearchCards(void);
  CardSet PickUpCard(int i);
 };
