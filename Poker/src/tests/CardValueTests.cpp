/**
 * @file CardValueTests.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Unit testing for the card value class
 * @version 0.1
 * @date 2021-09-23
 */

#include <string>
#include "CardValue.h"
#include "doctest.h"

using namespace std;

TEST_CASE("CardValue Test Cases") {
    CardValue ace1{string("a")};
    CardValue ace2{string("Ah")};
    CardValue three{string("3")};
    CardValue eight{string("8")};
    CardValue ten{string("1")};
    CardValue ten2{string("0")};
    CardValue ten3{string("T")};

    SUBCASE("Check construction of card value objects") {
        CHECK(ace1.getValue() == CardValue::ACE);
        CHECK(ace2.getValue() == CardValue::ACE);
        CHECK(three.getValue() == CardValue::THREE);
        CHECK(eight.getValue() == CardValue::EIGHT);
        CHECK(ten.getValue() == CardValue::TEN);
    }

    SUBCASE("Check equality of card value objects") {
        CHECK(ace1 == ace2);
        CHECK(!(ace1 != ace2));
        CHECK(ace1 != ten);
        CHECK(eight != ten);
        CHECK(eight == eight);
        CHECK(!(ten != ten));
    }

    SUBCASE("Check distance of cards") {
        CHECK(ten - eight == 2);
        CHECK(eight - ten == 2);
        CHECK(ten - ten == 0);
        CHECK(ace1 - ace2 == 0);
        CHECK(three - eight == 5);

        // High Ace mode
        CHECK(ace1 - ten == 4);

        // Low Ace mode
        CHECK(three - ace2 == 2);
    }
}
