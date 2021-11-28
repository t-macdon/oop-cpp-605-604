#ifndef SUMMARY_HPP
#define SUMMARY_HPP

#include <sstream>

struct Summary
{
    Summary(float averageTimeSpentWaiting, float averageTimeSpentTravelling, int totalSimulationTime) : 
        mAverageTimeSpentWaiting(averageTimeSpentWaiting), mAverageTimeSpentTravelling(averageTimeSpentTravelling),
        mTotalSimulationTime(totalSimulationTime) {};
    const float mAverageTimeSpentWaiting;
    const float mAverageTimeSpentTravelling;
    const int mTotalSimulationTime;

    std::string toString() const;
};
    
std::ostream& operator<< (std::ostream &os, const Summary &s);

#endif // SUMMARY_HPP