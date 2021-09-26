#ifndef HAND_H
#define HAND_H

#include <map>
#include <string>
#include <vector>

#include "Card.h"

class Hand
{
public:
    enum class Category
    {
        STRAIGHT_FLUSH,
        FULL_HOUSE,
        FLUSH,
        STRAIGHT,
        FOUR_OF_A_KIND,
        THREE_OF_A_KIND,
        TWO_OF_A_KIND,
        TWO_PAIR,
        HIGH_CARD,
        INCOMPLETE
    };
    Hand();
    static const int HAND_SIZE = 5;
    std::string toString();
    bool addCard(Card card);
    Card getCard(int i);
    Category getCategory();
private:
    void determineCategory();
    bool isFlush();
    bool isStraight();
    bool isFourOfAKind();
    bool isThreeOfAKind();
    bool isTwoOfAKind();
    bool isTwoPair();
    bool isFullHouse();

    int getMostDuplicates();

    std::vector<Card> handVector;
    std::map<Card, int> pairCounter;
    Category category = Category::INCOMPLETE;
};

#endif