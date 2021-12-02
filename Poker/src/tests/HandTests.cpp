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

    SUBCASE("Straight Flush Category Based Comparison") {
        CHECK(straightFlush > fourOfAKind);
        CHECK(straightFlush > fullHouse);
        CHECK(straightFlush > flush);
        CHECK(straightFlush > straight);
        CHECK(straightFlush > threeOfAKind);
        CHECK(straightFlush > twoPair);
        CHECK(straightFlush > twoOfAKind);
        CHECK(straightFlush > highCard);
    }

    SUBCASE("Four of a Kind Category Based Comparison") {
        CHECK(fourOfAKind < straightFlush);
        CHECK(fourOfAKind > fullHouse);
        CHECK(fourOfAKind > flush);
        CHECK(fourOfAKind > straight);
        CHECK(fourOfAKind > threeOfAKind);
        CHECK(fourOfAKind > twoPair);
        CHECK(fourOfAKind > twoOfAKind);
        CHECK(fourOfAKind > highCard);
    }

    SUBCASE("Full House Category Based Comparison") {
        CHECK(fullHouse < straightFlush);
        CHECK(fullHouse < fourOfAKind);
        CHECK(fullHouse > flush);
        CHECK(fullHouse > straight);
        CHECK(fullHouse > threeOfAKind);
        CHECK(fullHouse > twoPair);
        CHECK(fullHouse > twoOfAKind);
        CHECK(fullHouse > highCard);
    }

    SUBCASE("Flush Category Based Comparison") {
        CHECK(flush < straightFlush);
        CHECK(flush < fourOfAKind);
        CHECK(flush < fullHouse);
        CHECK(flush > straight);
        CHECK(flush > threeOfAKind);
        CHECK(flush > twoPair);
        CHECK(flush > twoOfAKind);
        CHECK(flush > highCard);
    }

    SUBCASE("Straight Category Based Comparison") {
        CHECK(straight < straightFlush);
        CHECK(straight < fourOfAKind);
        CHECK(straight < fullHouse);
        CHECK(straight < flush);
        CHECK(straight > threeOfAKind);
        CHECK(straight > twoPair);
        CHECK(straight > twoOfAKind);
        CHECK(straight > highCard);
        
    }

    SUBCASE("Three of a Kind Category Based Comparison") {
        CHECK(threeOfAKind < straightFlush);
        CHECK(threeOfAKind < fourOfAKind);
        CHECK(threeOfAKind < fullHouse);
        CHECK(threeOfAKind < flush);
        CHECK(threeOfAKind < straight);
        CHECK(threeOfAKind > twoPair);
        CHECK(threeOfAKind > twoOfAKind);
        CHECK(threeOfAKind > highCard);
        
    }

    SUBCASE("Two Pair Category Based Comparison") {
        
        CHECK(twoPair < straightFlush);
        CHECK(twoPair < fourOfAKind);
        CHECK(twoPair < fullHouse);
        CHECK(twoPair < flush);
        CHECK(twoPair < straight);
        CHECK(twoPair < threeOfAKind);
        CHECK(twoPair > twoOfAKind);
        CHECK(twoPair > highCard);
    }

    SUBCASE("Two of a Kind Category Based Comparison") {
        CHECK(twoOfAKind < straightFlush);
        CHECK(twoOfAKind < fourOfAKind);
        CHECK(twoOfAKind < fullHouse);
        CHECK(twoOfAKind < flush);
        CHECK(twoOfAKind < straight);
        CHECK(twoOfAKind < threeOfAKind);
        CHECK(twoOfAKind < twoPair);
        CHECK(twoOfAKind > highCard);
    }

    SUBCASE("High Card Category Based Comparison") {
        CHECK(highCard < straightFlush);
        CHECK(highCard < fourOfAKind);
        CHECK(highCard < fullHouse);
        CHECK(highCard < flush);
        CHECK(highCard < straight);
        CHECK(highCard < threeOfAKind);
        CHECK(highCard < twoPair);
        CHECK(highCard < twoOfAKind);
    }

    SUBCASE("Straight Flush Card Comparison") {
        // [4H, 5H, 6H, 7H, 8H] > [3C, 4C, 5C, 6C, 7C]
        Hand straightFlushA;
        straightFlushA.addCard(Card("4H"));
        straightFlushA.addCard(Card("5H"));
        straightFlushA.addCard(Card("6H"));
        straightFlushA.addCard(Card("7H"));
        straightFlushA.addCard(Card("8H"));
        Hand straightFlushB;
        straightFlushB.addCard(Card("3C"));
        straightFlushB.addCard(Card("4C"));
        straightFlushB.addCard(Card("5C"));
        straightFlushB.addCard(Card("6C"));
        straightFlushB.addCard(Card("7C"));
        CHECK(straightFlushA > straightFlushB); 
    }

    SUBCASE("Four of a Kind Card Comparison") {
        // [4H, 4H, 4H, 4H, 7H] > [3C, 3C, 3C, 3C, 7C]
        Hand fourOfAKindA;
        fourOfAKindA.addCard(Card("4H"));
        fourOfAKindA.addCard(Card("4H"));
        fourOfAKindA.addCard(Card("4H"));
        fourOfAKindA.addCard(Card("4H"));
        fourOfAKindA.addCard(Card("2H"));
        Hand fourOfAKindB;
        fourOfAKindB.addCard(Card("3C"));
        fourOfAKindB.addCard(Card("3C"));
        fourOfAKindB.addCard(Card("3C"));
        fourOfAKindB.addCard(Card("3C"));
        fourOfAKindB.addCard(Card("2C"));
        CHECK(fourOfAKindA > fourOfAKindB); 
    }

    SUBCASE("Full House Card Comparison") {
        // 2 cases: one where the 3-cards determine the outcome
        //          another one where the 2-cards determine the outcome

        // check 1
        // [5H, 5S, 5C, 7D, 7C] > [4H, 4S, 4C, 6D, 6C]
        Hand fullHouseA;
        fullHouseA.addCard(Card("5H"));
        fullHouseA.addCard(Card("5S"));
        fullHouseA.addCard(Card("5C"));
        fullHouseA.addCard(Card("6D"));
        fullHouseA.addCard(Card("6C"));
        Hand fullHouseB;
        fullHouseB.addCard(Card("4H"));
        fullHouseB.addCard(Card("4S"));
        fullHouseB.addCard(Card("4C"));
        fullHouseB.addCard(Card("7D"));
        fullHouseB.addCard(Card("7C"));
        CHECK(fullHouseA > fullHouseB); 

        // check 2
        // [5H, 5S, 5C, 7D, 7C] > [5H, 5S, 5C, 6D, 6C]
        Hand fullHouseC;
        fullHouseC.addCard(Card("5H"));
        fullHouseC.addCard(Card("5S"));
        fullHouseC.addCard(Card("5C"));
        fullHouseC.addCard(Card("7D"));
        fullHouseC.addCard(Card("7C"));
        Hand fullHouseD;
        fullHouseD.addCard(Card("5H"));
        fullHouseD.addCard(Card("5S"));
        fullHouseD.addCard(Card("5C"));
        fullHouseD.addCard(Card("6D"));
        fullHouseD.addCard(Card("6C"));
        CHECK(fullHouseC > fullHouseD); 
    }

    SUBCASE("Flush Card Comparison") {
        // [4H, 3H, 6H, 7H, KH] > [3C, 4C, 9C, 6C, 7C]
        Hand flushA;
        flushA.addCard(Card("4H"));
        flushA.addCard(Card("3H"));
        flushA.addCard(Card("6H"));
        flushA.addCard(Card("7H"));
        flushA.addCard(Card("KH"));
        Hand flushB;
        flushB.addCard(Card("3C"));
        flushB.addCard(Card("4C"));
        flushB.addCard(Card("9C"));
        flushB.addCard(Card("6C"));
        flushB.addCard(Card("7C"));
        CHECK(flushA > flushB);    
    }

    SUBCASE("Straight Card Comparison") {
        // [4H, 5C, 6H, 7H, 8H] > [3C, 4C, 5S, 6C, 7C]
        Hand straightA;
        straightA.addCard(Card("4H"));
        straightA.addCard(Card("5C"));
        straightA.addCard(Card("6H"));
        straightA.addCard(Card("7H"));
        straightA.addCard(Card("8H"));
        Hand straightB;
        straightB.addCard(Card("3C"));
        straightB.addCard(Card("4C"));
        straightB.addCard(Card("5S"));
        straightB.addCard(Card("6C"));
        straightB.addCard(Card("7C"));
        CHECK(straightA > straightB); 
    }

    SUBCASE("Three of a Kind Card Comparison") {
        // [4H, 4C, 4H, 6H, 7H] > [3C, 3C, 3S, 5C, 7C]
        Hand threeOfAKindA;
        threeOfAKindA.addCard(Card("4H"));
        threeOfAKindA.addCard(Card("4C"));
        threeOfAKindA.addCard(Card("4H"));
        threeOfAKindA.addCard(Card("6H"));
        threeOfAKindA.addCard(Card("7H"));
        Hand threeOfAKindB;
        threeOfAKindB.addCard(Card("3C"));
        threeOfAKindB.addCard(Card("3C"));
        threeOfAKindB.addCard(Card("3S"));
        threeOfAKindB.addCard(Card("5C"));
        threeOfAKindB.addCard(Card("7C"));
        CHECK(threeOfAKindA > threeOfAKindB); 
    }

    SUBCASE("Two Pair Card Comparison") {
        // [4H, 4C, 5H, 5H, 7H] > [3C, 3C, 4S, 4C, 7C]
        Hand twoPairA;
        twoPairA.addCard(Card("4H"));
        twoPairA.addCard(Card("4C"));
        twoPairA.addCard(Card("5H"));
        twoPairA.addCard(Card("5H"));
        twoPairA.addCard(Card("7H"));
        Hand twoPairB;
        twoPairB.addCard(Card("3C"));
        twoPairB.addCard(Card("3C"));
        twoPairB.addCard(Card("4S"));
        twoPairB.addCard(Card("4C"));
        twoPairB.addCard(Card("7C"));
        CHECK(twoPairA > twoPairB); 
    }

    SUBCASE("Two of a Kind Card Comparison") {
        // [4H, 4C, 5H, 6H, 7H] > [3C, 3C, 4S, 5C, 7C]
        Hand twoOfAKindA;
        twoOfAKindA.addCard(Card("4H"));
        twoOfAKindA.addCard(Card("4C"));
        twoOfAKindA.addCard(Card("5H"));
        twoOfAKindA.addCard(Card("6H"));
        twoOfAKindA.addCard(Card("7H"));
        Hand twoOfAKindB;
        twoOfAKindB.addCard(Card("3C"));
        twoOfAKindB.addCard(Card("3C"));
        twoOfAKindB.addCard(Card("4S"));
        twoOfAKindB.addCard(Card("5C"));
        twoOfAKindB.addCard(Card("7C"));
        CHECK(twoOfAKindA > twoOfAKindB); 
    }

    SUBCASE("High Card Comparison") {
        // [2S, 5S, 7S, 9S, 10S] > [AD, 3D, 5D, 7D, 8D]
        Hand highCardA;
        highCardA.addCard(Card("2S"));
        highCardA.addCard(Card("5S"));
        highCardA.addCard(Card("7S"));
        highCardA.addCard(Card("9S"));
        highCardA.addCard(Card("10S"));
        Hand highCardB;
        highCardB.addCard(Card("AD"));
        highCardB.addCard(Card("3D"));
        highCardB.addCard(Card("5D"));
        highCardB.addCard(Card("7D"));
        highCardB.addCard(Card("8D"));
        CHECK(highCardA > highCardB); 
    }
}
