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

bool Board::setPiece(BoardPiece piece, int xPos, int yPos)
{
    // Confirm X, Y are in range
    if (xPos > MAX_X || yPos > MAX_Y) {
        throw runtime_error("X or Y out of range");
    }

    // TODO: Do we want to check what's there first?
    // Or leave it up to the caller to enforce legal moves
    if (this->pieces[yPos][xPos] == BoardPiece::EMPTY)
    {
        this->pieces[yPos][xPos] = piece;
        return true;
    }

    return false;
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
        return "-";
    }
}


string Board::winnerToString(BoardWinner piece)
{
    if (BoardWinner::X == piece) {
        return "X";
    }
    else if (BoardWinner::O == piece) {
        return "O";
    }
    else {
        return "NONE";
    }
}

void Board::playBotTurn()
{
    // our smart AI chooses the first available piece
    // nothing will be changed if there are no empty pieces
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (this->pieces[y][x] == BoardPiece::EMPTY)
            {
                this->pieces[y][x] = BoardPiece::O;
                return;
            }
        }
    }
}

BoardWinner Board::pieceToWinner(BoardPiece piece)
{

    if (piece == BoardPiece::X)
    {
        return BoardWinner::X;
    } else if (piece == BoardPiece::O)
    {
        return BoardWinner::O;
    } else
    {
        return BoardWinner::NONE;
    }
}

BoardWinner Board::getWinner(void) const {
    // Iterate over the board
    // check each row for a winner
    // check each column for a winner
    for (int i = 0; i < 3; i++)
    {
        // check ith row
        if (pieces[i][0] == pieces[i][1] && pieces[i][1] == pieces[i][2])
        {
            return pieceToWinner(pieces[i][0]);
        }

        // check ith column
        if (pieces[0][i] == pieces[1][i] && pieces[1][i] == pieces[2][i])
        {
            return pieceToWinner(pieces[0][i]);
        }
    }

    // check diagonals
    if (pieces[0][0] == pieces[1][1] && pieces[1][1] == pieces[2][2])
    {
        return pieceToWinner(pieces[0][0]);
    }

    if (pieces[2][0] == pieces[1][1] && pieces[1][1] == pieces[0][2])
    {
        return pieceToWinner(pieces[2][0]);
    }

    // Tie is had when all grids are filled
    // yet no one has a winning combination
    // if any of the pieces are EMPTY then return NONE
    // if none are EMPTY then we have a tie
    for (int x = 0; x < 3; x++)
    {   
        for (int y = 0; y < 3; y++)
        {
            if (pieces[x][y] == BoardPiece::EMPTY)
            {
                return BoardWinner::NONE;
            }
        }
    }

    return BoardWinner::TIE;
}