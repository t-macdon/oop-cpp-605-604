/**
 * @file Dealer.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Interface for the Dealer class
 * @version 0.1
 * @date 2021-12-02
 */

#ifndef DEALER_H_
#define DEALER_H_

#include <vector>
#include "Player.h"
#include "Deck.h"

typedef struct {
    Player* player;
    float bet;
} PlayerAndBet;

class Dealer {
    public:

        /**
         * @brief Construct a new Dealer object
         * 
         * @param ante The minimum bet for this dealer
         */
        explicit Dealer(float ante);

        /**
         * @brief Displays and interprets user input to create players
         * 
         */
        void promptForPlayers();

        /**
         * @brief Instantiates a player and pushes them onto the internal player list
         * 
         * @param name Text name of the player
         * @param money Amount of money to start the player with
         * @param cpu True if CPUPlayer, False if human player
         */
        void loadPlayer(std::string name, float money, bool cpu);

        /**
         * @brief Show the players, open and shuffle a new deck, deal cards to players,
         *  prompt for bets, showdown, and determine winner
         * 
         */
        void playARound();

        /**
         * @brief Validation check to ensure the correct number of players and amount of money
         *  is present
         * 
         * @return true If ready to play
         * @return false If not ready to play
         */
        bool readyToPlay();

    private:

        void showPlayers();
        /**
         * @brief Open up a new deck and shuffle it.
         * If shuffleSeed is 0, a random seed will be used.
         * @param shuffleSeed 
         */
        void openAndShuffleANewDeck(int shuffleSeed=0);

        /**
         * @brief Takes cards from the deck and assigns them to players
         * 
         */
        void dealCardsToPlayers();

        /**
         * @brief Asks each player to input a bet and processes the input
         * 
         */
        void promptForBets();

        /**
         * @brief Asks for bet
         * 
         */
        void showdown();

        /**
         * @brief Computes who the winner of the hand is and assigns their winnings
         * 
         */
        void determineWinner();

        /**
         * @brief Make sure all players have enough money
         * to place bets, at least meeting the ante.
         * Any player without enough money will be kicked
         */
        void checkPockets();

        /**
         * @brief Determines if a player is human or CPU
         * 
         * @param player The Player object
         * @return true If human player
         * @return false If CPU player
         */
        bool isHuman(Player* player);

        /**
         * @brief Prints many return statements to effectively clear the screen
         * 
         */
        void clearScreen();

        /**
         * @brief Prompts user for input and waits
         * 
         */
        void waitForInput();

        /**
         * @brief Minimum bet
         * 
         */
        float ante;

        /**
         * @brief List of structs containing Player and Bet combinations
         * 
         */
        std::vector<PlayerAndBet> players;

        /**
         * @brief The current deck of cards
         * 
         */
        Deck deck;
};

#endif