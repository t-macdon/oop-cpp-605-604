#include <iostream>
#include <unordered_set>
#include <string>
#include "doctest.h"
#include "Deck.h"

#include "Hand.h"

using namespace std;

TEST_CASE("Initialize Deck") {
    Deck d;
    CHECK_EQ(d.size(), Deck::NUMBER_OF_CARDS_IN_A_FULL_DECK);

    // Make sure we can draw 52 cards out
    int numberOfDrawnCards = 0;
    while (not d.empty()) {
        d.draw();
        numberOfDrawnCards += 1;
        CHECK_EQ(d.size(), Deck::NUMBER_OF_CARDS_IN_A_FULL_DECK - numberOfDrawnCards);
    }

    CHECK_EQ(numberOfDrawnCards, Deck::NUMBER_OF_CARDS_IN_A_FULL_DECK);
}

TEST_CASE("Draw one of each card") {
    unordered_set<string> setOfCards;
    Deck d;

    while (not d.empty()) {
        auto card = d.draw();
        CHECK_EQ(setOfCards.find(card.toString()), setOfCards.end());
        setOfCards.insert(card.toString());
    }
}

TEST_CASE("Shuffle the cards") {
    vector<Card> unshuffledCards;
    vector<Card> cardsShuffledWithSeedA;
    vector<Card> cardsAlsoShuffledWithSeedA;
    vector<Card> cardsShuffledWithSeedB;

    int seedA = 0xDEADBEEF;
    int seedB = 0x1CEB00DA;    

    // Set up our unshuffled vector
    Deck deck;
    while (not deck.empty()) {
        unshuffledCards.push_back(deck.draw());
    }

    // Set up deck 1 with seed A
    Deck deckA1;
    deckA1.shuffle(seedA);
    while (not deckA1.empty()) {
        cardsShuffledWithSeedA.push_back(deckA1.draw());
    }

    // Set up deck 2 with seed A
    Deck deckA2;
    deckA2.shuffle(seedA);
    while (not deckA2.empty()) {
        cardsAlsoShuffledWithSeedA.push_back(deckA2.draw());
    }

    // Set up a deck with seed B
    Deck deckB;
    deckB.shuffle(seedB);
    while (not deckB.empty()) {
        cardsShuffledWithSeedB.push_back(deckB.draw());
    }

    // All draws should've been a full deck.
    // Verify this before checking equality of draws
    CHECK_EQ(unshuffledCards.size(), Deck::NUMBER_OF_CARDS_IN_A_FULL_DECK);
    CHECK_EQ(cardsShuffledWithSeedA.size(), Deck::NUMBER_OF_CARDS_IN_A_FULL_DECK);
    CHECK_EQ(cardsAlsoShuffledWithSeedA.size(), Deck::NUMBER_OF_CARDS_IN_A_FULL_DECK);
    CHECK_EQ(cardsShuffledWithSeedB.size(), Deck::NUMBER_OF_CARDS_IN_A_FULL_DECK);

    // The unshuffled deck should not match any other draws
    CHECK_NE(unshuffledCards, cardsShuffledWithSeedA);
    CHECK_NE(unshuffledCards, cardsAlsoShuffledWithSeedA);
    CHECK_NE(unshuffledCards, cardsShuffledWithSeedB);

    // Using the same seed should give us the same draws
    CHECK_EQ(cardsShuffledWithSeedA, cardsAlsoShuffledWithSeedA);

    // Different seeds should give different draws
    CHECK_NE(cardsShuffledWithSeedA, cardsShuffledWithSeedB);
}

TEST_CASE("Scratch, just checking hands") {
    for (int i = 0; i < 20; i++) {
        Deck d;
        d.shuffle(1024+i);
        Hand hand;
        for(auto card : d.drawMany(5)) {
            hand.addCard(card);
        }
        cout << hand << ": ";
        cout << hand.categoryAsString() << endl;
    }
}