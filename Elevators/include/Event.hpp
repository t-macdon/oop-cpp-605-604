/**
 * @file Event.hpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief A collection of data representing a Passenger arriving on a floor
 * @version 0.1
 * @date 2021-11-28
 */

#ifndef EVENT_HPP
#define EVENT_HPP

#include <sstream>

struct Event
{
    /**
     * @brief Construct a new Event object
     * 
     * @param startTime The simulation time when a Passenger should show up on a Floor
     * @param startFloor The Floor the Passenger should start on
     * @param endFloor The Floor the Passenger should end up on
     */
    Event(int startTime, int startFloor, int endFloor) :
        mStartTime(startTime), mStartFloor(startFloor), mEndFloor(endFloor) {};

    /**
     * @brief The simulation time when a Passenger should show up on a Floor
     * 
     */
    int mStartTime;

    /**
     * @brief The Floor the Passenger should start on
     * 
     */
    int mStartFloor;

    /**
     * @brief The Floor the Passenger should end up on
     * 
     */
    int mEndFloor;

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
std::ostream& operator<< (std::ostream &os, const Event &s);

#endif // EVENT_HPP