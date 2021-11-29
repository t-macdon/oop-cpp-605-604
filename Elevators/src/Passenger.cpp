/**
 * @file Passenger.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation file for the Passenger class
 * @version 0.1
 * @date 2021-11-28
 */

#include "Passenger.hpp"

std::string Passenger::toString() const {
    std::stringstream ss;
    ss << "[startFloorID=" << mStartFloorID;
    ss << ", targetFloorID=" << mTargetFloorID;
    ss << ", timeSpentWaiting=" << mTimeSpentWaiting;
    ss << ", timeSpentTravelling=" << mTimeSpentTravelling;
    ss << "]";
    return ss.str();
}

std::ostream& operator<< (std::ostream &os, const Passenger &s) {
    return (os << s.toString());
}
