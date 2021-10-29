# hardcode doctest directory
# there are better ways to do this but for now this works
set (DOCTEST_INCLUDE_DIRS /workspaces/oop-cpp-605-604/doctest/doctest)

# again, hardcoded for now just to get this to work
set (EXPRESSION_TREE_INCLUDE_DIRS /workspaces/oop-cpp-605-604/ExpressionTree/src/ExpressionTree/include)

# source files
file (GLOB TEST_SOURCE *.cpp)

# create test executable
add_executable(ExpressionTreeTest ${TEST_SOURCE})
target_include_directories(ExpressionTreeTest PRIVATE ${DOCTEST_INCLUDE_DIRS} ${EXPRESSION_TREE_INCLUDE_DIRS})
target_link_libraries(ExpressionTreeTest PRIVATE ExpressionTreeLibrary)