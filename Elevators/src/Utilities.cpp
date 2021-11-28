#include <fstream>

#include "Utilities.hpp"

std::queue<Event> Utilities::loadEventsFromCSV(const std::string &CSVPath)
{
    std::queue<Event> events;

    std::string row;
    std::ifstream eventsFile(CSVPath);

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
            Event event(
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