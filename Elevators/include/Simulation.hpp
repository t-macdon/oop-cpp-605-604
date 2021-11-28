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
    Simulation(int numberOfElevators, int numberOfFloors, int elevatorSpeed, const std::string CSVPath);
    Summary run();
    float getAverageTimeSpentWaiting();
    float getAverageTimeSpentTravelling();
    void addTimeSpentWaiting(int timeSpentWaiting) {mTimeSpentWaitingList.push_back(timeSpentWaiting);};
    void addTimeSpentTravelling(int timeSpentTravelling) {mTimeSpentTravellingList.push_back(timeSpentTravelling);};
    Passenger popPassengerFromFloor(int floorID) {return mFloorList.at(floorID).popNextPassengerInLine();};
    bool floorHasPassengersWaiting(int floorID) {return mFloorList.at(floorID).hasPassengersWaiting();};
    int getNumberOfFloors() {return mFloorList.size();};
private:
    std::vector<Elevator> mElevatorList;
    std::vector<Floor> mFloorList;
    std::queue<Event> mEventQueue;
    int mElapsedSimulationTime = 0;
    std::vector<int> mTimeSpentWaitingList;
    std::vector<int> mTimeSpentTravellingList;

    bool isSimulationRunning();
};

#endif // SIMULATION_HPP