/**
 * @file Player.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Interface file for the Player class
 * @version 0.1
 * @date 2021-12-10
 * @copyright Copyright (c) 2021
 */

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include "Card.h"
#include "Hand.h"

class Player {
public:
    Player(std::string name, float money);
    void addCardToHand(Card &card);
    void resetHand();
    const Hand &getHand() const { return hand; }
    int handSize() const { return hand.size(); }

    virtual float bet(float ante) = 0;

    float getMoney() const {return money;}
    std::string getName() const {return name;}

    void addMoney(float money) { this->money += money; }
    void removeMoney(float money) { this->money -= money; }

private:
    Hand hand;
    float money;
    std::string name;
};

#endif // _PLAYER_H_
