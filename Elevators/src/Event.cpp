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
