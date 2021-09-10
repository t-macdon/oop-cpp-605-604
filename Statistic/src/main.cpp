/*
 * main.cpp
 *
 *  Created on: Sep 9, 2021
 *      Author: Michael Schumacher && Tyler MacDonald
 */

#include <iostream>

#include "Statistic.h"

using namespace std;

int main()
{
    cout << "Starting!" << endl;

    // create statistic object
    Statistic statistic;

    // add some values
    statistic.add(2.354);
    statistic.add(4.764);
    statistic.add(6.1967);

    // print stats
    cout << "Average: " << statistic.getAverage() << endl;
    cout << "Standard Deviation: " << statistic.getSTD() << endl;

    cout << "Ending!" << endl;
}