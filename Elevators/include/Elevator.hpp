/**
 * @file Elevator.hpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Represents an Elevator in the simulation
 * @version 0.1
 * @date 2021-11-28
 */

#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include <vector>

#include "ElevatorStates.hpp"
#include "Passenger.hpp"
#include "Simulation.hpp"

// forward delcaration
class Simulation;

class Elevator
{
public:

    /**
     * @brief The total number of passengers that can fit in an elevator
     * 
     */
    static const int CAPACITY = 8;

    /**
     * @brief How many seconds the Elevator needs to spend STOPPING before it can transition to STOPPED
     * 
     */
    static const int STOPPING_TIME = 2;

    /**
     * @brief Construct a new Elevator object
     * 
     * @param speed How many seconds it takes for an elevator to travel between floors
     */
    Elevator(int speed) : mSpeed(speed) {};

    /**
     * @brief Updates the state of each Elevator depending on the state of the simulation.
     *  This can also update the state of the Passengers, Floors, and Simulation object itself
     *  if Passengers are leaving an Elevator or Floor
     * 
     * @param simulation Reference to the main simulation object
     */
    void update(Simulation &simulation);

    /**
     * @brief Determines if this Elevator contains Passengers
     * 
     * @return true If the Passenger list is not empty
     * @return false If the Passenger list is empty
     */
    bool hasPassengersTravelling() {return !mPassengerList.empty();};

    /**
     * @brief Returns a String representation of this object
     * 
     * @return std::string 
     */
    std::string toString() const;

private:

    /**
     * @brief The time in seconds it takes this elevator to travel between floors
     * 
     */
    int mSpeed;

    /**
     * @brief The current operational state of the Elevator
     * 
     */
    ElevatorStates mState = ElevatorStates::STOPPED;

    /**
     * @brief The ID of the Floor the Elevator is currently on
     *  If the Elevator is travelling between floors, this number
     *  is the ID of the Floor most recently passed by the Elevator
     * 
     */
    int mCurrentFloorID = 0;

    /**
     * @brief The ID of the Floor the Elevator is moving toward
     * 
     */
    int mTargetFloorID = 0;

    /**
     * @brief How many seconds have elapsed since the Elevator started moving between Floors
     * 
     */
    int mTimeSpentMoving = 0;

    /**
     * @brief How many seconds have elapsed since the Elevator began stopping
     * 
     */
    int mTimeSpentStopping = 0;

    /**
     * @brief Collection of all Passengers currently riding the Elevator
     * 
     */
    std::vector<Passenger> mPassengerList;

    /**
     * @brief Handles the Elevator stopping for STOPPING_TIME seconds before becoming STOPPED
     * 
     */
    void handleStoppingState();

    /**
     * @brief Handles embarking/disembarking Passengers and transitioning to the appropriate movement state
     * 
     * @param simulation A reference to the current simulation
     */
    void handleStoppedState(Simulation &simulation);

    /**
     * @brief Moves the elevator down
     * 
     */
    void handleMovingDownState();

    /**
     * @brief Moves the elevator up
     * 
     */
    void handleMovingUpState();

    /**
     * @brief Updates the Elevator accordingly when a new Floor is reached
     * 
     */
    void handleNewFloor();

    /**
     * @brief Decides if the Elevator needs to move up, down, or nowhere to reach its target
     * 
     * @return ElevatorStates 
     */
    ElevatorStates determineDirection();

    /**
     * @brief Finds a floor with Passengers waiting to be picked up
     * 
     * @param simulation A reference to the current simulation object
     * @return int -1 if no floor has Passengers waiting, a valid Floor ID otherwise
     */
    int getFirstFloorWithWaitingPassengers(Simulation &simulation);
};

/**
 * @brief Allows for printing this object to a stream
 * 
 * @param os 
 * @param s 
 * @return std::ostream& 
 */
std::ostream& operator<< (std::ostream &os, const Elevator &s);

#endif // ELEVATOR_HPP