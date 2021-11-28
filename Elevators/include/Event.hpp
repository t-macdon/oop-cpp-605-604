#ifndef EVENT_HPP
#define EVENT_HPP

#include <sstream>

struct Event
{
    Event(int startTime, int startFloor, int endFloor) :
        mStartTime(startTime), mStartFloor(startFloor), mEndFloor(endFloor) {};
    int mStartTime;
    int mStartFloor;
    int mEndFloor;

    std::string toString() const;
};
    
std::ostream& operator<< (std::ostream &os, const Event &s);

#endif // EVENT_HPP