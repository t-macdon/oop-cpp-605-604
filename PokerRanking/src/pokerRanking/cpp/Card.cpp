/**
 * @file Card.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief 
 * @version 0.1
 * @date 2021-09-22
 */

#include <sstream>
#include <stdexcept>
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

Card::Suit Card::stringToSuit(string str) {
    // Convert string to a lower-case representation
    for (auto& c : str) {
        c = tolower(c);
    }

    if (str.find("h") != string::npos ||
        str.find("heart") != string::npos) {
        return Suit::HEART;
    }

    if (str.find("d") != string::npos ||
        str.find("diamond") != string::npos) {
        return Suit::DIAMOND;
    }

    if (str.find("c") != string::npos ||
        str.find("club") != string::npos) {
        return Suit::CLUB;
    }

    if (str.find("s") != string::npos ||
        str.find("spade") != string::npos) {
        return Suit::SPADE;
    }

    // If we made it this far, we failed to convert.
    throw runtime_error("invalid string supplied");

}

Card::Suit Card::getSuit() const {
    return this->suit;
}

std::string Card::toString() const {
    std::stringstream ss;
    ss << getValue().toString();
    ss << suitToString(getSuit());
    return ss.str();
}

void Card::setValue(CardValue value) {
    this->value = CardValue(value);
}

CardValue Card::getValue() const {
    return this->value;
}

Card::Card(string str) : 
    value{str},
    suit{stringToSuit(str)}
{
}

int Card::operator-(const Card& v1) const {
    return (this->getValue() - v1.getValue());
}

bool Card::operator==(const Card& v1) const {
    // Trivial case, same object
    if (this == &v1) {
        return true;
    }
    return (this->getValue() == v1.getValue());
}

bool Card::operator!=(const Card& v1) const {
    return !(*this == v1);
}

bool Card::operator<(const Card& v1) const {
    return (this->getValue() < v1.getValue());
}

bool Card::operator>(const Card& v1) const {
    return (this->getValue() > v1.getValue());
}