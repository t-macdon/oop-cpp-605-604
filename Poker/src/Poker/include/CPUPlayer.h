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
        CPUPlayer(std::string name, float money);
        virtual float bet(float ante) final;
};

#endif // _CPU_PLAYER_H_
