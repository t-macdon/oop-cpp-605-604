/**
 * @file Deck.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Interface for the Deck class
 * @version 0.1
 * @date 2021-12-02
 */

#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include "Card.h"

/**
 * @brief Tracks the state of a standard 52-card deck
 * 
 */
class Deck {

    public:
        static constexpr int NUMBER_OF_CARDS_IN_A_FULL_DECK = 52;

        /**
         * @brief Construct a new Deck object. 
         * The deck starts off in order, so shuffle it.
         */
        Deck();

        /**
         * @brief Construct a new  Deck object from supplied cards
         * @param cards 
         */
        Deck::Deck(std::vector<Card> cards);
        /**
         * @brief Shuffle the deck using the Fisher-Yates method
         * 
         * @param seed Seed to use for shuffle
         */
        void shuffle(int seed);

        /**
         * @brief Draw a card from the deck (removes from the deck)
         * 
         * Will throw a runtime_error if the deck is empty
         * 
         * @return Card 
         */
        Card draw();

        /**
         * @brief Draw a number of cards from the deck
         * 
         * @param numCards 
         * @return std::vector 
         */
        std::vector<Card> drawMany(int numCards);

        /**
         * @brief Check how many cards are in this deck
         * 
         * @return int 
         */
        inline int size() const { return cards.size(); }

        /**
         * @brief Check if this deck is empty
         * 
         * @return bool
         */
        inline bool empty() const { return size() == 0; }

    private:
        std::vector<Card> cards;
};

#endif // DECK_H_