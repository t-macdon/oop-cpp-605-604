# source files
file(GLOB SOURCE_FILES cpp/*.cpp)
file(GLOB HEADER_FILES include/*.h)
#set (SOURCE_FILES
#    cpp/*.cpp
#)

# header files
#set (HEADER_FILES
#    include/*.h
#)
#
# create a library we can use in our tests
add_library(ExpressionTreeLibrary ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(
    ExpressionTreeLibrary
    PRIVATE
    include
)

# create an executable
# add_executable(ExpressionTree main.cpp ${HEADER_FILES})
# target_link_libraries(ExpressionTree PRIVATE ExpressionTreeLibrary)