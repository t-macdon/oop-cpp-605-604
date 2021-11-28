#include <iostream>

#include "Elevator.hpp"

std::string Elevator::toString() const {
    std::stringstream ss;
    ss << "[mCurrentFloorID=" << mCurrentFloorID;
    ss << ", mTargetFloorID=" << mTargetFloorID;
    ss << ", numberOfPassengers=" << mPassengerList.size();

    ss << ", mPassengerList=";
    ss << "[";
    
    for (size_t i = 0; i < mPassengerList.size(); i++)
    {
        ss << mPassengerList.at(i);
        if (i + 1 != mPassengerList.size())
        {
            ss << ", ";
        }
    }
    
    ss << "]";
    ss << "]";
    return ss.str();
}

std::ostream& operator<< (std::ostream &os, const Elevator &s) {
    return (os << s.toString());
}

void Elevator::update(Simulation &simulation)
{
    // update time spent travelling for all passengers
    for (Passenger &passenger : mPassengerList)
    {
        passenger.mTimeSpentTravelling += 1;
    }

    // now handle state
    if (mState == ElevatorStates::STOPPED)
    {
        handleStoppedState(simulation);
    } else if (mState == ElevatorStates::STOPPING)
    {

    } else if (mState == ElevatorStates::MOVING_DOWN)
    {
        handleMovingDownState();
    } else if (mState == ElevatorStates::MOVING_UP)
    {
        handleMovingUpState();
    }
}

void Elevator::handleStoppedState(Simulation &simulation)
{
    // check if we have passengers that can leave
    // remove them if they can
    std::vector<Passenger>::iterator passengerIterator = mPassengerList.begin();
    while (passengerIterator != mPassengerList.end())
    {
        if (passengerIterator->mTargetFloorID == mCurrentFloorID)
        {
            simulation.addTimeSpentWaiting(passengerIterator->mTimeSpentWaiting);
            simulation.addTimeSpentTravelling(passengerIterator->mTimeSpentTravelling);
            passengerIterator = mPassengerList.erase(passengerIterator);
        } else
        {
            passengerIterator++;
        }
    }

    // pick up new passengers if applicable
    while (mPassengerList.size() < CAPACITY && simulation.floorHasPassengersWaiting(mCurrentFloorID))
    {
        Passenger floorPassenger = simulation.popPassengerFromFloor(mCurrentFloorID);
        mPassengerList.push_back(floorPassenger);
    }

    // if we are at our target floor, choose a new target if applicable
    if (mCurrentFloorID == mTargetFloorID)
    {
        // revaluate movement
        // if we have passengers, go to the target floor of the first in line
        if (mPassengerList.size() > 0)
        {
            mTargetFloorID = mPassengerList.at(0).mTargetFloorID;
            //std::cout << "Eleavtor has passengers and is going to floor " << mTargetFloorID << std::endl;
        } else
        {
            // see if we can go somewhere and pick up a passenger
            int nextTarget = getFirstFloorWithWaitingPassengers(simulation);
            //std::cout << "Floor with passengers is: " << nextTarget << std::endl;
            if (nextTarget != -1)
            {
                mTargetFloorID = nextTarget;
            }
        }
    }

    // determine next state (can be same as current state depending on outcome of above operations)
    mState = determineDirection();
}

void Elevator::handleMovingDownState()
{
    mTimeSpentMoving += 1;
    if (mTimeSpentMoving % mSpeed == 0)
    {
        // elevator has made it to a new floor
        mCurrentFloorID -= 1;
        mTimeSpentMoving = 0;
        handleNewFloor();
    }
}

void Elevator::handleMovingUpState()
{
    mTimeSpentMoving += 1;
    if (mTimeSpentMoving % mSpeed == 0)
    {
        // elevator has made it to a new floor
        mCurrentFloorID += 1;
        mTimeSpentMoving = 0;
        handleNewFloor();
    }
}

void Elevator::handleNewFloor()
{
    if (mCurrentFloorID == mTargetFloorID)
    {
        // stop the elevator if we have arrived
        mState = ElevatorStates::STOPPED;
    } else
    {
        // if any passengers can get off on this floor, stop the elevator
        for (Passenger &passenger : mPassengerList)
        {
            if (passenger.mTargetFloorID == mCurrentFloorID)
            {
                mState = ElevatorStates::STOPPED;
            }
        }
    }
}

ElevatorStates Elevator::determineDirection()
{
    if (mCurrentFloorID < mTargetFloorID)
    {
        return ElevatorStates::MOVING_UP;
    } else if (mCurrentFloorID > mTargetFloorID)
    {
        return ElevatorStates::MOVING_DOWN;
    } else
    {
        return ElevatorStates::STOPPED;
    }
}

int Elevator::getFirstFloorWithWaitingPassengers(Simulation &simulation)
{
    for (int i = 0; i < simulation.getNumberOfFloors(); i++)
    {
        if (simulation.floorHasPassengersWaiting(i))
        {
            return i;
        }
    }
    return -1;
}
