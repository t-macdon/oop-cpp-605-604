cmake_minimum_required(VERSION 3.2)
project(PokerRanking)

# get the find cmake files
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")

# make warnings be errors
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

# find the jsoncpp package
find_package(JSONCPP REQUIRED)

# build PokerRanking library
add_subdirectory(src/pokerRanking)

# build test library
add_subdirectory(src/tests)
