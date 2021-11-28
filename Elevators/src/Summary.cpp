#include "Summary.hpp"

std::string Summary::toString() const {
    std::stringstream ss;
    ss << "[mAverageTimeSpentWaiting=" << mAverageTimeSpentWaiting;
    ss << ", mAverageTimeSpentTravelling=" << mAverageTimeSpentTravelling;
    ss << ", mTotalSimulationTime=" << mTotalSimulationTime;
    ss << "]";
    return ss.str();
}

std::ostream& operator<< (std::ostream &os, const Summary &s) {
    return (os << s.toString());
}
