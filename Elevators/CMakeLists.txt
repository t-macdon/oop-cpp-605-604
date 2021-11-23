cmake_minimum_required(VERSION 3.2)
project(Elevators)

# get the find cmake files
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")

# make warnings be errors
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -g")

# tell cmake where to put files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# add_subdirectory(src/Elevators)
# add_subdirectory(src/tests)

# create main executable
set(SOURCE
    src/Elevators/cpp/Elevator.cpp
    src/Elevators/cpp/ElevatorSimulation.cpp
)

set(HEADERS
    src/Elevators/include/Elevator.hpp
    src/Elevators/include/PassengerCreationEvent.hpp
)

add_executable(
    Elevators
    ${SOURCE}
    ${HEADERS}
)

target_include_directories(
    Elevators 
    PRIVATE 
    src/Elevators/include
)
