/**
 * @file Statistic.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Header file for the Statistic class
 * @version 0.1
 * @date 2021-09-15
 */

#ifndef STATISTIC_H
#define STATISTIC_H

/**
 * @brief The Statistic class keeps track of general stats of lists
 * 
 */
class Statistic {
public:

    /**
     * @brief Constructor
     * @return A Statistic object
     */
    Statistic();

    /**
     * @brief Add an item to the statistics
     * @param x A double value to add to the statistics
     */
    void add(double x);

    /**
     * @return The running average
     */
    double getAverage() const;

    /**
     * @return The standard deviation
     */
    double getSTD() const;

private:

    /**
     * @brief Sum of all elements added to this instance
     */
    double runningSum;

    /**
     * @brief Sum of all elements squared and the added to this instance
     */
    double runningSumOfSquares;

    /**
     * @brief The number of elements added to this instance
     */
    double numberOfElements;

    /**
     * @brief The average of all elements added to this instance
     */
    double average;

    /**
     * @brief The standard deviation of all elements added to this instance
     */
    double STD;

    /**
     * @brief Updates the average by dividing runningSum by numberOfElements
     */
    void updateAverage();

    /**
     * @brief Updates the standard deviation
     */
    void updateSTD();
};

#endif