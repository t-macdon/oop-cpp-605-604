# hardcode doctest directory
# there are better ways to do this but for now this works
set (DOCTEST_INCLUDE_DIRS /workspaces/oop-cpp-605-604/doctest/doctest)

# again, hardcoded for now just to get this to work
set (POKER_INCLUDE_DIRS /workspaces/oop-cpp-605-604/Poker/src/Poker/include)

# source files
file (GLOB TEST_SOURCE *.cpp)

# create test executable
add_executable(PokerTest ${TEST_SOURCE})
target_include_directories(PokerTest PRIVATE ${DOCTEST_INCLUDE_DIRS} ${POKER_INCLUDE_DIRS})
target_link_libraries(PokerTest PRIVATE PokerLibrary)