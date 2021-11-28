#ifndef FLOOR_HPP
#define FLOOR_HPP

#include <vector>

#include "Passenger.hpp"

class Floor
{
public:
    Floor(int identifier) : mIdentifier(identifier), mPassengerList() {};
    std::string toString() const;

    bool hasPassengersWaiting() {return (mPassengerList.size() > 0);};
    Passenger getNextInLine() {return mPassengerList.at(0);};
    void addPassenger(int targetFloorID) {mPassengerList.push_back(Passenger(mIdentifier, targetFloorID));};
    Passenger popNextPassengerInLine();
    void incrementAllTimeWaiting();
private:
    int mIdentifier;
    std::vector<Passenger> mPassengerList;
};
    
std::ostream& operator<< (std::ostream &os, const Floor &s);

#endif // FLOOR_HPP