/**
 * @file HumanPlayer.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Interface file for the HumanPlayer class
 * @version 0.1
 * @date 2021-12-10
 * @copyright Copyright (c) 2021
 */

#ifndef _HUMAN_PLAYER_H_
#define _HUMAN_PLAYER_H_

#include <string>
#include "Player.h"

class HumanPlayer : public Player {
    public:

        /**
         * @brief Construct a new Human Player object
         * 
         * @param name The text name of the Player
         * @param money The amount of money the player starts with
         */
        HumanPlayer(std::string name, float money);

        /**
         * @brief Places the specified amount of money in the pool
         * 
         * @param ante The minimum bet
         * @return float The total bet made
         */
        virtual float bet(float ante) final;
};

#endif // _HUMAN_PLAYER_H_


