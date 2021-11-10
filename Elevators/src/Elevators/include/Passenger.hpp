#ifndef PASSENGER_HPP
#define PASSENGER_HPP

class Passenger
{
public:
    Passenger(int currentFloorID, int targetFloorID) : currentFloorID(currentFloorID), targetFloorID(targetFloorID) {};
private:
    int currentFloorID;
    int targetFloorID;
};

#endif // PASSENGER_HPP