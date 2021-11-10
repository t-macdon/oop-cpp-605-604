#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include <queue>

#include "Passenger.hpp"
#include "Floor.hpp"

class Elevator
{
public:
    Elevator(int currentFloorID) : currentFloorID(currentFloorID) {};
    enum class State {STOPPED, STOPPING, MOVING_UP, MOVING_DOWN};
    static const int CAPACITY = 8;
    static const int STOPPING_TIME = 2;
    static const int FLOOR_MOVING_TIME = 10;
    bool hasPassengersOnBoard() const {return !passengers.empty();};
    void update();
private:
    void updateTargetFloor();

    std::queue<Passenger> passengers;
    int currentFloorID;
    int targetFloorID;
    State state = State::STOPPED;
};

#endif // ELEVATOR_HPP