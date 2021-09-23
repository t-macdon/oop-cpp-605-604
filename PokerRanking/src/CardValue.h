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
        // Explicitly use enum, not class, to permit conversion to int
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
        // We will be modifying the string inline, so pass by value to copy it.
        CardValue(std::string str);
        CardValue(Value value);
        // Overload the usual comparison operators.
        // Might also be worth adding a "distance" function and
        // include that with the subtract operator.
        // The idea would be to find successive cards.

        Value getValue() const {return this->value; }
        int distance(const CardValue& v1) const;
        int operator-(const CardValue& v1) const;
        bool operator==(const CardValue& v1) const;
        bool operator!=(const CardValue& v1) const;

        // How would the "hand checker" look? 
        // Do we need to sort the hand before looking for highest scores?
        // If so, we probably need to implement >, < operators.
        // So what happens with ACE?
        // Otherwise, can we use just distance?
    private:
        // We will be modifying the string inline, so pass by value to copy it.
        static Value stringToValue(std::string str);
        static int distanceBetweenValues(const CardValue& v1, const CardValue& v2);
        Value value;
};

#endif // end of CARD_VALUE_H
