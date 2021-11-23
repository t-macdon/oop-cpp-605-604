
#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <vector>

#include "Elevator.hpp"
#include "Floor.hpp"
#include "Passenger.hpp"
#include "PassengerCreationEvent.hpp"

static const char CSV_DELIMETER = ',';

std::queue<PassengerCreationEvent> loadEventsFromCSV(const std::string &pathToCSV)
{
    std::queue<PassengerCreationEvent> events;

    std::string row;
    std::ifstream eventsFile(pathToCSV);

    if (eventsFile.is_open())
    {
        // process each row in file
        bool header = true;
        while ( getline( eventsFile, row ) )
        {
            // skip the first header line
            if (header)
            {
                header = false;
                continue;
            }

            // parse row into data
            std::stringstream ss(row);
            std::string csvColumn;
            std::vector<std::string> rowData;
            while ( getline( ss, csvColumn, CSV_DELIMETER ) )
            {
                rowData.push_back(csvColumn);
            }
            
            // convert row data into event object
            PassengerCreationEvent event(
                stoi(rowData.at(0)),
                stoi(rowData.at(1)),
                stoi(rowData.at(2))
            );
            events.push(event);
        }
        eventsFile.close();
    }

    return events;
}

int main()
{
    const std::string eventsDataPath = "/workspaces/oop-cpp-605-604/Elevators/elevator_data.csv";
    std::queue<PassengerCreationEvent> events = loadEventsFromCSV(eventsDataPath);
    PassengerCreationEvent curEvent;
    while (!events.empty())
    {
        // get next event
        curEvent = events.front();
        events.pop();

        // print it
        std::cout << curEvent.startTime << "," << curEvent.startFloorID << "," << curEvent.endFloorID << std::endl;
    }
    return 0;
}

int main2()
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
    unsigned int simulationTime = 0;
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