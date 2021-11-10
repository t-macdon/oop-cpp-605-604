#ifndef FLOOR_HPP
#define FLOOR_HPP

#include <queue>

#include "Passenger.hpp"

class Floor
{
public:
    Floor(const int identifier) : identifier(identifier) {};
    ~Floor() {};
    void addPassengerToQueue(Passenger &passenger) {passengerQueue.push(passenger);};
private:
    const int identifier;
    std::queue<Passenger> passengerQueue;
};

#endif // FLOOR_HPP