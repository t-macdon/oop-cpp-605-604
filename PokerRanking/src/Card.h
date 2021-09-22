/**
 * @file Card.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief 
 * @version 0.1
 * @date 2021-09-22
 */

#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
    enum class Suit {
        HEART,
        DIAMOND,
        CLUB,
        SPADE,
    };

    public:
        bool operator==(const Card& card);
        bool operator>(const Card& card);
        bool operator<(const Card& card);

        Suit getSuit() const;
        char getValue() const;
        void setValue(char value);
    private:
        static std::string suitToString(Suit suit);
        static Suit stringToSuit(std::string str);

        Suit suit;
        char value;
        // Add in >, <, = operators
};

#endif // end of CARD_H