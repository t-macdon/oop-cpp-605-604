/**
 * @file CardValue.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation for the CardValue class
 * @version 0.1
 * @date 2021-09-25
 */

#include <algorithm>
#include <map>
#include <sstream>

#include "Hand.h"

Hand::Hand() : handVector(), pairCounter()
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

    // now add category
    std::string categoryString;
    switch (category)
    {
        case Category::STRAIGHT_FLUSH: 
            categoryString = "STRAIGHT_FLUSH";
            break;
        case Category::FULL_HOUSE: 
            categoryString = "FULL_HOUSE";
            break;
        case Category::FLUSH: 
            categoryString = "FLUSH";
            break;
        case Category::STRAIGHT: 
            categoryString = "STRAIGHT";
            break;
        case Category::FOUR_OF_A_KIND: 
            categoryString = "FOUR_OF_A_KIND";
            break;
        case Category::THREE_OF_A_KIND: 
            categoryString = "THREE_OF_A_KIND";
            break;
        case Category::TWO_OF_A_KIND: 
            categoryString = "TWO_OF_A_KIND";
            break;
        case Category::TWO_PAIR: 
            categoryString = "TWO_PAIR";
            break;
        case Category::HIGH_CARD: 
            categoryString = "HIGH_CARD";
            break;
        case Category::INCOMPLETE: 
            categoryString = "INCOMPLETE";
            break;
    }
    ss << ", category=" << categoryString;

    return ss.str();
}

bool Hand::addCard(Card card)
{
    // can't add a card if there are already HAND_SIZE cards
    if (handVector.size() >= HAND_SIZE)
    {
        return false;
    }
    
    // add to the vector and the pair counter
    handVector.push_back(card);
    std::pair<std::map<Card, int>::iterator, bool> result = pairCounter.insert(std::pair<Card, int>(card, 1));
    // if the bool is false then it was already there
    if (!result.second)
    {
        result.first->second++;
    }

    // if we have a full hand, it's time to determine the category
    if (handVector.size() == HAND_SIZE)
    {
        determineCategory();
    }
    return true;
}

bool Hand::isFlush()
{
    // start with the first suit to compare to
    Card::Suit suit = handVector.at(0).getSuit();
    for (unsigned int i = 1; i < handVector.size(); i++)
    {
        if (handVector.at(i).getSuit() != suit)
        {
            return false;
        }
    }
    return true;
}

bool Hand::isStraight()
{
    // we compare every sequential coupling of cards
    // they should all have a distance of 1 for a straight
    // note we assume the vector has been sorted
    for (unsigned int i = 0; i < handVector.size()-1; i++)
    {
        if (handVector.at(i+1) - handVector.at(i) != 1)
        {
            return false;
        }
    }
    return true;
}

bool Hand::isFourOfAKind()
{
    std::map<Card, int>::iterator mapItr;
    for (mapItr = pairCounter.begin(); mapItr != pairCounter.end(); mapItr++)
    {
        if (mapItr->second == 4)
        {
            return true;
        }
    }
    return false;
}

bool Hand::isThreeOfAKind()
{
    std::map<Card, int>::iterator mapItr;
    for (mapItr = pairCounter.begin(); mapItr != pairCounter.end(); mapItr++)
    {
        if (mapItr->second == 3)
        {
            return true;
        }
    }
    return false;
}

bool Hand::isTwoOfAKind()
{
    std::map<Card, int>::iterator mapItr;
    for (mapItr = pairCounter.begin(); mapItr != pairCounter.end(); mapItr++)
    {
        if (mapItr->second == 2)
        {
            return true;
        }
    }
    return false;
}

bool Hand::isTwoPair()
{
    int numberOfPairs = 0;
    std::map<Card, int>::iterator mapItr;
    for (mapItr = pairCounter.begin(); mapItr != pairCounter.end(); mapItr++)
    {
        if (mapItr->second == 2)
        {
            numberOfPairs++;
        }
    }
    if (numberOfPairs == 2)
    {
        return true;
    }
    return false;
}

void Hand::determineCategory()
{
    // we need the hand to be sorted, so ensure that here
    std::sort(handVector.begin(), handVector.end());

    // straight flush
    bool straight = isStraight();
    bool flush = isFlush();
    if (straight && flush)
    {
        category = Category::STRAIGHT_FLUSH;
        return;
    }

    // 4 of a kind
    if (isFourOfAKind())
    {
        category = Category::FOUR_OF_A_KIND;
        return;
    }

    // full house
    bool threeOfAKind = isThreeOfAKind();
    bool twoOfAKind = isTwoOfAKind();
    if (threeOfAKind && twoOfAKind)
    {
        category = Category::FULL_HOUSE;
        return;
    }

    // flush
    if (flush)
    {
        category = Category::FLUSH;
        return;
    }

    // straight
    if (straight)
    {
        category = Category::STRAIGHT;
        return;
    }

    // three of a kind
    if (threeOfAKind)
    {
        category = Category::THREE_OF_A_KIND;
        return;
    }

    // two pair
    if (isTwoPair())
    {
        category = Category::TWO_PAIR;
        return;
    }

    // two of a kind
    if (twoOfAKind)
    {
        category = Category::TWO_OF_A_KIND;
        return;
    }

    // if we got this far, there's nothing good!
    // so let's set the category to HIGH_CARD
    category = Category::HIGH_CARD;
}

Card Hand::getCard(int i)
{
    return handVector[i];
}