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
        FOUR_OF_A_KIND,
        FULL_HOUSE,
        FLUSH,
        STRAIGHT,
        THREE_OF_A_KIND,
        TWO_PAIR,
        TWO_OF_A_KIND,
        HIGH_CARD,
        INCOMPLETE
    };
    Hand();
    static const int HAND_SIZE = 5;
    std::string toString() const;
    bool addCard(Card card);
    Card getCard(int i) const;
    Category getCategory() const;

    bool operator<(const Hand& v1) const;
    bool operator>(const Hand& v1) const;
    bool operator=(const Hand& v1) const;
    bool operator!=(const Hand& v1) const;

private:
    void determineCategory();
    void determineScore();
    bool isFlush();
    bool isStraight();
    bool isFourOfAKind();
    bool isThreeOfAKind();
    bool isTwoOfAKind();
    bool isTwoPair();
    bool isFullHouse();

    int getMostDuplicates();

    int compareTo(const Hand& v1) const;

    CardValue getHighCardValue() const;

    std::vector<Card> handVector;
    std::map<Card, int> pairCounter;
    Category category = Category::INCOMPLETE;

    int score = 0;
};

#endif