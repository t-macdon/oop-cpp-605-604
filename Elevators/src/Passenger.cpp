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
