/*
 * Triangle.h
 *
 *  Created on: Sep 1, 2021
 *      Author: Michael Schumacher && Tyler MacDonald
 */

#ifndef STATISTIC_H
#define STATISTIC_H

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
    double average() const;

    /**
     * @return The standard deviation
     */
    double STD() const;

};

#endif