# source files
set (SOURCE_FILES
    cpp/Card.cpp
    cpp/CardValue.cpp
)

# header files
set (HEADER_FILES
    include/Card.h
    include/CardValue.h
)

# create a library we can use in our tests
add_library(PokerRankingLibrary ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(
    PokerRankingLibrary
    PRIVATE
    ${JSONCPP_INCLUDE_DIRS}
    include
)

target_link_libraries(
    PokerRankingLibrary
    ${JSONCPP_LIBRARIES}
)

# create an executable
add_executable(PokerRanking main.cpp)
target_include_directories(PokerRanking PRIVATE include)
target_link_libraries(PokerRanking PRIVATE PokerRankingLibrary)