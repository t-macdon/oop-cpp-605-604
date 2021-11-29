/**
 * @file Floor.hpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Represents a Floor in the simulation
 * @version 0.1
 * @date 2021-11-28
 */

#ifndef FLOOR_HPP
#define FLOOR_HPP

#include <vector>

#include "Passenger.hpp"

class Floor
{
public:

    /**
     * @brief Construct a new Floor object
     * 
     * @param identifier A unique ID for this floor
     */
    Floor(int identifier) : mIdentifier(identifier), mPassengerList() {};

    /**
     * @brief Returns a String representation of this object
     * 
     * @return std::string 
     */
    std::string toString() const;

    /**
     * @brief Determines if Passengers are waiting on this Floor to be picked up
     * 
     * @return true If the Passenger list is not empty
     * @return false If the Passenger list is empty
     */
    bool hasPassengersWaiting() {return (mPassengerList.size() > 0);};

    /**
     * @brief Creates a new Passenger and adds it to this Floor's waiting Passenger list
     * 
     * @param targetFloorID The floor the newly created Passenger needs to end up on
     */
    void addPassenger(int targetFloorID) {mPassengerList.push_back(Passenger(mIdentifier, targetFloorID));};

    /**
     * @brief Removes the next Passenger in line from the Passenger list and returns the object
     * 
     * @return Passenger The next Passenger that was in line
     */
    Passenger popNextPassengerInLine();

    /**
     * @brief Adds a +1 to each waiting Passenger's waiting time
     * 
     */
    void incrementAllTimeWaiting();
private:

    /**
     * @brief Unique identifier of this Floor
     * 
     */
    int mIdentifier;

    /**
     * @brief Collection of Passengers waiting on this Floor
     * 
     */
    std::vector<Passenger> mPassengerList;
};
    
/**
 * @brief Allows for printing this object to a stream
 * 
 * @param os 
 * @param s 
 * @return std::ostream& 
 */
std::ostream& operator<< (std::ostream &os, const Floor &s);

#endif // FLOOR_HPP