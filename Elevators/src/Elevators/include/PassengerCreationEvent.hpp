#ifndef PASSENGER_CREATION_EVENT_HPP
#define PASSENGER_CREATION_EVENT_HPP

class PassengerCreationEvent
{
public:
    PassengerCreationEvent(int startTime, int startFloorID, int endFloorID) :
        startTime(startTime), startFloorID(startFloorID), endFloorID(endFloorID) {};
    int startTime, startFloorID, endFloorID;
};

#endif // PASSENGER_CREATION_EVENT_HPP