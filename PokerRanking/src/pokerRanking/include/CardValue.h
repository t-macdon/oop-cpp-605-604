/**
 * @file CardValue.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Interface for the CardValue class
 * @version 0.1
 * @date 2021-09-22
 */

#ifndef CARD_VALUE_H
#define CARD_VALUE_H

#include <string>

/**
 * @brief Tracks the legal values of cards
 */
class CardValue {
    public:
        /**
         * @brief Enumerated values that a card can take
         * Explicitly use enum, not class, to permit conversion to int
         */
        enum Value {
            ACE=1,
            TWO,
            THREE,
            FOUR,
            FIVE,
            SIX,
            SEVEN,
            EIGHT,
            NINE,
            TEN,
            JACK,
            QUEEN,
            KING,
        };

        /**
         * @brief Construct a new Card Value object
         * Uses @ref stringToValue to map a string to a CardValue
         * @note We pass string by value as we modify the string inline, so cannot pass const ref
         * @param str 
         */
        CardValue(std::string str);

        /**
         * @brief Construct a new Card Value object
         * @param value 
         */
        CardValue(Value value);

        /**
         * @brief Get the Value object
         * 
         * @return Value 
         */
        Value getValue() const {return this->value; }

        /**
         * @brief Check for the distance between this card and another
         * Distance is always positive, and accounts for both high and low ace
         * @param v1 
         * @return int 
         */
        int distance(const CardValue& v1) const;

        /**
         * @brief Operator overload for the @ref distance method
         * @param v1 
         * @return int 
         */
        int operator-(const CardValue& v1) const;

        /**
         * @brief Check for equality between two cards
         * Cards are considered equal if they are of equal values. Suit is ignored.
         * @param v1 
         * @return true Cards match in value
         * @return false Cards don't match in value
         */
        bool operator==(const CardValue& v1) const;

        /**
         * @brief Inverse of the == operator.
         * Cards are considered equal if they are of equal values. Suit is ignored.
         */
        bool operator!=(const CardValue& v1) const;

        /**
         * @brief Check if a given card has a lower value
         * @param v1 
         */
        bool operator<(const CardValue& v1) const;

        /**
         * @brief Check if a given card has a higher value
         * @param v1 
         */
        bool operator>(const CardValue& v1) const;


        /**
         * @brief Return a string representation of this CardValue object
         * 
         * @return std::string 
         */
        std::string toString() const;
    private:
        /**
         * @brief Maps a given string to a card value
         * Throws a runtime error if no conversion can be made
         * @note We pass string by value as we modify the string inline, so cannot pass const ref
         * @param str 
         * @return Value 
         */
        static Value stringToValue(std::string str);
        
        /**
         * @brief Calculate the distance between two card values
         * 
         * @param v1 
         * @param v2 
         * @return int 
         */
        static int distanceBetweenValues(const CardValue& v1, const CardValue& v2);
        Value value;
};

#endif // end of CARD_VALUE_H
