/**
 * @file TicTacToeDriver.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Driver class for playing a TicTacToe game
 * @version 0.1
 * @date 2021-09-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

#include "Board.h"

using namespace std;

#if !defined(RUN_UNIT_TESTS) && !RUN_UNIT_TESTS
int main()
{
    cout << "Welcome to TicTacToe!" << endl;

    // create the playing board
    Board board;

    // start the playing loop
    BoardWinner winner = BoardWinner::NONE;
    while (winner == BoardWinner::NONE)
    {
        // printout the current board
        cout << board.toString();

        // get selection from player
        int x, y;
        do {
            cout << "Enter grid X coordinate: ";
            cin >> x;
            cout << "Enter grid Y coordinate: ";
            cin >> y;
            cout << "User selected [" << x << ", " << y << "]" << endl;
        } while (!board.setPiece(BoardPiece::X, x, y));

        // bot turn
        board.playBotTurn();

        // update winner
        winner = board.getWinner();
    }

    cout << board.toString();

    cout << "Player " << Board::winnerToString(winner) << " won the game!" << endl;

    cout << "Thanks for playing TicTacToe!" << endl;
    return 0;
}
#endif