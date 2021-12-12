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

/**
 * @brief A Human-controlled poker player
 * 
 */
class HumanPlayer : public Player {
public:
    /**
     * @brief Construct a new Human Player object
     * 
     * @param name Name of this player
     * @param money Amount of money this player starts with
     */
    HumanPlayer(std::string name, float money);

    /**
     * @brief Prompts the human-controller how much they'd like to bet
     * 
     * @param ante Minimum bet
     * @return float Amount bet
     */
    virtual float bet(float ante) final;
};

#endif // _HUMAN_PLAYER_H_


