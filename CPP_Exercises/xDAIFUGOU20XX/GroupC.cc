/*
 *  LittleThinkPlayer.cpp
 *  PlayingCard
 *
 *  Created by 下薗 真一 on 09/04/12.
 *  Modified by Kazutaka Shimada on 09/04/21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <iostream>
#include <string>

#include "Card.h"
#include "CardSet.h"
#include "Player.h"
#include "GroupC.h"


bool GroupC::approve( CardSet & pile, int numCards[]) {
  memory.insert(pile);
  // memoryには他のプレイヤーが場に出したカードがストックされる
  
  // 自分自身のidは getId() で獲得できる
#ifndef TAIKAI_HONBAN
   std::cerr << "your information is "<< getName() << " " << getId() << std::endl;
  for (int i=0; numCards[i] != Dealer::NO_MORE_PLAYERS; i++){
    // numCardsには自分を含めたそれぞれの持ち札の数が格納されている
    // 配列の最後には終端検知のため -1 という値が入っている
    // numCardsの添字はプレイヤーのidを表す
     std::cerr << i << " " << numCards[i] << std::endl;
  }
#endif

  return true;
  
}

bool GroupC::follow(CardSet & pile, CardSet & s) {
	Card tmp, c, min;
	s.makeempty();
	c = pile.at(0);
	int i, j, crank, num, small=0, big=0, count[14] = {};

	for(i = 0; i< inHand().size(); i++){
		num = inHand().at(i).getrank();
		count[num]++;
		if(num>2 && num<13){
			if(count[num] == 1)
				small++;
		}
		else
			big++;
	} //所持枚数のリスト



	/*for(i = 0; i<14; i++){
	  printf(" %d ", count[i]);
	}//リスト表示
	*/

	if(pile.isempty()){//場のカードが空の時
		num = 1;
		crank = 0;
		for(i = 3; i<8; i++){//低い順から2枚以上あるカードを探索
			if(count[i]>=2){
				crank = i;
				num = count[i];
				break;
			}
		}
		
		if(num == 1)
		  for(i = 3; i<13; i++){//低い順から1枚以上あるカードを探索
		    if(count[i]>=1){
		      crank = i;
		      num = count[i];
		      break;
		    }
		  }

		for(i = 0; num > 0&&i<inHand().size(); i++){
			if(inHand().at(i).getrank() == crank){
				inHand().pickup(&tmp, i);
				s.insert(tmp);
				i--;
				num--;
			}
		}//3~13までの数字で出せるかどうかを判定

		if(s.isempty()){//だせなかった時,1番目のカードを出す
					inHand().pickup(&tmp, 0);
					s.insert(tmp);
		}
	}



	else{//空でないとき
		num = pile.size();
		//printf("\n num: %d : %d :\n",num, pile.at(0).getrank());
		if(pile.at(0).getrank() > 2){//3以上13以下の時、
			for(i = pile.at(0).getrank()+1; i < 13; i++){
				if(count[i] >= num){
					for(j = 0; num > 0; j++)
						if(inHand().at(j).getrank() == i){
							inHand().pickup(&tmp, j);
							s.insert(tmp);
							j--;
							num--;
						}
				}
			}
			if(s.isempty()){
					if(big >= (small)){
						for(i=0; i < inHand().size(); i++){
							if(inHand().at(i).isGreaterThan(c)){
								inHand().pickup(&tmp, i);
								s.insert(tmp);
								break;
							}
						}
					}
			}
		}
		else{
			if(big >= (small))
				for(i=0; i < inHand().size(); i++)
					if(inHand().at(i).isGreaterThan(c)){
						inHand().pickup(&tmp, i);
						s.insert(tmp);
						break;
					}
		}
	}
	return true;
}
