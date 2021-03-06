/*
 * Statistic.cpp
 *
 *  Created on: Sep 9, 2021
 *      Author: Michael Schumacher && Tyler MacDonald
 */

#include <cmath>

#include "Statistic.h"

using namespace std;

Statistic::Statistic()
    : runningSum(0), runningSumOfSquares(0), numberOfElements(0),
        average(NAN), STD(NAN)
{
}

void Statistic::add(double x)
{
    this->numberOfElements++;
    this->runningSum += x;
    this->runningSumOfSquares += pow(x, 2);
    this->updateAverage();
    this->updateSTD();
}

double Statistic::getAverage() const
{
    return this->average;
}

double Statistic::getSTD() const
{
    return this->STD;
}

void Statistic::updateAverage() 
{
    this->average = this->runningSum / this->numberOfElements;
}

void Statistic::updateSTD()
{
    this->STD = sqrt(
        (this->runningSumOfSquares - (this->runningSum * this->runningSum / this->numberOfElements)) / 
        (this->numberOfElements - 1)
    );
}