/**
 * @file Hand.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Interface file for the Hand class
 * @version 0.1
 * @date 2021-09-26
 */

#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Card.h"

/**
 * @brief Container and evaluator of Card objects
 */
class Hand
{
public:
    /**
     * @brief Tracks all possible categories of poker hands
     */
    enum class Category
    {
        INCOMPLETE,
        HIGH_CARD,
        TWO_OF_A_KIND,
        TWO_PAIR,
        THREE_OF_A_KIND,
        STRAIGHT,
        FLUSH,
        FULL_HOUSE,
        FOUR_OF_A_KIND,
        STRAIGHT_FLUSH
    };

    /**
     * @brief Return this hand's category as a string
     * 
     * @return std::string 
     */
    std::string categoryAsString() const;

    /**
     * @brief Construct a new Hand object
     */
    Hand();

    /**
     * @brief Public constant to track the size of a player's hand
     */
    static const int HAND_SIZE = 5;

    /**
     * @brief Return a string representation of this object
     * @return std::string 
     */
    std::string toString() const;


    /**
     * @brief Returns the size of this hand
     * @return int 
     */
    inline int size() const { return handVector.size(); }

    /**
     * @brief Add a card to this hand
     * 
     * @param card 
     * @return true Card was able to be added
     * @return false Card could not be added
     */
    bool addCard(Card card);

    /**
     * @brief Get the Card object from a specified index
     * @note May throw an out_of_range error
     * @param i 
     * @return Card 
     */
    Card getCard(int i) const;

    /**
     * @brief Get the Category object
     * @return Category 
     */
    Category getCategory() const;

    /**
     * @brief See @ref compareTo
     * @param v1 
     * @return true compareTo is -1
     * @return false compareTo is not -1
     */
    bool operator<(const Hand& v1) const;

    /**
     * @brief See @ref compareTo
     * @param v1 
     * @return true compareTo is 1
     * @return false compareTo is not 1
     */
    bool operator>(const Hand& v1) const;

    /**
     * @brief See @ref compareTo
     * @param v1 
     * @return true compareTo is 0
     * @return false compareTo is not 0
     */
    bool operator==(const Hand& v1) const;

    /**
     * @brief Get a copy of this hand's underlying vector of cards
     * @return std::vector<Card> 
     */
    std::vector<Card> getHandVector() const;

    /**
     * @brief Get a vector of the cards that are not contributing to the category
     * @return std::vector<CardValue> 
     */
    std::vector<CardValue> getWildCardValues() const;

    /**
     * @brief Get a vector of the cards that are contributing to the category
     * @return std::vector<CardValue> 
     */
    std::vector<CardValue> getCategoryCardValues() const;

private:
    /**
     * @brief Evaluates the current category of this hand
     */
    void determineCategory();

    /**
     * @brief Is this hand a Flush?
     */
    bool isFlush();

    /**
     * @brief Is this hand a Straight?
     */
    bool isStraight();

    /**
     * @brief Is this hand a Four of a Kind?
     */
    bool isFourOfAKind();

    /**
     * @brief Is this hand a Three of a Kind?
     */
    bool isThreeOfAKind();

    /**
     * @brief Is this hand a Two of a Kind?
     */
    bool isTwoOfAKind();

    /**
     * @brief Is this hand a Pair?
     */
    bool isTwoPair();

    /**
     * @brief Is this hand a Full House?
     */
    bool isFullHouse();

    /**
     * @brief Compare this hand to another to see which has the highest value.
     * Initial check is for who has the better category
     * If the categories are a match, then a score is checked.
     * Score is weighted by the high card of a hand.
     * @param v1 
     * @return -1 if this category scores less than v1
     * @return  1 if this category scores higher than v1
     * @return  0 if this category scores equal to v1
     */
    int compareTo(const Hand& v1) const;

    /**
     * @brief Returns an integer representation of this hand
     * Score is composed of the category as well as the high card
     * @return int 
     */
    int getScore() const;

    /**
     * @brief Finds the highest value card of this hand
     * @return CardValue 
     */
    CardValue getHighCardValue() const;
    
    /**
     * @brief Finds the card value repeated the designated number of times
     * @param numberOfRepeats Number of times the card value repeats
     * @return std::vector<CardValue>
     */
    std::vector<CardValue> getRepeatedCardValue(int numberOfRepeats) const;

    static int getTieBreaker(const Hand& h1, const Hand& h2);

    // A vector containing a list of all cards in this hand.
    std::vector<Card> handVector;

    // For each card in this hand, provides a count of the number of cards with that value
    std::map<Card, int> pairCounter;

    // Contains the cards that are not contributing to the category
    std::vector<CardValue> wildCardValues;
    Category category = Category::INCOMPLETE;
};

/**
 * @brief Output stream operator overload
 * Calls the underlying @ref Hand.toString() method
 * @param os 
 * @param hand 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Hand& hand);
#endif