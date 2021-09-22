/**
 * @file Card.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief 
 * @version 0.1
 * @date 2021-09-22
 */

#include <string>
#include "Card.h"

using namespace std;

string Card::suitToString(Card::Suit suit) {
    string suitAsString = "?";
    switch(suit) {
        case Suit::CLUB: {
            suitAsString = "♧";
            break;
        }
        case Suit::DIAMOND: {
            suitAsString = "♢";
            break;
        }
        case Suit::HEART: {
            suitAsString = "♡";
            break;
        }
        case Suit::SPADE: {
            suitAsString = "♤";
            break;
        }
    }
    return suitAsString;
}


Card::Suit Card::getSuit() const {
    return this->suit;
}

void Card::setValue(char value) {
    // Force the lowercase version of all values
    value = tolower(value);
    // TODO: Actually probably worth pushing this off to a separate class
    // How do we represent 10 with char?
    // Comparison of them would be nicely contained in a class.
}

char Card::getValue() const {
    return this->value;
}

bool Card::operator==(const Card& card) {
    return this->getValue() == card.getValue();
}

bool Card::operator>(const Card& card) {

}

bool Card::operator<(const Card& card) {

}