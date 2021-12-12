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
        explicit Dealer(float ante);
        void promptForPlayers();
        void loadPlayer(std::string name, float money, bool cpu);
        void playARound();
        bool readyToPlay();

    private:

        void showPlayers();
        /**
         * @brief Open up a new deck and shuffle it.
         * If shuffleSeed is 0, a random seed will be used.
         * @param shuffleSeed 
         */
        void openAndShuffleANewDeck(int shuffleSeed=0);
        void dealCardsToPlayers();
        void promptForBets();
        void showdown();
        void determineWinner();

        /**
         * @brief Make sure all players have enough money
         * to place bets, at least meeting the ante.
         * Any player without enough money will be kicked
         */
        void checkPockets();
        bool isHuman(Player* player);
        void clearScreen();
        void waitForInput();

        float ante;
        std::vector<PlayerAndBet> players;
        Deck deck;
};

#endif