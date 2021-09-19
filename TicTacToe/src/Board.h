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

/**
 * @brief This class captures all valid states for a square on a board
 * 
 */
enum class BoardPiece {
    X,
    O,
    EMPTY
};

enum class BoardWinner {
    X,
    O,
    TIE,
    NONE
};


/**
 * @brief The Board class tracks the current state of a board
 * 
 */
class Board {
public:
    /**
     * @brief Construct a new Board object
     * 
     */
    Board();

    /**
     * @brief Set the state for a piece on the board
     * 
     * @param piece State to set this position
     * @param xPos X position of the piece
     * @param yPos Y position of the piece 
     */
    void setPiece(BoardPiece piece, int xPos, int yPos);

    /**
     * @brief Get the value of a position on the board
     * 
     * @param xPos X position to check
     * @param yPos Y position to check
     * @return BoardPiece Current piece at this position
     */
    BoardPiece getPiece(int xPos, int yPos) const;

    /**
     * @brief Get a string representation of the board, printed as a grid
     * 
     * @return std::string 
     */
    std::string toString(void) const;

    /**
     * @brief Returns the current winner of a game
     * If more than one valid winner is valid, the first one found is returned.
     * 
     * @return BoardWinner X, O, TIE, or NONE depending on winner.
     */
    BoardWinner getWinner(void) const;

private:
    /**
     * @brief Positions for X must be >=0, < MAX_X
     */
    static const int MAX_X {3};

    /**
     * @brief Positions for Y must be >=0, < MAX_Y
     */
    static const int MAX_Y {3};

    /**
     * @brief Tracks the current state of the board's pieces.
     * 
     */
    std::array<std::array<BoardPiece, MAX_X>, MAX_Y> pieces;
    
    /**
     * @brief Get the string representation for a board piece
     * 
     * @param piece Piece to represent
     * @return std::string 
     */
    static std::string pieceToString(BoardPiece piece);

};  // End of Board class

#endif // End of BOARD_H define