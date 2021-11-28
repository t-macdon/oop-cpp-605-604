#include "Floor.hpp"

Passenger Floor::popNextPassengerInLine()
{
    Passenger passenger = mPassengerList.front();
    mPassengerList.erase(mPassengerList.begin());
    return passenger;
}

void Floor::incrementAllTimeWaiting()
{
    for (Passenger &passenger : mPassengerList)
    {
        passenger.mTimeSpentWaiting += 1;
    }
}

std::string Floor::toString() const {
    std::stringstream ss;
    ss << "[mIdentifier=" << mIdentifier;
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

std::ostream& operator<< (std::ostream &os, const Floor &s) {
    return (os << s.toString());
}
