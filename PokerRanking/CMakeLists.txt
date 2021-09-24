cmake_minimum_required(VERSION 3.2)
project(PokerRanking)

# get the find cmake files
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")

# make warnings be errors
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

# find the jsoncpp package
find_package(JSONCPP)

# source files
set (SOURCE_FILES
    src/main.cpp
    src/Card.cpp
    src/CardValue.cpp
)

# header files
set (HEADER_FILES
    src/Card.h
    src/CardValue.h
)

add_executable(PokerRanking ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(
    PokerRanking 
    PRIVATE
    ${JSONCPP_INCLUDE_DIRS}
    src
)

target_link_libraries(
    PokerRanking
    ${JSONCPP_LIBRARIES}
)