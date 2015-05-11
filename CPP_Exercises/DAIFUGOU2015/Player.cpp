/*
 *  Player.cpp
 *  PlayingCard
 *
 *  Created by 下薗 真一 on 09/04/12.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <stdio.h>
#include <string.h>

#include <iostream>

#include "Card.h"
#include "CardSet.h"
#include "Player.h"

Player::Player(char const * given) {
	hand.makeEmpty(); //clear();
	id=-1;
	name = given;
	return;
}

std::ostream & Player::printOn(std::ostream & out) const {
	out << name << ": ";
	hand.printOn(out);
	return out;
}

void Player::setId(int temp){
  id=temp;
}

int Player::getId() const{
  return id;
}

void Player::clearHand() {
	hand.makeEmpty();
}

bool Player::isEmptyHanded() const {
	return hand.isEmpty();
}

bool Player::pickup(Card c) {
	return hand.insert(c);
}

bool Player::takeCards(CardSet & s) {
	Card tmp;
	while (!s.isEmpty()) {
		s.pickup(tmp, 0);
		hand.insert(tmp);
	}
	return true;
}

bool Player::approve(const GameStatus & gstat) {
  return true;
}

bool Player::follow(const GameStatus & gstat, CardSet & cards) {
	CardSet pile(gstat.pile);
	Card tmp;
	cards.makeEmpty();
	hand.pickup(tmp, -1); // choose a card.
	/*
	 * いったん tmp のカードは手札からなくなる
	 */
	cards.insert(tmp);
	return true;
}

