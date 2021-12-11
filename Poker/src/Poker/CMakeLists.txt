# source files
file(GLOB SOURCE_FILES cpp/*.cpp)
file(GLOB HEADER_FILES include/*.h)

# create a library we can use in our tests
add_library(PokerLibrary ${SOURCE_FILES} ${HEADER_FILES})
add_executable(Poker Poker.cpp ${SOURCE} ${HEADERS})

target_include_directories(
    PokerLibrary
    PRIVATE
    ${JSONCPP_INCLUDE_DIRS}
    include
)

target_link_libraries(
    PokerLibrary
    ${JSONCPP_LIBRARIES}
)

target_include_directories(
    Poker
    PRIVATE
    include
)

target_link_libraries(
    Poker
    PokerLibrary
)
