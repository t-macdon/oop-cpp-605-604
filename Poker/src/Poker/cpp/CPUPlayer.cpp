/**
 * @file CPUPlayer.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation file for the CPUPlayer class
 * @version 0.1
 * @date 2021-12-11
 * @copyright Copyright (c) 2021
 */
#include <string>
#include <cmath>
#include "CPUPlayer.h"

using namespace std;

CPUPlayer::CPUPlayer(string name, float money) :
    Player{name, money}
{
    ;
}

float CPUPlayer::bet(float ante) {
    // CPU Player always bets 1/2 of its money, to the nearest dollar
    float half = round(this->getMoney() / 2);
    if (half < ante) {
        if (getMoney() < ante) {
            return 0;
        } else {
            return ante;
        }
    }
    this->removeMoney(half);
    return half;
}
