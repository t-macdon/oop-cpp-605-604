# hardcode doctest directory
# there are better ways to do this but for now this works
set (DOCTEST_INCLUDE_DIRS /workspaces/oop-cpp-605-604/doctest/doctest)

# again, hardcoded for now just to get this to work
set (POKER_RANKING_INCLUDE_DIRS /workspaces/oop-cpp-605-604/PokerRanking/src/pokerRanking/include)

# source files
set (TEST_SOURCE 
    CardTests.cpp
    CardValueTests.cpp
    HandTests.cpp
    UnitTestMain.cpp
)

# create test executable
add_executable(PokerRankingTest ${TEST_SOURCE})
target_include_directories(PokerRankingTest PRIVATE ${DOCTEST_INCLUDE_DIRS} ${POKER_RANKING_INCLUDE_DIRS})
target_link_libraries(PokerRankingTest PRIVATE PokerRankingLibrary)