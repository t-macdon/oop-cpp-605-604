set (SOURCE
    Elevator.cpp
    Event.cpp
    Floor.cpp
    Passenger.cpp
    Simulation.cpp
    Summary.cpp
    Utilities.cpp
)

set (HEADER
    ${PROJECT_INCLUDE_DIR}/Elevator.hpp
    ${PROJECT_INCLUDE_DIR}/ElevatorStates.hpp
    ${PROJECT_INCLUDE_DIR}/Event.hpp
    ${PROJECT_INCLUDE_DIR}/Floor.hpp
    ${PROJECT_INCLUDE_DIR}/Passenger.hpp
    ${PROJECT_INCLUDE_DIR}/Simulation.hpp
    ${PROJECT_INCLUDE_DIR}/Summary.hpp
    ${PROJECT_INCLUDE_DIR}/Utilities.hpp
)

add_library(ElevatorLibrary ${SOURCE} ${HEADER})
target_include_directories(ElevatorLibrary PRIVATE ${PROJECT_INCLUDE_DIR})
