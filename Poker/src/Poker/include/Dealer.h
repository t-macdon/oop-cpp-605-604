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

/**
 * @brief Pair a player and their current bet
 */
typedef struct {
    Player* player;
    float bet;
} PlayerAndBet;

/**
 * @brief A dealer runs a poker game
 */
class Dealer {
public:
    /**
     * @brief Construct a new Dealer object
     * @param ante The minimum bet for this table
     */
    explicit Dealer(float ante);

    /**
     * @brief Prompt the user to enter a list of players
     */
    void promptForPlayers();
    
    /**
     * @brief Statically load in a player, instead of prompting
     * 
     * @param name Player name
     * @param money Amount of money this player is playing with
     * @param cpu True if this player is a CPU, False otherwise
     */
    void loadPlayer(std::string name, float money, bool cpu);

    /**
     * @brief Play a round of poker
     */
    void playARound();

    /**
     * @brief Check if the current conditions permit playing a round.
     * This method will also call @ref checkPockets, and remove any
     * players from the table if they fail the check
     * 
     * @return true 
     * @return false 
     */
    bool readyToPlay();

private:

    /**
     * @brief Display a list of all players and their standings
     */
    void showPlayers();

    /**
     * @brief Open up a new deck and shuffle it.
     * If shuffleSeed is 0, a random seed will be used.
     * @param shuffleSeed Seed to use for shuffling, or 0
     */
    void openAndShuffleANewDeck(int shuffleSeed=0);

    /**
     * @brief Deals out 5 cards from the deck to each player
     */
    void dealCardsToPlayers();

    /**
     * @brief Prompt each player to submit their bets.
     * Only human players are prompted, CPUs run their bet method
     */
    void promptForBets();

    /**
     * @brief Perform a showdown of all hands at the table
     */
    void showdown();

    /**
     * @brief Determine the winner of a showdown, awarding
     * them the current pot
     */
    void determineWinner();

    /**
     * @brief Make sure all players have enough money
     * to place bets, at least meeting the ante.
     * Any player without enough money will be kicked
     */
    void checkPockets();

    /**
     * @brief Check if the provided player is a human
     * @param player Player to query
     * @return true Human player
     * @return false CPU player
     */
    bool isHuman(Player* player);

    /**
     * @brief Clear out the terminal screen
     */
    void clearScreen();

    /**
     * @brief Prompt the user to provide input
     * Used as a delay between game phases
     */
    void waitForInput();

    /**
     * @brief Minimum bet for this table
     */
    float ante;

    /**
     * @brief List of structs containing Player and Bet combinations
     */
    std::vector<PlayerAndBet> players;

    /**
     * @brief Deck to use for this game
     * Will often be reset to a fresh instance
     */
    Deck deck;
};

#endif