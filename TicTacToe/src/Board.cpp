#include <exception>
#include <string>
#include <sstream>
#include "Board.h"

using namespace std;

Board::Board() :
    pieces {{
        {{BoardPiece::EMPTY, BoardPiece::EMPTY, BoardPiece::EMPTY}},
        {{BoardPiece::EMPTY, BoardPiece::EMPTY, BoardPiece::EMPTY}},
        {{BoardPiece::EMPTY, BoardPiece::EMPTY, BoardPiece::EMPTY}},
    }}
    {
        ;
    }

void Board::setPiece(BoardPiece piece, int xPos, int yPos)
{
    // Confirm X, Y are in range
    if (xPos > MAX_X || yPos > MAX_Y) {
        throw runtime_error("X or Y out of range");
    }

    // TODO: Do we want to check what's there first?
    // Or leave it up to the caller to enforce legal moves
    this->pieces[xPos][yPos] = piece;
}


BoardPiece Board::getPiece(int xPos, int yPos) const
{
    // Confirm X, Y are in range.
    // If out of range, return Empty Piece
    if (xPos > MAX_X || yPos > MAX_Y) {
        return BoardPiece::EMPTY;
    }

    return this->pieces[xPos][yPos];
}

// TODO
string Board::toString(void) const
{
    stringstream out;
    out << "  |   |   |   |   ";
    out << "--+---+---+---+---";
    out << "  |   |   |   |   ";
    out << "--+---+---+---+---";
    out << "  |   |   |   |   ";
    return out.str();
}


string Board::pieceToString(BoardPiece piece)
{
    if (BoardPiece::X == piece) {
        return "X";
    }
    else if (BoardPiece::O == piece) {
        return "O";
    }
    else {
        return " ";
    }
}