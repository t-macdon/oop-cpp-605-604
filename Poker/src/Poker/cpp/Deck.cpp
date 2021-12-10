#include <vector>
#include <exception>
#include <random>

#include "Deck.h"
#include "Card.h"
#include "CardValue.h"

using namespace std;

Deck::Deck()
{
    // Reserve enough space in the vector for a full deck upfront
    cards.reserve(NUMBER_OF_CARDS_IN_A_FULL_DECK);

    // Put all combinations of suit/value cards in to the deck.
    // This will create an ordered deck
    for(auto suit : Card::ALL_SUITS) {
        for(auto value: CardValue::ALL_VALUES) {
            Card c{value, suit};
            cards.push_back(c);
        }
    }
}

Deck::Deck(vector<Card> cards) :
cards{cards}
{
}

Card Deck::draw() {
    if (empty()) {
        throw runtime_error("Attempted to draw from an empty deck");
    }
    // Make a copy of the card at the end of our vector
    Card drawnCard{cards.back()};
    // Remove this last card from the vector
    cards.pop_back();
    // Return the cached copy
    return drawnCard;
};

vector<Card> Deck::drawMany(int numCards) {
    vector<Card> drawnCards;
    for(;numCards > 0; numCards--) {
        drawnCards.push_back(draw());
    }
    return drawnCards;
}

void Deck::shuffle(int seed) {
    default_random_engine engine{seed};
    // Fisher-Yates algorithm
    for(int i = 0; i < size()-2; i++) {
        uniform_int_distribution<int> distribution{i, size()-1};
        int j = distribution(engine);
        swap(cards[i], cards[j]);
    }
}