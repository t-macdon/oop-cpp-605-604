/**
 * @file Hand.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation for the Hand class
 * @version 0.1
 * @date 2021-09-25
 */

#include <algorithm>
#include <map>
#include <sstream>
#include <vector>

#include "Hand.h"

using namespace std;

Hand::Hand() : handVector(), pairCounter()
{
}

string Hand::categoryAsString() const {
    switch(getCategory()) {
        case Category::HIGH_CARD:
            return "High Card";
        case Category::TWO_OF_A_KIND:
            return "Two Of A Kind";
        case Category::TWO_PAIR:
            return "Two Pairs";
        case Category::THREE_OF_A_KIND:
            return "Three Of A Kind";
        case Category::STRAIGHT:
            return "Straight";
        case Category::FLUSH:
            return "Flush";
        case Category::FULL_HOUSE:
            return "Full House";
        case Category::FOUR_OF_A_KIND:
            return "Four Of A Kind";
        case Category::STRAIGHT_FLUSH:
            return "Straight Flush";
        case Category::INCOMPLETE:
        default:
            return "INCOMPLETE";
    }
}

string Hand::toString() const
{
    stringstream ss;
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

ostream& operator<<(ostream& os, const Hand& hand) {
    string handAsString = hand.toString();
    os << handAsString;
    return os;
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
    pair<map<Card, int>::iterator, bool> result = pairCounter.insert(pair<Card, int>(card, 1));
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

vector<CardValue> Hand::getWildCardValues() const 
{
    return wildCardValues;
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
    // There are no wildcards in a flush
    wildCardValues.clear();
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

    // There are no wildcards in a straight
    wildCardValues.clear();
    return true;
}

bool Hand::isFourOfAKind()
{
    map<Card, int>::iterator mapItr;
    vector<CardValue> possibleWildCards;
    bool fourOfAKindFound = false;
    for (mapItr = pairCounter.begin(); mapItr != pairCounter.end(); mapItr++)
    {
        if (mapItr->second == 4)
        {
            fourOfAKindFound = true;
        }
        else
        {
            possibleWildCards.push_back(mapItr->first.getValue());
        }
    }

    if (fourOfAKindFound)
    {
        wildCardValues = possibleWildCards;
    }
    return fourOfAKindFound;
}

bool Hand::isThreeOfAKind()
{
    map<Card, int>::iterator mapItr;
    vector<CardValue> possibleWildCards;
    bool threeOfAKindFound = false;
    for (mapItr = pairCounter.begin(); mapItr != pairCounter.end(); mapItr++)
    {
        if (mapItr->second == 3)
        {
            threeOfAKindFound = true;
        }
        else
        {
            possibleWildCards.push_back(mapItr->first.getValue());
        }
    }
    if (threeOfAKindFound)
    {
        wildCardValues = possibleWildCards;
    }
    return threeOfAKindFound;
}

bool Hand::isTwoOfAKind()
{
    map<Card, int>::iterator mapItr;
    vector<CardValue> possibleWildCards;
    bool twoOfAKindFound = false;
    for (mapItr = pairCounter.begin(); mapItr != pairCounter.end(); mapItr++)
    {
        if (mapItr->second == 2)
        {
            twoOfAKindFound = true;
        }
        else
        {
            possibleWildCards.push_back(mapItr->first.getValue());
        }
    }
    if (twoOfAKindFound)
    {
        wildCardValues = possibleWildCards;
    }
    return twoOfAKindFound;
}

bool Hand::isTwoPair()
{
    int numberOfPairs = 0;
    map<Card, int>::iterator mapItr;
    vector<CardValue> possibleWildCards;
    for (mapItr = pairCounter.begin(); mapItr != pairCounter.end(); mapItr++)
    {
        if (mapItr->second == 2)
        {
            numberOfPairs++;
        }
        else
        {
            possibleWildCards.push_back(mapItr->first.getValue());
        }
    }
    if (numberOfPairs == 2)
    {
        wildCardValues = possibleWildCards;
        return true;
    }
    return false;
}

void Hand::determineCategory()
{
    // we need the hand to be sorted, so ensure that here
    sort(handVector.begin(), handVector.end());

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
        wildCardValues.clear();
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
    CardValue highCardValue = getHighCardValue();
    for(Card c: handVector)
    {
        if (c.getValue() < highCardValue)
        {
            wildCardValues.push_back(c.getValue());
        }
    }
}

Card Hand::getCard(int i) const
{
    return handVector.at(i);
}

int Hand::getTieBreaker(const Hand& h1, const Hand& h2)
{
    vector<CardValue> v1 = h1.getWildCardValues();
    vector<CardValue> v2 = h2.getWildCardValues();

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    size_t cardsToCompare = min(v1.size(), v2.size());
    for(size_t idx = 0; idx < cardsToCompare; idx++) {
        CardValue card1 = v1.at(v1.size()-1-idx);
        CardValue card2 = v2.at(v2.size()-1-idx);
        if(card1 == card2) {
            continue;
        }
        if(card1 > card2) {
            return 1;
        }
        else {
            return -1;
        }
    }
    return 0;
}

vector<Card> Hand::getHandVector() const {
    return this->handVector;
}

CardValue Hand::getHighCardValue() const
{
    map<Card, int>::const_iterator counterIterator;
    CardValue highest = CardValue::TWO;
    for (counterIterator = pairCounter.begin(); counterIterator != pairCounter.end(); counterIterator++)
    {
        // first check for the duplicate cases
        bool isFourOfAKindHighest = (category == Category::FOUR_OF_A_KIND && counterIterator->second == 4);
        bool isThreeOfAKindHighest = (category == Category::THREE_OF_A_KIND && counterIterator->second == 3);
        bool isTwoOfAKindHighest = (category == Category::TWO_OF_A_KIND && counterIterator->second == 2);
        if (isFourOfAKindHighest || isThreeOfAKindHighest || isTwoOfAKindHighest)
        {
            return counterIterator->first.getValue();
        }

        // for two pair, we keep track of highest card but only if it's one of the two pairs
        bool isTwoPairCard = category == Category::TWO_PAIR && counterIterator->second == 2;
        if (isTwoPairCard || category == Category::HIGH_CARD || category == Category::STRAIGHT || 
            category == Category::STRAIGHT_FLUSH || category == Category::FLUSH)
        {
            // update highest valued card if applicable
            if (counterIterator->first.getValue() > highest)
            {
                highest = counterIterator->first.getValue();
            }
        }
    }
    return highest;
}

int Hand::compareTo(const Hand& v1) const
{
    if (category < v1.getCategory())
    {
        return -1;
    } 
    else if (category > v1.getCategory())
    {
        return 1;
    } 
    // The two hands have the same category
    else 
    {
        // Special case for comparing hands: Full House
        if (category == Category::FULL_HOUSE)
        {
            // first check 3 of a kind
            // if necessary, check 2 of a kind
            CardValue thisThreeOfAKind = getRepeatedCardValue(3).front();
            CardValue otherThreeOfAKind = v1.getRepeatedCardValue(3).front();
            if (thisThreeOfAKind < otherThreeOfAKind)
            {
                return -1;
            } else if (thisThreeOfAKind > otherThreeOfAKind)
            {
                return 1;
            } else
            {
                CardValue thisTwoOfAKind = getRepeatedCardValue(2).front();
                CardValue otherTwoOfAKind = v1.getRepeatedCardValue(2).front();
                if (thisTwoOfAKind < otherTwoOfAKind)
                {
                    return -1;
                } else if (thisTwoOfAKind > otherTwoOfAKind)
                {
                    return 1;
                } else
                {
                    return 0;
                }
            }
        } // End of full house category match
        // Special case for comparing hands: Flush
        else if (category == Category::FLUSH)
        {
            vector<Card> thisHand = this->getHandVector();
            vector<Card> v1Hand = v1.getHandVector();
            for(int i=thisHand.size()-1 ; i >= 0; i--) {
                if(thisHand[i] == v1Hand[i]) {
                    continue;
                }
                else if (thisHand[i] > v1Hand[i]) {
                    return 1;
                }
                else {
                    return -1;
                }
            }
            return 0;
        } // End of flush category match
        // Special case for comparing hands: Two pairs
        else if (category == Category::TWO_PAIR)
        {
            // For this case, we do two one_pair comparisons.
            vector<CardValue> thisValues = getRepeatedCardValue(2);
            vector<CardValue> v1Values = v1.getRepeatedCardValue(2);
            if (thisValues.back() == v1Values.back()) {
                if(thisValues.front() == v1Values.front()) {
                    return getTieBreaker(*this, v1);
                }
                else {
                    return (thisValues.front() > v1Values.front()) ? 1 : -1;
                }
            }
            else {
                return (thisValues.back() > v1Values.back()) ? 1 : -1;
            }
        } // End of two pair category match
        // General case for when the categories match
        else 
        {
            int thisScore = getScore();
            int otherScore = v1.getScore();
            if (thisScore == otherScore) {
                // Move on to the tie-breaker
                return getTieBreaker(*this, v1);
            } else {
                return (thisScore > otherScore) ? 1 : -1;
            }
        } // End of general category match
    } // End of category match
} // End of compareTo function


bool Hand::operator<(const Hand& v1) const
{
    if (compareTo(v1) == -1)
    {
        return true;
    } else
    {
        return false;
    }
}

bool Hand::operator>(const Hand& v1) const
{
    if (compareTo(v1) == 1)
    {
        return true;
    } else
    {
        return false;
    }
}

bool Hand::operator==(const Hand& v1) const
{
    if (compareTo(v1) == 0)
    {
        return true;
    } else
    {
        return false;
    }
}

Hand::Category Hand::getCategory() const
{
    return category;
}

int Hand::getScore() const
{
    const int base = CardValue::ACE+1;
    // Find the strength of this category.
    // This is determined by the highest value card that makes
    // Up the category. By wary of Ace, it can be the highest or lowest.
    CardValue categoryStrength = CardValue::TWO;
    vector<CardValue> categoryCardValues = getCategoryCardValues();
    sort(categoryCardValues.begin(), categoryCardValues.end());
    categoryStrength = categoryCardValues.back();
    // Ace can be a pain if we're in a straight
    if(category == Category::STRAIGHT || category == Category::STRAIGHT_FLUSH) {
        // Do we have a LOW ACE?
        if(categoryStrength == CardValue::ACE &&
           categoryCardValues.front() == CardValue::TWO) {
               // If we have a low ace, pick the card value
               // that is just below ace
            categoryStrength = categoryCardValues.at(categoryCardValues.size()-2);
        }
    }


    int score = ((int)getCategory()*base) + 
                ((int)categoryStrength.getValue());

    return score;
}

vector<CardValue> Hand::getCategoryCardValues() const
{
    vector<CardValue> categoryCardValues;
    vector<CardValue> wildCardValues = getWildCardValues();
    for(Card c: getHandVector())
    {
        auto v = find(wildCardValues.begin(), wildCardValues.end(), c.getValue());
        // Did not find this card in wildCards, so it's part of category
        if (v == wildCardValues.end()) {
            categoryCardValues.push_back(c.getValue());
        }
    }
    return categoryCardValues;
}

vector<CardValue> Hand::getRepeatedCardValue(int numberOfRepeats) const
{
    map<Card, int>::const_iterator counterIterator;
    vector<CardValue> repeatedValues;
    for (counterIterator = pairCounter.begin(); counterIterator != pairCounter.end(); counterIterator++)
    {
        if (counterIterator->second == numberOfRepeats)
        {
            repeatedValues.push_back(counterIterator->first.getValue());
        }
    }
    if (repeatedValues.empty()) {
        return vector<CardValue>{CardValue::NONE};
    }
    sort(repeatedValues.begin(), repeatedValues.end());
    return repeatedValues;
}
