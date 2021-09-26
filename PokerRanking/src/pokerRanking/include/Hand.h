#ifndef HAND_H
#define HAND_H

#include <vector>
#include <string>

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
        NONE,
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
    std::vector<Card> handVector;
    Category category = Category::INCOMPLETE;

    /**
     * @brief Score is only used when the card category matches that of another hand
     */
    int score = 0;
};

#endif