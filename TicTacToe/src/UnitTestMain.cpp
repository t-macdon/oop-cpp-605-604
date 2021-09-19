#include <iostream>

#if defined(RUN_UNIT_TESTS) && RUN_UNIT_TESTS
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#else
#define DOCTEST_CONFIG_IMPLEMENT
#endif
#include "doctest.h"
#include "Board.h"

using namespace std;

TEST_CASE("Initialize the Board object") {
    Board b;
}

TEST_CASE("Set and Get a few board pieces, no errors") {
    Board b;
    b.setPiece(BoardPiece::X, 1, 2);
    CHECK(BoardPiece::X == b.getPiece(1,2));
}

TEST_CASE("Print a board as a string") {
    Board b;
    stringstream ss;
    b.setPiece(BoardPiece::X, 0, 0);
    b.setPiece(BoardPiece::X, 1, 1);
    b.setPiece(BoardPiece::X, 2, 2);
    ss << " X    " << endl;
    ss << "   X  " << endl;
    ss << "     X" << endl;
    CHECK(ss.str() == b.toString());
    ss.str(string()); // Clear out the string stream
    b.setPiece(BoardPiece::O, 1, 0);
    b.setPiece(BoardPiece::O, 2, 1);
    b.setPiece(BoardPiece::O, 0, 2);
    ss << " X O  " << endl;
    ss << "   X O" << endl;
    ss << " O   X" << endl;
    CHECK(ss.str() == b.toString());
}