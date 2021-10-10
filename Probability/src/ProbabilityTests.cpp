/**
 * @file ProbabilityTests.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Unit testing for the Probability class
 * @version 0.1
 * @date 2021-10-04
 */


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "IndependentEvent.h"

TEST_CASE("Probability Test Cases")
{
    SUBCASE("Constructor")
    {
        IndependentEvent always(1.0);
        IndependentEvent never(0.0);
        IndependentEvent largeAlways(100.0);
        CHECK(largeAlways.getLikelihood() == 1.0);
        IndependentEvent negativeNever(-100.0);
        CHECK(negativeNever.getLikelihood() == 0.0);
    }

    SUBCASE("A and B")
    {
        IndependentEvent a(0.5);
        IndependentEvent b(0.5);
        IndependentEvent aAndB = a&b;
        CHECK(aAndB.getLikelihood() == 0.25);
    }

    SUBCASE("A or B")
    {
        IndependentEvent a(0.5);
        IndependentEvent b(0.5);
        IndependentEvent aOrB = a|b;
        CHECK(aOrB.getLikelihood() == 1.0);
    }

    SUBCASE("Either A or B but not both")
    {
        IndependentEvent a(0.5);
        IndependentEvent b(0.5);
        IndependentEvent eitherAOrB = a^b;
        CHECK(eitherAOrB.getLikelihood() == 0.75);
    }

    SUBCASE("A and not B")
    {
        IndependentEvent a(0.5);
        IndependentEvent b(0.5);
        IndependentEvent aAndNotB = a&(~b);
        CHECK(aAndNotB.getLikelihood() == 0.25);
    }

    SUBCASE("Not A")
    {
        IndependentEvent a(0.23);
        IndependentEvent notA = ~a;
        CHECK(notA.getLikelihood() == 0.77);
    }
}