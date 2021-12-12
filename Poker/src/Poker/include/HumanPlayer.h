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
        HumanPlayer(std::string name, float money);
        virtual float bet(float ante) final;
};

#endif // _HUMAN_PLAYER_H_


