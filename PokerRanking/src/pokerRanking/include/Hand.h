#ifndef HAND_H
#define HAND_H

#include <vector>
#include <string>

#include "Card.h"

class Hand
{
public:
    Hand();
    static const int HAND_SIZE = 5;
    std::string toString();
    bool addCard(Card card);
    Card getCard(int i);
private:
    std::vector<Card> handVector;
};

#endif