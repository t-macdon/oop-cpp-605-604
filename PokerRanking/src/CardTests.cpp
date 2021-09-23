/**
 * @file CardTests.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Unit testing for the card class
 * @version 0.1
 * @date 2021-09-23
 */

#include <string>
#include "doctest.h"
#include "Card.h"
#include "CardValue.h"

using namespace std;

TEST_CASE("Card Test Cases") {
    Card twoOfHearts{string("2h")};
    Card threeOfClubs{string("3c")};
    Card threeOfHearts{string("H3")};
    Card kingOfDiamonds{string("KD")};
    Card aceOfSpades{string("a-s")};
    CHECK(twoOfHearts.getSuit() == Card::Suit::HEART);
    CHECK(twoOfHearts.getValue() == CardValue::Value::TWO);
    CHECK(threeOfHearts.getSuit() == Card::Suit::HEART);
    CHECK(threeOfHearts.getValue() == CardValue::Value::THREE);
    CHECK(threeOfClubs.getSuit() == Card::Suit::CLUB);
    CHECK(threeOfClubs.getValue() == CardValue::Value::THREE);
    CHECK(kingOfDiamonds.getSuit() == Card::Suit::DIAMOND);
    CHECK(kingOfDiamonds.getValue() == CardValue::Value::KING);
    CHECK(aceOfSpades.getSuit() == Card::Suit::SPADE);
    CHECK(aceOfSpades.getValue() == CardValue::Value::ACE);

    SUBCASE("Check equality of cards") {
        // We say cards are equal if the values are equal.
        // Is that accurate?
        CHECK(threeOfClubs == threeOfClubs);
        CHECK(threeOfClubs == threeOfHearts);
        CHECK(aceOfSpades != threeOfHearts);
        CHECK(!(aceOfSpades == threeOfClubs));
        CHECK(kingOfDiamonds != aceOfSpades);
        CHECK(kingOfDiamonds == kingOfDiamonds);
    }

    SUBCASE("Check distance of cards") {
        CHECK(threeOfClubs - threeOfClubs == 0);
        CHECK(kingOfDiamonds - threeOfClubs == 10);
        CHECK(threeOfClubs - threeOfHearts == 0);
        CHECK(twoOfHearts - threeOfHearts == 1);
        // Low Ace
        CHECK(aceOfSpades - threeOfClubs == 2);
        // High Ace
        CHECK(aceOfSpades - kingOfDiamonds == 1);
    }
}