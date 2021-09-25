#ifndef HAND_H
#define HAND_H

#include <array>
#include <string>

#include "Card.h"

class Hand
{
public:
    Hand();
    static const int HAND_SIZE = 5;
    std::string toString();
private:
    std::array<Card, HAND_SIZE> handArray;
};

#endif