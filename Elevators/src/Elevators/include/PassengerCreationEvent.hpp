#ifndef PASSENGER_CREATION_EVENT_HPP
#define PASSENGER_CREATION_EVENT_HPP

struct PassengerCreationEvent
{
    PassengerCreationEvent() {};
    PassengerCreationEvent(unsigned int startTime, unsigned int startFloorID, unsigned int endFloorID) 
        : startTime(startTime), startFloorID(startFloorID), endFloorID(endFloorID) {};
    unsigned int startTime;
    unsigned int startFloorID;
    unsigned int endFloorID;
};

#endif // PASSENGER_CREATION_EVENT_HPP