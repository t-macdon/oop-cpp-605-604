#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <queue>

#include "Event.hpp"

class Utilities
{
public:
    static const char CSV_DELIMETER = ',';
    static std::queue<Event> loadEventsFromCSV(const std::string &CSVPath);
};

#endif // UTILITIES_HPP