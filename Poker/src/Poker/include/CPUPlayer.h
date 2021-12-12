/**
 * @file CPUPlayer.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Interface file for the CPUPlayer class
 * @version 0.1
 * @date 2021-12-10
 * @copyright Copyright (c) 2021
 */

#ifndef _CPU_PLAYER_H_
#define _CPU_PLAYER_H_

#include <string>
#include "Player.h"

class CPUPlayer : public Player {
    public:

        /**
         * @brief Construct a new CPUPlayer object
         * 
         * @param name Text name of the CPUPlayer
         * @param money The float amount of money the CPUPlayer starts with
         */
        CPUPlayer(std::string name, float money);

        /**
         * @brief Places the specified amount of money in the pool
         * 
         * @param ante The minimum bet
         * @return float The total bet made
         */
        virtual float bet(float ante) final;
};

#endif // _CPU_PLAYER_H_
