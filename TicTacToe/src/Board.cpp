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
    this->pieces[yPos][xPos] = piece;
}


BoardPiece Board::getPiece(int xPos, int yPos) const
{
    // Confirm X, Y are in range.
    // If out of range, return Empty Piece
    if (xPos > MAX_X || yPos > MAX_Y) {
        return BoardPiece::EMPTY;
    }

    return this->pieces[yPos][xPos];
}

string Board::toString(void) const
{
    stringstream out;
    for(auto row: this->pieces) {
        for(auto piece: row) {
            out << " " << pieceToString(piece);
        }
        out << endl;
    }
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

BoardWinner Board::getWinner(void) const {
    // Check for a winner by rows

    // Check for a winner by columns

    // Check for a winner by verticals

    // Tie is had when all grids are filled
    // yet no one has a winning combination

    return BoardWinner::NONE;
}