/*
 * main.cpp
 *
 *  Created on: Sep 9, 2021
 *      Author: Michael Schumacher && Tyler MacDonald
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Statistic.h"

using namespace std;

TEST_CASE("Same number repeatedly") {
    Statistic stat;
    static const double onlyNumber = 10;

    CHECK(stat.getAverage() == 0);
    // TODO: Average of an empty set is 0... Is that what we want?
    // Or should either/both of these tests start as NaN?
    CHECK(stat.getSTD() == 0);

    stat.add(onlyNumber);

    CHECK(stat.getAverage() == onlyNumber);
    // Here we say a single number's std is NaN... See above comment.
    CHECK(std::isnan(stat.getSTD()));

    // Continuosly add the same number to this list
    for(int i=0; i<10; i++) {
        stat.add(onlyNumber);
        CHECK(stat.getAverage() == onlyNumber);
        // The standard deviation of a set of 1 number should be 0.
        // They don't deviate.
        CHECK(stat.getSTD() == 0);
    }
}