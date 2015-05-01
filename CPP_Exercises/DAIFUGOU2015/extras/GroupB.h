/*
 *  Player.h
 *  PlayingCard
 *
 *  Created by 下薗 真一 on 09/04/12.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

class GroupB : public Player {
  CardSet memory;
  bool* pairFlag;
  int myCards;

  Card fieldGreatestCard;
  Card handGreatestCard;
  
 public:
  GroupB(const char name[] = "Bob") : Player(name) {
    init();
  }

  bool follow(CardSet &, CardSet &);
  bool approve(CardSet &, int[]);
  
 private:
  void init();
  void sort();
  void searchPair();
  bool multiCard(CardSet &);
  bool multiCard(CardSet &, CardSet &);
  int searchMemory(int);
  void memoryInsert(CardSet &);
  Card pairRank(CardSet &);
  
};
