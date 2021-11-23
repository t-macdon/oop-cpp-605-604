
#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <vector>

#include "Elevator.hpp"
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
    // load event data
    const std::string eventsDataPath = "/workspaces/oop-cpp-605-604/Elevators/elevator_data.csv";
    std::queue<PassengerCreationEvent> events = loadEventsFromCSV(eventsDataPath);
    std::cout << "Events go from time " << events.front().startTime << " to " << events.back().startTime << std::endl;

    // create the floors
    // floors are just Passenger queues at a specific index
    // passengers are just their target floors
    std::vector<std::queue<unsigned int>> floors;
    for (int i = 0; i < 100; i++)
    {
        floors.push_back(std::queue<unsigned int>());
    }

    // one unit of time per loop iteration
    unsigned int simulationTime = 0;

    // maintains the next event
    PassengerCreationEvent curEvent;

    // event loop
    // goes until we have no more events, all floors are empty, and all elevators are empty
    while (!events.empty())
    {
        // look at next event, but only process it if we have the right simulation time
        curEvent = events.front();
        if (simulationTime >= curEvent.startTime)
        {
            // process event by putting the passenger (ie target floor) on the correct floor
            floors.at(curEvent.startFloorID).push(curEvent.endFloorID);

            std::cout << "[Time: " << curEvent.startTime << "] Passenger starting at floor " << curEvent.startFloorID << " with a target floor of " << curEvent.endFloorID << std::endl;

            // remove the event from the queue since it's been processed
            events.pop();

            std::cout << events.size() << " events left" << std::endl;
        }


        // loop is over so increment the simulation time
        simulationTime++;
    }

    int counter = 0;
    for (std::queue<unsigned int> &floor : floors)
    {
        std::cout << "Floor at " << counter << " has " << floor.size() << " passengers waiting" << std::endl;
        counter++;
    }

    return 0;
}
