/**
 * @file Board.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Header file for the Board class
 * @version 0.1
 * @date 2021-09-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <string>

enum class BoardPiece {
    X,
    O,
    EMPTY
};


/**
 * @brief The Board class tracks the current state of a board
 * 
 */
class Board {
public:
    Board();
    void setPiece(BoardPiece piece, int xPos, int yPos);
    BoardPiece getPiece(int xPos, int yPos) const;
    std::string toString(void) const;

private:
    static const int MAX_X {3};
    static const int MAX_Y {3};
    std::array<std::array<BoardPiece, MAX_X>, MAX_Y> pieces;
    static std::string pieceToString(BoardPiece piece);

};  // End of Board class

#endif // End of BOARD_H define