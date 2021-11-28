#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include <sstream>

struct Passenger
{
    Passenger(int startFloorID, int targetFloorID) :
        mStartFloorID(startFloorID), mTargetFloorID(targetFloorID) {};
    int mStartFloorID;
    int mTargetFloorID;
    int mTimeSpentWaiting = 0;
    int mTimeSpentTravelling = 0;

    std::string toString() const;
};
    
std::ostream& operator<< (std::ostream &os, const Passenger &s);

#endif // PASSENGER_HPP