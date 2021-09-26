/**
 * @file CardValue.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation for the CardValue class
 * @version 0.1
 * @date 2021-09-23
 */

#include <stdexcept>
#include <string>
#include <algorithm>
#include "CardValue.h"

using namespace std;

CardValue::Value CardValue::stringToValue(string str) {
    // Transform the string to a lower-case representation of it.
    // Honestly surprised C++11 didn't include something for this.
    for (auto& c : str) {
        c = tolower(c);
    }

    if (str.find("2") != string::npos) {
        return Value::TWO;
    }
    if (str.find("3") != string::npos) {
        return Value::THREE;
    }
    if (str.find("4") != string::npos) {
        return Value::FOUR;
    }
    if (str.find("5") != string::npos) {
        return Value::FIVE;
    }
    if (str.find("6") != string::npos) {
        return Value::SIX;
    }
    if (str.find("7") != string::npos) {
        return Value::SEVEN;
    }
    if (str.find("8") != string::npos) {
        return Value::EIGHT;
    }
    if (str.find("9") != string::npos) {
        return Value::NINE;
    }
    if (str.find("0") != string::npos ||
        str.find("1") != string::npos ||
        str.find("t") != string::npos) {
        return Value::TEN;
    }
    if (str.find("j") != string::npos) {
        return Value::JACK;
    }
    if (str.find("q") != string::npos) {
        return Value::QUEEN;
    }
    if (str.find("k") != string::npos) {
        return Value::KING;
    }
    if (str.find("a") != string::npos) {
        return Value::ACE;
    }

    // If we made it this far, we failed to convert.
    throw runtime_error("invalid string supplied");
}

std::string CardValue::toString()
{
    switch(value)
    {
        case Value::ACE: return "A";
        case Value::KING: return "K";
        case Value::QUEEN: return "Q";
        case Value::JACK: return "J";
        case Value::TEN: return "10";
        case Value::NINE: return "9";
        case Value::EIGHT: return "8";
        case Value::SEVEN: return "7";
        case Value::SIX: return "6";
        case Value::FIVE: return "5";
        case Value::FOUR: return "4";
        case Value::THREE: return "3";
        case Value::TWO: return "2";
        default: return "?";
    }
}

CardValue::CardValue(std::string str) {
    value = stringToValue(str);
}

CardValue::CardValue(CardValue::Value value) :
    value{value}
{ }

int CardValue::distance(const CardValue& v1) const {
    return distanceBetweenValues(*this, v1);
}

int CardValue::distanceBetweenValues(const CardValue& v1, const CardValue& v2) {
    const int v1AsInt = static_cast<int> (v1.getValue());
    const int v2AsInt = static_cast<int> (v2.getValue());

    if (v1.getValue() == v2.getValue()) {
        return 0;
    }

    else if (v1.getValue() != Value::ACE && v2.getValue() != Value::ACE) {
        return abs(v1AsInt - v2AsInt);
    }

    // At this point, one of our two values is an Ace
    else {
        // Ace can be of either value; higher than King or lower than 2.
        // The distance is the minimum distance between the two.
        const int lowAceAsInt = static_cast<int>(Value::TWO) - 1;
        const int highAceAsInt = static_cast<int>(Value::KING) + 1;
        const int notAceValue = (v1.getValue() != Value::ACE) ? v1AsInt : v2AsInt;
        const int distanceWithLowAce = abs(lowAceAsInt - notAceValue);
        const int distanceWithHighAce = abs(highAceAsInt - notAceValue);

        return min(distanceWithLowAce, distanceWithHighAce);
    }
}


int CardValue::operator-(const CardValue& v1) const {
    return distance(v1);
}

bool CardValue::operator==(const CardValue& v1) const {
    // Trivial case, same object
    if (this == &v1) {
        return true;
    }
    return this->getValue() == v1.getValue();
}

bool CardValue::operator!=(const CardValue& v1) const {
    return !(*this == v1);
}

bool CardValue::operator<(const CardValue& v1) const {
    return this->getValue() < v1.getValue();
}

bool CardValue::operator>(const CardValue& v1) const {
    return this->getValue() > v1.getValue();
}