/**
 * @file HandTests.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Unit Tests for the Hand class
 * @version 0.1
 * @date 2021-09-29
 */

#include "doctest.h"
#include "Hand.h"
#include "Card.h"

using namespace std;

TEST_CASE("Hand Test Cases") {
    Card twoOfDiamonds{string("2d")};
    Card twoOfHearts{string("2h")};
    Card threeOfClubs{string("3c")};
    Card threeOfHearts{string("H3")};
    Card threeOfDiamonds{string("3D")};
    Card threeOfSpades{string("3S")};
    Card fourOfHearts{string("4H")};
    Card fourOfClubs{string("4C")};
    Card fiveOfHearts{string("5H")};
    Card sixOfHearts{string("6H")};
    Card sixOfClubs{string("6C")};
    Card eightOfHearts{string("8H")};
    Card queenOfHearts{string("HK")};
    Card kingOfDiamonds{string("KD")};
    Card aceOfSpades{string("a-s")};

    Hand incomplete;
    CHECK(incomplete.addCard(aceOfSpades));
    Hand highCard;
    CHECK(highCard.addCard(twoOfDiamonds));
    CHECK(highCard.addCard(threeOfDiamonds));
    CHECK(highCard.addCard(sixOfClubs));
    CHECK(highCard.addCard(eightOfHearts));
    CHECK(highCard.addCard(kingOfDiamonds));
    Hand twoOfAKind;
    CHECK(twoOfAKind.addCard(threeOfClubs));
    CHECK(twoOfAKind.addCard(threeOfHearts));
    CHECK(twoOfAKind.addCard(kingOfDiamonds));
    CHECK(twoOfAKind.addCard(aceOfSpades));
    CHECK(twoOfAKind.addCard(twoOfDiamonds));
    Hand twoPair;
    CHECK(twoPair.addCard(twoOfDiamonds));
    CHECK(twoPair.addCard(twoOfHearts));
    CHECK(twoPair.addCard(threeOfClubs));
    CHECK(twoPair.addCard(threeOfHearts));
    CHECK(twoPair.addCard(kingOfDiamonds));
    Hand threeOfAKind;
    CHECK(threeOfAKind.addCard(threeOfHearts));
    CHECK(threeOfAKind.addCard(threeOfClubs));
    CHECK(threeOfAKind.addCard(threeOfDiamonds));
    CHECK(threeOfAKind.addCard(aceOfSpades));
    CHECK(threeOfAKind.addCard(kingOfDiamonds));
    Hand straight;
    CHECK(straight.addCard(twoOfDiamonds));
    CHECK(straight.addCard(threeOfHearts));
    CHECK(straight.addCard(fourOfClubs));
    CHECK(straight.addCard(fiveOfHearts));
    CHECK(straight.addCard(sixOfClubs));
    Hand flush;
    CHECK(flush.addCard(twoOfHearts));
    CHECK(flush.addCard(fiveOfHearts));
    CHECK(flush.addCard(eightOfHearts));
    CHECK(flush.addCard(threeOfHearts));
    CHECK(flush.addCard(queenOfHearts));
    Hand fullHouse;
    CHECK(fullHouse.addCard(twoOfDiamonds));
    CHECK(fullHouse.addCard(twoOfHearts));
    CHECK(fullHouse.addCard(threeOfHearts));
    CHECK(fullHouse.addCard(threeOfClubs));
    CHECK(fullHouse.addCard(threeOfDiamonds));
    Hand fourOfAKind;
    CHECK(fourOfAKind.addCard(threeOfHearts));
    CHECK(fourOfAKind.addCard(threeOfSpades));
    CHECK(fourOfAKind.addCard(threeOfClubs));
    CHECK(fourOfAKind.addCard(threeOfDiamonds));
    CHECK(fourOfAKind.addCard(twoOfHearts));
    Hand straightFlush;
    CHECK(straightFlush.addCard(twoOfHearts));
    CHECK(straightFlush.addCard(threeOfHearts));
    CHECK(straightFlush.addCard(fourOfHearts));
    CHECK(straightFlush.addCard(fiveOfHearts));
    CHECK(straightFlush.addCard(sixOfHearts));


    SUBCASE("Incomplete") {
        CHECK(incomplete.getCategory() == Hand::Category::INCOMPLETE);
    }
    SUBCASE("High Card") {
        CHECK(highCard.getCategory() == Hand::Category::HIGH_CARD);
    }
    SUBCASE("Two Of A Kind") {
        CHECK(twoOfAKind.getCategory() == Hand::Category::TWO_OF_A_KIND);
    }
    SUBCASE("Two Pair") {
        CHECK(twoPair.getCategory() == Hand::Category::TWO_PAIR);
    }
    SUBCASE("Three Of A Kind") {
        CHECK(threeOfAKind.getCategory() == Hand::Category::THREE_OF_A_KIND);
    }
    SUBCASE("Straight") {
        CHECK(straight.getCategory() == Hand::Category::STRAIGHT);
    }
    SUBCASE("Flush") {
        CHECK(flush.getCategory() == Hand::Category::FLUSH);
    }
    SUBCASE("Full House") {
        CHECK(fullHouse.getCategory() == Hand::Category::FULL_HOUSE);
    }
    SUBCASE("Four of a Kind") {
        CHECK(fourOfAKind.getCategory() == Hand::Category::FOUR_OF_A_KIND);
    }
    SUBCASE("Straight Flush" ) {
        CHECK(straightFlush.getCategory() == Hand::Category::STRAIGHT_FLUSH);
    }

}
