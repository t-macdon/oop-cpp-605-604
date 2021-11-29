/**
 * @file Passenger.hpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Represents a Passenger. Starts on a Floor, gets picked up by an Elevator, gets dropped off at a Floor.
 * @version 0.1
 * @date 2021-11-28
 */

#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include <sstream>

struct Passenger
{
    /**
     * @brief Construct a new Passenger object
     * 
     * @param startFloorID The ID of the Floor the Passenger starts on
     * @param targetFloorID The ID of the Floor the Passenger should end up on
     */
    Passenger(int startFloorID, int targetFloorID) :
        mStartFloorID(startFloorID), mTargetFloorID(targetFloorID) {};

    /**
     * @brief The ID of the Floor the Passenger starts on
     * 
     */
    int mStartFloorID;

    /**
     * @brief The ID of the Floor the Passenger should end up on
     * 
     */
    int mTargetFloorID;

    /**
     * @brief Running counter of the number of seconds this Passenger spends waiting on its starting Floor
     * 
     */
    int mTimeSpentWaiting = 0;

    /**
     * @brief Running counter of the number of seconds this Passenger spends travelling inside of an Elevator
     * 
     */
    int mTimeSpentTravelling = 0;

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
std::ostream& operator<< (std::ostream &os, const Passenger &s);

#endif // PASSENGER_HPP