
#include <iostream>

#include "Simulation.hpp"
#include "Utilities.hpp"

Simulation::Simulation(int numberOfElevators, int numberOfFloors, int elevatorSpeed, const std::string CSVPath)
{
    // create the elevators
    for (int i = 0; i < numberOfElevators; i++)
    {
        mElevatorList.push_back(Elevator(elevatorSpeed));
    }

    // create the floors
    for (int i = 0; i < numberOfFloors; i++)
    {
        mFloorList.push_back(Floor(i));
    }

    // load all events into queue
    mEventQueue = Utilities::loadEventsFromCSV(CSVPath);
}

Summary Simulation::run()
{
    //std::cout << "Running..." << std::endl;
    //std::cout << mElevatorList.size() << " elevators" << std::endl;
    //std::cout << mFloorList.size() << " floors" << std::endl;
    //std::cout << mEventQueue.size() << " passengers" << std::endl;

    while (isSimulationRunning())
    {
        //std::cout << "Time: " << mElapsedSimulationTime << std::endl;

        // process event if applicable
        if (!mEventQueue.empty())
        {
            Event possibleEvent = mEventQueue.front();
            if (possibleEvent.mStartTime <= mElapsedSimulationTime)
            {
                //std::cout << "Adding event: " << possibleEvent << std::endl;
                mFloorList.at(possibleEvent.mStartFloor).addPassenger(possibleEvent.mEndFloor);
                mEventQueue.pop();
            }
        }

        // update all elevators
        for (Elevator &elevator : mElevatorList)
        {
            //std::cout << "Elevator: " << elevator << std::endl;
            elevator.update(*this);
        }

        // update time spent waiting for passengers on all floors
        for (Floor &floor : mFloorList)
        {
            floor.incrementAllTimeWaiting();
        }

        // increment simulation time
        mElapsedSimulationTime += 1;
    }

    //std::cout << "Exiting" << std::endl;
    return Summary(getAverageTimeSpentWaiting(), getAverageTimeSpentTravelling(), mElapsedSimulationTime);
}

float Simulation::getAverageTimeSpentWaiting()
{
    float total = 0;
    for (int &i : mTimeSpentWaitingList)
    {
        total += i;
    }
    return (total / mTimeSpentWaitingList.size());
}

float Simulation::getAverageTimeSpentTravelling()
{
    float total = 0;
    for (int &i : mTimeSpentTravellingList)
    {
        total += i;
    }
    return (total / mTimeSpentTravellingList.size());
}

bool Simulation::isSimulationRunning()
{
    // first see if we have events
    bool eventsRemaining = !mEventQueue.empty();

    // now see if the passengers are waiting
    bool passengersWaiting = false;
    for (Floor &floor : mFloorList)
    {
        if (floor.hasPassengersWaiting())
        {
            passengersWaiting = true;
        }
    }

    // finally, check if passengers are travelling
    bool passengersTravelling = false;
    for (Elevator &elevator : mElevatorList)
    {
        if (elevator.hasPassengersTravelling())
        {
            passengersTravelling = true;
        }
    }

    return (eventsRemaining || passengersWaiting || passengersTravelling);
}
