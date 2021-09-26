/**
 * @file CardValue.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation for the CardValue class
 * @version 0.1
 * @date 2021-09-25
 */

#include <map>
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

    // now add category and score
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
        case Category::NONE: 
            categoryString = "NONE";
            break;
        case Category::INCOMPLETE: 
            categoryString = "INCOMPLETE";
            break;
    }
    ss << ", category=" << categoryString;
    ss << ", score:" << score;

    return ss.str();
}

bool Hand::addCard(Card card)
{
    if (handVector.size() >= HAND_SIZE)
    {
        return false;
    }
    handVector.push_back(card);
    if (handVector.size() == HAND_SIZE)
    {
        determineCategory();
    }
    return true;
}

void Hand::determineCategory()
{

    
    // check repeats in hand
    // first we build a map
    std::map<Card, int> cardMap;
    std::vector<Card>::iterator handItr;
    for (handItr = handVector.begin(); handItr != handVector.end(); handItr++)
    {
        std::pair<std::map<Card, int>::iterator, bool> result = cardMap.insert(std::pair<Card, int>(*handItr, 1));
        // if the bool is false then it was already there
        if (!result.second)
        {
            result.first->second++;
        }
    }

    // now we iterate over the map to see what duplicates we have and to generate a score
    std::map<Card, int>::iterator mapItr;
    int maxDuplicates = 1;
    int maxScore = 0;
    for (mapItr = cardMap.begin(); mapItr != cardMap.end(); mapItr++)
    {
        if (mapItr->second > maxDuplicates)
        {
            maxDuplicates = mapItr->second;
            maxScore = mapItr->second * mapItr->first.getValue().getValue();
        }
    }

    if (maxDuplicates == 2)
    {
        // 2 pair
        category = Category::TWO_OF_A_KIND;
        score = maxScore;
        return;
    } else if (maxDuplicates == 3)
    {
        // 3 pair
        category = Category::THREE_OF_A_KIND;
        score = maxScore;
        return;
    } else if (maxDuplicates == 4)
    {
        // 4 pair
        category = Category::FOUR_OF_A_KIND;
        score = maxScore;
        return;
    }

    // if we got this far, there's nothing!
    // so let's set the category to NONE
    // we also compute the score (adding up the card values)
    // just in case we compare to a hand that is also NONE
    category = Category::NONE;
    for (handItr = handVector.begin(); handItr != handVector.end(); handItr++)
    {
        score += handItr->getValue().getValue();
    }
}

Card Hand::getCard(int i)
{
    return handVector[i];
}