
#include <iostream>
#include <queue>
#include <vector>

#include "Elevator.hpp"
#include "Floor.hpp"
#include "Passenger.hpp"
#include "PassengerCreationEvent.hpp"


int main()
{
    // create all the floors
    std::vector<Floor> floors;
    for (int i = 0; i < 100; i++)
    {
        floors.push_back(Floor(i));
    }

    // create 4 elevators
    std::vector<Elevator> elevators;
    for (int i = 0; i < 4; i++)
    {
        elevators.push_back(Elevator(0));
    }

    // TODO: load all events from csv file
    std::queue<PassengerCreationEvent> events;
    events.push(PassengerCreationEvent(41,54,55));
    events.push(PassengerCreationEvent(43,30,74));
    events.push(PassengerCreationEvent(88,87,32));

    // quit loop when no more events and no more passengers exist
    int simulationTime = 0;
    std::vector<Passenger> passengers;
    // TODO: we can probably just determine which floor an empty elevator goes to next
    // by looking at order of events... just pick the floor with the most recent event to target
    while (!events.empty() || !passengers.empty())
    {
        // check if we should process an event
        if (!events.empty())
        {
            PassengerCreationEvent nextEvent = events.front();
            if (nextEvent.startTime == simulationTime)
            {
                // create passenger for the event
                Passenger newPassenger(nextEvent.startFloorID, nextEvent.endFloorID);
                passengers.push_back(newPassenger);
                floors.at(nextEvent.startFloorID).addPassengerToQueue(newPassenger);

                // pop the event off the queue
                events.pop();
            }
        }

        // TODO: update elevators

        // update sim time
        simulationTime++;
    }
    
    std::cout << "HELLO WORLD" << std::endl;
    return 0;
}