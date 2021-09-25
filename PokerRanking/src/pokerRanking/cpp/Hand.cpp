/**
 * @file CardValue.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation for the CardValue class
 * @version 0.1
 * @date 2021-09-25
 */

#include <sstream>

#include "Hand.h"

Hand::Hand() : handVector()
{
}

std::string Hand::toString()
{
    std::stringstream ss;
    ss << "[";
    for (unsigned int i = 0; i < handVector.size(); i++)
    {
        ss << handVector[i].toString();
        if (i != handVector.size() - 1)
        {
            ss << ", ";
        }
    }
    ss << "]";
    return ss.str();
}

bool Hand::addCard(Card card)
{
    if (handVector.size() >= HAND_SIZE)
    {
        return false;
    }
    handVector.push_back(card);
    return true;
}

Card Hand::getCard(int i)
{
    return handVector[i];
}