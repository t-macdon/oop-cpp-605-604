/**
 * @file Event.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation file for the Event class
 * @version 0.1
 * @date 2021-11-28
 */

#include "Event.hpp"

std::string Event::toString() const {
    std::stringstream ss;
    ss << "[mStartTime=" << mStartTime;
    ss << ", mStartFloor=" << mStartFloor;
    ss << ", mEndFloor=" << mEndFloor;
    ss << "]";
    return ss.str();
}

std::ostream& operator<< (std::ostream &os, const Event &s) {
    return (os << s.toString());
}
