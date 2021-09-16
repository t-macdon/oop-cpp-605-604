#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Board.h"

TEST_CASE("Initialize the Board object") {
    Board b;
}

TEST_CASE("Set and Get a few board pieces, no errors") {
    Board b;
    b.setPiece(BoardPiece::X, 1, 2);
    CHECK(BoardPiece::X == b.getPiece(1,2));
}