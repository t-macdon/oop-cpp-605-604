cmake_minimum_required(VERSION 3.2)
project(Probability)

# get the find cmake files
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")

# make warnings be errors
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -g")

# tell cmake where to put files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# hardcode doctest directory
# there are better ways to do this but for now this works
set (DOCTEST_INCLUDE_DIRS /workspaces/oop-cpp-605-604/doctest/doctest)

# source files
set (SOURCE 
    src/IndependentEvent.cpp
    src/ProbabilityTests.cpp
)

set (HEADERS
    include/IndependentEvent.h
)

# create test executable
add_executable(Probability ${SOURCE} ${HEADERS})
target_include_directories(Probability PRIVATE include ${DOCTEST_INCLUDE_DIRS})
