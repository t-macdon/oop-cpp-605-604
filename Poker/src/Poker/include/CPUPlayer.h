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

/**
 * @brief A Computer-controlled poker player
 */
class CPUPlayer : public Player {
public:
    /**
     * @brief Construct a new CPUPlayer object
     * 
     * @param name Name of this player
     * @param money How much money does this player have
     */
    CPUPlayer(std::string name, float money);

    /**
     * @brief The default CPU bet implementation is to bet half of its money
     * 
     * @param ante Minimum bet to make
     * @return float Amount of money betted (or 0 if they cannot bet)
     */
    virtual float bet(float ante) final;
};

#endif // _CPU_PLAYER_H_
