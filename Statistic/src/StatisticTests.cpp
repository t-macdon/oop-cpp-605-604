/**
 * @file StatisticTests.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Unit tests for the Statistic class
 * @version 0.1
 * @date 2021-09-09
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <numeric>
#include <cmath>
#include "doctest.h"
#include "Statistic.h"

using namespace std;

/**
 * @brief Calculate the mean of a vector input
 * @param input test vector to find the mean of
 * @return double 
 */
double calculateMean(const vector<double>& input) {
    double sum = accumulate(input.begin(), input.end(), 0.0);
    return sum/input.size();
}

/**
 * @brief Calculate the standard deviation of a vector input
 * @param input test vector to find the sample standard deviation of
 * @return double 
 */
double calculateStandardDeviation(const vector<double>& input) {
    double mean = calculateMean(input);
    double accumulator = 0.0;
    for(double i : input) {
        accumulator += pow(i-mean, 2);
    }
    return sqrt(accumulator/(input.size()-1));
}

/**
 * @brief Verify that the Statistic class matches expected behavior
 * 
 * Given a vector of values, verify that the mean and standard deviation
 * calculated from the Statistic class matches the results found with
 * our local test functions
 * 
 * @param numbers Vector of numbers to compare results of
 */
void verifyStatisticsMatch(const vector<double>& numbers) {
    double mean = calculateMean(numbers);
    double standardDeviation = calculateStandardDeviation(numbers);

    Statistic stat;
    for(double i : numbers) {
        stat.add(i);
    }
    
    CHECK(stat.getAverage() == doctest::Approx(mean));
    CHECK(stat.getSTD() == doctest::Approx(standardDeviation));
    CHECK_FALSE(isnan(stat.getSTD()));
    CHECK_FALSE(isnan(stat.getAverage()));
}

TEST_CASE("Edge Conditions") {
    Statistic stat;
    const double testNumber = 43.12;

    SUBCASE("Statistics of no values is NaN") {
        // Verify that the Statistic class starts off with NaN
        CHECK(std::isnan(stat.getAverage()));
        CHECK(std::isnan(stat.getSTD()));
    }

    SUBCASE("Statistics of one value") {
        stat.add(testNumber);
        // The average of a single number should be that number.
        // However, there is no deviation for a single number. It should be NaN.
        CHECK(stat.getAverage() == testNumber);
        CHECK(isnan(stat.getSTD()));

    }
}

TEST_CASE("Same number repeatedly") {
    Statistic stat;
    const double onlyNumber = 10;

    stat.add(onlyNumber);

    // Continuosly add the same number to this list
    for(int i=0; i<10; i++) {
        stat.add(onlyNumber);
        CHECK(stat.getAverage() == onlyNumber);
        // The standard deviation of a set of 1 number should be 0.
        // They don't deviate.
        CHECK(stat.getSTD() == 0);
    }
}

TEST_CASE("Statistics of positive numbers") {
    const vector<double> numbers {
        50.12, 12221.32, 12221.3443, 40001.211,
        9421.11119200, 9994410002.321, 9.0, 10,
        491, 80, 32, 49.91, 48, 389.41, 12.345
    };
    verifyStatisticsMatch(numbers);
}

TEST_CASE("Statistics of negative numbers") {
    const vector<double> numbers {
        -31, -543.02234, -234522.2405,
        -4229.222203, -0.00345, -0.00006,
        -900234, -9223415, -10, -5001.2304,
        -340052.200, -6012.42, -19230.43
    };
    verifyStatisticsMatch(numbers);
}

TEST_CASE("Statistics of mixed sign numbers") {
    const vector<double> numbers {
        -31, -543.02234, -234522.2405,
        50.12, 12221.32, 12221.3443, 40001.211,
        -900234, -9223415, -10, -5001.2304,
        491, 80, 32, 49.91, 48, 389.41, 12.345
    };
    verifyStatisticsMatch(numbers);
}

TEST_CASE("Statistics of Tyler MacDonald's discussion numbers") {
    const vector<double> numbers {
        72, 72, 79, 79, 81, 81, 79, 77, 77,
        76, 76, 74, 74, 72, 79, 79, 77, 77,
        76, 76, 74, 79, 79, 77, 77, 76, 76,
        74, 72, 72, 79, 79, 81, 81, 79, 77,
        77, 76, 76, 74, 74, 24
    };
    verifyStatisticsMatch(numbers);
}

TEST_CASE("Statistics of Michael Schumacher's discussion numbers") {
    const vector<double> numbers {
        12, 21, 1, 33, 1, 111221111, 12 , 20000,
        112, 21110, 111111, 10, 21101110, 12, 
        100000, 11100000,
    };
    verifyStatisticsMatch(numbers);
}

TEST_CASE("Statistics of all zeros") {
    const vector<double> numbers {
        0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    verifyStatisticsMatch(numbers);
}