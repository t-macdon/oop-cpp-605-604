/**
 * @file ElevatorStates.hpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Each ElevatorState is an operational state of the Elevator
 * @version 0.1
 * @date 2021-11-28
 */

#ifndef ELEVATORSTATES_HPP
#define ELEVATORSTATES_HPP

enum class ElevatorStates
{
    STOPPED, STOPPING, MOVING_UP, MOVING_DOWN
};

#endif // ELEVATORSTATES_HPP