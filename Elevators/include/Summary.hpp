/**
 * @file Summary.hpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Values returned by the Simulation representative of the simulation results
 * @version 0.1
 * @date 2021-11-28
 */

#ifndef SUMMARY_HPP
#define SUMMARY_HPP

#include <sstream>

struct Summary
{
    /**
     * @brief Construct a new Summary object
     * 
     * @param averageTimeSpentWaiting The average time in seconds that Passengers spent waiting on Floors during the simulation
     * @param averageTimeSpentTravelling The average time in seconds that Passengers spent travelling in Elevators during the simulation
     * @param totalSimulationTime The total time in seconds the simulation ran from start to finish
     */
    Summary(float averageTimeSpentWaiting, float averageTimeSpentTravelling, int totalSimulationTime) : 
        mAverageTimeSpentWaiting(averageTimeSpentWaiting), mAverageTimeSpentTravelling(averageTimeSpentTravelling),
        mTotalSimulationTime(totalSimulationTime) {};

    /**
     * @brief The average time in seconds that Passengers spent waiting on Floors during the simulation
     * 
     */
    const float mAverageTimeSpentWaiting;

    /**
     * @brief The average time in seconds that Passengers spent travelling in Elevators during the simulation
     * 
     */
    const float mAverageTimeSpentTravelling;

    /**
     * @brief The total time in seconds the simulation ran from start to finish
     * 
     */
    const int mTotalSimulationTime;

    /**
     * @brief Returns a String representation of this object
     * 
     * @return std::string 
     */
    std::string toString() const;
};
    
/**
 * @brief Allows for printing this object to a stream
 * 
 * @param os 
 * @param s 
 * @return std::ostream& 
 */
std::ostream& operator<< (std::ostream &os, const Summary &s);

#endif // SUMMARY_HPP