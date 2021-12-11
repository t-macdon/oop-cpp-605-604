/**
 * @file Player.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation file for the Player class
 * @version 0.1
 * @date 2021-12-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <string>
#include "Player.h"
#include "Card.h"
#include "Hand.h"

using namespace std;

Player::Player(string name, float money) :
    money{money}, name{name}
{
    ;
}

void Player::addCardToHand(Card &card) {
    hand.addCard(card);
}

void Player::resetHand() {
    hand = Hand{};
}