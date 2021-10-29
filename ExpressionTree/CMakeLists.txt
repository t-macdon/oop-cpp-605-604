cmake_minimum_required(VERSION 3.2)
project(ExpressionTree)

# get the find cmake files
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")

# make warnings be errors
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -g")

# tell cmake where to put files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

add_subdirectory(src/ExpressionTree)
add_subdirectory(src/tests)

# create main executable
# add_executable(ExpressionTree ${SOURCE} ${HEADERS})
# target_include_directories(ExpressionTree PRIVATE include ${DOCTEST_INCLUDE_DIRS})
