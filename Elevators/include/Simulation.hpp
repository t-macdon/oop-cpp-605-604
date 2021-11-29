/**
 * @file Simulation.hpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Main container for the working elevator simulation
 * @version 0.1
 * @date 2021-11-28
 */

#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Elevator.hpp"
#include "Event.hpp"
#include "Floor.hpp"
#include "Summary.hpp"

#include <queue>
#include <vector>

class Elevator;

class Simulation
{
public:

    /**
     * @brief Construct a new Simulation object
     * 
     * @param numberOfElevators Number of working Elevators that can pick up Passengers
     * @param numberOfFloors Number of Floors that Passengers can arrive on and Elevators can go to
     * @param elevatorSpeed The time in seconds it takes an elevator to travel between Floors
     * @param CSVPath The String absolute path of the CSV file containing Passenger creation events
     */
    Simulation(int numberOfElevators, int numberOfFloors, int elevatorSpeed, const std::string CSVPath);

    /**
     * @brief Runs the Simulation object and collects results
     * 
     * @return Summary The data collected during the Simulation
     */
    Summary run();

    /**
     * @brief Adds a data point to the time spent waiting list
     * 
     * @param timeSpentWaiting Number of seconds a Passenger spent waiting
     */
    void addTimeSpentWaiting(int timeSpentWaiting) {mTimeSpentWaitingList.push_back(timeSpentWaiting);};

    /**
     * @brief Adds a data point to the time spent travelling list
     * 
     * @param timeSpentTravelling Number of seconds a Passenger spent travelling
     */
    void addTimeSpentTravelling(int timeSpentTravelling) {mTimeSpentTravellingList.push_back(timeSpentTravelling);};

    /**
     * @brief Removes a Passenger from the Floor with the provided ID and returns the Passenger
     * 
     * @param floorID The ID of the Floor to pop a Passenger from
     * @return Passenger The popped Passenger
     */
    Passenger popPassengerFromFloor(int floorID) {return mFloorList.at(floorID).popNextPassengerInLine();};

    /**
     * @brief Determines if the Floor with the provided ID has Passengers waiting
     * 
     * @param floorID The ID of the Floor to check
     * @return true If the Floor has Passengers waiting for an Elevator to arrive
     * @return false If the Floor has no Passengers on it
     */
    bool floorHasPassengersWaiting(int floorID) {return mFloorList.at(floorID).hasPassengersWaiting();};

    /**
     * @brief Compute the total number of Floors
     * 
     * @return int The number of Floors in the Simulation
     */
    int getNumberOfFloors() {return mFloorList.size();};

private:

    /**
     * @brief A collection of the Elevator objects used in this Simulation
     * 
     */
    std::vector<Elevator> mElevatorList;

    /**
     * @brief A collection of the Floor objects used in this Simulation
     * 
     */
    std::vector<Floor> mFloorList;

    /**
     * @brief A collection of the Event objects used in this Simulation
     * 
     */
    std::queue<Event> mEventQueue;

    /**
     * @brief Total elapsed time in seconds during this Simulation
     * 
     */
    int mElapsedSimulationTime = 0;

    /**
     * @brief Collection of all data points for time spent waiting by Passengers
     *  Used to compute the average at the end of the Simulation
     * 
     */
    std::vector<int> mTimeSpentWaitingList;

    /**
     * @brief Collection of all data points for time spent travelling by Passengers
     *  Used to compute the average at the end of the Simulation
     * 
     */
    std::vector<int> mTimeSpentTravellingList;

    /**
     * @brief Checks if there are events remaining, Passengers waiting on floors, or Passengers travelling in Elevators
     *  to determine if the Simulation has completed
     * 
     * @return true If Simulation should continue
     * @return false If Simulation should exit
     */
    bool isSimulationRunning();

    /**
     * @brief Computes and returns the average time in seconds Passengers spent waiting
     * 
     * @return float
     */
    float getAverageTimeSpentWaiting();

    /**
     * @brief Computes and returns the average time in seconds Passengers spent travelling
     * 
     * @return float 
     */
    float getAverageTimeSpentTravelling();
};

#endif // SIMULATION_HPP