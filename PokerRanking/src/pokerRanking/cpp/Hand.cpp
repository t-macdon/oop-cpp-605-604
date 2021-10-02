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
    map<Card, int>::iterator mapItr;
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
    map<Card, int>::iterator mapItr;
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
    map<Card, int>::iterator mapItr;
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
    map<Card, int>::iterator mapItr;
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

Card Hand::getCard(int i) const
{
    return handVector.at(i);
}

CardValue Hand::getTieBreakerCardValue() const
{
    CardValue highest = CardValue::TWO;
    for(Card card: handVector) {
        highest = highest > card.getValue() ? highest : card.getValue();
    }
    return highest;
}

vector<Card> Hand::getHandVector() const {
    return this->handVector;
}
#if 1
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
#endif

int Hand::compareTo(const Hand& v1) const
{
    if (category < v1.getCategory())
    {
        return -1;
    } else if (category > v1.getCategory())
    {
        return 1;
    } else if (category == Category::FULL_HOUSE)
    {
        // first check 3 of a kind
        // if necessary, check 2 of a kind
        CardValue thisThreeOfAKind = getRepeatedCardValue(3);
        CardValue otherThreeOfAKind = v1.getRepeatedCardValue(3);
        if (thisThreeOfAKind < otherThreeOfAKind)
        {
            return -1;
        } else if (thisThreeOfAKind > otherThreeOfAKind)
        {
            return 1;
        } else
        {
            CardValue thisTwoOfAKind = getRepeatedCardValue(2);
            CardValue otherTwoOfAKind = v1.getRepeatedCardValue(2);
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
    } else if (category == Category::FLUSH)
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
    }
    else {
        int thisScore = getScore();
        int otherScore = v1.getScore();
        if (thisScore < otherScore)
        {
            return -1;
        } else if (thisScore > otherScore)
        {
            return 1;
        } else
        {
            return 0;
        }
    }
}


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
    int score = ((int)getCategory()*base*base) + 
                ((int)getHighCardValue().getValue() * base) +
                ((int)getTieBreakerCardValue().getValue());
    return score;
}

CardValue Hand::getRepeatedCardValue(int numberOfRepeats) const
{
    map<Card, int>::const_iterator counterIterator;
    for (counterIterator = pairCounter.begin(); counterIterator != pairCounter.end(); counterIterator++)
    {
        if (counterIterator->second == numberOfRepeats)
        {
            return counterIterator->first.getValue();
        }
    }
    return CardValue::NONE;
}
