#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include <vector>

#include "ElevatorStates.hpp"
#include "Passenger.hpp"
#include "Simulation.hpp"

class Simulation;

class Elevator
{
public:
    static const int CAPACITY = 8;
    Elevator(int speed) : mSpeed(speed) {};
    void update(Simulation &simulation);
    bool hasPassengersTravelling() {return !mPassengerList.empty();};
    std::string toString() const;
private:
    int mSpeed;
    ElevatorStates mState = ElevatorStates::STOPPED;
    int mCurrentFloorID = 0;
    int mTargetFloorID = 0;
    int mTimeSpentMoving = 0;
    std::vector<Passenger> mPassengerList;

    void handleStoppedState(Simulation &simulation);
    void handleMovingDownState();
    void handleMovingUpState();
    void handleNewFloor();
    ElevatorStates determineDirection();
    int getFirstFloorWithWaitingPassengers(Simulation &simulation);
};
    
std::ostream& operator<< (std::ostream &os, const Elevator &s);

#endif // ELEVATOR_HPP