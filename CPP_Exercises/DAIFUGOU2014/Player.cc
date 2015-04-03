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
	hand.makeempty();
	id=-1;
	name = given;
	return;
}

std::string Player::playerName() { 
	return name; 
}


std::ostream & Player::printStream(std::ostream & out) const {
	out << name << ": ";
	hand.printStream(out);
	return out;
}

void Player::setId(int temp){
  id=temp;
}

int Player::getId(){
  return id;
}

void Player::clearHand() {
	hand.makeempty();
}

bool Player::isEmptyHanded() {
	return hand.isempty();
}

bool Player::pickup(Card c) {
	return hand.insert(c);
}

bool Player::takeCards(CardSet & s) {
	Card tmp;
	while (!s.isempty()) {
		s.pickup(&tmp, 0);
		hand.insert(tmp);
	}
	return true;
}

bool Player::approve(CardSet & pile, int numCards[]) {
  return true;
}

bool Player::follow(CardSet & pile, CardSet & s) {
	Card tmp;
	s.makeempty();
	hand.pickup(&tmp, -1); // choose a card.
	/*
	 * いったん tmp のカードは手札からなくなる
	 */
	s.insert(tmp);
	return true;
}
