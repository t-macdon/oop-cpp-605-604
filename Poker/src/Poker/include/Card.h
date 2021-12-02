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

/**
 * @brief The Card class tracks a single playing card instance
 * A card consists of a Suit and a Value
 */
class Card {
    public:
        /**
         * @brief All possible card suits, enumerated
         */
        enum class Suit {
            HEART,
            DIAMOND,
            CLUB,
            SPADE,
        };

        /**
         * @brief Construct a new Card object
         * Will call the constructor for CardValue
         * Expects a string containing a [h,d,c,s] for suit as well
         * Throws runtime error if no card can be created
         */
        Card(std::string);

        /**
         * @brief Get the Suit object
         * @return Suit 
         */
        Suit getSuit() const;

        /**
         * @brief Get the Value object
         * @return CardValue 
         */
        CardValue getValue() const;

        /**
         * @brief Generate a string representation of this card
         * @return std::string 
         */
        std::string toString() const;

        /**
         * @brief Set the Value object
         * @param value 
         */
        void setValue(CardValue value);
        
        /**
         * @brief Calculate the distance between two cards
         * @param v1 
         * @return int 
         */
        int operator-(const Card& v1) const;

        /**
         * @brief Check for equality between two cards
         * Cards are considered equal if they are of equal values. Suit is ignored.
         * @param v1 
         * @return true Cards match in value
         * @return false Cards don't match in value
         */
        bool operator==(const Card& v1) const;

        /**
         * @brief Inverse of the == operator.
         * Cards are considered equal if they are of equal values. Suit is ignored.
         */
        bool operator!=(const Card& v1) const;

        /**
         * @brief Check if a given card has a lower value
         * @param v1 
         */
        bool operator<(const Card& v1) const;

        /**
         * @brief Check if a given card has a higher value
         * @param v1 
         */
        bool operator>(const Card& v1) const;
    private:

        /**
         * @brief Get a Unicode string representation of a suit 
         * @param suit 
         * @return std::string 
         */
        static std::string suitToString(Suit suit);

        /**
         * @brief Maps [h,d,c,s] to a suit. Case-insensitive
         * throws a runtime exception if no match can be found
         * @param str 
         * @return Suit 
         */
        static Suit stringToSuit(std::string str);

        CardValue value;
        Suit suit;
};

#endif // end of CARD_H