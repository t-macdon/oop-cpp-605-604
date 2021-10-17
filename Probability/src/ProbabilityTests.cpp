/**
 * @file ProbabilityTests.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Unit testing for the Probability class
 * @version 0.1
 * @date 2021-10-04
 */


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <limits>
#include "doctest.h"
#include "IndependentEvent.h"

TEST_CASE("Probability Test Cases")
{
    const double quietNaN = std::numeric_limits<double>::quiet_NaN();
    const double positiveInfinity = std::numeric_limits<double>::infinity();
    const double negativeInfinity = -(positiveInfinity);
    const IndependentEvent a(0.5);
    const IndependentEvent b(0.5);
    const IndependentEvent c(0.25);
    const IndependentEvent d(0.05);
    SUBCASE("Constructor")
    {
        IndependentEvent always(1.0);
        IndependentEvent never(0.0);
        IndependentEvent largeAlways(100.0);
        CHECK(largeAlways.getLikelihood() == 1.0);
        IndependentEvent negativeNever(-100.0);
        CHECK(negativeNever.getLikelihood() == 0.0);
        IndependentEvent nanEvent(quietNaN);
        CHECK(nanEvent.getLikelihood() == 0.0);
        IndependentEvent positiveInfinityEvent(positiveInfinity);
        CHECK(positiveInfinityEvent.getLikelihood() == 1.0);
        IndependentEvent negativeInfinityEvent(negativeInfinity);
        CHECK(negativeInfinityEvent.getLikelihood() == 0.0);
    }

    SUBCASE("And Case")
    {
        IndependentEvent aAndB = a&b;
        IndependentEvent cAndD = c&d;
        CHECK(aAndB.getLikelihood() == 0.25);
        CHECK(cAndD.getLikelihood() == .0125);
    }

    SUBCASE("Or Case")
    {
        IndependentEvent aOrB = a|b;
        IndependentEvent cOrD = c|d;
        CHECK(aOrB.getLikelihood() == 1.0);
        CHECK(cOrD.getLikelihood() == 0.3);
    }

    SUBCASE("Exclusive Or Case")
    {
        IndependentEvent eitherAOrB = a^b;
        CHECK(eitherAOrB.getLikelihood() == 0.75);
    }

    SUBCASE("Exclusive Case")
    {
        IndependentEvent aAndNotB1 = a-b;
        IndependentEvent aAndNotB2 = a&(~b);
        CHECK(aAndNotB1.getLikelihood() == 0.25);
        CHECK(aAndNotB2.getLikelihood() == 0.25);
    }

    SUBCASE("Not Case")
    {
        IndependentEvent notC = ~c;
        IndependentEvent notD = ~d;
        CHECK(notC.getLikelihood() == 0.75);
        CHECK(notD.getLikelihood() == 0.95);
    }

    SUBCASE("Self Referencing")
    {
        IndependentEvent aAndA = a&a;
        IndependentEvent aOrA = a|a;
        IndependentEvent eitherAorA = a^a;
        IndependentEvent aAndNotA = a-a;
        const auto aLikelihood = a.getLikelihood();
        CHECK(aAndA.getLikelihood() == aLikelihood);
        CHECK(aOrA.getLikelihood() == aLikelihood);
        CHECK(eitherAorA.getLikelihood() == 0.0);
        CHECK(aAndNotA.getLikelihood() == 0.0);
    }
}