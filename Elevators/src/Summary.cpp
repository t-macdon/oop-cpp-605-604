/**
 * @file Summary.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation file for the Summary class
 * @version 0.1
 * @date 2021-11-28
 */

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
