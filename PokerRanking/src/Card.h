/**
 * @file Card.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Interface for the Card class
 * @version 0.1
 * @date 2021-09-22
 */

#ifndef CARD_H
#define CARD_H

#include <string>
#include "CardValue.h"

class Card {
    public:
        enum class Suit {
            HEART,
            DIAMOND,
            CLUB,
            SPADE,
        };
        Card(std::string);
        Suit getSuit() const;
        CardValue getValue() const;
        void setValue(CardValue value);
        int operator-(const Card& v1) const;
        bool operator==(const Card& v1) const;
        bool operator!=(const Card& v1) const;
    private:
        static std::string suitToString(Suit suit);
        static Suit stringToSuit(std::string str);

        CardValue value;
        Suit suit;
};

#endif // end of CARD_H