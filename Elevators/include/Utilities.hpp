/**
 * @file Utilities.hpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Class containing static methods that don't belong in a particular class
 * @version 0.1
 * @date 2021-11-28
 */

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <queue>

#include "Event.hpp"

class Utilities
{
public:

    /**
     * @brief Represents the expected character delimeter to be used in CSV files
     * 
     */
    static const char CSV_DELIMETER = ',';

    /**
     * @brief Parses a CSV file into Event objects and creates a Queue
     * 
     * @param CSVPath String absolute path to the CSV file to parse
     * @return std::queue<Event> An ordered queue of events parsed from the CSV file
     */
    static std::queue<Event> loadEventsFromCSV(const std::string &CSVPath);
};

#endif // UTILITIES_HPP